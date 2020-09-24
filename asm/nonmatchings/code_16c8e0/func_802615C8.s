.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802615C8
/* 18FEA8 802615C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18FEAC 802615CC AFB00010 */  sw        $s0, 0x10($sp)
/* 18FEB0 802615D0 0080802D */  daddu     $s0, $a0, $zero
/* 18FEB4 802615D4 10A00003 */  beqz      $a1, .L802615E4
/* 18FEB8 802615D8 AFBF0014 */   sw       $ra, 0x14($sp)
/* 18FEBC 802615DC 24020019 */  addiu     $v0, $zero, 0x19
/* 18FEC0 802615E0 AE020070 */  sw        $v0, 0x70($s0)
.L802615E4:
/* 18FEC4 802615E4 0000202D */  daddu     $a0, $zero, $zero
/* 18FEC8 802615E8 0080282D */  daddu     $a1, $a0, $zero
/* 18FECC 802615EC 8E020070 */  lw        $v0, 0x70($s0)
/* 18FED0 802615F0 0080302D */  daddu     $a2, $a0, $zero
/* 18FED4 802615F4 00023880 */  sll       $a3, $v0, 2
/* 18FED8 802615F8 00E23821 */  addu      $a3, $a3, $v0
/* 18FEDC 802615FC 00073840 */  sll       $a3, $a3, 1
/* 18FEE0 80261600 0C046F97 */  jal       set_background_color_blend
/* 18FEE4 80261604 30E700FE */   andi     $a3, $a3, 0xfe
/* 18FEE8 80261608 8E020070 */  lw        $v0, 0x70($s0)
/* 18FEEC 8026160C 2442FFFB */  addiu     $v0, $v0, -5
/* 18FEF0 80261610 10400003 */  beqz      $v0, .L80261620
/* 18FEF4 80261614 AE020070 */   sw       $v0, 0x70($s0)
/* 18FEF8 80261618 0809858E */  j         .L80261638
/* 18FEFC 8026161C 0000102D */   daddu    $v0, $zero, $zero
.L80261620:
/* 18FF00 80261620 0000202D */  daddu     $a0, $zero, $zero
/* 18FF04 80261624 0080282D */  daddu     $a1, $a0, $zero
/* 18FF08 80261628 0080302D */  daddu     $a2, $a0, $zero
/* 18FF0C 8026162C 0C046F97 */  jal       set_background_color_blend
/* 18FF10 80261630 0080382D */   daddu    $a3, $a0, $zero
/* 18FF14 80261634 24020002 */  addiu     $v0, $zero, 2
.L80261638:
/* 18FF18 80261638 8FBF0014 */  lw        $ra, 0x14($sp)
/* 18FF1C 8026163C 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FF20 80261640 03E00008 */  jr        $ra
/* 18FF24 80261644 27BD0018 */   addiu    $sp, $sp, 0x18
