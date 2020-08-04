.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024E60C
/* 17CEEC 8024E60C 3C01802A */  lui   $at, 0x802a
/* 17CEF0 8024E610 A020F2A6 */  sb    $zero, -0xd5a($at)
/* 17CEF4 8024E614 03E00008 */  jr    $ra
/* 17CEF8 8024E618 00000000 */   nop   

