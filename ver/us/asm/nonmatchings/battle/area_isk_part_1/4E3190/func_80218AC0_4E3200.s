.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AC0_4E3200
/* 4E3200 80218AC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4E3204 80218AC4 3C028022 */  lui       $v0, %hi(D_80224D90)
/* 4E3208 80218AC8 24424D90 */  addiu     $v0, $v0, %lo(D_80224D90)
/* 4E320C 80218ACC 3C013E99 */  lui       $at, 0x3e99
/* 4E3210 80218AD0 3421999A */  ori       $at, $at, 0x999a
/* 4E3214 80218AD4 44810000 */  mtc1      $at, $f0
/* 4E3218 80218AD8 3C0542DC */  lui       $a1, 0x42dc
/* 4E321C 80218ADC 3C0642A0 */  lui       $a2, 0x42a0
/* 4E3220 80218AE0 3C07C312 */  lui       $a3, 0xc312
/* 4E3224 80218AE4 24040001 */  addiu     $a0, $zero, 1
/* 4E3228 80218AE8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E322C 80218AEC AFA20014 */  sw        $v0, 0x14($sp)
/* 4E3230 80218AF0 0C01C124 */  jal       func_80070490
/* 4E3234 80218AF4 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4E3238 80218AF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E323C 80218AFC 24020002 */  addiu     $v0, $zero, 2
/* 4E3240 80218B00 03E00008 */  jr        $ra
/* 4E3244 80218B04 27BD0020 */   addiu    $sp, $sp, 0x20
