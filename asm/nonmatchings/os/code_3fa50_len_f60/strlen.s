.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel strlen
/* 03FE50 80064A50 80820000 */  lb    $v0, ($a0)
/* 03FE54 80064A54 10400005 */  beqz  $v0, .L80064A6C
/* 03FE58 80064A58 00801821 */   addu  $v1, $a0, $zero
/* 03FE5C 80064A5C 24630001 */  addiu $v1, $v1, 1
.L80064A60:
/* 03FE60 80064A60 80620000 */  lb    $v0, ($v1)
/* 03FE64 80064A64 5440FFFE */  bnel  $v0, $zero, .L80064A60
/* 03FE68 80064A68 24630001 */   addiu $v1, $v1, 1
.L80064A6C:
/* 03FE6C 80064A6C 03E00008 */  jr    $ra
/* 03FE70 80064A70 00641023 */   subu  $v0, $v1, $a0

