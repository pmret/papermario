.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC514_E30E64
/* E30E64 802BC514 8C830040 */  lw        $v1, 0x40($a0)
/* E30E68 802BC518 90620001 */  lbu       $v0, 1($v1)
/* E30E6C 802BC51C C4620008 */  lwc1      $f2, 8($v1)
/* E30E70 802BC520 30420001 */  andi      $v0, $v0, 1
/* E30E74 802BC524 3C01BF80 */  lui       $at, 0xbf80
/* E30E78 802BC528 44810000 */  mtc1      $at, $f0
/* E30E7C 802BC52C 10400004 */  beqz      $v0, .L802BC540
/* E30E80 802BC530 24840048 */   addiu    $a0, $a0, 0x48
/* E30E84 802BC534 3C013F80 */  lui       $at, 0x3f80
/* E30E88 802BC538 44810000 */  mtc1      $at, $f0
/* E30E8C 802BC53C 00000000 */  nop
.L802BC540:
/* E30E90 802BC540 46001000 */  add.s     $f0, $f2, $f0
/* E30E94 802BC544 E4800000 */  swc1      $f0, ($a0)
/* E30E98 802BC548 90620001 */  lbu       $v0, 1($v1)
/* E30E9C 802BC54C 2442FFFF */  addiu     $v0, $v0, -1
/* E30EA0 802BC550 03E00008 */  jr        $ra
/* E30EA4 802BC554 A0620001 */   sb       $v0, 1($v1)
