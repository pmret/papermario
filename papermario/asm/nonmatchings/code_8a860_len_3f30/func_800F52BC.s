.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800F52BC
/* 08E76C 800F52BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08E770 800F52C0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 08E774 800F52C4 0C03C684 */  jal   func_800F1A10
/* 08E778 800F52C8 00000000 */   nop   
/* 08E77C 800F52CC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 08E780 800F52D0 03E00008 */  jr    $ra
/* 08E784 800F52D4 27BD0018 */   addiu $sp, $sp, 0x18

/* 08E788 800F52D8 00000000 */  nop   
/* 08E78C 800F52DC 00000000 */  nop   
