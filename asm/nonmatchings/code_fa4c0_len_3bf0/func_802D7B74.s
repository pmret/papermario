.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7B74
/* FC524 802D7B74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FC528 802D7B78 AFBF0010 */  sw        $ra, 0x10($sp)
/* FC52C 802D7B7C 8C82000C */  lw        $v0, 0xc($a0)
/* FC530 802D7B80 0C0B1EAF */  jal       get_variable
/* FC534 802D7B84 8C450000 */   lw       $a1, ($v0)
/* FC538 802D7B88 8C44000C */  lw        $a0, 0xc($v0)
/* FC53C 802D7B8C 24030005 */  addiu     $v1, $zero, 5
/* FC540 802D7B90 AC830030 */  sw        $v1, 0x30($a0)
/* FC544 802D7B94 8FBF0010 */  lw        $ra, 0x10($sp)
/* FC548 802D7B98 24020002 */  addiu     $v0, $zero, 2
/* FC54C 802D7B9C 03E00008 */  jr        $ra
/* FC550 802D7BA0 27BD0018 */   addiu    $sp, $sp, 0x18
