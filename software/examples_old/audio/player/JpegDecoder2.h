/*
JPEGDecoder.h

JPEG Decoder for Arduino
Public domain, Makoto Kurauchi <http://yushakobo.jp>

Adapted by Bodmer for use with a TFT screen

Latest version here:
https://github.com/Bodmer/JPEGDecoder

*/

#ifndef JPEGDECODER2_H
#define JPEGDECODER2_H

#include "Arduino.h"
#include <SD.h>    // Default
  
#include "picojpeg.h"

enum {
  JPEG_ARRAY = 0,
  JPEG_FS_FILE,
  JPEG_SD_FILE
};

//------------------------------------------------------------------------------
#ifndef jpg_min
  #define jpg_min(a,b)     (((a) < (b)) ? (a) : (b))
#endif

#ifndef min
  #define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

//------------------------------------------------------------------------------
typedef unsigned char uint8;
typedef unsigned int uint;
//------------------------------------------------------------------------------

class JPEGDecoder {

private:
  File g_pInFileSd;
  pjpeg_scan_type_t scan_type;
  pjpeg_image_info_t image_info;
  
  int is_available;
  int mcu_x;
  int mcu_y;
  uint g_nInFileSize;
  uint g_nInFileOfs;
  uint row_pitch;
  uint decoded_width, decoded_height;
  uint row_blocks_per_mcu, col_blocks_per_mcu;
  uint8 status;
  uint8 jpg_source = 0;
  uint8_t* jpg_data;
  
  static uint8 pjpeg_callback(unsigned char* pBuf, unsigned char buf_size, unsigned char *pBytes_actually_read, void *pCallback_data);
  uint8 pjpeg_need_bytes_callback(unsigned char* pBuf, unsigned char buf_size, unsigned char *pBytes_actually_read, void *pCallback_data);
  int decode_mcu(void);
  int decodeCommon(void);
public:

  uint16_t *pImage;
  JPEGDecoder *thisPtr;

  int width;
  int height;
  int comps;
  int MCUSPerRow;
  int MCUSPerCol;
  pjpeg_scan_type_t scanType;
  int MCUWidth;
  int MCUHeight;
  int MCUx;
  int MCUy;
  
  JPEGDecoder();
  ~JPEGDecoder();

  int available(void);
  int read(void);
  int readSwappedBytes(void);
  
  int decodeFile (const char *pFilename);
  int decodeFile (const String& pFilename);
  

  int decodeSdFile (const char *pFilename);
  int decodeSdFile (const String& pFilename);
  int decodeSdFile (File g_pInFile);

  int decodeArray(const uint8_t array[], uint32_t  array_size);
  void abort(void);
  void reset();
};

JPEGDecoder JpegDec;

JPEGDecoder::JPEGDecoder(){
mcu_x = 0 ;
mcu_y = 0 ;
is_available = 0;
thisPtr = this;
}


JPEGDecoder::~JPEGDecoder(){
if (pImage) delete pImage;
pImage = NULL;
}


uint8_t JPEGDecoder::pjpeg_callback(uint8_t* pBuf, uint8_t buf_size, uint8_t *pBytes_actually_read, void *pCallback_data) {
JPEGDecoder *thisPtr = JpegDec.thisPtr ;
thisPtr->pjpeg_need_bytes_callback(pBuf, buf_size, pBytes_actually_read, pCallback_data);
return 0;
}


uint8_t JPEGDecoder::pjpeg_need_bytes_callback(uint8_t* pBuf, uint8_t buf_size, uint8_t *pBytes_actually_read, void *pCallback_data) {
  uint n;
  
  pCallback_data;
  
  n = jpg_min(g_nInFileSize - g_nInFileOfs, buf_size);
  /*
  if (jpg_source == JPEG_ARRAY) { // We are handling an array
    for (int i = 0; i < n; i++) {
      pBuf[i] = pgm_read_byte(jpg_data++);
      //Serial.println(pBuf[i],HEX);
    }
  }
  */
  g_pInFileSd.read(pBuf,n); // else we are handling a file
  //Serial.printf("read jpeg: %d", n);
  
  *pBytes_actually_read = (uint8_t)(n);
  g_nInFileOfs += n;
  return 0;
}
  
 int JPEGDecoder::decode_mcu(void) { 
  status = pjpeg_decode_mcu();
  
  if (status) {
    is_available = 0 ;
  
    if (status != PJPG_NO_MORE_BLOCKS) {
      #ifdef DEBUG
      Serial.print("pjpeg_decode_mcu() failed with status ");
      Serial.println(status);
      #endif
  
      return -1;
    }
  }
  return 1;
}


int JPEGDecoder::read(void) {
int y, x;
uint16_t *pDst_row;

if(is_available == 0 || mcu_y >= image_info.m_MCUSPerCol) {
  abort();
  return 0;
}

// Copy MCU's pixel blocks into the destination bitmap.
pDst_row = pImage;
for (y = 0; y < image_info.m_MCUHeight; y += 8) {

  const int by_limit = jpg_min(8, image_info.m_height - (mcu_y * image_info.m_MCUHeight + y));

  for (x = 0; x < image_info.m_MCUWidth; x += 8) {
    uint16_t *pDst_block = pDst_row + x;

    // Compute source byte offset of the block in the decoder's MCU buffer.
    uint src_ofs = (x * 8U) + (y * 16U);
    const uint8_t *pSrcR = image_info.m_pMCUBufR + src_ofs;
    const uint8_t *pSrcG = image_info.m_pMCUBufG + src_ofs;
    const uint8_t *pSrcB = image_info.m_pMCUBufB + src_ofs;

    const int bx_limit = jpg_min(8, image_info.m_width - (mcu_x * image_info.m_MCUWidth + x));

    if (image_info.m_scanType == PJPG_GRAYSCALE) {
      int bx, by;
      for (by = 0; by < by_limit; by++) {
        uint16_t *pDst = pDst_block;

        for (bx = 0; bx < bx_limit; bx++) {
#ifdef SWAP_BYTES
          *pDst++ = (*pSrcR & 0xF8) | (*pSrcR & 0xE0) >> 5 | (*pSrcR & 0xF8) << 5 | (*pSrcR & 0x1C) << 11;
#else
          *pDst++ = (*pSrcR & 0xF8) << 8 | (*pSrcR & 0xFC) <<3 | *pSrcR >> 3;
#endif
          pSrcR++;
        }

        pSrcR += (8 - bx_limit);

        pDst_block += row_pitch;
      }
    }
    else {
      int bx, by;
      for (by = 0; by < by_limit; by++) {
        uint16_t *pDst = pDst_block;

        for (bx = 0; bx < bx_limit; bx++) {
#ifdef SWAP_BYTES
          *pDst++ = (*pSrcR & 0xF8) | (*pSrcG & 0xE0) >> 5 | (*pSrcB & 0xF8) << 5 | (*pSrcG & 0x1C) << 11;
#else
          *pDst++ = (*pSrcR & 0xF8) << 8 | (*pSrcG & 0xFC) <<3 | *pSrcB >> 3;
#endif
          pSrcR++; pSrcG++; pSrcB++;
        }

        pSrcR += (8 - bx_limit);
        pSrcG += (8 - bx_limit);
        pSrcB += (8 - bx_limit);

        pDst_block += row_pitch;
      }
    }
  }
  pDst_row += (row_pitch * 8);
}

MCUx = mcu_x;
MCUy = mcu_y;

mcu_x++;
if (mcu_x == image_info.m_MCUSPerRow) {
  mcu_x = 0;
  mcu_y++;
}

if(decode_mcu()==-1) is_available = 0 ;

return 1;
}

int JPEGDecoder::readSwappedBytes(void) {
int y, x;
uint16_t *pDst_row;

if(is_available == 0 || mcu_y >= image_info.m_MCUSPerCol) {
  abort();
  return 0;
}

// Copy MCU's pixel blocks into the destination bitmap.
pDst_row = pImage;
for (y = 0; y < image_info.m_MCUHeight; y += 8) {

  const int by_limit = jpg_min(8, image_info.m_height - (mcu_y * image_info.m_MCUHeight + y));

  for (x = 0; x < image_info.m_MCUWidth; x += 8) {
    uint16_t *pDst_block = pDst_row + x;

    // Compute source byte offset of the block in the decoder's MCU buffer.
    uint src_ofs = (x * 8U) + (y * 16U);
    const uint8_t *pSrcR = image_info.m_pMCUBufR + src_ofs;
    const uint8_t *pSrcG = image_info.m_pMCUBufG + src_ofs;
    const uint8_t *pSrcB = image_info.m_pMCUBufB + src_ofs;

    const int bx_limit = jpg_min(8, image_info.m_width - (mcu_x * image_info.m_MCUWidth + x));

    if (image_info.m_scanType == PJPG_GRAYSCALE) {
      int bx, by;
      for (by = 0; by < by_limit; by++) {
        uint16_t *pDst = pDst_block;

        for (bx = 0; bx < bx_limit; bx++) {

          *pDst++ = (*pSrcR & 0xF8) | (*pSrcR & 0xE0) >> 5 | (*pSrcR & 0xF8) << 5 | (*pSrcR & 0x1C) << 11;

          pSrcR++;
        }
      }
    }
    else {
      int bx, by;
      for (by = 0; by < by_limit; by++) {
        uint16_t *pDst = pDst_block;

        for (bx = 0; bx < bx_limit; bx++) {

          *pDst++ = (*pSrcR & 0xF8) | (*pSrcG & 0xE0) >> 5 | (*pSrcB & 0xF8) << 5 | (*pSrcG & 0x1C) << 11;

          pSrcR++; pSrcG++; pSrcB++;
        }

        pSrcR += (8 - bx_limit);
        pSrcG += (8 - bx_limit);
        pSrcB += (8 - bx_limit);

        pDst_block += row_pitch;
      }
    }
  }
  pDst_row += (row_pitch * 8);
}

MCUx = mcu_x;
MCUy = mcu_y;

mcu_x++;
if (mcu_x == image_info.m_MCUSPerRow) {
  mcu_x = 0;
  mcu_y++;
}

if(decode_mcu()==-1) is_available = 0 ;

return 1;
}


// Generic file call for SD or SPIFFS, uses leading / to distinguish SPIFFS files
int JPEGDecoder::decodeFile(const char *pFilename){

#if defined (ESP8266) || defined (ESP32)
#if defined (LOAD_SD_LIBRARY) || defined (LOAD_SDFAT_LIBRARY)
if (*pFilename == '/')
#endif
return decodeFsFile(pFilename);
#endif

#if defined (LOAD_SD_LIBRARY) || defined (LOAD_SDFAT_LIBRARY)
return decodeSdFile(pFilename);
#endif

return -1;
}

int JPEGDecoder::decodeFile(const String& pFilename){

#if defined (ESP8266) || defined (ESP32)
#if defined (LOAD_SD_LIBRARY) || defined (LOAD_SDFAT_LIBRARY)
if (pFilename.charAt(0) == '/')
#endif
return decodeFsFile(pFilename);
#endif

#if defined (LOAD_SD_LIBRARY) || defined (LOAD_SDFAT_LIBRARY)
return decodeSdFile(pFilename);
#endif

return -1;
}

// Call specific to SD filing system in case leading / is used
int JPEGDecoder::decodeSdFile(const char *pFilename) {

File pInFile = SD.open( pFilename, FILE_READ);

return decodeSdFile(pInFile);
}


int JPEGDecoder::decodeSdFile(const String& pFilename) {
#if !defined (ARDUINO_ARCH_SAM)
File pInFile = SD.open( pFilename.c_str(), FILE_READ);

return decodeSdFile(pInFile);
#else
return -1;
#endif
}


int JPEGDecoder::decodeSdFile(File jpgFile) { // This is for the SD library

g_pInFileSd = jpgFile;

jpg_source = JPEG_SD_FILE; // Flag to indicate a SD file

if (!g_pInFileSd) {
  #ifdef DEBUG
  Serial.println("ERROR: SD file not found!");
  #endif

  return -1;
}

g_nInFileOfs = 0;

g_nInFileSize = g_pInFileSd.size();

return decodeCommon();

}

int JPEGDecoder::decodeArray(const uint8_t array[], uint32_t  array_size) {

  jpg_source = JPEG_ARRAY; // We are not processing a file, use arrays

  g_nInFileOfs = 0;

  jpg_data = (uint8_t *)array;

  g_nInFileSize = array_size;

  return decodeCommon();
}


int JPEGDecoder::decodeCommon(void) {

  status = pjpeg_decode_init(&image_info, pjpeg_callback, NULL, 0);

  if (status) {
    #ifdef DEBUG
    Serial.print("pjpeg_decode_init() failed with status ");
    Serial.println(status);

    if (status == PJPG_UNSUPPORTED_MODE) {
      Serial.println("Progressive JPEG files are not supported.");
    }
    #endif

    return -1;
  }

  decoded_width =  image_info.m_width;
  decoded_height =  image_info.m_height;
  
  row_pitch = image_info.m_MCUWidth;
  pImage = new uint16_t[image_info.m_MCUWidth * image_info.m_MCUHeight];
  if (!pImage) {
    #ifdef DEBUG
    Serial.println("Memory Allocation Failure");
    #endif

    return -1;
  }
  memset(pImage , 0 , sizeof(pImage));

  row_blocks_per_mcu = image_info.m_MCUWidth >> 3;
  col_blocks_per_mcu = image_info.m_MCUHeight >> 3;

  is_available = 1 ;

  width = decoded_width;
  height = decoded_height;
  comps = 1;
  MCUSPerRow = image_info.m_MCUSPerRow;
  MCUSPerCol = image_info.m_MCUSPerCol;
  scanType = image_info.m_scanType;
  MCUWidth = image_info.m_MCUWidth;
  MCUHeight = image_info.m_MCUHeight;

  return decode_mcu();
}

void JPEGDecoder::abort(void) {

}

void JPEGDecoder::reset(void) {
  mcu_x = 0;
  mcu_y = 0;
  is_available = 0;
  if (pImage) delete pImage;
  pImage = NULL;
}
#endif // JPEGDECODER2_H
