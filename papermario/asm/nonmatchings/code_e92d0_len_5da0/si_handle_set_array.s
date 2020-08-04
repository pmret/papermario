.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_set_array
/* 0EAB5C 802C61AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EAB60 802C61B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAB64 802C61B4 0080802D */  daddu $s0, $a0, $zero
/* 0EAB68 802C61B8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EAB6C 802C61BC 8E02000C */  lw    $v0, 0xc($s0)
/* 0EAB70 802C61C0 0C0B1EAF */  jal   get_variable
/* 0EAB74 802C61C4 8C450000 */   lw    $a1, ($v0)
/* 0EAB78 802C61C8 AE02013C */  sw    $v0, 0x13c($s0)
/* 0EAB7C 802C61CC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EAB80 802C61D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAB84 802C61D4 24020002 */  addiu $v0, $zero, 2
/* 0EAB88 802C61D8 03E00008 */  jr    $ra
/* 0EAB8C 802C61DC 27BD0018 */   addiu $sp, $sp, 0x18

