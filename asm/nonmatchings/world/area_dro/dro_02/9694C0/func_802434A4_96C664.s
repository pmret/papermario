.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802434A4_96C664
/* 96C664 802434A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C668 802434A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C66C 802434AC 0C03A631 */  jal       func_800E98C4
/* 96C670 802434B0 00000000 */   nop      
/* 96C674 802434B4 0C03A6DB */  jal       sync_status_menu
/* 96C678 802434B8 00000000 */   nop      
/* 96C67C 802434BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C680 802434C0 24020002 */  addiu     $v0, $zero, 2
/* 96C684 802434C4 03E00008 */  jr        $ra
/* 96C688 802434C8 27BD0018 */   addiu    $sp, $sp, 0x18
