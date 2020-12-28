.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180C8_4CF278
/* 4CF278 802180C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF27C 802180CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF280 802180D0 0C03A698 */  jal       status_menu_start_blinking_sp
/* 4CF284 802180D4 00000000 */   nop      
/* 4CF288 802180D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF28C 802180DC 24020002 */  addiu     $v0, $zero, 2
/* 4CF290 802180E0 03E00008 */  jr        $ra
/* 4CF294 802180E4 27BD0018 */   addiu    $sp, $sp, 0x18
