.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C60_844830
/* 844830 80241C60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844834 80241C64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 844838 80241C68 0C03A631 */  jal       func_800E98C4
/* 84483C 80241C6C 00000000 */   nop      
/* 844840 80241C70 0C03A5D8 */  jal       open_status_menu_long
/* 844844 80241C74 00000000 */   nop      
/* 844848 80241C78 8FBF0010 */  lw        $ra, 0x10($sp)
/* 84484C 80241C7C 24020002 */  addiu     $v0, $zero, 2
/* 844850 80241C80 03E00008 */  jr        $ra
/* 844854 80241C84 27BD0018 */   addiu    $sp, $sp, 0x18
/* 844858 80241C88 00000000 */  nop       
/* 84485C 80241C8C 00000000 */  nop       
