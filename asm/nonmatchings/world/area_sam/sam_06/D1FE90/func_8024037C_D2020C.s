.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024037C_D2020C
/* D2020C 8024037C 27BDFF78 */  addiu     $sp, $sp, -0x88
/* D20210 80240380 AFB10054 */  sw        $s1, 0x54($sp)
/* D20214 80240384 0080882D */  daddu     $s1, $a0, $zero
/* D20218 80240388 AFBF005C */  sw        $ra, 0x5c($sp)
/* D2021C 8024038C AFB20058 */  sw        $s2, 0x58($sp)
/* D20220 80240390 AFB00050 */  sw        $s0, 0x50($sp)
/* D20224 80240394 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* D20228 80240398 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* D2022C 8024039C F7B80070 */  sdc1      $f24, 0x70($sp)
/* D20230 802403A0 F7B60068 */  sdc1      $f22, 0x68($sp)
/* D20234 802403A4 F7B40060 */  sdc1      $f20, 0x60($sp)
/* D20238 802403A8 8E30000C */  lw        $s0, 0xc($s1)
/* D2023C 802403AC 8E050000 */  lw        $a1, ($s0)
/* D20240 802403B0 0C0B1EAF */  jal       get_variable
/* D20244 802403B4 26100004 */   addiu    $s0, $s0, 4
/* D20248 802403B8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D2024C 802403BC 0040202D */   daddu    $a0, $v0, $zero
/* D20250 802403C0 8E050000 */  lw        $a1, ($s0)
/* D20254 802403C4 26100004 */  addiu     $s0, $s0, 4
/* D20258 802403C8 0220202D */  daddu     $a0, $s1, $zero
/* D2025C 802403CC 0C0B210B */  jal       get_float_variable
/* D20260 802403D0 0040902D */   daddu    $s2, $v0, $zero
/* D20264 802403D4 8E050000 */  lw        $a1, ($s0)
/* D20268 802403D8 26100004 */  addiu     $s0, $s0, 4
/* D2026C 802403DC 0220202D */  daddu     $a0, $s1, $zero
/* D20270 802403E0 0C0B210B */  jal       get_float_variable
/* D20274 802403E4 46000706 */   mov.s    $f28, $f0
/* D20278 802403E8 8E050000 */  lw        $a1, ($s0)
/* D2027C 802403EC 26100004 */  addiu     $s0, $s0, 4
/* D20280 802403F0 0220202D */  daddu     $a0, $s1, $zero
/* D20284 802403F4 0C0B210B */  jal       get_float_variable
/* D20288 802403F8 46000686 */   mov.s    $f26, $f0
/* D2028C 802403FC 0220202D */  daddu     $a0, $s1, $zero
/* D20290 80240400 8E050000 */  lw        $a1, ($s0)
/* D20294 80240404 0C0B210B */  jal       get_float_variable
/* D20298 80240408 46000586 */   mov.s    $f22, $f0
/* D2029C 8024040C 0240202D */  daddu     $a0, $s2, $zero
/* D202A0 80240410 0C046B4C */  jal       get_model_from_list_index
/* D202A4 80240414 46000606 */   mov.s    $f24, $f0
/* D202A8 80240418 0040882D */  daddu     $s1, $v0, $zero
/* D202AC 8024041C 96220000 */  lhu       $v0, ($s1)
/* D202B0 80240420 30420400 */  andi      $v0, $v0, 0x400
/* D202B4 80240424 1440001E */  bnez      $v0, .L802404A0
/* D202B8 80240428 26300058 */   addiu    $s0, $s1, 0x58
/* D202BC 8024042C 4480A000 */  mtc1      $zero, $f20
/* D202C0 80240430 4406B000 */  mfc1      $a2, $f22
/* D202C4 80240434 4405A000 */  mfc1      $a1, $f20
/* D202C8 80240438 4407A000 */  mfc1      $a3, $f20
/* D202CC 8024043C 0C019E40 */  jal       guTranslateF
/* D202D0 80240440 0200202D */   daddu    $a0, $s0, $zero
/* D202D4 80240444 4405E000 */  mfc1      $a1, $f28
/* D202D8 80240448 4406D000 */  mfc1      $a2, $f26
/* D202DC 8024044C 4407C000 */  mfc1      $a3, $f24
/* D202E0 80240450 0C0900C3 */  jal       func_8024030C_D2019C
/* D202E4 80240454 27A40010 */   addiu    $a0, $sp, 0x10
/* D202E8 80240458 27A40010 */  addiu     $a0, $sp, 0x10
/* D202EC 8024045C 0200282D */  daddu     $a1, $s0, $zero
/* D202F0 80240460 0C019D80 */  jal       guMtxCatF
/* D202F4 80240464 0200302D */   daddu    $a2, $s0, $zero
/* D202F8 80240468 27A40010 */  addiu     $a0, $sp, 0x10
/* D202FC 8024046C 4600B587 */  neg.s     $f22, $f22
/* D20300 80240470 4405A000 */  mfc1      $a1, $f20
/* D20304 80240474 4406B000 */  mfc1      $a2, $f22
/* D20308 80240478 0C019E40 */  jal       guTranslateF
/* D2030C 8024047C 00A0382D */   daddu    $a3, $a1, $zero
/* D20310 80240480 27A40010 */  addiu     $a0, $sp, 0x10
/* D20314 80240484 0200282D */  daddu     $a1, $s0, $zero
/* D20318 80240488 0C019D80 */  jal       guMtxCatF
/* D2031C 8024048C 00A0302D */   daddu    $a2, $a1, $zero
/* D20320 80240490 96220000 */  lhu       $v0, ($s1)
/* D20324 80240494 34421400 */  ori       $v0, $v0, 0x1400
/* D20328 80240498 08090146 */  j         .L80240518
/* D2032C 8024049C A6220000 */   sh       $v0, ($s1)
.L802404A0:
/* D20330 802404A0 4480A000 */  mtc1      $zero, $f20
/* D20334 802404A4 4406B000 */  mfc1      $a2, $f22
/* D20338 802404A8 4405A000 */  mfc1      $a1, $f20
/* D2033C 802404AC 4407A000 */  mfc1      $a3, $f20
/* D20340 802404B0 0C019E40 */  jal       guTranslateF
/* D20344 802404B4 27A40010 */   addiu    $a0, $sp, 0x10
/* D20348 802404B8 27A40010 */  addiu     $a0, $sp, 0x10
/* D2034C 802404BC 26300058 */  addiu     $s0, $s1, 0x58
/* D20350 802404C0 0200282D */  daddu     $a1, $s0, $zero
/* D20354 802404C4 0C019D80 */  jal       guMtxCatF
/* D20358 802404C8 0200302D */   daddu    $a2, $s0, $zero
/* D2035C 802404CC 4405E000 */  mfc1      $a1, $f28
/* D20360 802404D0 4406D000 */  mfc1      $a2, $f26
/* D20364 802404D4 4407C000 */  mfc1      $a3, $f24
/* D20368 802404D8 0C0900C3 */  jal       func_8024030C_D2019C
/* D2036C 802404DC 27A40010 */   addiu    $a0, $sp, 0x10
/* D20370 802404E0 27A40010 */  addiu     $a0, $sp, 0x10
/* D20374 802404E4 0200282D */  daddu     $a1, $s0, $zero
/* D20378 802404E8 0C019D80 */  jal       guMtxCatF
/* D2037C 802404EC 0200302D */   daddu    $a2, $s0, $zero
/* D20380 802404F0 27A40010 */  addiu     $a0, $sp, 0x10
/* D20384 802404F4 4600B587 */  neg.s     $f22, $f22
/* D20388 802404F8 4405A000 */  mfc1      $a1, $f20
/* D2038C 802404FC 4406B000 */  mfc1      $a2, $f22
/* D20390 80240500 0C019E40 */  jal       guTranslateF
/* D20394 80240504 00A0382D */   daddu    $a3, $a1, $zero
/* D20398 80240508 27A40010 */  addiu     $a0, $sp, 0x10
/* D2039C 8024050C 0200282D */  daddu     $a1, $s0, $zero
/* D203A0 80240510 0C019D80 */  jal       guMtxCatF
/* D203A4 80240514 00A0302D */   daddu    $a2, $a1, $zero
.L80240518:
/* D203A8 80240518 8FBF005C */  lw        $ra, 0x5c($sp)
/* D203AC 8024051C 8FB20058 */  lw        $s2, 0x58($sp)
/* D203B0 80240520 8FB10054 */  lw        $s1, 0x54($sp)
/* D203B4 80240524 8FB00050 */  lw        $s0, 0x50($sp)
/* D203B8 80240528 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* D203BC 8024052C D7BA0078 */  ldc1      $f26, 0x78($sp)
/* D203C0 80240530 D7B80070 */  ldc1      $f24, 0x70($sp)
/* D203C4 80240534 D7B60068 */  ldc1      $f22, 0x68($sp)
/* D203C8 80240538 D7B40060 */  ldc1      $f20, 0x60($sp)
/* D203CC 8024053C 24020002 */  addiu     $v0, $zero, 2
/* D203D0 80240540 03E00008 */  jr        $ra
/* D203D4 80240544 27BD0088 */   addiu    $sp, $sp, 0x88
/* D203D8 80240548 00000000 */  nop       
/* D203DC 8024054C 00000000 */  nop       
