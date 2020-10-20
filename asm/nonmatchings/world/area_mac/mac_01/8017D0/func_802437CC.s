.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802437CC
/* 80404C 802437CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 804050 802437D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 804054 802437D4 0C03A631 */  jal       func_800E98C4
/* 804058 802437D8 00000000 */   nop      
/* 80405C 802437DC 0C03A6DB */  jal       sync_status_menu
/* 804060 802437E0 00000000 */   nop      
/* 804064 802437E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 804068 802437E8 24020002 */  addiu     $v0, $zero, 2
/* 80406C 802437EC 03E00008 */  jr        $ra
/* 804070 802437F0 27BD0018 */   addiu    $sp, $sp, 0x18
