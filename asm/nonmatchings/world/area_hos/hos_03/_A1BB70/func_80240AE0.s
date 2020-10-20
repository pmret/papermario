.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE0
/* A1BBE0 80240AE0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* A1BBE4 80240AE4 AFB10054 */  sw        $s1, 0x54($sp)
/* A1BBE8 80240AE8 0080882D */  daddu     $s1, $a0, $zero
/* A1BBEC 80240AEC AFBF005C */  sw        $ra, 0x5c($sp)
/* A1BBF0 80240AF0 AFB20058 */  sw        $s2, 0x58($sp)
/* A1BBF4 80240AF4 AFB00050 */  sw        $s0, 0x50($sp)
/* A1BBF8 80240AF8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* A1BBFC 80240AFC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* A1BC00 80240B00 F7B80070 */  sdc1      $f24, 0x70($sp)
/* A1BC04 80240B04 F7B60068 */  sdc1      $f22, 0x68($sp)
/* A1BC08 80240B08 F7B40060 */  sdc1      $f20, 0x60($sp)
/* A1BC0C 80240B0C 8E30000C */  lw        $s0, 0xc($s1)
/* A1BC10 80240B10 8E050000 */  lw        $a1, ($s0)
/* A1BC14 80240B14 0C0B1EAF */  jal       get_variable
/* A1BC18 80240B18 26100004 */   addiu    $s0, $s0, 4
/* A1BC1C 80240B1C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A1BC20 80240B20 0040202D */   daddu    $a0, $v0, $zero
/* A1BC24 80240B24 8E050000 */  lw        $a1, ($s0)
/* A1BC28 80240B28 26100004 */  addiu     $s0, $s0, 4
/* A1BC2C 80240B2C 0220202D */  daddu     $a0, $s1, $zero
/* A1BC30 80240B30 0C0B210B */  jal       get_float_variable
/* A1BC34 80240B34 0040902D */   daddu    $s2, $v0, $zero
/* A1BC38 80240B38 8E050000 */  lw        $a1, ($s0)
/* A1BC3C 80240B3C 26100004 */  addiu     $s0, $s0, 4
/* A1BC40 80240B40 0220202D */  daddu     $a0, $s1, $zero
/* A1BC44 80240B44 0C0B210B */  jal       get_float_variable
/* A1BC48 80240B48 46000706 */   mov.s    $f28, $f0
/* A1BC4C 80240B4C 8E050000 */  lw        $a1, ($s0)
/* A1BC50 80240B50 26100004 */  addiu     $s0, $s0, 4
/* A1BC54 80240B54 0220202D */  daddu     $a0, $s1, $zero
/* A1BC58 80240B58 0C0B210B */  jal       get_float_variable
/* A1BC5C 80240B5C 46000686 */   mov.s    $f26, $f0
/* A1BC60 80240B60 0220202D */  daddu     $a0, $s1, $zero
/* A1BC64 80240B64 8E050000 */  lw        $a1, ($s0)
/* A1BC68 80240B68 0C0B210B */  jal       get_float_variable
/* A1BC6C 80240B6C 46000586 */   mov.s    $f22, $f0
/* A1BC70 80240B70 0240202D */  daddu     $a0, $s2, $zero
/* A1BC74 80240B74 0C046B4C */  jal       get_model_from_list_index
/* A1BC78 80240B78 46000606 */   mov.s    $f24, $f0
/* A1BC7C 80240B7C 0040882D */  daddu     $s1, $v0, $zero
/* A1BC80 80240B80 96220000 */  lhu       $v0, ($s1)
/* A1BC84 80240B84 30420400 */  andi      $v0, $v0, 0x400
/* A1BC88 80240B88 1440001E */  bnez      $v0, .L80240C04
/* A1BC8C 80240B8C 26300058 */   addiu    $s0, $s1, 0x58
/* A1BC90 80240B90 4480A000 */  mtc1      $zero, $f20
/* A1BC94 80240B94 4406B000 */  mfc1      $a2, $f22
/* A1BC98 80240B98 4405A000 */  mfc1      $a1, $f20
/* A1BC9C 80240B9C 4407A000 */  mfc1      $a3, $f20
/* A1BCA0 80240BA0 0C019E40 */  jal       guTranslateF
/* A1BCA4 80240BA4 0200202D */   daddu    $a0, $s0, $zero
/* A1BCA8 80240BA8 4405E000 */  mfc1      $a1, $f28
/* A1BCAC 80240BAC 4406D000 */  mfc1      $a2, $f26
/* A1BCB0 80240BB0 4407C000 */  mfc1      $a3, $f24
/* A1BCB4 80240BB4 0C09029C */  jal       func_80240A70
/* A1BCB8 80240BB8 27A40010 */   addiu    $a0, $sp, 0x10
/* A1BCBC 80240BBC 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BCC0 80240BC0 0200282D */  daddu     $a1, $s0, $zero
/* A1BCC4 80240BC4 0C019D80 */  jal       guMtxCatF
/* A1BCC8 80240BC8 0200302D */   daddu    $a2, $s0, $zero
/* A1BCCC 80240BCC 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BCD0 80240BD0 4600B587 */  neg.s     $f22, $f22
/* A1BCD4 80240BD4 4405A000 */  mfc1      $a1, $f20
/* A1BCD8 80240BD8 4406B000 */  mfc1      $a2, $f22
/* A1BCDC 80240BDC 0C019E40 */  jal       guTranslateF
/* A1BCE0 80240BE0 00A0382D */   daddu    $a3, $a1, $zero
/* A1BCE4 80240BE4 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BCE8 80240BE8 0200282D */  daddu     $a1, $s0, $zero
/* A1BCEC 80240BEC 0C019D80 */  jal       guMtxCatF
/* A1BCF0 80240BF0 00A0302D */   daddu    $a2, $a1, $zero
/* A1BCF4 80240BF4 96220000 */  lhu       $v0, ($s1)
/* A1BCF8 80240BF8 34421400 */  ori       $v0, $v0, 0x1400
/* A1BCFC 80240BFC 0809031F */  j         .L80240C7C
/* A1BD00 80240C00 A6220000 */   sh       $v0, ($s1)
.L80240C04:
/* A1BD04 80240C04 4480A000 */  mtc1      $zero, $f20
/* A1BD08 80240C08 4406B000 */  mfc1      $a2, $f22
/* A1BD0C 80240C0C 4405A000 */  mfc1      $a1, $f20
/* A1BD10 80240C10 4407A000 */  mfc1      $a3, $f20
/* A1BD14 80240C14 0C019E40 */  jal       guTranslateF
/* A1BD18 80240C18 27A40010 */   addiu    $a0, $sp, 0x10
/* A1BD1C 80240C1C 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BD20 80240C20 26300058 */  addiu     $s0, $s1, 0x58
/* A1BD24 80240C24 0200282D */  daddu     $a1, $s0, $zero
/* A1BD28 80240C28 0C019D80 */  jal       guMtxCatF
/* A1BD2C 80240C2C 0200302D */   daddu    $a2, $s0, $zero
/* A1BD30 80240C30 4405E000 */  mfc1      $a1, $f28
/* A1BD34 80240C34 4406D000 */  mfc1      $a2, $f26
/* A1BD38 80240C38 4407C000 */  mfc1      $a3, $f24
/* A1BD3C 80240C3C 0C09029C */  jal       func_80240A70
/* A1BD40 80240C40 27A40010 */   addiu    $a0, $sp, 0x10
/* A1BD44 80240C44 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BD48 80240C48 0200282D */  daddu     $a1, $s0, $zero
/* A1BD4C 80240C4C 0C019D80 */  jal       guMtxCatF
/* A1BD50 80240C50 0200302D */   daddu    $a2, $s0, $zero
/* A1BD54 80240C54 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BD58 80240C58 4600B587 */  neg.s     $f22, $f22
/* A1BD5C 80240C5C 4405A000 */  mfc1      $a1, $f20
/* A1BD60 80240C60 4406B000 */  mfc1      $a2, $f22
/* A1BD64 80240C64 0C019E40 */  jal       guTranslateF
/* A1BD68 80240C68 00A0382D */   daddu    $a3, $a1, $zero
/* A1BD6C 80240C6C 27A40010 */  addiu     $a0, $sp, 0x10
/* A1BD70 80240C70 0200282D */  daddu     $a1, $s0, $zero
/* A1BD74 80240C74 0C019D80 */  jal       guMtxCatF
/* A1BD78 80240C78 00A0302D */   daddu    $a2, $a1, $zero
.L80240C7C:
/* A1BD7C 80240C7C 8FBF005C */  lw        $ra, 0x5c($sp)
/* A1BD80 80240C80 8FB20058 */  lw        $s2, 0x58($sp)
/* A1BD84 80240C84 8FB10054 */  lw        $s1, 0x54($sp)
/* A1BD88 80240C88 8FB00050 */  lw        $s0, 0x50($sp)
/* A1BD8C 80240C8C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* A1BD90 80240C90 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* A1BD94 80240C94 D7B80070 */  ldc1      $f24, 0x70($sp)
/* A1BD98 80240C98 D7B60068 */  ldc1      $f22, 0x68($sp)
/* A1BD9C 80240C9C D7B40060 */  ldc1      $f20, 0x60($sp)
/* A1BDA0 80240CA0 24020002 */  addiu     $v0, $zero, 2
/* A1BDA4 80240CA4 03E00008 */  jr        $ra
/* A1BDA8 80240CA8 27BD0088 */   addiu    $sp, $sp, 0x88
/* A1BDAC 80240CAC 00000000 */  nop       
