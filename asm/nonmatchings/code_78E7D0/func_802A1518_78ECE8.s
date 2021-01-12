.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_78ECE8
/* 78ECE8 802A1518 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 78ECEC 802A151C AFB00020 */  sw        $s0, 0x20($sp)
/* 78ECF0 802A1520 0080802D */  daddu     $s0, $a0, $zero
/* 78ECF4 802A1524 AFBF002C */  sw        $ra, 0x2c($sp)
/* 78ECF8 802A1528 AFB20028 */  sw        $s2, 0x28($sp)
/* 78ECFC 802A152C AFB10024 */  sw        $s1, 0x24($sp)
/* 78ED00 802A1530 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 78ED04 802A1534 0C00A67F */  jal       rand_int
/* 78ED08 802A1538 240400C8 */   addiu    $a0, $zero, 0xc8
/* 78ED0C 802A153C 24040028 */  addiu     $a0, $zero, 0x28
/* 78ED10 802A1540 2403FFCE */  addiu     $v1, $zero, -0x32
/* 78ED14 802A1544 0C00A67F */  jal       rand_int
/* 78ED18 802A1548 00628823 */   subu     $s1, $v1, $v0
/* 78ED1C 802A154C 241200C8 */  addiu     $s2, $zero, 0xc8
/* 78ED20 802A1550 8E030084 */  lw        $v1, 0x84($s0)
/* 78ED24 802A1554 30630003 */  andi      $v1, $v1, 3
/* 78ED28 802A1558 1060000C */  beqz      $v1, .L802A158C
/* 78ED2C 802A155C 0040802D */   daddu    $s0, $v0, $zero
/* 78ED30 802A1560 0C00A67F */  jal       rand_int
/* 78ED34 802A1564 24040032 */   addiu    $a0, $zero, 0x32
/* 78ED38 802A1568 00521021 */  addu      $v0, $v0, $s2
/* 78ED3C 802A156C 02221021 */  addu      $v0, $s1, $v0
/* 78ED40 802A1570 4482A000 */  mtc1      $v0, $f20
/* 78ED44 802A1574 00000000 */  nop
/* 78ED48 802A1578 4680A520 */  cvt.s.w   $f20, $f20
/* 78ED4C 802A157C 0C00A67F */  jal       rand_int
/* 78ED50 802A1580 2404000A */   addiu    $a0, $zero, 0xa
/* 78ED54 802A1584 080A856D */  j         .L802A15B4
/* 78ED58 802A1588 24040002 */   addiu    $a0, $zero, 2
.L802A158C:
/* 78ED5C 802A158C 0C00A67F */  jal       rand_int
/* 78ED60 802A1590 24040032 */   addiu    $a0, $zero, 0x32
/* 78ED64 802A1594 244200C8 */  addiu     $v0, $v0, 0xc8
/* 78ED68 802A1598 02221021 */  addu      $v0, $s1, $v0
/* 78ED6C 802A159C 4482A000 */  mtc1      $v0, $f20
/* 78ED70 802A15A0 00000000 */  nop
/* 78ED74 802A15A4 4680A520 */  cvt.s.w   $f20, $f20
/* 78ED78 802A15A8 0C00A67F */  jal       rand_int
/* 78ED7C 802A15AC 2404000A */   addiu    $a0, $zero, 0xa
/* 78ED80 802A15B0 24040003 */  addiu     $a0, $zero, 3
.L802A15B4:
/* 78ED84 802A15B4 44911000 */  mtc1      $s1, $f2
/* 78ED88 802A15B8 00000000 */  nop
/* 78ED8C 802A15BC 468010A0 */  cvt.s.w   $f2, $f2
/* 78ED90 802A15C0 44900000 */  mtc1      $s0, $f0
/* 78ED94 802A15C4 00000000 */  nop
/* 78ED98 802A15C8 46800020 */  cvt.s.w   $f0, $f0
/* 78ED9C 802A15CC 44051000 */  mfc1      $a1, $f2
/* 78EDA0 802A15D0 44921000 */  mtc1      $s2, $f2
/* 78EDA4 802A15D4 00000000 */  nop
/* 78EDA8 802A15D8 468010A0 */  cvt.s.w   $f2, $f2
/* 78EDAC 802A15DC 24420007 */  addiu     $v0, $v0, 7
/* 78EDB0 802A15E0 44070000 */  mfc1      $a3, $f0
/* 78EDB4 802A15E4 44061000 */  mfc1      $a2, $f2
/* 78EDB8 802A15E8 44820000 */  mtc1      $v0, $f0
/* 78EDBC 802A15EC 00000000 */  nop
/* 78EDC0 802A15F0 46800020 */  cvt.s.w   $f0, $f0
/* 78EDC4 802A15F4 E7B40010 */  swc1      $f20, 0x10($sp)
/* 78EDC8 802A15F8 AFA00014 */  sw        $zero, 0x14($sp)
/* 78EDCC 802A15FC E7A0001C */  swc1      $f0, 0x1c($sp)
/* 78EDD0 802A1600 0C01BF8C */  jal       func_8006FE30
/* 78EDD4 802A1604 AFA70018 */   sw       $a3, 0x18($sp)
/* 78EDD8 802A1608 8FBF002C */  lw        $ra, 0x2c($sp)
/* 78EDDC 802A160C 8FB20028 */  lw        $s2, 0x28($sp)
/* 78EDE0 802A1610 8FB10024 */  lw        $s1, 0x24($sp)
/* 78EDE4 802A1614 8FB00020 */  lw        $s0, 0x20($sp)
/* 78EDE8 802A1618 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 78EDEC 802A161C 24020002 */  addiu     $v0, $zero, 2
/* 78EDF0 802A1620 03E00008 */  jr        $ra
/* 78EDF4 802A1624 27BD0038 */   addiu    $sp, $sp, 0x38
