.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetBattleOutcome
/* 01F97C 8004457C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01F980 80044580 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01F984 80044584 8C82000C */  lw    $v0, 0xc($a0)
/* 01F988 80044588 3C06800B */  lui   $a2, 0x800b
/* 01F98C 8004458C 80C60F19 */  lb    $a2, 0xf19($a2)
/* 01F990 80044590 0C0B2026 */  jal   set_variable
/* 01F994 80044594 8C450000 */   lw    $a1, ($v0)
/* 01F998 80044598 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01F99C 8004459C 24020002 */  addiu $v0, $zero, 2
/* 01F9A0 800445A0 03E00008 */  jr    $ra
/* 01F9A4 800445A4 27BD0018 */   addiu $sp, $sp, 0x18

/* 01F9A8 800445A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01F9AC 800445AC AFBF0010 */  sw    $ra, 0x10($sp)
/* 01F9B0 800445B0 8C82000C */  lw    $v0, 0xc($a0)
/* 01F9B4 800445B4 8C830148 */  lw    $v1, 0x148($a0)
/* 01F9B8 800445B8 8C450000 */  lw    $a1, ($v0)
/* 01F9BC 800445BC 0C0B2026 */  jal   set_variable
/* 01F9C0 800445C0 8C6600C4 */   lw    $a2, 0xc4($v1)
/* 01F9C4 800445C4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01F9C8 800445C8 24020002 */  addiu $v0, $zero, 2
/* 01F9CC 800445CC 03E00008 */  jr    $ra
/* 01F9D0 800445D0 27BD0018 */   addiu $sp, $sp, 0x18

/* 01F9D4 800445D4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01F9D8 800445D8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01F9DC 800445DC 8C82000C */  lw    $v0, 0xc($a0)
/* 01F9E0 800445E0 8C830148 */  lw    $v1, 0x148($a0)
/* 01F9E4 800445E4 8C450000 */  lw    $a1, ($v0)
/* 01F9E8 800445E8 0C0B2026 */  jal   set_variable
/* 01F9EC 800445EC 8C6600C8 */   lw    $a2, 0xc8($v1)
/* 01F9F0 800445F0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01F9F4 800445F4 24020002 */  addiu $v0, $zero, 2
/* 01F9F8 800445F8 03E00008 */  jr    $ra
/* 01F9FC 800445FC 27BD0018 */   addiu $sp, $sp, 0x18

