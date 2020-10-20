.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EE0_B98AE0
/* B98AE0 80240EE0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B98AE4 80240EE4 AFB10014 */  sw        $s1, 0x14($sp)
/* B98AE8 80240EE8 0080882D */  daddu     $s1, $a0, $zero
/* B98AEC 80240EEC AFBF0024 */  sw        $ra, 0x24($sp)
/* B98AF0 80240EF0 AFB40020 */  sw        $s4, 0x20($sp)
/* B98AF4 80240EF4 AFB3001C */  sw        $s3, 0x1c($sp)
/* B98AF8 80240EF8 AFB20018 */  sw        $s2, 0x18($sp)
/* B98AFC 80240EFC AFB00010 */  sw        $s0, 0x10($sp)
/* B98B00 80240F00 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* B98B04 80240F04 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* B98B08 80240F08 F7B80038 */  sdc1      $f24, 0x38($sp)
/* B98B0C 80240F0C F7B60030 */  sdc1      $f22, 0x30($sp)
/* B98B10 80240F10 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B98B14 80240F14 8E30000C */  lw        $s0, 0xc($s1)
/* B98B18 80240F18 8E130000 */  lw        $s3, ($s0)
/* B98B1C 80240F1C 26100004 */  addiu     $s0, $s0, 4
/* B98B20 80240F20 0C0B1EAF */  jal       get_variable
/* B98B24 80240F24 0260282D */   daddu    $a1, $s3, $zero
/* B98B28 80240F28 4482E000 */  mtc1      $v0, $f28
/* B98B2C 80240F2C 00000000 */  nop       
/* B98B30 80240F30 4680E720 */  cvt.s.w   $f28, $f28
/* B98B34 80240F34 8E140000 */  lw        $s4, ($s0)
/* B98B38 80240F38 26100004 */  addiu     $s0, $s0, 4
/* B98B3C 80240F3C 0220202D */  daddu     $a0, $s1, $zero
/* B98B40 80240F40 0C0B1EAF */  jal       get_variable
/* B98B44 80240F44 0280282D */   daddu    $a1, $s4, $zero
/* B98B48 80240F48 4482D000 */  mtc1      $v0, $f26
/* B98B4C 80240F4C 00000000 */  nop       
/* B98B50 80240F50 4680D6A0 */  cvt.s.w   $f26, $f26
/* B98B54 80240F54 8E100000 */  lw        $s0, ($s0)
/* B98B58 80240F58 0220202D */  daddu     $a0, $s1, $zero
/* B98B5C 80240F5C 0C0B1EAF */  jal       get_variable
/* B98B60 80240F60 0200282D */   daddu    $a1, $s0, $zero
/* B98B64 80240F64 4482C000 */  mtc1      $v0, $f24
/* B98B68 80240F68 00000000 */  nop       
/* B98B6C 80240F6C 4680C620 */  cvt.s.w   $f24, $f24
/* B98B70 80240F70 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* B98B74 80240F74 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* B98B78 80240F78 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* B98B7C 80240F7C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* B98B80 80240F80 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* B98B84 80240F84 44800000 */  mtc1      $zero, $f0
/* B98B88 80240F88 00031080 */  sll       $v0, $v1, 2
/* B98B8C 80240F8C 00431021 */  addu      $v0, $v0, $v1
/* B98B90 80240F90 00021080 */  sll       $v0, $v0, 2
/* B98B94 80240F94 00431023 */  subu      $v0, $v0, $v1
/* B98B98 80240F98 000218C0 */  sll       $v1, $v0, 3
/* B98B9C 80240F9C 00431021 */  addu      $v0, $v0, $v1
/* B98BA0 80240FA0 000210C0 */  sll       $v0, $v0, 3
/* B98BA4 80240FA4 46001032 */  c.eq.s    $f2, $f0
/* B98BA8 80240FA8 3C01800B */  lui       $at, 0x800b
/* B98BAC 80240FAC 00220821 */  addu      $at, $at, $v0
/* B98BB0 80240FB0 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* B98BB4 80240FB4 45000005 */  bc1f      .L80240FCC
/* B98BB8 80240FB8 00000000 */   nop      
/* B98BBC 80240FBC 3C0142C8 */  lui       $at, 0x42c8
/* B98BC0 80240FC0 44810000 */  mtc1      $at, $f0
/* B98BC4 80240FC4 080903F7 */  j         .L80240FDC
/* B98BC8 80240FC8 4600B581 */   sub.s    $f22, $f22, $f0
.L80240FCC:
/* B98BCC 80240FCC 3C0142C8 */  lui       $at, 0x42c8
/* B98BD0 80240FD0 44810000 */  mtc1      $at, $f0
/* B98BD4 80240FD4 00000000 */  nop       
/* B98BD8 80240FD8 4600B580 */  add.s     $f22, $f22, $f0
.L80240FDC:
/* B98BDC 80240FDC 0C00A6C9 */  jal       clamp_angle
/* B98BE0 80240FE0 4600B306 */   mov.s    $f12, $f22
/* B98BE4 80240FE4 46000586 */  mov.s     $f22, $f0
/* B98BE8 80240FE8 3C014170 */  lui       $at, 0x4170
/* B98BEC 80240FEC 4481A000 */  mtc1      $at, $f20
/* B98BF0 80240FF0 0C00A8BB */  jal       sin_deg
/* B98BF4 80240FF4 4600B306 */   mov.s    $f12, $f22
/* B98BF8 80240FF8 46140002 */  mul.s     $f0, $f0, $f20
/* B98BFC 80240FFC 00000000 */  nop       
/* B98C00 80241000 864200B0 */  lh        $v0, 0xb0($s2)
/* B98C04 80241004 3C013F00 */  lui       $at, 0x3f00
/* B98C08 80241008 44812000 */  mtc1      $at, $f4
/* B98C0C 8024100C 44821000 */  mtc1      $v0, $f2
/* B98C10 80241010 00000000 */  nop       
/* B98C14 80241014 468010A0 */  cvt.s.w   $f2, $f2
/* B98C18 80241018 46041082 */  mul.s     $f2, $f2, $f4
/* B98C1C 8024101C 00000000 */  nop       
/* B98C20 80241020 4600E700 */  add.s     $f28, $f28, $f0
/* B98C24 80241024 4602D680 */  add.s     $f26, $f26, $f2
/* B98C28 80241028 0C00A8D4 */  jal       cos_deg
/* B98C2C 8024102C 4600B306 */   mov.s    $f12, $f22
/* B98C30 80241030 46140002 */  mul.s     $f0, $f0, $f20
/* B98C34 80241034 00000000 */  nop       
/* B98C38 80241038 0220202D */  daddu     $a0, $s1, $zero
/* B98C3C 8024103C 0260282D */  daddu     $a1, $s3, $zero
/* B98C40 80241040 4600E18D */  trunc.w.s $f6, $f28
/* B98C44 80241044 44063000 */  mfc1      $a2, $f6
/* B98C48 80241048 0C0B2026 */  jal       set_variable
/* B98C4C 8024104C 4600C601 */   sub.s    $f24, $f24, $f0
/* B98C50 80241050 0220202D */  daddu     $a0, $s1, $zero
/* B98C54 80241054 4600D18D */  trunc.w.s $f6, $f26
/* B98C58 80241058 44063000 */  mfc1      $a2, $f6
/* B98C5C 8024105C 0C0B2026 */  jal       set_variable
/* B98C60 80241060 0280282D */   daddu    $a1, $s4, $zero
/* B98C64 80241064 0220202D */  daddu     $a0, $s1, $zero
/* B98C68 80241068 4600C18D */  trunc.w.s $f6, $f24
/* B98C6C 8024106C 44063000 */  mfc1      $a2, $f6
/* B98C70 80241070 0C0B2026 */  jal       set_variable
/* B98C74 80241074 0200282D */   daddu    $a1, $s0, $zero
/* B98C78 80241078 8FBF0024 */  lw        $ra, 0x24($sp)
/* B98C7C 8024107C 8FB40020 */  lw        $s4, 0x20($sp)
/* B98C80 80241080 8FB3001C */  lw        $s3, 0x1c($sp)
/* B98C84 80241084 8FB20018 */  lw        $s2, 0x18($sp)
/* B98C88 80241088 8FB10014 */  lw        $s1, 0x14($sp)
/* B98C8C 8024108C 8FB00010 */  lw        $s0, 0x10($sp)
/* B98C90 80241090 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* B98C94 80241094 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* B98C98 80241098 D7B80038 */  ldc1      $f24, 0x38($sp)
/* B98C9C 8024109C D7B60030 */  ldc1      $f22, 0x30($sp)
/* B98CA0 802410A0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B98CA4 802410A4 24020002 */  addiu     $v0, $zero, 2
/* B98CA8 802410A8 03E00008 */  jr        $ra
/* B98CAC 802410AC 27BD0050 */   addiu    $sp, $sp, 0x50
