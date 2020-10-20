.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_B733A0
/* B733A0 802402F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B733A4 802402F4 AFB10054 */  sw        $s1, 0x54($sp)
/* B733A8 802402F8 0080882D */  daddu     $s1, $a0, $zero
/* B733AC 802402FC AFBF005C */  sw        $ra, 0x5c($sp)
/* B733B0 80240300 AFB20058 */  sw        $s2, 0x58($sp)
/* B733B4 80240304 AFB00050 */  sw        $s0, 0x50($sp)
/* B733B8 80240308 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B733BC 8024030C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B733C0 80240310 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B733C4 80240314 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B733C8 80240318 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B733CC 8024031C 8E30000C */  lw        $s0, 0xc($s1)
/* B733D0 80240320 8E050000 */  lw        $a1, ($s0)
/* B733D4 80240324 0C0B1EAF */  jal       get_variable
/* B733D8 80240328 26100004 */   addiu    $s0, $s0, 4
/* B733DC 8024032C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B733E0 80240330 0040202D */   daddu    $a0, $v0, $zero
/* B733E4 80240334 8E050000 */  lw        $a1, ($s0)
/* B733E8 80240338 26100004 */  addiu     $s0, $s0, 4
/* B733EC 8024033C 0220202D */  daddu     $a0, $s1, $zero
/* B733F0 80240340 0C0B210B */  jal       get_float_variable
/* B733F4 80240344 0040902D */   daddu    $s2, $v0, $zero
/* B733F8 80240348 8E050000 */  lw        $a1, ($s0)
/* B733FC 8024034C 26100004 */  addiu     $s0, $s0, 4
/* B73400 80240350 0220202D */  daddu     $a0, $s1, $zero
/* B73404 80240354 0C0B210B */  jal       get_float_variable
/* B73408 80240358 46000706 */   mov.s    $f28, $f0
/* B7340C 8024035C 8E050000 */  lw        $a1, ($s0)
/* B73410 80240360 26100004 */  addiu     $s0, $s0, 4
/* B73414 80240364 0220202D */  daddu     $a0, $s1, $zero
/* B73418 80240368 0C0B210B */  jal       get_float_variable
/* B7341C 8024036C 46000686 */   mov.s    $f26, $f0
/* B73420 80240370 0220202D */  daddu     $a0, $s1, $zero
/* B73424 80240374 8E050000 */  lw        $a1, ($s0)
/* B73428 80240378 0C0B210B */  jal       get_float_variable
/* B7342C 8024037C 46000586 */   mov.s    $f22, $f0
/* B73430 80240380 0240202D */  daddu     $a0, $s2, $zero
/* B73434 80240384 0C046B4C */  jal       get_model_from_list_index
/* B73438 80240388 46000606 */   mov.s    $f24, $f0
/* B7343C 8024038C 0040882D */  daddu     $s1, $v0, $zero
/* B73440 80240390 96220000 */  lhu       $v0, ($s1)
/* B73444 80240394 30420400 */  andi      $v0, $v0, 0x400
/* B73448 80240398 1440001E */  bnez      $v0, .L80240414
/* B7344C 8024039C 26300058 */   addiu    $s0, $s1, 0x58
/* B73450 802403A0 4480A000 */  mtc1      $zero, $f20
/* B73454 802403A4 4406B000 */  mfc1      $a2, $f22
/* B73458 802403A8 4405A000 */  mfc1      $a1, $f20
/* B7345C 802403AC 4407A000 */  mfc1      $a3, $f20
/* B73460 802403B0 0C019E40 */  jal       guTranslateF
/* B73464 802403B4 0200202D */   daddu    $a0, $s0, $zero
/* B73468 802403B8 4405E000 */  mfc1      $a1, $f28
/* B7346C 802403BC 4406D000 */  mfc1      $a2, $f26
/* B73470 802403C0 4407C000 */  mfc1      $a3, $f24
/* B73474 802403C4 0C0900A0 */  jal       func_80240280
/* B73478 802403C8 27A40010 */   addiu    $a0, $sp, 0x10
/* B7347C 802403CC 27A40010 */  addiu     $a0, $sp, 0x10
/* B73480 802403D0 0200282D */  daddu     $a1, $s0, $zero
/* B73484 802403D4 0C019D80 */  jal       guMtxCatF
/* B73488 802403D8 0200302D */   daddu    $a2, $s0, $zero
/* B7348C 802403DC 27A40010 */  addiu     $a0, $sp, 0x10
/* B73490 802403E0 4600B587 */  neg.s     $f22, $f22
/* B73494 802403E4 4405A000 */  mfc1      $a1, $f20
/* B73498 802403E8 4406B000 */  mfc1      $a2, $f22
/* B7349C 802403EC 0C019E40 */  jal       guTranslateF
/* B734A0 802403F0 00A0382D */   daddu    $a3, $a1, $zero
/* B734A4 802403F4 27A40010 */  addiu     $a0, $sp, 0x10
/* B734A8 802403F8 0200282D */  daddu     $a1, $s0, $zero
/* B734AC 802403FC 0C019D80 */  jal       guMtxCatF
/* B734B0 80240400 00A0302D */   daddu    $a2, $a1, $zero
/* B734B4 80240404 96220000 */  lhu       $v0, ($s1)
/* B734B8 80240408 34421400 */  ori       $v0, $v0, 0x1400
/* B734BC 8024040C 08090123 */  j         .L8024048C
/* B734C0 80240410 A6220000 */   sh       $v0, ($s1)
.L80240414:
/* B734C4 80240414 4480A000 */  mtc1      $zero, $f20
/* B734C8 80240418 4406B000 */  mfc1      $a2, $f22
/* B734CC 8024041C 4405A000 */  mfc1      $a1, $f20
/* B734D0 80240420 4407A000 */  mfc1      $a3, $f20
/* B734D4 80240424 0C019E40 */  jal       guTranslateF
/* B734D8 80240428 27A40010 */   addiu    $a0, $sp, 0x10
/* B734DC 8024042C 27A40010 */  addiu     $a0, $sp, 0x10
/* B734E0 80240430 26300058 */  addiu     $s0, $s1, 0x58
/* B734E4 80240434 0200282D */  daddu     $a1, $s0, $zero
/* B734E8 80240438 0C019D80 */  jal       guMtxCatF
/* B734EC 8024043C 0200302D */   daddu    $a2, $s0, $zero
/* B734F0 80240440 4405E000 */  mfc1      $a1, $f28
/* B734F4 80240444 4406D000 */  mfc1      $a2, $f26
/* B734F8 80240448 4407C000 */  mfc1      $a3, $f24
/* B734FC 8024044C 0C0900A0 */  jal       func_80240280
/* B73500 80240450 27A40010 */   addiu    $a0, $sp, 0x10
/* B73504 80240454 27A40010 */  addiu     $a0, $sp, 0x10
/* B73508 80240458 0200282D */  daddu     $a1, $s0, $zero
/* B7350C 8024045C 0C019D80 */  jal       guMtxCatF
/* B73510 80240460 0200302D */   daddu    $a2, $s0, $zero
/* B73514 80240464 27A40010 */  addiu     $a0, $sp, 0x10
/* B73518 80240468 4600B587 */  neg.s     $f22, $f22
/* B7351C 8024046C 4405A000 */  mfc1      $a1, $f20
/* B73520 80240470 4406B000 */  mfc1      $a2, $f22
/* B73524 80240474 0C019E40 */  jal       guTranslateF
/* B73528 80240478 00A0382D */   daddu    $a3, $a1, $zero
/* B7352C 8024047C 27A40010 */  addiu     $a0, $sp, 0x10
/* B73530 80240480 0200282D */  daddu     $a1, $s0, $zero
/* B73534 80240484 0C019D80 */  jal       guMtxCatF
/* B73538 80240488 00A0302D */   daddu    $a2, $a1, $zero
.L8024048C:
/* B7353C 8024048C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B73540 80240490 8FB20058 */  lw        $s2, 0x58($sp)
/* B73544 80240494 8FB10054 */  lw        $s1, 0x54($sp)
/* B73548 80240498 8FB00050 */  lw        $s0, 0x50($sp)
/* B7354C 8024049C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B73550 802404A0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B73554 802404A4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B73558 802404A8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B7355C 802404AC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B73560 802404B0 24020002 */  addiu     $v0, $zero, 2
/* B73564 802404B4 03E00008 */  jr        $ra
/* B73568 802404B8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B7356C 802404BC 00000000 */  nop       
