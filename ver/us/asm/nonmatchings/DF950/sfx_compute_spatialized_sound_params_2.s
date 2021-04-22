.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80151250
.double 5550.0

glabel D_80151258
.double 127.0

glabel D_80151260
.double 3.6

glabel D_80151268
.double 127.0

.section .text

glabel sfx_compute_spatialized_sound_params_2
/* DF950 80149250 44860000 */  mtc1      $a2, $f0
/* DF954 80149254 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* DF958 80149258 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* DF95C 8014925C 44056000 */  mfc1      $a1, $f12
/* DF960 80149260 44067000 */  mfc1      $a2, $f14
/* DF964 80149264 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DF968 80149268 AFB20038 */  sw        $s2, 0x38($sp)
/* DF96C 8014926C 8FB20078 */  lw        $s2, 0x78($sp)
/* DF970 80149270 AFB10034 */  sw        $s1, 0x34($sp)
/* DF974 80149274 00E0882D */  daddu     $s1, $a3, $zero
/* DF978 80149278 AFB00030 */  sw        $s0, 0x30($sp)
/* DF97C 8014927C 8FB0007C */  lw        $s0, 0x7c($sp)
/* DF980 80149280 27A20020 */  addiu     $v0, $sp, 0x20
/* DF984 80149284 AFA20010 */  sw        $v0, 0x10($sp)
/* DF988 80149288 27A20024 */  addiu     $v0, $sp, 0x24
/* DF98C 8014928C AFA20014 */  sw        $v0, 0x14($sp)
/* DF990 80149290 44070000 */  mfc1      $a3, $f0
/* DF994 80149294 27A20028 */  addiu     $v0, $sp, 0x28
/* DF998 80149298 AFBF003C */  sw        $ra, 0x3c($sp)
/* DF99C 8014929C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* DF9A0 801492A0 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* DF9A4 801492A4 F7B80050 */  sdc1      $f24, 0x50($sp)
/* DF9A8 801492A8 F7B60048 */  sdc1      $f22, 0x48($sp)
/* DF9AC 801492AC F7B40040 */  sdc1      $f20, 0x40($sp)
/* DF9B0 801492B0 0C00B94E */  jal       get_screen_coords
/* DF9B4 801492B4 AFA20018 */   sw       $v0, 0x18($sp)
/* DF9B8 801492B8 8FA40020 */  lw        $a0, 0x20($sp)
/* DF9BC 801492BC 24821388 */  addiu     $v0, $a0, 0x1388
/* DF9C0 801492C0 2C422711 */  sltiu     $v0, $v0, 0x2711
/* DF9C4 801492C4 10400020 */  beqz      $v0, .L80149348
/* DF9C8 801492C8 2402FFFF */   addiu    $v0, $zero, -1
/* DF9CC 801492CC 8FA30024 */  lw        $v1, 0x24($sp)
/* DF9D0 801492D0 28621389 */  slti      $v0, $v1, 0x1389
/* DF9D4 801492D4 1040001B */  beqz      $v0, .L80149344
/* DF9D8 801492D8 2862EC78 */   slti     $v0, $v1, -0x1388
/* DF9DC 801492DC 1440001A */  bnez      $v0, .L80149348
/* DF9E0 801492E0 2402FFFF */   addiu    $v0, $zero, -1
/* DF9E4 801492E4 3C020002 */  lui       $v0, 2
/* DF9E8 801492E8 02021024 */  and       $v0, $s0, $v0
/* DF9EC 801492EC 10400008 */  beqz      $v0, .L80149310
/* DF9F0 801492F0 2482001E */   addiu    $v0, $a0, 0x1e
/* DF9F4 801492F4 2C42017D */  sltiu     $v0, $v0, 0x17d
/* DF9F8 801492F8 10400012 */  beqz      $v0, .L80149344
/* DF9FC 801492FC 2862FFE2 */   slti     $v0, $v1, -0x1e
/* DFA00 80149300 14400011 */  bnez      $v0, .L80149348
/* DFA04 80149304 2402FFFF */   addiu    $v0, $zero, -1
/* DFA08 80149308 080524CF */  j         .L8014933C
/* DFA0C 8014930C 2862010F */   slti     $v0, $v1, 0x10f
.L80149310:
/* DFA10 80149310 3C020004 */  lui       $v0, 4
/* DFA14 80149314 02021024 */  and       $v0, $s0, $v0
/* DFA18 80149318 10400003 */  beqz      $v0, .L80149328
/* DFA1C 8014931C 2482001E */   addiu    $v0, $a0, 0x1e
/* DFA20 80149320 080524CF */  j         .L8014933C
/* DFA24 80149324 2C42017D */   sltiu    $v0, $v0, 0x17d
.L80149328:
/* DFA28 80149328 3C020008 */  lui       $v0, 8
/* DFA2C 8014932C 02021024 */  and       $v0, $s0, $v0
/* DFA30 80149330 10400008 */  beqz      $v0, .L80149354
/* DFA34 80149334 2462001E */   addiu    $v0, $v1, 0x1e
/* DFA38 80149338 2C42012D */  sltiu     $v0, $v0, 0x12d
.L8014933C:
/* DFA3C 8014933C 14400006 */  bnez      $v0, .L80149358
/* DFA40 80149340 240300A0 */   addiu    $v1, $zero, 0xa0
.L80149344:
/* DFA44 80149344 2402FFFF */  addiu     $v0, $zero, -1
.L80149348:
/* DFA48 80149348 A6220000 */  sh        $v0, ($s1)
/* DFA4C 8014934C 08052575 */  j         .L801495D4
/* DFA50 80149350 A6400000 */   sh       $zero, ($s2)
.L80149354:
/* DFA54 80149354 240300A0 */  addiu     $v1, $zero, 0xa0
.L80149358:
/* DFA58 80149358 8FA20020 */  lw        $v0, 0x20($sp)
/* DFA5C 8014935C 4480C000 */  mtc1      $zero, $f24
/* DFA60 80149360 4480C800 */  mtc1      $zero, $f25
/* DFA64 80149364 00621823 */  subu      $v1, $v1, $v0
/* DFA68 80149368 04620001 */  bltzl     $v1, .L80149370
/* DFA6C 8014936C 00031823 */   negu     $v1, $v1
.L80149370:
/* DFA70 80149370 2463FF6F */  addiu     $v1, $v1, -0x91
/* DFA74 80149374 44831000 */  mtc1      $v1, $f2
/* DFA78 80149378 00000000 */  nop
/* DFA7C 8014937C 468010A0 */  cvt.s.w   $f2, $f2
/* DFA80 80149380 46001021 */  cvt.d.s   $f0, $f2
/* DFA84 80149384 4638003C */  c.lt.d    $f0, $f24
/* DFA88 80149388 00000000 */  nop
/* DFA8C 8014938C 45000003 */  bc1f      .L8014939C
/* DFA90 80149390 0000202D */   daddu    $a0, $zero, $zero
/* DFA94 80149394 44801000 */  mtc1      $zero, $f2
/* DFA98 80149398 00000000 */  nop
.L8014939C:
/* DFA9C 8014939C 4600120D */  trunc.w.s $f8, $f2
/* DFAA0 801493A0 44074000 */  mfc1      $a3, $f8
/* DFAA4 801493A4 3C013F80 */  lui       $at, 0x3f80
/* DFAA8 801493A8 4481E000 */  mtc1      $at, $f28
/* DFAAC 801493AC 4480B000 */  mtc1      $zero, $f22
/* DFAB0 801493B0 4405E000 */  mfc1      $a1, $f28
/* DFAB4 801493B4 4406B000 */  mfc1      $a2, $f22
/* DFAB8 801493B8 240200C8 */  addiu     $v0, $zero, 0xc8
/* DFABC 801493BC 0C00A8ED */  jal       update_lerp
/* DFAC0 801493C0 AFA20010 */   sw       $v0, 0x10($sp)
/* DFAC4 801493C4 46000686 */  mov.s     $f26, $f0
/* DFAC8 801493C8 4600D021 */  cvt.d.s   $f0, $f26
/* DFACC 801493CC 4638003C */  c.lt.d    $f0, $f24
/* DFAD0 801493D0 00000000 */  nop
/* DFAD4 801493D4 45030001 */  bc1tl     .L801493DC
/* DFAD8 801493D8 4600B686 */   mov.s    $f26, $f22
.L801493DC:
/* DFADC 801493DC 8FA20024 */  lw        $v0, 0x24($sp)
/* DFAE0 801493E0 24030078 */  addiu     $v1, $zero, 0x78
/* DFAE4 801493E4 00621823 */  subu      $v1, $v1, $v0
/* DFAE8 801493E8 04620001 */  bltzl     $v1, .L801493F0
/* DFAEC 801493EC 00031823 */   negu     $v1, $v1
.L801493F0:
/* DFAF0 801493F0 2463FF97 */  addiu     $v1, $v1, -0x69
/* DFAF4 801493F4 44831000 */  mtc1      $v1, $f2
/* DFAF8 801493F8 00000000 */  nop
/* DFAFC 801493FC 468010A0 */  cvt.s.w   $f2, $f2
/* DFB00 80149400 46001021 */  cvt.d.s   $f0, $f2
/* DFB04 80149404 4638003C */  c.lt.d    $f0, $f24
/* DFB08 80149408 00000000 */  nop
/* DFB0C 8014940C 45030001 */  bc1tl     .L80149414
/* DFB10 80149410 4600B086 */   mov.s    $f2, $f22
.L80149414:
/* DFB14 80149414 0000202D */  daddu     $a0, $zero, $zero
/* DFB18 80149418 4600120D */  trunc.w.s $f8, $f2
/* DFB1C 8014941C 44074000 */  mfc1      $a3, $f8
/* DFB20 80149420 4405E000 */  mfc1      $a1, $f28
/* DFB24 80149424 4406B000 */  mfc1      $a2, $f22
/* DFB28 80149428 24020082 */  addiu     $v0, $zero, 0x82
/* DFB2C 8014942C 0C00A8ED */  jal       update_lerp
/* DFB30 80149430 AFA20010 */   sw       $v0, 0x10($sp)
/* DFB34 80149434 46000506 */  mov.s     $f20, $f0
/* DFB38 80149438 4600A021 */  cvt.d.s   $f0, $f20
/* DFB3C 8014943C 4638003C */  c.lt.d    $f0, $f24
/* DFB40 80149440 00000000 */  nop
/* DFB44 80149444 45030001 */  bc1tl     .L8014944C
/* DFB48 80149448 4600B506 */   mov.s    $f20, $f22
.L8014944C:
/* DFB4C 8014944C 3C018015 */  lui       $at, %hi(D_80151250)
/* DFB50 80149450 D4201250 */  ldc1      $f0, %lo(D_80151250)($at)
/* DFB54 80149454 C7A20028 */  lwc1      $f2, 0x28($sp)
/* DFB58 80149458 468010A1 */  cvt.d.w   $f2, $f2
/* DFB5C 8014945C 46201081 */  sub.d     $f2, $f2, $f0
/* DFB60 80149460 462010A0 */  cvt.s.d   $f2, $f2
/* DFB64 80149464 46001021 */  cvt.d.s   $f0, $f2
/* DFB68 80149468 4638003C */  c.lt.d    $f0, $f24
/* DFB6C 8014946C 00000000 */  nop
/* DFB70 80149470 45030001 */  bc1tl     .L80149478
/* DFB74 80149474 4600B086 */   mov.s    $f2, $f22
.L80149478:
/* DFB78 80149478 0000202D */  daddu     $a0, $zero, $zero
/* DFB7C 8014947C 4600120D */  trunc.w.s $f8, $f2
/* DFB80 80149480 44074000 */  mfc1      $a3, $f8
/* DFB84 80149484 4405E000 */  mfc1      $a1, $f28
/* DFB88 80149488 4406B000 */  mfc1      $a2, $f22
/* DFB8C 8014948C 240200FA */  addiu     $v0, $zero, 0xfa
/* DFB90 80149490 0C00A8ED */  jal       update_lerp
/* DFB94 80149494 AFA20010 */   sw       $v0, 0x10($sp)
/* DFB98 80149498 46000086 */  mov.s     $f2, $f0
/* DFB9C 8014949C 46001021 */  cvt.d.s   $f0, $f2
/* DFBA0 801494A0 4638003C */  c.lt.d    $f0, $f24
/* DFBA4 801494A4 00000000 */  nop
/* DFBA8 801494A8 45030001 */  bc1tl     .L801494B0
/* DFBAC 801494AC 4600B086 */   mov.s    $f2, $f22
.L801494B0:
/* DFBB0 801494B0 4614D002 */  mul.s     $f0, $f26, $f20
/* DFBB4 801494B4 00000000 */  nop
/* DFBB8 801494B8 46020002 */  mul.s     $f0, $f0, $f2
/* DFBBC 801494BC 00000000 */  nop
/* DFBC0 801494C0 3C018015 */  lui       $at, %hi(D_80151258)
/* DFBC4 801494C4 D4261258 */  ldc1      $f6, %lo(D_80151258)($at)
/* DFBC8 801494C8 46000021 */  cvt.d.s   $f0, $f0
/* DFBCC 801494CC 46260002 */  mul.d     $f0, $f0, $f6
/* DFBD0 801494D0 00000000 */  nop
/* DFBD4 801494D4 46200120 */  cvt.s.d   $f4, $f0
/* DFBD8 801494D8 3C01402E */  lui       $at, 0x402e
/* DFBDC 801494DC 44810800 */  mtc1      $at, $f1
/* DFBE0 801494E0 44800000 */  mtc1      $zero, $f0
/* DFBE4 801494E4 460020A1 */  cvt.d.s   $f2, $f4
/* DFBE8 801494E8 4620103C */  c.lt.d    $f2, $f0
/* DFBEC 801494EC 00000000 */  nop
/* DFBF0 801494F0 45000005 */  bc1f      .L80149508
/* DFBF4 801494F4 00000000 */   nop
/* DFBF8 801494F8 3C014170 */  lui       $at, 0x4170
/* DFBFC 801494FC 44812000 */  mtc1      $at, $f4
/* DFC00 80149500 08052549 */  j         .L80149524
/* DFC04 80149504 00000000 */   nop
.L80149508:
/* DFC08 80149508 4622303C */  c.lt.d    $f6, $f2
/* DFC0C 8014950C 00000000 */  nop
/* DFC10 80149510 45000004 */  bc1f      .L80149524
/* DFC14 80149514 00000000 */   nop
/* DFC18 80149518 3C0142FE */  lui       $at, 0x42fe
/* DFC1C 8014951C 44812000 */  mtc1      $at, $f4
/* DFC20 80149520 00000000 */  nop
.L80149524:
/* DFC24 80149524 4600220D */  trunc.w.s $f8, $f4
/* DFC28 80149528 44024000 */  mfc1      $v0, $f8
/* DFC2C 8014952C 00000000 */  nop
/* DFC30 80149530 A6220000 */  sh        $v0, ($s1)
/* DFC34 80149534 C7A00020 */  lwc1      $f0, 0x20($sp)
/* DFC38 80149538 46800020 */  cvt.s.w   $f0, $f0
/* DFC3C 8014953C 3C014064 */  lui       $at, 0x4064
/* DFC40 80149540 44811800 */  mtc1      $at, $f3
/* DFC44 80149544 44801000 */  mtc1      $zero, $f2
/* DFC48 80149548 46000021 */  cvt.d.s   $f0, $f0
/* DFC4C 8014954C 46220001 */  sub.d     $f0, $f0, $f2
/* DFC50 80149550 3C018015 */  lui       $at, %hi(D_80151260)
/* DFC54 80149554 D4221260 */  ldc1      $f2, %lo(D_80151260)($at)
/* DFC58 80149558 3C014050 */  lui       $at, 0x4050
/* DFC5C 8014955C 44812800 */  mtc1      $at, $f5
/* DFC60 80149560 44802000 */  mtc1      $zero, $f4
/* DFC64 80149564 46220003 */  div.d     $f0, $f0, $f2
/* DFC68 80149568 46240000 */  add.d     $f0, $f0, $f4
/* DFC6C 8014956C 46200120 */  cvt.s.d   $f4, $f0
/* DFC70 80149570 3C013FF0 */  lui       $at, 0x3ff0
/* DFC74 80149574 44810800 */  mtc1      $at, $f1
/* DFC78 80149578 44800000 */  mtc1      $zero, $f0
/* DFC7C 8014957C 460020A1 */  cvt.d.s   $f2, $f4
/* DFC80 80149580 4620103C */  c.lt.d    $f2, $f0
/* DFC84 80149584 00000000 */  nop
/* DFC88 80149588 45000005 */  bc1f      .L801495A0
/* DFC8C 8014958C 00000000 */   nop
/* DFC90 80149590 3C013F80 */  lui       $at, 0x3f80
/* DFC94 80149594 44812000 */  mtc1      $at, $f4
/* DFC98 80149598 08052571 */  j         .L801495C4
/* DFC9C 8014959C 00000000 */   nop
.L801495A0:
/* DFCA0 801495A0 3C018015 */  lui       $at, %hi(D_80151268)
/* DFCA4 801495A4 D4201268 */  ldc1      $f0, %lo(D_80151268)($at)
/* DFCA8 801495A8 4622003C */  c.lt.d    $f0, $f2
/* DFCAC 801495AC 00000000 */  nop
/* DFCB0 801495B0 45000004 */  bc1f      .L801495C4
/* DFCB4 801495B4 00000000 */   nop
/* DFCB8 801495B8 3C0142FE */  lui       $at, 0x42fe
/* DFCBC 801495BC 44812000 */  mtc1      $at, $f4
/* DFCC0 801495C0 00000000 */  nop
.L801495C4:
/* DFCC4 801495C4 4600220D */  trunc.w.s $f8, $f4
/* DFCC8 801495C8 44024000 */  mfc1      $v0, $f8
/* DFCCC 801495CC 00000000 */  nop
/* DFCD0 801495D0 A6420000 */  sh        $v0, ($s2)
.L801495D4:
/* DFCD4 801495D4 8FBF003C */  lw        $ra, 0x3c($sp)
/* DFCD8 801495D8 8FB20038 */  lw        $s2, 0x38($sp)
/* DFCDC 801495DC 8FB10034 */  lw        $s1, 0x34($sp)
/* DFCE0 801495E0 8FB00030 */  lw        $s0, 0x30($sp)
/* DFCE4 801495E4 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* DFCE8 801495E8 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* DFCEC 801495EC D7B80050 */  ldc1      $f24, 0x50($sp)
/* DFCF0 801495F0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* DFCF4 801495F4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DFCF8 801495F8 03E00008 */  jr        $ra
/* DFCFC 801495FC 27BD0068 */   addiu    $sp, $sp, 0x68
