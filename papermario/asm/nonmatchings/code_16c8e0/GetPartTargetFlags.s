.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartTargetFlags
/* 19BB8C 8026D2AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19BB90 8026D2B0 AFB20018 */  sw    $s2, 0x18($sp)
/* 19BB94 8026D2B4 0080902D */  daddu $s2, $a0, $zero
/* 19BB98 8026D2B8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19BB9C 8026D2BC AFB10014 */  sw    $s1, 0x14($sp)
/* 19BBA0 8026D2C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19BBA4 8026D2C4 8E51000C */  lw    $s1, 0xc($s2)
/* 19BBA8 8026D2C8 8E250000 */  lw    $a1, ($s1)
/* 19BBAC 8026D2CC 0C0B1EAF */  jal   get_variable
/* 19BBB0 8026D2D0 26310004 */   addiu $s1, $s1, 4
/* 19BBB4 8026D2D4 0040802D */  daddu $s0, $v0, $zero
/* 19BBB8 8026D2D8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19BBBC 8026D2DC 16020002 */  bne   $s0, $v0, .L8026D2E8
/* 19BBC0 8026D2E0 00000000 */   nop   
/* 19BBC4 8026D2E4 8E500148 */  lw    $s0, 0x148($s2)
.L8026D2E8:
/* 19BBC8 8026D2E8 8E250000 */  lw    $a1, ($s1)
/* 19BBCC 8026D2EC 26310004 */  addiu $s1, $s1, 4
/* 19BBD0 8026D2F0 0C0B1EAF */  jal   get_variable
/* 19BBD4 8026D2F4 0240202D */   daddu $a0, $s2, $zero
/* 19BBD8 8026D2F8 0200202D */  daddu $a0, $s0, $zero
/* 19BBDC 8026D2FC 8E310000 */  lw    $s1, ($s1)
/* 19BBE0 8026D300 0C09A75B */  jal   get_actor
/* 19BBE4 8026D304 0040802D */   daddu $s0, $v0, $zero
/* 19BBE8 8026D308 0040202D */  daddu $a0, $v0, $zero
/* 19BBEC 8026D30C 0C099117 */  jal   get_actor_part
/* 19BBF0 8026D310 0200282D */   daddu $a1, $s0, $zero
/* 19BBF4 8026D314 0240202D */  daddu $a0, $s2, $zero
/* 19BBF8 8026D318 8C460004 */  lw    $a2, 4($v0)
/* 19BBFC 8026D31C 0C0B2026 */  jal   set_variable
/* 19BC00 8026D320 0220282D */   daddu $a1, $s1, $zero
/* 19BC04 8026D324 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19BC08 8026D328 8FB20018 */  lw    $s2, 0x18($sp)
/* 19BC0C 8026D32C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19BC10 8026D330 8FB00010 */  lw    $s0, 0x10($sp)
/* 19BC14 8026D334 24020002 */  addiu $v0, $zero, 2
/* 19BC18 8026D338 03E00008 */  jr    $ra
/* 19BC1C 8026D33C 27BD0020 */   addiu $sp, $sp, 0x20

