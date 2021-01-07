.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80231000_54CC70
/* 54CC70 80231000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 54CC74 80231004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 54CC78 80231008 8C82000C */  lw        $v0, 0xc($a0)
/* 54CC7C 8023100C 0C0B1EAF */  jal       get_variable
/* 54CC80 80231010 8C450004 */   lw       $a1, 4($v0)
/* 54CC84 80231014 8FBF0010 */  lw        $ra, 0x10($sp)
/* 54CC88 80231018 24020002 */  addiu     $v0, $zero, 2
/* 54CC8C 8023101C 03E00008 */  jr        $ra
/* 54CC90 80231020 27BD0018 */   addiu    $sp, $sp, 0x18
/* 54CC94 80231024 00000000 */  nop       
/* 54CC98 80231028 00000000 */  nop       
/* 54CC9C 8023102C 00000000 */  nop       
