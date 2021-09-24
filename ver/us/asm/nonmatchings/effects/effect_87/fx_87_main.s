.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_87_main
/* 3B2350 E00AE000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3B2354 E00AE004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3B2358 E00AE008 4485A000 */  mtc1      $a1, $f20
/* 3B235C E00AE00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3B2360 E00AE010 4486B000 */  mtc1      $a2, $f22
/* 3B2364 E00AE014 AFB30034 */  sw        $s3, 0x34($sp)
/* 3B2368 E00AE018 0080982D */  daddu     $s3, $a0, $zero
/* 3B236C E00AE01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3B2370 E00AE020 4487C000 */  mtc1      $a3, $f24
/* 3B2374 E00AE024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B2378 E00AE028 AFB20030 */  sw        $s2, 0x30($sp)
/* 3B237C E00AE02C 8FB2006C */  lw        $s2, 0x6c($sp)
/* 3B2380 E00AE030 3C02E00B */  lui       $v0, %hi(func_E00AE1AC)
/* 3B2384 E00AE034 2442E1AC */  addiu     $v0, $v0, %lo(func_E00AE1AC)
/* 3B2388 E00AE038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B238C E00AE03C 3C02E00B */  lui       $v0, %hi(func_E00AE1B4)
/* 3B2390 E00AE040 2442E1B4 */  addiu     $v0, $v0, %lo(func_E00AE1B4)
/* 3B2394 E00AE044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B2398 E00AE048 3C02E00B */  lui       $v0, %hi(func_E00AE4FC)
/* 3B239C E00AE04C 2442E4FC */  addiu     $v0, $v0, %lo(func_E00AE4FC)
/* 3B23A0 E00AE050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B23A4 E00AE054 24020057 */  addiu     $v0, $zero, 0x57
/* 3B23A8 E00AE058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3B23AC E00AE05C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B23B0 E00AE060 AFB00028 */  sw        $s0, 0x28($sp)
/* 3B23B4 E00AE064 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B23B8 E00AE068 AFA00024 */  sw        $zero, 0x24($sp)
/* 3B23BC E00AE06C 0C080124 */  jal       shim_create_effect_instance
/* 3B23C0 E00AE070 AFA20014 */   sw       $v0, 0x14($sp)
/* 3B23C4 E00AE074 240405D8 */  addiu     $a0, $zero, 0x5d8
/* 3B23C8 E00AE078 24110016 */  addiu     $s1, $zero, 0x16
/* 3B23CC E00AE07C 0040802D */  daddu     $s0, $v0, $zero
/* 3B23D0 E00AE080 0C08012C */  jal       shim_general_heap_malloc
/* 3B23D4 E00AE084 AE110008 */   sw       $s1, 8($s0)
/* 3B23D8 E00AE088 0040202D */  daddu     $a0, $v0, $zero
/* 3B23DC E00AE08C 14800003 */  bnez      $a0, .LE00AE09C
/* 3B23E0 E00AE090 AE04000C */   sw       $a0, 0xc($s0)
.LE00AE094:
/* 3B23E4 E00AE094 0802B825 */  j         .LE00AE094
/* 3B23E8 E00AE098 00000000 */   nop
.LE00AE09C:
/* 3B23EC E00AE09C AC930000 */  sw        $s3, ($a0)
/* 3B23F0 E00AE0A0 1E400004 */  bgtz      $s2, .LE00AE0B4
/* 3B23F4 E00AE0A4 AC800014 */   sw       $zero, 0x14($a0)
/* 3B23F8 E00AE0A8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3B23FC E00AE0AC 0802B82E */  j         .LE00AE0B8
/* 3B2400 E00AE0B0 AC820010 */   sw       $v0, 0x10($a0)
.LE00AE0B4:
/* 3B2404 E00AE0B4 AC920010 */  sw        $s2, 0x10($a0)
.LE00AE0B8:
/* 3B2408 E00AE0B8 240300FF */  addiu     $v1, $zero, 0xff
/* 3B240C E00AE0BC 240200E6 */  addiu     $v0, $zero, 0xe6
/* 3B2410 E00AE0C0 AC800024 */  sw        $zero, 0x24($a0)
/* 3B2414 E00AE0C4 E4940004 */  swc1      $f20, 4($a0)
/* 3B2418 E00AE0C8 E4960008 */  swc1      $f22, 8($a0)
/* 3B241C E00AE0CC E498000C */  swc1      $f24, 0xc($a0)
/* 3B2420 E00AE0D0 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3B2424 E00AE0D4 24060001 */  addiu     $a2, $zero, 1
/* 3B2428 E00AE0D8 AC82001C */  sw        $v0, 0x1c($a0)
/* 3B242C E00AE0DC 00D1102A */  slt       $v0, $a2, $s1
/* 3B2430 E00AE0E0 AC830018 */  sw        $v1, 0x18($a0)
/* 3B2434 E00AE0E4 AC800020 */  sw        $zero, 0x20($a0)
/* 3B2438 E00AE0E8 AC830028 */  sw        $v1, 0x28($a0)
/* 3B243C E00AE0EC AC83002C */  sw        $v1, 0x2c($a0)
/* 3B2440 E00AE0F0 AC830030 */  sw        $v1, 0x30($a0)
/* 3B2444 E00AE0F4 E4800038 */  swc1      $f0, 0x38($a0)
/* 3B2448 E00AE0F8 10400021 */  beqz      $v0, .LE00AE180
/* 3B244C E00AE0FC 24840044 */   addiu    $a0, $a0, 0x44
/* 3B2450 E00AE100 24080014 */  addiu     $t0, $zero, 0x14
/* 3B2454 E00AE104 2627FFFF */  addiu     $a3, $s1, -1
/* 3B2458 E00AE108 3C013F80 */  lui       $at, 0x3f80
/* 3B245C E00AE10C 44811000 */  mtc1      $at, $f2
/* 3B2460 E00AE110 24840040 */  addiu     $a0, $a0, 0x40
/* 3B2464 E00AE114 0000282D */  daddu     $a1, $zero, $zero
.LE00AE118:
/* 3B2468 E00AE118 14E00002 */  bnez      $a3, .LE00AE124
/* 3B246C E00AE11C 00A7001A */   div      $zero, $a1, $a3
/* 3B2470 E00AE120 0007000D */  break     7
.LE00AE124:
/* 3B2474 E00AE124 2401FFFF */   addiu    $at, $zero, -1
/* 3B2478 E00AE128 14E10004 */  bne       $a3, $at, .LE00AE13C
/* 3B247C E00AE12C 3C018000 */   lui      $at, 0x8000
/* 3B2480 E00AE130 14A10002 */  bne       $a1, $at, .LE00AE13C
/* 3B2484 E00AE134 00000000 */   nop
/* 3B2488 E00AE138 0006000D */  break     6
.LE00AE13C:
/* 3B248C E00AE13C 00001812 */   mflo     $v1
/* 3B2490 E00AE140 24A50168 */  addiu     $a1, $a1, 0x168
/* 3B2494 E00AE144 30C2000F */  andi      $v0, $a2, 0xf
/* 3B2498 E00AE148 24C60001 */  addiu     $a2, $a2, 1
/* 3B249C E00AE14C AC820000 */  sw        $v0, ($a0)
/* 3B24A0 E00AE150 00D1102A */  slt       $v0, $a2, $s1
/* 3B24A4 E00AE154 AC88FFD0 */  sw        $t0, -0x30($a0)
/* 3B24A8 E00AE158 AC80FFD4 */  sw        $zero, -0x2c($a0)
/* 3B24AC E00AE15C AC80FFC4 */  sw        $zero, -0x3c($a0)
/* 3B24B0 E00AE160 AC80FFC8 */  sw        $zero, -0x38($a0)
/* 3B24B4 E00AE164 E482FFF4 */  swc1      $f2, -0xc($a0)
/* 3B24B8 E00AE168 44830000 */  mtc1      $v1, $f0
/* 3B24BC E00AE16C 00000000 */  nop
/* 3B24C0 E00AE170 46800020 */  cvt.s.w   $f0, $f0
/* 3B24C4 E00AE174 E480FFFC */  swc1      $f0, -4($a0)
/* 3B24C8 E00AE178 1440FFE7 */  bnez      $v0, .LE00AE118
/* 3B24CC E00AE17C 24840044 */   addiu    $a0, $a0, 0x44
.LE00AE180:
/* 3B24D0 E00AE180 0200102D */  daddu     $v0, $s0, $zero
/* 3B24D4 E00AE184 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3B24D8 E00AE188 8FB30034 */  lw        $s3, 0x34($sp)
/* 3B24DC E00AE18C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B24E0 E00AE190 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B24E4 E00AE194 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B24E8 E00AE198 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3B24EC E00AE19C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3B24F0 E00AE1A0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3B24F4 E00AE1A4 03E00008 */  jr        $ra
/* 3B24F8 E00AE1A8 27BD0058 */   addiu    $sp, $sp, 0x58
