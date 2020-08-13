.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004E4B8
/* 0298B8 8004E4B8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0298BC 8004E4BC AFB00010 */  sw    $s0, 0x10($sp)
/* 0298C0 8004E4C0 0080802D */  daddu $s0, $a0, $zero
/* 0298C4 8004E4C4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0298C8 8004E4C8 24110001 */  addiu $s1, $zero, 1
/* 0298CC 8004E4CC AFB20018 */  sw    $s2, 0x18($sp)
/* 0298D0 8004E4D0 0000902D */  daddu $s2, $zero, $zero
/* 0298D4 8004E4D4 AFB40020 */  sw    $s4, 0x20($sp)
/* 0298D8 8004E4D8 3C14800A */  lui   $s4, 0x800a
/* 0298DC 8004E4DC 269488C0 */  addiu $s4, $s4, -0x7740
/* 0298E0 8004E4E0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0298E4 8004E4E4 24130001 */  addiu $s3, $zero, 1
/* 0298E8 8004E4E8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0298EC 8004E4EC 96020052 */  lhu   $v0, 0x52($s0)
/* 0298F0 8004E4F0 9603001A */  lhu   $v1, 0x1a($s0)
/* 0298F4 8004E4F4 8E040018 */  lw    $a0, 0x18($s0)
/* 0298F8 8004E4F8 00431021 */  addu  $v0, $v0, $v1
/* 0298FC 8004E4FC 96030016 */  lhu   $v1, 0x16($s0)
/* 029900 8004E500 00042100 */  sll   $a0, $a0, 4
/* 029904 8004E504 00431021 */  addu  $v0, $v0, $v1
/* 029908 8004E508 96030056 */  lhu   $v1, 0x56($s0)
/* 02990C 8004E50C 3084FFFF */  andi  $a0, $a0, 0xffff
/* 029910 8004E510 AE020050 */  sw    $v0, 0x50($s0)
/* 029914 8004E514 8E020014 */  lw    $v0, 0x14($s0)
/* 029918 8004E518 00641821 */  addu  $v1, $v1, $a0
/* 02991C 8004E51C 00021103 */  sra   $v0, $v0, 4
/* 029920 8004E520 3042FFFF */  andi  $v0, $v0, 0xffff
/* 029924 8004E524 00621821 */  addu  $v1, $v1, $v0
/* 029928 8004E528 AE030054 */  sw    $v1, 0x54($s0)
.L8004E52C:
/* 02992C 8004E52C 92030221 */  lbu   $v1, 0x221($s0)
/* 029930 8004E530 2C620005 */  sltiu $v0, $v1, 5
/* 029934 8004E534 1040001B */  beqz  $v0, .L8004E5A4
/* 029938 8004E538 00031080 */   sll   $v0, $v1, 2
/* 02993C 8004E53C 00541021 */  addu  $v0, $v0, $s4
/* 029940 8004E540 8C420000 */  lw    $v0, ($v0)
/* 029944 8004E544 00400008 */  jr    $v0
/* 029948 8004E548 00000000 */   nop   
/* 02994C 8004E54C 92020220 */  lbu   $v0, 0x220($s0)
/* 029950 8004E550 54400016 */  bnel  $v0, $zero, .L8004E5AC
/* 029954 8004E554 0000882D */   daddu $s1, $zero, $zero
/* 029958 8004E558 0C013B1A */  jal   func_8004EC68
/* 02995C 8004E55C 0200202D */   daddu $a0, $s0, $zero
/* 029960 8004E560 92020221 */  lbu   $v0, 0x221($s0)
/* 029964 8004E564 14530012 */  bne   $v0, $s3, .L8004E5B0
/* 029968 8004E568 3222FFFF */   andi  $v0, $s1, 0xffff
/* 02996C 8004E56C 0801396B */  j     .L8004E5AC
/* 029970 8004E570 0000882D */   daddu $s1, $zero, $zero

/* 029974 8004E574 0C013A41 */  jal   func_8004E904
/* 029978 8004E578 0200202D */   daddu $a0, $s0, $zero
/* 02997C 8004E57C 0801396C */  j     .L8004E5B0
/* 029980 8004E580 3222FFFF */   andi  $v0, $s1, 0xffff

/* 029984 8004E584 0C013976 */  jal   func_8004E5D8
/* 029988 8004E588 0200202D */   daddu $a0, $s0, $zero
/* 02998C 8004E58C 0801396B */  j     .L8004E5AC
/* 029990 8004E590 0000882D */   daddu $s1, $zero, $zero

/* 029994 8004E594 0C013B01 */  jal   func_8004EC04
/* 029998 8004E598 0200202D */   daddu $a0, $s0, $zero
/* 02999C 8004E59C 0801396C */  j     .L8004E5B0
/* 0299A0 8004E5A0 3222FFFF */   andi  $v0, $s1, 0xffff

.L8004E5A4:
/* 0299A4 8004E5A4 24120001 */  addiu $s2, $zero, 1
/* 0299A8 8004E5A8 0000882D */  daddu $s1, $zero, $zero
.L8004E5AC:
/* 0299AC 8004E5AC 3222FFFF */  andi  $v0, $s1, 0xffff
.L8004E5B0:
/* 0299B0 8004E5B0 1440FFDE */  bnez  $v0, .L8004E52C
/* 0299B4 8004E5B4 0240102D */   daddu $v0, $s2, $zero
/* 0299B8 8004E5B8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0299BC 8004E5BC 8FB40020 */  lw    $s4, 0x20($sp)
/* 0299C0 8004E5C0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0299C4 8004E5C4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0299C8 8004E5C8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0299CC 8004E5CC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0299D0 8004E5D0 03E00008 */  jr    $ra
/* 0299D4 8004E5D4 27BD0028 */   addiu $sp, $sp, 0x28

