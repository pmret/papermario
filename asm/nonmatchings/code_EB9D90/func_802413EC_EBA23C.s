.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413EC_EBA23C
/* EBA23C 802413EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EBA240 802413F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* EBA244 802413F4 0C03C5BD */  jal       func_800F16F4
/* EBA248 802413F8 00000000 */   nop      
/* EBA24C 802413FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* EBA250 80241400 24020002 */  addiu     $v0, $zero, 2
/* EBA254 80241404 03E00008 */  jr        $ra
/* EBA258 80241408 27BD0018 */   addiu    $sp, $sp, 0x18
/* EBA25C 8024140C 00000000 */  nop       
