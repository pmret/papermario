.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8023E104
/* 16C9E4 8023E104 24020001 */  addiu $v0, $zero, 1
/* 16C9E8 8023E108 3C018028 */  lui   $at, 0x8028
/* 16C9EC 8023E10C A02209F4 */  sb    $v0, 0x9f4($at)
/* 16C9F0 8023E110 3C018028 */  lui   $at, 0x8028
/* 16C9F4 8023E114 03E00008 */  jr    $ra
/* 16C9F8 8023E118 A02009F5 */   sb    $zero, 0x9f5($at)

