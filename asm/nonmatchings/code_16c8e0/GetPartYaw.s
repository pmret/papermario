.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartYaw
/* 199DA0 8026B4C0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199DA4 8026B4C4 AFB20018 */  sw    $s2, 0x18($sp)
/* 199DA8 8026B4C8 0080902D */  daddu $s2, $a0, $zero
/* 199DAC 8026B4CC AFBF001C */  sw    $ra, 0x1c($sp)
/* 199DB0 8026B4D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 199DB4 8026B4D4 AFB00010 */  sw    $s0, 0x10($sp)
/* 199DB8 8026B4D8 8E51000C */  lw    $s1, 0xc($s2)
/* 199DBC 8026B4DC 8E250000 */  lw    $a1, ($s1)
/* 199DC0 8026B4E0 0C0B1EAF */  jal   get_variable
/* 199DC4 8026B4E4 26310004 */   addiu $s1, $s1, 4
/* 199DC8 8026B4E8 0040802D */  daddu $s0, $v0, $zero
/* 199DCC 8026B4EC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199DD0 8026B4F0 16020002 */  bne   $s0, $v0, .L8026B4FC
/* 199DD4 8026B4F4 00000000 */   nop   
/* 199DD8 8026B4F8 8E500148 */  lw    $s0, 0x148($s2)
.L8026B4FC:
/* 199DDC 8026B4FC 8E250000 */  lw    $a1, ($s1)
/* 199DE0 8026B500 26310004 */  addiu $s1, $s1, 4
/* 199DE4 8026B504 0C0B1EAF */  jal   get_variable
/* 199DE8 8026B508 0240202D */   daddu $a0, $s2, $zero
/* 199DEC 8026B50C 0200202D */  daddu $a0, $s0, $zero
/* 199DF0 8026B510 8E310000 */  lw    $s1, ($s1)
/* 199DF4 8026B514 0C09A75B */  jal   get_actor
/* 199DF8 8026B518 0040802D */   daddu $s0, $v0, $zero
/* 199DFC 8026B51C 0040202D */  daddu $a0, $v0, $zero
/* 199E00 8026B520 0C099117 */  jal   get_actor_part
/* 199E04 8026B524 0200282D */   daddu $a1, $s0, $zero
/* 199E08 8026B528 0240202D */  daddu $a0, $s2, $zero
/* 199E0C 8026B52C C4400064 */  lwc1  $f0, 0x64($v0)
/* 199E10 8026B530 4600008D */  trunc.w.s $f2, $f0
/* 199E14 8026B534 44061000 */  mfc1  $a2, $f2
/* 199E18 8026B538 0C0B2026 */  jal   set_variable
/* 199E1C 8026B53C 0220282D */   daddu $a1, $s1, $zero
/* 199E20 8026B540 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199E24 8026B544 8FB20018 */  lw    $s2, 0x18($sp)
/* 199E28 8026B548 8FB10014 */  lw    $s1, 0x14($sp)
/* 199E2C 8026B54C 8FB00010 */  lw    $s0, 0x10($sp)
/* 199E30 8026B550 24020002 */  addiu $v0, $zero, 2
/* 199E34 8026B554 03E00008 */  jr    $ra
/* 199E38 8026B558 27BD0020 */   addiu $sp, $sp, 0x20

