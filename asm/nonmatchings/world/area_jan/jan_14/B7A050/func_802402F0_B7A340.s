.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_B7A340
/* B7A340 802402F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B7A344 802402F4 AFB10054 */  sw        $s1, 0x54($sp)
/* B7A348 802402F8 0080882D */  daddu     $s1, $a0, $zero
/* B7A34C 802402FC AFBF005C */  sw        $ra, 0x5c($sp)
/* B7A350 80240300 AFB20058 */  sw        $s2, 0x58($sp)
/* B7A354 80240304 AFB00050 */  sw        $s0, 0x50($sp)
/* B7A358 80240308 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B7A35C 8024030C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B7A360 80240310 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B7A364 80240314 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B7A368 80240318 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B7A36C 8024031C 8E30000C */  lw        $s0, 0xc($s1)
/* B7A370 80240320 8E050000 */  lw        $a1, ($s0)
/* B7A374 80240324 0C0B1EAF */  jal       get_variable
/* B7A378 80240328 26100004 */   addiu    $s0, $s0, 4
/* B7A37C 8024032C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B7A380 80240330 0040202D */   daddu    $a0, $v0, $zero
/* B7A384 80240334 8E050000 */  lw        $a1, ($s0)
/* B7A388 80240338 26100004 */  addiu     $s0, $s0, 4
/* B7A38C 8024033C 0220202D */  daddu     $a0, $s1, $zero
/* B7A390 80240340 0C0B210B */  jal       get_float_variable
/* B7A394 80240344 0040902D */   daddu    $s2, $v0, $zero
/* B7A398 80240348 8E050000 */  lw        $a1, ($s0)
/* B7A39C 8024034C 26100004 */  addiu     $s0, $s0, 4
/* B7A3A0 80240350 0220202D */  daddu     $a0, $s1, $zero
/* B7A3A4 80240354 0C0B210B */  jal       get_float_variable
/* B7A3A8 80240358 46000706 */   mov.s    $f28, $f0
/* B7A3AC 8024035C 8E050000 */  lw        $a1, ($s0)
/* B7A3B0 80240360 26100004 */  addiu     $s0, $s0, 4
/* B7A3B4 80240364 0220202D */  daddu     $a0, $s1, $zero
/* B7A3B8 80240368 0C0B210B */  jal       get_float_variable
/* B7A3BC 8024036C 46000686 */   mov.s    $f26, $f0
/* B7A3C0 80240370 0220202D */  daddu     $a0, $s1, $zero
/* B7A3C4 80240374 8E050000 */  lw        $a1, ($s0)
/* B7A3C8 80240378 0C0B210B */  jal       get_float_variable
/* B7A3CC 8024037C 46000586 */   mov.s    $f22, $f0
/* B7A3D0 80240380 0240202D */  daddu     $a0, $s2, $zero
/* B7A3D4 80240384 0C046B4C */  jal       get_model_from_list_index
/* B7A3D8 80240388 46000606 */   mov.s    $f24, $f0
/* B7A3DC 8024038C 0040882D */  daddu     $s1, $v0, $zero
/* B7A3E0 80240390 96220000 */  lhu       $v0, ($s1)
/* B7A3E4 80240394 30420400 */  andi      $v0, $v0, 0x400
/* B7A3E8 80240398 1440001E */  bnez      $v0, .L80240414
/* B7A3EC 8024039C 26300058 */   addiu    $s0, $s1, 0x58
/* B7A3F0 802403A0 4480A000 */  mtc1      $zero, $f20
/* B7A3F4 802403A4 4406B000 */  mfc1      $a2, $f22
/* B7A3F8 802403A8 4405A000 */  mfc1      $a1, $f20
/* B7A3FC 802403AC 4407A000 */  mfc1      $a3, $f20
/* B7A400 802403B0 0C019E40 */  jal       guTranslateF
/* B7A404 802403B4 0200202D */   daddu    $a0, $s0, $zero
/* B7A408 802403B8 4405E000 */  mfc1      $a1, $f28
/* B7A40C 802403BC 4406D000 */  mfc1      $a2, $f26
/* B7A410 802403C0 4407C000 */  mfc1      $a3, $f24
/* B7A414 802403C4 0C0900A0 */  jal       func_80240280
/* B7A418 802403C8 27A40010 */   addiu    $a0, $sp, 0x10
/* B7A41C 802403CC 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A420 802403D0 0200282D */  daddu     $a1, $s0, $zero
/* B7A424 802403D4 0C019D80 */  jal       guMtxCatF
/* B7A428 802403D8 0200302D */   daddu    $a2, $s0, $zero
/* B7A42C 802403DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A430 802403E0 4600B587 */  neg.s     $f22, $f22
/* B7A434 802403E4 4405A000 */  mfc1      $a1, $f20
/* B7A438 802403E8 4406B000 */  mfc1      $a2, $f22
/* B7A43C 802403EC 0C019E40 */  jal       guTranslateF
/* B7A440 802403F0 00A0382D */   daddu    $a3, $a1, $zero
/* B7A444 802403F4 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A448 802403F8 0200282D */  daddu     $a1, $s0, $zero
/* B7A44C 802403FC 0C019D80 */  jal       guMtxCatF
/* B7A450 80240400 00A0302D */   daddu    $a2, $a1, $zero
/* B7A454 80240404 96220000 */  lhu       $v0, ($s1)
/* B7A458 80240408 34421400 */  ori       $v0, $v0, 0x1400
/* B7A45C 8024040C 08090123 */  j         .L8024048C
/* B7A460 80240410 A6220000 */   sh       $v0, ($s1)
.L80240414:
/* B7A464 80240414 4480A000 */  mtc1      $zero, $f20
/* B7A468 80240418 4406B000 */  mfc1      $a2, $f22
/* B7A46C 8024041C 4405A000 */  mfc1      $a1, $f20
/* B7A470 80240420 4407A000 */  mfc1      $a3, $f20
/* B7A474 80240424 0C019E40 */  jal       guTranslateF
/* B7A478 80240428 27A40010 */   addiu    $a0, $sp, 0x10
/* B7A47C 8024042C 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A480 80240430 26300058 */  addiu     $s0, $s1, 0x58
/* B7A484 80240434 0200282D */  daddu     $a1, $s0, $zero
/* B7A488 80240438 0C019D80 */  jal       guMtxCatF
/* B7A48C 8024043C 0200302D */   daddu    $a2, $s0, $zero
/* B7A490 80240440 4405E000 */  mfc1      $a1, $f28
/* B7A494 80240444 4406D000 */  mfc1      $a2, $f26
/* B7A498 80240448 4407C000 */  mfc1      $a3, $f24
/* B7A49C 8024044C 0C0900A0 */  jal       func_80240280
/* B7A4A0 80240450 27A40010 */   addiu    $a0, $sp, 0x10
/* B7A4A4 80240454 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A4A8 80240458 0200282D */  daddu     $a1, $s0, $zero
/* B7A4AC 8024045C 0C019D80 */  jal       guMtxCatF
/* B7A4B0 80240460 0200302D */   daddu    $a2, $s0, $zero
/* B7A4B4 80240464 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A4B8 80240468 4600B587 */  neg.s     $f22, $f22
/* B7A4BC 8024046C 4405A000 */  mfc1      $a1, $f20
/* B7A4C0 80240470 4406B000 */  mfc1      $a2, $f22
/* B7A4C4 80240474 0C019E40 */  jal       guTranslateF
/* B7A4C8 80240478 00A0382D */   daddu    $a3, $a1, $zero
/* B7A4CC 8024047C 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A4D0 80240480 0200282D */  daddu     $a1, $s0, $zero
/* B7A4D4 80240484 0C019D80 */  jal       guMtxCatF
/* B7A4D8 80240488 00A0302D */   daddu    $a2, $a1, $zero
.L8024048C:
/* B7A4DC 8024048C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B7A4E0 80240490 8FB20058 */  lw        $s2, 0x58($sp)
/* B7A4E4 80240494 8FB10054 */  lw        $s1, 0x54($sp)
/* B7A4E8 80240498 8FB00050 */  lw        $s0, 0x50($sp)
/* B7A4EC 8024049C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B7A4F0 802404A0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B7A4F4 802404A4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B7A4F8 802404A8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B7A4FC 802404AC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B7A500 802404B0 24020002 */  addiu     $v0, $zero, 2
/* B7A504 802404B4 03E00008 */  jr        $ra
/* B7A508 802404B8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B7A50C 802404BC 00000000 */  nop       
