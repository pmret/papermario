.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8012E9A0
/* 0C50A0 8012E9A0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0C50A4 8012E9A4 AFB10034 */  sw    $s1, 0x34($sp)
/* 0C50A8 8012E9A8 0080882D */  daddu $s1, $a0, $zero
/* 0C50AC 8012E9AC AFB20038 */  sw    $s2, 0x38($sp)
/* 0C50B0 8012E9B0 00A0902D */  daddu $s2, $a1, $zero
/* 0C50B4 8012E9B4 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0C50B8 8012E9B8 00C0982D */  daddu $s3, $a2, $zero
/* 0C50BC 8012E9BC AFB00030 */  sw    $s0, 0x30($sp)
/* 0C50C0 8012E9C0 00E0802D */  daddu $s0, $a3, $zero
/* 0C50C4 8012E9C4 3C05E300 */  lui   $a1, 0xe300
/* 0C50C8 8012E9C8 34A50A01 */  ori   $a1, $a1, 0xa01
/* 0C50CC 8012E9CC 3C06E300 */  lui   $a2, 0xe300
/* 0C50D0 8012E9D0 34C61201 */  ori   $a2, $a2, 0x1201
/* 0C50D4 8012E9D4 3C07E300 */  lui   $a3, 0xe300
/* 0C50D8 8012E9D8 3C09800A */  lui   $t1, 0x800a
/* 0C50DC 8012E9DC 2529A66C */  addiu $t1, $t1, -0x5994
/* 0C50E0 8012E9E0 34E70C00 */  ori   $a3, $a3, 0xc00
/* 0C50E4 8012E9E4 3C02E700 */  lui   $v0, 0xe700
/* 0C50E8 8012E9E8 AFBF0040 */  sw    $ra, 0x40($sp)
/* 0C50EC 8012E9EC 8D280000 */  lw    $t0, ($t1)
/* 0C50F0 8012E9F0 8FB90058 */  lw    $t9, 0x58($sp)
/* 0C50F4 8012E9F4 8FAA005C */  lw    $t2, 0x5c($sp)
/* 0C50F8 8012E9F8 97AB0062 */  lhu   $t3, 0x62($sp)
/* 0C50FC 8012E9FC 97AC0066 */  lhu   $t4, 0x66($sp)
/* 0C5100 8012EA00 97AD006A */  lhu   $t5, 0x6a($sp)
/* 0C5104 8012EA04 97AE006E */  lhu   $t6, 0x6e($sp)
/* 0C5108 8012EA08 97AF0072 */  lhu   $t7, 0x72($sp)
/* 0C510C 8012EA0C 97B80076 */  lhu   $t8, 0x76($sp)
/* 0C5110 8012EA10 93A4007B */  lbu   $a0, 0x7b($sp)
/* 0C5114 8012EA14 0100182D */  daddu $v1, $t0, $zero
/* 0C5118 8012EA18 25080008 */  addiu $t0, $t0, 8
/* 0C511C 8012EA1C AD280000 */  sw    $t0, ($t1)
/* 0C5120 8012EA20 AC620000 */  sw    $v0, ($v1)
/* 0C5124 8012EA24 25020008 */  addiu $v0, $t0, 8
/* 0C5128 8012EA28 AC600004 */  sw    $zero, 4($v1)
/* 0C512C 8012EA2C AD220000 */  sw    $v0, ($t1)
/* 0C5130 8012EA30 25020010 */  addiu $v0, $t0, 0x10
/* 0C5134 8012EA34 AD050000 */  sw    $a1, ($t0)
/* 0C5138 8012EA38 AD000004 */  sw    $zero, 4($t0)
/* 0C513C 8012EA3C AD220000 */  sw    $v0, ($t1)
/* 0C5140 8012EA40 25020018 */  addiu $v0, $t0, 0x18
/* 0C5144 8012EA44 AD060008 */  sw    $a2, 8($t0)
/* 0C5148 8012EA48 AD00000C */  sw    $zero, 0xc($t0)
/* 0C514C 8012EA4C AD220000 */  sw    $v0, ($t1)
/* 0C5150 8012EA50 AD070010 */  sw    $a3, 0x10($t0)
/* 0C5154 8012EA54 308700FF */  andi  $a3, $a0, 0xff
/* 0C5158 8012EA58 240200FF */  addiu $v0, $zero, 0xff
/* 0C515C 8012EA5C 14E20012 */  bne   $a3, $v0, .L8012EAA8
/* 0C5160 8012EA60 AD000014 */   sw    $zero, 0x14($t0)
/* 0C5164 8012EA64 3C05E200 */  lui   $a1, 0xe200
/* 0C5168 8012EA68 34A5001C */  ori   $a1, $a1, 0x1c
/* 0C516C 8012EA6C 3C030F0A */  lui   $v1, 0xf0a
/* 0C5170 8012EA70 34637008 */  ori   $v1, $v1, 0x7008
/* 0C5174 8012EA74 3C06FCFF */  lui   $a2, 0xfcff
/* 0C5178 8012EA78 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 0C517C 8012EA7C 3C04FFFC */  lui   $a0, 0xfffc
/* 0C5180 8012EA80 3484F279 */  ori   $a0, $a0, 0xf279
/* 0C5184 8012EA84 25020020 */  addiu $v0, $t0, 0x20
/* 0C5188 8012EA88 AD220000 */  sw    $v0, ($t1)
/* 0C518C 8012EA8C 25020028 */  addiu $v0, $t0, 0x28
/* 0C5190 8012EA90 AD050018 */  sw    $a1, 0x18($t0)
/* 0C5194 8012EA94 AD03001C */  sw    $v1, 0x1c($t0)
/* 0C5198 8012EA98 AD220000 */  sw    $v0, ($t1)
/* 0C519C 8012EA9C AD060020 */  sw    $a2, 0x20($t0)
/* 0C51A0 8012EAA0 0804BAC2 */  j     .L8012EB08
/* 0C51A4 8012EAA4 AD040024 */   sw    $a0, 0x24($t0)

.L8012EAA8:
/* 0C51A8 8012EAA8 14E00003 */  bnez  $a3, .L8012EAB8
/* 0C51AC 8012EAAC 3C05E200 */   lui   $a1, 0xe200
/* 0C51B0 8012EAB0 0804BB1E */  j     .L8012EC78
/* 0C51B4 8012EAB4 24020001 */   addiu $v0, $zero, 1

.L8012EAB8:
/* 0C51B8 8012EAB8 34A5001C */  ori   $a1, $a1, 0x1c
/* 0C51BC 8012EABC 3C030050 */  lui   $v1, 0x50
/* 0C51C0 8012EAC0 34634240 */  ori   $v1, $v1, 0x4240
/* 0C51C4 8012EAC4 3C06FCFF */  lui   $a2, 0xfcff
/* 0C51C8 8012EAC8 34C697FF */  ori   $a2, $a2, 0x97ff
/* 0C51CC 8012EACC 3C04FF2C */  lui   $a0, 0xff2c
/* 0C51D0 8012EAD0 3484FE7F */  ori   $a0, $a0, 0xfe7f
/* 0C51D4 8012EAD4 25020020 */  addiu $v0, $t0, 0x20
/* 0C51D8 8012EAD8 AD220000 */  sw    $v0, ($t1)
/* 0C51DC 8012EADC 25020028 */  addiu $v0, $t0, 0x28
/* 0C51E0 8012EAE0 AD050018 */  sw    $a1, 0x18($t0)
/* 0C51E4 8012EAE4 AD03001C */  sw    $v1, 0x1c($t0)
/* 0C51E8 8012EAE8 AD220000 */  sw    $v0, ($t1)
/* 0C51EC 8012EAEC 25020030 */  addiu $v0, $t0, 0x30
/* 0C51F0 8012EAF0 AD060020 */  sw    $a2, 0x20($t0)
/* 0C51F4 8012EAF4 AD040024 */  sw    $a0, 0x24($t0)
/* 0C51F8 8012EAF8 AD220000 */  sw    $v0, ($t1)
/* 0C51FC 8012EAFC 3C02FA00 */  lui   $v0, 0xfa00
/* 0C5200 8012EB00 AD020028 */  sw    $v0, 0x28($t0)
/* 0C5204 8012EB04 AD07002C */  sw    $a3, 0x2c($t0)
.L8012EB08:
/* 0C5208 8012EB08 24020002 */  addiu $v0, $zero, 2
/* 0C520C 8012EB0C 16020034 */  bne   $s0, $v0, .L8012EBE0
/* 0C5210 8012EB10 3C05E300 */   lui   $a1, 0xe300
/* 0C5214 8012EB14 3C02E300 */  lui   $v0, 0xe300
/* 0C5218 8012EB18 3C06800A */  lui   $a2, 0x800a
/* 0C521C 8012EB1C 24C6A66C */  addiu $a2, $a2, -0x5994
/* 0C5220 8012EB20 8CC50000 */  lw    $a1, ($a2)
/* 0C5224 8012EB24 34421001 */  ori   $v0, $v0, 0x1001
/* 0C5228 8012EB28 00A0182D */  daddu $v1, $a1, $zero
/* 0C522C 8012EB2C 24A50008 */  addiu $a1, $a1, 8
/* 0C5230 8012EB30 ACC50000 */  sw    $a1, ($a2)
/* 0C5234 8012EB34 AC620000 */  sw    $v0, ($v1)
/* 0C5238 8012EB38 34028000 */  ori   $v0, $zero, 0x8000
/* 0C523C 8012EB3C 17200005 */  bnez  $t9, .L8012EB54
/* 0C5240 8012EB40 AC620004 */   sw    $v0, 4($v1)
/* 0C5244 8012EB44 3C03F500 */  lui   $v1, 0xf500
/* 0C5248 8012EB48 34630100 */  ori   $v1, $v1, 0x100
/* 0C524C 8012EB4C 0804BAD8 */  j     .L8012EB60
/* 0C5250 8012EB50 3C040703 */   lui   $a0, 0x703

.L8012EB54:
/* 0C5254 8012EB54 3C03F500 */  lui   $v1, 0xf500
/* 0C5258 8012EB58 34630100 */  ori   $v1, $v1, 0x100
/* 0C525C 8012EB5C 3C04073F */  lui   $a0, 0x73f
.L8012EB60:
/* 0C5260 8012EB60 3484C000 */  ori   $a0, $a0, 0xc000
/* 0C5264 8012EB64 24A20008 */  addiu $v0, $a1, 8
/* 0C5268 8012EB68 ACC20000 */  sw    $v0, ($a2)
/* 0C526C 8012EB6C 3C02FD10 */  lui   $v0, 0xfd10
/* 0C5270 8012EB70 ACA20000 */  sw    $v0, ($a1)
/* 0C5274 8012EB74 24A20010 */  addiu $v0, $a1, 0x10
/* 0C5278 8012EB78 ACAA0004 */  sw    $t2, 4($a1)
/* 0C527C 8012EB7C ACC20000 */  sw    $v0, ($a2)
/* 0C5280 8012EB80 3C02E800 */  lui   $v0, 0xe800
/* 0C5284 8012EB84 ACA20008 */  sw    $v0, 8($a1)
/* 0C5288 8012EB88 24A20018 */  addiu $v0, $a1, 0x18
/* 0C528C 8012EB8C ACA0000C */  sw    $zero, 0xc($a1)
/* 0C5290 8012EB90 ACC20000 */  sw    $v0, ($a2)
/* 0C5294 8012EB94 3C020700 */  lui   $v0, 0x700
/* 0C5298 8012EB98 ACA20014 */  sw    $v0, 0x14($a1)
/* 0C529C 8012EB9C 24A20020 */  addiu $v0, $a1, 0x20
/* 0C52A0 8012EBA0 ACA30010 */  sw    $v1, 0x10($a1)
/* 0C52A4 8012EBA4 ACC20000 */  sw    $v0, ($a2)
/* 0C52A8 8012EBA8 3C02E600 */  lui   $v0, 0xe600
/* 0C52AC 8012EBAC ACA20018 */  sw    $v0, 0x18($a1)
/* 0C52B0 8012EBB0 24A20028 */  addiu $v0, $a1, 0x28
/* 0C52B4 8012EBB4 ACA0001C */  sw    $zero, 0x1c($a1)
/* 0C52B8 8012EBB8 ACC20000 */  sw    $v0, ($a2)
/* 0C52BC 8012EBBC 3C02F000 */  lui   $v0, 0xf000
/* 0C52C0 8012EBC0 ACA20020 */  sw    $v0, 0x20($a1)
/* 0C52C4 8012EBC4 24A20030 */  addiu $v0, $a1, 0x30
/* 0C52C8 8012EBC8 ACA40024 */  sw    $a0, 0x24($a1)
/* 0C52CC 8012EBCC ACC20000 */  sw    $v0, ($a2)
/* 0C52D0 8012EBD0 3C02E700 */  lui   $v0, 0xe700
/* 0C52D4 8012EBD4 ACA20028 */  sw    $v0, 0x28($a1)
/* 0C52D8 8012EBD8 0804BB01 */  j     .L8012EC04
/* 0C52DC 8012EBDC ACA0002C */   sw    $zero, 0x2c($a1)

.L8012EBE0:
/* 0C52E0 8012EBE0 3C04800A */  lui   $a0, 0x800a
/* 0C52E4 8012EBE4 2484A66C */  addiu $a0, $a0, -0x5994
/* 0C52E8 8012EBE8 8C820000 */  lw    $v0, ($a0)
/* 0C52EC 8012EBEC 34A51001 */  ori   $a1, $a1, 0x1001
/* 0C52F0 8012EBF0 0040182D */  daddu $v1, $v0, $zero
/* 0C52F4 8012EBF4 24420008 */  addiu $v0, $v0, 8
/* 0C52F8 8012EBF8 AC820000 */  sw    $v0, ($a0)
/* 0C52FC 8012EBFC AC650000 */  sw    $a1, ($v1)
/* 0C5300 8012EC00 AC600004 */  sw    $zero, 4($v1)
.L8012EC04:
/* 0C5304 8012EC04 000B1400 */  sll   $v0, $t3, 0x10
/* 0C5308 8012EC08 00021403 */  sra   $v0, $v0, 0x10
/* 0C530C 8012EC0C AFA20014 */  sw    $v0, 0x14($sp)
/* 0C5310 8012EC10 000C1400 */  sll   $v0, $t4, 0x10
/* 0C5314 8012EC14 00021403 */  sra   $v0, $v0, 0x10
/* 0C5318 8012EC18 AFA20018 */  sw    $v0, 0x18($sp)
/* 0C531C 8012EC1C 31A2FFFF */  andi  $v0, $t5, 0xffff
/* 0C5320 8012EC20 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0C5324 8012EC24 31C2FFFF */  andi  $v0, $t6, 0xffff
/* 0C5328 8012EC28 AFA20020 */  sw    $v0, 0x20($sp)
/* 0C532C 8012EC2C 31E2FFFF */  andi  $v0, $t7, 0xffff
/* 0C5330 8012EC30 AFA20024 */  sw    $v0, 0x24($sp)
/* 0C5334 8012EC34 3302FFFF */  andi  $v0, $t8, 0xffff
/* 0C5338 8012EC38 0220202D */  daddu $a0, $s1, $zero
/* 0C533C 8012EC3C 0240282D */  daddu $a1, $s2, $zero
/* 0C5340 8012EC40 0260302D */  daddu $a2, $s3, $zero
/* 0C5344 8012EC44 0200382D */  daddu $a3, $s0, $zero
/* 0C5348 8012EC48 AFB90010 */  sw    $t9, 0x10($sp)
/* 0C534C 8012EC4C 0C04BB25 */  jal   func_8012EC94
/* 0C5350 8012EC50 AFA20028 */   sw    $v0, 0x28($sp)
/* 0C5354 8012EC54 3C04800A */  lui   $a0, 0x800a
/* 0C5358 8012EC58 2484A66C */  addiu $a0, $a0, -0x5994
/* 0C535C 8012EC5C 8C830000 */  lw    $v1, ($a0)
/* 0C5360 8012EC60 0060282D */  daddu $a1, $v1, $zero
/* 0C5364 8012EC64 24630008 */  addiu $v1, $v1, 8
/* 0C5368 8012EC68 AC830000 */  sw    $v1, ($a0)
/* 0C536C 8012EC6C 3C03E700 */  lui   $v1, 0xe700
/* 0C5370 8012EC70 ACA30000 */  sw    $v1, ($a1)
/* 0C5374 8012EC74 ACA00004 */  sw    $zero, 4($a1)
.L8012EC78:
/* 0C5378 8012EC78 8FBF0040 */  lw    $ra, 0x40($sp)
/* 0C537C 8012EC7C 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0C5380 8012EC80 8FB20038 */  lw    $s2, 0x38($sp)
/* 0C5384 8012EC84 8FB10034 */  lw    $s1, 0x34($sp)
/* 0C5388 8012EC88 8FB00030 */  lw    $s0, 0x30($sp)
/* 0C538C 8012EC8C 03E00008 */  jr    $ra
/* 0C5390 8012EC90 27BD0048 */   addiu $sp, $sp, 0x48

