.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DE8DC
/* 1019CC 802DE8DC 3C03802E */  lui       $v1, %hi(D_802DFA48)
/* 1019D0 802DE8E0 2463FA48 */  addiu     $v1, $v1, %lo(D_802DFA48)
/* 1019D4 802DE8E4 00041080 */  sll       $v0, $a0, 2
/* 1019D8 802DE8E8 00441021 */  addu      $v0, $v0, $a0
/* 1019DC 802DE8EC 00021080 */  sll       $v0, $v0, 2
/* 1019E0 802DE8F0 00434021 */  addu      $t0, $v0, $v1
/* 1019E4 802DE8F4 8D030004 */  lw        $v1, 4($t0)
/* 1019E8 802DE8F8 10600035 */  beqz      $v1, .L802DE9D0
/* 1019EC 802DE8FC 8FAB0010 */   lw       $t3, 0x10($sp)
/* 1019F0 802DE900 910A000F */  lbu       $t2, 0xf($t0)
/* 1019F4 802DE904 240200FF */  addiu     $v0, $zero, 0xff
/* 1019F8 802DE908 11420031 */  beq       $t2, $v0, .L802DE9D0
/* 1019FC 802DE90C 0060202D */   daddu    $a0, $v1, $zero
/* 101A00 802DE910 000A1080 */  sll       $v0, $t2, 2
/* 101A04 802DE914 8D030008 */  lw        $v1, 8($t0)
/* 101A08 802DE918 24420010 */  addiu     $v0, $v0, 0x10
/* 101A0C 802DE91C 00621821 */  addu      $v1, $v1, $v0
/* 101A10 802DE920 8C680000 */  lw        $t0, ($v1)
/* 101A14 802DE924 8C830000 */  lw        $v1, ($a0)
/* 101A18 802DE928 2402FFFF */  addiu     $v0, $zero, -1
/* 101A1C 802DE92C 10620028 */  beq       $v1, $v0, .L802DE9D0
/* 101A20 802DE930 0000482D */   daddu    $t1, $zero, $zero
/* 101A24 802DE934 0040182D */  daddu     $v1, $v0, $zero
.L802DE938:
/* 101A28 802DE938 1525001D */  bne       $t1, $a1, .L802DE9B0
/* 101A2C 802DE93C 25290001 */   addiu    $t1, $t1, 1
/* 101A30 802DE940 8D030000 */  lw        $v1, ($t0)
/* 101A34 802DE944 8C840000 */  lw        $a0, ($a0)
/* 101A38 802DE948 84620006 */  lh        $v0, 6($v1)
/* 101A3C 802DE94C C4800028 */  lwc1      $f0, 0x28($a0)
/* 101A40 802DE950 44821000 */  mtc1      $v0, $f2
/* 101A44 802DE954 00000000 */  nop
/* 101A48 802DE958 468010A0 */  cvt.s.w   $f2, $f2
/* 101A4C 802DE95C 46020000 */  add.s     $f0, $f0, $f2
/* 101A50 802DE960 4600010D */  trunc.w.s $f4, $f0
/* 101A54 802DE964 E4C40000 */  swc1      $f4, ($a2)
/* 101A58 802DE968 84620008 */  lh        $v0, 8($v1)
/* 101A5C 802DE96C C480002C */  lwc1      $f0, 0x2c($a0)
/* 101A60 802DE970 44821000 */  mtc1      $v0, $f2
/* 101A64 802DE974 00000000 */  nop
/* 101A68 802DE978 468010A0 */  cvt.s.w   $f2, $f2
/* 101A6C 802DE97C 46020000 */  add.s     $f0, $f0, $f2
/* 101A70 802DE980 4600010D */  trunc.w.s $f4, $f0
/* 101A74 802DE984 E4E40000 */  swc1      $f4, ($a3)
/* 101A78 802DE988 8462000A */  lh        $v0, 0xa($v1)
/* 101A7C 802DE98C C4820030 */  lwc1      $f2, 0x30($a0)
/* 101A80 802DE990 44820000 */  mtc1      $v0, $f0
/* 101A84 802DE994 00000000 */  nop
/* 101A88 802DE998 46800020 */  cvt.s.w   $f0, $f0
/* 101A8C 802DE99C 46001080 */  add.s     $f2, $f2, $f0
/* 101A90 802DE9A0 4600110D */  trunc.w.s $f4, $f2
/* 101A94 802DE9A4 E5640000 */  swc1      $f4, ($t3)
/* 101A98 802DE9A8 03E00008 */  jr        $ra
/* 101A9C 802DE9AC 0000102D */   daddu    $v0, $zero, $zero
.L802DE9B0:
/* 101AA0 802DE9B0 8D020000 */  lw        $v0, ($t0)
/* 101AA4 802DE9B4 10430002 */  beq       $v0, $v1, .L802DE9C0
/* 101AA8 802DE9B8 24840004 */   addiu    $a0, $a0, 4
/* 101AAC 802DE9BC 25080004 */  addiu     $t0, $t0, 4
.L802DE9C0:
/* 101AB0 802DE9C0 8C820000 */  lw        $v0, ($a0)
/* 101AB4 802DE9C4 1443FFDC */  bne       $v0, $v1, .L802DE938
/* 101AB8 802DE9C8 00000000 */   nop
/* 101ABC 802DE9CC 2402FFFF */  addiu     $v0, $zero, -1
.L802DE9D0:
/* 101AC0 802DE9D0 03E00008 */  jr        $ra
/* 101AC4 802DE9D4 00000000 */   nop
