.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00EA66C
/* 3E254C E00EA66C 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 3E2550 E00EA670 0080302D */  daddu     $a2, $a0, $zero
/* 3E2554 E00EA674 3C07DB06 */  lui       $a3, 0xdb06
/* 3E2558 E00EA678 34E70024 */  ori       $a3, $a3, 0x24
/* 3E255C E00EA67C AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3E2560 E00EA680 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 3E2564 E00EA684 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 3E2568 E00EA688 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3E256C E00EA68C AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3E2570 E00EA690 AFB700BC */  sw        $s7, 0xbc($sp)
/* 3E2574 E00EA694 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3E2578 E00EA698 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3E257C E00EA69C AFB300AC */  sw        $s3, 0xac($sp)
/* 3E2580 E00EA6A0 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3E2584 E00EA6A4 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3E2588 E00EA6A8 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3E258C E00EA6AC 8E830000 */  lw        $v1, ($s4)
/* 3E2590 E00EA6B0 8CD3000C */  lw        $s3, 0xc($a2)
/* 3E2594 E00EA6B4 3C014080 */  lui       $at, 0x4080
/* 3E2598 E00EA6B8 44810000 */  mtc1      $at, $f0
/* 3E259C E00EA6BC 0060282D */  daddu     $a1, $v1, $zero
/* 3E25A0 E00EA6C0 24630008 */  addiu     $v1, $v1, 8
/* 3E25A4 E00EA6C4 AE830000 */  sw        $v1, ($s4)
/* 3E25A8 E00EA6C8 8E6B0000 */  lw        $t3, ($s3)
/* 3E25AC E00EA6CC 27A40018 */  addiu     $a0, $sp, 0x18
/* 3E25B0 E00EA6D0 AFAB0098 */  sw        $t3, 0x98($sp)
/* 3E25B4 E00EA6D4 C6620040 */  lwc1      $f2, 0x40($s3)
/* 3E25B8 E00EA6D8 3C02E700 */  lui       $v0, 0xe700
/* 3E25BC E00EA6DC 46001082 */  mul.s     $f2, $f2, $f0
/* 3E25C0 E00EA6E0 00000000 */  nop
/* 3E25C4 E00EA6E4 3C08800B */  lui       $t0, %hi(gCameras)
/* 3E25C8 E00EA6E8 25081D80 */  addiu     $t0, $t0, %lo(gCameras)
/* 3E25CC E00EA6EC C6640044 */  lwc1      $f4, 0x44($s3)
/* 3E25D0 E00EA6F0 C6660050 */  lwc1      $f6, 0x50($s3)
/* 3E25D4 E00EA6F4 C6680054 */  lwc1      $f8, 0x54($s3)
/* 3E25D8 E00EA6F8 46002102 */  mul.s     $f4, $f4, $f0
/* 3E25DC E00EA6FC 00000000 */  nop
/* 3E25E0 E00EA700 ACA20000 */  sw        $v0, ($a1)
/* 3E25E4 E00EA704 24620008 */  addiu     $v0, $v1, 8
/* 3E25E8 E00EA708 ACA00004 */  sw        $zero, 4($a1)
/* 3E25EC E00EA70C AE820000 */  sw        $v0, ($s4)
/* 3E25F0 E00EA710 46003182 */  mul.s     $f6, $f6, $f0
/* 3E25F4 E00EA714 00000000 */  nop
/* 3E25F8 E00EA718 AC670000 */  sw        $a3, ($v1)
/* 3E25FC E00EA71C 8CC20010 */  lw        $v0, 0x10($a2)
/* 3E2600 E00EA720 3C058000 */  lui       $a1, 0x8000
/* 3E2604 E00EA724 8C42001C */  lw        $v0, 0x1c($v0)
/* 3E2608 E00EA728 46004202 */  mul.s     $f8, $f8, $f0
/* 3E260C E00EA72C 00000000 */  nop
/* 3E2610 E00EA730 00451021 */  addu      $v0, $v0, $a1
/* 3E2614 E00EA734 AC620004 */  sw        $v0, 4($v1)
/* 3E2618 E00EA738 8E650004 */  lw        $a1, 4($s3)
/* 3E261C E00EA73C 8E660008 */  lw        $a2, 8($s3)
/* 3E2620 E00EA740 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3E2624 E00EA744 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3E2628 E00EA748 8E67000C */  lw        $a3, 0xc($s3)
/* 3E262C E00EA74C 00031080 */  sll       $v0, $v1, 2
/* 3E2630 E00EA750 00431021 */  addu      $v0, $v0, $v1
/* 3E2634 E00EA754 00021080 */  sll       $v0, $v0, 2
/* 3E2638 E00EA758 00431023 */  subu      $v0, $v0, $v1
/* 3E263C E00EA75C 000218C0 */  sll       $v1, $v0, 3
/* 3E2640 E00EA760 00431021 */  addu      $v0, $v0, $v1
/* 3E2644 E00EA764 000210C0 */  sll       $v0, $v0, 3
/* 3E2648 E00EA768 4600128D */  trunc.w.s $f10, $f2
/* 3E264C E00EA76C 44165000 */  mfc1      $s6, $f10
/* 3E2650 E00EA770 4600228D */  trunc.w.s $f10, $f4
/* 3E2654 E00EA774 44175000 */  mfc1      $s7, $f10
/* 3E2658 E00EA778 4600328D */  trunc.w.s $f10, $f6
/* 3E265C E00EA77C 441E5000 */  mfc1      $fp, $f10
/* 3E2660 E00EA780 4600428D */  trunc.w.s $f10, $f8
/* 3E2664 E00EA784 E7AA009C */  swc1      $f10, 0x9c($sp)
/* 3E2668 E00EA788 0C080108 */  jal       func_E0200420
/* 3E266C E00EA78C 0048A821 */   addu     $s5, $v0, $t0
/* 3E2670 E00EA790 27B00058 */  addiu     $s0, $sp, 0x58
/* 3E2674 E00EA794 8E65003C */  lw        $a1, 0x3c($s3)
/* 3E2678 E00EA798 0200202D */  daddu     $a0, $s0, $zero
/* 3E267C E00EA79C 00A0302D */  daddu     $a2, $a1, $zero
/* 3E2680 E00EA7A0 0C080110 */  jal       func_E0200440
/* 3E2684 E00EA7A4 00A0382D */   daddu    $a3, $a1, $zero
/* 3E2688 E00EA7A8 0200202D */  daddu     $a0, $s0, $zero
/* 3E268C E00EA7AC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3E2690 E00EA7B0 0C080114 */  jal       func_E0200450
/* 3E2694 E00EA7B4 00A0302D */   daddu    $a2, $a1, $zero
/* 3E2698 E00EA7B8 8FAB0098 */  lw        $t3, 0x98($sp)
/* 3E269C E00EA7BC 24020001 */  addiu     $v0, $zero, 1
/* 3E26A0 E00EA7C0 1562000F */  bne       $t3, $v0, .LE00EA800
/* 3E26A4 E00EA7C4 3C120001 */   lui      $s2, 1
/* 3E26A8 E00EA7C8 0200202D */  daddu     $a0, $s0, $zero
/* 3E26AC E00EA7CC 44800000 */  mtc1      $zero, $f0
/* 3E26B0 E00EA7D0 3C054334 */  lui       $a1, 0x4334
/* 3E26B4 E00EA7D4 44060000 */  mfc1      $a2, $f0
/* 3E26B8 E00EA7D8 3C013F80 */  lui       $at, 0x3f80
/* 3E26BC E00EA7DC 44810000 */  mtc1      $at, $f0
/* 3E26C0 E00EA7E0 00C0382D */  daddu     $a3, $a2, $zero
/* 3E26C4 E00EA7E4 0C080104 */  jal       func_E0200410
/* 3E26C8 E00EA7E8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 3E26CC E00EA7EC 0200202D */  daddu     $a0, $s0, $zero
/* 3E26D0 E00EA7F0 27A50018 */  addiu     $a1, $sp, 0x18
/* 3E26D4 E00EA7F4 0C080114 */  jal       func_E0200450
/* 3E26D8 E00EA7F8 00A0302D */   daddu    $a2, $a1, $zero
/* 3E26DC E00EA7FC 3C120001 */  lui       $s2, 1
.LE00EA800:
/* 3E26E0 E00EA800 36521630 */  ori       $s2, $s2, 0x1630
/* 3E26E4 E00EA804 27A40018 */  addiu     $a0, $sp, 0x18
/* 3E26E8 E00EA808 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3E26EC E00EA80C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3E26F0 E00EA810 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3E26F4 E00EA814 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3E26F8 E00EA818 96050000 */  lhu       $a1, ($s0)
/* 3E26FC E00EA81C 8E220000 */  lw        $v0, ($s1)
/* 3E2700 E00EA820 00052980 */  sll       $a1, $a1, 6
/* 3E2704 E00EA824 00B22821 */  addu      $a1, $a1, $s2
/* 3E2708 E00EA828 0C080118 */  jal       func_E0200460
/* 3E270C E00EA82C 00452821 */   addu     $a1, $v0, $a1
/* 3E2710 E00EA830 3C03DA38 */  lui       $v1, 0xda38
/* 3E2714 E00EA834 34630002 */  ori       $v1, $v1, 2
/* 3E2718 E00EA838 3C06DA38 */  lui       $a2, 0xda38
/* 3E271C E00EA83C 34C60001 */  ori       $a2, $a2, 1
/* 3E2720 E00EA840 3C098080 */  lui       $t1, 0x8080
/* 3E2724 E00EA844 35298081 */  ori       $t1, $t1, 0x8081
/* 3E2728 E00EA848 8E850000 */  lw        $a1, ($s4)
/* 3E272C E00EA84C 96020000 */  lhu       $v0, ($s0)
/* 3E2730 E00EA850 00A0202D */  daddu     $a0, $a1, $zero
/* 3E2734 E00EA854 24A50008 */  addiu     $a1, $a1, 8
/* 3E2738 E00EA858 AE850000 */  sw        $a1, ($s4)
/* 3E273C E00EA85C AC830000 */  sw        $v1, ($a0)
/* 3E2740 E00EA860 24430001 */  addiu     $v1, $v0, 1
/* 3E2744 E00EA864 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3E2748 E00EA868 00021180 */  sll       $v0, $v0, 6
/* 3E274C E00EA86C A6030000 */  sh        $v1, ($s0)
/* 3E2750 E00EA870 8E230000 */  lw        $v1, ($s1)
/* 3E2754 E00EA874 00521021 */  addu      $v0, $v0, $s2
/* 3E2758 E00EA878 00621821 */  addu      $v1, $v1, $v0
/* 3E275C E00EA87C 24A20008 */  addiu     $v0, $a1, 8
/* 3E2760 E00EA880 AC830004 */  sw        $v1, 4($a0)
/* 3E2764 E00EA884 AE820000 */  sw        $v0, ($s4)
/* 3E2768 E00EA888 24A20010 */  addiu     $v0, $a1, 0x10
/* 3E276C E00EA88C ACA60000 */  sw        $a2, ($a1)
/* 3E2770 E00EA890 AE820000 */  sw        $v0, ($s4)
/* 3E2774 E00EA894 8EA30204 */  lw        $v1, 0x204($s5)
/* 3E2778 E00EA898 3C02FA00 */  lui       $v0, 0xfa00
/* 3E277C E00EA89C ACA20008 */  sw        $v0, 8($a1)
/* 3E2780 E00EA8A0 ACA30004 */  sw        $v1, 4($a1)
/* 3E2784 E00EA8A4 9262001B */  lbu       $v0, 0x1b($s3)
/* 3E2788 E00EA8A8 9264001F */  lbu       $a0, 0x1f($s3)
/* 3E278C E00EA8AC 92660023 */  lbu       $a2, 0x23($s3)
/* 3E2790 E00EA8B0 92670037 */  lbu       $a3, 0x37($s3)
/* 3E2794 E00EA8B4 24A30018 */  addiu     $v1, $a1, 0x18
/* 3E2798 E00EA8B8 AE830000 */  sw        $v1, ($s4)
/* 3E279C E00EA8BC 3C03FB00 */  lui       $v1, 0xfb00
/* 3E27A0 E00EA8C0 ACA30010 */  sw        $v1, 0x10($a1)
/* 3E27A4 E00EA8C4 00021600 */  sll       $v0, $v0, 0x18
/* 3E27A8 E00EA8C8 00042400 */  sll       $a0, $a0, 0x10
/* 3E27AC E00EA8CC 00441025 */  or        $v0, $v0, $a0
/* 3E27B0 E00EA8D0 00063200 */  sll       $a2, $a2, 8
/* 3E27B4 E00EA8D4 00461025 */  or        $v0, $v0, $a2
/* 3E27B8 E00EA8D8 00471025 */  or        $v0, $v0, $a3
/* 3E27BC E00EA8DC ACA2000C */  sw        $v0, 0xc($a1)
/* 3E27C0 E00EA8E0 9264002B */  lbu       $a0, 0x2b($s3)
/* 3E27C4 E00EA8E4 9266002F */  lbu       $a2, 0x2f($s3)
/* 3E27C8 E00EA8E8 92670033 */  lbu       $a3, 0x33($s3)
/* 3E27CC E00EA8EC 24A20020 */  addiu     $v0, $a1, 0x20
/* 3E27D0 E00EA8F0 AE820000 */  sw        $v0, ($s4)
/* 3E27D4 E00EA8F4 8E630024 */  lw        $v1, 0x24($s3)
/* 3E27D8 E00EA8F8 8E620038 */  lw        $v0, 0x38($s3)
/* 3E27DC E00EA8FC 3C0AD838 */  lui       $t2, 0xd838
/* 3E27E0 E00EA900 00620018 */  mult      $v1, $v0
/* 3E27E4 E00EA904 3C08DE00 */  lui       $t0, 0xde00
/* 3E27E8 E00EA908 ACA80018 */  sw        $t0, 0x18($a1)
/* 3E27EC E00EA90C 24A20028 */  addiu     $v0, $a1, 0x28
/* 3E27F0 E00EA910 00042600 */  sll       $a0, $a0, 0x18
/* 3E27F4 E00EA914 00001812 */  mflo      $v1
/* 3E27F8 E00EA918 00063400 */  sll       $a2, $a2, 0x10
/* 3E27FC E00EA91C 00862025 */  or        $a0, $a0, $a2
/* 3E2800 E00EA920 00690018 */  mult      $v1, $t1
/* 3E2804 E00EA924 00073A00 */  sll       $a3, $a3, 8
/* 3E2808 E00EA928 00872025 */  or        $a0, $a0, $a3
/* 3E280C E00EA92C 3C06F200 */  lui       $a2, 0xf200
/* 3E2810 E00EA930 AE820000 */  sw        $v0, ($s4)
/* 3E2814 E00EA934 00001010 */  mfhi      $v0
/* 3E2818 E00EA938 00431021 */  addu      $v0, $v0, $v1
/* 3E281C E00EA93C 000211C3 */  sra       $v0, $v0, 7
/* 3E2820 E00EA940 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3E2824 E00EA944 00431023 */  subu      $v0, $v0, $v1
/* 3E2828 E00EA948 304200FF */  andi      $v0, $v0, 0xff
/* 3E282C E00EA94C 00822025 */  or        $a0, $a0, $v0
/* 3E2830 E00EA950 32C30FFF */  andi      $v1, $s6, 0xfff
/* 3E2834 E00EA954 00031B00 */  sll       $v1, $v1, 0xc
/* 3E2838 E00EA958 32E20FFF */  andi      $v0, $s7, 0xfff
/* 3E283C E00EA95C 00461025 */  or        $v0, $v0, $a2
/* 3E2840 E00EA960 00621825 */  or        $v1, $v1, $v0
/* 3E2844 E00EA964 26C200FC */  addiu     $v0, $s6, 0xfc
/* 3E2848 E00EA968 30420FFF */  andi      $v0, $v0, 0xfff
/* 3E284C E00EA96C ACA40014 */  sw        $a0, 0x14($a1)
/* 3E2850 E00EA970 3C04E00F */  lui       $a0, %hi(D_E00EAA58)
/* 3E2854 E00EA974 8C84AA58 */  lw        $a0, %lo(D_E00EAA58)($a0)
/* 3E2858 E00EA978 00021300 */  sll       $v0, $v0, 0xc
/* 3E285C E00EA97C ACA30020 */  sw        $v1, 0x20($a1)
/* 3E2860 E00EA980 26E300FC */  addiu     $v1, $s7, 0xfc
/* 3E2864 E00EA984 30630FFF */  andi      $v1, $v1, 0xfff
/* 3E2868 E00EA988 00431025 */  or        $v0, $v0, $v1
/* 3E286C E00EA98C ACA20024 */  sw        $v0, 0x24($a1)
/* 3E2870 E00EA990 24A20030 */  addiu     $v0, $a1, 0x30
/* 3E2874 E00EA994 33C30FFF */  andi      $v1, $fp, 0xfff
/* 3E2878 E00EA998 00031B00 */  sll       $v1, $v1, 0xc
/* 3E287C E00EA99C ACA4001C */  sw        $a0, 0x1c($a1)
/* 3E2880 E00EA9A0 AE820000 */  sw        $v0, ($s4)
/* 3E2884 E00EA9A4 8FAB009C */  lw        $t3, 0x9c($sp)
/* 3E2888 E00EA9A8 3C040100 */  lui       $a0, 0x100
/* 3E288C E00EA9AC 31620FFF */  andi      $v0, $t3, 0xfff
/* 3E2890 E00EA9B0 00461025 */  or        $v0, $v0, $a2
/* 3E2894 E00EA9B4 00621825 */  or        $v1, $v1, $v0
/* 3E2898 E00EA9B8 27C200FC */  addiu     $v0, $fp, 0xfc
/* 3E289C E00EA9BC 30420FFF */  andi      $v0, $v0, 0xfff
/* 3E28A0 E00EA9C0 00021300 */  sll       $v0, $v0, 0xc
/* 3E28A4 E00EA9C4 ACA30028 */  sw        $v1, 0x28($a1)
/* 3E28A8 E00EA9C8 256300FC */  addiu     $v1, $t3, 0xfc
/* 3E28AC E00EA9CC 30630FFF */  andi      $v1, $v1, 0xfff
/* 3E28B0 E00EA9D0 00641825 */  or        $v1, $v1, $a0
/* 3E28B4 E00EA9D4 00431025 */  or        $v0, $v0, $v1
/* 3E28B8 E00EA9D8 ACA2002C */  sw        $v0, 0x2c($a1)
/* 3E28BC E00EA9DC 24A20038 */  addiu     $v0, $a1, 0x38
/* 3E28C0 E00EA9E0 AE820000 */  sw        $v0, ($s4)
/* 3E28C4 E00EA9E4 ACA80030 */  sw        $t0, 0x30($a1)
/* 3E28C8 E00EA9E8 8FAB0098 */  lw        $t3, 0x98($sp)
/* 3E28CC E00EA9EC 354A0002 */  ori       $t2, $t2, 2
/* 3E28D0 E00EA9F0 000B1080 */  sll       $v0, $t3, 2
/* 3E28D4 E00EA9F4 3C03E00F */  lui       $v1, %hi(D_E00EAA50)
/* 3E28D8 E00EA9F8 00621821 */  addu      $v1, $v1, $v0
/* 3E28DC E00EA9FC 8C63AA50 */  lw        $v1, %lo(D_E00EAA50)($v1)
/* 3E28E0 E00EAA00 24A20040 */  addiu     $v0, $a1, 0x40
/* 3E28E4 E00EAA04 AE820000 */  sw        $v0, ($s4)
/* 3E28E8 E00EAA08 24020040 */  addiu     $v0, $zero, 0x40
/* 3E28EC E00EAA0C ACAA0038 */  sw        $t2, 0x38($a1)
/* 3E28F0 E00EAA10 ACA2003C */  sw        $v0, 0x3c($a1)
/* 3E28F4 E00EAA14 ACA30034 */  sw        $v1, 0x34($a1)
/* 3E28F8 E00EAA18 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3E28FC E00EAA1C 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3E2900 E00EAA20 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3E2904 E00EAA24 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3E2908 E00EAA28 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3E290C E00EAA2C 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3E2910 E00EAA30 8FB300AC */  lw        $s3, 0xac($sp)
/* 3E2914 E00EAA34 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3E2918 E00EAA38 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3E291C E00EAA3C 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3E2920 E00EAA40 03E00008 */  jr        $ra
/* 3E2924 E00EAA44 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 3E2928 E00EAA48 00000000 */  nop
/* 3E292C E00EAA4C 00000000 */  nop
