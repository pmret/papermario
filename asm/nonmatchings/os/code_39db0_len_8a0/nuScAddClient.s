.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuScAddClient
/* 03A230 8005EE30 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03A234 8005EE34 AFB00010 */  sw    $s0, 0x10($sp)
/* 03A238 8005EE38 0080802D */  daddu $s0, $a0, $zero
/* 03A23C 8005EE3C AFB20018 */  sw    $s2, 0x18($sp)
/* 03A240 8005EE40 00A0902D */  daddu $s2, $a1, $zero
/* 03A244 8005EE44 AFB10014 */  sw    $s1, 0x14($sp)
/* 03A248 8005EE48 00C0882D */  daddu $s1, $a2, $zero
/* 03A24C 8005EE4C AFBF001C */  sw    $ra, 0x1c($sp)
/* 03A250 8005EE50 0C018250 */  jal   osSetIntMask
/* 03A254 8005EE54 24040001 */   addiu $a0, $zero, 1
/* 03A258 8005EE58 3C05800E */  lui   $a1, 0x800e
/* 03A25C 8005EE5C 24A5AAA8 */  addiu $a1, $a1, -0x5558
/* 03A260 8005EE60 AE120004 */  sw    $s2, 4($s0)
/* 03A264 8005EE64 8CA30000 */  lw    $v1, ($a1)
/* 03A268 8005EE68 A6110008 */  sh    $s1, 8($s0)
/* 03A26C 8005EE6C 32310002 */  andi  $s1, $s1, 2
/* 03A270 8005EE70 AE030000 */  sw    $v1, ($s0)
/* 03A274 8005EE74 ACB00000 */  sw    $s0, ($a1)
/* 03A278 8005EE78 12200008 */  beqz  $s1, .L8005EE9C
/* 03A27C 8005EE7C 0040802D */   daddu $s0, $v0, $zero
/* 03A280 8005EE80 3C02800A */  lui   $v0, 0x800a
/* 03A284 8005EE84 9042A5B0 */  lbu   $v0, -0x5a50($v0)
/* 03A288 8005EE88 10400004 */  beqz  $v0, .L8005EE9C
/* 03A28C 8005EE8C 0240202D */   daddu $a0, $s2, $zero
/* 03A290 8005EE90 24A5F99A */  addiu $a1, $a1, -0x666
/* 03A294 8005EE94 0C019608 */  jal   osSendMesg
/* 03A298 8005EE98 0000302D */   daddu $a2, $zero, $zero
.L8005EE9C:
/* 03A29C 8005EE9C 0C018250 */  jal   osSetIntMask
/* 03A2A0 8005EEA0 0200202D */   daddu $a0, $s0, $zero
/* 03A2A4 8005EEA4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03A2A8 8005EEA8 8FB20018 */  lw    $s2, 0x18($sp)
/* 03A2AC 8005EEAC 8FB10014 */  lw    $s1, 0x14($sp)
/* 03A2B0 8005EEB0 8FB00010 */  lw    $s0, 0x10($sp)
/* 03A2B4 8005EEB4 03E00008 */  jr    $ra
/* 03A2B8 8005EEB8 27BD0020 */   addiu $sp, $sp, 0x20

