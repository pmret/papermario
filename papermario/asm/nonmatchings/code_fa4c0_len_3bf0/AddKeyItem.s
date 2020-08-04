.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddKeyItem
/* 0FB278 802D68C8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB27C 802D68CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0FB280 802D68D0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB284 802D68D4 8C82000C */  lw    $v0, 0xc($a0)
/* 0FB288 802D68D8 0C0B1EAF */  jal   get_variable
/* 0FB28C 802D68DC 8C450000 */   lw    $a1, ($v0)
/* 0FB290 802D68E0 3C108011 */  lui   $s0, 0x8011
/* 0FB294 802D68E4 2610F290 */  addiu $s0, $s0, -0xd70
/* 0FB298 802D68E8 0040282D */  daddu $a1, $v0, $zero
/* 0FB29C 802D68EC 24020010 */  addiu $v0, $zero, 0x10
/* 0FB2A0 802D68F0 14A20006 */  bne   $a1, $v0, .L802D690C
/* 0FB2A4 802D68F4 0000182D */   daddu $v1, $zero, $zero
/* 0FB2A8 802D68F8 9203000E */  lbu   $v1, 0xe($s0)
/* 0FB2AC 802D68FC 24020002 */  addiu $v0, $zero, 2
/* 0FB2B0 802D6900 24630001 */  addiu $v1, $v1, 1
/* 0FB2B4 802D6904 080B5A51 */  j     .L802D6944
/* 0FB2B8 802D6908 A203000E */   sb    $v1, 0xe($s0)

.L802D690C:
/* 0FB2BC 802D690C 0200202D */  daddu $a0, $s0, $zero
.L802D6910:
/* 0FB2C0 802D6910 84820074 */  lh    $v0, 0x74($a0)
/* 0FB2C4 802D6914 10400006 */  beqz  $v0, .L802D6930
/* 0FB2C8 802D6918 28620020 */   slti  $v0, $v1, 0x20
/* 0FB2CC 802D691C 24630001 */  addiu $v1, $v1, 1
/* 0FB2D0 802D6920 28620020 */  slti  $v0, $v1, 0x20
/* 0FB2D4 802D6924 1440FFFA */  bnez  $v0, .L802D6910
/* 0FB2D8 802D6928 24840002 */   addiu $a0, $a0, 2
/* 0FB2DC 802D692C 28620020 */  slti  $v0, $v1, 0x20
.L802D6930:
/* 0FB2E0 802D6930 10400003 */  beqz  $v0, .L802D6940
/* 0FB2E4 802D6934 00031040 */   sll   $v0, $v1, 1
/* 0FB2E8 802D6938 02021021 */  addu  $v0, $s0, $v0
/* 0FB2EC 802D693C A4450074 */  sh    $a1, 0x74($v0)
.L802D6940:
/* 0FB2F0 802D6940 24020002 */  addiu $v0, $zero, 2
.L802D6944:
/* 0FB2F4 802D6944 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0FB2F8 802D6948 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB2FC 802D694C 03E00008 */  jr    $ra
/* 0FB300 802D6950 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FB304 802D6954 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB308 802D6958 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FB30C 802D695C 0C038069 */  jal   func_800E01A4
/* 0FB310 802D6960 00000000 */   nop   
/* 0FB314 802D6964 0C038050 */  jal   disable_player_physics
/* 0FB318 802D6968 00000000 */   nop   
/* 0FB31C 802D696C 0C03BD80 */  jal   func_800EF600
/* 0FB320 802D6970 00000000 */   nop   
/* 0FB324 802D6974 3C03800A */  lui   $v1, 0x800a
/* 0FB328 802D6978 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0FB32C 802D697C 8C640000 */  lw    $a0, ($v1)
/* 0FB330 802D6980 2405FFBF */  addiu $a1, $zero, -0x41
/* 0FB334 802D6984 00852024 */  and   $a0, $a0, $a1
/* 0FB338 802D6988 AC640000 */  sw    $a0, ($v1)
/* 0FB33C 802D698C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FB340 802D6990 24020002 */  addiu $v0, $zero, 2
/* 0FB344 802D6994 03E00008 */  jr    $ra
/* 0FB348 802D6998 27BD0018 */   addiu $sp, $sp, 0x18

