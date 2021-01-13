.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241098_C40E48
/* C40E48 80241098 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C40E4C 8024109C AFBF0024 */  sw        $ra, 0x24($sp)
/* C40E50 802410A0 AFB40020 */  sw        $s4, 0x20($sp)
/* C40E54 802410A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* C40E58 802410A8 AFB20018 */  sw        $s2, 0x18($sp)
/* C40E5C 802410AC AFB10014 */  sw        $s1, 0x14($sp)
/* C40E60 802410B0 AFB00010 */  sw        $s0, 0x10($sp)
/* C40E64 802410B4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C40E68 802410B8 8C900148 */  lw        $s0, 0x148($a0)
/* C40E6C 802410BC 86040008 */  lh        $a0, 8($s0)
/* C40E70 802410C0 0C00EABB */  jal       get_npc_unsafe
/* C40E74 802410C4 24110001 */   addiu    $s1, $zero, 1
/* C40E78 802410C8 86040008 */  lh        $a0, 8($s0)
/* C40E7C 802410CC 0040802D */  daddu     $s0, $v0, $zero
/* C40E80 802410D0 3C05800B */  lui       $a1, %hi(gCameras)
/* C40E84 802410D4 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* C40E88 802410D8 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C40E8C 802410DC 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C40E90 802410E0 00912021 */  addu      $a0, $a0, $s1
/* C40E94 802410E4 00031080 */  sll       $v0, $v1, 2
/* C40E98 802410E8 00431021 */  addu      $v0, $v0, $v1
/* C40E9C 802410EC 00021080 */  sll       $v0, $v0, 2
/* C40EA0 802410F0 00431023 */  subu      $v0, $v0, $v1
/* C40EA4 802410F4 000218C0 */  sll       $v1, $v0, 3
/* C40EA8 802410F8 00431021 */  addu      $v0, $v0, $v1
/* C40EAC 802410FC 000210C0 */  sll       $v0, $v0, 3
/* C40EB0 80241100 0C00FB3A */  jal       get_enemy
/* C40EB4 80241104 00459021 */   addu     $s2, $v0, $a1
/* C40EB8 80241108 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* C40EBC 8024110C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* C40EC0 80241110 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C40EC4 80241114 8E830000 */  lw        $v1, ($s4)
/* C40EC8 80241118 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C40ECC 8024111C 8C660028 */  lw        $a2, 0x28($v1)
/* C40ED0 80241120 8C670030 */  lw        $a3, 0x30($v1)
/* C40ED4 80241124 0C00A7B5 */  jal       dist2D
/* C40ED8 80241128 0040982D */   daddu    $s3, $v0, $zero
/* C40EDC 8024112C C6620074 */  lwc1      $f2, 0x74($s3)
/* C40EE0 80241130 468010A0 */  cvt.s.w   $f2, $f2
/* C40EE4 80241134 4600103C */  c.lt.s    $f2, $f0
/* C40EE8 80241138 00000000 */  nop
/* C40EEC 8024113C 45030001 */  bc1tl     .L80241144
/* C40EF0 80241140 0000882D */   daddu    $s1, $zero, $zero
.L80241144:
/* C40EF4 80241144 C64C006C */  lwc1      $f12, 0x6c($s2)
/* C40EF8 80241148 C60E000C */  lwc1      $f14, 0xc($s0)
/* C40EFC 8024114C 3C014387 */  lui       $at, 0x4387
/* C40F00 80241150 4481A000 */  mtc1      $at, $f20
/* C40F04 80241154 0C00A70A */  jal       get_clamped_angle_diff
/* C40F08 80241158 00000000 */   nop
/* C40F0C 8024115C 0C00A6C9 */  jal       clamp_angle
/* C40F10 80241160 46000306 */   mov.s    $f12, $f0
/* C40F14 80241164 3C018024 */  lui       $at, %hi(D_80246BA0)
/* C40F18 80241168 D4226BA0 */  ldc1      $f2, %lo(D_80246BA0)($at)
/* C40F1C 8024116C 46000021 */  cvt.d.s   $f0, $f0
/* C40F20 80241170 4622003C */  c.lt.d    $f0, $f2
/* C40F24 80241174 00000000 */  nop
/* C40F28 80241178 45000003 */  bc1f      .L80241188
/* C40F2C 8024117C 00000000 */   nop
/* C40F30 80241180 3C0142B4 */  lui       $at, 0x42b4
/* C40F34 80241184 4481A000 */  mtc1      $at, $f20
.L80241188:
/* C40F38 80241188 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C40F3C 8024118C 8E820000 */  lw        $v0, ($s4)
/* C40F40 80241190 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C40F44 80241194 8C460028 */  lw        $a2, 0x28($v0)
/* C40F48 80241198 0C00A720 */  jal       atan2
/* C40F4C 8024119C 8C470030 */   lw       $a3, 0x30($v0)
/* C40F50 802411A0 4600A306 */  mov.s     $f12, $f20
/* C40F54 802411A4 0C00A70A */  jal       get_clamped_angle_diff
/* C40F58 802411A8 46000386 */   mov.s    $f14, $f0
/* C40F5C 802411AC C6620078 */  lwc1      $f2, 0x78($s3)
/* C40F60 802411B0 468010A0 */  cvt.s.w   $f2, $f2
/* C40F64 802411B4 46000005 */  abs.s     $f0, $f0
/* C40F68 802411B8 4600103C */  c.lt.s    $f2, $f0
/* C40F6C 802411BC 00000000 */  nop
/* C40F70 802411C0 45030001 */  bc1tl     .L802411C8
/* C40F74 802411C4 0000882D */   daddu    $s1, $zero, $zero
.L802411C8:
/* C40F78 802411C8 8E820000 */  lw        $v0, ($s4)
/* C40F7C 802411CC C600003C */  lwc1      $f0, 0x3c($s0)
/* C40F80 802411D0 C442002C */  lwc1      $f2, 0x2c($v0)
/* C40F84 802411D4 860200A8 */  lh        $v0, 0xa8($s0)
/* C40F88 802411D8 46020001 */  sub.s     $f0, $f0, $f2
/* C40F8C 802411DC 44821000 */  mtc1      $v0, $f2
/* C40F90 802411E0 00000000 */  nop
/* C40F94 802411E4 468010A1 */  cvt.d.w   $f2, $f2
/* C40F98 802411E8 46221080 */  add.d     $f2, $f2, $f2
/* C40F9C 802411EC 46000005 */  abs.s     $f0, $f0
/* C40FA0 802411F0 46000021 */  cvt.d.s   $f0, $f0
/* C40FA4 802411F4 4620103E */  c.le.d    $f2, $f0
/* C40FA8 802411F8 00000000 */  nop
/* C40FAC 802411FC 45030001 */  bc1tl     .L80241204
/* C40FB0 80241200 0000882D */   daddu    $s1, $zero, $zero
.L80241204:
/* C40FB4 80241204 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C40FB8 80241208 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C40FBC 8024120C 24020009 */  addiu     $v0, $zero, 9
/* C40FC0 80241210 50620001 */  beql      $v1, $v0, .L80241218
/* C40FC4 80241214 0000882D */   daddu    $s1, $zero, $zero
.L80241218:
/* C40FC8 80241218 24020007 */  addiu     $v0, $zero, 7
/* C40FCC 8024121C 50620001 */  beql      $v1, $v0, .L80241224
/* C40FD0 80241220 0000882D */   daddu    $s1, $zero, $zero
.L80241224:
/* C40FD4 80241224 0220102D */  daddu     $v0, $s1, $zero
/* C40FD8 80241228 8FBF0024 */  lw        $ra, 0x24($sp)
/* C40FDC 8024122C 8FB40020 */  lw        $s4, 0x20($sp)
/* C40FE0 80241230 8FB3001C */  lw        $s3, 0x1c($sp)
/* C40FE4 80241234 8FB20018 */  lw        $s2, 0x18($sp)
/* C40FE8 80241238 8FB10014 */  lw        $s1, 0x14($sp)
/* C40FEC 8024123C 8FB00010 */  lw        $s0, 0x10($sp)
/* C40FF0 80241240 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C40FF4 80241244 03E00008 */  jr        $ra
/* C40FF8 80241248 27BD0030 */   addiu    $sp, $sp, 0x30
