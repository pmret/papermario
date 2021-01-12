.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EDC_D9E3AC
/* D9E3AC 80240EDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D9E3B0 80240EE0 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E3B4 80240EE4 0080802D */  daddu     $s0, $a0, $zero
/* D9E3B8 80240EE8 AFBF001C */  sw        $ra, 0x1c($sp)
/* D9E3BC 80240EEC AFB20018 */  sw        $s2, 0x18($sp)
/* D9E3C0 80240EF0 AFB10014 */  sw        $s1, 0x14($sp)
/* D9E3C4 80240EF4 8E110148 */  lw        $s1, 0x148($s0)
/* D9E3C8 80240EF8 86240008 */  lh        $a0, 8($s1)
/* D9E3CC 80240EFC 0C00EABB */  jal       get_npc_unsafe
/* D9E3D0 80240F00 00A0902D */   daddu    $s2, $a1, $zero
/* D9E3D4 80240F04 8E2300CC */  lw        $v1, 0xcc($s1)
/* D9E3D8 80240F08 0040202D */  daddu     $a0, $v0, $zero
/* D9E3DC 80240F0C 8C630000 */  lw        $v1, ($v1)
/* D9E3E0 80240F10 24020001 */  addiu     $v0, $zero, 1
/* D9E3E4 80240F14 AC830028 */  sw        $v1, 0x28($a0)
/* D9E3E8 80240F18 AE020070 */  sw        $v0, 0x70($s0)
/* D9E3EC 80240F1C 8E220000 */  lw        $v0, ($s1)
/* D9E3F0 80240F20 3C030010 */  lui       $v1, 0x10
/* D9E3F4 80240F24 00431024 */  and       $v0, $v0, $v1
/* D9E3F8 80240F28 10400004 */  beqz      $v0, .L80240F3C
/* D9E3FC 80240F2C 00000000 */   nop
/* D9E400 80240F30 C620006C */  lwc1      $f0, 0x6c($s1)
/* D9E404 80240F34 46800020 */  cvt.s.w   $f0, $f0
/* D9E408 80240F38 E480000C */  swc1      $f0, 0xc($a0)
.L80240F3C:
/* D9E40C 80240F3C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9E410 80240F40 8C420014 */  lw        $v0, 0x14($v0)
/* D9E414 80240F44 1C400004 */  bgtz      $v0, .L80240F58
/* D9E418 80240F48 00000000 */   nop
/* D9E41C 80240F4C C640000C */  lwc1      $f0, 0xc($s2)
/* D9E420 80240F50 080903DE */  j         .L80240F78
/* D9E424 80240F54 E4800018 */   swc1     $f0, 0x18($a0)
.L80240F58:
/* D9E428 80240F58 3C018024 */  lui       $at, %hi(D_80247A10)
/* D9E42C 80240F5C D4227A10 */  ldc1      $f2, %lo(D_80247A10)($at)
/* D9E430 80240F60 44820000 */  mtc1      $v0, $f0
/* D9E434 80240F64 00000000 */  nop
/* D9E438 80240F68 46800021 */  cvt.d.w   $f0, $f0
/* D9E43C 80240F6C 46220003 */  div.d     $f0, $f0, $f2
/* D9E440 80240F70 46200020 */  cvt.s.d   $f0, $f0
/* D9E444 80240F74 E4800018 */  swc1      $f0, 0x18($a0)
.L80240F78:
/* D9E448 80240F78 8FBF001C */  lw        $ra, 0x1c($sp)
/* D9E44C 80240F7C 8FB20018 */  lw        $s2, 0x18($sp)
/* D9E450 80240F80 8FB10014 */  lw        $s1, 0x14($sp)
/* D9E454 80240F84 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E458 80240F88 03E00008 */  jr        $ra
/* D9E45C 80240F8C 27BD0020 */   addiu    $sp, $sp, 0x20
