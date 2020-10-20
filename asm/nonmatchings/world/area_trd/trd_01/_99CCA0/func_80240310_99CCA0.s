.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_99CCA0
/* 99CCA0 80240310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99CCA4 80240314 AFBF0010 */  sw        $ra, 0x10($sp)
/* 99CCA8 80240318 0C04417A */  jal       get_entity_by_index
/* 99CCAC 8024031C 8C840084 */   lw       $a0, 0x84($a0)
/* 99CCB0 80240320 0040182D */  daddu     $v1, $v0, $zero
/* 99CCB4 80240324 8C640000 */  lw        $a0, ($v1)
/* 99CCB8 80240328 3C050010 */  lui       $a1, 0x10
/* 99CCBC 8024032C 00852025 */  or        $a0, $a0, $a1
/* 99CCC0 80240330 AC640000 */  sw        $a0, ($v1)
/* 99CCC4 80240334 8FBF0010 */  lw        $ra, 0x10($sp)
/* 99CCC8 80240338 24020002 */  addiu     $v0, $zero, 2
/* 99CCCC 8024033C 03E00008 */  jr        $ra
/* 99CCD0 80240340 27BD0018 */   addiu    $sp, $sp, 0x18
