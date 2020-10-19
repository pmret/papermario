.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FDC_D4E01C
/* D4E01C 80240FDC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D4E020 80240FE0 AFB10014 */  sw        $s1, 0x14($sp)
/* D4E024 80240FE4 0080882D */  daddu     $s1, $a0, $zero
/* D4E028 80240FE8 AFBF0024 */  sw        $ra, 0x24($sp)
/* D4E02C 80240FEC AFB40020 */  sw        $s4, 0x20($sp)
/* D4E030 80240FF0 AFB3001C */  sw        $s3, 0x1c($sp)
/* D4E034 80240FF4 AFB20018 */  sw        $s2, 0x18($sp)
/* D4E038 80240FF8 AFB00010 */  sw        $s0, 0x10($sp)
/* D4E03C 80240FFC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D4E040 80241000 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D4E044 80241004 F7B80038 */  sdc1      $f24, 0x38($sp)
/* D4E048 80241008 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D4E04C 8024100C F7B40028 */  sdc1      $f20, 0x28($sp)
/* D4E050 80241010 8E30000C */  lw        $s0, 0xc($s1)
/* D4E054 80241014 8E130000 */  lw        $s3, ($s0)
/* D4E058 80241018 26100004 */  addiu     $s0, $s0, 4
/* D4E05C 8024101C 0C0B1EAF */  jal       get_variable
/* D4E060 80241020 0260282D */   daddu    $a1, $s3, $zero
/* D4E064 80241024 4482E000 */  mtc1      $v0, $f28
/* D4E068 80241028 00000000 */  nop       
/* D4E06C 8024102C 4680E720 */  cvt.s.w   $f28, $f28
/* D4E070 80241030 8E140000 */  lw        $s4, ($s0)
/* D4E074 80241034 26100004 */  addiu     $s0, $s0, 4
/* D4E078 80241038 0220202D */  daddu     $a0, $s1, $zero
/* D4E07C 8024103C 0C0B1EAF */  jal       get_variable
/* D4E080 80241040 0280282D */   daddu    $a1, $s4, $zero
/* D4E084 80241044 4482D000 */  mtc1      $v0, $f26
/* D4E088 80241048 00000000 */  nop       
/* D4E08C 8024104C 4680D6A0 */  cvt.s.w   $f26, $f26
/* D4E090 80241050 8E100000 */  lw        $s0, ($s0)
/* D4E094 80241054 0220202D */  daddu     $a0, $s1, $zero
/* D4E098 80241058 0C0B1EAF */  jal       get_variable
/* D4E09C 8024105C 0200282D */   daddu    $a1, $s0, $zero
/* D4E0A0 80241060 4482C000 */  mtc1      $v0, $f24
/* D4E0A4 80241064 00000000 */  nop       
/* D4E0A8 80241068 4680C620 */  cvt.s.w   $f24, $f24
/* D4E0AC 8024106C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D4E0B0 80241070 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D4E0B4 80241074 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D4E0B8 80241078 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D4E0BC 8024107C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* D4E0C0 80241080 44800000 */  mtc1      $zero, $f0
/* D4E0C4 80241084 00031080 */  sll       $v0, $v1, 2
/* D4E0C8 80241088 00431021 */  addu      $v0, $v0, $v1
/* D4E0CC 8024108C 00021080 */  sll       $v0, $v0, 2
/* D4E0D0 80241090 00431023 */  subu      $v0, $v0, $v1
/* D4E0D4 80241094 000218C0 */  sll       $v1, $v0, 3
/* D4E0D8 80241098 00431021 */  addu      $v0, $v0, $v1
/* D4E0DC 8024109C 000210C0 */  sll       $v0, $v0, 3
/* D4E0E0 802410A0 46001032 */  c.eq.s    $f2, $f0
/* D4E0E4 802410A4 3C01800B */  lui       $at, 0x800b
/* D4E0E8 802410A8 00220821 */  addu      $at, $at, $v0
/* D4E0EC 802410AC C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D4E0F0 802410B0 45000005 */  bc1f      .L802410C8
/* D4E0F4 802410B4 00000000 */   nop      
/* D4E0F8 802410B8 3C0142C8 */  lui       $at, 0x42c8
/* D4E0FC 802410BC 44810000 */  mtc1      $at, $f0
/* D4E100 802410C0 08090436 */  j         .L802410D8
/* D4E104 802410C4 4600B581 */   sub.s    $f22, $f22, $f0
.L802410C8:
/* D4E108 802410C8 3C0142C8 */  lui       $at, 0x42c8
/* D4E10C 802410CC 44810000 */  mtc1      $at, $f0
/* D4E110 802410D0 00000000 */  nop       
/* D4E114 802410D4 4600B580 */  add.s     $f22, $f22, $f0
.L802410D8:
/* D4E118 802410D8 0C00A6C9 */  jal       clamp_angle
/* D4E11C 802410DC 4600B306 */   mov.s    $f12, $f22
/* D4E120 802410E0 46000586 */  mov.s     $f22, $f0
/* D4E124 802410E4 3C014170 */  lui       $at, 0x4170
/* D4E128 802410E8 4481A000 */  mtc1      $at, $f20
/* D4E12C 802410EC 0C00A8BB */  jal       sin_deg
/* D4E130 802410F0 4600B306 */   mov.s    $f12, $f22
/* D4E134 802410F4 46140002 */  mul.s     $f0, $f0, $f20
/* D4E138 802410F8 00000000 */  nop       
/* D4E13C 802410FC 864200B0 */  lh        $v0, 0xb0($s2)
/* D4E140 80241100 3C013F00 */  lui       $at, 0x3f00
/* D4E144 80241104 44812000 */  mtc1      $at, $f4
/* D4E148 80241108 44821000 */  mtc1      $v0, $f2
/* D4E14C 8024110C 00000000 */  nop       
/* D4E150 80241110 468010A0 */  cvt.s.w   $f2, $f2
/* D4E154 80241114 46041082 */  mul.s     $f2, $f2, $f4
/* D4E158 80241118 00000000 */  nop       
/* D4E15C 8024111C 4600E700 */  add.s     $f28, $f28, $f0
/* D4E160 80241120 4602D680 */  add.s     $f26, $f26, $f2
/* D4E164 80241124 0C00A8D4 */  jal       cos_deg
/* D4E168 80241128 4600B306 */   mov.s    $f12, $f22
/* D4E16C 8024112C 46140002 */  mul.s     $f0, $f0, $f20
/* D4E170 80241130 00000000 */  nop       
/* D4E174 80241134 0220202D */  daddu     $a0, $s1, $zero
/* D4E178 80241138 0260282D */  daddu     $a1, $s3, $zero
/* D4E17C 8024113C 4600E18D */  trunc.w.s $f6, $f28
/* D4E180 80241140 44063000 */  mfc1      $a2, $f6
/* D4E184 80241144 0C0B2026 */  jal       set_variable
/* D4E188 80241148 4600C601 */   sub.s    $f24, $f24, $f0
/* D4E18C 8024114C 0220202D */  daddu     $a0, $s1, $zero
/* D4E190 80241150 4600D18D */  trunc.w.s $f6, $f26
/* D4E194 80241154 44063000 */  mfc1      $a2, $f6
/* D4E198 80241158 0C0B2026 */  jal       set_variable
/* D4E19C 8024115C 0280282D */   daddu    $a1, $s4, $zero
/* D4E1A0 80241160 0220202D */  daddu     $a0, $s1, $zero
/* D4E1A4 80241164 4600C18D */  trunc.w.s $f6, $f24
/* D4E1A8 80241168 44063000 */  mfc1      $a2, $f6
/* D4E1AC 8024116C 0C0B2026 */  jal       set_variable
/* D4E1B0 80241170 0200282D */   daddu    $a1, $s0, $zero
/* D4E1B4 80241174 8FBF0024 */  lw        $ra, 0x24($sp)
/* D4E1B8 80241178 8FB40020 */  lw        $s4, 0x20($sp)
/* D4E1BC 8024117C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D4E1C0 80241180 8FB20018 */  lw        $s2, 0x18($sp)
/* D4E1C4 80241184 8FB10014 */  lw        $s1, 0x14($sp)
/* D4E1C8 80241188 8FB00010 */  lw        $s0, 0x10($sp)
/* D4E1CC 8024118C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D4E1D0 80241190 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D4E1D4 80241194 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D4E1D8 80241198 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D4E1DC 8024119C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D4E1E0 802411A0 24020002 */  addiu     $v0, $zero, 2
/* D4E1E4 802411A4 03E00008 */  jr        $ra
/* D4E1E8 802411A8 27BD0050 */   addiu    $sp, $sp, 0x50
