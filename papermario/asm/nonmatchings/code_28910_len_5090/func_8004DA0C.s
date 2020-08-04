.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004DA0C
/* 028E0C 8004DA0C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 028E10 8004DA10 AFB10014 */  sw    $s1, 0x14($sp)
/* 028E14 8004DA14 0080882D */  daddu $s1, $a0, $zero
/* 028E18 8004DA18 AFB00010 */  sw    $s0, 0x10($sp)
/* 028E1C 8004DA1C 0000802D */  daddu $s0, $zero, $zero
/* 028E20 8004DA20 1220000D */  beqz  $s1, .L8004DA58
/* 028E24 8004DA24 AFBF0018 */   sw    $ra, 0x18($sp)
/* 028E28 8004DA28 0C0135E5 */  jal   func_8004D794
/* 028E2C 8004DA2C 00000000 */   nop   
/* 028E30 8004DA30 0040202D */  daddu $a0, $v0, $zero
/* 028E34 8004DA34 50800009 */  beql  $a0, $zero, .L8004DA5C
/* 028E38 8004DA38 24100002 */   addiu $s0, $zero, 2
/* 028E3C 8004DA3C 8C82001C */  lw    $v0, 0x1c($a0)
/* 028E40 8004DA40 16220007 */  bne   $s1, $v0, .L8004DA60
/* 028E44 8004DA44 0200102D */   daddu $v0, $s0, $zero
/* 028E48 8004DA48 0C0136AA */  jal   func_8004DAA8
/* 028E4C 8004DA4C 00000000 */   nop   
/* 028E50 8004DA50 08013698 */  j     .L8004DA60
/* 028E54 8004DA54 0200102D */   daddu $v0, $s0, $zero

.L8004DA58:
/* 028E58 8004DA58 24100003 */  addiu $s0, $zero, 3
.L8004DA5C:
/* 028E5C 8004DA5C 0200102D */  daddu $v0, $s0, $zero
.L8004DA60:
/* 028E60 8004DA60 8FBF0018 */  lw    $ra, 0x18($sp)
/* 028E64 8004DA64 8FB10014 */  lw    $s1, 0x14($sp)
/* 028E68 8004DA68 8FB00010 */  lw    $s0, 0x10($sp)
/* 028E6C 8004DA6C 03E00008 */  jr    $ra
/* 028E70 8004DA70 27BD0020 */   addiu $sp, $sp, 0x20

