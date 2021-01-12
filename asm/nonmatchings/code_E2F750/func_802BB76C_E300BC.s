.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB76C_E300BC
/* E300BC 802BB76C 8C830040 */  lw        $v1, 0x40($a0)
/* E300C0 802BB770 846200A4 */  lh        $v0, 0xa4($v1)
/* E300C4 802BB774 C4800048 */  lwc1      $f0, 0x48($a0)
/* E300C8 802BB778 44821000 */  mtc1      $v0, $f2
/* E300CC 802BB77C 00000000 */  nop
/* E300D0 802BB780 468010A0 */  cvt.s.w   $f2, $f2
/* E300D4 802BB784 846200A8 */  lh        $v0, 0xa8($v1)
/* E300D8 802BB788 46001081 */  sub.s     $f2, $f2, $f0
/* E300DC 802BB78C C4840050 */  lwc1      $f4, 0x50($a0)
/* E300E0 802BB790 44820000 */  mtc1      $v0, $f0
/* E300E4 802BB794 00000000 */  nop
/* E300E8 802BB798 46800020 */  cvt.s.w   $f0, $f0
/* E300EC 802BB79C 46040001 */  sub.s     $f0, $f0, $f4
/* E300F0 802BB7A0 0000102D */  daddu     $v0, $zero, $zero
/* E300F4 802BB7A4 3C014120 */  lui       $at, 0x4120
/* E300F8 802BB7A8 44812000 */  mtc1      $at, $f4
/* E300FC 802BB7AC 46001085 */  abs.s     $f2, $f2
/* E30100 802BB7B0 4604103E */  c.le.s    $f2, $f4
/* E30104 802BB7B4 00000000 */  nop
/* E30108 802BB7B8 45000002 */  bc1f      .L802BB7C4
/* E3010C 802BB7BC 46000005 */   abs.s    $f0, $f0
/* E30110 802BB7C0 24020001 */  addiu     $v0, $zero, 1
.L802BB7C4:
/* E30114 802BB7C4 4604003E */  c.le.s    $f0, $f4
/* E30118 802BB7C8 00000000 */  nop
/* E3011C 802BB7CC 45030001 */  bc1tl     .L802BB7D4
/* E30120 802BB7D0 24420001 */   addiu    $v0, $v0, 1
.L802BB7D4:
/* E30124 802BB7D4 28420002 */  slti      $v0, $v0, 2
/* E30128 802BB7D8 03E00008 */  jr        $ra
/* E3012C 802BB7DC 38420001 */   xori     $v0, $v0, 1
