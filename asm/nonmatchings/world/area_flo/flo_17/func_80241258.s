.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241258
/* CD8538 80241258 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CD853C 8024125C AFB00028 */  sw        $s0, 0x28($sp)
/* CD8540 80241260 00A0802D */  daddu     $s0, $a1, $zero
/* CD8544 80241264 AFB1002C */  sw        $s1, 0x2c($sp)
/* CD8548 80241268 00C0882D */  daddu     $s1, $a2, $zero
/* CD854C 8024126C AFBF0034 */  sw        $ra, 0x34($sp)
/* CD8550 80241270 AFB20030 */  sw        $s2, 0x30($sp)
/* CD8554 80241274 AE200070 */  sw        $zero, 0x70($s1)
/* CD8558 80241278 8C830000 */  lw        $v1, ($a0)
/* CD855C 8024127C 2402FDFF */  addiu     $v0, $zero, -0x201
/* CD8560 80241280 A480008E */  sh        $zero, 0x8e($a0)
/* CD8564 80241284 00621824 */  and       $v1, $v1, $v0
/* CD8568 80241288 34650800 */  ori       $a1, $v1, 0x800
/* CD856C 8024128C AC850000 */  sw        $a1, ($a0)
/* CD8570 80241290 8E0200D0 */  lw        $v0, 0xd0($s0)
/* CD8574 80241294 8C420034 */  lw        $v0, 0x34($v0)
/* CD8578 80241298 10400003 */  beqz      $v0, .L802412A8
/* CD857C 8024129C 00E0902D */   daddu    $s2, $a3, $zero
/* CD8580 802412A0 080904AC */  j         .L802412B0
/* CD8584 802412A4 34620808 */   ori      $v0, $v1, 0x808
.L802412A8:
/* CD8588 802412A8 2402FFF7 */  addiu     $v0, $zero, -9
/* CD858C 802412AC 00A21024 */  and       $v0, $a1, $v0
.L802412B0:
/* CD8590 802412B0 AC820000 */  sw        $v0, ($a0)
/* CD8594 802412B4 27A20024 */  addiu     $v0, $sp, 0x24
/* CD8598 802412B8 27A50018 */  addiu     $a1, $sp, 0x18
/* CD859C 802412BC C4800038 */  lwc1      $f0, 0x38($a0)
/* CD85A0 802412C0 C482003C */  lwc1      $f2, 0x3c($a0)
/* CD85A4 802412C4 C4840040 */  lwc1      $f4, 0x40($a0)
/* CD85A8 802412C8 3C01447A */  lui       $at, 0x447a
/* CD85AC 802412CC 44813000 */  mtc1      $at, $f6
/* CD85B0 802412D0 27A6001C */  addiu     $a2, $sp, 0x1c
/* CD85B4 802412D4 E7A00018 */  swc1      $f0, 0x18($sp)
/* CD85B8 802412D8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* CD85BC 802412DC E7A40020 */  swc1      $f4, 0x20($sp)
/* CD85C0 802412E0 E7A60024 */  swc1      $f6, 0x24($sp)
/* CD85C4 802412E4 AFA20010 */  sw        $v0, 0x10($sp)
/* CD85C8 802412E8 8C840080 */  lw        $a0, 0x80($a0)
/* CD85CC 802412EC 0C0372DF */  jal       func_800DCB7C
/* CD85D0 802412F0 27A70020 */   addiu    $a3, $sp, 0x20
/* CD85D4 802412F4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* CD85D8 802412F8 3C014059 */  lui       $at, 0x4059
/* CD85DC 802412FC 44812800 */  mtc1      $at, $f5
/* CD85E0 80241300 44802000 */  mtc1      $zero, $f4
/* CD85E4 80241304 460010A1 */  cvt.d.s   $f2, $f2
/* CD85E8 80241308 46241082 */  mul.d     $f2, $f2, $f4
/* CD85EC 8024130C 00000000 */  nop       
/* CD85F0 80241310 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CD85F4 80241314 46000021 */  cvt.d.s   $f0, $f0
/* CD85F8 80241318 46240002 */  mul.d     $f0, $f0, $f4
/* CD85FC 8024131C 00000000 */  nop       
/* CD8600 80241320 3C013FE0 */  lui       $at, 0x3fe0
/* CD8604 80241324 44812800 */  mtc1      $at, $f5
/* CD8608 80241328 44802000 */  mtc1      $zero, $f4
/* CD860C 8024132C 00000000 */  nop       
/* CD8610 80241330 46241080 */  add.d     $f2, $f2, $f4
/* CD8614 80241334 AE000074 */  sw        $zero, 0x74($s0)
/* CD8618 80241338 46240000 */  add.d     $f0, $f0, $f4
/* CD861C 8024133C AE000090 */  sw        $zero, 0x90($s0)
/* CD8620 80241340 4620120D */  trunc.w.d $f8, $f2
/* CD8624 80241344 E6080078 */  swc1      $f8, 0x78($s0)
/* CD8628 80241348 4620020D */  trunc.w.d $f8, $f0
/* CD862C 8024134C E6080088 */  swc1      $f8, 0x88($s0)
/* CD8630 80241350 8E420014 */  lw        $v0, 0x14($s2)
/* CD8634 80241354 AE220074 */  sw        $v0, 0x74($s1)
/* CD8638 80241358 8E0200B0 */  lw        $v0, 0xb0($s0)
/* CD863C 8024135C 34420010 */  ori       $v0, $v0, 0x10
/* CD8640 80241360 AE0200B0 */  sw        $v0, 0xb0($s0)
/* CD8644 80241364 8FBF0034 */  lw        $ra, 0x34($sp)
/* CD8648 80241368 8FB20030 */  lw        $s2, 0x30($sp)
/* CD864C 8024136C 8FB1002C */  lw        $s1, 0x2c($sp)
/* CD8650 80241370 8FB00028 */  lw        $s0, 0x28($sp)
/* CD8654 80241374 03E00008 */  jr        $ra
/* CD8658 80241378 27BD0038 */   addiu    $sp, $sp, 0x38
