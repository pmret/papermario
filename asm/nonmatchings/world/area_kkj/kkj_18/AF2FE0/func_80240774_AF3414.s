.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240774_AF3414
/* AF3414 80240774 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF3418 80240778 AFB00018 */  sw        $s0, 0x18($sp)
/* AF341C 8024077C 0080802D */  daddu     $s0, $a0, $zero
/* AF3420 80240780 3C03800B */  lui       $v1, %hi(gCameras)
/* AF3424 80240784 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* AF3428 80240788 0060202D */  daddu     $a0, $v1, $zero
/* AF342C 8024078C 10A00005 */  beqz      $a1, .L802407A4
/* AF3430 80240790 AFBF001C */   sw       $ra, 0x1c($sp)
/* AF3434 80240794 94620000 */  lhu       $v0, ($v1)
/* AF3438 80240798 34420008 */  ori       $v0, $v0, 8
/* AF343C 8024079C A4620000 */  sh        $v0, ($v1)
/* AF3440 802407A0 AE000070 */  sw        $zero, 0x70($s0)
.L802407A4:
/* AF3444 802407A4 C6000070 */  lwc1      $f0, 0x70($s0)
/* AF3448 802407A8 3C014120 */  lui       $at, 0x4120
/* AF344C 802407AC 44811000 */  mtc1      $at, $f2
/* AF3450 802407B0 00000000 */  nop       
/* AF3454 802407B4 46020000 */  add.s     $f0, $f0, $f2
/* AF3458 802407B8 3C01BF80 */  lui       $at, 0xbf80
/* AF345C 802407BC 44811000 */  mtc1      $at, $f2
/* AF3460 802407C0 E6000070 */  swc1      $f0, 0x70($s0)
/* AF3464 802407C4 44800000 */  mtc1      $zero, $f0
/* AF3468 802407C8 24840194 */  addiu     $a0, $a0, 0x194
/* AF346C 802407CC E7A20010 */  swc1      $f2, 0x10($sp)
/* AF3470 802407D0 44060000 */  mfc1      $a2, $f0
/* AF3474 802407D4 8E050070 */  lw        $a1, 0x70($s0)
/* AF3478 802407D8 0C019EC8 */  jal       guRotateF
/* AF347C 802407DC 00C0382D */   daddu    $a3, $a2, $zero
/* AF3480 802407E0 C6000070 */  lwc1      $f0, 0x70($s0)
/* AF3484 802407E4 3C018024 */  lui       $at, 0x8024
/* AF3488 802407E8 D4224CA0 */  ldc1      $f2, 0x4ca0($at)
/* AF348C 802407EC 46000021 */  cvt.d.s   $f0, $f0
/* AF3490 802407F0 4620103E */  c.le.d    $f2, $f0
/* AF3494 802407F4 00000000 */  nop       
/* AF3498 802407F8 45010002 */  bc1t      .L80240804
/* AF349C 802407FC 24020002 */   addiu    $v0, $zero, 2
/* AF34A0 80240800 0000102D */  daddu     $v0, $zero, $zero
.L80240804:
/* AF34A4 80240804 8FBF001C */  lw        $ra, 0x1c($sp)
/* AF34A8 80240808 8FB00018 */  lw        $s0, 0x18($sp)
/* AF34AC 8024080C 03E00008 */  jr        $ra
/* AF34B0 80240810 27BD0020 */   addiu    $sp, $sp, 0x20
/* AF34B4 80240814 00000000 */  nop       
/* AF34B8 80240818 00000000 */  nop       
/* AF34BC 8024081C 00000000 */  nop       
