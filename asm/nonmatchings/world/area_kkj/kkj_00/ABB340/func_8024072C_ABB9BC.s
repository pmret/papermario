.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024072C_ABB9BC
/* ABB9BC 8024072C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ABB9C0 80240730 AFB10014 */  sw        $s1, 0x14($sp)
/* ABB9C4 80240734 0080882D */  daddu     $s1, $a0, $zero
/* ABB9C8 80240738 AFBF001C */  sw        $ra, 0x1c($sp)
/* ABB9CC 8024073C AFB20018 */  sw        $s2, 0x18($sp)
/* ABB9D0 80240740 AFB00010 */  sw        $s0, 0x10($sp)
/* ABB9D4 80240744 8E300148 */  lw        $s0, 0x148($s1)
/* ABB9D8 80240748 86040008 */  lh        $a0, 8($s0)
/* ABB9DC 8024074C 0C00EABB */  jal       get_npc_unsafe
/* ABB9E0 80240750 00A0902D */   daddu    $s2, $a1, $zero
/* ABB9E4 80240754 8E230078 */  lw        $v1, 0x78($s1)
/* ABB9E8 80240758 24630001 */  addiu     $v1, $v1, 1
/* ABB9EC 8024075C AE230078 */  sw        $v1, 0x78($s1)
/* ABB9F0 80240760 8E0400D0 */  lw        $a0, 0xd0($s0)
/* ABB9F4 80240764 8C840000 */  lw        $a0, ($a0)
/* ABB9F8 80240768 0064182A */  slt       $v1, $v1, $a0
/* ABB9FC 8024076C 14600002 */  bnez      $v1, .L80240778
/* ABBA00 80240770 0040282D */   daddu    $a1, $v0, $zero
/* ABBA04 80240774 AE200078 */  sw        $zero, 0x78($s1)
.L80240778:
/* ABBA08 80240778 8E0200CC */  lw        $v0, 0xcc($s0)
/* ABBA0C 8024077C 8C420004 */  lw        $v0, 4($v0)
/* ABBA10 80240780 ACA20028 */  sw        $v0, 0x28($a1)
/* ABBA14 80240784 8E0200D0 */  lw        $v0, 0xd0($s0)
/* ABBA18 80240788 8C42007C */  lw        $v0, 0x7c($v0)
/* ABBA1C 8024078C 04410004 */  bgez      $v0, .L802407A0
/* ABBA20 80240790 00000000 */   nop      
/* ABBA24 80240794 C6400000 */  lwc1      $f0, ($s2)
/* ABBA28 80240798 080901F0 */  j         .L802407C0
/* ABBA2C 8024079C E4A00018 */   swc1     $f0, 0x18($a1)
.L802407A0:
/* ABBA30 802407A0 3C018025 */  lui       $at, %hi(D_80249D38)
/* ABBA34 802407A4 D4229D38 */  ldc1      $f2, %lo(D_80249D38)($at)
/* ABBA38 802407A8 44820000 */  mtc1      $v0, $f0
/* ABBA3C 802407AC 00000000 */  nop       
/* ABBA40 802407B0 46800021 */  cvt.d.w   $f0, $f0
/* ABBA44 802407B4 46220003 */  div.d     $f0, $f0, $f2
/* ABBA48 802407B8 46200020 */  cvt.s.d   $f0, $f0
/* ABBA4C 802407BC E4A00018 */  swc1      $f0, 0x18($a1)
.L802407C0:
/* ABBA50 802407C0 24020001 */  addiu     $v0, $zero, 1
/* ABBA54 802407C4 AE220070 */  sw        $v0, 0x70($s1)
/* ABBA58 802407C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* ABBA5C 802407CC 8FB20018 */  lw        $s2, 0x18($sp)
/* ABBA60 802407D0 8FB10014 */  lw        $s1, 0x14($sp)
/* ABBA64 802407D4 8FB00010 */  lw        $s0, 0x10($sp)
/* ABBA68 802407D8 03E00008 */  jr        $ra
/* ABBA6C 802407DC 27BD0020 */   addiu    $sp, $sp, 0x20
