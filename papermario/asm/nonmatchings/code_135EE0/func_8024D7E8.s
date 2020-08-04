.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024D7E8
/* 140B28 8024D7E8 3C018027 */  lui   $at, 0x8027
/* 140B2C 8024D7EC AC2200C8 */  sw    $v0, 0xc8($at)
