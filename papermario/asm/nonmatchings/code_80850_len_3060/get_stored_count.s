.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_stored_count
/* 080CC4 800E7814 0000202D */  daddu $a0, $zero, $zero
/* 080CC8 800E7818 0080282D */  daddu $a1, $a0, $zero
/* 080CCC 800E781C 3C038011 */  lui   $v1, 0x8011
/* 080CD0 800E7820 2463F290 */  addiu $v1, $v1, -0xd70
.L800E7824:
/* 080CD4 800E7824 846201C8 */  lh    $v0, 0x1c8($v1)
/* 080CD8 800E7828 54400001 */  bnezl $v0, .L800E7830
/* 080CDC 800E782C 24A50001 */   addiu $a1, $a1, 1
.L800E7830:
/* 080CE0 800E7830 24840001 */  addiu $a0, $a0, 1
/* 080CE4 800E7834 28820020 */  slti  $v0, $a0, 0x20
/* 080CE8 800E7838 1440FFFA */  bnez  $v0, .L800E7824
/* 080CEC 800E783C 24630002 */   addiu $v1, $v1, 2
/* 080CF0 800E7840 03E00008 */  jr    $ra
/* 080CF4 800E7844 00A0102D */   daddu $v0, $a1, $zero

