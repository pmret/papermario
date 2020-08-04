.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSetTime
/* 041730 80066330 3C01800A */  lui   $at, 0x800a
/* 041734 80066334 AC24A608 */  sw    $a0, -0x59f8($at)
/* 041738 80066338 3C01800A */  lui   $at, 0x800a
/* 04173C 8006633C 03E00008 */  jr    $ra
/* 041740 80066340 AC25A60C */   sw    $a1, -0x59f4($at)

/* 041744 80066344 00000000 */  nop   
/* 041748 80066348 00000000 */  nop   
/* 04174C 8006634C 00000000 */  nop   

.set reorder
