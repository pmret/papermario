.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A4_C7E724
/* C7E724 802405A4 3C018024 */  lui       $at, %hi(D_80242010)
/* C7E728 802405A8 D4222010 */  ldc1      $f2, %lo(D_80242010)($at)
/* C7E72C 802405AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7E730 802405B0 AFB00010 */  sw        $s0, 0x10($sp)
/* C7E734 802405B4 0080802D */  daddu     $s0, $a0, $zero
/* C7E738 802405B8 AFBF0014 */  sw        $ra, 0x14($sp)
/* C7E73C 802405BC C6000084 */  lwc1      $f0, 0x84($s0)
/* C7E740 802405C0 46800021 */  cvt.d.w   $f0, $f0
/* C7E744 802405C4 46201081 */  sub.d     $f2, $f2, $f0
/* C7E748 802405C8 462010A0 */  cvt.s.d   $f2, $f2
/* C7E74C 802405CC 46021082 */  mul.s     $f2, $f2, $f2
/* C7E750 802405D0 00000000 */  nop
/* C7E754 802405D4 3C014047 */  lui       $at, 0x4047
/* C7E758 802405D8 44810800 */  mtc1      $at, $f1
/* C7E75C 802405DC 44800000 */  mtc1      $zero, $f0
/* C7E760 802405E0 C604008C */  lwc1      $f4, 0x8c($s0)
/* C7E764 802405E4 46802121 */  cvt.d.w   $f4, $f4
/* C7E768 802405E8 46240001 */  sub.d     $f0, $f0, $f4
/* C7E76C 802405EC 46200020 */  cvt.s.d   $f0, $f0
/* C7E770 802405F0 46000002 */  mul.s     $f0, $f0, $f0
/* C7E774 802405F4 00000000 */  nop
/* C7E778 802405F8 46001300 */  add.s     $f12, $f2, $f0
/* C7E77C 802405FC 46006004 */  sqrt.s    $f0, $f12
/* C7E780 80240600 46000032 */  c.eq.s    $f0, $f0
/* C7E784 80240604 00000000 */  nop
/* C7E788 80240608 45030004 */  bc1tl     .L8024061C
/* C7E78C 8024060C 46000007 */   neg.s    $f0, $f0
/* C7E790 80240610 0C0187BC */  jal       sqrtf
/* C7E794 80240614 00000000 */   nop
/* C7E798 80240618 46000007 */  neg.s     $f0, $f0
.L8024061C:
/* C7E79C 8024061C 4600018D */  trunc.w.s $f6, $f0
/* C7E7A0 80240620 E6060090 */  swc1      $f6, 0x90($s0)
/* C7E7A4 80240624 8FBF0014 */  lw        $ra, 0x14($sp)
/* C7E7A8 80240628 8FB00010 */  lw        $s0, 0x10($sp)
/* C7E7AC 8024062C 24020002 */  addiu     $v0, $zero, 2
/* C7E7B0 80240630 03E00008 */  jr        $ra
/* C7E7B4 80240634 27BD0018 */   addiu    $sp, $sp, 0x18
