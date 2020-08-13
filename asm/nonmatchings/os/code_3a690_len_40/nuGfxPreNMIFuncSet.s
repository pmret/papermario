.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuGfxPreNMIFuncSet
/* 03A690 8005F290 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03A694 8005F294 AFB00010 */  sw    $s0, 0x10($sp)
/* 03A698 8005F298 0080802D */  daddu $s0, $a0, $zero
/* 03A69C 8005F29C AFBF0014 */  sw    $ra, 0x14($sp)
/* 03A6A0 8005F2A0 0C018250 */  jal   osSetIntMask
/* 03A6A4 8005F2A4 24040001 */   addiu $a0, $zero, 1
/* 03A6A8 8005F2A8 3C018009 */  lui   $at, 0x8009
/* 03A6AC 8005F2AC AC303D14 */  sw    $s0, 0x3d14($at)
/* 03A6B0 8005F2B0 0C018250 */  jal   osSetIntMask
/* 03A6B4 8005F2B4 0040202D */   daddu $a0, $v0, $zero
/* 03A6B8 8005F2B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03A6BC 8005F2BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 03A6C0 8005F2C0 03E00008 */  jr    $ra
/* 03A6C4 8005F2C4 27BD0018 */   addiu $sp, $sp, 0x18

/* 03A6C8 8005F2C8 00000000 */  nop   
/* 03A6CC 8005F2CC 00000000 */  nop   


