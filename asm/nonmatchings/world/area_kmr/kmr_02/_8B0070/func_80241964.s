.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241964
/* 8B19D4 80241964 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B19D8 80241968 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B19DC 8024196C 0080882D */  daddu     $s1, $a0, $zero
/* 8B19E0 80241970 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B19E4 80241974 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B19E8 80241978 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B19EC 8024197C 8E300148 */  lw        $s0, 0x148($s1)
/* 8B19F0 80241980 86040008 */  lh        $a0, 8($s0)
/* 8B19F4 80241984 0C00EABB */  jal       get_npc_unsafe
/* 8B19F8 80241988 00A0902D */   daddu    $s2, $a1, $zero
/* 8B19FC 8024198C 8E0300CC */  lw        $v1, 0xcc($s0)
/* 8B1A00 80241990 8C630004 */  lw        $v1, 4($v1)
/* 8B1A04 80241994 0040202D */  daddu     $a0, $v0, $zero
/* 8B1A08 80241998 AC830028 */  sw        $v1, 0x28($a0)
/* 8B1A0C 8024199C 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 8B1A10 802419A0 8C420014 */  lw        $v0, 0x14($v0)
/* 8B1A14 802419A4 04410009 */  bgez      $v0, .L802419CC
/* 8B1A18 802419A8 00000000 */   nop      
/* 8B1A1C 802419AC C640000C */  lwc1      $f0, 0xc($s2)
/* 8B1A20 802419B0 3C018025 */  lui       $at, 0x8025
/* 8B1A24 802419B4 D4227D48 */  ldc1      $f2, 0x7d48($at)
/* 8B1A28 802419B8 46000021 */  cvt.d.s   $f0, $f0
/* 8B1A2C 802419BC 46220002 */  mul.d     $f0, $f0, $f2
/* 8B1A30 802419C0 00000000 */  nop       
/* 8B1A34 802419C4 0809067A */  j         .L802419E8
/* 8B1A38 802419C8 46200020 */   cvt.s.d  $f0, $f0
.L802419CC:
/* 8B1A3C 802419CC 3C018025 */  lui       $at, 0x8025
/* 8B1A40 802419D0 D4227D50 */  ldc1      $f2, 0x7d50($at)
/* 8B1A44 802419D4 44820000 */  mtc1      $v0, $f0
/* 8B1A48 802419D8 00000000 */  nop       
/* 8B1A4C 802419DC 46800021 */  cvt.d.w   $f0, $f0
/* 8B1A50 802419E0 46220003 */  div.d     $f0, $f0, $f2
/* 8B1A54 802419E4 46200020 */  cvt.s.d   $f0, $f0
.L802419E8:
/* 8B1A58 802419E8 E4800018 */  swc1      $f0, 0x18($a0)
/* 8B1A5C 802419EC 24020010 */  addiu     $v0, $zero, 0x10
/* 8B1A60 802419F0 AE200074 */  sw        $zero, 0x74($s1)
/* 8B1A64 802419F4 AE220070 */  sw        $v0, 0x70($s1)
/* 8B1A68 802419F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B1A6C 802419FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B1A70 80241A00 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B1A74 80241A04 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B1A78 80241A08 03E00008 */  jr        $ra
/* 8B1A7C 80241A0C 27BD0020 */   addiu    $sp, $sp, 0x20
