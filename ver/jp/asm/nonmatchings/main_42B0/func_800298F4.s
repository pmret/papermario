.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800298F4
/* 4CF4 800298F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF8 800298F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CFC 800298FC 0C00A630 */  jal       func_800298C0
/* 4D00 80029900 00000000 */   nop
/* 4D04 80029904 30427FFF */  andi      $v0, $v0, 0x7fff
/* 4D08 80029908 44821000 */  mtc1      $v0, $f2
/* 4D0C 8002990C 00000000 */  nop
/* 4D10 80029910 04410006 */  bgez      $v0, .L8002992C
/* 4D14 80029914 468010A1 */   cvt.d.w  $f2, $f2
/* 4D18 80029918 3C0141F0 */  lui       $at, 0x41f0
/* 4D1C 8002991C 44810800 */  mtc1      $at, $f1
/* 4D20 80029920 44800000 */  mtc1      $zero, $f0
/* 4D24 80029924 00000000 */  nop
/* 4D28 80029928 46201080 */  add.d     $f2, $f2, $f0
.L8002992C:
/* 4D2C 8002992C 3C013F00 */  lui       $at, 0x3f00
/* 4D30 80029930 44810800 */  mtc1      $at, $f1
/* 4D34 80029934 44800000 */  mtc1      $zero, $f0
/* 4D38 80029938 00000000 */  nop
/* 4D3C 8002993C 46201002 */  mul.d     $f0, $f2, $f0
/* 4D40 80029940 00000000 */  nop
/* 4D44 80029944 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4D48 80029948 46200020 */  cvt.s.d   $f0, $f0
/* 4D4C 8002994C 03E00008 */  jr        $ra
/* 4D50 80029950 27BD0018 */   addiu    $sp, $sp, 0x18
