.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A14F0_730A90
/* 730A90 802A14F0 3C068009 */  lui       $a2, %hi(gItemTable+0x1980)
/* 730A94 802A14F4 24C69260 */  addiu     $a2, $a2, %lo(gItemTable+0x1980)
/* 730A98 802A14F8 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 730A9C 802A14FC 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 730AA0 802A1500 90A20005 */  lbu       $v0, 5($a1)
/* 730AA4 802A1504 90C3001B */  lbu       $v1, 0x1b($a2)
/* 730AA8 802A1508 00431021 */  addu      $v0, $v0, $v1
/* 730AAC 802A150C A0A20005 */  sb        $v0, 5($a1)
/* 730AB0 802A1510 00021600 */  sll       $v0, $v0, 0x18
/* 730AB4 802A1514 80A30006 */  lb        $v1, 6($a1)
/* 730AB8 802A1518 00021603 */  sra       $v0, $v0, 0x18
/* 730ABC 802A151C 0062182A */  slt       $v1, $v1, $v0
/* 730AC0 802A1520 90A20006 */  lbu       $v0, 6($a1)
/* 730AC4 802A1524 54600001 */  bnel      $v1, $zero, .L802A152C
/* 730AC8 802A1528 A0A20005 */   sb       $v0, 5($a1)
.L802A152C:
/* 730ACC 802A152C 80C2001C */  lb        $v0, 0x1c($a2)
/* 730AD0 802A1530 AC820090 */  sw        $v0, 0x90($a0)
/* 730AD4 802A1534 03E00008 */  jr        $ra
/* 730AD8 802A1538 24020002 */   addiu    $v0, $zero, 2
/* 730ADC 802A153C 00000000 */  nop       
