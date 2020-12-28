.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219988_66B708
/* 66B708 80219988 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66B70C 8021998C AFBF0010 */  sw        $ra, 0x10($sp)
/* 66B710 80219990 8C82000C */  lw        $v0, 0xc($a0)
/* 66B714 80219994 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 66B718 80219998 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 66B71C 8021999C 0C0B2026 */  jal       set_variable
/* 66B720 802199A0 8C450000 */   lw       $a1, ($v0)
/* 66B724 802199A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66B728 802199A8 24020002 */  addiu     $v0, $zero, 2
/* 66B72C 802199AC 03E00008 */  jr        $ra
/* 66B730 802199B0 27BD0018 */   addiu    $sp, $sp, 0x18
