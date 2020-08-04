.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel update_item_entity_static
/* 0CBD58 80135658 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0CBD5C 8013565C AFB00010 */  sw    $s0, 0x10($sp)
/* 0CBD60 80135660 0080802D */  daddu $s0, $a0, $zero
/* 0CBD64 80135664 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CBD68 80135668 8202001A */  lb    $v0, 0x1a($s0)
/* 0CBD6C 8013566C 14400011 */  bnez  $v0, .L801356B4
/* 0CBD70 80135670 00000000 */   nop   
/* 0CBD74 80135674 0C04CEC3 */  jal   test_item_player_collision
/* 0CBD78 80135678 00000000 */   nop   
/* 0CBD7C 8013567C 1040000D */  beqz  $v0, .L801356B4
/* 0CBD80 80135680 24020001 */   addiu $v0, $zero, 1
/* 0CBD84 80135684 3C018015 */  lui   $at, 0x8015
/* 0CBD88 80135688 A42265A4 */  sh    $v0, 0x65a4($at)
/* 0CBD8C 8013568C 2402001C */  addiu $v0, $zero, 0x1c
/* 0CBD90 80135690 3C03800A */  lui   $v1, 0x800a
/* 0CBD94 80135694 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0CBD98 80135698 A202001B */  sb    $v0, 0x1b($s0)
/* 0CBD9C 8013569C A200001A */  sb    $zero, 0x1a($s0)
/* 0CBDA0 801356A0 8C620000 */  lw    $v0, ($v1)
/* 0CBDA4 801356A4 3C018015 */  lui   $at, 0x8015
/* 0CBDA8 801356A8 A42065A8 */  sh    $zero, 0x65a8($at)
/* 0CBDAC 801356AC 34420040 */  ori   $v0, $v0, 0x40
/* 0CBDB0 801356B0 AC620000 */  sw    $v0, ($v1)
.L801356B4:
/* 0CBDB4 801356B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CBDB8 801356B8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0CBDBC 801356BC 03E00008 */  jr    $ra
/* 0CBDC0 801356C0 27BD0018 */   addiu $sp, $sp, 0x18

