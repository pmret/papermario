.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel BindNpcHit
/* 020540 80045140 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 020544 80045144 AFB10014 */  sw    $s1, 0x14($sp)
/* 020548 80045148 0080882D */  daddu $s1, $a0, $zero
/* 02054C 8004514C AFBF0020 */  sw    $ra, 0x20($sp)
/* 020550 80045150 AFB3001C */  sw    $s3, 0x1c($sp)
/* 020554 80045154 AFB20018 */  sw    $s2, 0x18($sp)
/* 020558 80045158 AFB00010 */  sw    $s0, 0x10($sp)
/* 02055C 8004515C 8E30000C */  lw    $s0, 0xc($s1)
/* 020560 80045160 8E330148 */  lw    $s3, 0x148($s1)
/* 020564 80045164 8E050000 */  lw    $a1, ($s0)
/* 020568 80045168 0C0B1EAF */  jal   get_variable
/* 02056C 8004516C 26100004 */   addiu $s0, $s0, 4
/* 020570 80045170 0040902D */  daddu $s2, $v0, $zero
/* 020574 80045174 8E050000 */  lw    $a1, ($s0)
/* 020578 80045178 0C0B1EAF */  jal   get_variable
/* 02057C 8004517C 0220202D */   daddu $a0, $s1, $zero
/* 020580 80045180 0040802D */  daddu $s0, $v0, $zero
/* 020584 80045184 2402FFFF */  addiu $v0, $zero, -1
/* 020588 80045188 16420002 */  bne   $s2, $v0, .L80045194
/* 02058C 8004518C 00000000 */   nop   
/* 020590 80045190 86720008 */  lh    $s2, 8($s3)
.L80045194:
/* 020594 80045194 0C00FB3A */  jal   get_enemy
/* 020598 80045198 0240202D */   daddu $a0, $s2, $zero
/* 02059C 8004519C 0040982D */  daddu $s3, $v0, $zero
/* 0205A0 800451A0 8E620040 */  lw    $v0, 0x40($s3)
/* 0205A4 800451A4 50400005 */  beql  $v0, $zero, .L800451BC
/* 0205A8 800451A8 AE700028 */   sw    $s0, 0x28($s3)
/* 0205AC 800451AC 8E640058 */  lw    $a0, 0x58($s3)
/* 0205B0 800451B0 0C0B102B */  jal   kill_script_by_ID
/* 0205B4 800451B4 00000000 */   nop   
/* 0205B8 800451B8 AE700028 */  sw    $s0, 0x28($s3)
.L800451BC:
/* 0205BC 800451BC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0205C0 800451C0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0205C4 800451C4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0205C8 800451C8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0205CC 800451CC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0205D0 800451D0 24020002 */  addiu $v0, $zero, 2
/* 0205D4 800451D4 03E00008 */  jr    $ra
/* 0205D8 800451D8 27BD0028 */   addiu $sp, $sp, 0x28

