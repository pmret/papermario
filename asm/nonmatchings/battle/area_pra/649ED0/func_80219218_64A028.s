.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219218_64A028
/* 64A028 80219218 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 64A02C 8021921C AFBF0010 */  sw        $ra, 0x10($sp)
/* 64A030 80219220 8C82000C */  lw        $v0, 0xc($a0)
/* 64A034 80219224 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 64A038 80219228 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 64A03C 8021922C 0C0B2026 */  jal       set_variable
/* 64A040 80219230 8C450000 */   lw       $a1, ($v0)
/* 64A044 80219234 8FBF0010 */  lw        $ra, 0x10($sp)
/* 64A048 80219238 24020002 */  addiu     $v0, $zero, 2
/* 64A04C 8021923C 03E00008 */  jr        $ra
/* 64A050 80219240 27BD0018 */   addiu    $sp, $sp, 0x18
