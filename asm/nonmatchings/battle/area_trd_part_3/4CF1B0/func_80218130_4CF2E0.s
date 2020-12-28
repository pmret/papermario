.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218130_4CF2E0
/* 4CF2E0 80218130 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF2E4 80218134 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF2E8 80218138 0C03A659 */  jal       status_menu_stop_blinking_hp
/* 4CF2EC 8021813C 00000000 */   nop      
/* 4CF2F0 80218140 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 4CF2F4 80218144 00000000 */   nop      
/* 4CF2F8 80218148 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF2FC 8021814C 24020002 */  addiu     $v0, $zero, 2
/* 4CF300 80218150 03E00008 */  jr        $ra
/* 4CF304 80218154 27BD0018 */   addiu    $sp, $sp, 0x18
