.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240280_D3A850
/* D3A850 80240280 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3A854 80240284 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3A858 80240288 0C04417A */  jal       get_entity_by_index
/* D3A85C 8024028C 8C840084 */   lw       $a0, 0x84($a0)
/* D3A860 80240290 0040182D */  daddu     $v1, $v0, $zero
/* D3A864 80240294 8C640000 */  lw        $a0, ($v1)
/* D3A868 80240298 3C050010 */  lui       $a1, 0x10
/* D3A86C 8024029C 00852025 */  or        $a0, $a0, $a1
/* D3A870 802402A0 AC640000 */  sw        $a0, ($v1)
/* D3A874 802402A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3A878 802402A8 24020002 */  addiu     $v0, $zero, 2
/* D3A87C 802402AC 03E00008 */  jr        $ra
/* D3A880 802402B0 27BD0018 */   addiu    $sp, $sp, 0x18
