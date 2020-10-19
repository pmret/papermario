.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F80
/* 833780 80241F80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 833784 80241F84 AFBF0010 */  sw        $ra, 0x10($sp)
/* 833788 80241F88 0C03A5B2 */  jal       func_800E96C8
/* 83378C 80241F8C 00000000 */   nop      
/* 833790 80241F90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 833794 80241F94 24020002 */  addiu     $v0, $zero, 2
/* 833798 80241F98 03E00008 */  jr        $ra
/* 83379C 80241F9C 27BD0018 */   addiu    $sp, $sp, 0x18
