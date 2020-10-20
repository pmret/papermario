.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F7C_D50F6C
/* D50F6C 80240F7C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D50F70 80240F80 AFB10014 */  sw        $s1, 0x14($sp)
/* D50F74 80240F84 0080882D */  daddu     $s1, $a0, $zero
/* D50F78 80240F88 AFBF0024 */  sw        $ra, 0x24($sp)
/* D50F7C 80240F8C AFB40020 */  sw        $s4, 0x20($sp)
/* D50F80 80240F90 AFB3001C */  sw        $s3, 0x1c($sp)
/* D50F84 80240F94 AFB20018 */  sw        $s2, 0x18($sp)
/* D50F88 80240F98 AFB00010 */  sw        $s0, 0x10($sp)
/* D50F8C 80240F9C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D50F90 80240FA0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D50F94 80240FA4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* D50F98 80240FA8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D50F9C 80240FAC F7B40028 */  sdc1      $f20, 0x28($sp)
/* D50FA0 80240FB0 8E30000C */  lw        $s0, 0xc($s1)
/* D50FA4 80240FB4 8E130000 */  lw        $s3, ($s0)
/* D50FA8 80240FB8 26100004 */  addiu     $s0, $s0, 4
/* D50FAC 80240FBC 0C0B1EAF */  jal       get_variable
/* D50FB0 80240FC0 0260282D */   daddu    $a1, $s3, $zero
/* D50FB4 80240FC4 4482E000 */  mtc1      $v0, $f28
/* D50FB8 80240FC8 00000000 */  nop       
/* D50FBC 80240FCC 4680E720 */  cvt.s.w   $f28, $f28
/* D50FC0 80240FD0 8E140000 */  lw        $s4, ($s0)
/* D50FC4 80240FD4 26100004 */  addiu     $s0, $s0, 4
/* D50FC8 80240FD8 0220202D */  daddu     $a0, $s1, $zero
/* D50FCC 80240FDC 0C0B1EAF */  jal       get_variable
/* D50FD0 80240FE0 0280282D */   daddu    $a1, $s4, $zero
/* D50FD4 80240FE4 4482D000 */  mtc1      $v0, $f26
/* D50FD8 80240FE8 00000000 */  nop       
/* D50FDC 80240FEC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D50FE0 80240FF0 8E100000 */  lw        $s0, ($s0)
/* D50FE4 80240FF4 0220202D */  daddu     $a0, $s1, $zero
/* D50FE8 80240FF8 0C0B1EAF */  jal       get_variable
/* D50FEC 80240FFC 0200282D */   daddu    $a1, $s0, $zero
/* D50FF0 80241000 4482C000 */  mtc1      $v0, $f24
/* D50FF4 80241004 00000000 */  nop       
/* D50FF8 80241008 4680C620 */  cvt.s.w   $f24, $f24
/* D50FFC 8024100C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D51000 80241010 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D51004 80241014 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D51008 80241018 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D5100C 8024101C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* D51010 80241020 44800000 */  mtc1      $zero, $f0
/* D51014 80241024 00031080 */  sll       $v0, $v1, 2
/* D51018 80241028 00431021 */  addu      $v0, $v0, $v1
/* D5101C 8024102C 00021080 */  sll       $v0, $v0, 2
/* D51020 80241030 00431023 */  subu      $v0, $v0, $v1
/* D51024 80241034 000218C0 */  sll       $v1, $v0, 3
/* D51028 80241038 00431021 */  addu      $v0, $v0, $v1
/* D5102C 8024103C 000210C0 */  sll       $v0, $v0, 3
/* D51030 80241040 46001032 */  c.eq.s    $f2, $f0
/* D51034 80241044 3C01800B */  lui       $at, 0x800b
/* D51038 80241048 00220821 */  addu      $at, $at, $v0
/* D5103C 8024104C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D51040 80241050 45000005 */  bc1f      .L80241068
/* D51044 80241054 00000000 */   nop      
/* D51048 80241058 3C0142C8 */  lui       $at, 0x42c8
/* D5104C 8024105C 44810000 */  mtc1      $at, $f0
/* D51050 80241060 0809041E */  j         .L80241078
/* D51054 80241064 4600B581 */   sub.s    $f22, $f22, $f0
.L80241068:
/* D51058 80241068 3C0142C8 */  lui       $at, 0x42c8
/* D5105C 8024106C 44810000 */  mtc1      $at, $f0
/* D51060 80241070 00000000 */  nop       
/* D51064 80241074 4600B580 */  add.s     $f22, $f22, $f0
.L80241078:
/* D51068 80241078 0C00A6C9 */  jal       clamp_angle
/* D5106C 8024107C 4600B306 */   mov.s    $f12, $f22
/* D51070 80241080 46000586 */  mov.s     $f22, $f0
/* D51074 80241084 3C014170 */  lui       $at, 0x4170
/* D51078 80241088 4481A000 */  mtc1      $at, $f20
/* D5107C 8024108C 0C00A8BB */  jal       sin_deg
/* D51080 80241090 4600B306 */   mov.s    $f12, $f22
/* D51084 80241094 46140002 */  mul.s     $f0, $f0, $f20
/* D51088 80241098 00000000 */  nop       
/* D5108C 8024109C 864200B0 */  lh        $v0, 0xb0($s2)
/* D51090 802410A0 3C013F00 */  lui       $at, 0x3f00
/* D51094 802410A4 44812000 */  mtc1      $at, $f4
/* D51098 802410A8 44821000 */  mtc1      $v0, $f2
/* D5109C 802410AC 00000000 */  nop       
/* D510A0 802410B0 468010A0 */  cvt.s.w   $f2, $f2
/* D510A4 802410B4 46041082 */  mul.s     $f2, $f2, $f4
/* D510A8 802410B8 00000000 */  nop       
/* D510AC 802410BC 4600E700 */  add.s     $f28, $f28, $f0
/* D510B0 802410C0 4602D680 */  add.s     $f26, $f26, $f2
/* D510B4 802410C4 0C00A8D4 */  jal       cos_deg
/* D510B8 802410C8 4600B306 */   mov.s    $f12, $f22
/* D510BC 802410CC 46140002 */  mul.s     $f0, $f0, $f20
/* D510C0 802410D0 00000000 */  nop       
/* D510C4 802410D4 0220202D */  daddu     $a0, $s1, $zero
/* D510C8 802410D8 0260282D */  daddu     $a1, $s3, $zero
/* D510CC 802410DC 4600E18D */  trunc.w.s $f6, $f28
/* D510D0 802410E0 44063000 */  mfc1      $a2, $f6
/* D510D4 802410E4 0C0B2026 */  jal       set_variable
/* D510D8 802410E8 4600C601 */   sub.s    $f24, $f24, $f0
/* D510DC 802410EC 0220202D */  daddu     $a0, $s1, $zero
/* D510E0 802410F0 4600D18D */  trunc.w.s $f6, $f26
/* D510E4 802410F4 44063000 */  mfc1      $a2, $f6
/* D510E8 802410F8 0C0B2026 */  jal       set_variable
/* D510EC 802410FC 0280282D */   daddu    $a1, $s4, $zero
/* D510F0 80241100 0220202D */  daddu     $a0, $s1, $zero
/* D510F4 80241104 4600C18D */  trunc.w.s $f6, $f24
/* D510F8 80241108 44063000 */  mfc1      $a2, $f6
/* D510FC 8024110C 0C0B2026 */  jal       set_variable
/* D51100 80241110 0200282D */   daddu    $a1, $s0, $zero
/* D51104 80241114 8FBF0024 */  lw        $ra, 0x24($sp)
/* D51108 80241118 8FB40020 */  lw        $s4, 0x20($sp)
/* D5110C 8024111C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D51110 80241120 8FB20018 */  lw        $s2, 0x18($sp)
/* D51114 80241124 8FB10014 */  lw        $s1, 0x14($sp)
/* D51118 80241128 8FB00010 */  lw        $s0, 0x10($sp)
/* D5111C 8024112C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D51120 80241130 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D51124 80241134 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D51128 80241138 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D5112C 8024113C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D51130 80241140 24020002 */  addiu     $v0, $zero, 2
/* D51134 80241144 03E00008 */  jr        $ra
/* D51138 80241148 27BD0050 */   addiu    $sp, $sp, 0x50
