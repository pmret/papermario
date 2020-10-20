.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D4_AB04C4
/* AB04C4 802404D4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AB04C8 802404D8 AFB10014 */  sw        $s1, 0x14($sp)
/* AB04CC 802404DC 0080882D */  daddu     $s1, $a0, $zero
/* AB04D0 802404E0 AFBF0024 */  sw        $ra, 0x24($sp)
/* AB04D4 802404E4 AFB40020 */  sw        $s4, 0x20($sp)
/* AB04D8 802404E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* AB04DC 802404EC AFB20018 */  sw        $s2, 0x18($sp)
/* AB04E0 802404F0 AFB00010 */  sw        $s0, 0x10($sp)
/* AB04E4 802404F4 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* AB04E8 802404F8 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* AB04EC 802404FC F7B80038 */  sdc1      $f24, 0x38($sp)
/* AB04F0 80240500 F7B60030 */  sdc1      $f22, 0x30($sp)
/* AB04F4 80240504 F7B40028 */  sdc1      $f20, 0x28($sp)
/* AB04F8 80240508 8E30000C */  lw        $s0, 0xc($s1)
/* AB04FC 8024050C 8E130000 */  lw        $s3, ($s0)
/* AB0500 80240510 26100004 */  addiu     $s0, $s0, 4
/* AB0504 80240514 0C0B1EAF */  jal       get_variable
/* AB0508 80240518 0260282D */   daddu    $a1, $s3, $zero
/* AB050C 8024051C 4482E000 */  mtc1      $v0, $f28
/* AB0510 80240520 00000000 */  nop       
/* AB0514 80240524 4680E720 */  cvt.s.w   $f28, $f28
/* AB0518 80240528 8E140000 */  lw        $s4, ($s0)
/* AB051C 8024052C 26100004 */  addiu     $s0, $s0, 4
/* AB0520 80240530 0220202D */  daddu     $a0, $s1, $zero
/* AB0524 80240534 0C0B1EAF */  jal       get_variable
/* AB0528 80240538 0280282D */   daddu    $a1, $s4, $zero
/* AB052C 8024053C 4482D000 */  mtc1      $v0, $f26
/* AB0530 80240540 00000000 */  nop       
/* AB0534 80240544 4680D6A0 */  cvt.s.w   $f26, $f26
/* AB0538 80240548 8E100000 */  lw        $s0, ($s0)
/* AB053C 8024054C 0220202D */  daddu     $a0, $s1, $zero
/* AB0540 80240550 0C0B1EAF */  jal       get_variable
/* AB0544 80240554 0200282D */   daddu    $a1, $s0, $zero
/* AB0548 80240558 4482C000 */  mtc1      $v0, $f24
/* AB054C 8024055C 00000000 */  nop       
/* AB0550 80240560 4680C620 */  cvt.s.w   $f24, $f24
/* AB0554 80240564 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AB0558 80240568 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AB055C 8024056C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* AB0560 80240570 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* AB0564 80240574 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* AB0568 80240578 44800000 */  mtc1      $zero, $f0
/* AB056C 8024057C 00031080 */  sll       $v0, $v1, 2
/* AB0570 80240580 00431021 */  addu      $v0, $v0, $v1
/* AB0574 80240584 00021080 */  sll       $v0, $v0, 2
/* AB0578 80240588 00431023 */  subu      $v0, $v0, $v1
/* AB057C 8024058C 000218C0 */  sll       $v1, $v0, 3
/* AB0580 80240590 00431021 */  addu      $v0, $v0, $v1
/* AB0584 80240594 000210C0 */  sll       $v0, $v0, 3
/* AB0588 80240598 46001032 */  c.eq.s    $f2, $f0
/* AB058C 8024059C 3C01800B */  lui       $at, 0x800b
/* AB0590 802405A0 00220821 */  addu      $at, $at, $v0
/* AB0594 802405A4 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* AB0598 802405A8 45000005 */  bc1f      .L802405C0
/* AB059C 802405AC 00000000 */   nop      
/* AB05A0 802405B0 3C0142C8 */  lui       $at, 0x42c8
/* AB05A4 802405B4 44810000 */  mtc1      $at, $f0
/* AB05A8 802405B8 08090174 */  j         .L802405D0
/* AB05AC 802405BC 4600B581 */   sub.s    $f22, $f22, $f0
.L802405C0:
/* AB05B0 802405C0 3C0142C8 */  lui       $at, 0x42c8
/* AB05B4 802405C4 44810000 */  mtc1      $at, $f0
/* AB05B8 802405C8 00000000 */  nop       
/* AB05BC 802405CC 4600B580 */  add.s     $f22, $f22, $f0
.L802405D0:
/* AB05C0 802405D0 0C00A6C9 */  jal       clamp_angle
/* AB05C4 802405D4 4600B306 */   mov.s    $f12, $f22
/* AB05C8 802405D8 46000586 */  mov.s     $f22, $f0
/* AB05CC 802405DC 3C014170 */  lui       $at, 0x4170
/* AB05D0 802405E0 4481A000 */  mtc1      $at, $f20
/* AB05D4 802405E4 0C00A8BB */  jal       sin_deg
/* AB05D8 802405E8 4600B306 */   mov.s    $f12, $f22
/* AB05DC 802405EC 46140002 */  mul.s     $f0, $f0, $f20
/* AB05E0 802405F0 00000000 */  nop       
/* AB05E4 802405F4 864200B0 */  lh        $v0, 0xb0($s2)
/* AB05E8 802405F8 3C013F00 */  lui       $at, 0x3f00
/* AB05EC 802405FC 44812000 */  mtc1      $at, $f4
/* AB05F0 80240600 44821000 */  mtc1      $v0, $f2
/* AB05F4 80240604 00000000 */  nop       
/* AB05F8 80240608 468010A0 */  cvt.s.w   $f2, $f2
/* AB05FC 8024060C 46041082 */  mul.s     $f2, $f2, $f4
/* AB0600 80240610 00000000 */  nop       
/* AB0604 80240614 4600E700 */  add.s     $f28, $f28, $f0
/* AB0608 80240618 4602D680 */  add.s     $f26, $f26, $f2
/* AB060C 8024061C 0C00A8D4 */  jal       cos_deg
/* AB0610 80240620 4600B306 */   mov.s    $f12, $f22
/* AB0614 80240624 46140002 */  mul.s     $f0, $f0, $f20
/* AB0618 80240628 00000000 */  nop       
/* AB061C 8024062C 0220202D */  daddu     $a0, $s1, $zero
/* AB0620 80240630 0260282D */  daddu     $a1, $s3, $zero
/* AB0624 80240634 4600E18D */  trunc.w.s $f6, $f28
/* AB0628 80240638 44063000 */  mfc1      $a2, $f6
/* AB062C 8024063C 0C0B2026 */  jal       set_variable
/* AB0630 80240640 4600C601 */   sub.s    $f24, $f24, $f0
/* AB0634 80240644 0220202D */  daddu     $a0, $s1, $zero
/* AB0638 80240648 4600D18D */  trunc.w.s $f6, $f26
/* AB063C 8024064C 44063000 */  mfc1      $a2, $f6
/* AB0640 80240650 0C0B2026 */  jal       set_variable
/* AB0644 80240654 0280282D */   daddu    $a1, $s4, $zero
/* AB0648 80240658 0220202D */  daddu     $a0, $s1, $zero
/* AB064C 8024065C 4600C18D */  trunc.w.s $f6, $f24
/* AB0650 80240660 44063000 */  mfc1      $a2, $f6
/* AB0654 80240664 0C0B2026 */  jal       set_variable
/* AB0658 80240668 0200282D */   daddu    $a1, $s0, $zero
/* AB065C 8024066C 8FBF0024 */  lw        $ra, 0x24($sp)
/* AB0660 80240670 8FB40020 */  lw        $s4, 0x20($sp)
/* AB0664 80240674 8FB3001C */  lw        $s3, 0x1c($sp)
/* AB0668 80240678 8FB20018 */  lw        $s2, 0x18($sp)
/* AB066C 8024067C 8FB10014 */  lw        $s1, 0x14($sp)
/* AB0670 80240680 8FB00010 */  lw        $s0, 0x10($sp)
/* AB0674 80240684 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* AB0678 80240688 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* AB067C 8024068C D7B80038 */  ldc1      $f24, 0x38($sp)
/* AB0680 80240690 D7B60030 */  ldc1      $f22, 0x30($sp)
/* AB0684 80240694 D7B40028 */  ldc1      $f20, 0x28($sp)
/* AB0688 80240698 24020002 */  addiu     $v0, $zero, 2
/* AB068C 8024069C 03E00008 */  jr        $ra
/* AB0690 802406A0 27BD0050 */   addiu    $sp, $sp, 0x50
