.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219CF8_66BA78
/* 66BA78 80219CF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66BA7C 80219CFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 66BA80 80219D00 8C82000C */  lw        $v0, 0xc($a0)
/* 66BA84 80219D04 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 66BA88 80219D08 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 66BA8C 80219D0C 0C0B2026 */  jal       set_variable
/* 66BA90 80219D10 8C450000 */   lw       $a1, ($v0)
/* 66BA94 80219D14 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66BA98 80219D18 24020002 */  addiu     $v0, $zero, 2
/* 66BA9C 80219D1C 03E00008 */  jr        $ra
/* 66BAA0 80219D20 27BD0018 */   addiu    $sp, $sp, 0x18
