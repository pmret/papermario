.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD514_319A84
/* 319A84 802BD514 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 319A88 802BD518 3C058011 */  lui       $a1, %hi(D_8010C954)
/* 319A8C 802BD51C 24A5C954 */  addiu     $a1, $a1, %lo(D_8010C954)
/* 319A90 802BD520 AFBF0010 */  sw        $ra, 0x10($sp)
/* 319A94 802BD524 8CA20000 */  lw        $v0, ($a1)
/* 319A98 802BD528 10400008 */  beqz      $v0, .L802BD54C
/* 319A9C 802BD52C 00000000 */   nop
/* 319AA0 802BD530 3C03802C */  lui       $v1, %hi(D_802BEAAC_31B01C)
/* 319AA4 802BD534 8C63EAAC */  lw        $v1, %lo(D_802BEAAC_31B01C)($v1)
/* 319AA8 802BD538 8C620008 */  lw        $v0, 8($v1)
/* 319AAC 802BD53C ACA00000 */  sw        $zero, ($a1)
/* 319AB0 802BD540 AC820000 */  sw        $v0, ($a0)
/* 319AB4 802BD544 0C03BD17 */  jal       clear_partner_move_history
/* 319AB8 802BD548 AC600004 */   sw       $zero, 4($v1)
.L802BD54C:
/* 319ABC 802BD54C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 319AC0 802BD550 03E00008 */  jr        $ra
/* 319AC4 802BD554 27BD0018 */   addiu    $sp, $sp, 0x18
