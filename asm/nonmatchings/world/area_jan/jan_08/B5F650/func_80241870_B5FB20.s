.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241870_B5FB20
/* B5FB20 80241870 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5FB24 80241874 AFBF0024 */  sw        $ra, 0x24($sp)
/* B5FB28 80241878 AFB40020 */  sw        $s4, 0x20($sp)
/* B5FB2C 8024187C AFB3001C */  sw        $s3, 0x1c($sp)
/* B5FB30 80241880 AFB20018 */  sw        $s2, 0x18($sp)
/* B5FB34 80241884 AFB10014 */  sw        $s1, 0x14($sp)
/* B5FB38 80241888 AFB00010 */  sw        $s0, 0x10($sp)
/* B5FB3C 8024188C F7B40028 */  sdc1      $f20, 0x28($sp)
/* B5FB40 80241890 8C900148 */  lw        $s0, 0x148($a0)
/* B5FB44 80241894 86040008 */  lh        $a0, 8($s0)
/* B5FB48 80241898 0C00EABB */  jal       get_npc_unsafe
/* B5FB4C 8024189C 24110001 */   addiu    $s1, $zero, 1
/* B5FB50 802418A0 86040008 */  lh        $a0, 8($s0)
/* B5FB54 802418A4 0040802D */  daddu     $s0, $v0, $zero
/* B5FB58 802418A8 3C05800B */  lui       $a1, %hi(gCameras)
/* B5FB5C 802418AC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B5FB60 802418B0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B5FB64 802418B4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B5FB68 802418B8 00912021 */  addu      $a0, $a0, $s1
/* B5FB6C 802418BC 00031080 */  sll       $v0, $v1, 2
/* B5FB70 802418C0 00431021 */  addu      $v0, $v0, $v1
/* B5FB74 802418C4 00021080 */  sll       $v0, $v0, 2
/* B5FB78 802418C8 00431023 */  subu      $v0, $v0, $v1
/* B5FB7C 802418CC 000218C0 */  sll       $v1, $v0, 3
/* B5FB80 802418D0 00431021 */  addu      $v0, $v0, $v1
/* B5FB84 802418D4 000210C0 */  sll       $v0, $v0, 3
/* B5FB88 802418D8 0C00FB3A */  jal       get_enemy
/* B5FB8C 802418DC 00459021 */   addu     $s2, $v0, $a1
/* B5FB90 802418E0 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B5FB94 802418E4 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B5FB98 802418E8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B5FB9C 802418EC 8E830000 */  lw        $v1, ($s4)
/* B5FBA0 802418F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B5FBA4 802418F4 8C660028 */  lw        $a2, 0x28($v1)
/* B5FBA8 802418F8 8C670030 */  lw        $a3, 0x30($v1)
/* B5FBAC 802418FC 0C00A7B5 */  jal       dist2D
/* B5FBB0 80241900 0040982D */   daddu    $s3, $v0, $zero
/* B5FBB4 80241904 C6620074 */  lwc1      $f2, 0x74($s3)
/* B5FBB8 80241908 468010A0 */  cvt.s.w   $f2, $f2
/* B5FBBC 8024190C 4600103C */  c.lt.s    $f2, $f0
/* B5FBC0 80241910 00000000 */  nop
/* B5FBC4 80241914 45030001 */  bc1tl     .L8024191C
/* B5FBC8 80241918 0000882D */   daddu    $s1, $zero, $zero
.L8024191C:
/* B5FBCC 8024191C C64C006C */  lwc1      $f12, 0x6c($s2)
/* B5FBD0 80241920 C60E000C */  lwc1      $f14, 0xc($s0)
/* B5FBD4 80241924 3C014387 */  lui       $at, 0x4387
/* B5FBD8 80241928 4481A000 */  mtc1      $at, $f20
/* B5FBDC 8024192C 0C00A70A */  jal       get_clamped_angle_diff
/* B5FBE0 80241930 00000000 */   nop
/* B5FBE4 80241934 0C00A6C9 */  jal       clamp_angle
/* B5FBE8 80241938 46000306 */   mov.s    $f12, $f0
/* B5FBEC 8024193C 3C018024 */  lui       $at, %hi(D_802474D8_B65788)
/* B5FBF0 80241940 D42274D8 */  ldc1      $f2, %lo(D_802474D8_B65788)($at)
/* B5FBF4 80241944 46000021 */  cvt.d.s   $f0, $f0
/* B5FBF8 80241948 4622003C */  c.lt.d    $f0, $f2
/* B5FBFC 8024194C 00000000 */  nop
/* B5FC00 80241950 45000003 */  bc1f      .L80241960
/* B5FC04 80241954 00000000 */   nop
/* B5FC08 80241958 3C0142B4 */  lui       $at, 0x42b4
/* B5FC0C 8024195C 4481A000 */  mtc1      $at, $f20
.L80241960:
/* B5FC10 80241960 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B5FC14 80241964 8E820000 */  lw        $v0, ($s4)
/* B5FC18 80241968 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B5FC1C 8024196C 8C460028 */  lw        $a2, 0x28($v0)
/* B5FC20 80241970 0C00A720 */  jal       atan2
/* B5FC24 80241974 8C470030 */   lw       $a3, 0x30($v0)
/* B5FC28 80241978 4600A306 */  mov.s     $f12, $f20
/* B5FC2C 8024197C 0C00A70A */  jal       get_clamped_angle_diff
/* B5FC30 80241980 46000386 */   mov.s    $f14, $f0
/* B5FC34 80241984 C6620078 */  lwc1      $f2, 0x78($s3)
/* B5FC38 80241988 468010A0 */  cvt.s.w   $f2, $f2
/* B5FC3C 8024198C 46000005 */  abs.s     $f0, $f0
/* B5FC40 80241990 4600103C */  c.lt.s    $f2, $f0
/* B5FC44 80241994 00000000 */  nop
/* B5FC48 80241998 45030001 */  bc1tl     .L802419A0
/* B5FC4C 8024199C 0000882D */   daddu    $s1, $zero, $zero
.L802419A0:
/* B5FC50 802419A0 8E820000 */  lw        $v0, ($s4)
/* B5FC54 802419A4 C600003C */  lwc1      $f0, 0x3c($s0)
/* B5FC58 802419A8 C442002C */  lwc1      $f2, 0x2c($v0)
/* B5FC5C 802419AC 860200A8 */  lh        $v0, 0xa8($s0)
/* B5FC60 802419B0 46020001 */  sub.s     $f0, $f0, $f2
/* B5FC64 802419B4 44821000 */  mtc1      $v0, $f2
/* B5FC68 802419B8 00000000 */  nop
/* B5FC6C 802419BC 468010A1 */  cvt.d.w   $f2, $f2
/* B5FC70 802419C0 46221080 */  add.d     $f2, $f2, $f2
/* B5FC74 802419C4 46000005 */  abs.s     $f0, $f0
/* B5FC78 802419C8 46000021 */  cvt.d.s   $f0, $f0
/* B5FC7C 802419CC 4620103E */  c.le.d    $f2, $f0
/* B5FC80 802419D0 00000000 */  nop
/* B5FC84 802419D4 45030001 */  bc1tl     .L802419DC
/* B5FC88 802419D8 0000882D */   daddu    $s1, $zero, $zero
.L802419DC:
/* B5FC8C 802419DC 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* B5FC90 802419E0 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* B5FC94 802419E4 24020009 */  addiu     $v0, $zero, 9
/* B5FC98 802419E8 50620001 */  beql      $v1, $v0, .L802419F0
/* B5FC9C 802419EC 0000882D */   daddu    $s1, $zero, $zero
.L802419F0:
/* B5FCA0 802419F0 24020007 */  addiu     $v0, $zero, 7
/* B5FCA4 802419F4 50620001 */  beql      $v1, $v0, .L802419FC
/* B5FCA8 802419F8 0000882D */   daddu    $s1, $zero, $zero
.L802419FC:
/* B5FCAC 802419FC 0220102D */  daddu     $v0, $s1, $zero
/* B5FCB0 80241A00 8FBF0024 */  lw        $ra, 0x24($sp)
/* B5FCB4 80241A04 8FB40020 */  lw        $s4, 0x20($sp)
/* B5FCB8 80241A08 8FB3001C */  lw        $s3, 0x1c($sp)
/* B5FCBC 80241A0C 8FB20018 */  lw        $s2, 0x18($sp)
/* B5FCC0 80241A10 8FB10014 */  lw        $s1, 0x14($sp)
/* B5FCC4 80241A14 8FB00010 */  lw        $s0, 0x10($sp)
/* B5FCC8 80241A18 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B5FCCC 80241A1C 03E00008 */  jr        $ra
/* B5FCD0 80241A20 27BD0030 */   addiu    $sp, $sp, 0x30
