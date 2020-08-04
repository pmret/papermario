.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802D4488
/* 0F8E38 802D4488 3C028007 */  lui   $v0, 0x8007
/* 0F8E3C 802D448C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0F8E40 802D4490 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8E44 802D4494 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8E48 802D4498 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8E4C 802D449C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8E50 802D44A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8E54 802D44A4 80420070 */  lb    $v0, 0x70($v0)
/* 0F8E58 802D44A8 14400005 */  bnez  $v0, .L802D44C0
/* 0F8E5C 802D44AC 00000000 */   nop   
/* 0F8E60 802D44B0 3C02802E */  lui   $v0, 0x802e
/* 0F8E64 802D44B4 2442B6C0 */  addiu $v0, $v0, -0x4940
/* 0F8E68 802D44B8 080B5132 */  j     .L802D44C8
/* 0F8E6C 802D44BC 00000000 */   nop   

.L802D44C0:
/* 0F8E70 802D44C0 3C02802E */  lui   $v0, 0x802e
/* 0F8E74 802D44C4 2442B5C0 */  addiu $v0, $v0, -0x4a40
.L802D44C8:
/* 0F8E78 802D44C8 3C01802E */  lui   $at, 0x802e
/* 0F8E7C 802D44CC AC22B7C0 */  sw    $v0, -0x4840($at)
/* 0F8E80 802D44D0 0000882D */  daddu $s1, $zero, $zero
/* 0F8E84 802D44D4 2412FFFF */  addiu $s2, $zero, -1
/* 0F8E88 802D44D8 0220802D */  daddu $s0, $s1, $zero
.L802D44DC:
/* 0F8E8C 802D44DC 0C00AB39 */  jal   heap_malloc
/* 0F8E90 802D44E0 2404004C */   addiu $a0, $zero, 0x4c
/* 0F8E94 802D44E4 3C03802E */  lui   $v1, 0x802e
/* 0F8E98 802D44E8 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F8E9C 802D44EC 02031821 */  addu  $v1, $s0, $v1
/* 0F8EA0 802D44F0 14400003 */  bnez  $v0, .L802D4500
/* 0F8EA4 802D44F4 AC620000 */   sw    $v0, ($v1)
.L802D44F8:
/* 0F8EA8 802D44F8 080B513E */  j     .L802D44F8
/* 0F8EAC 802D44FC 00000000 */   nop   

.L802D4500:
/* 0F8EB0 802D4500 3C02802E */  lui   $v0, 0x802e
/* 0F8EB4 802D4504 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8EB8 802D4508 26310001 */  addiu $s1, $s1, 1
/* 0F8EBC 802D450C 02021021 */  addu  $v0, $s0, $v0
/* 0F8EC0 802D4510 8C420000 */  lw    $v0, ($v0)
/* 0F8EC4 802D4514 AC520000 */  sw    $s2, ($v0)
/* 0F8EC8 802D4518 2A220040 */  slti  $v0, $s1, 0x40
/* 0F8ECC 802D451C 1440FFEF */  bnez  $v0, .L802D44DC
/* 0F8ED0 802D4520 26100004 */   addiu $s0, $s0, 4
/* 0F8ED4 802D4524 3C04802D */  lui   $a0, 0x802d
/* 0F8ED8 802D4528 24842FCC */  addiu $a0, $a0, 0x2fcc
/* 0F8EDC 802D452C 3C05802D */  lui   $a1, 0x802d
/* 0F8EE0 802D4530 0C048C56 */  jal   func_80123158
/* 0F8EE4 802D4534 24A53028 */   addiu $a1, $a1, 0x3028
/* 0F8EE8 802D4538 3C05802D */  lui   $a1, 0x802d
/* 0F8EEC 802D453C 24A531E0 */  addiu $a1, $a1, 0x31e0
/* 0F8EF0 802D4540 0C048CC8 */  jal   func_80123320
/* 0F8EF4 802D4544 0000202D */   daddu $a0, $zero, $zero
/* 0F8EF8 802D4548 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F8EFC 802D454C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8F00 802D4550 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8F04 802D4554 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8F08 802D4558 03E00008 */  jr    $ra
/* 0F8F0C 802D455C 27BD0020 */   addiu $sp, $sp, 0x20

