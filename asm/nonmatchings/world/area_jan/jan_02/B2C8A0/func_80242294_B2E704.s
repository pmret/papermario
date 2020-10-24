.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242294_B2E704
/* B2E704 80242294 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B2E708 80242298 AFB20018 */  sw        $s2, 0x18($sp)
/* B2E70C 8024229C 0080902D */  daddu     $s2, $a0, $zero
/* B2E710 802422A0 AFBF0030 */  sw        $ra, 0x30($sp)
/* B2E714 802422A4 AFB7002C */  sw        $s7, 0x2c($sp)
/* B2E718 802422A8 AFB60028 */  sw        $s6, 0x28($sp)
/* B2E71C 802422AC AFB50024 */  sw        $s5, 0x24($sp)
/* B2E720 802422B0 AFB40020 */  sw        $s4, 0x20($sp)
/* B2E724 802422B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* B2E728 802422B8 AFB10014 */  sw        $s1, 0x14($sp)
/* B2E72C 802422BC AFB00010 */  sw        $s0, 0x10($sp)
/* B2E730 802422C0 F7B60040 */  sdc1      $f22, 0x40($sp)
/* B2E734 802422C4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* B2E738 802422C8 8E50000C */  lw        $s0, 0xc($s2)
/* B2E73C 802422CC 8E050000 */  lw        $a1, ($s0)
/* B2E740 802422D0 0C0B1EAF */  jal       get_variable
/* B2E744 802422D4 26100004 */   addiu    $s0, $s0, 4
/* B2E748 802422D8 8E050000 */  lw        $a1, ($s0)
/* B2E74C 802422DC 26100004 */  addiu     $s0, $s0, 4
/* B2E750 802422E0 0240202D */  daddu     $a0, $s2, $zero
/* B2E754 802422E4 0C0B1EAF */  jal       get_variable
/* B2E758 802422E8 0040B82D */   daddu    $s7, $v0, $zero
/* B2E75C 802422EC 8E050000 */  lw        $a1, ($s0)
/* B2E760 802422F0 26100004 */  addiu     $s0, $s0, 4
/* B2E764 802422F4 0240202D */  daddu     $a0, $s2, $zero
/* B2E768 802422F8 0C0B1EAF */  jal       get_variable
/* B2E76C 802422FC 0040B02D */   daddu    $s6, $v0, $zero
/* B2E770 80242300 0240202D */  daddu     $a0, $s2, $zero
/* B2E774 80242304 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E778 80242308 34A5D481 */  ori       $a1, $a1, 0xd481
/* B2E77C 8024230C 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* B2E780 80242310 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* B2E784 80242314 8E140000 */  lw        $s4, ($s0)
/* B2E788 80242318 00061880 */  sll       $v1, $a2, 2
/* B2E78C 8024231C 00661821 */  addu      $v1, $v1, $a2
/* B2E790 80242320 00031880 */  sll       $v1, $v1, 2
/* B2E794 80242324 00661823 */  subu      $v1, $v1, $a2
/* B2E798 80242328 000330C0 */  sll       $a2, $v1, 3
/* B2E79C 8024232C 00661821 */  addu      $v1, $v1, $a2
/* B2E7A0 80242330 000318C0 */  sll       $v1, $v1, 3
/* B2E7A4 80242334 3C01800B */  lui       $at, 0x800b
/* B2E7A8 80242338 00230821 */  addu      $at, $at, $v1
/* B2E7AC 8024233C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* B2E7B0 80242340 8E150004 */  lw        $s5, 4($s0)
/* B2E7B4 80242344 4600010D */  trunc.w.s $f4, $f0
/* B2E7B8 80242348 44112000 */  mfc1      $s1, $f4
/* B2E7BC 8024234C 0C0B1EAF */  jal       get_variable
/* B2E7C0 80242350 0040982D */   daddu    $s3, $v0, $zero
/* B2E7C4 80242354 4491B000 */  mtc1      $s1, $f22
/* B2E7C8 80242358 00000000 */  nop       
/* B2E7CC 8024235C 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2E7D0 80242360 4600B306 */  mov.s     $f12, $f22
/* B2E7D4 80242364 0C00A8D4 */  jal       cos_deg
/* B2E7D8 80242368 0040802D */   daddu    $s0, $v0, $zero
/* B2E7DC 8024236C 4493A000 */  mtc1      $s3, $f20
/* B2E7E0 80242370 00000000 */  nop       
/* B2E7E4 80242374 4680A520 */  cvt.s.w   $f20, $f20
/* B2E7E8 80242378 4600A002 */  mul.s     $f0, $f20, $f0
/* B2E7EC 8024237C 00000000 */  nop       
/* B2E7F0 80242380 0240202D */  daddu     $a0, $s2, $zero
/* B2E7F4 80242384 44901000 */  mtc1      $s0, $f2
/* B2E7F8 80242388 00000000 */  nop       
/* B2E7FC 8024238C 468010A0 */  cvt.s.w   $f2, $f2
/* B2E800 80242390 46001081 */  sub.s     $f2, $f2, $f0
/* B2E804 80242394 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E808 80242398 4600110D */  trunc.w.s $f4, $f2
/* B2E80C 8024239C 44102000 */  mfc1      $s0, $f4
/* B2E810 802423A0 0C0B1EAF */  jal       get_variable
/* B2E814 802423A4 34A5D483 */   ori      $a1, $a1, 0xd483
/* B2E818 802423A8 4600B306 */  mov.s     $f12, $f22
/* B2E81C 802423AC 0C00A8BB */  jal       sin_deg
/* B2E820 802423B0 0040882D */   daddu    $s1, $v0, $zero
/* B2E824 802423B4 4600A502 */  mul.s     $f20, $f20, $f0
/* B2E828 802423B8 00000000 */  nop       
/* B2E82C 802423BC 0240202D */  daddu     $a0, $s2, $zero
/* B2E830 802423C0 44910000 */  mtc1      $s1, $f0
/* B2E834 802423C4 00000000 */  nop       
/* B2E838 802423C8 46800020 */  cvt.s.w   $f0, $f0
/* B2E83C 802423CC 46140001 */  sub.s     $f0, $f0, $f20
/* B2E840 802423D0 0280282D */  daddu     $a1, $s4, $zero
/* B2E844 802423D4 02173023 */  subu      $a2, $s0, $s7
/* B2E848 802423D8 4600010D */  trunc.w.s $f4, $f0
/* B2E84C 802423DC 44102000 */  mfc1      $s0, $f4
/* B2E850 802423E0 0C0B2026 */  jal       set_variable
/* B2E854 802423E4 02168023 */   subu     $s0, $s0, $s6
/* B2E858 802423E8 0240202D */  daddu     $a0, $s2, $zero
/* B2E85C 802423EC 02A0282D */  daddu     $a1, $s5, $zero
/* B2E860 802423F0 0C0B2026 */  jal       set_variable
/* B2E864 802423F4 0200302D */   daddu    $a2, $s0, $zero
/* B2E868 802423F8 8FBF0030 */  lw        $ra, 0x30($sp)
/* B2E86C 802423FC 8FB7002C */  lw        $s7, 0x2c($sp)
/* B2E870 80242400 8FB60028 */  lw        $s6, 0x28($sp)
/* B2E874 80242404 8FB50024 */  lw        $s5, 0x24($sp)
/* B2E878 80242408 8FB40020 */  lw        $s4, 0x20($sp)
/* B2E87C 8024240C 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2E880 80242410 8FB20018 */  lw        $s2, 0x18($sp)
/* B2E884 80242414 8FB10014 */  lw        $s1, 0x14($sp)
/* B2E888 80242418 8FB00010 */  lw        $s0, 0x10($sp)
/* B2E88C 8024241C D7B60040 */  ldc1      $f22, 0x40($sp)
/* B2E890 80242420 D7B40038 */  ldc1      $f20, 0x38($sp)
/* B2E894 80242424 24020002 */  addiu     $v0, $zero, 2
/* B2E898 80242428 03E00008 */  jr        $ra
/* B2E89C 8024242C 27BD0048 */   addiu    $sp, $sp, 0x48
