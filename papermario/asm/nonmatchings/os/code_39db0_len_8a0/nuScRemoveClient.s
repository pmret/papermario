.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuScRemoveClient
/* 03A2BC 8005EEBC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03A2C0 8005EEC0 AFB00010 */  sw    $s0, 0x10($sp)
/* 03A2C4 8005EEC4 0080802D */  daddu $s0, $a0, $zero
/* 03A2C8 8005EEC8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03A2CC 8005EECC 0C018250 */  jal   osSetIntMask
/* 03A2D0 8005EED0 24040001 */   addiu $a0, $zero, 1
/* 03A2D4 8005EED4 3C06800E */  lui   $a2, 0x800e
/* 03A2D8 8005EED8 24C6AAA8 */  addiu $a2, $a2, -0x5558
/* 03A2DC 8005EEDC 0000282D */  daddu $a1, $zero, $zero
/* 03A2E0 8005EEE0 8CC30000 */  lw    $v1, ($a2)
/* 03A2E4 8005EEE4 1060000E */  beqz  $v1, .L8005EF20
/* 03A2E8 8005EEE8 0040202D */   daddu $a0, $v0, $zero
.L8005EEEC:
/* 03A2EC 8005EEEC 54700009 */  bnel  $v1, $s0, .L8005EF14
/* 03A2F0 8005EEF0 0060282D */   daddu $a1, $v1, $zero
/* 03A2F4 8005EEF4 10A00004 */  beqz  $a1, .L8005EF08
/* 03A2F8 8005EEF8 00000000 */   nop   
/* 03A2FC 8005EEFC 8C620000 */  lw    $v0, ($v1)
/* 03A300 8005EF00 08017BC8 */  j     .L8005EF20
/* 03A304 8005EF04 ACA20000 */   sw    $v0, ($a1)

.L8005EF08:
/* 03A308 8005EF08 8C620000 */  lw    $v0, ($v1)
/* 03A30C 8005EF0C 08017BC8 */  j     .L8005EF20
/* 03A310 8005EF10 ACC20000 */   sw    $v0, ($a2)

.L8005EF14:
/* 03A314 8005EF14 8C630000 */  lw    $v1, ($v1)
/* 03A318 8005EF18 1460FFF4 */  bnez  $v1, .L8005EEEC
/* 03A31C 8005EF1C 00000000 */   nop   
.L8005EF20:
/* 03A320 8005EF20 0C018250 */  jal   osSetIntMask
/* 03A324 8005EF24 00000000 */   nop   
/* 03A328 8005EF28 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03A32C 8005EF2C 8FB00010 */  lw    $s0, 0x10($sp)
/* 03A330 8005EF30 03E00008 */  jr    $ra
/* 03A334 8005EF34 27BD0018 */   addiu $sp, $sp, 0x18

