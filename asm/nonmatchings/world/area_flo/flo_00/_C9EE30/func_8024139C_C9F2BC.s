.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024139C_C9F2BC
/* C9F2BC 8024139C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9F2C0 802413A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9F2C4 802413A4 0C03A6D5 */  jal       increment_status_menu_disabled
/* C9F2C8 802413A8 00000000 */   nop      
/* C9F2CC 802413AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9F2D0 802413B0 24020002 */  addiu     $v0, $zero, 2
/* C9F2D4 802413B4 03E00008 */  jr        $ra
/* C9F2D8 802413B8 27BD0018 */   addiu    $sp, $sp, 0x18
