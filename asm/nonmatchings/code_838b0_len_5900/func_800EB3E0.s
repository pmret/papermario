.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EB3E0
/* 084890 800EB3E0 3C028011 */  lui   $v0, 0x8011
/* 084894 800EB3E4 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 084898 800EB3E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08489C 800EB3EC 1040000B */  beqz  $v0, .L800EB41C
/* 0848A0 800EB3F0 AFBF0010 */   sw    $ra, 0x10($sp)
/* 0848A4 800EB3F4 8C420030 */  lw    $v0, 0x30($v0)
/* 0848A8 800EB3F8 50400009 */  beql  $v0, $zero, .L800EB420
/* 0848AC 800EB3FC 24020001 */   addiu $v0, $zero, 1
/* 0848B0 800EB400 3C048011 */  lui   $a0, 0x8011
/* 0848B4 800EB404 8C84C930 */  lw    $a0, -0x36d0($a0)
/* 0848B8 800EB408 0040F809 */  jalr  $v0
/* 0848BC 800EB40C 00000000 */  nop   
/* 0848C0 800EB410 0040182D */  daddu $v1, $v0, $zero
/* 0848C4 800EB414 10600002 */  beqz  $v1, .L800EB420
/* 0848C8 800EB418 0000102D */   daddu $v0, $zero, $zero
.L800EB41C:
/* 0848CC 800EB41C 24020001 */  addiu $v0, $zero, 1
.L800EB420:
/* 0848D0 800EB420 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0848D4 800EB424 03E00008 */  jr    $ra
/* 0848D8 800EB428 27BD0018 */   addiu $sp, $sp, 0x18

