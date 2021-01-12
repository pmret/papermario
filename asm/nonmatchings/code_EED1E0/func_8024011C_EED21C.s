.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024011C_EED21C
/* EED21C 8024011C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EED220 80240120 AFBF0010 */  sw        $ra, 0x10($sp)
/* EED224 80240124 8C82000C */  lw        $v0, 0xc($a0)
/* EED228 80240128 0C0B53A3 */  jal       func_802D4E8C
/* EED22C 8024012C 8C450000 */   lw       $a1, ($v0)
/* EED230 80240130 0C0BCEC0 */  jal       func_802F3B00
/* EED234 80240134 0040202D */   daddu    $a0, $v0, $zero
/* EED238 80240138 8FBF0010 */  lw        $ra, 0x10($sp)
/* EED23C 8024013C 24020002 */  addiu     $v0, $zero, 2
/* EED240 80240140 03E00008 */  jr        $ra
/* EED244 80240144 27BD0018 */   addiu    $sp, $sp, 0x18
