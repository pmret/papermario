.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel strchr
/* 3FE10 80064A10 90830000 */  lbu       $v1, ($a0)
/* 3FE14 80064A14 80820000 */  lb        $v0, ($a0)
/* 3FE18 80064A18 00052E00 */  sll       $a1, $a1, 0x18
/* 3FE1C 80064A1C 00052E03 */  sra       $a1, $a1, 0x18
/* 3FE20 80064A20 10450008 */  beq       $v0, $a1, .L80064A44
/* 3FE24 80064A24 27BDFFF0 */   addiu    $sp, $sp, -0x10
.L80064A28:
/* 3FE28 80064A28 14600003 */  bnez      $v1, .L80064A38
/* 3FE2C 80064A2C 24840001 */   addiu    $a0, $a0, 1
/* 3FE30 80064A30 08019292 */  j         .L80064A48
/* 3FE34 80064A34 00001021 */   addu     $v0, $zero, $zero
.L80064A38:
/* 3FE38 80064A38 80820000 */  lb        $v0, ($a0)
/* 3FE3C 80064A3C 1445FFFA */  bne       $v0, $a1, .L80064A28
/* 3FE40 80064A40 90830000 */   lbu      $v1, ($a0)
.L80064A44:
/* 3FE44 80064A44 00801021 */  addu      $v0, $a0, $zero
.L80064A48:
/* 3FE48 80064A48 03E00008 */  jr        $ra
/* 3FE4C 80064A4C 27BD0010 */   addiu    $sp, $sp, 0x10
