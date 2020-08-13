.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024D314
/* 140654 8024D314 0200202D */  daddu $a0, $s0, $zero
/* 140658 8024D318 0C04991D */  jal   get_string_width
/* 14065C 8024D31C 0000282D */   daddu $a1, $zero, $zero
/* 140660 8024D320 0200202D */  daddu $a0, $s0, $zero
/* 140664 8024D324 02221023 */  subu  $v0, $s1, $v0
/* 140668 8024D328 00021043 */  sra   $v0, $v0, 1
/* 14066C 8024D32C 02422821 */  addu  $a1, $s2, $v0
