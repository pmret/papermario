.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A9898
/* 41E628 802A9898 AE420318 */  sw    $v0, 0x318($s2)
/* 41E62C 802A989C AE500324 */  sw    $s0, 0x324($s2)
/* 41E630 802A98A0 00031880 */  sll   $v1, $v1, 2
/* 41E634 802A98A4 3C028009 */  lui   $v0, 0x8009
/* 41E638 802A98A8 00431021 */  addu  $v0, $v0, $v1
/* 41E63C 802A98AC 8C42EEF0 */  lw    $v0, -0x1110($v0)
