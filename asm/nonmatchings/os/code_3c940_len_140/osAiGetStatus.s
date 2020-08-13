.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osAiGetStatus
/* 03C950 80061550 3C02A450 */  lui   $v0, 0xa450
/* 03C954 80061554 3442000C */  ori   $v0, $v0, 0xc
/* 03C958 80061558 03E00008 */  jr    $ra
/* 03C95C 8006155C 8C420000 */   lw    $v0, ($v0)

