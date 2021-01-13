.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C58_C42A08
/* C42A08 80242C58 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C42A0C 80242C5C AFB3001C */  sw        $s3, 0x1c($sp)
/* C42A10 80242C60 0080982D */  daddu     $s3, $a0, $zero
/* C42A14 80242C64 AFBF0020 */  sw        $ra, 0x20($sp)
/* C42A18 80242C68 AFB20018 */  sw        $s2, 0x18($sp)
/* C42A1C 80242C6C AFB10014 */  sw        $s1, 0x14($sp)
/* C42A20 80242C70 AFB00010 */  sw        $s0, 0x10($sp)
/* C42A24 80242C74 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C42A28 80242C78 8E720148 */  lw        $s2, 0x148($s3)
/* C42A2C 80242C7C 86440008 */  lh        $a0, 8($s2)
/* C42A30 80242C80 0C00EABB */  jal       get_npc_unsafe
/* C42A34 80242C84 00A0882D */   daddu    $s1, $a1, $zero
/* C42A38 80242C88 0040802D */  daddu     $s0, $v0, $zero
/* C42A3C 80242C8C 9602008E */  lhu       $v0, 0x8e($s0)
/* C42A40 80242C90 2442FFFF */  addiu     $v0, $v0, -1
/* C42A44 80242C94 A602008E */  sh        $v0, 0x8e($s0)
/* C42A48 80242C98 00021400 */  sll       $v0, $v0, 0x10
/* C42A4C 80242C9C 1C40003C */  bgtz      $v0, .L80242D90
/* C42A50 80242CA0 3C03FFDF */   lui      $v1, 0xffdf
/* C42A54 80242CA4 8E020000 */  lw        $v0, ($s0)
/* C42A58 80242CA8 3463FFFF */  ori       $v1, $v1, 0xffff
/* C42A5C 80242CAC 00431024 */  and       $v0, $v0, $v1
/* C42A60 80242CB0 AE020000 */  sw        $v0, ($s0)
/* C42A64 80242CB4 8E240020 */  lw        $a0, 0x20($s1)
/* C42A68 80242CB8 000417C2 */  srl       $v0, $a0, 0x1f
/* C42A6C 80242CBC 00822021 */  addu      $a0, $a0, $v0
/* C42A70 80242CC0 00042043 */  sra       $a0, $a0, 1
/* C42A74 80242CC4 0C00A67F */  jal       rand_int
/* C42A78 80242CC8 24840001 */   addiu    $a0, $a0, 1
/* C42A7C 80242CCC 8E230020 */  lw        $v1, 0x20($s1)
/* C42A80 80242CD0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C42A84 80242CD4 000327C2 */  srl       $a0, $v1, 0x1f
/* C42A88 80242CD8 00641821 */  addu      $v1, $v1, $a0
/* C42A8C 80242CDC 00031843 */  sra       $v1, $v1, 1
/* C42A90 80242CE0 00621821 */  addu      $v1, $v1, $v0
/* C42A94 80242CE4 A603008E */  sh        $v1, 0x8e($s0)
/* C42A98 80242CE8 8E4200CC */  lw        $v0, 0xcc($s2)
/* C42A9C 80242CEC C60E0040 */  lwc1      $f14, 0x40($s0)
/* C42AA0 80242CF0 8C420020 */  lw        $v0, 0x20($v0)
/* C42AA4 80242CF4 AE020028 */  sw        $v0, 0x28($s0)
/* C42AA8 80242CF8 C6200018 */  lwc1      $f0, 0x18($s1)
/* C42AAC 80242CFC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C42AB0 80242D00 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C42AB4 80242D04 E6000018 */  swc1      $f0, 0x18($s0)
/* C42AB8 80242D08 8C460028 */  lw        $a2, 0x28($v0)
/* C42ABC 80242D0C 0C00A720 */  jal       atan2
/* C42AC0 80242D10 8C470030 */   lw       $a3, 0x30($v0)
/* C42AC4 80242D14 46000506 */  mov.s     $f20, $f0
/* C42AC8 80242D18 C60C000C */  lwc1      $f12, 0xc($s0)
/* C42ACC 80242D1C 0C00A70A */  jal       get_clamped_angle_diff
/* C42AD0 80242D20 4600A386 */   mov.s    $f14, $f20
/* C42AD4 80242D24 46000086 */  mov.s     $f2, $f0
/* C42AD8 80242D28 8E22001C */  lw        $v0, 0x1c($s1)
/* C42ADC 80242D2C 46001005 */  abs.s     $f0, $f2
/* C42AE0 80242D30 44822000 */  mtc1      $v0, $f4
/* C42AE4 80242D34 00000000 */  nop
/* C42AE8 80242D38 46802120 */  cvt.s.w   $f4, $f4
/* C42AEC 80242D3C 4600203C */  c.lt.s    $f4, $f0
/* C42AF0 80242D40 00000000 */  nop
/* C42AF4 80242D44 4500000D */  bc1f      .L80242D7C
/* C42AF8 80242D48 00000000 */   nop
/* C42AFC 80242D4C 44800000 */  mtc1      $zero, $f0
/* C42B00 80242D50 C614000C */  lwc1      $f20, 0xc($s0)
/* C42B04 80242D54 4600103C */  c.lt.s    $f2, $f0
/* C42B08 80242D58 00000000 */  nop
/* C42B0C 80242D5C 45000006 */  bc1f      .L80242D78
/* C42B10 80242D60 00021023 */   negu     $v0, $v0
/* C42B14 80242D64 44820000 */  mtc1      $v0, $f0
/* C42B18 80242D68 00000000 */  nop
/* C42B1C 80242D6C 46800020 */  cvt.s.w   $f0, $f0
/* C42B20 80242D70 08090B5F */  j         .L80242D7C
/* C42B24 80242D74 4600A500 */   add.s    $f20, $f20, $f0
.L80242D78:
/* C42B28 80242D78 4604A500 */  add.s     $f20, $f20, $f4
.L80242D7C:
/* C42B2C 80242D7C 0C00A6C9 */  jal       clamp_angle
/* C42B30 80242D80 4600A306 */   mov.s    $f12, $f20
/* C42B34 80242D84 2402000D */  addiu     $v0, $zero, 0xd
/* C42B38 80242D88 E600000C */  swc1      $f0, 0xc($s0)
/* C42B3C 80242D8C AE620070 */  sw        $v0, 0x70($s3)
.L80242D90:
/* C42B40 80242D90 8FBF0020 */  lw        $ra, 0x20($sp)
/* C42B44 80242D94 8FB3001C */  lw        $s3, 0x1c($sp)
/* C42B48 80242D98 8FB20018 */  lw        $s2, 0x18($sp)
/* C42B4C 80242D9C 8FB10014 */  lw        $s1, 0x14($sp)
/* C42B50 80242DA0 8FB00010 */  lw        $s0, 0x10($sp)
/* C42B54 80242DA4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C42B58 80242DA8 03E00008 */  jr        $ra
/* C42B5C 80242DAC 27BD0030 */   addiu    $sp, $sp, 0x30
