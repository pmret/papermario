.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044500
/* 1F900 80044500 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F904 80044504 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F908 80044508 0C0110DD */  jal       func_80044374
/* 1F90C 8004450C 2405FFFF */   addiu    $a1, $zero, -1
/* 1F910 80044510 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F914 80044514 24020001 */  addiu     $v0, $zero, 1
/* 1F918 80044518 03E00008 */  jr        $ra
/* 1F91C 8004451C 27BD0018 */   addiu    $sp, $sp, 0x18
