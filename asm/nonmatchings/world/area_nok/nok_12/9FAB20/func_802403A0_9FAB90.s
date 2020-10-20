.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A0_9FAB90
/* 9FAB90 802403A0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 9FAB94 802403A4 AFB10054 */  sw        $s1, 0x54($sp)
/* 9FAB98 802403A8 0080882D */  daddu     $s1, $a0, $zero
/* 9FAB9C 802403AC AFBF005C */  sw        $ra, 0x5c($sp)
/* 9FABA0 802403B0 AFB20058 */  sw        $s2, 0x58($sp)
/* 9FABA4 802403B4 AFB00050 */  sw        $s0, 0x50($sp)
/* 9FABA8 802403B8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 9FABAC 802403BC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 9FABB0 802403C0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 9FABB4 802403C4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 9FABB8 802403C8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 9FABBC 802403CC 8E30000C */  lw        $s0, 0xc($s1)
/* 9FABC0 802403D0 8E050000 */  lw        $a1, ($s0)
/* 9FABC4 802403D4 0C0B1EAF */  jal       get_variable
/* 9FABC8 802403D8 26100004 */   addiu    $s0, $s0, 4
/* 9FABCC 802403DC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 9FABD0 802403E0 0040202D */   daddu    $a0, $v0, $zero
/* 9FABD4 802403E4 8E050000 */  lw        $a1, ($s0)
/* 9FABD8 802403E8 26100004 */  addiu     $s0, $s0, 4
/* 9FABDC 802403EC 0220202D */  daddu     $a0, $s1, $zero
/* 9FABE0 802403F0 0C0B210B */  jal       get_float_variable
/* 9FABE4 802403F4 0040902D */   daddu    $s2, $v0, $zero
/* 9FABE8 802403F8 8E050000 */  lw        $a1, ($s0)
/* 9FABEC 802403FC 26100004 */  addiu     $s0, $s0, 4
/* 9FABF0 80240400 0220202D */  daddu     $a0, $s1, $zero
/* 9FABF4 80240404 0C0B210B */  jal       get_float_variable
/* 9FABF8 80240408 46000706 */   mov.s    $f28, $f0
/* 9FABFC 8024040C 8E050000 */  lw        $a1, ($s0)
/* 9FAC00 80240410 26100004 */  addiu     $s0, $s0, 4
/* 9FAC04 80240414 0220202D */  daddu     $a0, $s1, $zero
/* 9FAC08 80240418 0C0B210B */  jal       get_float_variable
/* 9FAC0C 8024041C 46000686 */   mov.s    $f26, $f0
/* 9FAC10 80240420 0220202D */  daddu     $a0, $s1, $zero
/* 9FAC14 80240424 8E050000 */  lw        $a1, ($s0)
/* 9FAC18 80240428 0C0B210B */  jal       get_float_variable
/* 9FAC1C 8024042C 46000586 */   mov.s    $f22, $f0
/* 9FAC20 80240430 0240202D */  daddu     $a0, $s2, $zero
/* 9FAC24 80240434 0C046B4C */  jal       get_model_from_list_index
/* 9FAC28 80240438 46000606 */   mov.s    $f24, $f0
/* 9FAC2C 8024043C 0040882D */  daddu     $s1, $v0, $zero
/* 9FAC30 80240440 96220000 */  lhu       $v0, ($s1)
/* 9FAC34 80240444 30420400 */  andi      $v0, $v0, 0x400
/* 9FAC38 80240448 1440001E */  bnez      $v0, .L802404C4
/* 9FAC3C 8024044C 26300058 */   addiu    $s0, $s1, 0x58
/* 9FAC40 80240450 4480A000 */  mtc1      $zero, $f20
/* 9FAC44 80240454 4406B000 */  mfc1      $a2, $f22
/* 9FAC48 80240458 4405A000 */  mfc1      $a1, $f20
/* 9FAC4C 8024045C 4407A000 */  mfc1      $a3, $f20
/* 9FAC50 80240460 0C019E40 */  jal       guTranslateF
/* 9FAC54 80240464 0200202D */   daddu    $a0, $s0, $zero
/* 9FAC58 80240468 4405E000 */  mfc1      $a1, $f28
/* 9FAC5C 8024046C 4406D000 */  mfc1      $a2, $f26
/* 9FAC60 80240470 4407C000 */  mfc1      $a3, $f24
/* 9FAC64 80240474 0C0900CC */  jal       func_80240330
/* 9FAC68 80240478 27A40010 */   addiu    $a0, $sp, 0x10
/* 9FAC6C 8024047C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FAC70 80240480 0200282D */  daddu     $a1, $s0, $zero
/* 9FAC74 80240484 0C019D80 */  jal       guMtxCatF
/* 9FAC78 80240488 0200302D */   daddu    $a2, $s0, $zero
/* 9FAC7C 8024048C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FAC80 80240490 4600B587 */  neg.s     $f22, $f22
/* 9FAC84 80240494 4405A000 */  mfc1      $a1, $f20
/* 9FAC88 80240498 4406B000 */  mfc1      $a2, $f22
/* 9FAC8C 8024049C 0C019E40 */  jal       guTranslateF
/* 9FAC90 802404A0 00A0382D */   daddu    $a3, $a1, $zero
/* 9FAC94 802404A4 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FAC98 802404A8 0200282D */  daddu     $a1, $s0, $zero
/* 9FAC9C 802404AC 0C019D80 */  jal       guMtxCatF
/* 9FACA0 802404B0 00A0302D */   daddu    $a2, $a1, $zero
/* 9FACA4 802404B4 96220000 */  lhu       $v0, ($s1)
/* 9FACA8 802404B8 34421400 */  ori       $v0, $v0, 0x1400
/* 9FACAC 802404BC 0809014F */  j         .L8024053C
/* 9FACB0 802404C0 A6220000 */   sh       $v0, ($s1)
.L802404C4:
/* 9FACB4 802404C4 4480A000 */  mtc1      $zero, $f20
/* 9FACB8 802404C8 4406B000 */  mfc1      $a2, $f22
/* 9FACBC 802404CC 4405A000 */  mfc1      $a1, $f20
/* 9FACC0 802404D0 4407A000 */  mfc1      $a3, $f20
/* 9FACC4 802404D4 0C019E40 */  jal       guTranslateF
/* 9FACC8 802404D8 27A40010 */   addiu    $a0, $sp, 0x10
/* 9FACCC 802404DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FACD0 802404E0 26300058 */  addiu     $s0, $s1, 0x58
/* 9FACD4 802404E4 0200282D */  daddu     $a1, $s0, $zero
/* 9FACD8 802404E8 0C019D80 */  jal       guMtxCatF
/* 9FACDC 802404EC 0200302D */   daddu    $a2, $s0, $zero
/* 9FACE0 802404F0 4405E000 */  mfc1      $a1, $f28
/* 9FACE4 802404F4 4406D000 */  mfc1      $a2, $f26
/* 9FACE8 802404F8 4407C000 */  mfc1      $a3, $f24
/* 9FACEC 802404FC 0C0900CC */  jal       func_80240330
/* 9FACF0 80240500 27A40010 */   addiu    $a0, $sp, 0x10
/* 9FACF4 80240504 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FACF8 80240508 0200282D */  daddu     $a1, $s0, $zero
/* 9FACFC 8024050C 0C019D80 */  jal       guMtxCatF
/* 9FAD00 80240510 0200302D */   daddu    $a2, $s0, $zero
/* 9FAD04 80240514 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FAD08 80240518 4600B587 */  neg.s     $f22, $f22
/* 9FAD0C 8024051C 4405A000 */  mfc1      $a1, $f20
/* 9FAD10 80240520 4406B000 */  mfc1      $a2, $f22
/* 9FAD14 80240524 0C019E40 */  jal       guTranslateF
/* 9FAD18 80240528 00A0382D */   daddu    $a3, $a1, $zero
/* 9FAD1C 8024052C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9FAD20 80240530 0200282D */  daddu     $a1, $s0, $zero
/* 9FAD24 80240534 0C019D80 */  jal       guMtxCatF
/* 9FAD28 80240538 00A0302D */   daddu    $a2, $a1, $zero
.L8024053C:
/* 9FAD2C 8024053C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 9FAD30 80240540 8FB20058 */  lw        $s2, 0x58($sp)
/* 9FAD34 80240544 8FB10054 */  lw        $s1, 0x54($sp)
/* 9FAD38 80240548 8FB00050 */  lw        $s0, 0x50($sp)
/* 9FAD3C 8024054C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 9FAD40 80240550 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 9FAD44 80240554 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 9FAD48 80240558 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 9FAD4C 8024055C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 9FAD50 80240560 24020002 */  addiu     $v0, $zero, 2
/* 9FAD54 80240564 03E00008 */  jr        $ra
/* 9FAD58 80240568 27BD0088 */   addiu    $sp, $sp, 0x88
/* 9FAD5C 8024056C 00000000 */  nop       
