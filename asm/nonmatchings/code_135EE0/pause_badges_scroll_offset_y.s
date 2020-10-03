.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_scroll_offset_y
/* 13A5D8 80247298 3C028027 */  lui       $v0, 0x8027
/* 13A5DC 8024729C 8C42038C */  lw        $v0, 0x38c($v0)
/* 13A5E0 802472A0 03E00008 */  jr        $ra
/* 13A5E4 802472A4 00821023 */   subu     $v0, $a0, $v0
