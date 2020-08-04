.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E97E4
/* 082C94 800E97E4 3C028011 */  lui   $v0, 0x8011
/* 082C98 800E97E8 2442EF58 */  addiu $v0, $v0, -0x10a8
/* 082C9C 800E97EC 2403FF9C */  addiu $v1, $zero, -0x64
/* 082CA0 800E97F0 A4430036 */  sh    $v1, 0x36($v0)
/* 082CA4 800E97F4 24030001 */  addiu $v1, $zero, 1
/* 082CA8 800E97F8 A0400044 */  sb    $zero, 0x44($v0)
/* 082CAC 800E97FC A4400038 */  sh    $zero, 0x38($v0)
/* 082CB0 800E9800 A043003A */  sb    $v1, 0x3a($v0)
/* 082CB4 800E9804 A040003B */  sb    $zero, 0x3b($v0)
/* 082CB8 800E9808 03E00008 */  jr    $ra
/* 082CBC 800E980C A040003C */   sb    $zero, 0x3c($v0)

