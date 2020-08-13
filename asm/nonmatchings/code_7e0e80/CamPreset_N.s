.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_N
/* 7E1C10 80280D90 24020001 */  addiu $v0, $zero, 1
/* 7E1C14 80280D94 148201A0 */  bne   $a0, $v0, .L80281418
/* 7E1C18 80280D98 0000102D */   daddu $v0, $zero, $zero
/* 7E1C1C 80280D9C 3C028028 */  lui   $v0, 0x8028
/* 7E1C20 80280DA0 8C426538 */  lw    $v0, 0x6538($v0)
/* 7E1C24 80280DA4 904304E8 */  lbu   $v1, 0x4e8($v0)
/* 7E1C28 80280DA8 10640012 */  beq   $v1, $a0, .L80280DF4
