.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A97BC
/* 41E54C 802A97BC 00000000 */   nop   
/* 41E550 802A97C0 0C0A8426 */  jal   func_802A1098
/* 41E554 802A97C4 00000000 */   nop   
/* 41E558 802A97C8 080AA6A9 */  j     .L802A9AA4
