.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetAnimModelPosition
/* 0F1994 802CCFE4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1998 802CCFE8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F199C 802CCFEC 0080902D */  daddu $s2, $a0, $zero
/* 0F19A0 802CCFF0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F19A4 802CCFF4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F19A8 802CCFF8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F19AC 802CCFFC F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F19B0 802CD000 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F19B4 802CD004 8E50000C */  lw    $s0, 0xc($s2)
/* 0F19B8 802CD008 8E050000 */  lw    $a1, ($s0)
/* 0F19BC 802CD00C 0C0B1EAF */  jal   get_variable
/* 0F19C0 802CD010 26100004 */   addiu $s0, $s0, 4
/* 0F19C4 802CD014 8E050000 */  lw    $a1, ($s0)
/* 0F19C8 802CD018 26100004 */  addiu $s0, $s0, 4
/* 0F19CC 802CD01C 0240202D */  daddu $a0, $s2, $zero
/* 0F19D0 802CD020 0C0B210B */  jal   get_float_variable
/* 0F19D4 802CD024 0040882D */   daddu $s1, $v0, $zero
/* 0F19D8 802CD028 8E050000 */  lw    $a1, ($s0)
/* 0F19DC 802CD02C 26100004 */  addiu $s0, $s0, 4
/* 0F19E0 802CD030 0240202D */  daddu $a0, $s2, $zero
/* 0F19E4 802CD034 0C0B210B */  jal   get_float_variable
/* 0F19E8 802CD038 46000586 */   mov.s $f22, $f0
/* 0F19EC 802CD03C 0240202D */  daddu $a0, $s2, $zero
/* 0F19F0 802CD040 8E050000 */  lw    $a1, ($s0)
/* 0F19F4 802CD044 0C0B210B */  jal   get_float_variable
/* 0F19F8 802CD048 46000506 */   mov.s $f20, $f0
/* 0F19FC 802CD04C 3C02802E */  lui   $v0, 0x802e
/* 0F1A00 802CD050 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F1A04 802CD054 00118880 */  sll   $s1, $s1, 2
/* 0F1A08 802CD058 02228821 */  addu  $s1, $s1, $v0
/* 0F1A0C 802CD05C 8E230000 */  lw    $v1, ($s1)
/* 0F1A10 802CD060 E4760004 */  swc1  $f22, 4($v1)
/* 0F1A14 802CD064 E4740008 */  swc1  $f20, 8($v1)
/* 0F1A18 802CD068 E460000C */  swc1  $f0, 0xc($v1)
/* 0F1A1C 802CD06C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1A20 802CD070 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1A24 802CD074 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F1A28 802CD078 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1A2C 802CD07C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F1A30 802CD080 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F1A34 802CD084 24020002 */  addiu $v0, $zero, 2
/* 0F1A38 802CD088 03E00008 */  jr    $ra
/* 0F1A3C 802CD08C 27BD0030 */   addiu $sp, $sp, 0x30

