<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="4" name="tKeepout" color="0" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="4" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="1" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="1" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="1" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="1" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="0" fill="1" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="1" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="4" fill="1" visible="no" active="no"/>
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
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Molex - 503182-1853" urn="urn:adsk.eagle:library:5794425">
<description>Upverter Parts Library

Created by Upverter.com</description>
<packages>
<package name="MOLEX_503182-1853_0" urn="urn:adsk.eagle:footprint:5794426/2" library_version="4">
<description>microSD Memory Card Connector</description>
<wire x1="-7.07" y1="-7.475" x2="-7.07" y2="7.475" width="0.15" layer="51"/>
<wire x1="-7.07" y1="7.475" x2="7.07" y2="7.475" width="0.15" layer="51"/>
<wire x1="7.07" y1="7.475" x2="7.07" y2="-7.475" width="0.15" layer="51"/>
<wire x1="7.07" y1="-7.475" x2="-7.07" y2="-7.475" width="0.15" layer="51"/>
<wire x1="-7.07" y1="-4.525" x2="-7.07" y2="2.975" width="0.15" layer="21"/>
<wire x1="7.07" y1="1.475" x2="7.07" y2="-4.525" width="0.15" layer="21"/>
<wire x1="3.5" y1="-7.475" x2="-1.25" y2="-7.475" width="0.15" layer="21"/>
<wire x1="-4.5" y1="-7.475" x2="-5.75" y2="-7.475" width="0.15" layer="21"/>
<wire x1="-7.07" y1="7.475" x2="7.07" y2="7.475" width="0.15" layer="21"/>
<wire x1="-7.07" y1="7.475" x2="-7.07" y2="6.975" width="0.15" layer="21"/>
<wire x1="7.07" y1="7.475" x2="7.07" y2="6.975" width="0.15" layer="21"/>
<text x="-6.825" y="8.025" size="1" layer="25">&gt;NAME</text>
<circle x="-2.9" y="6.875" radius="0.3" width="0" layer="21"/>
<rectangle x1="7.07" y1="-4.925" x2="7.47" y2="-2.525" layer="4"/>
<rectangle x1="-3.65" y1="-3.425" x2="5.55" y2="-0.025" layer="4"/>
<smd name="1" x="-2.9" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="11" x="-7.245" y="4.975" dx="0.95" dy="2.5" layer="1"/>
<smd name="2" x="-1.8" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="3" x="-0.7" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="4" x="0.4" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="5" x="1.5" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="6" x="2.6" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="7" x="3.7" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="8" x="4.8" y="5.605" dx="0.8" dy="1.24" layer="1"/>
<smd name="15" x="7.145" y="5.125" dx="1.15" dy="2.2" layer="1"/>
<smd name="9" x="6.74" y="2.975" dx="1.16" dy="1.25" layer="1"/>
<smd name="10" x="6.74" y="-6.025" dx="1.16" dy="1.2" layer="1"/>
<smd name="12" x="-7.145" y="-6.355" dx="1.15" dy="2.2" layer="1"/>
<smd name="13" x="-2.84" y="-7.15" dx="1.5" dy="1.15" layer="1"/>
<smd name="14" x="4.94" y="-7.15" dx="1.5" dy="1.15" layer="1"/>
</package>
</packages>
<packages3d>
<package3d name="MOLEX_503182-1853_0" urn="urn:adsk.eagle:package:5794428/3" type="model" library_version="4">
<description>microSD Memory Card Connector</description>
<packageinstances>
<packageinstance name="MOLEX_503182-1853_0"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MOLEX_503182-1853_0_0" urn="urn:adsk.eagle:symbol:5794427/1" library_version="3">
<description>microSD Memory Card Connector</description>
<wire x1="2.54" y1="-86.36" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="30.48" y2="-5.08" width="0.254" layer="94"/>
<wire x1="30.48" y1="-5.08" x2="30.48" y2="-86.36" width="0.254" layer="94"/>
<wire x1="30.48" y1="-86.36" x2="2.54" y2="-86.36" width="0.254" layer="94"/>
<wire x1="23.622" y1="-10.16" x2="30.48" y2="-10.16" width="0.508" layer="94"/>
<wire x1="23.622" y1="-15.24" x2="30.48" y2="-15.24" width="0.508" layer="94"/>
<wire x1="23.622" y1="-20.32" x2="30.48" y2="-20.32" width="0.508" layer="94"/>
<wire x1="23.622" y1="-25.4" x2="30.48" y2="-25.4" width="0.508" layer="94"/>
<wire x1="23.622" y1="-30.48" x2="30.48" y2="-30.48" width="0.508" layer="94"/>
<wire x1="23.622" y1="-35.56" x2="30.48" y2="-35.56" width="0.508" layer="94"/>
<wire x1="23.622" y1="-40.64" x2="30.48" y2="-40.64" width="0.508" layer="94"/>
<wire x1="23.622" y1="-45.72" x2="30.48" y2="-45.72" width="0.508" layer="94"/>
<wire x1="23.622" y1="-50.8" x2="30.48" y2="-50.8" width="0.508" layer="94"/>
<wire x1="23.622" y1="-55.88" x2="30.48" y2="-55.88" width="0.508" layer="94"/>
<wire x1="23.622" y1="-60.96" x2="30.48" y2="-60.96" width="0.508" layer="94"/>
<wire x1="23.622" y1="-66.04" x2="30.48" y2="-66.04" width="0.508" layer="94"/>
<wire x1="23.622" y1="-71.12" x2="30.48" y2="-71.12" width="0.508" layer="94"/>
<wire x1="23.622" y1="-76.2" x2="30.48" y2="-76.2" width="0.508" layer="94"/>
<wire x1="23.622" y1="-81.28" x2="30.48" y2="-81.28" width="0.508" layer="94"/>
<wire x1="30.48" y1="-10.16" x2="30.48" y2="-10.16" width="0.15" layer="94"/>
<wire x1="30.48" y1="-15.24" x2="30.48" y2="-15.24" width="0.15" layer="94"/>
<wire x1="30.48" y1="-20.32" x2="30.48" y2="-20.32" width="0.15" layer="94"/>
<wire x1="30.48" y1="-25.4" x2="30.48" y2="-25.4" width="0.15" layer="94"/>
<wire x1="30.48" y1="-30.48" x2="30.48" y2="-30.48" width="0.15" layer="94"/>
<wire x1="30.48" y1="-35.56" x2="30.48" y2="-35.56" width="0.15" layer="94"/>
<wire x1="30.48" y1="-40.64" x2="30.48" y2="-40.64" width="0.15" layer="94"/>
<wire x1="30.48" y1="-45.72" x2="30.48" y2="-45.72" width="0.15" layer="94"/>
<wire x1="30.48" y1="-50.8" x2="30.48" y2="-50.8" width="0.15" layer="94"/>
<wire x1="30.48" y1="-55.88" x2="30.48" y2="-55.88" width="0.15" layer="94"/>
<wire x1="30.48" y1="-60.96" x2="30.48" y2="-60.96" width="0.15" layer="94"/>
<wire x1="30.48" y1="-66.04" x2="30.48" y2="-66.04" width="0.15" layer="94"/>
<wire x1="30.48" y1="-71.12" x2="30.48" y2="-71.12" width="0.15" layer="94"/>
<wire x1="30.48" y1="-76.2" x2="30.48" y2="-76.2" width="0.15" layer="94"/>
<wire x1="30.48" y1="-81.28" x2="30.48" y2="-81.28" width="0.15" layer="94"/>
<text x="2.54" y="-2.54" size="2.54" layer="95" align="top-left">&gt;NAME</text>
<text x="2.54" y="-88.9" size="2.54" layer="95" align="top-left">503182-1853</text>
<pin name="DATA2" x="35.56" y="-10.16" visible="pad" length="middle" rot="R180"/>
<pin name="CD/DAT3" x="35.56" y="-15.24" visible="pad" length="middle" rot="R180"/>
<pin name="CMD" x="35.56" y="-20.32" visible="pad" length="middle" rot="R180"/>
<pin name="VDD" x="35.56" y="-25.4" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="CLK" x="35.56" y="-30.48" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="VSS" x="35.56" y="-35.56" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="DAT0" x="35.56" y="-40.64" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="DAT1" x="35.56" y="-45.72" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="MNT_1" x="35.56" y="-50.8" visible="pad" length="middle" rot="R180"/>
<pin name="MNT_2" x="35.56" y="-55.88" visible="pad" length="middle" rot="R180"/>
<pin name="SWITCH" x="35.56" y="-60.96" visible="pad" length="middle" rot="R180"/>
<pin name="MNT_3" x="35.56" y="-66.04" visible="pad" length="middle" rot="R180"/>
<pin name="DETECT" x="35.56" y="-71.12" visible="pad" length="middle" rot="R180"/>
<pin name="MNT_4" x="35.56" y="-76.2" visible="pad" length="middle" rot="R180"/>
<pin name="MNT_5" x="35.56" y="-81.28" visible="pad" length="middle" rot="R180"/>
<circle x="22.86" y="-10.16" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-15.24" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-20.32" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-25.4" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-30.48" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-35.56" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-40.64" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-45.72" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-50.8" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-55.88" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-60.96" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-66.04" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-71.12" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-76.2" radius="0.762" width="0.254" layer="94"/>
<circle x="22.86" y="-81.28" radius="0.762" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOLEX_503182-1853" urn="urn:adsk.eagle:component:5794429/3" prefix="J" library_version="4">
<description>microSD Memory Card Connector</description>
<gates>
<gate name="G$0" symbol="MOLEX_503182-1853_0_0" x="0" y="0"/>
</gates>
<devices>
<device name="MOLEX_503182-1853_0_0" package="MOLEX_503182-1853_0">
<connects>
<connect gate="G$0" pin="CD/DAT3" pad="2"/>
<connect gate="G$0" pin="CLK" pad="5"/>
<connect gate="G$0" pin="CMD" pad="3"/>
<connect gate="G$0" pin="DAT0" pad="7"/>
<connect gate="G$0" pin="DAT1" pad="8"/>
<connect gate="G$0" pin="DATA2" pad="1"/>
<connect gate="G$0" pin="DETECT" pad="13"/>
<connect gate="G$0" pin="MNT_1" pad="9"/>
<connect gate="G$0" pin="MNT_2" pad="10"/>
<connect gate="G$0" pin="MNT_3" pad="12"/>
<connect gate="G$0" pin="MNT_4" pad="14"/>
<connect gate="G$0" pin="MNT_5" pad="15"/>
<connect gate="G$0" pin="SWITCH" pad="11"/>
<connect gate="G$0" pin="VDD" pad="4"/>
<connect gate="G$0" pin="VSS" pad="6"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5794428/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CARD_DETECTION_SWITCH" value="Yes"/>
<attribute name="CENTROID_NOT_SPECIFIED" value="No"/>
<attribute name="CIRCUITS" value="8"/>
<attribute name="CURRENT-MAX_PER_CONTACT" value="0.5A"/>
<attribute name="DATASHEET" value="http://www.molex.com/pdm_docs/sd/5031821853_sd.pdf"/>
<attribute name="DIGIKEY_DESCRIPTION" value="CONN 10 (8 + 2) Position Card Connector Secure Digital - microSD™ Surface Mount, Right Angle Gold"/>
<attribute name="DIGIKEY_PART_NUMBER" value="WM9750CT-ND"/>
<attribute name="DURABILITY(MATING_CYCLES_MAX)" value="10000"/>
<attribute name="ENTRY_ANGLE" value="90° Angle"/>
<attribute name="IS_FEMALE" value="yes"/>
<attribute name="LEAD_FREE" value="yes"/>
<attribute name="MF" value="Molex"/>
<attribute name="MFG_PACKAGE_IDENT" value="5031821853"/>
<attribute name="MOUNTING_TYPE" value="Surface Mount, Right Angle"/>
<attribute name="MOUSER_PART_NUMBER" value="538-503182-1853"/>
<attribute name="MPN" value="503182-1853"/>
<attribute name="PACKAGE" value="CONN_MICRO_SD"/>
<attribute name="PREFIX" value="J"/>
<attribute name="ROHS" value="yes"/>
<attribute name="TEMPERATURE_RANGE_HIGH" value="+85°C"/>
<attribute name="TEMPERATURE_RANGE_LOW" value="-25°C"/>
<attribute name="VOLTAGE" value="10V AC(RMS)/DC"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Molex - 54550-0871" urn="urn:adsk.eagle:library:5794469">
<description>Upverter Parts Library

Created by Upverter.com</description>
<packages>
<package name="MOLEX_54550-0871_0" urn="urn:adsk.eagle:footprint:5794470/2" library_version="3">
<description>MOLX-54550-0871</description>
<wire x1="2.25" y1="0.6" x2="2.25" y2="0.7" width="0.1" layer="51"/>
<wire x1="-2.25" y1="0.6" x2="-2.25" y2="0.7" width="0.1" layer="51"/>
<wire x1="-4.55" y1="0.7" x2="-2.25" y2="0.7" width="0.1" layer="51"/>
<wire x1="-2.25" y1="0.6" x2="2.25" y2="0.6" width="0.1" layer="51"/>
<wire x1="-4.6" y1="-3.05" x2="-4" y2="-3.05" width="0.1" layer="51"/>
<wire x1="4.55" y1="-0.1" x2="4.55" y2="0.7" width="0.1" layer="51"/>
<wire x1="2.25" y1="0.7" x2="4.55" y2="0.7" width="0.1" layer="51"/>
<wire x1="-4.55" y1="-0.1" x2="-4.55" y2="0.7" width="0.1" layer="51"/>
<wire x1="-4" y1="-3.05" x2="-4" y2="-0.1" width="0.1" layer="51"/>
<wire x1="-4.55" y1="-0.1" x2="-4" y2="-0.1" width="0.1" layer="51"/>
<wire x1="4" y1="-0.1" x2="4.55" y2="-0.1" width="0.1" layer="51"/>
<wire x1="4.6" y1="-3.85" x2="4.6" y2="-3.05" width="0.1" layer="51"/>
<wire x1="-4.6" y1="-3.85" x2="4.6" y2="-3.85" width="0.1" layer="51"/>
<wire x1="-4.6" y1="-3.85" x2="-4.6" y2="-3.05" width="0.1" layer="51"/>
<wire x1="4" y1="-3.05" x2="4" y2="-0.1" width="0.1" layer="51"/>
<wire x1="4" y1="-3.05" x2="4.6" y2="-3.05" width="0.1" layer="51"/>
<wire x1="-4" y1="-3.05" x2="-4" y2="-2" width="0.15" layer="21"/>
<wire x1="-4.55" y1="0.1" x2="-4.55" y2="0.7" width="0.15" layer="21"/>
<wire x1="-4.55" y1="0.7" x2="-2.3" y2="0.7" width="0.15" layer="21"/>
<wire x1="-4.6" y1="-3.05" x2="-4" y2="-3.05" width="0.15" layer="21"/>
<wire x1="-4.6" y1="-3.85" x2="4.6" y2="-3.85" width="0.15" layer="21"/>
<wire x1="-4.6" y1="-3.85" x2="-4.6" y2="-3.05" width="0.15" layer="21"/>
<wire x1="2.3" y1="0.7" x2="4.55" y2="0.7" width="0.15" layer="21"/>
<wire x1="4" y1="-3.05" x2="4" y2="-2" width="0.15" layer="21"/>
<wire x1="4" y1="-3.05" x2="4.6" y2="-3.05" width="0.15" layer="21"/>
<wire x1="4.55" y1="0.1" x2="4.55" y2="0.7" width="0.15" layer="21"/>
<wire x1="4.6" y1="-3.85" x2="4.6" y2="-3.05" width="0.15" layer="21"/>
<text x="-5.95" y="2.125" size="1" layer="25">&gt;NAME</text>
<circle x="-1.75" y="2" radius="0.125" width="0.25" layer="21"/>
<smd name="1" x="-1.75" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="2" x="-1.25" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="4" x="-0.25" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="3" x="-0.75" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="MP2" x="4.025" y="-0.95" dx="1.65" dy="1.3" layer="1"/>
<smd name="MP1" x="-4.025" y="-0.95" dx="1.65" dy="1.3" layer="1"/>
<smd name="5" x="0.25" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="6" x="0.75" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="8" x="1.75" y="0.95" dx="0.3" dy="1" layer="1"/>
<smd name="7" x="1.25" y="0.95" dx="0.3" dy="1" layer="1"/>
</package>
</packages>
<packages3d>
<package3d name="MOLEX_54550-0871_0" urn="urn:adsk.eagle:package:5794472/3" type="model" library_version="3">
<description>MOLX-54550-0871</description>
<packageinstances>
<packageinstance name="MOLEX_54550-0871_0"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MOLEX_54550-0871_0_0" urn="urn:adsk.eagle:symbol:5794471/1" library_version="2">
<description>MOLX-54550-0871</description>
<wire x1="0" y1="-10.16" x2="0" y2="-5.08" width="0.254" layer="94"/>
<wire x1="0" y1="-5.08" x2="30.48" y2="-5.08" width="0.254" layer="94"/>
<wire x1="30.48" y1="-5.08" x2="30.48" y2="-10.16" width="0.254" layer="94"/>
<wire x1="30.48" y1="-10.16" x2="0" y2="-10.16" width="0.254" layer="94"/>
<wire x1="20.32" y1="-10.16" x2="20.32" y2="-8.382" width="0.254" layer="94"/>
<wire x1="17.78" y1="-10.16" x2="17.78" y2="-8.382" width="0.254" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="15.24" y2="-8.382" width="0.254" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="12.7" y2="-8.382" width="0.254" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="10.16" y2="-8.382" width="0.254" layer="94"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="-8.382" width="0.254" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="5.08" y2="-8.382" width="0.254" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="2.54" y2="-8.382" width="0.254" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="2.54" y2="-10.16" width="0.15" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="5.08" y2="-10.16" width="0.15" layer="94"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="-10.16" width="0.15" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="10.16" y2="-10.16" width="0.15" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="12.7" y2="-10.16" width="0.15" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="15.24" y2="-10.16" width="0.15" layer="94"/>
<wire x1="17.78" y1="-10.16" x2="17.78" y2="-10.16" width="0.15" layer="94"/>
<wire x1="20.32" y1="-10.16" x2="20.32" y2="-10.16" width="0.15" layer="94"/>
<wire x1="25.4" y1="-10.16" x2="25.4" y2="-10.16" width="0.15" layer="94"/>
<wire x1="27.94" y1="-10.16" x2="27.94" y2="-10.16" width="0.15" layer="94"/>
<text x="0" y="-2.54" size="2.54" layer="95" align="top-left">&gt;NAME</text>
<text x="0" y="-15.24" size="2.54" layer="95" align="top-left">54550-0871</text>
<pin name="1" x="2.54" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="2" x="5.08" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="3" x="7.62" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="4" x="10.16" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="5" x="12.7" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="6" x="15.24" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="7" x="17.78" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="8" x="20.32" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="MP1" x="25.4" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="MP2" x="27.94" y="-15.24" visible="pad" length="middle" direction="pas" rot="R90"/>
<circle x="20.32" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="17.78" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="15.24" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="12.7" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="10.16" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="7.62" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="5.08" y="-7.62" radius="0.762" width="0.254" layer="94"/>
<circle x="2.54" y="-7.62" radius="0.762" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOLEX_54550-0871" urn="urn:adsk.eagle:component:5794473/3" prefix="J" library_version="3">
<description>MOLX-54550-0871</description>
<gates>
<gate name="G$0" symbol="MOLEX_54550-0871_0_0" x="0" y="0"/>
</gates>
<devices>
<device name="MOLEX_54550-0871_0_0" package="MOLEX_54550-0871_0">
<connects>
<connect gate="G$0" pin="1" pad="1"/>
<connect gate="G$0" pin="2" pad="2"/>
<connect gate="G$0" pin="3" pad="3"/>
<connect gate="G$0" pin="4" pad="4"/>
<connect gate="G$0" pin="5" pad="5"/>
<connect gate="G$0" pin="6" pad="6"/>
<connect gate="G$0" pin="7" pad="7"/>
<connect gate="G$0" pin="8" pad="8"/>
<connect gate="G$0" pin="MP1" pad="MP1"/>
<connect gate="G$0" pin="MP2" pad="MP2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5794472/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CIIVA_IDS" value="3405314"/>
<attribute name="CIRCUITS_LOADED" value="8"/>
<attribute name="COMPONENT_LINK_1_DESCRIPTION" value="Manufacturer URL"/>
<attribute name="COMPONENT_LINK_1_URL" value="http://www.molex.com/molex/index.jsp"/>
<attribute name="COMPONENT_LINK_3_DESCRIPTION" value="Package Specification"/>
<attribute name="COMPONENT_LINK_3_URL" value="http://www.molex.com/pdm_docs/sd/545500871_sd.pdf"/>
<attribute name="CONTACT_POSITION" value="Top"/>
<attribute name="CURRENT_MAX_PER_CONTACT" value="0.5A"/>
<attribute name="DATASHEET" value="http://www.molex.com/webdocs/datasheets/pdf/en-us/0545500871_FFC_FPC_CONNECTORS.pdf"/>
<attribute name="DURABILITY_MATING_CYCLES_MAX" value="20"/>
<attribute name="ENTRY_ANGLE" value="90degrees Angle"/>
<attribute name="FOOTPRINT_VARIANT_NAME_0" value="Manufacturer Recommended"/>
<attribute name="IMPORTED" value="yes"/>
<attribute name="IMPORTED_FROM" value="vault"/>
<attribute name="IMPORT_TS" value="1521843996"/>
<attribute name="MATED_HEIGHT" value="1.20mm"/>
<attribute name="MATERIAL___METAL" value="Phosphor Bronze"/>
<attribute name="MATERIAL___PLATING_MATING" value="Gold"/>
<attribute name="MATERIAL___PLATING_TERMINATION" value="Tin"/>
<attribute name="MF" value="Molex"/>
<attribute name="MOUNTING_TECHNOLOGY" value="Surface Mount"/>
<attribute name="MPN" value="54550-0871"/>
<attribute name="NUMBER_OF_ROWS" value="1"/>
<attribute name="ORIENTATION" value="Right Angle"/>
<attribute name="PACKAGE" value="54550-0871"/>
<attribute name="PACKAGE_DESCRIPTION" value="8-Lead FPC Connector, Pitch 0.5 mm"/>
<attribute name="PACKAGE_VERSION" value="Rev. M, 12/2009"/>
<attribute name="PACKING" value="Tape and Reel"/>
<attribute name="PCB_LOCATOR" value="No"/>
<attribute name="PCB_RETENTION" value="Yes"/>
<attribute name="PITCH___MATING_INTERFACE" value="0.50mm"/>
<attribute name="POLARIZED_TO_PCB" value="Yes"/>
<attribute name="PREFIX" value="J"/>
<attribute name="RELEASE_DATE" value="1411372735"/>
<attribute name="ROHS" value="Yes"/>
<attribute name="STACKABLE" value="No"/>
<attribute name="VAULT_GUID" value="4F5E3AE4-AE0A-4DC1-8CF3-4F404F9FC512"/>
<attribute name="VAULT_REVISION" value="F633CFB0-ED6A-4DFE-8830-DF58A16BDF03"/>
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
<part name="J1" library="Molex - 503182-1853" library_urn="urn:adsk.eagle:library:5794425" deviceset="MOLEX_503182-1853" device="MOLEX_503182-1853_0_0" package3d_urn="urn:adsk.eagle:package:5794428/3"/>
<part name="J2" library="Molex - 54550-0871" library_urn="urn:adsk.eagle:library:5794469" deviceset="MOLEX_54550-0871" device="MOLEX_54550-0871_0_0" package3d_urn="urn:adsk.eagle:package:5794472/3"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="J1" gate="G$0" x="-2.54" y="86.36">
<attribute name="NAME" x="0" y="83.82" size="2.54" layer="95" align="top-left"/>
</instance>
<instance part="J2" gate="G$0" x="76.2" y="78.74" rot="R270">
<attribute name="NAME" x="73.66" y="78.74" size="2.54" layer="95" rot="R270" align="top-left"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="J1" gate="G$0" pin="DATA2"/>
<pinref part="J2" gate="G$0" pin="1"/>
<wire x1="33.02" y1="76.2" x2="60.96" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="2"/>
<wire x1="60.96" y1="73.66" x2="35.56" y2="73.66" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="CD/DAT3"/>
<wire x1="35.56" y1="73.66" x2="33.02" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="3"/>
<wire x1="60.96" y1="71.12" x2="38.1" y2="71.12" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="CMD"/>
<wire x1="38.1" y1="71.12" x2="33.02" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="4"/>
<wire x1="60.96" y1="68.58" x2="40.64" y2="68.58" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="VDD"/>
<wire x1="40.64" y1="68.58" x2="33.02" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="5"/>
<wire x1="60.96" y1="66.04" x2="43.18" y2="66.04" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="CLK"/>
<wire x1="43.18" y1="66.04" x2="33.02" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="6"/>
<wire x1="60.96" y1="63.5" x2="45.72" y2="63.5" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="VSS"/>
<wire x1="45.72" y1="63.5" x2="33.02" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="7"/>
<wire x1="60.96" y1="60.96" x2="48.26" y2="60.96" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="DAT0"/>
<wire x1="48.26" y1="60.96" x2="33.02" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="J2" gate="G$0" pin="8"/>
<wire x1="60.96" y1="58.42" x2="50.8" y2="58.42" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$0" pin="DAT1"/>
<wire x1="50.8" y1="58.42" x2="33.02" y2="40.64" width="0.1524" layer="91"/>
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
