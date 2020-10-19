.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428E0
/* C38E10 802428E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C38E14 802428E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C38E18 802428E8 8C82000C */  lw        $v0, 0xc($a0)
/* C38E1C 802428EC 0C0B1EAF */  jal       get_variable
/* C38E20 802428F0 8C450000 */   lw       $a1, ($v0)
/* C38E24 802428F4 0040202D */  daddu     $a0, $v0, $zero
/* C38E28 802428F8 8C830000 */  lw        $v1, ($a0)
/* C38E2C 802428FC 34630010 */  ori       $v1, $v1, 0x10
/* C38E30 80242900 AC830000 */  sw        $v1, ($a0)
/* C38E34 80242904 8FBF0010 */  lw        $ra, 0x10($sp)
/* C38E38 80242908 24020002 */  addiu     $v0, $zero, 2
/* C38E3C 8024290C 03E00008 */  jr        $ra
/* C38E40 80242910 27BD0018 */   addiu    $sp, $sp, 0x18
