.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuScSetFrameBufferNum
/* 03A390 8005EF90 3C01800E */  lui   $at, 0x800e
/* 03A394 8005EF94 03E00008 */  jr    $ra
/* 03A398 8005EF98 A024AABD */   sb    $a0, -0x5543($at)

