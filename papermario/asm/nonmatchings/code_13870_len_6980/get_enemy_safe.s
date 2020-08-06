.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_enemy_safe
/* 01A168 8003ED68 3C03800B */  lui   $v1, 0x800b
/* 01A16C 8003ED6C 24630F10 */  addiu $v1, $v1, 0xf10
/* 01A170 8003ED70 8062001C */  lb    $v0, 0x1c($v1)
/* 01A174 8003ED74 1840001A */  blez  $v0, .L8003EDE0
/* 01A178 8003ED78 0000382D */   daddu $a3, $zero, $zero
/* 01A17C 8003ED7C 0040502D */  daddu $t2, $v0, $zero
/* 01A180 8003ED80 0060482D */  daddu $t1, $v1, $zero
.L8003ED84:
/* 01A184 8003ED84 8D220028 */  lw    $v0, 0x28($t1)
/* 01A188 8003ED88 50400012 */  beql  $v0, $zero, .L8003EDD4
/* 01A18C 8003ED8C 24E70001 */   addiu $a3, $a3, 1
/* 01A190 8003ED90 8C430000 */  lw    $v1, ($v0)
/* 01A194 8003ED94 1860000E */  blez  $v1, .L8003EDD0
/* 01A198 8003ED98 0000302D */   daddu $a2, $zero, $zero
/* 01A19C 8003ED9C 0060402D */  daddu $t0, $v1, $zero
/* 01A1A0 8003EDA0 0040282D */  daddu $a1, $v0, $zero
.L8003EDA4:
/* 01A1A4 8003EDA4 8CA30004 */  lw    $v1, 4($a1)
/* 01A1A8 8003EDA8 10600006 */  beqz  $v1, .L8003EDC4
/* 01A1AC 8003EDAC 24C60001 */   addiu $a2, $a2, 1
/* 01A1B0 8003EDB0 84620008 */  lh    $v0, 8($v1)
/* 01A1B4 8003EDB4 14440004 */  bne   $v0, $a0, .L8003EDC8
/* 01A1B8 8003EDB8 00C8102A */   slt   $v0, $a2, $t0
/* 01A1BC 8003EDBC 03E00008 */  jr    $ra
/* 01A1C0 8003EDC0 0060102D */   daddu $v0, $v1, $zero

.L8003EDC4:
/* 01A1C4 8003EDC4 00C8102A */  slt   $v0, $a2, $t0
.L8003EDC8:
/* 01A1C8 8003EDC8 1440FFF6 */  bnez  $v0, .L8003EDA4
/* 01A1CC 8003EDCC 24A50004 */   addiu $a1, $a1, 4
.L8003EDD0:
/* 01A1D0 8003EDD0 24E70001 */  addiu $a3, $a3, 1
.L8003EDD4:
/* 01A1D4 8003EDD4 00EA102A */  slt   $v0, $a3, $t2
/* 01A1D8 8003EDD8 1440FFEA */  bnez  $v0, .L8003ED84
/* 01A1DC 8003EDDC 25290004 */   addiu $t1, $t1, 4
.L8003EDE0:
/* 01A1E0 8003EDE0 03E00008 */  jr    $ra
/* 01A1E4 8003EDE4 0000102D */   daddu $v0, $zero, $zero

/* 01A1E8 8003EDE8 00000000 */  nop   
/* 01A1EC 8003EDEC 00000000 */  nop   


