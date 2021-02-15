.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240280_DE2710
/* DE2710 80240280 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE2714 80240284 AFB10014 */  sw        $s1, 0x14($sp)
/* DE2718 80240288 0080882D */  daddu     $s1, $a0, $zero
/* DE271C 8024028C AFBF0018 */  sw        $ra, 0x18($sp)
/* DE2720 80240290 AFB00010 */  sw        $s0, 0x10($sp)
/* DE2724 80240294 8E300148 */  lw        $s0, 0x148($s1)
/* DE2728 80240298 0C00EABB */  jal       get_npc_unsafe
/* DE272C 8024029C 86040008 */   lh       $a0, 8($s0)
/* DE2730 802402A0 C4400018 */  lwc1      $f0, 0x18($v0)
/* DE2734 802402A4 3C018024 */  lui       $at, %hi(D_80242EE0_DE5370)
/* DE2738 802402A8 D4222EE0 */  ldc1      $f2, %lo(D_80242EE0_DE5370)($at)
/* DE273C 802402AC 46000021 */  cvt.d.s   $f0, $f0
/* DE2740 802402B0 46220002 */  mul.d     $f0, $f0, $f2
/* DE2744 802402B4 00000000 */  nop
/* DE2748 802402B8 46200020 */  cvt.s.d   $f0, $f0
/* DE274C 802402BC E4400018 */  swc1      $f0, 0x18($v0)
/* DE2750 802402C0 8E0300CC */  lw        $v1, 0xcc($s0)
/* DE2754 802402C4 8C640030 */  lw        $a0, 0x30($v1)
/* DE2758 802402C8 24030005 */  addiu     $v1, $zero, 5
/* DE275C 802402CC A443008E */  sh        $v1, 0x8e($v0)
/* DE2760 802402D0 AC440028 */  sw        $a0, 0x28($v0)
/* DE2764 802402D4 2402000F */  addiu     $v0, $zero, 0xf
/* DE2768 802402D8 AE220070 */  sw        $v0, 0x70($s1)
/* DE276C 802402DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE2770 802402E0 8FB10014 */  lw        $s1, 0x14($sp)
/* DE2774 802402E4 8FB00010 */  lw        $s0, 0x10($sp)
/* DE2778 802402E8 03E00008 */  jr        $ra
/* DE277C 802402EC 27BD0020 */   addiu    $sp, $sp, 0x20
