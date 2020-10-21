.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240370_B80370
/* B80370 80240370 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B80374 80240374 AFB10054 */  sw        $s1, 0x54($sp)
/* B80378 80240378 0080882D */  daddu     $s1, $a0, $zero
/* B8037C 8024037C AFBF005C */  sw        $ra, 0x5c($sp)
/* B80380 80240380 AFB20058 */  sw        $s2, 0x58($sp)
/* B80384 80240384 AFB00050 */  sw        $s0, 0x50($sp)
/* B80388 80240388 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B8038C 8024038C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B80390 80240390 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B80394 80240394 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B80398 80240398 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B8039C 8024039C 8E30000C */  lw        $s0, 0xc($s1)
/* B803A0 802403A0 8E050000 */  lw        $a1, ($s0)
/* B803A4 802403A4 0C0B1EAF */  jal       get_variable
/* B803A8 802403A8 26100004 */   addiu    $s0, $s0, 4
/* B803AC 802403AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B803B0 802403B0 0040202D */   daddu    $a0, $v0, $zero
/* B803B4 802403B4 8E050000 */  lw        $a1, ($s0)
/* B803B8 802403B8 26100004 */  addiu     $s0, $s0, 4
/* B803BC 802403BC 0220202D */  daddu     $a0, $s1, $zero
/* B803C0 802403C0 0C0B210B */  jal       get_float_variable
/* B803C4 802403C4 0040902D */   daddu    $s2, $v0, $zero
/* B803C8 802403C8 8E050000 */  lw        $a1, ($s0)
/* B803CC 802403CC 26100004 */  addiu     $s0, $s0, 4
/* B803D0 802403D0 0220202D */  daddu     $a0, $s1, $zero
/* B803D4 802403D4 0C0B210B */  jal       get_float_variable
/* B803D8 802403D8 46000706 */   mov.s    $f28, $f0
/* B803DC 802403DC 8E050000 */  lw        $a1, ($s0)
/* B803E0 802403E0 26100004 */  addiu     $s0, $s0, 4
/* B803E4 802403E4 0220202D */  daddu     $a0, $s1, $zero
/* B803E8 802403E8 0C0B210B */  jal       get_float_variable
/* B803EC 802403EC 46000686 */   mov.s    $f26, $f0
/* B803F0 802403F0 0220202D */  daddu     $a0, $s1, $zero
/* B803F4 802403F4 8E050000 */  lw        $a1, ($s0)
/* B803F8 802403F8 0C0B210B */  jal       get_float_variable
/* B803FC 802403FC 46000586 */   mov.s    $f22, $f0
/* B80400 80240400 0240202D */  daddu     $a0, $s2, $zero
/* B80404 80240404 0C046B4C */  jal       get_model_from_list_index
/* B80408 80240408 46000606 */   mov.s    $f24, $f0
/* B8040C 8024040C 0040882D */  daddu     $s1, $v0, $zero
/* B80410 80240410 96220000 */  lhu       $v0, ($s1)
/* B80414 80240414 30420400 */  andi      $v0, $v0, 0x400
/* B80418 80240418 1440001E */  bnez      $v0, .L80240494
/* B8041C 8024041C 26300058 */   addiu    $s0, $s1, 0x58
/* B80420 80240420 4480A000 */  mtc1      $zero, $f20
/* B80424 80240424 4406B000 */  mfc1      $a2, $f22
/* B80428 80240428 4405A000 */  mfc1      $a1, $f20
/* B8042C 8024042C 4407A000 */  mfc1      $a3, $f20
/* B80430 80240430 0C019E40 */  jal       guTranslateF
/* B80434 80240434 0200202D */   daddu    $a0, $s0, $zero
/* B80438 80240438 4405E000 */  mfc1      $a1, $f28
/* B8043C 8024043C 4406D000 */  mfc1      $a2, $f26
/* B80440 80240440 4407C000 */  mfc1      $a3, $f24
/* B80444 80240444 0C0900C0 */  jal       func_80240300_B80300
/* B80448 80240448 27A40010 */   addiu    $a0, $sp, 0x10
/* B8044C 8024044C 27A40010 */  addiu     $a0, $sp, 0x10
/* B80450 80240450 0200282D */  daddu     $a1, $s0, $zero
/* B80454 80240454 0C019D80 */  jal       guMtxCatF
/* B80458 80240458 0200302D */   daddu    $a2, $s0, $zero
/* B8045C 8024045C 27A40010 */  addiu     $a0, $sp, 0x10
/* B80460 80240460 4600B587 */  neg.s     $f22, $f22
/* B80464 80240464 4405A000 */  mfc1      $a1, $f20
/* B80468 80240468 4406B000 */  mfc1      $a2, $f22
/* B8046C 8024046C 0C019E40 */  jal       guTranslateF
/* B80470 80240470 00A0382D */   daddu    $a3, $a1, $zero
/* B80474 80240474 27A40010 */  addiu     $a0, $sp, 0x10
/* B80478 80240478 0200282D */  daddu     $a1, $s0, $zero
/* B8047C 8024047C 0C019D80 */  jal       guMtxCatF
/* B80480 80240480 00A0302D */   daddu    $a2, $a1, $zero
/* B80484 80240484 96220000 */  lhu       $v0, ($s1)
/* B80488 80240488 34421400 */  ori       $v0, $v0, 0x1400
/* B8048C 8024048C 08090143 */  j         .L8024050C
/* B80490 80240490 A6220000 */   sh       $v0, ($s1)
.L80240494:
/* B80494 80240494 4480A000 */  mtc1      $zero, $f20
/* B80498 80240498 4406B000 */  mfc1      $a2, $f22
/* B8049C 8024049C 4405A000 */  mfc1      $a1, $f20
/* B804A0 802404A0 4407A000 */  mfc1      $a3, $f20
/* B804A4 802404A4 0C019E40 */  jal       guTranslateF
/* B804A8 802404A8 27A40010 */   addiu    $a0, $sp, 0x10
/* B804AC 802404AC 27A40010 */  addiu     $a0, $sp, 0x10
/* B804B0 802404B0 26300058 */  addiu     $s0, $s1, 0x58
/* B804B4 802404B4 0200282D */  daddu     $a1, $s0, $zero
/* B804B8 802404B8 0C019D80 */  jal       guMtxCatF
/* B804BC 802404BC 0200302D */   daddu    $a2, $s0, $zero
/* B804C0 802404C0 4405E000 */  mfc1      $a1, $f28
/* B804C4 802404C4 4406D000 */  mfc1      $a2, $f26
/* B804C8 802404C8 4407C000 */  mfc1      $a3, $f24
/* B804CC 802404CC 0C0900C0 */  jal       func_80240300_B80300
/* B804D0 802404D0 27A40010 */   addiu    $a0, $sp, 0x10
/* B804D4 802404D4 27A40010 */  addiu     $a0, $sp, 0x10
/* B804D8 802404D8 0200282D */  daddu     $a1, $s0, $zero
/* B804DC 802404DC 0C019D80 */  jal       guMtxCatF
/* B804E0 802404E0 0200302D */   daddu    $a2, $s0, $zero
/* B804E4 802404E4 27A40010 */  addiu     $a0, $sp, 0x10
/* B804E8 802404E8 4600B587 */  neg.s     $f22, $f22
/* B804EC 802404EC 4405A000 */  mfc1      $a1, $f20
/* B804F0 802404F0 4406B000 */  mfc1      $a2, $f22
/* B804F4 802404F4 0C019E40 */  jal       guTranslateF
/* B804F8 802404F8 00A0382D */   daddu    $a3, $a1, $zero
/* B804FC 802404FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B80500 80240500 0200282D */  daddu     $a1, $s0, $zero
/* B80504 80240504 0C019D80 */  jal       guMtxCatF
/* B80508 80240508 00A0302D */   daddu    $a2, $a1, $zero
.L8024050C:
/* B8050C 8024050C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B80510 80240510 8FB20058 */  lw        $s2, 0x58($sp)
/* B80514 80240514 8FB10054 */  lw        $s1, 0x54($sp)
/* B80518 80240518 8FB00050 */  lw        $s0, 0x50($sp)
/* B8051C 8024051C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B80520 80240520 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B80524 80240524 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B80528 80240528 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B8052C 8024052C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B80530 80240530 24020002 */  addiu     $v0, $zero, 2
/* B80534 80240534 03E00008 */  jr        $ra
/* B80538 80240538 27BD0088 */   addiu    $sp, $sp, 0x88
/* B8053C 8024053C 00000000 */  nop       
