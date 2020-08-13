.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetLastElement
/* 198734 80269E54 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 198738 80269E58 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19873C 80269E5C 8C82000C */  lw    $v0, 0xc($a0)
/* 198740 80269E60 3C06800E */  lui   $a2, 0x800e
/* 198744 80269E64 8CC6C1F8 */  lw    $a2, -0x3e08($a2)
/* 198748 80269E68 0C0B2026 */  jal   set_variable
/* 19874C 80269E6C 8C450000 */   lw    $a1, ($v0)
/* 198750 80269E70 8FBF0010 */  lw    $ra, 0x10($sp)
/* 198754 80269E74 24020002 */  addiu $v0, $zero, 2
/* 198758 80269E78 03E00008 */  jr    $ra
/* 19875C 80269E7C 27BD0018 */   addiu $sp, $sp, 0x18

/* 198760 80269E80 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 198764 80269E84 AFBF0010 */  sw    $ra, 0x10($sp)
/* 198768 80269E88 8C82000C */  lw    $v0, 0xc($a0)
/* 19876C 80269E8C 3C06800E */  lui   $a2, 0x800e
/* 198770 80269E90 90C6C20A */  lbu   $a2, -0x3df6($a2)
/* 198774 80269E94 0C0B2026 */  jal   set_variable
/* 198778 80269E98 8C450000 */   lw    $a1, ($v0)
/* 19877C 80269E9C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 198780 80269EA0 24020002 */  addiu $v0, $zero, 2
/* 198784 80269EA4 03E00008 */  jr    $ra
/* 198788 80269EA8 27BD0018 */   addiu $sp, $sp, 0x18

/* 19878C 80269EAC 8C82000C */  lw    $v0, 0xc($a0)
/* 198790 80269EB0 8C420000 */  lw    $v0, ($v0)
/* 198794 80269EB4 3C01800E */  lui   $at, 0x800e
/* 198798 80269EB8 A022C20A */  sb    $v0, -0x3df6($at)
/* 19879C 80269EBC 03E00008 */  jr    $ra
/* 1987A0 80269EC0 24020002 */   addiu $v0, $zero, 2

