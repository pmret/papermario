.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243574
/* 7EE284 80243574 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 7EE288 80243578 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EE28C 8024357C 0080882D */  daddu     $s1, $a0, $zero
/* 7EE290 80243580 AFBF0024 */  sw        $ra, 0x24($sp)
/* 7EE294 80243584 AFB40020 */  sw        $s4, 0x20($sp)
/* 7EE298 80243588 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7EE29C 8024358C AFB20018 */  sw        $s2, 0x18($sp)
/* 7EE2A0 80243590 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EE2A4 80243594 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 7EE2A8 80243598 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 7EE2AC 8024359C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 7EE2B0 802435A0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 7EE2B4 802435A4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 7EE2B8 802435A8 8E30000C */  lw        $s0, 0xc($s1)
/* 7EE2BC 802435AC 8E130000 */  lw        $s3, ($s0)
/* 7EE2C0 802435B0 26100004 */  addiu     $s0, $s0, 4
/* 7EE2C4 802435B4 0C0B1EAF */  jal       get_variable
/* 7EE2C8 802435B8 0260282D */   daddu    $a1, $s3, $zero
/* 7EE2CC 802435BC 4482E000 */  mtc1      $v0, $f28
/* 7EE2D0 802435C0 00000000 */  nop       
/* 7EE2D4 802435C4 4680E720 */  cvt.s.w   $f28, $f28
/* 7EE2D8 802435C8 8E140000 */  lw        $s4, ($s0)
/* 7EE2DC 802435CC 26100004 */  addiu     $s0, $s0, 4
/* 7EE2E0 802435D0 0220202D */  daddu     $a0, $s1, $zero
/* 7EE2E4 802435D4 0C0B1EAF */  jal       get_variable
/* 7EE2E8 802435D8 0280282D */   daddu    $a1, $s4, $zero
/* 7EE2EC 802435DC 4482D000 */  mtc1      $v0, $f26
/* 7EE2F0 802435E0 00000000 */  nop       
/* 7EE2F4 802435E4 4680D6A0 */  cvt.s.w   $f26, $f26
/* 7EE2F8 802435E8 8E100000 */  lw        $s0, ($s0)
/* 7EE2FC 802435EC 0220202D */  daddu     $a0, $s1, $zero
/* 7EE300 802435F0 0C0B1EAF */  jal       get_variable
/* 7EE304 802435F4 0200282D */   daddu    $a1, $s0, $zero
/* 7EE308 802435F8 4482C000 */  mtc1      $v0, $f24
/* 7EE30C 802435FC 00000000 */  nop       
/* 7EE310 80243600 4680C620 */  cvt.s.w   $f24, $f24
/* 7EE314 80243604 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 7EE318 80243608 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 7EE31C 8024360C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7EE320 80243610 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7EE324 80243614 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 7EE328 80243618 44800000 */  mtc1      $zero, $f0
/* 7EE32C 8024361C 00031080 */  sll       $v0, $v1, 2
/* 7EE330 80243620 00431021 */  addu      $v0, $v0, $v1
/* 7EE334 80243624 00021080 */  sll       $v0, $v0, 2
/* 7EE338 80243628 00431023 */  subu      $v0, $v0, $v1
/* 7EE33C 8024362C 000218C0 */  sll       $v1, $v0, 3
/* 7EE340 80243630 00431021 */  addu      $v0, $v0, $v1
/* 7EE344 80243634 000210C0 */  sll       $v0, $v0, 3
/* 7EE348 80243638 46001032 */  c.eq.s    $f2, $f0
/* 7EE34C 8024363C 3C01800B */  lui       $at, 0x800b
/* 7EE350 80243640 00220821 */  addu      $at, $at, $v0
/* 7EE354 80243644 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* 7EE358 80243648 45000005 */  bc1f      .L80243660
/* 7EE35C 8024364C 00000000 */   nop      
/* 7EE360 80243650 3C0142C8 */  lui       $at, 0x42c8
/* 7EE364 80243654 44810000 */  mtc1      $at, $f0
/* 7EE368 80243658 08090D9C */  j         .L80243670
/* 7EE36C 8024365C 4600B581 */   sub.s    $f22, $f22, $f0
.L80243660:
/* 7EE370 80243660 3C0142C8 */  lui       $at, 0x42c8
/* 7EE374 80243664 44810000 */  mtc1      $at, $f0
/* 7EE378 80243668 00000000 */  nop       
/* 7EE37C 8024366C 4600B580 */  add.s     $f22, $f22, $f0
.L80243670:
/* 7EE380 80243670 0C00A6C9 */  jal       clamp_angle
/* 7EE384 80243674 4600B306 */   mov.s    $f12, $f22
/* 7EE388 80243678 46000586 */  mov.s     $f22, $f0
/* 7EE38C 8024367C 3C014170 */  lui       $at, 0x4170
/* 7EE390 80243680 4481A000 */  mtc1      $at, $f20
/* 7EE394 80243684 0C00A8BB */  jal       sin_deg
/* 7EE398 80243688 4600B306 */   mov.s    $f12, $f22
/* 7EE39C 8024368C 46140002 */  mul.s     $f0, $f0, $f20
/* 7EE3A0 80243690 00000000 */  nop       
/* 7EE3A4 80243694 864200B0 */  lh        $v0, 0xb0($s2)
/* 7EE3A8 80243698 3C013F00 */  lui       $at, 0x3f00
/* 7EE3AC 8024369C 44812000 */  mtc1      $at, $f4
/* 7EE3B0 802436A0 44821000 */  mtc1      $v0, $f2
/* 7EE3B4 802436A4 00000000 */  nop       
/* 7EE3B8 802436A8 468010A0 */  cvt.s.w   $f2, $f2
/* 7EE3BC 802436AC 46041082 */  mul.s     $f2, $f2, $f4
/* 7EE3C0 802436B0 00000000 */  nop       
/* 7EE3C4 802436B4 4600E700 */  add.s     $f28, $f28, $f0
/* 7EE3C8 802436B8 4602D680 */  add.s     $f26, $f26, $f2
/* 7EE3CC 802436BC 0C00A8D4 */  jal       cos_deg
/* 7EE3D0 802436C0 4600B306 */   mov.s    $f12, $f22
/* 7EE3D4 802436C4 46140002 */  mul.s     $f0, $f0, $f20
/* 7EE3D8 802436C8 00000000 */  nop       
/* 7EE3DC 802436CC 0220202D */  daddu     $a0, $s1, $zero
/* 7EE3E0 802436D0 0260282D */  daddu     $a1, $s3, $zero
/* 7EE3E4 802436D4 4600E18D */  trunc.w.s $f6, $f28
/* 7EE3E8 802436D8 44063000 */  mfc1      $a2, $f6
/* 7EE3EC 802436DC 0C0B2026 */  jal       set_variable
/* 7EE3F0 802436E0 4600C601 */   sub.s    $f24, $f24, $f0
/* 7EE3F4 802436E4 0220202D */  daddu     $a0, $s1, $zero
/* 7EE3F8 802436E8 4600D18D */  trunc.w.s $f6, $f26
/* 7EE3FC 802436EC 44063000 */  mfc1      $a2, $f6
/* 7EE400 802436F0 0C0B2026 */  jal       set_variable
/* 7EE404 802436F4 0280282D */   daddu    $a1, $s4, $zero
/* 7EE408 802436F8 0220202D */  daddu     $a0, $s1, $zero
/* 7EE40C 802436FC 4600C18D */  trunc.w.s $f6, $f24
/* 7EE410 80243700 44063000 */  mfc1      $a2, $f6
/* 7EE414 80243704 0C0B2026 */  jal       set_variable
/* 7EE418 80243708 0200282D */   daddu    $a1, $s0, $zero
/* 7EE41C 8024370C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7EE420 80243710 8FB40020 */  lw        $s4, 0x20($sp)
/* 7EE424 80243714 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7EE428 80243718 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EE42C 8024371C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EE430 80243720 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EE434 80243724 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 7EE438 80243728 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 7EE43C 8024372C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 7EE440 80243730 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 7EE444 80243734 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 7EE448 80243738 24020002 */  addiu     $v0, $zero, 2
/* 7EE44C 8024373C 03E00008 */  jr        $ra
/* 7EE450 80243740 27BD0050 */   addiu    $sp, $sp, 0x50
