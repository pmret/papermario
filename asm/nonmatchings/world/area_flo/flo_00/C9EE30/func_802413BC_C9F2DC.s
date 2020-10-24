.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413BC_C9F2DC
/* C9F2DC 802413BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9F2E0 802413C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9F2E4 802413C4 0C03A6CC */  jal       decrement_status_menu_disabled
/* C9F2E8 802413C8 00000000 */   nop      
/* C9F2EC 802413CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9F2F0 802413D0 24020002 */  addiu     $v0, $zero, 2
/* C9F2F4 802413D4 03E00008 */  jr        $ra
/* C9F2F8 802413D8 27BD0018 */   addiu    $sp, $sp, 0x18
/* C9F2FC 802413DC 00000000 */  nop       
