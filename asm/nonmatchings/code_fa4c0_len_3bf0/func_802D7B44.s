.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7B44
/* FC4F4 802D7B44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FC4F8 802D7B48 AFBF0010 */  sw        $ra, 0x10($sp)
/* FC4FC 802D7B4C 8C82000C */  lw        $v0, 0xc($a0)
/* FC500 802D7B50 0C0B1EAF */  jal       get_variable
/* FC504 802D7B54 8C450000 */   lw       $a1, ($v0)
/* FC508 802D7B58 8C44000C */  lw        $a0, 0xc($v0)
/* FC50C 802D7B5C 2403000A */  addiu     $v1, $zero, 0xa
/* FC510 802D7B60 AC830014 */  sw        $v1, 0x14($a0)
/* FC514 802D7B64 8FBF0010 */  lw        $ra, 0x10($sp)
/* FC518 802D7B68 24020002 */  addiu     $v0, $zero, 2
/* FC51C 802D7B6C 03E00008 */  jr        $ra
/* FC520 802D7B70 27BD0018 */   addiu    $sp, $sp, 0x18
