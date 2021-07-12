.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219E40_63F020
/* 63F020 80219E40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63F024 80219E44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63F028 80219E48 0C051C83 */  jal       enable_background_wave
/* 63F02C 80219E4C 00000000 */   nop
/* 63F030 80219E50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63F034 80219E54 03E00008 */  jr        $ra
/* 63F038 80219E58 27BD0018 */   addiu    $sp, $sp, 0x18
/* 63F03C 80219E5C 00000000 */  nop
