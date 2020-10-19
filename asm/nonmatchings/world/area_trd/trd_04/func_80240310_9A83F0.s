.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_9A8700
/* 9A8700 80240310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9A8704 80240314 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9A8708 80240318 0C04417A */  jal       get_entity_by_index
/* 9A870C 8024031C 8C840084 */   lw       $a0, 0x84($a0)
/* 9A8710 80240320 0040182D */  daddu     $v1, $v0, $zero
/* 9A8714 80240324 8C640000 */  lw        $a0, ($v1)
/* 9A8718 80240328 3C050010 */  lui       $a1, 0x10
/* 9A871C 8024032C 00852025 */  or        $a0, $a0, $a1
/* 9A8720 80240330 AC640000 */  sw        $a0, ($v1)
/* 9A8724 80240334 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9A8728 80240338 24020002 */  addiu     $v0, $zero, 2
/* 9A872C 8024033C 03E00008 */  jr        $ra
/* 9A8730 80240340 27BD0018 */   addiu    $sp, $sp, 0x18
