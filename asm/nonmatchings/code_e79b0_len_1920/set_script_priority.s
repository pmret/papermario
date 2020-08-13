.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_script_priority
/* 0E8B88 802C41D8 03E00008 */  jr    $ra
/* 0E8B8C 802C41DC A0850003 */   sb    $a1, 3($a0)

