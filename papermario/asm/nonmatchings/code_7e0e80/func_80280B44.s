.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80280B44
/* 7E19C4 80280B44 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 7E19C8 80280B48 AFBF0010 */  sw    $ra, 0x10($sp)
/* 7E19CC 80280B4C 0C03C54E */  jal   func_800F1538
/* 7E19D0 80280B50 00000000 */   nop   
/* 7E19D4 80280B54 0C03A640 */  jal   func_800E9900
/* 7E19D8 80280B58 00000000 */   nop   
/* 7E19DC 80280B5C 0C03A631 */  jal   status_menu_disable_ignore_changes
/* 7E19E0 80280B60 00000000 */   nop   
/* 7E19E4 80280B64 0C03A5EE */  jal   func_800E97B8
/* 7E19E8 80280B68 00000000 */   nop   
