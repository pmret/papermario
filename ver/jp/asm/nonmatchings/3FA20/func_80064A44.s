.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80064A44
/* 3FE44 80064A44 10C00007 */  beqz      $a2, .L80064A64
/* 3FE48 80064A48 00801821 */   addu     $v1, $a0, $zero
.L80064A4C:
/* 3FE4C 80064A4C 90A20000 */  lbu       $v0, ($a1)
/* 3FE50 80064A50 24A50001 */  addiu     $a1, $a1, 1
/* 3FE54 80064A54 24C6FFFF */  addiu     $a2, $a2, -1
/* 3FE58 80064A58 A0620000 */  sb        $v0, ($v1)
/* 3FE5C 80064A5C 14C0FFFB */  bnez      $a2, .L80064A4C
/* 3FE60 80064A60 24630001 */   addiu    $v1, $v1, 1
.L80064A64:
/* 3FE64 80064A64 03E00008 */  jr        $ra
/* 3FE68 80064A68 00801021 */   addu     $v0, $a0, $zero
/* 3FE6C 80064A6C 00000000 */  nop
