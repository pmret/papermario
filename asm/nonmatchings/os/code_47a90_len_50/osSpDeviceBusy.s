.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSpDeviceBusy
/* 47AC0 8006C6C0 3C02A404 */  lui       $v0, 0xa404
/* 47AC4 8006C6C4 34420010 */  ori       $v0, $v0, 0x10
/* 47AC8 8006C6C8 8C420000 */  lw        $v0, ($v0)
/* 47ACC 8006C6CC 3042001C */  andi      $v0, $v0, 0x1c
/* 47AD0 8006C6D0 03E00008 */  jr        $ra
/* 47AD4 8006C6D4 0002102B */   sltu     $v0, $zero, $v0
/* 47AD8 8006C6D8 00000000 */  nop       
/* 47ADC 8006C6DC 00000000 */  nop       
