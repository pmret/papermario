.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186B8_5B1B68
/* 5B1B68 802186B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5B1B6C 802186BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 5B1B70 802186C0 8C82000C */  lw        $v0, 0xc($a0)
/* 5B1B74 802186C4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 5B1B78 802186C8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 5B1B7C 802186CC 0C0B2026 */  jal       set_variable
/* 5B1B80 802186D0 8C450000 */   lw       $a1, ($v0)
/* 5B1B84 802186D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5B1B88 802186D8 24020002 */  addiu     $v0, $zero, 2
/* 5B1B8C 802186DC 03E00008 */  jr        $ra
/* 5B1B90 802186E0 27BD0018 */   addiu    $sp, $sp, 0x18
