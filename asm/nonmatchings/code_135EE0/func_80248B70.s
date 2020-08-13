.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248B70
/* 13BEB0 80248B70 0C091CAA */  jal   func_802472A8
/* 13BEB4 80248B74 0040802D */   daddu $s0, $v0, $zero
/* 13BEB8 80248B78 0200202D */  daddu $a0, $s0, $zero
/* 13BEBC 80248B7C 0C091CA6 */  jal   func_80247298
/* 13BEC0 80248B80 0040802D */   daddu $s0, $v0, $zero
/* 13BEC4 80248B84 0040302D */  daddu $a2, $v0, $zero
/* 13BEC8 80248B88 04C10003 */  bgez  $a2, .L80248B98
/* 13BECC 80248B8C 28C20071 */   slti  $v0, $a2, 0x71
/* 13BED0 80248B90 080922E8 */  j     func_80248BA0
/* 13BED4 80248B94 0000302D */   daddu $a2, $zero, $zero

.L80248B98:
/* 13BED8 80248B98 50400001 */  beql  $v0, $zero, .L80248BA0
/* 13BEDC 80248B9C 24060070 */   addiu $a2, $zero, 0x70
