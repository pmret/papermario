.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DFC_95BFFC
/* 95BFFC 80240DFC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 95C000 80240E00 AFB3001C */  sw        $s3, 0x1c($sp)
/* 95C004 80240E04 0080982D */  daddu     $s3, $a0, $zero
/* 95C008 80240E08 AFBF0020 */  sw        $ra, 0x20($sp)
/* 95C00C 80240E0C AFB20018 */  sw        $s2, 0x18($sp)
/* 95C010 80240E10 AFB10014 */  sw        $s1, 0x14($sp)
/* 95C014 80240E14 AFB00010 */  sw        $s0, 0x10($sp)
/* 95C018 80240E18 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 95C01C 80240E1C 8E710148 */  lw        $s1, 0x148($s3)
/* 95C020 80240E20 86240008 */  lh        $a0, 8($s1)
/* 95C024 80240E24 0C00EABB */  jal       get_npc_unsafe
/* 95C028 80240E28 00A0802D */   daddu    $s0, $a1, $zero
/* 95C02C 80240E2C 8E040020 */  lw        $a0, 0x20($s0)
/* 95C030 80240E30 0040902D */  daddu     $s2, $v0, $zero
/* 95C034 80240E34 00041FC2 */  srl       $v1, $a0, 0x1f
/* 95C038 80240E38 00832021 */  addu      $a0, $a0, $v1
/* 95C03C 80240E3C 00042043 */  sra       $a0, $a0, 1
/* 95C040 80240E40 0C00A67F */  jal       rand_int
/* 95C044 80240E44 24840001 */   addiu    $a0, $a0, 1
/* 95C048 80240E48 8E030020 */  lw        $v1, 0x20($s0)
/* 95C04C 80240E4C C64C0038 */  lwc1      $f12, 0x38($s2)
/* 95C050 80240E50 000327C2 */  srl       $a0, $v1, 0x1f
/* 95C054 80240E54 00641821 */  addu      $v1, $v1, $a0
/* 95C058 80240E58 00031843 */  sra       $v1, $v1, 1
/* 95C05C 80240E5C 00621821 */  addu      $v1, $v1, $v0
/* 95C060 80240E60 A643008E */  sh        $v1, 0x8e($s2)
/* 95C064 80240E64 8E2200CC */  lw        $v0, 0xcc($s1)
/* 95C068 80240E68 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 95C06C 80240E6C 8C42000C */  lw        $v0, 0xc($v0)
/* 95C070 80240E70 AE420028 */  sw        $v0, 0x28($s2)
/* 95C074 80240E74 C6000018 */  lwc1      $f0, 0x18($s0)
/* 95C078 80240E78 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 95C07C 80240E7C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 95C080 80240E80 E6400018 */  swc1      $f0, 0x18($s2)
/* 95C084 80240E84 8C460028 */  lw        $a2, 0x28($v0)
/* 95C088 80240E88 0C00A720 */  jal       atan2
/* 95C08C 80240E8C 8C470030 */   lw       $a3, 0x30($v0)
/* 95C090 80240E90 46000506 */  mov.s     $f20, $f0
/* 95C094 80240E94 C64C000C */  lwc1      $f12, 0xc($s2)
/* 95C098 80240E98 0C00A70A */  jal       get_clamped_angle_diff
/* 95C09C 80240E9C 4600A386 */   mov.s    $f14, $f20
/* 95C0A0 80240EA0 46000086 */  mov.s     $f2, $f0
/* 95C0A4 80240EA4 8E02001C */  lw        $v0, 0x1c($s0)
/* 95C0A8 80240EA8 46001005 */  abs.s     $f0, $f2
/* 95C0AC 80240EAC 44822000 */  mtc1      $v0, $f4
/* 95C0B0 80240EB0 00000000 */  nop
/* 95C0B4 80240EB4 46802120 */  cvt.s.w   $f4, $f4
/* 95C0B8 80240EB8 4600203C */  c.lt.s    $f4, $f0
/* 95C0BC 80240EBC 00000000 */  nop
/* 95C0C0 80240EC0 4500000D */  bc1f      .L80240EF8
/* 95C0C4 80240EC4 00000000 */   nop
/* 95C0C8 80240EC8 44800000 */  mtc1      $zero, $f0
/* 95C0CC 80240ECC C654000C */  lwc1      $f20, 0xc($s2)
/* 95C0D0 80240ED0 4600103C */  c.lt.s    $f2, $f0
/* 95C0D4 80240ED4 00000000 */  nop
/* 95C0D8 80240ED8 45000006 */  bc1f      .L80240EF4
/* 95C0DC 80240EDC 00021023 */   negu     $v0, $v0
/* 95C0E0 80240EE0 44820000 */  mtc1      $v0, $f0
/* 95C0E4 80240EE4 00000000 */  nop
/* 95C0E8 80240EE8 46800020 */  cvt.s.w   $f0, $f0
/* 95C0EC 80240EEC 080903BE */  j         .L80240EF8
/* 95C0F0 80240EF0 4600A500 */   add.s    $f20, $f20, $f0
.L80240EF4:
/* 95C0F4 80240EF4 4604A500 */  add.s     $f20, $f20, $f4
.L80240EF8:
/* 95C0F8 80240EF8 0C00A6C9 */  jal       clamp_angle
/* 95C0FC 80240EFC 4600A306 */   mov.s    $f12, $f20
/* 95C100 80240F00 2402000D */  addiu     $v0, $zero, 0xd
/* 95C104 80240F04 E640000C */  swc1      $f0, 0xc($s2)
/* 95C108 80240F08 AE620070 */  sw        $v0, 0x70($s3)
/* 95C10C 80240F0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 95C110 80240F10 8FB3001C */  lw        $s3, 0x1c($sp)
/* 95C114 80240F14 8FB20018 */  lw        $s2, 0x18($sp)
/* 95C118 80240F18 8FB10014 */  lw        $s1, 0x14($sp)
/* 95C11C 80240F1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 95C120 80240F20 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 95C124 80240F24 03E00008 */  jr        $ra
/* 95C128 80240F28 27BD0030 */   addiu    $sp, $sp, 0x30
