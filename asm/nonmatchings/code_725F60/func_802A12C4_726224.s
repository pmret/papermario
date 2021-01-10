.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12C4_726224
/* 726224 802A12C4 24020002 */  addiu     $v0, $zero, 2
/* 726228 802A12C8 3C01800E */  lui       $at, %hi(gBattleStatus+0x8B)
/* 72622C 802A12CC A022C0FB */  sb        $v0, %lo(gBattleStatus+0x8B)($at)
/* 726230 802A12D0 03E00008 */  jr        $ra
/* 726234 802A12D4 24020002 */   addiu    $v0, $zero, 2
/* 726238 802A12D8 00000000 */  nop       
/* 72623C 802A12DC 00000000 */  nop       
