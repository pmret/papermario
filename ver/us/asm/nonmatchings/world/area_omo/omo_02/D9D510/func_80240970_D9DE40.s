.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80247870_DA4D40
.double 0.6

.section .text

glabel func_80240970_D9DE40
/* D9DE40 80240970 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D9DE44 80240974 AFB10014 */  sw        $s1, 0x14($sp)
/* D9DE48 80240978 0080882D */  daddu     $s1, $a0, $zero
/* D9DE4C 8024097C AFBF0018 */  sw        $ra, 0x18($sp)
/* D9DE50 80240980 AFB00010 */  sw        $s0, 0x10($sp)
/* D9DE54 80240984 8E300148 */  lw        $s0, 0x148($s1)
/* D9DE58 80240988 0C00EABB */  jal       get_npc_unsafe
/* D9DE5C 8024098C 86040008 */   lh       $a0, 8($s0)
/* D9DE60 80240990 C4400018 */  lwc1      $f0, 0x18($v0)
/* D9DE64 80240994 3C018024 */  lui       $at, %hi(D_80247870_DA4D40)
/* D9DE68 80240998 D4227870 */  ldc1      $f2, %lo(D_80247870_DA4D40)($at)
/* D9DE6C 8024099C 46000021 */  cvt.d.s   $f0, $f0
/* D9DE70 802409A0 46220002 */  mul.d     $f0, $f0, $f2
/* D9DE74 802409A4 00000000 */  nop
/* D9DE78 802409A8 46200020 */  cvt.s.d   $f0, $f0
/* D9DE7C 802409AC E4400018 */  swc1      $f0, 0x18($v0)
/* D9DE80 802409B0 8E0300CC */  lw        $v1, 0xcc($s0)
/* D9DE84 802409B4 8C640030 */  lw        $a0, 0x30($v1)
/* D9DE88 802409B8 24030005 */  addiu     $v1, $zero, 5
/* D9DE8C 802409BC A443008E */  sh        $v1, 0x8e($v0)
/* D9DE90 802409C0 AC440028 */  sw        $a0, 0x28($v0)
/* D9DE94 802409C4 2402000F */  addiu     $v0, $zero, 0xf
/* D9DE98 802409C8 AE220070 */  sw        $v0, 0x70($s1)
/* D9DE9C 802409CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D9DEA0 802409D0 8FB10014 */  lw        $s1, 0x14($sp)
/* D9DEA4 802409D4 8FB00010 */  lw        $s0, 0x10($sp)
/* D9DEA8 802409D8 03E00008 */  jr        $ra
/* D9DEAC 802409DC 27BD0020 */   addiu    $sp, $sp, 0x20
