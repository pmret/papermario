.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EB168
/* 084618 800EB168 3C038011 */  lui   $v1, 0x8011
/* 08461C 800EB16C 8C63CFD8 */  lw    $v1, -0x3028($v1)
/* 084620 800EB170 3C058011 */  lui   $a1, 0x8011
/* 084624 800EB174 24A5EFC8 */  addiu $a1, $a1, -0x1038
/* 084628 800EB178 1064000C */  beq   $v1, $a0, .L800EB1AC
/* 08462C 800EB17C 24020001 */   addiu $v0, $zero, 1
/* 084630 800EB180 3C018011 */  lui   $at, 0x8011
/* 084634 800EB184 AC22CFE0 */  sw    $v0, -0x3020($at)
/* 084638 800EB188 3C018011 */  lui   $at, 0x8011
/* 08463C 800EB18C AC24CFE4 */  sw    $a0, -0x301c($at)
/* 084640 800EB190 10600008 */  beqz  $v1, .L800EB1B4
/* 084644 800EB194 00000000 */   nop   
/* 084648 800EB198 10800009 */  beqz  $a0, .L800EB1C0
/* 08464C 800EB19C 24020004 */   addiu $v0, $zero, 4
/* 084650 800EB1A0 24020003 */  addiu $v0, $zero, 3
/* 084654 800EB1A4 3C018011 */  lui   $at, 0x8011
/* 084658 800EB1A8 AC22CFE8 */  sw    $v0, -0x3018($at)
.L800EB1AC:
/* 08465C 800EB1AC 03E00008 */  jr    $ra
/* 084660 800EB1B0 00000000 */   nop   

.L800EB1B4:
/* 084664 800EB1B4 14800006 */  bnez  $a0, .L800EB1D0
/* 084668 800EB1B8 24020006 */   addiu $v0, $zero, 6
/* 08466C 800EB1BC 24020004 */  addiu $v0, $zero, 4
.L800EB1C0:
/* 084670 800EB1C0 3C018011 */  lui   $at, 0x8011
/* 084674 800EB1C4 AC22CFE8 */  sw    $v0, -0x3018($at)
/* 084678 800EB1C8 03E00008 */  jr    $ra
/* 08467C 800EB1CC 00000000 */   nop   

.L800EB1D0:
/* 084680 800EB1D0 C4A00028 */  lwc1  $f0, 0x28($a1)
/* 084684 800EB1D4 C4A2002C */  lwc1  $f2, 0x2c($a1)
/* 084688 800EB1D8 C4A40030 */  lwc1  $f4, 0x30($a1)
/* 08468C 800EB1DC 3C018011 */  lui   $at, 0x8011
/* 084690 800EB1E0 AC22CFE8 */  sw    $v0, -0x3018($at)
/* 084694 800EB1E4 3C018010 */  lui   $at, 0x8010
/* 084698 800EB1E8 E420833C */  swc1  $f0, -0x7cc4($at)
/* 08469C 800EB1EC 3C018010 */  lui   $at, 0x8010
/* 0846A0 800EB1F0 E4228340 */  swc1  $f2, -0x7cc0($at)
/* 0846A4 800EB1F4 3C018010 */  lui   $at, 0x8010
/* 0846A8 800EB1F8 03E00008 */  jr    $ra
/* 0846AC 800EB1FC E4248344 */   swc1  $f4, -0x7cbc($at)

