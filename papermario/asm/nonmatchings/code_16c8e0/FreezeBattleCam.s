.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FreezeBattleCam
/* 17D658 8024ED78 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17D65C 8024ED7C AFBF0010 */  sw    $ra, 0x10($sp)
/* 17D660 8024ED80 8C82000C */  lw    $v0, 0xc($a0)
/* 17D664 8024ED84 0C0B1EAF */  jal   get_variable
/* 17D668 8024ED88 8C450000 */   lw    $a1, ($v0)
/* 17D66C 8024ED8C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17D670 8024ED90 3C018028 */  lui   $at, 0x8028
/* 17D674 8024ED94 A0220CE0 */  sb    $v0, 0xce0($at)
/* 17D678 8024ED98 24020002 */  addiu $v0, $zero, 2
/* 17D67C 8024ED9C 03E00008 */  jr    $ra
/* 17D680 8024EDA0 27BD0018 */   addiu $sp, $sp, 0x18

/* 17D684 8024EDA4 3C01802A */  lui   $at, 0x802a
/* 17D688 8024EDA8 A020F2A6 */  sb    $zero, -0xd5a($at)
/* 17D68C 8024EDAC 03E00008 */  jr    $ra
/* 17D690 8024EDB0 24020002 */   addiu $v0, $zero, 2

/* 17D694 8024EDB4 00000000 */  nop   
/* 17D698 8024EDB8 00000000 */  nop   
/* 17D69C 8024EDBC 00000000 */  nop   
