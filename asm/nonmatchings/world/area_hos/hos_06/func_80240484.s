.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240484
/* A39964 80240484 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A39968 80240488 AFB10014 */  sw        $s1, 0x14($sp)
/* A3996C 8024048C 0080882D */  daddu     $s1, $a0, $zero
/* A39970 80240490 AFBF0024 */  sw        $ra, 0x24($sp)
/* A39974 80240494 AFB40020 */  sw        $s4, 0x20($sp)
/* A39978 80240498 AFB3001C */  sw        $s3, 0x1c($sp)
/* A3997C 8024049C AFB20018 */  sw        $s2, 0x18($sp)
/* A39980 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* A39984 802404A4 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* A39988 802404A8 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* A3998C 802404AC F7B80038 */  sdc1      $f24, 0x38($sp)
/* A39990 802404B0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A39994 802404B4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A39998 802404B8 8E30000C */  lw        $s0, 0xc($s1)
/* A3999C 802404BC 8E130000 */  lw        $s3, ($s0)
/* A399A0 802404C0 26100004 */  addiu     $s0, $s0, 4
/* A399A4 802404C4 0C0B1EAF */  jal       get_variable
/* A399A8 802404C8 0260282D */   daddu    $a1, $s3, $zero
/* A399AC 802404CC 4482E000 */  mtc1      $v0, $f28
/* A399B0 802404D0 00000000 */  nop       
/* A399B4 802404D4 4680E720 */  cvt.s.w   $f28, $f28
/* A399B8 802404D8 8E140000 */  lw        $s4, ($s0)
/* A399BC 802404DC 26100004 */  addiu     $s0, $s0, 4
/* A399C0 802404E0 0220202D */  daddu     $a0, $s1, $zero
/* A399C4 802404E4 0C0B1EAF */  jal       get_variable
/* A399C8 802404E8 0280282D */   daddu    $a1, $s4, $zero
/* A399CC 802404EC 4482D000 */  mtc1      $v0, $f26
/* A399D0 802404F0 00000000 */  nop       
/* A399D4 802404F4 4680D6A0 */  cvt.s.w   $f26, $f26
/* A399D8 802404F8 8E100000 */  lw        $s0, ($s0)
/* A399DC 802404FC 0220202D */  daddu     $a0, $s1, $zero
/* A399E0 80240500 0C0B1EAF */  jal       get_variable
/* A399E4 80240504 0200282D */   daddu    $a1, $s0, $zero
/* A399E8 80240508 4482C000 */  mtc1      $v0, $f24
/* A399EC 8024050C 00000000 */  nop       
/* A399F0 80240510 4680C620 */  cvt.s.w   $f24, $f24
/* A399F4 80240514 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* A399F8 80240518 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* A399FC 8024051C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A39A00 80240520 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A39A04 80240524 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* A39A08 80240528 44800000 */  mtc1      $zero, $f0
/* A39A0C 8024052C 00031080 */  sll       $v0, $v1, 2
/* A39A10 80240530 00431021 */  addu      $v0, $v0, $v1
/* A39A14 80240534 00021080 */  sll       $v0, $v0, 2
/* A39A18 80240538 00431023 */  subu      $v0, $v0, $v1
/* A39A1C 8024053C 000218C0 */  sll       $v1, $v0, 3
/* A39A20 80240540 00431021 */  addu      $v0, $v0, $v1
/* A39A24 80240544 000210C0 */  sll       $v0, $v0, 3
/* A39A28 80240548 46001032 */  c.eq.s    $f2, $f0
/* A39A2C 8024054C 3C01800B */  lui       $at, 0x800b
/* A39A30 80240550 00220821 */  addu      $at, $at, $v0
/* A39A34 80240554 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* A39A38 80240558 45000005 */  bc1f      .L80240570
/* A39A3C 8024055C 00000000 */   nop      
/* A39A40 80240560 3C0142C8 */  lui       $at, 0x42c8
/* A39A44 80240564 44810000 */  mtc1      $at, $f0
/* A39A48 80240568 08090160 */  j         .L80240580
/* A39A4C 8024056C 4600B581 */   sub.s    $f22, $f22, $f0
.L80240570:
/* A39A50 80240570 3C0142C8 */  lui       $at, 0x42c8
/* A39A54 80240574 44810000 */  mtc1      $at, $f0
/* A39A58 80240578 00000000 */  nop       
/* A39A5C 8024057C 4600B580 */  add.s     $f22, $f22, $f0
.L80240580:
/* A39A60 80240580 0C00A6C9 */  jal       clamp_angle
/* A39A64 80240584 4600B306 */   mov.s    $f12, $f22
/* A39A68 80240588 46000586 */  mov.s     $f22, $f0
/* A39A6C 8024058C 3C014170 */  lui       $at, 0x4170
/* A39A70 80240590 4481A000 */  mtc1      $at, $f20
/* A39A74 80240594 0C00A8BB */  jal       sin_deg
/* A39A78 80240598 4600B306 */   mov.s    $f12, $f22
/* A39A7C 8024059C 46140002 */  mul.s     $f0, $f0, $f20
/* A39A80 802405A0 00000000 */  nop       
/* A39A84 802405A4 864200B0 */  lh        $v0, 0xb0($s2)
/* A39A88 802405A8 3C013F00 */  lui       $at, 0x3f00
/* A39A8C 802405AC 44812000 */  mtc1      $at, $f4
/* A39A90 802405B0 44821000 */  mtc1      $v0, $f2
/* A39A94 802405B4 00000000 */  nop       
/* A39A98 802405B8 468010A0 */  cvt.s.w   $f2, $f2
/* A39A9C 802405BC 46041082 */  mul.s     $f2, $f2, $f4
/* A39AA0 802405C0 00000000 */  nop       
/* A39AA4 802405C4 4600E700 */  add.s     $f28, $f28, $f0
/* A39AA8 802405C8 4602D680 */  add.s     $f26, $f26, $f2
/* A39AAC 802405CC 0C00A8D4 */  jal       cos_deg
/* A39AB0 802405D0 4600B306 */   mov.s    $f12, $f22
/* A39AB4 802405D4 46140002 */  mul.s     $f0, $f0, $f20
/* A39AB8 802405D8 00000000 */  nop       
/* A39ABC 802405DC 0220202D */  daddu     $a0, $s1, $zero
/* A39AC0 802405E0 0260282D */  daddu     $a1, $s3, $zero
/* A39AC4 802405E4 4600E18D */  trunc.w.s $f6, $f28
/* A39AC8 802405E8 44063000 */  mfc1      $a2, $f6
/* A39ACC 802405EC 0C0B2026 */  jal       set_variable
/* A39AD0 802405F0 4600C601 */   sub.s    $f24, $f24, $f0
/* A39AD4 802405F4 0220202D */  daddu     $a0, $s1, $zero
/* A39AD8 802405F8 4600D18D */  trunc.w.s $f6, $f26
/* A39ADC 802405FC 44063000 */  mfc1      $a2, $f6
/* A39AE0 80240600 0C0B2026 */  jal       set_variable
/* A39AE4 80240604 0280282D */   daddu    $a1, $s4, $zero
/* A39AE8 80240608 0220202D */  daddu     $a0, $s1, $zero
/* A39AEC 8024060C 4600C18D */  trunc.w.s $f6, $f24
/* A39AF0 80240610 44063000 */  mfc1      $a2, $f6
/* A39AF4 80240614 0C0B2026 */  jal       set_variable
/* A39AF8 80240618 0200282D */   daddu    $a1, $s0, $zero
/* A39AFC 8024061C 8FBF0024 */  lw        $ra, 0x24($sp)
/* A39B00 80240620 8FB40020 */  lw        $s4, 0x20($sp)
/* A39B04 80240624 8FB3001C */  lw        $s3, 0x1c($sp)
/* A39B08 80240628 8FB20018 */  lw        $s2, 0x18($sp)
/* A39B0C 8024062C 8FB10014 */  lw        $s1, 0x14($sp)
/* A39B10 80240630 8FB00010 */  lw        $s0, 0x10($sp)
/* A39B14 80240634 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* A39B18 80240638 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* A39B1C 8024063C D7B80038 */  ldc1      $f24, 0x38($sp)
/* A39B20 80240640 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A39B24 80240644 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A39B28 80240648 24020002 */  addiu     $v0, $zero, 2
/* A39B2C 8024064C 03E00008 */  jr        $ra
/* A39B30 80240650 27BD0050 */   addiu    $sp, $sp, 0x50
