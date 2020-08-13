.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247318
/* 13A658 80247318 5440FFFB */  bnezl $v0, .L80247308
/* 13A65C 8024731C 24A50001 */   addiu $a1, $a1, 1
/* 13A660 80247320 A4600000 */  sh    $zero, ($v1)
/* 13A664 80247324 84C20000 */  lh    $v0, ($a2)
/* 13A668 80247328 50400001 */  beql  $v0, $zero, .L80247330
/* 13A66C 8024732C 24070002 */   addiu $a3, $zero, 2
.L80247330:
/* 13A670 80247330 03E00008 */  jr    $ra
/* 13A674 80247334 00E0102D */   daddu $v0, $a3, $zero

