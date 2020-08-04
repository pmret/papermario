.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249274
/* 13C5B4 80249274 8E030000 */  lw    $v1, ($s0)
/* 13C5B8 80249278 10400002 */  beqz  $v0, .L80249284
/* 13C5BC 8024927C 38620001 */   xori  $v0, $v1, 1
/* 13C5C0 80249280 AE020000 */  sw    $v0, ($s0)
.L80249284:
/* 13C5C4 80249284 8E020000 */  lw    $v0, ($s0)
/* 13C5C8 80249288 106200A0 */  beq   $v1, $v0, .L8024950C
