.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800363FC
/* 0117FC 800363FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 011800 80036400 3C03800A */  lui   $v1, 0x800a
/* 011804 80036404 84630944 */  lh    $v1, 0x944($v1)
/* 011808 80036408 24020004 */  addiu $v0, $zero, 4
/* 01180C 8003640C 10620003 */  beq   $v1, $v0, .L8003641C
/* 011810 80036410 AFBF0010 */   sw    $ra, 0x10($sp)
/* 011814 80036414 14600003 */  bnez  $v1, .L80036424
/* 011818 80036418 00000000 */   nop   
.L8003641C:
/* 01181C 8003641C 0C03A5CF */  jal   func_800E973C
/* 011820 80036420 00000000 */   nop   
.L80036424:
/* 011824 80036424 8FBF0010 */  lw    $ra, 0x10($sp)
/* 011828 80036428 03E00008 */  jr    $ra
/* 01182C 8003642C 27BD0018 */   addiu $sp, $sp, 0x18

