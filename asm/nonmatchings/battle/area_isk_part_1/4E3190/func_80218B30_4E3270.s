.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B30_4E3270
/* 4E3270 80218B30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4E3274 80218B34 3C028022 */  lui       $v0, %hi(D_80224DA0)
/* 4E3278 80218B38 24424DA0 */  addiu     $v0, $v0, %lo(D_80224DA0)
/* 4E327C 80218B3C 3C013E99 */  lui       $at, 0x3e99
/* 4E3280 80218B40 3421999A */  ori       $at, $at, 0x999a
/* 4E3284 80218B44 44810000 */  mtc1      $at, $f0
/* 4E3288 80218B48 3C05C2DC */  lui       $a1, 0xc2dc
/* 4E328C 80218B4C 3C0642A0 */  lui       $a2, 0x42a0
/* 4E3290 80218B50 3C07C312 */  lui       $a3, 0xc312
/* 4E3294 80218B54 24040001 */  addiu     $a0, $zero, 1
/* 4E3298 80218B58 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E329C 80218B5C AFA20014 */  sw        $v0, 0x14($sp)
/* 4E32A0 80218B60 0C01C124 */  jal       func_80070490
/* 4E32A4 80218B64 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4E32A8 80218B68 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E32AC 80218B6C 24020002 */  addiu     $v0, $zero, 2
/* 4E32B0 80218B70 03E00008 */  jr        $ra
/* 4E32B4 80218B74 27BD0020 */   addiu    $sp, $sp, 0x20
