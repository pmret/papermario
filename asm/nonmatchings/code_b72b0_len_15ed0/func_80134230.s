.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80134230
/* 0CA930 80134230 3C018015 */  lui   $at, 0x8015
/* 0CA934 80134234 AC245D88 */  sw    $a0, 0x5d88($at)
/* 0CA938 80134238 03E00008 */  jr    $ra
/* 0CA93C 8013423C 00000000 */   nop   

