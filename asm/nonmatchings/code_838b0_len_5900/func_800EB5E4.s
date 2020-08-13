.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EB5E4
/* 084A94 800EB5E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 084A98 800EB5E8 3C028011 */  lui   $v0, 0x8011
/* 084A9C 800EB5EC 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 084AA0 800EB5F0 0080282D */  daddu $a1, $a0, $zero
/* 084AA4 800EB5F4 1040000C */  beqz  $v0, .L800EB628
/* 084AA8 800EB5F8 AFBF0010 */   sw    $ra, 0x10($sp)
/* 084AAC 800EB5FC 3C028011 */  lui   $v0, 0x8011
/* 084AB0 800EB600 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 084AB4 800EB604 8C420028 */  lw    $v0, 0x28($v0)
/* 084AB8 800EB608 50400008 */  beql  $v0, $zero, .L800EB62C
/* 084ABC 800EB60C 0000102D */   daddu $v0, $zero, $zero
/* 084AC0 800EB610 3C048011 */  lui   $a0, 0x8011
/* 084AC4 800EB614 8C84C930 */  lw    $a0, -0x36d0($a0)
/* 084AC8 800EB618 0040F809 */  jalr  $v0
/* 084ACC 800EB61C 00000000 */  nop   
/* 084AD0 800EB620 0803AD8B */  j     .L800EB62C
/* 084AD4 800EB624 00000000 */   nop   

.L800EB628:
/* 084AD8 800EB628 0000102D */  daddu $v0, $zero, $zero
.L800EB62C:
/* 084ADC 800EB62C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 084AE0 800EB630 03E00008 */  jr    $ra
/* 084AE4 800EB634 27BD0018 */   addiu $sp, $sp, 0x18

