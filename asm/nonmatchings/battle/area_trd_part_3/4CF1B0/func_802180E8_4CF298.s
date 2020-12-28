.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180E8_4CF298
/* 4CF298 802180E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF29C 802180EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF2A0 802180F0 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 4CF2A4 802180F4 00000000 */   nop      
/* 4CF2A8 802180F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF2AC 802180FC 24020002 */  addiu     $v0, $zero, 2
/* 4CF2B0 80218100 03E00008 */  jr        $ra
/* 4CF2B4 80218104 27BD0018 */   addiu    $sp, $sp, 0x18
