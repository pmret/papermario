.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osGetThreadPri
/* 041330 80065F30 14800003 */  bnez  $a0, .L80065F40
/* 041334 80065F34 00000000 */   nop
/* 041338 80065F38 3C048009 */  lui   $a0, 0x8009
/* 04133C 80065F3C 8C844660 */  lw    $a0, 0x4660($a0)
.L80065F40:
/* 041340 80065F40 03E00008 */  jr    $ra
/* 041344 80065F44 8C820004 */   lw    $v0, 4($a0)

/* 041348 80065F48 00000000 */  nop
/* 04134C 80065F4C 00000000 */  nop

.set reorder
