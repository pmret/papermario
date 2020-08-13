.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_area_byte
/* 0DBD38 80145638 3C02800E */  lui   $v0, 0x800e
/* 0DBD3C 8014563C 2442ACC0 */  addiu $v0, $v0, -0x5340
/* 0DBD40 80145640 00822021 */  addu  $a0, $a0, $v0
/* 0DBD44 80145644 808212D0 */  lb    $v0, 0x12d0($a0)
/* 0DBD48 80145648 03E00008 */  jr    $ra
/* 0DBD4C 8014564C A08512D0 */   sb    $a1, 0x12d0($a0)

