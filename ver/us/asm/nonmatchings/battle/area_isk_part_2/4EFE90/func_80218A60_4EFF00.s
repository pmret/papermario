.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A60_4EFF00
/* 4EFF00 80218A60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4EFF04 80218A64 3C028022 */  lui       $v0, %hi(D_80220770)
/* 4EFF08 80218A68 24420770 */  addiu     $v0, $v0, %lo(D_80220770)
/* 4EFF0C 80218A6C 3C013E99 */  lui       $at, 0x3e99
/* 4EFF10 80218A70 3421999A */  ori       $at, $at, 0x999a
/* 4EFF14 80218A74 44810000 */  mtc1      $at, $f0
/* 4EFF18 80218A78 3C05C2DC */  lui       $a1, 0xc2dc
/* 4EFF1C 80218A7C 3C0642A0 */  lui       $a2, 0x42a0
/* 4EFF20 80218A80 3C07C312 */  lui       $a3, 0xc312
/* 4EFF24 80218A84 24040001 */  addiu     $a0, $zero, 1
/* 4EFF28 80218A88 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFF2C 80218A8C AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFF30 80218A90 0C01C124 */  jal       func_80070490
/* 4EFF34 80218A94 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4EFF38 80218A98 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFF3C 80218A9C 24020002 */  addiu     $v0, $zero, 2
/* 4EFF40 80218AA0 03E00008 */  jr        $ra
/* 4EFF44 80218AA4 27BD0020 */   addiu    $sp, $sp, 0x20
