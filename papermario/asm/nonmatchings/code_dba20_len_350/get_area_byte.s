.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_area_byte
/* 0DBD50 80145650 3C02800E */  lui   $v0, 0x800e
/* 0DBD54 80145654 00441021 */  addu  $v0, $v0, $a0
/* 0DBD58 80145658 8042BF90 */  lb    $v0, -0x4070($v0)
/* 0DBD5C 8014565C 03E00008 */  jr    $ra
/* 0DBD60 80145660 00000000 */   nop   

/* 0DBD64 80145664 00000000 */  nop   
/* 0DBD68 80145668 00000000 */  nop   
/* 0DBD6C 8014566C 00000000 */  nop   

.set reorder
