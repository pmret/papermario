.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A28_5B1ED8
/* 5B1ED8 80218A28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5B1EDC 80218A2C AFBF0010 */  sw        $ra, 0x10($sp)
/* 5B1EE0 80218A30 8C82000C */  lw        $v0, 0xc($a0)
/* 5B1EE4 80218A34 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 5B1EE8 80218A38 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 5B1EEC 80218A3C 0C0B2026 */  jal       set_variable
/* 5B1EF0 80218A40 8C450000 */   lw       $a1, ($v0)
/* 5B1EF4 80218A44 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5B1EF8 80218A48 24020002 */  addiu     $v0, $zero, 2
/* 5B1EFC 80218A4C 03E00008 */  jr        $ra
/* 5B1F00 80218A50 27BD0018 */   addiu    $sp, $sp, 0x18
