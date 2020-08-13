.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024428C
/* 1375CC 8024428C 8FB20018 */  lw    $s2, 0x18($sp)
/* 1375D0 80244290 8FB10014 */  lw    $s1, 0x14($sp)
/* 1375D4 80244294 8FB00010 */  lw    $s0, 0x10($sp)
/* 1375D8 80244298 03E00008 */  jr    $ra
/* 1375DC 8024429C 27BD0030 */   addiu $sp, $sp, 0x30

