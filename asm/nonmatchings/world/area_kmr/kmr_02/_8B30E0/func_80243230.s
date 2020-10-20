.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243230
/* 8B32A0 80243230 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 8B32A4 80243234 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 8B32A8 80243238 AC800088 */  sw        $zero, 0x88($a0)
/* 8B32AC 8024323C 80A30003 */  lb        $v1, 3($a1)
/* 8B32B0 80243240 80A20002 */  lb        $v0, 2($a1)
/* 8B32B4 80243244 1462000B */  bne       $v1, $v0, .L80243274
/* 8B32B8 80243248 00A0302D */   daddu    $a2, $a1, $zero
/* 8B32BC 8024324C 80A30006 */  lb        $v1, 6($a1)
/* 8B32C0 80243250 80A20005 */  lb        $v0, 5($a1)
/* 8B32C4 80243254 14620007 */  bne       $v1, $v0, .L80243274
/* 8B32C8 80243258 00000000 */   nop      
/* 8B32CC 8024325C 80C2028E */  lb        $v0, 0x28e($a2)
/* 8B32D0 80243260 84C30290 */  lh        $v1, 0x290($a2)
/* 8B32D4 80243264 00021200 */  sll       $v0, $v0, 8
/* 8B32D8 80243268 14620004 */  bne       $v1, $v0, .L8024327C
/* 8B32DC 8024326C 24020001 */   addiu    $v0, $zero, 1
/* 8B32E0 80243270 AC820088 */  sw        $v0, 0x88($a0)
.L80243274:
/* 8B32E4 80243274 03E00008 */  jr        $ra
/* 8B32E8 80243278 24020002 */   addiu    $v0, $zero, 2
.L8024327C:
/* 8B32EC 8024327C 03E00008 */  jr        $ra
/* 8B32F0 80243280 24020002 */   addiu    $v0, $zero, 2
