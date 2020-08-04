.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSetSR
/* 047AA0 8006C6A0 40846000 */  mtc0  $a0, $12
/* 047AA4 8006C6A4 00000000 */  nop   
/* 047AA8 8006C6A8 03E00008 */  jr    $ra
/* 047AAC 8006C6AC 00000000 */   nop   

