.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802C6E14
/* 0EB7C4 802C6E14 03E00008 */  jr    $ra
/* 0EB7C8 802C6E18 24020002 */   addiu $v0, $zero, 2

