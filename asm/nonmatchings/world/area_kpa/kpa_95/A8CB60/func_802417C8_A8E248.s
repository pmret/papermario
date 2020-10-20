.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417C8_A8E248
/* A8E248 802417C8 3C058011 */  lui       $a1, %hi(gPlayerData)
/* A8E24C 802417CC 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* A8E250 802417D0 AC800088 */  sw        $zero, 0x88($a0)
/* A8E254 802417D4 80A30003 */  lb        $v1, 3($a1)
/* A8E258 802417D8 80A20002 */  lb        $v0, 2($a1)
/* A8E25C 802417DC 1462000B */  bne       $v1, $v0, .L8024180C
/* A8E260 802417E0 00A0302D */   daddu    $a2, $a1, $zero
/* A8E264 802417E4 80A30006 */  lb        $v1, 6($a1)
/* A8E268 802417E8 80A20005 */  lb        $v0, 5($a1)
/* A8E26C 802417EC 14620007 */  bne       $v1, $v0, .L8024180C
/* A8E270 802417F0 00000000 */   nop      
/* A8E274 802417F4 80C2028E */  lb        $v0, 0x28e($a2)
/* A8E278 802417F8 84C30290 */  lh        $v1, 0x290($a2)
/* A8E27C 802417FC 00021200 */  sll       $v0, $v0, 8
/* A8E280 80241800 14620004 */  bne       $v1, $v0, .L80241814
/* A8E284 80241804 24020001 */   addiu    $v0, $zero, 1
/* A8E288 80241808 AC820088 */  sw        $v0, 0x88($a0)
.L8024180C:
/* A8E28C 8024180C 03E00008 */  jr        $ra
/* A8E290 80241810 24020002 */   addiu    $v0, $zero, 2
.L80241814:
/* A8E294 80241814 03E00008 */  jr        $ra
/* A8E298 80241818 24020002 */   addiu    $v0, $zero, 2
