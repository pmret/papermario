.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802187C8_6495D8
/* 6495D8 802187C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6495DC 802187CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 6495E0 802187D0 8C82000C */  lw        $v0, 0xc($a0)
/* 6495E4 802187D4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 6495E8 802187D8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 6495EC 802187DC 0C0B2026 */  jal       set_variable
/* 6495F0 802187E0 8C450000 */   lw       $a1, ($v0)
/* 6495F4 802187E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6495F8 802187E8 24020002 */  addiu     $v0, $zero, 2
/* 6495FC 802187EC 03E00008 */  jr        $ra
/* 649600 802187F0 27BD0018 */   addiu    $sp, $sp, 0x18
