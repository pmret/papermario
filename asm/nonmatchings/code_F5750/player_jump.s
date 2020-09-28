.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel player_jump
/* F5E90 802D14E0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* F5E94 802D14E4 AFB20020 */  sw        $s2, 0x20($sp)
/* F5E98 802D14E8 0080902D */  daddu     $s2, $a0, $zero
/* F5E9C 802D14EC AFB30024 */  sw        $s3, 0x24($sp)
/* F5EA0 802D14F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* F5EA4 802D14F4 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* F5EA8 802D14F8 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* F5EAC 802D14FC AFBF0028 */  sw        $ra, 0x28($sp)
/* F5EB0 802D1500 AFB00018 */  sw        $s0, 0x18($sp)
/* F5EB4 802D1504 F7B80040 */  sdc1      $f24, 0x40($sp)
/* F5EB8 802D1508 F7B60038 */  sdc1      $f22, 0x38($sp)
/* F5EBC 802D150C F7B40030 */  sdc1      $f20, 0x30($sp)
/* F5EC0 802D1510 8E50000C */  lw        $s0, 0xc($s2)
/* F5EC4 802D1514 10A00002 */  beqz      $a1, .L802D1520
/* F5EC8 802D1518 00C0982D */   daddu    $s3, $a2, $zero
/* F5ECC 802D151C AE400070 */  sw        $zero, 0x70($s2)
.L802D1520:
/* F5ED0 802D1520 8E420070 */  lw        $v0, 0x70($s2)
/* F5ED4 802D1524 1440007E */  bnez      $v0, .L802D1720
/* F5ED8 802D1528 00000000 */   nop      
/* F5EDC 802D152C 8E050000 */  lw        $a1, ($s0)
/* F5EE0 802D1530 26100004 */  addiu     $s0, $s0, 4
/* F5EE4 802D1534 0C0B1EAF */  jal       get_variable
/* F5EE8 802D1538 0240202D */   daddu    $a0, $s2, $zero
/* F5EEC 802D153C 8E050000 */  lw        $a1, ($s0)
/* F5EF0 802D1540 26100004 */  addiu     $s0, $s0, 4
/* F5EF4 802D1544 4482B000 */  mtc1      $v0, $f22
/* F5EF8 802D1548 00000000 */  nop       
/* F5EFC 802D154C 4680B5A0 */  cvt.s.w   $f22, $f22
/* F5F00 802D1550 0C0B1EAF */  jal       get_variable
/* F5F04 802D1554 0240202D */   daddu    $a0, $s2, $zero
/* F5F08 802D1558 4482C000 */  mtc1      $v0, $f24
/* F5F0C 802D155C 00000000 */  nop       
/* F5F10 802D1560 4680C620 */  cvt.s.w   $f24, $f24
/* F5F14 802D1564 8E050000 */  lw        $a1, ($s0)
/* F5F18 802D1568 26100004 */  addiu     $s0, $s0, 4
/* F5F1C 802D156C 0C0B1EAF */  jal       get_variable
/* F5F20 802D1570 0240202D */   daddu    $a0, $s2, $zero
/* F5F24 802D1574 8E050000 */  lw        $a1, ($s0)
/* F5F28 802D1578 4482A000 */  mtc1      $v0, $f20
/* F5F2C 802D157C 00000000 */  nop       
/* F5F30 802D1580 4680A520 */  cvt.s.w   $f20, $f20
/* F5F34 802D1584 0C0B1EAF */  jal       get_variable
/* F5F38 802D1588 0240202D */   daddu    $a0, $s2, $zero
/* F5F3C 802D158C 3C10802E */  lui       $s0, %hi(gPlayerNpcPtr)
/* F5F40 802D1590 26109D20 */  addiu     $s0, $s0, %lo(gPlayerNpcPtr)
/* F5F44 802D1594 8E030000 */  lw        $v1, ($s0)
/* F5F48 802D1598 C6200028 */  lwc1      $f0, 0x28($s1)
/* F5F4C 802D159C E4600038 */  swc1      $f0, 0x38($v1)
/* F5F50 802D15A0 46000306 */  mov.s     $f12, $f0
/* F5F54 802D15A4 C620002C */  lwc1      $f0, 0x2c($s1)
/* F5F58 802D15A8 E460003C */  swc1      $f0, 0x3c($v1)
/* F5F5C 802D15AC C6200030 */  lwc1      $f0, 0x30($s1)
/* F5F60 802D15B0 E4760060 */  swc1      $f22, 0x60($v1)
/* F5F64 802D15B4 4406B000 */  mfc1      $a2, $f22
/* F5F68 802D15B8 E4740068 */  swc1      $f20, 0x68($v1)
/* F5F6C 802D15BC 4407A000 */  mfc1      $a3, $f20
/* F5F70 802D15C0 E4780064 */  swc1      $f24, 0x64($v1)
/* F5F74 802D15C4 A462008E */  sh        $v0, 0x8e($v1)
/* F5F78 802D15C8 E4600040 */  swc1      $f0, 0x40($v1)
/* F5F7C 802D15CC 46000386 */  mov.s     $f14, $f0
/* F5F80 802D15D0 C6200080 */  lwc1      $f0, 0x80($s1)
/* F5F84 802D15D4 0C00A7B5 */  jal       dist2D
/* F5F88 802D15D8 E460000C */   swc1     $f0, 0xc($v1)
/* F5F8C 802D15DC 46000506 */  mov.s     $f20, $f0
/* F5F90 802D15E0 3C013FF0 */  lui       $at, 0x3ff0
/* F5F94 802D15E4 44811800 */  mtc1      $at, $f3
/* F5F98 802D15E8 44801000 */  mtc1      $zero, $f2
/* F5F9C 802D15EC 4600A021 */  cvt.d.s   $f0, $f20
/* F5FA0 802D15F0 4620103C */  c.lt.d    $f2, $f0
/* F5FA4 802D15F4 00000000 */  nop       
/* F5FA8 802D15F8 45000009 */  bc1f      .L802D1620
/* F5FAC 802D15FC 00000000 */   nop      
/* F5FB0 802D1600 8E020000 */  lw        $v0, ($s0)
/* F5FB4 802D1604 C44C0038 */  lwc1      $f12, 0x38($v0)
/* F5FB8 802D1608 C44E0040 */  lwc1      $f14, 0x40($v0)
/* F5FBC 802D160C 8C460060 */  lw        $a2, 0x60($v0)
/* F5FC0 802D1610 0C00A720 */  jal       atan2
/* F5FC4 802D1614 8C470068 */   lw       $a3, 0x68($v0)
/* F5FC8 802D1618 8E020000 */  lw        $v0, ($s0)
/* F5FCC 802D161C E440000C */  swc1      $f0, 0xc($v0)
.L802D1620:
/* F5FD0 802D1620 8E030000 */  lw        $v1, ($s0)
/* F5FD4 802D1624 C4620064 */  lwc1      $f2, 0x64($v1)
/* F5FD8 802D1628 C460003C */  lwc1      $f0, 0x3c($v1)
/* F5FDC 802D162C 8462008E */  lh        $v0, 0x8e($v1)
/* F5FE0 802D1630 14400007 */  bnez      $v0, .L802D1650
/* F5FE4 802D1634 46001601 */   sub.s    $f24, $f2, $f0
/* F5FE8 802D1638 C4600018 */  lwc1      $f0, 0x18($v1)
/* F5FEC 802D163C 4600A003 */  div.s     $f0, $f20, $f0
/* F5FF0 802D1640 4600018D */  trunc.w.s $f6, $f0
/* F5FF4 802D1644 44023000 */  mfc1      $v0, $f6
/* F5FF8 802D1648 080B4599 */  j         .L802D1664
/* F5FFC 802D164C A462008E */   sh       $v0, 0x8e($v1)
.L802D1650:
/* F6000 802D1650 44820000 */  mtc1      $v0, $f0
/* F6004 802D1654 00000000 */  nop       
/* F6008 802D1658 46800020 */  cvt.s.w   $f0, $f0
/* F600C 802D165C 4600A003 */  div.s     $f0, $f20, $f0
/* F6010 802D1660 E4600018 */  swc1      $f0, 0x18($v1)
.L802D1664:
/* F6014 802D1664 3C03802E */  lui       $v1, %hi(gPlayerNpcPtr)
/* F6018 802D1668 8C639D20 */  lw        $v1, %lo(gPlayerNpcPtr)($v1)
/* F601C 802D166C 8464008E */  lh        $a0, 0x8e($v1)
/* F6020 802D1670 C4620014 */  lwc1      $f2, 0x14($v1)
/* F6024 802D1674 2482FFFF */  addiu     $v0, $a0, -1
/* F6028 802D1678 44820000 */  mtc1      $v0, $f0
/* F602C 802D167C 00000000 */  nop       
/* F6030 802D1680 46800020 */  cvt.s.w   $f0, $f0
/* F6034 802D1684 46001082 */  mul.s     $f2, $f2, $f0
/* F6038 802D1688 00000000 */  nop       
/* F603C 802D168C 3C013F00 */  lui       $at, 0x3f00
/* F6040 802D1690 44810000 */  mtc1      $at, $f0
/* F6044 802D1694 00000000 */  nop       
/* F6048 802D1698 46001082 */  mul.s     $f2, $f2, $f0
/* F604C 802D169C 00000000 */  nop       
/* F6050 802D16A0 44840000 */  mtc1      $a0, $f0
/* F6054 802D16A4 00000000 */  nop       
/* F6058 802D16A8 46800020 */  cvt.s.w   $f0, $f0
/* F605C 802D16AC 4600C003 */  div.s     $f0, $f24, $f0
/* F6060 802D16B0 46001080 */  add.s     $f2, $f2, $f0
/* F6064 802D16B4 E462001C */  swc1      $f2, 0x1c($v1)
/* F6068 802D16B8 8E220000 */  lw        $v0, ($s1)
/* F606C 802D16BC 8E230004 */  lw        $v1, 4($s1)
/* F6070 802D16C0 34420008 */  ori       $v0, $v0, 8
/* F6074 802D16C4 AE220000 */  sw        $v0, ($s1)
/* F6078 802D16C8 3C021000 */  lui       $v0, 0x1000
/* F607C 802D16CC 00621825 */  or        $v1, $v1, $v0
/* F6080 802D16D0 16600011 */  bnez      $s3, .L802D1718
/* F6084 802D16D4 AE230004 */   sw       $v1, 4($s1)
/* F6088 802D16D8 30624000 */  andi      $v0, $v1, 0x4000
/* F608C 802D16DC 14400008 */  bnez      $v0, .L802D1700
/* F6090 802D16E0 3C040009 */   lui      $a0, 9
/* F6094 802D16E4 3C040006 */  lui       $a0, 6
/* F6098 802D16E8 30620001 */  andi      $v0, $v1, 1
/* F609C 802D16EC 14400005 */  bnez      $v0, .L802D1704
/* F60A0 802D16F0 34840009 */   ori      $a0, $a0, 9
/* F60A4 802D16F4 3C040001 */  lui       $a0, 1
/* F60A8 802D16F8 080B45C1 */  j         .L802D1704
/* F60AC 802D16FC 34840007 */   ori      $a0, $a0, 7
.L802D1700:
/* F60B0 802D1700 34840005 */  ori       $a0, $a0, 5
.L802D1704:
/* F60B4 802D1704 0C037FBF */  jal       func_800DFEFC
/* F60B8 802D1708 00000000 */   nop      
/* F60BC 802D170C 24042081 */  addiu     $a0, $zero, 0x2081
/* F60C0 802D1710 0C052736 */  jal       play_sound_at_player
/* F60C4 802D1714 0000282D */   daddu    $a1, $zero, $zero
.L802D1718:
/* F60C8 802D1718 24020001 */  addiu     $v0, $zero, 1
/* F60CC 802D171C AE420070 */  sw        $v0, 0x70($s2)
.L802D1720:
/* F60D0 802D1720 3C10802E */  lui       $s0, %hi(gPlayerNpcPtr)
/* F60D4 802D1724 26109D20 */  addiu     $s0, $s0, %lo(gPlayerNpcPtr)
/* F60D8 802D1728 8E040000 */  lw        $a0, ($s0)
/* F60DC 802D172C 8C850018 */  lw        $a1, 0x18($a0)
/* F60E0 802D1730 0C00EA95 */  jal       npc_move_heading
/* F60E4 802D1734 8C86000C */   lw       $a2, 0xc($a0)
/* F60E8 802D1738 8E020000 */  lw        $v0, ($s0)
/* F60EC 802D173C C440001C */  lwc1      $f0, 0x1c($v0)
/* F60F0 802D1740 C442003C */  lwc1      $f2, 0x3c($v0)
/* F60F4 802D1744 46000106 */  mov.s     $f4, $f0
/* F60F8 802D1748 46001080 */  add.s     $f2, $f2, $f0
/* F60FC 802D174C C4400014 */  lwc1      $f0, 0x14($v0)
/* F6100 802D1750 46002001 */  sub.s     $f0, $f4, $f0
/* F6104 802D1754 E442003C */  swc1      $f2, 0x3c($v0)
/* F6108 802D1758 16600019 */  bnez      $s3, .L802D17C0
/* F610C 802D175C E440001C */   swc1     $f0, 0x1c($v0)
/* F6110 802D1760 44801000 */  mtc1      $zero, $f2
/* F6114 802D1764 00000000 */  nop       
/* F6118 802D1768 4604103C */  c.lt.s    $f2, $f4
/* F611C 802D176C 00000000 */  nop       
/* F6120 802D1770 45000013 */  bc1f      .L802D17C0
/* F6124 802D1774 00000000 */   nop      
/* F6128 802D1778 4602003E */  c.le.s    $f0, $f2
/* F612C 802D177C 00000000 */  nop       
/* F6130 802D1780 4500000F */  bc1f      .L802D17C0
/* F6134 802D1784 00000000 */   nop      
/* F6138 802D1788 8E230004 */  lw        $v1, 4($s1)
/* F613C 802D178C 30624000 */  andi      $v0, $v1, 0x4000
/* F6140 802D1790 14400008 */  bnez      $v0, .L802D17B4
/* F6144 802D1794 3C040009 */   lui      $a0, 9
/* F6148 802D1798 3C040006 */  lui       $a0, 6
/* F614C 802D179C 30620001 */  andi      $v0, $v1, 1
/* F6150 802D17A0 14400005 */  bnez      $v0, .L802D17B8
/* F6154 802D17A4 3484000A */   ori      $a0, $a0, 0xa
/* F6158 802D17A8 3C040001 */  lui       $a0, 1
/* F615C 802D17AC 080B45EE */  j         .L802D17B8
/* F6160 802D17B0 34840008 */   ori      $a0, $a0, 8
.L802D17B4:
/* F6164 802D17B4 34840005 */  ori       $a0, $a0, 5
.L802D17B8:
/* F6168 802D17B8 0C037FBF */  jal       func_800DFEFC
/* F616C 802D17BC 00000000 */   nop      
.L802D17C0:
/* F6170 802D17C0 3C03802E */  lui       $v1, %hi(gPlayerNpcPtr)
/* F6174 802D17C4 24639D20 */  addiu     $v1, $v1, %lo(gPlayerNpcPtr)
/* F6178 802D17C8 8C620000 */  lw        $v0, ($v1)
/* F617C 802D17CC C4400038 */  lwc1      $f0, 0x38($v0)
/* F6180 802D17D0 E6200028 */  swc1      $f0, 0x28($s1)
/* F6184 802D17D4 C440003C */  lwc1      $f0, 0x3c($v0)
/* F6188 802D17D8 E620002C */  swc1      $f0, 0x2c($s1)
/* F618C 802D17DC C4400040 */  lwc1      $f0, 0x40($v0)
/* F6190 802D17E0 16600003 */  bnez      $s3, .L802D17F0
/* F6194 802D17E4 E6200030 */   swc1     $f0, 0x30($s1)
/* F6198 802D17E8 C440000C */  lwc1      $f0, 0xc($v0)
/* F619C 802D17EC E6200080 */  swc1      $f0, 0x80($s1)
.L802D17F0:
/* F61A0 802D17F0 8C630000 */  lw        $v1, ($v1)
/* F61A4 802D17F4 9462008E */  lhu       $v0, 0x8e($v1)
/* F61A8 802D17F8 2442FFFF */  addiu     $v0, $v0, -1
/* F61AC 802D17FC A462008E */  sh        $v0, 0x8e($v1)
/* F61B0 802D1800 00021400 */  sll       $v0, $v0, 0x10
/* F61B4 802D1804 1440002E */  bnez      $v0, .L802D18C0
/* F61B8 802D1808 0000102D */   daddu    $v0, $zero, $zero
/* F61BC 802D180C 3C02EFFF */  lui       $v0, 0xefff
/* F61C0 802D1810 3442FFFF */  ori       $v0, $v0, 0xffff
/* F61C4 802D1814 2404FFF7 */  addiu     $a0, $zero, -9
/* F61C8 802D1818 8E230000 */  lw        $v1, ($s1)
/* F61CC 802D181C 8E250004 */  lw        $a1, 4($s1)
/* F61D0 802D1820 00641824 */  and       $v1, $v1, $a0
/* F61D4 802D1824 00A21024 */  and       $v0, $a1, $v0
/* F61D8 802D1828 AE230000 */  sw        $v1, ($s1)
/* F61DC 802D182C 16600014 */  bnez      $s3, .L802D1880
/* F61E0 802D1830 AE220004 */   sw       $v0, 4($s1)
/* F61E4 802D1834 30A24000 */  andi      $v0, $a1, 0x4000
/* F61E8 802D1838 14400008 */  bnez      $v0, .L802D185C
/* F61EC 802D183C 3C040001 */   lui      $a0, 1
/* F61F0 802D1840 3C040006 */  lui       $a0, 6
/* F61F4 802D1844 30A20001 */  andi      $v0, $a1, 1
/* F61F8 802D1848 14400005 */  bnez      $v0, .L802D1860
/* F61FC 802D184C 3484000B */   ori      $a0, $a0, 0xb
/* F6200 802D1850 3C040001 */  lui       $a0, 1
/* F6204 802D1854 080B4618 */  j         .L802D1860
/* F6208 802D1858 34840009 */   ori      $a0, $a0, 9
.L802D185C:
/* F620C 802D185C 34840003 */  ori       $a0, $a0, 3
.L802D1860:
/* F6210 802D1860 0C037FBF */  jal       func_800DFEFC
/* F6214 802D1864 00000000 */   nop      
/* F6218 802D1868 3C04802E */  lui       $a0, %hi(gPlayerNpcPtr)
/* F621C 802D186C 8C849D20 */  lw        $a0, %lo(gPlayerNpcPtr)($a0)
/* F6220 802D1870 0C00F598 */  jal       func_8003D660
/* F6224 802D1874 24050002 */   addiu    $a1, $zero, 2
/* F6228 802D1878 12600004 */  beqz      $s3, .L802D188C
/* F622C 802D187C 00000000 */   nop      
.L802D1880:
/* F6230 802D1880 24020002 */  addiu     $v0, $zero, 2
/* F6234 802D1884 1662000E */  bne       $s3, $v0, .L802D18C0
/* F6238 802D1888 24020001 */   addiu    $v0, $zero, 1
.L802D188C:
/* F623C 802D188C 3C02802E */  lui       $v0, %hi(gPlayerNpcPtr)
/* F6240 802D1890 8C429D20 */  lw        $v0, %lo(gPlayerNpcPtr)($v0)
/* F6244 802D1894 C44C001C */  lwc1      $f12, 0x1c($v0)
/* F6248 802D1898 0C038D45 */  jal       func_800E3514
/* F624C 802D189C 27A50010 */   addiu    $a1, $sp, 0x10
/* F6250 802D18A0 8FA40010 */  lw        $a0, 0x10($sp)
/* F6254 802D18A4 04800005 */  bltz      $a0, .L802D18BC
/* F6258 802D18A8 46000606 */   mov.s    $f24, $f0
/* F625C 802D18AC 0C038C57 */  jal       func_800E315C
/* F6260 802D18B0 E638002C */   swc1     $f24, 0x2c($s1)
/* F6264 802D18B4 0C03BF42 */  jal       func_800EFD08
/* F6268 802D18B8 00000000 */   nop      
.L802D18BC:
/* F626C 802D18BC 24020001 */  addiu     $v0, $zero, 1
.L802D18C0:
/* F6270 802D18C0 8FBF0028 */  lw        $ra, 0x28($sp)
/* F6274 802D18C4 8FB30024 */  lw        $s3, 0x24($sp)
/* F6278 802D18C8 8FB20020 */  lw        $s2, 0x20($sp)
/* F627C 802D18CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* F6280 802D18D0 8FB00018 */  lw        $s0, 0x18($sp)
/* F6284 802D18D4 D7B80040 */  ldc1      $f24, 0x40($sp)
/* F6288 802D18D8 D7B60038 */  ldc1      $f22, 0x38($sp)
/* F628C 802D18DC D7B40030 */  ldc1      $f20, 0x30($sp)
/* F6290 802D18E0 03E00008 */  jr        $ra
/* F6294 802D18E4 27BD0048 */   addiu    $sp, $sp, 0x48
