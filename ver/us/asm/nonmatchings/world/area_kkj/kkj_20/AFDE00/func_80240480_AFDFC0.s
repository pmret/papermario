.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kkj_20_UnkFunc34
/* AFDFC0 80240480 3C058011 */  lui       $a1, %hi(gPlayerData)
/* AFDFC4 80240484 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* AFDFC8 80240488 AC800088 */  sw        $zero, 0x88($a0)
/* AFDFCC 8024048C 80A30003 */  lb        $v1, 3($a1)
/* AFDFD0 80240490 80A20002 */  lb        $v0, 2($a1)
/* AFDFD4 80240494 1462000B */  bne       $v1, $v0, .L802404C4
/* AFDFD8 80240498 00A0302D */   daddu    $a2, $a1, $zero
/* AFDFDC 8024049C 80A30006 */  lb        $v1, 6($a1)
/* AFDFE0 802404A0 80A20005 */  lb        $v0, 5($a1)
/* AFDFE4 802404A4 14620007 */  bne       $v1, $v0, .L802404C4
/* AFDFE8 802404A8 00000000 */   nop
/* AFDFEC 802404AC 80C2028E */  lb        $v0, 0x28e($a2)
/* AFDFF0 802404B0 84C30290 */  lh        $v1, 0x290($a2)
/* AFDFF4 802404B4 00021200 */  sll       $v0, $v0, 8
/* AFDFF8 802404B8 14620004 */  bne       $v1, $v0, .L802404CC
/* AFDFFC 802404BC 24020001 */   addiu    $v0, $zero, 1
/* AFE000 802404C0 AC820088 */  sw        $v0, 0x88($a0)
.L802404C4:
/* AFE004 802404C4 03E00008 */  jr        $ra
/* AFE008 802404C8 24020002 */   addiu    $v0, $zero, 2
.L802404CC:
/* AFE00C 802404CC 03E00008 */  jr        $ra
/* AFE010 802404D0 24020002 */   addiu    $v0, $zero, 2
