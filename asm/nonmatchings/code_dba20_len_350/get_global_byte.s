.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_global_byte
/* 0DBC38 80145538 3C02800E */  lui   $v0, 0x800e
/* 0DBC3C 8014553C 00441021 */  addu  $v0, $v0, $a0
/* 0DBC40 80145540 8042BD70 */  lb    $v0, -0x4290($v0)
/* 0DBC44 80145544 03E00008 */  jr    $ra
/* 0DBC48 80145548 00000000 */   nop   

