.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel read_background_size
/* 0DC528 80145E28 3C038007 */  lui   $v1, 0x8007
/* 0DC52C 80145E2C 8C63419C */  lw    $v1, 0x419c($v1)
/* 0DC530 80145E30 9482000C */  lhu   $v0, 0xc($a0)
/* 0DC534 80145E34 A462014E */  sh    $v0, 0x14e($v1)
/* 0DC538 80145E38 9482000E */  lhu   $v0, 0xe($a0)
/* 0DC53C 80145E3C A4620150 */  sh    $v0, 0x150($v1)
/* 0DC540 80145E40 94820008 */  lhu   $v0, 8($a0)
/* 0DC544 80145E44 A462014A */  sh    $v0, 0x14a($v1)
/* 0DC548 80145E48 9482000A */  lhu   $v0, 0xa($a0)
/* 0DC54C 80145E4C A462014C */  sh    $v0, 0x14c($v1)
/* 0DC550 80145E50 8C820000 */  lw    $v0, ($a0)
/* 0DC554 80145E54 AC620154 */  sw    $v0, 0x154($v1)
/* 0DC558 80145E58 94620148 */  lhu   $v0, 0x148($v1)
/* 0DC55C 80145E5C 8C840004 */  lw    $a0, 4($a0)
/* 0DC560 80145E60 34420001 */  ori   $v0, $v0, 1
/* 0DC564 80145E64 A4620148 */  sh    $v0, 0x148($v1)
/* 0DC568 80145E68 03E00008 */  jr    $ra
/* 0DC56C 80145E6C AC640158 */   sw    $a0, 0x158($v1)

