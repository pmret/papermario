.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetBattleInputMask
/* 19C930 8026E050 8C82000C */  lw    $v0, 0xc($a0)
/* 19C934 8026E054 8C420000 */  lw    $v0, ($v0)
/* 19C938 8026E058 3C01800E */  lui   $at, 0x800e
/* 19C93C 8026E05C AC22C294 */  sw    $v0, -0x3d6c($at)
/* 19C940 8026E060 03E00008 */  jr    $ra
/* 19C944 8026E064 24020002 */   addiu $v0, $zero, 2

