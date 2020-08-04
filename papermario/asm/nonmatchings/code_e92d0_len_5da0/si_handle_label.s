.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_label
/* 0E9368 802C49B8 03E00008 */  jr    $ra
/* 0E936C 802C49BC 24020002 */   addiu $v0, $zero, 2

