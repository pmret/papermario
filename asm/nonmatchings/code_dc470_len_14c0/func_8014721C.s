.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8014721C
/* 0DD91C 8014721C 3C018015 */  lui   $at, 0x8015
/* 0DD920 80147220 03E00008 */  jr    $ra
/* 0DD924 80147224 A020F12F */   sb    $zero, -0xed1($at)

/* 0DD928 80147228 00000000 */  nop   
/* 0DD92C 8014722C 00000000 */  nop   