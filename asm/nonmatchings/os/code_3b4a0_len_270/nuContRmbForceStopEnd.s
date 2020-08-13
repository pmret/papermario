.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuContRmbForceStopEnd
/* 03B4C0 800600C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B4C4 800600C4 24040305 */  addiu $a0, $zero, 0x305
/* 03B4C8 800600C8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B4CC 800600CC 0C00B3CA */  jal   nuSiSendMesg
/* 03B4D0 800600D0 0000282D */   daddu $a1, $zero, $zero
/* 03B4D4 800600D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B4D8 800600D8 03E00008 */  jr    $ra
/* 03B4DC 800600DC 27BD0018 */   addiu $sp, $sp, 0x18

