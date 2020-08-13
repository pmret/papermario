.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel LoadSettings
/* 0F03A8 802CB9F8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F03AC 802CB9FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F03B0 802CBA00 0080882D */  daddu $s1, $a0, $zero
/* 0F03B4 802CBA04 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F03B8 802CBA08 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F03BC 802CBA0C 8E30000C */  lw    $s0, 0xc($s1)
/* 0F03C0 802CBA10 8E050000 */  lw    $a1, ($s0)
/* 0F03C4 802CBA14 0C0B1EAF */  jal   get_variable
/* 0F03C8 802CBA18 26100004 */   addiu $s0, $s0, 4
/* 0F03CC 802CBA1C 0220202D */  daddu $a0, $s1, $zero
/* 0F03D0 802CBA20 3C03800B */  lui   $v1, 0x800b
/* 0F03D4 802CBA24 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F03D8 802CBA28 8E050000 */  lw    $a1, ($s0)
/* 0F03DC 802CBA2C 00028080 */  sll   $s0, $v0, 2
/* 0F03E0 802CBA30 02028021 */  addu  $s0, $s0, $v0
/* 0F03E4 802CBA34 00108080 */  sll   $s0, $s0, 2
/* 0F03E8 802CBA38 02028023 */  subu  $s0, $s0, $v0
/* 0F03EC 802CBA3C 001010C0 */  sll   $v0, $s0, 3
/* 0F03F0 802CBA40 02028021 */  addu  $s0, $s0, $v0
/* 0F03F4 802CBA44 001080C0 */  sll   $s0, $s0, 3
/* 0F03F8 802CBA48 0C0B1EAF */  jal   get_variable
/* 0F03FC 802CBA4C 02038021 */   addu  $s0, $s0, $v1
/* 0F0400 802CBA50 261004D8 */  addiu $s0, $s0, 0x4d8
/* 0F0404 802CBA54 24430020 */  addiu $v1, $v0, 0x20
.L802CBA58:
/* 0F0408 802CBA58 8C460000 */  lw    $a2, ($v0)
/* 0F040C 802CBA5C 8C470004 */  lw    $a3, 4($v0)
/* 0F0410 802CBA60 8C480008 */  lw    $t0, 8($v0)
/* 0F0414 802CBA64 8C49000C */  lw    $t1, 0xc($v0)
/* 0F0418 802CBA68 AE060000 */  sw    $a2, ($s0)
/* 0F041C 802CBA6C AE070004 */  sw    $a3, 4($s0)
/* 0F0420 802CBA70 AE080008 */  sw    $t0, 8($s0)
/* 0F0424 802CBA74 AE09000C */  sw    $t1, 0xc($s0)
/* 0F0428 802CBA78 24420010 */  addiu $v0, $v0, 0x10
/* 0F042C 802CBA7C 1443FFF6 */  bne   $v0, $v1, .L802CBA58
/* 0F0430 802CBA80 26100010 */   addiu $s0, $s0, 0x10
/* 0F0434 802CBA84 8C460000 */  lw    $a2, ($v0)
/* 0F0438 802CBA88 8C470004 */  lw    $a3, 4($v0)
/* 0F043C 802CBA8C 8C480008 */  lw    $t0, 8($v0)
/* 0F0440 802CBA90 AE060000 */  sw    $a2, ($s0)
/* 0F0444 802CBA94 AE070004 */  sw    $a3, 4($s0)
/* 0F0448 802CBA98 AE080008 */  sw    $t0, 8($s0)
/* 0F044C 802CBA9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F0450 802CBAA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0454 802CBAA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0458 802CBAA8 24020002 */  addiu $v0, $zero, 2
/* 0F045C 802CBAAC 03E00008 */  jr    $ra
/* 0F0460 802CBAB0 27BD0020 */   addiu $sp, $sp, 0x20

