.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CAC_852E1C
/* 852E1C 80240CAC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 852E20 80240CB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 852E24 80240CB4 0080982D */  daddu     $s3, $a0, $zero
/* 852E28 80240CB8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 852E2C 80240CBC AFB20018 */  sw        $s2, 0x18($sp)
/* 852E30 80240CC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 852E34 80240CC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 852E38 80240CC8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 852E3C 80240CCC 8E710148 */  lw        $s1, 0x148($s3)
/* 852E40 80240CD0 86240008 */  lh        $a0, 8($s1)
/* 852E44 80240CD4 0C00EABB */  jal       get_npc_unsafe
/* 852E48 80240CD8 00A0802D */   daddu    $s0, $a1, $zero
/* 852E4C 80240CDC 8E040020 */  lw        $a0, 0x20($s0)
/* 852E50 80240CE0 0040902D */  daddu     $s2, $v0, $zero
/* 852E54 80240CE4 00041FC2 */  srl       $v1, $a0, 0x1f
/* 852E58 80240CE8 00832021 */  addu      $a0, $a0, $v1
/* 852E5C 80240CEC 00042043 */  sra       $a0, $a0, 1
/* 852E60 80240CF0 0C00A67F */  jal       rand_int
/* 852E64 80240CF4 24840001 */   addiu    $a0, $a0, 1
/* 852E68 80240CF8 8E030020 */  lw        $v1, 0x20($s0)
/* 852E6C 80240CFC C64C0038 */  lwc1      $f12, 0x38($s2)
/* 852E70 80240D00 000327C2 */  srl       $a0, $v1, 0x1f
/* 852E74 80240D04 00641821 */  addu      $v1, $v1, $a0
/* 852E78 80240D08 00031843 */  sra       $v1, $v1, 1
/* 852E7C 80240D0C 00621821 */  addu      $v1, $v1, $v0
/* 852E80 80240D10 A643008E */  sh        $v1, 0x8e($s2)
/* 852E84 80240D14 8E2200CC */  lw        $v0, 0xcc($s1)
/* 852E88 80240D18 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 852E8C 80240D1C 8C42000C */  lw        $v0, 0xc($v0)
/* 852E90 80240D20 AE420028 */  sw        $v0, 0x28($s2)
/* 852E94 80240D24 C6000018 */  lwc1      $f0, 0x18($s0)
/* 852E98 80240D28 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 852E9C 80240D2C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 852EA0 80240D30 E6400018 */  swc1      $f0, 0x18($s2)
/* 852EA4 80240D34 8C460028 */  lw        $a2, 0x28($v0)
/* 852EA8 80240D38 0C00A720 */  jal       atan2
/* 852EAC 80240D3C 8C470030 */   lw       $a3, 0x30($v0)
/* 852EB0 80240D40 46000506 */  mov.s     $f20, $f0
/* 852EB4 80240D44 C64C000C */  lwc1      $f12, 0xc($s2)
/* 852EB8 80240D48 0C00A70A */  jal       get_clamped_angle_diff
/* 852EBC 80240D4C 4600A386 */   mov.s    $f14, $f20
/* 852EC0 80240D50 46000086 */  mov.s     $f2, $f0
/* 852EC4 80240D54 8E02001C */  lw        $v0, 0x1c($s0)
/* 852EC8 80240D58 46001005 */  abs.s     $f0, $f2
/* 852ECC 80240D5C 44822000 */  mtc1      $v0, $f4
/* 852ED0 80240D60 00000000 */  nop
/* 852ED4 80240D64 46802120 */  cvt.s.w   $f4, $f4
/* 852ED8 80240D68 4600203C */  c.lt.s    $f4, $f0
/* 852EDC 80240D6C 00000000 */  nop
/* 852EE0 80240D70 4500000D */  bc1f      .L80240DA8
/* 852EE4 80240D74 00000000 */   nop
/* 852EE8 80240D78 44800000 */  mtc1      $zero, $f0
/* 852EEC 80240D7C C654000C */  lwc1      $f20, 0xc($s2)
/* 852EF0 80240D80 4600103C */  c.lt.s    $f2, $f0
/* 852EF4 80240D84 00000000 */  nop
/* 852EF8 80240D88 45000006 */  bc1f      .L80240DA4
/* 852EFC 80240D8C 00021023 */   negu     $v0, $v0
/* 852F00 80240D90 44820000 */  mtc1      $v0, $f0
/* 852F04 80240D94 00000000 */  nop
/* 852F08 80240D98 46800020 */  cvt.s.w   $f0, $f0
/* 852F0C 80240D9C 0809036A */  j         .L80240DA8
/* 852F10 80240DA0 4600A500 */   add.s    $f20, $f20, $f0
.L80240DA4:
/* 852F14 80240DA4 4604A500 */  add.s     $f20, $f20, $f4
.L80240DA8:
/* 852F18 80240DA8 0C00A6C9 */  jal       clamp_angle
/* 852F1C 80240DAC 4600A306 */   mov.s    $f12, $f20
/* 852F20 80240DB0 2402000D */  addiu     $v0, $zero, 0xd
/* 852F24 80240DB4 E640000C */  swc1      $f0, 0xc($s2)
/* 852F28 80240DB8 AE620070 */  sw        $v0, 0x70($s3)
/* 852F2C 80240DBC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 852F30 80240DC0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 852F34 80240DC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 852F38 80240DC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 852F3C 80240DCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 852F40 80240DD0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 852F44 80240DD4 03E00008 */  jr        $ra
/* 852F48 80240DD8 27BD0030 */   addiu    $sp, $sp, 0x30
