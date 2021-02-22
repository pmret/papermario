.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261530
/* 18FE10 80261530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18FE14 80261534 AFB00010 */  sw        $s0, 0x10($sp)
/* 18FE18 80261538 0080802D */  daddu     $s0, $a0, $zero
/* 18FE1C 8026153C 10A0000E */  beqz      $a1, .L80261578
/* 18FE20 80261540 AFBF0014 */   sw       $ra, 0x14($sp)
/* 18FE24 80261544 0C04760B */  jal       func_8011D82C
/* 18FE28 80261548 24040001 */   addiu    $a0, $zero, 1
/* 18FE2C 8026154C 0000202D */  daddu     $a0, $zero, $zero
/* 18FE30 80261550 0080282D */  daddu     $a1, $a0, $zero
/* 18FE34 80261554 0080302D */  daddu     $a2, $a0, $zero
/* 18FE38 80261558 0080382D */  daddu     $a3, $a0, $zero
/* 18FE3C 8026155C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 18FE40 80261560 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 18FE44 80261564 24030001 */  addiu     $v1, $zero, 1
/* 18FE48 80261568 0C046F97 */  jal       set_background_color_blend
/* 18FE4C 8026156C A0430000 */   sb       $v1, ($v0)
/* 18FE50 80261570 24020019 */  addiu     $v0, $zero, 0x19
/* 18FE54 80261574 AE020070 */  sw        $v0, 0x70($s0)
.L80261578:
/* 18FE58 80261578 0000202D */  daddu     $a0, $zero, $zero
/* 18FE5C 8026157C 0080282D */  daddu     $a1, $a0, $zero
/* 18FE60 80261580 0080302D */  daddu     $a2, $a0, $zero
/* 18FE64 80261584 8E030070 */  lw        $v1, 0x70($s0)
/* 18FE68 80261588 24020019 */  addiu     $v0, $zero, 0x19
/* 18FE6C 8026158C 00431023 */  subu      $v0, $v0, $v1
/* 18FE70 80261590 00023880 */  sll       $a3, $v0, 2
/* 18FE74 80261594 00E23821 */  addu      $a3, $a3, $v0
/* 18FE78 80261598 00073840 */  sll       $a3, $a3, 1
/* 18FE7C 8026159C 0C046F97 */  jal       set_background_color_blend
/* 18FE80 802615A0 30E700FE */   andi     $a3, $a3, 0xfe
/* 18FE84 802615A4 8E020070 */  lw        $v0, 0x70($s0)
/* 18FE88 802615A8 2442FFFF */  addiu     $v0, $v0, -1
/* 18FE8C 802615AC AE020070 */  sw        $v0, 0x70($s0)
/* 18FE90 802615B0 2C420001 */  sltiu     $v0, $v0, 1
/* 18FE94 802615B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 18FE98 802615B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FE9C 802615BC 00021040 */  sll       $v0, $v0, 1
/* 18FEA0 802615C0 03E00008 */  jr        $ra
/* 18FEA4 802615C4 27BD0018 */   addiu    $sp, $sp, 0x18
