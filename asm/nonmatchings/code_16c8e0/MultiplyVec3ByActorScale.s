.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel MultiplyVec3ByActorScale
/* 1829BC 802540DC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1829C0 802540E0 AFB00010 */  sw    $s0, 0x10($sp)
/* 1829C4 802540E4 0080802D */  daddu $s0, $a0, $zero
/* 1829C8 802540E8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1829CC 802540EC AFB20018 */  sw    $s2, 0x18($sp)
/* 1829D0 802540F0 AFB10014 */  sw    $s1, 0x14($sp)
/* 1829D4 802540F4 8E040148 */  lw    $a0, 0x148($s0)
/* 1829D8 802540F8 0C09A75B */  jal   get_actor
/* 1829DC 802540FC 8E11000C */   lw    $s1, 0xc($s0)
/* 1829E0 80254100 0200202D */  daddu $a0, $s0, $zero
/* 1829E4 80254104 8E250000 */  lw    $a1, ($s1)
/* 1829E8 80254108 0C0B210B */  jal   get_float_variable
/* 1829EC 8025410C 0040902D */   daddu $s2, $v0, $zero
/* 1829F0 80254110 C6420188 */  lwc1  $f2, 0x188($s2)
/* 1829F4 80254114 46020002 */  mul.s $f0, $f0, $f2
/* 1829F8 80254118 00000000 */  nop   
/* 1829FC 8025411C 8E250000 */  lw    $a1, ($s1)
/* 182A00 80254120 44060000 */  mfc1  $a2, $f0
/* 182A04 80254124 0C0B2190 */  jal   set_float_variable
/* 182A08 80254128 0200202D */   daddu $a0, $s0, $zero
/* 182A0C 8025412C 8E250004 */  lw    $a1, 4($s1)
/* 182A10 80254130 0C0B210B */  jal   get_float_variable
/* 182A14 80254134 0200202D */   daddu $a0, $s0, $zero
/* 182A18 80254138 C6420188 */  lwc1  $f2, 0x188($s2)
/* 182A1C 8025413C 46020002 */  mul.s $f0, $f0, $f2
/* 182A20 80254140 00000000 */  nop   
/* 182A24 80254144 8E250004 */  lw    $a1, 4($s1)
/* 182A28 80254148 44060000 */  mfc1  $a2, $f0
/* 182A2C 8025414C 0C0B2190 */  jal   set_float_variable
/* 182A30 80254150 0200202D */   daddu $a0, $s0, $zero
/* 182A34 80254154 8E250008 */  lw    $a1, 8($s1)
/* 182A38 80254158 0C0B210B */  jal   get_float_variable
/* 182A3C 8025415C 0200202D */   daddu $a0, $s0, $zero
/* 182A40 80254160 C6420188 */  lwc1  $f2, 0x188($s2)
/* 182A44 80254164 46020002 */  mul.s $f0, $f0, $f2
/* 182A48 80254168 00000000 */  nop   
/* 182A4C 8025416C 8E250008 */  lw    $a1, 8($s1)
/* 182A50 80254170 44060000 */  mfc1  $a2, $f0
/* 182A54 80254174 0C0B2190 */  jal   set_float_variable
/* 182A58 80254178 0200202D */   daddu $a0, $s0, $zero
/* 182A5C 8025417C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 182A60 80254180 8FB20018 */  lw    $s2, 0x18($sp)
/* 182A64 80254184 8FB10014 */  lw    $s1, 0x14($sp)
/* 182A68 80254188 8FB00010 */  lw    $s0, 0x10($sp)
/* 182A6C 8025418C 24020002 */  addiu $v0, $zero, 2
/* 182A70 80254190 03E00008 */  jr    $ra
/* 182A74 80254194 27BD0020 */   addiu $sp, $sp, 0x20

