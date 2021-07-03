.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243650_8A5A20
.double 0.8

.section .text

glabel func_802409DC_8A2DAC
/* 8A2DAC 802409DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8A2DB0 802409E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8A2DB4 802409E4 0080982D */  daddu     $s3, $a0, $zero
/* 8A2DB8 802409E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8A2DBC 802409EC AFB20018 */  sw        $s2, 0x18($sp)
/* 8A2DC0 802409F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A2DC4 802409F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A2DC8 802409F8 8E710148 */  lw        $s1, 0x148($s3)
/* 8A2DCC 802409FC 86240008 */  lh        $a0, 8($s1)
/* 8A2DD0 80240A00 0C00EABB */  jal       get_npc_unsafe
/* 8A2DD4 80240A04 00A0902D */   daddu    $s2, $a1, $zero
/* 8A2DD8 80240A08 0040802D */  daddu     $s0, $v0, $zero
/* 8A2DDC 80240A0C 8602008E */  lh        $v0, 0x8e($s0)
/* 8A2DE0 80240A10 9603008E */  lhu       $v1, 0x8e($s0)
/* 8A2DE4 80240A14 18400005 */  blez      $v0, .L80240A2C
/* 8A2DE8 80240A18 2462FFFF */   addiu    $v0, $v1, -1
/* 8A2DEC 80240A1C A602008E */  sh        $v0, 0x8e($s0)
/* 8A2DF0 80240A20 00021400 */  sll       $v0, $v0, 0x10
/* 8A2DF4 80240A24 1C400033 */  bgtz      $v0, .L80240AF4
/* 8A2DF8 80240A28 00000000 */   nop
.L80240A2C:
/* 8A2DFC 80240A2C 8602008C */  lh        $v0, 0x8c($s0)
/* 8A2E00 80240A30 14400030 */  bnez      $v0, .L80240AF4
/* 8A2E04 80240A34 00000000 */   nop
/* 8A2E08 80240A38 8E2200CC */  lw        $v0, 0xcc($s1)
/* 8A2E0C 80240A3C 8C420024 */  lw        $v0, 0x24($v0)
/* 8A2E10 80240A40 AE020028 */  sw        $v0, 0x28($s0)
/* 8A2E14 80240A44 C6400018 */  lwc1      $f0, 0x18($s2)
/* 8A2E18 80240A48 E6000018 */  swc1      $f0, 0x18($s0)
/* 8A2E1C 80240A4C 8E230088 */  lw        $v1, 0x88($s1)
/* 8A2E20 80240A50 24020005 */  addiu     $v0, $zero, 5
/* 8A2E24 80240A54 10620005 */  beq       $v1, $v0, .L80240A6C
/* 8A2E28 80240A58 00000000 */   nop
/* 8A2E2C 80240A5C 10600003 */  beqz      $v1, .L80240A6C
/* 8A2E30 80240A60 24020001 */   addiu    $v0, $zero, 1
/* 8A2E34 80240A64 14620006 */  bne       $v1, $v0, .L80240A80
/* 8A2E38 80240A68 00000000 */   nop
.L80240A6C:
/* 8A2E3C 80240A6C 8E220084 */  lw        $v0, 0x84($s1)
/* 8A2E40 80240A70 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8A2E44 80240A74 00431021 */  addu      $v0, $v0, $v1
/* 8A2E48 80240A78 00021043 */  sra       $v0, $v0, 1
/* 8A2E4C 80240A7C A60200A8 */  sh        $v0, 0xa8($s0)
.L80240A80:
/* 8A2E50 80240A80 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8A2E54 80240A84 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8A2E58 80240A88 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8A2E5C 80240A8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8A2E60 80240A90 8C460028 */  lw        $a2, 0x28($v0)
/* 8A2E64 80240A94 0C00A7B5 */  jal       dist2D
/* 8A2E68 80240A98 8C470030 */   lw       $a3, 0x30($v0)
/* 8A2E6C 80240A9C C6020018 */  lwc1      $f2, 0x18($s0)
/* 8A2E70 80240AA0 46020003 */  div.s     $f0, $f0, $f2
/* 8A2E74 80240AA4 3C018024 */  lui       $at, %hi(D_80243650_8A5A20)
/* 8A2E78 80240AA8 D4223650 */  ldc1      $f2, %lo(D_80243650_8A5A20)($at)
/* 8A2E7C 80240AAC 46000021 */  cvt.d.s   $f0, $f0
/* 8A2E80 80240AB0 46220000 */  add.d     $f0, $f0, $f2
/* 8A2E84 80240AB4 4620010D */  trunc.w.d $f4, $f0
/* 8A2E88 80240AB8 44022000 */  mfc1      $v0, $f4
/* 8A2E8C 80240ABC 00000000 */  nop
/* 8A2E90 80240AC0 A602008E */  sh        $v0, 0x8e($s0)
/* 8A2E94 80240AC4 00021400 */  sll       $v0, $v0, 0x10
/* 8A2E98 80240AC8 8E230078 */  lw        $v1, 0x78($s1)
/* 8A2E9C 80240ACC 00021403 */  sra       $v0, $v0, 0x10
/* 8A2EA0 80240AD0 0043102A */  slt       $v0, $v0, $v1
/* 8A2EA4 80240AD4 10400003 */  beqz      $v0, .L80240AE4
/* 8A2EA8 80240AD8 00000000 */   nop
/* 8A2EAC 80240ADC 9622007A */  lhu       $v0, 0x7a($s1)
/* 8A2EB0 80240AE0 A602008E */  sh        $v0, 0x8e($s0)
.L80240AE4:
/* 8A2EB4 80240AE4 8602008E */  lh        $v0, 0x8e($s0)
/* 8A2EB8 80240AE8 AE22007C */  sw        $v0, 0x7c($s1)
/* 8A2EBC 80240AEC 2402000E */  addiu     $v0, $zero, 0xe
/* 8A2EC0 80240AF0 AE620070 */  sw        $v0, 0x70($s3)
.L80240AF4:
/* 8A2EC4 80240AF4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8A2EC8 80240AF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8A2ECC 80240AFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A2ED0 80240B00 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A2ED4 80240B04 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A2ED8 80240B08 03E00008 */  jr        $ra
/* 8A2EDC 80240B0C 27BD0028 */   addiu    $sp, $sp, 0x28
