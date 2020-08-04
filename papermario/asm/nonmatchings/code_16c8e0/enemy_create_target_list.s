.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel enemy_create_target_list
/* 191928 80263048 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19192C 8026304C AFBF0010 */  sw    $ra, 0x10($sp)
/* 191930 80263050 0C098890 */  jal   create_target_list
/* 191934 80263054 24050001 */   addiu $a1, $zero, 1
/* 191938 80263058 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19193C 8026305C 03E00008 */  jr    $ra
/* 191940 80263060 27BD0018 */   addiu $sp, $sp, 0x18

