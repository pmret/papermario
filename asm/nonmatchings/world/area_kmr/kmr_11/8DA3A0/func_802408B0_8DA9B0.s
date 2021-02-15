.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408B0_8DA9B0
/* 8DA9B0 802408B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8DA9B4 802408B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8DA9B8 802408B8 0080882D */  daddu     $s1, $a0, $zero
/* 8DA9BC 802408BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 8DA9C0 802408C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 8DA9C4 802408C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DA9C8 802408C8 8E300148 */  lw        $s0, 0x148($s1)
/* 8DA9CC 802408CC 86040008 */  lh        $a0, 8($s0)
/* 8DA9D0 802408D0 0C00EABB */  jal       get_npc_unsafe
/* 8DA9D4 802408D4 00A0902D */   daddu    $s2, $a1, $zero
/* 8DA9D8 802408D8 8E0300CC */  lw        $v1, 0xcc($s0)
/* 8DA9DC 802408DC 8C630004 */  lw        $v1, 4($v1)
/* 8DA9E0 802408E0 0040202D */  daddu     $a0, $v0, $zero
/* 8DA9E4 802408E4 AC830028 */  sw        $v1, 0x28($a0)
/* 8DA9E8 802408E8 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 8DA9EC 802408EC 8C420014 */  lw        $v0, 0x14($v0)
/* 8DA9F0 802408F0 04410009 */  bgez      $v0, .L80240918
/* 8DA9F4 802408F4 00000000 */   nop
/* 8DA9F8 802408F8 C640000C */  lwc1      $f0, 0xc($s2)
/* 8DA9FC 802408FC 3C018025 */  lui       $at, %hi(D_802510B8_8EB1B8)
/* 8DAA00 80240900 D42210B8 */  ldc1      $f2, %lo(D_802510B8_8EB1B8)($at)
/* 8DAA04 80240904 46000021 */  cvt.d.s   $f0, $f0
/* 8DAA08 80240908 46220002 */  mul.d     $f0, $f0, $f2
/* 8DAA0C 8024090C 00000000 */  nop
/* 8DAA10 80240910 0809024D */  j         .L80240934
/* 8DAA14 80240914 46200020 */   cvt.s.d  $f0, $f0
.L80240918:
/* 8DAA18 80240918 3C018025 */  lui       $at, %hi(D_802510C0_8EB1C0)
/* 8DAA1C 8024091C D42210C0 */  ldc1      $f2, %lo(D_802510C0_8EB1C0)($at)
/* 8DAA20 80240920 44820000 */  mtc1      $v0, $f0
/* 8DAA24 80240924 00000000 */  nop
/* 8DAA28 80240928 46800021 */  cvt.d.w   $f0, $f0
/* 8DAA2C 8024092C 46220003 */  div.d     $f0, $f0, $f2
/* 8DAA30 80240930 46200020 */  cvt.s.d   $f0, $f0
.L80240934:
/* 8DAA34 80240934 E4800018 */  swc1      $f0, 0x18($a0)
/* 8DAA38 80240938 24020010 */  addiu     $v0, $zero, 0x10
/* 8DAA3C 8024093C AE200074 */  sw        $zero, 0x74($s1)
/* 8DAA40 80240940 AE220070 */  sw        $v0, 0x70($s1)
/* 8DAA44 80240944 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8DAA48 80240948 8FB20018 */  lw        $s2, 0x18($sp)
/* 8DAA4C 8024094C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8DAA50 80240950 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DAA54 80240954 03E00008 */  jr        $ra
/* 8DAA58 80240958 27BD0020 */   addiu    $sp, $sp, 0x20
