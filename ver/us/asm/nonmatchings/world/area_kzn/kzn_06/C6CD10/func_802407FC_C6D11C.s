.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407FC_C6D11C
/* C6D11C 802407FC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C6D120 80240800 AFB5002C */  sw        $s5, 0x2c($sp)
/* C6D124 80240804 0080A82D */  daddu     $s5, $a0, $zero
/* C6D128 80240808 AFB20020 */  sw        $s2, 0x20($sp)
/* C6D12C 8024080C 00A0902D */  daddu     $s2, $a1, $zero
/* C6D130 80240810 AFBF003C */  sw        $ra, 0x3c($sp)
/* C6D134 80240814 AFBE0038 */  sw        $fp, 0x38($sp)
/* C6D138 80240818 AFB70034 */  sw        $s7, 0x34($sp)
/* C6D13C 8024081C AFB60030 */  sw        $s6, 0x30($sp)
/* C6D140 80240820 AFB40028 */  sw        $s4, 0x28($sp)
/* C6D144 80240824 AFB30024 */  sw        $s3, 0x24($sp)
/* C6D148 80240828 AFB1001C */  sw        $s1, 0x1c($sp)
/* C6D14C 8024082C AFB00018 */  sw        $s0, 0x18($sp)
/* C6D150 80240830 8EB0000C */  lw        $s0, 0xc($s5)
/* C6D154 80240834 8E050000 */  lw        $a1, ($s0)
/* C6D158 80240838 0C0B1EAF */  jal       evt_get_variable
/* C6D15C 8024083C 26100004 */   addiu    $s0, $s0, 4
/* C6D160 80240840 8E050000 */  lw        $a1, ($s0)
/* C6D164 80240844 26100004 */  addiu     $s0, $s0, 4
/* C6D168 80240848 02A0202D */  daddu     $a0, $s5, $zero
/* C6D16C 8024084C 0C0B1EAF */  jal       evt_get_variable
/* C6D170 80240850 0040882D */   daddu    $s1, $v0, $zero
/* C6D174 80240854 8E050000 */  lw        $a1, ($s0)
/* C6D178 80240858 26100004 */  addiu     $s0, $s0, 4
/* C6D17C 8024085C 02A0202D */  daddu     $a0, $s5, $zero
/* C6D180 80240860 0C0B1EAF */  jal       evt_get_variable
/* C6D184 80240864 AFA20010 */   sw       $v0, 0x10($sp)
/* C6D188 80240868 8E050000 */  lw        $a1, ($s0)
/* C6D18C 8024086C 26100004 */  addiu     $s0, $s0, 4
/* C6D190 80240870 02A0202D */  daddu     $a0, $s5, $zero
/* C6D194 80240874 0C0B1EAF */  jal       evt_get_variable
/* C6D198 80240878 0040F02D */   daddu    $fp, $v0, $zero
/* C6D19C 8024087C 8E050000 */  lw        $a1, ($s0)
/* C6D1A0 80240880 26100004 */  addiu     $s0, $s0, 4
/* C6D1A4 80240884 02A0202D */  daddu     $a0, $s5, $zero
/* C6D1A8 80240888 0C0B1EAF */  jal       evt_get_variable
/* C6D1AC 8024088C 0040B82D */   daddu    $s7, $v0, $zero
/* C6D1B0 80240890 02A0202D */  daddu     $a0, $s5, $zero
/* C6D1B4 80240894 8E050000 */  lw        $a1, ($s0)
/* C6D1B8 80240898 0C0B1EAF */  jal       evt_get_variable
/* C6D1BC 8024089C 0040A02D */   daddu    $s4, $v0, $zero
/* C6D1C0 802408A0 0040B02D */  daddu     $s6, $v0, $zero
/* C6D1C4 802408A4 12400019 */  beqz      $s2, .L8024090C
/* C6D1C8 802408A8 0220982D */   daddu    $s3, $s1, $zero
/* C6D1CC 802408AC 96620000 */  lhu       $v0, ($s3)
/* C6D1D0 802408B0 10400015 */  beqz      $v0, .L80240908
/* C6D1D4 802408B4 0000902D */   daddu    $s2, $zero, $zero
.L802408B8:
/* C6D1D8 802408B8 96240002 */  lhu       $a0, 2($s1)
/* C6D1DC 802408BC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* C6D1E0 802408C0 00000000 */   nop
/* C6D1E4 802408C4 0C046B4C */  jal       get_model_from_list_index
/* C6D1E8 802408C8 0040202D */   daddu    $a0, $v0, $zero
/* C6D1EC 802408CC 0040802D */  daddu     $s0, $v0, $zero
/* C6D1F0 802408D0 0200202D */  daddu     $a0, $s0, $zero
/* C6D1F4 802408D4 2405FFFF */  addiu     $a1, $zero, -1
/* C6D1F8 802408D8 0C046F1F */  jal       set_mdl_custom_gfx_set
/* C6D1FC 802408DC 24060003 */   addiu    $a2, $zero, 3
/* C6D200 802408E0 12C00004 */  beqz      $s6, .L802408F4
/* C6D204 802408E4 00000000 */   nop
/* C6D208 802408E8 96020000 */  lhu       $v0, ($s0)
/* C6D20C 802408EC 3042FFFD */  andi      $v0, $v0, 0xfffd
/* C6D210 802408F0 A6020000 */  sh        $v0, ($s0)
.L802408F4:
/* C6D214 802408F4 96620000 */  lhu       $v0, ($s3)
/* C6D218 802408F8 26520001 */  addiu     $s2, $s2, 1
/* C6D21C 802408FC 0242102A */  slt       $v0, $s2, $v0
/* C6D220 80240900 1440FFED */  bnez      $v0, .L802408B8
/* C6D224 80240904 26310002 */   addiu    $s1, $s1, 2
.L80240908:
/* C6D228 80240908 AEB40070 */  sw        $s4, 0x70($s5)
.L8024090C:
/* C6D22C 8024090C 12C00011 */  beqz      $s6, .L80240954
/* C6D230 80240910 33C500FF */   andi     $a1, $fp, 0xff
/* C6D234 80240914 8EA20070 */  lw        $v0, 0x70($s5)
/* C6D238 80240918 00023A00 */  sll       $a3, $v0, 8
/* C6D23C 8024091C 00E23823 */  subu      $a3, $a3, $v0
/* C6D240 80240920 16800002 */  bnez      $s4, .L8024092C
/* C6D244 80240924 00F4001A */   div      $zero, $a3, $s4
/* C6D248 80240928 0007000D */  break     7
.L8024092C:
/* C6D24C 8024092C 2401FFFF */   addiu    $at, $zero, -1
/* C6D250 80240930 16810004 */  bne       $s4, $at, .L80240944
/* C6D254 80240934 3C018000 */   lui      $at, 0x8000
/* C6D258 80240938 14E10002 */  bne       $a3, $at, .L80240944
/* C6D25C 8024093C 00000000 */   nop
/* C6D260 80240940 0006000D */  break     6
.L80240944:
/* C6D264 80240944 00003812 */   mflo     $a3
/* C6D268 80240948 93A40013 */  lbu       $a0, 0x13($sp)
/* C6D26C 8024094C 08090265 */  j         .L80240994
/* C6D270 80240950 32E600FF */   andi     $a2, $s7, 0xff
.L80240954:
/* C6D274 80240954 8EA20070 */  lw        $v0, 0x70($s5)
/* C6D278 80240958 00023A00 */  sll       $a3, $v0, 8
/* C6D27C 8024095C 00E23823 */  subu      $a3, $a3, $v0
/* C6D280 80240960 16800002 */  bnez      $s4, .L8024096C
/* C6D284 80240964 00F4001A */   div      $zero, $a3, $s4
/* C6D288 80240968 0007000D */  break     7
.L8024096C:
/* C6D28C 8024096C 2401FFFF */   addiu    $at, $zero, -1
/* C6D290 80240970 16810004 */  bne       $s4, $at, .L80240984
/* C6D294 80240974 3C018000 */   lui      $at, 0x8000
/* C6D298 80240978 14E10002 */  bne       $a3, $at, .L80240984
/* C6D29C 8024097C 00000000 */   nop
/* C6D2A0 80240980 0006000D */  break     6
.L80240984:
/* C6D2A4 80240984 00003812 */   mflo     $a3
/* C6D2A8 80240988 32E600FF */  andi      $a2, $s7, 0xff
/* C6D2AC 8024098C 93A40013 */  lbu       $a0, 0x13($sp)
/* C6D2B0 80240990 00073827 */  nor       $a3, $zero, $a3
.L80240994:
/* C6D2B4 80240994 0C046F97 */  jal       set_background_color_blend
/* C6D2B8 80240998 30E700FF */   andi     $a3, $a3, 0xff
/* C6D2BC 8024099C 8EA20070 */  lw        $v0, 0x70($s5)
/* C6D2C0 802409A0 2442FFFF */  addiu     $v0, $v0, -1
/* C6D2C4 802409A4 0441001A */  bgez      $v0, .L80240A10
/* C6D2C8 802409A8 AEA20070 */   sw       $v0, 0x70($s5)
/* C6D2CC 802409AC 96620000 */  lhu       $v0, ($s3)
/* C6D2D0 802409B0 10400015 */  beqz      $v0, .L80240A08
/* C6D2D4 802409B4 0000902D */   daddu    $s2, $zero, $zero
/* C6D2D8 802409B8 0260882D */  daddu     $s1, $s3, $zero
.L802409BC:
/* C6D2DC 802409BC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* C6D2E0 802409C0 96240002 */   lhu      $a0, 2($s1)
/* C6D2E4 802409C4 0C046B4C */  jal       get_model_from_list_index
/* C6D2E8 802409C8 0040202D */   daddu    $a0, $v0, $zero
/* C6D2EC 802409CC 0040802D */  daddu     $s0, $v0, $zero
/* C6D2F0 802409D0 0200202D */  daddu     $a0, $s0, $zero
/* C6D2F4 802409D4 2405FFFF */  addiu     $a1, $zero, -1
/* C6D2F8 802409D8 0C046F1F */  jal       set_mdl_custom_gfx_set
/* C6D2FC 802409DC 0000302D */   daddu    $a2, $zero, $zero
/* C6D300 802409E0 16C00004 */  bnez      $s6, .L802409F4
/* C6D304 802409E4 00000000 */   nop
/* C6D308 802409E8 96020000 */  lhu       $v0, ($s0)
/* C6D30C 802409EC 34420002 */  ori       $v0, $v0, 2
/* C6D310 802409F0 A6020000 */  sh        $v0, ($s0)
.L802409F4:
/* C6D314 802409F4 96620000 */  lhu       $v0, ($s3)
/* C6D318 802409F8 26520001 */  addiu     $s2, $s2, 1
/* C6D31C 802409FC 0242102A */  slt       $v0, $s2, $v0
/* C6D320 80240A00 1440FFEE */  bnez      $v0, .L802409BC
/* C6D324 80240A04 26310002 */   addiu    $s1, $s1, 2
.L80240A08:
/* C6D328 80240A08 08090285 */  j         .L80240A14
/* C6D32C 80240A0C 24020001 */   addiu    $v0, $zero, 1
.L80240A10:
/* C6D330 80240A10 0000102D */  daddu     $v0, $zero, $zero
.L80240A14:
/* C6D334 80240A14 8FBF003C */  lw        $ra, 0x3c($sp)
/* C6D338 80240A18 8FBE0038 */  lw        $fp, 0x38($sp)
/* C6D33C 80240A1C 8FB70034 */  lw        $s7, 0x34($sp)
/* C6D340 80240A20 8FB60030 */  lw        $s6, 0x30($sp)
/* C6D344 80240A24 8FB5002C */  lw        $s5, 0x2c($sp)
/* C6D348 80240A28 8FB40028 */  lw        $s4, 0x28($sp)
/* C6D34C 80240A2C 8FB30024 */  lw        $s3, 0x24($sp)
/* C6D350 80240A30 8FB20020 */  lw        $s2, 0x20($sp)
/* C6D354 80240A34 8FB1001C */  lw        $s1, 0x1c($sp)
/* C6D358 80240A38 8FB00018 */  lw        $s0, 0x18($sp)
/* C6D35C 80240A3C 03E00008 */  jr        $ra
/* C6D360 80240A40 27BD0040 */   addiu    $sp, $sp, 0x40
