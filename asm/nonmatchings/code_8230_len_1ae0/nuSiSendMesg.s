.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuSiSendMesg
/* 008328 8002CF28 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 00832C 8002CF2C AFB00040 */  sw    $s0, 0x40($sp)
/* 008330 8002CF30 27B00010 */  addiu $s0, $sp, 0x10
/* 008334 8002CF34 A7A40028 */  sh    $a0, 0x28($sp)
/* 008338 8002CF38 0200202D */  daddu $a0, $s0, $zero
/* 00833C 8002CF3C AFA50034 */  sw    $a1, 0x34($sp)
/* 008340 8002CF40 27A50038 */  addiu $a1, $sp, 0x38
/* 008344 8002CF44 24060001 */  addiu $a2, $zero, 1
/* 008348 8002CF48 AFBF0044 */  sw    $ra, 0x44($sp)
/* 00834C 8002CF4C 0C019560 */  jal   osCreateMesgQueue
/* 008350 8002CF50 AFB0002C */   sw    $s0, 0x2c($sp)
/* 008354 8002CF54 3C04800E */  lui   $a0, 0x800e
/* 008358 8002CF58 248491F8 */  addiu $a0, $a0, -0x6e08
/* 00835C 8002CF5C 27A50028 */  addiu $a1, $sp, 0x28
/* 008360 8002CF60 0C019608 */  jal   osSendMesg
/* 008364 8002CF64 24060001 */   addiu $a2, $zero, 1
/* 008368 8002CF68 0200202D */  daddu $a0, $s0, $zero
/* 00836C 8002CF6C 0000282D */  daddu $a1, $zero, $zero
/* 008370 8002CF70 0C0195BC */  jal   osRecvMesg
/* 008374 8002CF74 24060001 */   addiu $a2, $zero, 1
/* 008378 8002CF78 8FA20030 */  lw    $v0, 0x30($sp)
/* 00837C 8002CF7C 8FBF0044 */  lw    $ra, 0x44($sp)
/* 008380 8002CF80 8FB00040 */  lw    $s0, 0x40($sp)
/* 008384 8002CF84 03E00008 */  jr    $ra
/* 008388 8002CF88 27BD0048 */   addiu $sp, $sp, 0x48

