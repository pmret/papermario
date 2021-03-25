.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80247BB0_EE6570
.double 180.0, 1.3362052230687696e+98, 1.680557229813803e+122, 1.2934576819307836e+74, 3.85307767486332e+107, 0.0

.section .text

glabel func_80242AF0_EE14B0
/* EE14B0 80242AF0 27BDFF68 */  addiu     $sp, $sp, -0x98
/* EE14B4 80242AF4 AFB5007C */  sw        $s5, 0x7c($sp)
/* EE14B8 80242AF8 0080A82D */  daddu     $s5, $a0, $zero
/* EE14BC 80242AFC AFBF0080 */  sw        $ra, 0x80($sp)
/* EE14C0 80242B00 AFB40078 */  sw        $s4, 0x78($sp)
/* EE14C4 80242B04 AFB30074 */  sw        $s3, 0x74($sp)
/* EE14C8 80242B08 AFB20070 */  sw        $s2, 0x70($sp)
/* EE14CC 80242B0C AFB1006C */  sw        $s1, 0x6c($sp)
/* EE14D0 80242B10 AFB00068 */  sw        $s0, 0x68($sp)
/* EE14D4 80242B14 F7B60090 */  sdc1      $f22, 0x90($sp)
/* EE14D8 80242B18 F7B40088 */  sdc1      $f20, 0x88($sp)
/* EE14DC 80242B1C 8EB20148 */  lw        $s2, 0x148($s5)
/* EE14E0 80242B20 86440008 */  lh        $a0, 8($s2)
/* EE14E4 80242B24 0C00F92F */  jal       func_8003E4BC
/* EE14E8 80242B28 00A0802D */   daddu    $s0, $a1, $zero
/* EE14EC 80242B2C 8EA3000C */  lw        $v1, 0xc($s5)
/* EE14F0 80242B30 02A0202D */  daddu     $a0, $s5, $zero
/* EE14F4 80242B34 8C650000 */  lw        $a1, ($v1)
/* EE14F8 80242B38 0C0B53A3 */  jal       func_802D4E8C
/* EE14FC 80242B3C 0040882D */   daddu    $s1, $v0, $zero
/* EE1500 80242B40 AFA00028 */  sw        $zero, 0x28($sp)
/* EE1504 80242B44 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE1508 80242B48 8C630030 */  lw        $v1, 0x30($v1)
/* EE150C 80242B4C AFA3002C */  sw        $v1, 0x2c($sp)
/* EE1510 80242B50 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE1514 80242B54 8C63001C */  lw        $v1, 0x1c($v1)
/* EE1518 80242B58 AFA30030 */  sw        $v1, 0x30($sp)
/* EE151C 80242B5C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE1520 80242B60 8C630024 */  lw        $v1, 0x24($v1)
/* EE1524 80242B64 AFA30034 */  sw        $v1, 0x34($sp)
/* EE1528 80242B68 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE152C 80242B6C 8C630028 */  lw        $v1, 0x28($v1)
/* EE1530 80242B70 AFA30038 */  sw        $v1, 0x38($sp)
/* EE1534 80242B74 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE1538 80242B78 3C014282 */  lui       $at, 0x4282
/* EE153C 80242B7C 44810000 */  mtc1      $at, $f0
/* EE1540 80242B80 8C63002C */  lw        $v1, 0x2c($v1)
/* EE1544 80242B84 E7A00040 */  swc1      $f0, 0x40($sp)
/* EE1548 80242B88 A7A00044 */  sh        $zero, 0x44($sp)
/* EE154C 80242B8C AFA3003C */  sw        $v1, 0x3c($sp)
/* EE1550 80242B90 C6200038 */  lwc1      $f0, 0x38($s1)
/* EE1554 80242B94 E6400108 */  swc1      $f0, 0x108($s2)
/* EE1558 80242B98 C620003C */  lwc1      $f0, 0x3c($s1)
/* EE155C 80242B9C 27B40028 */  addiu     $s4, $sp, 0x28
/* EE1560 80242BA0 E640010C */  swc1      $f0, 0x10c($s2)
/* EE1564 80242BA4 3C0138D1 */  lui       $at, 0x38d1
/* EE1568 80242BA8 3421B717 */  ori       $at, $at, 0xb717
/* EE156C 80242BAC 44810000 */  mtc1      $at, $f0
/* EE1570 80242BB0 C6220040 */  lwc1      $f2, 0x40($s1)
/* EE1574 80242BB4 0040982D */  daddu     $s3, $v0, $zero
/* EE1578 80242BB8 E6400114 */  swc1      $f0, 0x114($s2)
/* EE157C 80242BBC E6400118 */  swc1      $f0, 0x118($s2)
/* EE1580 80242BC0 12000007 */  beqz      $s0, .L80242BE0
/* EE1584 80242BC4 E6420110 */   swc1     $f2, 0x110($s2)
/* EE1588 80242BC8 8E4200B0 */  lw        $v0, 0xb0($s2)
/* EE158C 80242BCC 862300A8 */  lh        $v1, 0xa8($s1)
/* EE1590 80242BD0 34420008 */  ori       $v0, $v0, 8
/* EE1594 80242BD4 AE430084 */  sw        $v1, 0x84($s2)
/* EE1598 80242BD8 08090AFC */  j         .L80242BF0
/* EE159C 80242BDC AE4200B0 */   sw       $v0, 0xb0($s2)
.L80242BE0:
/* EE15A0 80242BE0 8E430094 */  lw        $v1, 0x94($s2)
/* EE15A4 80242BE4 24020064 */  addiu     $v0, $zero, 0x64
/* EE15A8 80242BE8 1462001C */  bne       $v1, $v0, .L80242C5C
/* EE15AC 80242BEC 00000000 */   nop
.L80242BF0:
/* EE15B0 80242BF0 24020064 */  addiu     $v0, $zero, 0x64
/* EE15B4 80242BF4 2404F7FF */  addiu     $a0, $zero, -0x801
/* EE15B8 80242BF8 AEA20070 */  sw        $v0, 0x70($s5)
/* EE15BC 80242BFC A620008E */  sh        $zero, 0x8e($s1)
/* EE15C0 80242C00 8E4300CC */  lw        $v1, 0xcc($s2)
/* EE15C4 80242C04 8E220000 */  lw        $v0, ($s1)
/* EE15C8 80242C08 3C01C47A */  lui       $at, 0xc47a
/* EE15CC 80242C0C 44810000 */  mtc1      $at, $f0
/* EE15D0 80242C10 8C630000 */  lw        $v1, ($v1)
/* EE15D4 80242C14 00441024 */  and       $v0, $v0, $a0
/* EE15D8 80242C18 AE220000 */  sw        $v0, ($s1)
/* EE15DC 80242C1C AE230028 */  sw        $v1, 0x28($s1)
/* EE15E0 80242C20 8E420000 */  lw        $v0, ($s2)
/* EE15E4 80242C24 3C030020 */  lui       $v1, 0x20
/* EE15E8 80242C28 00431025 */  or        $v0, $v0, $v1
/* EE15EC 80242C2C AE420000 */  sw        $v0, ($s2)
/* EE15F0 80242C30 8E220000 */  lw        $v0, ($s1)
/* EE15F4 80242C34 2403FDFF */  addiu     $v1, $zero, -0x201
/* EE15F8 80242C38 00431024 */  and       $v0, $v0, $v1
/* EE15FC 80242C3C 34420008 */  ori       $v0, $v0, 8
/* EE1600 80242C40 AE220000 */  sw        $v0, ($s1)
/* EE1604 80242C44 2402FFFF */  addiu     $v0, $zero, -1
/* EE1608 80242C48 AE400094 */  sw        $zero, 0x94($s2)
/* EE160C 80242C4C AE420098 */  sw        $v0, 0x98($s2)
/* EE1610 80242C50 AE200038 */  sw        $zero, 0x38($s1)
/* EE1614 80242C54 E620003C */  swc1      $f0, 0x3c($s1)
/* EE1618 80242C58 AE200040 */  sw        $zero, 0x40($s1)
.L80242C5C:
/* EE161C 80242C5C 8E4200B0 */  lw        $v0, 0xb0($s2)
/* EE1620 80242C60 30420004 */  andi      $v0, $v0, 4
/* EE1624 80242C64 10400030 */  beqz      $v0, .L80242D28
/* EE1628 80242C68 2403FFFB */   addiu    $v1, $zero, -5
/* EE162C 80242C6C A620008E */  sh        $zero, 0x8e($s1)
/* EE1630 80242C70 96420086 */  lhu       $v0, 0x86($s2)
/* EE1634 80242C74 A62200A8 */  sh        $v0, 0xa8($s1)
/* EE1638 80242C78 8E4200B0 */  lw        $v0, 0xb0($s2)
/* EE163C 80242C7C 00431024 */  and       $v0, $v0, $v1
/* EE1640 80242C80 AE4200B0 */  sw        $v0, 0xb0($s2)
/* EE1644 80242C84 8E220000 */  lw        $v0, ($s1)
/* EE1648 80242C88 30420800 */  andi      $v0, $v0, 0x800
/* EE164C 80242C8C 1040000A */  beqz      $v0, .L80242CB8
/* EE1650 80242C90 3C02004A */   lui      $v0, 0x4a
/* EE1654 80242C94 3C013F80 */  lui       $at, 0x3f80
/* EE1658 80242C98 44810000 */  mtc1      $at, $f0
/* EE165C 80242C9C 34420018 */  ori       $v0, $v0, 0x18
/* EE1660 80242CA0 AE220028 */  sw        $v0, 0x28($s1)
/* EE1664 80242CA4 24020066 */  addiu     $v0, $zero, 0x66
/* EE1668 80242CA8 AE200018 */  sw        $zero, 0x18($s1)
/* EE166C 80242CAC AE20001C */  sw        $zero, 0x1c($s1)
/* EE1670 80242CB0 08090B49 */  j         .L80242D24
/* EE1674 80242CB4 E6200014 */   swc1     $f0, 0x14($s1)
.L80242CB8:
/* EE1678 80242CB8 24040002 */  addiu     $a0, $zero, 2
/* EE167C 80242CBC 0220282D */  daddu     $a1, $s1, $zero
/* EE1680 80242CC0 0000302D */  daddu     $a2, $zero, $zero
/* EE1684 80242CC4 862300A8 */  lh        $v1, 0xa8($s1)
/* EE1688 80242CC8 3C013F80 */  lui       $at, 0x3f80
/* EE168C 80242CCC 44810000 */  mtc1      $at, $f0
/* EE1690 80242CD0 3C014000 */  lui       $at, 0x4000
/* EE1694 80242CD4 44811000 */  mtc1      $at, $f2
/* EE1698 80242CD8 3C01C1A0 */  lui       $at, 0xc1a0
/* EE169C 80242CDC 44812000 */  mtc1      $at, $f4
/* EE16A0 80242CE0 24020028 */  addiu     $v0, $zero, 0x28
/* EE16A4 80242CE4 AFA2001C */  sw        $v0, 0x1c($sp)
/* EE16A8 80242CE8 44834000 */  mtc1      $v1, $f8
/* EE16AC 80242CEC 00000000 */  nop
/* EE16B0 80242CF0 46804220 */  cvt.s.w   $f8, $f8
/* EE16B4 80242CF4 44074000 */  mfc1      $a3, $f8
/* EE16B8 80242CF8 27A20048 */  addiu     $v0, $sp, 0x48
/* EE16BC 80242CFC AFA20020 */  sw        $v0, 0x20($sp)
/* EE16C0 80242D00 E7A00010 */  swc1      $f0, 0x10($sp)
/* EE16C4 80242D04 E7A20014 */  swc1      $f2, 0x14($sp)
/* EE16C8 80242D08 0C01D444 */  jal       func_80075110
/* EE16CC 80242D0C E7A40018 */   swc1     $f4, 0x18($sp)
/* EE16D0 80242D10 8E4200CC */  lw        $v0, 0xcc($s2)
/* EE16D4 80242D14 8C420000 */  lw        $v0, ($v0)
/* EE16D8 80242D18 AE220028 */  sw        $v0, 0x28($s1)
/* EE16DC 80242D1C 240200C8 */  addiu     $v0, $zero, 0xc8
/* EE16E0 80242D20 AEA00074 */  sw        $zero, 0x74($s5)
.L80242D24:
/* EE16E4 80242D24 AEA20070 */  sw        $v0, 0x70($s5)
.L80242D28:
/* EE16E8 80242D28 27A2004C */  addiu     $v0, $sp, 0x4c
/* EE16EC 80242D2C AFA20010 */  sw        $v0, 0x10($sp)
/* EE16F0 80242D30 27A20050 */  addiu     $v0, $sp, 0x50
/* EE16F4 80242D34 AFA20014 */  sw        $v0, 0x14($sp)
/* EE16F8 80242D38 27A20054 */  addiu     $v0, $sp, 0x54
/* EE16FC 80242D3C AFA20018 */  sw        $v0, 0x18($sp)
/* EE1700 80242D40 8E250038 */  lw        $a1, 0x38($s1)
/* EE1704 80242D44 8E26003C */  lw        $a2, 0x3c($s1)
/* EE1708 80242D48 8E270040 */  lw        $a3, 0x40($s1)
/* EE170C 80242D4C 0C00BF2F */  jal       func_8002FCBC
/* EE1710 80242D50 0000202D */   daddu    $a0, $zero, $zero
/* EE1714 80242D54 8EA20070 */  lw        $v0, 0x70($s5)
/* EE1718 80242D58 28420064 */  slti      $v0, $v0, 0x64
/* EE171C 80242D5C 10400007 */  beqz      $v0, .L80242D7C
/* EE1720 80242D60 00000000 */   nop
/* EE1724 80242D64 8FA2004C */  lw        $v0, 0x4c($sp)
/* EE1728 80242D68 24420032 */  addiu     $v0, $v0, 0x32
/* EE172C 80242D6C 2C4201A5 */  sltiu     $v0, $v0, 0x1a5
/* EE1730 80242D70 14400002 */  bnez      $v0, .L80242D7C
/* EE1734 80242D74 2402006E */   addiu    $v0, $zero, 0x6e
/* EE1738 80242D78 AEA20070 */  sw        $v0, 0x70($s5)
.L80242D7C:
/* EE173C 80242D7C 8EA30070 */  lw        $v1, 0x70($s5)
/* EE1740 80242D80 2402000F */  addiu     $v0, $zero, 0xf
/* EE1744 80242D84 1062006B */  beq       $v1, $v0, .L80242F34
/* EE1748 80242D88 28620010 */   slti     $v0, $v1, 0x10
/* EE174C 80242D8C 10400016 */  beqz      $v0, .L80242DE8
/* EE1750 80242D90 24020003 */   addiu    $v0, $zero, 3
/* EE1754 80242D94 10620051 */  beq       $v1, $v0, .L80242EDC
/* EE1758 80242D98 28620004 */   slti     $v0, $v1, 4
/* EE175C 80242D9C 10400009 */  beqz      $v0, .L80242DC4
/* EE1760 80242DA0 24020001 */   addiu    $v0, $zero, 1
/* EE1764 80242DA4 10620044 */  beq       $v1, $v0, .L80242EB8
/* EE1768 80242DA8 28620002 */   slti     $v0, $v1, 2
/* EE176C 80242DAC 50400048 */  beql      $v0, $zero, .L80242ED0
/* EE1770 80242DB0 02A0202D */   daddu    $a0, $s5, $zero
/* EE1774 80242DB4 50600027 */  beql      $v1, $zero, .L80242E54
/* EE1778 80242DB8 02A0202D */   daddu    $a0, $s5, $zero
/* EE177C 80242DBC 08090CFA */  j         .L802433E8
/* EE1780 80242DC0 00000000 */   nop
.L80242DC4:
/* EE1784 80242DC4 2402000D */  addiu     $v0, $zero, 0xd
/* EE1788 80242DC8 1062004D */  beq       $v1, $v0, .L80242F00
/* EE178C 80242DCC 2862000E */   slti     $v0, $v1, 0xe
/* EE1790 80242DD0 10400052 */  beqz      $v0, .L80242F1C
/* EE1794 80242DD4 2402000C */   addiu    $v0, $zero, 0xc
/* EE1798 80242DD8 10620046 */  beq       $v1, $v0, .L80242EF4
/* EE179C 80242DDC 02A0202D */   daddu    $a0, $s5, $zero
/* EE17A0 80242DE0 08090CFA */  j         .L802433E8
/* EE17A4 80242DE4 00000000 */   nop
.L80242DE8:
/* EE17A8 80242DE8 24020067 */  addiu     $v0, $zero, 0x67
/* EE17AC 80242DEC 10620158 */  beq       $v1, $v0, .L80243350
/* EE17B0 80242DF0 28620068 */   slti     $v0, $v1, 0x68
/* EE17B4 80242DF4 10400009 */  beqz      $v0, .L80242E1C
/* EE17B8 80242DF8 24020065 */   addiu    $v0, $zero, 0x65
/* EE17BC 80242DFC 1062008F */  beq       $v1, $v0, .L8024303C
/* EE17C0 80242E00 28620066 */   slti     $v0, $v1, 0x66
/* EE17C4 80242E04 104000A9 */  beqz      $v0, .L802430AC
/* EE17C8 80242E08 24020064 */   addiu    $v0, $zero, 0x64
/* EE17CC 80242E0C 1062004F */  beq       $v1, $v0, .L80242F4C
/* EE17D0 80242E10 24020002 */   addiu    $v0, $zero, 2
/* EE17D4 80242E14 08090CFA */  j         .L802433E8
/* EE17D8 80242E18 00000000 */   nop
.L80242E1C:
/* EE17DC 80242E1C 2404006F */  addiu     $a0, $zero, 0x6f
/* EE17E0 80242E20 10640166 */  beq       $v1, $a0, .L802433BC
/* EE17E4 80242E24 28620070 */   slti     $v0, $v1, 0x70
/* EE17E8 80242E28 10400005 */  beqz      $v0, .L80242E40
/* EE17EC 80242E2C 2402006E */   addiu    $v0, $zero, 0x6e
/* EE17F0 80242E30 10620156 */  beq       $v1, $v0, .L8024338C
/* EE17F4 80242E34 2402001E */   addiu    $v0, $zero, 0x1e
/* EE17F8 80242E38 08090CFA */  j         .L802433E8
/* EE17FC 80242E3C 00000000 */   nop
.L80242E40:
/* EE1800 80242E40 240200C8 */  addiu     $v0, $zero, 0xc8
/* EE1804 80242E44 10620166 */  beq       $v1, $v0, .L802433E0
/* EE1808 80242E48 00000000 */   nop
/* EE180C 80242E4C 08090CFA */  j         .L802433E8
/* EE1810 80242E50 00000000 */   nop
.L80242E54:
/* EE1814 80242E54 0260282D */  daddu     $a1, $s3, $zero
/* EE1818 80242E58 0C013670 */  jal       func_8004D9C0
/* EE181C 80242E5C 0280302D */   daddu    $a2, $s4, $zero
/* EE1820 80242E60 96420086 */  lhu       $v0, 0x86($s2)
/* EE1824 80242E64 A62200A8 */  sh        $v0, 0xa8($s1)
/* EE1828 80242E68 8E4200A0 */  lw        $v0, 0xa0($s2)
/* EE182C 80242E6C 10400013 */  beqz      $v0, .L80242EBC
/* EE1830 80242E70 02A0202D */   daddu    $a0, $s5, $zero
/* EE1834 80242E74 C620003C */  lwc1      $f0, 0x3c($s1)
/* EE1838 80242E78 44801000 */  mtc1      $zero, $f2
/* EE183C 80242E7C 44801800 */  mtc1      $zero, $f3
/* EE1840 80242E80 46000021 */  cvt.d.s   $f0, $f0
/* EE1844 80242E84 4622003E */  c.le.d    $f0, $f2
/* EE1848 80242E88 00000000 */  nop
/* EE184C 80242E8C 45000005 */  bc1f      .L80242EA4
/* EE1850 80242E90 2403FDFF */   addiu    $v1, $zero, -0x201
/* EE1854 80242E94 8E220000 */  lw        $v0, ($s1)
/* EE1858 80242E98 00431024 */  and       $v0, $v0, $v1
/* EE185C 80242E9C 08090BAD */  j         .L80242EB4
/* EE1860 80242EA0 34420008 */   ori      $v0, $v0, 8
.L80242EA4:
/* EE1864 80242EA4 8E220000 */  lw        $v0, ($s1)
/* EE1868 80242EA8 2403FFF7 */  addiu     $v1, $zero, -9
/* EE186C 80242EAC 34420200 */  ori       $v0, $v0, 0x200
/* EE1870 80242EB0 00431024 */  and       $v0, $v0, $v1
.L80242EB4:
/* EE1874 80242EB4 AE220000 */  sw        $v0, ($s1)
.L80242EB8:
/* EE1878 80242EB8 02A0202D */  daddu     $a0, $s5, $zero
.L80242EBC:
/* EE187C 80242EBC 0260282D */  daddu     $a1, $s3, $zero
/* EE1880 80242EC0 0C0136B6 */  jal       func_8004DAD8
/* EE1884 80242EC4 0280302D */   daddu    $a2, $s4, $zero
/* EE1888 80242EC8 08090CFA */  j         .L802433E8
/* EE188C 80242ECC 00000000 */   nop
.L80242ED0:
/* EE1890 80242ED0 0260282D */  daddu     $a1, $s3, $zero
/* EE1894 80242ED4 0C0137D9 */  jal       func_8004DF64
/* EE1898 80242ED8 0280302D */   daddu    $a2, $s4, $zero
.L80242EDC:
/* EE189C 80242EDC 02A0202D */  daddu     $a0, $s5, $zero
/* EE18A0 80242EE0 0260282D */  daddu     $a1, $s3, $zero
/* EE18A4 80242EE4 0C013809 */  jal       func_8004E024
/* EE18A8 80242EE8 0280302D */   daddu    $a2, $s4, $zero
/* EE18AC 80242EEC 08090CFA */  j         .L802433E8
/* EE18B0 80242EF0 00000000 */   nop
.L80242EF4:
/* EE18B4 80242EF4 0260282D */  daddu     $a1, $s3, $zero
/* EE18B8 80242EF8 0C0908BC */  jal       func_802422F0_EE0CB0
/* EE18BC 80242EFC 0280302D */   daddu    $a2, $s4, $zero
.L80242F00:
/* EE18C0 80242F00 02A0202D */  daddu     $a0, $s5, $zero
/* EE18C4 80242F04 0260282D */  daddu     $a1, $s3, $zero
/* EE18C8 80242F08 0C0908DB */  jal       func_8024236C_EE0D2C
/* EE18CC 80242F0C 0280302D */   daddu    $a2, $s4, $zero
/* EE18D0 80242F10 96420086 */  lhu       $v0, 0x86($s2)
/* EE18D4 80242F14 08090CFA */  j         .L802433E8
/* EE18D8 80242F18 A62200A8 */   sh       $v0, 0xa8($s1)
.L80242F1C:
/* EE18DC 80242F1C 02A0202D */  daddu     $a0, $s5, $zero
/* EE18E0 80242F20 0260282D */  daddu     $a1, $s3, $zero
/* EE18E4 80242F24 0C090928 */  jal       func_802424A0_EE0E60
/* EE18E8 80242F28 0280302D */   daddu    $a2, $s4, $zero
/* EE18EC 80242F2C 08090CFA */  j         .L802433E8
/* EE18F0 80242F30 00000000 */   nop
.L80242F34:
/* EE18F4 80242F34 02A0202D */  daddu     $a0, $s5, $zero
/* EE18F8 80242F38 0260282D */  daddu     $a1, $s3, $zero
/* EE18FC 80242F3C 0C090981 */  jal       func_80242604_EE0FC4
/* EE1900 80242F40 0280302D */   daddu    $a2, $s4, $zero
/* EE1904 80242F44 08090CFA */  j         .L802433E8
/* EE1908 80242F48 00000000 */   nop
.L80242F4C:
/* EE190C 80242F4C 8E430094 */  lw        $v1, 0x94($s2)
/* EE1910 80242F50 14620125 */  bne       $v1, $v0, .L802433E8
/* EE1914 80242F54 00000000 */   nop
/* EE1918 80242F58 0C010ABD */  jal       func_80042AF4
/* EE191C 80242F5C 8E440098 */   lw       $a0, 0x98($s2)
/* EE1920 80242F60 0C00F92F */  jal       func_8003E4BC
/* EE1924 80242F64 84440008 */   lh       $a0, 8($v0)
/* EE1928 80242F68 C440000C */  lwc1      $f0, 0xc($v0)
/* EE192C 80242F6C 3C018024 */  lui       $at, %hi(D_80247BB0_EE6570)
/* EE1930 80242F70 D4227BB0 */  ldc1      $f2, %lo(D_80247BB0_EE6570)($at)
/* EE1934 80242F74 46000021 */  cvt.d.s   $f0, $f0
/* EE1938 80242F78 4622003C */  c.lt.d    $f0, $f2
/* EE193C 80242F7C 00000000 */  nop
/* EE1940 80242F80 45000008 */  bc1f      .L80242FA4
/* EE1944 80242F84 00000000 */   nop
/* EE1948 80242F88 C4400038 */  lwc1      $f0, 0x38($v0)
/* EE194C 80242F8C 3C014028 */  lui       $at, 0x4028
/* EE1950 80242F90 44811800 */  mtc1      $at, $f3
/* EE1954 80242F94 44801000 */  mtc1      $zero, $f2
/* EE1958 80242F98 46000021 */  cvt.d.s   $f0, $f0
/* EE195C 80242F9C 08090BEF */  j         .L80242FBC
/* EE1960 80242FA0 46220000 */   add.d    $f0, $f0, $f2
.L80242FA4:
/* EE1964 80242FA4 C4400038 */  lwc1      $f0, 0x38($v0)
/* EE1968 80242FA8 3C014028 */  lui       $at, 0x4028
/* EE196C 80242FAC 44811800 */  mtc1      $at, $f3
/* EE1970 80242FB0 44801000 */  mtc1      $zero, $f2
/* EE1974 80242FB4 46000021 */  cvt.d.s   $f0, $f0
/* EE1978 80242FB8 46220001 */  sub.d     $f0, $f0, $f2
.L80242FBC:
/* EE197C 80242FBC 46200020 */  cvt.s.d   $f0, $f0
/* EE1980 80242FC0 E6200038 */  swc1      $f0, 0x38($s1)
/* EE1984 80242FC4 3C04004A */  lui       $a0, 0x4a
/* EE1988 80242FC8 C440003C */  lwc1      $f0, 0x3c($v0)
/* EE198C 80242FCC 3C014039 */  lui       $at, 0x4039
/* EE1990 80242FD0 44811800 */  mtc1      $at, $f3
/* EE1994 80242FD4 44801000 */  mtc1      $zero, $f2
/* EE1998 80242FD8 46000021 */  cvt.d.s   $f0, $f0
/* EE199C 80242FDC 46220000 */  add.d     $f0, $f0, $f2
/* EE19A0 80242FE0 34840018 */  ori       $a0, $a0, 0x18
/* EE19A4 80242FE4 3C013FF0 */  lui       $at, 0x3ff0
/* EE19A8 80242FE8 44811800 */  mtc1      $at, $f3
/* EE19AC 80242FEC 44801000 */  mtc1      $zero, $f2
/* EE19B0 80242FF0 46200020 */  cvt.s.d   $f0, $f0
/* EE19B4 80242FF4 E620003C */  swc1      $f0, 0x3c($s1)
/* EE19B8 80242FF8 C4400040 */  lwc1      $f0, 0x40($v0)
/* EE19BC 80242FFC 8E220000 */  lw        $v0, ($s1)
/* EE19C0 80243000 2403FFFD */  addiu     $v1, $zero, -3
/* EE19C4 80243004 AE200048 */  sw        $zero, 0x48($s1)
/* EE19C8 80243008 AE200034 */  sw        $zero, 0x34($s1)
/* EE19CC 8024300C AE240028 */  sw        $a0, 0x28($s1)
/* EE19D0 80243010 34420008 */  ori       $v0, $v0, 8
/* EE19D4 80243014 00431024 */  and       $v0, $v0, $v1
/* EE19D8 80243018 2403FDFF */  addiu     $v1, $zero, -0x201
/* EE19DC 8024301C 00431024 */  and       $v0, $v0, $v1
/* EE19E0 80243020 46000021 */  cvt.d.s   $f0, $f0
/* EE19E4 80243024 46220000 */  add.d     $f0, $f0, $f2
/* EE19E8 80243028 AE220000 */  sw        $v0, ($s1)
/* EE19EC 8024302C 24020065 */  addiu     $v0, $zero, 0x65
/* EE19F0 80243030 46200020 */  cvt.s.d   $f0, $f0
/* EE19F4 80243034 E6200040 */  swc1      $f0, 0x40($s1)
/* EE19F8 80243038 AEA20070 */  sw        $v0, 0x70($s5)
.L8024303C:
/* EE19FC 8024303C 8E430094 */  lw        $v1, 0x94($s2)
/* EE1A00 80243040 24020003 */  addiu     $v0, $zero, 3
/* EE1A04 80243044 146200E8 */  bne       $v1, $v0, .L802433E8
/* EE1A08 80243048 24020004 */   addiu    $v0, $zero, 4
/* EE1A0C 8024304C AE420094 */  sw        $v0, 0x94($s2)
/* EE1A10 80243050 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EE1A14 80243054 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EE1A18 80243058 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EE1A1C 8024305C C62E0040 */  lwc1      $f14, 0x40($s1)
/* EE1A20 80243060 8C460028 */  lw        $a2, 0x28($v0)
/* EE1A24 80243064 0C00ABDC */  jal       fio_validate_header_checksums
/* EE1A28 80243068 8C470030 */   lw       $a3, 0x30($v0)
/* EE1A2C 8024306C 3C014020 */  lui       $at, 0x4020
/* EE1A30 80243070 44811000 */  mtc1      $at, $f2
/* EE1A34 80243074 3C014100 */  lui       $at, 0x4100
/* EE1A38 80243078 44812000 */  mtc1      $at, $f4
/* EE1A3C 8024307C 3C013F4C */  lui       $at, 0x3f4c
/* EE1A40 80243080 3421CCCD */  ori       $at, $at, 0xcccd
/* EE1A44 80243084 44813000 */  mtc1      $at, $f6
/* EE1A48 80243088 8E220000 */  lw        $v0, ($s1)
/* EE1A4C 8024308C E620000C */  swc1      $f0, 0xc($s1)
/* EE1A50 80243090 34420800 */  ori       $v0, $v0, 0x800
/* EE1A54 80243094 AE220000 */  sw        $v0, ($s1)
/* EE1A58 80243098 24020066 */  addiu     $v0, $zero, 0x66
/* EE1A5C 8024309C E6220018 */  swc1      $f2, 0x18($s1)
/* EE1A60 802430A0 E624001C */  swc1      $f4, 0x1c($s1)
/* EE1A64 802430A4 E6260014 */  swc1      $f6, 0x14($s1)
/* EE1A68 802430A8 AEA20070 */  sw        $v0, 0x70($s5)
.L802430AC:
/* EE1A6C 802430AC C6200018 */  lwc1      $f0, 0x18($s1)
/* EE1A70 802430B0 44801000 */  mtc1      $zero, $f2
/* EE1A74 802430B4 44801800 */  mtc1      $zero, $f3
/* EE1A78 802430B8 46000021 */  cvt.d.s   $f0, $f0
/* EE1A7C 802430BC 4620103C */  c.lt.d    $f2, $f0
/* EE1A80 802430C0 00000000 */  nop
/* EE1A84 802430C4 4500001F */  bc1f      .L80243144
/* EE1A88 802430C8 27A50058 */   addiu    $a1, $sp, 0x58
/* EE1A8C 802430CC C6200038 */  lwc1      $f0, 0x38($s1)
/* EE1A90 802430D0 C622003C */  lwc1      $f2, 0x3c($s1)
/* EE1A94 802430D4 C6240040 */  lwc1      $f4, 0x40($s1)
/* EE1A98 802430D8 C6260018 */  lwc1      $f6, 0x18($s1)
/* EE1A9C 802430DC E7A00058 */  swc1      $f0, 0x58($sp)
/* EE1AA0 802430E0 E7A2005C */  swc1      $f2, 0x5c($sp)
/* EE1AA4 802430E4 E7A40060 */  swc1      $f4, 0x60($sp)
/* EE1AA8 802430E8 E7A60010 */  swc1      $f6, 0x10($sp)
/* EE1AAC 802430EC C620000C */  lwc1      $f0, 0xc($s1)
/* EE1AB0 802430F0 E7A00014 */  swc1      $f0, 0x14($sp)
/* EE1AB4 802430F4 862200A8 */  lh        $v0, 0xa8($s1)
/* EE1AB8 802430F8 44820000 */  mtc1      $v0, $f0
/* EE1ABC 802430FC 00000000 */  nop
/* EE1AC0 80243100 46800020 */  cvt.s.w   $f0, $f0
/* EE1AC4 80243104 E7A00018 */  swc1      $f0, 0x18($sp)
/* EE1AC8 80243108 862200A6 */  lh        $v0, 0xa6($s1)
/* EE1ACC 8024310C 27A6005C */  addiu     $a2, $sp, 0x5c
/* EE1AD0 80243110 44820000 */  mtc1      $v0, $f0
/* EE1AD4 80243114 00000000 */  nop
/* EE1AD8 80243118 46800020 */  cvt.s.w   $f0, $f0
/* EE1ADC 8024311C E7A0001C */  swc1      $f0, 0x1c($sp)
/* EE1AE0 80243120 8E240080 */  lw        $a0, 0x80($s1)
/* EE1AE4 80243124 0C0394C1 */  jal       func_800E5304
/* EE1AE8 80243128 27A70060 */   addiu    $a3, $sp, 0x60
/* EE1AEC 8024312C 54400005 */  bnel      $v0, $zero, .L80243144
/* EE1AF0 80243130 AE200018 */   sw       $zero, 0x18($s1)
/* EE1AF4 80243134 8E250018 */  lw        $a1, 0x18($s1)
/* EE1AF8 80243138 8E26000C */  lw        $a2, 0xc($s1)
/* EE1AFC 8024313C 0C00F909 */  jal       func_8003E424
/* EE1B00 80243140 0220202D */   daddu    $a0, $s1, $zero
.L80243144:
/* EE1B04 80243144 C620001C */  lwc1      $f0, 0x1c($s1)
/* EE1B08 80243148 4480B000 */  mtc1      $zero, $f22
/* EE1B0C 8024314C 4480B800 */  mtc1      $zero, $f23
/* EE1B10 80243150 46000021 */  cvt.d.s   $f0, $f0
/* EE1B14 80243154 4636003C */  c.lt.d    $f0, $f22
/* EE1B18 80243158 00000000 */  nop
/* EE1B1C 8024315C 45000074 */  bc1f      .L80243330
/* EE1B20 80243160 27A50058 */   addiu    $a1, $sp, 0x58
/* EE1B24 80243164 27A6005C */  addiu     $a2, $sp, 0x5c
/* EE1B28 80243168 27A20064 */  addiu     $v0, $sp, 0x64
/* EE1B2C 8024316C C622003C */  lwc1      $f2, 0x3c($s1)
/* EE1B30 80243170 C6260038 */  lwc1      $f6, 0x38($s1)
/* EE1B34 80243174 3C01402A */  lui       $at, 0x402a
/* EE1B38 80243178 4481A800 */  mtc1      $at, $f21
/* EE1B3C 8024317C 4480A000 */  mtc1      $zero, $f20
/* EE1B40 80243180 460010A1 */  cvt.d.s   $f2, $f2
/* EE1B44 80243184 46341080 */  add.d     $f2, $f2, $f20
/* EE1B48 80243188 C620001C */  lwc1      $f0, 0x1c($s1)
/* EE1B4C 8024318C C6240040 */  lwc1      $f4, 0x40($s1)
/* EE1B50 80243190 46000005 */  abs.s     $f0, $f0
/* EE1B54 80243194 E7A40060 */  swc1      $f4, 0x60($sp)
/* EE1B58 80243198 3C014030 */  lui       $at, 0x4030
/* EE1B5C 8024319C 44812800 */  mtc1      $at, $f5
/* EE1B60 802431A0 44802000 */  mtc1      $zero, $f4
/* EE1B64 802431A4 46000021 */  cvt.d.s   $f0, $f0
/* EE1B68 802431A8 E7A60058 */  swc1      $f6, 0x58($sp)
/* EE1B6C 802431AC 46240000 */  add.d     $f0, $f0, $f4
/* EE1B70 802431B0 462010A0 */  cvt.s.d   $f2, $f2
/* EE1B74 802431B4 E7A2005C */  swc1      $f2, 0x5c($sp)
/* EE1B78 802431B8 46200020 */  cvt.s.d   $f0, $f0
/* EE1B7C 802431BC E7A00064 */  swc1      $f0, 0x64($sp)
/* EE1B80 802431C0 AFA20010 */  sw        $v0, 0x10($sp)
/* EE1B84 802431C4 8E240080 */  lw        $a0, 0x80($s1)
/* EE1B88 802431C8 0C03908F */  jal       func_800E423C
/* EE1B8C 802431CC 27A70060 */   addiu    $a3, $sp, 0x60
/* EE1B90 802431D0 10400057 */  beqz      $v0, .L80243330
/* EE1B94 802431D4 00000000 */   nop
/* EE1B98 802431D8 C620001C */  lwc1      $f0, 0x1c($s1)
/* EE1B9C 802431DC C7A20064 */  lwc1      $f2, 0x64($sp)
/* EE1BA0 802431E0 46000005 */  abs.s     $f0, $f0
/* EE1BA4 802431E4 46000021 */  cvt.d.s   $f0, $f0
/* EE1BA8 802431E8 46340000 */  add.d     $f0, $f0, $f20
/* EE1BAC 802431EC 460010A1 */  cvt.d.s   $f2, $f2
/* EE1BB0 802431F0 4620103E */  c.le.d    $f2, $f0
/* EE1BB4 802431F4 00000000 */  nop
/* EE1BB8 802431F8 4500004D */  bc1f      .L80243330
/* EE1BBC 802431FC 00000000 */   nop
/* EE1BC0 80243200 C7A0005C */  lwc1      $f0, 0x5c($sp)
/* EE1BC4 80243204 E620003C */  swc1      $f0, 0x3c($s1)
/* EE1BC8 80243208 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1BCC 8024320C C6200038 */  lwc1      $f0, 0x38($s1)
/* EE1BD0 80243210 4600020D */  trunc.w.s $f8, $f0
/* EE1BD4 80243214 E4480000 */  swc1      $f8, ($v0)
/* EE1BD8 80243218 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1BDC 8024321C C620003C */  lwc1      $f0, 0x3c($s1)
/* EE1BE0 80243220 4600020D */  trunc.w.s $f8, $f0
/* EE1BE4 80243224 E4480004 */  swc1      $f8, 4($v0)
/* EE1BE8 80243228 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1BEC 8024322C C6200040 */  lwc1      $f0, 0x40($s1)
/* EE1BF0 80243230 4600020D */  trunc.w.s $f8, $f0
/* EE1BF4 80243234 E4480008 */  swc1      $f8, 8($v0)
/* EE1BF8 80243238 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1BFC 8024323C C6200038 */  lwc1      $f0, 0x38($s1)
/* EE1C00 80243240 4600020D */  trunc.w.s $f8, $f0
/* EE1C04 80243244 E448001C */  swc1      $f8, 0x1c($v0)
/* EE1C08 80243248 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1C0C 8024324C C620003C */  lwc1      $f0, 0x3c($s1)
/* EE1C10 80243250 4600020D */  trunc.w.s $f8, $f0
/* EE1C14 80243254 E4480020 */  swc1      $f8, 0x20($v0)
/* EE1C18 80243258 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1C1C 8024325C C6200040 */  lwc1      $f0, 0x40($s1)
/* EE1C20 80243260 4600020D */  trunc.w.s $f8, $f0
/* EE1C24 80243264 E4480024 */  swc1      $f8, 0x24($v0)
/* EE1C28 80243268 8E4300A0 */  lw        $v1, 0xa0($s2)
/* EE1C2C 8024326C 24020005 */  addiu     $v0, $zero, 5
/* EE1C30 80243270 1060000B */  beqz      $v1, .L802432A0
/* EE1C34 80243274 AE420094 */   sw       $v0, 0x94($s2)
/* EE1C38 80243278 C620003C */  lwc1      $f0, 0x3c($s1)
/* EE1C3C 8024327C 46000021 */  cvt.d.s   $f0, $f0
/* EE1C40 80243280 4636003E */  c.le.d    $f0, $f22
/* EE1C44 80243284 00000000 */  nop
/* EE1C48 80243288 4501000D */  bc1t      .L802432C0
/* EE1C4C 8024328C 2403FFF7 */   addiu    $v1, $zero, -9
/* EE1C50 80243290 8E220000 */  lw        $v0, ($s1)
/* EE1C54 80243294 34420200 */  ori       $v0, $v0, 0x200
/* EE1C58 80243298 08090CB4 */  j         .L802432D0
/* EE1C5C 8024329C 00431024 */   and      $v0, $v0, $v1
.L802432A0:
/* EE1C60 802432A0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EE1C64 802432A4 8C420034 */  lw        $v0, 0x34($v0)
/* EE1C68 802432A8 14400005 */  bnez      $v0, .L802432C0
/* EE1C6C 802432AC 2403FFF7 */   addiu    $v1, $zero, -9
/* EE1C70 802432B0 8E220000 */  lw        $v0, ($s1)
/* EE1C74 802432B4 34420200 */  ori       $v0, $v0, 0x200
/* EE1C78 802432B8 08090CB4 */  j         .L802432D0
/* EE1C7C 802432BC 00431024 */   and      $v0, $v0, $v1
.L802432C0:
/* EE1C80 802432C0 8E220000 */  lw        $v0, ($s1)
/* EE1C84 802432C4 2403FDFF */  addiu     $v1, $zero, -0x201
/* EE1C88 802432C8 00431024 */  and       $v0, $v0, $v1
/* EE1C8C 802432CC 34420008 */  ori       $v0, $v0, 8
.L802432D0:
/* EE1C90 802432D0 AE220000 */  sw        $v0, ($s1)
/* EE1C94 802432D4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EE1C98 802432D8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* EE1C9C 802432DC 8E220000 */  lw        $v0, ($s1)
/* EE1CA0 802432E0 3C048010 */  lui       $a0, %hi(D_800FFC90)
/* EE1CA4 802432E4 8C84FC90 */  lw        $a0, %lo(D_800FFC90)($a0)
/* EE1CA8 802432E8 3C030004 */  lui       $v1, 4
/* EE1CAC 802432EC AE20001C */  sw        $zero, 0x1c($s1)
/* EE1CB0 802432F0 00431025 */  or        $v0, $v0, $v1
/* EE1CB4 802432F4 2403F7FF */  addiu     $v1, $zero, -0x801
/* EE1CB8 802432F8 00431024 */  and       $v0, $v0, $v1
/* EE1CBC 802432FC AE220000 */  sw        $v0, ($s1)
/* EE1CC0 80243300 8C860028 */  lw        $a2, 0x28($a0)
/* EE1CC4 80243304 0C00ABDC */  jal       fio_validate_header_checksums
/* EE1CC8 80243308 8C870030 */   lw       $a3, 0x30($a0)
/* EE1CCC 8024330C 3C02004A */  lui       $v0, 0x4a
/* EE1CD0 80243310 3442001A */  ori       $v0, $v0, 0x1a
/* EE1CD4 80243314 AE220028 */  sw        $v0, 0x28($s1)
/* EE1CD8 80243318 24020003 */  addiu     $v0, $zero, 3
/* EE1CDC 8024331C A622008E */  sh        $v0, 0x8e($s1)
/* EE1CE0 80243320 24020067 */  addiu     $v0, $zero, 0x67
/* EE1CE4 80243324 E620000C */  swc1      $f0, 0xc($s1)
/* EE1CE8 80243328 08090CFA */  j         .L802433E8
/* EE1CEC 8024332C AEA20070 */   sw       $v0, 0x70($s5)
.L80243330:
/* EE1CF0 80243330 C624003C */  lwc1      $f4, 0x3c($s1)
/* EE1CF4 80243334 C620001C */  lwc1      $f0, 0x1c($s1)
/* EE1CF8 80243338 46002100 */  add.s     $f4, $f4, $f0
/* EE1CFC 8024333C C6220014 */  lwc1      $f2, 0x14($s1)
/* EE1D00 80243340 46020001 */  sub.s     $f0, $f0, $f2
/* EE1D04 80243344 E624003C */  swc1      $f4, 0x3c($s1)
/* EE1D08 80243348 08090CFA */  j         .L802433E8
/* EE1D0C 8024334C E620001C */   swc1     $f0, 0x1c($s1)
.L80243350:
/* EE1D10 80243350 9622008E */  lhu       $v0, 0x8e($s1)
/* EE1D14 80243354 2442FFFF */  addiu     $v0, $v0, -1
/* EE1D18 80243358 A622008E */  sh        $v0, 0x8e($s1)
/* EE1D1C 8024335C 00021400 */  sll       $v0, $v0, 0x10
/* EE1D20 80243360 1C400021 */  bgtz      $v0, .L802433E8
/* EE1D24 80243364 3C03004A */   lui      $v1, 0x4a
/* EE1D28 80243368 3C04FFFB */  lui       $a0, 0xfffb
/* EE1D2C 8024336C 3484FFFF */  ori       $a0, $a0, 0xffff
/* EE1D30 80243370 8E220000 */  lw        $v0, ($s1)
/* EE1D34 80243374 34630001 */  ori       $v1, $v1, 1
/* EE1D38 80243378 AE230028 */  sw        $v1, 0x28($s1)
/* EE1D3C 8024337C 00441024 */  and       $v0, $v0, $a0
/* EE1D40 80243380 AE220000 */  sw        $v0, ($s1)
/* EE1D44 80243384 08090CFA */  j         .L802433E8
/* EE1D48 80243388 AEA00070 */   sw       $zero, 0x70($s5)
.L8024338C:
/* EE1D4C 8024338C 3C01C47A */  lui       $at, 0xc47a
/* EE1D50 80243390 44810000 */  mtc1      $at, $f0
/* EE1D54 80243394 8E230000 */  lw        $v1, ($s1)
/* EE1D58 80243398 A622008E */  sh        $v0, 0x8e($s1)
/* EE1D5C 8024339C 2402FDFF */  addiu     $v0, $zero, -0x201
/* EE1D60 802433A0 AE200038 */  sw        $zero, 0x38($s1)
/* EE1D64 802433A4 AE200040 */  sw        $zero, 0x40($s1)
/* EE1D68 802433A8 3463000A */  ori       $v1, $v1, 0xa
/* EE1D6C 802433AC 00621824 */  and       $v1, $v1, $v0
/* EE1D70 802433B0 E620003C */  swc1      $f0, 0x3c($s1)
/* EE1D74 802433B4 AE230000 */  sw        $v1, ($s1)
/* EE1D78 802433B8 AEA40070 */  sw        $a0, 0x70($s5)
.L802433BC:
/* EE1D7C 802433BC 9622008E */  lhu       $v0, 0x8e($s1)
/* EE1D80 802433C0 2442FFFF */  addiu     $v0, $v0, -1
/* EE1D84 802433C4 A622008E */  sh        $v0, 0x8e($s1)
/* EE1D88 802433C8 00021400 */  sll       $v0, $v0, 0x10
/* EE1D8C 802433CC 1C400006 */  bgtz      $v0, .L802433E8
/* EE1D90 802433D0 24020064 */   addiu    $v0, $zero, 0x64
/* EE1D94 802433D4 AE400094 */  sw        $zero, 0x94($s2)
/* EE1D98 802433D8 08090CFA */  j         .L802433E8
/* EE1D9C 802433DC AEA20070 */   sw       $v0, 0x70($s5)
.L802433E0:
/* EE1DA0 802433E0 0C013AE3 */  jal       func_8004EB8C
/* EE1DA4 802433E4 02A0202D */   daddu    $a0, $s5, $zero
.L802433E8:
/* EE1DA8 802433E8 8FBF0080 */  lw        $ra, 0x80($sp)
/* EE1DAC 802433EC 8FB5007C */  lw        $s5, 0x7c($sp)
/* EE1DB0 802433F0 8FB40078 */  lw        $s4, 0x78($sp)
/* EE1DB4 802433F4 8FB30074 */  lw        $s3, 0x74($sp)
/* EE1DB8 802433F8 8FB20070 */  lw        $s2, 0x70($sp)
/* EE1DBC 802433FC 8FB1006C */  lw        $s1, 0x6c($sp)
/* EE1DC0 80243400 8FB00068 */  lw        $s0, 0x68($sp)
/* EE1DC4 80243404 D7B60090 */  ldc1      $f22, 0x90($sp)
/* EE1DC8 80243408 D7B40088 */  ldc1      $f20, 0x88($sp)
/* EE1DCC 8024340C 0000102D */  daddu     $v0, $zero, $zero
/* EE1DD0 80243410 03E00008 */  jr        $ra
/* EE1DD4 80243414 27BD0098 */   addiu    $sp, $sp, 0x98
