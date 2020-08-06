.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_game_mode
/* 00E928 80033528 3C02800A */  lui   $v0, 0x800a
/* 00E92C 8003352C 844208F0 */  lh    $v0, 0x8f0($v0)
/* 00E930 80033530 03E00008 */  jr    $ra
/* 00E934 80033534 00000000 */   nop   

/* 00E938 80033538 00000000 */  nop   
/* 00E93C 8003353C 00000000 */  nop   


