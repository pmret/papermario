.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408DC_B7398C
/* B7398C 802408DC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B73990 802408E0 AFBF0024 */  sw        $ra, 0x24($sp)
/* B73994 802408E4 AFB40020 */  sw        $s4, 0x20($sp)
/* B73998 802408E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* B7399C 802408EC AFB20018 */  sw        $s2, 0x18($sp)
/* B739A0 802408F0 AFB10014 */  sw        $s1, 0x14($sp)
/* B739A4 802408F4 AFB00010 */  sw        $s0, 0x10($sp)
/* B739A8 802408F8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B739AC 802408FC 8C900148 */  lw        $s0, 0x148($a0)
/* B739B0 80240900 86040008 */  lh        $a0, 8($s0)
/* B739B4 80240904 0C00EABB */  jal       get_npc_unsafe
/* B739B8 80240908 24110001 */   addiu    $s1, $zero, 1
/* B739BC 8024090C 86040008 */  lh        $a0, 8($s0)
/* B739C0 80240910 0040802D */  daddu     $s0, $v0, $zero
/* B739C4 80240914 3C05800B */  lui       $a1, %hi(gCameras)
/* B739C8 80240918 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B739CC 8024091C 3C03800A */  lui       $v1, 0x800a
/* B739D0 80240920 8463A634 */  lh        $v1, -0x59cc($v1)
/* B739D4 80240924 00912021 */  addu      $a0, $a0, $s1
/* B739D8 80240928 00031080 */  sll       $v0, $v1, 2
/* B739DC 8024092C 00431021 */  addu      $v0, $v0, $v1
/* B739E0 80240930 00021080 */  sll       $v0, $v0, 2
/* B739E4 80240934 00431023 */  subu      $v0, $v0, $v1
/* B739E8 80240938 000218C0 */  sll       $v1, $v0, 3
/* B739EC 8024093C 00431021 */  addu      $v0, $v0, $v1
/* B739F0 80240940 000210C0 */  sll       $v0, $v0, 3
/* B739F4 80240944 0C00FB3A */  jal       get_enemy
/* B739F8 80240948 00459021 */   addu     $s2, $v0, $a1
/* B739FC 8024094C 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B73A00 80240950 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B73A04 80240954 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B73A08 80240958 8E830000 */  lw        $v1, ($s4)
/* B73A0C 8024095C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B73A10 80240960 8C660028 */  lw        $a2, 0x28($v1)
/* B73A14 80240964 8C670030 */  lw        $a3, 0x30($v1)
/* B73A18 80240968 0C00A7B5 */  jal       dist2D
/* B73A1C 8024096C 0040982D */   daddu    $s3, $v0, $zero
/* B73A20 80240970 C6620074 */  lwc1      $f2, 0x74($s3)
/* B73A24 80240974 468010A0 */  cvt.s.w   $f2, $f2
/* B73A28 80240978 4600103C */  c.lt.s    $f2, $f0
/* B73A2C 8024097C 00000000 */  nop       
/* B73A30 80240980 45030001 */  bc1tl     .L80240988
/* B73A34 80240984 0000882D */   daddu    $s1, $zero, $zero
.L80240988:
/* B73A38 80240988 C64C006C */  lwc1      $f12, 0x6c($s2)
/* B73A3C 8024098C C60E000C */  lwc1      $f14, 0xc($s0)
/* B73A40 80240990 3C014387 */  lui       $at, 0x4387
/* B73A44 80240994 4481A000 */  mtc1      $at, $f20
/* B73A48 80240998 0C00A70A */  jal       get_clamped_angle_diff
/* B73A4C 8024099C 00000000 */   nop      
/* B73A50 802409A0 0C00A6C9 */  jal       clamp_angle
/* B73A54 802409A4 46000306 */   mov.s    $f12, $f0
/* B73A58 802409A8 3C018024 */  lui       $at, 0x8024
/* B73A5C 802409AC D42233D8 */  ldc1      $f2, 0x33d8($at)
/* B73A60 802409B0 46000021 */  cvt.d.s   $f0, $f0
/* B73A64 802409B4 4622003C */  c.lt.d    $f0, $f2
/* B73A68 802409B8 00000000 */  nop       
/* B73A6C 802409BC 45000003 */  bc1f      .L802409CC
/* B73A70 802409C0 00000000 */   nop      
/* B73A74 802409C4 3C0142B4 */  lui       $at, 0x42b4
/* B73A78 802409C8 4481A000 */  mtc1      $at, $f20
.L802409CC:
/* B73A7C 802409CC C60C0038 */  lwc1      $f12, 0x38($s0)
/* B73A80 802409D0 8E820000 */  lw        $v0, ($s4)
/* B73A84 802409D4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B73A88 802409D8 8C460028 */  lw        $a2, 0x28($v0)
/* B73A8C 802409DC 0C00A720 */  jal       atan2
/* B73A90 802409E0 8C470030 */   lw       $a3, 0x30($v0)
/* B73A94 802409E4 4600A306 */  mov.s     $f12, $f20
/* B73A98 802409E8 0C00A70A */  jal       get_clamped_angle_diff
/* B73A9C 802409EC 46000386 */   mov.s    $f14, $f0
/* B73AA0 802409F0 C6620078 */  lwc1      $f2, 0x78($s3)
/* B73AA4 802409F4 468010A0 */  cvt.s.w   $f2, $f2
/* B73AA8 802409F8 46000005 */  abs.s     $f0, $f0
/* B73AAC 802409FC 4600103C */  c.lt.s    $f2, $f0
/* B73AB0 80240A00 00000000 */  nop       
/* B73AB4 80240A04 45030001 */  bc1tl     .L80240A0C
/* B73AB8 80240A08 0000882D */   daddu    $s1, $zero, $zero
.L80240A0C:
/* B73ABC 80240A0C 8E820000 */  lw        $v0, ($s4)
/* B73AC0 80240A10 C600003C */  lwc1      $f0, 0x3c($s0)
/* B73AC4 80240A14 C442002C */  lwc1      $f2, 0x2c($v0)
/* B73AC8 80240A18 860200A8 */  lh        $v0, 0xa8($s0)
/* B73ACC 80240A1C 46020001 */  sub.s     $f0, $f0, $f2
/* B73AD0 80240A20 44821000 */  mtc1      $v0, $f2
/* B73AD4 80240A24 00000000 */  nop       
/* B73AD8 80240A28 468010A1 */  cvt.d.w   $f2, $f2
/* B73ADC 80240A2C 46221080 */  add.d     $f2, $f2, $f2
/* B73AE0 80240A30 46000005 */  abs.s     $f0, $f0
/* B73AE4 80240A34 46000021 */  cvt.d.s   $f0, $f0
/* B73AE8 80240A38 4620103E */  c.le.d    $f2, $f0
/* B73AEC 80240A3C 00000000 */  nop       
/* B73AF0 80240A40 45030001 */  bc1tl     .L80240A48
/* B73AF4 80240A44 0000882D */   daddu    $s1, $zero, $zero
.L80240A48:
/* B73AF8 80240A48 3C038011 */  lui       $v1, 0x8011
/* B73AFC 80240A4C 8063EBB3 */  lb        $v1, -0x144d($v1)
/* B73B00 80240A50 24020009 */  addiu     $v0, $zero, 9
/* B73B04 80240A54 50620001 */  beql      $v1, $v0, .L80240A5C
/* B73B08 80240A58 0000882D */   daddu    $s1, $zero, $zero
.L80240A5C:
/* B73B0C 80240A5C 24020007 */  addiu     $v0, $zero, 7
/* B73B10 80240A60 50620001 */  beql      $v1, $v0, .L80240A68
/* B73B14 80240A64 0000882D */   daddu    $s1, $zero, $zero
.L80240A68:
/* B73B18 80240A68 0220102D */  daddu     $v0, $s1, $zero
/* B73B1C 80240A6C 8FBF0024 */  lw        $ra, 0x24($sp)
/* B73B20 80240A70 8FB40020 */  lw        $s4, 0x20($sp)
/* B73B24 80240A74 8FB3001C */  lw        $s3, 0x1c($sp)
/* B73B28 80240A78 8FB20018 */  lw        $s2, 0x18($sp)
/* B73B2C 80240A7C 8FB10014 */  lw        $s1, 0x14($sp)
/* B73B30 80240A80 8FB00010 */  lw        $s0, 0x10($sp)
/* B73B34 80240A84 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B73B38 80240A88 03E00008 */  jr        $ra
/* B73B3C 80240A8C 27BD0030 */   addiu    $sp, $sp, 0x30
