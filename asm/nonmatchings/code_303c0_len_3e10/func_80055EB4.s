.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055EB4
/* 0312B4 80055EB4 2C820008 */  sltiu $v0, $a0, 8
/* 0312B8 80055EB8 10400025 */  beqz  $v0, .L80055F50
/* 0312BC 80055EBC 0000182D */   daddu $v1, $zero, $zero
/* 0312C0 80055EC0 00041080 */  sll   $v0, $a0, 2
/* 0312C4 80055EC4 3C01800A */  lui   $at, 0x800a
/* 0312C8 80055EC8 00220821 */  addu  $at, $at, $v0
/* 0312CC 80055ECC 8C228908 */  lw    $v0, -0x76f8($at)
/* 0312D0 80055ED0 00400008 */  jr    $v0
/* 0312D4 80055ED4 00000000 */   nop   
/* 0312D8 80055ED8 3C038008 */  lui   $v1, 0x8008
/* 0312DC 80055EDC 24638DB8 */  addiu $v1, $v1, -0x7248
/* 0312E0 80055EE0 03E00008 */  jr    $ra
/* 0312E4 80055EE4 0060102D */   daddu $v0, $v1, $zero

/* 0312E8 80055EE8 3C038008 */  lui   $v1, 0x8008
/* 0312EC 80055EEC 24638DC4 */  addiu $v1, $v1, -0x723c
/* 0312F0 80055EF0 03E00008 */  jr    $ra
/* 0312F4 80055EF4 0060102D */   daddu $v0, $v1, $zero

/* 0312F8 80055EF8 3C038008 */  lui   $v1, 0x8008
/* 0312FC 80055EFC 24638DCC */  addiu $v1, $v1, -0x7234
/* 031300 80055F00 03E00008 */  jr    $ra
/* 031304 80055F04 0060102D */   daddu $v0, $v1, $zero

/* 031308 80055F08 3C038008 */  lui   $v1, 0x8008
/* 03130C 80055F0C 24638DD0 */  addiu $v1, $v1, -0x7230
/* 031310 80055F10 03E00008 */  jr    $ra
/* 031314 80055F14 0060102D */   daddu $v0, $v1, $zero

/* 031318 80055F18 3C038008 */  lui   $v1, 0x8008
/* 03131C 80055F1C 24638DDC */  addiu $v1, $v1, -0x7224
/* 031320 80055F20 03E00008 */  jr    $ra
/* 031324 80055F24 0060102D */   daddu $v0, $v1, $zero

/* 031328 80055F28 3C038008 */  lui   $v1, 0x8008
/* 03132C 80055F2C 24638DF8 */  addiu $v1, $v1, -0x7208
/* 031330 80055F30 03E00008 */  jr    $ra
/* 031334 80055F34 0060102D */   daddu $v0, $v1, $zero

/* 031338 80055F38 3C038008 */  lui   $v1, 0x8008
/* 03133C 80055F3C 24638E14 */  addiu $v1, $v1, -0x71ec
/* 031340 80055F40 03E00008 */  jr    $ra
/* 031344 80055F44 0060102D */   daddu $v0, $v1, $zero

/* 031348 80055F48 3C038008 */  lui   $v1, 0x8008
/* 03134C 80055F4C 24638E30 */  addiu $v1, $v1, -0x71d0
.L80055F50:
/* 031350 80055F50 03E00008 */  jr    $ra
/* 031354 80055F54 0060102D */   daddu $v0, $v1, $zero

