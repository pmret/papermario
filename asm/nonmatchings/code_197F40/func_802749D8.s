.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802749D8
/* 1A32B8 802749D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A32BC 802749DC AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A32C0 802749E0 0C095268 */  jal       func_802549A0
/* 1A32C4 802749E4 00000000 */   nop      
/* 1A32C8 802749E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A32CC 802749EC 24020002 */  addiu     $v0, $zero, 2
/* 1A32D0 802749F0 03E00008 */  jr        $ra
/* 1A32D4 802749F4 27BD0018 */   addiu    $sp, $sp, 0x18
