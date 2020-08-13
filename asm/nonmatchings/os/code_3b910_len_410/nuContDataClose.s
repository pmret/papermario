.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuContDataClose
/* 03BA0C 8006060C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BA10 80060610 3C04800E */  lui   $a0, 0x800e
/* 03BA14 80060614 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BA18 80060618 0000282D */  daddu $a1, $zero, $zero
/* 03BA1C 8006061C AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BA20 80060620 0C019608 */  jal   osSendMesg
/* 03BA24 80060624 24060001 */   addiu $a2, $zero, 1
/* 03BA28 80060628 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BA2C 8006062C 03E00008 */  jr    $ra
/* 03BA30 80060630 27BD0018 */   addiu $sp, $sp, 0x18

