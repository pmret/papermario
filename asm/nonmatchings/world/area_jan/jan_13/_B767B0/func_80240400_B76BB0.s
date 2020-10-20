.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240400_B76BB0
/* B76BB0 80240400 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B76BB4 80240404 AFB10054 */  sw        $s1, 0x54($sp)
/* B76BB8 80240408 0080882D */  daddu     $s1, $a0, $zero
/* B76BBC 8024040C AFBF005C */  sw        $ra, 0x5c($sp)
/* B76BC0 80240410 AFB20058 */  sw        $s2, 0x58($sp)
/* B76BC4 80240414 AFB00050 */  sw        $s0, 0x50($sp)
/* B76BC8 80240418 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B76BCC 8024041C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B76BD0 80240420 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B76BD4 80240424 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B76BD8 80240428 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B76BDC 8024042C 8E30000C */  lw        $s0, 0xc($s1)
/* B76BE0 80240430 8E050000 */  lw        $a1, ($s0)
/* B76BE4 80240434 0C0B1EAF */  jal       get_variable
/* B76BE8 80240438 26100004 */   addiu    $s0, $s0, 4
/* B76BEC 8024043C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B76BF0 80240440 0040202D */   daddu    $a0, $v0, $zero
/* B76BF4 80240444 8E050000 */  lw        $a1, ($s0)
/* B76BF8 80240448 26100004 */  addiu     $s0, $s0, 4
/* B76BFC 8024044C 0220202D */  daddu     $a0, $s1, $zero
/* B76C00 80240450 0C0B210B */  jal       get_float_variable
/* B76C04 80240454 0040902D */   daddu    $s2, $v0, $zero
/* B76C08 80240458 8E050000 */  lw        $a1, ($s0)
/* B76C0C 8024045C 26100004 */  addiu     $s0, $s0, 4
/* B76C10 80240460 0220202D */  daddu     $a0, $s1, $zero
/* B76C14 80240464 0C0B210B */  jal       get_float_variable
/* B76C18 80240468 46000706 */   mov.s    $f28, $f0
/* B76C1C 8024046C 8E050000 */  lw        $a1, ($s0)
/* B76C20 80240470 26100004 */  addiu     $s0, $s0, 4
/* B76C24 80240474 0220202D */  daddu     $a0, $s1, $zero
/* B76C28 80240478 0C0B210B */  jal       get_float_variable
/* B76C2C 8024047C 46000686 */   mov.s    $f26, $f0
/* B76C30 80240480 0220202D */  daddu     $a0, $s1, $zero
/* B76C34 80240484 8E050000 */  lw        $a1, ($s0)
/* B76C38 80240488 0C0B210B */  jal       get_float_variable
/* B76C3C 8024048C 46000586 */   mov.s    $f22, $f0
/* B76C40 80240490 0240202D */  daddu     $a0, $s2, $zero
/* B76C44 80240494 0C046B4C */  jal       get_model_from_list_index
/* B76C48 80240498 46000606 */   mov.s    $f24, $f0
/* B76C4C 8024049C 0040882D */  daddu     $s1, $v0, $zero
/* B76C50 802404A0 96220000 */  lhu       $v0, ($s1)
/* B76C54 802404A4 30420400 */  andi      $v0, $v0, 0x400
/* B76C58 802404A8 1440001E */  bnez      $v0, .L80240524
/* B76C5C 802404AC 26300058 */   addiu    $s0, $s1, 0x58
/* B76C60 802404B0 4480A000 */  mtc1      $zero, $f20
/* B76C64 802404B4 4406B000 */  mfc1      $a2, $f22
/* B76C68 802404B8 4405A000 */  mfc1      $a1, $f20
/* B76C6C 802404BC 4407A000 */  mfc1      $a3, $f20
/* B76C70 802404C0 0C019E40 */  jal       guTranslateF
/* B76C74 802404C4 0200202D */   daddu    $a0, $s0, $zero
/* B76C78 802404C8 4405E000 */  mfc1      $a1, $f28
/* B76C7C 802404CC 4406D000 */  mfc1      $a2, $f26
/* B76C80 802404D0 4407C000 */  mfc1      $a3, $f24
/* B76C84 802404D4 0C0900E4 */  jal       func_80240390
/* B76C88 802404D8 27A40010 */   addiu    $a0, $sp, 0x10
/* B76C8C 802404DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B76C90 802404E0 0200282D */  daddu     $a1, $s0, $zero
/* B76C94 802404E4 0C019D80 */  jal       guMtxCatF
/* B76C98 802404E8 0200302D */   daddu    $a2, $s0, $zero
/* B76C9C 802404EC 27A40010 */  addiu     $a0, $sp, 0x10
/* B76CA0 802404F0 4600B587 */  neg.s     $f22, $f22
/* B76CA4 802404F4 4405A000 */  mfc1      $a1, $f20
/* B76CA8 802404F8 4406B000 */  mfc1      $a2, $f22
/* B76CAC 802404FC 0C019E40 */  jal       guTranslateF
/* B76CB0 80240500 00A0382D */   daddu    $a3, $a1, $zero
/* B76CB4 80240504 27A40010 */  addiu     $a0, $sp, 0x10
/* B76CB8 80240508 0200282D */  daddu     $a1, $s0, $zero
/* B76CBC 8024050C 0C019D80 */  jal       guMtxCatF
/* B76CC0 80240510 00A0302D */   daddu    $a2, $a1, $zero
/* B76CC4 80240514 96220000 */  lhu       $v0, ($s1)
/* B76CC8 80240518 34421400 */  ori       $v0, $v0, 0x1400
/* B76CCC 8024051C 08090167 */  j         .L8024059C
/* B76CD0 80240520 A6220000 */   sh       $v0, ($s1)
.L80240524:
/* B76CD4 80240524 4480A000 */  mtc1      $zero, $f20
/* B76CD8 80240528 4406B000 */  mfc1      $a2, $f22
/* B76CDC 8024052C 4405A000 */  mfc1      $a1, $f20
/* B76CE0 80240530 4407A000 */  mfc1      $a3, $f20
/* B76CE4 80240534 0C019E40 */  jal       guTranslateF
/* B76CE8 80240538 27A40010 */   addiu    $a0, $sp, 0x10
/* B76CEC 8024053C 27A40010 */  addiu     $a0, $sp, 0x10
/* B76CF0 80240540 26300058 */  addiu     $s0, $s1, 0x58
/* B76CF4 80240544 0200282D */  daddu     $a1, $s0, $zero
/* B76CF8 80240548 0C019D80 */  jal       guMtxCatF
/* B76CFC 8024054C 0200302D */   daddu    $a2, $s0, $zero
/* B76D00 80240550 4405E000 */  mfc1      $a1, $f28
/* B76D04 80240554 4406D000 */  mfc1      $a2, $f26
/* B76D08 80240558 4407C000 */  mfc1      $a3, $f24
/* B76D0C 8024055C 0C0900E4 */  jal       func_80240390
/* B76D10 80240560 27A40010 */   addiu    $a0, $sp, 0x10
/* B76D14 80240564 27A40010 */  addiu     $a0, $sp, 0x10
/* B76D18 80240568 0200282D */  daddu     $a1, $s0, $zero
/* B76D1C 8024056C 0C019D80 */  jal       guMtxCatF
/* B76D20 80240570 0200302D */   daddu    $a2, $s0, $zero
/* B76D24 80240574 27A40010 */  addiu     $a0, $sp, 0x10
/* B76D28 80240578 4600B587 */  neg.s     $f22, $f22
/* B76D2C 8024057C 4405A000 */  mfc1      $a1, $f20
/* B76D30 80240580 4406B000 */  mfc1      $a2, $f22
/* B76D34 80240584 0C019E40 */  jal       guTranslateF
/* B76D38 80240588 00A0382D */   daddu    $a3, $a1, $zero
/* B76D3C 8024058C 27A40010 */  addiu     $a0, $sp, 0x10
/* B76D40 80240590 0200282D */  daddu     $a1, $s0, $zero
/* B76D44 80240594 0C019D80 */  jal       guMtxCatF
/* B76D48 80240598 00A0302D */   daddu    $a2, $a1, $zero
.L8024059C:
/* B76D4C 8024059C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B76D50 802405A0 8FB20058 */  lw        $s2, 0x58($sp)
/* B76D54 802405A4 8FB10054 */  lw        $s1, 0x54($sp)
/* B76D58 802405A8 8FB00050 */  lw        $s0, 0x50($sp)
/* B76D5C 802405AC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B76D60 802405B0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B76D64 802405B4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B76D68 802405B8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B76D6C 802405BC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B76D70 802405C0 24020002 */  addiu     $v0, $zero, 2
/* B76D74 802405C4 03E00008 */  jr        $ra
/* B76D78 802405C8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B76D7C 802405CC 00000000 */  nop       
