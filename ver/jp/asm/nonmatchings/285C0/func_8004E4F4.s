.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E4F4
/* 298F4 8004E4F4 000510C0 */  sll       $v0, $a1, 3
/* 298F8 8004E4F8 00451021 */  addu      $v0, $v0, $a1
/* 298FC 8004E4FC 00021040 */  sll       $v0, $v0, 1
/* 29900 8004E500 24420174 */  addiu     $v0, $v0, 0x174
/* 29904 8004E504 00821821 */  addu      $v1, $a0, $v0
/* 29908 8004E508 00852021 */  addu      $a0, $a0, $a1
/* 2990C 8004E50C A0800212 */  sb        $zero, 0x212($a0)
/* 29910 8004E510 3404FF00 */  ori       $a0, $zero, 0xff00
/* 29914 8004E514 24020008 */  addiu     $v0, $zero, 8
.L8004E518:
/* 29918 8004E518 A4640000 */  sh        $a0, ($v1)
/* 2991C 8004E51C 2442FFFF */  addiu     $v0, $v0, -1
/* 29920 8004E520 0441FFFD */  bgez      $v0, .L8004E518
/* 29924 8004E524 24630002 */   addiu    $v1, $v1, 2
/* 29928 8004E528 03E00008 */  jr        $ra
/* 2992C 8004E52C 00000000 */   nop
