.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006ED50
.L8006ED50:
/* 4A150 8006ED50 90860000 */  lbu       $a2, ($a0)
/* 4A154 8006ED54 24840001 */  addiu     $a0, $a0, 1
/* 4A158 8006ED58 90A20000 */  lbu       $v0, ($a1)
/* 4A15C 8006ED5C 30C300FF */  andi      $v1, $a2, 0xff
/* 4A160 8006ED60 304200FF */  andi      $v0, $v0, 0xff
/* 4A164 8006ED64 10620003 */  beq       $v1, $v0, .L8006ED74
/* 4A168 8006ED68 24A50001 */   addiu    $a1, $a1, 1
/* 4A16C 8006ED6C 0801BB5F */  j         .L8006ED7C
/* 4A170 8006ED70 00621023 */   subu     $v0, $v1, $v0
.L8006ED74:
/* 4A174 8006ED74 14C0FFF6 */  bnez      $a2, .L8006ED50
/* 4A178 8006ED78 00001021 */   addu     $v0, $zero, $zero
.L8006ED7C:
/* 4A17C 8006ED7C 03E00008 */  jr        $ra
/* 4A180 8006ED80 00000000 */   nop
/* 4A184 8006ED84 00000000 */  nop
/* 4A188 8006ED88 00000000 */  nop
/* 4A18C 8006ED8C 00000000 */  nop
