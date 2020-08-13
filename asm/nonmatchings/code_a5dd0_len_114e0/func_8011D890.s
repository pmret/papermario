.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011D890
/* 0B3F90 8011D890 24040002 */  addiu $a0, $zero, 2
/* 0B3F94 8011D894 3C038015 */  lui   $v1, 0x8015
/* 0B3F98 8011D898 246333A8 */  addiu $v1, $v1, 0x33a8
/* 0B3F9C 8011D89C 3C02802C */  lui   $v0, 0x802c
/* 0B3FA0 8011D8A0 24429E00 */  addiu $v0, $v0, -0x6200
.L8011D8A4:
/* 0B3FA4 8011D8A4 AC620000 */  sw    $v0, ($v1)
/* 0B3FA8 8011D8A8 2463FFFC */  addiu $v1, $v1, -4
/* 0B3FAC 8011D8AC 2484FFFF */  addiu $a0, $a0, -1
/* 0B3FB0 8011D8B0 0481FFFC */  bgez  $a0, .L8011D8A4
/* 0B3FB4 8011D8B4 2442F000 */   addiu $v0, $v0, -0x1000
/* 0B3FB8 8011D8B8 3C018015 */  lui   $at, 0x8015
/* 0B3FBC 8011D8BC AC2033AC */  sw    $zero, 0x33ac($at)
/* 0B3FC0 8011D8C0 3C018015 */  lui   $at, 0x8015
/* 0B3FC4 8011D8C4 AC2033B0 */  sw    $zero, 0x33b0($at)
/* 0B3FC8 8011D8C8 03E00008 */  jr    $ra
/* 0B3FCC 8011D8CC 00000000 */   nop   

/* 0B3FD0 8011D8D0 24040002 */  addiu $a0, $zero, 2
/* 0B3FD4 8011D8D4 3C038015 */  lui   $v1, 0x8015
/* 0B3FD8 8011D8D8 246333A8 */  addiu $v1, $v1, 0x33a8
/* 0B3FDC 8011D8DC 3C02802C */  lui   $v0, 0x802c
/* 0B3FE0 8011D8E0 24429E00 */  addiu $v0, $v0, -0x6200
.L8011D8E4:
/* 0B3FE4 8011D8E4 AC620000 */  sw    $v0, ($v1)
/* 0B3FE8 8011D8E8 2463FFFC */  addiu $v1, $v1, -4
/* 0B3FEC 8011D8EC 2484FFFF */  addiu $a0, $a0, -1
/* 0B3FF0 8011D8F0 0481FFFC */  bgez  $a0, .L8011D8E4
/* 0B3FF4 8011D8F4 2442F000 */   addiu $v0, $v0, -0x1000
/* 0B3FF8 8011D8F8 3C018015 */  lui   $at, 0x8015
/* 0B3FFC 8011D8FC AC2033AC */  sw    $zero, 0x33ac($at)
/* 0B4000 8011D900 3C018015 */  lui   $at, 0x8015
/* 0B4004 8011D904 AC2033B0 */  sw    $zero, 0x33b0($at)
/* 0B4008 8011D908 03E00008 */  jr    $ra
/* 0B400C 8011D90C 00000000 */   nop   

