.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024DA68
/* 140DA8 8024DA68 080936B8 */  j     func_8024DAE0
/* 140DAC 8024DA6C 00072880 */   sll   $a1, $a3, 2

.L8024DA70:
/* 140DB0 8024DA70 00072880 */  sll   $a1, $a3, 2
/* 140DB4 8024DA74 24660010 */  addiu $a2, $v1, 0x10
/* 140DB8 8024DA78 00063080 */  sll   $a2, $a2, 2
/* 140DBC 8024DA7C 24E70010 */  addiu $a3, $a3, 0x10
/* 140DC0 8024DA80 00073880 */  sll   $a3, $a3, 2
/* 140DC4 8024DA84 24020400 */  addiu $v0, $zero, 0x400
/* 140DC8 8024DA88 AFA00010 */  sw    $zero, 0x10($sp)
/* 140DCC 8024DA8C AFA00014 */  sw    $zero, 0x14($sp)
/* 140DD0 8024DA90 080936C1 */  j     func_8024DB04
/* 140DD4 8024DA94 AFA00018 */   sw    $zero, 0x18($sp)

.L8024DA98:
/* 140DD8 8024DA98 00032080 */  sll   $a0, $v1, 2
/* 140DDC 8024DA9C 00072880 */  sll   $a1, $a3, 2
/* 140DE0 8024DAA0 24660010 */  addiu $a2, $v1, 0x10
/* 140DE4 8024DAA4 00063080 */  sll   $a2, $a2, 2
/* 140DE8 8024DAA8 24E70010 */  addiu $a3, $a3, 0x10
/* 140DEC 8024DAAC 00073880 */  sll   $a3, $a3, 2
/* 140DF0 8024DAB0 080936BD */  j     func_8024DAF4
/* 140DF4 8024DAB4 24020200 */   addiu $v0, $zero, 0x200

.L8024DAB8:
/* 140DF8 8024DAB8 00072880 */  sll   $a1, $a3, 2
/* 140DFC 8024DABC 24660010 */  addiu $a2, $v1, 0x10
/* 140E00 8024DAC0 00063080 */  sll   $a2, $a2, 2
/* 140E04 8024DAC4 24E70010 */  addiu $a3, $a3, 0x10
/* 140E08 8024DAC8 00073880 */  sll   $a3, $a3, 2
/* 140E0C 8024DACC 24020400 */  addiu $v0, $zero, 0x400
/* 140E10 8024DAD0 AFA00010 */  sw    $zero, 0x10($sp)
/* 140E14 8024DAD4 AFA00014 */  sw    $zero, 0x14($sp)
/* 140E18 8024DAD8 080936C1 */  j     func_8024DB04
/* 140E1C 8024DADC AFA20018 */   sw    $v0, 0x18($sp)

