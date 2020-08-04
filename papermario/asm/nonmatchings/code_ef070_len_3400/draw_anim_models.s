.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel draw_anim_models
/* 0F14C8 802CCB18 27BDFDA8 */  addiu $sp, $sp, -0x258
/* 0F14CC 802CCB1C F7B60250 */  sdc1  $f22, 0x250($sp)
/* 0F14D0 802CCB20 3C013F80 */  lui   $at, 0x3f80
/* 0F14D4 802CCB24 4481B000 */  mtc1  $at, $f22
/* 0F14D8 802CCB28 AFB3022C */  sw    $s3, 0x22c($sp)
/* 0F14DC 802CCB2C 0000982D */  daddu $s3, $zero, $zero
/* 0F14E0 802CCB30 F7B40248 */  sdc1  $f20, 0x248($sp)
/* 0F14E4 802CCB34 4480A000 */  mtc1  $zero, $f20
/* 0F14E8 802CCB38 27A80058 */  addiu $t0, $sp, 0x58
/* 0F14EC 802CCB3C AFBE0240 */  sw    $fp, 0x240($sp)
/* 0F14F0 802CCB40 27BE0098 */  addiu $fp, $sp, 0x98
/* 0F14F4 802CCB44 AFB7023C */  sw    $s7, 0x23c($sp)
/* 0F14F8 802CCB48 27B700D8 */  addiu $s7, $sp, 0xd8
/* 0F14FC 802CCB4C AFB60238 */  sw    $s6, 0x238($sp)
/* 0F1500 802CCB50 27B601D8 */  addiu $s6, $sp, 0x1d8
/* 0F1504 802CCB54 AFB20228 */  sw    $s2, 0x228($sp)
/* 0F1508 802CCB58 27B20158 */  addiu $s2, $sp, 0x158
/* 0F150C 802CCB5C AFB50234 */  sw    $s5, 0x234($sp)
/* 0F1510 802CCB60 27B50118 */  addiu $s5, $sp, 0x118
/* 0F1514 802CCB64 AFB40230 */  sw    $s4, 0x230($sp)
/* 0F1518 802CCB68 27B40198 */  addiu $s4, $sp, 0x198
/* 0F151C 802CCB6C AFBF0244 */  sw    $ra, 0x244($sp)
/* 0F1520 802CCB70 AFB10224 */  sw    $s1, 0x224($sp)
/* 0F1524 802CCB74 AFB00220 */  sw    $s0, 0x220($sp)
/* 0F1528 802CCB78 AFA80218 */  sw    $t0, 0x218($sp)
.L802CCB7C:
/* 0F152C 802CCB7C 3C02802E */  lui   $v0, 0x802e
/* 0F1530 802CCB80 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F1534 802CCB84 00131880 */  sll   $v1, $s3, 2
/* 0F1538 802CCB88 00621821 */  addu  $v1, $v1, $v0
/* 0F153C 802CCB8C 8C710000 */  lw    $s1, ($v1)
/* 0F1540 802CCB90 8E220000 */  lw    $v0, ($s1)
/* 0F1544 802CCB94 04420035 */  bltzl $v0, .L802CCC6C
/* 0F1548 802CCB98 26730001 */   addiu $s3, $s3, 1
/* 0F154C 802CCB9C 8E250004 */  lw    $a1, 4($s1)
/* 0F1550 802CCBA0 8E260008 */  lw    $a2, 8($s1)
/* 0F1554 802CCBA4 8E27000C */  lw    $a3, 0xc($s1)
/* 0F1558 802CCBA8 0C019E40 */  jal   guTranslateF
/* 0F155C 802CCBAC 27A40018 */   addiu $a0, $sp, 0x18
/* 0F1560 802CCBB0 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0F1564 802CCBB4 8E250010 */  lw    $a1, 0x10($s1)
/* 0F1568 802CCBB8 4406B000 */  mfc1  $a2, $f22
/* 0F156C 802CCBBC 4407A000 */  mfc1  $a3, $f20
/* 0F1570 802CCBC0 8FA40218 */  lw    $a0, 0x218($sp)
/* 0F1574 802CCBC4 0C019EC8 */  jal   guRotateF
/* 0F1578 802CCBC8 26300028 */   addiu $s0, $s1, 0x28
/* 0F157C 802CCBCC E7B40010 */  swc1  $f20, 0x10($sp)
/* 0F1580 802CCBD0 8E250014 */  lw    $a1, 0x14($s1)
/* 0F1584 802CCBD4 4406A000 */  mfc1  $a2, $f20
/* 0F1588 802CCBD8 4407B000 */  mfc1  $a3, $f22
/* 0F158C 802CCBDC 0C019EC8 */  jal   guRotateF
/* 0F1590 802CCBE0 03C0202D */   daddu $a0, $fp, $zero
/* 0F1594 802CCBE4 E7B60010 */  swc1  $f22, 0x10($sp)
/* 0F1598 802CCBE8 8E250018 */  lw    $a1, 0x18($s1)
/* 0F159C 802CCBEC 4406A000 */  mfc1  $a2, $f20
/* 0F15A0 802CCBF0 4407A000 */  mfc1  $a3, $f20
/* 0F15A4 802CCBF4 0C019EC8 */  jal   guRotateF
/* 0F15A8 802CCBF8 02E0202D */   daddu $a0, $s7, $zero
/* 0F15AC 802CCBFC 8E25001C */  lw    $a1, 0x1c($s1)
/* 0F15B0 802CCC00 8E260020 */  lw    $a2, 0x20($s1)
/* 0F15B4 802CCC04 8E270024 */  lw    $a3, 0x24($s1)
/* 0F15B8 802CCC08 0C019DF0 */  jal   guScaleF
/* 0F15BC 802CCC0C 02C0202D */   daddu $a0, $s6, $zero
/* 0F15C0 802CCC10 02E0202D */  daddu $a0, $s7, $zero
/* 0F15C4 802CCC14 8FA50218 */  lw    $a1, 0x218($sp)
/* 0F15C8 802CCC18 0C019D80 */  jal   guMtxCatF
/* 0F15CC 802CCC1C 0240302D */   daddu $a2, $s2, $zero
/* 0F15D0 802CCC20 0240202D */  daddu $a0, $s2, $zero
/* 0F15D4 802CCC24 03C0282D */  daddu $a1, $fp, $zero
/* 0F15D8 802CCC28 0C019D80 */  jal   guMtxCatF
/* 0F15DC 802CCC2C 02A0302D */   daddu $a2, $s5, $zero
/* 0F15E0 802CCC30 02C0202D */  daddu $a0, $s6, $zero
/* 0F15E4 802CCC34 02A0282D */  daddu $a1, $s5, $zero
/* 0F15E8 802CCC38 0C019D80 */  jal   guMtxCatF
/* 0F15EC 802CCC3C 0240302D */   daddu $a2, $s2, $zero
/* 0F15F0 802CCC40 0240202D */  daddu $a0, $s2, $zero
/* 0F15F4 802CCC44 27A50018 */  addiu $a1, $sp, 0x18
/* 0F15F8 802CCC48 0C019D80 */  jal   guMtxCatF
/* 0F15FC 802CCC4C 0280302D */   daddu $a2, $s4, $zero
/* 0F1600 802CCC50 0280202D */  daddu $a0, $s4, $zero
/* 0F1604 802CCC54 0C019D40 */  jal   guMtxF2L
/* 0F1608 802CCC58 0200282D */   daddu $a1, $s0, $zero
/* 0F160C 802CCC5C 8E240000 */  lw    $a0, ($s1)
/* 0F1610 802CCC60 0C047CC1 */  jal   func_8011F304
/* 0F1614 802CCC64 0200282D */   daddu $a1, $s0, $zero
/* 0F1618 802CCC68 26730001 */  addiu $s3, $s3, 1
.L802CCC6C:
/* 0F161C 802CCC6C 2A620010 */  slti  $v0, $s3, 0x10
/* 0F1620 802CCC70 1440FFC2 */  bnez  $v0, .L802CCB7C
/* 0F1624 802CCC74 00000000 */   nop   
/* 0F1628 802CCC78 8FBF0244 */  lw    $ra, 0x244($sp)
/* 0F162C 802CCC7C 8FBE0240 */  lw    $fp, 0x240($sp)
/* 0F1630 802CCC80 8FB7023C */  lw    $s7, 0x23c($sp)
/* 0F1634 802CCC84 8FB60238 */  lw    $s6, 0x238($sp)
/* 0F1638 802CCC88 8FB50234 */  lw    $s5, 0x234($sp)
/* 0F163C 802CCC8C 8FB40230 */  lw    $s4, 0x230($sp)
/* 0F1640 802CCC90 8FB3022C */  lw    $s3, 0x22c($sp)
/* 0F1644 802CCC94 8FB20228 */  lw    $s2, 0x228($sp)
/* 0F1648 802CCC98 8FB10224 */  lw    $s1, 0x224($sp)
/* 0F164C 802CCC9C 8FB00220 */  lw    $s0, 0x220($sp)
/* 0F1650 802CCCA0 D7B60250 */  ldc1  $f22, 0x250($sp)
/* 0F1654 802CCCA4 D7B40248 */  ldc1  $f20, 0x248($sp)
/* 0F1658 802CCCA8 03E00008 */  jr    $ra
/* 0F165C 802CCCAC 27BD0258 */   addiu $sp, $sp, 0x258

/* 0F1660 802CCCB0 3C028007 */  lui   $v0, 0x8007
/* 0F1664 802CCCB4 8C42419C */  lw    $v0, 0x419c($v0)
/* 0F1668 802CCCB8 80420070 */  lb    $v0, 0x70($v0)
/* 0F166C 802CCCBC 14400005 */  bnez  $v0, .L802CCCD4
/* 0F1670 802CCCC0 00000000 */   nop   
/* 0F1674 802CCCC4 3C02802E */  lui   $v0, 0x802e
/* 0F1678 802CCCC8 2442ADF0 */  addiu $v0, $v0, -0x5210
/* 0F167C 802CCCCC 080B3337 */  j     .L802CCCDC
/* 0F1680 802CCCD0 00000000 */   nop   

.L802CCCD4:
/* 0F1684 802CCCD4 3C02802E */  lui   $v0, 0x802e
/* 0F1688 802CCCD8 2442ADB0 */  addiu $v0, $v0, -0x5250
.L802CCCDC:
/* 0F168C 802CCCDC 3C01802E */  lui   $at, 0x802e
/* 0F1690 802CCCE0 AC22AE30 */  sw    $v0, -0x51d0($at)
/* 0F1694 802CCCE4 03E00008 */  jr    $ra
/* 0F1698 802CCCE8 24020002 */   addiu $v0, $zero, 2

