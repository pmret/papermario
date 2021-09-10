.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7690
/* FC040 802D7690 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* FC044 802D7694 AFB20020 */  sw        $s2, 0x20($sp)
/* FC048 802D7698 0080902D */  daddu     $s2, $a0, $zero
/* FC04C 802D769C AFB1001C */  sw        $s1, 0x1c($sp)
/* FC050 802D76A0 00A0882D */  daddu     $s1, $a1, $zero
/* FC054 802D76A4 AFBF0024 */  sw        $ra, 0x24($sp)
/* FC058 802D76A8 AFB00018 */  sw        $s0, 0x18($sp)
/* FC05C 802D76AC F7BE0050 */  sdc1      $f30, 0x50($sp)
/* FC060 802D76B0 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* FC064 802D76B4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* FC068 802D76B8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* FC06C 802D76BC F7B60030 */  sdc1      $f22, 0x30($sp)
/* FC070 802D76C0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* FC074 802D76C4 8E50000C */  lw        $s0, 0xc($s2)
/* FC078 802D76C8 8E050000 */  lw        $a1, ($s0)
/* FC07C 802D76CC 0C0B210B */  jal       evt_get_float_variable
/* FC080 802D76D0 26100004 */   addiu    $s0, $s0, 4
/* FC084 802D76D4 8E050000 */  lw        $a1, ($s0)
/* FC088 802D76D8 26100004 */  addiu     $s0, $s0, 4
/* FC08C 802D76DC 0240202D */  daddu     $a0, $s2, $zero
/* FC090 802D76E0 0C0B210B */  jal       evt_get_float_variable
/* FC094 802D76E4 E7A00010 */   swc1     $f0, 0x10($sp)
/* FC098 802D76E8 8E050000 */  lw        $a1, ($s0)
/* FC09C 802D76EC 26100004 */  addiu     $s0, $s0, 4
/* FC0A0 802D76F0 0240202D */  daddu     $a0, $s2, $zero
/* FC0A4 802D76F4 0C0B210B */  jal       evt_get_float_variable
/* FC0A8 802D76F8 46000786 */   mov.s    $f30, $f0
/* FC0AC 802D76FC 8E050000 */  lw        $a1, ($s0)
/* FC0B0 802D7700 26100004 */  addiu     $s0, $s0, 4
/* FC0B4 802D7704 0240202D */  daddu     $a0, $s2, $zero
/* FC0B8 802D7708 0C0B210B */  jal       evt_get_float_variable
/* FC0BC 802D770C E7A00014 */   swc1     $f0, 0x14($sp)
/* FC0C0 802D7710 8E050000 */  lw        $a1, ($s0)
/* FC0C4 802D7714 26100004 */  addiu     $s0, $s0, 4
/* FC0C8 802D7718 0240202D */  daddu     $a0, $s2, $zero
/* FC0CC 802D771C 0C0B210B */  jal       evt_get_float_variable
/* FC0D0 802D7720 46000586 */   mov.s    $f22, $f0
/* FC0D4 802D7724 0240202D */  daddu     $a0, $s2, $zero
/* FC0D8 802D7728 8E050000 */  lw        $a1, ($s0)
/* FC0DC 802D772C 0C0B1EAF */  jal       evt_get_variable
/* FC0E0 802D7730 46000706 */   mov.s    $f28, $f0
/* FC0E4 802D7734 12200002 */  beqz      $s1, .L802D7740
/* FC0E8 802D7738 0040802D */   daddu    $s0, $v0, $zero
/* FC0EC 802D773C AE400070 */  sw        $zero, 0x70($s2)
.L802D7740:
/* FC0F0 802D7740 0C00A67F */  jal       rand_int
/* FC0F4 802D7744 2404000A */   addiu    $a0, $zero, 0xa
/* FC0F8 802D7748 2442FFFB */  addiu     $v0, $v0, -5
/* FC0FC 802D774C 4482D000 */  mtc1      $v0, $f26
/* FC100 802D7750 00000000 */  nop
/* FC104 802D7754 4680D6A0 */  cvt.s.w   $f26, $f26
/* FC108 802D7758 0C00A67F */  jal       rand_int
/* FC10C 802D775C 2404000A */   addiu    $a0, $zero, 0xa
/* FC110 802D7760 461AD082 */  mul.s     $f2, $f26, $f26
/* FC114 802D7764 00000000 */  nop
/* FC118 802D7768 2442FFFB */  addiu     $v0, $v0, -5
/* FC11C 802D776C 4482C000 */  mtc1      $v0, $f24
/* FC120 802D7770 00000000 */  nop
/* FC124 802D7774 4680C620 */  cvt.s.w   $f24, $f24
/* FC128 802D7778 4618C102 */  mul.s     $f4, $f24, $f24
/* FC12C 802D777C 00000000 */  nop
/* FC130 802D7780 3C0140C9 */  lui       $at, 0x40c9
/* FC134 802D7784 34210FD0 */  ori       $at, $at, 0xfd0
/* FC138 802D7788 4481A000 */  mtc1      $at, $f20
/* FC13C 802D778C 00000000 */  nop
/* FC140 802D7790 4614B502 */  mul.s     $f20, $f22, $f20
/* FC144 802D7794 00000000 */  nop
/* FC148 802D7798 3C0143B4 */  lui       $at, 0x43b4
/* FC14C 802D779C 44810000 */  mtc1      $at, $f0
/* FC150 802D77A0 3C01C000 */  lui       $at, 0xc000
/* FC154 802D77A4 4481B000 */  mtc1      $at, $f22
/* FC158 802D77A8 46041080 */  add.s     $f2, $f2, $f4
/* FC15C 802D77AC 4600A503 */  div.s     $f20, $f20, $f0
/* FC160 802D77B0 3C0140A0 */  lui       $at, 0x40a0
/* FC164 802D77B4 44810000 */  mtc1      $at, $f0
/* FC168 802D77B8 4600A306 */  mov.s     $f12, $f20
/* FC16C 802D77BC 46001083 */  div.s     $f2, $f2, $f0
/* FC170 802D77C0 0C00A85B */  jal       sin_rad
/* FC174 802D77C4 4602B581 */   sub.s    $f22, $f22, $f2
/* FC178 802D77C8 4600A306 */  mov.s     $f12, $f20
/* FC17C 802D77CC 0C00A874 */  jal       cos_rad
/* FC180 802D77D0 46000506 */   mov.s    $f20, $f0
/* FC184 802D77D4 461CA502 */  mul.s     $f20, $f20, $f28
/* FC188 802D77D8 00000000 */  nop
/* FC18C 802D77DC 46000007 */  neg.s     $f0, $f0
/* FC190 802D77E0 461C0002 */  mul.s     $f0, $f0, $f28
/* FC194 802D77E4 00000000 */  nop
/* FC198 802D77E8 C6420070 */  lwc1      $f2, 0x70($s2)
/* FC19C 802D77EC 468010A0 */  cvt.s.w   $f2, $f2
/* FC1A0 802D77F0 4602A502 */  mul.s     $f20, $f20, $f2
/* FC1A4 802D77F4 00000000 */  nop
/* FC1A8 802D77F8 46020002 */  mul.s     $f0, $f0, $f2
/* FC1AC 802D77FC 00000000 */  nop
/* FC1B0 802D7800 3C014178 */  lui       $at, 0x4178
/* FC1B4 802D7804 44811000 */  mtc1      $at, $f2
/* FC1B8 802D7808 00000000 */  nop
/* FC1BC 802D780C 4602F080 */  add.s     $f2, $f30, $f2
/* FC1C0 802D7810 46161080 */  add.s     $f2, $f2, $f22
/* FC1C4 802D7814 C7A60010 */  lwc1      $f6, 0x10($sp)
/* FC1C8 802D7818 44051000 */  mfc1      $a1, $f2
/* FC1CC 802D781C 44901000 */  mtc1      $s0, $f2
/* FC1D0 802D7820 00000000 */  nop
/* FC1D4 802D7824 468010A0 */  cvt.s.w   $f2, $f2
/* FC1D8 802D7828 4602A503 */  div.s     $f20, $f20, $f2
/* FC1DC 802D782C 46143500 */  add.s     $f20, $f6, $f20
/* FC1E0 802D7830 C7A60014 */  lwc1      $f6, 0x14($sp)
/* FC1E4 802D7834 46020003 */  div.s     $f0, $f0, $f2
/* FC1E8 802D7838 46003000 */  add.s     $f0, $f6, $f0
/* FC1EC 802D783C 46180000 */  add.s     $f0, $f0, $f24
/* FC1F0 802D7840 461AA500 */  add.s     $f20, $f20, $f26
/* FC1F4 802D7844 44060000 */  mfc1      $a2, $f0
/* FC1F8 802D7848 4600A18D */  trunc.w.s $f6, $f20
/* FC1FC 802D784C 44043000 */  mfc1      $a0, $f6
/* FC200 802D7850 0C01BF2C */  jal       playFX_0B
/* FC204 802D7854 0000382D */   daddu    $a3, $zero, $zero
/* FC208 802D7858 8E430070 */  lw        $v1, 0x70($s2)
/* FC20C 802D785C 24630001 */  addiu     $v1, $v1, 1
/* FC210 802D7860 0070102A */  slt       $v0, $v1, $s0
/* FC214 802D7864 38420001 */  xori      $v0, $v0, 1
/* FC218 802D7868 AE430070 */  sw        $v1, 0x70($s2)
/* FC21C 802D786C 8FBF0024 */  lw        $ra, 0x24($sp)
/* FC220 802D7870 8FB20020 */  lw        $s2, 0x20($sp)
/* FC224 802D7874 8FB1001C */  lw        $s1, 0x1c($sp)
/* FC228 802D7878 8FB00018 */  lw        $s0, 0x18($sp)
/* FC22C 802D787C D7BE0050 */  ldc1      $f30, 0x50($sp)
/* FC230 802D7880 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* FC234 802D7884 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* FC238 802D7888 D7B80038 */  ldc1      $f24, 0x38($sp)
/* FC23C 802D788C D7B60030 */  ldc1      $f22, 0x30($sp)
/* FC240 802D7890 D7B40028 */  ldc1      $f20, 0x28($sp)
/* FC244 802D7894 00021040 */  sll       $v0, $v0, 1
/* FC248 802D7898 03E00008 */  jr        $ra
/* FC24C 802D789C 27BD0058 */   addiu    $sp, $sp, 0x58
