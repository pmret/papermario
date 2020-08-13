.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A1050
/* 415DE0 802A1050 24020002 */  addiu $v0, $zero, 2
/* 415DE4 802A1054 3C01802B */  lui   $at, 0x802b
/* 415DE8 802A1058 A022D000 */  sb    $v0, -0x3000($at)
/* 415DEC 802A105C 240200FF */  addiu $v0, $zero, 0xff
/* 415DF0 802A1060 3C01802B */  lui   $at, 0x802b
/* 415DF4 802A1064 A422D006 */  sh    $v0, -0x2ffa($at)
/* 415DF8 802A1068 3C01802B */  lui   $at, 0x802b
/* 415DFC 802A106C A422D008 */  sh    $v0, -0x2ff8($at)
/* 415E00 802A1070 03E00008 */  jr    $ra
/* 415E04 802A1074 00000000 */   nop   

