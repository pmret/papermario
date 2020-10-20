.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_D13640
/* D13640 80240070 27BDFF78 */  addiu     $sp, $sp, -0x88
/* D13644 80240074 AFB10054 */  sw        $s1, 0x54($sp)
/* D13648 80240078 0080882D */  daddu     $s1, $a0, $zero
/* D1364C 8024007C AFBF005C */  sw        $ra, 0x5c($sp)
/* D13650 80240080 AFB20058 */  sw        $s2, 0x58($sp)
/* D13654 80240084 AFB00050 */  sw        $s0, 0x50($sp)
/* D13658 80240088 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* D1365C 8024008C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* D13660 80240090 F7B80070 */  sdc1      $f24, 0x70($sp)
/* D13664 80240094 F7B60068 */  sdc1      $f22, 0x68($sp)
/* D13668 80240098 F7B40060 */  sdc1      $f20, 0x60($sp)
/* D1366C 8024009C 8E30000C */  lw        $s0, 0xc($s1)
/* D13670 802400A0 8E050000 */  lw        $a1, ($s0)
/* D13674 802400A4 0C0B1EAF */  jal       get_variable
/* D13678 802400A8 26100004 */   addiu    $s0, $s0, 4
/* D1367C 802400AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D13680 802400B0 0040202D */   daddu    $a0, $v0, $zero
/* D13684 802400B4 8E050000 */  lw        $a1, ($s0)
/* D13688 802400B8 26100004 */  addiu     $s0, $s0, 4
/* D1368C 802400BC 0220202D */  daddu     $a0, $s1, $zero
/* D13690 802400C0 0C0B210B */  jal       get_float_variable
/* D13694 802400C4 0040902D */   daddu    $s2, $v0, $zero
/* D13698 802400C8 8E050000 */  lw        $a1, ($s0)
/* D1369C 802400CC 26100004 */  addiu     $s0, $s0, 4
/* D136A0 802400D0 0220202D */  daddu     $a0, $s1, $zero
/* D136A4 802400D4 0C0B210B */  jal       get_float_variable
/* D136A8 802400D8 46000706 */   mov.s    $f28, $f0
/* D136AC 802400DC 8E050000 */  lw        $a1, ($s0)
/* D136B0 802400E0 26100004 */  addiu     $s0, $s0, 4
/* D136B4 802400E4 0220202D */  daddu     $a0, $s1, $zero
/* D136B8 802400E8 0C0B210B */  jal       get_float_variable
/* D136BC 802400EC 46000686 */   mov.s    $f26, $f0
/* D136C0 802400F0 0220202D */  daddu     $a0, $s1, $zero
/* D136C4 802400F4 8E050000 */  lw        $a1, ($s0)
/* D136C8 802400F8 0C0B210B */  jal       get_float_variable
/* D136CC 802400FC 46000586 */   mov.s    $f22, $f0
/* D136D0 80240100 0240202D */  daddu     $a0, $s2, $zero
/* D136D4 80240104 0C046B4C */  jal       get_model_from_list_index
/* D136D8 80240108 46000606 */   mov.s    $f24, $f0
/* D136DC 8024010C 0040882D */  daddu     $s1, $v0, $zero
/* D136E0 80240110 96220000 */  lhu       $v0, ($s1)
/* D136E4 80240114 30420400 */  andi      $v0, $v0, 0x400
/* D136E8 80240118 1440001E */  bnez      $v0, .L80240194
/* D136EC 8024011C 26300058 */   addiu    $s0, $s1, 0x58
/* D136F0 80240120 4480A000 */  mtc1      $zero, $f20
/* D136F4 80240124 4406B000 */  mfc1      $a2, $f22
/* D136F8 80240128 4405A000 */  mfc1      $a1, $f20
/* D136FC 8024012C 4407A000 */  mfc1      $a3, $f20
/* D13700 80240130 0C019E40 */  jal       guTranslateF
/* D13704 80240134 0200202D */   daddu    $a0, $s0, $zero
/* D13708 80240138 4405E000 */  mfc1      $a1, $f28
/* D1370C 8024013C 4406D000 */  mfc1      $a2, $f26
/* D13710 80240140 4407C000 */  mfc1      $a3, $f24
/* D13714 80240144 0C090000 */  jal       func_80240000
/* D13718 80240148 27A40010 */   addiu    $a0, $sp, 0x10
/* D1371C 8024014C 27A40010 */  addiu     $a0, $sp, 0x10
/* D13720 80240150 0200282D */  daddu     $a1, $s0, $zero
/* D13724 80240154 0C019D80 */  jal       guMtxCatF
/* D13728 80240158 0200302D */   daddu    $a2, $s0, $zero
/* D1372C 8024015C 27A40010 */  addiu     $a0, $sp, 0x10
/* D13730 80240160 4600B587 */  neg.s     $f22, $f22
/* D13734 80240164 4405A000 */  mfc1      $a1, $f20
/* D13738 80240168 4406B000 */  mfc1      $a2, $f22
/* D1373C 8024016C 0C019E40 */  jal       guTranslateF
/* D13740 80240170 00A0382D */   daddu    $a3, $a1, $zero
/* D13744 80240174 27A40010 */  addiu     $a0, $sp, 0x10
/* D13748 80240178 0200282D */  daddu     $a1, $s0, $zero
/* D1374C 8024017C 0C019D80 */  jal       guMtxCatF
/* D13750 80240180 00A0302D */   daddu    $a2, $a1, $zero
/* D13754 80240184 96220000 */  lhu       $v0, ($s1)
/* D13758 80240188 34421400 */  ori       $v0, $v0, 0x1400
/* D1375C 8024018C 08090083 */  j         .L8024020C
/* D13760 80240190 A6220000 */   sh       $v0, ($s1)
.L80240194:
/* D13764 80240194 4480A000 */  mtc1      $zero, $f20
/* D13768 80240198 4406B000 */  mfc1      $a2, $f22
/* D1376C 8024019C 4405A000 */  mfc1      $a1, $f20
/* D13770 802401A0 4407A000 */  mfc1      $a3, $f20
/* D13774 802401A4 0C019E40 */  jal       guTranslateF
/* D13778 802401A8 27A40010 */   addiu    $a0, $sp, 0x10
/* D1377C 802401AC 27A40010 */  addiu     $a0, $sp, 0x10
/* D13780 802401B0 26300058 */  addiu     $s0, $s1, 0x58
/* D13784 802401B4 0200282D */  daddu     $a1, $s0, $zero
/* D13788 802401B8 0C019D80 */  jal       guMtxCatF
/* D1378C 802401BC 0200302D */   daddu    $a2, $s0, $zero
/* D13790 802401C0 4405E000 */  mfc1      $a1, $f28
/* D13794 802401C4 4406D000 */  mfc1      $a2, $f26
/* D13798 802401C8 4407C000 */  mfc1      $a3, $f24
/* D1379C 802401CC 0C090000 */  jal       func_80240000
/* D137A0 802401D0 27A40010 */   addiu    $a0, $sp, 0x10
/* D137A4 802401D4 27A40010 */  addiu     $a0, $sp, 0x10
/* D137A8 802401D8 0200282D */  daddu     $a1, $s0, $zero
/* D137AC 802401DC 0C019D80 */  jal       guMtxCatF
/* D137B0 802401E0 0200302D */   daddu    $a2, $s0, $zero
/* D137B4 802401E4 27A40010 */  addiu     $a0, $sp, 0x10
/* D137B8 802401E8 4600B587 */  neg.s     $f22, $f22
/* D137BC 802401EC 4405A000 */  mfc1      $a1, $f20
/* D137C0 802401F0 4406B000 */  mfc1      $a2, $f22
/* D137C4 802401F4 0C019E40 */  jal       guTranslateF
/* D137C8 802401F8 00A0382D */   daddu    $a3, $a1, $zero
/* D137CC 802401FC 27A40010 */  addiu     $a0, $sp, 0x10
/* D137D0 80240200 0200282D */  daddu     $a1, $s0, $zero
/* D137D4 80240204 0C019D80 */  jal       guMtxCatF
/* D137D8 80240208 00A0302D */   daddu    $a2, $a1, $zero
.L8024020C:
/* D137DC 8024020C 8FBF005C */  lw        $ra, 0x5c($sp)
/* D137E0 80240210 8FB20058 */  lw        $s2, 0x58($sp)
/* D137E4 80240214 8FB10054 */  lw        $s1, 0x54($sp)
/* D137E8 80240218 8FB00050 */  lw        $s0, 0x50($sp)
/* D137EC 8024021C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* D137F0 80240220 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* D137F4 80240224 D7B80070 */  ldc1      $f24, 0x70($sp)
/* D137F8 80240228 D7B60068 */  ldc1      $f22, 0x68($sp)
/* D137FC 8024022C D7B40060 */  ldc1      $f20, 0x60($sp)
/* D13800 80240230 24020002 */  addiu     $v0, $zero, 2
/* D13804 80240234 03E00008 */  jr        $ra
/* D13808 80240238 27BD0088 */   addiu    $sp, $sp, 0x88
/* D1380C 8024023C 00000000 */  nop       
