.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5FD8
/* FA988 802D5FD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FA98C 802D5FDC AFBF0010 */  sw        $ra, 0x10($sp)
/* FA990 802D5FE0 0C052B69 */  jal       func_8014ADA4
/* FA994 802D5FE4 00000000 */   nop      
/* FA998 802D5FE8 8FBF0010 */  lw        $ra, 0x10($sp)
/* FA99C 802D5FEC 24020002 */  addiu     $v0, $zero, 2
/* FA9A0 802D5FF0 03E00008 */  jr        $ra
/* FA9A4 802D5FF4 27BD0018 */   addiu    $sp, $sp, 0x18
