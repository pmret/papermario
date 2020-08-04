.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel enqueueRunning
.L8006AF34:
/* 046334 8006AF34 3C098009 */  lui   $t1, 0x8009
/* 046338 8006AF38 25294658 */  addiu $t1, $t1, 0x4658
/* 04633C 8006AF3C 8D2A0000 */  lw    $t2, ($t1)
/* 046340 8006AF40 AF4A0000 */  sw    $t2, ($k0)
/* 046344 8006AF44 0801AC75 */  j     osDispatchThread
/* 046348 8006AF48 AD3A0000 */   sw    $k0, ($t1)

