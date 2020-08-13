.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A1000
/* 415D90 802A1000 240200FF */  addiu $v0, $zero, 0xff
/* 415D94 802A1004 3C01802B */  lui   $at, 0x802b
/* 415D98 802A1008 A422D006 */  sh    $v0, -0x2ffa($at)
/* 415D9C 802A100C 3C01802B */  lui   $at, 0x802b
/* 415DA0 802A1010 A422D008 */  sh    $v0, -0x2ff8($at)
/* 415DA4 802A1014 2402FFFF */  addiu $v0, $zero, -1
/* 415DA8 802A1018 3C01802B */  lui   $at, 0x802b
/* 415DAC 802A101C A020D000 */  sb    $zero, -0x3000($at)
/* 415DB0 802A1020 3C01802B */  lui   $at, 0x802b
/* 415DB4 802A1024 A022D068 */  sb    $v0, -0x2f98($at)
/* 415DB8 802A1028 03E00008 */  jr    $ra
/* 415DBC 802A102C 00000000 */   nop   

