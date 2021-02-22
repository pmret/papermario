.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417CC_ECB4CC
/* ECB4CC 802417CC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* ECB4D0 802417D0 AFB10014 */  sw        $s1, 0x14($sp)
/* ECB4D4 802417D4 0080882D */  daddu     $s1, $a0, $zero
/* ECB4D8 802417D8 AFBF0024 */  sw        $ra, 0x24($sp)
/* ECB4DC 802417DC AFB40020 */  sw        $s4, 0x20($sp)
/* ECB4E0 802417E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* ECB4E4 802417E4 AFB20018 */  sw        $s2, 0x18($sp)
/* ECB4E8 802417E8 AFB00010 */  sw        $s0, 0x10($sp)
/* ECB4EC 802417EC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* ECB4F0 802417F0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* ECB4F4 802417F4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* ECB4F8 802417F8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* ECB4FC 802417FC F7B40028 */  sdc1      $f20, 0x28($sp)
/* ECB500 80241800 8E30000C */  lw        $s0, 0xc($s1)
/* ECB504 80241804 8E130000 */  lw        $s3, ($s0)
/* ECB508 80241808 26100004 */  addiu     $s0, $s0, 4
/* ECB50C 8024180C 0C0B53A3 */  jal       func_802D4E8C
/* ECB510 80241810 0260282D */   daddu    $a1, $s3, $zero
/* ECB514 80241814 4482E000 */  mtc1      $v0, $f28
/* ECB518 80241818 00000000 */  nop
/* ECB51C 8024181C 4680E720 */  cvt.s.w   $f28, $f28
/* ECB520 80241820 8E140000 */  lw        $s4, ($s0)
/* ECB524 80241824 26100004 */  addiu     $s0, $s0, 4
/* ECB528 80241828 0220202D */  daddu     $a0, $s1, $zero
/* ECB52C 8024182C 0C0B53A3 */  jal       func_802D4E8C
/* ECB530 80241830 0280282D */   daddu    $a1, $s4, $zero
/* ECB534 80241834 4482D000 */  mtc1      $v0, $f26
/* ECB538 80241838 00000000 */  nop
/* ECB53C 8024183C 4680D6A0 */  cvt.s.w   $f26, $f26
/* ECB540 80241840 8E100000 */  lw        $s0, ($s0)
/* ECB544 80241844 0220202D */  daddu     $a0, $s1, $zero
/* ECB548 80241848 0C0B53A3 */  jal       func_802D4E8C
/* ECB54C 8024184C 0200282D */   daddu    $a1, $s0, $zero
/* ECB550 80241850 4482C000 */  mtc1      $v0, $f24
/* ECB554 80241854 00000000 */  nop
/* ECB558 80241858 4680C620 */  cvt.s.w   $f24, $f24
/* ECB55C 8024185C 3C128011 */  lui       $s2, %hi(D_80117578)
/* ECB560 80241860 26527578 */  addiu     $s2, $s2, %lo(D_80117578)
/* ECB564 80241864 3C038008 */  lui       $v1, %hi(D_8007C760)
/* ECB568 80241868 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* ECB56C 8024186C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* ECB570 80241870 44800000 */  mtc1      $zero, $f0
/* ECB574 80241874 00031080 */  sll       $v0, $v1, 2
/* ECB578 80241878 00431021 */  addu      $v0, $v0, $v1
/* ECB57C 8024187C 00021080 */  sll       $v0, $v0, 2
/* ECB580 80241880 00431023 */  subu      $v0, $v0, $v1
/* ECB584 80241884 000218C0 */  sll       $v1, $v0, 3
/* ECB588 80241888 00431021 */  addu      $v0, $v0, $v1
/* ECB58C 8024188C 000210C0 */  sll       $v0, $v0, 3
/* ECB590 80241890 46001032 */  c.eq.s    $f2, $f0
/* ECB594 80241894 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* ECB598 80241898 00220821 */  addu      $at, $at, $v0
/* ECB59C 8024189C C4368DEC */  lwc1      $f22, %lo(D_800B8DEC)($at)
/* ECB5A0 802418A0 45000005 */  bc1f      .L802418B8
/* ECB5A4 802418A4 00000000 */   nop
/* ECB5A8 802418A8 3C0142C8 */  lui       $at, 0x42c8
/* ECB5AC 802418AC 44810000 */  mtc1      $at, $f0
/* ECB5B0 802418B0 08090632 */  j         .L802418C8
/* ECB5B4 802418B4 4600B581 */   sub.s    $f22, $f22, $f0
.L802418B8:
/* ECB5B8 802418B8 3C0142C8 */  lui       $at, 0x42c8
/* ECB5BC 802418BC 44810000 */  mtc1      $at, $f0
/* ECB5C0 802418C0 00000000 */  nop
/* ECB5C4 802418C4 4600B580 */  add.s     $f22, $f22, $f0
.L802418C8:
/* ECB5C8 802418C8 0C00AB85 */  jal       func_8002AE14
/* ECB5CC 802418CC 4600B306 */   mov.s    $f12, $f22
/* ECB5D0 802418D0 46000586 */  mov.s     $f22, $f0
/* ECB5D4 802418D4 3C014170 */  lui       $at, 0x4170
/* ECB5D8 802418D8 4481A000 */  mtc1      $at, $f20
/* ECB5DC 802418DC 0C00AD77 */  jal       func_8002B5DC
/* ECB5E0 802418E0 4600B306 */   mov.s    $f12, $f22
/* ECB5E4 802418E4 46140002 */  mul.s     $f0, $f0, $f20
/* ECB5E8 802418E8 00000000 */  nop
/* ECB5EC 802418EC 864200B0 */  lh        $v0, 0xb0($s2)
/* ECB5F0 802418F0 3C013F00 */  lui       $at, 0x3f00
/* ECB5F4 802418F4 44812000 */  mtc1      $at, $f4
/* ECB5F8 802418F8 44821000 */  mtc1      $v0, $f2
/* ECB5FC 802418FC 00000000 */  nop
/* ECB600 80241900 468010A0 */  cvt.s.w   $f2, $f2
/* ECB604 80241904 46041082 */  mul.s     $f2, $f2, $f4
/* ECB608 80241908 00000000 */  nop
/* ECB60C 8024190C 4600E700 */  add.s     $f28, $f28, $f0
/* ECB610 80241910 4602D680 */  add.s     $f26, $f26, $f2
/* ECB614 80241914 0C00AD90 */  jal       func_8002B640
/* ECB618 80241918 4600B306 */   mov.s    $f12, $f22
/* ECB61C 8024191C 46140002 */  mul.s     $f0, $f0, $f20
/* ECB620 80241920 00000000 */  nop
/* ECB624 80241924 0220202D */  daddu     $a0, $s1, $zero
/* ECB628 80241928 0260282D */  daddu     $a1, $s3, $zero
/* ECB62C 8024192C 4600E18D */  trunc.w.s $f6, $f28
/* ECB630 80241930 44063000 */  mfc1      $a2, $f6
/* ECB634 80241934 0C0B551A */  jal       func_802D5468
/* ECB638 80241938 4600C601 */   sub.s    $f24, $f24, $f0
/* ECB63C 8024193C 0220202D */  daddu     $a0, $s1, $zero
/* ECB640 80241940 4600D18D */  trunc.w.s $f6, $f26
/* ECB644 80241944 44063000 */  mfc1      $a2, $f6
/* ECB648 80241948 0C0B551A */  jal       func_802D5468
/* ECB64C 8024194C 0280282D */   daddu    $a1, $s4, $zero
/* ECB650 80241950 0220202D */  daddu     $a0, $s1, $zero
/* ECB654 80241954 4600C18D */  trunc.w.s $f6, $f24
/* ECB658 80241958 44063000 */  mfc1      $a2, $f6
/* ECB65C 8024195C 0C0B551A */  jal       func_802D5468
/* ECB660 80241960 0200282D */   daddu    $a1, $s0, $zero
/* ECB664 80241964 8FBF0024 */  lw        $ra, 0x24($sp)
/* ECB668 80241968 8FB40020 */  lw        $s4, 0x20($sp)
/* ECB66C 8024196C 8FB3001C */  lw        $s3, 0x1c($sp)
/* ECB670 80241970 8FB20018 */  lw        $s2, 0x18($sp)
/* ECB674 80241974 8FB10014 */  lw        $s1, 0x14($sp)
/* ECB678 80241978 8FB00010 */  lw        $s0, 0x10($sp)
/* ECB67C 8024197C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* ECB680 80241980 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* ECB684 80241984 D7B80038 */  ldc1      $f24, 0x38($sp)
/* ECB688 80241988 D7B60030 */  ldc1      $f22, 0x30($sp)
/* ECB68C 8024198C D7B40028 */  ldc1      $f20, 0x28($sp)
/* ECB690 80241990 24020002 */  addiu     $v0, $zero, 2
/* ECB694 80241994 03E00008 */  jr        $ra
/* ECB698 80241998 27BD0050 */   addiu    $sp, $sp, 0x50
