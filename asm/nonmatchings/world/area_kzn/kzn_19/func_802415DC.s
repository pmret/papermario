.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415DC
/* C8F18C 802415DC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C8F190 802415E0 AFB10014 */  sw        $s1, 0x14($sp)
/* C8F194 802415E4 0080882D */  daddu     $s1, $a0, $zero
/* C8F198 802415E8 AFBF0024 */  sw        $ra, 0x24($sp)
/* C8F19C 802415EC AFB40020 */  sw        $s4, 0x20($sp)
/* C8F1A0 802415F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* C8F1A4 802415F4 AFB20018 */  sw        $s2, 0x18($sp)
/* C8F1A8 802415F8 AFB00010 */  sw        $s0, 0x10($sp)
/* C8F1AC 802415FC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* C8F1B0 80241600 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* C8F1B4 80241604 F7B80038 */  sdc1      $f24, 0x38($sp)
/* C8F1B8 80241608 F7B60030 */  sdc1      $f22, 0x30($sp)
/* C8F1BC 8024160C F7B40028 */  sdc1      $f20, 0x28($sp)
/* C8F1C0 80241610 8E30000C */  lw        $s0, 0xc($s1)
/* C8F1C4 80241614 8E130000 */  lw        $s3, ($s0)
/* C8F1C8 80241618 26100004 */  addiu     $s0, $s0, 4
/* C8F1CC 8024161C 0C0B1EAF */  jal       get_variable
/* C8F1D0 80241620 0260282D */   daddu    $a1, $s3, $zero
/* C8F1D4 80241624 4482E000 */  mtc1      $v0, $f28
/* C8F1D8 80241628 00000000 */  nop       
/* C8F1DC 8024162C 4680E720 */  cvt.s.w   $f28, $f28
/* C8F1E0 80241630 8E140000 */  lw        $s4, ($s0)
/* C8F1E4 80241634 26100004 */  addiu     $s0, $s0, 4
/* C8F1E8 80241638 0220202D */  daddu     $a0, $s1, $zero
/* C8F1EC 8024163C 0C0B1EAF */  jal       get_variable
/* C8F1F0 80241640 0280282D */   daddu    $a1, $s4, $zero
/* C8F1F4 80241644 4482D000 */  mtc1      $v0, $f26
/* C8F1F8 80241648 00000000 */  nop       
/* C8F1FC 8024164C 4680D6A0 */  cvt.s.w   $f26, $f26
/* C8F200 80241650 8E100000 */  lw        $s0, ($s0)
/* C8F204 80241654 0220202D */  daddu     $a0, $s1, $zero
/* C8F208 80241658 0C0B1EAF */  jal       get_variable
/* C8F20C 8024165C 0200282D */   daddu    $a1, $s0, $zero
/* C8F210 80241660 4482C000 */  mtc1      $v0, $f24
/* C8F214 80241664 00000000 */  nop       
/* C8F218 80241668 4680C620 */  cvt.s.w   $f24, $f24
/* C8F21C 8024166C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* C8F220 80241670 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* C8F224 80241674 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* C8F228 80241678 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* C8F22C 8024167C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* C8F230 80241680 44800000 */  mtc1      $zero, $f0
/* C8F234 80241684 00031080 */  sll       $v0, $v1, 2
/* C8F238 80241688 00431021 */  addu      $v0, $v0, $v1
/* C8F23C 8024168C 00021080 */  sll       $v0, $v0, 2
/* C8F240 80241690 00431023 */  subu      $v0, $v0, $v1
/* C8F244 80241694 000218C0 */  sll       $v1, $v0, 3
/* C8F248 80241698 00431021 */  addu      $v0, $v0, $v1
/* C8F24C 8024169C 000210C0 */  sll       $v0, $v0, 3
/* C8F250 802416A0 46001032 */  c.eq.s    $f2, $f0
/* C8F254 802416A4 3C01800B */  lui       $at, 0x800b
/* C8F258 802416A8 00220821 */  addu      $at, $at, $v0
/* C8F25C 802416AC C4361DEC */  lwc1      $f22, 0x1dec($at)
/* C8F260 802416B0 45000005 */  bc1f      .L802416C8
/* C8F264 802416B4 00000000 */   nop      
/* C8F268 802416B8 3C0142C8 */  lui       $at, 0x42c8
/* C8F26C 802416BC 44810000 */  mtc1      $at, $f0
/* C8F270 802416C0 080905B6 */  j         .L802416D8
/* C8F274 802416C4 4600B581 */   sub.s    $f22, $f22, $f0
.L802416C8:
/* C8F278 802416C8 3C0142C8 */  lui       $at, 0x42c8
/* C8F27C 802416CC 44810000 */  mtc1      $at, $f0
/* C8F280 802416D0 00000000 */  nop       
/* C8F284 802416D4 4600B580 */  add.s     $f22, $f22, $f0
.L802416D8:
/* C8F288 802416D8 0C00A6C9 */  jal       clamp_angle
/* C8F28C 802416DC 4600B306 */   mov.s    $f12, $f22
/* C8F290 802416E0 46000586 */  mov.s     $f22, $f0
/* C8F294 802416E4 3C014170 */  lui       $at, 0x4170
/* C8F298 802416E8 4481A000 */  mtc1      $at, $f20
/* C8F29C 802416EC 0C00A8BB */  jal       sin_deg
/* C8F2A0 802416F0 4600B306 */   mov.s    $f12, $f22
/* C8F2A4 802416F4 46140002 */  mul.s     $f0, $f0, $f20
/* C8F2A8 802416F8 00000000 */  nop       
/* C8F2AC 802416FC 864200B0 */  lh        $v0, 0xb0($s2)
/* C8F2B0 80241700 3C013F00 */  lui       $at, 0x3f00
/* C8F2B4 80241704 44812000 */  mtc1      $at, $f4
/* C8F2B8 80241708 44821000 */  mtc1      $v0, $f2
/* C8F2BC 8024170C 00000000 */  nop       
/* C8F2C0 80241710 468010A0 */  cvt.s.w   $f2, $f2
/* C8F2C4 80241714 46041082 */  mul.s     $f2, $f2, $f4
/* C8F2C8 80241718 00000000 */  nop       
/* C8F2CC 8024171C 4600E700 */  add.s     $f28, $f28, $f0
/* C8F2D0 80241720 4602D680 */  add.s     $f26, $f26, $f2
/* C8F2D4 80241724 0C00A8D4 */  jal       cos_deg
/* C8F2D8 80241728 4600B306 */   mov.s    $f12, $f22
/* C8F2DC 8024172C 46140002 */  mul.s     $f0, $f0, $f20
/* C8F2E0 80241730 00000000 */  nop       
/* C8F2E4 80241734 0220202D */  daddu     $a0, $s1, $zero
/* C8F2E8 80241738 0260282D */  daddu     $a1, $s3, $zero
/* C8F2EC 8024173C 4600E18D */  trunc.w.s $f6, $f28
/* C8F2F0 80241740 44063000 */  mfc1      $a2, $f6
/* C8F2F4 80241744 0C0B2026 */  jal       set_variable
/* C8F2F8 80241748 4600C601 */   sub.s    $f24, $f24, $f0
/* C8F2FC 8024174C 0220202D */  daddu     $a0, $s1, $zero
/* C8F300 80241750 4600D18D */  trunc.w.s $f6, $f26
/* C8F304 80241754 44063000 */  mfc1      $a2, $f6
/* C8F308 80241758 0C0B2026 */  jal       set_variable
/* C8F30C 8024175C 0280282D */   daddu    $a1, $s4, $zero
/* C8F310 80241760 0220202D */  daddu     $a0, $s1, $zero
/* C8F314 80241764 4600C18D */  trunc.w.s $f6, $f24
/* C8F318 80241768 44063000 */  mfc1      $a2, $f6
/* C8F31C 8024176C 0C0B2026 */  jal       set_variable
/* C8F320 80241770 0200282D */   daddu    $a1, $s0, $zero
/* C8F324 80241774 8FBF0024 */  lw        $ra, 0x24($sp)
/* C8F328 80241778 8FB40020 */  lw        $s4, 0x20($sp)
/* C8F32C 8024177C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C8F330 80241780 8FB20018 */  lw        $s2, 0x18($sp)
/* C8F334 80241784 8FB10014 */  lw        $s1, 0x14($sp)
/* C8F338 80241788 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F33C 8024178C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* C8F340 80241790 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* C8F344 80241794 D7B80038 */  ldc1      $f24, 0x38($sp)
/* C8F348 80241798 D7B60030 */  ldc1      $f22, 0x30($sp)
/* C8F34C 8024179C D7B40028 */  ldc1      $f20, 0x28($sp)
/* C8F350 802417A0 24020002 */  addiu     $v0, $zero, 2
/* C8F354 802417A4 03E00008 */  jr        $ra
/* C8F358 802417A8 27BD0050 */   addiu    $sp, $sp, 0x50
