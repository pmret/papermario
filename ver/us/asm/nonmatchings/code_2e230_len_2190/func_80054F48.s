.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054F48
/* 30348 80054F48 18C00008 */  blez      $a2, .L80054F6C
/* 3034C 80054F4C 24C6FFFF */   addiu    $a2, $a2, -1
.L80054F50:
/* 30350 80054F50 90820000 */  lbu       $v0, ($a0)
/* 30354 80054F54 24840001 */  addiu     $a0, $a0, 1
/* 30358 80054F58 00C0182D */  daddu     $v1, $a2, $zero
/* 3035C 80054F5C 24C6FFFF */  addiu     $a2, $a2, -1
/* 30360 80054F60 A0A20000 */  sb        $v0, ($a1)
/* 30364 80054F64 1460FFFA */  bnez      $v1, .L80054F50
/* 30368 80054F68 24A50001 */   addiu    $a1, $a1, 1
.L80054F6C:
/* 3036C 80054F6C 03E00008 */  jr        $ra
/* 30370 80054F70 00000000 */   nop
