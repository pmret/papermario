.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel alUnlink
/* 02680C 8004B40C 8C830000 */  lw    $v1, ($a0)
/* 026810 8004B410 10600003 */  beqz  $v1, .L8004B420
/* 026814 8004B414 00000000 */   nop   
/* 026818 8004B418 8C820004 */  lw    $v0, 4($a0)
/* 02681C 8004B41C AC620004 */  sw    $v0, 4($v1)
.L8004B420:
/* 026820 8004B420 8C830004 */  lw    $v1, 4($a0)
/* 026824 8004B424 10600003 */  beqz  $v1, .L8004B434
/* 026828 8004B428 00000000 */   nop   
/* 02682C 8004B42C 8C820000 */  lw    $v0, ($a0)
/* 026830 8004B430 AC620000 */  sw    $v0, ($v1)
.L8004B434:
/* 026834 8004B434 03E00008 */  jr    $ra
/* 026838 8004B438 00000000 */   nop   

/* 02683C 8004B43C 00000000 */  nop   


