.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240778_BA4EF8
/* BA4EF8 80240778 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BA4EFC 8024077C AFBF0024 */  sw        $ra, 0x24($sp)
/* BA4F00 80240780 AFB40020 */  sw        $s4, 0x20($sp)
/* BA4F04 80240784 AFB3001C */  sw        $s3, 0x1c($sp)
/* BA4F08 80240788 AFB20018 */  sw        $s2, 0x18($sp)
/* BA4F0C 8024078C AFB10014 */  sw        $s1, 0x14($sp)
/* BA4F10 80240790 AFB00010 */  sw        $s0, 0x10($sp)
/* BA4F14 80240794 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BA4F18 80240798 8C900148 */  lw        $s0, 0x148($a0)
/* BA4F1C 8024079C 86040008 */  lh        $a0, 8($s0)
/* BA4F20 802407A0 0C00EABB */  jal       get_npc_unsafe
/* BA4F24 802407A4 24110001 */   addiu    $s1, $zero, 1
/* BA4F28 802407A8 86040008 */  lh        $a0, 8($s0)
/* BA4F2C 802407AC 0040802D */  daddu     $s0, $v0, $zero
/* BA4F30 802407B0 3C05800B */  lui       $a1, %hi(gCameras)
/* BA4F34 802407B4 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* BA4F38 802407B8 3C03800A */  lui       $v1, 0x800a
/* BA4F3C 802407BC 8463A634 */  lh        $v1, -0x59cc($v1)
/* BA4F40 802407C0 00912021 */  addu      $a0, $a0, $s1
/* BA4F44 802407C4 00031080 */  sll       $v0, $v1, 2
/* BA4F48 802407C8 00431021 */  addu      $v0, $v0, $v1
/* BA4F4C 802407CC 00021080 */  sll       $v0, $v0, 2
/* BA4F50 802407D0 00431023 */  subu      $v0, $v0, $v1
/* BA4F54 802407D4 000218C0 */  sll       $v1, $v0, 3
/* BA4F58 802407D8 00431021 */  addu      $v0, $v0, $v1
/* BA4F5C 802407DC 000210C0 */  sll       $v0, $v0, 3
/* BA4F60 802407E0 0C00FB3A */  jal       get_enemy
/* BA4F64 802407E4 00459021 */   addu     $s2, $v0, $a1
/* BA4F68 802407E8 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* BA4F6C 802407EC 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* BA4F70 802407F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA4F74 802407F4 8E830000 */  lw        $v1, ($s4)
/* BA4F78 802407F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA4F7C 802407FC 8C660028 */  lw        $a2, 0x28($v1)
/* BA4F80 80240800 8C670030 */  lw        $a3, 0x30($v1)
/* BA4F84 80240804 0C00A7B5 */  jal       dist2D
/* BA4F88 80240808 0040982D */   daddu    $s3, $v0, $zero
/* BA4F8C 8024080C C6620074 */  lwc1      $f2, 0x74($s3)
/* BA4F90 80240810 468010A0 */  cvt.s.w   $f2, $f2
/* BA4F94 80240814 4600103C */  c.lt.s    $f2, $f0
/* BA4F98 80240818 00000000 */  nop       
/* BA4F9C 8024081C 45030001 */  bc1tl     .L80240824
/* BA4FA0 80240820 0000882D */   daddu    $s1, $zero, $zero
.L80240824:
/* BA4FA4 80240824 C64C006C */  lwc1      $f12, 0x6c($s2)
/* BA4FA8 80240828 C60E000C */  lwc1      $f14, 0xc($s0)
/* BA4FAC 8024082C 3C014387 */  lui       $at, 0x4387
/* BA4FB0 80240830 4481A000 */  mtc1      $at, $f20
/* BA4FB4 80240834 0C00A70A */  jal       get_clamped_angle_diff
/* BA4FB8 80240838 00000000 */   nop      
/* BA4FBC 8024083C 0C00A6C9 */  jal       clamp_angle
/* BA4FC0 80240840 46000306 */   mov.s    $f12, $f0
/* BA4FC4 80240844 3C018024 */  lui       $at, 0x8024
/* BA4FC8 80240848 D42257B0 */  ldc1      $f2, 0x57b0($at)
/* BA4FCC 8024084C 46000021 */  cvt.d.s   $f0, $f0
/* BA4FD0 80240850 4622003C */  c.lt.d    $f0, $f2
/* BA4FD4 80240854 00000000 */  nop       
/* BA4FD8 80240858 45000003 */  bc1f      .L80240868
/* BA4FDC 8024085C 00000000 */   nop      
/* BA4FE0 80240860 3C0142B4 */  lui       $at, 0x42b4
/* BA4FE4 80240864 4481A000 */  mtc1      $at, $f20
.L80240868:
/* BA4FE8 80240868 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA4FEC 8024086C 8E820000 */  lw        $v0, ($s4)
/* BA4FF0 80240870 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA4FF4 80240874 8C460028 */  lw        $a2, 0x28($v0)
/* BA4FF8 80240878 0C00A720 */  jal       atan2
/* BA4FFC 8024087C 8C470030 */   lw       $a3, 0x30($v0)
/* BA5000 80240880 4600A306 */  mov.s     $f12, $f20
/* BA5004 80240884 0C00A70A */  jal       get_clamped_angle_diff
/* BA5008 80240888 46000386 */   mov.s    $f14, $f0
/* BA500C 8024088C C6620078 */  lwc1      $f2, 0x78($s3)
/* BA5010 80240890 468010A0 */  cvt.s.w   $f2, $f2
/* BA5014 80240894 46000005 */  abs.s     $f0, $f0
/* BA5018 80240898 4600103C */  c.lt.s    $f2, $f0
/* BA501C 8024089C 00000000 */  nop       
/* BA5020 802408A0 45030001 */  bc1tl     .L802408A8
/* BA5024 802408A4 0000882D */   daddu    $s1, $zero, $zero
.L802408A8:
/* BA5028 802408A8 8E820000 */  lw        $v0, ($s4)
/* BA502C 802408AC C600003C */  lwc1      $f0, 0x3c($s0)
/* BA5030 802408B0 C442002C */  lwc1      $f2, 0x2c($v0)
/* BA5034 802408B4 860200A8 */  lh        $v0, 0xa8($s0)
/* BA5038 802408B8 46020001 */  sub.s     $f0, $f0, $f2
/* BA503C 802408BC 44821000 */  mtc1      $v0, $f2
/* BA5040 802408C0 00000000 */  nop       
/* BA5044 802408C4 468010A1 */  cvt.d.w   $f2, $f2
/* BA5048 802408C8 46221080 */  add.d     $f2, $f2, $f2
/* BA504C 802408CC 46000005 */  abs.s     $f0, $f0
/* BA5050 802408D0 46000021 */  cvt.d.s   $f0, $f0
/* BA5054 802408D4 4620103E */  c.le.d    $f2, $f0
/* BA5058 802408D8 00000000 */  nop       
/* BA505C 802408DC 45030001 */  bc1tl     .L802408E4
/* BA5060 802408E0 0000882D */   daddu    $s1, $zero, $zero
.L802408E4:
/* BA5064 802408E4 3C038011 */  lui       $v1, 0x8011
/* BA5068 802408E8 8063EBB3 */  lb        $v1, -0x144d($v1)
/* BA506C 802408EC 24020009 */  addiu     $v0, $zero, 9
/* BA5070 802408F0 50620001 */  beql      $v1, $v0, .L802408F8
/* BA5074 802408F4 0000882D */   daddu    $s1, $zero, $zero
.L802408F8:
/* BA5078 802408F8 24020007 */  addiu     $v0, $zero, 7
/* BA507C 802408FC 50620001 */  beql      $v1, $v0, .L80240904
/* BA5080 80240900 0000882D */   daddu    $s1, $zero, $zero
.L80240904:
/* BA5084 80240904 0220102D */  daddu     $v0, $s1, $zero
/* BA5088 80240908 8FBF0024 */  lw        $ra, 0x24($sp)
/* BA508C 8024090C 8FB40020 */  lw        $s4, 0x20($sp)
/* BA5090 80240910 8FB3001C */  lw        $s3, 0x1c($sp)
/* BA5094 80240914 8FB20018 */  lw        $s2, 0x18($sp)
/* BA5098 80240918 8FB10014 */  lw        $s1, 0x14($sp)
/* BA509C 8024091C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA50A0 80240920 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BA50A4 80240924 03E00008 */  jr        $ra
/* BA50A8 80240928 27BD0030 */   addiu    $sp, $sp, 0x30
