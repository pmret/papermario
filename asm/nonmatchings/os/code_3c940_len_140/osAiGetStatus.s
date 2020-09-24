.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osAiGetStatus
/* 3C950 80061550 3C02A450 */  lui       $v0, 0xa450
/* 3C954 80061554 3442000C */  ori       $v0, $v0, 0xc
/* 3C958 80061558 03E00008 */  jr        $ra
/* 3C95C 8006155C 8C420000 */   lw       $v0, ($v0)
