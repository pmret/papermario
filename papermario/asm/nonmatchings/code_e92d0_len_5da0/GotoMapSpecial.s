.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GotoMapSpecial
/* 0EEDD0 802CA420 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEDD4 802CA424 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEDD8 802CA428 0C0B28C1 */  jal   goto_map
/* 0EEDDC 802CA42C 24050001 */   addiu $a1, $zero, 1
/* 0EEDE0 802CA430 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEDE4 802CA434 24020001 */  addiu $v0, $zero, 1
/* 0EEDE8 802CA438 03E00008 */  jr    $ra
/* 0EEDEC 802CA43C 27BD0018 */   addiu $sp, $sp, 0x18

