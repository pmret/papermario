.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409EC_B073EC
/* B073EC 802409EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B073F0 802409F0 AFB10014 */  sw        $s1, 0x14($sp)
/* B073F4 802409F4 0080882D */  daddu     $s1, $a0, $zero
/* B073F8 802409F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B073FC 802409FC AFB20018 */  sw        $s2, 0x18($sp)
/* B07400 80240A00 AFB00010 */  sw        $s0, 0x10($sp)
/* B07404 80240A04 8E30000C */  lw        $s0, 0xc($s1)
/* B07408 80240A08 8E050000 */  lw        $a1, ($s0)
/* B0740C 80240A0C 0C0B210B */  jal       evt_get_float_variable
/* B07410 80240A10 26100004 */   addiu    $s0, $s0, 4
/* B07414 80240A14 8E050000 */  lw        $a1, ($s0)
/* B07418 80240A18 26100004 */  addiu     $s0, $s0, 4
/* B0741C 80240A1C 4600008D */  trunc.w.s $f2, $f0
/* B07420 80240A20 44121000 */  mfc1      $s2, $f2
/* B07424 80240A24 0C0B210B */  jal       evt_get_float_variable
/* B07428 80240A28 0220202D */   daddu    $a0, $s1, $zero
/* B0742C 80240A2C 0220202D */  daddu     $a0, $s1, $zero
/* B07430 80240A30 8E050000 */  lw        $a1, ($s0)
/* B07434 80240A34 4600008D */  trunc.w.s $f2, $f0
/* B07438 80240A38 44111000 */  mfc1      $s1, $f2
/* B0743C 80240A3C 0C0B210B */  jal       evt_get_float_variable
/* B07440 80240A40 00000000 */   nop
/* B07444 80240A44 0000202D */  daddu     $a0, $zero, $zero
/* B07448 80240A48 3C05FD05 */  lui       $a1, 0xfd05
/* B0744C 80240A4C 4600008D */  trunc.w.s $f2, $f0
/* B07450 80240A50 44101000 */  mfc1      $s0, $f2
/* B07454 80240A54 0C0B1EAF */  jal       evt_get_variable
/* B07458 80240A58 34A50F8A */   ori      $a1, $a1, 0xf8a
/* B0745C 80240A5C 0040182D */  daddu     $v1, $v0, $zero
/* B07460 80240A60 44920000 */  mtc1      $s2, $f0
/* B07464 80240A64 00000000 */  nop
/* B07468 80240A68 46800020 */  cvt.s.w   $f0, $f0
/* B0746C 80240A6C E4600028 */  swc1      $f0, 0x28($v1)
/* B07470 80240A70 44910000 */  mtc1      $s1, $f0
/* B07474 80240A74 00000000 */  nop
/* B07478 80240A78 46800020 */  cvt.s.w   $f0, $f0
/* B0747C 80240A7C E460002C */  swc1      $f0, 0x2c($v1)
/* B07480 80240A80 44900000 */  mtc1      $s0, $f0
/* B07484 80240A84 00000000 */  nop
/* B07488 80240A88 46800020 */  cvt.s.w   $f0, $f0
/* B0748C 80240A8C E4600030 */  swc1      $f0, 0x30($v1)
/* B07490 80240A90 8FBF001C */  lw        $ra, 0x1c($sp)
/* B07494 80240A94 8FB20018 */  lw        $s2, 0x18($sp)
/* B07498 80240A98 8FB10014 */  lw        $s1, 0x14($sp)
/* B0749C 80240A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* B074A0 80240AA0 24020002 */  addiu     $v0, $zero, 2
/* B074A4 80240AA4 03E00008 */  jr        $ra
/* B074A8 80240AA8 27BD0020 */   addiu    $sp, $sp, 0x20
