.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AD0
/* 8ED8F0 80241AD0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 8ED8F4 80241AD4 AFB10054 */  sw        $s1, 0x54($sp)
/* 8ED8F8 80241AD8 0080882D */  daddu     $s1, $a0, $zero
/* 8ED8FC 80241ADC AFBF005C */  sw        $ra, 0x5c($sp)
/* 8ED900 80241AE0 AFB20058 */  sw        $s2, 0x58($sp)
/* 8ED904 80241AE4 AFB00050 */  sw        $s0, 0x50($sp)
/* 8ED908 80241AE8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 8ED90C 80241AEC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 8ED910 80241AF0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 8ED914 80241AF4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 8ED918 80241AF8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 8ED91C 80241AFC 8E30000C */  lw        $s0, 0xc($s1)
/* 8ED920 80241B00 8E050000 */  lw        $a1, ($s0)
/* 8ED924 80241B04 0C0B1EAF */  jal       get_variable
/* 8ED928 80241B08 26100004 */   addiu    $s0, $s0, 4
/* 8ED92C 80241B0C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8ED930 80241B10 0040202D */   daddu    $a0, $v0, $zero
/* 8ED934 80241B14 8E050000 */  lw        $a1, ($s0)
/* 8ED938 80241B18 26100004 */  addiu     $s0, $s0, 4
/* 8ED93C 80241B1C 0220202D */  daddu     $a0, $s1, $zero
/* 8ED940 80241B20 0C0B210B */  jal       get_float_variable
/* 8ED944 80241B24 0040902D */   daddu    $s2, $v0, $zero
/* 8ED948 80241B28 8E050000 */  lw        $a1, ($s0)
/* 8ED94C 80241B2C 26100004 */  addiu     $s0, $s0, 4
/* 8ED950 80241B30 0220202D */  daddu     $a0, $s1, $zero
/* 8ED954 80241B34 0C0B210B */  jal       get_float_variable
/* 8ED958 80241B38 46000706 */   mov.s    $f28, $f0
/* 8ED95C 80241B3C 8E050000 */  lw        $a1, ($s0)
/* 8ED960 80241B40 26100004 */  addiu     $s0, $s0, 4
/* 8ED964 80241B44 0220202D */  daddu     $a0, $s1, $zero
/* 8ED968 80241B48 0C0B210B */  jal       get_float_variable
/* 8ED96C 80241B4C 46000686 */   mov.s    $f26, $f0
/* 8ED970 80241B50 0220202D */  daddu     $a0, $s1, $zero
/* 8ED974 80241B54 8E050000 */  lw        $a1, ($s0)
/* 8ED978 80241B58 0C0B210B */  jal       get_float_variable
/* 8ED97C 80241B5C 46000586 */   mov.s    $f22, $f0
/* 8ED980 80241B60 0240202D */  daddu     $a0, $s2, $zero
/* 8ED984 80241B64 0C046B4C */  jal       get_model_from_list_index
/* 8ED988 80241B68 46000606 */   mov.s    $f24, $f0
/* 8ED98C 80241B6C 0040882D */  daddu     $s1, $v0, $zero
/* 8ED990 80241B70 96220000 */  lhu       $v0, ($s1)
/* 8ED994 80241B74 30420400 */  andi      $v0, $v0, 0x400
/* 8ED998 80241B78 1440001E */  bnez      $v0, .L80241BF4
/* 8ED99C 80241B7C 26300058 */   addiu    $s0, $s1, 0x58
/* 8ED9A0 80241B80 4480A000 */  mtc1      $zero, $f20
/* 8ED9A4 80241B84 4406B000 */  mfc1      $a2, $f22
/* 8ED9A8 80241B88 4405A000 */  mfc1      $a1, $f20
/* 8ED9AC 80241B8C 4407A000 */  mfc1      $a3, $f20
/* 8ED9B0 80241B90 0C019E40 */  jal       guTranslateF
/* 8ED9B4 80241B94 0200202D */   daddu    $a0, $s0, $zero
/* 8ED9B8 80241B98 4405E000 */  mfc1      $a1, $f28
/* 8ED9BC 80241B9C 4406D000 */  mfc1      $a2, $f26
/* 8ED9C0 80241BA0 4407C000 */  mfc1      $a3, $f24
/* 8ED9C4 80241BA4 0C090698 */  jal       func_80241A60
/* 8ED9C8 80241BA8 27A40010 */   addiu    $a0, $sp, 0x10
/* 8ED9CC 80241BAC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED9D0 80241BB0 0200282D */  daddu     $a1, $s0, $zero
/* 8ED9D4 80241BB4 0C019D80 */  jal       guMtxCatF
/* 8ED9D8 80241BB8 0200302D */   daddu    $a2, $s0, $zero
/* 8ED9DC 80241BBC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED9E0 80241BC0 4600B587 */  neg.s     $f22, $f22
/* 8ED9E4 80241BC4 4405A000 */  mfc1      $a1, $f20
/* 8ED9E8 80241BC8 4406B000 */  mfc1      $a2, $f22
/* 8ED9EC 80241BCC 0C019E40 */  jal       guTranslateF
/* 8ED9F0 80241BD0 00A0382D */   daddu    $a3, $a1, $zero
/* 8ED9F4 80241BD4 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED9F8 80241BD8 0200282D */  daddu     $a1, $s0, $zero
/* 8ED9FC 80241BDC 0C019D80 */  jal       guMtxCatF
/* 8EDA00 80241BE0 00A0302D */   daddu    $a2, $a1, $zero
/* 8EDA04 80241BE4 96220000 */  lhu       $v0, ($s1)
/* 8EDA08 80241BE8 34421400 */  ori       $v0, $v0, 0x1400
/* 8EDA0C 80241BEC 0809071B */  j         .L80241C6C
/* 8EDA10 80241BF0 A6220000 */   sh       $v0, ($s1)
.L80241BF4:
/* 8EDA14 80241BF4 4480A000 */  mtc1      $zero, $f20
/* 8EDA18 80241BF8 4406B000 */  mfc1      $a2, $f22
/* 8EDA1C 80241BFC 4405A000 */  mfc1      $a1, $f20
/* 8EDA20 80241C00 4407A000 */  mfc1      $a3, $f20
/* 8EDA24 80241C04 0C019E40 */  jal       guTranslateF
/* 8EDA28 80241C08 27A40010 */   addiu    $a0, $sp, 0x10
/* 8EDA2C 80241C0C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EDA30 80241C10 26300058 */  addiu     $s0, $s1, 0x58
/* 8EDA34 80241C14 0200282D */  daddu     $a1, $s0, $zero
/* 8EDA38 80241C18 0C019D80 */  jal       guMtxCatF
/* 8EDA3C 80241C1C 0200302D */   daddu    $a2, $s0, $zero
/* 8EDA40 80241C20 4405E000 */  mfc1      $a1, $f28
/* 8EDA44 80241C24 4406D000 */  mfc1      $a2, $f26
/* 8EDA48 80241C28 4407C000 */  mfc1      $a3, $f24
/* 8EDA4C 80241C2C 0C090698 */  jal       func_80241A60
/* 8EDA50 80241C30 27A40010 */   addiu    $a0, $sp, 0x10
/* 8EDA54 80241C34 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EDA58 80241C38 0200282D */  daddu     $a1, $s0, $zero
/* 8EDA5C 80241C3C 0C019D80 */  jal       guMtxCatF
/* 8EDA60 80241C40 0200302D */   daddu    $a2, $s0, $zero
/* 8EDA64 80241C44 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EDA68 80241C48 4600B587 */  neg.s     $f22, $f22
/* 8EDA6C 80241C4C 4405A000 */  mfc1      $a1, $f20
/* 8EDA70 80241C50 4406B000 */  mfc1      $a2, $f22
/* 8EDA74 80241C54 0C019E40 */  jal       guTranslateF
/* 8EDA78 80241C58 00A0382D */   daddu    $a3, $a1, $zero
/* 8EDA7C 80241C5C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EDA80 80241C60 0200282D */  daddu     $a1, $s0, $zero
/* 8EDA84 80241C64 0C019D80 */  jal       guMtxCatF
/* 8EDA88 80241C68 00A0302D */   daddu    $a2, $a1, $zero
.L80241C6C:
/* 8EDA8C 80241C6C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 8EDA90 80241C70 8FB20058 */  lw        $s2, 0x58($sp)
/* 8EDA94 80241C74 8FB10054 */  lw        $s1, 0x54($sp)
/* 8EDA98 80241C78 8FB00050 */  lw        $s0, 0x50($sp)
/* 8EDA9C 80241C7C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 8EDAA0 80241C80 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 8EDAA4 80241C84 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 8EDAA8 80241C88 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 8EDAAC 80241C8C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 8EDAB0 80241C90 24020002 */  addiu     $v0, $zero, 2
/* 8EDAB4 80241C94 03E00008 */  jr        $ra
/* 8EDAB8 80241C98 27BD0088 */   addiu    $sp, $sp, 0x88
