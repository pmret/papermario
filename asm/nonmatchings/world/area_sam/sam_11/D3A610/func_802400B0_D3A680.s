.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_D3A680
/* D3A680 802400B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* D3A684 802400B4 AFB10054 */  sw        $s1, 0x54($sp)
/* D3A688 802400B8 0080882D */  daddu     $s1, $a0, $zero
/* D3A68C 802400BC AFBF005C */  sw        $ra, 0x5c($sp)
/* D3A690 802400C0 AFB20058 */  sw        $s2, 0x58($sp)
/* D3A694 802400C4 AFB00050 */  sw        $s0, 0x50($sp)
/* D3A698 802400C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* D3A69C 802400CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* D3A6A0 802400D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* D3A6A4 802400D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* D3A6A8 802400D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* D3A6AC 802400DC 8E30000C */  lw        $s0, 0xc($s1)
/* D3A6B0 802400E0 8E050000 */  lw        $a1, ($s0)
/* D3A6B4 802400E4 0C0B1EAF */  jal       get_variable
/* D3A6B8 802400E8 26100004 */   addiu    $s0, $s0, 4
/* D3A6BC 802400EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D3A6C0 802400F0 0040202D */   daddu    $a0, $v0, $zero
/* D3A6C4 802400F4 8E050000 */  lw        $a1, ($s0)
/* D3A6C8 802400F8 26100004 */  addiu     $s0, $s0, 4
/* D3A6CC 802400FC 0220202D */  daddu     $a0, $s1, $zero
/* D3A6D0 80240100 0C0B210B */  jal       get_float_variable
/* D3A6D4 80240104 0040902D */   daddu    $s2, $v0, $zero
/* D3A6D8 80240108 8E050000 */  lw        $a1, ($s0)
/* D3A6DC 8024010C 26100004 */  addiu     $s0, $s0, 4
/* D3A6E0 80240110 0220202D */  daddu     $a0, $s1, $zero
/* D3A6E4 80240114 0C0B210B */  jal       get_float_variable
/* D3A6E8 80240118 46000706 */   mov.s    $f28, $f0
/* D3A6EC 8024011C 8E050000 */  lw        $a1, ($s0)
/* D3A6F0 80240120 26100004 */  addiu     $s0, $s0, 4
/* D3A6F4 80240124 0220202D */  daddu     $a0, $s1, $zero
/* D3A6F8 80240128 0C0B210B */  jal       get_float_variable
/* D3A6FC 8024012C 46000686 */   mov.s    $f26, $f0
/* D3A700 80240130 0220202D */  daddu     $a0, $s1, $zero
/* D3A704 80240134 8E050000 */  lw        $a1, ($s0)
/* D3A708 80240138 0C0B210B */  jal       get_float_variable
/* D3A70C 8024013C 46000586 */   mov.s    $f22, $f0
/* D3A710 80240140 0240202D */  daddu     $a0, $s2, $zero
/* D3A714 80240144 0C046B4C */  jal       get_model_from_list_index
/* D3A718 80240148 46000606 */   mov.s    $f24, $f0
/* D3A71C 8024014C 0040882D */  daddu     $s1, $v0, $zero
/* D3A720 80240150 96220000 */  lhu       $v0, ($s1)
/* D3A724 80240154 30420400 */  andi      $v0, $v0, 0x400
/* D3A728 80240158 1440001E */  bnez      $v0, .L802401D4
/* D3A72C 8024015C 26300058 */   addiu    $s0, $s1, 0x58
/* D3A730 80240160 4480A000 */  mtc1      $zero, $f20
/* D3A734 80240164 4406B000 */  mfc1      $a2, $f22
/* D3A738 80240168 4405A000 */  mfc1      $a1, $f20
/* D3A73C 8024016C 4407A000 */  mfc1      $a3, $f20
/* D3A740 80240170 0C019E40 */  jal       guTranslateF
/* D3A744 80240174 0200202D */   daddu    $a0, $s0, $zero
/* D3A748 80240178 4405E000 */  mfc1      $a1, $f28
/* D3A74C 8024017C 4406D000 */  mfc1      $a2, $f26
/* D3A750 80240180 4407C000 */  mfc1      $a3, $f24
/* D3A754 80240184 0C090010 */  jal       func_80240040
/* D3A758 80240188 27A40010 */   addiu    $a0, $sp, 0x10
/* D3A75C 8024018C 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A760 80240190 0200282D */  daddu     $a1, $s0, $zero
/* D3A764 80240194 0C019D80 */  jal       guMtxCatF
/* D3A768 80240198 0200302D */   daddu    $a2, $s0, $zero
/* D3A76C 8024019C 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A770 802401A0 4600B587 */  neg.s     $f22, $f22
/* D3A774 802401A4 4405A000 */  mfc1      $a1, $f20
/* D3A778 802401A8 4406B000 */  mfc1      $a2, $f22
/* D3A77C 802401AC 0C019E40 */  jal       guTranslateF
/* D3A780 802401B0 00A0382D */   daddu    $a3, $a1, $zero
/* D3A784 802401B4 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A788 802401B8 0200282D */  daddu     $a1, $s0, $zero
/* D3A78C 802401BC 0C019D80 */  jal       guMtxCatF
/* D3A790 802401C0 00A0302D */   daddu    $a2, $a1, $zero
/* D3A794 802401C4 96220000 */  lhu       $v0, ($s1)
/* D3A798 802401C8 34421400 */  ori       $v0, $v0, 0x1400
/* D3A79C 802401CC 08090093 */  j         .L8024024C
/* D3A7A0 802401D0 A6220000 */   sh       $v0, ($s1)
.L802401D4:
/* D3A7A4 802401D4 4480A000 */  mtc1      $zero, $f20
/* D3A7A8 802401D8 4406B000 */  mfc1      $a2, $f22
/* D3A7AC 802401DC 4405A000 */  mfc1      $a1, $f20
/* D3A7B0 802401E0 4407A000 */  mfc1      $a3, $f20
/* D3A7B4 802401E4 0C019E40 */  jal       guTranslateF
/* D3A7B8 802401E8 27A40010 */   addiu    $a0, $sp, 0x10
/* D3A7BC 802401EC 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A7C0 802401F0 26300058 */  addiu     $s0, $s1, 0x58
/* D3A7C4 802401F4 0200282D */  daddu     $a1, $s0, $zero
/* D3A7C8 802401F8 0C019D80 */  jal       guMtxCatF
/* D3A7CC 802401FC 0200302D */   daddu    $a2, $s0, $zero
/* D3A7D0 80240200 4405E000 */  mfc1      $a1, $f28
/* D3A7D4 80240204 4406D000 */  mfc1      $a2, $f26
/* D3A7D8 80240208 4407C000 */  mfc1      $a3, $f24
/* D3A7DC 8024020C 0C090010 */  jal       func_80240040
/* D3A7E0 80240210 27A40010 */   addiu    $a0, $sp, 0x10
/* D3A7E4 80240214 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A7E8 80240218 0200282D */  daddu     $a1, $s0, $zero
/* D3A7EC 8024021C 0C019D80 */  jal       guMtxCatF
/* D3A7F0 80240220 0200302D */   daddu    $a2, $s0, $zero
/* D3A7F4 80240224 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A7F8 80240228 4600B587 */  neg.s     $f22, $f22
/* D3A7FC 8024022C 4405A000 */  mfc1      $a1, $f20
/* D3A800 80240230 4406B000 */  mfc1      $a2, $f22
/* D3A804 80240234 0C019E40 */  jal       guTranslateF
/* D3A808 80240238 00A0382D */   daddu    $a3, $a1, $zero
/* D3A80C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A810 80240240 0200282D */  daddu     $a1, $s0, $zero
/* D3A814 80240244 0C019D80 */  jal       guMtxCatF
/* D3A818 80240248 00A0302D */   daddu    $a2, $a1, $zero
.L8024024C:
/* D3A81C 8024024C 8FBF005C */  lw        $ra, 0x5c($sp)
/* D3A820 80240250 8FB20058 */  lw        $s2, 0x58($sp)
/* D3A824 80240254 8FB10054 */  lw        $s1, 0x54($sp)
/* D3A828 80240258 8FB00050 */  lw        $s0, 0x50($sp)
/* D3A82C 8024025C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* D3A830 80240260 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* D3A834 80240264 D7B80070 */  ldc1      $f24, 0x70($sp)
/* D3A838 80240268 D7B60068 */  ldc1      $f22, 0x68($sp)
/* D3A83C 8024026C D7B40060 */  ldc1      $f20, 0x60($sp)
/* D3A840 80240270 24020002 */  addiu     $v0, $zero, 2
/* D3A844 80240274 03E00008 */  jr        $ra
/* D3A848 80240278 27BD0088 */   addiu    $sp, $sp, 0x88
/* D3A84C 8024027C 00000000 */  nop       
