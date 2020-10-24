.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241830_A88280
/* A88280 80241830 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A88284 80241834 AFBF0010 */  sw        $ra, 0x10($sp)
/* A88288 80241838 0C04417A */  jal       get_entity_by_index
/* A8828C 8024183C 8C840084 */   lw       $a0, 0x84($a0)
/* A88290 80241840 0040182D */  daddu     $v1, $v0, $zero
/* A88294 80241844 8C640000 */  lw        $a0, ($v1)
/* A88298 80241848 3C050010 */  lui       $a1, 0x10
/* A8829C 8024184C 00852025 */  or        $a0, $a0, $a1
/* A882A0 80241850 AC640000 */  sw        $a0, ($v1)
/* A882A4 80241854 8FBF0010 */  lw        $ra, 0x10($sp)
/* A882A8 80241858 24020002 */  addiu     $v0, $zero, 2
/* A882AC 8024185C 03E00008 */  jr        $ra
/* A882B0 80241860 27BD0018 */   addiu    $sp, $sp, 0x18
