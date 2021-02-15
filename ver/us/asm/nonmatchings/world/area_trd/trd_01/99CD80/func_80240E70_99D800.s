.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E70_99D800
/* 99D800 80240E70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 99D804 80240E74 AFB3001C */  sw        $s3, 0x1c($sp)
/* 99D808 80240E78 0080982D */  daddu     $s3, $a0, $zero
/* 99D80C 80240E7C AFBF0020 */  sw        $ra, 0x20($sp)
/* 99D810 80240E80 AFB20018 */  sw        $s2, 0x18($sp)
/* 99D814 80240E84 AFB10014 */  sw        $s1, 0x14($sp)
/* 99D818 80240E88 AFB00010 */  sw        $s0, 0x10($sp)
/* 99D81C 80240E8C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 99D820 80240E90 8E710148 */  lw        $s1, 0x148($s3)
/* 99D824 80240E94 86240008 */  lh        $a0, 8($s1)
/* 99D828 80240E98 0C00EABB */  jal       get_npc_unsafe
/* 99D82C 80240E9C 00A0802D */   daddu    $s0, $a1, $zero
/* 99D830 80240EA0 8E040014 */  lw        $a0, 0x14($s0)
/* 99D834 80240EA4 0040902D */  daddu     $s2, $v0, $zero
/* 99D838 80240EA8 00041FC2 */  srl       $v1, $a0, 0x1f
/* 99D83C 80240EAC 00832021 */  addu      $a0, $a0, $v1
/* 99D840 80240EB0 00042043 */  sra       $a0, $a0, 1
/* 99D844 80240EB4 0C00A67F */  jal       rand_int
/* 99D848 80240EB8 24840001 */   addiu    $a0, $a0, 1
/* 99D84C 80240EBC 8E030014 */  lw        $v1, 0x14($s0)
/* 99D850 80240EC0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* 99D854 80240EC4 000327C2 */  srl       $a0, $v1, 0x1f
/* 99D858 80240EC8 00641821 */  addu      $v1, $v1, $a0
/* 99D85C 80240ECC 00031843 */  sra       $v1, $v1, 1
/* 99D860 80240ED0 00621821 */  addu      $v1, $v1, $v0
/* 99D864 80240ED4 A643008E */  sh        $v1, 0x8e($s2)
/* 99D868 80240ED8 8E2200CC */  lw        $v0, 0xcc($s1)
/* 99D86C 80240EDC C64E0040 */  lwc1      $f14, 0x40($s2)
/* 99D870 80240EE0 8C42000C */  lw        $v0, 0xc($v0)
/* 99D874 80240EE4 AE420028 */  sw        $v0, 0x28($s2)
/* 99D878 80240EE8 C600000C */  lwc1      $f0, 0xc($s0)
/* 99D87C 80240EEC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 99D880 80240EF0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 99D884 80240EF4 E6400018 */  swc1      $f0, 0x18($s2)
/* 99D888 80240EF8 8C460028 */  lw        $a2, 0x28($v0)
/* 99D88C 80240EFC 0C00A720 */  jal       atan2
/* 99D890 80240F00 8C470030 */   lw       $a3, 0x30($v0)
/* 99D894 80240F04 46000506 */  mov.s     $f20, $f0
/* 99D898 80240F08 C64C000C */  lwc1      $f12, 0xc($s2)
/* 99D89C 80240F0C 0C00A70A */  jal       get_clamped_angle_diff
/* 99D8A0 80240F10 4600A386 */   mov.s    $f14, $f20
/* 99D8A4 80240F14 46000086 */  mov.s     $f2, $f0
/* 99D8A8 80240F18 8E020010 */  lw        $v0, 0x10($s0)
/* 99D8AC 80240F1C 46001005 */  abs.s     $f0, $f2
/* 99D8B0 80240F20 44822000 */  mtc1      $v0, $f4
/* 99D8B4 80240F24 00000000 */  nop
/* 99D8B8 80240F28 46802120 */  cvt.s.w   $f4, $f4
/* 99D8BC 80240F2C 4600203C */  c.lt.s    $f4, $f0
/* 99D8C0 80240F30 00000000 */  nop
/* 99D8C4 80240F34 4500000D */  bc1f      .L80240F6C
/* 99D8C8 80240F38 00000000 */   nop
/* 99D8CC 80240F3C 44800000 */  mtc1      $zero, $f0
/* 99D8D0 80240F40 C654000C */  lwc1      $f20, 0xc($s2)
/* 99D8D4 80240F44 4600103C */  c.lt.s    $f2, $f0
/* 99D8D8 80240F48 00000000 */  nop
/* 99D8DC 80240F4C 45000006 */  bc1f      .L80240F68
/* 99D8E0 80240F50 00021023 */   negu     $v0, $v0
/* 99D8E4 80240F54 44820000 */  mtc1      $v0, $f0
/* 99D8E8 80240F58 00000000 */  nop
/* 99D8EC 80240F5C 46800020 */  cvt.s.w   $f0, $f0
/* 99D8F0 80240F60 080903DB */  j         .L80240F6C
/* 99D8F4 80240F64 4600A500 */   add.s    $f20, $f20, $f0
.L80240F68:
/* 99D8F8 80240F68 4604A500 */  add.s     $f20, $f20, $f4
.L80240F6C:
/* 99D8FC 80240F6C 0C00A6C9 */  jal       clamp_angle
/* 99D900 80240F70 4600A306 */   mov.s    $f12, $f20
/* 99D904 80240F74 2402000D */  addiu     $v0, $zero, 0xd
/* 99D908 80240F78 E640000C */  swc1      $f0, 0xc($s2)
/* 99D90C 80240F7C AE620070 */  sw        $v0, 0x70($s3)
/* 99D910 80240F80 8FBF0020 */  lw        $ra, 0x20($sp)
/* 99D914 80240F84 8FB3001C */  lw        $s3, 0x1c($sp)
/* 99D918 80240F88 8FB20018 */  lw        $s2, 0x18($sp)
/* 99D91C 80240F8C 8FB10014 */  lw        $s1, 0x14($sp)
/* 99D920 80240F90 8FB00010 */  lw        $s0, 0x10($sp)
/* 99D924 80240F94 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 99D928 80240F98 03E00008 */  jr        $ra
/* 99D92C 80240F9C 27BD0030 */   addiu    $sp, $sp, 0x30
