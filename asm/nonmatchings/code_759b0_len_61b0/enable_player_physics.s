.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel enable_player_physics
/* 0795C4 800E0114 3C038011 */  lui   $v1, 0x8011
/* 0795C8 800E0118 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0795CC 800E011C 8C640000 */  lw    $a0, ($v1)
/* 0795D0 800E0120 90620014 */  lbu   $v0, 0x14($v1)
/* 0795D4 800E0124 34841000 */  ori   $a0, $a0, 0x1000
/* 0795D8 800E0128 24420001 */  addiu $v0, $v0, 1
/* 0795DC 800E012C A0620014 */  sb    $v0, 0x14($v1)
/* 0795E0 800E0130 00021600 */  sll   $v0, $v0, 0x18
/* 0795E4 800E0134 00021603 */  sra   $v0, $v0, 0x18
/* 0795E8 800E0138 03E00008 */  jr    $ra
/* 0795EC 800E013C AC640000 */   sw    $a0, ($v1)

