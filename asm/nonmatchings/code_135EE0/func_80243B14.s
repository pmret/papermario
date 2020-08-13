.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80243B14
/* 136E54 80243B14 3C063F4C */  lui   $a2, 0x3f4c
/* 136E58 80243B18 34C6CCCD */  ori   $a2, $a2, 0xcccd
/* 136E5C 80243B1C 3C073F80 */  lui   $a3, 0x3f80
/* 136E60 80243B20 0C019DF0 */  jal   guScaleF
/* 136E64 80243B24 02A0202D */   daddu $a0, $s5, $zero
/* 136E68 80243B28 02A0202D */  daddu $a0, $s5, $zero
/* 136E6C 80243B2C 27A50028 */  addiu $a1, $sp, 0x28
/* 136E70 80243B30 0C019D80 */  jal   guMtxCatF
/* 136E74 80243B34 00A0302D */   daddu $a2, $a1, $zero
/* 136E78 80243B38 4405C000 */  mfc1  $a1, $f24
/* 136E7C 80243B3C 4406A000 */  mfc1  $a2, $f20
/* 136E80 80243B40 4407A000 */  mfc1  $a3, $f20
/* 136E84 80243B44 02A0202D */  daddu $a0, $s5, $zero
/* 136E88 80243B48 0C019EC8 */  jal   guRotateF
/* 136E8C 80243B4C E7B60010 */   swc1  $f22, 0x10($sp)
/* 136E90 80243B50 02A0202D */  daddu $a0, $s5, $zero
/* 136E94 80243B54 27A50028 */  addiu $a1, $sp, 0x28
/* 136E98 80243B58 0C019D80 */  jal   guMtxCatF
/* 136E9C 80243B5C 00A0302D */   daddu $a2, $a1, $zero
/* 136EA0 80243B60 4405C000 */  mfc1  $a1, $f24
/* 136EA4 80243B64 4406A000 */  mfc1  $a2, $f20
/* 136EA8 80243B68 4407B000 */  mfc1  $a3, $f22
/* 136EAC 80243B6C 02A0202D */  daddu $a0, $s5, $zero
/* 136EB0 80243B70 0C019EC8 */  jal   guRotateF
/* 136EB4 80243B74 E7B40010 */   swc1  $f20, 0x10($sp)
/* 136EB8 80243B78 02A0202D */  daddu $a0, $s5, $zero
/* 136EBC 80243B7C 27A50028 */  addiu $a1, $sp, 0x28
/* 136EC0 80243B80 0C019D80 */  jal   guMtxCatF
/* 136EC4 80243B84 00A0302D */   daddu $a2, $a1, $zero
/* 136EC8 80243B88 27A40028 */  addiu $a0, $sp, 0x28
/* 136ECC 80243B8C 97C50000 */  lhu   $a1, ($fp)
/* 136ED0 80243B90 3C02800A */  lui   $v0, 0x800a
/* 136ED4 80243B94 8C42A674 */  lw    $v0, -0x598c($v0)
/* 136ED8 80243B98 8FAE00D0 */  lw    $t6, 0xd0($sp)
/* 136EDC 80243B9C 00052980 */  sll   $a1, $a1, 6
/* 136EE0 80243BA0 00AE2821 */  addu  $a1, $a1, $t6
