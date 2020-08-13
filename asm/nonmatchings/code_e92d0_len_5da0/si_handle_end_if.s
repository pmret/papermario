.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_end_if
/* 0E991C 802C4F6C 03E00008 */  jr    $ra
/* 0E9920 802C4F70 24020002 */   addiu $v0, $zero, 2

