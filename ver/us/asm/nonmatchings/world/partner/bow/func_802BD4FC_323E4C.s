.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD4FC_323E4C
/* 323E4C 802BD4FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 323E50 802BD500 3C058011 */  lui       $a1, %hi(D_8010C954)
/* 323E54 802BD504 24A5C954 */  addiu     $a1, $a1, %lo(D_8010C954)
/* 323E58 802BD508 AFBF0010 */  sw        $ra, 0x10($sp)
/* 323E5C 802BD50C 8CA20000 */  lw        $v0, ($a1)
/* 323E60 802BD510 10400008 */  beqz      $v0, .L802BD534
/* 323E64 802BD514 00000000 */   nop
/* 323E68 802BD518 3C03802C */  lui       $v1, %hi(D_802BDFFC_32494C)
/* 323E6C 802BD51C 8C63DFFC */  lw        $v1, %lo(D_802BDFFC_32494C)($v1)
/* 323E70 802BD520 8C620008 */  lw        $v0, 8($v1)
/* 323E74 802BD524 ACA00000 */  sw        $zero, ($a1)
/* 323E78 802BD528 AC820000 */  sw        $v0, ($a0)
/* 323E7C 802BD52C 0C03BD17 */  jal       partner_clear_player_tracking
/* 323E80 802BD530 AC600004 */   sw       $zero, 4($v1)
.L802BD534:
/* 323E84 802BD534 8FBF0010 */  lw        $ra, 0x10($sp)
/* 323E88 802BD538 03E00008 */  jr        $ra
/* 323E8C 802BD53C 27BD0018 */   addiu    $sp, $sp, 0x18
