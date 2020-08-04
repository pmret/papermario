.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel make_npcs
/* 019A78 8003E678 3C028007 */  lui   $v0, 0x8007
/* 019A7C 8003E67C 8C42419C */  lw    $v0, 0x419c($v0)
/* 019A80 8003E680 3C08800B */  lui   $t0, 0x800b
/* 019A84 8003E684 25080F10 */  addiu $t0, $t0, 0xf10
/* 019A88 8003E688 A1040021 */  sb    $a0, 0x21($t0)
/* 019A8C 8003E68C A1050020 */  sb    $a1, 0x20($t0)
/* 019A90 8003E690 AD060024 */  sw    $a2, 0x24($t0)
/* 019A94 8003E694 8442008A */  lh    $v0, 0x8a($v0)
/* 019A98 8003E698 1040001B */  beqz  $v0, .L8003E708
/* 019A9C 8003E69C 00000000 */   nop   
/* 019AA0 8003E6A0 0000282D */  daddu $a1, $zero, $zero
/* 019AA4 8003E6A4 00A0382D */  daddu $a3, $a1, $zero
.L8003E6A8:
/* 019AA8 8003E6A8 0000202D */  daddu $a0, $zero, $zero
/* 019AAC 8003E6AC 00E0182D */  daddu $v1, $a3, $zero
.L8003E6B0:
/* 019AB0 8003E6B0 01031021 */  addu  $v0, $t0, $v1
/* 019AB4 8003E6B4 AC4000B0 */  sw    $zero, 0xb0($v0)
/* 019AB8 8003E6B8 24840001 */  addiu $a0, $a0, 1
/* 019ABC 8003E6BC 2882000C */  slti  $v0, $a0, 0xc
/* 019AC0 8003E6C0 1440FFFB */  bnez  $v0, .L8003E6B0
/* 019AC4 8003E6C4 24630004 */   addiu $v1, $v1, 4
/* 019AC8 8003E6C8 24A50001 */  addiu $a1, $a1, 1
/* 019ACC 8003E6CC 28A2003C */  slti  $v0, $a1, 0x3c
/* 019AD0 8003E6D0 1440FFF5 */  bnez  $v0, .L8003E6A8
/* 019AD4 8003E6D4 24E70030 */   addiu $a3, $a3, 0x30
/* 019AD8 8003E6D8 3C028007 */  lui   $v0, 0x8007
/* 019ADC 8003E6DC 8C42419C */  lw    $v0, 0x419c($v0)
/* 019AE0 8003E6E0 8442008A */  lh    $v0, 0x8a($v0)
/* 019AE4 8003E6E4 10400008 */  beqz  $v0, .L8003E708
/* 019AE8 8003E6E8 00000000 */   nop   
/* 019AEC 8003E6EC 2403FFFF */  addiu $v1, $zero, -1
/* 019AF0 8003E6F0 24050001 */  addiu $a1, $zero, 1
/* 019AF4 8003E6F4 25020002 */  addiu $v0, $t0, 2
.L8003E6F8:
/* 019AF8 8003E6F8 A4430BF0 */  sh    $v1, 0xbf0($v0)
/* 019AFC 8003E6FC 24A5FFFF */  addiu $a1, $a1, -1
/* 019B00 8003E700 04A1FFFD */  bgez  $a1, .L8003E6F8
/* 019B04 8003E704 2442FFFE */   addiu $v0, $v0, -2
.L8003E708:
/* 019B08 8003E708 10C00007 */  beqz  $a2, .L8003E728
/* 019B0C 8003E70C 24020001 */   addiu $v0, $zero, 1
/* 019B10 8003E710 3C01800A */  lui   $at, 0x800a
/* 019B14 8003E714 AC22A600 */  sw    $v0, -0x5a00($at)
/* 019B18 8003E718 3C01800A */  lui   $at, 0x800a
/* 019B1C 8003E71C AC22A678 */  sw    $v0, -0x5988($at)
/* 019B20 8003E720 3C01800A */  lui   $at, 0x800a
/* 019B24 8003E724 AC20A5D0 */  sw    $zero, -0x5a30($at)
.L8003E728:
/* 019B28 8003E728 03E00008 */  jr    $ra
/* 019B2C 8003E72C 00000000 */   nop   

