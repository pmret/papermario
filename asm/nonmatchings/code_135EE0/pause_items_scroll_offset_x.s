.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_scroll_offset_x
/* 13CCA8 80249968 03E00008 */  jr        $ra
/* 13CCAC 8024996C 0080102D */   daddu    $v0, $a0, $zero
