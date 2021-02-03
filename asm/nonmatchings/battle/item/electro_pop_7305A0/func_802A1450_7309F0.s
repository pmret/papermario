.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1450_7309F0
/* 7309F0 802A1450 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 7309F4 802A1454 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 7309F8 802A1458 90A20002 */  lbu       $v0, 2($a1)
/* 7309FC 802A145C 3C068009 */  lui       $a2, %hi(gItemTable+0x199B)
/* 730A00 802A1460 90C6927B */  lbu       $a2, %lo(gItemTable+0x199B)($a2)
/* 730A04 802A1464 80A30003 */  lb        $v1, 3($a1)
/* 730A08 802A1468 00461021 */  addu      $v0, $v0, $a2
/* 730A0C 802A146C A0A20002 */  sb        $v0, 2($a1)
/* 730A10 802A1470 00021600 */  sll       $v0, $v0, 0x18
/* 730A14 802A1474 00021603 */  sra       $v0, $v0, 0x18
/* 730A18 802A1478 0062182A */  slt       $v1, $v1, $v0
/* 730A1C 802A147C 90A20003 */  lbu       $v0, 3($a1)
/* 730A20 802A1480 54600001 */  bnel      $v1, $zero, .L802A1488
/* 730A24 802A1484 A0A20002 */   sb       $v0, 2($a1)
.L802A1488:
/* 730A28 802A1488 00061600 */  sll       $v0, $a2, 0x18
/* 730A2C 802A148C 00021603 */  sra       $v0, $v0, 0x18
/* 730A30 802A1490 AC820090 */  sw        $v0, 0x90($a0)
/* 730A34 802A1494 03E00008 */  jr        $ra
/* 730A38 802A1498 24020002 */   addiu    $v0, $zero, 2
