.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269E80
/* 198760 80269E80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 198764 80269E84 AFBF0010 */  sw        $ra, 0x10($sp)
/* 198768 80269E88 8C82000C */  lw        $v0, 0xc($a0)
/* 19876C 80269E8C 3C06800E */  lui       $a2, %hi(gBattleStatus+0x19A)
/* 198770 80269E90 90C6C20A */  lbu       $a2, %lo(gBattleStatus+0x19A)($a2)
/* 198774 80269E94 0C0B2026 */  jal       set_variable
/* 198778 80269E98 8C450000 */   lw       $a1, ($v0)
/* 19877C 80269E9C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 198780 80269EA0 24020002 */  addiu     $v0, $zero, 2
/* 198784 80269EA4 03E00008 */  jr        $ra
/* 198788 80269EA8 27BD0018 */   addiu    $sp, $sp, 0x18
