.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DFEFC
/* 0793AC 800DFEFC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0793B0 800DFF00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0793B4 800DFF04 3C108011 */  lui   $s0, 0x8011
/* 0793B8 800DFF08 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 0793BC 800DFF0C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0793C0 800DFF10 0C037F52 */  jal   func_800DFD48
/* 0793C4 800DFF14 00000000 */   nop   
/* 0793C8 800DFF18 0040202D */  daddu $a0, $v0, $zero
/* 0793CC 800DFF1C 2402FFFF */  addiu $v0, $zero, -1
/* 0793D0 800DFF20 10820007 */  beq   $a0, $v0, .L800DFF40
/* 0793D4 800DFF24 3C03EFFF */   lui   $v1, 0xefff
/* 0793D8 800DFF28 8E020000 */  lw    $v0, ($s0)
/* 0793DC 800DFF2C 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0793E0 800DFF30 AE0400B8 */  sw    $a0, 0xb8($s0)
/* 0793E4 800DFF34 A60000BC */  sh    $zero, 0xbc($s0)
/* 0793E8 800DFF38 00431024 */  and   $v0, $v0, $v1
/* 0793EC 800DFF3C AE020000 */  sw    $v0, ($s0)
.L800DFF40:
/* 0793F0 800DFF40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0793F4 800DFF44 8FB00010 */  lw    $s0, 0x10($sp)
/* 0793F8 800DFF48 03E00008 */  jr    $ra
/* 0793FC 800DFF4C 27BD0018 */   addiu $sp, $sp, 0x18

/* 079400 800DFF50 3C02EFFF */  lui   $v0, 0xefff
/* 079404 800DFF54 3C038011 */  lui   $v1, 0x8011
/* 079408 800DFF58 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 07940C 800DFF5C 8C650000 */  lw    $a1, ($v1)
/* 079410 800DFF60 3442FFFF */  ori   $v0, $v0, 0xffff
/* 079414 800DFF64 AC6400B8 */  sw    $a0, 0xb8($v1)
/* 079418 800DFF68 A46000BC */  sh    $zero, 0xbc($v1)
/* 07941C 800DFF6C 00A22824 */  and   $a1, $a1, $v0
/* 079420 800DFF70 03E00008 */  jr    $ra
/* 079424 800DFF74 AC650000 */   sw    $a1, ($v1)

