.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006ED20
/* 4A120 8006ED20 90A20000 */  lbu       $v0, ($a1)
/* 4A124 8006ED24 10400007 */  beqz      $v0, .L8006ED44
/* 4A128 8006ED28 00801821 */   addu     $v1, $a0, $zero
.L8006ED2C:
/* 4A12C 8006ED2C 90A20000 */  lbu       $v0, ($a1)
/* 4A130 8006ED30 A0620000 */  sb        $v0, ($v1)
/* 4A134 8006ED34 24A50001 */  addiu     $a1, $a1, 1
/* 4A138 8006ED38 90A20000 */  lbu       $v0, ($a1)
/* 4A13C 8006ED3C 1440FFFB */  bnez      $v0, .L8006ED2C
/* 4A140 8006ED40 24630001 */   addiu    $v1, $v1, 1
.L8006ED44:
/* 4A144 8006ED44 A0600000 */  sb        $zero, ($v1)
/* 4A148 8006ED48 03E00008 */  jr        $ra
/* 4A14C 8006ED4C 00801021 */   addu     $v0, $a0, $zero
