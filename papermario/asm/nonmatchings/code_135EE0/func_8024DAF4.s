.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024DAF4
/* 140E34 8024DAF4 AFA20018 */  sw    $v0, 0x18($sp)
/* 140E38 8024DAF8 24020400 */  addiu $v0, $zero, 0x400
/* 140E3C 8024DAFC AFA00010 */  sw    $zero, 0x10($sp)
/* 140E40 8024DB00 AFA00014 */  sw    $zero, 0x14($sp)
