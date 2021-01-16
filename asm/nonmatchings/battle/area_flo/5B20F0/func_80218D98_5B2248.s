.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D98_5B2248
/* 5B2248 80218D98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5B224C 80218D9C AFBF0010 */  sw        $ra, 0x10($sp)
/* 5B2250 80218DA0 8C82000C */  lw        $v0, 0xc($a0)
/* 5B2254 80218DA4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 5B2258 80218DA8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 5B225C 80218DAC 0C0B2026 */  jal       set_variable
/* 5B2260 80218DB0 8C450000 */   lw       $a1, ($v0)
/* 5B2264 80218DB4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5B2268 80218DB8 24020002 */  addiu     $v0, $zero, 2
/* 5B226C 80218DBC 03E00008 */  jr        $ra
/* 5B2270 80218DC0 27BD0018 */   addiu    $sp, $sp, 0x18
