.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241830_C50D40
/* C50D40 80241830 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C50D44 80241834 AFBF0010 */  sw        $ra, 0x10($sp)
/* C50D48 80241838 0C04417A */  jal       get_entity_by_index
/* C50D4C 8024183C 8C840084 */   lw       $a0, 0x84($a0)
/* C50D50 80241840 0040182D */  daddu     $v1, $v0, $zero
/* C50D54 80241844 8C640000 */  lw        $a0, ($v1)
/* C50D58 80241848 3C050010 */  lui       $a1, 0x10
/* C50D5C 8024184C 00852025 */  or        $a0, $a0, $a1
/* C50D60 80241850 AC640000 */  sw        $a0, ($v1)
/* C50D64 80241854 8FBF0010 */  lw        $ra, 0x10($sp)
/* C50D68 80241858 24020002 */  addiu     $v0, $zero, 2
/* C50D6C 8024185C 03E00008 */  jr        $ra
/* C50D70 80241860 27BD0018 */   addiu    $sp, $sp, 0x18
/* C50D74 80241864 00000000 */  nop       
/* C50D78 80241868 00000000 */  nop       
/* C50D7C 8024186C 00000000 */  nop       
