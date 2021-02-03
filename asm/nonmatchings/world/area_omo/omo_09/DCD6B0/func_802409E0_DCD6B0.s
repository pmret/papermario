.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409E0_DCD6B0
/* DCD6B0 802409E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCD6B4 802409E4 AFB10014 */  sw        $s1, 0x14($sp)
/* DCD6B8 802409E8 0080882D */  daddu     $s1, $a0, $zero
/* DCD6BC 802409EC AFBF0018 */  sw        $ra, 0x18($sp)
/* DCD6C0 802409F0 AFB00010 */  sw        $s0, 0x10($sp)
/* DCD6C4 802409F4 8E300148 */  lw        $s0, 0x148($s1)
/* DCD6C8 802409F8 0C00EABB */  jal       get_npc_unsafe
/* DCD6CC 802409FC 86040008 */   lh       $a0, 8($s0)
/* DCD6D0 80240A00 C4400018 */  lwc1      $f0, 0x18($v0)
/* DCD6D4 80240A04 3C018025 */  lui       $at, %hi(D_8024A630_DD7300)
/* DCD6D8 80240A08 D422A630 */  ldc1      $f2, %lo(D_8024A630_DD7300)($at)
/* DCD6DC 80240A0C 46000021 */  cvt.d.s   $f0, $f0
/* DCD6E0 80240A10 46220002 */  mul.d     $f0, $f0, $f2
/* DCD6E4 80240A14 00000000 */  nop
/* DCD6E8 80240A18 46200020 */  cvt.s.d   $f0, $f0
/* DCD6EC 80240A1C E4400018 */  swc1      $f0, 0x18($v0)
/* DCD6F0 80240A20 8E0300CC */  lw        $v1, 0xcc($s0)
/* DCD6F4 80240A24 8C640030 */  lw        $a0, 0x30($v1)
/* DCD6F8 80240A28 24030005 */  addiu     $v1, $zero, 5
/* DCD6FC 80240A2C A443008E */  sh        $v1, 0x8e($v0)
/* DCD700 80240A30 AC440028 */  sw        $a0, 0x28($v0)
/* DCD704 80240A34 2402000F */  addiu     $v0, $zero, 0xf
/* DCD708 80240A38 AE220070 */  sw        $v0, 0x70($s1)
/* DCD70C 80240A3C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCD710 80240A40 8FB10014 */  lw        $s1, 0x14($sp)
/* DCD714 80240A44 8FB00010 */  lw        $s0, 0x10($sp)
/* DCD718 80240A48 03E00008 */  jr        $ra
/* DCD71C 80240A4C 27BD0020 */   addiu    $sp, $sp, 0x20
