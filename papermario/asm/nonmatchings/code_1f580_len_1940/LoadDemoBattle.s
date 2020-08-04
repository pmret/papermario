.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel LoadDemoBattle
/* 01F664 80044264 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01F668 80044268 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01F66C 8004426C 8C82000C */  lw    $v0, 0xc($a0)
/* 01F670 80044270 0C0B1EAF */  jal   get_variable
/* 01F674 80044274 8C450000 */   lw    $a1, ($v0)
/* 01F678 80044278 0C01CB85 */  jal   load_demo_battle
/* 01F67C 8004427C 0040202D */   daddu $a0, $v0, $zero
/* 01F680 80044280 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01F684 80044284 24020002 */  addiu $v0, $zero, 2
/* 01F688 80044288 03E00008 */  jr    $ra
/* 01F68C 8004428C 27BD0018 */   addiu $sp, $sp, 0x18

/* 01F690 80044290 03E00008 */  jr    $ra
/* 01F694 80044294 24020002 */   addiu $v0, $zero, 2

