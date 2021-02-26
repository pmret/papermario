.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C6C0
/* 47AC0 8006C6C0 3C02A404 */  lui       $v0, 0xa404
/* 47AC4 8006C6C4 34420010 */  ori       $v0, $v0, 0x10
/* 47AC8 8006C6C8 03E00008 */  jr        $ra
/* 47ACC 8006C6CC 8C420000 */   lw       $v0, ($v0)
