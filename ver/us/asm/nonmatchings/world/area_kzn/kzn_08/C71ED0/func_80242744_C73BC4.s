.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242744_C73BC4
/* C73BC4 80242744 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C73BC8 80242748 AFBF0024 */  sw        $ra, 0x24($sp)
/* C73BCC 8024274C AFB40020 */  sw        $s4, 0x20($sp)
/* C73BD0 80242750 AFB3001C */  sw        $s3, 0x1c($sp)
/* C73BD4 80242754 AFB20018 */  sw        $s2, 0x18($sp)
/* C73BD8 80242758 AFB10014 */  sw        $s1, 0x14($sp)
/* C73BDC 8024275C AFB00010 */  sw        $s0, 0x10($sp)
/* C73BE0 80242760 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C73BE4 80242764 8C900148 */  lw        $s0, 0x148($a0)
/* C73BE8 80242768 86040008 */  lh        $a0, 8($s0)
/* C73BEC 8024276C 0C00EABB */  jal       get_npc_unsafe
/* C73BF0 80242770 24110001 */   addiu    $s1, $zero, 1
/* C73BF4 80242774 86040008 */  lh        $a0, 8($s0)
/* C73BF8 80242778 0040802D */  daddu     $s0, $v0, $zero
/* C73BFC 8024277C 3C05800B */  lui       $a1, %hi(gCameras)
/* C73C00 80242780 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* C73C04 80242784 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C73C08 80242788 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C73C0C 8024278C 00912021 */  addu      $a0, $a0, $s1
/* C73C10 80242790 00031080 */  sll       $v0, $v1, 2
/* C73C14 80242794 00431021 */  addu      $v0, $v0, $v1
/* C73C18 80242798 00021080 */  sll       $v0, $v0, 2
/* C73C1C 8024279C 00431023 */  subu      $v0, $v0, $v1
/* C73C20 802427A0 000218C0 */  sll       $v1, $v0, 3
/* C73C24 802427A4 00431021 */  addu      $v0, $v0, $v1
/* C73C28 802427A8 000210C0 */  sll       $v0, $v0, 3
/* C73C2C 802427AC 0C00FB3A */  jal       get_enemy
/* C73C30 802427B0 00459021 */   addu     $s2, $v0, $a1
/* C73C34 802427B4 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* C73C38 802427B8 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* C73C3C 802427BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C73C40 802427C0 8E830000 */  lw        $v1, ($s4)
/* C73C44 802427C4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C73C48 802427C8 8C660028 */  lw        $a2, 0x28($v1)
/* C73C4C 802427CC 8C670030 */  lw        $a3, 0x30($v1)
/* C73C50 802427D0 0C00A7B5 */  jal       dist2D
/* C73C54 802427D4 0040982D */   daddu    $s3, $v0, $zero
/* C73C58 802427D8 C6620074 */  lwc1      $f2, 0x74($s3)
/* C73C5C 802427DC 468010A0 */  cvt.s.w   $f2, $f2
/* C73C60 802427E0 4600103C */  c.lt.s    $f2, $f0
/* C73C64 802427E4 00000000 */  nop
/* C73C68 802427E8 45030001 */  bc1tl     .L802427F0
/* C73C6C 802427EC 0000882D */   daddu    $s1, $zero, $zero
.L802427F0:
/* C73C70 802427F0 C64C006C */  lwc1      $f12, 0x6c($s2)
/* C73C74 802427F4 C60E000C */  lwc1      $f14, 0xc($s0)
/* C73C78 802427F8 3C014387 */  lui       $at, 0x4387
/* C73C7C 802427FC 4481A000 */  mtc1      $at, $f20
/* C73C80 80242800 0C00A70A */  jal       get_clamped_angle_diff
/* C73C84 80242804 00000000 */   nop
/* C73C88 80242808 0C00A6C9 */  jal       clamp_angle
/* C73C8C 8024280C 46000306 */   mov.s    $f12, $f0
/* C73C90 80242810 3C018024 */  lui       $at, %hi(D_80245698_C76B18)
/* C73C94 80242814 D4225698 */  ldc1      $f2, %lo(D_80245698_C76B18)($at)
/* C73C98 80242818 46000021 */  cvt.d.s   $f0, $f0
/* C73C9C 8024281C 4622003C */  c.lt.d    $f0, $f2
/* C73CA0 80242820 00000000 */  nop
/* C73CA4 80242824 45000003 */  bc1f      .L80242834
/* C73CA8 80242828 00000000 */   nop
/* C73CAC 8024282C 3C0142B4 */  lui       $at, 0x42b4
/* C73CB0 80242830 4481A000 */  mtc1      $at, $f20
.L80242834:
/* C73CB4 80242834 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C73CB8 80242838 8E820000 */  lw        $v0, ($s4)
/* C73CBC 8024283C C60E0040 */  lwc1      $f14, 0x40($s0)
/* C73CC0 80242840 8C460028 */  lw        $a2, 0x28($v0)
/* C73CC4 80242844 0C00A720 */  jal       atan2
/* C73CC8 80242848 8C470030 */   lw       $a3, 0x30($v0)
/* C73CCC 8024284C 4600A306 */  mov.s     $f12, $f20
/* C73CD0 80242850 0C00A70A */  jal       get_clamped_angle_diff
/* C73CD4 80242854 46000386 */   mov.s    $f14, $f0
/* C73CD8 80242858 C6620078 */  lwc1      $f2, 0x78($s3)
/* C73CDC 8024285C 468010A0 */  cvt.s.w   $f2, $f2
/* C73CE0 80242860 46000005 */  abs.s     $f0, $f0
/* C73CE4 80242864 4600103C */  c.lt.s    $f2, $f0
/* C73CE8 80242868 00000000 */  nop
/* C73CEC 8024286C 45030001 */  bc1tl     .L80242874
/* C73CF0 80242870 0000882D */   daddu    $s1, $zero, $zero
.L80242874:
/* C73CF4 80242874 8E820000 */  lw        $v0, ($s4)
/* C73CF8 80242878 C600003C */  lwc1      $f0, 0x3c($s0)
/* C73CFC 8024287C C442002C */  lwc1      $f2, 0x2c($v0)
/* C73D00 80242880 860200A8 */  lh        $v0, 0xa8($s0)
/* C73D04 80242884 46020001 */  sub.s     $f0, $f0, $f2
/* C73D08 80242888 44821000 */  mtc1      $v0, $f2
/* C73D0C 8024288C 00000000 */  nop
/* C73D10 80242890 468010A1 */  cvt.d.w   $f2, $f2
/* C73D14 80242894 46221080 */  add.d     $f2, $f2, $f2
/* C73D18 80242898 46000005 */  abs.s     $f0, $f0
/* C73D1C 8024289C 46000021 */  cvt.d.s   $f0, $f0
/* C73D20 802428A0 4620103E */  c.le.d    $f2, $f0
/* C73D24 802428A4 00000000 */  nop
/* C73D28 802428A8 45030001 */  bc1tl     .L802428B0
/* C73D2C 802428AC 0000882D */   daddu    $s1, $zero, $zero
.L802428B0:
/* C73D30 802428B0 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* C73D34 802428B4 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* C73D38 802428B8 24020009 */  addiu     $v0, $zero, 9
/* C73D3C 802428BC 50620001 */  beql      $v1, $v0, .L802428C4
/* C73D40 802428C0 0000882D */   daddu    $s1, $zero, $zero
.L802428C4:
/* C73D44 802428C4 24020007 */  addiu     $v0, $zero, 7
/* C73D48 802428C8 50620001 */  beql      $v1, $v0, .L802428D0
/* C73D4C 802428CC 0000882D */   daddu    $s1, $zero, $zero
.L802428D0:
/* C73D50 802428D0 0220102D */  daddu     $v0, $s1, $zero
/* C73D54 802428D4 8FBF0024 */  lw        $ra, 0x24($sp)
/* C73D58 802428D8 8FB40020 */  lw        $s4, 0x20($sp)
/* C73D5C 802428DC 8FB3001C */  lw        $s3, 0x1c($sp)
/* C73D60 802428E0 8FB20018 */  lw        $s2, 0x18($sp)
/* C73D64 802428E4 8FB10014 */  lw        $s1, 0x14($sp)
/* C73D68 802428E8 8FB00010 */  lw        $s0, 0x10($sp)
/* C73D6C 802428EC D7B40028 */  ldc1      $f20, 0x28($sp)
/* C73D70 802428F0 03E00008 */  jr        $ra
/* C73D74 802428F4 27BD0030 */   addiu    $sp, $sp, 0x30
