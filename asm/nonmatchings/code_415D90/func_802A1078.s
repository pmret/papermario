.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A1078
/* 415E08 802A1078 240200FF */  addiu $v0, $zero, 0xff
/* 415E0C 802A107C 3C01802B */  lui   $at, 0x802b
/* 415E10 802A1080 A422D008 */  sh    $v0, -0x2ff8($at)
/* 415E14 802A1084 24020014 */  addiu $v0, $zero, 0x14
/* 415E18 802A1088 3C01802B */  lui   $at, 0x802b
/* 415E1C 802A108C A022D000 */  sb    $v0, -0x3000($at)
/* 415E20 802A1090 03E00008 */  jr    $ra
/* 415E24 802A1094 00000000 */   nop   

