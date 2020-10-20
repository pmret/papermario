.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D88_DBE038
/* DBE038 80240D88 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DBE03C 80240D8C AFB3001C */  sw        $s3, 0x1c($sp)
/* DBE040 80240D90 0080982D */  daddu     $s3, $a0, $zero
/* DBE044 80240D94 AFBF0020 */  sw        $ra, 0x20($sp)
/* DBE048 80240D98 AFB20018 */  sw        $s2, 0x18($sp)
/* DBE04C 80240D9C AFB10014 */  sw        $s1, 0x14($sp)
/* DBE050 80240DA0 AFB00010 */  sw        $s0, 0x10($sp)
/* DBE054 80240DA4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* DBE058 80240DA8 8E710148 */  lw        $s1, 0x148($s3)
/* DBE05C 80240DAC 86240008 */  lh        $a0, 8($s1)
/* DBE060 80240DB0 0C00EABB */  jal       get_npc_unsafe
/* DBE064 80240DB4 00A0802D */   daddu    $s0, $a1, $zero
/* DBE068 80240DB8 8E040020 */  lw        $a0, 0x20($s0)
/* DBE06C 80240DBC 0040902D */  daddu     $s2, $v0, $zero
/* DBE070 80240DC0 00041FC2 */  srl       $v1, $a0, 0x1f
/* DBE074 80240DC4 00832021 */  addu      $a0, $a0, $v1
/* DBE078 80240DC8 00042043 */  sra       $a0, $a0, 1
/* DBE07C 80240DCC 0C00A67F */  jal       rand_int
/* DBE080 80240DD0 24840001 */   addiu    $a0, $a0, 1
/* DBE084 80240DD4 8E030020 */  lw        $v1, 0x20($s0)
/* DBE088 80240DD8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* DBE08C 80240DDC 000327C2 */  srl       $a0, $v1, 0x1f
/* DBE090 80240DE0 00641821 */  addu      $v1, $v1, $a0
/* DBE094 80240DE4 00031843 */  sra       $v1, $v1, 1
/* DBE098 80240DE8 00621821 */  addu      $v1, $v1, $v0
/* DBE09C 80240DEC A643008E */  sh        $v1, 0x8e($s2)
/* DBE0A0 80240DF0 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBE0A4 80240DF4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* DBE0A8 80240DF8 8C42000C */  lw        $v0, 0xc($v0)
/* DBE0AC 80240DFC AE420028 */  sw        $v0, 0x28($s2)
/* DBE0B0 80240E00 C6000018 */  lwc1      $f0, 0x18($s0)
/* DBE0B4 80240E04 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBE0B8 80240E08 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBE0BC 80240E0C E6400018 */  swc1      $f0, 0x18($s2)
/* DBE0C0 80240E10 8C460028 */  lw        $a2, 0x28($v0)
/* DBE0C4 80240E14 0C00A720 */  jal       atan2
/* DBE0C8 80240E18 8C470030 */   lw       $a3, 0x30($v0)
/* DBE0CC 80240E1C 46000506 */  mov.s     $f20, $f0
/* DBE0D0 80240E20 C64C000C */  lwc1      $f12, 0xc($s2)
/* DBE0D4 80240E24 0C00A70A */  jal       get_clamped_angle_diff
/* DBE0D8 80240E28 4600A386 */   mov.s    $f14, $f20
/* DBE0DC 80240E2C 46000086 */  mov.s     $f2, $f0
/* DBE0E0 80240E30 8E02001C */  lw        $v0, 0x1c($s0)
/* DBE0E4 80240E34 46001005 */  abs.s     $f0, $f2
/* DBE0E8 80240E38 44822000 */  mtc1      $v0, $f4
/* DBE0EC 80240E3C 00000000 */  nop       
/* DBE0F0 80240E40 46802120 */  cvt.s.w   $f4, $f4
/* DBE0F4 80240E44 4600203C */  c.lt.s    $f4, $f0
/* DBE0F8 80240E48 00000000 */  nop       
/* DBE0FC 80240E4C 4500000D */  bc1f      .L80240E84
/* DBE100 80240E50 00000000 */   nop      
/* DBE104 80240E54 44800000 */  mtc1      $zero, $f0
/* DBE108 80240E58 C654000C */  lwc1      $f20, 0xc($s2)
/* DBE10C 80240E5C 4600103C */  c.lt.s    $f2, $f0
/* DBE110 80240E60 00000000 */  nop       
/* DBE114 80240E64 45000006 */  bc1f      .L80240E80
/* DBE118 80240E68 00021023 */   negu     $v0, $v0
/* DBE11C 80240E6C 44820000 */  mtc1      $v0, $f0
/* DBE120 80240E70 00000000 */  nop       
/* DBE124 80240E74 46800020 */  cvt.s.w   $f0, $f0
/* DBE128 80240E78 080903A1 */  j         .L80240E84
/* DBE12C 80240E7C 4600A500 */   add.s    $f20, $f20, $f0
.L80240E80:
/* DBE130 80240E80 4604A500 */  add.s     $f20, $f20, $f4
.L80240E84:
/* DBE134 80240E84 0C00A6C9 */  jal       clamp_angle
/* DBE138 80240E88 4600A306 */   mov.s    $f12, $f20
/* DBE13C 80240E8C 2402000D */  addiu     $v0, $zero, 0xd
/* DBE140 80240E90 E640000C */  swc1      $f0, 0xc($s2)
/* DBE144 80240E94 AE620070 */  sw        $v0, 0x70($s3)
/* DBE148 80240E98 8FBF0020 */  lw        $ra, 0x20($sp)
/* DBE14C 80240E9C 8FB3001C */  lw        $s3, 0x1c($sp)
/* DBE150 80240EA0 8FB20018 */  lw        $s2, 0x18($sp)
/* DBE154 80240EA4 8FB10014 */  lw        $s1, 0x14($sp)
/* DBE158 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* DBE15C 80240EAC D7B40028 */  ldc1      $f20, 0x28($sp)
/* DBE160 80240EB0 03E00008 */  jr        $ra
/* DBE164 80240EB4 27BD0030 */   addiu    $sp, $sp, 0x30
