.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219394_6A0594
/* 6A0594 80219394 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A0598 80219398 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A059C 8021939C 0080802D */  daddu     $s0, $a0, $zero
/* 6A05A0 802193A0 10A00003 */  beqz      $a1, .L802193B0
/* 6A05A4 802193A4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 6A05A8 802193A8 24020014 */  addiu     $v0, $zero, 0x14
/* 6A05AC 802193AC AE020070 */  sw        $v0, 0x70($s0)
.L802193B0:
/* 6A05B0 802193B0 0000202D */  daddu     $a0, $zero, $zero
/* 6A05B4 802193B4 0080282D */  daddu     $a1, $a0, $zero
/* 6A05B8 802193B8 8E020070 */  lw        $v0, 0x70($s0)
/* 6A05BC 802193BC 0080302D */  daddu     $a2, $a0, $zero
/* 6A05C0 802193C0 00023880 */  sll       $a3, $v0, 2
/* 6A05C4 802193C4 00E23821 */  addu      $a3, $a3, $v0
/* 6A05C8 802193C8 00073840 */  sll       $a3, $a3, 1
/* 6A05CC 802193CC 0C046F97 */  jal       set_background_color_blend
/* 6A05D0 802193D0 30E700FE */   andi     $a3, $a3, 0xfe
/* 6A05D4 802193D4 8E020070 */  lw        $v0, 0x70($s0)
/* 6A05D8 802193D8 2442FFFF */  addiu     $v0, $v0, -1
/* 6A05DC 802193DC 10400003 */  beqz      $v0, .L802193EC
/* 6A05E0 802193E0 AE020070 */   sw       $v0, 0x70($s0)
/* 6A05E4 802193E4 08086501 */  j         .L80219404
/* 6A05E8 802193E8 0000102D */   daddu    $v0, $zero, $zero
.L802193EC:
/* 6A05EC 802193EC 0000202D */  daddu     $a0, $zero, $zero
/* 6A05F0 802193F0 0080282D */  daddu     $a1, $a0, $zero
/* 6A05F4 802193F4 0080302D */  daddu     $a2, $a0, $zero
/* 6A05F8 802193F8 0C046F97 */  jal       set_background_color_blend
/* 6A05FC 802193FC 0080382D */   daddu    $a3, $a0, $zero
/* 6A0600 80219400 24020002 */  addiu     $v0, $zero, 2
.L80219404:
/* 6A0604 80219404 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6A0608 80219408 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A060C 8021940C 03E00008 */  jr        $ra
/* 6A0610 80219410 27BD0018 */   addiu    $sp, $sp, 0x18
