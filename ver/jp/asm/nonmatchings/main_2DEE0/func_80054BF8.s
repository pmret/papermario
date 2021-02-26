.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054BF8
/* 2FFF8 80054BF8 18C00008 */  blez      $a2, .L80054C1C
/* 2FFFC 80054BFC 24C6FFFF */   addiu    $a2, $a2, -1
.L80054C00:
/* 30000 80054C00 90820000 */  lbu       $v0, ($a0)
/* 30004 80054C04 24840001 */  addiu     $a0, $a0, 1
/* 30008 80054C08 00C0182D */  daddu     $v1, $a2, $zero
/* 3000C 80054C0C 24C6FFFF */  addiu     $a2, $a2, -1
/* 30010 80054C10 A0A20000 */  sb        $v0, ($a1)
/* 30014 80054C14 1460FFFA */  bnez      $v1, .L80054C00
/* 30018 80054C18 24A50001 */   addiu    $a1, $a1, 1
.L80054C1C:
/* 3001C 80054C1C 03E00008 */  jr        $ra
/* 30020 80054C20 00000000 */   nop
