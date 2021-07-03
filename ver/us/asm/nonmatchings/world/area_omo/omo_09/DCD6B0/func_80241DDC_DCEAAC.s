.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8024A970_DD7640
.double 0.6

.section .text

glabel func_80241DDC_DCEAAC
/* DCEAAC 80241DDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCEAB0 80241DE0 AFB10014 */  sw        $s1, 0x14($sp)
/* DCEAB4 80241DE4 0080882D */  daddu     $s1, $a0, $zero
/* DCEAB8 80241DE8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCEABC 80241DEC AFB00010 */  sw        $s0, 0x10($sp)
/* DCEAC0 80241DF0 8E300148 */  lw        $s0, 0x148($s1)
/* DCEAC4 80241DF4 0C00EABB */  jal       get_npc_unsafe
/* DCEAC8 80241DF8 86040008 */   lh       $a0, 8($s0)
/* DCEACC 80241DFC C4400018 */  lwc1      $f0, 0x18($v0)
/* DCEAD0 80241E00 3C018025 */  lui       $at, %hi(D_8024A970_DD7640)
/* DCEAD4 80241E04 D422A970 */  ldc1      $f2, %lo(D_8024A970_DD7640)($at)
/* DCEAD8 80241E08 46000021 */  cvt.d.s   $f0, $f0
/* DCEADC 80241E0C 46220002 */  mul.d     $f0, $f0, $f2
/* DCEAE0 80241E10 00000000 */  nop
/* DCEAE4 80241E14 46200020 */  cvt.s.d   $f0, $f0
/* DCEAE8 80241E18 E4400018 */  swc1      $f0, 0x18($v0)
/* DCEAEC 80241E1C 8E0300CC */  lw        $v1, 0xcc($s0)
/* DCEAF0 80241E20 8C640030 */  lw        $a0, 0x30($v1)
/* DCEAF4 80241E24 24030005 */  addiu     $v1, $zero, 5
/* DCEAF8 80241E28 A443008E */  sh        $v1, 0x8e($v0)
/* DCEAFC 80241E2C AC440028 */  sw        $a0, 0x28($v0)
/* DCEB00 80241E30 2402000F */  addiu     $v0, $zero, 0xf
/* DCEB04 80241E34 AE220070 */  sw        $v0, 0x70($s1)
/* DCEB08 80241E38 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCEB0C 80241E3C 8FB10014 */  lw        $s1, 0x14($sp)
/* DCEB10 80241E40 8FB00010 */  lw        $s0, 0x10($sp)
/* DCEB14 80241E44 03E00008 */  jr        $ra
/* DCEB18 80241E48 27BD0020 */   addiu    $sp, $sp, 0x20
