.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B0FC_6A22FC
/* 6A22FC 8021B0FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6A2300 8021B100 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A2304 8021B104 0080902D */  daddu     $s2, $a0, $zero
/* 6A2308 8021B108 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A230C 8021B10C AFB10014 */  sw        $s1, 0x14($sp)
/* 6A2310 8021B110 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A2314 8021B114 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 6A2318 8021B118 10A00044 */  beqz      $a1, .L8021B22C
/* 6A231C 8021B11C 8E50000C */   lw       $s0, 0xc($s2)
/* 6A2320 8021B120 0C00AB39 */  jal       heap_malloc
/* 6A2324 8021B124 24040024 */   addiu    $a0, $zero, 0x24
/* 6A2328 8021B128 0040882D */  daddu     $s1, $v0, $zero
/* 6A232C 8021B12C AE510070 */  sw        $s1, 0x70($s2)
/* 6A2330 8021B130 8E050000 */  lw        $a1, ($s0)
/* 6A2334 8021B134 26100004 */  addiu     $s0, $s0, 4
/* 6A2338 8021B138 0C0B1EAF */  jal       get_variable
/* 6A233C 8021B13C 0240202D */   daddu    $a0, $s2, $zero
/* 6A2340 8021B140 AE220020 */  sw        $v0, 0x20($s1)
/* 6A2344 8021B144 8E050000 */  lw        $a1, ($s0)
/* 6A2348 8021B148 26100004 */  addiu     $s0, $s0, 4
/* 6A234C 8021B14C 0C0B210B */  jal       get_float_variable
/* 6A2350 8021B150 0240202D */   daddu    $a0, $s2, $zero
/* 6A2354 8021B154 E6200000 */  swc1      $f0, ($s1)
/* 6A2358 8021B158 8E050000 */  lw        $a1, ($s0)
/* 6A235C 8021B15C 26100004 */  addiu     $s0, $s0, 4
/* 6A2360 8021B160 0C0B210B */  jal       get_float_variable
/* 6A2364 8021B164 0240202D */   daddu    $a0, $s2, $zero
/* 6A2368 8021B168 E6200004 */  swc1      $f0, 4($s1)
/* 6A236C 8021B16C 8E050000 */  lw        $a1, ($s0)
/* 6A2370 8021B170 26100004 */  addiu     $s0, $s0, 4
/* 6A2374 8021B174 0C0B210B */  jal       get_float_variable
/* 6A2378 8021B178 0240202D */   daddu    $a0, $s2, $zero
/* 6A237C 8021B17C E6200008 */  swc1      $f0, 8($s1)
/* 6A2380 8021B180 8E050000 */  lw        $a1, ($s0)
/* 6A2384 8021B184 26100004 */  addiu     $s0, $s0, 4
/* 6A2388 8021B188 0C0B1EAF */  jal       get_variable
/* 6A238C 8021B18C 0240202D */   daddu    $a0, $s2, $zero
/* 6A2390 8021B190 AE22001C */  sw        $v0, 0x1c($s1)
/* 6A2394 8021B194 8E050000 */  lw        $a1, ($s0)
/* 6A2398 8021B198 0C0B210B */  jal       get_float_variable
/* 6A239C 8021B19C 0240202D */   daddu    $a0, $s2, $zero
/* 6A23A0 8021B1A0 8E240020 */  lw        $a0, 0x20($s1)
/* 6A23A4 8021B1A4 0C04C3D6 */  jal       get_item_entity
/* 6A23A8 8021B1A8 E6200010 */   swc1     $f0, 0x10($s1)
/* 6A23AC 8021B1AC 0040802D */  daddu     $s0, $v0, $zero
/* 6A23B0 8021B1B0 C60C0008 */  lwc1      $f12, 8($s0)
/* 6A23B4 8021B1B4 C60E0010 */  lwc1      $f14, 0x10($s0)
/* 6A23B8 8021B1B8 8E260000 */  lw        $a2, ($s1)
/* 6A23BC 8021B1BC 0C00A7B5 */  jal       dist2D
/* 6A23C0 8021B1C0 8E270008 */   lw       $a3, 8($s1)
/* 6A23C4 8021B1C4 C60C0008 */  lwc1      $f12, 8($s0)
/* 6A23C8 8021B1C8 C60E0010 */  lwc1      $f14, 0x10($s0)
/* 6A23CC 8021B1CC 8E260000 */  lw        $a2, ($s1)
/* 6A23D0 8021B1D0 8E270008 */  lw        $a3, 8($s1)
/* 6A23D4 8021B1D4 0C00A720 */  jal       atan2
/* 6A23D8 8021B1D8 46000506 */   mov.s    $f20, $f0
/* 6A23DC 8021B1DC C6240010 */  lwc1      $f4, 0x10($s1)
/* 6A23E0 8021B1E0 C626001C */  lwc1      $f6, 0x1c($s1)
/* 6A23E4 8021B1E4 468031A0 */  cvt.s.w   $f6, $f6
/* 6A23E8 8021B1E8 46062102 */  mul.s     $f4, $f4, $f6
/* 6A23EC 8021B1EC 00000000 */  nop
/* 6A23F0 8021B1F0 3C013F00 */  lui       $at, 0x3f00
/* 6A23F4 8021B1F4 44811000 */  mtc1      $at, $f2
/* 6A23F8 8021B1F8 00000000 */  nop
/* 6A23FC 8021B1FC 46022102 */  mul.s     $f4, $f4, $f2
/* 6A2400 8021B200 00000000 */  nop
/* 6A2404 8021B204 E620000C */  swc1      $f0, 0xc($s1)
/* 6A2408 8021B208 C6200004 */  lwc1      $f0, 4($s1)
/* 6A240C 8021B20C C602000C */  lwc1      $f2, 0xc($s0)
/* 6A2410 8021B210 46020001 */  sub.s     $f0, $f0, $f2
/* 6A2414 8021B214 46003086 */  mov.s     $f2, $f6
/* 6A2418 8021B218 46060003 */  div.s     $f0, $f0, $f6
/* 6A241C 8021B21C 46002100 */  add.s     $f4, $f4, $f0
/* 6A2420 8021B220 4602A503 */  div.s     $f20, $f20, $f2
/* 6A2424 8021B224 E6340014 */  swc1      $f20, 0x14($s1)
/* 6A2428 8021B228 E6240018 */  swc1      $f4, 0x18($s1)
.L8021B22C:
/* 6A242C 8021B22C 8E510070 */  lw        $s1, 0x70($s2)
/* 6A2430 8021B230 0C04C3D6 */  jal       get_item_entity
/* 6A2434 8021B234 8E240020 */   lw       $a0, 0x20($s1)
/* 6A2438 8021B238 0040802D */  daddu     $s0, $v0, $zero
/* 6A243C 8021B23C 16000005 */  bnez      $s0, .L8021B254
/* 6A2440 8021B240 00000000 */   nop
/* 6A2444 8021B244 0C00AB4B */  jal       heap_free
/* 6A2448 8021B248 8E440070 */   lw       $a0, 0x70($s2)
/* 6A244C 8021B24C 08086CBE */  j         .L8021B2F8
/* 6A2450 8021B250 24020002 */   addiu    $v0, $zero, 2
.L8021B254:
/* 6A2454 8021B254 C62C000C */  lwc1      $f12, 0xc($s1)
/* 6A2458 8021B258 0C00A8BB */  jal       sin_deg
/* 6A245C 8021B25C 00000000 */   nop
/* 6A2460 8021B260 C6220014 */  lwc1      $f2, 0x14($s1)
/* 6A2464 8021B264 46001082 */  mul.s     $f2, $f2, $f0
/* 6A2468 8021B268 00000000 */  nop
/* 6A246C 8021B26C C6000008 */  lwc1      $f0, 8($s0)
/* 6A2470 8021B270 46020000 */  add.s     $f0, $f0, $f2
/* 6A2474 8021B274 E6000008 */  swc1      $f0, 8($s0)
/* 6A2478 8021B278 0C00A8D4 */  jal       cos_deg
/* 6A247C 8021B27C C62C000C */   lwc1     $f12, 0xc($s1)
/* 6A2480 8021B280 C6220014 */  lwc1      $f2, 0x14($s1)
/* 6A2484 8021B284 46001082 */  mul.s     $f2, $f2, $f0
/* 6A2488 8021B288 00000000 */  nop
/* 6A248C 8021B28C C6000010 */  lwc1      $f0, 0x10($s0)
/* 6A2490 8021B290 46020001 */  sub.s     $f0, $f0, $f2
/* 6A2494 8021B294 E6000010 */  swc1      $f0, 0x10($s0)
/* 6A2498 8021B298 C600000C */  lwc1      $f0, 0xc($s0)
/* 6A249C 8021B29C C6220018 */  lwc1      $f2, 0x18($s1)
/* 6A24A0 8021B2A0 46020000 */  add.s     $f0, $f0, $f2
/* 6A24A4 8021B2A4 E600000C */  swc1      $f0, 0xc($s0)
/* 6A24A8 8021B2A8 C6200018 */  lwc1      $f0, 0x18($s1)
/* 6A24AC 8021B2AC C6220010 */  lwc1      $f2, 0x10($s1)
/* 6A24B0 8021B2B0 8E22001C */  lw        $v0, 0x1c($s1)
/* 6A24B4 8021B2B4 46020001 */  sub.s     $f0, $f0, $f2
/* 6A24B8 8021B2B8 2442FFFF */  addiu     $v0, $v0, -1
/* 6A24BC 8021B2BC AE22001C */  sw        $v0, 0x1c($s1)
/* 6A24C0 8021B2C0 04400003 */  bltz      $v0, .L8021B2D0
/* 6A24C4 8021B2C4 E6200018 */   swc1     $f0, 0x18($s1)
/* 6A24C8 8021B2C8 08086CBE */  j         .L8021B2F8
/* 6A24CC 8021B2CC 0000102D */   daddu    $v0, $zero, $zero
.L8021B2D0:
/* 6A24D0 8021B2D0 C6200000 */  lwc1      $f0, ($s1)
/* 6A24D4 8021B2D4 E6000008 */  swc1      $f0, 8($s0)
/* 6A24D8 8021B2D8 C6200004 */  lwc1      $f0, 4($s1)
/* 6A24DC 8021B2DC E600000C */  swc1      $f0, 0xc($s0)
/* 6A24E0 8021B2E0 C6200008 */  lwc1      $f0, 8($s1)
/* 6A24E4 8021B2E4 E6000010 */  swc1      $f0, 0x10($s0)
/* 6A24E8 8021B2E8 AE200018 */  sw        $zero, 0x18($s1)
/* 6A24EC 8021B2EC 0C00AB4B */  jal       heap_free
/* 6A24F0 8021B2F0 8E440070 */   lw       $a0, 0x70($s2)
/* 6A24F4 8021B2F4 24020001 */  addiu     $v0, $zero, 1
.L8021B2F8:
/* 6A24F8 8021B2F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A24FC 8021B2FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A2500 8021B300 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A2504 8021B304 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A2508 8021B308 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 6A250C 8021B30C 03E00008 */  jr        $ra
/* 6A2510 8021B310 27BD0028 */   addiu    $sp, $sp, 0x28
