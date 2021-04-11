.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kmr_20_UnkFunc34
/* 8ED280 80241460 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 8ED284 80241464 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 8ED288 80241468 AC800088 */  sw        $zero, 0x88($a0)
/* 8ED28C 8024146C 80A30003 */  lb        $v1, 3($a1)
/* 8ED290 80241470 80A20002 */  lb        $v0, 2($a1)
/* 8ED294 80241474 1462000B */  bne       $v1, $v0, .L802414A4
/* 8ED298 80241478 00A0302D */   daddu    $a2, $a1, $zero
/* 8ED29C 8024147C 80A30006 */  lb        $v1, 6($a1)
/* 8ED2A0 80241480 80A20005 */  lb        $v0, 5($a1)
/* 8ED2A4 80241484 14620007 */  bne       $v1, $v0, .L802414A4
/* 8ED2A8 80241488 00000000 */   nop
/* 8ED2AC 8024148C 80C2028E */  lb        $v0, 0x28e($a2)
/* 8ED2B0 80241490 84C30290 */  lh        $v1, 0x290($a2)
/* 8ED2B4 80241494 00021200 */  sll       $v0, $v0, 8
/* 8ED2B8 80241498 14620004 */  bne       $v1, $v0, .L802414AC
/* 8ED2BC 8024149C 24020001 */   addiu    $v0, $zero, 1
/* 8ED2C0 802414A0 AC820088 */  sw        $v0, 0x88($a0)
.L802414A4:
/* 8ED2C4 802414A4 03E00008 */  jr        $ra
/* 8ED2C8 802414A8 24020002 */   addiu    $v0, $zero, 2
.L802414AC:
/* 8ED2CC 802414AC 03E00008 */  jr        $ra
/* 8ED2D0 802414B0 24020002 */   addiu    $v0, $zero, 2
