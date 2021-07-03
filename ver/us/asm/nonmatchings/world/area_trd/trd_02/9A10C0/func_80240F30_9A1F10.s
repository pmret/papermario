.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243348_9A4328
.double 32767.0

.section .text

glabel func_80240F30_9A1F10
/* 9A1F10 80240F30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A1F14 80240F34 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A1F18 80240F38 0080882D */  daddu     $s1, $a0, $zero
/* 9A1F1C 80240F3C AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A1F20 80240F40 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A1F24 80240F44 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A1F28 80240F48 8E300148 */  lw        $s0, 0x148($s1)
/* 9A1F2C 80240F4C 86040008 */  lh        $a0, 8($s0)
/* 9A1F30 80240F50 0C00EABB */  jal       get_npc_unsafe
/* 9A1F34 80240F54 00A0902D */   daddu    $s2, $a1, $zero
/* 9A1F38 80240F58 8E230078 */  lw        $v1, 0x78($s1)
/* 9A1F3C 80240F5C 24630001 */  addiu     $v1, $v1, 1
/* 9A1F40 80240F60 AE230078 */  sw        $v1, 0x78($s1)
/* 9A1F44 80240F64 8E0400D0 */  lw        $a0, 0xd0($s0)
/* 9A1F48 80240F68 8C840000 */  lw        $a0, ($a0)
/* 9A1F4C 80240F6C 0064182A */  slt       $v1, $v1, $a0
/* 9A1F50 80240F70 14600002 */  bnez      $v1, .L80240F7C
/* 9A1F54 80240F74 0040282D */   daddu    $a1, $v0, $zero
/* 9A1F58 80240F78 AE200078 */  sw        $zero, 0x78($s1)
.L80240F7C:
/* 9A1F5C 80240F7C 8E0200CC */  lw        $v0, 0xcc($s0)
/* 9A1F60 80240F80 8C420004 */  lw        $v0, 4($v0)
/* 9A1F64 80240F84 ACA20028 */  sw        $v0, 0x28($a1)
/* 9A1F68 80240F88 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 9A1F6C 80240F8C 8C42007C */  lw        $v0, 0x7c($v0)
/* 9A1F70 80240F90 04410004 */  bgez      $v0, .L80240FA4
/* 9A1F74 80240F94 00000000 */   nop
/* 9A1F78 80240F98 C6400000 */  lwc1      $f0, ($s2)
/* 9A1F7C 80240F9C 080903F1 */  j         .L80240FC4
/* 9A1F80 80240FA0 E4A00018 */   swc1     $f0, 0x18($a1)
.L80240FA4:
/* 9A1F84 80240FA4 3C018024 */  lui       $at, %hi(D_80243348_9A4328)
/* 9A1F88 80240FA8 D4223348 */  ldc1      $f2, %lo(D_80243348_9A4328)($at)
/* 9A1F8C 80240FAC 44820000 */  mtc1      $v0, $f0
/* 9A1F90 80240FB0 00000000 */  nop
/* 9A1F94 80240FB4 46800021 */  cvt.d.w   $f0, $f0
/* 9A1F98 80240FB8 46220003 */  div.d     $f0, $f0, $f2
/* 9A1F9C 80240FBC 46200020 */  cvt.s.d   $f0, $f0
/* 9A1FA0 80240FC0 E4A00018 */  swc1      $f0, 0x18($a1)
.L80240FC4:
/* 9A1FA4 80240FC4 24020001 */  addiu     $v0, $zero, 1
/* 9A1FA8 80240FC8 AE220070 */  sw        $v0, 0x70($s1)
/* 9A1FAC 80240FCC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A1FB0 80240FD0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A1FB4 80240FD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A1FB8 80240FD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A1FBC 80240FDC 03E00008 */  jr        $ra
/* 9A1FC0 80240FE0 27BD0020 */   addiu    $sp, $sp, 0x20
