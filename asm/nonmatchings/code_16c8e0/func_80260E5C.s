.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260E5C
/* 18F73C 80260E5C 3C03FFFF */  lui       $v1, 0xffff
/* 18F740 80260E60 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 18F744 80260E64 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 18F748 80260E68 8C820000 */  lw        $v0, ($a0)
/* 18F74C 80260E6C 34637FFF */  ori       $v1, $v1, 0x7fff
/* 18F750 80260E70 00431024 */  and       $v0, $v0, $v1
/* 18F754 80260E74 2403DFFF */  addiu     $v1, $zero, -0x2001
/* 18F758 80260E78 00431024 */  and       $v0, $v0, $v1
/* 18F75C 80260E7C 2403BFFF */  addiu     $v1, $zero, -0x4001
/* 18F760 80260E80 00431024 */  and       $v0, $v0, $v1
/* 18F764 80260E84 AC820000 */  sw        $v0, ($a0)
/* 18F768 80260E88 03E00008 */  jr        $ra
/* 18F76C 80260E8C 24020002 */   addiu    $v0, $zero, 2
