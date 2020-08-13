.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osCleanupThread
/* 046750 8006B350 00002021 */  addu  $a0, $zero, $zero
/* 046754 8006B354 0C01B254 */  jal   osDestroyThread
/* 046758 8006B358 00000000 */   nop   
/* 04675C 8006B35C 00000000 */  nop   


