.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1438_72E968
/* 72E968 802A1438 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 72E96C 802A143C 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 72E970 802A1440 90A20002 */  lbu       $v0, 2($a1)
/* 72E974 802A1444 3C068009 */  lui       $a2, %hi(gItemTable+0x12BB)
/* 72E978 802A1448 90C68B9B */  lbu       $a2, %lo(gItemTable+0x12BB)($a2)
/* 72E97C 802A144C 80A30003 */  lb        $v1, 3($a1)
/* 72E980 802A1450 00461021 */  addu      $v0, $v0, $a2
/* 72E984 802A1454 A0A20002 */  sb        $v0, 2($a1)
/* 72E988 802A1458 00021600 */  sll       $v0, $v0, 0x18
/* 72E98C 802A145C 00021603 */  sra       $v0, $v0, 0x18
/* 72E990 802A1460 0062182A */  slt       $v1, $v1, $v0
/* 72E994 802A1464 90A20003 */  lbu       $v0, 3($a1)
/* 72E998 802A1468 54600001 */  bnel      $v1, $zero, .L802A1470
/* 72E99C 802A146C A0A20002 */   sb       $v0, 2($a1)
.L802A1470:
/* 72E9A0 802A1470 00061600 */  sll       $v0, $a2, 0x18
/* 72E9A4 802A1474 00021603 */  sra       $v0, $v0, 0x18
/* 72E9A8 802A1478 AC820090 */  sw        $v0, 0x90($a0)
/* 72E9AC 802A147C 03E00008 */  jr        $ra
/* 72E9B0 802A1480 24020002 */   addiu    $v0, $zero, 2
