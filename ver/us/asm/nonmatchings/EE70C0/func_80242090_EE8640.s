.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242090_EE8640
/* EE8640 80242090 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EE8644 80242094 AFB10014 */  sw        $s1, 0x14($sp)
/* EE8648 80242098 0080882D */  daddu     $s1, $a0, $zero
/* EE864C 8024209C AFBF0024 */  sw        $ra, 0x24($sp)
/* EE8650 802420A0 AFB40020 */  sw        $s4, 0x20($sp)
/* EE8654 802420A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* EE8658 802420A8 AFB20018 */  sw        $s2, 0x18($sp)
/* EE865C 802420AC AFB00010 */  sw        $s0, 0x10($sp)
/* EE8660 802420B0 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* EE8664 802420B4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* EE8668 802420B8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* EE866C 802420BC F7B60030 */  sdc1      $f22, 0x30($sp)
/* EE8670 802420C0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EE8674 802420C4 8E30000C */  lw        $s0, 0xc($s1)
/* EE8678 802420C8 8E130000 */  lw        $s3, ($s0)
/* EE867C 802420CC 26100004 */  addiu     $s0, $s0, 4
/* EE8680 802420D0 0C0B53A3 */  jal       dead_get_variable
/* EE8684 802420D4 0260282D */   daddu    $a1, $s3, $zero
/* EE8688 802420D8 4482E000 */  mtc1      $v0, $f28
/* EE868C 802420DC 00000000 */  nop
/* EE8690 802420E0 4680E720 */  cvt.s.w   $f28, $f28
/* EE8694 802420E4 8E140000 */  lw        $s4, ($s0)
/* EE8698 802420E8 26100004 */  addiu     $s0, $s0, 4
/* EE869C 802420EC 0220202D */  daddu     $a0, $s1, $zero
/* EE86A0 802420F0 0C0B53A3 */  jal       dead_get_variable
/* EE86A4 802420F4 0280282D */   daddu    $a1, $s4, $zero
/* EE86A8 802420F8 4482D000 */  mtc1      $v0, $f26
/* EE86AC 802420FC 00000000 */  nop
/* EE86B0 80242100 4680D6A0 */  cvt.s.w   $f26, $f26
/* EE86B4 80242104 8E100000 */  lw        $s0, ($s0)
/* EE86B8 80242108 0220202D */  daddu     $a0, $s1, $zero
/* EE86BC 8024210C 0C0B53A3 */  jal       dead_get_variable
/* EE86C0 80242110 0200282D */   daddu    $a1, $s0, $zero
/* EE86C4 80242114 4482C000 */  mtc1      $v0, $f24
/* EE86C8 80242118 00000000 */  nop
/* EE86CC 8024211C 4680C620 */  cvt.s.w   $f24, $f24
/* EE86D0 80242120 3C128011 */  lui       $s2, %hi(D_80117578)
/* EE86D4 80242124 26527578 */  addiu     $s2, $s2, %lo(D_80117578)
/* EE86D8 80242128 3C038008 */  lui       $v1, %hi(D_8007C760)
/* EE86DC 8024212C 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* EE86E0 80242130 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* EE86E4 80242134 44800000 */  mtc1      $zero, $f0
/* EE86E8 80242138 00031080 */  sll       $v0, $v1, 2
/* EE86EC 8024213C 00431021 */  addu      $v0, $v0, $v1
/* EE86F0 80242140 00021080 */  sll       $v0, $v0, 2
/* EE86F4 80242144 00431023 */  subu      $v0, $v0, $v1
/* EE86F8 80242148 000218C0 */  sll       $v1, $v0, 3
/* EE86FC 8024214C 00431021 */  addu      $v0, $v0, $v1
/* EE8700 80242150 000210C0 */  sll       $v0, $v0, 3
/* EE8704 80242154 46001032 */  c.eq.s    $f2, $f0
/* EE8708 80242158 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EE870C 8024215C 00220821 */  addu      $at, $at, $v0
/* EE8710 80242160 C4368DEC */  lwc1      $f22, %lo(D_800B8DEC)($at)
/* EE8714 80242164 45000005 */  bc1f      .L8024217C
/* EE8718 80242168 00000000 */   nop
/* EE871C 8024216C 3C0142C8 */  lui       $at, 0x42c8
/* EE8720 80242170 44810000 */  mtc1      $at, $f0
/* EE8724 80242174 08090863 */  j         .L8024218C
/* EE8728 80242178 4600B581 */   sub.s    $f22, $f22, $f0
.L8024217C:
/* EE872C 8024217C 3C0142C8 */  lui       $at, 0x42c8
/* EE8730 80242180 44810000 */  mtc1      $at, $f0
/* EE8734 80242184 00000000 */  nop
/* EE8738 80242188 4600B580 */  add.s     $f22, $f22, $f0
.L8024218C:
/* EE873C 8024218C 0C00AB85 */  jal       func_8002AE14
/* EE8740 80242190 4600B306 */   mov.s    $f12, $f22
/* EE8744 80242194 46000586 */  mov.s     $f22, $f0
/* EE8748 80242198 3C014170 */  lui       $at, 0x4170
/* EE874C 8024219C 4481A000 */  mtc1      $at, $f20
/* EE8750 802421A0 0C00AD77 */  jal       func_8002B5DC
/* EE8754 802421A4 4600B306 */   mov.s    $f12, $f22
/* EE8758 802421A8 46140002 */  mul.s     $f0, $f0, $f20
/* EE875C 802421AC 00000000 */  nop
/* EE8760 802421B0 864200B0 */  lh        $v0, 0xb0($s2)
/* EE8764 802421B4 3C013F00 */  lui       $at, 0x3f00
/* EE8768 802421B8 44812000 */  mtc1      $at, $f4
/* EE876C 802421BC 44821000 */  mtc1      $v0, $f2
/* EE8770 802421C0 00000000 */  nop
/* EE8774 802421C4 468010A0 */  cvt.s.w   $f2, $f2
/* EE8778 802421C8 46041082 */  mul.s     $f2, $f2, $f4
/* EE877C 802421CC 00000000 */  nop
/* EE8780 802421D0 4600E700 */  add.s     $f28, $f28, $f0
/* EE8784 802421D4 4602D680 */  add.s     $f26, $f26, $f2
/* EE8788 802421D8 0C00AD90 */  jal       func_8002B640
/* EE878C 802421DC 4600B306 */   mov.s    $f12, $f22
/* EE8790 802421E0 46140002 */  mul.s     $f0, $f0, $f20
/* EE8794 802421E4 00000000 */  nop
/* EE8798 802421E8 0220202D */  daddu     $a0, $s1, $zero
/* EE879C 802421EC 0260282D */  daddu     $a1, $s3, $zero
/* EE87A0 802421F0 4600E18D */  trunc.w.s $f6, $f28
/* EE87A4 802421F4 44063000 */  mfc1      $a2, $f6
/* EE87A8 802421F8 0C0B551A */  jal       dead_set_variable
/* EE87AC 802421FC 4600C601 */   sub.s    $f24, $f24, $f0
/* EE87B0 80242200 0220202D */  daddu     $a0, $s1, $zero
/* EE87B4 80242204 4600D18D */  trunc.w.s $f6, $f26
/* EE87B8 80242208 44063000 */  mfc1      $a2, $f6
/* EE87BC 8024220C 0C0B551A */  jal       dead_set_variable
/* EE87C0 80242210 0280282D */   daddu    $a1, $s4, $zero
/* EE87C4 80242214 0220202D */  daddu     $a0, $s1, $zero
/* EE87C8 80242218 4600C18D */  trunc.w.s $f6, $f24
/* EE87CC 8024221C 44063000 */  mfc1      $a2, $f6
/* EE87D0 80242220 0C0B551A */  jal       dead_set_variable
/* EE87D4 80242224 0200282D */   daddu    $a1, $s0, $zero
/* EE87D8 80242228 8FBF0024 */  lw        $ra, 0x24($sp)
/* EE87DC 8024222C 8FB40020 */  lw        $s4, 0x20($sp)
/* EE87E0 80242230 8FB3001C */  lw        $s3, 0x1c($sp)
/* EE87E4 80242234 8FB20018 */  lw        $s2, 0x18($sp)
/* EE87E8 80242238 8FB10014 */  lw        $s1, 0x14($sp)
/* EE87EC 8024223C 8FB00010 */  lw        $s0, 0x10($sp)
/* EE87F0 80242240 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* EE87F4 80242244 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* EE87F8 80242248 D7B80038 */  ldc1      $f24, 0x38($sp)
/* EE87FC 8024224C D7B60030 */  ldc1      $f22, 0x30($sp)
/* EE8800 80242250 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EE8804 80242254 24020002 */  addiu     $v0, $zero, 2
/* EE8808 80242258 03E00008 */  jr        $ra
/* EE880C 8024225C 27BD0050 */   addiu    $sp, $sp, 0x50
