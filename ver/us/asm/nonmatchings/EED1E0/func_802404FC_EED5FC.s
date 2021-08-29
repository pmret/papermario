.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404FC_EED5FC
/* EED5FC 802404FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EED600 80240500 AFBF0010 */  sw        $ra, 0x10($sp)
/* EED604 80240504 8C82000C */  lw        $v0, 0xc($a0)
/* EED608 80240508 0C0B53A3 */  jal       dead_evt_get_variable
/* EED60C 8024050C 8C450000 */   lw       $a1, ($v0)
/* EED610 80240510 0C03CB57 */  jal       func_800F2D5C
/* EED614 80240514 0040202D */   daddu    $a0, $v0, $zero
/* EED618 80240518 8FBF0010 */  lw        $ra, 0x10($sp)
/* EED61C 8024051C 24020002 */  addiu     $v0, $zero, 2
/* EED620 80240520 03E00008 */  jr        $ra
/* EED624 80240524 27BD0018 */   addiu    $sp, $sp, 0x18
