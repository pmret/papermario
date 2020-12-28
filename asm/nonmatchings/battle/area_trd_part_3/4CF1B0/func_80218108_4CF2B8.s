.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218108_4CF2B8
/* 4CF2B8 80218108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF2BC 8021810C AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF2C0 80218110 0C03A648 */  jal       status_menu_start_blinking_hp
/* 4CF2C4 80218114 00000000 */   nop      
/* 4CF2C8 80218118 0C03A663 */  jal       status_menu_start_blinking_fp
/* 4CF2CC 8021811C 00000000 */   nop      
/* 4CF2D0 80218120 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF2D4 80218124 24020002 */  addiu     $v0, $zero, 2
/* 4CF2D8 80218128 03E00008 */  jr        $ra
/* 4CF2DC 8021812C 27BD0018 */   addiu    $sp, $sp, 0x18
