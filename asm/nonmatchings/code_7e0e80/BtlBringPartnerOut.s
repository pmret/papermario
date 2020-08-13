.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel BtlBringPartnerOut
/* 7E19EC 80280B6C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 7E19F0 80280B70 03E00008 */  jr    $ra
/* 7E19F4 80280B74 27BD0018 */   addiu $sp, $sp, 0x18

