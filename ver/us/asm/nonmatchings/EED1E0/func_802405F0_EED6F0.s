.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F0_EED6F0
/* EED6F0 802405F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EED6F4 802405F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* EED6F8 802405F8 8C82000C */  lw        $v0, 0xc($a0)
/* EED6FC 802405FC 0C0B53A3 */  jal       dead_get_variable
/* EED700 80240600 8C450000 */   lw       $a1, ($v0)
/* EED704 80240604 0040202D */  daddu     $a0, $v0, $zero
/* EED708 80240608 8C830000 */  lw        $v1, ($a0)
/* EED70C 8024060C 34630010 */  ori       $v1, $v1, 0x10
/* EED710 80240610 AC830000 */  sw        $v1, ($a0)
/* EED714 80240614 8FBF0010 */  lw        $ra, 0x10($sp)
/* EED718 80240618 24020002 */  addiu     $v0, $zero, 2
/* EED71C 8024061C 03E00008 */  jr        $ra
/* EED720 80240620 27BD0018 */   addiu    $sp, $sp, 0x18
