.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419D0_B21F10
/* B21F10 802419D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B21F14 802419D4 AFB10054 */  sw        $s1, 0x54($sp)
/* B21F18 802419D8 0080882D */  daddu     $s1, $a0, $zero
/* B21F1C 802419DC AFBF005C */  sw        $ra, 0x5c($sp)
/* B21F20 802419E0 AFB20058 */  sw        $s2, 0x58($sp)
/* B21F24 802419E4 AFB00050 */  sw        $s0, 0x50($sp)
/* B21F28 802419E8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B21F2C 802419EC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B21F30 802419F0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B21F34 802419F4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B21F38 802419F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B21F3C 802419FC 8E30000C */  lw        $s0, 0xc($s1)
/* B21F40 80241A00 8E050000 */  lw        $a1, ($s0)
/* B21F44 80241A04 0C0B1EAF */  jal       get_variable
/* B21F48 80241A08 26100004 */   addiu    $s0, $s0, 4
/* B21F4C 80241A0C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B21F50 80241A10 0040202D */   daddu    $a0, $v0, $zero
/* B21F54 80241A14 8E050000 */  lw        $a1, ($s0)
/* B21F58 80241A18 26100004 */  addiu     $s0, $s0, 4
/* B21F5C 80241A1C 0220202D */  daddu     $a0, $s1, $zero
/* B21F60 80241A20 0C0B210B */  jal       get_float_variable
/* B21F64 80241A24 0040902D */   daddu    $s2, $v0, $zero
/* B21F68 80241A28 8E050000 */  lw        $a1, ($s0)
/* B21F6C 80241A2C 26100004 */  addiu     $s0, $s0, 4
/* B21F70 80241A30 0220202D */  daddu     $a0, $s1, $zero
/* B21F74 80241A34 0C0B210B */  jal       get_float_variable
/* B21F78 80241A38 46000706 */   mov.s    $f28, $f0
/* B21F7C 80241A3C 8E050000 */  lw        $a1, ($s0)
/* B21F80 80241A40 26100004 */  addiu     $s0, $s0, 4
/* B21F84 80241A44 0220202D */  daddu     $a0, $s1, $zero
/* B21F88 80241A48 0C0B210B */  jal       get_float_variable
/* B21F8C 80241A4C 46000686 */   mov.s    $f26, $f0
/* B21F90 80241A50 0220202D */  daddu     $a0, $s1, $zero
/* B21F94 80241A54 8E050000 */  lw        $a1, ($s0)
/* B21F98 80241A58 0C0B210B */  jal       get_float_variable
/* B21F9C 80241A5C 46000586 */   mov.s    $f22, $f0
/* B21FA0 80241A60 0240202D */  daddu     $a0, $s2, $zero
/* B21FA4 80241A64 0C046B4C */  jal       get_model_from_list_index
/* B21FA8 80241A68 46000606 */   mov.s    $f24, $f0
/* B21FAC 80241A6C 0040882D */  daddu     $s1, $v0, $zero
/* B21FB0 80241A70 96220000 */  lhu       $v0, ($s1)
/* B21FB4 80241A74 30420400 */  andi      $v0, $v0, 0x400
/* B21FB8 80241A78 1440001E */  bnez      $v0, .L80241AF4
/* B21FBC 80241A7C 26300058 */   addiu    $s0, $s1, 0x58
/* B21FC0 80241A80 4480A000 */  mtc1      $zero, $f20
/* B21FC4 80241A84 4406B000 */  mfc1      $a2, $f22
/* B21FC8 80241A88 4405A000 */  mfc1      $a1, $f20
/* B21FCC 80241A8C 4407A000 */  mfc1      $a3, $f20
/* B21FD0 80241A90 0C019E40 */  jal       guTranslateF
/* B21FD4 80241A94 0200202D */   daddu    $a0, $s0, $zero
/* B21FD8 80241A98 4405E000 */  mfc1      $a1, $f28
/* B21FDC 80241A9C 4406D000 */  mfc1      $a2, $f26
/* B21FE0 80241AA0 4407C000 */  mfc1      $a3, $f24
/* B21FE4 80241AA4 0C090658 */  jal       func_80241960
/* B21FE8 80241AA8 27A40010 */   addiu    $a0, $sp, 0x10
/* B21FEC 80241AAC 27A40010 */  addiu     $a0, $sp, 0x10
/* B21FF0 80241AB0 0200282D */  daddu     $a1, $s0, $zero
/* B21FF4 80241AB4 0C019D80 */  jal       guMtxCatF
/* B21FF8 80241AB8 0200302D */   daddu    $a2, $s0, $zero
/* B21FFC 80241ABC 27A40010 */  addiu     $a0, $sp, 0x10
/* B22000 80241AC0 4600B587 */  neg.s     $f22, $f22
/* B22004 80241AC4 4405A000 */  mfc1      $a1, $f20
/* B22008 80241AC8 4406B000 */  mfc1      $a2, $f22
/* B2200C 80241ACC 0C019E40 */  jal       guTranslateF
/* B22010 80241AD0 00A0382D */   daddu    $a3, $a1, $zero
/* B22014 80241AD4 27A40010 */  addiu     $a0, $sp, 0x10
/* B22018 80241AD8 0200282D */  daddu     $a1, $s0, $zero
/* B2201C 80241ADC 0C019D80 */  jal       guMtxCatF
/* B22020 80241AE0 00A0302D */   daddu    $a2, $a1, $zero
/* B22024 80241AE4 96220000 */  lhu       $v0, ($s1)
/* B22028 80241AE8 34421400 */  ori       $v0, $v0, 0x1400
/* B2202C 80241AEC 080906DB */  j         .L80241B6C
/* B22030 80241AF0 A6220000 */   sh       $v0, ($s1)
.L80241AF4:
/* B22034 80241AF4 4480A000 */  mtc1      $zero, $f20
/* B22038 80241AF8 4406B000 */  mfc1      $a2, $f22
/* B2203C 80241AFC 4405A000 */  mfc1      $a1, $f20
/* B22040 80241B00 4407A000 */  mfc1      $a3, $f20
/* B22044 80241B04 0C019E40 */  jal       guTranslateF
/* B22048 80241B08 27A40010 */   addiu    $a0, $sp, 0x10
/* B2204C 80241B0C 27A40010 */  addiu     $a0, $sp, 0x10
/* B22050 80241B10 26300058 */  addiu     $s0, $s1, 0x58
/* B22054 80241B14 0200282D */  daddu     $a1, $s0, $zero
/* B22058 80241B18 0C019D80 */  jal       guMtxCatF
/* B2205C 80241B1C 0200302D */   daddu    $a2, $s0, $zero
/* B22060 80241B20 4405E000 */  mfc1      $a1, $f28
/* B22064 80241B24 4406D000 */  mfc1      $a2, $f26
/* B22068 80241B28 4407C000 */  mfc1      $a3, $f24
/* B2206C 80241B2C 0C090658 */  jal       func_80241960
/* B22070 80241B30 27A40010 */   addiu    $a0, $sp, 0x10
/* B22074 80241B34 27A40010 */  addiu     $a0, $sp, 0x10
/* B22078 80241B38 0200282D */  daddu     $a1, $s0, $zero
/* B2207C 80241B3C 0C019D80 */  jal       guMtxCatF
/* B22080 80241B40 0200302D */   daddu    $a2, $s0, $zero
/* B22084 80241B44 27A40010 */  addiu     $a0, $sp, 0x10
/* B22088 80241B48 4600B587 */  neg.s     $f22, $f22
/* B2208C 80241B4C 4405A000 */  mfc1      $a1, $f20
/* B22090 80241B50 4406B000 */  mfc1      $a2, $f22
/* B22094 80241B54 0C019E40 */  jal       guTranslateF
/* B22098 80241B58 00A0382D */   daddu    $a3, $a1, $zero
/* B2209C 80241B5C 27A40010 */  addiu     $a0, $sp, 0x10
/* B220A0 80241B60 0200282D */  daddu     $a1, $s0, $zero
/* B220A4 80241B64 0C019D80 */  jal       guMtxCatF
/* B220A8 80241B68 00A0302D */   daddu    $a2, $a1, $zero
.L80241B6C:
/* B220AC 80241B6C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B220B0 80241B70 8FB20058 */  lw        $s2, 0x58($sp)
/* B220B4 80241B74 8FB10054 */  lw        $s1, 0x54($sp)
/* B220B8 80241B78 8FB00050 */  lw        $s0, 0x50($sp)
/* B220BC 80241B7C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B220C0 80241B80 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B220C4 80241B84 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B220C8 80241B88 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B220CC 80241B8C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B220D0 80241B90 24020002 */  addiu     $v0, $zero, 2
/* B220D4 80241B94 03E00008 */  jr        $ra
/* B220D8 80241B98 27BD0088 */   addiu    $sp, $sp, 0x88
/* B220DC 80241B9C 00000000 */  nop       
