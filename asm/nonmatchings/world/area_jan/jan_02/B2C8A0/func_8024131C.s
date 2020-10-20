.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024131C
/* B2D78C 8024131C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B2D790 80241320 AFB10014 */  sw        $s1, 0x14($sp)
/* B2D794 80241324 0080882D */  daddu     $s1, $a0, $zero
/* B2D798 80241328 AFBF0024 */  sw        $ra, 0x24($sp)
/* B2D79C 8024132C AFB40020 */  sw        $s4, 0x20($sp)
/* B2D7A0 80241330 AFB3001C */  sw        $s3, 0x1c($sp)
/* B2D7A4 80241334 AFB20018 */  sw        $s2, 0x18($sp)
/* B2D7A8 80241338 AFB00010 */  sw        $s0, 0x10($sp)
/* B2D7AC 8024133C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* B2D7B0 80241340 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* B2D7B4 80241344 F7B80038 */  sdc1      $f24, 0x38($sp)
/* B2D7B8 80241348 F7B60030 */  sdc1      $f22, 0x30($sp)
/* B2D7BC 8024134C F7B40028 */  sdc1      $f20, 0x28($sp)
/* B2D7C0 80241350 8E30000C */  lw        $s0, 0xc($s1)
/* B2D7C4 80241354 8E130000 */  lw        $s3, ($s0)
/* B2D7C8 80241358 26100004 */  addiu     $s0, $s0, 4
/* B2D7CC 8024135C 0C0B1EAF */  jal       get_variable
/* B2D7D0 80241360 0260282D */   daddu    $a1, $s3, $zero
/* B2D7D4 80241364 4482E000 */  mtc1      $v0, $f28
/* B2D7D8 80241368 00000000 */  nop       
/* B2D7DC 8024136C 4680E720 */  cvt.s.w   $f28, $f28
/* B2D7E0 80241370 8E140000 */  lw        $s4, ($s0)
/* B2D7E4 80241374 26100004 */  addiu     $s0, $s0, 4
/* B2D7E8 80241378 0220202D */  daddu     $a0, $s1, $zero
/* B2D7EC 8024137C 0C0B1EAF */  jal       get_variable
/* B2D7F0 80241380 0280282D */   daddu    $a1, $s4, $zero
/* B2D7F4 80241384 4482D000 */  mtc1      $v0, $f26
/* B2D7F8 80241388 00000000 */  nop       
/* B2D7FC 8024138C 4680D6A0 */  cvt.s.w   $f26, $f26
/* B2D800 80241390 8E100000 */  lw        $s0, ($s0)
/* B2D804 80241394 0220202D */  daddu     $a0, $s1, $zero
/* B2D808 80241398 0C0B1EAF */  jal       get_variable
/* B2D80C 8024139C 0200282D */   daddu    $a1, $s0, $zero
/* B2D810 802413A0 4482C000 */  mtc1      $v0, $f24
/* B2D814 802413A4 00000000 */  nop       
/* B2D818 802413A8 4680C620 */  cvt.s.w   $f24, $f24
/* B2D81C 802413AC 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* B2D820 802413B0 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* B2D824 802413B4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* B2D828 802413B8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* B2D82C 802413BC C64200A8 */  lwc1      $f2, 0xa8($s2)
/* B2D830 802413C0 44800000 */  mtc1      $zero, $f0
/* B2D834 802413C4 00031080 */  sll       $v0, $v1, 2
/* B2D838 802413C8 00431021 */  addu      $v0, $v0, $v1
/* B2D83C 802413CC 00021080 */  sll       $v0, $v0, 2
/* B2D840 802413D0 00431023 */  subu      $v0, $v0, $v1
/* B2D844 802413D4 000218C0 */  sll       $v1, $v0, 3
/* B2D848 802413D8 00431021 */  addu      $v0, $v0, $v1
/* B2D84C 802413DC 000210C0 */  sll       $v0, $v0, 3
/* B2D850 802413E0 46001032 */  c.eq.s    $f2, $f0
/* B2D854 802413E4 3C01800B */  lui       $at, 0x800b
/* B2D858 802413E8 00220821 */  addu      $at, $at, $v0
/* B2D85C 802413EC C4361DEC */  lwc1      $f22, 0x1dec($at)
/* B2D860 802413F0 45000005 */  bc1f      .L80241408
/* B2D864 802413F4 00000000 */   nop      
/* B2D868 802413F8 3C0142C8 */  lui       $at, 0x42c8
/* B2D86C 802413FC 44810000 */  mtc1      $at, $f0
/* B2D870 80241400 08090506 */  j         .L80241418
/* B2D874 80241404 4600B581 */   sub.s    $f22, $f22, $f0
.L80241408:
/* B2D878 80241408 3C0142C8 */  lui       $at, 0x42c8
/* B2D87C 8024140C 44810000 */  mtc1      $at, $f0
/* B2D880 80241410 00000000 */  nop       
/* B2D884 80241414 4600B580 */  add.s     $f22, $f22, $f0
.L80241418:
/* B2D888 80241418 0C00A6C9 */  jal       clamp_angle
/* B2D88C 8024141C 4600B306 */   mov.s    $f12, $f22
/* B2D890 80241420 46000586 */  mov.s     $f22, $f0
/* B2D894 80241424 3C014170 */  lui       $at, 0x4170
/* B2D898 80241428 4481A000 */  mtc1      $at, $f20
/* B2D89C 8024142C 0C00A8BB */  jal       sin_deg
/* B2D8A0 80241430 4600B306 */   mov.s    $f12, $f22
/* B2D8A4 80241434 46140002 */  mul.s     $f0, $f0, $f20
/* B2D8A8 80241438 00000000 */  nop       
/* B2D8AC 8024143C 864200B0 */  lh        $v0, 0xb0($s2)
/* B2D8B0 80241440 3C013F00 */  lui       $at, 0x3f00
/* B2D8B4 80241444 44812000 */  mtc1      $at, $f4
/* B2D8B8 80241448 44821000 */  mtc1      $v0, $f2
/* B2D8BC 8024144C 00000000 */  nop       
/* B2D8C0 80241450 468010A0 */  cvt.s.w   $f2, $f2
/* B2D8C4 80241454 46041082 */  mul.s     $f2, $f2, $f4
/* B2D8C8 80241458 00000000 */  nop       
/* B2D8CC 8024145C 4600E700 */  add.s     $f28, $f28, $f0
/* B2D8D0 80241460 4602D680 */  add.s     $f26, $f26, $f2
/* B2D8D4 80241464 0C00A8D4 */  jal       cos_deg
/* B2D8D8 80241468 4600B306 */   mov.s    $f12, $f22
/* B2D8DC 8024146C 46140002 */  mul.s     $f0, $f0, $f20
/* B2D8E0 80241470 00000000 */  nop       
/* B2D8E4 80241474 0220202D */  daddu     $a0, $s1, $zero
/* B2D8E8 80241478 0260282D */  daddu     $a1, $s3, $zero
/* B2D8EC 8024147C 4600E18D */  trunc.w.s $f6, $f28
/* B2D8F0 80241480 44063000 */  mfc1      $a2, $f6
/* B2D8F4 80241484 0C0B2026 */  jal       set_variable
/* B2D8F8 80241488 4600C601 */   sub.s    $f24, $f24, $f0
/* B2D8FC 8024148C 0220202D */  daddu     $a0, $s1, $zero
/* B2D900 80241490 4600D18D */  trunc.w.s $f6, $f26
/* B2D904 80241494 44063000 */  mfc1      $a2, $f6
/* B2D908 80241498 0C0B2026 */  jal       set_variable
/* B2D90C 8024149C 0280282D */   daddu    $a1, $s4, $zero
/* B2D910 802414A0 0220202D */  daddu     $a0, $s1, $zero
/* B2D914 802414A4 4600C18D */  trunc.w.s $f6, $f24
/* B2D918 802414A8 44063000 */  mfc1      $a2, $f6
/* B2D91C 802414AC 0C0B2026 */  jal       set_variable
/* B2D920 802414B0 0200282D */   daddu    $a1, $s0, $zero
/* B2D924 802414B4 8FBF0024 */  lw        $ra, 0x24($sp)
/* B2D928 802414B8 8FB40020 */  lw        $s4, 0x20($sp)
/* B2D92C 802414BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2D930 802414C0 8FB20018 */  lw        $s2, 0x18($sp)
/* B2D934 802414C4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2D938 802414C8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D93C 802414CC D7BC0048 */  ldc1      $f28, 0x48($sp)
/* B2D940 802414D0 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* B2D944 802414D4 D7B80038 */  ldc1      $f24, 0x38($sp)
/* B2D948 802414D8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* B2D94C 802414DC D7B40028 */  ldc1      $f20, 0x28($sp)
/* B2D950 802414E0 24020002 */  addiu     $v0, $zero, 2
/* B2D954 802414E4 03E00008 */  jr        $ra
/* B2D958 802414E8 27BD0050 */   addiu    $sp, $sp, 0x50
