.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD4E0
/* 324DF0 802BD4E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 324DF4 802BD4E4 3C058011 */  lui       $a1, %hi(D_8010C954)
/* 324DF8 802BD4E8 24A5C954 */  addiu     $a1, $a1, %lo(D_8010C954)
/* 324DFC 802BD4EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 324E00 802BD4F0 8CA20000 */  lw        $v0, ($a1)
/* 324E04 802BD4F4 10400008 */  beqz      $v0, .L802BD518
/* 324E08 802BD4F8 00000000 */   nop
/* 324E0C 802BD4FC 3C03802C */  lui       $v1, %hi(D_802BD58C)
/* 324E10 802BD500 8C63D58C */  lw        $v1, %lo(D_802BD58C)($v1)
/* 324E14 802BD504 8C620008 */  lw        $v0, 8($v1)
/* 324E18 802BD508 ACA00000 */  sw        $zero, ($a1)
/* 324E1C 802BD50C AC820000 */  sw        $v0, ($a0)
/* 324E20 802BD510 0C03BD17 */  jal       clear_partner_move_history
/* 324E24 802BD514 AC600004 */   sw       $zero, 4($v1)
.L802BD518:
/* 324E28 802BD518 8FBF0010 */  lw        $ra, 0x10($sp)
/* 324E2C 802BD51C 03E00008 */  jr        $ra
/* 324E30 802BD520 27BD0018 */   addiu    $sp, $sp, 0x18
