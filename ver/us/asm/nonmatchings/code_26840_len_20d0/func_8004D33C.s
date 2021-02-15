.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D33C
/* 2873C 8004D33C 8CA20000 */  lw        $v0, ($a1)
/* 28740 8004D340 90430000 */  lbu       $v1, ($v0)
/* 28744 8004D344 24420001 */  addiu     $v0, $v0, 1
/* 28748 8004D348 ACA20000 */  sw        $v0, ($a1)
/* 2874C 8004D34C 03E00008 */  jr        $ra
/* 28750 8004D350 A0A300A2 */   sb       $v1, 0xa2($a1)
