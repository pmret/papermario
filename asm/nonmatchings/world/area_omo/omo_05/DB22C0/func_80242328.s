.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242328
/* DB45E8 80242328 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB45EC 8024232C AFB00018 */  sw        $s0, 0x18($sp)
/* DB45F0 80242330 0080802D */  daddu     $s0, $a0, $zero
/* DB45F4 80242334 3C03800B */  lui       $v1, %hi(gCameras)
/* DB45F8 80242338 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DB45FC 8024233C 0060202D */  daddu     $a0, $v1, $zero
/* DB4600 80242340 10A00005 */  beqz      $a1, .L80242358
/* DB4604 80242344 AFBF001C */   sw       $ra, 0x1c($sp)
/* DB4608 80242348 94620000 */  lhu       $v0, ($v1)
/* DB460C 8024234C 34420008 */  ori       $v0, $v0, 8
/* DB4610 80242350 A4620000 */  sh        $v0, ($v1)
/* DB4614 80242354 AE000070 */  sw        $zero, 0x70($s0)
.L80242358:
/* DB4618 80242358 C6000070 */  lwc1      $f0, 0x70($s0)
/* DB461C 8024235C 3C014120 */  lui       $at, 0x4120
/* DB4620 80242360 44811000 */  mtc1      $at, $f2
/* DB4624 80242364 00000000 */  nop       
/* DB4628 80242368 46020000 */  add.s     $f0, $f0, $f2
/* DB462C 8024236C 3C01BF80 */  lui       $at, 0xbf80
/* DB4630 80242370 44811000 */  mtc1      $at, $f2
/* DB4634 80242374 E6000070 */  swc1      $f0, 0x70($s0)
/* DB4638 80242378 44800000 */  mtc1      $zero, $f0
/* DB463C 8024237C 24840194 */  addiu     $a0, $a0, 0x194
/* DB4640 80242380 E7A20010 */  swc1      $f2, 0x10($sp)
/* DB4644 80242384 44060000 */  mfc1      $a2, $f0
/* DB4648 80242388 8E050070 */  lw        $a1, 0x70($s0)
/* DB464C 8024238C 0C019EC8 */  jal       guRotateF
/* DB4650 80242390 00C0382D */   daddu    $a3, $a2, $zero
/* DB4654 80242394 C6000070 */  lwc1      $f0, 0x70($s0)
/* DB4658 80242398 3C018024 */  lui       $at, 0x8024
/* DB465C 8024239C D4225648 */  ldc1      $f2, 0x5648($at)
/* DB4660 802423A0 46000021 */  cvt.d.s   $f0, $f0
/* DB4664 802423A4 4620103E */  c.le.d    $f2, $f0
/* DB4668 802423A8 00000000 */  nop       
/* DB466C 802423AC 45010002 */  bc1t      .L802423B8
/* DB4670 802423B0 24020002 */   addiu    $v0, $zero, 2
/* DB4674 802423B4 0000102D */  daddu     $v0, $zero, $zero
.L802423B8:
/* DB4678 802423B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DB467C 802423BC 8FB00018 */  lw        $s0, 0x18($sp)
/* DB4680 802423C0 03E00008 */  jr        $ra
/* DB4684 802423C4 27BD0020 */   addiu    $sp, $sp, 0x20
