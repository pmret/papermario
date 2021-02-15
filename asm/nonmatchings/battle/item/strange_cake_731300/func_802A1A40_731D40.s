.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1A40_731D40
/* 731D40 802A1A40 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 731D44 802A1A44 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 731D48 802A1A48 90A20002 */  lbu       $v0, 2($a1)
/* 731D4C 802A1A4C 3C068009 */  lui       $a2, %hi(gItemTable+0x1A7B)
/* 731D50 802A1A50 90C6935B */  lbu       $a2, %lo(gItemTable+0x1A7B)($a2)
/* 731D54 802A1A54 80A30003 */  lb        $v1, 3($a1)
/* 731D58 802A1A58 00461021 */  addu      $v0, $v0, $a2
/* 731D5C 802A1A5C A0A20002 */  sb        $v0, 2($a1)
/* 731D60 802A1A60 00021600 */  sll       $v0, $v0, 0x18
/* 731D64 802A1A64 00021603 */  sra       $v0, $v0, 0x18
/* 731D68 802A1A68 0062182A */  slt       $v1, $v1, $v0
/* 731D6C 802A1A6C 90A20003 */  lbu       $v0, 3($a1)
/* 731D70 802A1A70 54600001 */  bnel      $v1, $zero, .L802A1A78
/* 731D74 802A1A74 A0A20002 */   sb       $v0, 2($a1)
.L802A1A78:
/* 731D78 802A1A78 00061600 */  sll       $v0, $a2, 0x18
/* 731D7C 802A1A7C 00021603 */  sra       $v0, $v0, 0x18
/* 731D80 802A1A80 AC820090 */  sw        $v0, 0x90($a0)
/* 731D84 802A1A84 03E00008 */  jr        $ra
/* 731D88 802A1A88 24020002 */   addiu    $v0, $zero, 2
