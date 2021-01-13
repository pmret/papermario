.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C40_844810
/* 844810 80241C40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844814 80241C44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 844818 80241C48 0C03A631 */  jal       func_800E98C4
/* 84481C 80241C4C 00000000 */   nop
/* 844820 80241C50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 844824 80241C54 24020002 */  addiu     $v0, $zero, 2
/* 844828 80241C58 03E00008 */  jr        $ra
/* 84482C 80241C5C 27BD0018 */   addiu    $sp, $sp, 0x18
