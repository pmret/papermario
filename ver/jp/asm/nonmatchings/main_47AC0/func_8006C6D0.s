.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C6D0
/* 47AD0 8006C6D0 3C02A404 */  lui       $v0, 0xa404
/* 47AD4 8006C6D4 34420010 */  ori       $v0, $v0, 0x10
/* 47AD8 8006C6D8 03E00008 */  jr        $ra
/* 47ADC 8006C6DC AC440000 */   sw       $a0, ($v0)
