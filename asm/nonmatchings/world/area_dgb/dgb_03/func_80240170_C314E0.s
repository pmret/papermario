.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240170_C31650
/* C31650 80240170 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C31654 80240174 AFBF0010 */  sw        $ra, 0x10($sp)
/* C31658 80240178 0C04417A */  jal       get_entity_by_index
/* C3165C 8024017C 8C840084 */   lw       $a0, 0x84($a0)
/* C31660 80240180 0040182D */  daddu     $v1, $v0, $zero
/* C31664 80240184 8C640000 */  lw        $a0, ($v1)
/* C31668 80240188 3C050010 */  lui       $a1, 0x10
/* C3166C 8024018C 00852025 */  or        $a0, $a0, $a1
/* C31670 80240190 AC640000 */  sw        $a0, ($v1)
/* C31674 80240194 8FBF0010 */  lw        $ra, 0x10($sp)
/* C31678 80240198 24020002 */  addiu     $v0, $zero, 2
/* C3167C 8024019C 03E00008 */  jr        $ra
/* C31680 802401A0 27BD0018 */   addiu    $sp, $sp, 0x18
