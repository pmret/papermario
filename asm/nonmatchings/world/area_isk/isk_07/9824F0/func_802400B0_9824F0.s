.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_9824F0
/* 9824F0 802400B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9824F4 802400B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9824F8 802400B8 0C04417A */  jal       get_entity_by_index
/* 9824FC 802400BC 8C840084 */   lw       $a0, 0x84($a0)
/* 982500 802400C0 0040182D */  daddu     $v1, $v0, $zero
/* 982504 802400C4 8C640000 */  lw        $a0, ($v1)
/* 982508 802400C8 3C050010 */  lui       $a1, 0x10
/* 98250C 802400CC 00852025 */  or        $a0, $a0, $a1
/* 982510 802400D0 AC640000 */  sw        $a0, ($v1)
/* 982514 802400D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 982518 802400D8 24020002 */  addiu     $v0, $zero, 2
/* 98251C 802400DC 03E00008 */  jr        $ra
/* 982520 802400E0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 982524 802400E4 00000000 */  nop       
/* 982528 802400E8 00000000 */  nop       
/* 98252C 802400EC 00000000 */  nop       
