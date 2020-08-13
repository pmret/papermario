.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E0B38
/* 079FE8 800E0B38 3C028007 */  lui   $v0, 0x8007
/* 079FEC 800E0B3C 8C42419C */  lw    $v0, 0x419c($v0)
/* 079FF0 800E0B40 80420070 */  lb    $v0, 0x70($v0)
/* 079FF4 800E0B44 3C048011 */  lui   $a0, 0x8011
/* 079FF8 800E0B48 2484F290 */  addiu $a0, $a0, -0xd70
/* 079FFC 800E0B4C 1440000E */  bnez  $v0, .L800E0B88
/* 07A000 800E0B50 24050001 */   addiu $a1, $zero, 1
/* 07A004 800E0B54 24830004 */  addiu $v1, $a0, 4
/* 07A008 800E0B58 24840008 */  addiu $a0, $a0, 8
.L800E0B5C:
/* 07A00C 800E0B5C 90820014 */  lbu   $v0, 0x14($a0)
/* 07A010 800E0B60 50400005 */  beql  $v0, $zero, .L800E0B78
/* 07A014 800E0B64 24630004 */   addiu $v1, $v1, 4
/* 07A018 800E0B68 8C6202C4 */  lw    $v0, 0x2c4($v1)
/* 07A01C 800E0B6C 24420001 */  addiu $v0, $v0, 1
/* 07A020 800E0B70 AC6202C4 */  sw    $v0, 0x2c4($v1)
/* 07A024 800E0B74 24630004 */  addiu $v1, $v1, 4
.L800E0B78:
/* 07A028 800E0B78 24A50001 */  addiu $a1, $a1, 1
/* 07A02C 800E0B7C 28A2000C */  slti  $v0, $a1, 0xc
/* 07A030 800E0B80 1440FFF6 */  bnez  $v0, .L800E0B5C
/* 07A034 800E0B84 24840008 */   addiu $a0, $a0, 8
.L800E0B88:
/* 07A038 800E0B88 03E00008 */  jr    $ra
/* 07A03C 800E0B8C 00000000 */   nop   

