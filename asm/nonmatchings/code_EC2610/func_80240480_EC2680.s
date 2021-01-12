.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480_EC2680
/* EC2680 80240480 27BDFF78 */  addiu     $sp, $sp, -0x88
/* EC2684 80240484 AFB10054 */  sw        $s1, 0x54($sp)
/* EC2688 80240488 0080882D */  daddu     $s1, $a0, $zero
/* EC268C 8024048C AFBF005C */  sw        $ra, 0x5c($sp)
/* EC2690 80240490 AFB20058 */  sw        $s2, 0x58($sp)
/* EC2694 80240494 AFB00050 */  sw        $s0, 0x50($sp)
/* EC2698 80240498 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* EC269C 8024049C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EC26A0 802404A0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* EC26A4 802404A4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* EC26A8 802404A8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EC26AC 802404AC 8E30000C */  lw        $s0, 0xc($s1)
/* EC26B0 802404B0 8E050000 */  lw        $a1, ($s0)
/* EC26B4 802404B4 0C0B53A3 */  jal       func_802D4E8C
/* EC26B8 802404B8 26100004 */   addiu    $s0, $s0, 4
/* EC26BC 802404BC 0C04949C */  jal       func_80125270
/* EC26C0 802404C0 0040202D */   daddu    $a0, $v0, $zero
/* EC26C4 802404C4 8E050000 */  lw        $a1, ($s0)
/* EC26C8 802404C8 26100004 */  addiu     $s0, $s0, 4
/* EC26CC 802404CC 0220202D */  daddu     $a0, $s1, $zero
/* EC26D0 802404D0 0C0B55FF */  jal       func_802D57FC
/* EC26D4 802404D4 0040902D */   daddu    $s2, $v0, $zero
/* EC26D8 802404D8 8E050000 */  lw        $a1, ($s0)
/* EC26DC 802404DC 26100004 */  addiu     $s0, $s0, 4
/* EC26E0 802404E0 0220202D */  daddu     $a0, $s1, $zero
/* EC26E4 802404E4 0C0B55FF */  jal       func_802D57FC
/* EC26E8 802404E8 46000706 */   mov.s    $f28, $f0
/* EC26EC 802404EC 8E050000 */  lw        $a1, ($s0)
/* EC26F0 802404F0 26100004 */  addiu     $s0, $s0, 4
/* EC26F4 802404F4 0220202D */  daddu     $a0, $s1, $zero
/* EC26F8 802404F8 0C0B55FF */  jal       func_802D57FC
/* EC26FC 802404FC 46000686 */   mov.s    $f26, $f0
/* EC2700 80240500 0220202D */  daddu     $a0, $s1, $zero
/* EC2704 80240504 8E050000 */  lw        $a1, ($s0)
/* EC2708 80240508 0C0B55FF */  jal       func_802D57FC
/* EC270C 8024050C 46000586 */   mov.s    $f22, $f0
/* EC2710 80240510 0240202D */  daddu     $a0, $s2, $zero
/* EC2714 80240514 0C0493D1 */  jal       func_80124F44
/* EC2718 80240518 46000606 */   mov.s    $f24, $f0
/* EC271C 8024051C 0040882D */  daddu     $s1, $v0, $zero
/* EC2720 80240520 96220000 */  lhu       $v0, ($s1)
/* EC2724 80240524 30420400 */  andi      $v0, $v0, 0x400
/* EC2728 80240528 1440001E */  bnez      $v0, .L802405A4
/* EC272C 8024052C 26300058 */   addiu    $s0, $s1, 0x58
/* EC2730 80240530 4480A000 */  mtc1      $zero, $f20
/* EC2734 80240534 4406B000 */  mfc1      $a2, $f22
/* EC2738 80240538 4405A000 */  mfc1      $a1, $f20
/* EC273C 8024053C 4407A000 */  mfc1      $a3, $f20
/* EC2740 80240540 0C01B2B0 */  jal       func_8006CAC0
/* EC2744 80240544 0200202D */   daddu    $a0, $s0, $zero
/* EC2748 80240548 4405E000 */  mfc1      $a1, $f28
/* EC274C 8024054C 4406D000 */  mfc1      $a2, $f26
/* EC2750 80240550 4407C000 */  mfc1      $a3, $f24
/* EC2754 80240554 0C090104 */  jal       func_80240410_EC2610
/* EC2758 80240558 27A40010 */   addiu    $a0, $sp, 0x10
/* EC275C 8024055C 27A40010 */  addiu     $a0, $sp, 0x10
/* EC2760 80240560 0200282D */  daddu     $a1, $s0, $zero
/* EC2764 80240564 0C01B1F0 */  jal       osSiRawReadIo
/* EC2768 80240568 0200302D */   daddu    $a2, $s0, $zero
/* EC276C 8024056C 27A40010 */  addiu     $a0, $sp, 0x10
/* EC2770 80240570 4600B587 */  neg.s     $f22, $f22
/* EC2774 80240574 4405A000 */  mfc1      $a1, $f20
/* EC2778 80240578 4406B000 */  mfc1      $a2, $f22
/* EC277C 8024057C 0C01B2B0 */  jal       func_8006CAC0
/* EC2780 80240580 00A0382D */   daddu    $a3, $a1, $zero
/* EC2784 80240584 27A40010 */  addiu     $a0, $sp, 0x10
/* EC2788 80240588 0200282D */  daddu     $a1, $s0, $zero
/* EC278C 8024058C 0C01B1F0 */  jal       osSiRawReadIo
/* EC2790 80240590 00A0302D */   daddu    $a2, $a1, $zero
/* EC2794 80240594 96220000 */  lhu       $v0, ($s1)
/* EC2798 80240598 34421400 */  ori       $v0, $v0, 0x1400
/* EC279C 8024059C 08090187 */  j         .L8024061C
/* EC27A0 802405A0 A6220000 */   sh       $v0, ($s1)
.L802405A4:
/* EC27A4 802405A4 4480A000 */  mtc1      $zero, $f20
/* EC27A8 802405A8 4406B000 */  mfc1      $a2, $f22
/* EC27AC 802405AC 4405A000 */  mfc1      $a1, $f20
/* EC27B0 802405B0 4407A000 */  mfc1      $a3, $f20
/* EC27B4 802405B4 0C01B2B0 */  jal       func_8006CAC0
/* EC27B8 802405B8 27A40010 */   addiu    $a0, $sp, 0x10
/* EC27BC 802405BC 27A40010 */  addiu     $a0, $sp, 0x10
/* EC27C0 802405C0 26300058 */  addiu     $s0, $s1, 0x58
/* EC27C4 802405C4 0200282D */  daddu     $a1, $s0, $zero
/* EC27C8 802405C8 0C01B1F0 */  jal       osSiRawReadIo
/* EC27CC 802405CC 0200302D */   daddu    $a2, $s0, $zero
/* EC27D0 802405D0 4405E000 */  mfc1      $a1, $f28
/* EC27D4 802405D4 4406D000 */  mfc1      $a2, $f26
/* EC27D8 802405D8 4407C000 */  mfc1      $a3, $f24
/* EC27DC 802405DC 0C090104 */  jal       func_80240410_EC2610
/* EC27E0 802405E0 27A40010 */   addiu    $a0, $sp, 0x10
/* EC27E4 802405E4 27A40010 */  addiu     $a0, $sp, 0x10
/* EC27E8 802405E8 0200282D */  daddu     $a1, $s0, $zero
/* EC27EC 802405EC 0C01B1F0 */  jal       osSiRawReadIo
/* EC27F0 802405F0 0200302D */   daddu    $a2, $s0, $zero
/* EC27F4 802405F4 27A40010 */  addiu     $a0, $sp, 0x10
/* EC27F8 802405F8 4600B587 */  neg.s     $f22, $f22
/* EC27FC 802405FC 4405A000 */  mfc1      $a1, $f20
/* EC2800 80240600 4406B000 */  mfc1      $a2, $f22
/* EC2804 80240604 0C01B2B0 */  jal       func_8006CAC0
/* EC2808 80240608 00A0382D */   daddu    $a3, $a1, $zero
/* EC280C 8024060C 27A40010 */  addiu     $a0, $sp, 0x10
/* EC2810 80240610 0200282D */  daddu     $a1, $s0, $zero
/* EC2814 80240614 0C01B1F0 */  jal       osSiRawReadIo
/* EC2818 80240618 00A0302D */   daddu    $a2, $a1, $zero
.L8024061C:
/* EC281C 8024061C 8FBF005C */  lw        $ra, 0x5c($sp)
/* EC2820 80240620 8FB20058 */  lw        $s2, 0x58($sp)
/* EC2824 80240624 8FB10054 */  lw        $s1, 0x54($sp)
/* EC2828 80240628 8FB00050 */  lw        $s0, 0x50($sp)
/* EC282C 8024062C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* EC2830 80240630 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EC2834 80240634 D7B80070 */  ldc1      $f24, 0x70($sp)
/* EC2838 80240638 D7B60068 */  ldc1      $f22, 0x68($sp)
/* EC283C 8024063C D7B40060 */  ldc1      $f20, 0x60($sp)
/* EC2840 80240640 24020002 */  addiu     $v0, $zero, 2
/* EC2844 80240644 03E00008 */  jr        $ra
/* EC2848 80240648 27BD0088 */   addiu    $sp, $sp, 0x88
/* EC284C 8024064C 00000000 */  nop
