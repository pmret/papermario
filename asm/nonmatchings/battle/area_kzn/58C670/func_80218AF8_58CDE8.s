.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AF8_58CDE8
/* 58CDE8 80218AF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 58CDEC 80218AFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 58CDF0 80218B00 8C82000C */  lw        $v0, 0xc($a0)
/* 58CDF4 80218B04 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 58CDF8 80218B08 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 58CDFC 80218B0C 0C0B2026 */  jal       set_variable
/* 58CE00 80218B10 8C450000 */   lw       $a1, ($v0)
/* 58CE04 80218B14 8FBF0010 */  lw        $ra, 0x10($sp)
/* 58CE08 80218B18 24020002 */  addiu     $v0, $zero, 2
/* 58CE0C 80218B1C 03E00008 */  jr        $ra
/* 58CE10 80218B20 27BD0018 */   addiu    $sp, $sp, 0x18
