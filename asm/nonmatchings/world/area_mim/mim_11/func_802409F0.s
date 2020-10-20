.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F0
/* BB7A60 802409F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* BB7A64 802409F4 AFB10054 */  sw        $s1, 0x54($sp)
/* BB7A68 802409F8 0080882D */  daddu     $s1, $a0, $zero
/* BB7A6C 802409FC AFBF005C */  sw        $ra, 0x5c($sp)
/* BB7A70 80240A00 AFB20058 */  sw        $s2, 0x58($sp)
/* BB7A74 80240A04 AFB00050 */  sw        $s0, 0x50($sp)
/* BB7A78 80240A08 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* BB7A7C 80240A0C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* BB7A80 80240A10 F7B80070 */  sdc1      $f24, 0x70($sp)
/* BB7A84 80240A14 F7B60068 */  sdc1      $f22, 0x68($sp)
/* BB7A88 80240A18 F7B40060 */  sdc1      $f20, 0x60($sp)
/* BB7A8C 80240A1C 8E30000C */  lw        $s0, 0xc($s1)
/* BB7A90 80240A20 8E050000 */  lw        $a1, ($s0)
/* BB7A94 80240A24 0C0B1EAF */  jal       get_variable
/* BB7A98 80240A28 26100004 */   addiu    $s0, $s0, 4
/* BB7A9C 80240A2C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BB7AA0 80240A30 0040202D */   daddu    $a0, $v0, $zero
/* BB7AA4 80240A34 8E050000 */  lw        $a1, ($s0)
/* BB7AA8 80240A38 26100004 */  addiu     $s0, $s0, 4
/* BB7AAC 80240A3C 0220202D */  daddu     $a0, $s1, $zero
/* BB7AB0 80240A40 0C0B210B */  jal       get_float_variable
/* BB7AB4 80240A44 0040902D */   daddu    $s2, $v0, $zero
/* BB7AB8 80240A48 8E050000 */  lw        $a1, ($s0)
/* BB7ABC 80240A4C 26100004 */  addiu     $s0, $s0, 4
/* BB7AC0 80240A50 0220202D */  daddu     $a0, $s1, $zero
/* BB7AC4 80240A54 0C0B210B */  jal       get_float_variable
/* BB7AC8 80240A58 46000706 */   mov.s    $f28, $f0
/* BB7ACC 80240A5C 8E050000 */  lw        $a1, ($s0)
/* BB7AD0 80240A60 26100004 */  addiu     $s0, $s0, 4
/* BB7AD4 80240A64 0220202D */  daddu     $a0, $s1, $zero
/* BB7AD8 80240A68 0C0B210B */  jal       get_float_variable
/* BB7ADC 80240A6C 46000686 */   mov.s    $f26, $f0
/* BB7AE0 80240A70 0220202D */  daddu     $a0, $s1, $zero
/* BB7AE4 80240A74 8E050000 */  lw        $a1, ($s0)
/* BB7AE8 80240A78 0C0B210B */  jal       get_float_variable
/* BB7AEC 80240A7C 46000586 */   mov.s    $f22, $f0
/* BB7AF0 80240A80 0240202D */  daddu     $a0, $s2, $zero
/* BB7AF4 80240A84 0C046B4C */  jal       get_model_from_list_index
/* BB7AF8 80240A88 46000606 */   mov.s    $f24, $f0
/* BB7AFC 80240A8C 0040882D */  daddu     $s1, $v0, $zero
/* BB7B00 80240A90 96220000 */  lhu       $v0, ($s1)
/* BB7B04 80240A94 30420400 */  andi      $v0, $v0, 0x400
/* BB7B08 80240A98 1440001E */  bnez      $v0, .L80240B14
/* BB7B0C 80240A9C 26300058 */   addiu    $s0, $s1, 0x58
/* BB7B10 80240AA0 4480A000 */  mtc1      $zero, $f20
/* BB7B14 80240AA4 4406B000 */  mfc1      $a2, $f22
/* BB7B18 80240AA8 4405A000 */  mfc1      $a1, $f20
/* BB7B1C 80240AAC 4407A000 */  mfc1      $a3, $f20
/* BB7B20 80240AB0 0C019E40 */  jal       guTranslateF
/* BB7B24 80240AB4 0200202D */   daddu    $a0, $s0, $zero
/* BB7B28 80240AB8 4405E000 */  mfc1      $a1, $f28
/* BB7B2C 80240ABC 4406D000 */  mfc1      $a2, $f26
/* BB7B30 80240AC0 4407C000 */  mfc1      $a3, $f24
/* BB7B34 80240AC4 0C090260 */  jal       func_80240980
/* BB7B38 80240AC8 27A40010 */   addiu    $a0, $sp, 0x10
/* BB7B3C 80240ACC 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7B40 80240AD0 0200282D */  daddu     $a1, $s0, $zero
/* BB7B44 80240AD4 0C019D80 */  jal       guMtxCatF
/* BB7B48 80240AD8 0200302D */   daddu    $a2, $s0, $zero
/* BB7B4C 80240ADC 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7B50 80240AE0 4600B587 */  neg.s     $f22, $f22
/* BB7B54 80240AE4 4405A000 */  mfc1      $a1, $f20
/* BB7B58 80240AE8 4406B000 */  mfc1      $a2, $f22
/* BB7B5C 80240AEC 0C019E40 */  jal       guTranslateF
/* BB7B60 80240AF0 00A0382D */   daddu    $a3, $a1, $zero
/* BB7B64 80240AF4 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7B68 80240AF8 0200282D */  daddu     $a1, $s0, $zero
/* BB7B6C 80240AFC 0C019D80 */  jal       guMtxCatF
/* BB7B70 80240B00 00A0302D */   daddu    $a2, $a1, $zero
/* BB7B74 80240B04 96220000 */  lhu       $v0, ($s1)
/* BB7B78 80240B08 34421400 */  ori       $v0, $v0, 0x1400
/* BB7B7C 80240B0C 080902E3 */  j         .L80240B8C
/* BB7B80 80240B10 A6220000 */   sh       $v0, ($s1)
.L80240B14:
/* BB7B84 80240B14 4480A000 */  mtc1      $zero, $f20
/* BB7B88 80240B18 4406B000 */  mfc1      $a2, $f22
/* BB7B8C 80240B1C 4405A000 */  mfc1      $a1, $f20
/* BB7B90 80240B20 4407A000 */  mfc1      $a3, $f20
/* BB7B94 80240B24 0C019E40 */  jal       guTranslateF
/* BB7B98 80240B28 27A40010 */   addiu    $a0, $sp, 0x10
/* BB7B9C 80240B2C 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7BA0 80240B30 26300058 */  addiu     $s0, $s1, 0x58
/* BB7BA4 80240B34 0200282D */  daddu     $a1, $s0, $zero
/* BB7BA8 80240B38 0C019D80 */  jal       guMtxCatF
/* BB7BAC 80240B3C 0200302D */   daddu    $a2, $s0, $zero
/* BB7BB0 80240B40 4405E000 */  mfc1      $a1, $f28
/* BB7BB4 80240B44 4406D000 */  mfc1      $a2, $f26
/* BB7BB8 80240B48 4407C000 */  mfc1      $a3, $f24
/* BB7BBC 80240B4C 0C090260 */  jal       func_80240980
/* BB7BC0 80240B50 27A40010 */   addiu    $a0, $sp, 0x10
/* BB7BC4 80240B54 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7BC8 80240B58 0200282D */  daddu     $a1, $s0, $zero
/* BB7BCC 80240B5C 0C019D80 */  jal       guMtxCatF
/* BB7BD0 80240B60 0200302D */   daddu    $a2, $s0, $zero
/* BB7BD4 80240B64 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7BD8 80240B68 4600B587 */  neg.s     $f22, $f22
/* BB7BDC 80240B6C 4405A000 */  mfc1      $a1, $f20
/* BB7BE0 80240B70 4406B000 */  mfc1      $a2, $f22
/* BB7BE4 80240B74 0C019E40 */  jal       guTranslateF
/* BB7BE8 80240B78 00A0382D */   daddu    $a3, $a1, $zero
/* BB7BEC 80240B7C 27A40010 */  addiu     $a0, $sp, 0x10
/* BB7BF0 80240B80 0200282D */  daddu     $a1, $s0, $zero
/* BB7BF4 80240B84 0C019D80 */  jal       guMtxCatF
/* BB7BF8 80240B88 00A0302D */   daddu    $a2, $a1, $zero
.L80240B8C:
/* BB7BFC 80240B8C 8FBF005C */  lw        $ra, 0x5c($sp)
/* BB7C00 80240B90 8FB20058 */  lw        $s2, 0x58($sp)
/* BB7C04 80240B94 8FB10054 */  lw        $s1, 0x54($sp)
/* BB7C08 80240B98 8FB00050 */  lw        $s0, 0x50($sp)
/* BB7C0C 80240B9C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* BB7C10 80240BA0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* BB7C14 80240BA4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* BB7C18 80240BA8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* BB7C1C 80240BAC D7B40060 */  ldc1      $f20, 0x60($sp)
/* BB7C20 80240BB0 24020002 */  addiu     $v0, $zero, 2
/* BB7C24 80240BB4 03E00008 */  jr        $ra
/* BB7C28 80240BB8 27BD0088 */   addiu    $sp, $sp, 0x88
/* BB7C2C 80240BBC 00000000 */  nop       
