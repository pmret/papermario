.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetSelfNpcID
/* 020A14 80045614 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 020A18 80045618 AFBF0010 */  sw    $ra, 0x10($sp)
/* 020A1C 8004561C 8C82000C */  lw    $v0, 0xc($a0)
/* 020A20 80045620 8C830148 */  lw    $v1, 0x148($a0)
/* 020A24 80045624 8C450000 */  lw    $a1, ($v0)
/* 020A28 80045628 0C0B2026 */  jal   set_variable
/* 020A2C 8004562C 84660008 */   lh    $a2, 8($v1)
/* 020A30 80045630 8FBF0010 */  lw    $ra, 0x10($sp)
/* 020A34 80045634 24020002 */  addiu $v0, $zero, 2
/* 020A38 80045638 03E00008 */  jr    $ra
/* 020A3C 8004563C 27BD0018 */   addiu $sp, $sp, 0x18

