.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00183BC
/* 32F93C E00183BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32F940 E00183C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 32F944 E00183C4 0C080128 */  jal       func_E02004A0
/* 32F948 E00183C8 00000000 */   nop      
/* 32F94C E00183CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 32F950 E00183D0 03E00008 */  jr        $ra
/* 32F954 E00183D4 27BD0018 */   addiu    $sp, $sp, 0x18
