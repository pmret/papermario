.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006062C
/* 3BA2C 8006062C 3C02800A */  lui       $v0, %hi(D_8009A5C0)
/* 3BA30 80060630 8C42A5C0 */  lw        $v0, %lo(D_8009A5C0)($v0)
/* 3BA34 80060634 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BA38 80060638 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BA3C 8006063C 0080802D */  daddu     $s0, $a0, $zero
/* 3BA40 80060640 1440002C */  bnez      $v0, .L800606F4
/* 3BA44 80060644 AFBF0014 */   sw       $ra, 0x14($sp)
/* 3BA48 80060648 3C04800B */  lui       $a0, %hi(D_800B0E98)
/* 3BA4C 8006064C 24840E98 */  addiu     $a0, $a0, %lo(D_800B0E98)
/* 3BA50 80060650 0000282D */  daddu     $a1, $zero, $zero
/* 3BA54 80060654 0C0195B0 */  jal       func_800656C0
/* 3BA58 80060658 00A0302D */   daddu    $a2, $a1, $zero
/* 3BA5C 8006065C 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3BA60 80060660 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3BA64 80060664 0C01865C */  jal       func_80061970
/* 3BA68 80060668 00000000 */   nop
/* 3BA6C 8006066C 14400016 */  bnez      $v0, .L800606C8
/* 3BA70 80060670 0000282D */   daddu    $a1, $zero, $zero
/* 3BA74 80060674 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3BA78 80060678 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3BA7C 8006067C 0C0195B0 */  jal       func_800656C0
/* 3BA80 80060680 24060001 */   addiu    $a2, $zero, 1
/* 3BA84 80060684 3C02800A */  lui       $v0, %hi(D_8009A5C0)
/* 3BA88 80060688 8C42A5C0 */  lw        $v0, %lo(D_8009A5C0)($v0)
/* 3BA8C 8006068C 30420001 */  andi      $v0, $v0, 1
/* 3BA90 80060690 1440000D */  bnez      $v0, .L800606C8
/* 3BA94 80060694 0000282D */   daddu    $a1, $zero, $zero
/* 3BA98 80060698 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BA9C 8006069C 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BAA0 800606A0 0C0195FC */  jal       func_800657F0
/* 3BAA4 800606A4 24060001 */   addiu    $a2, $zero, 1
/* 3BAA8 800606A8 3C04800B */  lui       $a0, %hi(D_800B1D48)
/* 3BAAC 800606AC 0C01867E */  jal       func_800619F8
/* 3BAB0 800606B0 24841D48 */   addiu    $a0, $a0, %lo(D_800B1D48)
/* 3BAB4 800606B4 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BAB8 800606B8 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BABC 800606BC 0000282D */  daddu     $a1, $zero, $zero
/* 3BAC0 800606C0 0C0195B0 */  jal       func_800656C0
/* 3BAC4 800606C4 24060001 */   addiu    $a2, $zero, 1
.L800606C8:
/* 3BAC8 800606C8 3C028009 */  lui       $v0, %hi(D_80093D00)
/* 3BACC 800606CC 8C423D00 */  lw        $v0, %lo(D_80093D00)($v0)
/* 3BAD0 800606D0 10400003 */  beqz      $v0, .L800606E0
/* 3BAD4 800606D4 00000000 */   nop
/* 3BAD8 800606D8 0040F809 */  jalr      $v0
/* 3BADC 800606DC 86040000 */   lh       $a0, ($s0)
.L800606E0:
/* 3BAE0 800606E0 3C04800B */  lui       $a0, %hi(D_800B0E98)
/* 3BAE4 800606E4 24840E98 */  addiu     $a0, $a0, %lo(D_800B0E98)
/* 3BAE8 800606E8 0000282D */  daddu     $a1, $zero, $zero
/* 3BAEC 800606EC 0C0195FC */  jal       func_800657F0
/* 3BAF0 800606F0 00A0302D */   daddu    $a2, $a1, $zero
.L800606F4:
/* 3BAF4 800606F4 0000102D */  daddu     $v0, $zero, $zero
/* 3BAF8 800606F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BAFC 800606FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BB00 80060700 03E00008 */  jr        $ra
/* 3BB04 80060704 27BD0018 */   addiu    $sp, $sp, 0x18
