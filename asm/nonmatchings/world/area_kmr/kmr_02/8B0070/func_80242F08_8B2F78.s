.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F08_8B2F78
/* 8B2F78 80242F08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2F7C 80242F0C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B2F80 80242F10 0C04760B */  jal       func_8011D82C
/* 8B2F84 80242F14 24040003 */   addiu    $a0, $zero, 3
/* 8B2F88 80242F18 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2F8C 80242F1C 24020002 */  addiu     $v0, $zero, 2
/* 8B2F90 80242F20 03E00008 */  jr        $ra
/* 8B2F94 80242F24 27BD0018 */   addiu    $sp, $sp, 0x18
