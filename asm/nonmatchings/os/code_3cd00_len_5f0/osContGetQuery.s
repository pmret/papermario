.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osContGetQuery
/* 03CD80 80061980 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03CD84 80061984 AFBF0018 */  sw    $ra, 0x18($sp)
/* 03CD88 80061988 00802821 */  addu  $a1, $a0, $zero
/* 03CD8C 8006198C 0C018747 */  jal   osContGetInitData
/* 03CD90 80061990 27A40010 */   addiu $a0, $sp, 0x10
/* 03CD94 80061994 8FBF0018 */  lw    $ra, 0x18($sp)
/* 03CD98 80061998 03E00008 */  jr    $ra
/* 03CD9C 8006199C 27BD0020 */   addiu $sp, $sp, 0x20

