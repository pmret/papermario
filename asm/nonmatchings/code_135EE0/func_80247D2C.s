.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247D2C
/* 13B06C 80247D2C 0C0511FF */  jal   set_menu_icon_script
/* 13B070 80247D30 0220202D */   daddu $a0, $s1, $zero
/* 13B074 80247D34 3C053F2B */  lui   $a1, 0x3f2b
/* 13B078 80247D38 34A5BA99 */  ori   $a1, $a1, 0xba99
/* 13B07C 80247D3C 0C051308 */  jal   func_80144C20
/* 13B080 80247D40 0220202D */   daddu $a0, $s1, $zero
