.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EB580
/* 084A30 800EB580 3C028011 */  lui   $v0, 0x8011
/* 084A34 800EB584 2442EBB0 */  addiu $v0, $v0, -0x1450
/* 084A38 800EB588 3C018011 */  lui   $at, 0x8011
/* 084A3C 800EB58C AC20CFD8 */  sw    $zero, -0x3028($at)
/* 084A40 800EB590 3C018011 */  lui   $at, 0x8011
/* 084A44 800EB594 AC20CFE0 */  sw    $zero, -0x3020($at)
/* 084A48 800EB598 3C018011 */  lui   $at, 0x8011
/* 084A4C 800EB59C AC20CFE8 */  sw    $zero, -0x3018($at)
/* 084A50 800EB5A0 3C018011 */  lui   $at, 0x8011
/* 084A54 800EB5A4 AC20CFC4 */  sw    $zero, -0x303c($at)
/* 084A58 800EB5A8 A0400003 */  sb    $zero, 3($v0)
/* 084A5C 800EB5AC A0400014 */  sb    $zero, 0x14($v0)
/* 084A60 800EB5B0 A0400001 */  sb    $zero, 1($v0)
/* 084A64 800EB5B4 A0400000 */  sb    $zero, ($v0)
/* 084A68 800EB5B8 AC400358 */  sw    $zero, 0x358($v0)
/* 084A6C 800EB5BC A0400002 */  sb    $zero, 2($v0)
/* 084A70 800EB5C0 3C018011 */  lui   $at, 0x8011
/* 084A74 800EB5C4 AC20CFEC */  sw    $zero, -0x3014($at)
/* 084A78 800EB5C8 3C018010 */  lui   $at, 0x8010
/* 084A7C 800EB5CC AC20833C */  sw    $zero, -0x7cc4($at)
/* 084A80 800EB5D0 3C018010 */  lui   $at, 0x8010
/* 084A84 800EB5D4 AC208340 */  sw    $zero, -0x7cc0($at)
/* 084A88 800EB5D8 3C018010 */  lui   $at, 0x8010
/* 084A8C 800EB5DC 03E00008 */  jr    $ra
/* 084A90 800EB5E0 AC208344 */   sw    $zero, -0x7cbc($at)

