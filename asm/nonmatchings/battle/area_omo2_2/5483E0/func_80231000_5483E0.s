.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80231000_5483E0
/* 5483E0 80231000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5483E4 80231004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5483E8 80231008 8C82000C */  lw        $v0, 0xc($a0)
/* 5483EC 8023100C 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 5483F0 80231010 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 5483F4 80231014 0C0B2026 */  jal       set_variable
/* 5483F8 80231018 8C450000 */   lw       $a1, ($v0)
/* 5483FC 8023101C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 548400 80231020 24020002 */  addiu     $v0, $zero, 2
/* 548404 80231024 03E00008 */  jr        $ra
/* 548408 80231028 27BD0018 */   addiu    $sp, $sp, 0x18
