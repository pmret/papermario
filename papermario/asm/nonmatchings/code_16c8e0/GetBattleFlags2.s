.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetBattleFlags2
/* 19B680 8026CDA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19B684 8026CDA4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19B688 8026CDA8 8C82000C */  lw    $v0, 0xc($a0)
/* 19B68C 8026CDAC 3C06800E */  lui   $a2, 0x800e
/* 19B690 8026CDB0 8CC6C074 */  lw    $a2, -0x3f8c($a2)
/* 19B694 8026CDB4 0C0B2026 */  jal   set_variable
/* 19B698 8026CDB8 8C450000 */   lw    $a1, ($v0)
/* 19B69C 8026CDBC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19B6A0 8026CDC0 24020002 */  addiu $v0, $zero, 2
/* 19B6A4 8026CDC4 03E00008 */  jr    $ra
/* 19B6A8 8026CDC8 27BD0018 */   addiu $sp, $sp, 0x18

