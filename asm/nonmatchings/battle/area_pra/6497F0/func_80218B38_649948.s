.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B38_649948
/* 649948 80218B38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 64994C 80218B3C AFBF0010 */  sw        $ra, 0x10($sp)
/* 649950 80218B40 8C82000C */  lw        $v0, 0xc($a0)
/* 649954 80218B44 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 649958 80218B48 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 64995C 80218B4C 0C0B2026 */  jal       set_variable
/* 649960 80218B50 8C450000 */   lw       $a1, ($v0)
/* 649964 80218B54 8FBF0010 */  lw        $ra, 0x10($sp)
/* 649968 80218B58 24020002 */  addiu     $v0, $zero, 2
/* 64996C 80218B5C 03E00008 */  jr        $ra
/* 649970 80218B60 27BD0018 */   addiu    $sp, $sp, 0x18
