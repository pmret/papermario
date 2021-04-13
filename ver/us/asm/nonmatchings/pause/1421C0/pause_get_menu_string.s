.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_get_menu_string
/* 1421C0 8024EE80 00042080 */  sll       $a0, $a0, 2
/* 1421C4 8024EE84 3C028027 */  lui       $v0, %hi(gPauseMenuStrings)
/* 1421C8 8024EE88 00441021 */  addu      $v0, $v0, $a0
/* 1421CC 8024EE8C 03E00008 */  jr        $ra
/* 1421D0 8024EE90 8C42F778 */   lw       $v0, %lo(gPauseMenuStrings)($v0)
