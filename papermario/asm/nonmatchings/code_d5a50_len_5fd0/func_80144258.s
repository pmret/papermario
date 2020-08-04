.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80144258
/* 0DA958 80144258 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DA95C 8014425C 24050001 */  addiu $a1, $zero, 1
/* 0DA960 80144260 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0DA964 80144264 0C050F12 */  jal   func_80143C48
/* 0DA968 80144268 00A0302D */   daddu $a2, $a1, $zero
/* 0DA96C 8014426C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0DA970 80144270 03E00008 */  jr    $ra
/* 0DA974 80144274 27BD0018 */   addiu $sp, $sp, 0x18

