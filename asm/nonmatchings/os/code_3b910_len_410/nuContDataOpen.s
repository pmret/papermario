.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuContDataOpen
/* 03BA34 80060634 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BA38 80060638 3C04800E */  lui   $a0, 0x800e
/* 03BA3C 8006063C 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BA40 80060640 0000282D */  daddu $a1, $zero, $zero
/* 03BA44 80060644 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BA48 80060648 0C0195BC */  jal   osRecvMesg
/* 03BA4C 8006064C 24060001 */   addiu $a2, $zero, 1
/* 03BA50 80060650 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BA54 80060654 03E00008 */  jr    $ra
/* 03BA58 80060658 27BD0018 */   addiu $sp, $sp, 0x18

