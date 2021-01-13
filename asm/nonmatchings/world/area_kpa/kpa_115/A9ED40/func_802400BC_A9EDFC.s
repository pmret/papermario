.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400BC_A9EDFC
/* A9EDFC 802400BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A9EE00 802400C0 AFBF002C */  sw        $ra, 0x2c($sp)
/* A9EE04 802400C4 AFB00028 */  sw        $s0, 0x28($sp)
/* A9EE08 802400C8 8C820098 */  lw        $v0, 0x98($a0)
/* A9EE0C 802400CC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A9EE10 802400D0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A9EE14 802400D4 14400005 */  bnez      $v0, .L802400EC
/* A9EE18 802400D8 00000000 */   nop
/* A9EE1C 802400DC C4800084 */  lwc1      $f0, 0x84($a0)
/* A9EE20 802400E0 46800020 */  cvt.s.w   $f0, $f0
/* A9EE24 802400E4 0809003E */  j         .L802400F8
/* A9EE28 802400E8 E6000028 */   swc1     $f0, 0x28($s0)
.L802400EC:
/* A9EE2C 802400EC C4800084 */  lwc1      $f0, 0x84($a0)
/* A9EE30 802400F0 46800020 */  cvt.s.w   $f0, $f0
/* A9EE34 802400F4 E6000030 */  swc1      $f0, 0x30($s0)
.L802400F8:
/* A9EE38 802400F8 27A20024 */  addiu     $v0, $sp, 0x24
/* A9EE3C 802400FC 0000202D */  daddu     $a0, $zero, $zero
/* A9EE40 80240100 27A50018 */  addiu     $a1, $sp, 0x18
/* A9EE44 80240104 27A6001C */  addiu     $a2, $sp, 0x1c
/* A9EE48 80240108 C6000028 */  lwc1      $f0, 0x28($s0)
/* A9EE4C 8024010C 3C014120 */  lui       $at, 0x4120
/* A9EE50 80240110 44811000 */  mtc1      $at, $f2
/* A9EE54 80240114 3C014220 */  lui       $at, 0x4220
/* A9EE58 80240118 44813000 */  mtc1      $at, $f6
/* A9EE5C 8024011C 27A70020 */  addiu     $a3, $sp, 0x20
/* A9EE60 80240120 E7A00018 */  swc1      $f0, 0x18($sp)
/* A9EE64 80240124 C600002C */  lwc1      $f0, 0x2c($s0)
/* A9EE68 80240128 C6040030 */  lwc1      $f4, 0x30($s0)
/* A9EE6C 8024012C 46020000 */  add.s     $f0, $f0, $f2
/* A9EE70 80240130 E7A60024 */  swc1      $f6, 0x24($sp)
/* A9EE74 80240134 E7A40020 */  swc1      $f4, 0x20($sp)
/* A9EE78 80240138 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A9EE7C 8024013C 0C0372DF */  jal       func_800DCB7C
/* A9EE80 80240140 AFA20010 */   sw       $v0, 0x10($sp)
/* A9EE84 80240144 C7A00018 */  lwc1      $f0, 0x18($sp)
/* A9EE88 80240148 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* A9EE8C 8024014C C7A40020 */  lwc1      $f4, 0x20($sp)
/* A9EE90 80240150 E6000028 */  swc1      $f0, 0x28($s0)
/* A9EE94 80240154 E602002C */  swc1      $f2, 0x2c($s0)
/* A9EE98 80240158 E6040030 */  swc1      $f4, 0x30($s0)
/* A9EE9C 8024015C 8FBF002C */  lw        $ra, 0x2c($sp)
/* A9EEA0 80240160 8FB00028 */  lw        $s0, 0x28($sp)
/* A9EEA4 80240164 24020002 */  addiu     $v0, $zero, 2
/* A9EEA8 80240168 03E00008 */  jr        $ra
/* A9EEAC 8024016C 27BD0030 */   addiu    $sp, $sp, 0x30
