.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800271A0
/* 0025A0 800271A0 3C04800A */  lui   $a0, 0x800a
/* 0025A4 800271A4 2484A66C */  addiu $a0, $a0, -0x5994
/* 0025A8 800271A8 8C830000 */  lw    $v1, ($a0)
/* 0025AC 800271AC 3C02DB06 */  lui   $v0, 0xdb06
/* 0025B0 800271B0 0060282D */  daddu $a1, $v1, $zero
/* 0025B4 800271B4 24630008 */  addiu $v1, $v1, 8
/* 0025B8 800271B8 AC830000 */  sw    $v1, ($a0)
/* 0025BC 800271BC ACA20000 */  sw    $v0, ($a1)
/* 0025C0 800271C0 24620008 */  addiu $v0, $v1, 8
/* 0025C4 800271C4 ACA00004 */  sw    $zero, 4($a1)
/* 0025C8 800271C8 3C05DE00 */  lui   $a1, 0xde00
/* 0025CC 800271CC AC820000 */  sw    $v0, ($a0)
/* 0025D0 800271D0 3C020007 */  lui   $v0, 7
/* 0025D4 800271D4 24424230 */  addiu $v0, $v0, 0x4230
/* 0025D8 800271D8 AC620004 */  sw    $v0, 4($v1)
/* 0025DC 800271DC 24620010 */  addiu $v0, $v1, 0x10
/* 0025E0 800271E0 AC650000 */  sw    $a1, ($v1)
/* 0025E4 800271E4 AC820000 */  sw    $v0, ($a0)
/* 0025E8 800271E8 3C020007 */  lui   $v0, 7
/* 0025EC 800271EC 24424210 */  addiu $v0, $v0, 0x4210
/* 0025F0 800271F0 AC650008 */  sw    $a1, 8($v1)
/* 0025F4 800271F4 03E00008 */  jr    $ra
/* 0025F8 800271F8 AC62000C */   sw    $v0, 0xc($v1)


