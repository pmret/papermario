.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AE1B4
/* 3B2504 E00AE1B4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B2508 E00AE1B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3B250C E00AE1BC 0080982D */  daddu     $s3, $a0, $zero
/* 3B2510 E00AE1C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B2514 E00AE1C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 3B2518 E00AE1C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 3B251C E00AE1CC AFB00010 */  sw        $s0, 0x10($sp)
/* 3B2520 E00AE1D0 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 3B2524 E00AE1D4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 3B2528 E00AE1D8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 3B252C E00AE1DC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 3B2530 E00AE1E0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 3B2534 E00AE1E4 8E630000 */  lw        $v1, ($s3)
/* 3B2538 E00AE1E8 8E71000C */  lw        $s1, 0xc($s3)
/* 3B253C E00AE1EC 30620010 */  andi      $v0, $v1, 0x10
/* 3B2540 E00AE1F0 10400005 */  beqz      $v0, .LE00AE208
/* 3B2544 E00AE1F4 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B2548 E00AE1F8 00621024 */  and       $v0, $v1, $v0
/* 3B254C E00AE1FC AE620000 */  sw        $v0, ($s3)
/* 3B2550 E00AE200 24020010 */  addiu     $v0, $zero, 0x10
/* 3B2554 E00AE204 AE220010 */  sw        $v0, 0x10($s1)
.LE00AE208:
/* 3B2558 E00AE208 8E230010 */  lw        $v1, 0x10($s1)
/* 3B255C E00AE20C 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3B2560 E00AE210 10400002 */  beqz      $v0, .LE00AE21C
/* 3B2564 E00AE214 2462FFFF */   addiu    $v0, $v1, -1
/* 3B2568 E00AE218 AE220010 */  sw        $v0, 0x10($s1)
.LE00AE21C:
/* 3B256C E00AE21C 8E220014 */  lw        $v0, 0x14($s1)
/* 3B2570 E00AE220 8E230010 */  lw        $v1, 0x10($s1)
/* 3B2574 E00AE224 24440001 */  addiu     $a0, $v0, 1
/* 3B2578 E00AE228 04610005 */  bgez      $v1, .LE00AE240
/* 3B257C E00AE22C AE240014 */   sw       $a0, 0x14($s1)
/* 3B2580 E00AE230 0C080128 */  jal       shim_remove_effect
/* 3B2584 E00AE234 0260202D */   daddu    $a0, $s3, $zero
/* 3B2588 E00AE238 0802B933 */  j         .LE00AE4CC
/* 3B258C E00AE23C 00000000 */   nop
.LE00AE240:
/* 3B2590 E00AE240 28620010 */  slti      $v0, $v1, 0x10
/* 3B2594 E00AE244 10400002 */  beqz      $v0, .LE00AE250
/* 3B2598 E00AE248 00031100 */   sll      $v0, $v1, 4
/* 3B259C E00AE24C AE220024 */  sw        $v0, 0x24($s1)
.LE00AE250:
/* 3B25A0 E00AE250 28820010 */  slti      $v0, $a0, 0x10
/* 3B25A4 E00AE254 10400003 */  beqz      $v0, .LE00AE264
/* 3B25A8 E00AE258 00041100 */   sll      $v0, $a0, 4
/* 3B25AC E00AE25C 2442000F */  addiu     $v0, $v0, 0xf
/* 3B25B0 E00AE260 AE220024 */  sw        $v0, 0x24($s1)
.LE00AE264:
/* 3B25B4 E00AE264 8E620008 */  lw        $v0, 8($s3)
/* 3B25B8 E00AE268 24120001 */  addiu     $s2, $zero, 1
/* 3B25BC E00AE26C 0242102A */  slt       $v0, $s2, $v0
/* 3B25C0 E00AE270 1040008B */  beqz      $v0, .LE00AE4A0
/* 3B25C4 E00AE274 26310044 */   addiu    $s1, $s1, 0x44
/* 3B25C8 E00AE278 4480E000 */  mtc1      $zero, $f28
/* 3B25CC E00AE27C 26300014 */  addiu     $s0, $s1, 0x14
.LE00AE280:
/* 3B25D0 E00AE280 8E020000 */  lw        $v0, ($s0)
/* 3B25D4 E00AE284 8E03FFFC */  lw        $v1, -4($s0)
/* 3B25D8 E00AE288 0043102A */  slt       $v0, $v0, $v1
/* 3B25DC E00AE28C 1440000E */  bnez      $v0, .LE00AE2C8
/* 3B25E0 E00AE290 00000000 */   nop
/* 3B25E4 E00AE294 0C080138 */  jal       shim_rand_int
/* 3B25E8 E00AE298 24040032 */   addiu    $a0, $zero, 0x32
/* 3B25EC E00AE29C 24040168 */  addiu     $a0, $zero, 0x168
/* 3B25F0 E00AE2A0 24420014 */  addiu     $v0, $v0, 0x14
/* 3B25F4 E00AE2A4 AE02FFFC */  sw        $v0, -4($s0)
/* 3B25F8 E00AE2A8 0C080138 */  jal       shim_rand_int
/* 3B25FC E00AE2AC AE000000 */   sw       $zero, ($s0)
/* 3B2600 E00AE2B0 44820000 */  mtc1      $v0, $f0
/* 3B2604 E00AE2B4 00000000 */  nop
/* 3B2608 E00AE2B8 46800020 */  cvt.s.w   $f0, $f0
/* 3B260C E00AE2BC E6000028 */  swc1      $f0, 0x28($s0)
/* 3B2610 E00AE2C0 AE00FFF0 */  sw        $zero, -0x10($s0)
/* 3B2614 E00AE2C4 AE00FFF4 */  sw        $zero, -0xc($s0)
.LE00AE2C8:
/* 3B2618 E00AE2C8 0C080138 */  jal       shim_rand_int
/* 3B261C E00AE2CC 24040064 */   addiu    $a0, $zero, 0x64
/* 3B2620 E00AE2D0 28420033 */  slti      $v0, $v0, 0x33
/* 3B2624 E00AE2D4 10400047 */  beqz      $v0, .LE00AE3F4
/* 3B2628 E00AE2D8 00000000 */   nop
/* 3B262C E00AE2DC C618FFF0 */  lwc1      $f24, -0x10($s0)
/* 3B2630 E00AE2E0 C61AFFF4 */  lwc1      $f26, -0xc($s0)
/* 3B2634 E00AE2E4 0C080138 */  jal       shim_rand_int
/* 3B2638 E00AE2E8 24040010 */   addiu    $a0, $zero, 0x10
/* 3B263C E00AE2EC 2442FFF8 */  addiu     $v0, $v0, -8
/* 3B2640 E00AE2F0 4482B000 */  mtc1      $v0, $f22
/* 3B2644 E00AE2F4 00000000 */  nop
/* 3B2648 E00AE2F8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 3B264C E00AE2FC 0C080138 */  jal       shim_rand_int
/* 3B2650 E00AE300 24040010 */   addiu    $a0, $zero, 0x10
/* 3B2654 E00AE304 2442FFF8 */  addiu     $v0, $v0, -8
/* 3B2658 E00AE308 4482A000 */  mtc1      $v0, $f20
/* 3B265C E00AE30C 00000000 */  nop
/* 3B2660 E00AE310 4680A520 */  cvt.s.w   $f20, $f20
/* 3B2664 E00AE314 26230088 */  addiu     $v1, $s1, 0x88
/* 3B2668 E00AE318 26220044 */  addiu     $v0, $s1, 0x44
/* 3B266C E00AE31C 26240084 */  addiu     $a0, $s1, 0x84
.LE00AE320:
/* 3B2670 E00AE320 8C450000 */  lw        $a1, ($v0)
/* 3B2674 E00AE324 8C480004 */  lw        $t0, 4($v0)
/* 3B2678 E00AE328 8C490008 */  lw        $t1, 8($v0)
/* 3B267C E00AE32C 8C4A000C */  lw        $t2, 0xc($v0)
/* 3B2680 E00AE330 AC650000 */  sw        $a1, ($v1)
/* 3B2684 E00AE334 AC680004 */  sw        $t0, 4($v1)
/* 3B2688 E00AE338 AC690008 */  sw        $t1, 8($v1)
/* 3B268C E00AE33C AC6A000C */  sw        $t2, 0xc($v1)
/* 3B2690 E00AE340 24420010 */  addiu     $v0, $v0, 0x10
/* 3B2694 E00AE344 1444FFF6 */  bne       $v0, $a0, .LE00AE320
/* 3B2698 E00AE348 24630010 */   addiu    $v1, $v1, 0x10
/* 3B269C E00AE34C 8C450000 */  lw        $a1, ($v0)
/* 3B26A0 E00AE350 AC650000 */  sw        $a1, ($v1)
/* 3B26A4 E00AE354 26230044 */  addiu     $v1, $s1, 0x44
/* 3B26A8 E00AE358 0220102D */  daddu     $v0, $s1, $zero
/* 3B26AC E00AE35C 26240040 */  addiu     $a0, $s1, 0x40
.LE00AE360:
/* 3B26B0 E00AE360 8C450000 */  lw        $a1, ($v0)
/* 3B26B4 E00AE364 8C480004 */  lw        $t0, 4($v0)
/* 3B26B8 E00AE368 8C490008 */  lw        $t1, 8($v0)
/* 3B26BC E00AE36C 8C4A000C */  lw        $t2, 0xc($v0)
/* 3B26C0 E00AE370 AC650000 */  sw        $a1, ($v1)
/* 3B26C4 E00AE374 AC680004 */  sw        $t0, 4($v1)
/* 3B26C8 E00AE378 AC690008 */  sw        $t1, 8($v1)
/* 3B26CC E00AE37C AC6A000C */  sw        $t2, 0xc($v1)
/* 3B26D0 E00AE380 24420010 */  addiu     $v0, $v0, 0x10
/* 3B26D4 E00AE384 1444FFF6 */  bne       $v0, $a0, .LE00AE360
/* 3B26D8 E00AE388 24630010 */   addiu    $v1, $v1, 0x10
/* 3B26DC E00AE38C 4600E306 */  mov.s     $f12, $f28
/* 3B26E0 E00AE390 4600E386 */  mov.s     $f14, $f28
/* 3B26E4 E00AE394 4616C080 */  add.s     $f2, $f24, $f22
/* 3B26E8 E00AE398 4406B000 */  mfc1      $a2, $f22
/* 3B26EC E00AE39C 4407A000 */  mfc1      $a3, $f20
/* 3B26F0 E00AE3A0 4614D000 */  add.s     $f0, $f26, $f20
/* 3B26F4 E00AE3A4 8C450000 */  lw        $a1, ($v0)
/* 3B26F8 E00AE3A8 AC650000 */  sw        $a1, ($v1)
/* 3B26FC E00AE3AC E602FFF0 */  swc1      $f2, -0x10($s0)
/* 3B2700 E00AE3B0 0C080148 */  jal       shim_atan2
/* 3B2704 E00AE3B4 E600FFF4 */   swc1     $f0, -0xc($s0)
/* 3B2708 E00AE3B8 461CB032 */  c.eq.s    $f22, $f28
/* 3B270C E00AE3BC 00000000 */  nop
/* 3B2710 E00AE3C0 45000005 */  bc1f      .LE00AE3D8
/* 3B2714 E00AE3C4 E6000028 */   swc1     $f0, 0x28($s0)
/* 3B2718 E00AE3C8 461CA032 */  c.eq.s    $f20, $f28
/* 3B271C E00AE3CC 00000000 */  nop
/* 3B2720 E00AE3D0 45030008 */  bc1tl     .LE00AE3F4
/* 3B2724 E00AE3D4 E61C0020 */   swc1     $f28, 0x20($s0)
.LE00AE3D8:
/* 3B2728 E00AE3D8 4616B002 */  mul.s     $f0, $f22, $f22
/* 3B272C E00AE3DC 00000000 */  nop
/* 3B2730 E00AE3E0 4614A302 */  mul.s     $f12, $f20, $f20
/* 3B2734 E00AE3E4 00000000 */  nop
/* 3B2738 E00AE3E8 0C080154 */  jal       shim_sqrtf
/* 3B273C E00AE3EC 460C0300 */   add.s    $f12, $f0, $f12
/* 3B2740 E00AE3F0 E6000020 */  swc1      $f0, 0x20($s0)
.LE00AE3F4:
/* 3B2744 E00AE3F4 8E020000 */  lw        $v0, ($s0)
/* 3B2748 E00AE3F8 00021840 */  sll       $v1, $v0, 1
/* 3B274C E00AE3FC 00621821 */  addu      $v1, $v1, $v0
/* 3B2750 E00AE400 00031100 */  sll       $v0, $v1, 4
/* 3B2754 E00AE404 00431023 */  subu      $v0, $v0, $v1
/* 3B2758 E00AE408 8E03FFFC */  lw        $v1, -4($s0)
/* 3B275C E00AE40C 00021080 */  sll       $v0, $v0, 2
/* 3B2760 E00AE410 14600002 */  bnez      $v1, .LE00AE41C
/* 3B2764 E00AE414 0043001A */   div      $zero, $v0, $v1
/* 3B2768 E00AE418 0007000D */  break     7
.LE00AE41C:
/* 3B276C E00AE41C 2401FFFF */   addiu    $at, $zero, -1
/* 3B2770 E00AE420 14610004 */  bne       $v1, $at, .LE00AE434
/* 3B2774 E00AE424 3C018000 */   lui      $at, 0x8000
/* 3B2778 E00AE428 14410002 */  bne       $v0, $at, .LE00AE434
/* 3B277C E00AE42C 00000000 */   nop
/* 3B2780 E00AE430 0006000D */  break     6
.LE00AE434:
/* 3B2784 E00AE434 00001012 */   mflo     $v0
/* 3B2788 E00AE438 44826000 */  mtc1      $v0, $f12
/* 3B278C E00AE43C 00000000 */  nop
/* 3B2790 E00AE440 0C080140 */  jal       shim_sin_deg
/* 3B2794 E00AE444 46806320 */   cvt.s.w  $f12, $f12
/* 3B2798 E00AE448 3C014480 */  lui       $at, 0x4480
/* 3B279C E00AE44C 44811000 */  mtc1      $at, $f2
/* 3B27A0 E00AE450 00000000 */  nop
/* 3B27A4 E00AE454 46020002 */  mul.s     $f0, $f0, $f2
/* 3B27A8 E00AE458 00000000 */  nop
/* 3B27AC E00AE45C 4600010D */  trunc.w.s $f4, $f0
/* 3B27B0 E00AE460 44022000 */  mfc1      $v0, $f4
/* 3B27B4 E00AE464 00000000 */  nop
/* 3B27B8 E00AE468 AE020010 */  sw        $v0, 0x10($s0)
/* 3B27BC E00AE46C 28420100 */  slti      $v0, $v0, 0x100
/* 3B27C0 E00AE470 14400003 */  bnez      $v0, .LE00AE480
/* 3B27C4 E00AE474 26520003 */   addiu    $s2, $s2, 3
/* 3B27C8 E00AE478 240200FF */  addiu     $v0, $zero, 0xff
/* 3B27CC E00AE47C AE020010 */  sw        $v0, 0x10($s0)
.LE00AE480:
/* 3B27D0 E00AE480 8E020000 */  lw        $v0, ($s0)
/* 3B27D4 E00AE484 263100CC */  addiu     $s1, $s1, 0xcc
/* 3B27D8 E00AE488 24420001 */  addiu     $v0, $v0, 1
/* 3B27DC E00AE48C AE020000 */  sw        $v0, ($s0)
/* 3B27E0 E00AE490 8E620008 */  lw        $v0, 8($s3)
/* 3B27E4 E00AE494 0242102A */  slt       $v0, $s2, $v0
/* 3B27E8 E00AE498 1440FF79 */  bnez      $v0, .LE00AE280
/* 3B27EC E00AE49C 261000CC */   addiu    $s0, $s0, 0xcc
.LE00AE4A0:
/* 3B27F0 E00AE4A0 8E71000C */  lw        $s1, 0xc($s3)
/* 3B27F4 E00AE4A4 0802B92F */  j         .LE00AE4BC
/* 3B27F8 E00AE4A8 24120001 */   addiu    $s2, $zero, 1
.LE00AE4AC:
/* 3B27FC E00AE4AC 0C080138 */  jal       shim_rand_int
/* 3B2800 E00AE4B0 2404000F */   addiu    $a0, $zero, 0xf
/* 3B2804 E00AE4B4 26520001 */  addiu     $s2, $s2, 1
/* 3B2808 E00AE4B8 AE220040 */  sw        $v0, 0x40($s1)
.LE00AE4BC:
/* 3B280C E00AE4BC 8E620008 */  lw        $v0, 8($s3)
/* 3B2810 E00AE4C0 0242102A */  slt       $v0, $s2, $v0
/* 3B2814 E00AE4C4 1440FFF9 */  bnez      $v0, .LE00AE4AC
/* 3B2818 E00AE4C8 26310044 */   addiu    $s1, $s1, 0x44
.LE00AE4CC:
/* 3B281C E00AE4CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B2820 E00AE4D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3B2824 E00AE4D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 3B2828 E00AE4D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3B282C E00AE4DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B2830 E00AE4E0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 3B2834 E00AE4E4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 3B2838 E00AE4E8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 3B283C E00AE4EC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 3B2840 E00AE4F0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 3B2844 E00AE4F4 03E00008 */  jr        $ra
/* 3B2848 E00AE4F8 27BD0050 */   addiu    $sp, $sp, 0x50
