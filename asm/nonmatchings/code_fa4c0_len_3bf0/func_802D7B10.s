.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7B10
/* FC4C0 802D7B10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FC4C4 802D7B14 AFBF0010 */  sw        $ra, 0x10($sp)
/* FC4C8 802D7B18 8C82000C */  lw        $v0, 0xc($a0)
/* FC4CC 802D7B1C 0C0B1EAF */  jal       get_variable
/* FC4D0 802D7B20 8C450000 */   lw       $a1, ($v0)
/* FC4D4 802D7B24 0040202D */  daddu     $a0, $v0, $zero
/* FC4D8 802D7B28 8C830000 */  lw        $v1, ($a0)
/* FC4DC 802D7B2C 34630010 */  ori       $v1, $v1, 0x10
/* FC4E0 802D7B30 AC830000 */  sw        $v1, ($a0)
/* FC4E4 802D7B34 8FBF0010 */  lw        $ra, 0x10($sp)
/* FC4E8 802D7B38 24020002 */  addiu     $v0, $zero, 2
/* FC4EC 802D7B3C 03E00008 */  jr        $ra
/* FC4F0 802D7B40 27BD0018 */   addiu    $sp, $sp, 0x18
