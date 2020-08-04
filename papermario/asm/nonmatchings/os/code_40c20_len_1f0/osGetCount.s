.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osGetCount
/* 040E00 80065A00 40024800 */  mfc0  $v0, $9
/* 040E04 80065A04 03E00008 */  jr    $ra
/* 040E08 80065A08 00000000 */   nop   

/* 040E0C 80065A0C 00000000 */  nop   

.set reorder
