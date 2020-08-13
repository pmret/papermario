.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel mem_clear
/* 004A00 80029600 18A00005 */  blez  $a1, .L80029618
/* 004A04 80029604 00000000 */   nop   
.L80029608:
/* 004A08 80029608 A0800000 */  sb    $zero, ($a0)
/* 004A0C 8002960C 24A5FFFF */  addiu $a1, $a1, -1
/* 004A10 80029610 1CA0FFFD */  bgtz  $a1, .L80029608
/* 004A14 80029614 24840001 */   addiu $a0, $a0, 1
.L80029618:
/* 004A18 80029618 03E00008 */  jr    $ra
/* 004A1C 8002961C 00000000 */   nop   

