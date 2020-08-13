.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel BindHandleEvent
/* 1A7500 80278C20 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A7504 80278C24 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A7508 80278C28 0080902D */  daddu $s2, $a0, $zero
/* 1A750C 80278C2C AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A7510 80278C30 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A7514 80278C34 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A7518 80278C38 8E51000C */  lw    $s1, 0xc($s2)
/* 1A751C 80278C3C 8E250000 */  lw    $a1, ($s1)
/* 1A7520 80278C40 0C0B1EAF */  jal   get_variable
/* 1A7524 80278C44 26310004 */   addiu $s1, $s1, 4
/* 1A7528 80278C48 0040802D */  daddu $s0, $v0, $zero
/* 1A752C 80278C4C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A7530 80278C50 16020002 */  bne   $s0, $v0, .L80278C5C
/* 1A7534 80278C54 00000000 */   nop   
/* 1A7538 80278C58 8E500148 */  lw    $s0, 0x148($s2)
.L80278C5C:
/* 1A753C 80278C5C 8E250000 */  lw    $a1, ($s1)
/* 1A7540 80278C60 0C0B1EAF */  jal   get_variable
/* 1A7544 80278C64 0240202D */   daddu $a0, $s2, $zero
/* 1A7548 80278C68 0200202D */  daddu $a0, $s0, $zero
/* 1A754C 80278C6C 0C09A75B */  jal   get_actor
/* 1A7550 80278C70 0040802D */   daddu $s0, $v0, $zero
/* 1A7554 80278C74 AC5001C8 */  sw    $s0, 0x1c8($v0)
/* 1A7558 80278C78 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A755C 80278C7C 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A7560 80278C80 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A7564 80278C84 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A7568 80278C88 24020002 */  addiu $v0, $zero, 2
/* 1A756C 80278C8C 03E00008 */  jr    $ra
/* 1A7570 80278C90 27BD0020 */   addiu $sp, $sp, 0x20

