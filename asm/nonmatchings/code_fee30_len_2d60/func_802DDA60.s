.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DDA60
/* 100B50 802DDA60 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 100B54 802DDA64 AFBF0010 */  sw    $ra, 0x10($sp)
/* 100B58 802DDA68 0C0B7BED */  jal   func_802DEFB4
/* 100B5C 802DDA6C 00000000 */   nop   
/* 100B60 802DDA70 0C0B6FF0 */  jal   func_802DBFC0
/* 100B64 802DDA74 00000000 */   nop   
/* 100B68 802DDA78 8FBF0010 */  lw    $ra, 0x10($sp)
/* 100B6C 802DDA7C 03E00008 */  jr    $ra
/* 100B70 802DDA80 27BD0018 */   addiu $sp, $sp, 0x18

/* 100B74 802DDA84 03E00008 */  jr    $ra
/* 100B78 802DDA88 0000102D */   daddu $v0, $zero, $zero

