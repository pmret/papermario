.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80033540
/* 00E940 80033540 3C03800A */  lui   $v1, 0x800a
/* 00E944 80033544 2463A650 */  addiu $v1, $v1, -0x59b0
/* 00E948 80033548 8C620000 */  lw    $v0, ($v1)
/* 00E94C 8003354C 34420008 */  ori   $v0, $v0, 8
/* 00E950 80033550 AC620000 */  sw    $v0, ($v1)
/* 00E954 80033554 3C038007 */  lui   $v1, 0x8007
/* 00E958 80033558 8C63419C */  lw    $v1, 0x419c($v1)
/* 00E95C 8003355C 24020003 */  addiu $v0, $zero, 3
/* 00E960 80033560 03E00008 */  jr    $ra
/* 00E964 80033564 A06200AC */   sb    $v0, 0xac($v1)

