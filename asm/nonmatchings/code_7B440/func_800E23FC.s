.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E23FC
/* 7B8AC 800E23FC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7B8B0 800E2400 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7B8B4 800E2404 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7B8B8 800E2408 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 7B8BC 800E240C 4480D000 */  mtc1      $zero, $f26
/* 7B8C0 800E2410 AFB00010 */  sw        $s0, 0x10($sp)
/* 7B8C4 800E2414 0080802D */  daddu     $s0, $a0, $zero
/* 7B8C8 800E2418 AFB10014 */  sw        $s1, 0x14($sp)
/* 7B8CC 800E241C 00A0882D */  daddu     $s1, $a1, $zero
/* 7B8D0 800E2420 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7B8D4 800E2424 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 7B8D8 800E2428 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 7B8DC 800E242C F7B60028 */  sdc1      $f22, 0x28($sp)
/* 7B8E0 800E2430 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 7B8E4 800E2434 80620040 */  lb        $v0, 0x40($v1)
/* 7B8E8 800E2438 4600D306 */  mov.s     $f12, $f26
/* 7B8EC 800E243C 4482E000 */  mtc1      $v0, $f28
/* 7B8F0 800E2440 00000000 */  nop
/* 7B8F4 800E2444 4680E720 */  cvt.s.w   $f28, $f28
/* 7B8F8 800E2448 80620044 */  lb        $v0, 0x44($v1)
/* 7B8FC 800E244C 4406E000 */  mfc1      $a2, $f28
/* 7B900 800E2450 00021023 */  negu      $v0, $v0
/* 7B904 800E2454 4482C000 */  mtc1      $v0, $f24
/* 7B908 800E2458 00000000 */  nop
/* 7B90C 800E245C 4680C620 */  cvt.s.w   $f24, $f24
/* 7B910 800E2460 4407C000 */  mfc1      $a3, $f24
/* 7B914 800E2464 0C00A7B5 */  jal       dist2D
/* 7B918 800E2468 4600D386 */   mov.s    $f14, $f26
/* 7B91C 800E246C 3C01428C */  lui       $at, 0x428c
/* 7B920 800E2470 4481B000 */  mtc1      $at, $f22
/* 7B924 800E2474 46000506 */  mov.s     $f20, $f0
/* 7B928 800E2478 4614B03E */  c.le.s    $f22, $f20
/* 7B92C 800E247C 00000000 */  nop
/* 7B930 800E2480 45030001 */  bc1tl     .L800E2488
/* 7B934 800E2484 4600B506 */   mov.s    $f20, $f22
.L800E2488:
/* 7B938 800E2488 4600D306 */  mov.s     $f12, $f26
/* 7B93C 800E248C 4406E000 */  mfc1      $a2, $f28
/* 7B940 800E2490 4407C000 */  mfc1      $a3, $f24
/* 7B944 800E2494 0C00A720 */  jal       atan2
/* 7B948 800E2498 4600D386 */   mov.s    $f14, $f26
/* 7B94C 800E249C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 7B950 800E24A0 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* 7B954 800E24A4 0C00A6C9 */  jal       clamp_angle
/* 7B958 800E24A8 460C0300 */   add.s    $f12, $f0, $f12
/* 7B95C 800E24AC 461AA032 */  c.eq.s    $f20, $f26
/* 7B960 800E24B0 00000000 */  nop
/* 7B964 800E24B4 45020005 */  bc1fl     .L800E24CC
/* 7B968 800E24B8 E6000000 */   swc1     $f0, ($s0)
/* 7B96C 800E24BC 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7B970 800E24C0 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7B974 800E24C4 C4400080 */  lwc1      $f0, 0x80($v0)
/* 7B978 800E24C8 E6000000 */  swc1      $f0, ($s0)
.L800E24CC:
/* 7B97C 800E24CC E6340000 */  swc1      $f20, ($s1)
/* 7B980 800E24D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7B984 800E24D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 7B988 800E24D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7B98C 800E24DC D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 7B990 800E24E0 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 7B994 800E24E4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 7B998 800E24E8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 7B99C 800E24EC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 7B9A0 800E24F0 03E00008 */  jr        $ra
/* 7B9A4 800E24F4 27BD0048 */   addiu    $sp, $sp, 0x48
