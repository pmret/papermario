.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1388_722EC8
/* 722EC8 802A1388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 722ECC 802A138C AFB00010 */  sw        $s0, 0x10($sp)
/* 722ED0 802A1390 0080802D */  daddu     $s0, $a0, $zero
/* 722ED4 802A1394 10A0000E */  beqz      $a1, .L802A13D0
/* 722ED8 802A1398 AFBF0014 */   sw       $ra, 0x14($sp)
/* 722EDC 802A139C 0C04760B */  jal       func_8011D82C
/* 722EE0 802A13A0 24040001 */   addiu    $a0, $zero, 1
/* 722EE4 802A13A4 0000202D */  daddu     $a0, $zero, $zero
/* 722EE8 802A13A8 0080282D */  daddu     $a1, $a0, $zero
/* 722EEC 802A13AC 0080302D */  daddu     $a2, $a0, $zero
/* 722EF0 802A13B0 0080382D */  daddu     $a3, $a0, $zero
/* 722EF4 802A13B4 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 722EF8 802A13B8 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 722EFC 802A13BC 24030001 */  addiu     $v1, $zero, 1
/* 722F00 802A13C0 0C046F97 */  jal       set_background_color_blend
/* 722F04 802A13C4 A0430000 */   sb       $v1, ($v0)
/* 722F08 802A13C8 24020014 */  addiu     $v0, $zero, 0x14
/* 722F0C 802A13CC AE020070 */  sw        $v0, 0x70($s0)
.L802A13D0:
/* 722F10 802A13D0 0000202D */  daddu     $a0, $zero, $zero
/* 722F14 802A13D4 0080282D */  daddu     $a1, $a0, $zero
/* 722F18 802A13D8 0080302D */  daddu     $a2, $a0, $zero
/* 722F1C 802A13DC 8E030070 */  lw        $v1, 0x70($s0)
/* 722F20 802A13E0 24020014 */  addiu     $v0, $zero, 0x14
/* 722F24 802A13E4 00431023 */  subu      $v0, $v0, $v1
/* 722F28 802A13E8 00023880 */  sll       $a3, $v0, 2
/* 722F2C 802A13EC 00E23821 */  addu      $a3, $a3, $v0
/* 722F30 802A13F0 00073840 */  sll       $a3, $a3, 1
/* 722F34 802A13F4 0C046F97 */  jal       set_background_color_blend
/* 722F38 802A13F8 30E700FE */   andi     $a3, $a3, 0xfe
/* 722F3C 802A13FC 8E020070 */  lw        $v0, 0x70($s0)
/* 722F40 802A1400 2442FFFF */  addiu     $v0, $v0, -1
/* 722F44 802A1404 AE020070 */  sw        $v0, 0x70($s0)
/* 722F48 802A1408 2C420001 */  sltiu     $v0, $v0, 1
/* 722F4C 802A140C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 722F50 802A1410 8FB00010 */  lw        $s0, 0x10($sp)
/* 722F54 802A1414 00021040 */  sll       $v0, $v0, 1
/* 722F58 802A1418 03E00008 */  jr        $ra
/* 722F5C 802A141C 27BD0018 */   addiu    $sp, $sp, 0x18
