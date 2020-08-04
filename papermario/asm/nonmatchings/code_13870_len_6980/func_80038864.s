.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80038864
/* 013C64 80038864 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 013C68 80038868 AFBF0010 */  sw    $ra, 0x10($sp)
/* 013C6C 8003886C 0C00E166 */  jal   func_80038598
/* 013C70 80038870 0000302D */   daddu $a2, $zero, $zero
/* 013C74 80038874 8FBF0010 */  lw    $ra, 0x10($sp)
/* 013C78 80038878 03E00008 */  jr    $ra
/* 013C7C 8003887C 27BD0018 */   addiu $sp, $sp, 0x18

