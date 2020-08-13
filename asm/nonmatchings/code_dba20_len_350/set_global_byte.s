.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_global_byte
/* 0DBC20 80145520 3C02800E */  lui   $v0, 0x800e
/* 0DBC24 80145524 2442ACC0 */  addiu $v0, $v0, -0x5340
/* 0DBC28 80145528 00822021 */  addu  $a0, $a0, $v0
/* 0DBC2C 8014552C 808210B0 */  lb    $v0, 0x10b0($a0)
/* 0DBC30 80145530 03E00008 */  jr    $ra
/* 0DBC34 80145534 A08510B0 */   sb    $a1, 0x10b0($a0)

