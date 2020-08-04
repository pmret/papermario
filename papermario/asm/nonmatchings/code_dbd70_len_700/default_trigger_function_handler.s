.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel default_trigger_function_handler
/* 0DBD70 80145670 8C820000 */  lw    $v0, ($a0)
/* 0DBD74 80145674 34420002 */  ori   $v0, $v0, 2
/* 0DBD78 80145678 03E00008 */  jr    $ra
/* 0DBD7C 8014567C AC820000 */   sw    $v0, ($a0)

