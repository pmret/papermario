.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802DBD8C
/* 0FEE7C 802DBD8C 3C02802E */  lui   $v0, 0x802e
/* 0FEE80 802DBD90 2442FE48 */  addiu $v0, $v0, -0x1b8
/* 0FEE84 802DBD94 00041880 */  sll   $v1, $a0, 2
/* 0FEE88 802DBD98 00621821 */  addu  $v1, $v1, $v0
/* 0FEE8C 802DBD9C 8C620000 */  lw    $v0, ($v1)
/* 0FEE90 802DBDA0 3442001F */  ori   $v0, $v0, 0x1f
/* 0FEE94 802DBDA4 AC620000 */  sw    $v0, ($v1)
/* 0FEE98 802DBDA8 3C02802E */  lui   $v0, 0x802e
/* 0FEE9C 802DBDAC 8C42FE44 */  lw    $v0, -0x1bc($v0)
/* 0FEEA0 802DBDB0 00042180 */  sll   $a0, $a0, 6
/* 0FEEA4 802DBDB4 03E00008 */  jr    $ra
/* 0FEEA8 802DBDB8 00441021 */   addu  $v0, $v0, $a0

