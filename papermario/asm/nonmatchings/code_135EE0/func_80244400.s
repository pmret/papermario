.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80244400
.L80244400:
/* 137740 80244400 AE510000 */  sw    $s1, ($s2)
.L80244404:
/* 137744 80244404 AE700000 */  sw    $s0, ($s3)
/* 137748 80244408 8FBF0020 */  lw    $ra, 0x20($sp)
/* 13774C 8024440C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 137750 80244410 8FB20018 */  lw    $s2, 0x18($sp)
/* 137754 80244414 8FB10014 */  lw    $s1, 0x14($sp)
/* 137758 80244418 8FB00010 */  lw    $s0, 0x10($sp)
/* 13775C 8024441C 03E00008 */  jr    $ra
/* 137760 80244420 27BD0028 */   addiu $sp, $sp, 0x28

