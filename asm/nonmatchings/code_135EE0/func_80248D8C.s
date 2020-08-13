.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80248D8C
/* 13C0CC 80248D8C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 13C0D0 80248D90 AFB00010 */  sw    $s0, 0x10($sp)
/* 13C0D4 80248D94 AFB10014 */  sw    $s1, 0x14($sp)
/* 13C0D8 80248D98 3C118011 */  lui   $s1, 0x8011
/* 13C0DC 80248D9C 2631F290 */  addiu $s1, $s1, -0xd70
/* 13C0E0 80248DA0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 13C0E4 80248DA4 3C018027 */  lui   $at, 0x8027
/* 13C0E8 80248DA8 AC200388 */  sw    $zero, 0x388($at)
/* 13C0EC 80248DAC 14800014 */  bnez  $a0, .L80248E00
/* 13C0F0 80248DB0 0000802D */   daddu $s0, $zero, $zero
/* 13C0F4 80248DB4 0200202D */  daddu $a0, $s0, $zero
/* 13C0F8 80248DB8 0220302D */  daddu $a2, $s1, $zero
/* 13C0FC 80248DBC 3C058027 */  lui   $a1, 0x8027
/* 13C100 80248DC0 24A50180 */  addiu $a1, $a1, 0x180
.L80248DC4:
/* 13C104 80248DC4 84C200B4 */  lh    $v0, 0xb4($a2)
/* 13C108 80248DC8 94C300B4 */  lhu   $v1, 0xb4($a2)
/* 13C10C 80248DCC 10400007 */  beqz  $v0, .L80248DEC
/* 13C110 80248DD0 24840001 */   addiu $a0, $a0, 1
/* 13C114 80248DD4 28420155 */  slti  $v0, $v0, 0x155
/* 13C118 80248DD8 10400019 */  beqz  $v0, .L80248E40
/* 13C11C 80248DDC 00000000 */   nop   
/* 13C120 80248DE0 A4A30000 */  sh    $v1, ($a1)
/* 13C124 80248DE4 24A50002 */  addiu $a1, $a1, 2
/* 13C128 80248DE8 26100001 */  addiu $s0, $s0, 1
.L80248DEC:
/* 13C12C 80248DEC 28820080 */  slti  $v0, $a0, 0x80
/* 13C130 80248DF0 1440FFF4 */  bnez  $v0, .L80248DC4
/* 13C134 80248DF4 24C60002 */   addiu $a2, $a2, 2
/* 13C138 80248DF8 08092390 */  j     func_80248E40
/* 13C13C 80248DFC 00000000 */   nop   

.L80248E00:
/* 13C140 80248E00 0C091C2C */  jal   func_802470B0
/* 13C144 80248E04 00000000 */   nop   
/* 13C148 80248E08 26260208 */  addiu $a2, $s1, 0x208
/* 13C14C 80248E0C 0000202D */  daddu $a0, $zero, $zero
/* 13C150 80248E10 3C058027 */  lui   $a1, 0x8027
/* 13C154 80248E14 24A50180 */  addiu $a1, $a1, 0x180
.L80248E18:
/* 13C158 80248E18 84C20000 */  lh    $v0, ($a2)
/* 13C15C 80248E1C 94C30000 */  lhu   $v1, ($a2)
/* 13C160 80248E20 10400004 */  beqz  $v0, .L80248E34
/* 13C164 80248E24 24840001 */   addiu $a0, $a0, 1
/* 13C168 80248E28 A4A30000 */  sh    $v1, ($a1)
/* 13C16C 80248E2C 24A50002 */  addiu $a1, $a1, 2
/* 13C170 80248E30 26100001 */  addiu $s0, $s0, 1
.L80248E34:
/* 13C174 80248E34 28820040 */  slti  $v0, $a0, 0x40
/* 13C178 80248E38 1440FFF7 */  bnez  $v0, .L80248E18
/* 13C17C 80248E3C 24C60002 */   addiu $a2, $a2, 2
