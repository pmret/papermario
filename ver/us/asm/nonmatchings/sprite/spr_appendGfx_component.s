.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_appendGfx_component
/* FF9E4 802DC8F4 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* FF9E8 802DC8F8 F7B800F0 */  sdc1      $f24, 0xf0($sp)
/* FF9EC 802DC8FC C7B80120 */  lwc1      $f24, 0x120($sp)
/* FF9F0 802DC900 F7B600E8 */  sdc1      $f22, 0xe8($sp)
/* FF9F4 802DC904 C7B60128 */  lwc1      $f22, 0x128($sp)
/* FF9F8 802DC908 F7BA00F8 */  sdc1      $f26, 0xf8($sp)
/* FF9FC 802DC90C C7BA012C */  lwc1      $f26, 0x12c($sp)
/* FFA00 802DC910 F7BC0100 */  sdc1      $f28, 0x100($sp)
/* FFA04 802DC914 C7BC0130 */  lwc1      $f28, 0x130($sp)
/* FFA08 802DC918 F7BE0108 */  sdc1      $f30, 0x108($sp)
/* FFA0C 802DC91C C7BE0134 */  lwc1      $f30, 0x134($sp)
/* FFA10 802DC920 AFB500D4 */  sw        $s5, 0xd4($sp)
/* FFA14 802DC924 8FB50138 */  lw        $s5, 0x138($sp)
/* FFA18 802DC928 AFB600D8 */  sw        $s6, 0xd8($sp)
/* FFA1C 802DC92C 8FB6013C */  lw        $s6, 0x13c($sp)
/* FFA20 802DC930 AFB400D0 */  sw        $s4, 0xd0($sp)
/* FFA24 802DC934 0080A02D */  daddu     $s4, $a0, $zero
/* FFA28 802DC938 AFB100C4 */  sw        $s1, 0xc4($sp)
/* FFA2C 802DC93C 27B10060 */  addiu     $s1, $sp, 0x60
/* FFA30 802DC940 AFB000C0 */  sw        $s0, 0xc0($sp)
/* FFA34 802DC944 8FB00140 */  lw        $s0, 0x140($sp)
/* FFA38 802DC948 AFBF00DC */  sw        $ra, 0xdc($sp)
/* FFA3C 802DC94C AFB300CC */  sw        $s3, 0xcc($sp)
/* FFA40 802DC950 AFB200C8 */  sw        $s2, 0xc8($sp)
/* FFA44 802DC954 F7B400E0 */  sdc1      $f20, 0xe0($sp)
/* FFA48 802DC958 0C019E40 */  jal       guTranslateF
/* FFA4C 802DC95C 0220202D */   daddu    $a0, $s1, $zero
/* FFA50 802DC960 0220202D */  daddu     $a0, $s1, $zero
/* FFA54 802DC964 27A60020 */  addiu     $a2, $sp, 0x20
/* FFA58 802DC968 4480A000 */  mtc1      $zero, $f20
/* FFA5C 802DC96C 0C019D80 */  jal       guMtxCatF
/* FFA60 802DC970 0200282D */   daddu    $a1, $s0, $zero
/* FFA64 802DC974 C7A20124 */  lwc1      $f2, 0x124($sp)
/* FFA68 802DC978 46141032 */  c.eq.s    $f2, $f20
/* FFA6C 802DC97C 00000000 */  nop
/* FFA70 802DC980 4501000A */  bc1t      .L802DC9AC
/* FFA74 802DC984 0220202D */   daddu    $a0, $s1, $zero
/* FFA78 802DC988 44051000 */  mfc1      $a1, $f2
/* FFA7C 802DC98C 4406A000 */  mfc1      $a2, $f20
/* FFA80 802DC990 3C073F80 */  lui       $a3, 0x3f80
/* FFA84 802DC994 0C019EC8 */  jal       guRotateF
/* FFA88 802DC998 E7B40010 */   swc1     $f20, 0x10($sp)
/* FFA8C 802DC99C 0220202D */  daddu     $a0, $s1, $zero
/* FFA90 802DC9A0 27A50020 */  addiu     $a1, $sp, 0x20
/* FFA94 802DC9A4 0C019D80 */  jal       guMtxCatF
/* FFA98 802DC9A8 00A0302D */   daddu    $a2, $a1, $zero
.L802DC9AC:
/* FFA9C 802DC9AC 4614B032 */  c.eq.s    $f22, $f20
/* FFAA0 802DC9B0 00000000 */  nop
/* FFAA4 802DC9B4 4501000C */  bc1t      .L802DC9E8
/* FFAA8 802DC9B8 0220202D */   daddu    $a0, $s1, $zero
/* FFAAC 802DC9BC 4405B000 */  mfc1      $a1, $f22
/* FFAB0 802DC9C0 4406A000 */  mfc1      $a2, $f20
/* FFAB4 802DC9C4 4407A000 */  mfc1      $a3, $f20
/* FFAB8 802DC9C8 3C013F80 */  lui       $at, 0x3f80
/* FFABC 802DC9CC 44810000 */  mtc1      $at, $f0
/* FFAC0 802DC9D0 0C019EC8 */  jal       guRotateF
/* FFAC4 802DC9D4 E7A00010 */   swc1     $f0, 0x10($sp)
/* FFAC8 802DC9D8 0220202D */  daddu     $a0, $s1, $zero
/* FFACC 802DC9DC 27A50020 */  addiu     $a1, $sp, 0x20
/* FFAD0 802DC9E0 0C019D80 */  jal       guMtxCatF
/* FFAD4 802DC9E4 00A0302D */   daddu    $a2, $a1, $zero
.L802DC9E8:
/* FFAD8 802DC9E8 4614C032 */  c.eq.s    $f24, $f20
/* FFADC 802DC9EC 00000000 */  nop
/* FFAE0 802DC9F0 4501000A */  bc1t      .L802DCA1C
/* FFAE4 802DC9F4 0220202D */   daddu    $a0, $s1, $zero
/* FFAE8 802DC9F8 4405C000 */  mfc1      $a1, $f24
/* FFAEC 802DC9FC 3C063F80 */  lui       $a2, 0x3f80
/* FFAF0 802DCA00 4407A000 */  mfc1      $a3, $f20
/* FFAF4 802DCA04 0C019EC8 */  jal       guRotateF
/* FFAF8 802DCA08 AFA70010 */   sw       $a3, 0x10($sp)
/* FFAFC 802DCA0C 0220202D */  daddu     $a0, $s1, $zero
/* FFB00 802DCA10 27A50020 */  addiu     $a1, $sp, 0x20
/* FFB04 802DCA14 0C019D80 */  jal       guMtxCatF
/* FFB08 802DCA18 00A0302D */   daddu    $a2, $a1, $zero
.L802DCA1C:
/* FFB0C 802DCA1C 3C013F80 */  lui       $at, 0x3f80
/* FFB10 802DCA20 44810000 */  mtc1      $at, $f0
/* FFB14 802DCA24 00000000 */  nop
/* FFB18 802DCA28 4600D032 */  c.eq.s    $f26, $f0
/* FFB1C 802DCA2C 00000000 */  nop
/* FFB20 802DCA30 4500000A */  bc1f      .L802DCA5C
/* FFB24 802DCA34 27B00060 */   addiu    $s0, $sp, 0x60
/* FFB28 802DCA38 4600E032 */  c.eq.s    $f28, $f0
/* FFB2C 802DCA3C 00000000 */  nop
/* FFB30 802DCA40 45000006 */  bc1f      .L802DCA5C
/* FFB34 802DCA44 00000000 */   nop
/* FFB38 802DCA48 4600F032 */  c.eq.s    $f30, $f0
/* FFB3C 802DCA4C 00000000 */  nop
/* FFB40 802DCA50 4501000C */  bc1t      .L802DCA84
/* FFB44 802DCA54 3C120001 */   lui      $s2, 1
/* FFB48 802DCA58 27B00060 */  addiu     $s0, $sp, 0x60
.L802DCA5C:
/* FFB4C 802DCA5C 4405D000 */  mfc1      $a1, $f26
/* FFB50 802DCA60 4406E000 */  mfc1      $a2, $f28
/* FFB54 802DCA64 4407F000 */  mfc1      $a3, $f30
/* FFB58 802DCA68 0C019DF0 */  jal       guScaleF
/* FFB5C 802DCA6C 0200202D */   daddu    $a0, $s0, $zero
/* FFB60 802DCA70 0200202D */  daddu     $a0, $s0, $zero
/* FFB64 802DCA74 27A50020 */  addiu     $a1, $sp, 0x20
/* FFB68 802DCA78 0C019D80 */  jal       guMtxCatF
/* FFB6C 802DCA7C 00A0302D */   daddu    $a2, $a1, $zero
/* FFB70 802DCA80 3C120001 */  lui       $s2, 1
.L802DCA84:
/* FFB74 802DCA84 36521630 */  ori       $s2, $s2, 0x1630
/* FFB78 802DCA88 27A40020 */  addiu     $a0, $sp, 0x20
/* FFB7C 802DCA8C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* FFB80 802DCA90 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* FFB84 802DCA94 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* FFB88 802DCA98 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* FFB8C 802DCA9C 96050000 */  lhu       $a1, ($s0)
/* FFB90 802DCAA0 8E220000 */  lw        $v0, ($s1)
/* FFB94 802DCAA4 00052980 */  sll       $a1, $a1, 6
/* FFB98 802DCAA8 00B22821 */  addu      $a1, $a1, $s2
/* FFB9C 802DCAAC 0C019D40 */  jal       guMtxF2L
/* FFBA0 802DCAB0 00452821 */   addu     $a1, $v0, $a1
/* FFBA4 802DCAB4 3C02DA38 */  lui       $v0, 0xda38
/* FFBA8 802DCAB8 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* FFBAC 802DCABC 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* FFBB0 802DCAC0 34420002 */  ori       $v0, $v0, 2
/* FFBB4 802DCAC4 8D070000 */  lw        $a3, ($t0)
/* FFBB8 802DCAC8 96040000 */  lhu       $a0, ($s0)
/* FFBBC 802DCACC 00E0302D */  daddu     $a2, $a3, $zero
/* FFBC0 802DCAD0 24E70008 */  addiu     $a3, $a3, 8
/* FFBC4 802DCAD4 AD070000 */  sw        $a3, ($t0)
/* FFBC8 802DCAD8 ACC20000 */  sw        $v0, ($a2)
/* FFBCC 802DCADC 3082FFFF */  andi      $v0, $a0, 0xffff
/* FFBD0 802DCAE0 00021180 */  sll       $v0, $v0, 6
/* FFBD4 802DCAE4 00521021 */  addu      $v0, $v0, $s2
/* FFBD8 802DCAE8 8E230000 */  lw        $v1, ($s1)
/* FFBDC 802DCAEC 3C058015 */  lui       $a1, %hi(D_80151328)
/* FFBE0 802DCAF0 8CA51328 */  lw        $a1, %lo(D_80151328)($a1)
/* FFBE4 802DCAF4 00621821 */  addu      $v1, $v1, $v0
/* FFBE8 802DCAF8 3C028000 */  lui       $v0, 0x8000
/* FFBEC 802DCAFC 00621821 */  addu      $v1, $v1, $v0
/* FFBF0 802DCB00 ACC30004 */  sw        $v1, 4($a2)
/* FFBF4 802DCB04 94A20000 */  lhu       $v0, ($a1)
/* FFBF8 802DCB08 24840001 */  addiu     $a0, $a0, 1
/* FFBFC 802DCB0C 30420001 */  andi      $v0, $v0, 1
/* FFC00 802DCB10 10400013 */  beqz      $v0, .L802DCB60
/* FFC04 802DCB14 A6040000 */   sh       $a0, ($s0)
/* FFC08 802DCB18 32A300FF */  andi      $v1, $s5, 0xff
/* FFC0C 802DCB1C 240200FF */  addiu     $v0, $zero, 0xff
/* FFC10 802DCB20 14620008 */  bne       $v1, $v0, .L802DCB44
/* FFC14 802DCB24 24E20008 */   addiu    $v0, $a3, 8
/* FFC18 802DCB28 AD020000 */  sw        $v0, ($t0)
/* FFC1C 802DCB2C 3C02DE00 */  lui       $v0, 0xde00
/* FFC20 802DCB30 ACE20000 */  sw        $v0, ($a3)
/* FFC24 802DCB34 3C02802E */  lui       $v0, %hi(D_802DF460)
/* FFC28 802DCB38 2442F460 */  addiu     $v0, $v0, %lo(D_802DF460)
/* FFC2C 802DCB3C 080B72EE */  j         .L802DCBB8
/* FFC30 802DCB40 ACE20004 */   sw       $v0, 4($a3)
.L802DCB44:
/* FFC34 802DCB44 AD020000 */  sw        $v0, ($t0)
/* FFC38 802DCB48 3C02DE00 */  lui       $v0, 0xde00
/* FFC3C 802DCB4C ACE20000 */  sw        $v0, ($a3)
/* FFC40 802DCB50 3C02802E */  lui       $v0, %hi(D_802DF490)
/* FFC44 802DCB54 2442F490 */  addiu     $v0, $v0, %lo(D_802DF490)
/* FFC48 802DCB58 080B72EE */  j         .L802DCBB8
/* FFC4C 802DCB5C ACE20004 */   sw       $v0, 4($a3)
.L802DCB60:
/* FFC50 802DCB60 32A300FF */  andi      $v1, $s5, 0xff
/* FFC54 802DCB64 240200FF */  addiu     $v0, $zero, 0xff
/* FFC58 802DCB68 14620008 */  bne       $v1, $v0, .L802DCB8C
/* FFC5C 802DCB6C 24E20008 */   addiu    $v0, $a3, 8
/* FFC60 802DCB70 AD020000 */  sw        $v0, ($t0)
/* FFC64 802DCB74 3C02DE00 */  lui       $v0, 0xde00
/* FFC68 802DCB78 ACE20000 */  sw        $v0, ($a3)
/* FFC6C 802DCB7C 3C02802E */  lui       $v0, %hi(D_802DF3F0)
/* FFC70 802DCB80 2442F3F0 */  addiu     $v0, $v0, %lo(D_802DF3F0)
/* FFC74 802DCB84 080B72EE */  j         .L802DCBB8
/* FFC78 802DCB88 ACE20004 */   sw       $v0, 4($a3)
.L802DCB8C:
/* FFC7C 802DCB8C AD020000 */  sw        $v0, ($t0)
/* FFC80 802DCB90 3C02FA00 */  lui       $v0, 0xfa00
/* FFC84 802DCB94 ACE20000 */  sw        $v0, ($a3)
/* FFC88 802DCB98 24E20010 */  addiu     $v0, $a3, 0x10
/* FFC8C 802DCB9C ACE30004 */  sw        $v1, 4($a3)
/* FFC90 802DCBA0 AD020000 */  sw        $v0, ($t0)
/* FFC94 802DCBA4 3C02DE00 */  lui       $v0, 0xde00
/* FFC98 802DCBA8 ACE20008 */  sw        $v0, 8($a3)
/* FFC9C 802DCBAC 3C02802E */  lui       $v0, %hi(D_802DF428)
/* FFCA0 802DCBB0 2442F428 */  addiu     $v0, $v0, %lo(D_802DF428)
/* FFCA4 802DCBB4 ACE2000C */  sw        $v0, 0xc($a3)
.L802DCBB8:
/* FFCA8 802DCBB8 92910004 */  lbu       $s1, 4($s4)
/* FFCAC 802DCBBC 92920005 */  lbu       $s2, 5($s4)
/* FFCB0 802DCBC0 82820007 */  lb        $v0, 7($s4)
/* FFCB4 802DCBC4 3C13802E */  lui       $s3, %hi(D_802DF540)
/* FFCB8 802DCBC8 2673F540 */  addiu     $s3, $s3, %lo(D_802DF540)
/* FFCBC 802DCBCC AFA200B8 */  sw        $v0, 0xb8($sp)
/* FFCC0 802DCBD0 8E620000 */  lw        $v0, ($s3)
/* FFCC4 802DCBD4 3C03F000 */  lui       $v1, 0xf000
/* FFCC8 802DCBD8 00431024 */  and       $v0, $v0, $v1
/* FFCCC 802DCBDC 14400009 */  bnez      $v0, .L802DCC04
/* FFCD0 802DCBE0 0000202D */   daddu    $a0, $zero, $zero
/* FFCD4 802DCBE4 27B000B8 */  addiu     $s0, $sp, 0xb8
/* FFCD8 802DCBE8 0200202D */  daddu     $a0, $s0, $zero
/* FFCDC 802DCBEC 0220282D */  daddu     $a1, $s1, $zero
/* FFCE0 802DCBF0 0C0B6F9E */  jal       spr_get_quad_for_size
/* FFCE4 802DCBF4 0240302D */   daddu    $a2, $s2, $zero
/* FFCE8 802DCBF8 92030003 */  lbu       $v1, 3($s0)
/* FFCEC 802DCBFC 0040202D */  daddu     $a0, $v0, $zero
/* FFCF0 802DCC00 A2830007 */  sb        $v1, 7($s4)
.L802DCC04:
/* FFCF4 802DCC04 1080000D */  beqz      $a0, .L802DCC3C
/* FFCF8 802DCC08 02C0302D */   daddu    $a2, $s6, $zero
/* FFCFC 802DCC0C C7A20124 */  lwc1      $f2, 0x124($sp)
/* FFD00 802DCC10 27A20020 */  addiu     $v0, $sp, 0x20
/* FFD04 802DCC14 AFA20018 */  sw        $v0, 0x18($sp)
/* FFD08 802DCC18 32A200FF */  andi      $v0, $s5, 0xff
/* FFD0C 802DCC1C AFB20010 */  sw        $s2, 0x10($sp)
/* FFD10 802DCC20 AFA2001C */  sw        $v0, 0x1c($sp)
/* FFD14 802DCC24 E7A20014 */  swc1      $f2, 0x14($sp)
/* FFD18 802DCC28 8E850000 */  lw        $a1, ($s4)
/* FFD1C 802DCC2C 0C0B7002 */  jal       spr_appendGfx_component_flat
/* FFD20 802DCC30 0220382D */   daddu    $a3, $s1, $zero
/* FFD24 802DCC34 080B7326 */  j         .L802DCC98
/* FFD28 802DCC38 3C05D838 */   lui      $a1, 0xd838
.L802DCC3C:
/* FFD2C 802DCC3C 27A500A0 */  addiu     $a1, $sp, 0xa0
/* FFD30 802DCC40 3C060008 */  lui       $a2, 8
/* FFD34 802DCC44 27A70020 */  addiu     $a3, $sp, 0x20
/* FFD38 802DCC48 00111842 */  srl       $v1, $s1, 1
/* FFD3C 802DCC4C 92640003 */  lbu       $a0, 3($s3)
/* FFD40 802DCC50 8E820000 */  lw        $v0, ($s4)
/* FFD44 802DCC54 00031823 */  negu      $v1, $v1
/* FFD48 802DCC58 AFB600A4 */  sw        $s6, 0xa4($sp)
/* FFD4C 802DCC5C A7B100A8 */  sh        $s1, 0xa8($sp)
/* FFD50 802DCC60 A7B200AA */  sh        $s2, 0xaa($sp)
/* FFD54 802DCC64 A7A300AC */  sh        $v1, 0xac($sp)
/* FFD58 802DCC68 A7B200AE */  sh        $s2, 0xae($sp)
/* FFD5C 802DCC6C A3B500B0 */  sb        $s5, 0xb0($sp)
/* FFD60 802DCC70 0C04EBDC */  jal       fold_appendGfx_component
/* FFD64 802DCC74 AFA200A0 */   sw       $v0, 0xa0($sp)
/* FFD68 802DCC78 24030001 */  addiu     $v1, $zero, 1
/* FFD6C 802DCC7C 14430006 */  bne       $v0, $v1, .L802DCC98
/* FFD70 802DCC80 3C05D838 */   lui      $a1, 0xd838
/* FFD74 802DCC84 3C030FFF */  lui       $v1, 0xfff
/* FFD78 802DCC88 8E620000 */  lw        $v0, ($s3)
/* FFD7C 802DCC8C 3463FFFF */  ori       $v1, $v1, 0xffff
/* FFD80 802DCC90 00431024 */  and       $v0, $v0, $v1
/* FFD84 802DCC94 AE620000 */  sw        $v0, ($s3)
.L802DCC98:
/* FFD88 802DCC98 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* FFD8C 802DCC9C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* FFD90 802DCCA0 8C620000 */  lw        $v0, ($v1)
/* FFD94 802DCCA4 34A50002 */  ori       $a1, $a1, 2
/* FFD98 802DCCA8 0040202D */  daddu     $a0, $v0, $zero
/* FFD9C 802DCCAC 24420008 */  addiu     $v0, $v0, 8
/* FFDA0 802DCCB0 AC620000 */  sw        $v0, ($v1)
/* FFDA4 802DCCB4 24020040 */  addiu     $v0, $zero, 0x40
/* FFDA8 802DCCB8 AC850000 */  sw        $a1, ($a0)
/* FFDAC 802DCCBC AC820004 */  sw        $v0, 4($a0)
/* FFDB0 802DCCC0 8FBF00DC */  lw        $ra, 0xdc($sp)
/* FFDB4 802DCCC4 8FB600D8 */  lw        $s6, 0xd8($sp)
/* FFDB8 802DCCC8 8FB500D4 */  lw        $s5, 0xd4($sp)
/* FFDBC 802DCCCC 8FB400D0 */  lw        $s4, 0xd0($sp)
/* FFDC0 802DCCD0 8FB300CC */  lw        $s3, 0xcc($sp)
/* FFDC4 802DCCD4 8FB200C8 */  lw        $s2, 0xc8($sp)
/* FFDC8 802DCCD8 8FB100C4 */  lw        $s1, 0xc4($sp)
/* FFDCC 802DCCDC 8FB000C0 */  lw        $s0, 0xc0($sp)
/* FFDD0 802DCCE0 D7BE0108 */  ldc1      $f30, 0x108($sp)
/* FFDD4 802DCCE4 D7BC0100 */  ldc1      $f28, 0x100($sp)
/* FFDD8 802DCCE8 D7BA00F8 */  ldc1      $f26, 0xf8($sp)
/* FFDDC 802DCCEC D7B800F0 */  ldc1      $f24, 0xf0($sp)
/* FFDE0 802DCCF0 D7B600E8 */  ldc1      $f22, 0xe8($sp)
/* FFDE4 802DCCF4 D7B400E0 */  ldc1      $f20, 0xe0($sp)
/* FFDE8 802DCCF8 03E00008 */  jr        $ra
/* FFDEC 802DCCFC 27BD0110 */   addiu    $sp, $sp, 0x110
