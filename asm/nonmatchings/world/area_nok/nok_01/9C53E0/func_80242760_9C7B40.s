.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242760_9C7B40
/* 9C7B40 80242760 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7B44 80242764 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7B48 80242768 0C03A63B */  jal       func_800E98EC
/* 9C7B4C 8024276C 00000000 */   nop      
/* 9C7B50 80242770 0C03A625 */  jal       func_800E9894
/* 9C7B54 80242774 00000000 */   nop      
/* 9C7B58 80242778 0C03A5D8 */  jal       open_status_menu_long
/* 9C7B5C 8024277C 00000000 */   nop      
/* 9C7B60 80242780 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7B64 80242784 24020002 */  addiu     $v0, $zero, 2
/* 9C7B68 80242788 03E00008 */  jr        $ra
/* 9C7B6C 8024278C 27BD0018 */   addiu    $sp, $sp, 0x18
