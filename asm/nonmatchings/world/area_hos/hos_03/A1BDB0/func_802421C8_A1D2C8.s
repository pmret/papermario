.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421C8_A1D2C8
/* A1D2C8 802421C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D2CC 802421CC AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D2D0 802421D0 0C03A631 */  jal       func_800E98C4
/* A1D2D4 802421D4 00000000 */   nop      
/* A1D2D8 802421D8 0C03A6DB */  jal       sync_status_menu
/* A1D2DC 802421DC 00000000 */   nop      
/* A1D2E0 802421E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D2E4 802421E4 24020002 */  addiu     $v0, $zero, 2
/* A1D2E8 802421E8 03E00008 */  jr        $ra
/* A1D2EC 802421EC 27BD0018 */   addiu    $sp, $sp, 0x18
