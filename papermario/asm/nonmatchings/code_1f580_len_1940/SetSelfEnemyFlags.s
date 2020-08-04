.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetSelfEnemyFlags
/* 02090C 8004550C 8C82000C */  lw    $v0, 0xc($a0)
/* 020910 80045510 8C830148 */  lw    $v1, 0x148($a0)
/* 020914 80045514 8C420000 */  lw    $v0, ($v0)
/* 020918 80045518 AC620000 */  sw    $v0, ($v1)
/* 02091C 8004551C 03E00008 */  jr    $ra
/* 020920 80045520 24020002 */   addiu $v0, $zero, 2

