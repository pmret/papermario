.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248CD0
/* 13C010 80248CD0 240200AD */  addiu $v0, $zero, 0xad
/* 13C014 80248CD4 AFA20014 */  sw    $v0, 0x14($sp)
/* 13C018 80248CD8 2402001A */  addiu $v0, $zero, 0x1a
/* 13C01C 80248CDC AFA20018 */  sw    $v0, 0x18($sp)
/* 13C020 80248CE0 240200FF */  addiu $v0, $zero, 0xff
/* 13C024 80248CE4 AFA2001C */  sw    $v0, 0x1c($sp)
/* 13C028 80248CE8 24020140 */  addiu $v0, $zero, 0x140
/* 13C02C 80248CEC AFA20044 */  sw    $v0, 0x44($sp)
/* 13C030 80248CF0 240200F0 */  addiu $v0, $zero, 0xf0
/* 13C034 80248CF4 AFA00010 */  sw    $zero, 0x10($sp)
/* 13C038 80248CF8 AFA00020 */  sw    $zero, 0x20($sp)
/* 13C03C 80248CFC AFA00024 */  sw    $zero, 0x24($sp)
/* 13C040 80248D00 AFA00028 */  sw    $zero, 0x28($sp)
/* 13C044 80248D04 AFA0002C */  sw    $zero, 0x2c($sp)
/* 13C048 80248D08 AFA00030 */  sw    $zero, 0x30($sp)
/* 13C04C 80248D0C AFA00034 */  sw    $zero, 0x34($sp)
/* 13C050 80248D10 AFA00038 */  sw    $zero, 0x38($sp)
/* 13C054 80248D14 AFA0003C */  sw    $zero, 0x3c($sp)
/* 13C058 80248D18 AFA00040 */  sw    $zero, 0x40($sp)
/* 13C05C 80248D1C AFA20048 */  sw    $v0, 0x48($sp)
/* 13C060 80248D20 AFA0004C */  sw    $zero, 0x4c($sp)
/* 13C064 80248D24 25660043 */  addiu $a2, $t3, 0x43
/* 13C068 80248D28 0C03D4B8 */  jal   draw_box
/* 13C06C 80248D2C 2547003C */   addiu $a3, $t2, 0x3c
/* 13C070 80248D30 0C093BA0 */  jal   func_8024EE80
/* 13C074 80248D34 2404004B */   addiu $a0, $zero, 0x4b
/* 13C078 80248D38 0040202D */  daddu $a0, $v0, $zero
/* 13C07C 80248D3C 8FAB00C4 */  lw    $t3, 0xc4($sp)
