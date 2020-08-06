.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel collision_heap_malloc
/* 0061B0 8002ADB0 3C028007 */  lui   $v0, 0x8007
/* 0061B4 8002ADB4 8C42419C */  lw    $v0, 0x419c($v0)
/* 0061B8 8002ADB8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0061BC 8002ADBC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0061C0 8002ADC0 80420070 */  lb    $v0, 0x70($v0)
/* 0061C4 8002ADC4 0080282D */  daddu $a1, $a0, $zero
/* 0061C8 8002ADC8 3C048027 */  lui   $a0, 0x8027
/* 0061CC 8002ADCC 24848000 */  addiu $a0, $a0, -0x8000
/* 0061D0 8002ADD0 10400003 */  beqz  $v0, .L8002ADE0
/* 0061D4 8002ADD4 00000000 */   nop   
/* 0061D8 8002ADD8 3C04803E */  lui   $a0, 0x803e
/* 0061DC 8002ADDC 2484A800 */  addiu $a0, $a0, -0x5800
.L8002ADE0:
/* 0061E0 8002ADE0 0C00A41B */  jal   _heap_malloc
/* 0061E4 8002ADE4 00000000 */   nop   
/* 0061E8 8002ADE8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0061EC 8002ADEC 03E00008 */  jr    $ra
/* 0061F0 8002ADF0 27BD0018 */   addiu $sp, $sp, 0x18


