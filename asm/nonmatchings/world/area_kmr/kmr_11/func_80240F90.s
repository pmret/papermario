.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F90
/* 8DB090 80240F90 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8DB094 80240F94 AFB10054 */  sw        $s1, 0x54($sp)
/* 8DB098 80240F98 0080882D */  daddu     $s1, $a0, $zero
/* 8DB09C 80240F9C AFBF005C */  sw        $ra, 0x5c($sp)
/* 8DB0A0 80240FA0 AFB20058 */  sw        $s2, 0x58($sp)
/* 8DB0A4 80240FA4 AFB00050 */  sw        $s0, 0x50($sp)
/* 8DB0A8 80240FA8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8DB0AC 80240FAC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8DB0B0 80240FB0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8DB0B4 80240FB4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8DB0B8 80240FB8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8DB0BC 80240FBC 8E30000C */  lw        $s0, 0xc($s1)
/* 8DB0C0 80240FC0 8E050000 */  lw        $a1, ($s0)
/* 8DB0C4 80240FC4 0C0B1EAF */  jal       get_variable
/* 8DB0C8 80240FC8 26100004 */   addiu    $s0, $s0, 4
/* 8DB0CC 80240FCC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8DB0D0 80240FD0 0040202D */   daddu    $a0, $v0, $zero
/* 8DB0D4 80240FD4 8E050000 */  lw        $a1, ($s0)
/* 8DB0D8 80240FD8 26100004 */  addiu     $s0, $s0, 4
/* 8DB0DC 80240FDC 0220202D */  daddu     $a0, $s1, $zero
/* 8DB0E0 80240FE0 0C0B210B */  jal       get_float_variable
/* 8DB0E4 80240FE4 0040902D */   daddu    $s2, $v0, $zero
/* 8DB0E8 80240FE8 8E050000 */  lw        $a1, ($s0)
/* 8DB0EC 80240FEC 26100004 */  addiu     $s0, $s0, 4
/* 8DB0F0 80240FF0 0220202D */  daddu     $a0, $s1, $zero
/* 8DB0F4 80240FF4 0C0B210B */  jal       get_float_variable
/* 8DB0F8 80240FF8 46000706 */   mov.s    $f28, $f0
/* 8DB0FC 80240FFC 8E050000 */  lw        $a1, ($s0)
/* 8DB100 80241000 26100004 */  addiu     $s0, $s0, 4
/* 8DB104 80241004 0220202D */  daddu     $a0, $s1, $zero
/* 8DB108 80241008 0C0B210B */  jal       get_float_variable
/* 8DB10C 8024100C 46000686 */   mov.s    $f26, $f0
/* 8DB110 80241010 0220202D */  daddu     $a0, $s1, $zero
/* 8DB114 80241014 8E050000 */  lw        $a1, ($s0)
/* 8DB118 80241018 0C0B210B */  jal       get_float_variable
/* 8DB11C 8024101C 46000586 */   mov.s    $f22, $f0
/* 8DB120 80241020 0240202D */  daddu     $a0, $s2, $zero
/* 8DB124 80241024 0C046B4C */  jal       get_model_from_list_index
/* 8DB128 80241028 46000606 */   mov.s    $f24, $f0
/* 8DB12C 8024102C 0040882D */  daddu     $s1, $v0, $zero
/* 8DB130 80241030 96220000 */  lhu       $v0, ($s1)
/* 8DB134 80241034 30420400 */  andi      $v0, $v0, 0x400
/* 8DB138 80241038 1440001E */  bnez      $v0, .L802410B4
/* 8DB13C 8024103C 26300058 */   addiu    $s0, $s1, 0x58
/* 8DB140 80241040 4480A000 */  mtc1      $zero, $f20
/* 8DB144 80241044 4406B000 */  mfc1      $a2, $f22
/* 8DB148 80241048 4405A000 */  mfc1      $a1, $f20
/* 8DB14C 8024104C 4407A000 */  mfc1      $a3, $f20
/* 8DB150 80241050 0C019E40 */  jal       guTranslateF
/* 8DB154 80241054 0200202D */   daddu    $a0, $s0, $zero
/* 8DB158 80241058 4405E000 */  mfc1      $a1, $f28
/* 8DB15C 8024105C 4406D000 */  mfc1      $a2, $f26
/* 8DB160 80241060 4407C000 */  mfc1      $a3, $f24
/* 8DB164 80241064 0C0903C8 */  jal       func_80240F20
/* 8DB168 80241068 27A40010 */   addiu    $a0, $sp, 0x10
/* 8DB16C 8024106C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB170 80241070 0200282D */  daddu     $a1, $s0, $zero
/* 8DB174 80241074 0C019D80 */  jal       guMtxCatF
/* 8DB178 80241078 0200302D */   daddu    $a2, $s0, $zero
/* 8DB17C 8024107C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB180 80241080 4600B587 */  neg.s     $f22, $f22
/* 8DB184 80241084 4405A000 */  mfc1      $a1, $f20
/* 8DB188 80241088 4406B000 */  mfc1      $a2, $f22
/* 8DB18C 8024108C 0C019E40 */  jal       guTranslateF
/* 8DB190 80241090 00A0382D */   daddu    $a3, $a1, $zero
/* 8DB194 80241094 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB198 80241098 0200282D */  daddu     $a1, $s0, $zero
/* 8DB19C 8024109C 0C019D80 */  jal       guMtxCatF
/* 8DB1A0 802410A0 00A0302D */   daddu    $a2, $a1, $zero
/* 8DB1A4 802410A4 96220000 */  lhu       $v0, ($s1)
/* 8DB1A8 802410A8 34421400 */  ori       $v0, $v0, 0x1400
/* 8DB1AC 802410AC 0809044B */  j         .L8024112C
/* 8DB1B0 802410B0 A6220000 */   sh       $v0, ($s1)
.L802410B4:
/* 8DB1B4 802410B4 4480A000 */  mtc1      $zero, $f20
/* 8DB1B8 802410B8 4406B000 */  mfc1      $a2, $f22
/* 8DB1BC 802410BC 4405A000 */  mfc1      $a1, $f20
/* 8DB1C0 802410C0 4407A000 */  mfc1      $a3, $f20
/* 8DB1C4 802410C4 0C019E40 */  jal       guTranslateF
/* 8DB1C8 802410C8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8DB1CC 802410CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB1D0 802410D0 26300058 */  addiu     $s0, $s1, 0x58
/* 8DB1D4 802410D4 0200282D */  daddu     $a1, $s0, $zero
/* 8DB1D8 802410D8 0C019D80 */  jal       guMtxCatF
/* 8DB1DC 802410DC 0200302D */   daddu    $a2, $s0, $zero
/* 8DB1E0 802410E0 4405E000 */  mfc1      $a1, $f28
/* 8DB1E4 802410E4 4406D000 */  mfc1      $a2, $f26
/* 8DB1E8 802410E8 4407C000 */  mfc1      $a3, $f24
/* 8DB1EC 802410EC 0C0903C8 */  jal       func_80240F20
/* 8DB1F0 802410F0 27A40010 */   addiu    $a0, $sp, 0x10
/* 8DB1F4 802410F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB1F8 802410F8 0200282D */  daddu     $a1, $s0, $zero
/* 8DB1FC 802410FC 0C019D80 */  jal       guMtxCatF
/* 8DB200 80241100 0200302D */   daddu    $a2, $s0, $zero
/* 8DB204 80241104 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB208 80241108 4600B587 */  neg.s     $f22, $f22
/* 8DB20C 8024110C 4405A000 */  mfc1      $a1, $f20
/* 8DB210 80241110 4406B000 */  mfc1      $a2, $f22
/* 8DB214 80241114 0C019E40 */  jal       guTranslateF
/* 8DB218 80241118 00A0382D */   daddu    $a3, $a1, $zero
/* 8DB21C 8024111C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8DB220 80241120 0200282D */  daddu     $a1, $s0, $zero
/* 8DB224 80241124 0C019D80 */  jal       guMtxCatF
/* 8DB228 80241128 00A0302D */   daddu    $a2, $a1, $zero
.L8024112C:
/* 8DB22C 8024112C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8DB230 80241130 8FB20058 */  lw        $s2, 0x58($sp)
/* 8DB234 80241134 8FB10054 */  lw        $s1, 0x54($sp)
/* 8DB238 80241138 8FB00050 */  lw        $s0, 0x50($sp)
/* 8DB23C 8024113C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8DB240 80241140 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8DB244 80241144 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8DB248 80241148 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8DB24C 8024114C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8DB250 80241150 24020002 */  addiu     $v0, $zero, 2
/* 8DB254 80241154 03E00008 */  jr        $ra
/* 8DB258 80241158 27BD0088 */   addiu    $sp, $sp, 0x88
/* 8DB25C 8024115C 00000000 */  nop       
