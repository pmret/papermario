.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802497D0
/* 13CB10 802497D0 00041040 */  sll   $v0, $a0, 1
/* 13CB14 802497D4 00441021 */  addu  $v0, $v0, $a0
