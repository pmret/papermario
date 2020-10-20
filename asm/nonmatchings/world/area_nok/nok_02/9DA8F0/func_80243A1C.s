.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243A1C
/* 9DAA3C 80243A1C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9DAA40 80243A20 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DAA44 80243A24 0080882D */  daddu     $s1, $a0, $zero
/* 9DAA48 80243A28 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9DAA4C 80243A2C AFB40020 */  sw        $s4, 0x20($sp)
/* 9DAA50 80243A30 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9DAA54 80243A34 AFB20018 */  sw        $s2, 0x18($sp)
/* 9DAA58 80243A38 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DAA5C 80243A3C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 9DAA60 80243A40 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 9DAA64 80243A44 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 9DAA68 80243A48 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 9DAA6C 80243A4C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 9DAA70 80243A50 8E30000C */  lw        $s0, 0xc($s1)
/* 9DAA74 80243A54 8E130000 */  lw        $s3, ($s0)
/* 9DAA78 80243A58 26100004 */  addiu     $s0, $s0, 4
/* 9DAA7C 80243A5C 0C0B1EAF */  jal       get_variable
/* 9DAA80 80243A60 0260282D */   daddu    $a1, $s3, $zero
/* 9DAA84 80243A64 4482E000 */  mtc1      $v0, $f28
/* 9DAA88 80243A68 00000000 */  nop       
/* 9DAA8C 80243A6C 4680E720 */  cvt.s.w   $f28, $f28
/* 9DAA90 80243A70 8E140000 */  lw        $s4, ($s0)
/* 9DAA94 80243A74 26100004 */  addiu     $s0, $s0, 4
/* 9DAA98 80243A78 0220202D */  daddu     $a0, $s1, $zero
/* 9DAA9C 80243A7C 0C0B1EAF */  jal       get_variable
/* 9DAAA0 80243A80 0280282D */   daddu    $a1, $s4, $zero
/* 9DAAA4 80243A84 4482D000 */  mtc1      $v0, $f26
/* 9DAAA8 80243A88 00000000 */  nop       
/* 9DAAAC 80243A8C 4680D6A0 */  cvt.s.w   $f26, $f26
/* 9DAAB0 80243A90 8E100000 */  lw        $s0, ($s0)
/* 9DAAB4 80243A94 0220202D */  daddu     $a0, $s1, $zero
/* 9DAAB8 80243A98 0C0B1EAF */  jal       get_variable
/* 9DAABC 80243A9C 0200282D */   daddu    $a1, $s0, $zero
/* 9DAAC0 80243AA0 4482C000 */  mtc1      $v0, $f24
/* 9DAAC4 80243AA4 00000000 */  nop       
/* 9DAAC8 80243AA8 4680C620 */  cvt.s.w   $f24, $f24
/* 9DAACC 80243AAC 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 9DAAD0 80243AB0 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 9DAAD4 80243AB4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 9DAAD8 80243AB8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 9DAADC 80243ABC C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 9DAAE0 80243AC0 44800000 */  mtc1      $zero, $f0
/* 9DAAE4 80243AC4 00031080 */  sll       $v0, $v1, 2
/* 9DAAE8 80243AC8 00431021 */  addu      $v0, $v0, $v1
/* 9DAAEC 80243ACC 00021080 */  sll       $v0, $v0, 2
/* 9DAAF0 80243AD0 00431023 */  subu      $v0, $v0, $v1
/* 9DAAF4 80243AD4 000218C0 */  sll       $v1, $v0, 3
/* 9DAAF8 80243AD8 00431021 */  addu      $v0, $v0, $v1
/* 9DAAFC 80243ADC 000210C0 */  sll       $v0, $v0, 3
/* 9DAB00 80243AE0 46001032 */  c.eq.s    $f2, $f0
/* 9DAB04 80243AE4 3C01800B */  lui       $at, 0x800b
/* 9DAB08 80243AE8 00220821 */  addu      $at, $at, $v0
/* 9DAB0C 80243AEC C4361DEC */  lwc1      $f22, 0x1dec($at)
/* 9DAB10 80243AF0 45000005 */  bc1f      .L80243B08
/* 9DAB14 80243AF4 00000000 */   nop      
/* 9DAB18 80243AF8 3C0142C8 */  lui       $at, 0x42c8
/* 9DAB1C 80243AFC 44810000 */  mtc1      $at, $f0
/* 9DAB20 80243B00 08090EC6 */  j         .L80243B18
/* 9DAB24 80243B04 4600B581 */   sub.s    $f22, $f22, $f0
.L80243B08:
/* 9DAB28 80243B08 3C0142C8 */  lui       $at, 0x42c8
/* 9DAB2C 80243B0C 44810000 */  mtc1      $at, $f0
/* 9DAB30 80243B10 00000000 */  nop       
/* 9DAB34 80243B14 4600B580 */  add.s     $f22, $f22, $f0
.L80243B18:
/* 9DAB38 80243B18 0C00A6C9 */  jal       clamp_angle
/* 9DAB3C 80243B1C 4600B306 */   mov.s    $f12, $f22
/* 9DAB40 80243B20 46000586 */  mov.s     $f22, $f0
/* 9DAB44 80243B24 3C014170 */  lui       $at, 0x4170
/* 9DAB48 80243B28 4481A000 */  mtc1      $at, $f20
/* 9DAB4C 80243B2C 0C00A8BB */  jal       sin_deg
/* 9DAB50 80243B30 4600B306 */   mov.s    $f12, $f22
/* 9DAB54 80243B34 46140002 */  mul.s     $f0, $f0, $f20
/* 9DAB58 80243B38 00000000 */  nop       
/* 9DAB5C 80243B3C 864200B0 */  lh        $v0, 0xb0($s2)
/* 9DAB60 80243B40 3C013F00 */  lui       $at, 0x3f00
/* 9DAB64 80243B44 44812000 */  mtc1      $at, $f4
/* 9DAB68 80243B48 44821000 */  mtc1      $v0, $f2
/* 9DAB6C 80243B4C 00000000 */  nop       
/* 9DAB70 80243B50 468010A0 */  cvt.s.w   $f2, $f2
/* 9DAB74 80243B54 46041082 */  mul.s     $f2, $f2, $f4
/* 9DAB78 80243B58 00000000 */  nop       
/* 9DAB7C 80243B5C 4600E700 */  add.s     $f28, $f28, $f0
/* 9DAB80 80243B60 4602D680 */  add.s     $f26, $f26, $f2
/* 9DAB84 80243B64 0C00A8D4 */  jal       cos_deg
/* 9DAB88 80243B68 4600B306 */   mov.s    $f12, $f22
/* 9DAB8C 80243B6C 46140002 */  mul.s     $f0, $f0, $f20
/* 9DAB90 80243B70 00000000 */  nop       
/* 9DAB94 80243B74 0220202D */  daddu     $a0, $s1, $zero
/* 9DAB98 80243B78 0260282D */  daddu     $a1, $s3, $zero
/* 9DAB9C 80243B7C 4600E18D */  trunc.w.s $f6, $f28
/* 9DABA0 80243B80 44063000 */  mfc1      $a2, $f6
/* 9DABA4 80243B84 0C0B2026 */  jal       set_variable
/* 9DABA8 80243B88 4600C601 */   sub.s    $f24, $f24, $f0
/* 9DABAC 80243B8C 0220202D */  daddu     $a0, $s1, $zero
/* 9DABB0 80243B90 4600D18D */  trunc.w.s $f6, $f26
/* 9DABB4 80243B94 44063000 */  mfc1      $a2, $f6
/* 9DABB8 80243B98 0C0B2026 */  jal       set_variable
/* 9DABBC 80243B9C 0280282D */   daddu    $a1, $s4, $zero
/* 9DABC0 80243BA0 0220202D */  daddu     $a0, $s1, $zero
/* 9DABC4 80243BA4 4600C18D */  trunc.w.s $f6, $f24
/* 9DABC8 80243BA8 44063000 */  mfc1      $a2, $f6
/* 9DABCC 80243BAC 0C0B2026 */  jal       set_variable
/* 9DABD0 80243BB0 0200282D */   daddu    $a1, $s0, $zero
/* 9DABD4 80243BB4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9DABD8 80243BB8 8FB40020 */  lw        $s4, 0x20($sp)
/* 9DABDC 80243BBC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9DABE0 80243BC0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9DABE4 80243BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DABE8 80243BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DABEC 80243BCC D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 9DABF0 80243BD0 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 9DABF4 80243BD4 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 9DABF8 80243BD8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 9DABFC 80243BDC D7B40028 */  ldc1      $f20, 0x28($sp)
/* 9DAC00 80243BE0 24020002 */  addiu     $v0, $zero, 2
/* 9DAC04 80243BE4 03E00008 */  jr        $ra
/* 9DAC08 80243BE8 27BD0050 */   addiu    $sp, $sp, 0x50
