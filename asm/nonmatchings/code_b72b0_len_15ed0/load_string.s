.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel load_string
/* 0BC000 80125900 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0BC004 80125904 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0BC008 80125908 0C049647 */  jal   _load_string
/* 0BC00C 8012590C 0000302D */   daddu $a2, $zero, $zero
/* 0BC010 80125910 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0BC014 80125914 03E00008 */  jr    $ra
/* 0BC018 80125918 27BD0018 */   addiu $sp, $sp, 0x18

