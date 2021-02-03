.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024141C_D9E8EC
/* D9E8EC 8024141C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D9E8F0 80241420 AFB10014 */  sw        $s1, 0x14($sp)
/* D9E8F4 80241424 0080882D */  daddu     $s1, $a0, $zero
/* D9E8F8 80241428 AFBF001C */  sw        $ra, 0x1c($sp)
/* D9E8FC 8024142C AFB20018 */  sw        $s2, 0x18($sp)
/* D9E900 80241430 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E904 80241434 8E300148 */  lw        $s0, 0x148($s1)
/* D9E908 80241438 86040008 */  lh        $a0, 8($s0)
/* D9E90C 8024143C 0C00EABB */  jal       get_npc_unsafe
/* D9E910 80241440 00A0902D */   daddu    $s2, $a1, $zero
/* D9E914 80241444 8E0300CC */  lw        $v1, 0xcc($s0)
/* D9E918 80241448 8C630004 */  lw        $v1, 4($v1)
/* D9E91C 8024144C 0040202D */  daddu     $a0, $v0, $zero
/* D9E920 80241450 AC830028 */  sw        $v1, 0x28($a0)
/* D9E924 80241454 8E0200D0 */  lw        $v0, 0xd0($s0)
/* D9E928 80241458 8C420014 */  lw        $v0, 0x14($v0)
/* D9E92C 8024145C 04410009 */  bgez      $v0, .L80241484
/* D9E930 80241460 00000000 */   nop
/* D9E934 80241464 C640000C */  lwc1      $f0, 0xc($s2)
/* D9E938 80241468 3C018024 */  lui       $at, %hi(D_80247A18_DA4EE8)
/* D9E93C 8024146C D4227A18 */  ldc1      $f2, %lo(D_80247A18_DA4EE8)($at)
/* D9E940 80241470 46000021 */  cvt.d.s   $f0, $f0
/* D9E944 80241474 46220002 */  mul.d     $f0, $f0, $f2
/* D9E948 80241478 00000000 */  nop
/* D9E94C 8024147C 08090528 */  j         .L802414A0
/* D9E950 80241480 46200020 */   cvt.s.d  $f0, $f0
.L80241484:
/* D9E954 80241484 3C018024 */  lui       $at, %hi(D_80247A20_DA4EF0)
/* D9E958 80241488 D4227A20 */  ldc1      $f2, %lo(D_80247A20_DA4EF0)($at)
/* D9E95C 8024148C 44820000 */  mtc1      $v0, $f0
/* D9E960 80241490 00000000 */  nop
/* D9E964 80241494 46800021 */  cvt.d.w   $f0, $f0
/* D9E968 80241498 46220003 */  div.d     $f0, $f0, $f2
/* D9E96C 8024149C 46200020 */  cvt.s.d   $f0, $f0
.L802414A0:
/* D9E970 802414A0 E4800018 */  swc1      $f0, 0x18($a0)
/* D9E974 802414A4 24020010 */  addiu     $v0, $zero, 0x10
/* D9E978 802414A8 AE200074 */  sw        $zero, 0x74($s1)
/* D9E97C 802414AC AE220070 */  sw        $v0, 0x70($s1)
/* D9E980 802414B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* D9E984 802414B4 8FB20018 */  lw        $s2, 0x18($sp)
/* D9E988 802414B8 8FB10014 */  lw        $s1, 0x14($sp)
/* D9E98C 802414BC 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E990 802414C0 03E00008 */  jr        $ra
/* D9E994 802414C4 27BD0020 */   addiu    $sp, $sp, 0x20
