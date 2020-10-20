.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240568_B20AA8
/* B20AA8 80240568 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B20AAC 8024056C AFB10014 */  sw        $s1, 0x14($sp)
/* B20AB0 80240570 0080882D */  daddu     $s1, $a0, $zero
/* B20AB4 80240574 AFBF0024 */  sw        $ra, 0x24($sp)
/* B20AB8 80240578 AFB40020 */  sw        $s4, 0x20($sp)
/* B20ABC 8024057C AFB3001C */  sw        $s3, 0x1c($sp)
/* B20AC0 80240580 AFB20018 */  sw        $s2, 0x18($sp)
/* B20AC4 80240584 AFB00010 */  sw        $s0, 0x10($sp)
/* B20AC8 80240588 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* B20ACC 8024058C F7BA0040 */  sdc1      $f26, 0x40($sp)
/* B20AD0 80240590 F7B80038 */  sdc1      $f24, 0x38($sp)
/* B20AD4 80240594 F7B60030 */  sdc1      $f22, 0x30($sp)
/* B20AD8 80240598 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B20ADC 8024059C 8E30000C */  lw        $s0, 0xc($s1)
/* B20AE0 802405A0 8E130000 */  lw        $s3, ($s0)
/* B20AE4 802405A4 26100004 */  addiu     $s0, $s0, 4
/* B20AE8 802405A8 0C0B1EAF */  jal       get_variable
/* B20AEC 802405AC 0260282D */   daddu    $a1, $s3, $zero
/* B20AF0 802405B0 4482E000 */  mtc1      $v0, $f28
/* B20AF4 802405B4 00000000 */  nop       
/* B20AF8 802405B8 4680E720 */  cvt.s.w   $f28, $f28
/* B20AFC 802405BC 8E140000 */  lw        $s4, ($s0)
/* B20B00 802405C0 26100004 */  addiu     $s0, $s0, 4
/* B20B04 802405C4 0220202D */  daddu     $a0, $s1, $zero
/* B20B08 802405C8 0C0B1EAF */  jal       get_variable
/* B20B0C 802405CC 0280282D */   daddu    $a1, $s4, $zero
/* B20B10 802405D0 4482D000 */  mtc1      $v0, $f26
/* B20B14 802405D4 00000000 */  nop       
/* B20B18 802405D8 4680D6A0 */  cvt.s.w   $f26, $f26
/* B20B1C 802405DC 8E100000 */  lw        $s0, ($s0)
/* B20B20 802405E0 0220202D */  daddu     $a0, $s1, $zero
/* B20B24 802405E4 0C0B1EAF */  jal       get_variable
/* B20B28 802405E8 0200282D */   daddu    $a1, $s0, $zero
/* B20B2C 802405EC 4482C000 */  mtc1      $v0, $f24
/* B20B30 802405F0 00000000 */  nop       
/* B20B34 802405F4 4680C620 */  cvt.s.w   $f24, $f24
/* B20B38 802405F8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* B20B3C 802405FC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* B20B40 80240600 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* B20B44 80240604 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* B20B48 80240608 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* B20B4C 8024060C 44800000 */  mtc1      $zero, $f0
/* B20B50 80240610 00031080 */  sll       $v0, $v1, 2
/* B20B54 80240614 00431021 */  addu      $v0, $v0, $v1
/* B20B58 80240618 00021080 */  sll       $v0, $v0, 2
/* B20B5C 8024061C 00431023 */  subu      $v0, $v0, $v1
/* B20B60 80240620 000218C0 */  sll       $v1, $v0, 3
/* B20B64 80240624 00431021 */  addu      $v0, $v0, $v1
/* B20B68 80240628 000210C0 */  sll       $v0, $v0, 3
/* B20B6C 8024062C 46001032 */  c.eq.s    $f2, $f0
/* B20B70 80240630 3C01800B */  lui       $at, 0x800b
/* B20B74 80240634 00220821 */  addu      $at, $at, $v0
/* B20B78 80240638 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* B20B7C 8024063C 45000005 */  bc1f      .L80240654
/* B20B80 80240640 00000000 */   nop      
/* B20B84 80240644 3C0142C8 */  lui       $at, 0x42c8
/* B20B88 80240648 44810000 */  mtc1      $at, $f0
/* B20B8C 8024064C 08090199 */  j         .L80240664
/* B20B90 80240650 4600B581 */   sub.s    $f22, $f22, $f0
.L80240654:
/* B20B94 80240654 3C0142C8 */  lui       $at, 0x42c8
/* B20B98 80240658 44810000 */  mtc1      $at, $f0
/* B20B9C 8024065C 00000000 */  nop       
/* B20BA0 80240660 4600B580 */  add.s     $f22, $f22, $f0
.L80240664:
/* B20BA4 80240664 0C00A6C9 */  jal       clamp_angle
/* B20BA8 80240668 4600B306 */   mov.s    $f12, $f22
/* B20BAC 8024066C 46000586 */  mov.s     $f22, $f0
/* B20BB0 80240670 3C014170 */  lui       $at, 0x4170
/* B20BB4 80240674 4481A000 */  mtc1      $at, $f20
/* B20BB8 80240678 0C00A8BB */  jal       sin_deg
/* B20BBC 8024067C 4600B306 */   mov.s    $f12, $f22
/* B20BC0 80240680 46140002 */  mul.s     $f0, $f0, $f20
/* B20BC4 80240684 00000000 */  nop       
/* B20BC8 80240688 864200B0 */  lh        $v0, 0xb0($s2)
/* B20BCC 8024068C 3C013F00 */  lui       $at, 0x3f00
/* B20BD0 80240690 44812000 */  mtc1      $at, $f4
/* B20BD4 80240694 44821000 */  mtc1      $v0, $f2
/* B20BD8 80240698 00000000 */  nop       
/* B20BDC 8024069C 468010A0 */  cvt.s.w   $f2, $f2
/* B20BE0 802406A0 46041082 */  mul.s     $f2, $f2, $f4
/* B20BE4 802406A4 00000000 */  nop       
/* B20BE8 802406A8 4600E700 */  add.s     $f28, $f28, $f0
/* B20BEC 802406AC 4602D680 */  add.s     $f26, $f26, $f2
/* B20BF0 802406B0 0C00A8D4 */  jal       cos_deg
/* B20BF4 802406B4 4600B306 */   mov.s    $f12, $f22
/* B20BF8 802406B8 46140002 */  mul.s     $f0, $f0, $f20
/* B20BFC 802406BC 00000000 */  nop       
/* B20C00 802406C0 0220202D */  daddu     $a0, $s1, $zero
/* B20C04 802406C4 0260282D */  daddu     $a1, $s3, $zero
/* B20C08 802406C8 4600E18D */  trunc.w.s $f6, $f28
/* B20C0C 802406CC 44063000 */  mfc1      $a2, $f6
/* B20C10 802406D0 0C0B2026 */  jal       set_variable
/* B20C14 802406D4 4600C601 */   sub.s    $f24, $f24, $f0
/* B20C18 802406D8 0220202D */  daddu     $a0, $s1, $zero
/* B20C1C 802406DC 4600D18D */  trunc.w.s $f6, $f26
/* B20C20 802406E0 44063000 */  mfc1      $a2, $f6
/* B20C24 802406E4 0C0B2026 */  jal       set_variable
/* B20C28 802406E8 0280282D */   daddu    $a1, $s4, $zero
/* B20C2C 802406EC 0220202D */  daddu     $a0, $s1, $zero
/* B20C30 802406F0 4600C18D */  trunc.w.s $f6, $f24
/* B20C34 802406F4 44063000 */  mfc1      $a2, $f6
/* B20C38 802406F8 0C0B2026 */  jal       set_variable
/* B20C3C 802406FC 0200282D */   daddu    $a1, $s0, $zero
/* B20C40 80240700 8FBF0024 */  lw        $ra, 0x24($sp)
/* B20C44 80240704 8FB40020 */  lw        $s4, 0x20($sp)
/* B20C48 80240708 8FB3001C */  lw        $s3, 0x1c($sp)
/* B20C4C 8024070C 8FB20018 */  lw        $s2, 0x18($sp)
/* B20C50 80240710 8FB10014 */  lw        $s1, 0x14($sp)
/* B20C54 80240714 8FB00010 */  lw        $s0, 0x10($sp)
/* B20C58 80240718 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* B20C5C 8024071C D7BA0040 */  ldc1      $f26, 0x40($sp)
/* B20C60 80240720 D7B80038 */  ldc1      $f24, 0x38($sp)
/* B20C64 80240724 D7B60030 */  ldc1      $f22, 0x30($sp)
/* B20C68 80240728 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B20C6C 8024072C 24020002 */  addiu     $v0, $zero, 2
/* B20C70 80240730 03E00008 */  jr        $ra
/* B20C74 80240734 27BD0050 */   addiu    $sp, $sp, 0x50
