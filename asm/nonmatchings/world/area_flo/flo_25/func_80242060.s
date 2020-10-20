.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242060
/* CF4C30 80242060 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CF4C34 80242064 AFB10054 */  sw        $s1, 0x54($sp)
/* CF4C38 80242068 0080882D */  daddu     $s1, $a0, $zero
/* CF4C3C 8024206C AFBF005C */  sw        $ra, 0x5c($sp)
/* CF4C40 80242070 AFB20058 */  sw        $s2, 0x58($sp)
/* CF4C44 80242074 AFB00050 */  sw        $s0, 0x50($sp)
/* CF4C48 80242078 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CF4C4C 8024207C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CF4C50 80242080 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CF4C54 80242084 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CF4C58 80242088 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CF4C5C 8024208C 8E30000C */  lw        $s0, 0xc($s1)
/* CF4C60 80242090 8E050000 */  lw        $a1, ($s0)
/* CF4C64 80242094 0C0B1EAF */  jal       get_variable
/* CF4C68 80242098 26100004 */   addiu    $s0, $s0, 4
/* CF4C6C 8024209C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CF4C70 802420A0 0040202D */   daddu    $a0, $v0, $zero
/* CF4C74 802420A4 8E050000 */  lw        $a1, ($s0)
/* CF4C78 802420A8 26100004 */  addiu     $s0, $s0, 4
/* CF4C7C 802420AC 0220202D */  daddu     $a0, $s1, $zero
/* CF4C80 802420B0 0C0B210B */  jal       get_float_variable
/* CF4C84 802420B4 0040902D */   daddu    $s2, $v0, $zero
/* CF4C88 802420B8 8E050000 */  lw        $a1, ($s0)
/* CF4C8C 802420BC 26100004 */  addiu     $s0, $s0, 4
/* CF4C90 802420C0 0220202D */  daddu     $a0, $s1, $zero
/* CF4C94 802420C4 0C0B210B */  jal       get_float_variable
/* CF4C98 802420C8 46000706 */   mov.s    $f28, $f0
/* CF4C9C 802420CC 8E050000 */  lw        $a1, ($s0)
/* CF4CA0 802420D0 26100004 */  addiu     $s0, $s0, 4
/* CF4CA4 802420D4 0220202D */  daddu     $a0, $s1, $zero
/* CF4CA8 802420D8 0C0B210B */  jal       get_float_variable
/* CF4CAC 802420DC 46000686 */   mov.s    $f26, $f0
/* CF4CB0 802420E0 0220202D */  daddu     $a0, $s1, $zero
/* CF4CB4 802420E4 8E050000 */  lw        $a1, ($s0)
/* CF4CB8 802420E8 0C0B210B */  jal       get_float_variable
/* CF4CBC 802420EC 46000586 */   mov.s    $f22, $f0
/* CF4CC0 802420F0 0240202D */  daddu     $a0, $s2, $zero
/* CF4CC4 802420F4 0C046B4C */  jal       get_model_from_list_index
/* CF4CC8 802420F8 46000606 */   mov.s    $f24, $f0
/* CF4CCC 802420FC 0040882D */  daddu     $s1, $v0, $zero
/* CF4CD0 80242100 96220000 */  lhu       $v0, ($s1)
/* CF4CD4 80242104 30420400 */  andi      $v0, $v0, 0x400
/* CF4CD8 80242108 1440001E */  bnez      $v0, .L80242184
/* CF4CDC 8024210C 26300058 */   addiu    $s0, $s1, 0x58
/* CF4CE0 80242110 4480A000 */  mtc1      $zero, $f20
/* CF4CE4 80242114 4406B000 */  mfc1      $a2, $f22
/* CF4CE8 80242118 4405A000 */  mfc1      $a1, $f20
/* CF4CEC 8024211C 4407A000 */  mfc1      $a3, $f20
/* CF4CF0 80242120 0C019E40 */  jal       guTranslateF
/* CF4CF4 80242124 0200202D */   daddu    $a0, $s0, $zero
/* CF4CF8 80242128 4405E000 */  mfc1      $a1, $f28
/* CF4CFC 8024212C 4406D000 */  mfc1      $a2, $f26
/* CF4D00 80242130 4407C000 */  mfc1      $a3, $f24
/* CF4D04 80242134 0C0907FC */  jal       func_80241FF0
/* CF4D08 80242138 27A40010 */   addiu    $a0, $sp, 0x10
/* CF4D0C 8024213C 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4D10 80242140 0200282D */  daddu     $a1, $s0, $zero
/* CF4D14 80242144 0C019D80 */  jal       guMtxCatF
/* CF4D18 80242148 0200302D */   daddu    $a2, $s0, $zero
/* CF4D1C 8024214C 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4D20 80242150 4600B587 */  neg.s     $f22, $f22
/* CF4D24 80242154 4405A000 */  mfc1      $a1, $f20
/* CF4D28 80242158 4406B000 */  mfc1      $a2, $f22
/* CF4D2C 8024215C 0C019E40 */  jal       guTranslateF
/* CF4D30 80242160 00A0382D */   daddu    $a3, $a1, $zero
/* CF4D34 80242164 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4D38 80242168 0200282D */  daddu     $a1, $s0, $zero
/* CF4D3C 8024216C 0C019D80 */  jal       guMtxCatF
/* CF4D40 80242170 00A0302D */   daddu    $a2, $a1, $zero
/* CF4D44 80242174 96220000 */  lhu       $v0, ($s1)
/* CF4D48 80242178 34421400 */  ori       $v0, $v0, 0x1400
/* CF4D4C 8024217C 0809087F */  j         .L802421FC
/* CF4D50 80242180 A6220000 */   sh       $v0, ($s1)
.L80242184:
/* CF4D54 80242184 4480A000 */  mtc1      $zero, $f20
/* CF4D58 80242188 4406B000 */  mfc1      $a2, $f22
/* CF4D5C 8024218C 4405A000 */  mfc1      $a1, $f20
/* CF4D60 80242190 4407A000 */  mfc1      $a3, $f20
/* CF4D64 80242194 0C019E40 */  jal       guTranslateF
/* CF4D68 80242198 27A40010 */   addiu    $a0, $sp, 0x10
/* CF4D6C 8024219C 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4D70 802421A0 26300058 */  addiu     $s0, $s1, 0x58
/* CF4D74 802421A4 0200282D */  daddu     $a1, $s0, $zero
/* CF4D78 802421A8 0C019D80 */  jal       guMtxCatF
/* CF4D7C 802421AC 0200302D */   daddu    $a2, $s0, $zero
/* CF4D80 802421B0 4405E000 */  mfc1      $a1, $f28
/* CF4D84 802421B4 4406D000 */  mfc1      $a2, $f26
/* CF4D88 802421B8 4407C000 */  mfc1      $a3, $f24
/* CF4D8C 802421BC 0C0907FC */  jal       func_80241FF0
/* CF4D90 802421C0 27A40010 */   addiu    $a0, $sp, 0x10
/* CF4D94 802421C4 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4D98 802421C8 0200282D */  daddu     $a1, $s0, $zero
/* CF4D9C 802421CC 0C019D80 */  jal       guMtxCatF
/* CF4DA0 802421D0 0200302D */   daddu    $a2, $s0, $zero
/* CF4DA4 802421D4 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4DA8 802421D8 4600B587 */  neg.s     $f22, $f22
/* CF4DAC 802421DC 4405A000 */  mfc1      $a1, $f20
/* CF4DB0 802421E0 4406B000 */  mfc1      $a2, $f22
/* CF4DB4 802421E4 0C019E40 */  jal       guTranslateF
/* CF4DB8 802421E8 00A0382D */   daddu    $a3, $a1, $zero
/* CF4DBC 802421EC 27A40010 */  addiu     $a0, $sp, 0x10
/* CF4DC0 802421F0 0200282D */  daddu     $a1, $s0, $zero
/* CF4DC4 802421F4 0C019D80 */  jal       guMtxCatF
/* CF4DC8 802421F8 00A0302D */   daddu    $a2, $a1, $zero
.L802421FC:
/* CF4DCC 802421FC 8FBF005C */  lw        $ra, 0x5c($sp)
/* CF4DD0 80242200 8FB20058 */  lw        $s2, 0x58($sp)
/* CF4DD4 80242204 8FB10054 */  lw        $s1, 0x54($sp)
/* CF4DD8 80242208 8FB00050 */  lw        $s0, 0x50($sp)
/* CF4DDC 8024220C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CF4DE0 80242210 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CF4DE4 80242214 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CF4DE8 80242218 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CF4DEC 8024221C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CF4DF0 80242220 24020002 */  addiu     $v0, $zero, 2
/* CF4DF4 80242224 03E00008 */  jr        $ra
/* CF4DF8 80242228 27BD0088 */   addiu    $sp, $sp, 0x88
/* CF4DFC 8024222C 00000000 */  nop       
