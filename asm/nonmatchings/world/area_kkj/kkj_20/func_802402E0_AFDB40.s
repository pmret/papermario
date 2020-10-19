.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_AFDE20
/* AFDE20 802402E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFDE24 802402E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFDE28 802402E8 0C03A631 */  jal       func_800E98C4
/* AFDE2C 802402EC 00000000 */   nop      
/* AFDE30 802402F0 0C03A6DB */  jal       sync_status_menu
/* AFDE34 802402F4 00000000 */   nop      
/* AFDE38 802402F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFDE3C 802402FC 24020002 */  addiu     $v0, $zero, 2
/* AFDE40 80240300 03E00008 */  jr        $ra
/* AFDE44 80240304 27BD0018 */   addiu    $sp, $sp, 0x18
