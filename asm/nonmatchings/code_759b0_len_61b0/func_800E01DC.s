.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E01DC
/* 07968C 800E01DC 3C048011 */  lui   $a0, 0x8011
/* 079690 800E01E0 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 079694 800E01E4 8C820004 */  lw    $v0, 4($a0)
/* 079698 800E01E8 30420010 */  andi  $v0, $v0, 0x10
/* 07969C 800E01EC 10400004 */  beqz  $v0, .L800E0200
/* 0796A0 800E01F0 3C030800 */   lui   $v1, 0x800
/* 0796A4 800E01F4 8C820000 */  lw    $v0, ($a0)
/* 0796A8 800E01F8 00431025 */  or    $v0, $v0, $v1
/* 0796AC 800E01FC AC820000 */  sw    $v0, ($a0)
.L800E0200:
/* 0796B0 800E0200 03E00008 */  jr    $ra
/* 0796B4 800E0204 00000000 */   nop   

