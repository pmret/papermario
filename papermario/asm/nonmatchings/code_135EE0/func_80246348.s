.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246348
/* 139688 80246348 3C058025 */  lui   $a1, 0x8025
/* 13968C 8024634C 00B02821 */  addu  $a1, $a1, $s0
/* 139690 80246350 8CA5F434 */  lw    $a1, -0xbcc($a1)
/* 139694 80246354 0C0511FF */  jal   set_menu_icon_script
