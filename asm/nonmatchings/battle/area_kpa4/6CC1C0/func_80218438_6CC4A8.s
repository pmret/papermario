.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218438_6CC4A8
/* 6CC4A8 80218438 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6CC4AC 8021843C AFBF0010 */  sw        $ra, 0x10($sp)
/* 6CC4B0 80218440 8C82000C */  lw        $v0, 0xc($a0)
/* 6CC4B4 80218444 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 6CC4B8 80218448 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 6CC4BC 8021844C 0C0B2026 */  jal       set_variable
/* 6CC4C0 80218450 8C450000 */   lw       $a1, ($v0)
/* 6CC4C4 80218454 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6CC4C8 80218458 24020002 */  addiu     $v0, $zero, 2
/* 6CC4CC 8021845C 03E00008 */  jr        $ra
/* 6CC4D0 80218460 27BD0018 */   addiu    $sp, $sp, 0x18
