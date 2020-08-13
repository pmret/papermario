.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024A29C
.L8024A29C:
/* 13D5DC 8024A29C 8FAA00B0 */  lw    $t2, 0xb0($sp)
/* 13D5E0 8024A2A0 2402005B */  addiu $v0, $zero, 0x5b
/* 13D5E4 8024A2A4 AFA20014 */  sw    $v0, 0x14($sp)
/* 13D5E8 8024A2A8 24020022 */  addiu $v0, $zero, 0x22
/* 13D5EC 8024A2AC AFA20018 */  sw    $v0, 0x18($sp)
/* 13D5F0 8024A2B0 240200FF */  addiu $v0, $zero, 0xff
/* 13D5F4 8024A2B4 AFA00010 */  sw    $zero, 0x10($sp)
/* 13D5F8 8024A2B8 AFA2001C */  sw    $v0, 0x1c($sp)
/* 13D5FC 8024A2BC 14600004 */  bnez  $v1, .L8024A2D0
/* 13D600 8024A2C0 25470027 */   addiu $a3, $t2, 0x27
/* 13D604 8024A2C4 24020080 */  addiu $v0, $zero, 0x80
/* 13D608 8024A2C8 080928B5 */  j     func_8024A2D4
/* 13D60C 8024A2CC AFA20020 */   sw    $v0, 0x20($sp)

.L8024A2D0:
/* 13D610 8024A2D0 AFA00020 */  sw    $zero, 0x20($sp)
