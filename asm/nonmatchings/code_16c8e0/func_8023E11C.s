.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8023E11C
/* 16C9FC 8023E11C 3C018028 */  lui   $at, 0x8028
/* 16CA00 8023E120 A02009F4 */  sb    $zero, 0x9f4($at)
/* 16CA04 8023E124 3C018028 */  lui   $at, 0x8028
/* 16CA08 8023E128 03E00008 */  jr    $ra
/* 16CA0C 8023E12C A02009F5 */   sb    $zero, 0x9f5($at)

