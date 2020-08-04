.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GotoMap
/* 0EEDB0 802CA400 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEDB4 802CA404 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEDB8 802CA408 0C0B28C1 */  jal   goto_map
/* 0EEDBC 802CA40C 0000282D */   daddu $a1, $zero, $zero
/* 0EEDC0 802CA410 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEDC4 802CA414 24020001 */  addiu $v0, $zero, 1
/* 0EEDC8 802CA418 03E00008 */  jr    $ra
/* 0EEDCC 802CA41C 27BD0018 */   addiu $sp, $sp, 0x18

