.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetBattlePhase
/* 198708 80269E28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19870C 80269E2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 198710 80269E30 8C82000C */  lw    $v0, 0xc($a0)
/* 198714 80269E34 3C06800E */  lui   $a2, 0x800e
/* 198718 80269E38 80C6C217 */  lb    $a2, -0x3de9($a2)
/* 19871C 80269E3C 0C0B2026 */  jal   set_variable
/* 198720 80269E40 8C450000 */   lw    $a1, ($v0)
/* 198724 80269E44 8FBF0010 */  lw    $ra, 0x10($sp)
/* 198728 80269E48 24020002 */  addiu $v0, $zero, 2
/* 19872C 80269E4C 03E00008 */  jr    $ra
/* 198730 80269E50 27BD0018 */   addiu $sp, $sp, 0x18

