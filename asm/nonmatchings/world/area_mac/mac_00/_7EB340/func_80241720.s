.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241720
/* 7EC430 80241720 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 7EC434 80241724 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EC438 80241728 0080882D */  daddu     $s1, $a0, $zero
/* 7EC43C 8024172C AFBF0024 */  sw        $ra, 0x24($sp)
/* 7EC440 80241730 AFB40020 */  sw        $s4, 0x20($sp)
/* 7EC444 80241734 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7EC448 80241738 AFB20018 */  sw        $s2, 0x18($sp)
/* 7EC44C 8024173C AFB00010 */  sw        $s0, 0x10($sp)
/* 7EC450 80241740 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 7EC454 80241744 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 7EC458 80241748 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 7EC45C 8024174C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 7EC460 80241750 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 7EC464 80241754 8E30000C */  lw        $s0, 0xc($s1)
/* 7EC468 80241758 8E130000 */  lw        $s3, ($s0)
/* 7EC46C 8024175C 26100004 */  addiu     $s0, $s0, 4
/* 7EC470 80241760 0C0B1EAF */  jal       get_variable
/* 7EC474 80241764 0260282D */   daddu    $a1, $s3, $zero
/* 7EC478 80241768 4482E000 */  mtc1      $v0, $f28
/* 7EC47C 8024176C 00000000 */  nop       
/* 7EC480 80241770 4680E720 */  cvt.s.w   $f28, $f28
/* 7EC484 80241774 8E140000 */  lw        $s4, ($s0)
/* 7EC488 80241778 26100004 */  addiu     $s0, $s0, 4
/* 7EC48C 8024177C 0220202D */  daddu     $a0, $s1, $zero
/* 7EC490 80241780 0C0B1EAF */  jal       get_variable
/* 7EC494 80241784 0280282D */   daddu    $a1, $s4, $zero
/* 7EC498 80241788 4482D000 */  mtc1      $v0, $f26
/* 7EC49C 8024178C 00000000 */  nop       
/* 7EC4A0 80241790 4680D6A0 */  cvt.s.w   $f26, $f26
/* 7EC4A4 80241794 8E100000 */  lw        $s0, ($s0)
/* 7EC4A8 80241798 0220202D */  daddu     $a0, $s1, $zero
/* 7EC4AC 8024179C 0C0B1EAF */  jal       get_variable
/* 7EC4B0 802417A0 0200282D */   daddu    $a1, $s0, $zero
/* 7EC4B4 802417A4 4482C000 */  mtc1      $v0, $f24
/* 7EC4B8 802417A8 00000000 */  nop       
/* 7EC4BC 802417AC 4680C620 */  cvt.s.w   $f24, $f24
/* 7EC4C0 802417B0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 7EC4C4 802417B4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 7EC4C8 802417B8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7EC4CC 802417BC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7EC4D0 802417C0 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 7EC4D4 802417C4 44800000 */  mtc1      $zero, $f0
/* 7EC4D8 802417C8 00031080 */  sll       $v0, $v1, 2
/* 7EC4DC 802417CC 00431021 */  addu      $v0, $v0, $v1
/* 7EC4E0 802417D0 00021080 */  sll       $v0, $v0, 2
/* 7EC4E4 802417D4 00431023 */  subu      $v0, $v0, $v1
/* 7EC4E8 802417D8 000218C0 */  sll       $v1, $v0, 3
/* 7EC4EC 802417DC 00431021 */  addu      $v0, $v0, $v1
/* 7EC4F0 802417E0 000210C0 */  sll       $v0, $v0, 3
/* 7EC4F4 802417E4 46001032 */  c.eq.s    $f2, $f0
/* 7EC4F8 802417E8 3C01800B */  lui       $at, 0x800b
/* 7EC4FC 802417EC 00220821 */  addu      $at, $at, $v0
/* 7EC500 802417F0 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* 7EC504 802417F4 45000005 */  bc1f      .L8024180C
/* 7EC508 802417F8 00000000 */   nop      
/* 7EC50C 802417FC 3C0142C8 */  lui       $at, 0x42c8
/* 7EC510 80241800 44810000 */  mtc1      $at, $f0
/* 7EC514 80241804 08090607 */  j         .L8024181C
/* 7EC518 80241808 4600B581 */   sub.s    $f22, $f22, $f0
.L8024180C:
/* 7EC51C 8024180C 3C0142C8 */  lui       $at, 0x42c8
/* 7EC520 80241810 44810000 */  mtc1      $at, $f0
/* 7EC524 80241814 00000000 */  nop       
/* 7EC528 80241818 4600B580 */  add.s     $f22, $f22, $f0
.L8024181C:
/* 7EC52C 8024181C 0C00A6C9 */  jal       clamp_angle
/* 7EC530 80241820 4600B306 */   mov.s    $f12, $f22
/* 7EC534 80241824 46000586 */  mov.s     $f22, $f0
/* 7EC538 80241828 3C014170 */  lui       $at, 0x4170
/* 7EC53C 8024182C 4481A000 */  mtc1      $at, $f20
/* 7EC540 80241830 0C00A8BB */  jal       sin_deg
/* 7EC544 80241834 4600B306 */   mov.s    $f12, $f22
/* 7EC548 80241838 46140002 */  mul.s     $f0, $f0, $f20
/* 7EC54C 8024183C 00000000 */  nop       
/* 7EC550 80241840 864200B0 */  lh        $v0, 0xb0($s2)
/* 7EC554 80241844 3C013F00 */  lui       $at, 0x3f00
/* 7EC558 80241848 44812000 */  mtc1      $at, $f4
/* 7EC55C 8024184C 44821000 */  mtc1      $v0, $f2
/* 7EC560 80241850 00000000 */  nop       
/* 7EC564 80241854 468010A0 */  cvt.s.w   $f2, $f2
/* 7EC568 80241858 46041082 */  mul.s     $f2, $f2, $f4
/* 7EC56C 8024185C 00000000 */  nop       
/* 7EC570 80241860 4600E700 */  add.s     $f28, $f28, $f0
/* 7EC574 80241864 4602D680 */  add.s     $f26, $f26, $f2
/* 7EC578 80241868 0C00A8D4 */  jal       cos_deg
/* 7EC57C 8024186C 4600B306 */   mov.s    $f12, $f22
/* 7EC580 80241870 46140002 */  mul.s     $f0, $f0, $f20
/* 7EC584 80241874 00000000 */  nop       
/* 7EC588 80241878 0220202D */  daddu     $a0, $s1, $zero
/* 7EC58C 8024187C 0260282D */  daddu     $a1, $s3, $zero
/* 7EC590 80241880 4600E18D */  trunc.w.s $f6, $f28
/* 7EC594 80241884 44063000 */  mfc1      $a2, $f6
/* 7EC598 80241888 0C0B2026 */  jal       set_variable
/* 7EC59C 8024188C 4600C601 */   sub.s    $f24, $f24, $f0
/* 7EC5A0 80241890 0220202D */  daddu     $a0, $s1, $zero
/* 7EC5A4 80241894 4600D18D */  trunc.w.s $f6, $f26
/* 7EC5A8 80241898 44063000 */  mfc1      $a2, $f6
/* 7EC5AC 8024189C 0C0B2026 */  jal       set_variable
/* 7EC5B0 802418A0 0280282D */   daddu    $a1, $s4, $zero
/* 7EC5B4 802418A4 0220202D */  daddu     $a0, $s1, $zero
/* 7EC5B8 802418A8 4600C18D */  trunc.w.s $f6, $f24
/* 7EC5BC 802418AC 44063000 */  mfc1      $a2, $f6
/* 7EC5C0 802418B0 0C0B2026 */  jal       set_variable
/* 7EC5C4 802418B4 0200282D */   daddu    $a1, $s0, $zero
/* 7EC5C8 802418B8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7EC5CC 802418BC 8FB40020 */  lw        $s4, 0x20($sp)
/* 7EC5D0 802418C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7EC5D4 802418C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EC5D8 802418C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EC5DC 802418CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EC5E0 802418D0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 7EC5E4 802418D4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 7EC5E8 802418D8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 7EC5EC 802418DC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 7EC5F0 802418E0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 7EC5F4 802418E4 24020002 */  addiu     $v0, $zero, 2
/* 7EC5F8 802418E8 03E00008 */  jr        $ra
/* 7EC5FC 802418EC 27BD0050 */   addiu    $sp, $sp, 0x50
