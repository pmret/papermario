.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSpDeviceBusy
/* 047AC0 8006C6C0 3C02A404 */  lui   $v0, 0xa404
/* 047AC4 8006C6C4 34420010 */  ori   $v0, $v0, 0x10
/* 047AC8 8006C6C8 8C420000 */  lw    $v0, ($v0)
/* 047ACC 8006C6CC 3042001C */  andi  $v0, $v0, 0x1c
/* 047AD0 8006C6D0 03E00008 */  jr    $ra
/* 047AD4 8006C6D4 0002102B */   sltu  $v0, $zero, $v0

/* 047AD8 8006C6D8 00000000 */  nop   
/* 047ADC 8006C6DC 00000000 */  nop   


