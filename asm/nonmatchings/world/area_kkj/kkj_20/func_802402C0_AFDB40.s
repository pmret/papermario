.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402C0_AFDE00
/* AFDE00 802402C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFDE04 802402C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFDE08 802402C8 0C03A625 */  jal       func_800E9894
/* AFDE0C 802402CC 00000000 */   nop      
/* AFDE10 802402D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFDE14 802402D4 24020002 */  addiu     $v0, $zero, 2
/* AFDE18 802402D8 03E00008 */  jr        $ra
/* AFDE1C 802402DC 27BD0018 */   addiu    $sp, $sp, 0x18
