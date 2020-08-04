.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800559FC
/* 030DFC 800559FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 030E00 80055A00 AFBF0010 */  sw    $ra, 0x10($sp)
/* 030E04 80055A04 0C0136B8 */  jal   func_8004DAE0
/* 030E08 80055A08 00000000 */   nop   
/* 030E0C 80055A0C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 030E10 80055A10 03E00008 */  jr    $ra
/* 030E14 80055A14 27BD0018 */   addiu $sp, $sp, 0x18

