.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80053CF8
/* 02F0F8 80053CF8 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 02F0FC 80053CFC AFB20028 */  sw    $s2, 0x28($sp)
/* 02F100 80053D00 3C12800A */  lui   $s2, 0x800a
/* 02F104 80053D04 8E52A5C0 */  lw    $s2, -0x5a40($s2)
/* 02F108 80053D08 AFB60038 */  sw    $s6, 0x38($sp)
/* 02F10C 80053D0C 0080B02D */  daddu $s6, $a0, $zero
/* 02F110 80053D10 AFB3002C */  sw    $s3, 0x2c($sp)
/* 02F114 80053D14 00C0982D */  daddu $s3, $a2, $zero
/* 02F118 80053D18 AFBF0044 */  sw    $ra, 0x44($sp)
/* 02F11C 80053D1C AFBE0040 */  sw    $fp, 0x40($sp)
/* 02F120 80053D20 AFB7003C */  sw    $s7, 0x3c($sp)
/* 02F124 80053D24 AFB50034 */  sw    $s5, 0x34($sp)
/* 02F128 80053D28 AFB40030 */  sw    $s4, 0x30($sp)
/* 02F12C 80053D2C AFB10024 */  sw    $s1, 0x24($sp)
/* 02F130 80053D30 AFB00020 */  sw    $s0, 0x20($sp)
/* 02F134 80053D34 AFA5004C */  sw    $a1, 0x4c($sp)
/* 02F138 80053D38 8E420030 */  lw    $v0, 0x30($s2)
/* 02F13C 80053D3C 02C2102B */  sltu  $v0, $s6, $v0
/* 02F140 80053D40 10400038 */  beqz  $v0, .L80053E24
/* 02F144 80053D44 00A0B82D */   daddu $s7, $a1, $zero
/* 02F148 80053D48 24050010 */  addiu $a1, $zero, 0x10
/* 02F14C 80053D4C 8E43002C */  lw    $v1, 0x2c($s2)
/* 02F150 80053D50 001610C0 */  sll   $v0, $s6, 3
/* 02F154 80053D54 0062A021 */  addu  $s4, $v1, $v0
/* 02F158 80053D58 96840000 */  lhu   $a0, ($s4)
/* 02F15C 80053D5C 0C01511F */  jal   al_CopyFileTableEntry
/* 02F160 80053D60 03A53021 */   addu  $a2, $sp, $a1
/* 02F164 80053D64 14400030 */  bnez  $v0, .L80053E28
/* 02F168 80053D68 00000000 */   nop   
/* 02F16C 80053D6C 0C0136CA */  jal   func_8004DB28
/* 02F170 80053D70 0260202D */   daddu $a0, $s3, $zero
/* 02F174 80053D74 1440002C */  bnez  $v0, .L80053E28
/* 02F178 80053D78 240200C9 */   addiu $v0, $zero, 0xc9
/* 02F17C 80053D7C 3C0200FF */  lui   $v0, 0xff
/* 02F180 80053D80 3442FFFF */  ori   $v0, $v0, 0xffff
/* 02F184 80053D84 02E0282D */  daddu $a1, $s7, $zero
/* 02F188 80053D88 0000802D */  daddu $s0, $zero, $zero
/* 02F18C 80053D8C 3C1500FF */  lui   $s5, 0xff
/* 02F190 80053D90 36B5FFFF */  ori   $s5, $s5, 0xffff
/* 02F194 80053D94 241E0030 */  addiu $fp, $zero, 0x30
/* 02F198 80053D98 0280882D */  daddu $s1, $s4, $zero
/* 02F19C 80053D9C 8FA60014 */  lw    $a2, 0x14($sp)
/* 02F1A0 80053DA0 8FA40010 */  lw    $a0, 0x10($sp)
/* 02F1A4 80053DA4 0C015380 */  jal   al_DmaCopy
/* 02F1A8 80053DA8 00C23024 */   and   $a2, $a2, $v0
.L80053DAC:
/* 02F1AC 80053DAC 96220002 */  lhu   $v0, 2($s1)
/* 02F1B0 80053DB0 50400012 */  beql  $v0, $zero, .L80053DFC
/* 02F1B4 80053DB4 26100001 */   addiu $s0, $s0, 1
/* 02F1B8 80053DB8 8E440020 */  lw    $a0, 0x20($s2)
/* 02F1BC 80053DBC 000210C0 */  sll   $v0, $v0, 3
/* 02F1C0 80053DC0 00822021 */  addu  $a0, $a0, $v0
/* 02F1C4 80053DC4 8C820000 */  lw    $v0, ($a0)
/* 02F1C8 80053DC8 8E43001C */  lw    $v1, 0x1c($s2)
/* 02F1CC 80053DCC 00551024 */  and   $v0, $v0, $s5
/* 02F1D0 80053DD0 00431821 */  addu  $v1, $v0, $v1
/* 02F1D4 80053DD4 AFA30018 */  sw    $v1, 0x18($sp)
/* 02F1D8 80053DD8 8C820004 */  lw    $v0, 4($a0)
/* 02F1DC 80053DDC AFA2001C */  sw    $v0, 0x1c($sp)
/* 02F1E0 80053DE0 00021602 */  srl   $v0, $v0, 0x18
/* 02F1E4 80053DE4 545E0005 */  bnel  $v0, $fp, .L80053DFC
/* 02F1E8 80053DE8 26100001 */   addiu $s0, $s0, 1
/* 02F1EC 80053DEC 0060202D */  daddu $a0, $v1, $zero
/* 02F1F0 80053DF0 0C015313 */  jal   func_80054C4C
/* 02F1F4 80053DF4 0200282D */   daddu $a1, $s0, $zero
/* 02F1F8 80053DF8 26100001 */  addiu $s0, $s0, 1
.L80053DFC:
/* 02F1FC 80053DFC 2A020003 */  slti  $v0, $s0, 3
/* 02F200 80053E00 1440FFEA */  bnez  $v0, .L80053DAC
/* 02F204 80053E04 26310002 */   addiu $s1, $s1, 2
/* 02F208 80053E08 96820000 */  lhu   $v0, ($s4)
/* 02F20C 80053E0C AE760028 */  sw    $s6, 0x28($s3)
/* 02F210 80053E10 8FA7004C */  lw    $a3, 0x4c($sp)
/* 02F214 80053E14 AE670064 */  sw    $a3, 0x64($s3)
/* 02F218 80053E18 AE620024 */  sw    $v0, 0x24($s3)
/* 02F21C 80053E1C 08014F8A */  j     .L80053E28
/* 02F220 80053E20 8EE20008 */   lw    $v0, 8($s7)

.L80053E24:
/* 02F224 80053E24 24020097 */  addiu $v0, $zero, 0x97
.L80053E28:
/* 02F228 80053E28 8FBF0044 */  lw    $ra, 0x44($sp)
/* 02F22C 80053E2C 8FBE0040 */  lw    $fp, 0x40($sp)
/* 02F230 80053E30 8FB7003C */  lw    $s7, 0x3c($sp)
/* 02F234 80053E34 8FB60038 */  lw    $s6, 0x38($sp)
/* 02F238 80053E38 8FB50034 */  lw    $s5, 0x34($sp)
/* 02F23C 80053E3C 8FB40030 */  lw    $s4, 0x30($sp)
/* 02F240 80053E40 8FB3002C */  lw    $s3, 0x2c($sp)
/* 02F244 80053E44 8FB20028 */  lw    $s2, 0x28($sp)
/* 02F248 80053E48 8FB10024 */  lw    $s1, 0x24($sp)
/* 02F24C 80053E4C 8FB00020 */  lw    $s0, 0x20($sp)
/* 02F250 80053E50 03E00008 */  jr    $ra
/* 02F254 80053E54 27BD0048 */   addiu $sp, $sp, 0x48

