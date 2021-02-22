.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F0_D06120
/* D06120 802409F0 3C058011 */  lui       $a1, %hi(gPlayerData)
/* D06124 802409F4 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* D06128 802409F8 AC800088 */  sw        $zero, 0x88($a0)
/* D0612C 802409FC 80A30003 */  lb        $v1, 3($a1)
/* D06130 80240A00 80A20002 */  lb        $v0, 2($a1)
/* D06134 80240A04 1462000B */  bne       $v1, $v0, .L80240A34
/* D06138 80240A08 00A0302D */   daddu    $a2, $a1, $zero
/* D0613C 80240A0C 80A30006 */  lb        $v1, 6($a1)
/* D06140 80240A10 80A20005 */  lb        $v0, 5($a1)
/* D06144 80240A14 14620007 */  bne       $v1, $v0, .L80240A34
/* D06148 80240A18 00000000 */   nop
/* D0614C 80240A1C 80C2028E */  lb        $v0, 0x28e($a2)
/* D06150 80240A20 84C30290 */  lh        $v1, 0x290($a2)
/* D06154 80240A24 00021200 */  sll       $v0, $v0, 8
/* D06158 80240A28 14620004 */  bne       $v1, $v0, .L80240A3C
/* D0615C 80240A2C 24020001 */   addiu    $v0, $zero, 1
/* D06160 80240A30 AC820088 */  sw        $v0, 0x88($a0)
.L80240A34:
/* D06164 80240A34 03E00008 */  jr        $ra
/* D06168 80240A38 24020002 */   addiu    $v0, $zero, 2
.L80240A3C:
/* D0616C 80240A3C 03E00008 */  jr        $ra
/* D06170 80240A40 24020002 */   addiu    $v0, $zero, 2
