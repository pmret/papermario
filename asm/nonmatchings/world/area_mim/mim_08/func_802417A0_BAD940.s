.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A0_BAF0E0
/* BAF0E0 802417A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BAF0E4 802417A4 AFBF0024 */  sw        $ra, 0x24($sp)
/* BAF0E8 802417A8 AFB40020 */  sw        $s4, 0x20($sp)
/* BAF0EC 802417AC AFB3001C */  sw        $s3, 0x1c($sp)
/* BAF0F0 802417B0 AFB20018 */  sw        $s2, 0x18($sp)
/* BAF0F4 802417B4 AFB10014 */  sw        $s1, 0x14($sp)
/* BAF0F8 802417B8 AFB00010 */  sw        $s0, 0x10($sp)
/* BAF0FC 802417BC F7B40028 */  sdc1      $f20, 0x28($sp)
/* BAF100 802417C0 8C900148 */  lw        $s0, 0x148($a0)
/* BAF104 802417C4 86040008 */  lh        $a0, 8($s0)
/* BAF108 802417C8 0C00EABB */  jal       get_npc_unsafe
/* BAF10C 802417CC 24110001 */   addiu    $s1, $zero, 1
/* BAF110 802417D0 86040008 */  lh        $a0, 8($s0)
/* BAF114 802417D4 0040802D */  daddu     $s0, $v0, $zero
/* BAF118 802417D8 3C05800B */  lui       $a1, %hi(gCameras)
/* BAF11C 802417DC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* BAF120 802417E0 3C03800A */  lui       $v1, 0x800a
/* BAF124 802417E4 8463A634 */  lh        $v1, -0x59cc($v1)
/* BAF128 802417E8 00912021 */  addu      $a0, $a0, $s1
/* BAF12C 802417EC 00031080 */  sll       $v0, $v1, 2
/* BAF130 802417F0 00431021 */  addu      $v0, $v0, $v1
/* BAF134 802417F4 00021080 */  sll       $v0, $v0, 2
/* BAF138 802417F8 00431023 */  subu      $v0, $v0, $v1
/* BAF13C 802417FC 000218C0 */  sll       $v1, $v0, 3
/* BAF140 80241800 00431021 */  addu      $v0, $v0, $v1
/* BAF144 80241804 000210C0 */  sll       $v0, $v0, 3
/* BAF148 80241808 0C00FB3A */  jal       get_enemy
/* BAF14C 8024180C 00459021 */   addu     $s2, $v0, $a1
/* BAF150 80241810 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* BAF154 80241814 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* BAF158 80241818 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAF15C 8024181C 8E830000 */  lw        $v1, ($s4)
/* BAF160 80241820 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAF164 80241824 8C660028 */  lw        $a2, 0x28($v1)
/* BAF168 80241828 8C670030 */  lw        $a3, 0x30($v1)
/* BAF16C 8024182C 0C00A7B5 */  jal       dist2D
/* BAF170 80241830 0040982D */   daddu    $s3, $v0, $zero
/* BAF174 80241834 C6620074 */  lwc1      $f2, 0x74($s3)
/* BAF178 80241838 468010A0 */  cvt.s.w   $f2, $f2
/* BAF17C 8024183C 4600103C */  c.lt.s    $f2, $f0
/* BAF180 80241840 00000000 */  nop       
/* BAF184 80241844 45030001 */  bc1tl     .L8024184C
/* BAF188 80241848 0000882D */   daddu    $s1, $zero, $zero
.L8024184C:
/* BAF18C 8024184C C64C006C */  lwc1      $f12, 0x6c($s2)
/* BAF190 80241850 C60E000C */  lwc1      $f14, 0xc($s0)
/* BAF194 80241854 3C014387 */  lui       $at, 0x4387
/* BAF198 80241858 4481A000 */  mtc1      $at, $f20
/* BAF19C 8024185C 0C00A70A */  jal       get_clamped_angle_diff
/* BAF1A0 80241860 00000000 */   nop      
/* BAF1A4 80241864 0C00A6C9 */  jal       clamp_angle
/* BAF1A8 80241868 46000306 */   mov.s    $f12, $f0
/* BAF1AC 8024186C 3C018024 */  lui       $at, 0x8024
/* BAF1B0 80241870 D42252F8 */  ldc1      $f2, 0x52f8($at)
/* BAF1B4 80241874 46000021 */  cvt.d.s   $f0, $f0
/* BAF1B8 80241878 4622003C */  c.lt.d    $f0, $f2
/* BAF1BC 8024187C 00000000 */  nop       
/* BAF1C0 80241880 45000003 */  bc1f      .L80241890
/* BAF1C4 80241884 00000000 */   nop      
/* BAF1C8 80241888 3C0142B4 */  lui       $at, 0x42b4
/* BAF1CC 8024188C 4481A000 */  mtc1      $at, $f20
.L80241890:
/* BAF1D0 80241890 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAF1D4 80241894 8E820000 */  lw        $v0, ($s4)
/* BAF1D8 80241898 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAF1DC 8024189C 8C460028 */  lw        $a2, 0x28($v0)
/* BAF1E0 802418A0 0C00A720 */  jal       atan2
/* BAF1E4 802418A4 8C470030 */   lw       $a3, 0x30($v0)
/* BAF1E8 802418A8 4600A306 */  mov.s     $f12, $f20
/* BAF1EC 802418AC 0C00A70A */  jal       get_clamped_angle_diff
/* BAF1F0 802418B0 46000386 */   mov.s    $f14, $f0
/* BAF1F4 802418B4 C6620078 */  lwc1      $f2, 0x78($s3)
/* BAF1F8 802418B8 468010A0 */  cvt.s.w   $f2, $f2
/* BAF1FC 802418BC 46000005 */  abs.s     $f0, $f0
/* BAF200 802418C0 4600103C */  c.lt.s    $f2, $f0
/* BAF204 802418C4 00000000 */  nop       
/* BAF208 802418C8 45030001 */  bc1tl     .L802418D0
/* BAF20C 802418CC 0000882D */   daddu    $s1, $zero, $zero
.L802418D0:
/* BAF210 802418D0 8E820000 */  lw        $v0, ($s4)
/* BAF214 802418D4 C600003C */  lwc1      $f0, 0x3c($s0)
/* BAF218 802418D8 C442002C */  lwc1      $f2, 0x2c($v0)
/* BAF21C 802418DC 860200A8 */  lh        $v0, 0xa8($s0)
/* BAF220 802418E0 46020001 */  sub.s     $f0, $f0, $f2
/* BAF224 802418E4 44821000 */  mtc1      $v0, $f2
/* BAF228 802418E8 00000000 */  nop       
/* BAF22C 802418EC 468010A1 */  cvt.d.w   $f2, $f2
/* BAF230 802418F0 46221080 */  add.d     $f2, $f2, $f2
/* BAF234 802418F4 46000005 */  abs.s     $f0, $f0
/* BAF238 802418F8 46000021 */  cvt.d.s   $f0, $f0
/* BAF23C 802418FC 4620103E */  c.le.d    $f2, $f0
/* BAF240 80241900 00000000 */  nop       
/* BAF244 80241904 45030001 */  bc1tl     .L8024190C
/* BAF248 80241908 0000882D */   daddu    $s1, $zero, $zero
.L8024190C:
/* BAF24C 8024190C 3C038011 */  lui       $v1, 0x8011
/* BAF250 80241910 8063EBB3 */  lb        $v1, -0x144d($v1)
/* BAF254 80241914 24020009 */  addiu     $v0, $zero, 9
/* BAF258 80241918 50620001 */  beql      $v1, $v0, .L80241920
/* BAF25C 8024191C 0000882D */   daddu    $s1, $zero, $zero
.L80241920:
/* BAF260 80241920 24020007 */  addiu     $v0, $zero, 7
/* BAF264 80241924 50620001 */  beql      $v1, $v0, .L8024192C
/* BAF268 80241928 0000882D */   daddu    $s1, $zero, $zero
.L8024192C:
/* BAF26C 8024192C 0220102D */  daddu     $v0, $s1, $zero
/* BAF270 80241930 8FBF0024 */  lw        $ra, 0x24($sp)
/* BAF274 80241934 8FB40020 */  lw        $s4, 0x20($sp)
/* BAF278 80241938 8FB3001C */  lw        $s3, 0x1c($sp)
/* BAF27C 8024193C 8FB20018 */  lw        $s2, 0x18($sp)
/* BAF280 80241940 8FB10014 */  lw        $s1, 0x14($sp)
/* BAF284 80241944 8FB00010 */  lw        $s0, 0x10($sp)
/* BAF288 80241948 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BAF28C 8024194C 03E00008 */  jr        $ra
/* BAF290 80241950 27BD0030 */   addiu    $sp, $sp, 0x30
