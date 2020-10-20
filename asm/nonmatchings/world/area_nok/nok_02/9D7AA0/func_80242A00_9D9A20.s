.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A00_9D9A20
/* 9D9A20 80242A00 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9D9A24 80242A04 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D9A28 80242A08 0080882D */  daddu     $s1, $a0, $zero
/* 9D9A2C 80242A0C AFBF0024 */  sw        $ra, 0x24($sp)
/* 9D9A30 80242A10 AFB40020 */  sw        $s4, 0x20($sp)
/* 9D9A34 80242A14 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9D9A38 80242A18 AFB20018 */  sw        $s2, 0x18($sp)
/* 9D9A3C 80242A1C AFB00010 */  sw        $s0, 0x10($sp)
/* 9D9A40 80242A20 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 9D9A44 80242A24 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 9D9A48 80242A28 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 9D9A4C 80242A2C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 9D9A50 80242A30 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 9D9A54 80242A34 8E30000C */  lw        $s0, 0xc($s1)
/* 9D9A58 80242A38 8E130000 */  lw        $s3, ($s0)
/* 9D9A5C 80242A3C 26100004 */  addiu     $s0, $s0, 4
/* 9D9A60 80242A40 0C0B1EAF */  jal       get_variable
/* 9D9A64 80242A44 0260282D */   daddu    $a1, $s3, $zero
/* 9D9A68 80242A48 4482E000 */  mtc1      $v0, $f28
/* 9D9A6C 80242A4C 00000000 */  nop       
/* 9D9A70 80242A50 4680E720 */  cvt.s.w   $f28, $f28
/* 9D9A74 80242A54 8E140000 */  lw        $s4, ($s0)
/* 9D9A78 80242A58 26100004 */  addiu     $s0, $s0, 4
/* 9D9A7C 80242A5C 0220202D */  daddu     $a0, $s1, $zero
/* 9D9A80 80242A60 0C0B1EAF */  jal       get_variable
/* 9D9A84 80242A64 0280282D */   daddu    $a1, $s4, $zero
/* 9D9A88 80242A68 4482D000 */  mtc1      $v0, $f26
/* 9D9A8C 80242A6C 00000000 */  nop       
/* 9D9A90 80242A70 4680D6A0 */  cvt.s.w   $f26, $f26
/* 9D9A94 80242A74 8E100000 */  lw        $s0, ($s0)
/* 9D9A98 80242A78 0220202D */  daddu     $a0, $s1, $zero
/* 9D9A9C 80242A7C 0C0B1EAF */  jal       get_variable
/* 9D9AA0 80242A80 0200282D */   daddu    $a1, $s0, $zero
/* 9D9AA4 80242A84 4482C000 */  mtc1      $v0, $f24
/* 9D9AA8 80242A88 00000000 */  nop       
/* 9D9AAC 80242A8C 4680C620 */  cvt.s.w   $f24, $f24
/* 9D9AB0 80242A90 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 9D9AB4 80242A94 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 9D9AB8 80242A98 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 9D9ABC 80242A9C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 9D9AC0 80242AA0 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 9D9AC4 80242AA4 44800000 */  mtc1      $zero, $f0
/* 9D9AC8 80242AA8 00031080 */  sll       $v0, $v1, 2
/* 9D9ACC 80242AAC 00431021 */  addu      $v0, $v0, $v1
/* 9D9AD0 80242AB0 00021080 */  sll       $v0, $v0, 2
/* 9D9AD4 80242AB4 00431023 */  subu      $v0, $v0, $v1
/* 9D9AD8 80242AB8 000218C0 */  sll       $v1, $v0, 3
/* 9D9ADC 80242ABC 00431021 */  addu      $v0, $v0, $v1
/* 9D9AE0 80242AC0 000210C0 */  sll       $v0, $v0, 3
/* 9D9AE4 80242AC4 46001032 */  c.eq.s    $f2, $f0
/* 9D9AE8 80242AC8 3C01800B */  lui       $at, 0x800b
/* 9D9AEC 80242ACC 00220821 */  addu      $at, $at, $v0
/* 9D9AF0 80242AD0 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* 9D9AF4 80242AD4 45000005 */  bc1f      .L80242AEC
/* 9D9AF8 80242AD8 00000000 */   nop      
/* 9D9AFC 80242ADC 3C0142C8 */  lui       $at, 0x42c8
/* 9D9B00 80242AE0 44810000 */  mtc1      $at, $f0
/* 9D9B04 80242AE4 08090ABF */  j         .L80242AFC
/* 9D9B08 80242AE8 4600B581 */   sub.s    $f22, $f22, $f0
.L80242AEC:
/* 9D9B0C 80242AEC 3C0142C8 */  lui       $at, 0x42c8
/* 9D9B10 80242AF0 44810000 */  mtc1      $at, $f0
/* 9D9B14 80242AF4 00000000 */  nop       
/* 9D9B18 80242AF8 4600B580 */  add.s     $f22, $f22, $f0
.L80242AFC:
/* 9D9B1C 80242AFC 0C00A6C9 */  jal       clamp_angle
/* 9D9B20 80242B00 4600B306 */   mov.s    $f12, $f22
/* 9D9B24 80242B04 46000586 */  mov.s     $f22, $f0
/* 9D9B28 80242B08 3C014170 */  lui       $at, 0x4170
/* 9D9B2C 80242B0C 4481A000 */  mtc1      $at, $f20
/* 9D9B30 80242B10 0C00A8BB */  jal       sin_deg
/* 9D9B34 80242B14 4600B306 */   mov.s    $f12, $f22
/* 9D9B38 80242B18 46140002 */  mul.s     $f0, $f0, $f20
/* 9D9B3C 80242B1C 00000000 */  nop       
/* 9D9B40 80242B20 864200B0 */  lh        $v0, 0xb0($s2)
/* 9D9B44 80242B24 3C013F00 */  lui       $at, 0x3f00
/* 9D9B48 80242B28 44812000 */  mtc1      $at, $f4
/* 9D9B4C 80242B2C 44821000 */  mtc1      $v0, $f2
/* 9D9B50 80242B30 00000000 */  nop       
/* 9D9B54 80242B34 468010A0 */  cvt.s.w   $f2, $f2
/* 9D9B58 80242B38 46041082 */  mul.s     $f2, $f2, $f4
/* 9D9B5C 80242B3C 00000000 */  nop       
/* 9D9B60 80242B40 4600E700 */  add.s     $f28, $f28, $f0
/* 9D9B64 80242B44 4602D680 */  add.s     $f26, $f26, $f2
/* 9D9B68 80242B48 0C00A8D4 */  jal       cos_deg
/* 9D9B6C 80242B4C 4600B306 */   mov.s    $f12, $f22
/* 9D9B70 80242B50 46140002 */  mul.s     $f0, $f0, $f20
/* 9D9B74 80242B54 00000000 */  nop       
/* 9D9B78 80242B58 0220202D */  daddu     $a0, $s1, $zero
/* 9D9B7C 80242B5C 0260282D */  daddu     $a1, $s3, $zero
/* 9D9B80 80242B60 4600E18D */  trunc.w.s $f6, $f28
/* 9D9B84 80242B64 44063000 */  mfc1      $a2, $f6
/* 9D9B88 80242B68 0C0B2026 */  jal       set_variable
/* 9D9B8C 80242B6C 4600C601 */   sub.s    $f24, $f24, $f0
/* 9D9B90 80242B70 0220202D */  daddu     $a0, $s1, $zero
/* 9D9B94 80242B74 4600D18D */  trunc.w.s $f6, $f26
/* 9D9B98 80242B78 44063000 */  mfc1      $a2, $f6
/* 9D9B9C 80242B7C 0C0B2026 */  jal       set_variable
/* 9D9BA0 80242B80 0280282D */   daddu    $a1, $s4, $zero
/* 9D9BA4 80242B84 0220202D */  daddu     $a0, $s1, $zero
/* 9D9BA8 80242B88 4600C18D */  trunc.w.s $f6, $f24
/* 9D9BAC 80242B8C 44063000 */  mfc1      $a2, $f6
/* 9D9BB0 80242B90 0C0B2026 */  jal       set_variable
/* 9D9BB4 80242B94 0200282D */   daddu    $a1, $s0, $zero
/* 9D9BB8 80242B98 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9D9BBC 80242B9C 8FB40020 */  lw        $s4, 0x20($sp)
/* 9D9BC0 80242BA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9D9BC4 80242BA4 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D9BC8 80242BA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9BCC 80242BAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9BD0 80242BB0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 9D9BD4 80242BB4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 9D9BD8 80242BB8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 9D9BDC 80242BBC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 9D9BE0 80242BC0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 9D9BE4 80242BC4 24020002 */  addiu     $v0, $zero, 2
/* 9D9BE8 80242BC8 03E00008 */  jr        $ra
/* 9D9BEC 80242BCC 27BD0050 */   addiu    $sp, $sp, 0x50
