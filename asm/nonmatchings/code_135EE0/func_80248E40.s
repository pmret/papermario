.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80248E40
.L80248E40:
/* 13C180 80248E40 16000004 */  bnez  $s0, .L80248E54
/* 13C184 80248E44 24027FFE */   addiu $v0, $zero, 0x7ffe
/* 13C188 80248E48 3C018027 */  lui   $at, 0x8027
/* 13C18C 80248E4C A4220180 */  sh    $v0, 0x180($at)
/* 13C190 80248E50 24100001 */  addiu $s0, $zero, 1
.L80248E54:
/* 13C194 80248E54 3C018027 */  lui   $at, 0x8027
/* 13C198 80248E58 A4300384 */  sh    $s0, 0x384($at)
/* 13C19C 80248E5C 0200202D */  daddu $a0, $s0, $zero
/* 13C1A0 80248E60 28820080 */  slti  $v0, $a0, 0x80
/* 13C1A4 80248E64 1040000A */  beqz  $v0, .L80248E90
/* 13C1A8 80248E68 24057FFF */   addiu $a1, $zero, 0x7fff
/* 13C1AC 80248E6C 3C038027 */  lui   $v1, 0x8027
/* 13C1B0 80248E70 24630180 */  addiu $v1, $v1, 0x180
/* 13C1B4 80248E74 00041040 */  sll   $v0, $a0, 1
/* 13C1B8 80248E78 00431821 */  addu  $v1, $v0, $v1
.L80248E7C:
/* 13C1BC 80248E7C A4650000 */  sh    $a1, ($v1)
/* 13C1C0 80248E80 24840001 */  addiu $a0, $a0, 1
/* 13C1C4 80248E84 28820080 */  slti  $v0, $a0, 0x80
/* 13C1C8 80248E88 1440FFFC */  bnez  $v0, .L80248E7C
/* 13C1CC 80248E8C 24630002 */   addiu $v1, $v1, 2
.L80248E90:
/* 13C1D0 80248E90 3C058027 */  lui   $a1, 0x8027
/* 13C1D4 80248E94 24A50288 */  addiu $a1, $a1, 0x288
/* 13C1D8 80248E98 0000202D */  daddu $a0, $zero, $zero
/* 13C1DC 80248E9C 3C078027 */  lui   $a3, 0x8027
/* 13C1E0 80248EA0 24E70384 */  addiu $a3, $a3, 0x384
/* 13C1E4 80248EA4 24060001 */  addiu $a2, $zero, 1
/* 13C1E8 80248EA8 24090008 */  addiu $t1, $zero, 8
/* 13C1EC 80248EAC 24080008 */  addiu $t0, $zero, 8
/* 13C1F0 80248EB0 00A81821 */  addu  $v1, $a1, $t0
