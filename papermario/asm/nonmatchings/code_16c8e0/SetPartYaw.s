.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetPartYaw
/* 199D18 8026B438 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199D1C 8026B43C AFB20018 */  sw    $s2, 0x18($sp)
/* 199D20 8026B440 0080902D */  daddu $s2, $a0, $zero
/* 199D24 8026B444 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199D28 8026B448 AFB10014 */  sw    $s1, 0x14($sp)
/* 199D2C 8026B44C AFB00010 */  sw    $s0, 0x10($sp)
/* 199D30 8026B450 8E50000C */  lw    $s0, 0xc($s2)
/* 199D34 8026B454 8E050000 */  lw    $a1, ($s0)
/* 199D38 8026B458 0C0B1EAF */  jal   get_variable
/* 199D3C 8026B45C 26100004 */   addiu $s0, $s0, 4
/* 199D40 8026B460 0040882D */  daddu $s1, $v0, $zero
/* 199D44 8026B464 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199D48 8026B468 16220002 */  bne   $s1, $v0, .L8026B474
/* 199D4C 8026B46C 00000000 */   nop   
/* 199D50 8026B470 8E510148 */  lw    $s1, 0x148($s2)
.L8026B474:
/* 199D54 8026B474 8E050000 */  lw    $a1, ($s0)
/* 199D58 8026B478 26100004 */  addiu $s0, $s0, 4
/* 199D5C 8026B47C 0C0B1EAF */  jal   get_variable
/* 199D60 8026B480 0240202D */   daddu $a0, $s2, $zero
/* 199D64 8026B484 0240202D */  daddu $a0, $s2, $zero
/* 199D68 8026B488 8E050000 */  lw    $a1, ($s0)
/* 199D6C 8026B48C 0C0B1EAF */  jal   get_variable
/* 199D70 8026B490 0040802D */   daddu $s0, $v0, $zero
/* 199D74 8026B494 0220202D */  daddu $a0, $s1, $zero
/* 199D78 8026B498 0200282D */  daddu $a1, $s0, $zero
/* 199D7C 8026B49C 0C098FE7 */  jal   set_part_yaw
/* 199D80 8026B4A0 0040302D */   daddu $a2, $v0, $zero
/* 199D84 8026B4A4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199D88 8026B4A8 8FB20018 */  lw    $s2, 0x18($sp)
/* 199D8C 8026B4AC 8FB10014 */  lw    $s1, 0x14($sp)
/* 199D90 8026B4B0 8FB00010 */  lw    $s0, 0x10($sp)
/* 199D94 8026B4B4 24020002 */  addiu $v0, $zero, 2
/* 199D98 8026B4B8 03E00008 */  jr    $ra
/* 199D9C 8026B4BC 27BD0020 */   addiu $sp, $sp, 0x20

