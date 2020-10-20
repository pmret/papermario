.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414D0
/* B360A0 802414D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B360A4 802414D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B360A8 802414D8 0C03A631 */  jal       func_800E98C4
/* B360AC 802414DC 00000000 */   nop      
/* B360B0 802414E0 0C03A6DB */  jal       sync_status_menu
/* B360B4 802414E4 00000000 */   nop      
/* B360B8 802414E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B360BC 802414EC 24020002 */  addiu     $v0, $zero, 2
/* B360C0 802414F0 03E00008 */  jr        $ra
/* B360C4 802414F4 27BD0018 */   addiu    $sp, $sp, 0x18
