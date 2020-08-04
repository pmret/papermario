.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_background_size
/* 0DC570 80145E70 3C028007 */  lui   $v0, 0x8007
/* 0DC574 80145E74 8C42419C */  lw    $v0, 0x419c($v0)
/* 0DC578 80145E78 94430148 */  lhu   $v1, 0x148($v0)
/* 0DC57C 80145E7C A444014E */  sh    $a0, 0x14e($v0)
/* 0DC580 80145E80 A4450150 */  sh    $a1, 0x150($v0)
/* 0DC584 80145E84 A446014A */  sh    $a2, 0x14a($v0)
/* 0DC588 80145E88 A447014C */  sh    $a3, 0x14c($v0)
/* 0DC58C 80145E8C 3063FFFE */  andi  $v1, $v1, 0xfffe
/* 0DC590 80145E90 03E00008 */  jr    $ra
/* 0DC594 80145E94 A4430148 */   sh    $v1, 0x148($v0)

