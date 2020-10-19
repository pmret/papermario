.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C20
/* 8447F0 80241C20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8447F4 80241C24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8447F8 80241C28 0C03A625 */  jal       func_800E9894
/* 8447FC 80241C2C 00000000 */   nop      
/* 844800 80241C30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 844804 80241C34 24020002 */  addiu     $v0, $zero, 2
/* 844808 80241C38 03E00008 */  jr        $ra
/* 84480C 80241C3C 27BD0018 */   addiu    $sp, $sp, 0x18
