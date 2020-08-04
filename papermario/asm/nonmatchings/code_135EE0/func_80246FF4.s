.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246FF4
.L80246FF4:
/* 13A334 80246FF4 3C038008 */  lui   $v1, 0x8008
/* 13A338 80246FF8 00621821 */  addu  $v1, $v1, $v0
