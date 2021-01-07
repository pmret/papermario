.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AD0_4EFF70
/* 4EFF70 80218AD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4EFF74 80218AD4 3C028022 */  lui       $v0, %hi(D_80220780)
/* 4EFF78 80218AD8 24420780 */  addiu     $v0, $v0, %lo(D_80220780)
/* 4EFF7C 80218ADC 3C013E99 */  lui       $at, 0x3e99
/* 4EFF80 80218AE0 3421999A */  ori       $at, $at, 0x999a
/* 4EFF84 80218AE4 44810000 */  mtc1      $at, $f0
/* 4EFF88 80218AE8 3C0542DC */  lui       $a1, 0x42dc
/* 4EFF8C 80218AEC 3C0642A0 */  lui       $a2, 0x42a0
/* 4EFF90 80218AF0 3C07C312 */  lui       $a3, 0xc312
/* 4EFF94 80218AF4 24040001 */  addiu     $a0, $zero, 1
/* 4EFF98 80218AF8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFF9C 80218AFC AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFFA0 80218B00 0C01C124 */  jal       func_80070490
/* 4EFFA4 80218B04 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4EFFA8 80218B08 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFFAC 80218B0C 24020002 */  addiu     $v0, $zero, 2
/* 4EFFB0 80218B10 03E00008 */  jr        $ra
/* 4EFFB4 80218B14 27BD0020 */   addiu    $sp, $sp, 0x20
