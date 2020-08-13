.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuSiMgrStop
/* 00838C 8002CF8C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 008390 8002CF90 24047F00 */  addiu $a0, $zero, 0x7f00
/* 008394 8002CF94 AFBF0010 */  sw    $ra, 0x10($sp)
/* 008398 8002CF98 0C00B3CA */  jal   nuSiSendMesg
/* 00839C 8002CF9C 0000282D */   daddu $a1, $zero, $zero
/* 0083A0 8002CFA0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0083A4 8002CFA4 03E00008 */  jr    $ra
/* 0083A8 8002CFA8 27BD0018 */   addiu $sp, $sp, 0x18

