.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "globals.inc"

func_80027190:
/* 002590 80027190 3C02800A */  lui   $v0, 0x800a
/* 002594 80027194 8C42A5D8 */  lw    $v0, -0x5a28($v0)
/* 002598 80027198 03E00008 */  jr    $ra
/* 00259C 8002719C 00000000 */   nop   

.set reorder
