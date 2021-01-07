.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219998_625538
/* 625538 80219998 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 62553C 8021999C AFBF0010 */  sw        $ra, 0x10($sp)
/* 625540 802199A0 8C82000C */  lw        $v0, 0xc($a0)
/* 625544 802199A4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 625548 802199A8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 62554C 802199AC 0C0B2026 */  jal       set_variable
/* 625550 802199B0 8C450000 */   lw       $a1, ($v0)
/* 625554 802199B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 625558 802199B8 24020002 */  addiu     $v0, $zero, 2
/* 62555C 802199BC 03E00008 */  jr        $ra
/* 625560 802199C0 27BD0018 */   addiu    $sp, $sp, 0x18
