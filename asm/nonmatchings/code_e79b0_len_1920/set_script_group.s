.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_script_group
/* 0E8BC8 802C4218 03E00008 */  jr    $ra
/* 0E8BCC 802C421C A0850004 */   sb    $a1, 4($a0)

