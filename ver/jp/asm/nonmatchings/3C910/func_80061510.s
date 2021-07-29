.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061510
/* 3C910 80061510 3C02A450 */  lui       $v0, 0xa450
/* 3C914 80061514 34420004 */  ori       $v0, $v0, 4
/* 3C918 80061518 03E00008 */  jr        $ra
/* 3C91C 8006151C 8C420000 */   lw       $v0, ($v0)
