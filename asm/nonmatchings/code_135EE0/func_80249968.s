.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249968
/* 13CCA8 80249968 03E00008 */  jr    $ra
/* 13CCAC 8024996C 0080102D */   daddu $v0, $a0, $zero

/* 13CCB0 80249970 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 13CCB4 80249974 3C038027 */  lui   $v1, 0x8027
/* 13CCB8 80249978 8C6304C8 */  lw    $v1, 0x4c8($v1)
/* 13CCBC 8024997C 240A0001 */  addiu $t2, $zero, 1
/* 13CCC0 80249980 AFA500AC */  sw    $a1, 0xac($sp)
/* 13CCC4 80249984 AFAA0060 */  sw    $t2, 0x60($sp)
/* 13CCC8 80249988 8FAA00AC */  lw    $t2, 0xac($sp)
/* 13CCCC 8024998C AFA600B0 */  sw    $a2, 0xb0($sp)
/* 13CCD0 80249990 AFA700B4 */  sw    $a3, 0xb4($sp)
/* 13CCD4 80249994 8FA700B0 */  lw    $a3, 0xb0($sp)
/* 13CCD8 80249998 240B000A */  addiu $t3, $zero, 0xa
/* 13CCDC 8024999C AFAB0064 */  sw    $t3, 0x64($sp)
/* 13CCE0 802499A0 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 13CCE4 802499A4 AFBF00A4 */  sw    $ra, 0xa4($sp)
/* 13CCE8 802499A8 AFBE00A0 */  sw    $fp, 0xa0($sp)
/* 13CCEC 802499AC AFB7009C */  sw    $s7, 0x9c($sp)
/* 13CCF0 802499B0 AFB60098 */  sw    $s6, 0x98($sp)
/* 13CCF4 802499B4 AFB50094 */  sw    $s5, 0x94($sp)
/* 13CCF8 802499B8 AFB40090 */  sw    $s4, 0x90($sp)
/* 13CCFC 802499BC AFB3008C */  sw    $s3, 0x8c($sp)
/* 13CD00 802499C0 AFB20088 */  sw    $s2, 0x88($sp)
/* 13CD04 802499C4 AFB10084 */  sw    $s1, 0x84($sp)
/* 13CD08 802499C8 AFB00080 */  sw    $s0, 0x80($sp)
/* 13CD0C 802499CC 25460044 */  addiu $a2, $t2, 0x44
/* 13CD10 802499D0 00031040 */  sll   $v0, $v1, 1
/* 13CD14 802499D4 00431021 */  addu  $v0, $v0, $v1
/* 13CD18 802499D8 00021080 */  sll   $v0, $v0, 2
/* 13CD1C 802499DC 3C088027 */  lui   $t0, 0x8027
/* 13CD20 802499E0 01024021 */  addu  $t0, $t0, $v0
/* 13CD24 802499E4 910804D2 */  lbu   $t0, 0x4d2($t0)
/* 13CD28 802499E8 8FAA00B8 */  lw    $t2, 0xb8($sp)
/* 13CD2C 802499EC 2562FFBC */  addiu $v0, $t3, -0x44
/* 13CD30 802499F0 AFA20014 */  sw    $v0, 0x14($sp)
/* 13CD34 802499F4 240200FF */  addiu $v0, $zero, 0xff
/* 13CD38 802499F8 AFA00010 */  sw    $zero, 0x10($sp)
/* 13CD3C 802499FC AFA2001C */  sw    $v0, 0x1c($sp)
/* 13CD40 80249A00 AFA00020 */  sw    $zero, 0x20($sp)
/* 13CD44 80249A04 AFA00024 */  sw    $zero, 0x24($sp)
/* 13CD48 80249A08 AFA00028 */  sw    $zero, 0x28($sp)
/* 13CD4C 80249A0C AFA0002C */  sw    $zero, 0x2c($sp)
/* 13CD50 80249A10 AFA00030 */  sw    $zero, 0x30($sp)
/* 13CD54 80249A14 AFA00034 */  sw    $zero, 0x34($sp)
/* 13CD58 80249A18 AFA00038 */  sw    $zero, 0x38($sp)
/* 13CD5C 80249A1C AFA0003C */  sw    $zero, 0x3c($sp)
/* 13CD60 80249A20 AFAA0018 */  sw    $t2, 0x18($sp)
/* 13CD64 80249A24 AFA00040 */  sw    $zero, 0x40($sp)
/* 13CD68 80249A28 3C038027 */  lui   $v1, 0x8027
/* 13CD6C 80249A2C 8C6305C0 */  lw    $v1, 0x5c0($v1)
/* 13CD70 80249A30 15000002 */  bnez  $t0, .L80249A3C
/* 13CD74 80249A34 0068001A */   div   $zero, $v1, $t0
/* 13CD78 80249A38 0007000D */  break 7
.L80249A3C:
/* 13CD7C 80249A3C 2401FFFF */  addiu $at, $zero, -1
/* 13CD80 80249A40 15010004 */  bne   $t0, $at, .L80249A54
/* 13CD84 80249A44 3C018000 */   lui   $at, 0x8000
/* 13CD88 80249A48 14610002 */  bne   $v1, $at, .L80249A54
/* 13CD8C 80249A4C 00000000 */   nop   
/* 13CD90 80249A50 0006000D */  break 6
.L80249A54:
/* 13CD94 80249A54 00005012 */  mflo  $t2
/* 13CD98 80249A58 00005810 */  mfhi  $t3
/* 13CD9C 80249A5C 24040004 */  addiu $a0, $zero, 4
/* 13CDA0 80249A60 3C058027 */  lui   $a1, 0x8027
/* 13CDA4 80249A64 24A5FCF0 */  addiu $a1, $a1, -0x310
/* 13CDA8 80249A68 24020140 */  addiu $v0, $zero, 0x140
/* 13CDAC 80249A6C AFA20044 */  sw    $v0, 0x44($sp)
/* 13CDB0 80249A70 240200F0 */  addiu $v0, $zero, 0xf0
/* 13CDB4 80249A74 AFA20048 */  sw    $v0, 0x48($sp)
/* 13CDB8 80249A78 AFA0004C */  sw    $zero, 0x4c($sp)
/* 13CDBC 80249A7C AFAA005C */  sw    $t2, 0x5c($sp)
/* 13CDC0 80249A80 0C03D4B8 */  jal   draw_box
/* 13CDC4 80249A84 AFAB0058 */   sw    $t3, 0x58($sp)
/* 13CDC8 80249A88 3C108027 */  lui   $s0, 0x8027
/* 13CDCC 80249A8C 261004D0 */  addiu $s0, $s0, 0x4d0
/* 13CDD0 80249A90 8FAB00B0 */  lw    $t3, 0xb0($sp)
/* 13CDD4 80249A94 8FAA00AC */  lw    $t2, 0xac($sp)
/* 13CDD8 80249A98 25660007 */  addiu $a2, $t3, 7
/* 13CDDC 80249A9C 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 13CDE0 80249AA0 25440001 */  addiu $a0, $t2, 1
/* 13CDE4 80249AA4 014B1021 */  addu  $v0, $t2, $t3
/* 13CDE8 80249AA8 8FAA00B0 */  lw    $t2, 0xb0($sp)
/* 13CDEC 80249AAC 8FAB00B8 */  lw    $t3, 0xb8($sp)
/* 13CDF0 80249AB0 2447FFFF */  addiu $a3, $v0, -1
/* 13CDF4 80249AB4 014B1021 */  addu  $v0, $t2, $t3
/* 13CDF8 80249AB8 1C800002 */  bgtz  $a0, .L80249AC4
/* 13CDFC 80249ABC 2448FFF9 */   addiu $t0, $v0, -7
/* 13CE00 80249AC0 24040001 */  addiu $a0, $zero, 1
.L80249AC4:
/* 13CE04 80249AC4 58C00001 */  blezl $a2, .L80249ACC
/* 13CE08 80249AC8 24060001 */   addiu $a2, $zero, 1
.L80249ACC:
/* 13CE0C 80249ACC 18E00277 */  blez  $a3, .L8024A4AC
/* 13CE10 80249AD0 00000000 */   nop   
/* 13CE14 80249AD4 19000275 */  blez  $t0, .L8024A4AC
/* 13CE18 80249AD8 2882013F */   slti  $v0, $a0, 0x13f
/* 13CE1C 80249ADC 10400273 */  beqz  $v0, .L8024A4AC
/* 13CE20 80249AE0 28C200EF */   slti  $v0, $a2, 0xef
/* 13CE24 80249AE4 10400271 */  beqz  $v0, .L8024A4AC
/* 13CE28 80249AE8 28E2013F */   slti  $v0, $a3, 0x13f
/* 13CE2C 80249AEC 50400001 */  beql  $v0, $zero, .L80249AF4
/* 13CE30 80249AF0 2407013F */   addiu $a3, $zero, 0x13f
.L80249AF4:
/* 13CE34 80249AF4 290200EF */  slti  $v0, $t0, 0xef
/* 13CE38 80249AF8 50400001 */  beql  $v0, $zero, .L80249B00
/* 13CE3C 80249AFC 240800EF */   addiu $t0, $zero, 0xef
.L80249B00:
/* 13CE40 80249B00 3C03800A */  lui   $v1, 0x800a
/* 13CE44 80249B04 2463A66C */  addiu $v1, $v1, -0x5994
/* 13CE48 80249B08 44841000 */  mtc1  $a0, $f2
/* 13CE4C 80249B0C 00000000 */  nop   
/* 13CE50 80249B10 468010A0 */  cvt.s.w $f2, $f2
/* 13CE54 80249B14 44860000 */  mtc1  $a2, $f0
/* 13CE58 80249B18 00000000 */  nop   
/* 13CE5C 80249B1C 46800020 */  cvt.s.w $f0, $f0
/* 13CE60 80249B20 8FAA00AC */  lw    $t2, 0xac($sp)
/* 13CE64 80249B24 8FAB00B0 */  lw    $t3, 0xb0($sp)
/* 13CE68 80249B28 3C014080 */  lui   $at, 0x4080
/* 13CE6C 80249B2C 44812000 */  mtc1  $at, $f4
