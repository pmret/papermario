.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D8C2D0
/* D8C2D0 80240F20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8C2D4 80240F24 AFBF0010 */  sw        $ra, 0x10($sp)
/* D8C2D8 80240F28 0C04417A */  jal       get_entity_by_index
/* D8C2DC 80240F2C 8C840084 */   lw       $a0, 0x84($a0)
/* D8C2E0 80240F30 0040182D */  daddu     $v1, $v0, $zero
/* D8C2E4 80240F34 8C640000 */  lw        $a0, ($v1)
/* D8C2E8 80240F38 3C050010 */  lui       $a1, 0x10
/* D8C2EC 80240F3C 00852025 */  or        $a0, $a0, $a1
/* D8C2F0 80240F40 AC640000 */  sw        $a0, ($v1)
/* D8C2F4 80240F44 8FBF0010 */  lw        $ra, 0x10($sp)
/* D8C2F8 80240F48 24020002 */  addiu     $v0, $zero, 2
/* D8C2FC 80240F4C 03E00008 */  jr        $ra
/* D8C300 80240F50 27BD0018 */   addiu    $sp, $sp, 0x18
