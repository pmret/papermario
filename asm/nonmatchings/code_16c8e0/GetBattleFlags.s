.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetBattleFlags
/* 19B5F0 8026CD10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19B5F4 8026CD14 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19B5F8 8026CD18 8C82000C */  lw    $v0, 0xc($a0)
/* 19B5FC 8026CD1C 3C06800E */  lui   $a2, 0x800e
/* 19B600 8026CD20 8CC6C070 */  lw    $a2, -0x3f90($a2)
/* 19B604 8026CD24 0C0B2026 */  jal   set_variable
/* 19B608 8026CD28 8C450000 */   lw    $a1, ($v0)
/* 19B60C 8026CD2C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19B610 8026CD30 24020002 */  addiu $v0, $zero, 2
/* 19B614 8026CD34 03E00008 */  jr    $ra
/* 19B618 8026CD38 27BD0018 */   addiu $sp, $sp, 0x18

