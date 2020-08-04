.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80145E98
/* 0DC598 80145E98 3082FFFF */  andi  $v0, $a0, 0xffff
/* 0DC59C 80145E9C 00A22823 */  subu  $a1, $a1, $v0
/* 0DC5A0 80145EA0 00A60018 */  mult  $a1, $a2
/* 0DC5A4 80145EA4 00001012 */  mflo  $v0
/* 0DC5A8 80145EA8 04420001 */  bltzl $v0, .L80145EB0
/* 0DC5AC 80145EAC 244200FF */   addiu $v0, $v0, 0xff
.L80145EB0:
/* 0DC5B0 80145EB0 00021203 */  sra   $v0, $v0, 8
/* 0DC5B4 80145EB4 00821021 */  addu  $v0, $a0, $v0
/* 0DC5B8 80145EB8 03E00008 */  jr    $ra
/* 0DC5BC 80145EBC 3042FFFF */   andi  $v0, $v0, 0xffff

