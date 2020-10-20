.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C70_CB09B0
/* CB09B0 80241C70 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CB09B4 80241C74 AFB10054 */  sw        $s1, 0x54($sp)
/* CB09B8 80241C78 0080882D */  daddu     $s1, $a0, $zero
/* CB09BC 80241C7C AFBF005C */  sw        $ra, 0x5c($sp)
/* CB09C0 80241C80 AFB20058 */  sw        $s2, 0x58($sp)
/* CB09C4 80241C84 AFB00050 */  sw        $s0, 0x50($sp)
/* CB09C8 80241C88 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CB09CC 80241C8C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CB09D0 80241C90 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CB09D4 80241C94 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CB09D8 80241C98 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CB09DC 80241C9C 8E30000C */  lw        $s0, 0xc($s1)
/* CB09E0 80241CA0 8E050000 */  lw        $a1, ($s0)
/* CB09E4 80241CA4 0C0B1EAF */  jal       get_variable
/* CB09E8 80241CA8 26100004 */   addiu    $s0, $s0, 4
/* CB09EC 80241CAC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CB09F0 80241CB0 0040202D */   daddu    $a0, $v0, $zero
/* CB09F4 80241CB4 8E050000 */  lw        $a1, ($s0)
/* CB09F8 80241CB8 26100004 */  addiu     $s0, $s0, 4
/* CB09FC 80241CBC 0220202D */  daddu     $a0, $s1, $zero
/* CB0A00 80241CC0 0C0B210B */  jal       get_float_variable
/* CB0A04 80241CC4 0040902D */   daddu    $s2, $v0, $zero
/* CB0A08 80241CC8 8E050000 */  lw        $a1, ($s0)
/* CB0A0C 80241CCC 26100004 */  addiu     $s0, $s0, 4
/* CB0A10 80241CD0 0220202D */  daddu     $a0, $s1, $zero
/* CB0A14 80241CD4 0C0B210B */  jal       get_float_variable
/* CB0A18 80241CD8 46000706 */   mov.s    $f28, $f0
/* CB0A1C 80241CDC 8E050000 */  lw        $a1, ($s0)
/* CB0A20 80241CE0 26100004 */  addiu     $s0, $s0, 4
/* CB0A24 80241CE4 0220202D */  daddu     $a0, $s1, $zero
/* CB0A28 80241CE8 0C0B210B */  jal       get_float_variable
/* CB0A2C 80241CEC 46000686 */   mov.s    $f26, $f0
/* CB0A30 80241CF0 0220202D */  daddu     $a0, $s1, $zero
/* CB0A34 80241CF4 8E050000 */  lw        $a1, ($s0)
/* CB0A38 80241CF8 0C0B210B */  jal       get_float_variable
/* CB0A3C 80241CFC 46000586 */   mov.s    $f22, $f0
/* CB0A40 80241D00 0240202D */  daddu     $a0, $s2, $zero
/* CB0A44 80241D04 0C046B4C */  jal       get_model_from_list_index
/* CB0A48 80241D08 46000606 */   mov.s    $f24, $f0
/* CB0A4C 80241D0C 0040882D */  daddu     $s1, $v0, $zero
/* CB0A50 80241D10 96220000 */  lhu       $v0, ($s1)
/* CB0A54 80241D14 30420400 */  andi      $v0, $v0, 0x400
/* CB0A58 80241D18 1440001E */  bnez      $v0, .L80241D94
/* CB0A5C 80241D1C 26300058 */   addiu    $s0, $s1, 0x58
/* CB0A60 80241D20 4480A000 */  mtc1      $zero, $f20
/* CB0A64 80241D24 4406B000 */  mfc1      $a2, $f22
/* CB0A68 80241D28 4405A000 */  mfc1      $a1, $f20
/* CB0A6C 80241D2C 4407A000 */  mfc1      $a3, $f20
/* CB0A70 80241D30 0C019E40 */  jal       guTranslateF
/* CB0A74 80241D34 0200202D */   daddu    $a0, $s0, $zero
/* CB0A78 80241D38 4405E000 */  mfc1      $a1, $f28
/* CB0A7C 80241D3C 4406D000 */  mfc1      $a2, $f26
/* CB0A80 80241D40 4407C000 */  mfc1      $a3, $f24
/* CB0A84 80241D44 0C090700 */  jal       func_80241C00
/* CB0A88 80241D48 27A40010 */   addiu    $a0, $sp, 0x10
/* CB0A8C 80241D4C 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0A90 80241D50 0200282D */  daddu     $a1, $s0, $zero
/* CB0A94 80241D54 0C019D80 */  jal       guMtxCatF
/* CB0A98 80241D58 0200302D */   daddu    $a2, $s0, $zero
/* CB0A9C 80241D5C 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0AA0 80241D60 4600B587 */  neg.s     $f22, $f22
/* CB0AA4 80241D64 4405A000 */  mfc1      $a1, $f20
/* CB0AA8 80241D68 4406B000 */  mfc1      $a2, $f22
/* CB0AAC 80241D6C 0C019E40 */  jal       guTranslateF
/* CB0AB0 80241D70 00A0382D */   daddu    $a3, $a1, $zero
/* CB0AB4 80241D74 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0AB8 80241D78 0200282D */  daddu     $a1, $s0, $zero
/* CB0ABC 80241D7C 0C019D80 */  jal       guMtxCatF
/* CB0AC0 80241D80 00A0302D */   daddu    $a2, $a1, $zero
/* CB0AC4 80241D84 96220000 */  lhu       $v0, ($s1)
/* CB0AC8 80241D88 34421400 */  ori       $v0, $v0, 0x1400
/* CB0ACC 80241D8C 08090783 */  j         .L80241E0C
/* CB0AD0 80241D90 A6220000 */   sh       $v0, ($s1)
.L80241D94:
/* CB0AD4 80241D94 4480A000 */  mtc1      $zero, $f20
/* CB0AD8 80241D98 4406B000 */  mfc1      $a2, $f22
/* CB0ADC 80241D9C 4405A000 */  mfc1      $a1, $f20
/* CB0AE0 80241DA0 4407A000 */  mfc1      $a3, $f20
/* CB0AE4 80241DA4 0C019E40 */  jal       guTranslateF
/* CB0AE8 80241DA8 27A40010 */   addiu    $a0, $sp, 0x10
/* CB0AEC 80241DAC 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0AF0 80241DB0 26300058 */  addiu     $s0, $s1, 0x58
/* CB0AF4 80241DB4 0200282D */  daddu     $a1, $s0, $zero
/* CB0AF8 80241DB8 0C019D80 */  jal       guMtxCatF
/* CB0AFC 80241DBC 0200302D */   daddu    $a2, $s0, $zero
/* CB0B00 80241DC0 4405E000 */  mfc1      $a1, $f28
/* CB0B04 80241DC4 4406D000 */  mfc1      $a2, $f26
/* CB0B08 80241DC8 4407C000 */  mfc1      $a3, $f24
/* CB0B0C 80241DCC 0C090700 */  jal       func_80241C00
/* CB0B10 80241DD0 27A40010 */   addiu    $a0, $sp, 0x10
/* CB0B14 80241DD4 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0B18 80241DD8 0200282D */  daddu     $a1, $s0, $zero
/* CB0B1C 80241DDC 0C019D80 */  jal       guMtxCatF
/* CB0B20 80241DE0 0200302D */   daddu    $a2, $s0, $zero
/* CB0B24 80241DE4 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0B28 80241DE8 4600B587 */  neg.s     $f22, $f22
/* CB0B2C 80241DEC 4405A000 */  mfc1      $a1, $f20
/* CB0B30 80241DF0 4406B000 */  mfc1      $a2, $f22
/* CB0B34 80241DF4 0C019E40 */  jal       guTranslateF
/* CB0B38 80241DF8 00A0382D */   daddu    $a3, $a1, $zero
/* CB0B3C 80241DFC 27A40010 */  addiu     $a0, $sp, 0x10
/* CB0B40 80241E00 0200282D */  daddu     $a1, $s0, $zero
/* CB0B44 80241E04 0C019D80 */  jal       guMtxCatF
/* CB0B48 80241E08 00A0302D */   daddu    $a2, $a1, $zero
.L80241E0C:
/* CB0B4C 80241E0C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CB0B50 80241E10 8FB20058 */  lw        $s2, 0x58($sp)
/* CB0B54 80241E14 8FB10054 */  lw        $s1, 0x54($sp)
/* CB0B58 80241E18 8FB00050 */  lw        $s0, 0x50($sp)
/* CB0B5C 80241E1C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CB0B60 80241E20 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CB0B64 80241E24 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CB0B68 80241E28 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CB0B6C 80241E2C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CB0B70 80241E30 24020002 */  addiu     $v0, $zero, 2
/* CB0B74 80241E34 03E00008 */  jr        $ra
/* CB0B78 80241E38 27BD0088 */   addiu    $sp, $sp, 0x88
/* CB0B7C 80241E3C 00000000 */  nop       
