.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802184E8_684F18
/* 684F18 802184E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 684F1C 802184EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 684F20 802184F0 8C82000C */  lw        $v0, 0xc($a0)
/* 684F24 802184F4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 684F28 802184F8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 684F2C 802184FC 0C0B2026 */  jal       set_variable
/* 684F30 80218500 8C450000 */   lw       $a1, ($v0)
/* 684F34 80218504 8FBF0010 */  lw        $ra, 0x10($sp)
/* 684F38 80218508 24020002 */  addiu     $v0, $zero, 2
/* 684F3C 8021850C 03E00008 */  jr        $ra
/* 684F40 80218510 27BD0018 */   addiu    $sp, $sp, 0x18
