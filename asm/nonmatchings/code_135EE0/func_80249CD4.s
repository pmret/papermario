.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249CD4
/* 13D014 80249CD4 0000A02D */   daddu $s4, $zero, $zero
/* 13D018 80249CD8 03C0202D */  daddu $a0, $fp, $zero
/* 13D01C 80249CDC 0C092638 */  jal   func_802498E0
/* 13D020 80249CE0 0240282D */   daddu $a1, $s2, $zero
/* 13D024 80249CE4 8FAA005C */  lw    $t2, 0x5c($sp)
/* 13D028 80249CE8 004A1026 */  xor   $v0, $v0, $t2
/* 13D02C 80249CEC 2C530001 */  sltiu $s3, $v0, 1
/* 13D030 80249CF0 0000A02D */  daddu $s4, $zero, $zero
.L80249CF4:
/* 13D034 80249CF4 12600003 */  beqz  $s3, .L80249D04
/* 13D038 80249CF8 0280A82D */   daddu $s5, $s4, $zero
/* 13D03C 80249CFC 2414FFFF */  addiu $s4, $zero, -1
/* 13D040 80249D00 0280A82D */  daddu $s5, $s4, $zero
.L80249D04:
/* 13D044 80249D04 8FAB0050 */  lw    $t3, 0x50($sp)
/* 13D048 80249D08 15600007 */  bnez  $t3, .L80249D28
/* 13D04C 80249D0C 240A0001 */   addiu $t2, $zero, 1
/* 13D050 80249D10 240B000A */  addiu $t3, $zero, 0xa
/* 13D054 80249D14 AFAA0060 */  sw    $t2, 0x60($sp)
/* 13D058 80249D18 12600003 */  beqz  $s3, .L80249D28
/* 13D05C 80249D1C AFAB0064 */   sw    $t3, 0x64($sp)
/* 13D060 80249D20 240A0009 */  addiu $t2, $zero, 9
/* 13D064 80249D24 AFAA0060 */  sw    $t2, 0x60($sp)
.L80249D28:
/* 13D068 80249D28 0C09264C */  jal   func_80249930
/* 13D06C 80249D2C 02E0202D */   daddu $a0, $s7, $zero
/* 13D070 80249D30 1040008B */  beqz  $v0, .L80249F60
/* 13D074 80249D34 00000000 */   nop   
/* 13D078 80249D38 8FAB0050 */  lw    $t3, 0x50($sp)
/* 13D07C 80249D3C 15600035 */  bnez  $t3, .L80249E14
/* 13D080 80249D40 00000000 */   nop   
/* 13D084 80249D44 8FAA0074 */  lw    $t2, 0x74($sp)
/* 13D088 80249D48 11400016 */  beqz  $t2, .L80249DA4
/* 13D08C 80249D4C 00161400 */   sll   $v0, $s6, 0x10
/* 13D090 80249D50 0C093BA0 */  jal   func_8024EE80
/* 13D094 80249D54 2404004E */   addiu $a0, $zero, 0x4e
/* 13D098 80249D58 8FA40068 */  lw    $a0, 0x68($sp)
/* 13D09C 80249D5C 0C09265A */  jal   func_80249968
/* 13D0A0 80249D60 0040882D */   daddu $s1, $v0, $zero
/* 13D0A4 80249D64 8FAB006C */  lw    $t3, 0x6c($sp)
/* 13D0A8 80249D68 02E0202D */  daddu $a0, $s7, $zero
/* 13D0AC 80249D6C 01628021 */  addu  $s0, $t3, $v0
/* 13D0B0 80249D70 0C092656 */  jal   func_80249958
/* 13D0B4 80249D74 02148021 */   addu  $s0, $s0, $s4
/* 13D0B8 80249D78 0220202D */  daddu $a0, $s1, $zero
/* 13D0BC 80249D7C 0200282D */  daddu $a1, $s0, $zero
/* 13D0C0 80249D80 240700FF */  addiu $a3, $zero, 0xff
/* 13D0C4 80249D84 8FAA0070 */  lw    $t2, 0x70($sp)
/* 13D0C8 80249D88 8FAB0064 */  lw    $t3, 0x64($sp)
/* 13D0CC 80249D8C 01421021 */  addu  $v0, $t2, $v0
/* 13D0D0 80249D90 8FAA0060 */  lw    $t2, 0x60($sp)
/* 13D0D4 80249D94 00553021 */  addu  $a2, $v0, $s5
/* 13D0D8 80249D98 AFAB0010 */  sw    $t3, 0x10($sp)
/* 13D0DC 80249D9C 08092783 */  j     func_80249E0C
/* 13D0E0 80249DA0 AFAA0014 */   sw    $t2, 0x14($sp)

.L80249DA4:
/* 13D0E4 80249DA4 000212C3 */  sra   $v0, $v0, 0xb
/* 13D0E8 80249DA8 3C0B8008 */  lui   $t3, 0x8008
/* 13D0EC 80249DAC 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13D0F0 80249DB0 004B8821 */  addu  $s1, $v0, $t3
/* 13D0F4 80249DB4 8E220000 */  lw    $v0, ($s1)
/* 13D0F8 80249DB8 10400016 */  beqz  $v0, .L80249E14
/* 13D0FC 80249DBC 00000000 */   nop   
/* 13D100 80249DC0 18400014 */  blez  $v0, .L80249E14
/* 13D104 80249DC4 00000000 */   nop   
/* 13D108 80249DC8 0C09265A */  jal   func_80249968
/* 13D10C 80249DCC 8FA40068 */   lw    $a0, 0x68($sp)
/* 13D110 80249DD0 8FAA006C */  lw    $t2, 0x6c($sp)
/* 13D114 80249DD4 02E0202D */  daddu $a0, $s7, $zero
/* 13D118 80249DD8 01428021 */  addu  $s0, $t2, $v0
/* 13D11C 80249DDC 0C092656 */  jal   func_80249958
/* 13D120 80249DE0 02148021 */   addu  $s0, $s0, $s4
/* 13D124 80249DE4 0200282D */  daddu $a1, $s0, $zero
/* 13D128 80249DE8 8FAB0070 */  lw    $t3, 0x70($sp)
/* 13D12C 80249DEC 8FAA0064 */  lw    $t2, 0x64($sp)
/* 13D130 80249DF0 01621021 */  addu  $v0, $t3, $v0
/* 13D134 80249DF4 8FAB0060 */  lw    $t3, 0x60($sp)
/* 13D138 80249DF8 240700FF */  addiu $a3, $zero, 0xff
/* 13D13C 80249DFC AFAA0010 */  sw    $t2, 0x10($sp)
/* 13D140 80249E00 AFAB0014 */  sw    $t3, 0x14($sp)
/* 13D144 80249E04 8E240000 */  lw    $a0, ($s1)
/* 13D148 80249E08 00553021 */  addu  $a2, $v0, $s5
