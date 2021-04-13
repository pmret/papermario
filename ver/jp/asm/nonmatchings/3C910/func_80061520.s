.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061520
/* 3C920 80061520 3C02A450 */  lui       $v0, 0xa450
/* 3C924 80061524 3442000C */  ori       $v0, $v0, 0xc
/* 3C928 80061528 03E00008 */  jr        $ra
/* 3C92C 8006152C 8C420000 */   lw       $v0, ($v0)
