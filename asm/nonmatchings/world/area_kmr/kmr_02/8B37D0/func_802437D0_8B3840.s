.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802437D0_8B3840
/* 8B3840 802437D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8B3844 802437D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 8B3848 802437D8 0080882D */  daddu     $s1, $a0, $zero
/* 8B384C 802437DC AFBF005C */  sw        $ra, 0x5c($sp)
/* 8B3850 802437E0 AFB20058 */  sw        $s2, 0x58($sp)
/* 8B3854 802437E4 AFB00050 */  sw        $s0, 0x50($sp)
/* 8B3858 802437E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8B385C 802437EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8B3860 802437F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8B3864 802437F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8B3868 802437F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8B386C 802437FC 8E30000C */  lw        $s0, 0xc($s1)
/* 8B3870 80243800 8E050000 */  lw        $a1, ($s0)
/* 8B3874 80243804 0C0B1EAF */  jal       get_variable
/* 8B3878 80243808 26100004 */   addiu    $s0, $s0, 4
/* 8B387C 8024380C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8B3880 80243810 0040202D */   daddu    $a0, $v0, $zero
/* 8B3884 80243814 8E050000 */  lw        $a1, ($s0)
/* 8B3888 80243818 26100004 */  addiu     $s0, $s0, 4
/* 8B388C 8024381C 0220202D */  daddu     $a0, $s1, $zero
/* 8B3890 80243820 0C0B210B */  jal       get_float_variable
/* 8B3894 80243824 0040902D */   daddu    $s2, $v0, $zero
/* 8B3898 80243828 8E050000 */  lw        $a1, ($s0)
/* 8B389C 8024382C 26100004 */  addiu     $s0, $s0, 4
/* 8B38A0 80243830 0220202D */  daddu     $a0, $s1, $zero
/* 8B38A4 80243834 0C0B210B */  jal       get_float_variable
/* 8B38A8 80243838 46000706 */   mov.s    $f28, $f0
/* 8B38AC 8024383C 8E050000 */  lw        $a1, ($s0)
/* 8B38B0 80243840 26100004 */  addiu     $s0, $s0, 4
/* 8B38B4 80243844 0220202D */  daddu     $a0, $s1, $zero
/* 8B38B8 80243848 0C0B210B */  jal       get_float_variable
/* 8B38BC 8024384C 46000686 */   mov.s    $f26, $f0
/* 8B38C0 80243850 0220202D */  daddu     $a0, $s1, $zero
/* 8B38C4 80243854 8E050000 */  lw        $a1, ($s0)
/* 8B38C8 80243858 0C0B210B */  jal       get_float_variable
/* 8B38CC 8024385C 46000586 */   mov.s    $f22, $f0
/* 8B38D0 80243860 0240202D */  daddu     $a0, $s2, $zero
/* 8B38D4 80243864 0C046B4C */  jal       get_model_from_list_index
/* 8B38D8 80243868 46000606 */   mov.s    $f24, $f0
/* 8B38DC 8024386C 0040882D */  daddu     $s1, $v0, $zero
/* 8B38E0 80243870 96220000 */  lhu       $v0, ($s1)
/* 8B38E4 80243874 30420400 */  andi      $v0, $v0, 0x400
/* 8B38E8 80243878 1440001E */  bnez      $v0, .L802438F4
/* 8B38EC 8024387C 26300058 */   addiu    $s0, $s1, 0x58
/* 8B38F0 80243880 4480A000 */  mtc1      $zero, $f20
/* 8B38F4 80243884 4406B000 */  mfc1      $a2, $f22
/* 8B38F8 80243888 4405A000 */  mfc1      $a1, $f20
/* 8B38FC 8024388C 4407A000 */  mfc1      $a3, $f20
/* 8B3900 80243890 0C019E40 */  jal       guTranslateF
/* 8B3904 80243894 0200202D */   daddu    $a0, $s0, $zero
/* 8B3908 80243898 4405E000 */  mfc1      $a1, $f28
/* 8B390C 8024389C 4406D000 */  mfc1      $a2, $f26
/* 8B3910 802438A0 4407C000 */  mfc1      $a3, $f24
/* 8B3914 802438A4 0C090DD8 */  jal       func_80243760_8B37D0
/* 8B3918 802438A8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8B391C 802438AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B3920 802438B0 0200282D */  daddu     $a1, $s0, $zero
/* 8B3924 802438B4 0C019D80 */  jal       guMtxCatF
/* 8B3928 802438B8 0200302D */   daddu    $a2, $s0, $zero
/* 8B392C 802438BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B3930 802438C0 4600B587 */  neg.s     $f22, $f22
/* 8B3934 802438C4 4405A000 */  mfc1      $a1, $f20
/* 8B3938 802438C8 4406B000 */  mfc1      $a2, $f22
/* 8B393C 802438CC 0C019E40 */  jal       guTranslateF
/* 8B3940 802438D0 00A0382D */   daddu    $a3, $a1, $zero
/* 8B3944 802438D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B3948 802438D8 0200282D */  daddu     $a1, $s0, $zero
/* 8B394C 802438DC 0C019D80 */  jal       guMtxCatF
/* 8B3950 802438E0 00A0302D */   daddu    $a2, $a1, $zero
/* 8B3954 802438E4 96220000 */  lhu       $v0, ($s1)
/* 8B3958 802438E8 34421400 */  ori       $v0, $v0, 0x1400
/* 8B395C 802438EC 08090E5B */  j         .L8024396C
/* 8B3960 802438F0 A6220000 */   sh       $v0, ($s1)
.L802438F4:
/* 8B3964 802438F4 4480A000 */  mtc1      $zero, $f20
/* 8B3968 802438F8 4406B000 */  mfc1      $a2, $f22
/* 8B396C 802438FC 4405A000 */  mfc1      $a1, $f20
/* 8B3970 80243900 4407A000 */  mfc1      $a3, $f20
/* 8B3974 80243904 0C019E40 */  jal       guTranslateF
/* 8B3978 80243908 27A40010 */   addiu    $a0, $sp, 0x10
/* 8B397C 8024390C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B3980 80243910 26300058 */  addiu     $s0, $s1, 0x58
/* 8B3984 80243914 0200282D */  daddu     $a1, $s0, $zero
/* 8B3988 80243918 0C019D80 */  jal       guMtxCatF
/* 8B398C 8024391C 0200302D */   daddu    $a2, $s0, $zero
/* 8B3990 80243920 4405E000 */  mfc1      $a1, $f28
/* 8B3994 80243924 4406D000 */  mfc1      $a2, $f26
/* 8B3998 80243928 4407C000 */  mfc1      $a3, $f24
/* 8B399C 8024392C 0C090DD8 */  jal       func_80243760_8B37D0
/* 8B39A0 80243930 27A40010 */   addiu    $a0, $sp, 0x10
/* 8B39A4 80243934 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B39A8 80243938 0200282D */  daddu     $a1, $s0, $zero
/* 8B39AC 8024393C 0C019D80 */  jal       guMtxCatF
/* 8B39B0 80243940 0200302D */   daddu    $a2, $s0, $zero
/* 8B39B4 80243944 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B39B8 80243948 4600B587 */  neg.s     $f22, $f22
/* 8B39BC 8024394C 4405A000 */  mfc1      $a1, $f20
/* 8B39C0 80243950 4406B000 */  mfc1      $a2, $f22
/* 8B39C4 80243954 0C019E40 */  jal       guTranslateF
/* 8B39C8 80243958 00A0382D */   daddu    $a3, $a1, $zero
/* 8B39CC 8024395C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B39D0 80243960 0200282D */  daddu     $a1, $s0, $zero
/* 8B39D4 80243964 0C019D80 */  jal       guMtxCatF
/* 8B39D8 80243968 00A0302D */   daddu    $a2, $a1, $zero
.L8024396C:
/* 8B39DC 8024396C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8B39E0 80243970 8FB20058 */  lw        $s2, 0x58($sp)
/* 8B39E4 80243974 8FB10054 */  lw        $s1, 0x54($sp)
/* 8B39E8 80243978 8FB00050 */  lw        $s0, 0x50($sp)
/* 8B39EC 8024397C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8B39F0 80243980 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8B39F4 80243984 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8B39F8 80243988 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8B39FC 8024398C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8B3A00 80243990 24020002 */  addiu     $v0, $zero, 2
/* 8B3A04 80243994 03E00008 */  jr        $ra
/* 8B3A08 80243998 27BD0088 */   addiu    $sp, $sp, 0x88
/* 8B3A0C 8024399C 00000000 */  nop       
