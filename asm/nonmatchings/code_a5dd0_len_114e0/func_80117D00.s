.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80117D00
/* 0AE400 80117D00 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 0AE404 80117D04 AFBF00DC */  sw    $ra, 0xdc($sp)
/* 0AE408 80117D08 AFB600D8 */  sw    $s6, 0xd8($sp)
/* 0AE40C 80117D0C AFB500D4 */  sw    $s5, 0xd4($sp)
/* 0AE410 80117D10 AFB400D0 */  sw    $s4, 0xd0($sp)
/* 0AE414 80117D14 AFB300CC */  sw    $s3, 0xcc($sp)
/* 0AE418 80117D18 AFB200C8 */  sw    $s2, 0xc8($sp)
/* 0AE41C 80117D1C AFB100C4 */  sw    $s1, 0xc4($sp)
/* 0AE420 80117D20 AFB000C0 */  sw    $s0, 0xc0($sp)
/* 0AE424 80117D24 8C930008 */  lw    $s3, 8($a0)
/* 0AE428 80117D28 8E630000 */  lw    $v1, ($s3)
/* 0AE42C 80117D2C 24020002 */  addiu $v0, $zero, 2
/* 0AE430 80117D30 10620044 */  beq   $v1, $v0, .L80117E44
/* 0AE434 80117D34 0080802D */   daddu $s0, $a0, $zero
/* 0AE438 80117D38 8E620010 */  lw    $v0, 0x10($s3)
/* 0AE43C 80117D3C 10400043 */  beqz  $v0, .L80117E4C
/* 0AE440 80117D40 00000000 */   nop   
/* 0AE444 80117D44 8C52000C */  lw    $s2, 0xc($v0)
/* 0AE448 80117D48 12400040 */  beqz  $s2, .L80117E4C
/* 0AE44C 80117D4C 00000000 */   nop   
/* 0AE450 80117D50 1A40003E */  blez  $s2, .L80117E4C
/* 0AE454 80117D54 0000882D */   daddu $s1, $zero, $zero
/* 0AE458 80117D58 249500B0 */  addiu $s5, $a0, 0xb0
/* 0AE45C 80117D5C 24160002 */  addiu $s6, $zero, 2
/* 0AE460 80117D60 3C148015 */  lui   $s4, 0x8015
/* 0AE464 80117D64 26943224 */  addiu $s4, $s4, 0x3224
/* 0AE468 80117D68 27A30010 */  addiu $v1, $sp, 0x10
.L80117D6C:
/* 0AE46C 80117D6C 0200102D */  daddu $v0, $s0, $zero
.L80117D70:
/* 0AE470 80117D70 8C460000 */  lw    $a2, ($v0)
/* 0AE474 80117D74 8C470004 */  lw    $a3, 4($v0)
/* 0AE478 80117D78 8C480008 */  lw    $t0, 8($v0)
/* 0AE47C 80117D7C 8C49000C */  lw    $t1, 0xc($v0)
/* 0AE480 80117D80 AC660000 */  sw    $a2, ($v1)
/* 0AE484 80117D84 AC670004 */  sw    $a3, 4($v1)
/* 0AE488 80117D88 AC680008 */  sw    $t0, 8($v1)
/* 0AE48C 80117D8C AC69000C */  sw    $t1, 0xc($v1)
/* 0AE490 80117D90 24420010 */  addiu $v0, $v0, 0x10
/* 0AE494 80117D94 1455FFF6 */  bne   $v0, $s5, .L80117D70
/* 0AE498 80117D98 24630010 */   addiu $v1, $v1, 0x10
/* 0AE49C 80117D9C 96020000 */  lhu   $v0, ($s0)
/* 0AE4A0 80117DA0 A7A20010 */  sh    $v0, 0x10($sp)
/* 0AE4A4 80117DA4 8E020010 */  lw    $v0, 0x10($s0)
/* 0AE4A8 80117DA8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0AE4AC 80117DAC 8E620010 */  lw    $v0, 0x10($s3)
/* 0AE4B0 80117DB0 8C430010 */  lw    $v1, 0x10($v0)
/* 0AE4B4 80117DB4 00111080 */  sll   $v0, $s1, 2
/* 0AE4B8 80117DB8 00431021 */  addu  $v0, $v0, $v1
/* 0AE4BC 80117DBC 8C440000 */  lw    $a0, ($v0)
/* 0AE4C0 80117DC0 AFA40018 */  sw    $a0, 0x18($sp)
/* 0AE4C4 80117DC4 920200A4 */  lbu   $v0, 0xa4($s0)
/* 0AE4C8 80117DC8 A3A200B4 */  sb    $v0, 0xb4($sp)
/* 0AE4CC 80117DCC 920200A5 */  lbu   $v0, 0xa5($s0)
/* 0AE4D0 80117DD0 A3A200B5 */  sb    $v0, 0xb5($sp)
/* 0AE4D4 80117DD4 8C820000 */  lw    $v0, ($a0)
/* 0AE4D8 80117DD8 14560003 */  bne   $v0, $s6, .L80117DE8
/* 0AE4DC 80117DDC 0000102D */   daddu $v0, $zero, $zero
/* 0AE4E0 80117DE0 0C0456C3 */  jal   get_model_property
/* 0AE4E4 80117DE4 2405005C */   addiu $a1, $zero, 0x5c
.L80117DE8:
/* 0AE4E8 80117DE8 50400003 */  beql  $v0, $zero, .L80117DF8
/* 0AE4EC 80117DEC A3A000B6 */   sb    $zero, 0xb6($sp)
/* 0AE4F0 80117DF0 9042000B */  lbu   $v0, 0xb($v0)
/* 0AE4F4 80117DF4 A3A200B6 */  sb    $v0, 0xb6($sp)
.L80117DF8:
/* 0AE4F8 80117DF8 8E820000 */  lw    $v0, ($s4)
/* 0AE4FC 80117DFC 3C03800A */  lui   $v1, 0x800a
/* 0AE500 80117E00 8C63A5F4 */  lw    $v1, -0x5a0c($v1)
/* 0AE504 80117E04 00021080 */  sll   $v0, $v0, 2
/* 0AE508 80117E08 00431021 */  addu  $v0, $v0, $v1
/* 0AE50C 80117E0C 90420002 */  lbu   $v0, 2($v0)
/* 0AE510 80117E10 27A40010 */  addiu $a0, $sp, 0x10
/* 0AE514 80117E14 A3A000B9 */  sb    $zero, 0xb9($sp)
/* 0AE518 80117E18 0C045F40 */  jal   func_80117D00
/* 0AE51C 80117E1C A3A200B8 */   sb    $v0, 0xb8($sp)
/* 0AE520 80117E20 8E820000 */  lw    $v0, ($s4)
/* 0AE524 80117E24 26310001 */  addiu $s1, $s1, 1
/* 0AE528 80117E28 24420001 */  addiu $v0, $v0, 1
/* 0AE52C 80117E2C AE820000 */  sw    $v0, ($s4)
/* 0AE530 80117E30 0232102A */  slt   $v0, $s1, $s2
/* 0AE534 80117E34 1440FFCD */  bnez  $v0, .L80117D6C
/* 0AE538 80117E38 27A30010 */   addiu $v1, $sp, 0x10
/* 0AE53C 80117E3C 08045F93 */  j     .L80117E4C
/* 0AE540 80117E40 00000000 */   nop   

.L80117E44:
/* 0AE544 80117E44 0C044C24 */  jal   func_80113090
/* 0AE548 80117E48 0200202D */   daddu $a0, $s0, $zero
.L80117E4C:
/* 0AE54C 80117E4C 8FBF00DC */  lw    $ra, 0xdc($sp)
/* 0AE550 80117E50 8FB600D8 */  lw    $s6, 0xd8($sp)
/* 0AE554 80117E54 8FB500D4 */  lw    $s5, 0xd4($sp)
/* 0AE558 80117E58 8FB400D0 */  lw    $s4, 0xd0($sp)
/* 0AE55C 80117E5C 8FB300CC */  lw    $s3, 0xcc($sp)
/* 0AE560 80117E60 8FB200C8 */  lw    $s2, 0xc8($sp)
/* 0AE564 80117E64 8FB100C4 */  lw    $s1, 0xc4($sp)
/* 0AE568 80117E68 8FB000C0 */  lw    $s0, 0xc0($sp)
/* 0AE56C 80117E6C 03E00008 */  jr    $ra
/* 0AE570 80117E70 27BD00E0 */   addiu $sp, $sp, 0xe0

