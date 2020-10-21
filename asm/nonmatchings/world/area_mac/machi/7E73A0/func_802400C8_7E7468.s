.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C8_7E7468
/* 7E7468 802400C8 8C820084 */  lw        $v0, 0x84($a0)
/* 7E746C 802400CC 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 7E7470 802400D0 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 7E7474 802400D4 24420001 */  addiu     $v0, $v0, 1
/* 7E7478 802400D8 000210C0 */  sll       $v0, $v0, 3
/* 7E747C 802400DC 00451021 */  addu      $v0, $v0, $a1
/* 7E7480 802400E0 90430015 */  lbu       $v1, 0x15($v0)
/* 7E7484 802400E4 24630001 */  addiu     $v1, $v1, 1
/* 7E7488 802400E8 A0430015 */  sb        $v1, 0x15($v0)
/* 7E748C 802400EC AC800084 */  sw        $zero, 0x84($a0)
/* 7E7490 802400F0 80A2001D */  lb        $v0, 0x1d($a1)
/* 7E7494 802400F4 28420003 */  slti      $v0, $v0, 3
/* 7E7498 802400F8 14400004 */  bnez      $v0, .L8024010C
/* 7E749C 802400FC 24020002 */   addiu    $v0, $zero, 2
/* 7E74A0 80240100 A0A2001D */  sb        $v0, 0x1d($a1)
/* 7E74A4 80240104 24020001 */  addiu     $v0, $zero, 1
/* 7E74A8 80240108 AC820084 */  sw        $v0, 0x84($a0)
.L8024010C:
/* 7E74AC 8024010C 03E00008 */  jr        $ra
/* 7E74B0 80240110 24020002 */   addiu    $v0, $zero, 2
