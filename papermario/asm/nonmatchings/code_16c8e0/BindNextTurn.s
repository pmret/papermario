.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel BindNextTurn
/* 1A7574 80278C94 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A7578 80278C98 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A757C 80278C9C 0080902D */  daddu $s2, $a0, $zero
/* 1A7580 80278CA0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A7584 80278CA4 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A7588 80278CA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A758C 80278CAC 8E51000C */  lw    $s1, 0xc($s2)
/* 1A7590 80278CB0 8E250000 */  lw    $a1, ($s1)
/* 1A7594 80278CB4 0C0B1EAF */  jal   get_variable
/* 1A7598 80278CB8 26310004 */   addiu $s1, $s1, 4
/* 1A759C 80278CBC 0040802D */  daddu $s0, $v0, $zero
/* 1A75A0 80278CC0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A75A4 80278CC4 16020002 */  bne   $s0, $v0, .L80278CD0
/* 1A75A8 80278CC8 00000000 */   nop   
/* 1A75AC 80278CCC 8E500148 */  lw    $s0, 0x148($s2)
.L80278CD0:
/* 1A75B0 80278CD0 8E250000 */  lw    $a1, ($s1)
/* 1A75B4 80278CD4 0C0B1EAF */  jal   get_variable
/* 1A75B8 80278CD8 0240202D */   daddu $a0, $s2, $zero
/* 1A75BC 80278CDC 0200202D */  daddu $a0, $s0, $zero
/* 1A75C0 80278CE0 0C09A75B */  jal   get_actor
/* 1A75C4 80278CE4 0040802D */   daddu $s0, $v0, $zero
/* 1A75C8 80278CE8 AC5001CC */  sw    $s0, 0x1cc($v0)
/* 1A75CC 80278CEC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A75D0 80278CF0 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A75D4 80278CF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A75D8 80278CF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A75DC 80278CFC 24020002 */  addiu $v0, $zero, 2
/* 1A75E0 80278D00 03E00008 */  jr    $ra
/* 1A75E4 80278D04 27BD0020 */   addiu $sp, $sp, 0x20

