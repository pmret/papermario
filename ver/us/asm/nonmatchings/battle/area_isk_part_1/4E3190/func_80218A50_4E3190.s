.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A50_4E3190
/* 4E3190 80218A50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4E3194 80218A54 3C028022 */  lui       $v0, %hi(D_80224D80)
/* 4E3198 80218A58 24424D80 */  addiu     $v0, $v0, %lo(D_80224D80)
/* 4E319C 80218A5C 3C013E99 */  lui       $at, 0x3e99
/* 4E31A0 80218A60 3421999A */  ori       $at, $at, 0x999a
/* 4E31A4 80218A64 44810000 */  mtc1      $at, $f0
/* 4E31A8 80218A68 3C05C2DC */  lui       $a1, 0xc2dc
/* 4E31AC 80218A6C 3C0642A0 */  lui       $a2, 0x42a0
/* 4E31B0 80218A70 3C07C312 */  lui       $a3, 0xc312
/* 4E31B4 80218A74 24040001 */  addiu     $a0, $zero, 1
/* 4E31B8 80218A78 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E31BC 80218A7C AFA20014 */  sw        $v0, 0x14($sp)
/* 4E31C0 80218A80 0C01C124 */  jal       func_80070490
/* 4E31C4 80218A84 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4E31C8 80218A88 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E31CC 80218A8C 24020002 */  addiu     $v0, $zero, 2
/* 4E31D0 80218A90 03E00008 */  jr        $ra
/* 4E31D4 80218A94 27BD0020 */   addiu    $sp, $sp, 0x20
