.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0086398
/* 389BE8 E0086398 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 389BEC E008639C AFBF0010 */  sw        $ra, 0x10($sp)
/* 389BF0 E00863A0 0C0218ED */  jal       func_E00863B4
/* 389BF4 E00863A4 00000000 */   nop      
/* 389BF8 E00863A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 389BFC E00863AC 03E00008 */  jr        $ra
/* 389C00 E00863B0 27BD0018 */   addiu    $sp, $sp, 0x18
