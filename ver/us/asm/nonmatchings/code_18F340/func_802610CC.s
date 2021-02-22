.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802610CC
/* 18F9AC 802610CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18F9B0 802610D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 18F9B4 802610D4 0080802D */  daddu     $s0, $a0, $zero
/* 18F9B8 802610D8 10A0000E */  beqz      $a1, .L80261114
/* 18F9BC 802610DC AFBF0014 */   sw       $ra, 0x14($sp)
/* 18F9C0 802610E0 0C04760B */  jal       func_8011D82C
/* 18F9C4 802610E4 24040001 */   addiu    $a0, $zero, 1
/* 18F9C8 802610E8 0000202D */  daddu     $a0, $zero, $zero
/* 18F9CC 802610EC 0080282D */  daddu     $a1, $a0, $zero
/* 18F9D0 802610F0 0080302D */  daddu     $a2, $a0, $zero
/* 18F9D4 802610F4 0080382D */  daddu     $a3, $a0, $zero
/* 18F9D8 802610F8 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 18F9DC 802610FC 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 18F9E0 80261100 24030001 */  addiu     $v1, $zero, 1
/* 18F9E4 80261104 0C046F97 */  jal       set_background_color_blend
/* 18F9E8 80261108 A0430000 */   sb       $v1, ($v0)
/* 18F9EC 8026110C 24020014 */  addiu     $v0, $zero, 0x14
/* 18F9F0 80261110 AE020070 */  sw        $v0, 0x70($s0)
.L80261114:
/* 18F9F4 80261114 0000202D */  daddu     $a0, $zero, $zero
/* 18F9F8 80261118 0080282D */  daddu     $a1, $a0, $zero
/* 18F9FC 8026111C 0080302D */  daddu     $a2, $a0, $zero
/* 18FA00 80261120 8E030070 */  lw        $v1, 0x70($s0)
/* 18FA04 80261124 24020014 */  addiu     $v0, $zero, 0x14
/* 18FA08 80261128 00431023 */  subu      $v0, $v0, $v1
/* 18FA0C 8026112C 00023840 */  sll       $a3, $v0, 1
/* 18FA10 80261130 00E23821 */  addu      $a3, $a3, $v0
/* 18FA14 80261134 00073880 */  sll       $a3, $a3, 2
/* 18FA18 80261138 0C046F97 */  jal       set_background_color_blend
/* 18FA1C 8026113C 30E700FC */   andi     $a3, $a3, 0xfc
/* 18FA20 80261140 8E020070 */  lw        $v0, 0x70($s0)
/* 18FA24 80261144 2442FFFF */  addiu     $v0, $v0, -1
/* 18FA28 80261148 AE020070 */  sw        $v0, 0x70($s0)
/* 18FA2C 8026114C 2C420001 */  sltiu     $v0, $v0, 1
/* 18FA30 80261150 8FBF0014 */  lw        $ra, 0x14($sp)
/* 18FA34 80261154 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FA38 80261158 00021040 */  sll       $v0, $v0, 1
/* 18FA3C 8026115C 03E00008 */  jr        $ra
/* 18FA40 80261160 27BD0018 */   addiu    $sp, $sp, 0x18
