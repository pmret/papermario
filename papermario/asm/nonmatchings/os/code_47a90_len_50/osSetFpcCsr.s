.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSetFpcCsr
/* 047A90 8006C690 4442F800 */  cfc1  $v0, $31
/* 047A94 8006C694 44C4F800 */  ctc1  $a0, $31
/* 047A98 8006C698 03E00008 */  jr    $ra
/* 047A9C 8006C69C 00000000 */   nop   

