.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D6050
/* FAA00 802D6050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FAA04 802D6054 AFBF0010 */  sw        $ra, 0x10($sp)
/* FAA08 802D6058 0C052B9B */  jal       func_8014AE6C
/* FAA0C 802D605C 00000000 */   nop      
/* FAA10 802D6060 8FBF0010 */  lw        $ra, 0x10($sp)
/* FAA14 802D6064 24020002 */  addiu     $v0, $zero, 2
/* FAA18 802D6068 03E00008 */  jr        $ra
/* FAA1C 802D606C 27BD0018 */   addiu    $sp, $sp, 0x18
