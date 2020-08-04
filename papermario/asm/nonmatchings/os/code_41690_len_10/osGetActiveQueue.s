.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osGetActiveQueue
/* 041690 80066290 3C028009 */  lui   $v0, 0x8009
/* 041694 80066294 03E00008 */  jr    $ra
/* 041698 80066298 8C42465C */   lw    $v0, 0x465c($v0)

/* 04169C 8006629C 00000000 */  nop   

.set reorder
