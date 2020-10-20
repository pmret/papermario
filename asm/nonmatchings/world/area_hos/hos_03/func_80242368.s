.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242368
/* A1D468 80242368 3C058011 */  lui       $a1, %hi(gPlayerData)
/* A1D46C 8024236C 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* A1D470 80242370 AC800088 */  sw        $zero, 0x88($a0)
/* A1D474 80242374 80A30003 */  lb        $v1, 3($a1)
/* A1D478 80242378 80A20002 */  lb        $v0, 2($a1)
/* A1D47C 8024237C 1462000B */  bne       $v1, $v0, .L802423AC
/* A1D480 80242380 00A0302D */   daddu    $a2, $a1, $zero
/* A1D484 80242384 80A30006 */  lb        $v1, 6($a1)
/* A1D488 80242388 80A20005 */  lb        $v0, 5($a1)
/* A1D48C 8024238C 14620007 */  bne       $v1, $v0, .L802423AC
/* A1D490 80242390 00000000 */   nop      
/* A1D494 80242394 80C2028E */  lb        $v0, 0x28e($a2)
/* A1D498 80242398 84C30290 */  lh        $v1, 0x290($a2)
/* A1D49C 8024239C 00021200 */  sll       $v0, $v0, 8
/* A1D4A0 802423A0 14620004 */  bne       $v1, $v0, .L802423B4
/* A1D4A4 802423A4 24020001 */   addiu    $v0, $zero, 1
/* A1D4A8 802423A8 AC820088 */  sw        $v0, 0x88($a0)
.L802423AC:
/* A1D4AC 802423AC 03E00008 */  jr        $ra
/* A1D4B0 802423B0 24020002 */   addiu    $v0, $zero, 2
.L802423B4:
/* A1D4B4 802423B4 03E00008 */  jr        $ra
/* A1D4B8 802423B8 24020002 */   addiu    $v0, $zero, 2
