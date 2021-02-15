.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408B0_93FE60
/* 93FE60 802408B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 93FE64 802408B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 93FE68 802408B8 0080882D */  daddu     $s1, $a0, $zero
/* 93FE6C 802408BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 93FE70 802408C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 93FE74 802408C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 93FE78 802408C8 8E300148 */  lw        $s0, 0x148($s1)
/* 93FE7C 802408CC 86040008 */  lh        $a0, 8($s0)
/* 93FE80 802408D0 0C00EABB */  jal       get_npc_unsafe
/* 93FE84 802408D4 00A0902D */   daddu    $s2, $a1, $zero
/* 93FE88 802408D8 8E0300CC */  lw        $v1, 0xcc($s0)
/* 93FE8C 802408DC 8C630004 */  lw        $v1, 4($v1)
/* 93FE90 802408E0 0040202D */  daddu     $a0, $v0, $zero
/* 93FE94 802408E4 AC830028 */  sw        $v1, 0x28($a0)
/* 93FE98 802408E8 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 93FE9C 802408EC 8C420014 */  lw        $v0, 0x14($v0)
/* 93FEA0 802408F0 04410009 */  bgez      $v0, .L80240918
/* 93FEA4 802408F4 00000000 */   nop
/* 93FEA8 802408F8 C640000C */  lwc1      $f0, 0xc($s2)
/* 93FEAC 802408FC 3C018024 */  lui       $at, %hi(D_802448A8_943E58)
/* 93FEB0 80240900 D42248A8 */  ldc1      $f2, %lo(D_802448A8_943E58)($at)
/* 93FEB4 80240904 46000021 */  cvt.d.s   $f0, $f0
/* 93FEB8 80240908 46220002 */  mul.d     $f0, $f0, $f2
/* 93FEBC 8024090C 00000000 */  nop
/* 93FEC0 80240910 0809024D */  j         .L80240934
/* 93FEC4 80240914 46200020 */   cvt.s.d  $f0, $f0
.L80240918:
/* 93FEC8 80240918 3C018024 */  lui       $at, %hi(D_802448B0_943E60)
/* 93FECC 8024091C D42248B0 */  ldc1      $f2, %lo(D_802448B0_943E60)($at)
/* 93FED0 80240920 44820000 */  mtc1      $v0, $f0
/* 93FED4 80240924 00000000 */  nop
/* 93FED8 80240928 46800021 */  cvt.d.w   $f0, $f0
/* 93FEDC 8024092C 46220003 */  div.d     $f0, $f0, $f2
/* 93FEE0 80240930 46200020 */  cvt.s.d   $f0, $f0
.L80240934:
/* 93FEE4 80240934 E4800018 */  swc1      $f0, 0x18($a0)
/* 93FEE8 80240938 24020010 */  addiu     $v0, $zero, 0x10
/* 93FEEC 8024093C AE200074 */  sw        $zero, 0x74($s1)
/* 93FEF0 80240940 AE220070 */  sw        $v0, 0x70($s1)
/* 93FEF4 80240944 8FBF001C */  lw        $ra, 0x1c($sp)
/* 93FEF8 80240948 8FB20018 */  lw        $s2, 0x18($sp)
/* 93FEFC 8024094C 8FB10014 */  lw        $s1, 0x14($sp)
/* 93FF00 80240950 8FB00010 */  lw        $s0, 0x10($sp)
/* 93FF04 80240954 03E00008 */  jr        $ra
/* 93FF08 80240958 27BD0020 */   addiu    $sp, $sp, 0x20
