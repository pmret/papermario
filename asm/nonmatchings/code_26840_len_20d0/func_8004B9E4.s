.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004B9E4
/* 026DE4 8004B9E4 30A500FF */  andi  $a1, $a1, 0xff
/* 026DE8 8004B9E8 240200F0 */  addiu $v0, $zero, 0xf0
/* 026DEC 8004B9EC 10A20017 */  beq   $a1, $v0, .L8004BA4C
/* 026DF0 8004B9F0 28A20008 */   slti  $v0, $a1, 8
/* 026DF4 8004B9F4 10400013 */  beqz  $v0, .L8004BA44
/* 026DF8 8004B9F8 240200FF */   addiu $v0, $zero, 0xff
/* 026DFC 8004B9FC 9082008C */  lbu   $v0, 0x8c($a0)
/* 026E00 8004BA00 1045000C */  beq   $v0, $a1, .L8004BA34
/* 026E04 8004BA04 24020006 */   addiu $v0, $zero, 6
/* 026E08 8004BA08 8C830000 */  lw    $v1, ($a0)
/* 026E0C 8004BA0C A085008C */  sb    $a1, 0x8c($a0)
/* 026E10 8004BA10 A0620044 */  sb    $v0, 0x44($v1)
/* 026E14 8004BA14 8C830000 */  lw    $v1, ($a0)
/* 026E18 8004BA18 24020001 */  addiu $v0, $zero, 1
/* 026E1C 8004BA1C A0620045 */  sb    $v0, 0x45($v1)
/* 026E20 8004BA20 00051080 */  sll   $v0, $a1, 2
/* 026E24 8004BA24 00821021 */  addu  $v0, $a0, $v0
/* 026E28 8004BA28 8C420064 */  lw    $v0, 0x64($v0)
/* 026E2C 8004BA2C 3C018008 */  lui   $at, 0x8008
/* 026E30 8004BA30 AC22F1F8 */  sw    $v0, -0xe08($at)
.L8004BA34:
/* 026E34 8004BA34 00851021 */  addu  $v0, $a0, $a1
/* 026E38 8004BA38 90420084 */  lbu   $v0, 0x84($v0)
/* 026E3C 8004BA3C 08012E93 */  j     .L8004BA4C
/* 026E40 8004BA40 A082008D */   sb    $v0, 0x8d($a0)

.L8004BA44:
/* 026E44 8004BA44 A082008C */  sb    $v0, 0x8c($a0)
/* 026E48 8004BA48 A080008D */  sb    $zero, 0x8d($a0)
.L8004BA4C:
/* 026E4C 8004BA4C 03E00008 */  jr    $ra
/* 026E50 8004BA50 9082008C */   lbu   $v0, 0x8c($a0)

