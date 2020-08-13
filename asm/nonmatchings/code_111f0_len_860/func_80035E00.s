.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80035E00
/* 011200 80035E00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 011204 80035E04 AFBF0010 */  sw    $ra, 0x10($sp)
/* 011208 80035E08 3C01800A */  lui   $at, 0x800a
/* 01120C 80035E0C A4200948 */  sh    $zero, 0x948($at)
/* 011210 80035E10 0C00D795 */  jal   func_80035E54
/* 011214 80035E14 00000000 */   nop   
/* 011218 80035E18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01121C 80035E1C 03E00008 */  jr    $ra
/* 011220 80035E20 27BD0018 */   addiu $sp, $sp, 0x18

