.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413CC_EBA21C
/* EBA21C 802413CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EBA220 802413D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* EBA224 802413D4 0C03C5C6 */  jal       func_800F1718
/* EBA228 802413D8 00000000 */   nop      
/* EBA22C 802413DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* EBA230 802413E0 24020002 */  addiu     $v0, $zero, 2
/* EBA234 802413E4 03E00008 */  jr        $ra
/* EBA238 802413E8 27BD0018 */   addiu    $sp, $sp, 0x18
