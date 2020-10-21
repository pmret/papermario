.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024293C_8B29AC
/* 8B29AC 8024293C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B29B0 80242940 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B29B4 80242944 0C03A6DB */  jal       sync_status_menu
/* 8B29B8 80242948 00000000 */   nop      
/* 8B29BC 8024294C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B29C0 80242950 24020002 */  addiu     $v0, $zero, 2
/* 8B29C4 80242954 03E00008 */  jr        $ra
/* 8B29C8 80242958 27BD0018 */   addiu    $sp, $sp, 0x18
