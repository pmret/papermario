.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AD4_B4C544
/* B4C544 80241AD4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B4C548 80241AD8 AFBF0024 */  sw        $ra, 0x24($sp)
/* B4C54C 80241ADC AFB40020 */  sw        $s4, 0x20($sp)
/* B4C550 80241AE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* B4C554 80241AE4 AFB20018 */  sw        $s2, 0x18($sp)
/* B4C558 80241AE8 AFB10014 */  sw        $s1, 0x14($sp)
/* B4C55C 80241AEC AFB00010 */  sw        $s0, 0x10($sp)
/* B4C560 80241AF0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B4C564 80241AF4 8C900148 */  lw        $s0, 0x148($a0)
/* B4C568 80241AF8 86040008 */  lh        $a0, 8($s0)
/* B4C56C 80241AFC 0C00EABB */  jal       get_npc_unsafe
/* B4C570 80241B00 24110001 */   addiu    $s1, $zero, 1
/* B4C574 80241B04 86040008 */  lh        $a0, 8($s0)
/* B4C578 80241B08 0040802D */  daddu     $s0, $v0, $zero
/* B4C57C 80241B0C 3C05800B */  lui       $a1, %hi(gCameras)
/* B4C580 80241B10 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B4C584 80241B14 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* B4C588 80241B18 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* B4C58C 80241B1C 00912021 */  addu      $a0, $a0, $s1
/* B4C590 80241B20 00031080 */  sll       $v0, $v1, 2
/* B4C594 80241B24 00431021 */  addu      $v0, $v0, $v1
/* B4C598 80241B28 00021080 */  sll       $v0, $v0, 2
/* B4C59C 80241B2C 00431023 */  subu      $v0, $v0, $v1
/* B4C5A0 80241B30 000218C0 */  sll       $v1, $v0, 3
/* B4C5A4 80241B34 00431021 */  addu      $v0, $v0, $v1
/* B4C5A8 80241B38 000210C0 */  sll       $v0, $v0, 3
/* B4C5AC 80241B3C 0C00FB3A */  jal       get_enemy
/* B4C5B0 80241B40 00459021 */   addu     $s2, $v0, $a1
/* B4C5B4 80241B44 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B4C5B8 80241B48 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B4C5BC 80241B4C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B4C5C0 80241B50 8E830000 */  lw        $v1, ($s4)
/* B4C5C4 80241B54 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B4C5C8 80241B58 8C660028 */  lw        $a2, 0x28($v1)
/* B4C5CC 80241B5C 8C670030 */  lw        $a3, 0x30($v1)
/* B4C5D0 80241B60 0C00A7B5 */  jal       dist2D
/* B4C5D4 80241B64 0040982D */   daddu    $s3, $v0, $zero
/* B4C5D8 80241B68 C6620074 */  lwc1      $f2, 0x74($s3)
/* B4C5DC 80241B6C 468010A0 */  cvt.s.w   $f2, $f2
/* B4C5E0 80241B70 4600103C */  c.lt.s    $f2, $f0
/* B4C5E4 80241B74 00000000 */  nop
/* B4C5E8 80241B78 45030001 */  bc1tl     .L80241B80
/* B4C5EC 80241B7C 0000882D */   daddu    $s1, $zero, $zero
.L80241B80:
/* B4C5F0 80241B80 C64C006C */  lwc1      $f12, 0x6c($s2)
/* B4C5F4 80241B84 C60E000C */  lwc1      $f14, 0xc($s0)
/* B4C5F8 80241B88 3C014387 */  lui       $at, 0x4387
/* B4C5FC 80241B8C 4481A000 */  mtc1      $at, $f20
/* B4C600 80241B90 0C00A70A */  jal       get_clamped_angle_diff
/* B4C604 80241B94 00000000 */   nop
/* B4C608 80241B98 0C00A6C9 */  jal       clamp_angle
/* B4C60C 80241B9C 46000306 */   mov.s    $f12, $f0
/* B4C610 80241BA0 3C018024 */  lui       $at, %hi(D_80247A90_B52500)
/* B4C614 80241BA4 D4227A90 */  ldc1      $f2, %lo(D_80247A90_B52500)($at)
/* B4C618 80241BA8 46000021 */  cvt.d.s   $f0, $f0
/* B4C61C 80241BAC 4622003C */  c.lt.d    $f0, $f2
/* B4C620 80241BB0 00000000 */  nop
/* B4C624 80241BB4 45000003 */  bc1f      .L80241BC4
/* B4C628 80241BB8 00000000 */   nop
/* B4C62C 80241BBC 3C0142B4 */  lui       $at, 0x42b4
/* B4C630 80241BC0 4481A000 */  mtc1      $at, $f20
.L80241BC4:
/* B4C634 80241BC4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B4C638 80241BC8 8E820000 */  lw        $v0, ($s4)
/* B4C63C 80241BCC C60E0040 */  lwc1      $f14, 0x40($s0)
/* B4C640 80241BD0 8C460028 */  lw        $a2, 0x28($v0)
/* B4C644 80241BD4 0C00A720 */  jal       atan2
/* B4C648 80241BD8 8C470030 */   lw       $a3, 0x30($v0)
/* B4C64C 80241BDC 4600A306 */  mov.s     $f12, $f20
/* B4C650 80241BE0 0C00A70A */  jal       get_clamped_angle_diff
/* B4C654 80241BE4 46000386 */   mov.s    $f14, $f0
/* B4C658 80241BE8 C6620078 */  lwc1      $f2, 0x78($s3)
/* B4C65C 80241BEC 468010A0 */  cvt.s.w   $f2, $f2
/* B4C660 80241BF0 46000005 */  abs.s     $f0, $f0
/* B4C664 80241BF4 4600103C */  c.lt.s    $f2, $f0
/* B4C668 80241BF8 00000000 */  nop
/* B4C66C 80241BFC 45030001 */  bc1tl     .L80241C04
/* B4C670 80241C00 0000882D */   daddu    $s1, $zero, $zero
.L80241C04:
/* B4C674 80241C04 8E820000 */  lw        $v0, ($s4)
/* B4C678 80241C08 C600003C */  lwc1      $f0, 0x3c($s0)
/* B4C67C 80241C0C C442002C */  lwc1      $f2, 0x2c($v0)
/* B4C680 80241C10 860200A8 */  lh        $v0, 0xa8($s0)
/* B4C684 80241C14 46020001 */  sub.s     $f0, $f0, $f2
/* B4C688 80241C18 44821000 */  mtc1      $v0, $f2
/* B4C68C 80241C1C 00000000 */  nop
/* B4C690 80241C20 468010A1 */  cvt.d.w   $f2, $f2
/* B4C694 80241C24 46221080 */  add.d     $f2, $f2, $f2
/* B4C698 80241C28 46000005 */  abs.s     $f0, $f0
/* B4C69C 80241C2C 46000021 */  cvt.d.s   $f0, $f0
/* B4C6A0 80241C30 4620103E */  c.le.d    $f2, $f0
/* B4C6A4 80241C34 00000000 */  nop
/* B4C6A8 80241C38 45030001 */  bc1tl     .L80241C40
/* B4C6AC 80241C3C 0000882D */   daddu    $s1, $zero, $zero
.L80241C40:
/* B4C6B0 80241C40 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* B4C6B4 80241C44 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* B4C6B8 80241C48 24020009 */  addiu     $v0, $zero, 9
/* B4C6BC 80241C4C 50620001 */  beql      $v1, $v0, .L80241C54
/* B4C6C0 80241C50 0000882D */   daddu    $s1, $zero, $zero
.L80241C54:
/* B4C6C4 80241C54 24020007 */  addiu     $v0, $zero, 7
/* B4C6C8 80241C58 50620001 */  beql      $v1, $v0, .L80241C60
/* B4C6CC 80241C5C 0000882D */   daddu    $s1, $zero, $zero
.L80241C60:
/* B4C6D0 80241C60 0220102D */  daddu     $v0, $s1, $zero
/* B4C6D4 80241C64 8FBF0024 */  lw        $ra, 0x24($sp)
/* B4C6D8 80241C68 8FB40020 */  lw        $s4, 0x20($sp)
/* B4C6DC 80241C6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* B4C6E0 80241C70 8FB20018 */  lw        $s2, 0x18($sp)
/* B4C6E4 80241C74 8FB10014 */  lw        $s1, 0x14($sp)
/* B4C6E8 80241C78 8FB00010 */  lw        $s0, 0x10($sp)
/* B4C6EC 80241C7C D7B40028 */  ldc1      $f20, 0x28($sp)
/* B4C6F0 80241C80 03E00008 */  jr        $ra
/* B4C6F4 80241C84 27BD0030 */   addiu    $sp, $sp, 0x30
