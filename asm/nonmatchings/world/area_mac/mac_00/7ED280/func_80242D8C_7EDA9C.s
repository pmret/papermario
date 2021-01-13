.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D8C_7EDA9C
/* 7EDA9C 80242D8C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7EDAA0 80242D90 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7EDAA4 80242D94 0080982D */  daddu     $s3, $a0, $zero
/* 7EDAA8 80242D98 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7EDAAC 80242D9C AFB20018 */  sw        $s2, 0x18($sp)
/* 7EDAB0 80242DA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EDAB4 80242DA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EDAB8 80242DA8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 7EDABC 80242DAC 8E710148 */  lw        $s1, 0x148($s3)
/* 7EDAC0 80242DB0 86240008 */  lh        $a0, 8($s1)
/* 7EDAC4 80242DB4 0C00EABB */  jal       get_npc_unsafe
/* 7EDAC8 80242DB8 00A0802D */   daddu    $s0, $a1, $zero
/* 7EDACC 80242DBC 8E040020 */  lw        $a0, 0x20($s0)
/* 7EDAD0 80242DC0 0040902D */  daddu     $s2, $v0, $zero
/* 7EDAD4 80242DC4 00041FC2 */  srl       $v1, $a0, 0x1f
/* 7EDAD8 80242DC8 00832021 */  addu      $a0, $a0, $v1
/* 7EDADC 80242DCC 00042043 */  sra       $a0, $a0, 1
/* 7EDAE0 80242DD0 0C00A67F */  jal       rand_int
/* 7EDAE4 80242DD4 24840001 */   addiu    $a0, $a0, 1
/* 7EDAE8 80242DD8 8E030020 */  lw        $v1, 0x20($s0)
/* 7EDAEC 80242DDC C64C0038 */  lwc1      $f12, 0x38($s2)
/* 7EDAF0 80242DE0 000327C2 */  srl       $a0, $v1, 0x1f
/* 7EDAF4 80242DE4 00641821 */  addu      $v1, $v1, $a0
/* 7EDAF8 80242DE8 00031843 */  sra       $v1, $v1, 1
/* 7EDAFC 80242DEC 00621821 */  addu      $v1, $v1, $v0
/* 7EDB00 80242DF0 A643008E */  sh        $v1, 0x8e($s2)
/* 7EDB04 80242DF4 8E2200CC */  lw        $v0, 0xcc($s1)
/* 7EDB08 80242DF8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 7EDB0C 80242DFC 8C42000C */  lw        $v0, 0xc($v0)
/* 7EDB10 80242E00 AE420028 */  sw        $v0, 0x28($s2)
/* 7EDB14 80242E04 C6000018 */  lwc1      $f0, 0x18($s0)
/* 7EDB18 80242E08 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 7EDB1C 80242E0C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 7EDB20 80242E10 E6400018 */  swc1      $f0, 0x18($s2)
/* 7EDB24 80242E14 8C460028 */  lw        $a2, 0x28($v0)
/* 7EDB28 80242E18 0C00A720 */  jal       atan2
/* 7EDB2C 80242E1C 8C470030 */   lw       $a3, 0x30($v0)
/* 7EDB30 80242E20 46000506 */  mov.s     $f20, $f0
/* 7EDB34 80242E24 C64C000C */  lwc1      $f12, 0xc($s2)
/* 7EDB38 80242E28 0C00A70A */  jal       get_clamped_angle_diff
/* 7EDB3C 80242E2C 4600A386 */   mov.s    $f14, $f20
/* 7EDB40 80242E30 46000086 */  mov.s     $f2, $f0
/* 7EDB44 80242E34 8E02001C */  lw        $v0, 0x1c($s0)
/* 7EDB48 80242E38 46001005 */  abs.s     $f0, $f2
/* 7EDB4C 80242E3C 44822000 */  mtc1      $v0, $f4
/* 7EDB50 80242E40 00000000 */  nop
/* 7EDB54 80242E44 46802120 */  cvt.s.w   $f4, $f4
/* 7EDB58 80242E48 4600203C */  c.lt.s    $f4, $f0
/* 7EDB5C 80242E4C 00000000 */  nop
/* 7EDB60 80242E50 4500000D */  bc1f      .L80242E88
/* 7EDB64 80242E54 00000000 */   nop
/* 7EDB68 80242E58 44800000 */  mtc1      $zero, $f0
/* 7EDB6C 80242E5C C654000C */  lwc1      $f20, 0xc($s2)
/* 7EDB70 80242E60 4600103C */  c.lt.s    $f2, $f0
/* 7EDB74 80242E64 00000000 */  nop
/* 7EDB78 80242E68 45000006 */  bc1f      .L80242E84
/* 7EDB7C 80242E6C 00021023 */   negu     $v0, $v0
/* 7EDB80 80242E70 44820000 */  mtc1      $v0, $f0
/* 7EDB84 80242E74 00000000 */  nop
/* 7EDB88 80242E78 46800020 */  cvt.s.w   $f0, $f0
/* 7EDB8C 80242E7C 08090BA2 */  j         .L80242E88
/* 7EDB90 80242E80 4600A500 */   add.s    $f20, $f20, $f0
.L80242E84:
/* 7EDB94 80242E84 4604A500 */  add.s     $f20, $f20, $f4
.L80242E88:
/* 7EDB98 80242E88 0C00A6C9 */  jal       clamp_angle
/* 7EDB9C 80242E8C 4600A306 */   mov.s    $f12, $f20
/* 7EDBA0 80242E90 2402000D */  addiu     $v0, $zero, 0xd
/* 7EDBA4 80242E94 E640000C */  swc1      $f0, 0xc($s2)
/* 7EDBA8 80242E98 AE620070 */  sw        $v0, 0x70($s3)
/* 7EDBAC 80242E9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7EDBB0 80242EA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7EDBB4 80242EA4 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EDBB8 80242EA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EDBBC 80242EAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EDBC0 80242EB0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 7EDBC4 80242EB4 03E00008 */  jr        $ra
/* 7EDBC8 80242EB8 27BD0030 */   addiu    $sp, $sp, 0x30
