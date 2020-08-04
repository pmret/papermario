.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055ABC
/* 030EBC 80055ABC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030EC0 80055AC0 AFA40010 */  sw    $a0, 0x10($sp)
/* 030EC4 80055AC4 27A40010 */  addiu $a0, $sp, 0x10
/* 030EC8 80055AC8 AFBF0030 */  sw    $ra, 0x30($sp)
/* 030ECC 80055ACC AFA50014 */  sw    $a1, 0x14($sp)
/* 030ED0 80055AD0 AFA00018 */  sw    $zero, 0x18($sp)
/* 030ED4 80055AD4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 030ED8 80055AD8 AFA60020 */  sw    $a2, 0x20($sp)
/* 030EDC 80055ADC 0C0136D3 */  jal   func_8004DB4C
/* 030EE0 80055AE0 AFA00024 */   sw    $zero, 0x24($sp)
/* 030EE4 80055AE4 8FBF0030 */  lw    $ra, 0x30($sp)
/* 030EE8 80055AE8 03E00008 */  jr    $ra
/* 030EEC 80055AEC 27BD0038 */   addiu $sp, $sp, 0x38

