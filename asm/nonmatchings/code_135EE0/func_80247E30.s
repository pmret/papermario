.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247E30
/* 13B170 80247E30 2442F348 */  addiu $v0, $v0, -0xcb8
/* 13B174 80247E34 AC620004 */  sw    $v0, 4($v1)
/* 13B178 80247E38 24A20008 */  addiu $v0, $a1, 8
/* 13B17C 80247E3C 3C01800A */  lui   $at, 0x800a
/* 13B180 80247E40 AC25A66C */  sw    $a1, -0x5994($at)
/* 13B184 80247E44 3C01800A */  lui   $at, 0x800a
/* 13B188 80247E48 AC22A66C */  sw    $v0, -0x5994($at)
/* 13B18C 80247E4C 24022000 */  addiu $v0, $zero, 0x2000
/* 13B190 80247E50 ACA40000 */  sw    $a0, ($a1)
/* 13B194 80247E54 ACA20004 */  sw    $v0, 4($a1)
/* 13B198 80247E58 8FAB0084 */  lw    $t3, 0x84($sp)
/* 13B19C 80247E5C 15600081 */  bnez  $t3, .L80248064
/* 13B1A0 80247E60 3C0300FF */   lui   $v1, 0xff
/* 13B1A4 80247E64 1A600032 */  blez  $s3, .L80247F30
/* 13B1A8 80247E68 0000802D */   daddu $s0, $zero, $zero
/* 13B1AC 80247E6C 2A740005 */  slti  $s4, $s3, 5
.L80247E70:
/* 13B1B0 80247E70 3C02800A */  lui   $v0, 0x800a
/* 13B1B4 80247E74 8C42A66C */  lw    $v0, -0x5994($v0)
/* 13B1B8 80247E78 02E0202D */  daddu $a0, $s7, $zero
/* 13B1BC 80247E7C 0040182D */  daddu $v1, $v0, $zero
/* 13B1C0 80247E80 3C0AFA00 */  lui   $t2, 0xfa00
/* 13B1C4 80247E84 AC6A0000 */  sw    $t2, ($v1)
/* 13B1C8 80247E88 8FAB0090 */  lw    $t3, 0x90($sp)
/* 13B1CC 80247E8C 24420008 */  addiu $v0, $v0, 8
/* 13B1D0 80247E90 3C01800A */  lui   $at, 0x800a
/* 13B1D4 80247E94 AC22A66C */  sw    $v0, -0x5994($at)
/* 13B1D8 80247E98 0C091CAA */  jal   func_802472A8
/* 13B1DC 80247E9C AC6B0004 */   sw    $t3, 4($v1)
/* 13B1E0 80247EA0 8FAA0094 */  lw    $t2, 0x94($sp)
/* 13B1E4 80247EA4 02C0202D */  daddu $a0, $s6, $zero
/* 13B1E8 80247EA8 020A0018 */  mult  $s0, $t2
/* 13B1EC 80247EAC 244200EB */  addiu $v0, $v0, 0xeb
/* 13B1F0 80247EB0 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13B1F4 80247EB4 00101FC3 */  sra   $v1, $s0, 0x1f
/* 13B1F8 80247EB8 01621021 */  addu  $v0, $t3, $v0
/* 13B1FC 80247EBC 00005010 */  mfhi  $t2
/* 13B200 80247EC0 000A2843 */  sra   $a1, $t2, 1
/* 13B204 80247EC4 00A38823 */  subu  $s1, $a1, $v1
/* 13B208 80247EC8 00112880 */  sll   $a1, $s1, 2
/* 13B20C 80247ECC 00B12821 */  addu  $a1, $a1, $s1
/* 13B210 80247ED0 02052823 */  subu  $a1, $s0, $a1
/* 13B214 80247ED4 00051840 */  sll   $v1, $a1, 1
/* 13B218 80247ED8 00651821 */  addu  $v1, $v1, $a1
/* 13B21C 80247EDC 00031840 */  sll   $v1, $v1, 1
/* 13B220 80247EE0 24630001 */  addiu $v1, $v1, 1
/* 13B224 80247EE4 0C091CA6 */  jal   func_80247298
/* 13B228 80247EE8 00439021 */   addu  $s2, $v0, $v1
/* 13B22C 80247EEC 8FAB00C8 */  lw    $t3, 0xc8($sp)
/* 13B230 80247EF0 24420011 */  addiu $v0, $v0, 0x11
/* 13B234 80247EF4 01621021 */  addu  $v0, $t3, $v0
/* 13B238 80247EF8 16800006 */  bnez  $s4, .L80247F14
/* 13B23C 80247EFC 00553021 */   addu  $a2, $v0, $s5
/* 13B240 80247F00 24C3FFFD */  addiu $v1, $a2, -3
/* 13B244 80247F04 00111040 */  sll   $v0, $s1, 1
/* 13B248 80247F08 00511021 */  addu  $v0, $v0, $s1
/* 13B24C 80247F0C 00021040 */  sll   $v0, $v0, 1
/* 13B250 80247F10 00623021 */  addu  $a2, $v1, $v0
.L80247F14:
/* 13B254 80247F14 0000202D */  daddu $a0, $zero, $zero
/* 13B258 80247F18 0C091D16 */  jal   func_80247458
/* 13B25C 80247F1C 0240282D */   daddu $a1, $s2, $zero
/* 13B260 80247F20 26100001 */  addiu $s0, $s0, 1
/* 13B264 80247F24 0213102A */  slt   $v0, $s0, $s3
/* 13B268 80247F28 1440FFD1 */  bnez  $v0, .L80247E70
/* 13B26C 80247F2C 00000000 */   nop   
.L80247F30:
/* 13B270 80247F30 3C06E200 */  lui   $a2, 0xe200
/* 13B274 80247F34 34C6001C */  ori   $a2, $a2, 0x1c
/* 13B278 80247F38 3C050050 */  lui   $a1, 0x50
/* 13B27C 80247F3C 34A54340 */  ori   $a1, $a1, 0x4340
/* 13B280 80247F40 0000802D */  daddu $s0, $zero, $zero
/* 13B284 80247F44 3C02E700 */  lui   $v0, 0xe700
/* 13B288 80247F48 3C04800A */  lui   $a0, 0x800a
/* 13B28C 80247F4C 8C84A66C */  lw    $a0, -0x5994($a0)
/* 13B290 80247F50 240B00FF */  addiu $t3, $zero, 0xff
/* 13B294 80247F54 0080182D */  daddu $v1, $a0, $zero
/* 13B298 80247F58 24840008 */  addiu $a0, $a0, 8
/* 13B29C 80247F5C AC620000 */  sw    $v0, ($v1)
/* 13B2A0 80247F60 24820008 */  addiu $v0, $a0, 8
/* 13B2A4 80247F64 3C01800A */  lui   $at, 0x800a
/* 13B2A8 80247F68 AC24A66C */  sw    $a0, -0x5994($at)
/* 13B2AC 80247F6C 3C01800A */  lui   $at, 0x800a
/* 13B2B0 80247F70 AC22A66C */  sw    $v0, -0x5994($at)
/* 13B2B4 80247F74 24820010 */  addiu $v0, $a0, 0x10
/* 13B2B8 80247F78 AC600004 */  sw    $zero, 4($v1)
/* 13B2BC 80247F7C 3C0AFA00 */  lui   $t2, 0xfa00
