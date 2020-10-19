.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242240
/* 9C7620 80242240 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9C7624 80242244 AFB1001C */  sw        $s1, 0x1c($sp)
/* 9C7628 80242248 0080882D */  daddu     $s1, $a0, $zero
/* 9C762C 8024224C AFBF0034 */  sw        $ra, 0x34($sp)
/* 9C7630 80242250 AFB60030 */  sw        $s6, 0x30($sp)
/* 9C7634 80242254 AFB5002C */  sw        $s5, 0x2c($sp)
/* 9C7638 80242258 AFB40028 */  sw        $s4, 0x28($sp)
/* 9C763C 8024225C AFB30024 */  sw        $s3, 0x24($sp)
/* 9C7640 80242260 AFB20020 */  sw        $s2, 0x20($sp)
/* 9C7644 80242264 AFB00018 */  sw        $s0, 0x18($sp)
/* 9C7648 80242268 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 9C764C 8024226C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9C7650 80242270 8E30000C */  lw        $s0, 0xc($s1)
/* 9C7654 80242274 8E160000 */  lw        $s6, ($s0)
/* 9C7658 80242278 26100004 */  addiu     $s0, $s0, 4
/* 9C765C 8024227C 0C0B1EAF */  jal       get_variable
/* 9C7660 80242280 02C0282D */   daddu    $a1, $s6, $zero
/* 9C7664 80242284 44820000 */  mtc1      $v0, $f0
/* 9C7668 80242288 00000000 */  nop       
/* 9C766C 8024228C 46800020 */  cvt.s.w   $f0, $f0
/* 9C7670 80242290 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9C7674 80242294 8E140000 */  lw        $s4, ($s0)
/* 9C7678 80242298 26100004 */  addiu     $s0, $s0, 4
/* 9C767C 8024229C 0220202D */  daddu     $a0, $s1, $zero
/* 9C7680 802422A0 0C0B1EAF */  jal       get_variable
/* 9C7684 802422A4 0280282D */   daddu    $a1, $s4, $zero
/* 9C7688 802422A8 0220202D */  daddu     $a0, $s1, $zero
/* 9C768C 802422AC 8E150000 */  lw        $s5, ($s0)
/* 9C7690 802422B0 4482B000 */  mtc1      $v0, $f22
/* 9C7694 802422B4 00000000 */  nop       
/* 9C7698 802422B8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9C769C 802422BC 0C0B1EAF */  jal       get_variable
/* 9C76A0 802422C0 02A0282D */   daddu    $a1, $s5, $zero
/* 9C76A4 802422C4 2404FFFC */  addiu     $a0, $zero, -4
/* 9C76A8 802422C8 44820000 */  mtc1      $v0, $f0
/* 9C76AC 802422CC 00000000 */  nop       
/* 9C76B0 802422D0 46800020 */  cvt.s.w   $f0, $f0
/* 9C76B4 802422D4 0C00EABB */  jal       get_npc_unsafe
/* 9C76B8 802422D8 E7A00014 */   swc1     $f0, 0x14($sp)
/* 9C76BC 802422DC 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 9C76C0 802422E0 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 9C76C4 802422E4 3C014334 */  lui       $at, 0x4334
/* 9C76C8 802422E8 44816000 */  mtc1      $at, $f12
/* 9C76CC 802422EC 00041880 */  sll       $v1, $a0, 2
/* 9C76D0 802422F0 00641821 */  addu      $v1, $v1, $a0
/* 9C76D4 802422F4 00031880 */  sll       $v1, $v1, 2
/* 9C76D8 802422F8 00641823 */  subu      $v1, $v1, $a0
/* 9C76DC 802422FC 000320C0 */  sll       $a0, $v1, 3
/* 9C76E0 80242300 00641821 */  addu      $v1, $v1, $a0
/* 9C76E4 80242304 000318C0 */  sll       $v1, $v1, 3
/* 9C76E8 80242308 3C01800B */  lui       $at, 0x800b
/* 9C76EC 8024230C 00230821 */  addu      $at, $at, $v1
/* 9C76F0 80242310 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 9C76F4 80242314 460C0300 */  add.s     $f12, $f0, $f12
/* 9C76F8 80242318 0C00A6C9 */  jal       clamp_angle
/* 9C76FC 8024231C 0040982D */   daddu    $s3, $v0, $zero
/* 9C7700 80242320 27B00010 */  addiu     $s0, $sp, 0x10
/* 9C7704 80242324 0200202D */  daddu     $a0, $s0, $zero
/* 9C7708 80242328 27B20014 */  addiu     $s2, $sp, 0x14
/* 9C770C 8024232C 0240282D */  daddu     $a1, $s2, $zero
/* 9C7710 80242330 3C064170 */  lui       $a2, 0x4170
/* 9C7714 80242334 8E67000C */  lw        $a3, 0xc($s3)
/* 9C7718 80242338 0C00A7E7 */  jal       add_vec2D_polar
/* 9C771C 8024233C 46000506 */   mov.s    $f20, $f0
/* 9C7720 80242340 0200202D */  daddu     $a0, $s0, $zero
/* 9C7724 80242344 3C064120 */  lui       $a2, 0x4120
/* 9C7728 80242348 4407A000 */  mfc1      $a3, $f20
/* 9C772C 8024234C 0C00A7E7 */  jal       add_vec2D_polar
/* 9C7730 80242350 0240282D */   daddu    $a1, $s2, $zero
/* 9C7734 80242354 0220202D */  daddu     $a0, $s1, $zero
/* 9C7738 80242358 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 9C773C 8024235C 4600008D */  trunc.w.s $f2, $f0
/* 9C7740 80242360 44061000 */  mfc1      $a2, $f2
/* 9C7744 80242364 0C0B2026 */  jal       set_variable
/* 9C7748 80242368 02C0282D */   daddu    $a1, $s6, $zero
/* 9C774C 8024236C 0220202D */  daddu     $a0, $s1, $zero
/* 9C7750 80242370 4600B08D */  trunc.w.s $f2, $f22
/* 9C7754 80242374 44061000 */  mfc1      $a2, $f2
/* 9C7758 80242378 0C0B2026 */  jal       set_variable
/* 9C775C 8024237C 0280282D */   daddu    $a1, $s4, $zero
/* 9C7760 80242380 0220202D */  daddu     $a0, $s1, $zero
/* 9C7764 80242384 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 9C7768 80242388 4600008D */  trunc.w.s $f2, $f0
/* 9C776C 8024238C 44061000 */  mfc1      $a2, $f2
/* 9C7770 80242390 0C0B2026 */  jal       set_variable
/* 9C7774 80242394 02A0282D */   daddu    $a1, $s5, $zero
/* 9C7778 80242398 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9C777C 8024239C 8FB60030 */  lw        $s6, 0x30($sp)
/* 9C7780 802423A0 8FB5002C */  lw        $s5, 0x2c($sp)
/* 9C7784 802423A4 8FB40028 */  lw        $s4, 0x28($sp)
/* 9C7788 802423A8 8FB30024 */  lw        $s3, 0x24($sp)
/* 9C778C 802423AC 8FB20020 */  lw        $s2, 0x20($sp)
/* 9C7790 802423B0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9C7794 802423B4 8FB00018 */  lw        $s0, 0x18($sp)
/* 9C7798 802423B8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 9C779C 802423BC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 9C77A0 802423C0 24020002 */  addiu     $v0, $zero, 2
/* 9C77A4 802423C4 03E00008 */  jr        $ra
/* 9C77A8 802423C8 27BD0048 */   addiu    $sp, $sp, 0x48
