.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025D290
/* 18BB70 8025D290 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 18BB74 8025D294 00052880 */  sll       $a1, $a1, 2
/* 18BB78 8025D298 00451021 */  addu      $v0, $v0, $a1
/* 18BB7C 8025D29C 8C4208B0 */  lw        $v0, 0x8b0($v0)
/* 18BB80 8025D2A0 8C43000C */  lw        $v1, 0xc($v0)
/* 18BB84 8025D2A4 24020005 */  addiu     $v0, $zero, 5
/* 18BB88 8025D2A8 03E00008 */  jr        $ra
/* 18BB8C 8025D2AC AC62002C */   sw       $v0, 0x2c($v1)
