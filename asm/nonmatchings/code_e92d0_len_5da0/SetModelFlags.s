.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetModelFlags
/* 0EDEC8 802C9518 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDECC 802C951C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDED0 802C9520 0080802D */  daddu $s0, $a0, $zero
/* 0EDED4 802C9524 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EDED8 802C9528 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDEDC 802C952C 8E11000C */  lw    $s1, 0xc($s0)
/* 0EDEE0 802C9530 8E250000 */  lw    $a1, ($s1)
/* 0EDEE4 802C9534 0C0B1EAF */  jal   get_variable
/* 0EDEE8 802C9538 26310004 */   addiu $s1, $s1, 4
/* 0EDEEC 802C953C 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EDEF0 802C9540 0040202D */   daddu $a0, $v0, $zero
/* 0EDEF4 802C9544 0200202D */  daddu $a0, $s0, $zero
/* 0EDEF8 802C9548 8E250004 */  lw    $a1, 4($s1)
/* 0EDEFC 802C954C 8E310000 */  lw    $s1, ($s1)
/* 0EDF00 802C9550 0C0B1EAF */  jal   get_variable
/* 0EDF04 802C9554 0040802D */   daddu $s0, $v0, $zero
/* 0EDF08 802C9558 0200202D */  daddu $a0, $s0, $zero
/* 0EDF0C 802C955C 0C046B4C */  jal   get_model_from_list_index
/* 0EDF10 802C9560 0040802D */   daddu $s0, $v0, $zero
/* 0EDF14 802C9564 12000004 */  beqz  $s0, .L802C9578
/* 0EDF18 802C9568 0040202D */   daddu $a0, $v0, $zero
/* 0EDF1C 802C956C 94820000 */  lhu   $v0, ($a0)
/* 0EDF20 802C9570 080B2561 */  j     .L802C9584
/* 0EDF24 802C9574 00511025 */   or    $v0, $v0, $s1

.L802C9578:
/* 0EDF28 802C9578 94820000 */  lhu   $v0, ($a0)
/* 0EDF2C 802C957C 00111827 */  nor   $v1, $zero, $s1
/* 0EDF30 802C9580 00431024 */  and   $v0, $v0, $v1
.L802C9584:
/* 0EDF34 802C9584 A4820000 */  sh    $v0, ($a0)
/* 0EDF38 802C9588 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EDF3C 802C958C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDF40 802C9590 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDF44 802C9594 24020002 */  addiu $v0, $zero, 2
/* 0EDF48 802C9598 03E00008 */  jr    $ra
/* 0EDF4C 802C959C 27BD0020 */   addiu $sp, $sp, 0x20

