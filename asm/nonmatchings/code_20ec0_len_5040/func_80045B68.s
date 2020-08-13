.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80045B68
/* 020F68 80045B68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020F6C 80045B6C AFB10014 */  sw    $s1, 0x14($sp)
/* 020F70 80045B70 0000882D */  daddu $s1, $zero, $zero
/* 020F74 80045B74 AFB00010 */  sw    $s0, 0x10($sp)
/* 020F78 80045B78 3C10800A */  lui   $s0, 0x800a
/* 020F7C 80045B7C 26100BC0 */  addiu $s0, $s0, 0xbc0
/* 020F80 80045B80 AFBF0018 */  sw    $ra, 0x18($sp)
.L80045B84:
/* 020F84 80045B84 86020010 */  lh    $v0, 0x10($s0)
/* 020F88 80045B88 50400007 */  beql  $v0, $zero, .L80045BA8
/* 020F8C 80045B8C 26310001 */   addiu $s1, $s1, 1
/* 020F90 80045B90 8E020004 */  lw    $v0, 4($s0)
/* 020F94 80045B94 50400004 */  beql  $v0, $zero, .L80045BA8
/* 020F98 80045B98 26310001 */   addiu $s1, $s1, 1
/* 020F9C 80045B9C 0040F809 */  jalr  $v0
/* 020FA0 80045BA0 0200202D */  daddu $a0, $s0, $zero
/* 020FA4 80045BA4 26310001 */  addiu $s1, $s1, 1
.L80045BA8:
/* 020FA8 80045BA8 2A220020 */  slti  $v0, $s1, 0x20
/* 020FAC 80045BAC 1440FFF5 */  bnez  $v0, .L80045B84
/* 020FB0 80045BB0 2610001C */   addiu $s0, $s0, 0x1c
/* 020FB4 80045BB4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 020FB8 80045BB8 8FB10014 */  lw    $s1, 0x14($sp)
/* 020FBC 80045BBC 8FB00010 */  lw    $s0, 0x10($sp)
/* 020FC0 80045BC0 03E00008 */  jr    $ra
/* 020FC4 80045BC4 27BD0020 */   addiu $sp, $sp, 0x20

/* 020FC8 80045BC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020FCC 80045BCC AFB10014 */  sw    $s1, 0x14($sp)
/* 020FD0 80045BD0 0000882D */  daddu $s1, $zero, $zero
/* 020FD4 80045BD4 AFB00010 */  sw    $s0, 0x10($sp)
/* 020FD8 80045BD8 3C10800A */  lui   $s0, 0x800a
/* 020FDC 80045BDC 26100BC0 */  addiu $s0, $s0, 0xbc0
/* 020FE0 80045BE0 AFBF0018 */  sw    $ra, 0x18($sp)
.L80045BE4:
/* 020FE4 80045BE4 86020010 */  lh    $v0, 0x10($s0)
/* 020FE8 80045BE8 50400007 */  beql  $v0, $zero, .L80045C08
/* 020FEC 80045BEC 26310001 */   addiu $s1, $s1, 1
/* 020FF0 80045BF0 8E020008 */  lw    $v0, 8($s0)
/* 020FF4 80045BF4 50400004 */  beql  $v0, $zero, .L80045C08
/* 020FF8 80045BF8 26310001 */   addiu $s1, $s1, 1
/* 020FFC 80045BFC 0040F809 */  jalr  $v0
/* 021000 80045C00 0200202D */  daddu $a0, $s0, $zero
/* 021004 80045C04 26310001 */  addiu $s1, $s1, 1
.L80045C08:
/* 021008 80045C08 2A220020 */  slti  $v0, $s1, 0x20
/* 02100C 80045C0C 1440FFF5 */  bnez  $v0, .L80045BE4
/* 021010 80045C10 2610001C */   addiu $s0, $s0, 0x1c
/* 021014 80045C14 8FBF0018 */  lw    $ra, 0x18($sp)
/* 021018 80045C18 8FB10014 */  lw    $s1, 0x14($sp)
/* 02101C 80045C1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 021020 80045C20 03E00008 */  jr    $ra
/* 021024 80045C24 27BD0020 */   addiu $sp, $sp, 0x20

