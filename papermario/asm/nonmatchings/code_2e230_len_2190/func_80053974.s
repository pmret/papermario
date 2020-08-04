.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80053974
/* 02ED74 80053974 0080402D */  daddu $t0, $a0, $zero
/* 02ED78 80053978 00063400 */  sll   $a2, $a2, 0x10
/* 02ED7C 8005397C AD060000 */  sw    $a2, ($t0)
/* 02ED80 80053980 10A00020 */  beqz  $a1, .L80053A04
/* 02ED84 80053984 A5070008 */   sh    $a3, 8($t0)
/* 02ED88 80053988 3C03B65C */  lui   $v1, 0xb65c
/* 02ED8C 8005398C 34636D59 */  ori   $v1, $v1, 0x6d59
/* 02ED90 80053990 00051140 */  sll   $v0, $a1, 5
/* 02ED94 80053994 00451023 */  subu  $v0, $v0, $a1
/* 02ED98 80053998 00021080 */  sll   $v0, $v0, 2
/* 02ED9C 8005399C 00451021 */  addu  $v0, $v0, $a1
/* 02EDA0 800539A0 000210C0 */  sll   $v0, $v0, 3
/* 02EDA4 800539A4 00430018 */  mult  $v0, $v1
/* 02EDA8 800539A8 00001810 */  mfhi  $v1
/* 02EDAC 800539AC 00622021 */  addu  $a0, $v1, $v0
/* 02EDB0 800539B0 00042303 */  sra   $a0, $a0, 0xc
/* 02EDB4 800539B4 000217C3 */  sra   $v0, $v0, 0x1f
/* 02EDB8 800539B8 00822023 */  subu  $a0, $a0, $v0
/* 02EDBC 800539BC 00C0102D */  daddu $v0, $a2, $zero
/* 02EDC0 800539C0 00071C00 */  sll   $v1, $a3, 0x10
/* 02EDC4 800539C4 00621823 */  subu  $v1, $v1, $v0
/* 02EDC8 800539C8 00041400 */  sll   $v0, $a0, 0x10
/* 02EDCC 800539CC 00021403 */  sra   $v0, $v0, 0x10
/* 02EDD0 800539D0 14400002 */  bnez  $v0, .L800539DC
/* 02EDD4 800539D4 0062001A */   div   $zero, $v1, $v0
/* 02EDD8 800539D8 0007000D */  break 7
.L800539DC:
/* 02EDDC 800539DC 2401FFFF */  addiu $at, $zero, -1
/* 02EDE0 800539E0 14410004 */  bne   $v0, $at, .L800539F4
/* 02EDE4 800539E4 3C018000 */   lui   $at, 0x8000
/* 02EDE8 800539E8 14610002 */  bne   $v1, $at, .L800539F4
/* 02EDEC 800539EC 00000000 */   nop   
/* 02EDF0 800539F0 0006000D */  break 6
.L800539F4:
/* 02EDF4 800539F4 00001812 */  mflo  $v1
/* 02EDF8 800539F8 A504000A */  sh    $a0, 0xa($t0)
/* 02EDFC 800539FC 08014E84 */  j     .L80053A10
/* 02EE00 80053A00 AD030004 */   sw    $v1, 4($t0)

.L80053A04:
/* 02EE04 80053A04 24020001 */  addiu $v0, $zero, 1
/* 02EE08 80053A08 A502000A */  sh    $v0, 0xa($t0)
/* 02EE0C 80053A0C AD000004 */  sw    $zero, 4($t0)
.L80053A10:
/* 02EE10 80053A10 03E00008 */  jr    $ra
/* 02EE14 80053A14 AD00000C */   sw    $zero, 0xc($t0)

