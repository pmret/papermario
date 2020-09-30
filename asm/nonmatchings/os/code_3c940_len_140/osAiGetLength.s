.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osAiGetLength
/* 3C940 80061540 3C02A450 */  lui       $v0, 0xa450
/* 3C944 80061544 34420004 */  ori       $v0, $v0, 4
/* 3C948 80061548 03E00008 */  jr        $ra
/* 3C94C 8006154C 8C420000 */   lw       $v0, ($v0)
