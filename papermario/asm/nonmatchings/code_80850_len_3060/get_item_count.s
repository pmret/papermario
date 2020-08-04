.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_item_count
/* 080A9C 800E75EC 0000202D */  daddu $a0, $zero, $zero
/* 080AA0 800E75F0 0080282D */  daddu $a1, $a0, $zero
/* 080AA4 800E75F4 3C038011 */  lui   $v1, 0x8011
/* 080AA8 800E75F8 2463F290 */  addiu $v1, $v1, -0xd70
.L800E75FC:
/* 080AAC 800E75FC 846201B4 */  lh    $v0, 0x1b4($v1)
/* 080AB0 800E7600 54400001 */  bnezl $v0, .L800E7608
/* 080AB4 800E7604 24A50001 */   addiu $a1, $a1, 1
.L800E7608:
/* 080AB8 800E7608 24840001 */  addiu $a0, $a0, 1
/* 080ABC 800E760C 2882000A */  slti  $v0, $a0, 0xa
/* 080AC0 800E7610 1440FFFA */  bnez  $v0, .L800E75FC
/* 080AC4 800E7614 24630002 */   addiu $v1, $v1, 2
/* 080AC8 800E7618 03E00008 */  jr    $ra
/* 080ACC 800E761C 00A0102D */   daddu $v0, $a1, $zero

