.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuSiMgrRestart
/* 0083AC 8002CFAC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0083B0 8002CFB0 3C04800A */  lui   $a0, 0x800a
/* 0083B4 8002CFB4 2484E710 */  addiu $a0, $a0, -0x18f0
/* 0083B8 8002CFB8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0083BC 8002CFBC 0C019808 */  jal   osStartThread
/* 0083C0 8002CFC0 00000000 */   nop   
/* 0083C4 8002CFC4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0083C8 8002CFC8 03E00008 */  jr    $ra
/* 0083CC 8002CFCC 27BD0018 */   addiu $sp, $sp, 0x18

