<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.4.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S" xrefpart="/%S.%C%R">
<libraries>
<library name="interface" urn="urn:adsk.eagle:library:5637722">
<description>Generated from &lt;b&gt;interface.sch&lt;/b&gt;&lt;p&gt;
by exp-lbrs.ulp</description>
<packages>
<package name="SWITCH-ALPS_ALPS_EC12E_SW" urn="urn:adsk.eagle:footprint:5637723/1" library_version="2">
<description>ALPS rotary encoder&lt;br&gt;
EC12E series with push-on switch</description>
<circle x="0" y="0" radius="3" width="0.127" layer="21"/>
<wire x1="-6.2" y1="-6.6" x2="6.2" y2="-6.6" width="0.127" layer="21"/>
<wire x1="6.2" y1="-6.6" x2="6.2" y2="6.6" width="0.127" layer="21"/>
<wire x1="6.2" y1="6.6" x2="-6.2" y2="6.6" width="0.127" layer="21"/>
<wire x1="-6.2" y1="6.6" x2="-6.2" y2="-6.6" width="0.127" layer="21"/>
<wire x1="-2.6" y1="1.5" x2="2.6" y2="1.5" width="0.127" layer="21"/>
<pad name="A" x="-2.5" y="-7.5" drill="1" shape="square"/>
<pad name="B" x="2.5" y="-7.5" drill="1" shape="square"/>
<pad name="C" x="0" y="-7.5" drill="1" shape="square"/>
<pad name="D" x="-2.5" y="7" drill="1" shape="square"/>
<pad name="E" x="2.5" y="7" drill="1" shape="square"/>
<pad name="GND1" x="-6.1" y="0" drill="2.2" shape="square"/>
<pad name="GND2" x="6.1" y="0" drill="2.2" shape="square"/>
<text x="-2.5" y="8.5" size="1.27" layer="25">&gt;NAME</text>
<text x="3.5" y="-9" size="1.27" layer="27" rot="R180">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="SWITCH-ALPS_ALPS_EC12E_SW" urn="urn:adsk.eagle:package:5637727/3" type="model" library_version="2">
<description>ALPS rotary encoder&lt;br&gt;
EC12E series with push-on switch</description>
<packageinstances>
<packageinstance name="SWITCH-ALPS_ALPS_EC12E_SW"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="SWITCH-ALPS_ENCODER" urn="urn:adsk.eagle:symbol:5637726/1" library_version="2">
<circle x="0" y="0" radius="0.5679" width="0" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="4.1275" width="0.3048" layer="94"/>
<wire x1="-2.54" y1="4.1275" x2="-0.9525" y2="1.905" width="0.3048" layer="94"/>
<wire x1="-1.905" y1="1.905" x2="-2.54" y2="1.905" width="0.3048" layer="94"/>
<wire x1="-2.54" y1="1.905" x2="-2.54" y2="0" width="0.3048" layer="94"/>
<wire x1="2.54" y1="5.08" x2="2.54" y2="4.1275" width="0.3048" layer="94"/>
<wire x1="2.54" y1="4.1275" x2="4.1275" y2="1.905" width="0.3048" layer="94"/>
<wire x1="3.175" y1="1.905" x2="2.54" y2="1.905" width="0.3048" layer="94"/>
<wire x1="2.54" y1="1.905" x2="2.54" y2="0" width="0.3048" layer="94"/>
<wire x1="-2.54" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<pin name="A" x="-2.54" y="7.62" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="B" x="2.54" y="7.62" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="C" x="0" y="-2.54" visible="off" length="short" direction="pas" rot="R90"/>
<text x="-3.81" y="0" size="1.27" layer="95" rot="R90">&gt;PART</text>
<text x="6.35" y="0" size="1.27" layer="96" rot="R90">&gt;VALUE</text>
</symbol>
<symbol name="SWITCH-ALPS_TASTER" urn="urn:adsk.eagle:symbol:5637724/1" library_version="2">
<wire x1="-2.54" y1="0" x2="-1.5875" y2="0" width="0.3048" layer="94"/>
<wire x1="-1.5875" y1="0" x2="0.635" y2="1.5875" width="0.3048" layer="94"/>
<wire x1="0.635" y1="0.635" x2="0.635" y2="0" width="0.3048" layer="94"/>
<wire x1="0.635" y1="0" x2="2.54" y2="0" width="0.3048" layer="94"/>
<wire x1="0" y1="1.27" x2="0" y2="3.81" width="0.127" layer="94"/>
<wire x1="-0.635" y1="3.81" x2="0.635" y2="3.81" width="0.127" layer="94"/>
<wire x1="-0.635" y1="3.81" x2="-0.635" y2="3.4925" width="0.127" layer="94"/>
<wire x1="0.635" y1="3.81" x2="0.635" y2="3.4925" width="0.127" layer="94"/>
<pin name="1" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<text x="-5.08" y="5.08" size="1.27" layer="95">&gt;PART</text>
<text x="-5.08" y="-2.54" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="SWITCH-ALPS_GEHAEUSEANSCHLUSS" urn="urn:adsk.eagle:symbol:5637725/1" library_version="2">
<wire x1="0" y1="0" x2="0.9525" y2="0" width="0.254" layer="94"/>
<wire x1="1.5875" y1="0" x2="2.2225" y2="0" width="0.254" layer="94"/>
<wire x1="2.8575" y1="0" x2="3.4925" y2="0" width="0.254" layer="94"/>
<wire x1="4.1275" y1="0" x2="5.08" y2="0" width="0.254" layer="94"/>
<pin name="G" x="0" y="0" visible="pad" length="point" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SWITCH-ALPS_EC12E_SW" urn="urn:adsk.eagle:component:5637728/2" prefix="SW" library_version="2">
<description>ALPS rotary Encoder EC12E series with switch</description>
<gates>
<gate name="G$1" symbol="SWITCH-ALPS_ENCODER" x="-10.16" y="-2.54" addlevel="always"/>
<gate name="G$2" symbol="SWITCH-ALPS_TASTER" x="10.16" y="5.08" addlevel="always"/>
<gate name="G$3" symbol="SWITCH-ALPS_GEHAEUSEANSCHLUSS" x="10.16" y="-5.08" addlevel="request"/>
<gate name="G$4" symbol="SWITCH-ALPS_GEHAEUSEANSCHLUSS" x="10.16" y="-7.62" addlevel="request"/>
</gates>
<devices>
<device name="" package="SWITCH-ALPS_ALPS_EC12E_SW">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="B" pad="B"/>
<connect gate="G$1" pin="C" pad="C"/>
<connect gate="G$2" pin="1" pad="D"/>
<connect gate="G$2" pin="2" pad="E"/>
<connect gate="G$3" pin="G" pad="GND1"/>
<connect gate="G$4" pin="G" pad="GND2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5637727/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="EC12E2424407" constant="no"/>
<attribute name="OC_FARNELL" value="1520813" constant="no"/>
<attribute name="OC_NEWARK" value="74M1068" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Panasonic - EVU-F2MFL3D14" urn="urn:adsk.eagle:library:5363488">
<description>Upverter Parts Library

Created by Upverter.com</description>
<packages>
<package name="PANASONIC_EVU-F2MFL3D14_0" urn="urn:adsk.eagle:footprint:5363489/1" library_version="2">
<description>Square Rotary Potentiometers with Insulated Shaft</description>
<wire x1="-4.85" y1="-6.25" x2="-4.85" y2="6.25" width="0.15" layer="51"/>
<wire x1="-4.85" y1="6.25" x2="4.85" y2="6.25" width="0.15" layer="51"/>
<wire x1="4.85" y1="6.25" x2="4.85" y2="-6.25" width="0.15" layer="51"/>
<wire x1="4.85" y1="-6.25" x2="-4.85" y2="-6.25" width="0.15" layer="51"/>
<wire x1="4.85" y1="6.25" x2="-4.85" y2="6.25" width="0.15" layer="21"/>
<wire x1="-4.85" y1="6.25" x2="-4.85" y2="2.85" width="0.15" layer="21"/>
<wire x1="4.85" y1="6.25" x2="4.85" y2="2.85" width="0.15" layer="21"/>
<wire x1="-4.85" y1="-6.25" x2="-4.85" y2="-2.35" width="0.15" layer="21"/>
<wire x1="4.85" y1="-6.25" x2="4.85" y2="-2.35" width="0.15" layer="21"/>
<wire x1="-4.85" y1="-6.25" x2="-3.75" y2="-6.25" width="0.15" layer="21"/>
<wire x1="4.85" y1="-6.25" x2="3.75" y2="-6.25" width="0.15" layer="21"/>
<text x="-6.175" y="7.225" size="1" layer="25">&gt;NAME</text>
<circle x="-2.375" y="-8.625" radius="0.25" width="0" layer="21"/>
<pad name="4" x="-4.5" y="0.25" drill="2.286" diameter="3.048" rot="R90"/>
<pad name="5" x="4.5" y="0.25" drill="2.286" diameter="3.048" rot="R90"/>
<pad name="1" x="-2.5" y="-6.75" drill="1.1" diameter="1.7" shape="square"/>
<pad name="2" x="0" y="-6.75" drill="1.1" diameter="1.7"/>
<pad name="3" x="2.5" y="-6.75" drill="1.1" diameter="1.7"/>
</package>
</packages>
<packages3d>
<package3d name="PANASONIC_EVU-F2MFL3D14_0" urn="urn:adsk.eagle:package:5363493/2" type="model" library_version="2">
<description>Square Rotary Potentiometers with Insulated Shaft</description>
<packageinstances>
<packageinstance name="PANASONIC_EVU-F2MFL3D14_0"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PANASONIC_EVU-F2MFL3D14_0_0" urn="urn:adsk.eagle:symbol:5363491/1" library_version="2">
<description>Square Rotary Potentiometers with Insulated Shaft</description>
<wire x1="2.54" y1="-2.54" x2="3.302" y2="-1.27" width="0.508" layer="94"/>
<wire x1="3.302" y1="-1.27" x2="4.572" y2="-3.81" width="0.508" layer="94"/>
<wire x1="4.572" y1="-3.81" x2="5.842" y2="-1.27" width="0.508" layer="94"/>
<wire x1="5.842" y1="-1.27" x2="7.112" y2="-3.81" width="0.508" layer="94"/>
<wire x1="7.112" y1="-3.81" x2="8.382" y2="-1.27" width="0.508" layer="94"/>
<wire x1="8.382" y1="-1.27" x2="9.652" y2="-3.81" width="0.508" layer="94"/>
<wire x1="9.652" y1="-3.81" x2="10.16" y2="-2.54" width="0.508" layer="94"/>
<wire x1="7.62" y1="-4.318" x2="6.858" y2="-5.334" width="0.508" layer="94"/>
<wire x1="7.62" y1="-4.318" x2="8.382" y2="-5.334" width="0.508" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="-2.54" width="0.15" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="10.16" y2="-2.54" width="0.15" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="7.62" y2="-4.318" width="0.15" layer="94"/>
<text x="-2.794" y="4.064" size="2.54" layer="95" align="top-left">&gt;NAME</text>
<text x="-2.794" y="-11.176" size="2.54" layer="95" align="top-left">EVU-F2MFL3D14</text>
<pin name="1" x="-2.54" y="-2.54" visible="pad" length="middle"/>
<pin name="3" x="15.24" y="-2.54" visible="pad" length="middle" rot="R180"/>
<pin name="2" x="7.62" y="-10.16" visible="pad" length="middle" rot="R90"/>
</symbol>
<symbol name="PANASONIC_EVU-F2MFL3D14_0_1" urn="urn:adsk.eagle:symbol:5363490/1" library_version="2">
<description>Square Rotary Potentiometers with Insulated Shaft</description>
<wire x1="2.54" y1="-12.7" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="15.24" y2="-5.08" width="0.254" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="15.24" y2="-12.7" width="0.254" layer="94"/>
<wire x1="15.24" y1="-12.7" x2="2.54" y2="-12.7" width="0.254" layer="94"/>
<wire x1="2.54" y1="-7.62" x2="2.54" y2="-7.62" width="0.15" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="2.54" y2="-10.16" width="0.15" layer="94"/>
<text x="-2.54" y="0" size="2.54" layer="95" align="top-left">&gt;NAME</text>
<text x="-2.54" y="-15.24" size="2.54" layer="95" align="top-left">EVU-F2MFL3D14</text>
<pin name="MNT_1" x="-2.54" y="-7.62" length="middle"/>
<pin name="MNT_2" x="-2.54" y="-10.16" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PANASONIC_EVU-F2MFL3D14" urn="urn:adsk.eagle:component:5363494/2" prefix="VR" library_version="2">
<description>Square Rotary Potentiometers with Insulated Shaft</description>
<gates>
<gate name="A" symbol="PANASONIC_EVU-F2MFL3D14_0_0" x="0" y="0"/>
<gate name="B" symbol="PANASONIC_EVU-F2MFL3D14_0_1" x="27.62" y="0"/>
</gates>
<devices>
<device name="PANASONIC_EVU-F2MFL3D14_0_0" package="PANASONIC_EVU-F2MFL3D14_0">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="B" pin="MNT_1" pad="4"/>
<connect gate="B" pin="MNT_2" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5363493/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CENTROID_NOT_SPECIFIED" value="Yes"/>
<attribute name="DATASHEET" value="https://upverter.com/datasheet/0e6f35378f82932eabea89c93832ce37004881c1.pdf"/>
<attribute name="DIGIKEY_DESCRIPTION" value="RES POT 10K OHM 1/20W LOGARITHMIC"/>
<attribute name="DIGIKEY_PART_NUMBER" value="P3H8103-ND"/>
<attribute name="LEAD_FREE" value="yes"/>
<attribute name="MF" value="Panasonic"/>
<attribute name="MOUSER_PART_NUMBER" value="667-EVU-F2MFL3D14"/>
<attribute name="MPN" value="EVU-F2MFL3D14"/>
<attribute name="PACKAGE" value="PTH_POT_12MM5_9MM7"/>
<attribute name="POWER" value="50mW"/>
<attribute name="PREFIX" value="VR"/>
<attribute name="RESISTANCE" value="10kΩ"/>
<attribute name="ROHS" value="yes"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VCC" urn="urn:adsk.eagle:symbol:26928/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="VCC" urn="urn:adsk.eagle:component:26957/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Molex - 52892-1633" urn="urn:adsk.eagle:library:6095958">
<description>Upverter Parts Library

Created by Upverter.com</description>
<packages>
<package name="MOLEX_52892-1633_0" urn="urn:adsk.eagle:footprint:6095960/2" library_version="3">
<description>MOLX-52892-1633</description>
<wire x1="4.5" y1="1.075" x2="4.5" y2="1.125" width="0.1" layer="51"/>
<wire x1="-4.5" y1="1.075" x2="-4.5" y2="1.125" width="0.1" layer="51"/>
<wire x1="-6.3" y1="1.125" x2="-4.5" y2="1.125" width="0.1" layer="51"/>
<wire x1="4.5" y1="1.125" x2="6.3" y2="1.125" width="0.1" layer="51"/>
<wire x1="-4.5" y1="1.075" x2="4.5" y2="1.075" width="0.1" layer="51"/>
<wire x1="3.785" y1="-3.775" x2="3.785" y2="-3.275" width="0.1" layer="51"/>
<wire x1="-3.785" y1="-3.775" x2="-3.785" y2="-3.275" width="0.1" layer="51"/>
<wire x1="3.785" y1="-3.275" x2="6.3" y2="-3.275" width="0.1" layer="51"/>
<wire x1="-6.3" y1="-3.275" x2="-3.785" y2="-3.275" width="0.1" layer="51"/>
<wire x1="-6.3" y1="-3.275" x2="-6.3" y2="1.125" width="0.1" layer="51"/>
<wire x1="-3.785" y1="-3.775" x2="3.785" y2="-3.775" width="0.1" layer="51"/>
<wire x1="6.3" y1="-3.275" x2="6.3" y2="1.125" width="0.1" layer="51"/>
<wire x1="-6.3" y1="-3.275" x2="6.3" y2="-3.275" width="0.15" layer="21"/>
<wire x1="6.3" y1="-0.075" x2="6.3" y2="1.125" width="0.15" layer="21"/>
<wire x1="4.3" y1="1.125" x2="6.3" y2="1.125" width="0.15" layer="21"/>
<wire x1="6.3" y1="-3.275" x2="6.3" y2="-3.075" width="0.15" layer="21"/>
<wire x1="-6.3" y1="1.125" x2="-4.3" y2="1.125" width="0.15" layer="21"/>
<wire x1="-6.3" y1="-0.075" x2="-6.3" y2="1.125" width="0.15" layer="21"/>
<wire x1="-6.3" y1="-3.275" x2="-6.3" y2="-3.075" width="0.15" layer="21"/>
<text x="-8.3" y="2.95" size="1" layer="25">&gt;NAME</text>
<circle x="-3.75" y="2.825" radius="0.125" width="0.25" layer="21"/>
<rectangle x1="-5.6" y1="-3.575" x2="-4.35" y2="-0.475" layer="4"/>
<rectangle x1="4.35" y1="-3.575" x2="5.6" y2="-0.475" layer="4"/>
<smd name="16" x="3.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="15" x="3.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="14" x="2.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="13" x="2.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="12" x="1.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="11" x="1.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="1" x="-3.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="2" x="-3.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="3" x="-2.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="4" x="-2.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="5" x="-1.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="6" x="-1.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="7" x="-0.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="8" x="-0.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="9" x="0.25" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="10" x="0.75" y="1.575" dx="0.3" dy="1.4" layer="1"/>
<smd name="MP1" x="-6.4" y="-1.575" dx="1.6" dy="2.2" layer="1"/>
<smd name="MP2" x="6.4" y="-1.575" dx="1.6" dy="2.2" layer="1"/>
</package>
</packages>
<packages3d>
<package3d name="MOLEX_52892-1633_0" urn="urn:adsk.eagle:package:6095962/3" type="model" library_version="3">
<description>MOLX-52892-1633</description>
<packageinstances>
<packageinstance name="MOLEX_52892-1633_0"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MOLEX_52892-1633_0_0" urn="urn:adsk.eagle:symbol:6095961/1" library_version="3">
<description>MOLX-52892-1633</description>
<wire x1="0" y1="-10.16" x2="0" y2="-5.08" width="0.254" layer="94"/>
<wire x1="0" y1="-5.08" x2="50.8" y2="-5.08" width="0.254" layer="94"/>
<wire x1="50.8" y1="-5.08" x2="50.8" y2="-10.16" width="0.254" layer="94"/>
<wire x1="50.8" y1="-10.16" x2="0" y2="-10.16" width="0.254" layer="94"/>
<wire x1="27.94" y1="-10.16" x2="27.94" y2="-8.382" width="0.254" layer="94"/>
<wire x1="25.4" y1="-10.16" x2="25.4" y2="-8.382" width="0.254" layer="94"/>
<wire x1="22.86" y1="-10.16" x2="22.86" y2="-8.382" width="0.254" layer="94"/>
<wire x1="20.32" y1="-10.16" x2="20.32" y2="-8.382" width="0.254" layer="94"/>
<wire x1="17.78" y1="-10.16" x2="17.78" y2="-8.382" width="0.254" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="15.24" y2="-8.382" width="0.254" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="12.7" y2="-8.382" width="0.254" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="10.16" y2="-8.382" width="0.254" layer="94"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="-8.382" width="0.254" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="5.08" y2="-8.382" width="0.254" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="2.54" y2="-8.382" width="0.254" layer="94"/>
<wire x1="30.48" y1="-10.16" x2="30.48" y2="-8.382" width="0.254" layer="94"/>
<wire x1="33.02" y1="-10.16" x2="33.02" y2="-8.382" width="0.254" layer="94"/>
<wire x1="35.56" y1="-10.16" x2="35.56" y2="-8.382" width="0.254" layer="94"/>
<wire x1="38.1" y1="-10.16" x2="38.1" y2="-8.382" width="0.254" layer="94"/>
<wire x1="40.64" y1="-10.16" x2="40.64" y2="-8.382" width="0.254" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="2.54" y2="-10.16" width="0.15" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="5.08" y2="-10.16" width="0.15" layer="94"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="-10.16" width="0.15" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="10.16" y2="-10.16" width="0.15" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="12.7" y2="-10.16" width="0.15" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="15.24" y2="-10.16" width="0.15" layer="94"/>
<wire x1="17.78" y1="-10.16" x2="17.78" y2="-10.16" width="0.15" layer="94"/>
<wire x1="20.32" y1="-10.16" x2="20.32" y2="-10.16" width="0.15" layer="94"/>
<wire x1="22.86" y1="-10.16" x2="22.86" y2="-10.16" width="0.15" layer="94"/>
<wire x1="25.4" y1="-10.16" x2="25.4" y2="-10.16" width="0.15" layer="94"/>
<wire x1="27.94" y1="-10.16" x2="27.94" y2="-10.16" width="0.15" layer="94"/>
<wire x1="45.72" y1="-10.16" x2="45.72" y2="-10.16" width="0.15" layer="94"/>
<wire x1="48.26" y1="-10.16" x2="48.26" y2="-10.16" width="0.15" layer="94"/>
<wire x1="30.48" y1="-10.16" x2="30.48" y2="-10.16" width="0.15" layer="94"/>
<wire x1="33.02" y1="-10.16" x2="33.02" y2="-10.16" width="0.15" layer="94"/>
<wire x1="35.56" y1="-10.16" x2="35.56" y2="-10.16" width="0.15" layer="94"/>
<wire x1="38.1" y1="-10.16" x2="38.1" y2="-10.16" width="0.15" layer="94"/>
<wire x1="40.64" y1="-10.16" x2="40.64" y2="-10.16" width="0.15" layer="94"/>
<text x="0" y="-2.54" size="2.54" layer="95" align="top-left">&gt;NAME</text>
<text x="0" y="-15.24" size="2.54" layer="95" align="top-left">52892-1633</text>
<pin name="1" x="2.54" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="2" x="5.08" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="3" x="7.62" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="4" x="10.16" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="5" x="12.7" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="6" x="15.24" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="7" x="17.78" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="8" x="20.32" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="9" x="22.86" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="10" x="25.4" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="11" x="27.94" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="MP1" x="45.72" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="MP2" x="48.26" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="12" x="30.48" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="13" x="33.02" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="14" x="35.56" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="15" x="38.1" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="16" x="40.64" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<circle x="27.94" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="25.4" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="20.32" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="17.78" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="15.24" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="12.7" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="10.16" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="7.62" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="5.08" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="2.54" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="30.48" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="33.02" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="35.56" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="38.1" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="40.64" y="-7.62" radius="0.762" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOLEX_52892-1633" urn="urn:adsk.eagle:component:6095963/3" prefix="J" library_version="3">
<description>MOLX-52892-1633</description>
<gates>
<gate name="G$0" symbol="MOLEX_52892-1633_0_0" x="0" y="0"/>
</gates>
<devices>
<device name="MOLEX_52892-1633_0_0" package="MOLEX_52892-1633_0">
<connects>
<connect gate="G$0" pin="1" pad="1"/>
<connect gate="G$0" pin="10" pad="10"/>
<connect gate="G$0" pin="11" pad="11"/>
<connect gate="G$0" pin="12" pad="12"/>
<connect gate="G$0" pin="13" pad="13"/>
<connect gate="G$0" pin="14" pad="14"/>
<connect gate="G$0" pin="15" pad="15"/>
<connect gate="G$0" pin="16" pad="16"/>
<connect gate="G$0" pin="2" pad="2"/>
<connect gate="G$0" pin="3" pad="3"/>
<connect gate="G$0" pin="4" pad="4"/>
<connect gate="G$0" pin="5" pad="5"/>
<connect gate="G$0" pin="6" pad="6"/>
<connect gate="G$0" pin="7" pad="7"/>
<connect gate="G$0" pin="8" pad="8"/>
<connect gate="G$0" pin="9" pad="9"/>
<connect gate="G$0" pin="MP1" pad="MP1"/>
<connect gate="G$0" pin="MP2" pad="MP2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:6095962/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CIIVA_IDS" value="12958044"/>
<attribute name="CIRCUITS_LOADED" value="16"/>
<attribute name="COMPONENT_LINK_1_DESCRIPTION" value="Manufacturer URL"/>
<attribute name="COMPONENT_LINK_1_URL" value="http://www.molex.com/molex/index.jsp"/>
<attribute name="COMPONENT_LINK_3_DESCRIPTION" value="Package Specification"/>
<attribute name="COMPONENT_LINK_3_URL" value="http://www.molex.com/pdm_docs/sd/528921633_sd.pdf"/>
<attribute name="CONTACT_POSITION" value="Bottom"/>
<attribute name="CURRENT_MAX_PER_CONTACT" value="0.5A"/>
<attribute name="DATASHEET" value="http://www.molex.com/webdocs/datasheets/pdf/en-us/0528921633_FFC_FPC_CONNECTORS.pdf"/>
<attribute name="DURABILITY_MATING_CYCLES_MAX" value="20"/>
<attribute name="ENTRY_ANGLE" value="90degrees Angle"/>
<attribute name="FOOTPRINT_VARIANT_NAME_0" value="Manufacturer Recommended"/>
<attribute name="IMPORTED" value="yes"/>
<attribute name="IMPORTED_FROM" value="vault"/>
<attribute name="IMPORT_TS" value="1521865775"/>
<attribute name="MATED_HEIGHT" value="2.00mm"/>
<attribute name="MATERIAL___METAL" value="Phosphor Bronze"/>
<attribute name="MATERIAL___PLATING_MATING" value="Silver, Tin-Bismuth"/>
<attribute name="MATERIAL___PLATING_TERMINATION" value="Silver, Tin-Bismuth"/>
<attribute name="MF" value="Molex"/>
<attribute name="MOUNTING_TECHNOLOGY" value="Surface Mount"/>
<attribute name="MPN" value="52892-1633"/>
<attribute name="NUMBER_OF_ROWS" value="1"/>
<attribute name="ORIENTATION" value="Right Angle"/>
<attribute name="PACKAGE" value="52892-1633"/>
<attribute name="PACKAGE_DESCRIPTION" value="16-Lead FPC Connector, Pitch 0.5 mm"/>
<attribute name="PACKAGE_VERSION" value="Rev. A, 05/2013"/>
<attribute name="PACKING" value="Tape and Reel"/>
<attribute name="PCB_LOCATOR" value="No"/>
<attribute name="PCB_RETENTION" value="Yes"/>
<attribute name="PITCH___MATING_INTERFACE" value="0.50mm"/>
<attribute name="PITCH___TERMINATION_INTERFACE" value="0.50mm"/>
<attribute name="POLARIZED_TO_PCB" value="No"/>
<attribute name="PREFIX" value="J"/>
<attribute name="RELEASE_DATE" value="1411372667"/>
<attribute name="ROHS" value="Yes"/>
<attribute name="STACKABLE" value="No"/>
<attribute name="VAULT_GUID" value="C24F345D-8B09-4EB3-B126-737F836EC0CC"/>
<attribute name="VAULT_REVISION" value="B04BDDE3-DCC0-4E22-88B5-2BA07A3C3672"/>
<attribute name="VOLTAGE_MAX" value="50V"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="SW1" library="interface" library_urn="urn:adsk.eagle:library:5637722" deviceset="SWITCH-ALPS_EC12E_SW" device="" package3d_urn="urn:adsk.eagle:package:5637727/3"/>
<part name="SW2" library="interface" library_urn="urn:adsk.eagle:library:5637722" deviceset="SWITCH-ALPS_EC12E_SW" device="" package3d_urn="urn:adsk.eagle:package:5637727/3"/>
<part name="VR1" library="Panasonic - EVU-F2MFL3D14" library_urn="urn:adsk.eagle:library:5363488" deviceset="PANASONIC_EVU-F2MFL3D14" device="PANASONIC_EVU-F2MFL3D14_0_0" package3d_urn="urn:adsk.eagle:package:5363493/2"/>
<part name="VR2" library="Panasonic - EVU-F2MFL3D14" library_urn="urn:adsk.eagle:library:5363488" deviceset="PANASONIC_EVU-F2MFL3D14" device="PANASONIC_EVU-F2MFL3D14_0_0" package3d_urn="urn:adsk.eagle:package:5363493/2"/>
<part name="VR3" library="Panasonic - EVU-F2MFL3D14" library_urn="urn:adsk.eagle:library:5363488" deviceset="PANASONIC_EVU-F2MFL3D14" device="PANASONIC_EVU-F2MFL3D14_0_0" package3d_urn="urn:adsk.eagle:package:5363493/2"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="J1" library="Molex - 52892-1633" library_urn="urn:adsk.eagle:library:6095958" deviceset="MOLEX_52892-1633" device="MOLEX_52892-1633_0_0" package3d_urn="urn:adsk.eagle:package:6095962/3"/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="VR4" library="Panasonic - EVU-F2MFL3D14" library_urn="urn:adsk.eagle:library:5363488" deviceset="PANASONIC_EVU-F2MFL3D14" device="PANASONIC_EVU-F2MFL3D14_0_0" package3d_urn="urn:adsk.eagle:package:5363493/2"/>
<part name="P+5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="SW3" library="interface" library_urn="urn:adsk.eagle:library:5637722" deviceset="SWITCH-ALPS_EC12E_SW" device="" package3d_urn="urn:adsk.eagle:package:5637727/3"/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="SW1" gate="G$1" x="83.82" y="38.1" smashed="yes">
<attribute name="PART" x="80.01" y="38.1" size="1.27" layer="95" rot="R90"/>
<attribute name="VALUE" x="90.17" y="38.1" size="1.27" layer="96" rot="R90"/>
</instance>
<instance part="SW1" gate="G$2" x="104.14" y="40.64" smashed="yes">
<attribute name="PART" x="99.06" y="45.72" size="1.27" layer="95"/>
<attribute name="VALUE" x="99.06" y="38.1" size="1.27" layer="96"/>
</instance>
<instance part="SW2" gate="G$1" x="83.82" y="5.08" smashed="yes">
<attribute name="PART" x="80.01" y="5.08" size="1.27" layer="95" rot="R90"/>
<attribute name="VALUE" x="90.17" y="5.08" size="1.27" layer="96" rot="R90"/>
</instance>
<instance part="SW2" gate="G$2" x="104.14" y="12.7" smashed="yes">
<attribute name="PART" x="99.06" y="17.78" size="1.27" layer="95"/>
<attribute name="VALUE" x="99.06" y="10.16" size="1.27" layer="96"/>
</instance>
<instance part="VR1" gate="A" x="0" y="76.2" smashed="yes">
<attribute name="NAME" x="-2.794" y="80.264" size="2.54" layer="95" align="top-left"/>
</instance>
<instance part="VR2" gate="A" x="0" y="48.26" smashed="yes">
<attribute name="NAME" x="-2.794" y="52.324" size="2.54" layer="95" align="top-left"/>
</instance>
<instance part="VR3" gate="A" x="-2.54" y="22.86" smashed="yes">
<attribute name="NAME" x="-5.334" y="26.924" size="2.54" layer="95" align="top-left"/>
</instance>
<instance part="GND1" gate="1" x="15.24" y="71.12" smashed="yes">
<attribute name="VALUE" x="12.7" y="68.58" size="1.778" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="15.24" y="43.18" smashed="yes">
<attribute name="VALUE" x="12.7" y="40.64" size="1.778" layer="96"/>
</instance>
<instance part="GND3" gate="1" x="12.7" y="17.78" smashed="yes">
<attribute name="VALUE" x="10.16" y="15.24" size="1.778" layer="96"/>
</instance>
<instance part="GND4" gate="1" x="83.82" y="0" smashed="yes">
<attribute name="VALUE" x="81.28" y="-2.54" size="1.778" layer="96"/>
</instance>
<instance part="GND5" gate="1" x="83.82" y="27.94" smashed="yes">
<attribute name="VALUE" x="81.28" y="25.4" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="109.22" y="38.1" smashed="yes">
<attribute name="VALUE" x="106.68" y="35.56" size="1.778" layer="96"/>
</instance>
<instance part="GND7" gate="1" x="109.22" y="10.16" smashed="yes">
<attribute name="VALUE" x="106.68" y="7.62" size="1.778" layer="96"/>
</instance>
<instance part="P+1" gate="VCC" x="-2.54" y="76.2" smashed="yes">
<attribute name="VALUE" x="-5.08" y="73.66" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="P+2" gate="VCC" x="-2.54" y="48.26" smashed="yes">
<attribute name="VALUE" x="-5.08" y="45.72" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="P+3" gate="VCC" x="-5.08" y="22.86" smashed="yes">
<attribute name="VALUE" x="-7.62" y="20.32" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="P+4" gate="VCC" x="33.02" y="81.28" smashed="yes">
<attribute name="VALUE" x="30.48" y="78.74" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="J1" gate="G$0" x="35.56" y="129.54" smashed="yes">
<attribute name="NAME" x="35.56" y="127" size="2.54" layer="95" align="top-left"/>
</instance>
<instance part="GND8" gate="1" x="76.2" y="111.76" smashed="yes">
<attribute name="VALUE" x="73.66" y="109.22" size="1.778" layer="96"/>
</instance>
<instance part="VR4" gate="A" x="-2.54" y="2.54" smashed="yes">
<attribute name="NAME" x="-5.334" y="6.604" size="2.54" layer="95" align="top-left"/>
</instance>
<instance part="P+5" gate="VCC" x="-5.08" y="2.54" smashed="yes">
<attribute name="VALUE" x="-7.62" y="0" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND9" gate="1" x="12.7" y="-2.54" smashed="yes">
<attribute name="VALUE" x="10.16" y="-5.08" size="1.778" layer="96"/>
</instance>
<instance part="SW3" gate="G$1" x="88.9" y="81.28" smashed="yes">
<attribute name="PART" x="85.09" y="81.28" size="1.27" layer="95" rot="R90"/>
<attribute name="VALUE" x="95.25" y="81.28" size="1.27" layer="96" rot="R90"/>
</instance>
<instance part="SW3" gate="G$2" x="109.22" y="91.44" smashed="yes">
<attribute name="PART" x="104.14" y="96.52" size="1.27" layer="95"/>
<attribute name="VALUE" x="104.14" y="88.9" size="1.27" layer="96"/>
</instance>
<instance part="GND10" gate="1" x="88.9" y="76.2" smashed="yes">
<attribute name="VALUE" x="86.36" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="GND11" gate="1" x="114.3" y="88.9" smashed="yes">
<attribute name="VALUE" x="111.76" y="86.36" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="VR1" gate="A" pin="3"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="VR2" gate="A" pin="3"/>
<pinref part="GND2" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="VR3" gate="A" pin="3"/>
<pinref part="GND3" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SW2" gate="G$1" pin="C"/>
<pinref part="GND4" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SW1" gate="G$1" pin="C"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="83.82" y1="35.56" x2="83.82" y2="30.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SW1" gate="G$2" pin="1"/>
<pinref part="GND6" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SW2" gate="G$2" pin="1"/>
<pinref part="GND7" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="J1" gate="G$0" pin="16"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="VR4" gate="A" pin="3"/>
<pinref part="GND9" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SW3" gate="G$1" pin="C"/>
<pinref part="GND10" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SW3" gate="G$2" pin="1"/>
<pinref part="GND11" gate="1" pin="GND"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="VR1" gate="A" pin="1"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="VR2" gate="A" pin="1"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="VR3" gate="A" pin="1"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="P+4" gate="VCC" pin="VCC"/>
<wire x1="33.02" y1="78.74" x2="33.02" y2="76.2" width="0.1524" layer="91"/>
<wire x1="33.02" y1="76.2" x2="38.1" y2="76.2" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="1"/>
<wire x1="38.1" y1="114.3" x2="38.1" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VR4" gate="A" pin="1"/>
<pinref part="P+5" gate="VCC" pin="VCC"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="VR1" gate="A" pin="2"/>
<wire x1="7.62" y1="66.04" x2="40.64" y2="66.04" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="2"/>
<wire x1="40.64" y1="114.3" x2="40.64" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="VR2" gate="A" pin="2"/>
<wire x1="7.62" y1="38.1" x2="43.18" y2="38.1" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="3"/>
<wire x1="43.18" y1="114.3" x2="43.18" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="VR3" gate="A" pin="2"/>
<wire x1="5.08" y1="12.7" x2="45.72" y2="12.7" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="4"/>
<wire x1="45.72" y1="114.3" x2="45.72" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="SW2" gate="G$1" pin="A"/>
<wire x1="81.28" y1="12.7" x2="81.28" y2="15.24" width="0.1524" layer="91"/>
<wire x1="81.28" y1="15.24" x2="50.8" y2="15.24" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="6"/>
<wire x1="50.8" y1="15.24" x2="50.8" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="SW2" gate="G$1" pin="B"/>
<wire x1="86.36" y1="12.7" x2="86.36" y2="17.78" width="0.1524" layer="91"/>
<wire x1="86.36" y1="17.78" x2="53.34" y2="17.78" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="7"/>
<wire x1="53.34" y1="17.78" x2="53.34" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="SW1" gate="G$1" pin="B"/>
<wire x1="86.36" y1="45.72" x2="86.36" y2="63.5" width="0.1524" layer="91"/>
<wire x1="58.42" y1="63.5" x2="86.36" y2="63.5" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="9"/>
<wire x1="58.42" y1="63.5" x2="58.42" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="SW2" gate="G$2" pin="2"/>
<wire x1="99.06" y1="12.7" x2="93.98" y2="12.7" width="0.1524" layer="91"/>
<wire x1="93.98" y1="12.7" x2="93.98" y2="68.58" width="0.1524" layer="91"/>
<wire x1="93.98" y1="68.58" x2="60.96" y2="68.58" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="10"/>
<wire x1="60.96" y1="68.58" x2="60.96" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="SW1" gate="G$2" pin="2"/>
<wire x1="99.06" y1="40.64" x2="99.06" y2="73.66" width="0.1524" layer="91"/>
<wire x1="99.06" y1="73.66" x2="63.5" y2="73.66" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="11"/>
<wire x1="63.5" y1="73.66" x2="63.5" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="SW1" gate="G$1" pin="A"/>
<wire x1="81.28" y1="45.72" x2="81.28" y2="58.42" width="0.1524" layer="91"/>
<wire x1="81.28" y1="58.42" x2="55.88" y2="58.42" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="8"/>
<wire x1="55.88" y1="58.42" x2="55.88" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="VR4" gate="A" pin="2"/>
<pinref part="J1" gate="G$0" pin="5"/>
<wire x1="5.08" y1="-7.62" x2="48.26" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="48.26" y1="-7.62" x2="48.26" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="SW3" gate="G$1" pin="A"/>
<pinref part="J1" gate="G$0" pin="12"/>
<wire x1="86.36" y1="88.9" x2="66.04" y2="88.9" width="0.1524" layer="91"/>
<wire x1="66.04" y1="88.9" x2="66.04" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="SW3" gate="G$1" pin="B"/>
<wire x1="91.44" y1="88.9" x2="91.44" y2="91.44" width="0.1524" layer="91"/>
<wire x1="91.44" y1="91.44" x2="68.58" y2="91.44" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="13"/>
<wire x1="68.58" y1="91.44" x2="68.58" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="SW3" gate="G$2" pin="2"/>
<wire x1="104.14" y1="91.44" x2="104.14" y2="93.98" width="0.1524" layer="91"/>
<wire x1="104.14" y1="93.98" x2="71.12" y2="93.98" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="14"/>
<wire x1="71.12" y1="93.98" x2="71.12" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
