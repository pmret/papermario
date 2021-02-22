.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E5B4
/* 299B4 8004E5B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 299B8 8004E5B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 299BC 8004E5BC 0080802D */  daddu     $s0, $a0, $zero
/* 299C0 8004E5C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 299C4 8004E5C4 24110001 */  addiu     $s1, $zero, 1
/* 299C8 8004E5C8 AFB40020 */  sw        $s4, 0x20($sp)
/* 299CC 8004E5CC 24140004 */  addiu     $s4, $zero, 4
/* 299D0 8004E5D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 299D4 8004E5D4 3C130004 */  lui       $s3, 4
/* 299D8 8004E5D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 299DC 8004E5DC 3C120006 */  lui       $s2, 6
/* 299E0 8004E5E0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 299E4 8004E5E4 AE0000B4 */  sw        $zero, 0xb4($s0)
/* 299E8 8004E5E8 AE0000BC */  sw        $zero, 0xbc($s0)
.L8004E5EC:
/* 299EC 8004E5EC 8E020068 */  lw        $v0, 0x68($s0)
/* 299F0 8004E5F0 8C450000 */  lw        $a1, ($v0)
/* 299F4 8004E5F4 24420004 */  addiu     $v0, $v0, 4
/* 299F8 8004E5F8 14A00003 */  bnez      $a1, .L8004E608
/* 299FC 8004E5FC AE020068 */   sw       $v0, 0x68($s0)
/* 29A00 8004E600 080139AD */  j         .L8004E6B4
/* 29A04 8004E604 A2140221 */   sb       $s4, 0x221($s0)
.L8004E608:
/* 29A08 8004E608 00051B02 */  srl       $v1, $a1, 0xc
/* 29A0C 8004E60C 10730029 */  beq       $v1, $s3, .L8004E6B4
/* 29A10 8004E610 0263102B */   sltu     $v0, $s3, $v1
/* 29A14 8004E614 14400007 */  bnez      $v0, .L8004E634
/* 29A18 8004E618 3C020001 */   lui      $v0, 1
/* 29A1C 8004E61C 10620012 */  beq       $v1, $v0, .L8004E668
/* 29A20 8004E620 3C020003 */   lui      $v0, 3
/* 29A24 8004E624 10620025 */  beq       $v1, $v0, .L8004E6BC
/* 29A28 8004E628 3222FFFF */   andi     $v0, $s1, 0xffff
/* 29A2C 8004E62C 080139AE */  j         .L8004E6B8
/* 29A30 8004E630 0000882D */   daddu    $s1, $zero, $zero
.L8004E634:
/* 29A34 8004E634 10720011 */  beq       $v1, $s2, .L8004E67C
/* 29A38 8004E638 0243102B */   sltu     $v0, $s2, $v1
/* 29A3C 8004E63C 14400006 */  bnez      $v0, .L8004E658
/* 29A40 8004E640 3C020007 */   lui      $v0, 7
/* 29A44 8004E644 3C020005 */  lui       $v0, 5
/* 29A48 8004E648 10620016 */  beq       $v1, $v0, .L8004E6A4
/* 29A4C 8004E64C 00000000 */   nop
/* 29A50 8004E650 080139AE */  j         .L8004E6B8
/* 29A54 8004E654 0000882D */   daddu    $s1, $zero, $zero
.L8004E658:
/* 29A58 8004E658 1062000E */  beq       $v1, $v0, .L8004E694
/* 29A5C 8004E65C 00000000 */   nop
/* 29A60 8004E660 080139AE */  j         .L8004E6B8
/* 29A64 8004E664 0000882D */   daddu    $s1, $zero, $zero
.L8004E668:
/* 29A68 8004E668 0C0139E1 */  jal       func_8004E784
/* 29A6C 8004E66C 0200202D */   daddu    $a0, $s0, $zero
/* 29A70 8004E670 24020001 */  addiu     $v0, $zero, 1
/* 29A74 8004E674 080139AD */  j         .L8004E6B4
/* 29A78 8004E678 A2020221 */   sb       $v0, 0x221($s0)
.L8004E67C:
/* 29A7C 8004E67C 92020223 */  lbu       $v0, 0x223($s0)
/* 29A80 8004E680 30420001 */  andi      $v0, $v0, 1
/* 29A84 8004E684 1440000D */  bnez      $v0, .L8004E6BC
/* 29A88 8004E688 3222FFFF */   andi     $v0, $s1, 0xffff
/* 29A8C 8004E68C 080139A9 */  j         .L8004E6A4
/* 29A90 8004E690 00000000 */   nop
.L8004E694:
/* 29A94 8004E694 92020223 */  lbu       $v0, 0x223($s0)
/* 29A98 8004E698 30420001 */  andi      $v0, $v0, 1
/* 29A9C 8004E69C 10400007 */  beqz      $v0, .L8004E6BC
/* 29AA0 8004E6A0 3222FFFF */   andi     $v0, $s1, 0xffff
.L8004E6A4:
/* 29AA4 8004E6A4 0C0139B9 */  jal       func_8004E6E4
/* 29AA8 8004E6A8 0200202D */   daddu    $a0, $s0, $zero
/* 29AAC 8004E6AC 080139AF */  j         .L8004E6BC
/* 29AB0 8004E6B0 3222FFFF */   andi     $v0, $s1, 0xffff
.L8004E6B4:
/* 29AB4 8004E6B4 0000882D */  daddu     $s1, $zero, $zero
.L8004E6B8:
/* 29AB8 8004E6B8 3222FFFF */  andi      $v0, $s1, 0xffff
.L8004E6BC:
/* 29ABC 8004E6BC 1440FFCB */  bnez      $v0, .L8004E5EC
/* 29AC0 8004E6C0 00000000 */   nop
/* 29AC4 8004E6C4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 29AC8 8004E6C8 8FB40020 */  lw        $s4, 0x20($sp)
/* 29ACC 8004E6CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 29AD0 8004E6D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 29AD4 8004E6D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 29AD8 8004E6D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 29ADC 8004E6DC 03E00008 */  jr        $ra
/* 29AE0 8004E6E0 27BD0028 */   addiu    $sp, $sp, 0x28
