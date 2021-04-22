.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800649E0
/* 3FDE0 800649E0 90830000 */  lbu       $v1, ($a0)
/* 3FDE4 800649E4 80820000 */  lb        $v0, ($a0)
/* 3FDE8 800649E8 00052E00 */  sll       $a1, $a1, 0x18
/* 3FDEC 800649EC 00052E03 */  sra       $a1, $a1, 0x18
/* 3FDF0 800649F0 10450008 */  beq       $v0, $a1, .L80064A14
/* 3FDF4 800649F4 27BDFFF0 */   addiu    $sp, $sp, -0x10
.L800649F8:
/* 3FDF8 800649F8 14600003 */  bnez      $v1, .L80064A08
/* 3FDFC 800649FC 24840001 */   addiu    $a0, $a0, 1
/* 3FE00 80064A00 08019286 */  j         .L80064A18
/* 3FE04 80064A04 00001021 */   addu     $v0, $zero, $zero
.L80064A08:
/* 3FE08 80064A08 80820000 */  lb        $v0, ($a0)
/* 3FE0C 80064A0C 1445FFFA */  bne       $v0, $a1, .L800649F8
/* 3FE10 80064A10 90830000 */   lbu      $v1, ($a0)
.L80064A14:
/* 3FE14 80064A14 00801021 */  addu      $v0, $a0, $zero
.L80064A18:
/* 3FE18 80064A18 03E00008 */  jr        $ra
/* 3FE1C 80064A1C 27BD0010 */   addiu    $sp, $sp, 0x10
