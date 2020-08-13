.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80241AB8
/* 170398 80241AB8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17039C 80241ABC 0000202D */  daddu $a0, $zero, $zero
/* 1703A0 80241AC0 0080282D */  daddu $a1, $a0, $zero
/* 1703A4 80241AC4 0080302D */  daddu $a2, $a0, $zero
/* 1703A8 80241AC8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1703AC 80241ACC 0C04DF84 */  jal   func_80137E10
/* 1703B0 80241AD0 0080382D */   daddu $a3, $a0, $zero
/* 1703B4 80241AD4 3C058028 */  lui   $a1, 0x8028
/* 1703B8 80241AD8 8CA50A30 */  lw    $a1, 0xa30($a1)
/* 1703BC 80241ADC 28A20100 */  slti  $v0, $a1, 0x100
/* 1703C0 80241AE0 14400003 */  bnez  $v0, .L80241AF0
/* 1703C4 80241AE4 00000000 */   nop   
/* 1703C8 80241AE8 080906C0 */  j     .L80241B00
/* 1703CC 80241AEC 3C05437F */   lui   $a1, 0x437f

.L80241AF0:
/* 1703D0 80241AF0 44850000 */  mtc1  $a1, $f0
/* 1703D4 80241AF4 00000000 */  nop   
/* 1703D8 80241AF8 46800020 */  cvt.s.w $f0, $f0
/* 1703DC 80241AFC 44050000 */  mfc1  $a1, $f0
.L80241B00:
/* 1703E0 80241B00 0C04DF62 */  jal   func_80137D88
/* 1703E4 80241B04 0000202D */   daddu $a0, $zero, $zero
/* 1703E8 80241B08 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1703EC 80241B0C 03E00008 */  jr    $ra
/* 1703F0 80241B10 27BD0018 */   addiu $sp, $sp, 0x18

