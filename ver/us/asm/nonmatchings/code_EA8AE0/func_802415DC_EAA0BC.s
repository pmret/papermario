.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415DC_EAA0BC
/* EAA0BC 802415DC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EAA0C0 802415E0 AFB10014 */  sw        $s1, 0x14($sp)
/* EAA0C4 802415E4 0080882D */  daddu     $s1, $a0, $zero
/* EAA0C8 802415E8 AFBF0024 */  sw        $ra, 0x24($sp)
/* EAA0CC 802415EC AFB40020 */  sw        $s4, 0x20($sp)
/* EAA0D0 802415F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* EAA0D4 802415F4 AFB20018 */  sw        $s2, 0x18($sp)
/* EAA0D8 802415F8 AFB00010 */  sw        $s0, 0x10($sp)
/* EAA0DC 802415FC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* EAA0E0 80241600 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* EAA0E4 80241604 F7B80038 */  sdc1      $f24, 0x38($sp)
/* EAA0E8 80241608 F7B60030 */  sdc1      $f22, 0x30($sp)
/* EAA0EC 8024160C F7B40028 */  sdc1      $f20, 0x28($sp)
/* EAA0F0 80241610 8E30000C */  lw        $s0, 0xc($s1)
/* EAA0F4 80241614 8E130000 */  lw        $s3, ($s0)
/* EAA0F8 80241618 26100004 */  addiu     $s0, $s0, 4
/* EAA0FC 8024161C 0C0B53A3 */  jal       func_802D4E8C
/* EAA100 80241620 0260282D */   daddu    $a1, $s3, $zero
/* EAA104 80241624 4482E000 */  mtc1      $v0, $f28
/* EAA108 80241628 00000000 */  nop
/* EAA10C 8024162C 4680E720 */  cvt.s.w   $f28, $f28
/* EAA110 80241630 8E140000 */  lw        $s4, ($s0)
/* EAA114 80241634 26100004 */  addiu     $s0, $s0, 4
/* EAA118 80241638 0220202D */  daddu     $a0, $s1, $zero
/* EAA11C 8024163C 0C0B53A3 */  jal       func_802D4E8C
/* EAA120 80241640 0280282D */   daddu    $a1, $s4, $zero
/* EAA124 80241644 4482D000 */  mtc1      $v0, $f26
/* EAA128 80241648 00000000 */  nop
/* EAA12C 8024164C 4680D6A0 */  cvt.s.w   $f26, $f26
/* EAA130 80241650 8E100000 */  lw        $s0, ($s0)
/* EAA134 80241654 0220202D */  daddu     $a0, $s1, $zero
/* EAA138 80241658 0C0B53A3 */  jal       func_802D4E8C
/* EAA13C 8024165C 0200282D */   daddu    $a1, $s0, $zero
/* EAA140 80241660 4482C000 */  mtc1      $v0, $f24
/* EAA144 80241664 00000000 */  nop
/* EAA148 80241668 4680C620 */  cvt.s.w   $f24, $f24
/* EAA14C 8024166C 3C128011 */  lui       $s2, %hi(D_80117578)
/* EAA150 80241670 26527578 */  addiu     $s2, $s2, %lo(D_80117578)
/* EAA154 80241674 3C038008 */  lui       $v1, %hi(D_8007C760)
/* EAA158 80241678 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* EAA15C 8024167C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* EAA160 80241680 44800000 */  mtc1      $zero, $f0
/* EAA164 80241684 00031080 */  sll       $v0, $v1, 2
/* EAA168 80241688 00431021 */  addu      $v0, $v0, $v1
/* EAA16C 8024168C 00021080 */  sll       $v0, $v0, 2
/* EAA170 80241690 00431023 */  subu      $v0, $v0, $v1
/* EAA174 80241694 000218C0 */  sll       $v1, $v0, 3
/* EAA178 80241698 00431021 */  addu      $v0, $v0, $v1
/* EAA17C 8024169C 000210C0 */  sll       $v0, $v0, 3
/* EAA180 802416A0 46001032 */  c.eq.s    $f2, $f0
/* EAA184 802416A4 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EAA188 802416A8 00220821 */  addu      $at, $at, $v0
/* EAA18C 802416AC C4368DEC */  lwc1      $f22, %lo(D_800B8DEC)($at)
/* EAA190 802416B0 45000005 */  bc1f      .L802416C8
/* EAA194 802416B4 00000000 */   nop
/* EAA198 802416B8 3C0142C8 */  lui       $at, 0x42c8
/* EAA19C 802416BC 44810000 */  mtc1      $at, $f0
/* EAA1A0 802416C0 080905B6 */  j         .L802416D8
/* EAA1A4 802416C4 4600B581 */   sub.s    $f22, $f22, $f0
.L802416C8:
/* EAA1A8 802416C8 3C0142C8 */  lui       $at, 0x42c8
/* EAA1AC 802416CC 44810000 */  mtc1      $at, $f0
/* EAA1B0 802416D0 00000000 */  nop
/* EAA1B4 802416D4 4600B580 */  add.s     $f22, $f22, $f0
.L802416D8:
/* EAA1B8 802416D8 0C00AB85 */  jal       func_8002AE14
/* EAA1BC 802416DC 4600B306 */   mov.s    $f12, $f22
/* EAA1C0 802416E0 46000586 */  mov.s     $f22, $f0
/* EAA1C4 802416E4 3C014170 */  lui       $at, 0x4170
/* EAA1C8 802416E8 4481A000 */  mtc1      $at, $f20
/* EAA1CC 802416EC 0C00AD77 */  jal       func_8002B5DC
/* EAA1D0 802416F0 4600B306 */   mov.s    $f12, $f22
/* EAA1D4 802416F4 46140002 */  mul.s     $f0, $f0, $f20
/* EAA1D8 802416F8 00000000 */  nop
/* EAA1DC 802416FC 864200B0 */  lh        $v0, 0xb0($s2)
/* EAA1E0 80241700 3C013F00 */  lui       $at, 0x3f00
/* EAA1E4 80241704 44812000 */  mtc1      $at, $f4
/* EAA1E8 80241708 44821000 */  mtc1      $v0, $f2
/* EAA1EC 8024170C 00000000 */  nop
/* EAA1F0 80241710 468010A0 */  cvt.s.w   $f2, $f2
/* EAA1F4 80241714 46041082 */  mul.s     $f2, $f2, $f4
/* EAA1F8 80241718 00000000 */  nop
/* EAA1FC 8024171C 4600E700 */  add.s     $f28, $f28, $f0
/* EAA200 80241720 4602D680 */  add.s     $f26, $f26, $f2
/* EAA204 80241724 0C00AD90 */  jal       func_8002B640
/* EAA208 80241728 4600B306 */   mov.s    $f12, $f22
/* EAA20C 8024172C 46140002 */  mul.s     $f0, $f0, $f20
/* EAA210 80241730 00000000 */  nop
/* EAA214 80241734 0220202D */  daddu     $a0, $s1, $zero
/* EAA218 80241738 0260282D */  daddu     $a1, $s3, $zero
/* EAA21C 8024173C 4600E18D */  trunc.w.s $f6, $f28
/* EAA220 80241740 44063000 */  mfc1      $a2, $f6
/* EAA224 80241744 0C0B551A */  jal       func_802D5468
/* EAA228 80241748 4600C601 */   sub.s    $f24, $f24, $f0
/* EAA22C 8024174C 0220202D */  daddu     $a0, $s1, $zero
/* EAA230 80241750 4600D18D */  trunc.w.s $f6, $f26
/* EAA234 80241754 44063000 */  mfc1      $a2, $f6
/* EAA238 80241758 0C0B551A */  jal       func_802D5468
/* EAA23C 8024175C 0280282D */   daddu    $a1, $s4, $zero
/* EAA240 80241760 0220202D */  daddu     $a0, $s1, $zero
/* EAA244 80241764 4600C18D */  trunc.w.s $f6, $f24
/* EAA248 80241768 44063000 */  mfc1      $a2, $f6
/* EAA24C 8024176C 0C0B551A */  jal       func_802D5468
/* EAA250 80241770 0200282D */   daddu    $a1, $s0, $zero
/* EAA254 80241774 8FBF0024 */  lw        $ra, 0x24($sp)
/* EAA258 80241778 8FB40020 */  lw        $s4, 0x20($sp)
/* EAA25C 8024177C 8FB3001C */  lw        $s3, 0x1c($sp)
/* EAA260 80241780 8FB20018 */  lw        $s2, 0x18($sp)
/* EAA264 80241784 8FB10014 */  lw        $s1, 0x14($sp)
/* EAA268 80241788 8FB00010 */  lw        $s0, 0x10($sp)
/* EAA26C 8024178C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* EAA270 80241790 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* EAA274 80241794 D7B80038 */  ldc1      $f24, 0x38($sp)
/* EAA278 80241798 D7B60030 */  ldc1      $f22, 0x30($sp)
/* EAA27C 8024179C D7B40028 */  ldc1      $f20, 0x28($sp)
/* EAA280 802417A0 24020002 */  addiu     $v0, $zero, 2
/* EAA284 802417A4 03E00008 */  jr        $ra
/* EAA288 802417A8 27BD0050 */   addiu    $sp, $sp, 0x50
