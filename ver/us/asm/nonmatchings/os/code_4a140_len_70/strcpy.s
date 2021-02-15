.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel strcpy
/* 4A140 8006ED40 90A20000 */  lbu       $v0, ($a1)
/* 4A144 8006ED44 10400007 */  beqz      $v0, .L8006ED64
/* 4A148 8006ED48 00801821 */   addu     $v1, $a0, $zero
.L8006ED4C:
/* 4A14C 8006ED4C 90A20000 */  lbu       $v0, ($a1)
/* 4A150 8006ED50 A0620000 */  sb        $v0, ($v1)
/* 4A154 8006ED54 24A50001 */  addiu     $a1, $a1, 1
/* 4A158 8006ED58 90A20000 */  lbu       $v0, ($a1)
/* 4A15C 8006ED5C 1440FFFB */  bnez      $v0, .L8006ED4C
/* 4A160 8006ED60 24630001 */   addiu    $v1, $v1, 1
.L8006ED64:
/* 4A164 8006ED64 A0600000 */  sb        $zero, ($v1)
/* 4A168 8006ED68 03E00008 */  jr        $ra
/* 4A16C 8006ED6C 00801021 */   addu     $v0, $a0, $zero
