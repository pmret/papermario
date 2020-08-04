.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel BindNpcDefeat
/* 0205DC 800451DC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0205E0 800451E0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0205E4 800451E4 0080882D */  daddu $s1, $a0, $zero
/* 0205E8 800451E8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0205EC 800451EC AFB3001C */  sw    $s3, 0x1c($sp)
/* 0205F0 800451F0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0205F4 800451F4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0205F8 800451F8 8E30000C */  lw    $s0, 0xc($s1)
/* 0205FC 800451FC 8E330148 */  lw    $s3, 0x148($s1)
/* 020600 80045200 8E050000 */  lw    $a1, ($s0)
/* 020604 80045204 0C0B1EAF */  jal   get_variable
/* 020608 80045208 26100004 */   addiu $s0, $s0, 4
/* 02060C 8004520C 0040902D */  daddu $s2, $v0, $zero
/* 020610 80045210 8E050000 */  lw    $a1, ($s0)
/* 020614 80045214 0C0B1EAF */  jal   get_variable
/* 020618 80045218 0220202D */   daddu $a0, $s1, $zero
/* 02061C 8004521C 0040802D */  daddu $s0, $v0, $zero
/* 020620 80045220 2402FFFF */  addiu $v0, $zero, -1
/* 020624 80045224 16420002 */  bne   $s2, $v0, .L80045230
/* 020628 80045228 00000000 */   nop   
/* 02062C 8004522C 86720008 */  lh    $s2, 8($s3)
.L80045230:
/* 020630 80045230 0C00FB3A */  jal   get_enemy
/* 020634 80045234 0240202D */   daddu $a0, $s2, $zero
/* 020638 80045238 AC500030 */  sw    $s0, 0x30($v0)
/* 02063C 8004523C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 020640 80045240 8FB3001C */  lw    $s3, 0x1c($sp)
/* 020644 80045244 8FB20018 */  lw    $s2, 0x18($sp)
/* 020648 80045248 8FB10014 */  lw    $s1, 0x14($sp)
/* 02064C 8004524C 8FB00010 */  lw    $s0, 0x10($sp)
/* 020650 80045250 24020002 */  addiu $v0, $zero, 2
/* 020654 80045254 03E00008 */  jr    $ra
/* 020658 80045258 27BD0028 */   addiu $sp, $sp, 0x28

