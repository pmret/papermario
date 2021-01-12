.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240708_B93B48
/* B93B48 80240708 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B93B4C 8024070C AFBF0024 */  sw        $ra, 0x24($sp)
/* B93B50 80240710 AFB40020 */  sw        $s4, 0x20($sp)
/* B93B54 80240714 AFB3001C */  sw        $s3, 0x1c($sp)
/* B93B58 80240718 AFB20018 */  sw        $s2, 0x18($sp)
/* B93B5C 8024071C AFB10014 */  sw        $s1, 0x14($sp)
/* B93B60 80240720 AFB00010 */  sw        $s0, 0x10($sp)
/* B93B64 80240724 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B93B68 80240728 8C900148 */  lw        $s0, 0x148($a0)
/* B93B6C 8024072C 86040008 */  lh        $a0, 8($s0)
/* B93B70 80240730 0C00EABB */  jal       get_npc_unsafe
/* B93B74 80240734 24110001 */   addiu    $s1, $zero, 1
/* B93B78 80240738 86040008 */  lh        $a0, 8($s0)
/* B93B7C 8024073C 0040802D */  daddu     $s0, $v0, $zero
/* B93B80 80240740 3C05800B */  lui       $a1, %hi(gCameras)
/* B93B84 80240744 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B93B88 80240748 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B93B8C 8024074C 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B93B90 80240750 00912021 */  addu      $a0, $a0, $s1
/* B93B94 80240754 00031080 */  sll       $v0, $v1, 2
/* B93B98 80240758 00431021 */  addu      $v0, $v0, $v1
/* B93B9C 8024075C 00021080 */  sll       $v0, $v0, 2
/* B93BA0 80240760 00431023 */  subu      $v0, $v0, $v1
/* B93BA4 80240764 000218C0 */  sll       $v1, $v0, 3
/* B93BA8 80240768 00431021 */  addu      $v0, $v0, $v1
/* B93BAC 8024076C 000210C0 */  sll       $v0, $v0, 3
/* B93BB0 80240770 0C00FB3A */  jal       get_enemy
/* B93BB4 80240774 00459021 */   addu     $s2, $v0, $a1
/* B93BB8 80240778 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B93BBC 8024077C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B93BC0 80240780 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B93BC4 80240784 8E830000 */  lw        $v1, ($s4)
/* B93BC8 80240788 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B93BCC 8024078C 8C660028 */  lw        $a2, 0x28($v1)
/* B93BD0 80240790 8C670030 */  lw        $a3, 0x30($v1)
/* B93BD4 80240794 0C00A7B5 */  jal       dist2D
/* B93BD8 80240798 0040982D */   daddu    $s3, $v0, $zero
/* B93BDC 8024079C C6620074 */  lwc1      $f2, 0x74($s3)
/* B93BE0 802407A0 468010A0 */  cvt.s.w   $f2, $f2
/* B93BE4 802407A4 4600103C */  c.lt.s    $f2, $f0
/* B93BE8 802407A8 00000000 */  nop
/* B93BEC 802407AC 45030001 */  bc1tl     .L802407B4
/* B93BF0 802407B0 0000882D */   daddu    $s1, $zero, $zero
.L802407B4:
/* B93BF4 802407B4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* B93BF8 802407B8 C60E000C */  lwc1      $f14, 0xc($s0)
/* B93BFC 802407BC 3C014387 */  lui       $at, 0x4387
/* B93C00 802407C0 4481A000 */  mtc1      $at, $f20
/* B93C04 802407C4 0C00A70A */  jal       get_clamped_angle_diff
/* B93C08 802407C8 00000000 */   nop
/* B93C0C 802407CC 0C00A6C9 */  jal       clamp_angle
/* B93C10 802407D0 46000306 */   mov.s    $f12, $f0
/* B93C14 802407D4 3C018024 */  lui       $at, %hi(D_802445F0)
/* B93C18 802407D8 D42245F0 */  ldc1      $f2, %lo(D_802445F0)($at)
/* B93C1C 802407DC 46000021 */  cvt.d.s   $f0, $f0
/* B93C20 802407E0 4622003C */  c.lt.d    $f0, $f2
/* B93C24 802407E4 00000000 */  nop
/* B93C28 802407E8 45000003 */  bc1f      .L802407F8
/* B93C2C 802407EC 00000000 */   nop
/* B93C30 802407F0 3C0142B4 */  lui       $at, 0x42b4
/* B93C34 802407F4 4481A000 */  mtc1      $at, $f20
.L802407F8:
/* B93C38 802407F8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B93C3C 802407FC 8E820000 */  lw        $v0, ($s4)
/* B93C40 80240800 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B93C44 80240804 8C460028 */  lw        $a2, 0x28($v0)
/* B93C48 80240808 0C00A720 */  jal       atan2
/* B93C4C 8024080C 8C470030 */   lw       $a3, 0x30($v0)
/* B93C50 80240810 4600A306 */  mov.s     $f12, $f20
/* B93C54 80240814 0C00A70A */  jal       get_clamped_angle_diff
/* B93C58 80240818 46000386 */   mov.s    $f14, $f0
/* B93C5C 8024081C C6620078 */  lwc1      $f2, 0x78($s3)
/* B93C60 80240820 468010A0 */  cvt.s.w   $f2, $f2
/* B93C64 80240824 46000005 */  abs.s     $f0, $f0
/* B93C68 80240828 4600103C */  c.lt.s    $f2, $f0
/* B93C6C 8024082C 00000000 */  nop
/* B93C70 80240830 45030001 */  bc1tl     .L80240838
/* B93C74 80240834 0000882D */   daddu    $s1, $zero, $zero
.L80240838:
/* B93C78 80240838 8E820000 */  lw        $v0, ($s4)
/* B93C7C 8024083C C600003C */  lwc1      $f0, 0x3c($s0)
/* B93C80 80240840 C442002C */  lwc1      $f2, 0x2c($v0)
/* B93C84 80240844 860200A8 */  lh        $v0, 0xa8($s0)
/* B93C88 80240848 46020001 */  sub.s     $f0, $f0, $f2
/* B93C8C 8024084C 44821000 */  mtc1      $v0, $f2
/* B93C90 80240850 00000000 */  nop
/* B93C94 80240854 468010A1 */  cvt.d.w   $f2, $f2
/* B93C98 80240858 46221080 */  add.d     $f2, $f2, $f2
/* B93C9C 8024085C 46000005 */  abs.s     $f0, $f0
/* B93CA0 80240860 46000021 */  cvt.d.s   $f0, $f0
/* B93CA4 80240864 4620103E */  c.le.d    $f2, $f0
/* B93CA8 80240868 00000000 */  nop
/* B93CAC 8024086C 45030001 */  bc1tl     .L80240874
/* B93CB0 80240870 0000882D */   daddu    $s1, $zero, $zero
.L80240874:
/* B93CB4 80240874 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* B93CB8 80240878 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* B93CBC 8024087C 24020009 */  addiu     $v0, $zero, 9
/* B93CC0 80240880 50620001 */  beql      $v1, $v0, .L80240888
/* B93CC4 80240884 0000882D */   daddu    $s1, $zero, $zero
.L80240888:
/* B93CC8 80240888 24020007 */  addiu     $v0, $zero, 7
/* B93CCC 8024088C 50620001 */  beql      $v1, $v0, .L80240894
/* B93CD0 80240890 0000882D */   daddu    $s1, $zero, $zero
.L80240894:
/* B93CD4 80240894 0220102D */  daddu     $v0, $s1, $zero
/* B93CD8 80240898 8FBF0024 */  lw        $ra, 0x24($sp)
/* B93CDC 8024089C 8FB40020 */  lw        $s4, 0x20($sp)
/* B93CE0 802408A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* B93CE4 802408A4 8FB20018 */  lw        $s2, 0x18($sp)
/* B93CE8 802408A8 8FB10014 */  lw        $s1, 0x14($sp)
/* B93CEC 802408AC 8FB00010 */  lw        $s0, 0x10($sp)
/* B93CF0 802408B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B93CF4 802408B4 03E00008 */  jr        $ra
/* B93CF8 802408B8 27BD0030 */   addiu    $sp, $sp, 0x30
