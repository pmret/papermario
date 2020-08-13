.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D74C0
/* 0FBE70 802D74C0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FBE74 802D74C4 24E2001E */  addiu $v0, $a3, 0x1e
/* 0FBE78 802D74C8 44820000 */  mtc1  $v0, $f0
/* 0FBE7C 802D74CC 00000000 */  nop   
/* 0FBE80 802D74D0 46800020 */  cvt.s.w $f0, $f0
/* 0FBE84 802D74D4 000717C2 */  srl   $v0, $a3, 0x1f
/* 0FBE88 802D74D8 00E23821 */  addu  $a3, $a3, $v0
/* 0FBE8C 802D74DC 00073843 */  sra   $a3, $a3, 1
/* 0FBE90 802D74E0 24E7000A */  addiu $a3, $a3, 0xa
/* 0FBE94 802D74E4 44861000 */  mtc1  $a2, $f2
/* 0FBE98 802D74E8 44056000 */  mfc1  $a1, $f12
/* 0FBE9C 802D74EC 44067000 */  mfc1  $a2, $f14
/* 0FBEA0 802D74F0 2402001E */  addiu $v0, $zero, 0x1e
/* 0FBEA4 802D74F4 AFA70018 */  sw    $a3, 0x18($sp)
/* 0FBEA8 802D74F8 44071000 */  mfc1  $a3, $f2
/* 0FBEAC 802D74FC 24040002 */  addiu $a0, $zero, 2
/* 0FBEB0 802D7500 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0FBEB4 802D7504 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0FBEB8 802D7508 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0FBEBC 802D750C 0C01C154 */  jal   func_80070550
/* 0FBEC0 802D7510 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0FBEC4 802D7514 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0FBEC8 802D7518 03E00008 */  jr    $ra
/* 0FBECC 802D751C 27BD0028 */   addiu $sp, $sp, 0x28

/* 0FBED0 802D7520 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0FBED4 802D7524 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FBED8 802D7528 0080882D */  daddu $s1, $a0, $zero
/* 0FBEDC 802D752C AFBF0020 */  sw    $ra, 0x20($sp)
/* 0FBEE0 802D7530 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FBEE4 802D7534 F7B80038 */  sdc1  $f24, 0x38($sp)
/* 0FBEE8 802D7538 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 0FBEEC 802D753C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0FBEF0 802D7540 8E30000C */  lw    $s0, 0xc($s1)
/* 0FBEF4 802D7544 8E050000 */  lw    $a1, ($s0)
/* 0FBEF8 802D7548 0C0B210B */  jal   get_float_variable
/* 0FBEFC 802D754C 26100004 */   addiu $s0, $s0, 4
/* 0FBF00 802D7550 8E050000 */  lw    $a1, ($s0)
/* 0FBF04 802D7554 26100004 */  addiu $s0, $s0, 4
/* 0FBF08 802D7558 0220202D */  daddu $a0, $s1, $zero
/* 0FBF0C 802D755C 0C0B210B */  jal   get_float_variable
/* 0FBF10 802D7560 46000606 */   mov.s $f24, $f0
/* 0FBF14 802D7564 8E050000 */  lw    $a1, ($s0)
/* 0FBF18 802D7568 26100004 */  addiu $s0, $s0, 4
/* 0FBF1C 802D756C 0220202D */  daddu $a0, $s1, $zero
/* 0FBF20 802D7570 0C0B210B */  jal   get_float_variable
/* 0FBF24 802D7574 46000586 */   mov.s $f22, $f0
/* 0FBF28 802D7578 0220202D */  daddu $a0, $s1, $zero
/* 0FBF2C 802D757C 8E050000 */  lw    $a1, ($s0)
/* 0FBF30 802D7580 0C0B1EAF */  jal   get_variable
/* 0FBF34 802D7584 46000506 */   mov.s $f20, $f0
/* 0FBF38 802D7588 0040382D */  daddu $a3, $v0, $zero
/* 0FBF3C 802D758C 4600C306 */  mov.s $f12, $f24
/* 0FBF40 802D7590 4406A000 */  mfc1  $a2, $f20
/* 0FBF44 802D7594 0C0B5D18 */  jal   func_802D7460
/* 0FBF48 802D7598 4600B386 */   mov.s $f14, $f22
/* 0FBF4C 802D759C 24042055 */  addiu $a0, $zero, 0x2055
/* 0FBF50 802D75A0 4406C000 */  mfc1  $a2, $f24
/* 0FBF54 802D75A4 4407B000 */  mfc1  $a3, $f22
/* 0FBF58 802D75A8 0000282D */  daddu $a1, $zero, $zero
/* 0FBF5C 802D75AC 0C052757 */  jal   play_sound_at_position
/* 0FBF60 802D75B0 E7B40010 */   swc1  $f20, 0x10($sp)
/* 0FBF64 802D75B4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0FBF68 802D75B8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FBF6C 802D75BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FBF70 802D75C0 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 0FBF74 802D75C4 D7B60030 */  ldc1  $f22, 0x30($sp)
/* 0FBF78 802D75C8 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0FBF7C 802D75CC 24020002 */  addiu $v0, $zero, 2
/* 0FBF80 802D75D0 03E00008 */  jr    $ra
/* 0FBF84 802D75D4 27BD0040 */   addiu $sp, $sp, 0x40

/* 0FBF88 802D75D8 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0FBF8C 802D75DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FBF90 802D75E0 0080882D */  daddu $s1, $a0, $zero
/* 0FBF94 802D75E4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0FBF98 802D75E8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FBF9C 802D75EC F7B80038 */  sdc1  $f24, 0x38($sp)
/* 0FBFA0 802D75F0 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 0FBFA4 802D75F4 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0FBFA8 802D75F8 8E30000C */  lw    $s0, 0xc($s1)
/* 0FBFAC 802D75FC 8E050000 */  lw    $a1, ($s0)
/* 0FBFB0 802D7600 0C0B210B */  jal   get_float_variable
/* 0FBFB4 802D7604 26100004 */   addiu $s0, $s0, 4
/* 0FBFB8 802D7608 8E050000 */  lw    $a1, ($s0)
/* 0FBFBC 802D760C 26100004 */  addiu $s0, $s0, 4
/* 0FBFC0 802D7610 0220202D */  daddu $a0, $s1, $zero
/* 0FBFC4 802D7614 0C0B210B */  jal   get_float_variable
/* 0FBFC8 802D7618 46000606 */   mov.s $f24, $f0
/* 0FBFCC 802D761C 8E050000 */  lw    $a1, ($s0)
/* 0FBFD0 802D7620 26100004 */  addiu $s0, $s0, 4
/* 0FBFD4 802D7624 0220202D */  daddu $a0, $s1, $zero
/* 0FBFD8 802D7628 0C0B210B */  jal   get_float_variable
/* 0FBFDC 802D762C 46000586 */   mov.s $f22, $f0
/* 0FBFE0 802D7630 0220202D */  daddu $a0, $s1, $zero
/* 0FBFE4 802D7634 8E050000 */  lw    $a1, ($s0)
/* 0FBFE8 802D7638 0C0B1EAF */  jal   get_variable
/* 0FBFEC 802D763C 46000506 */   mov.s $f20, $f0
/* 0FBFF0 802D7640 0040382D */  daddu $a3, $v0, $zero
/* 0FBFF4 802D7644 4600C306 */  mov.s $f12, $f24
/* 0FBFF8 802D7648 4406A000 */  mfc1  $a2, $f20
/* 0FBFFC 802D764C 0C0B5D30 */  jal   func_802D74C0
/* 0FC000 802D7650 4600B386 */   mov.s $f14, $f22
/* 0FC004 802D7654 24040378 */  addiu $a0, $zero, 0x378
/* 0FC008 802D7658 4406C000 */  mfc1  $a2, $f24
/* 0FC00C 802D765C 4407B000 */  mfc1  $a3, $f22
/* 0FC010 802D7660 0000282D */  daddu $a1, $zero, $zero
/* 0FC014 802D7664 0C052757 */  jal   play_sound_at_position
/* 0FC018 802D7668 E7B40010 */   swc1  $f20, 0x10($sp)
/* 0FC01C 802D766C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0FC020 802D7670 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FC024 802D7674 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FC028 802D7678 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 0FC02C 802D767C D7B60030 */  ldc1  $f22, 0x30($sp)
/* 0FC030 802D7680 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0FC034 802D7684 24020002 */  addiu $v0, $zero, 2
/* 0FC038 802D7688 03E00008 */  jr    $ra
/* 0FC03C 802D768C 27BD0040 */   addiu $sp, $sp, 0x40

/* 0FC040 802D7690 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0FC044 802D7694 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FC048 802D7698 0080902D */  daddu $s2, $a0, $zero
/* 0FC04C 802D769C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FC050 802D76A0 00A0882D */  daddu $s1, $a1, $zero
/* 0FC054 802D76A4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0FC058 802D76A8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FC05C 802D76AC F7BE0050 */  sdc1  $f30, 0x50($sp)
/* 0FC060 802D76B0 F7BC0048 */  sdc1  $f28, 0x48($sp)
/* 0FC064 802D76B4 F7BA0040 */  sdc1  $f26, 0x40($sp)
/* 0FC068 802D76B8 F7B80038 */  sdc1  $f24, 0x38($sp)
/* 0FC06C 802D76BC F7B60030 */  sdc1  $f22, 0x30($sp)
/* 0FC070 802D76C0 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0FC074 802D76C4 8E50000C */  lw    $s0, 0xc($s2)
/* 0FC078 802D76C8 8E050000 */  lw    $a1, ($s0)
/* 0FC07C 802D76CC 0C0B210B */  jal   get_float_variable
/* 0FC080 802D76D0 26100004 */   addiu $s0, $s0, 4
/* 0FC084 802D76D4 8E050000 */  lw    $a1, ($s0)
/* 0FC088 802D76D8 26100004 */  addiu $s0, $s0, 4
/* 0FC08C 802D76DC 0240202D */  daddu $a0, $s2, $zero
/* 0FC090 802D76E0 0C0B210B */  jal   get_float_variable
/* 0FC094 802D76E4 E7A00010 */   swc1  $f0, 0x10($sp)
/* 0FC098 802D76E8 8E050000 */  lw    $a1, ($s0)
/* 0FC09C 802D76EC 26100004 */  addiu $s0, $s0, 4
/* 0FC0A0 802D76F0 0240202D */  daddu $a0, $s2, $zero
/* 0FC0A4 802D76F4 0C0B210B */  jal   get_float_variable
/* 0FC0A8 802D76F8 46000786 */   mov.s $f30, $f0
/* 0FC0AC 802D76FC 8E050000 */  lw    $a1, ($s0)
/* 0FC0B0 802D7700 26100004 */  addiu $s0, $s0, 4
/* 0FC0B4 802D7704 0240202D */  daddu $a0, $s2, $zero
/* 0FC0B8 802D7708 0C0B210B */  jal   get_float_variable
/* 0FC0BC 802D770C E7A00014 */   swc1  $f0, 0x14($sp)
/* 0FC0C0 802D7710 8E050000 */  lw    $a1, ($s0)
/* 0FC0C4 802D7714 26100004 */  addiu $s0, $s0, 4
/* 0FC0C8 802D7718 0240202D */  daddu $a0, $s2, $zero
/* 0FC0CC 802D771C 0C0B210B */  jal   get_float_variable
/* 0FC0D0 802D7720 46000586 */   mov.s $f22, $f0
/* 0FC0D4 802D7724 0240202D */  daddu $a0, $s2, $zero
/* 0FC0D8 802D7728 8E050000 */  lw    $a1, ($s0)
/* 0FC0DC 802D772C 0C0B1EAF */  jal   get_variable
/* 0FC0E0 802D7730 46000706 */   mov.s $f28, $f0
/* 0FC0E4 802D7734 12200002 */  beqz  $s1, .L802D7740
/* 0FC0E8 802D7738 0040802D */   daddu $s0, $v0, $zero
/* 0FC0EC 802D773C AE400070 */  sw    $zero, 0x70($s2)
.L802D7740:
/* 0FC0F0 802D7740 0C00A67F */  jal   rand_int
/* 0FC0F4 802D7744 2404000A */   addiu $a0, $zero, 0xa
/* 0FC0F8 802D7748 2442FFFB */  addiu $v0, $v0, -5
/* 0FC0FC 802D774C 4482D000 */  mtc1  $v0, $f26
/* 0FC100 802D7750 00000000 */  nop   
/* 0FC104 802D7754 4680D6A0 */  cvt.s.w $f26, $f26
/* 0FC108 802D7758 0C00A67F */  jal   rand_int
/* 0FC10C 802D775C 2404000A */   addiu $a0, $zero, 0xa
/* 0FC110 802D7760 461AD082 */  mul.s $f2, $f26, $f26
/* 0FC114 802D7764 00000000 */  nop   
/* 0FC118 802D7768 2442FFFB */  addiu $v0, $v0, -5
/* 0FC11C 802D776C 4482C000 */  mtc1  $v0, $f24
/* 0FC120 802D7770 00000000 */  nop   
/* 0FC124 802D7774 4680C620 */  cvt.s.w $f24, $f24
/* 0FC128 802D7778 4618C102 */  mul.s $f4, $f24, $f24
/* 0FC12C 802D777C 00000000 */  nop   
/* 0FC130 802D7780 3C0140C9 */  lui   $at, 0x40c9
/* 0FC134 802D7784 34210FD0 */  ori   $at, $at, 0xfd0
/* 0FC138 802D7788 4481A000 */  mtc1  $at, $f20
/* 0FC13C 802D778C 00000000 */  nop   
/* 0FC140 802D7790 4614B502 */  mul.s $f20, $f22, $f20
/* 0FC144 802D7794 00000000 */  nop   
/* 0FC148 802D7798 3C0143B4 */  lui   $at, 0x43b4
/* 0FC14C 802D779C 44810000 */  mtc1  $at, $f0
/* 0FC150 802D77A0 3C01C000 */  lui   $at, 0xc000
/* 0FC154 802D77A4 4481B000 */  mtc1  $at, $f22
/* 0FC158 802D77A8 46041080 */  add.s $f2, $f2, $f4
/* 0FC15C 802D77AC 4600A503 */  div.s $f20, $f20, $f0
/* 0FC160 802D77B0 3C0140A0 */  lui   $at, 0x40a0
/* 0FC164 802D77B4 44810000 */  mtc1  $at, $f0
/* 0FC168 802D77B8 4600A306 */  mov.s $f12, $f20
/* 0FC16C 802D77BC 46001083 */  div.s $f2, $f2, $f0
/* 0FC170 802D77C0 0C00A85B */  jal   sin_rad
/* 0FC174 802D77C4 4602B581 */   sub.s $f22, $f22, $f2
/* 0FC178 802D77C8 4600A306 */  mov.s $f12, $f20
/* 0FC17C 802D77CC 0C00A874 */  jal   cos_rad
/* 0FC180 802D77D0 46000506 */   mov.s $f20, $f0
/* 0FC184 802D77D4 461CA502 */  mul.s $f20, $f20, $f28
/* 0FC188 802D77D8 00000000 */  nop   
/* 0FC18C 802D77DC 46000007 */  neg.s $f0, $f0
/* 0FC190 802D77E0 461C0002 */  mul.s $f0, $f0, $f28
/* 0FC194 802D77E4 00000000 */  nop   
/* 0FC198 802D77E8 C6420070 */  lwc1  $f2, 0x70($s2)
/* 0FC19C 802D77EC 468010A0 */  cvt.s.w $f2, $f2
/* 0FC1A0 802D77F0 4602A502 */  mul.s $f20, $f20, $f2
/* 0FC1A4 802D77F4 00000000 */  nop   
/* 0FC1A8 802D77F8 46020002 */  mul.s $f0, $f0, $f2
/* 0FC1AC 802D77FC 00000000 */  nop   
/* 0FC1B0 802D7800 3C014178 */  lui   $at, 0x4178
/* 0FC1B4 802D7804 44811000 */  mtc1  $at, $f2
/* 0FC1B8 802D7808 00000000 */  nop   
/* 0FC1BC 802D780C 4602F080 */  add.s $f2, $f30, $f2
/* 0FC1C0 802D7810 46161080 */  add.s $f2, $f2, $f22
/* 0FC1C4 802D7814 C7A60010 */  lwc1  $f6, 0x10($sp)
/* 0FC1C8 802D7818 44051000 */  mfc1  $a1, $f2
/* 0FC1CC 802D781C 44901000 */  mtc1  $s0, $f2
/* 0FC1D0 802D7820 00000000 */  nop   
/* 0FC1D4 802D7824 468010A0 */  cvt.s.w $f2, $f2
/* 0FC1D8 802D7828 4602A503 */  div.s $f20, $f20, $f2
/* 0FC1DC 802D782C 46143500 */  add.s $f20, $f6, $f20
/* 0FC1E0 802D7830 C7A60014 */  lwc1  $f6, 0x14($sp)
/* 0FC1E4 802D7834 46020003 */  div.s $f0, $f0, $f2
/* 0FC1E8 802D7838 46003000 */  add.s $f0, $f6, $f0
/* 0FC1EC 802D783C 46180000 */  add.s $f0, $f0, $f24
/* 0FC1F0 802D7840 461AA500 */  add.s $f20, $f20, $f26
/* 0FC1F4 802D7844 44060000 */  mfc1  $a2, $f0
/* 0FC1F8 802D7848 4600A18D */  trunc.w.s $f6, $f20
/* 0FC1FC 802D784C 44043000 */  mfc1  $a0, $f6
/* 0FC200 802D7850 0C01BF2C */  jal   func_8006FCB0
/* 0FC204 802D7854 0000382D */   daddu $a3, $zero, $zero
/* 0FC208 802D7858 8E430070 */  lw    $v1, 0x70($s2)
/* 0FC20C 802D785C 24630001 */  addiu $v1, $v1, 1
/* 0FC210 802D7860 0070102A */  slt   $v0, $v1, $s0
/* 0FC214 802D7864 38420001 */  xori  $v0, $v0, 1
/* 0FC218 802D7868 AE430070 */  sw    $v1, 0x70($s2)
/* 0FC21C 802D786C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0FC220 802D7870 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FC224 802D7874 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FC228 802D7878 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FC22C 802D787C D7BE0050 */  ldc1  $f30, 0x50($sp)
/* 0FC230 802D7880 D7BC0048 */  ldc1  $f28, 0x48($sp)
/* 0FC234 802D7884 D7BA0040 */  ldc1  $f26, 0x40($sp)
/* 0FC238 802D7888 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 0FC23C 802D788C D7B60030 */  ldc1  $f22, 0x30($sp)
/* 0FC240 802D7890 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0FC244 802D7894 00021040 */  sll   $v0, $v0, 1
/* 0FC248 802D7898 03E00008 */  jr    $ra
/* 0FC24C 802D789C 27BD0058 */   addiu $sp, $sp, 0x58

