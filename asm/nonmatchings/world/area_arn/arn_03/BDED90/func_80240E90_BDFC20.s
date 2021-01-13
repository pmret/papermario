.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_BDFC20
/* BDFC20 80240E90 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BDFC24 80240E94 AFB20030 */  sw        $s2, 0x30($sp)
/* BDFC28 80240E98 0080902D */  daddu     $s2, $a0, $zero
/* BDFC2C 80240E9C AFBF0034 */  sw        $ra, 0x34($sp)
/* BDFC30 80240EA0 AFB1002C */  sw        $s1, 0x2c($sp)
/* BDFC34 80240EA4 AFB00028 */  sw        $s0, 0x28($sp)
/* BDFC38 80240EA8 F7B60040 */  sdc1      $f22, 0x40($sp)
/* BDFC3C 80240EAC F7B40038 */  sdc1      $f20, 0x38($sp)
/* BDFC40 80240EB0 8E500148 */  lw        $s0, 0x148($s2)
/* BDFC44 80240EB4 0C00EABB */  jal       get_npc_unsafe
/* BDFC48 80240EB8 86040008 */   lh       $a0, 8($s0)
/* BDFC4C 80240EBC 0040882D */  daddu     $s1, $v0, $zero
/* BDFC50 80240EC0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BDFC54 80240EC4 8E430078 */  lw        $v1, 0x78($s2)
/* BDFC58 80240EC8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BDFC5C 80240ECC 00031040 */  sll       $v0, $v1, 1
/* BDFC60 80240ED0 00431021 */  addu      $v0, $v0, $v1
/* BDFC64 80240ED4 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BDFC68 80240ED8 00021080 */  sll       $v0, $v0, 2
/* BDFC6C 80240EDC 00431021 */  addu      $v0, $v0, $v1
/* BDFC70 80240EE0 C4560004 */  lwc1      $f22, 4($v0)
/* BDFC74 80240EE4 4680B5A0 */  cvt.s.w   $f22, $f22
/* BDFC78 80240EE8 C454000C */  lwc1      $f20, 0xc($v0)
/* BDFC7C 80240EEC 4680A520 */  cvt.s.w   $f20, $f20
/* BDFC80 80240EF0 4406B000 */  mfc1      $a2, $f22
/* BDFC84 80240EF4 4407A000 */  mfc1      $a3, $f20
/* BDFC88 80240EF8 E7AC0018 */  swc1      $f12, 0x18($sp)
/* BDFC8C 80240EFC 0C00A720 */  jal       atan2
/* BDFC90 80240F00 E7AE0020 */   swc1     $f14, 0x20($sp)
/* BDFC94 80240F04 8E250018 */  lw        $a1, 0x18($s1)
/* BDFC98 80240F08 44060000 */  mfc1      $a2, $f0
/* BDFC9C 80240F0C 0220202D */  daddu     $a0, $s1, $zero
/* BDFCA0 80240F10 0C00EA95 */  jal       npc_move_heading
/* BDFCA4 80240F14 AE26000C */   sw       $a2, 0xc($s1)
/* BDFCA8 80240F18 27A50018 */  addiu     $a1, $sp, 0x18
/* BDFCAC 80240F1C 27A6001C */  addiu     $a2, $sp, 0x1c
/* BDFCB0 80240F20 C6200038 */  lwc1      $f0, 0x38($s1)
/* BDFCB4 80240F24 8E430078 */  lw        $v1, 0x78($s2)
/* BDFCB8 80240F28 3C01447A */  lui       $at, 0x447a
/* BDFCBC 80240F2C 44812000 */  mtc1      $at, $f4
/* BDFCC0 80240F30 00031040 */  sll       $v0, $v1, 1
/* BDFCC4 80240F34 00431021 */  addu      $v0, $v0, $v1
/* BDFCC8 80240F38 00021080 */  sll       $v0, $v0, 2
/* BDFCCC 80240F3C E7A00018 */  swc1      $f0, 0x18($sp)
/* BDFCD0 80240F40 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BDFCD4 80240F44 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDFCD8 80240F48 C6220040 */  lwc1      $f2, 0x40($s1)
/* BDFCDC 80240F4C 00431021 */  addu      $v0, $v0, $v1
/* BDFCE0 80240F50 C4460008 */  lwc1      $f6, 8($v0)
/* BDFCE4 80240F54 468031A0 */  cvt.s.w   $f6, $f6
/* BDFCE8 80240F58 27A20024 */  addiu     $v0, $sp, 0x24
/* BDFCEC 80240F5C 46060000 */  add.s     $f0, $f0, $f6
/* BDFCF0 80240F60 E7A20020 */  swc1      $f2, 0x20($sp)
/* BDFCF4 80240F64 E7A40024 */  swc1      $f4, 0x24($sp)
/* BDFCF8 80240F68 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BDFCFC 80240F6C AFA20010 */  sw        $v0, 0x10($sp)
/* BDFD00 80240F70 8E240080 */  lw        $a0, 0x80($s1)
/* BDFD04 80240F74 0C0372DF */  jal       func_800DCB7C
/* BDFD08 80240F78 27A70020 */   addiu    $a3, $sp, 0x20
/* BDFD0C 80240F7C 8E430078 */  lw        $v1, 0x78($s2)
/* BDFD10 80240F80 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* BDFD14 80240F84 00031040 */  sll       $v0, $v1, 1
/* BDFD18 80240F88 00431021 */  addu      $v0, $v0, $v1
/* BDFD1C 80240F8C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BDFD20 80240F90 00021080 */  sll       $v0, $v0, 2
/* BDFD24 80240F94 00431021 */  addu      $v0, $v0, $v1
/* BDFD28 80240F98 C4400008 */  lwc1      $f0, 8($v0)
/* BDFD2C 80240F9C 46800020 */  cvt.s.w   $f0, $f0
/* BDFD30 80240FA0 46001080 */  add.s     $f2, $f2, $f0
/* BDFD34 80240FA4 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDFD38 80240FA8 3C014000 */  lui       $at, 0x4000
/* BDFD3C 80240FAC 44813800 */  mtc1      $at, $f7
/* BDFD40 80240FB0 44803000 */  mtc1      $zero, $f6
/* BDFD44 80240FB4 46001001 */  sub.s     $f0, $f2, $f0
/* BDFD48 80240FB8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BDFD4C 80240FBC 46000121 */  cvt.d.s   $f4, $f0
/* BDFD50 80240FC0 4624303C */  c.lt.d    $f6, $f4
/* BDFD54 80240FC4 00000000 */  nop
/* BDFD58 80240FC8 45000005 */  bc1f      .L80240FE0
/* BDFD5C 80240FCC E7A00024 */   swc1     $f0, 0x24($sp)
/* BDFD60 80240FD0 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDFD64 80240FD4 46000021 */  cvt.d.s   $f0, $f0
/* BDFD68 80240FD8 08090403 */  j         .L8024100C
/* BDFD6C 80240FDC 46260000 */   add.d    $f0, $f0, $f6
.L80240FE0:
/* BDFD70 80240FE0 3C01C000 */  lui       $at, 0xc000
/* BDFD74 80240FE4 44810800 */  mtc1      $at, $f1
/* BDFD78 80240FE8 44800000 */  mtc1      $zero, $f0
/* BDFD7C 80240FEC 00000000 */  nop
/* BDFD80 80240FF0 4620203C */  c.lt.d    $f4, $f0
/* BDFD84 80240FF4 00000000 */  nop
/* BDFD88 80240FF8 45020006 */  bc1fl     .L80241014
/* BDFD8C 80240FFC E622003C */   swc1     $f2, 0x3c($s1)
/* BDFD90 80241000 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDFD94 80241004 46000021 */  cvt.d.s   $f0, $f0
/* BDFD98 80241008 46260001 */  sub.d     $f0, $f0, $f6
.L8024100C:
/* BDFD9C 8024100C 46200020 */  cvt.s.d   $f0, $f0
/* BDFDA0 80241010 E620003C */  swc1      $f0, 0x3c($s1)
.L80241014:
/* BDFDA4 80241014 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BDFDA8 80241018 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BDFDAC 8024101C 4406B000 */  mfc1      $a2, $f22
/* BDFDB0 80241020 4407A000 */  mfc1      $a3, $f20
/* BDFDB4 80241024 0C00A7B5 */  jal       dist2D
/* BDFDB8 80241028 00000000 */   nop
/* BDFDBC 8024102C C6220018 */  lwc1      $f2, 0x18($s1)
/* BDFDC0 80241030 4600103C */  c.lt.s    $f2, $f0
/* BDFDC4 80241034 00000000 */  nop
/* BDFDC8 80241038 45010003 */  bc1t      .L80241048
/* BDFDCC 8024103C E7A00024 */   swc1     $f0, 0x24($sp)
/* BDFDD0 80241040 24020002 */  addiu     $v0, $zero, 2
/* BDFDD4 80241044 AE420070 */  sw        $v0, 0x70($s2)
.L80241048:
/* BDFDD8 80241048 8FBF0034 */  lw        $ra, 0x34($sp)
/* BDFDDC 8024104C 8FB20030 */  lw        $s2, 0x30($sp)
/* BDFDE0 80241050 8FB1002C */  lw        $s1, 0x2c($sp)
/* BDFDE4 80241054 8FB00028 */  lw        $s0, 0x28($sp)
/* BDFDE8 80241058 D7B60040 */  ldc1      $f22, 0x40($sp)
/* BDFDEC 8024105C D7B40038 */  ldc1      $f20, 0x38($sp)
/* BDFDF0 80241060 03E00008 */  jr        $ra
/* BDFDF4 80241064 27BD0048 */   addiu    $sp, $sp, 0x48
