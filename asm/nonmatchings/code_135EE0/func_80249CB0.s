.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249CB0
/* 13CFF0 80249CB0 3C028027 */  lui   $v0, 0x8027
/* 13CFF4 80249CB4 8C4205E0 */  lw    $v0, 0x5e0($v0)
/* 13CFF8 80249CB8 240A0001 */  addiu $t2, $zero, 1
/* 13CFFC 80249CBC 144A000D */  bne   $v0, $t2, .L80249CF4
/* 13D000 80249CC0 03C0202D */   daddu $a0, $fp, $zero
/* 13D004 80249CC4 0C092626 */  jal   func_80249898
/* 13D008 80249CC8 0240282D */   daddu $a1, $s2, $zero
/* 13D00C 80249CCC 8FAB0058 */  lw    $t3, 0x58($sp)
/* 13D010 80249CD0 144B0008 */  bne   $v0, $t3, .L80249CF4
