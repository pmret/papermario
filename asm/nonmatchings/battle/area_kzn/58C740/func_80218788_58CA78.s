.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218788_58CA78
/* 58CA78 80218788 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 58CA7C 8021878C AFBF0010 */  sw        $ra, 0x10($sp)
/* 58CA80 80218790 8C82000C */  lw        $v0, 0xc($a0)
/* 58CA84 80218794 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 58CA88 80218798 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 58CA8C 8021879C 0C0B2026 */  jal       set_variable
/* 58CA90 802187A0 8C450000 */   lw       $a1, ($v0)
/* 58CA94 802187A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 58CA98 802187A8 24020002 */  addiu     $v0, $zero, 2
/* 58CA9C 802187AC 03E00008 */  jr        $ra
/* 58CAA0 802187B0 27BD0018 */   addiu    $sp, $sp, 0x18
