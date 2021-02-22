.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F4_C6EB24
/* C6EB24 802407F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C6EB28 802407F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* C6EB2C 802407FC 0C04417A */  jal       get_entity_by_index
/* C6EB30 80240800 8C840084 */   lw       $a0, 0x84($a0)
/* C6EB34 80240804 8C440040 */  lw        $a0, 0x40($v0)
/* C6EB38 80240808 24030001 */  addiu     $v1, $zero, 1
/* C6EB3C 8024080C A0830030 */  sb        $v1, 0x30($a0)
/* C6EB40 80240810 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6EB44 80240814 24020002 */  addiu     $v0, $zero, 2
/* C6EB48 80240818 03E00008 */  jr        $ra
/* C6EB4C 8024081C 27BD0018 */   addiu    $sp, $sp, 0x18
