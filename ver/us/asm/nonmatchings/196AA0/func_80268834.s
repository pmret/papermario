.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80268834
/* 197114 80268834 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197118 80268838 3C01802A */  lui       $at, %hi(D_8029FBC0)
/* 19711C 8026883C AC27FBC0 */  sw        $a3, %lo(D_8029FBC0)($at)
/* 197120 80268840 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197124 80268844 0C09A0A1 */  jal       func_80268284
/* 197128 80268848 2407FFFF */   addiu    $a3, $zero, -1
/* 19712C 8026884C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197130 80268850 03E00008 */  jr        $ra
/* 197134 80268854 27BD0018 */   addiu    $sp, $sp, 0x18
