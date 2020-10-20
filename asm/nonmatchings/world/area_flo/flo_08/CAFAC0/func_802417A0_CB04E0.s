.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A0_CB04E0
/* CB04E0 802417A0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CB04E4 802417A4 AFB10014 */  sw        $s1, 0x14($sp)
/* CB04E8 802417A8 0080882D */  daddu     $s1, $a0, $zero
/* CB04EC 802417AC AFBF0024 */  sw        $ra, 0x24($sp)
/* CB04F0 802417B0 AFB40020 */  sw        $s4, 0x20($sp)
/* CB04F4 802417B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* CB04F8 802417B8 AFB20018 */  sw        $s2, 0x18($sp)
/* CB04FC 802417BC AFB00010 */  sw        $s0, 0x10($sp)
/* CB0500 802417C0 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CB0504 802417C4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CB0508 802417C8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* CB050C 802417CC F7B60030 */  sdc1      $f22, 0x30($sp)
/* CB0510 802417D0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CB0514 802417D4 8E30000C */  lw        $s0, 0xc($s1)
/* CB0518 802417D8 8E130000 */  lw        $s3, ($s0)
/* CB051C 802417DC 26100004 */  addiu     $s0, $s0, 4
/* CB0520 802417E0 0C0B1EAF */  jal       get_variable
/* CB0524 802417E4 0260282D */   daddu    $a1, $s3, $zero
/* CB0528 802417E8 4482E000 */  mtc1      $v0, $f28
/* CB052C 802417EC 00000000 */  nop       
/* CB0530 802417F0 4680E720 */  cvt.s.w   $f28, $f28
/* CB0534 802417F4 8E140000 */  lw        $s4, ($s0)
/* CB0538 802417F8 26100004 */  addiu     $s0, $s0, 4
/* CB053C 802417FC 0220202D */  daddu     $a0, $s1, $zero
/* CB0540 80241800 0C0B1EAF */  jal       get_variable
/* CB0544 80241804 0280282D */   daddu    $a1, $s4, $zero
/* CB0548 80241808 4482D000 */  mtc1      $v0, $f26
/* CB054C 8024180C 00000000 */  nop       
/* CB0550 80241810 4680D6A0 */  cvt.s.w   $f26, $f26
/* CB0554 80241814 8E100000 */  lw        $s0, ($s0)
/* CB0558 80241818 0220202D */  daddu     $a0, $s1, $zero
/* CB055C 8024181C 0C0B1EAF */  jal       get_variable
/* CB0560 80241820 0200282D */   daddu    $a1, $s0, $zero
/* CB0564 80241824 4482C000 */  mtc1      $v0, $f24
/* CB0568 80241828 00000000 */  nop       
/* CB056C 8024182C 4680C620 */  cvt.s.w   $f24, $f24
/* CB0570 80241830 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CB0574 80241834 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CB0578 80241838 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CB057C 8024183C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CB0580 80241840 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* CB0584 80241844 44800000 */  mtc1      $zero, $f0
/* CB0588 80241848 00031080 */  sll       $v0, $v1, 2
/* CB058C 8024184C 00431021 */  addu      $v0, $v0, $v1
/* CB0590 80241850 00021080 */  sll       $v0, $v0, 2
/* CB0594 80241854 00431023 */  subu      $v0, $v0, $v1
/* CB0598 80241858 000218C0 */  sll       $v1, $v0, 3
/* CB059C 8024185C 00431021 */  addu      $v0, $v0, $v1
/* CB05A0 80241860 000210C0 */  sll       $v0, $v0, 3
/* CB05A4 80241864 46001032 */  c.eq.s    $f2, $f0
/* CB05A8 80241868 3C01800B */  lui       $at, 0x800b
/* CB05AC 8024186C 00220821 */  addu      $at, $at, $v0
/* CB05B0 80241870 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* CB05B4 80241874 45000005 */  bc1f      .L8024188C
/* CB05B8 80241878 00000000 */   nop      
/* CB05BC 8024187C 3C0142C8 */  lui       $at, 0x42c8
/* CB05C0 80241880 44810000 */  mtc1      $at, $f0
/* CB05C4 80241884 08090627 */  j         .L8024189C
/* CB05C8 80241888 4600B581 */   sub.s    $f22, $f22, $f0
.L8024188C:
/* CB05CC 8024188C 3C0142C8 */  lui       $at, 0x42c8
/* CB05D0 80241890 44810000 */  mtc1      $at, $f0
/* CB05D4 80241894 00000000 */  nop       
/* CB05D8 80241898 4600B580 */  add.s     $f22, $f22, $f0
.L8024189C:
/* CB05DC 8024189C 0C00A6C9 */  jal       clamp_angle
/* CB05E0 802418A0 4600B306 */   mov.s    $f12, $f22
/* CB05E4 802418A4 46000586 */  mov.s     $f22, $f0
/* CB05E8 802418A8 3C014170 */  lui       $at, 0x4170
/* CB05EC 802418AC 4481A000 */  mtc1      $at, $f20
/* CB05F0 802418B0 0C00A8BB */  jal       sin_deg
/* CB05F4 802418B4 4600B306 */   mov.s    $f12, $f22
/* CB05F8 802418B8 46140002 */  mul.s     $f0, $f0, $f20
/* CB05FC 802418BC 00000000 */  nop       
/* CB0600 802418C0 864200B0 */  lh        $v0, 0xb0($s2)
/* CB0604 802418C4 3C013F00 */  lui       $at, 0x3f00
/* CB0608 802418C8 44812000 */  mtc1      $at, $f4
/* CB060C 802418CC 44821000 */  mtc1      $v0, $f2
/* CB0610 802418D0 00000000 */  nop       
/* CB0614 802418D4 468010A0 */  cvt.s.w   $f2, $f2
/* CB0618 802418D8 46041082 */  mul.s     $f2, $f2, $f4
/* CB061C 802418DC 00000000 */  nop       
/* CB0620 802418E0 4600E700 */  add.s     $f28, $f28, $f0
/* CB0624 802418E4 4602D680 */  add.s     $f26, $f26, $f2
/* CB0628 802418E8 0C00A8D4 */  jal       cos_deg
/* CB062C 802418EC 4600B306 */   mov.s    $f12, $f22
/* CB0630 802418F0 46140002 */  mul.s     $f0, $f0, $f20
/* CB0634 802418F4 00000000 */  nop       
/* CB0638 802418F8 0220202D */  daddu     $a0, $s1, $zero
/* CB063C 802418FC 0260282D */  daddu     $a1, $s3, $zero
/* CB0640 80241900 4600E18D */  trunc.w.s $f6, $f28
/* CB0644 80241904 44063000 */  mfc1      $a2, $f6
/* CB0648 80241908 0C0B2026 */  jal       set_variable
/* CB064C 8024190C 4600C601 */   sub.s    $f24, $f24, $f0
/* CB0650 80241910 0220202D */  daddu     $a0, $s1, $zero
/* CB0654 80241914 4600D18D */  trunc.w.s $f6, $f26
/* CB0658 80241918 44063000 */  mfc1      $a2, $f6
/* CB065C 8024191C 0C0B2026 */  jal       set_variable
/* CB0660 80241920 0280282D */   daddu    $a1, $s4, $zero
/* CB0664 80241924 0220202D */  daddu     $a0, $s1, $zero
/* CB0668 80241928 4600C18D */  trunc.w.s $f6, $f24
/* CB066C 8024192C 44063000 */  mfc1      $a2, $f6
/* CB0670 80241930 0C0B2026 */  jal       set_variable
/* CB0674 80241934 0200282D */   daddu    $a1, $s0, $zero
/* CB0678 80241938 8FBF0024 */  lw        $ra, 0x24($sp)
/* CB067C 8024193C 8FB40020 */  lw        $s4, 0x20($sp)
/* CB0680 80241940 8FB3001C */  lw        $s3, 0x1c($sp)
/* CB0684 80241944 8FB20018 */  lw        $s2, 0x18($sp)
/* CB0688 80241948 8FB10014 */  lw        $s1, 0x14($sp)
/* CB068C 8024194C 8FB00010 */  lw        $s0, 0x10($sp)
/* CB0690 80241950 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CB0694 80241954 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CB0698 80241958 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CB069C 8024195C D7B60030 */  ldc1      $f22, 0x30($sp)
/* CB06A0 80241960 D7B40028 */  ldc1      $f20, 0x28($sp)
/* CB06A4 80241964 24020002 */  addiu     $v0, $zero, 2
/* CB06A8 80241968 03E00008 */  jr        $ra
/* CB06AC 8024196C 27BD0050 */   addiu    $sp, $sp, 0x50
