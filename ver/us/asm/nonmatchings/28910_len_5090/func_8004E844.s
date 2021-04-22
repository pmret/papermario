.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E844
/* 29C44 8004E844 000510C0 */  sll       $v0, $a1, 3
/* 29C48 8004E848 00451021 */  addu      $v0, $v0, $a1
/* 29C4C 8004E84C 00021040 */  sll       $v0, $v0, 1
/* 29C50 8004E850 24420174 */  addiu     $v0, $v0, 0x174
/* 29C54 8004E854 00821821 */  addu      $v1, $a0, $v0
/* 29C58 8004E858 00852021 */  addu      $a0, $a0, $a1
/* 29C5C 8004E85C A0800212 */  sb        $zero, 0x212($a0)
/* 29C60 8004E860 3404FF00 */  ori       $a0, $zero, 0xff00
/* 29C64 8004E864 24020008 */  addiu     $v0, $zero, 8
.L8004E868:
/* 29C68 8004E868 A4640000 */  sh        $a0, ($v1)
/* 29C6C 8004E86C 2442FFFF */  addiu     $v0, $v0, -1
/* 29C70 8004E870 0441FFFD */  bgez      $v0, .L8004E868
/* 29C74 8004E874 24630002 */   addiu    $v1, $v1, 2
/* 29C78 8004E878 03E00008 */  jr        $ra
/* 29C7C 8004E87C 00000000 */   nop
