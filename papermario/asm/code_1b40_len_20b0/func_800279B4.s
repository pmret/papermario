.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800279B4
/* 002DB4 800279B4 27BDFF98 */  addiu $sp, $sp, -0x68
/* 002DB8 800279B8 AFB50054 */  sw    $s5, 0x54($sp)
/* 002DBC 800279BC 0080A82D */  daddu $s5, $a0, $zero
/* 002DC0 800279C0 AFB60058 */  sw    $s6, 0x58($sp)
/* 002DC4 800279C4 00A0B02D */  daddu $s6, $a1, $zero
/* 002DC8 800279C8 AFB3004C */  sw    $s3, 0x4c($sp)
/* 002DCC 800279CC 24130001 */  addiu $s3, $zero, 1
/* 002DD0 800279D0 27A80018 */  addiu $t0, $sp, 0x18
/* 002DD4 800279D4 AFA80038 */  sw    $t0, 0x38($sp)
/* 002DD8 800279D8 24080140 */  addiu $t0, $zero, 0x140
/* 002DDC 800279DC AFBF0064 */  sw    $ra, 0x64($sp)
/* 002DE0 800279E0 AFBE0060 */  sw    $fp, 0x60($sp)
/* 002DE4 800279E4 AFB7005C */  sw    $s7, 0x5c($sp)
/* 002DE8 800279E8 AFB40050 */  sw    $s4, 0x50($sp)
/* 002DEC 800279EC AFB20048 */  sw    $s2, 0x48($sp)
/* 002DF0 800279F0 AFB10044 */  sw    $s1, 0x44($sp)
/* 002DF4 800279F4 AFB00040 */  sw    $s0, 0x40($sp)
/* 002DF8 800279F8 AFA60070 */  sw    $a2, 0x70($sp)
/* 002DFC 800279FC AFA8003C */  sw    $t0, 0x3c($sp)
.L80027A00:
/* 002E00 80027A00 24120002 */  addiu $s2, $zero, 2
/* 002E04 80027A04 267EFFFF */  addiu $fp, $s3, -1
/* 002E08 80027A08 26770001 */  addiu $s7, $s3, 1
.L80027A0C:
/* 002E0C 80027A0C 8FA8003C */  lw    $t0, 0x3c($sp)
/* 002E10 80027A10 01121021 */  addu  $v0, $t0, $s2
/* 002E14 80027A14 0002A040 */  sll   $s4, $v0, 1
/* 002E18 80027A18 02961021 */  addu  $v0, $s4, $s6
/* 002E1C 80027A1C 94420000 */  lhu   $v0, ($v0)
/* 002E20 80027A20 00021082 */  srl   $v0, $v0, 2
/* 002E24 80027A24 3042000F */  andi  $v0, $v0, 0xf
/* 002E28 80027A28 2C420008 */  sltiu $v0, $v0, 8
/* 002E2C 80027A2C 10400043 */  beqz  $v0, .L80027B3C
/* 002E30 80027A30 02A0202D */   daddu $a0, $s5, $zero
/* 002E34 80027A34 02C0282D */  daddu $a1, $s6, $zero
/* 002E38 80027A38 03C0302D */  daddu $a2, $fp, $zero
/* 002E3C 80027A3C 2650FFFF */  addiu $s0, $s2, -1
/* 002E40 80027A40 8FA80038 */  lw    $t0, 0x38($sp)
/* 002E44 80027A44 0200382D */  daddu $a3, $s0, $zero
/* 002E48 80027A48 0C009C7F */  jal   func_800271FC
/* 002E4C 80027A4C AFA80010 */   sw    $t0, 0x10($sp)
/* 002E50 80027A50 02A0202D */  daddu $a0, $s5, $zero
/* 002E54 80027A54 02C0282D */  daddu $a1, $s6, $zero
/* 002E58 80027A58 03C0302D */  daddu $a2, $fp, $zero
/* 002E5C 80027A5C 26510001 */  addiu $s1, $s2, 1
/* 002E60 80027A60 0220382D */  daddu $a3, $s1, $zero
/* 002E64 80027A64 27A2001C */  addiu $v0, $sp, 0x1c
/* 002E68 80027A68 0C009C7F */  jal   func_800271FC
/* 002E6C 80027A6C AFA20010 */   sw    $v0, 0x10($sp)
/* 002E70 80027A70 02A0202D */  daddu $a0, $s5, $zero
/* 002E74 80027A74 02C0282D */  daddu $a1, $s6, $zero
/* 002E78 80027A78 0260302D */  daddu $a2, $s3, $zero
/* 002E7C 80027A7C 2647FFFE */  addiu $a3, $s2, -2
/* 002E80 80027A80 27A20020 */  addiu $v0, $sp, 0x20
/* 002E84 80027A84 0C009C7F */  jal   func_800271FC
/* 002E88 80027A88 AFA20010 */   sw    $v0, 0x10($sp)
/* 002E8C 80027A8C 02A0202D */  daddu $a0, $s5, $zero
/* 002E90 80027A90 02C0282D */  daddu $a1, $s6, $zero
/* 002E94 80027A94 0260302D */  daddu $a2, $s3, $zero
/* 002E98 80027A98 26470002 */  addiu $a3, $s2, 2
/* 002E9C 80027A9C 27A20024 */  addiu $v0, $sp, 0x24
/* 002EA0 80027AA0 0C009C7F */  jal   func_800271FC
/* 002EA4 80027AA4 AFA20010 */   sw    $v0, 0x10($sp)
/* 002EA8 80027AA8 02A0202D */  daddu $a0, $s5, $zero
/* 002EAC 80027AAC 02C0282D */  daddu $a1, $s6, $zero
/* 002EB0 80027AB0 02E0302D */  daddu $a2, $s7, $zero
/* 002EB4 80027AB4 0200382D */  daddu $a3, $s0, $zero
/* 002EB8 80027AB8 27A20028 */  addiu $v0, $sp, 0x28
/* 002EBC 80027ABC 0C009C7F */  jal   func_800271FC
/* 002EC0 80027AC0 AFA20010 */   sw    $v0, 0x10($sp)
/* 002EC4 80027AC4 02A0202D */  daddu $a0, $s5, $zero
/* 002EC8 80027AC8 02C0282D */  daddu $a1, $s6, $zero
/* 002ECC 80027ACC 02E0302D */  daddu $a2, $s7, $zero
/* 002ED0 80027AD0 0220382D */  daddu $a3, $s1, $zero
/* 002ED4 80027AD4 27A2002C */  addiu $v0, $sp, 0x2c
/* 002ED8 80027AD8 0C009C7F */  jal   func_800271FC
/* 002EDC 80027ADC AFA20010 */   sw    $v0, 0x10($sp)
/* 002EE0 80027AE0 02A0202D */  daddu $a0, $s5, $zero
/* 002EE4 80027AE4 02C0282D */  daddu $a1, $s6, $zero
/* 002EE8 80027AE8 0260302D */  daddu $a2, $s3, $zero
/* 002EEC 80027AEC 0240382D */  daddu $a3, $s2, $zero
/* 002EF0 80027AF0 27A20030 */  addiu $v0, $sp, 0x30
/* 002EF4 80027AF4 0C009C7F */  jal   func_800271FC
/* 002EF8 80027AF8 AFA20010 */   sw    $v0, 0x10($sp)
/* 002EFC 80027AFC 8FA40038 */  lw    $a0, 0x38($sp)
/* 002F00 80027B00 8FA80070 */  lw    $t0, 0x70($sp)
/* 002F04 80027B04 93A50030 */  lbu   $a1, 0x30($sp)
/* 002F08 80027B08 93A20031 */  lbu   $v0, 0x31($sp)
/* 002F0C 80027B0C 93A30032 */  lbu   $v1, 0x32($sp)
/* 002F10 80027B10 01143021 */  addu  $a2, $t0, $s4
/* 002F14 80027B14 00052E00 */  sll   $a1, $a1, 0x18
/* 002F18 80027B18 00021400 */  sll   $v0, $v0, 0x10
/* 002F1C 80027B1C 00A22825 */  or    $a1, $a1, $v0
/* 002F20 80027B20 00031A00 */  sll   $v1, $v1, 8
/* 002F24 80027B24 93A20033 */  lbu   $v0, 0x33($sp)
/* 002F28 80027B28 00A32825 */  or    $a1, $a1, $v1
/* 002F2C 80027B2C 0C009C97 */  jal   func_8002725C
/* 002F30 80027B30 00A22825 */   or    $a1, $a1, $v0
/* 002F34 80027B34 08009ED6 */  j     .L80027B58
/* 002F38 80027B38 26520001 */   addiu $s2, $s2, 1

.L80027B3C:
/* 002F3C 80027B3C 02951021 */  addu  $v0, $s4, $s5
/* 002F40 80027B40 8FA80070 */  lw    $t0, 0x70($sp)
/* 002F44 80027B44 94420000 */  lhu   $v0, ($v0)
/* 002F48 80027B48 02881821 */  addu  $v1, $s4, $t0
/* 002F4C 80027B4C 34420001 */  ori   $v0, $v0, 1
/* 002F50 80027B50 A4620000 */  sh    $v0, ($v1)
/* 002F54 80027B54 26520001 */  addiu $s2, $s2, 1
.L80027B58:
/* 002F58 80027B58 2A42013E */  slti  $v0, $s2, 0x13e
/* 002F5C 80027B5C 1440FFAB */  bnez  $v0, .L80027A0C
/* 002F60 80027B60 00000000 */   nop   
/* 002F64 80027B64 26730001 */  addiu $s3, $s3, 1
/* 002F68 80027B68 8FA8003C */  lw    $t0, 0x3c($sp)
/* 002F6C 80027B6C 2A6200EF */  slti  $v0, $s3, 0xef
/* 002F70 80027B70 25080140 */  addiu $t0, $t0, 0x140
/* 002F74 80027B74 1440FFA2 */  bnez  $v0, .L80027A00
/* 002F78 80027B78 AFA8003C */   sw    $t0, 0x3c($sp)
/* 002F7C 80027B7C 8FBF0064 */  lw    $ra, 0x64($sp)
/* 002F80 80027B80 8FBE0060 */  lw    $fp, 0x60($sp)
/* 002F84 80027B84 8FB7005C */  lw    $s7, 0x5c($sp)
/* 002F88 80027B88 8FB60058 */  lw    $s6, 0x58($sp)
/* 002F8C 80027B8C 8FB50054 */  lw    $s5, 0x54($sp)
/* 002F90 80027B90 8FB40050 */  lw    $s4, 0x50($sp)
/* 002F94 80027B94 8FB3004C */  lw    $s3, 0x4c($sp)
/* 002F98 80027B98 8FB20048 */  lw    $s2, 0x48($sp)
/* 002F9C 80027B9C 8FB10044 */  lw    $s1, 0x44($sp)
/* 002FA0 80027BA0 8FB00040 */  lw    $s0, 0x40($sp)
/* 002FA4 80027BA4 03E00008 */  jr    $ra
/* 002FA8 80027BA8 27BD0068 */   addiu $sp, $sp, 0x68

.set reorder
