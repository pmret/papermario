.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80069754
/* 44B54 80069754 2487001C */  addiu     $a3, $a0, 0x1c
/* 44B58 80069758 A4C00000 */  sh        $zero, ($a2)
/* 44B5C 8006975C A4A00000 */  sh        $zero, ($a1)
.L80069760:
/* 44B60 80069760 94830000 */  lhu       $v1, ($a0)
/* 44B64 80069764 94A20000 */  lhu       $v0, ($a1)
/* 44B68 80069768 00431021 */  addu      $v0, $v0, $v1
/* 44B6C 8006976C A4A20000 */  sh        $v0, ($a1)
/* 44B70 80069770 94C20000 */  lhu       $v0, ($a2)
/* 44B74 80069774 24840002 */  addiu     $a0, $a0, 2
/* 44B78 80069778 00031827 */  nor       $v1, $zero, $v1
/* 44B7C 8006977C 00431021 */  addu      $v0, $v0, $v1
/* 44B80 80069780 A4C20000 */  sh        $v0, ($a2)
/* 44B84 80069784 0087102B */  sltu      $v0, $a0, $a3
/* 44B88 80069788 1440FFF5 */  bnez      $v0, .L80069760
/* 44B8C 8006978C 00000000 */   nop
/* 44B90 80069790 03E00008 */  jr        $ra
/* 44B94 80069794 00001021 */   addu     $v0, $zero, $zero
