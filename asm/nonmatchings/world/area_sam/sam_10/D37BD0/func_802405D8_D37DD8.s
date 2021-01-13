.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D8_D37DD8
/* D37DD8 802405D8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D37DDC 802405DC AFBF0024 */  sw        $ra, 0x24($sp)
/* D37DE0 802405E0 AFB40020 */  sw        $s4, 0x20($sp)
/* D37DE4 802405E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* D37DE8 802405E8 AFB20018 */  sw        $s2, 0x18($sp)
/* D37DEC 802405EC AFB10014 */  sw        $s1, 0x14($sp)
/* D37DF0 802405F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D37DF4 802405F4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D37DF8 802405F8 8C900148 */  lw        $s0, 0x148($a0)
/* D37DFC 802405FC 86040008 */  lh        $a0, 8($s0)
/* D37E00 80240600 0C00EABB */  jal       get_npc_unsafe
/* D37E04 80240604 24110001 */   addiu    $s1, $zero, 1
/* D37E08 80240608 86040008 */  lh        $a0, 8($s0)
/* D37E0C 8024060C 0040802D */  daddu     $s0, $v0, $zero
/* D37E10 80240610 3C05800B */  lui       $a1, %hi(gCameras)
/* D37E14 80240614 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D37E18 80240618 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D37E1C 8024061C 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D37E20 80240620 00912021 */  addu      $a0, $a0, $s1
/* D37E24 80240624 00031080 */  sll       $v0, $v1, 2
/* D37E28 80240628 00431021 */  addu      $v0, $v0, $v1
/* D37E2C 8024062C 00021080 */  sll       $v0, $v0, 2
/* D37E30 80240630 00431023 */  subu      $v0, $v0, $v1
/* D37E34 80240634 000218C0 */  sll       $v1, $v0, 3
/* D37E38 80240638 00431021 */  addu      $v0, $v0, $v1
/* D37E3C 8024063C 000210C0 */  sll       $v0, $v0, 3
/* D37E40 80240640 0C00FB3A */  jal       get_enemy
/* D37E44 80240644 00459021 */   addu     $s2, $v0, $a1
/* D37E48 80240648 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* D37E4C 8024064C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* D37E50 80240650 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D37E54 80240654 8E830000 */  lw        $v1, ($s4)
/* D37E58 80240658 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D37E5C 8024065C 8C660028 */  lw        $a2, 0x28($v1)
/* D37E60 80240660 8C670030 */  lw        $a3, 0x30($v1)
/* D37E64 80240664 0C00A7B5 */  jal       dist2D
/* D37E68 80240668 0040982D */   daddu    $s3, $v0, $zero
/* D37E6C 8024066C C6620074 */  lwc1      $f2, 0x74($s3)
/* D37E70 80240670 468010A0 */  cvt.s.w   $f2, $f2
/* D37E74 80240674 4600103C */  c.lt.s    $f2, $f0
/* D37E78 80240678 00000000 */  nop
/* D37E7C 8024067C 45030001 */  bc1tl     .L80240684
/* D37E80 80240680 0000882D */   daddu    $s1, $zero, $zero
.L80240684:
/* D37E84 80240684 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D37E88 80240688 C60E000C */  lwc1      $f14, 0xc($s0)
/* D37E8C 8024068C 3C014387 */  lui       $at, 0x4387
/* D37E90 80240690 4481A000 */  mtc1      $at, $f20
/* D37E94 80240694 0C00A70A */  jal       get_clamped_angle_diff
/* D37E98 80240698 00000000 */   nop
/* D37E9C 8024069C 0C00A6C9 */  jal       clamp_angle
/* D37EA0 802406A0 46000306 */   mov.s    $f12, $f0
/* D37EA4 802406A4 3C018024 */  lui       $at, %hi(func_80242C30_B37800)
/* D37EA8 802406A8 D4222C30 */  ldc1      $f2, %lo(func_80242C30_B37800)($at)
/* D37EAC 802406AC 46000021 */  cvt.d.s   $f0, $f0
/* D37EB0 802406B0 4622003C */  c.lt.d    $f0, $f2
/* D37EB4 802406B4 00000000 */  nop
/* D37EB8 802406B8 45000003 */  bc1f      .L802406C8
/* D37EBC 802406BC 00000000 */   nop
/* D37EC0 802406C0 3C0142B4 */  lui       $at, 0x42b4
/* D37EC4 802406C4 4481A000 */  mtc1      $at, $f20
.L802406C8:
/* D37EC8 802406C8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D37ECC 802406CC 8E820000 */  lw        $v0, ($s4)
/* D37ED0 802406D0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D37ED4 802406D4 8C460028 */  lw        $a2, 0x28($v0)
/* D37ED8 802406D8 0C00A720 */  jal       atan2
/* D37EDC 802406DC 8C470030 */   lw       $a3, 0x30($v0)
/* D37EE0 802406E0 4600A306 */  mov.s     $f12, $f20
/* D37EE4 802406E4 0C00A70A */  jal       get_clamped_angle_diff
/* D37EE8 802406E8 46000386 */   mov.s    $f14, $f0
/* D37EEC 802406EC C6620078 */  lwc1      $f2, 0x78($s3)
/* D37EF0 802406F0 468010A0 */  cvt.s.w   $f2, $f2
/* D37EF4 802406F4 46000005 */  abs.s     $f0, $f0
/* D37EF8 802406F8 4600103C */  c.lt.s    $f2, $f0
/* D37EFC 802406FC 00000000 */  nop
/* D37F00 80240700 45030001 */  bc1tl     .L80240708
/* D37F04 80240704 0000882D */   daddu    $s1, $zero, $zero
.L80240708:
/* D37F08 80240708 8E820000 */  lw        $v0, ($s4)
/* D37F0C 8024070C C600003C */  lwc1      $f0, 0x3c($s0)
/* D37F10 80240710 C442002C */  lwc1      $f2, 0x2c($v0)
/* D37F14 80240714 860200A8 */  lh        $v0, 0xa8($s0)
/* D37F18 80240718 46020001 */  sub.s     $f0, $f0, $f2
/* D37F1C 8024071C 44821000 */  mtc1      $v0, $f2
/* D37F20 80240720 00000000 */  nop
/* D37F24 80240724 468010A1 */  cvt.d.w   $f2, $f2
/* D37F28 80240728 46221080 */  add.d     $f2, $f2, $f2
/* D37F2C 8024072C 46000005 */  abs.s     $f0, $f0
/* D37F30 80240730 46000021 */  cvt.d.s   $f0, $f0
/* D37F34 80240734 4620103E */  c.le.d    $f2, $f0
/* D37F38 80240738 00000000 */  nop
/* D37F3C 8024073C 45030001 */  bc1tl     .L80240744
/* D37F40 80240740 0000882D */   daddu    $s1, $zero, $zero
.L80240744:
/* D37F44 80240744 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* D37F48 80240748 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* D37F4C 8024074C 24020009 */  addiu     $v0, $zero, 9
/* D37F50 80240750 50620001 */  beql      $v1, $v0, .L80240758
/* D37F54 80240754 0000882D */   daddu    $s1, $zero, $zero
.L80240758:
/* D37F58 80240758 24020007 */  addiu     $v0, $zero, 7
/* D37F5C 8024075C 50620001 */  beql      $v1, $v0, .L80240764
/* D37F60 80240760 0000882D */   daddu    $s1, $zero, $zero
.L80240764:
/* D37F64 80240764 0220102D */  daddu     $v0, $s1, $zero
/* D37F68 80240768 8FBF0024 */  lw        $ra, 0x24($sp)
/* D37F6C 8024076C 8FB40020 */  lw        $s4, 0x20($sp)
/* D37F70 80240770 8FB3001C */  lw        $s3, 0x1c($sp)
/* D37F74 80240774 8FB20018 */  lw        $s2, 0x18($sp)
/* D37F78 80240778 8FB10014 */  lw        $s1, 0x14($sp)
/* D37F7C 8024077C 8FB00010 */  lw        $s0, 0x10($sp)
/* D37F80 80240780 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D37F84 80240784 03E00008 */  jr        $ra
/* D37F88 80240788 27BD0030 */   addiu    $sp, $sp, 0x30
