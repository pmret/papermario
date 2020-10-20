.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A8C
/* 9C5E6C 80240A8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C5E70 80240A90 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C5E74 80240A94 0C03A631 */  jal       func_800E98C4
/* 9C5E78 80240A98 00000000 */   nop      
/* 9C5E7C 80240A9C 0C03A6DB */  jal       sync_status_menu
/* 9C5E80 80240AA0 00000000 */   nop      
/* 9C5E84 80240AA4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C5E88 80240AA8 24020002 */  addiu     $v0, $zero, 2
/* 9C5E8C 80240AAC 03E00008 */  jr        $ra
/* 9C5E90 80240AB0 27BD0018 */   addiu    $sp, $sp, 0x18
