.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029934
/* 4D34 80029934 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4D38 80029938 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4D3C 8002993C 0C00A640 */  jal       _advance_rng
/* 4D40 80029940 00000000 */   nop
/* 4D44 80029944 30427FFF */  andi      $v0, $v0, 0x7fff
/* 4D48 80029948 44821000 */  mtc1      $v0, $f2
/* 4D4C 8002994C 00000000 */  nop
/* 4D50 80029950 04410006 */  bgez      $v0, .L8002996C
/* 4D54 80029954 468010A1 */   cvt.d.w  $f2, $f2
/* 4D58 80029958 3C0141F0 */  lui       $at, 0x41f0
/* 4D5C 8002995C 44810800 */  mtc1      $at, $f1
/* 4D60 80029960 44800000 */  mtc1      $zero, $f0
/* 4D64 80029964 00000000 */  nop
/* 4D68 80029968 46201080 */  add.d     $f2, $f2, $f0
.L8002996C:
/* 4D6C 8002996C 3C013F00 */  lui       $at, 0x3f00
/* 4D70 80029970 44810800 */  mtc1      $at, $f1
/* 4D74 80029974 44800000 */  mtc1      $zero, $f0
/* 4D78 80029978 00000000 */  nop
/* 4D7C 8002997C 46201002 */  mul.d     $f0, $f2, $f0
/* 4D80 80029980 00000000 */  nop
/* 4D84 80029984 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4D88 80029988 46200020 */  cvt.s.d   $f0, $f0
/* 4D8C 8002998C 03E00008 */  jr        $ra
/* 4D90 80029990 27BD0018 */   addiu    $sp, $sp, 0x18
