.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B21E4
/* 3B4974 E00B21E4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3B4978 E00B21E8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 3B497C E00B21EC AFB50024 */  sw        $s5, 0x24($sp)
/* 3B4980 E00B21F0 AFB40020 */  sw        $s4, 0x20($sp)
/* 3B4984 E00B21F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3B4988 E00B21F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 3B498C E00B21FC AFB10014 */  sw        $s1, 0x14($sp)
/* 3B4990 E00B2200 AFB00010 */  sw        $s0, 0x10($sp)
/* 3B4994 E00B2204 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 3B4998 E00B2208 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 3B499C E00B220C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 3B49A0 E00B2210 8C830000 */  lw        $v1, ($a0)
/* 3B49A4 E00B2214 8C90000C */  lw        $s0, 0xc($a0)
/* 3B49A8 E00B2218 30620010 */  andi      $v0, $v1, 0x10
/* 3B49AC E00B221C 8E140000 */  lw        $s4, ($s0)
/* 3B49B0 E00B2220 10400005 */  beqz      $v0, .LE00B2238
/* 3B49B4 E00B2224 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B49B8 E00B2228 00621024 */  and       $v0, $v1, $v0
/* 3B49BC E00B222C AC820000 */  sw        $v0, ($a0)
/* 3B49C0 E00B2230 24020010 */  addiu     $v0, $zero, 0x10
/* 3B49C4 E00B2234 AE02002C */  sw        $v0, 0x2c($s0)
.LE00B2238:
/* 3B49C8 E00B2238 8E03002C */  lw        $v1, 0x2c($s0)
/* 3B49CC E00B223C 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3B49D0 E00B2240 10400002 */  beqz      $v0, .LE00B224C
/* 3B49D4 E00B2244 2462FFFF */   addiu    $v0, $v1, -1
/* 3B49D8 E00B2248 AE02002C */  sw        $v0, 0x2c($s0)
.LE00B224C:
/* 3B49DC E00B224C 8E020030 */  lw        $v0, 0x30($s0)
/* 3B49E0 E00B2250 8E03002C */  lw        $v1, 0x2c($s0)
/* 3B49E4 E00B2254 24420001 */  addiu     $v0, $v0, 1
/* 3B49E8 E00B2258 04610005 */  bgez      $v1, .LE00B2270
/* 3B49EC E00B225C AE020030 */   sw       $v0, 0x30($s0)
/* 3B49F0 E00B2260 0C080128 */  jal       shim_remove_effect
/* 3B49F4 E00B2264 00000000 */   nop
/* 3B49F8 E00B2268 0802C90C */  j         .LE00B2430
/* 3B49FC E00B226C 00000000 */   nop
.LE00B2270:
/* 3B4A00 E00B2270 8E020054 */  lw        $v0, 0x54($s0)
/* 3B4A04 E00B2274 8E130028 */  lw        $s3, 0x28($s0)
/* 3B4A08 E00B2278 24420001 */  addiu     $v0, $v0, 1
/* 3B4A0C E00B227C AE020054 */  sw        $v0, 0x54($s0)
/* 3B4A10 E00B2280 2842000D */  slti      $v0, $v0, 0xd
/* 3B4A14 E00B2284 14400003 */  bnez      $v0, .LE00B2294
/* 3B4A18 E00B2288 0000902D */   daddu    $s2, $zero, $zero
/* 3B4A1C E00B228C 2402000C */  addiu     $v0, $zero, 0xc
/* 3B4A20 E00B2290 AE020054 */  sw        $v0, 0x54($s0)
.LE00B2294:
/* 3B4A24 E00B2294 3C158000 */  lui       $s5, 0x8000
/* 3B4A28 E00B2298 0200882D */  daddu     $s1, $s0, $zero
/* 3B4A2C E00B229C 3C01437F */  lui       $at, 0x437f
/* 3B4A30 E00B22A0 4481C000 */  mtc1      $at, $f24
/* 3B4A34 E00B22A4 3C014F00 */  lui       $at, 0x4f00
/* 3B4A38 E00B22A8 4481B000 */  mtc1      $at, $f22
.LE00B22AC:
/* 3B4A3C E00B22AC 8E220178 */  lw        $v0, 0x178($s1)
/* 3B4A40 E00B22B0 10400003 */  beqz      $v0, .LE00B22C0
/* 3B4A44 E00B22B4 2442FFFF */   addiu    $v0, $v0, -1
/* 3B4A48 E00B22B8 14400059 */  bnez      $v0, .LE00B2420
/* 3B4A4C E00B22BC AE220178 */   sw       $v0, 0x178($s1)
.LE00B22C0:
/* 3B4A50 E00B22C0 8E2201A8 */  lw        $v0, 0x1a8($s1)
/* 3B4A54 E00B22C4 24420001 */  addiu     $v0, $v0, 1
/* 3B4A58 E00B22C8 0040182D */  daddu     $v1, $v0, $zero
/* 3B4A5C E00B22CC 0073102A */  slt       $v0, $v1, $s3
/* 3B4A60 E00B22D0 14400002 */  bnez      $v0, .LE00B22DC
/* 3B4A64 E00B22D4 AE2301A8 */   sw       $v1, 0x1a8($s1)
/* 3B4A68 E00B22D8 0260182D */  daddu     $v1, $s3, $zero
.LE00B22DC:
/* 3B4A6C E00B22DC 44831000 */  mtc1      $v1, $f2
/* 3B4A70 E00B22E0 00000000 */  nop
/* 3B4A74 E00B22E4 468010A0 */  cvt.s.w   $f2, $f2
/* 3B4A78 E00B22E8 44930000 */  mtc1      $s3, $f0
/* 3B4A7C E00B22EC 00000000 */  nop
/* 3B4A80 E00B22F0 46800020 */  cvt.s.w   $f0, $f0
/* 3B4A84 E00B22F4 16800017 */  bnez      $s4, .LE00B2354
/* 3B4A88 E00B22F8 46001503 */   div.s    $f20, $f2, $f0
/* 3B4A8C E00B22FC C600001C */  lwc1      $f0, 0x1c($s0)
/* 3B4A90 E00B2300 C6020010 */  lwc1      $f2, 0x10($s0)
/* 3B4A94 E00B2304 46020001 */  sub.s     $f0, $f0, $f2
/* 3B4A98 E00B2308 46140002 */  mul.s     $f0, $f0, $f20
/* 3B4A9C E00B230C 00000000 */  nop
/* 3B4AA0 E00B2310 46001080 */  add.s     $f2, $f2, $f0
/* 3B4AA4 E00B2314 E62200E8 */  swc1      $f2, 0xe8($s1)
/* 3B4AA8 E00B2318 C6000020 */  lwc1      $f0, 0x20($s0)
/* 3B4AAC E00B231C C6020014 */  lwc1      $f2, 0x14($s0)
/* 3B4AB0 E00B2320 46020001 */  sub.s     $f0, $f0, $f2
/* 3B4AB4 E00B2324 46140002 */  mul.s     $f0, $f0, $f20
/* 3B4AB8 E00B2328 00000000 */  nop
/* 3B4ABC E00B232C 46001080 */  add.s     $f2, $f2, $f0
/* 3B4AC0 E00B2330 E6220118 */  swc1      $f2, 0x118($s1)
/* 3B4AC4 E00B2334 C6000024 */  lwc1      $f0, 0x24($s0)
/* 3B4AC8 E00B2338 C6020018 */  lwc1      $f2, 0x18($s0)
/* 3B4ACC E00B233C 46020001 */  sub.s     $f0, $f0, $f2
/* 3B4AD0 E00B2340 46140002 */  mul.s     $f0, $f0, $f20
/* 3B4AD4 E00B2344 00000000 */  nop
/* 3B4AD8 E00B2348 46001080 */  add.s     $f2, $f2, $f0
/* 3B4ADC E00B234C 0802C908 */  j         .LE00B2420
/* 3B4AE0 E00B2350 E6220148 */   swc1     $f2, 0x148($s1)
.LE00B2354:
/* 3B4AE4 E00B2354 3C014334 */  lui       $at, 0x4334
/* 3B4AE8 E00B2358 44816000 */  mtc1      $at, $f12
/* 3B4AEC E00B235C 00000000 */  nop
/* 3B4AF0 E00B2360 460CA302 */  mul.s     $f12, $f20, $f12
/* 3B4AF4 E00B2364 00000000 */  nop
/* 3B4AF8 E00B2368 C600001C */  lwc1      $f0, 0x1c($s0)
/* 3B4AFC E00B236C C6020010 */  lwc1      $f2, 0x10($s0)
/* 3B4B00 E00B2370 46020001 */  sub.s     $f0, $f0, $f2
/* 3B4B04 E00B2374 46140002 */  mul.s     $f0, $f0, $f20
/* 3B4B08 E00B2378 00000000 */  nop
/* 3B4B0C E00B237C 46001080 */  add.s     $f2, $f2, $f0
/* 3B4B10 E00B2380 0C080140 */  jal       shim_sin_deg
/* 3B4B14 E00B2384 E62200E8 */   swc1     $f2, 0xe8($s1)
/* 3B4B18 E00B2388 3C0142F0 */  lui       $at, 0x42f0
/* 3B4B1C E00B238C 44811000 */  mtc1      $at, $f2
/* 3B4B20 E00B2390 00000000 */  nop
/* 3B4B24 E00B2394 46020002 */  mul.s     $f0, $f0, $f2
/* 3B4B28 E00B2398 00000000 */  nop
/* 3B4B2C E00B239C C6040020 */  lwc1      $f4, 0x20($s0)
/* 3B4B30 E00B23A0 C6060014 */  lwc1      $f6, 0x14($s0)
/* 3B4B34 E00B23A4 46062101 */  sub.s     $f4, $f4, $f6
/* 3B4B38 E00B23A8 46142102 */  mul.s     $f4, $f4, $f20
/* 3B4B3C E00B23AC 00000000 */  nop
/* 3B4B40 E00B23B0 46043180 */  add.s     $f6, $f6, $f4
/* 3B4B44 E00B23B4 46003180 */  add.s     $f6, $f6, $f0
/* 3B4B48 E00B23B8 4618A102 */  mul.s     $f4, $f20, $f24
/* 3B4B4C E00B23BC 00000000 */  nop
/* 3B4B50 E00B23C0 E6260118 */  swc1      $f6, 0x118($s1)
/* 3B4B54 E00B23C4 C6000024 */  lwc1      $f0, 0x24($s0)
/* 3B4B58 E00B23C8 C6020018 */  lwc1      $f2, 0x18($s0)
/* 3B4B5C E00B23CC 46020001 */  sub.s     $f0, $f0, $f2
/* 3B4B60 E00B23D0 46140002 */  mul.s     $f0, $f0, $f20
/* 3B4B64 E00B23D4 00000000 */  nop
/* 3B4B68 E00B23D8 46001080 */  add.s     $f2, $f2, $f0
/* 3B4B6C E00B23DC 02121021 */  addu      $v0, $s0, $s2
/* 3B4B70 E00B23E0 4604C001 */  sub.s     $f0, $f24, $f4
/* 3B4B74 E00B23E4 244201D8 */  addiu     $v0, $v0, 0x1d8
/* 3B4B78 E00B23E8 4600B03E */  c.le.s    $f22, $f0
/* 3B4B7C E00B23EC 00000000 */  nop
/* 3B4B80 E00B23F0 45010005 */  bc1t      .LE00B2408
/* 3B4B84 E00B23F4 E6220148 */   swc1     $f2, 0x148($s1)
/* 3B4B88 E00B23F8 4600020D */  trunc.w.s $f8, $f0
/* 3B4B8C E00B23FC 44034000 */  mfc1      $v1, $f8
/* 3B4B90 E00B2400 0802C908 */  j         .LE00B2420
/* 3B4B94 E00B2404 A0430000 */   sb       $v1, ($v0)
.LE00B2408:
/* 3B4B98 E00B2408 46160001 */  sub.s     $f0, $f0, $f22
/* 3B4B9C E00B240C 4600020D */  trunc.w.s $f8, $f0
/* 3B4BA0 E00B2410 44034000 */  mfc1      $v1, $f8
/* 3B4BA4 E00B2414 00000000 */  nop
/* 3B4BA8 E00B2418 00751825 */  or        $v1, $v1, $s5
/* 3B4BAC E00B241C A0430000 */  sb        $v1, ($v0)
.LE00B2420:
/* 3B4BB0 E00B2420 26520001 */  addiu     $s2, $s2, 1
/* 3B4BB4 E00B2424 2A42000C */  slti      $v0, $s2, 0xc
/* 3B4BB8 E00B2428 1440FFA0 */  bnez      $v0, .LE00B22AC
/* 3B4BBC E00B242C 26310004 */   addiu    $s1, $s1, 4
.LE00B2430:
/* 3B4BC0 E00B2430 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3B4BC4 E00B2434 8FB50024 */  lw        $s5, 0x24($sp)
/* 3B4BC8 E00B2438 8FB40020 */  lw        $s4, 0x20($sp)
/* 3B4BCC E00B243C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3B4BD0 E00B2440 8FB20018 */  lw        $s2, 0x18($sp)
/* 3B4BD4 E00B2444 8FB10014 */  lw        $s1, 0x14($sp)
/* 3B4BD8 E00B2448 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B4BDC E00B244C D7B80040 */  ldc1      $f24, 0x40($sp)
/* 3B4BE0 E00B2450 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 3B4BE4 E00B2454 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 3B4BE8 E00B2458 03E00008 */  jr        $ra
/* 3B4BEC E00B245C 27BD0048 */   addiu    $sp, $sp, 0x48
