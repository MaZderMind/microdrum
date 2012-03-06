<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
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
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="7" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="7" fill="1" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="alps">
<description>&lt;B&gt;ALPS Encoders, Potentiometers &amp;amp; Stick Controllers&lt;/B&gt;
&lt;br&gt;&lt;br&gt;
STEC12Exx&lt;br&gt;
RK09K11x&lt;br&gt;
RKJXP&lt;br&gt;
&lt;br&gt;
2008-2009 MrMcCrash</description>
<packages>
<package name="RK09K113">
<wire x1="-4.9" y1="5.5" x2="4.9" y2="5.5" width="0.127" layer="21"/>
<wire x1="4.9" y1="5.5" x2="4.9" y2="-5.4" width="0.127" layer="21"/>
<wire x1="4.9" y1="-5.4" x2="-4.9" y2="-5.4" width="0.127" layer="21"/>
<wire x1="-4.9" y1="-5.4" x2="-4.9" y2="5.5" width="0.127" layer="21"/>
<circle x="0" y="0" radius="3.4" width="0" layer="21"/>
<pad name="CASE1" x="-5.3" y="0" drill="2.2" shape="long" rot="R90"/>
<pad name="CASE2" x="5.3" y="0" drill="2.2" shape="long" rot="R90"/>
<pad name="B" x="2.5" y="-7" drill="1" shape="long" rot="R90"/>
<pad name="C" x="0" y="-7" drill="1" shape="long" rot="R90"/>
<pad name="A" x="-2.5" y="-7" drill="1" shape="long" rot="R90"/>
<text x="-5.1" y="1.8" size="1.27" layer="21" rot="R90">&gt;NAME</text>
<text x="6.4" y="1.8" size="1.27" layer="21" rot="R90">&gt;VALUE</text>
<rectangle x1="-5.5" y1="-1" x2="-5.1" y2="1" layer="21"/>
<rectangle x1="5.1" y1="-1" x2="5.5" y2="1" layer="21"/>
<rectangle x1="-2.8" y1="-7.3" x2="-2.2" y2="-6.7" layer="21"/>
<rectangle x1="-0.3" y1="-7.3" x2="0.3" y2="-6.7" layer="21"/>
<rectangle x1="2.2" y1="-7.3" x2="2.8" y2="-6.7" layer="21"/>
</package>
<package name="RK09K111">
<wire x1="-4.9" y1="2.4" x2="-4.7" y2="2.4" width="0.127" layer="21"/>
<wire x1="-4.7" y1="2.4" x2="-4.7" y2="0" width="0.127" layer="21"/>
<wire x1="-4.7" y1="0" x2="4.7" y2="0" width="0.127" layer="21"/>
<wire x1="4.7" y1="0" x2="4.7" y2="2.4" width="0.127" layer="21"/>
<wire x1="4.7" y1="2.4" x2="4.9" y2="2.4" width="0.127" layer="21"/>
<wire x1="4.9" y1="2.4" x2="4.9" y2="-7.6" width="0.127" layer="21"/>
<wire x1="4.9" y1="-7.6" x2="3" y2="-7.6" width="0.127" layer="21"/>
<wire x1="3" y1="-7.6" x2="-3" y2="-7.6" width="0.127" layer="21"/>
<wire x1="-3" y1="-7.6" x2="-4.9" y2="-7.6" width="0.127" layer="21"/>
<wire x1="-4.9" y1="-7.6" x2="-4.9" y2="2.4" width="0.127" layer="21"/>
<wire x1="-3" y1="-7.6" x2="-3" y2="-13" width="0.127" layer="21"/>
<wire x1="-3" y1="-13" x2="-3" y2="-20" width="0.127" layer="21"/>
<wire x1="-3" y1="-20" x2="-2.5" y2="-20" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-20" x2="-2" y2="-20" width="0.127" layer="21"/>
<wire x1="-2" y1="-20" x2="-1.5" y2="-20" width="0.127" layer="21"/>
<wire x1="-1.5" y1="-20" x2="-1" y2="-20" width="0.127" layer="21"/>
<wire x1="-1" y1="-20" x2="-0.5" y2="-20" width="0.127" layer="21"/>
<wire x1="-0.5" y1="-20" x2="0.5" y2="-20" width="0.127" layer="21"/>
<wire x1="0.5" y1="-20" x2="1" y2="-20" width="0.127" layer="21"/>
<wire x1="1" y1="-20" x2="1.5" y2="-20" width="0.127" layer="21"/>
<wire x1="1.5" y1="-20" x2="2" y2="-20" width="0.127" layer="21"/>
<wire x1="2" y1="-20" x2="2.5" y2="-20" width="0.127" layer="21"/>
<wire x1="2.5" y1="-20" x2="3" y2="-20" width="0.127" layer="21"/>
<wire x1="3" y1="-20" x2="3" y2="-13" width="0.127" layer="21"/>
<wire x1="3" y1="-13" x2="3" y2="-7.6" width="0.127" layer="21"/>
<wire x1="-3" y1="-13" x2="-2.5" y2="-13" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-13" x2="-2" y2="-13" width="0.127" layer="21"/>
<wire x1="-2" y1="-13" x2="-1.5" y2="-13" width="0.127" layer="21"/>
<wire x1="-1.5" y1="-13" x2="-1" y2="-13" width="0.127" layer="21"/>
<wire x1="-1" y1="-13" x2="-0.5" y2="-13" width="0.127" layer="21"/>
<wire x1="-0.5" y1="-13" x2="0" y2="-13" width="0.127" layer="21"/>
<wire x1="0" y1="-13" x2="0.5" y2="-13" width="0.127" layer="21"/>
<wire x1="0.5" y1="-13" x2="1" y2="-13" width="0.127" layer="21"/>
<wire x1="1" y1="-13" x2="1.5" y2="-13" width="0.127" layer="21"/>
<wire x1="1.5" y1="-13" x2="2" y2="-13" width="0.127" layer="21"/>
<wire x1="2" y1="-13" x2="2.5" y2="-13" width="0.127" layer="21"/>
<wire x1="2.5" y1="-13" x2="3" y2="-13" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-13" x2="-2.5" y2="-20" width="0.127" layer="21"/>
<wire x1="-2" y1="-20" x2="-2" y2="-13" width="0.127" layer="21"/>
<wire x1="-1.5" y1="-13" x2="-1.5" y2="-20" width="0.127" layer="21"/>
<wire x1="-1" y1="-13" x2="-1" y2="-20" width="0.127" layer="21"/>
<wire x1="-0.5" y1="-13" x2="-0.5" y2="-20" width="0.127" layer="21"/>
<wire x1="0.5" y1="-13" x2="0.5" y2="-20" width="0.127" layer="21"/>
<wire x1="2.5" y1="-13" x2="2.5" y2="-20" width="0.127" layer="21"/>
<wire x1="1.5" y1="-13" x2="1.5" y2="-20" width="0.127" layer="21"/>
<wire x1="1" y1="-13" x2="1" y2="-20" width="0.127" layer="21"/>
<wire x1="2" y1="-13" x2="2" y2="-20" width="0.127" layer="21"/>
<wire x1="0" y1="-13" x2="0" y2="-17" width="0.127" layer="21"/>
<pad name="CASE1" x="-5.3" y="0" drill="2.2" shape="long" rot="R270"/>
<pad name="CASE2" x="5.3" y="0" drill="2.2" shape="long" rot="R90"/>
<pad name="B" x="2.5" y="-3.3" drill="1" shape="long" rot="R90"/>
<pad name="C" x="0" y="-3.3" drill="1" shape="long" rot="R90"/>
<pad name="A" x="-2.5" y="-3.3" drill="1" shape="long" rot="R90"/>
<text x="-3.5" y="4.1" size="1.27" layer="21">&gt;NAME</text>
<text x="-3.5" y="2.6" size="1.27" layer="21">&gt;VALUE</text>
<rectangle x1="-5.4" y1="-1" x2="-5" y2="1" layer="21"/>
<rectangle x1="5" y1="-1" x2="5.4" y2="1" layer="21"/>
<rectangle x1="-2.8" y1="-3.6" x2="-2.2" y2="-3" layer="21"/>
<rectangle x1="-0.3" y1="-3.6" x2="0.3" y2="-3" layer="21"/>
<rectangle x1="2.2" y1="-3.6" x2="2.8" y2="-3" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="POT-EU-SHIELD">
<wire x1="1.27" y1="0" x2="2.54" y2="1.27" width="0.2032" layer="94"/>
<wire x1="2.54" y1="-1.27" x2="1.27" y2="0" width="0.2032" layer="94"/>
<wire x1="2.54" y1="1.27" x2="2.54" y2="-1.27" width="0.2032" layer="94"/>
<wire x1="2.032" y1="-4.699" x2="2.032" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="2.032" y1="-2.159" x2="2.667" y2="-3.429" width="0.1524" layer="94"/>
<wire x1="2.667" y1="-3.429" x2="1.397" y2="-3.429" width="0.1524" layer="94"/>
<wire x1="1.397" y1="-3.429" x2="2.032" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="-1.016" y1="-2.54" x2="1.016" y2="-2.54" width="0.254" layer="94"/>
<wire x1="1.016" y1="-2.54" x2="1.016" y2="2.54" width="0.254" layer="94"/>
<wire x1="1.016" y1="2.54" x2="-1.016" y2="2.54" width="0.254" layer="94"/>
<wire x1="-1.016" y1="2.54" x2="-1.016" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="-2.54" y2="-5.08" width="0.254" layer="94" style="shortdash"/>
<wire x1="-2.54" y1="-5.08" x2="-2.54" y2="5.08" width="0.254" layer="94" style="shortdash"/>
<wire x1="-2.54" y1="5.08" x2="2.54" y2="5.08" width="0.254" layer="94" style="shortdash"/>
<text x="-7.62" y="-2.54" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="-5.08" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<text x="2.54" y="-8.89" size="1.27" layer="95" rot="R90">A</text>
<text x="5.08" y="-1.27" size="1.27" layer="95" rot="R90">C</text>
<text x="2.54" y="7.874" size="1.27" layer="95" rot="R90">B</text>
<pin name="A" x="0" y="-7.62" visible="off" length="middle" direction="pas" rot="R90"/>
<pin name="B" x="0" y="7.62" visible="off" length="middle" direction="pas" rot="R270"/>
<pin name="C" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<pin name="CASE1" x="5.08" y="-5.08" visible="off" length="short" direction="pas" rot="R180"/>
<pin name="CASE2" x="5.08" y="5.08" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="RK09K" prefix="VR" uservalue="yes">
<description>&lt;b&gt;Insulated Shaft Potentiometer&lt;/b&gt;&lt;br&gt;
&lt;br&gt;
ALPS Electric Co&lt;br&gt;
9mm Size Snap-in Insulated Shaft Type RK09K&lt;br&gt;
&lt;br&gt;
-111: horizontal Package&lt;br&gt;
-113: vertical Package&lt;br&gt;
&lt;hr&gt;
Reichelt Part No.&lt;br&gt;
RK09K111-/RK09K113-&lt;br&gt;
LIN10K, 50K, 100K&lt;br&gt;
LOG10K, 50K, 100K&lt;br&gt;</description>
<gates>
<gate name="G$1" symbol="POT-EU-SHIELD" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="113" package="RK09K113">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="B" pad="B"/>
<connect gate="G$1" pin="C" pad="C"/>
<connect gate="G$1" pin="CASE1" pad="CASE1"/>
<connect gate="G$1" pin="CASE2" pad="CASE2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="111" package="RK09K111">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="B" pad="B"/>
<connect gate="G$1" pin="C" pad="C"/>
<connect gate="G$1" pin="CASE1" pad="CASE1"/>
<connect gate="G$1" pin="CASE2" pad="CASE2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="40xx">
<description>&lt;b&gt;CMOS Logic Devices, 4000 Series&lt;/b&gt;&lt;p&gt;
Based on the following sources:
&lt;ul&gt;
&lt;li&gt;Motorola &lt;i&gt;CMOS LOGIC DATA&lt;/i&gt;; book, 02/88, DL131 REV 1
&lt;li&gt;http://www.elexp.com
&lt;li&gt;http://www.intersil.com
&lt;li&gt;http://www.ls3c.com.tw/product/1/COMOS.html
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DIL16">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;</description>
<wire x1="10.16" y1="2.921" x2="-10.16" y2="2.921" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="10.16" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="10.16" y1="2.921" x2="10.16" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="2.921" x2="-10.16" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="-10.16" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.016" x2="-10.16" y2="-1.016" width="0.1524" layer="21" curve="-180"/>
<pad name="1" x="-8.89" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="9" x="8.89" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="10" x="6.35" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="11" x="3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="12" x="1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="13" x="-1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="14" x="-3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="15" x="-6.35" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="16" x="-8.89" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-10.541" y="-2.921" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-7.493" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="SO16">
<description>&lt;b&gt;Small Outline package&lt;/b&gt; 150 mil</description>
<wire x1="4.699" y1="1.9558" x2="-4.699" y2="1.9558" width="0.1524" layer="21"/>
<wire x1="4.699" y1="-1.9558" x2="5.08" y2="-1.5748" width="0.1524" layer="21" curve="90"/>
<wire x1="-5.08" y1="1.5748" x2="-4.699" y2="1.9558" width="0.1524" layer="21" curve="-90"/>
<wire x1="4.699" y1="1.9558" x2="5.08" y2="1.5748" width="0.1524" layer="21" curve="-90"/>
<wire x1="-5.08" y1="-1.5748" x2="-4.699" y2="-1.9558" width="0.1524" layer="21" curve="90"/>
<wire x1="-4.699" y1="-1.9558" x2="4.699" y2="-1.9558" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.5748" x2="5.08" y2="1.5748" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.5748" x2="-5.08" y2="0.508" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.508" x2="-5.08" y2="-0.508" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.508" x2="-5.08" y2="-1.5748" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.508" x2="-5.08" y2="-0.508" width="0.1524" layer="21" curve="-180"/>
<wire x1="-5.08" y1="-1.6002" x2="5.08" y2="-1.6002" width="0.0508" layer="21"/>
<smd name="1" x="-4.445" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="16" x="-4.445" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="2" x="-3.175" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="3" x="-1.905" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="15" x="-3.175" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="14" x="-1.905" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="4" x="-0.635" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="13" x="-0.635" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="5" x="0.635" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="12" x="0.635" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="6" x="1.905" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="7" x="3.175" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="11" x="1.905" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="10" x="3.175" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="8" x="4.445" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="9" x="4.445" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<text x="-4.064" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="-5.461" y="-2.032" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<rectangle x1="-0.889" y1="1.9558" x2="-0.381" y2="3.0988" layer="51"/>
<rectangle x1="-4.699" y1="-3.0988" x2="-4.191" y2="-1.9558" layer="51"/>
<rectangle x1="-3.429" y1="-3.0988" x2="-2.921" y2="-1.9558" layer="51"/>
<rectangle x1="-2.159" y1="-3.0734" x2="-1.651" y2="-1.9304" layer="51"/>
<rectangle x1="-0.889" y1="-3.0988" x2="-0.381" y2="-1.9558" layer="51"/>
<rectangle x1="-2.159" y1="1.9558" x2="-1.651" y2="3.0988" layer="51"/>
<rectangle x1="-3.429" y1="1.9558" x2="-2.921" y2="3.0988" layer="51"/>
<rectangle x1="-4.699" y1="1.9558" x2="-4.191" y2="3.0988" layer="51"/>
<rectangle x1="0.381" y1="-3.0988" x2="0.889" y2="-1.9558" layer="51"/>
<rectangle x1="1.651" y1="-3.0988" x2="2.159" y2="-1.9558" layer="51"/>
<rectangle x1="2.921" y1="-3.0988" x2="3.429" y2="-1.9558" layer="51"/>
<rectangle x1="4.191" y1="-3.0988" x2="4.699" y2="-1.9558" layer="51"/>
<rectangle x1="0.381" y1="1.9558" x2="0.889" y2="3.0988" layer="51"/>
<rectangle x1="1.651" y1="1.9558" x2="2.159" y2="3.0988" layer="51"/>
<rectangle x1="2.921" y1="1.9558" x2="3.429" y2="3.0988" layer="51"/>
<rectangle x1="4.191" y1="1.9558" x2="4.699" y2="3.0988" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="4051">
<wire x1="-7.62" y1="-17.78" x2="7.62" y2="-17.78" width="0.4064" layer="94"/>
<wire x1="7.62" y1="-17.78" x2="7.62" y2="17.78" width="0.4064" layer="94"/>
<wire x1="7.62" y1="17.78" x2="-7.62" y2="17.78" width="0.4064" layer="94"/>
<wire x1="-7.62" y1="17.78" x2="-7.62" y2="-17.78" width="0.4064" layer="94"/>
<text x="-7.62" y="18.415" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="-20.32" size="1.778" layer="96">&gt;VALUE</text>
<pin name="X4" x="-12.7" y="5.08" length="middle"/>
<pin name="X6" x="-12.7" y="0" length="middle"/>
<pin name="X" x="12.7" y="15.24" length="middle" rot="R180"/>
<pin name="X7" x="-12.7" y="-2.54" length="middle"/>
<pin name="X5" x="-12.7" y="2.54" length="middle"/>
<pin name="INH" x="-12.7" y="-7.62" length="middle" direction="in"/>
<pin name="C" x="-12.7" y="-15.24" length="middle" direction="in"/>
<pin name="B" x="-12.7" y="-12.7" length="middle" direction="in"/>
<pin name="A" x="-12.7" y="-10.16" length="middle" direction="in"/>
<pin name="X3" x="-12.7" y="7.62" length="middle"/>
<pin name="X0" x="-12.7" y="15.24" length="middle"/>
<pin name="X1" x="-12.7" y="12.7" length="middle"/>
<pin name="X2" x="-12.7" y="10.16" length="middle"/>
</symbol>
<symbol name="PWR+VEE">
<text x="-2.54" y="-0.635" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.175" y="-5.842" size="1.27" layer="95" rot="R90">VEE</text>
<text x="1.905" y="-5.842" size="1.27" layer="95" rot="R90">GND</text>
<text x="1.905" y="2.54" size="1.27" layer="95" rot="R90">VCC</text>
<pin name="VEE" x="-5.08" y="-7.62" visible="pad" length="middle" direction="pwr" rot="R90"/>
<pin name="GND" x="0" y="-7.62" visible="pad" length="middle" direction="pwr" rot="R90"/>
<pin name="VCC" x="0" y="7.62" visible="pad" length="middle" direction="pwr" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="4051" prefix="IC">
<description>8-channel &lt;b&gt;ANALOG MULTIPLEXER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="4051" x="20.32" y="0"/>
<gate name="P" symbol="PWR+VEE" x="-5.08" y="0" addlevel="request"/>
</gates>
<devices>
<device name="N" package="DIL16">
<connects>
<connect gate="A" pin="A" pad="11"/>
<connect gate="A" pin="B" pad="10"/>
<connect gate="A" pin="C" pad="9"/>
<connect gate="A" pin="INH" pad="6"/>
<connect gate="A" pin="X" pad="3"/>
<connect gate="A" pin="X0" pad="13"/>
<connect gate="A" pin="X1" pad="14"/>
<connect gate="A" pin="X2" pad="15"/>
<connect gate="A" pin="X3" pad="12"/>
<connect gate="A" pin="X4" pad="1"/>
<connect gate="A" pin="X5" pad="5"/>
<connect gate="A" pin="X6" pad="2"/>
<connect gate="A" pin="X7" pad="4"/>
<connect gate="P" pin="GND" pad="8"/>
<connect gate="P" pin="VCC" pad="16"/>
<connect gate="P" pin="VEE" pad="7"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="D" package="SO16">
<connects>
<connect gate="A" pin="A" pad="11"/>
<connect gate="A" pin="B" pad="10"/>
<connect gate="A" pin="C" pad="9"/>
<connect gate="A" pin="INH" pad="6"/>
<connect gate="A" pin="X" pad="3"/>
<connect gate="A" pin="X0" pad="13"/>
<connect gate="A" pin="X1" pad="14"/>
<connect gate="A" pin="X2" pad="15"/>
<connect gate="A" pin="X3" pad="12"/>
<connect gate="A" pin="X4" pad="1"/>
<connect gate="A" pin="X5" pad="5"/>
<connect gate="A" pin="X6" pad="2"/>
<connect gate="A" pin="X7" pad="4"/>
<connect gate="P" pin="GND" pad="8"/>
<connect gate="P" pin="VCC" pad="16"/>
<connect gate="P" pin="VEE" pad="7"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
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
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="AGND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<wire x1="-1.0922" y1="-0.508" x2="1.0922" y2="-0.508" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="AGND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
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
<deviceset name="VCC" prefix="P+">
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
<deviceset name="AGND" prefix="AGND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VR1" symbol="AGND" x="0" y="0"/>
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
<library name="con-harting-ml">
<description>&lt;b&gt;Harting  &amp; 3M Connectors&lt;/b&gt;&lt;p&gt;
Low profile connectors, straight&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="ML10">
<description>&lt;b&gt;HARTING&lt;/b&gt;</description>
<wire x1="-8.89" y1="3.175" x2="8.89" y2="3.175" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-3.175" x2="8.89" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="3.175" x2="-8.89" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="4.445" x2="-8.89" y2="4.445" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-4.445" x2="5.461" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-4.445" x2="10.16" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="4.445" x2="-10.16" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-3.175" x2="4.572" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-2.413" x2="-2.032" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.175" x2="-2.032" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.175" x2="-8.89" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.175" x2="-2.032" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-2.413" x2="2.032" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-3.175" x2="2.032" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="8.89" y1="4.445" x2="8.89" y2="4.699" width="0.1524" layer="21"/>
<wire x1="8.89" y1="4.699" x2="7.62" y2="4.699" width="0.1524" layer="21"/>
<wire x1="7.62" y1="4.445" x2="7.62" y2="4.699" width="0.1524" layer="21"/>
<wire x1="8.89" y1="4.445" x2="10.16" y2="4.445" width="0.1524" layer="21"/>
<wire x1="0.635" y1="4.699" x2="-0.635" y2="4.699" width="0.1524" layer="21"/>
<wire x1="0.635" y1="4.699" x2="0.635" y2="4.445" width="0.1524" layer="21"/>
<wire x1="0.635" y1="4.445" x2="7.62" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="4.699" x2="-0.635" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="4.699" x2="-8.89" y2="4.699" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="4.699" x2="-8.89" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="4.699" x2="-7.62" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="4.445" x2="-0.635" y2="4.445" width="0.1524" layer="21"/>
<wire x1="2.159" y1="-4.445" x2="2.032" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-4.445" x2="-2.032" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-3.175" x2="3.048" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-3.175" x2="2.032" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="4.572" y1="-3.175" x2="4.572" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="4.572" y1="-3.175" x2="3.048" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="2.159" y1="-4.445" x2="2.54" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-3.937" x2="5.461" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-3.937" x2="4.572" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-3.429" x2="2.032" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="2.032" y1="-3.429" x2="2.032" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="4.572" y1="-3.429" x2="9.144" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="9.144" y1="-3.429" x2="9.144" y2="3.429" width="0.0508" layer="21"/>
<wire x1="9.144" y1="3.429" x2="-9.144" y2="3.429" width="0.0508" layer="21"/>
<wire x1="-9.144" y1="3.429" x2="-9.144" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-9.144" y1="-3.429" x2="-2.032" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-2.032" y1="-3.429" x2="-2.032" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-3.429" x2="3.048" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-3.937" x2="2.54" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="4.572" y1="-3.429" x2="4.572" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="4.572" y1="-3.937" x2="3.048" y2="-3.937" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-4.445" x2="-4.445" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-4.318" x2="-4.445" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-4.318" x2="-5.715" y2="-4.318" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-4.445" x2="-5.715" y2="-4.318" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-4.445" x2="-10.16" y2="-4.445" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="2" x="-5.08" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="3" x="-2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="4" x="-2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="5" x="0" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="6" x="0" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="7" x="2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="8" x="2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="9" x="5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="10" x="5.08" y="1.27" drill="0.9144" shape="octagon"/>
<text x="-1.016" y="-4.064" size="1.27" layer="21" ratio="10">10</text>
<text x="-10.16" y="5.08" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="5.08" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-7.62" y="-1.905" size="1.27" layer="21" ratio="10">1</text>
<text x="-7.62" y="0.635" size="1.27" layer="21" ratio="10">2</text>
<rectangle x1="-2.794" y1="1.016" x2="-2.286" y2="1.524" layer="51"/>
<rectangle x1="-5.334" y1="1.016" x2="-4.826" y2="1.524" layer="51"/>
<rectangle x1="-0.254" y1="1.016" x2="0.254" y2="1.524" layer="51"/>
<rectangle x1="4.826" y1="1.016" x2="5.334" y2="1.524" layer="51"/>
<rectangle x1="2.286" y1="1.016" x2="2.794" y2="1.524" layer="51"/>
<rectangle x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.016" layer="51"/>
<rectangle x1="-5.334" y1="-1.524" x2="-4.826" y2="-1.016" layer="51"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-1.016" layer="51"/>
<rectangle x1="4.826" y1="-1.524" x2="5.334" y2="-1.016" layer="51"/>
<rectangle x1="2.286" y1="-1.524" x2="2.794" y2="-1.016" layer="51"/>
</package>
<package name="ML10L">
<description>&lt;b&gt;HARTING&lt;/b&gt;</description>
<wire x1="-6.35" y1="10.16" x2="-3.81" y2="10.16" width="0.254" layer="21"/>
<wire x1="-3.81" y1="10.16" x2="-5.08" y2="7.62" width="0.254" layer="21"/>
<wire x1="-5.08" y1="7.62" x2="-6.35" y2="10.16" width="0.254" layer="21"/>
<wire x1="2.794" y1="9.906" x2="2.794" y2="10.922" width="0.1524" layer="21"/>
<wire x1="2.794" y1="9.906" x2="4.826" y2="9.906" width="0.1524" layer="21"/>
<wire x1="4.826" y1="10.922" x2="4.826" y2="9.906" width="0.1524" layer="21"/>
<wire x1="2.159" y1="3.683" x2="3.048" y2="3.683" width="0.1524" layer="21"/>
<wire x1="3.048" y1="5.969" x2="4.572" y2="5.969" width="0.1524" layer="21" curve="-180"/>
<wire x1="4.572" y1="5.969" x2="4.572" y2="4.445" width="0.1524" layer="21"/>
<wire x1="4.572" y1="3.683" x2="5.969" y2="3.683" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="10.922" x2="-2.159" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="10.922" x2="2.159" y2="10.922" width="0.1524" layer="21"/>
<wire x1="2.159" y1="10.922" x2="2.159" y2="4.445" width="0.1524" layer="21"/>
<wire x1="2.159" y1="4.445" x2="-2.159" y2="4.445" width="0.1524" layer="21"/>
<wire x1="2.159" y1="3.429" x2="-2.159" y2="3.429" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="4.445" x2="-2.159" y2="3.429" width="0.1524" layer="21"/>
<wire x1="2.159" y1="4.445" x2="2.159" y2="3.683" width="0.1524" layer="21"/>
<wire x1="2.159" y1="3.683" x2="2.159" y2="3.429" width="0.1524" layer="21"/>
<wire x1="2.159" y1="3.429" x2="2.159" y2="2.159" width="0.1524" layer="21"/>
<wire x1="3.048" y1="5.969" x2="3.048" y2="4.445" width="0.1524" layer="21"/>
<wire x1="3.048" y1="4.445" x2="3.048" y2="3.683" width="0.1524" layer="21"/>
<wire x1="3.048" y1="4.445" x2="4.572" y2="4.445" width="0.1524" layer="21"/>
<wire x1="4.572" y1="4.445" x2="4.572" y2="3.683" width="0.1524" layer="21"/>
<wire x1="5.969" y1="3.683" x2="5.969" y2="10.922" width="0.1524" layer="21"/>
<wire x1="5.969" y1="3.683" x2="5.969" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.032" x2="-4.445" y2="2.032" width="0.1524" layer="51"/>
<wire x1="-4.445" y1="2.032" x2="-3.175" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.032" x2="-1.905" y2="2.032" width="0.1524" layer="51"/>
<wire x1="-1.905" y1="2.032" x2="-0.635" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.032" x2="0.635" y2="2.032" width="0.1524" layer="51"/>
<wire x1="0.635" y1="2.032" x2="1.905" y2="2.032" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.032" x2="2.159" y2="2.032" width="0.1524" layer="51"/>
<wire x1="3.175" y1="2.032" x2="4.445" y2="2.032" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.032" x2="4.445" y2="2.032" width="0.1524" layer="51"/>
<wire x1="0" y1="10.033" x2="0" y2="10.287" width="0.508" layer="21"/>
<wire x1="6.731" y1="4.445" x2="9.525" y2="4.445" width="0.1524" layer="21"/>
<wire x1="9.525" y1="4.445" x2="9.525" y2="8.255" width="0.1524" layer="21"/>
<wire x1="6.731" y1="8.255" x2="9.525" y2="8.255" width="0.1524" layer="21"/>
<wire x1="6.731" y1="8.255" x2="6.731" y2="4.445" width="0.1524" layer="21"/>
<wire x1="2.159" y1="10.922" x2="10.16" y2="10.922" width="0.1524" layer="21"/>
<wire x1="10.16" y1="10.922" x2="10.16" y2="2.032" width="0.1524" layer="21"/>
<wire x1="10.16" y1="2.032" x2="9.017" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="10.922" x2="-10.16" y2="10.922" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="2.032" x2="-10.16" y2="10.922" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="2.032" x2="-9.017" y2="2.032" width="0.1524" layer="21"/>
<wire x1="5.969" y1="2.032" x2="5.715" y2="2.032" width="0.1524" layer="21"/>
<wire x1="2.159" y1="2.159" x2="2.159" y2="2.032" width="0.1524" layer="51"/>
<wire x1="2.159" y1="2.032" x2="3.175" y2="2.032" width="0.1524" layer="51"/>
<wire x1="8.001" y1="2.032" x2="8.001" y2="1.397" width="0.1524" layer="21"/>
<wire x1="9.017" y1="1.397" x2="8.001" y2="1.397" width="0.1524" layer="21"/>
<wire x1="9.017" y1="1.397" x2="9.017" y2="2.032" width="0.1524" layer="21"/>
<wire x1="8.001" y1="2.032" x2="5.969" y2="2.032" width="0.1524" layer="21"/>
<wire x1="9.017" y1="2.032" x2="8.001" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-9.017" y1="2.032" x2="-9.017" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-9.017" y1="2.032" x2="-8.001" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-8.001" y1="1.397" x2="-9.017" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-8.001" y1="1.397" x2="-8.001" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-8.001" y1="2.032" x2="-5.715" y2="2.032" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="2" x="-5.08" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="3" x="-2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="4" x="-2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="5" x="0" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="6" x="0" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="7" x="2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="8" x="2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="9" x="5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="10" x="5.08" y="1.27" drill="0.9144" shape="octagon"/>
<text x="-7.1628" y="-1.6764" size="1.27" layer="21" ratio="10">1</text>
<text x="-7.1882" y="0.3556" size="1.27" layer="21" ratio="10">2</text>
<text x="-10.1854" y="11.43" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-0.0254" y="11.43" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="8.89" y="5.08" size="1.524" layer="21" ratio="10" rot="R90">10</text>
<rectangle x1="-0.254" y1="4.445" x2="0.254" y2="10.287" layer="21"/>
<rectangle x1="-6.223" y1="9.652" x2="-3.937" y2="10.16" layer="21"/>
<rectangle x1="-5.969" y1="9.144" x2="-4.191" y2="9.652" layer="21"/>
<rectangle x1="-5.715" y1="8.636" x2="-4.445" y2="9.144" layer="21"/>
<rectangle x1="-5.461" y1="8.128" x2="-4.699" y2="8.636" layer="21"/>
<rectangle x1="-5.207" y1="7.874" x2="-4.953" y2="8.128" layer="21"/>
<rectangle x1="-5.334" y1="-0.381" x2="-4.826" y2="0.381" layer="21"/>
<rectangle x1="-5.334" y1="0.381" x2="-4.826" y2="2.032" layer="51"/>
<rectangle x1="-5.334" y1="-1.524" x2="-4.826" y2="-0.381" layer="51"/>
<rectangle x1="-2.794" y1="0.381" x2="-2.286" y2="2.032" layer="51"/>
<rectangle x1="-2.794" y1="-0.381" x2="-2.286" y2="0.381" layer="21"/>
<rectangle x1="-2.794" y1="-1.524" x2="-2.286" y2="-0.381" layer="51"/>
<rectangle x1="-0.254" y1="0.381" x2="0.254" y2="2.032" layer="51"/>
<rectangle x1="-0.254" y1="-0.381" x2="0.254" y2="0.381" layer="21"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-0.381" layer="51"/>
<rectangle x1="2.286" y1="0.381" x2="2.794" y2="2.032" layer="51"/>
<rectangle x1="2.286" y1="-0.381" x2="2.794" y2="0.381" layer="21"/>
<rectangle x1="2.286" y1="-1.524" x2="2.794" y2="-0.381" layer="51"/>
<rectangle x1="4.826" y1="0.381" x2="5.334" y2="2.032" layer="51"/>
<rectangle x1="4.826" y1="-0.381" x2="5.334" y2="0.381" layer="21"/>
<rectangle x1="4.826" y1="-1.524" x2="5.334" y2="-0.381" layer="51"/>
</package>
<package name="3M_10">
<description>&lt;b&gt;3M&lt;/b&gt;</description>
<wire x1="15.875" y1="-4.2418" x2="15.875" y2="4.3" width="0.3048" layer="21"/>
<wire x1="-15.875" y1="4.3" x2="-15.875" y2="-4.2418" width="0.3048" layer="21"/>
<wire x1="-15.875" y1="-4.3" x2="-2.54" y2="-4.3" width="0.3048" layer="21"/>
<wire x1="-2.54" y1="-4.3" x2="-2.54" y2="-3.048" width="0.3048" layer="21"/>
<wire x1="2.54" y1="-3.048" x2="2.54" y2="-4.3" width="0.3048" layer="21"/>
<wire x1="2.54" y1="-4.3" x2="15.621" y2="-4.3" width="0.3048" layer="21"/>
<wire x1="15.875" y1="4.3" x2="-15.875" y2="4.3" width="0.3048" layer="21"/>
<wire x1="8.89" y1="-3" x2="2.54" y2="-3" width="0.3048" layer="21"/>
<wire x1="-2.54" y1="-3" x2="-8.89" y2="-3" width="0.3048" layer="21"/>
<wire x1="-8.89" y1="-3" x2="-8.89" y2="-1.27" width="0.3048" layer="21"/>
<wire x1="8.763" y1="3" x2="-8.89" y2="3" width="0.3048" layer="21"/>
<wire x1="-8.89" y1="1.27" x2="-8.89" y2="3" width="0.3048" layer="21"/>
<wire x1="-8.89" y1="-1.27" x2="-15.748" y2="-1.27" width="0.3048" layer="21"/>
<wire x1="-8.89" y1="1.27" x2="-15.748" y2="1.27" width="0.3048" layer="21"/>
<wire x1="-2.54" y1="-4.318" x2="2.54" y2="-4.318" width="0.3048" layer="21"/>
<wire x1="8.89" y1="-3" x2="8.89" y2="-1.27" width="0.3048" layer="21"/>
<wire x1="8.89" y1="1.27" x2="8.89" y2="3" width="0.3048" layer="21"/>
<wire x1="8.89" y1="-1.27" x2="15.748" y2="-1.27" width="0.3048" layer="21"/>
<wire x1="8.89" y1="1.27" x2="15.748" y2="1.27" width="0.3048" layer="21"/>
<pad name="1" x="-5.08" y="-1.27" drill="0.8128" shape="square"/>
<pad name="2" x="-5.08" y="1.27" drill="0.8128" shape="square"/>
<pad name="3" x="-2.54" y="-1.27" drill="0.8128" shape="square"/>
<pad name="4" x="-2.54" y="1.27" drill="0.8128" shape="square"/>
<pad name="5" x="0" y="-1.27" drill="0.8128" shape="square"/>
<pad name="6" x="0" y="1.27" drill="0.8128" shape="square"/>
<pad name="8" x="2.54" y="1.27" drill="0.8128" shape="square"/>
<pad name="9" x="5.08" y="-1.27" drill="0.8128" shape="square"/>
<pad name="10" x="5.08" y="1.27" drill="0.8128" shape="square"/>
<pad name="7" x="2.54" y="-1.27" drill="0.8128" shape="square"/>
<text x="-15.24" y="5.08" size="2.54" layer="25">&gt;NAME</text>
<text x="2.54" y="5.08" size="2.54" layer="27">&gt;VALUE</text>
<polygon width="0.3048" layer="21">
<vertex x="-6.477" y="-4.826"/>
<vertex x="-3.683" y="-4.826"/>
<vertex x="-5.08" y="-5.969"/>
</polygon>
</package>
<package name="3M_10L">
<description>&lt;b&gt;3M&lt;/b&gt;</description>
<wire x1="-15.875" y1="-6.0198" x2="-13.335" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="15.875" y1="-6.0198" x2="15.875" y2="2.54" width="0.3048" layer="21"/>
<wire x1="-15.875" y1="2.54" x2="-15.875" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="-13.335" y1="-6.0198" x2="-13.335" y2="-2.032" width="0.3048" layer="21"/>
<wire x1="-13.335" y1="-6.0198" x2="-8.6614" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="-13.335" y1="-2.032" x2="-10.9982" y2="-0.4572" width="0.3048" layer="21"/>
<wire x1="-10.9982" y1="-0.4572" x2="-8.6614" y2="-2.032" width="0.3048" layer="21"/>
<wire x1="-8.6614" y1="-2.032" x2="-8.6614" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="-8.6614" y1="-6.0198" x2="8.6614" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="8.6614" y1="-6.0198" x2="8.6614" y2="-2.0574" width="0.3048" layer="21"/>
<wire x1="8.6614" y1="-2.0574" x2="10.9982" y2="-0.4572" width="0.3048" layer="21"/>
<wire x1="10.9982" y1="-0.4572" x2="13.335" y2="-2.0574" width="0.3048" layer="21"/>
<wire x1="13.335" y1="-2.0574" x2="13.335" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="8.6614" y1="-6.0198" x2="13.335" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="13.335" y1="-6.0198" x2="15.875" y2="-6.0198" width="0.3048" layer="21"/>
<wire x1="-15.875" y1="2.54" x2="-13.0048" y2="10.9982" width="0.3048" layer="21"/>
<wire x1="15.875" y1="2.54" x2="13.0048" y2="10.9982" width="0.3048" layer="21"/>
<wire x1="-8.89" y1="10.9982" x2="-13.0048" y2="10.9982" width="0.3048" layer="21"/>
<wire x1="-8.89" y1="8.89" x2="-8.89" y2="10.9982" width="0.3048" layer="21"/>
<wire x1="2.54" y1="1.27" x2="-2.54" y2="1.27" width="0.3048" layer="21"/>
<wire x1="-2.54" y1="1.27" x2="-2.54" y2="6.6802" width="0.3048" layer="21"/>
<wire x1="-3.81" y1="7.874" x2="-2.54" y2="6.604" width="0.3048" layer="21" curve="-90"/>
<wire x1="-8.89" y1="8.89" x2="-7.874" y2="7.874" width="0.3048" layer="21" curve="90"/>
<wire x1="2.54" y1="1.27" x2="2.54" y2="6.6802" width="0.3048" layer="21"/>
<wire x1="2.54" y1="6.604" x2="3.81" y2="7.874" width="0.3048" layer="21" curve="-90"/>
<wire x1="-8.89" y1="1.27" x2="-8.89" y2="3.81" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="5.08" x2="-8.89" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="1.27" x2="-6.35" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="-2.54" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.89" y1="10.9982" x2="13.0048" y2="10.9982" width="0.3048" layer="21"/>
<wire x1="-7.874" y1="7.874" x2="7.874" y2="7.874" width="0.3048" layer="21"/>
<wire x1="8.89" y1="8.89" x2="8.89" y2="10.9982" width="0.3048" layer="21"/>
<wire x1="7.874" y1="7.874" x2="8.89" y2="8.89" width="0.3048" layer="21" curve="90"/>
<wire x1="0" y1="1.27" x2="2.54" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.89" y1="1.27" x2="8.89" y2="3.81" width="0.1524" layer="21"/>
<wire x1="8.89" y1="5.08" x2="8.89" y2="7.62" width="0.1524" layer="21"/>
<wire x1="8.89" y1="1.27" x2="6.35" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.27" x2="2.54" y2="1.27" width="0.1524" layer="21"/>
<circle x="-10.9982" y="-3.2766" radius="1.9304" width="0" layer="42"/>
<circle x="10.9982" y="-3.2766" radius="1.9304" width="0" layer="42"/>
<circle x="-14.8082" y="-4.5466" radius="1.9304" width="0" layer="41"/>
<circle x="-10.9982" y="-3.2766" radius="1.9304" width="0" layer="41"/>
<circle x="10.9982" y="-3.2766" radius="1.9304" width="0" layer="41"/>
<pad name="1" x="-5.08" y="-5.08" drill="0.8128" shape="square"/>
<pad name="2" x="-5.08" y="-2.54" drill="0.8128" shape="square"/>
<pad name="3" x="-2.54" y="-5.08" drill="0.8128" shape="square"/>
<pad name="4" x="-2.54" y="-2.54" drill="0.8128" shape="square"/>
<pad name="5" x="0" y="-5.08" drill="0.8128" shape="square"/>
<pad name="6" x="0" y="-2.54" drill="0.8128" shape="square"/>
<pad name="8" x="2.54" y="-2.54" drill="0.8128" shape="square"/>
<pad name="9" x="5.08" y="-5.08" drill="0.8128" shape="square"/>
<pad name="10" x="5.08" y="-2.54" drill="0.8128" shape="square"/>
<pad name="7" x="2.54" y="-5.08" drill="0.8128" shape="square"/>
<text x="-15.24" y="-10.16" size="2.54" layer="25">&gt;NAME</text>
<text x="2.54" y="-10.16" size="2.54" layer="27">&gt;VALUE</text>
<hole x="-10.9982" y="-3.2766" drill="2.54"/>
<hole x="10.9982" y="-3.2766" drill="2.54"/>
</package>
</packages>
<symbols>
<symbol name="10P">
<wire x1="3.81" y1="-7.62" x2="-3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="7.62" x2="-3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-1.27" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.27" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-1.27" y2="-5.08" width="0.6096" layer="94"/>
<text x="-3.81" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="8.382" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="5" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="7" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="8" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="9" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="10" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ML10" prefix="SV" uservalue="yes">
<description>&lt;b&gt;HARTING&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="10P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ML10">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="L" package="ML10L">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="-3M" package="3M_10">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="-3ML" package="3M_10L">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="holes">
<description>&lt;b&gt;Mounting Holes and Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2,8-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 2.8 mm, round</description>
<wire x1="0" y1="2.921" x2="0" y2="2.667" width="0.0508" layer="21"/>
<wire x1="0" y1="-2.667" x2="0" y2="-2.921" width="0.0508" layer="21"/>
<wire x1="-1.778" y1="0" x2="0" y2="-1.778" width="2.286" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="1.778" x2="1.778" y2="0" width="2.286" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.635" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="2.921" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="39"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="40"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="43"/>
<circle x="0" y="0" radius="1.5" width="0.2032" layer="21"/>
<pad name="B2,8" x="0" y="0" drill="2.8" diameter="5.334"/>
</package>
<package name="3,0-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.0 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="39"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.6" width="0.2032" layer="21"/>
<pad name="B3,0" x="0" y="0" drill="3" diameter="5.842"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,0</text>
</package>
<package name="3,2-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.2 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.7" width="0.1524" layer="21"/>
<pad name="B3,2" x="0" y="0" drill="3.2" diameter="5.842"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,2</text>
</package>
<package name="3,3-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.3 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.7" width="0.2032" layer="21"/>
<pad name="B3,3" x="0" y="0" drill="3.3" diameter="5.842"/>
</package>
<package name="3,6-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.6 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.397" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.397" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.9" width="0.2032" layer="21"/>
<pad name="B3,6" x="0" y="0" drill="3.6" diameter="5.842"/>
</package>
<package name="4,1-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.1 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="4.572" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="5.08" width="2" layer="41"/>
<circle x="0" y="0" radius="5.08" width="2" layer="42"/>
<circle x="0" y="0" radius="5.08" width="2" layer="43"/>
<circle x="0" y="0" radius="2.15" width="0.2032" layer="21"/>
<pad name="B4,1" x="0" y="0" drill="4.1" diameter="8"/>
</package>
<package name="4,3-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.3 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.25" width="0.1524" layer="21"/>
<pad name="B4,3" x="0" y="0" drill="4.3" diameter="9"/>
</package>
<package name="4,5-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.5 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.35" width="0.1524" layer="21"/>
<pad name="B4,5" x="0" y="0" drill="4.5" diameter="9"/>
</package>
<package name="5,0-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 5.0 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.6" width="0.1524" layer="21"/>
<pad name="B5" x="0" y="0" drill="5" diameter="9"/>
</package>
<package name="5,5-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 5.5 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.85" width="0.1524" layer="21"/>
<pad name="B5,5" x="0" y="0" drill="5.5" diameter="9"/>
</package>
</packages>
<symbols>
<symbol name="MOUNT-PAD">
<wire x1="0.254" y1="2.032" x2="2.032" y2="0.254" width="1.016" layer="94" curve="-75.749967" cap="flat"/>
<wire x1="-2.032" y1="0.254" x2="-0.254" y2="2.032" width="1.016" layer="94" curve="-75.749967" cap="flat"/>
<wire x1="-2.032" y1="-0.254" x2="-0.254" y2="-2.032" width="1.016" layer="94" curve="75.749967" cap="flat"/>
<wire x1="0.254" y1="-2.032" x2="2.032" y2="-0.254" width="1.016" layer="94" curve="75.749967" cap="flat"/>
<circle x="0" y="0" radius="1.524" width="0.0508" layer="94"/>
<text x="2.794" y="0.5842" size="1.778" layer="95">&gt;NAME</text>
<text x="2.794" y="-2.4638" size="1.778" layer="96">&gt;VALUE</text>
<pin name="MOUNT" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOUNT-PAD-ROUND" prefix="H">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt;, round</description>
<gates>
<gate name="G$1" symbol="MOUNT-PAD" x="0" y="0"/>
</gates>
<devices>
<device name="2.8" package="2,8-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B2,8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.0" package="3,0-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,0"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.2" package="3,2-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.3" package="3,3-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.6" package="3,6-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.1" package="4,1-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.3" package="4,3-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.5" package="4,5-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.0" package="5,0-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.5" package="5,5-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B5,5"/>
</connects>
<technologies>
<technology name=""/>
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
<class number="0" name="default" width="0.254" drill="0">
</class>
<class number="1" name="supply" width="0.4064" drill="0">
</class>
</classes>
<parts>
<part name="3P4" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="3P3" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="3P2" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="3P1" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="MX2" library="40xx" deviceset="4051" device="N"/>
<part name="4P4" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="4P3" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="4P2" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="4P1" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="SV1" library="con-harting-ml" deviceset="ML10" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="GND4" library="supply1" deviceset="GND" device=""/>
<part name="GND8" library="supply1" deviceset="GND" device=""/>
<part name="GND9" library="supply1" deviceset="GND" device=""/>
<part name="1P4" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="1P3" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="1P2" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="1P1" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="MX1" library="40xx" deviceset="4051" device="N"/>
<part name="2P4" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="2P3" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="2P2" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="2P1" library="alps" deviceset="RK09K" device="113" value="100k"/>
<part name="GND11" library="supply1" deviceset="GND" device=""/>
<part name="GND12" library="supply1" deviceset="GND" device=""/>
<part name="GND13" library="supply1" deviceset="GND" device=""/>
<part name="GND17" library="supply1" deviceset="GND" device=""/>
<part name="GND18" library="supply1" deviceset="GND" device=""/>
<part name="AGND1" library="supply1" deviceset="AGND" device=""/>
<part name="AGND2" library="supply1" deviceset="AGND" device=""/>
<part name="AGND5" library="supply1" deviceset="AGND" device=""/>
<part name="AGND6" library="supply1" deviceset="AGND" device=""/>
<part name="AGND8" library="supply1" deviceset="AGND" device=""/>
<part name="AGND10" library="supply1" deviceset="AGND" device=""/>
<part name="AGND13" library="supply1" deviceset="AGND" device=""/>
<part name="AGND14" library="supply1" deviceset="AGND" device=""/>
<part name="AGND17" library="supply1" deviceset="AGND" device=""/>
<part name="GND20" library="supply1" deviceset="GND" device=""/>
<part name="GND21" library="supply1" deviceset="GND" device=""/>
<part name="GND22" library="supply1" deviceset="GND" device=""/>
<part name="GND23" library="supply1" deviceset="GND" device=""/>
<part name="P+2" library="supply1" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" deviceset="VCC" device=""/>
<part name="AGND3" library="supply1" deviceset="AGND" device=""/>
<part name="GND14" library="supply1" deviceset="GND" device=""/>
<part name="AGND4" library="supply1" deviceset="AGND" device=""/>
<part name="GND15" library="supply1" deviceset="GND" device=""/>
<part name="GND16" library="supply1" deviceset="GND" device=""/>
<part name="AGND7" library="supply1" deviceset="AGND" device=""/>
<part name="AGND9" library="supply1" deviceset="AGND" device=""/>
<part name="GND19" library="supply1" deviceset="GND" device=""/>
<part name="GND5" library="supply1" deviceset="GND" device=""/>
<part name="AGND11" library="supply1" deviceset="AGND" device=""/>
<part name="AGND12" library="supply1" deviceset="AGND" device=""/>
<part name="GND6" library="supply1" deviceset="GND" device=""/>
<part name="AGND15" library="supply1" deviceset="AGND" device=""/>
<part name="GND7" library="supply1" deviceset="GND" device=""/>
<part name="AGND16" library="supply1" deviceset="AGND" device=""/>
<part name="GND10" library="supply1" deviceset="GND" device=""/>
<part name="H1" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.2"/>
<part name="H2" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.2"/>
<part name="H3" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="3P4" gate="G$1" x="78.74" y="129.54"/>
<instance part="3P3" gate="G$1" x="78.74" y="160.02"/>
<instance part="3P2" gate="G$1" x="78.74" y="190.5"/>
<instance part="3P1" gate="G$1" x="78.74" y="220.98"/>
<instance part="MX2" gate="A" x="96.52" y="60.96" rot="MR270"/>
<instance part="4P4" gate="G$1" x="104.14" y="129.54"/>
<instance part="4P3" gate="G$1" x="104.14" y="160.02"/>
<instance part="4P2" gate="G$1" x="104.14" y="190.5"/>
<instance part="4P1" gate="G$1" x="104.14" y="220.98"/>
<instance part="P+1" gate="VCC" x="53.34" y="7.62" smashed="yes" rot="R90">
<attribute name="VALUE" x="57.15" y="5.715" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND3" gate="1" x="53.34" y="33.02" smashed="yes" rot="R270">
<attribute name="VALUE" x="55.88" y="30.48" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND2" gate="1" x="104.14" y="78.74" rot="R180"/>
<instance part="SV1" gate="G$1" x="63.5" y="20.32" rot="R270"/>
<instance part="GND1" gate="1" x="78.74" y="139.7" smashed="yes" rot="R180"/>
<instance part="GND4" gate="1" x="78.74" y="170.18" smashed="yes" rot="R180"/>
<instance part="GND8" gate="1" x="78.74" y="200.66" smashed="yes" rot="R180"/>
<instance part="GND9" gate="1" x="78.74" y="231.14" smashed="yes" rot="R180"/>
<instance part="1P4" gate="G$1" x="12.7" y="129.54"/>
<instance part="1P3" gate="G$1" x="12.7" y="160.02"/>
<instance part="1P2" gate="G$1" x="12.7" y="190.5"/>
<instance part="1P1" gate="G$1" x="12.7" y="220.98"/>
<instance part="MX1" gate="A" x="27.94" y="60.96" rot="MR270"/>
<instance part="2P4" gate="G$1" x="38.1" y="129.54"/>
<instance part="2P3" gate="G$1" x="38.1" y="160.02"/>
<instance part="2P2" gate="G$1" x="38.1" y="190.5"/>
<instance part="2P1" gate="G$1" x="38.1" y="220.98"/>
<instance part="GND11" gate="1" x="35.56" y="78.74" rot="R180"/>
<instance part="GND12" gate="1" x="12.7" y="139.7" smashed="yes" rot="R180"/>
<instance part="GND13" gate="1" x="12.7" y="170.18" smashed="yes" rot="R180"/>
<instance part="GND17" gate="1" x="12.7" y="200.66" smashed="yes" rot="R180"/>
<instance part="GND18" gate="1" x="12.7" y="231.14" smashed="yes" rot="R180"/>
<instance part="AGND1" gate="VR1" x="60.96" y="35.56" smashed="yes" rot="R180">
<attribute name="VALUE" x="56.515" y="41.275" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="AGND2" gate="VR1" x="12.7" y="119.38" smashed="yes"/>
<instance part="AGND5" gate="VR1" x="12.7" y="149.86" smashed="yes"/>
<instance part="AGND6" gate="VR1" x="12.7" y="180.34" smashed="yes"/>
<instance part="AGND8" gate="VR1" x="12.7" y="210.82" smashed="yes"/>
<instance part="AGND10" gate="VR1" x="78.74" y="210.82" smashed="yes"/>
<instance part="AGND13" gate="VR1" x="78.74" y="180.34" smashed="yes"/>
<instance part="AGND14" gate="VR1" x="78.74" y="149.86" smashed="yes"/>
<instance part="AGND17" gate="VR1" x="78.74" y="119.38" smashed="yes"/>
<instance part="MX1" gate="P" x="109.22" y="15.24"/>
<instance part="MX2" gate="P" x="121.92" y="15.24"/>
<instance part="GND20" gate="1" x="121.92" y="5.08" smashed="yes"/>
<instance part="GND21" gate="1" x="116.84" y="5.08" smashed="yes"/>
<instance part="GND22" gate="1" x="109.22" y="5.08" smashed="yes"/>
<instance part="GND23" gate="1" x="104.14" y="5.08" smashed="yes"/>
<instance part="P+2" gate="VCC" x="121.92" y="25.4" smashed="yes"/>
<instance part="P+3" gate="VCC" x="109.22" y="25.4" smashed="yes"/>
<instance part="AGND3" gate="VR1" x="38.1" y="231.14" smashed="yes" rot="R180"/>
<instance part="GND14" gate="1" x="38.1" y="210.82" smashed="yes"/>
<instance part="AGND4" gate="VR1" x="38.1" y="200.66" smashed="yes" rot="R180"/>
<instance part="GND15" gate="1" x="38.1" y="180.34" smashed="yes"/>
<instance part="GND16" gate="1" x="38.1" y="149.86" smashed="yes"/>
<instance part="AGND7" gate="VR1" x="38.1" y="170.18" smashed="yes" rot="R180"/>
<instance part="AGND9" gate="VR1" x="38.1" y="139.7" smashed="yes" rot="R180"/>
<instance part="GND19" gate="1" x="38.1" y="119.38" smashed="yes"/>
<instance part="GND5" gate="1" x="104.14" y="210.82" smashed="yes"/>
<instance part="AGND11" gate="VR1" x="104.14" y="231.14" smashed="yes" rot="R180"/>
<instance part="AGND12" gate="VR1" x="104.14" y="200.66" smashed="yes" rot="R180"/>
<instance part="GND6" gate="1" x="104.14" y="180.34" smashed="yes"/>
<instance part="AGND15" gate="VR1" x="104.14" y="170.18" smashed="yes" rot="R180"/>
<instance part="GND7" gate="1" x="104.14" y="149.86" smashed="yes"/>
<instance part="AGND16" gate="VR1" x="104.14" y="139.7" smashed="yes" rot="R180"/>
<instance part="GND10" gate="1" x="104.14" y="119.38" smashed="yes"/>
<instance part="H1" gate="G$1" x="-40.64" y="7.62"/>
<instance part="H2" gate="G$1" x="-40.64" y="15.24"/>
<instance part="H3" gate="G$1" x="-40.64" y="22.86"/>
</instances>
<busses>
</busses>
<nets>
<net name="C" class="0">
<segment>
<pinref part="MX2" gate="A" pin="C"/>
<wire x1="111.76" y1="73.66" x2="124.46" y2="73.66" width="0.1524" layer="91"/>
<wire x1="124.46" y1="73.66" x2="124.46" y2="45.72" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="C"/>
<wire x1="43.18" y1="73.66" x2="68.58" y2="73.66" width="0.1524" layer="91"/>
<wire x1="124.46" y1="45.72" x2="68.58" y2="45.72" width="0.1524" layer="91"/>
<wire x1="68.58" y1="45.72" x2="68.58" y2="73.66" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="10"/>
<wire x1="68.58" y1="27.94" x2="68.58" y2="45.72" width="0.1524" layer="91"/>
<junction x="68.58" y="45.72"/>
</segment>
</net>
<net name="B" class="0">
<segment>
<pinref part="MX2" gate="A" pin="B"/>
<wire x1="109.22" y1="73.66" x2="109.22" y2="76.2" width="0.1524" layer="91"/>
<wire x1="109.22" y1="76.2" x2="127" y2="76.2" width="0.1524" layer="91"/>
<wire x1="127" y1="76.2" x2="127" y2="43.18" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="B"/>
<wire x1="40.64" y1="73.66" x2="40.64" y2="76.2" width="0.1524" layer="91"/>
<wire x1="40.64" y1="76.2" x2="66.04" y2="76.2" width="0.1524" layer="91"/>
<wire x1="127" y1="43.18" x2="66.04" y2="43.18" width="0.1524" layer="91"/>
<wire x1="66.04" y1="43.18" x2="66.04" y2="76.2" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="8"/>
<wire x1="66.04" y1="27.94" x2="66.04" y2="43.18" width="0.1524" layer="91"/>
<junction x="66.04" y="43.18"/>
</segment>
</net>
<net name="GND" class="1">
<segment>
<pinref part="MX2" gate="A" pin="INH"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="104.14" y1="76.2" x2="104.14" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="3P4" gate="G$1" pin="B"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="3P3" gate="G$1" pin="B"/>
<pinref part="GND4" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="3P2" gate="G$1" pin="B"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="3P1" gate="G$1" pin="B"/>
<pinref part="GND9" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="MX1" gate="A" pin="INH"/>
<pinref part="GND11" gate="1" pin="GND"/>
<wire x1="35.56" y1="76.2" x2="35.56" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="1P4" gate="G$1" pin="B"/>
<pinref part="GND12" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="1P3" gate="G$1" pin="B"/>
<pinref part="GND13" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="1P2" gate="G$1" pin="B"/>
<pinref part="GND17" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="1P1" gate="G$1" pin="B"/>
<pinref part="GND18" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="MX2" gate="P" pin="GND"/>
<pinref part="GND20" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="MX1" gate="P" pin="GND"/>
<pinref part="GND22" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="MX1" gate="P" pin="VEE"/>
<pinref part="GND23" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="MX2" gate="P" pin="VEE"/>
<pinref part="GND21" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="2"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="55.88" y1="33.02" x2="58.42" y2="33.02" width="0.1524" layer="91"/>
<wire x1="58.42" y1="33.02" x2="58.42" y2="27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="2P1" gate="G$1" pin="A"/>
<pinref part="GND14" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="2P2" gate="G$1" pin="A"/>
<pinref part="GND15" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="2P3" gate="G$1" pin="A"/>
<pinref part="GND16" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="2P4" gate="G$1" pin="A"/>
<pinref part="GND19" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="4P1" gate="G$1" pin="A"/>
<pinref part="GND5" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="4P2" gate="G$1" pin="A"/>
<pinref part="GND6" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="4P3" gate="G$1" pin="A"/>
<pinref part="GND7" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="4P4" gate="G$1" pin="A"/>
<pinref part="GND10" gate="1" pin="GND"/>
</segment>
</net>
<net name="A" class="0">
<segment>
<pinref part="MX2" gate="A" pin="A"/>
<wire x1="106.68" y1="73.66" x2="106.68" y2="78.74" width="0.1524" layer="91"/>
<wire x1="106.68" y1="78.74" x2="129.54" y2="78.74" width="0.1524" layer="91"/>
<wire x1="129.54" y1="78.74" x2="129.54" y2="40.64" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="A"/>
<wire x1="38.1" y1="73.66" x2="38.1" y2="78.74" width="0.1524" layer="91"/>
<wire x1="38.1" y1="78.74" x2="63.5" y2="78.74" width="0.1524" layer="91"/>
<wire x1="129.54" y1="40.64" x2="63.5" y2="40.64" width="0.1524" layer="91"/>
<wire x1="63.5" y1="40.64" x2="63.5" y2="78.74" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="6"/>
<wire x1="63.5" y1="27.94" x2="63.5" y2="40.64" width="0.1524" layer="91"/>
<junction x="63.5" y="40.64"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="MX2" gate="P" pin="VCC"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="MX1" gate="P" pin="VCC"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="1"/>
<wire x1="55.88" y1="7.62" x2="58.42" y2="7.62" width="0.1524" layer="91"/>
<wire x1="58.42" y1="7.62" x2="58.42" y2="12.7" width="0.1524" layer="91"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
</segment>
</net>
<net name="X1" class="0">
<segment>
<pinref part="MX1" gate="A" pin="X"/>
<wire x1="12.7" y1="48.26" x2="12.7" y2="-2.54" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="3"/>
<wire x1="12.7" y1="-2.54" x2="60.96" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="60.96" y1="-2.54" x2="60.96" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AGND" class="0">
<segment>
<pinref part="1P4" gate="G$1" pin="A"/>
<pinref part="AGND2" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="1P3" gate="G$1" pin="A"/>
<pinref part="AGND5" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="1P2" gate="G$1" pin="A"/>
<pinref part="AGND6" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="1P1" gate="G$1" pin="A"/>
<pinref part="AGND8" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="3P1" gate="G$1" pin="A"/>
<pinref part="AGND10" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="3P2" gate="G$1" pin="A"/>
<pinref part="AGND13" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="3P3" gate="G$1" pin="A"/>
<pinref part="AGND14" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="3P4" gate="G$1" pin="A"/>
<pinref part="AGND17" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="AGND1" gate="VR1" pin="AGND"/>
<pinref part="SV1" gate="G$1" pin="4"/>
<wire x1="60.96" y1="33.02" x2="60.96" y2="27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="2P1" gate="G$1" pin="B"/>
<pinref part="AGND3" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="2P2" gate="G$1" pin="B"/>
<pinref part="AGND4" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="2P3" gate="G$1" pin="B"/>
<pinref part="AGND7" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="2P4" gate="G$1" pin="B"/>
<pinref part="AGND9" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="4P1" gate="G$1" pin="B"/>
<pinref part="AGND11" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="4P2" gate="G$1" pin="B"/>
<pinref part="AGND12" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="4P3" gate="G$1" pin="B"/>
<pinref part="AGND15" gate="VR1" pin="AGND"/>
</segment>
<segment>
<pinref part="4P4" gate="G$1" pin="B"/>
<pinref part="AGND16" gate="VR1" pin="AGND"/>
</segment>
</net>
<net name="X2" class="0">
<segment>
<pinref part="SV1" gate="G$1" pin="5"/>
<pinref part="MX2" gate="A" pin="X"/>
<wire x1="81.28" y1="48.26" x2="81.28" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="81.28" y1="-2.54" x2="63.5" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="63.5" y1="-2.54" x2="63.5" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="4MX1" class="0">
<segment>
<pinref part="1P1" gate="G$1" pin="C"/>
<pinref part="MX1" gate="A" pin="X4"/>
<wire x1="22.86" y1="220.98" x2="17.78" y2="220.98" width="0.1524" layer="91"/>
<wire x1="22.86" y1="73.66" x2="22.86" y2="220.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="7MX1" class="0">
<segment>
<pinref part="1P2" gate="G$1" pin="C"/>
<pinref part="MX1" gate="A" pin="X7"/>
<wire x1="30.48" y1="73.66" x2="30.48" y2="190.5" width="0.1524" layer="91"/>
<wire x1="30.48" y1="190.5" x2="17.78" y2="190.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="3MX1" class="0">
<segment>
<pinref part="1P4" gate="G$1" pin="C"/>
<wire x1="17.78" y1="129.54" x2="20.32" y2="129.54" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="X3"/>
<wire x1="20.32" y1="73.66" x2="20.32" y2="129.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="6MX1" class="0">
<segment>
<pinref part="2P1" gate="G$1" pin="C"/>
<wire x1="43.18" y1="220.98" x2="45.72" y2="220.98" width="0.1524" layer="91"/>
<wire x1="45.72" y1="220.98" x2="45.72" y2="88.9" width="0.1524" layer="91"/>
<wire x1="27.94" y1="88.9" x2="45.72" y2="88.9" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="X6"/>
<wire x1="27.94" y1="88.9" x2="27.94" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="2MX1" class="0">
<segment>
<pinref part="2P2" gate="G$1" pin="C"/>
<wire x1="43.18" y1="190.5" x2="48.26" y2="190.5" width="0.1524" layer="91"/>
<wire x1="48.26" y1="190.5" x2="48.26" y2="91.44" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="X2"/>
<wire x1="17.78" y1="73.66" x2="17.78" y2="91.44" width="0.1524" layer="91"/>
<wire x1="17.78" y1="91.44" x2="48.26" y2="91.44" width="0.1524" layer="91"/>
</segment>
</net>
<net name="1MX1" class="0">
<segment>
<pinref part="2P3" gate="G$1" pin="C"/>
<wire x1="43.18" y1="160.02" x2="50.8" y2="160.02" width="0.1524" layer="91"/>
<wire x1="50.8" y1="160.02" x2="50.8" y2="93.98" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="X1"/>
<wire x1="15.24" y1="73.66" x2="15.24" y2="93.98" width="0.1524" layer="91"/>
<wire x1="15.24" y1="93.98" x2="50.8" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="0MX1" class="0">
<segment>
<pinref part="2P4" gate="G$1" pin="C"/>
<wire x1="43.18" y1="129.54" x2="53.34" y2="129.54" width="0.1524" layer="91"/>
<wire x1="53.34" y1="129.54" x2="53.34" y2="96.52" width="0.1524" layer="91"/>
<pinref part="MX1" gate="A" pin="X0"/>
<wire x1="12.7" y1="73.66" x2="12.7" y2="96.52" width="0.1524" layer="91"/>
<wire x1="12.7" y1="96.52" x2="53.34" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5MX1" class="0">
<segment>
<pinref part="1P3" gate="G$1" pin="C"/>
<pinref part="MX1" gate="A" pin="X5"/>
<wire x1="25.4" y1="73.66" x2="25.4" y2="160.02" width="0.1524" layer="91"/>
<wire x1="25.4" y1="160.02" x2="17.78" y2="160.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X5"/>
<pinref part="3P4" gate="G$1" pin="C"/>
<wire x1="93.98" y1="73.66" x2="93.98" y2="129.54" width="0.1524" layer="91"/>
<wire x1="93.98" y1="129.54" x2="83.82" y2="129.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="7MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X7"/>
<pinref part="3P3" gate="G$1" pin="C"/>
<wire x1="99.06" y1="73.66" x2="99.06" y2="160.02" width="0.1524" layer="91"/>
<wire x1="99.06" y1="160.02" x2="83.82" y2="160.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="6MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X6"/>
<pinref part="3P2" gate="G$1" pin="C"/>
<wire x1="96.52" y1="73.66" x2="96.52" y2="190.5" width="0.1524" layer="91"/>
<wire x1="96.52" y1="190.5" x2="83.82" y2="190.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="4MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X4"/>
<wire x1="91.44" y1="73.66" x2="91.44" y2="220.98" width="0.1524" layer="91"/>
<wire x1="91.44" y1="220.98" x2="83.82" y2="220.98" width="0.1524" layer="91"/>
<pinref part="3P1" gate="G$1" pin="C"/>
</segment>
</net>
<net name="3MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X3"/>
<wire x1="88.9" y1="73.66" x2="88.9" y2="106.68" width="0.1524" layer="91"/>
<wire x1="88.9" y1="106.68" x2="111.76" y2="106.68" width="0.1524" layer="91"/>
<wire x1="111.76" y1="106.68" x2="111.76" y2="129.54" width="0.1524" layer="91"/>
<wire x1="111.76" y1="129.54" x2="109.22" y2="129.54" width="0.1524" layer="91"/>
<pinref part="4P4" gate="G$1" pin="C"/>
</segment>
</net>
<net name="0MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X0"/>
<wire x1="81.28" y1="73.66" x2="81.28" y2="104.14" width="0.1524" layer="91"/>
<wire x1="81.28" y1="104.14" x2="114.3" y2="104.14" width="0.1524" layer="91"/>
<pinref part="4P3" gate="G$1" pin="C"/>
<wire x1="114.3" y1="104.14" x2="114.3" y2="160.02" width="0.1524" layer="91"/>
<wire x1="114.3" y1="160.02" x2="109.22" y2="160.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="1MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X1"/>
<wire x1="83.82" y1="73.66" x2="83.82" y2="101.6" width="0.1524" layer="91"/>
<wire x1="83.82" y1="101.6" x2="116.84" y2="101.6" width="0.1524" layer="91"/>
<wire x1="116.84" y1="101.6" x2="116.84" y2="190.5" width="0.1524" layer="91"/>
<wire x1="116.84" y1="190.5" x2="109.22" y2="190.5" width="0.1524" layer="91"/>
<pinref part="4P2" gate="G$1" pin="C"/>
</segment>
</net>
<net name="2MX2" class="0">
<segment>
<pinref part="MX2" gate="A" pin="X2"/>
<wire x1="86.36" y1="73.66" x2="86.36" y2="99.06" width="0.1524" layer="91"/>
<wire x1="86.36" y1="99.06" x2="119.38" y2="99.06" width="0.1524" layer="91"/>
<pinref part="4P1" gate="G$1" pin="C"/>
<wire x1="119.38" y1="99.06" x2="119.38" y2="220.98" width="0.1524" layer="91"/>
<wire x1="119.38" y1="220.98" x2="109.22" y2="220.98" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
