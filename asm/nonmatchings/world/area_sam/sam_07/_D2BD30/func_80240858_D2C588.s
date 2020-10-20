.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240858_D2C588
/* D2C588 80240858 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D2C58C 8024085C AFBF0024 */  sw        $ra, 0x24($sp)
/* D2C590 80240860 AFB40020 */  sw        $s4, 0x20($sp)
/* D2C594 80240864 AFB3001C */  sw        $s3, 0x1c($sp)
/* D2C598 80240868 AFB20018 */  sw        $s2, 0x18($sp)
/* D2C59C 8024086C AFB10014 */  sw        $s1, 0x14($sp)
/* D2C5A0 80240870 AFB00010 */  sw        $s0, 0x10($sp)
/* D2C5A4 80240874 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D2C5A8 80240878 8C900148 */  lw        $s0, 0x148($a0)
/* D2C5AC 8024087C 86040008 */  lh        $a0, 8($s0)
/* D2C5B0 80240880 0C00EABB */  jal       get_npc_unsafe
/* D2C5B4 80240884 24110001 */   addiu    $s1, $zero, 1
/* D2C5B8 80240888 86040008 */  lh        $a0, 8($s0)
/* D2C5BC 8024088C 0040802D */  daddu     $s0, $v0, $zero
/* D2C5C0 80240890 3C05800B */  lui       $a1, %hi(gCameras)
/* D2C5C4 80240894 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D2C5C8 80240898 3C03800A */  lui       $v1, 0x800a
/* D2C5CC 8024089C 8463A634 */  lh        $v1, -0x59cc($v1)
/* D2C5D0 802408A0 00912021 */  addu      $a0, $a0, $s1
/* D2C5D4 802408A4 00031080 */  sll       $v0, $v1, 2
/* D2C5D8 802408A8 00431021 */  addu      $v0, $v0, $v1
/* D2C5DC 802408AC 00021080 */  sll       $v0, $v0, 2
/* D2C5E0 802408B0 00431023 */  subu      $v0, $v0, $v1
/* D2C5E4 802408B4 000218C0 */  sll       $v1, $v0, 3
/* D2C5E8 802408B8 00431021 */  addu      $v0, $v0, $v1
/* D2C5EC 802408BC 000210C0 */  sll       $v0, $v0, 3
/* D2C5F0 802408C0 0C00FB3A */  jal       get_enemy
/* D2C5F4 802408C4 00459021 */   addu     $s2, $v0, $a1
/* D2C5F8 802408C8 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* D2C5FC 802408CC 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* D2C600 802408D0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D2C604 802408D4 8E830000 */  lw        $v1, ($s4)
/* D2C608 802408D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D2C60C 802408DC 8C660028 */  lw        $a2, 0x28($v1)
/* D2C610 802408E0 8C670030 */  lw        $a3, 0x30($v1)
/* D2C614 802408E4 0C00A7B5 */  jal       dist2D
/* D2C618 802408E8 0040982D */   daddu    $s3, $v0, $zero
/* D2C61C 802408EC C6620074 */  lwc1      $f2, 0x74($s3)
/* D2C620 802408F0 468010A0 */  cvt.s.w   $f2, $f2
/* D2C624 802408F4 4600103C */  c.lt.s    $f2, $f0
/* D2C628 802408F8 00000000 */  nop       
/* D2C62C 802408FC 45030001 */  bc1tl     .L80240904
/* D2C630 80240900 0000882D */   daddu    $s1, $zero, $zero
.L80240904:
/* D2C634 80240904 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D2C638 80240908 C60E000C */  lwc1      $f14, 0xc($s0)
/* D2C63C 8024090C 3C014387 */  lui       $at, 0x4387
/* D2C640 80240910 4481A000 */  mtc1      $at, $f20
/* D2C644 80240914 0C00A70A */  jal       get_clamped_angle_diff
/* D2C648 80240918 00000000 */   nop      
/* D2C64C 8024091C 0C00A6C9 */  jal       clamp_angle
/* D2C650 80240920 46000306 */   mov.s    $f12, $f0
/* D2C654 80240924 3C018024 */  lui       $at, 0x8024
/* D2C658 80240928 D4223D80 */  ldc1      $f2, 0x3d80($at)
/* D2C65C 8024092C 46000021 */  cvt.d.s   $f0, $f0
/* D2C660 80240930 4622003C */  c.lt.d    $f0, $f2
/* D2C664 80240934 00000000 */  nop       
/* D2C668 80240938 45000003 */  bc1f      .L80240948
/* D2C66C 8024093C 00000000 */   nop      
/* D2C670 80240940 3C0142B4 */  lui       $at, 0x42b4
/* D2C674 80240944 4481A000 */  mtc1      $at, $f20
.L80240948:
/* D2C678 80240948 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D2C67C 8024094C 8E820000 */  lw        $v0, ($s4)
/* D2C680 80240950 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D2C684 80240954 8C460028 */  lw        $a2, 0x28($v0)
/* D2C688 80240958 0C00A720 */  jal       atan2
/* D2C68C 8024095C 8C470030 */   lw       $a3, 0x30($v0)
/* D2C690 80240960 4600A306 */  mov.s     $f12, $f20
/* D2C694 80240964 0C00A70A */  jal       get_clamped_angle_diff
/* D2C698 80240968 46000386 */   mov.s    $f14, $f0
/* D2C69C 8024096C C6620078 */  lwc1      $f2, 0x78($s3)
/* D2C6A0 80240970 468010A0 */  cvt.s.w   $f2, $f2
/* D2C6A4 80240974 46000005 */  abs.s     $f0, $f0
/* D2C6A8 80240978 4600103C */  c.lt.s    $f2, $f0
/* D2C6AC 8024097C 00000000 */  nop       
/* D2C6B0 80240980 45030001 */  bc1tl     .L80240988
/* D2C6B4 80240984 0000882D */   daddu    $s1, $zero, $zero
.L80240988:
/* D2C6B8 80240988 8E820000 */  lw        $v0, ($s4)
/* D2C6BC 8024098C C600003C */  lwc1      $f0, 0x3c($s0)
/* D2C6C0 80240990 C442002C */  lwc1      $f2, 0x2c($v0)
/* D2C6C4 80240994 860200A8 */  lh        $v0, 0xa8($s0)
/* D2C6C8 80240998 46020001 */  sub.s     $f0, $f0, $f2
/* D2C6CC 8024099C 44821000 */  mtc1      $v0, $f2
/* D2C6D0 802409A0 00000000 */  nop       
/* D2C6D4 802409A4 468010A1 */  cvt.d.w   $f2, $f2
/* D2C6D8 802409A8 46221080 */  add.d     $f2, $f2, $f2
/* D2C6DC 802409AC 46000005 */  abs.s     $f0, $f0
/* D2C6E0 802409B0 46000021 */  cvt.d.s   $f0, $f0
/* D2C6E4 802409B4 4620103E */  c.le.d    $f2, $f0
/* D2C6E8 802409B8 00000000 */  nop       
/* D2C6EC 802409BC 45030001 */  bc1tl     .L802409C4
/* D2C6F0 802409C0 0000882D */   daddu    $s1, $zero, $zero
.L802409C4:
/* D2C6F4 802409C4 3C038011 */  lui       $v1, 0x8011
/* D2C6F8 802409C8 8063EBB3 */  lb        $v1, -0x144d($v1)
/* D2C6FC 802409CC 24020009 */  addiu     $v0, $zero, 9
/* D2C700 802409D0 50620001 */  beql      $v1, $v0, .L802409D8
/* D2C704 802409D4 0000882D */   daddu    $s1, $zero, $zero
.L802409D8:
/* D2C708 802409D8 24020007 */  addiu     $v0, $zero, 7
/* D2C70C 802409DC 50620001 */  beql      $v1, $v0, .L802409E4
/* D2C710 802409E0 0000882D */   daddu    $s1, $zero, $zero
.L802409E4:
/* D2C714 802409E4 0220102D */  daddu     $v0, $s1, $zero
/* D2C718 802409E8 8FBF0024 */  lw        $ra, 0x24($sp)
/* D2C71C 802409EC 8FB40020 */  lw        $s4, 0x20($sp)
/* D2C720 802409F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* D2C724 802409F4 8FB20018 */  lw        $s2, 0x18($sp)
/* D2C728 802409F8 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C72C 802409FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C730 80240A00 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D2C734 80240A04 03E00008 */  jr        $ra
/* D2C738 80240A08 27BD0030 */   addiu    $sp, $sp, 0x30
