.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241670
/* B36240 80241670 3C058011 */  lui       $a1, %hi(gPlayerData)
/* B36244 80241674 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* B36248 80241678 AC800088 */  sw        $zero, 0x88($a0)
/* B3624C 8024167C 80A30003 */  lb        $v1, 3($a1)
/* B36250 80241680 80A20002 */  lb        $v0, 2($a1)
/* B36254 80241684 1462000B */  bne       $v1, $v0, .L802416B4
/* B36258 80241688 00A0302D */   daddu    $a2, $a1, $zero
/* B3625C 8024168C 80A30006 */  lb        $v1, 6($a1)
/* B36260 80241690 80A20005 */  lb        $v0, 5($a1)
/* B36264 80241694 14620007 */  bne       $v1, $v0, .L802416B4
/* B36268 80241698 00000000 */   nop      
/* B3626C 8024169C 80C2028E */  lb        $v0, 0x28e($a2)
/* B36270 802416A0 84C30290 */  lh        $v1, 0x290($a2)
/* B36274 802416A4 00021200 */  sll       $v0, $v0, 8
/* B36278 802416A8 14620004 */  bne       $v1, $v0, .L802416BC
/* B3627C 802416AC 24020001 */   addiu    $v0, $zero, 1
/* B36280 802416B0 AC820088 */  sw        $v0, 0x88($a0)
.L802416B4:
/* B36284 802416B4 03E00008 */  jr        $ra
/* B36288 802416B8 24020002 */   addiu    $v0, $zero, 2
.L802416BC:
/* B3628C 802416BC 03E00008 */  jr        $ra
/* B36290 802416C0 24020002 */   addiu    $v0, $zero, 2
