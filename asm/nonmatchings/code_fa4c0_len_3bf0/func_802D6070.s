.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D6070
/* FAA20 802D6070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FAA24 802D6074 AFBF0010 */  sw        $ra, 0x10($sp)
/* FAA28 802D6078 0C052BBE */  jal       func_8014AEF8
/* FAA2C 802D607C 00000000 */   nop      
/* FAA30 802D6080 8FBF0010 */  lw        $ra, 0x10($sp)
/* FAA34 802D6084 24020002 */  addiu     $v0, $zero, 2
/* FAA38 802D6088 03E00008 */  jr        $ra
/* FAA3C 802D608C 27BD0018 */   addiu    $sp, $sp, 0x18
