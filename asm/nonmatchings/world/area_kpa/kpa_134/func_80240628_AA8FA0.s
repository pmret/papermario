.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240628_AA95C8
/* AA95C8 80240628 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AA95CC 8024062C AFBF0010 */  sw        $ra, 0x10($sp)
/* AA95D0 80240630 0C04417A */  jal       get_entity_by_index
/* AA95D4 80240634 8C840084 */   lw       $a0, 0x84($a0)
/* AA95D8 80240638 0040182D */  daddu     $v1, $v0, $zero
/* AA95DC 8024063C 8C640000 */  lw        $a0, ($v1)
/* AA95E0 80240640 3C050010 */  lui       $a1, 0x10
/* AA95E4 80240644 00852025 */  or        $a0, $a0, $a1
/* AA95E8 80240648 AC640000 */  sw        $a0, ($v1)
/* AA95EC 8024064C 8FBF0010 */  lw        $ra, 0x10($sp)
/* AA95F0 80240650 24020002 */  addiu     $v0, $zero, 2
/* AA95F4 80240654 03E00008 */  jr        $ra
/* AA95F8 80240658 27BD0018 */   addiu    $sp, $sp, 0x18
