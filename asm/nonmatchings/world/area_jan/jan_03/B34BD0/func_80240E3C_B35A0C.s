.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E3C_B35A0C
/* B35A0C 80240E3C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B35A10 80240E40 AFB3001C */  sw        $s3, 0x1c($sp)
/* B35A14 80240E44 0080982D */  daddu     $s3, $a0, $zero
/* B35A18 80240E48 AFBF0020 */  sw        $ra, 0x20($sp)
/* B35A1C 80240E4C AFB20018 */  sw        $s2, 0x18($sp)
/* B35A20 80240E50 AFB10014 */  sw        $s1, 0x14($sp)
/* B35A24 80240E54 AFB00010 */  sw        $s0, 0x10($sp)
/* B35A28 80240E58 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B35A2C 80240E5C 8E710148 */  lw        $s1, 0x148($s3)
/* B35A30 80240E60 86240008 */  lh        $a0, 8($s1)
/* B35A34 80240E64 0C00EABB */  jal       get_npc_unsafe
/* B35A38 80240E68 00A0802D */   daddu    $s0, $a1, $zero
/* B35A3C 80240E6C 8E040020 */  lw        $a0, 0x20($s0)
/* B35A40 80240E70 0040902D */  daddu     $s2, $v0, $zero
/* B35A44 80240E74 00041FC2 */  srl       $v1, $a0, 0x1f
/* B35A48 80240E78 00832021 */  addu      $a0, $a0, $v1
/* B35A4C 80240E7C 00042043 */  sra       $a0, $a0, 1
/* B35A50 80240E80 0C00A67F */  jal       rand_int
/* B35A54 80240E84 24840001 */   addiu    $a0, $a0, 1
/* B35A58 80240E88 8E030020 */  lw        $v1, 0x20($s0)
/* B35A5C 80240E8C C64C0038 */  lwc1      $f12, 0x38($s2)
/* B35A60 80240E90 000327C2 */  srl       $a0, $v1, 0x1f
/* B35A64 80240E94 00641821 */  addu      $v1, $v1, $a0
/* B35A68 80240E98 00031843 */  sra       $v1, $v1, 1
/* B35A6C 80240E9C 00621821 */  addu      $v1, $v1, $v0
/* B35A70 80240EA0 A643008E */  sh        $v1, 0x8e($s2)
/* B35A74 80240EA4 8E2200CC */  lw        $v0, 0xcc($s1)
/* B35A78 80240EA8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* B35A7C 80240EAC 8C42000C */  lw        $v0, 0xc($v0)
/* B35A80 80240EB0 AE420028 */  sw        $v0, 0x28($s2)
/* B35A84 80240EB4 C6000018 */  lwc1      $f0, 0x18($s0)
/* B35A88 80240EB8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B35A8C 80240EBC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B35A90 80240EC0 E6400018 */  swc1      $f0, 0x18($s2)
/* B35A94 80240EC4 8C460028 */  lw        $a2, 0x28($v0)
/* B35A98 80240EC8 0C00A720 */  jal       atan2
/* B35A9C 80240ECC 8C470030 */   lw       $a3, 0x30($v0)
/* B35AA0 80240ED0 46000506 */  mov.s     $f20, $f0
/* B35AA4 80240ED4 C64C000C */  lwc1      $f12, 0xc($s2)
/* B35AA8 80240ED8 0C00A70A */  jal       get_clamped_angle_diff
/* B35AAC 80240EDC 4600A386 */   mov.s    $f14, $f20
/* B35AB0 80240EE0 46000086 */  mov.s     $f2, $f0
/* B35AB4 80240EE4 8E02001C */  lw        $v0, 0x1c($s0)
/* B35AB8 80240EE8 46001005 */  abs.s     $f0, $f2
/* B35ABC 80240EEC 44822000 */  mtc1      $v0, $f4
/* B35AC0 80240EF0 00000000 */  nop       
/* B35AC4 80240EF4 46802120 */  cvt.s.w   $f4, $f4
/* B35AC8 80240EF8 4600203C */  c.lt.s    $f4, $f0
/* B35ACC 80240EFC 00000000 */  nop       
/* B35AD0 80240F00 4500000D */  bc1f      .L80240F38
/* B35AD4 80240F04 00000000 */   nop      
/* B35AD8 80240F08 44800000 */  mtc1      $zero, $f0
/* B35ADC 80240F0C C654000C */  lwc1      $f20, 0xc($s2)
/* B35AE0 80240F10 4600103C */  c.lt.s    $f2, $f0
/* B35AE4 80240F14 00000000 */  nop       
/* B35AE8 80240F18 45000006 */  bc1f      .L80240F34
/* B35AEC 80240F1C 00021023 */   negu     $v0, $v0
/* B35AF0 80240F20 44820000 */  mtc1      $v0, $f0
/* B35AF4 80240F24 00000000 */  nop       
/* B35AF8 80240F28 46800020 */  cvt.s.w   $f0, $f0
/* B35AFC 80240F2C 080903CE */  j         .L80240F38
/* B35B00 80240F30 4600A500 */   add.s    $f20, $f20, $f0
.L80240F34:
/* B35B04 80240F34 4604A500 */  add.s     $f20, $f20, $f4
.L80240F38:
/* B35B08 80240F38 0C00A6C9 */  jal       clamp_angle
/* B35B0C 80240F3C 4600A306 */   mov.s    $f12, $f20
/* B35B10 80240F40 2402000D */  addiu     $v0, $zero, 0xd
/* B35B14 80240F44 E640000C */  swc1      $f0, 0xc($s2)
/* B35B18 80240F48 AE620070 */  sw        $v0, 0x70($s3)
/* B35B1C 80240F4C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B35B20 80240F50 8FB3001C */  lw        $s3, 0x1c($sp)
/* B35B24 80240F54 8FB20018 */  lw        $s2, 0x18($sp)
/* B35B28 80240F58 8FB10014 */  lw        $s1, 0x14($sp)
/* B35B2C 80240F5C 8FB00010 */  lw        $s0, 0x10($sp)
/* B35B30 80240F60 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B35B34 80240F64 03E00008 */  jr        $ra
/* B35B38 80240F68 27BD0030 */   addiu    $sp, $sp, 0x30
