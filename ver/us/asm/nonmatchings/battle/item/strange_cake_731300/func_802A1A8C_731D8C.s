.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1A8C_731D8C
/* 731D8C 802A1A8C 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 731D90 802A1A90 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 731D94 802A1A94 90A20005 */  lbu       $v0, 5($a1)
/* 731D98 802A1A98 3C068009 */  lui       $a2, %hi(gItemTable+0x1A7C)
/* 731D9C 802A1A9C 90C6935C */  lbu       $a2, %lo(gItemTable+0x1A7C)($a2)
/* 731DA0 802A1AA0 80A30006 */  lb        $v1, 6($a1)
/* 731DA4 802A1AA4 00461021 */  addu      $v0, $v0, $a2
/* 731DA8 802A1AA8 A0A20005 */  sb        $v0, 5($a1)
/* 731DAC 802A1AAC 00021600 */  sll       $v0, $v0, 0x18
/* 731DB0 802A1AB0 00021603 */  sra       $v0, $v0, 0x18
/* 731DB4 802A1AB4 0062182A */  slt       $v1, $v1, $v0
/* 731DB8 802A1AB8 90A20006 */  lbu       $v0, 6($a1)
/* 731DBC 802A1ABC 54600001 */  bnel      $v1, $zero, .L802A1AC4
/* 731DC0 802A1AC0 A0A20005 */   sb       $v0, 5($a1)
.L802A1AC4:
/* 731DC4 802A1AC4 00061600 */  sll       $v0, $a2, 0x18
/* 731DC8 802A1AC8 00021603 */  sra       $v0, $v0, 0x18
/* 731DCC 802A1ACC AC820090 */  sw        $v0, 0x90($a0)
/* 731DD0 802A1AD0 03E00008 */  jr        $ra
/* 731DD4 802A1AD4 24020002 */   addiu    $v0, $zero, 2
