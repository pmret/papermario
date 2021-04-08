.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D4B8
.word L8025D07C_18B95C, L8025D08C_18B96C, L8025D09C_18B97C, L8025D0AC_18B98C, L8025D0BC_18B99C, L8025D0CC_18B9AC, L8025D0DC_18B9BC, L8025D0EC_18B9CC, L8025D0FC_18B9DC, L8025D10C_18B9EC, L8025D11C_18B9FC, L8025D12C_18BA0C

.section .text

glabel _remove_part_decoration
/* 18B91C 8025D03C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18B920 8025D040 AFBF0018 */  sw        $ra, 0x18($sp)
/* 18B924 8025D044 AFB10014 */  sw        $s1, 0x14($sp)
/* 18B928 8025D048 AFB00010 */  sw        $s0, 0x10($sp)
/* 18B92C 8025D04C 8C9100C0 */  lw        $s1, 0xc0($a0)
/* 18B930 8025D050 00A0802D */  daddu     $s0, $a1, $zero
/* 18B934 8025D054 02301021 */  addu      $v0, $s1, $s0
/* 18B938 8025D058 804308B8 */  lb        $v1, 0x8b8($v0)
/* 18B93C 8025D05C 2C62000C */  sltiu     $v0, $v1, 0xc
/* 18B940 8025D060 10400034 */  beqz      $v0, .L8025D134
/* 18B944 8025D064 00031080 */   sll      $v0, $v1, 2
/* 18B948 8025D068 3C01802A */  lui       $at, %hi(jtbl_8029D4B8)
/* 18B94C 8025D06C 00220821 */  addu      $at, $at, $v0
/* 18B950 8025D070 8C22D4B8 */  lw        $v0, %lo(jtbl_8029D4B8)($at)
/* 18B954 8025D074 00400008 */  jr        $v0
/* 18B958 8025D078 00000000 */   nop
glabel L8025D07C_18B95C
/* 18B95C 8025D07C 0C097456 */  jal       func_8025D158
/* 18B960 8025D080 0200282D */   daddu    $a1, $s0, $zero
/* 18B964 8025D084 0809744E */  j         .L8025D138
/* 18B968 8025D088 02301021 */   addu     $v0, $s1, $s0
glabel L8025D08C_18B96C
/* 18B96C 8025D08C 0C0974A4 */  jal       func_8025D290
/* 18B970 8025D090 0200282D */   daddu    $a1, $s0, $zero
/* 18B974 8025D094 0809744E */  j         .L8025D138
/* 18B978 8025D098 02301021 */   addu     $v0, $s1, $s0
glabel L8025D09C_18B97C
/* 18B97C 8025D09C 0C0974F1 */  jal       func_8025D3C4
/* 18B980 8025D0A0 0200282D */   daddu    $a1, $s0, $zero
/* 18B984 8025D0A4 0809744E */  j         .L8025D138
/* 18B988 8025D0A8 02301021 */   addu     $v0, $s1, $s0
glabel L8025D0AC_18B98C
/* 18B98C 8025D0AC 0C097528 */  jal       func_8025D4A0
/* 18B990 8025D0B0 0200282D */   daddu    $a1, $s0, $zero
/* 18B994 8025D0B4 0809744E */  j         .L8025D138
/* 18B998 8025D0B8 02301021 */   addu     $v0, $s1, $s0
glabel L8025D0BC_18B99C
/* 18B99C 8025D0BC 0C097588 */  jal       func_8025D620
/* 18B9A0 8025D0C0 0200282D */   daddu    $a1, $s0, $zero
/* 18B9A4 8025D0C4 0809744E */  j         .L8025D138
/* 18B9A8 8025D0C8 02301021 */   addu     $v0, $s1, $s0
glabel L8025D0CC_18B9AC
/* 18B9AC 8025D0CC 0C0975BF */  jal       func_8025D6FC
/* 18B9B0 8025D0D0 0200282D */   daddu    $a1, $s0, $zero
/* 18B9B4 8025D0D4 0809744E */  j         .L8025D138
/* 18B9B8 8025D0D8 02301021 */   addu     $v0, $s1, $s0
glabel L8025D0DC_18B9BC
/* 18B9BC 8025D0DC 0C097604 */  jal       func_8025D810
/* 18B9C0 8025D0E0 0200282D */   daddu    $a1, $s0, $zero
/* 18B9C4 8025D0E4 0809744E */  j         .L8025D138
/* 18B9C8 8025D0E8 02301021 */   addu     $v0, $s1, $s0
glabel L8025D0EC_18B9CC
/* 18B9CC 8025D0EC 0C09763B */  jal       func_8025D8EC
/* 18B9D0 8025D0F0 0200282D */   daddu    $a1, $s0, $zero
/* 18B9D4 8025D0F4 0809744E */  j         .L8025D138
/* 18B9D8 8025D0F8 02301021 */   addu     $v0, $s1, $s0
glabel L8025D0FC_18B9DC
/* 18B9DC 8025D0FC 0C097698 */  jal       func_8025DA60
/* 18B9E0 8025D100 0200282D */   daddu    $a1, $s0, $zero
/* 18B9E4 8025D104 0809744E */  j         .L8025D138
/* 18B9E8 8025D108 02301021 */   addu     $v0, $s1, $s0
glabel L8025D10C_18B9EC
/* 18B9EC 8025D10C 0C0976F2 */  jal       func_8025DBC8
/* 18B9F0 8025D110 0200282D */   daddu    $a1, $s0, $zero
/* 18B9F4 8025D114 0809744E */  j         .L8025D138
/* 18B9F8 8025D118 02301021 */   addu     $v0, $s1, $s0
glabel L8025D11C_18B9FC
/* 18B9FC 8025D11C 0C097750 */  jal       func_8025DD40
/* 18BA00 8025D120 0200282D */   daddu    $a1, $s0, $zero
/* 18BA04 8025D124 0809744E */  j         .L8025D138
/* 18BA08 8025D128 02301021 */   addu     $v0, $s1, $s0
glabel L8025D12C_18BA0C
/* 18BA0C 8025D12C 0C0977A2 */  jal       func_8025DE88
/* 18BA10 8025D130 0200282D */   daddu    $a1, $s0, $zero
.L8025D134:
/* 18BA14 8025D134 02301021 */  addu      $v0, $s1, $s0
.L8025D138:
/* 18BA18 8025D138 A04008B8 */  sb        $zero, 0x8b8($v0)
/* 18BA1C 8025D13C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18BA20 8025D140 8FB10014 */  lw        $s1, 0x14($sp)
/* 18BA24 8025D144 8FB00010 */  lw        $s0, 0x10($sp)
/* 18BA28 8025D148 03E00008 */  jr        $ra
/* 18BA2C 8025D14C 27BD0020 */   addiu    $sp, $sp, 0x20
