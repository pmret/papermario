.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80064A20
/* 3FE20 80064A20 80820000 */  lb        $v0, ($a0)
/* 3FE24 80064A24 10400005 */  beqz      $v0, .L80064A3C
/* 3FE28 80064A28 00801821 */   addu     $v1, $a0, $zero
/* 3FE2C 80064A2C 24630001 */  addiu     $v1, $v1, 1
.L80064A30:
/* 3FE30 80064A30 80620000 */  lb        $v0, ($v1)
/* 3FE34 80064A34 5440FFFE */  bnel      $v0, $zero, .L80064A30
/* 3FE38 80064A38 24630001 */   addiu    $v1, $v1, 1
.L80064A3C:
/* 3FE3C 80064A3C 03E00008 */  jr        $ra
/* 3FE40 80064A40 00641023 */   subu     $v0, $v1, $a0
