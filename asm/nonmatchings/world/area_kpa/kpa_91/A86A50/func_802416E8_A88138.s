.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416E8_A88138
/* A88138 802416E8 3C058011 */  lui       $a1, %hi(gPlayerData)
/* A8813C 802416EC 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* A88140 802416F0 AC800088 */  sw        $zero, 0x88($a0)
/* A88144 802416F4 80A30003 */  lb        $v1, 3($a1)
/* A88148 802416F8 80A20002 */  lb        $v0, 2($a1)
/* A8814C 802416FC 1462000B */  bne       $v1, $v0, .L8024172C
/* A88150 80241700 00A0302D */   daddu    $a2, $a1, $zero
/* A88154 80241704 80A30006 */  lb        $v1, 6($a1)
/* A88158 80241708 80A20005 */  lb        $v0, 5($a1)
/* A8815C 8024170C 14620007 */  bne       $v1, $v0, .L8024172C
/* A88160 80241710 00000000 */   nop
/* A88164 80241714 80C2028E */  lb        $v0, 0x28e($a2)
/* A88168 80241718 84C30290 */  lh        $v1, 0x290($a2)
/* A8816C 8024171C 00021200 */  sll       $v0, $v0, 8
/* A88170 80241720 14620004 */  bne       $v1, $v0, .L80241734
/* A88174 80241724 24020001 */   addiu    $v0, $zero, 1
/* A88178 80241728 AC820088 */  sw        $v0, 0x88($a0)
.L8024172C:
/* A8817C 8024172C 03E00008 */  jr        $ra
/* A88180 80241730 24020002 */   addiu    $v0, $zero, 2
.L80241734:
/* A88184 80241734 03E00008 */  jr        $ra
/* A88188 80241738 24020002 */   addiu    $v0, $zero, 2
