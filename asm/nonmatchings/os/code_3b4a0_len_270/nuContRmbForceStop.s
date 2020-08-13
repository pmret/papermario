.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuContRmbForceStop
/* 03B4A0 800600A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B4A4 800600A4 24040304 */  addiu $a0, $zero, 0x304
/* 03B4A8 800600A8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B4AC 800600AC 0C00B3CA */  jal   nuSiSendMesg
/* 03B4B0 800600B0 0000282D */   daddu $a1, $zero, $zero
/* 03B4B4 800600B4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B4B8 800600B8 03E00008 */  jr    $ra
/* 03B4BC 800600BC 27BD0018 */   addiu $sp, $sp, 0x18

