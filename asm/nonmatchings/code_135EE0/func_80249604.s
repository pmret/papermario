.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249604
.L80249604:
/* 13C944 80249604 8FBF001C */  lw    $ra, 0x1c($sp)
/* 13C948 80249608 8FB20018 */  lw    $s2, 0x18($sp)
/* 13C94C 8024960C 8FB10014 */  lw    $s1, 0x14($sp)
/* 13C950 80249610 8FB00010 */  lw    $s0, 0x10($sp)
/* 13C954 80249614 03E00008 */  jr    $ra
/* 13C958 80249618 27BD0020 */   addiu $sp, $sp, 0x20

