.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_45_main
/* 3602C0 E005A000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3602C4 E005A004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3602C8 E005A008 4485A000 */  mtc1      $a1, $f20
/* 3602CC E005A00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3602D0 E005A010 4486B000 */  mtc1      $a2, $f22
/* 3602D4 E005A014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3602D8 E005A018 4487C000 */  mtc1      $a3, $f24
/* 3602DC E005A01C AFB40038 */  sw        $s4, 0x38($sp)
/* 3602E0 E005A020 0080A02D */  daddu     $s4, $a0, $zero
/* 3602E4 E005A024 AFB30034 */  sw        $s3, 0x34($sp)
/* 3602E8 E005A028 8FB30070 */  lw        $s3, 0x70($sp)
/* 3602EC E005A02C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3602F0 E005A030 AFB20030 */  sw        $s2, 0x30($sp)
/* 3602F4 E005A034 8FB20074 */  lw        $s2, 0x74($sp)
/* 3602F8 E005A038 3C02E006 */  lui       $v0, %hi(func_E005A1F4)
/* 3602FC E005A03C 2442A1F4 */  addiu     $v0, $v0, %lo(func_E005A1F4)
/* 360300 E005A040 AFA20018 */  sw        $v0, 0x18($sp)
/* 360304 E005A044 3C02E006 */  lui       $v0, %hi(func_E005A1FC)
/* 360308 E005A048 2442A1FC */  addiu     $v0, $v0, %lo(func_E005A1FC)
/* 36030C E005A04C AFA2001C */  sw        $v0, 0x1c($sp)
/* 360310 E005A050 3C02E006 */  lui       $v0, %hi(func_E005A3B0)
/* 360314 E005A054 2442A3B0 */  addiu     $v0, $v0, %lo(func_E005A3B0)
/* 360318 E005A058 AFA20020 */  sw        $v0, 0x20($sp)
/* 36031C E005A05C 2402002D */  addiu     $v0, $zero, 0x2d
/* 360320 E005A060 AFBF003C */  sw        $ra, 0x3c($sp)
/* 360324 E005A064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 360328 E005A068 AFB00028 */  sw        $s0, 0x28($sp)
/* 36032C E005A06C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 360330 E005A070 AFA00010 */  sw        $zero, 0x10($sp)
/* 360334 E005A074 AFA00024 */  sw        $zero, 0x24($sp)
/* 360338 E005A078 AFA20014 */  sw        $v0, 0x14($sp)
/* 36033C E005A07C 0C080124 */  jal       shim_create_effect_instance
/* 360340 E005A080 26730001 */   addiu    $s3, $s3, 1
/* 360344 E005A084 00132040 */  sll       $a0, $s3, 1
/* 360348 E005A088 00932021 */  addu      $a0, $a0, $s3
/* 36034C E005A08C 00042080 */  sll       $a0, $a0, 2
/* 360350 E005A090 00932021 */  addu      $a0, $a0, $s3
/* 360354 E005A094 00042080 */  sll       $a0, $a0, 2
/* 360358 E005A098 0040802D */  daddu     $s0, $v0, $zero
/* 36035C E005A09C 0C08012C */  jal       shim_general_heap_malloc
/* 360360 E005A0A0 AE130008 */   sw       $s3, 8($s0)
/* 360364 E005A0A4 0040882D */  daddu     $s1, $v0, $zero
/* 360368 E005A0A8 16200003 */  bnez      $s1, .LE005A0B8
/* 36036C E005A0AC AE11000C */   sw       $s1, 0xc($s0)
.LE005A0B0:
/* 360370 E005A0B0 0801682C */  j         .LE005A0B0
/* 360374 E005A0B4 00000000 */   nop
.LE005A0B8:
/* 360378 E005A0B8 0220202D */  daddu     $a0, $s1, $zero
/* 36037C E005A0BC 00132840 */  sll       $a1, $s3, 1
/* 360380 E005A0C0 00B32821 */  addu      $a1, $a1, $s3
/* 360384 E005A0C4 00052880 */  sll       $a1, $a1, 2
/* 360388 E005A0C8 00B32821 */  addu      $a1, $a1, $s3
/* 36038C E005A0CC 0C080130 */  jal       shim_mem_clear
/* 360390 E005A0D0 00052880 */   sll      $a1, $a1, 2
/* 360394 E005A0D4 AE320024 */  sw        $s2, 0x24($s1)
/* 360398 E005A0D8 AE200028 */  sw        $zero, 0x28($s1)
/* 36039C E005A0DC AE32002C */  sw        $s2, 0x2c($s1)
/* 3603A0 E005A0E0 A6340000 */  sh        $s4, ($s1)
/* 3603A4 E005A0E4 E6340004 */  swc1      $f20, 4($s1)
/* 3603A8 E005A0E8 E6360008 */  swc1      $f22, 8($s1)
/* 3603AC E005A0EC E638000C */  swc1      $f24, 0xc($s1)
/* 3603B0 E005A0F0 24120001 */  addiu     $s2, $zero, 1
/* 3603B4 E005A0F4 0253102A */  slt       $v0, $s2, $s3
/* 3603B8 E005A0F8 10400032 */  beqz      $v0, .LE005A1C4
/* 3603BC E005A0FC 26310034 */   addiu    $s1, $s1, 0x34
/* 3603C0 E005A100 2674FFFF */  addiu     $s4, $s3, -1
/* 3603C4 E005A104 26300030 */  addiu     $s0, $s1, 0x30
/* 3603C8 E005A108 0000882D */  daddu     $s1, $zero, $zero
/* 3603CC E005A10C 3C014020 */  lui       $at, 0x4020
/* 3603D0 E005A110 4481B800 */  mtc1      $at, $f23
/* 3603D4 E005A114 4480B000 */  mtc1      $zero, $f22
/* 3603D8 E005A118 3C0141A0 */  lui       $at, 0x41a0
/* 3603DC E005A11C 4481D000 */  mtc1      $at, $f26
/* 3603E0 E005A120 3C013F80 */  lui       $at, 0x3f80
/* 3603E4 E005A124 4481C000 */  mtc1      $at, $f24
.LE005A128:
/* 3603E8 E005A128 16800002 */  bnez      $s4, .LE005A134
/* 3603EC E005A12C 0234001A */   div      $zero, $s1, $s4
/* 3603F0 E005A130 0007000D */  break     7
.LE005A134:
/* 3603F4 E005A134 2401FFFF */   addiu    $at, $zero, -1
/* 3603F8 E005A138 16810004 */  bne       $s4, $at, .LE005A14C
/* 3603FC E005A13C 3C018000 */   lui      $at, 0x8000
/* 360400 E005A140 16210002 */  bne       $s1, $at, .LE005A14C
/* 360404 E005A144 00000000 */   nop
/* 360408 E005A148 0006000D */  break     6
.LE005A14C:
/* 36040C E005A14C 00001812 */   mflo     $v1
/* 360410 E005A150 AE00FFD4 */  sw        $zero, -0x2c($s0)
/* 360414 E005A154 AE00FFD8 */  sw        $zero, -0x28($s0)
/* 360418 E005A158 AE00FFDC */  sw        $zero, -0x24($s0)
/* 36041C E005A15C 4483A000 */  mtc1      $v1, $f20
/* 360420 E005A160 00000000 */  nop
/* 360424 E005A164 4680A520 */  cvt.s.w   $f20, $f20
/* 360428 E005A168 0C080140 */  jal       shim_sin_deg
/* 36042C E005A16C 4600A306 */   mov.s    $f12, $f20
/* 360430 E005A170 46000021 */  cvt.d.s   $f0, $f0
/* 360434 E005A174 46360002 */  mul.d     $f0, $f0, $f22
/* 360438 E005A178 00000000 */  nop
/* 36043C E005A17C 4600A306 */  mov.s     $f12, $f20
/* 360440 E005A180 46200020 */  cvt.s.d   $f0, $f0
/* 360444 E005A184 0C080144 */  jal       shim_cos_deg
/* 360448 E005A188 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 36044C E005A18C 46000021 */  cvt.d.s   $f0, $f0
/* 360450 E005A190 46360002 */  mul.d     $f0, $f0, $f22
/* 360454 E005A194 00000000 */  nop
/* 360458 E005A198 26310168 */  addiu     $s1, $s1, 0x168
/* 36045C E005A19C 26520001 */  addiu     $s2, $s2, 1
/* 360460 E005A1A0 0253102A */  slt       $v0, $s2, $s3
/* 360464 E005A1A4 AE00FFE8 */  sw        $zero, -0x18($s0)
/* 360468 E005A1A8 AE00FFEC */  sw        $zero, -0x14($s0)
/* 36046C E005A1AC E61AFFF0 */  swc1      $f26, -0x10($s0)
/* 360470 E005A1B0 E6180000 */  swc1      $f24, ($s0)
/* 360474 E005A1B4 46200020 */  cvt.s.d   $f0, $f0
/* 360478 E005A1B8 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 36047C E005A1BC 1440FFDA */  bnez      $v0, .LE005A128
/* 360480 E005A1C0 26100034 */   addiu    $s0, $s0, 0x34
.LE005A1C4:
/* 360484 E005A1C4 8FBF003C */  lw        $ra, 0x3c($sp)
/* 360488 E005A1C8 8FB40038 */  lw        $s4, 0x38($sp)
/* 36048C E005A1CC 8FB30034 */  lw        $s3, 0x34($sp)
/* 360490 E005A1D0 8FB20030 */  lw        $s2, 0x30($sp)
/* 360494 E005A1D4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 360498 E005A1D8 8FB00028 */  lw        $s0, 0x28($sp)
/* 36049C E005A1DC D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 3604A0 E005A1E0 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3604A4 E005A1E4 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3604A8 E005A1E8 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3604AC E005A1EC 03E00008 */  jr        $ra
/* 3604B0 E005A1F0 27BD0060 */   addiu    $sp, $sp, 0x60
