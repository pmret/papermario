.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EB0
/* 844A80 80241EB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844A84 80241EB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 844A88 80241EB8 0C04417A */  jal       get_entity_by_index
/* 844A8C 80241EBC 8C840084 */   lw       $a0, 0x84($a0)
/* 844A90 80241EC0 0040182D */  daddu     $v1, $v0, $zero
/* 844A94 80241EC4 8C640000 */  lw        $a0, ($v1)
/* 844A98 80241EC8 3C050010 */  lui       $a1, 0x10
/* 844A9C 80241ECC 00852025 */  or        $a0, $a0, $a1
/* 844AA0 80241ED0 AC640000 */  sw        $a0, ($v1)
/* 844AA4 80241ED4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 844AA8 80241ED8 24020002 */  addiu     $v0, $zero, 2
/* 844AAC 80241EDC 03E00008 */  jr        $ra
/* 844AB0 80241EE0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 844AB4 80241EE4 00000000 */  nop       
/* 844AB8 80241EE8 00000000 */  nop       
/* 844ABC 80241EEC 00000000 */  nop       
