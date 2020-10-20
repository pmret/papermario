.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024036C_D1393C
/* D1393C 8024036C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D13940 80240370 AFB10014 */  sw        $s1, 0x14($sp)
/* D13944 80240374 0080882D */  daddu     $s1, $a0, $zero
/* D13948 80240378 AFBF0024 */  sw        $ra, 0x24($sp)
/* D1394C 8024037C AFB40020 */  sw        $s4, 0x20($sp)
/* D13950 80240380 AFB3001C */  sw        $s3, 0x1c($sp)
/* D13954 80240384 AFB20018 */  sw        $s2, 0x18($sp)
/* D13958 80240388 AFB00010 */  sw        $s0, 0x10($sp)
/* D1395C 8024038C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D13960 80240390 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D13964 80240394 F7B80038 */  sdc1      $f24, 0x38($sp)
/* D13968 80240398 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D1396C 8024039C F7B40028 */  sdc1      $f20, 0x28($sp)
/* D13970 802403A0 8E30000C */  lw        $s0, 0xc($s1)
/* D13974 802403A4 8E130000 */  lw        $s3, ($s0)
/* D13978 802403A8 26100004 */  addiu     $s0, $s0, 4
/* D1397C 802403AC 0C0B1EAF */  jal       get_variable
/* D13980 802403B0 0260282D */   daddu    $a1, $s3, $zero
/* D13984 802403B4 4482E000 */  mtc1      $v0, $f28
/* D13988 802403B8 00000000 */  nop       
/* D1398C 802403BC 4680E720 */  cvt.s.w   $f28, $f28
/* D13990 802403C0 8E140000 */  lw        $s4, ($s0)
/* D13994 802403C4 26100004 */  addiu     $s0, $s0, 4
/* D13998 802403C8 0220202D */  daddu     $a0, $s1, $zero
/* D1399C 802403CC 0C0B1EAF */  jal       get_variable
/* D139A0 802403D0 0280282D */   daddu    $a1, $s4, $zero
/* D139A4 802403D4 4482D000 */  mtc1      $v0, $f26
/* D139A8 802403D8 00000000 */  nop       
/* D139AC 802403DC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D139B0 802403E0 8E100000 */  lw        $s0, ($s0)
/* D139B4 802403E4 0220202D */  daddu     $a0, $s1, $zero
/* D139B8 802403E8 0C0B1EAF */  jal       get_variable
/* D139BC 802403EC 0200282D */   daddu    $a1, $s0, $zero
/* D139C0 802403F0 4482C000 */  mtc1      $v0, $f24
/* D139C4 802403F4 00000000 */  nop       
/* D139C8 802403F8 4680C620 */  cvt.s.w   $f24, $f24
/* D139CC 802403FC 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D139D0 80240400 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D139D4 80240404 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D139D8 80240408 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D139DC 8024040C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* D139E0 80240410 44800000 */  mtc1      $zero, $f0
/* D139E4 80240414 00031080 */  sll       $v0, $v1, 2
/* D139E8 80240418 00431021 */  addu      $v0, $v0, $v1
/* D139EC 8024041C 00021080 */  sll       $v0, $v0, 2
/* D139F0 80240420 00431023 */  subu      $v0, $v0, $v1
/* D139F4 80240424 000218C0 */  sll       $v1, $v0, 3
/* D139F8 80240428 00431021 */  addu      $v0, $v0, $v1
/* D139FC 8024042C 000210C0 */  sll       $v0, $v0, 3
/* D13A00 80240430 46001032 */  c.eq.s    $f2, $f0
/* D13A04 80240434 3C01800B */  lui       $at, 0x800b
/* D13A08 80240438 00220821 */  addu      $at, $at, $v0
/* D13A0C 8024043C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D13A10 80240440 45000005 */  bc1f      .L80240458
/* D13A14 80240444 00000000 */   nop      
/* D13A18 80240448 3C0142C8 */  lui       $at, 0x42c8
/* D13A1C 8024044C 44810000 */  mtc1      $at, $f0
/* D13A20 80240450 0809011A */  j         .L80240468
/* D13A24 80240454 4600B581 */   sub.s    $f22, $f22, $f0
.L80240458:
/* D13A28 80240458 3C0142C8 */  lui       $at, 0x42c8
/* D13A2C 8024045C 44810000 */  mtc1      $at, $f0
/* D13A30 80240460 00000000 */  nop       
/* D13A34 80240464 4600B580 */  add.s     $f22, $f22, $f0
.L80240468:
/* D13A38 80240468 0C00A6C9 */  jal       clamp_angle
/* D13A3C 8024046C 4600B306 */   mov.s    $f12, $f22
/* D13A40 80240470 46000586 */  mov.s     $f22, $f0
/* D13A44 80240474 3C014170 */  lui       $at, 0x4170
/* D13A48 80240478 4481A000 */  mtc1      $at, $f20
/* D13A4C 8024047C 0C00A8BB */  jal       sin_deg
/* D13A50 80240480 4600B306 */   mov.s    $f12, $f22
/* D13A54 80240484 46140002 */  mul.s     $f0, $f0, $f20
/* D13A58 80240488 00000000 */  nop       
/* D13A5C 8024048C 864200B0 */  lh        $v0, 0xb0($s2)
/* D13A60 80240490 3C013F00 */  lui       $at, 0x3f00
/* D13A64 80240494 44812000 */  mtc1      $at, $f4
/* D13A68 80240498 44821000 */  mtc1      $v0, $f2
/* D13A6C 8024049C 00000000 */  nop       
/* D13A70 802404A0 468010A0 */  cvt.s.w   $f2, $f2
/* D13A74 802404A4 46041082 */  mul.s     $f2, $f2, $f4
/* D13A78 802404A8 00000000 */  nop       
/* D13A7C 802404AC 4600E700 */  add.s     $f28, $f28, $f0
/* D13A80 802404B0 4602D680 */  add.s     $f26, $f26, $f2
/* D13A84 802404B4 0C00A8D4 */  jal       cos_deg
/* D13A88 802404B8 4600B306 */   mov.s    $f12, $f22
/* D13A8C 802404BC 46140002 */  mul.s     $f0, $f0, $f20
/* D13A90 802404C0 00000000 */  nop       
/* D13A94 802404C4 0220202D */  daddu     $a0, $s1, $zero
/* D13A98 802404C8 0260282D */  daddu     $a1, $s3, $zero
/* D13A9C 802404CC 4600E18D */  trunc.w.s $f6, $f28
/* D13AA0 802404D0 44063000 */  mfc1      $a2, $f6
/* D13AA4 802404D4 0C0B2026 */  jal       set_variable
/* D13AA8 802404D8 4600C601 */   sub.s    $f24, $f24, $f0
/* D13AAC 802404DC 0220202D */  daddu     $a0, $s1, $zero
/* D13AB0 802404E0 4600D18D */  trunc.w.s $f6, $f26
/* D13AB4 802404E4 44063000 */  mfc1      $a2, $f6
/* D13AB8 802404E8 0C0B2026 */  jal       set_variable
/* D13ABC 802404EC 0280282D */   daddu    $a1, $s4, $zero
/* D13AC0 802404F0 0220202D */  daddu     $a0, $s1, $zero
/* D13AC4 802404F4 4600C18D */  trunc.w.s $f6, $f24
/* D13AC8 802404F8 44063000 */  mfc1      $a2, $f6
/* D13ACC 802404FC 0C0B2026 */  jal       set_variable
/* D13AD0 80240500 0200282D */   daddu    $a1, $s0, $zero
/* D13AD4 80240504 8FBF0024 */  lw        $ra, 0x24($sp)
/* D13AD8 80240508 8FB40020 */  lw        $s4, 0x20($sp)
/* D13ADC 8024050C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D13AE0 80240510 8FB20018 */  lw        $s2, 0x18($sp)
/* D13AE4 80240514 8FB10014 */  lw        $s1, 0x14($sp)
/* D13AE8 80240518 8FB00010 */  lw        $s0, 0x10($sp)
/* D13AEC 8024051C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D13AF0 80240520 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D13AF4 80240524 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D13AF8 80240528 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D13AFC 8024052C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D13B00 80240530 24020002 */  addiu     $v0, $zero, 2
/* D13B04 80240534 03E00008 */  jr        $ra
/* D13B08 80240538 27BD0050 */   addiu    $sp, $sp, 0x50
