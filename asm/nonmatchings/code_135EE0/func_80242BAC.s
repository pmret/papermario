.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80242BAC
/* 135EEC 80242BAC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 135EF0 80242BB0 AFB10014 */  sw    $s1, 0x14($sp)
/* 135EF4 80242BB4 00A0882D */  daddu $s1, $a1, $zero
/* 135EF8 80242BB8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 135EFC 80242BBC 00C0982D */  daddu $s3, $a2, $zero
/* 135F00 80242BC0 AFB40020 */  sw    $s4, 0x20($sp)
/* 135F04 80242BC4 3C148016 */  lui   $s4, 0x8016
/* 135F08 80242BC8 26949D50 */  addiu $s4, $s4, -0x62b0
/* 135F0C 80242BCC 00042140 */  sll   $a0, $a0, 5
/* 135F10 80242BD0 AFB20018 */  sw    $s2, 0x18($sp)
/* 135F14 80242BD4 3C128025 */  lui   $s2, 0x8025
/* 135F18 80242BD8 2652EFB4 */  addiu $s2, $s2, -0x104c
/* 135F1C 80242BDC AFBF0024 */  sw    $ra, 0x24($sp)
/* 135F20 80242BE0 AFB00010 */  sw    $s0, 0x10($sp)
/* 135F24 80242BE4 8E420000 */  lw    $v0, ($s2)
/* 135F28 80242BE8 14400012 */  bnez  $v0, .L80242C34
/* 135F2C 80242BEC 00948021 */   addu  $s0, $a0, $s4
/* 135F30 80242BF0 0C00CD4A */  jal   get_game_mode
/* 135F34 80242BF4 00000000 */   nop   
/* 135F38 80242BF8 00021400 */  sll   $v0, $v0, 0x10
/* 135F3C 80242BFC 00021403 */  sra   $v0, $v0, 0x10
/* 135F40 80242C00 2403000F */  addiu $v1, $zero, 0xf
/* 135F44 80242C04 10430008 */  beq   $v0, $v1, .L80242C28
/* 135F48 80242C08 00000000 */   nop   
/* 135F4C 80242C0C 0C00CD4A */  jal   get_game_mode
/* 135F50 80242C10 00000000 */   nop   
/* 135F54 80242C14 00021400 */  sll   $v0, $v0, 0x10
/* 135F58 80242C18 00021403 */  sra   $v0, $v0, 0x10
/* 135F5C 80242C1C 2403000D */  addiu $v1, $zero, 0xd
/* 135F60 80242C20 1443001C */  bne   $v0, $v1, .L80242C94
/* 135F64 80242C24 00000000 */   nop   
.L80242C28:
/* 135F68 80242C28 8E420000 */  lw    $v0, ($s2)
