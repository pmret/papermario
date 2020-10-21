.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C0_8ED0E0
/* 8ED0E0 802412C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED0E4 802412C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED0E8 802412C8 0C03A631 */  jal       func_800E98C4
/* 8ED0EC 802412CC 00000000 */   nop      
/* 8ED0F0 802412D0 0C03A6DB */  jal       sync_status_menu
/* 8ED0F4 802412D4 00000000 */   nop      
/* 8ED0F8 802412D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED0FC 802412DC 24020002 */  addiu     $v0, $zero, 2
/* 8ED100 802412E0 03E00008 */  jr        $ra
/* 8ED104 802412E4 27BD0018 */   addiu    $sp, $sp, 0x18
