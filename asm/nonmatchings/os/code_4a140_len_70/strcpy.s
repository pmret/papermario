.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel strcpy
/* 04A140 8006ED40 90A20000 */  lbu   $v0, ($a1)
/* 04A144 8006ED44 10400007 */  beqz  $v0, .L8006ED64
/* 04A148 8006ED48 00801821 */   addu  $v1, $a0, $zero
.L8006ED4C:
/* 04A14C 8006ED4C 90A20000 */  lbu   $v0, ($a1)
/* 04A150 8006ED50 A0620000 */  sb    $v0, ($v1)
/* 04A154 8006ED54 24A50001 */  addiu $a1, $a1, 1
/* 04A158 8006ED58 90A20000 */  lbu   $v0, ($a1)
/* 04A15C 8006ED5C 1440FFFB */  bnez  $v0, .L8006ED4C
/* 04A160 8006ED60 24630001 */   addiu $v1, $v1, 1
.L8006ED64:
/* 04A164 8006ED64 A0600000 */  sb    $zero, ($v1)
/* 04A168 8006ED68 03E00008 */  jr    $ra
/* 04A16C 8006ED6C 00801021 */   addu  $v0, $a0, $zero

