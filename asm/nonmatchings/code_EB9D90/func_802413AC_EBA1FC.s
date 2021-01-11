.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413AC_EBA1FC
/* EBA1FC 802413AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EBA200 802413B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* EBA204 802413B4 0C03C5CC */  jal       func_800F1730
/* EBA208 802413B8 00000000 */   nop      
/* EBA20C 802413BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* EBA210 802413C0 24020002 */  addiu     $v0, $zero, 2
/* EBA214 802413C4 03E00008 */  jr        $ra
/* EBA218 802413C8 27BD0018 */   addiu    $sp, $sp, 0x18
