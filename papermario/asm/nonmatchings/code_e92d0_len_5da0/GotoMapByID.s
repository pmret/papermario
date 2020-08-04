.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GotoMapByID
/* 0EEDF0 802CA440 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEDF4 802CA444 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEDF8 802CA448 0C0B28C1 */  jal   goto_map
/* 0EEDFC 802CA44C 24050002 */   addiu $a1, $zero, 2
/* 0EEE00 802CA450 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEE04 802CA454 24020001 */  addiu $v0, $zero, 1
/* 0EEE08 802CA458 03E00008 */  jr    $ra
/* 0EEE0C 802CA45C 27BD0018 */   addiu $sp, $sp, 0x18

