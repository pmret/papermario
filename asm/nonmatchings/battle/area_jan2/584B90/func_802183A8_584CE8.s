.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183A8_584CE8
/* 584CE8 802183A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 584CEC 802183AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 584CF0 802183B0 8C82000C */  lw        $v0, 0xc($a0)
/* 584CF4 802183B4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 584CF8 802183B8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 584CFC 802183BC 0C0B2026 */  jal       set_variable
/* 584D00 802183C0 8C450000 */   lw       $a1, ($v0)
/* 584D04 802183C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 584D08 802183C8 24020002 */  addiu     $v0, $zero, 2
/* 584D0C 802183CC 03E00008 */  jr        $ra
/* 584D10 802183D0 27BD0018 */   addiu    $sp, $sp, 0x18
