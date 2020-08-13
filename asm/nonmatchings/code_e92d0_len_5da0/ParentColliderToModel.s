.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ParentColliderToModel
/* 0EEAC4 802CA114 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EEAC8 802CA118 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EEACC 802CA11C 0080882D */  daddu $s1, $a0, $zero
/* 0EEAD0 802CA120 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EEAD4 802CA124 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EEAD8 802CA128 8E30000C */  lw    $s0, 0xc($s1)
/* 0EEADC 802CA12C 8E050000 */  lw    $a1, ($s0)
/* 0EEAE0 802CA130 0C0B1EAF */  jal   get_variable
/* 0EEAE4 802CA134 26100004 */   addiu $s0, $s0, 4
/* 0EEAE8 802CA138 0220202D */  daddu $a0, $s1, $zero
/* 0EEAEC 802CA13C 8E050000 */  lw    $a1, ($s0)
/* 0EEAF0 802CA140 0C0B1EAF */  jal   get_variable
/* 0EEAF4 802CA144 0040802D */   daddu $s0, $v0, $zero
/* 0EEAF8 802CA148 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EEAFC 802CA14C 0040202D */   daddu $a0, $v0, $zero
/* 0EEB00 802CA150 00108400 */  sll   $s0, $s0, 0x10
/* 0EEB04 802CA154 00108403 */  sra   $s0, $s0, 0x10
/* 0EEB08 802CA158 0200202D */  daddu $a0, $s0, $zero
/* 0EEB0C 802CA15C 00021400 */  sll   $v0, $v0, 0x10
/* 0EEB10 802CA160 0C016DE0 */  jal   parent_collider_to_model
/* 0EEB14 802CA164 00022C03 */   sra   $a1, $v0, 0x10
/* 0EEB18 802CA168 0C016E89 */  jal   update_collider_transform
/* 0EEB1C 802CA16C 0200202D */   daddu $a0, $s0, $zero
/* 0EEB20 802CA170 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EEB24 802CA174 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EEB28 802CA178 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EEB2C 802CA17C 24020002 */  addiu $v0, $zero, 2
/* 0EEB30 802CA180 03E00008 */  jr    $ra
/* 0EEB34 802CA184 27BD0020 */   addiu $sp, $sp, 0x20

