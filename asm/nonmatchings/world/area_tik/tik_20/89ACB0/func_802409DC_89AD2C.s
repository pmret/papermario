.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409DC_89AD2C
/* 89AD2C 802409DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 89AD30 802409E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 89AD34 802409E4 0080982D */  daddu     $s3, $a0, $zero
/* 89AD38 802409E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 89AD3C 802409EC AFB20018 */  sw        $s2, 0x18($sp)
/* 89AD40 802409F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 89AD44 802409F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 89AD48 802409F8 8E710148 */  lw        $s1, 0x148($s3)
/* 89AD4C 802409FC 86240008 */  lh        $a0, 8($s1)
/* 89AD50 80240A00 0C00EABB */  jal       get_npc_unsafe
/* 89AD54 80240A04 00A0902D */   daddu    $s2, $a1, $zero
/* 89AD58 80240A08 0040802D */  daddu     $s0, $v0, $zero
/* 89AD5C 80240A0C 8602008E */  lh        $v0, 0x8e($s0)
/* 89AD60 80240A10 9603008E */  lhu       $v1, 0x8e($s0)
/* 89AD64 80240A14 18400005 */  blez      $v0, .L80240A2C
/* 89AD68 80240A18 2462FFFF */   addiu    $v0, $v1, -1
/* 89AD6C 80240A1C A602008E */  sh        $v0, 0x8e($s0)
/* 89AD70 80240A20 00021400 */  sll       $v0, $v0, 0x10
/* 89AD74 80240A24 1C400033 */  bgtz      $v0, .L80240AF4
/* 89AD78 80240A28 00000000 */   nop      
.L80240A2C:
/* 89AD7C 80240A2C 8602008C */  lh        $v0, 0x8c($s0)
/* 89AD80 80240A30 14400030 */  bnez      $v0, .L80240AF4
/* 89AD84 80240A34 00000000 */   nop      
/* 89AD88 80240A38 8E2200CC */  lw        $v0, 0xcc($s1)
/* 89AD8C 80240A3C 8C420024 */  lw        $v0, 0x24($v0)
/* 89AD90 80240A40 AE020028 */  sw        $v0, 0x28($s0)
/* 89AD94 80240A44 C6400018 */  lwc1      $f0, 0x18($s2)
/* 89AD98 80240A48 E6000018 */  swc1      $f0, 0x18($s0)
/* 89AD9C 80240A4C 8E230088 */  lw        $v1, 0x88($s1)
/* 89ADA0 80240A50 24020005 */  addiu     $v0, $zero, 5
/* 89ADA4 80240A54 10620005 */  beq       $v1, $v0, .L80240A6C
/* 89ADA8 80240A58 00000000 */   nop      
/* 89ADAC 80240A5C 10600003 */  beqz      $v1, .L80240A6C
/* 89ADB0 80240A60 24020001 */   addiu    $v0, $zero, 1
/* 89ADB4 80240A64 14620006 */  bne       $v1, $v0, .L80240A80
/* 89ADB8 80240A68 00000000 */   nop      
.L80240A6C:
/* 89ADBC 80240A6C 8E220084 */  lw        $v0, 0x84($s1)
/* 89ADC0 80240A70 00021FC2 */  srl       $v1, $v0, 0x1f
/* 89ADC4 80240A74 00431021 */  addu      $v0, $v0, $v1
/* 89ADC8 80240A78 00021043 */  sra       $v0, $v0, 1
/* 89ADCC 80240A7C A60200A8 */  sh        $v0, 0xa8($s0)
.L80240A80:
/* 89ADD0 80240A80 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 89ADD4 80240A84 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 89ADD8 80240A88 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 89ADDC 80240A8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 89ADE0 80240A90 8C460028 */  lw        $a2, 0x28($v0)
/* 89ADE4 80240A94 0C00A7B5 */  jal       dist2D
/* 89ADE8 80240A98 8C470030 */   lw       $a3, 0x30($v0)
/* 89ADEC 80240A9C C6020018 */  lwc1      $f2, 0x18($s0)
/* 89ADF0 80240AA0 46020003 */  div.s     $f0, $f0, $f2
/* 89ADF4 80240AA4 3C018024 */  lui       $at, 0x8024
/* 89ADF8 80240AA8 D42233F0 */  ldc1      $f2, 0x33f0($at)
/* 89ADFC 80240AAC 46000021 */  cvt.d.s   $f0, $f0
/* 89AE00 80240AB0 46220000 */  add.d     $f0, $f0, $f2
/* 89AE04 80240AB4 4620010D */  trunc.w.d $f4, $f0
/* 89AE08 80240AB8 44022000 */  mfc1      $v0, $f4
/* 89AE0C 80240ABC 00000000 */  nop       
/* 89AE10 80240AC0 A602008E */  sh        $v0, 0x8e($s0)
/* 89AE14 80240AC4 00021400 */  sll       $v0, $v0, 0x10
/* 89AE18 80240AC8 8E230078 */  lw        $v1, 0x78($s1)
/* 89AE1C 80240ACC 00021403 */  sra       $v0, $v0, 0x10
/* 89AE20 80240AD0 0043102A */  slt       $v0, $v0, $v1
/* 89AE24 80240AD4 10400003 */  beqz      $v0, .L80240AE4
/* 89AE28 80240AD8 00000000 */   nop      
/* 89AE2C 80240ADC 9622007A */  lhu       $v0, 0x7a($s1)
/* 89AE30 80240AE0 A602008E */  sh        $v0, 0x8e($s0)
.L80240AE4:
/* 89AE34 80240AE4 8602008E */  lh        $v0, 0x8e($s0)
/* 89AE38 80240AE8 AE22007C */  sw        $v0, 0x7c($s1)
/* 89AE3C 80240AEC 2402000E */  addiu     $v0, $zero, 0xe
/* 89AE40 80240AF0 AE620070 */  sw        $v0, 0x70($s3)
.L80240AF4:
/* 89AE44 80240AF4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 89AE48 80240AF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 89AE4C 80240AFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 89AE50 80240B00 8FB10014 */  lw        $s1, 0x14($sp)
/* 89AE54 80240B04 8FB00010 */  lw        $s0, 0x10($sp)
/* 89AE58 80240B08 03E00008 */  jr        $ra
/* 89AE5C 80240B0C 27BD0028 */   addiu    $sp, $sp, 0x28
