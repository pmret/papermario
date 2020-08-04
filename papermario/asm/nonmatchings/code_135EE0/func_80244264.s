.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80244264
/* 1375A4 80244264 24050001 */   addiu $a1, $zero, 1
/* 1375A8 80244268 0C05272D */  jal   play_sound
/* 1375AC 8024426C 24040009 */   addiu $a0, $zero, 9
.L80244270:
/* 1375B0 80244270 2404002C */  addiu $a0, $zero, 0x2c
/* 1375B4 80244274 0C051F5C */  jal   func_80147D70
/* 1375B8 80244278 24050040 */   addiu $a1, $zero, 0x40
/* 1375BC 8024427C 8FBF0028 */  lw    $ra, 0x28($sp)
/* 1375C0 80244280 8FB50024 */  lw    $s5, 0x24($sp)
/* 1375C4 80244284 8FB40020 */  lw    $s4, 0x20($sp)
/* 1375C8 80244288 8FB3001C */  lw    $s3, 0x1c($sp)
