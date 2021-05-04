.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238E04_6F1EE4
/* 6F1EE4 80238E04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6F1EE8 80238E08 0000202D */  daddu     $a0, $zero, $zero
/* 6F1EEC 80238E0C 3C013F80 */  lui       $at, 0x3f80
/* 6F1EF0 80238E10 44810000 */  mtc1      $at, $f0
/* 6F1EF4 80238E14 3C05434E */  lui       $a1, 0x434e
/* 6F1EF8 80238E18 3C064310 */  lui       $a2, 0x4310
/* 6F1EFC 80238E1C 0000382D */  daddu     $a3, $zero, $zero
/* 6F1F00 80238E20 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6F1F04 80238E24 AFA00014 */  sw        $zero, 0x14($sp)
/* 6F1F08 80238E28 0C01C844 */  jal       func_80072110
/* 6F1F0C 80238E2C E7A00010 */   swc1     $f0, 0x10($sp)
/* 6F1F10 80238E30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6F1F14 80238E34 3C018024 */  lui       $at, %hi(D_8023CDA0)
/* 6F1F18 80238E38 AC22CDA0 */  sw        $v0, %lo(D_8023CDA0)($at)
/* 6F1F1C 80238E3C 24020002 */  addiu     $v0, $zero, 2
/* 6F1F20 80238E40 03E00008 */  jr        $ra
/* 6F1F24 80238E44 27BD0020 */   addiu    $sp, $sp, 0x20
