.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osIdCheckSum
/* 44B74 80069774 2487001C */  addiu     $a3, $a0, 0x1c
/* 44B78 80069778 A4C00000 */  sh        $zero, ($a2)
/* 44B7C 8006977C A4A00000 */  sh        $zero, ($a1)
.L80069780:
/* 44B80 80069780 94830000 */  lhu       $v1, ($a0)
/* 44B84 80069784 94A20000 */  lhu       $v0, ($a1)
/* 44B88 80069788 00431021 */  addu      $v0, $v0, $v1
/* 44B8C 8006978C A4A20000 */  sh        $v0, ($a1)
/* 44B90 80069790 94C20000 */  lhu       $v0, ($a2)
/* 44B94 80069794 24840002 */  addiu     $a0, $a0, 2
/* 44B98 80069798 00031827 */  nor       $v1, $zero, $v1
/* 44B9C 8006979C 00431021 */  addu      $v0, $v0, $v1
/* 44BA0 800697A0 A4C20000 */  sh        $v0, ($a2)
/* 44BA4 800697A4 0087102B */  sltu      $v0, $a0, $a3
/* 44BA8 800697A8 1440FFF5 */  bnez      $v0, .L80069780
/* 44BAC 800697AC 00000000 */   nop      
/* 44BB0 800697B0 03E00008 */  jr        $ra
/* 44BB4 800697B4 00001021 */   addu     $v0, $zero, $zero
