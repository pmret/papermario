.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ParentColliderToModel
/* EEAC4 802CA114 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEAC8 802CA118 AFB10014 */  sw        $s1, 0x14($sp)
/* EEACC 802CA11C 0080882D */  daddu     $s1, $a0, $zero
/* EEAD0 802CA120 AFBF0018 */  sw        $ra, 0x18($sp)
/* EEAD4 802CA124 AFB00010 */  sw        $s0, 0x10($sp)
/* EEAD8 802CA128 8E30000C */  lw        $s0, 0xc($s1)
/* EEADC 802CA12C 8E050000 */  lw        $a1, ($s0)
/* EEAE0 802CA130 0C0B1EAF */  jal       get_variable
/* EEAE4 802CA134 26100004 */   addiu    $s0, $s0, 4
/* EEAE8 802CA138 0220202D */  daddu     $a0, $s1, $zero
/* EEAEC 802CA13C 8E050000 */  lw        $a1, ($s0)
/* EEAF0 802CA140 0C0B1EAF */  jal       get_variable
/* EEAF4 802CA144 0040802D */   daddu    $s0, $v0, $zero
/* EEAF8 802CA148 0C046C04 */  jal       get_model_list_index_from_tree_index
/* EEAFC 802CA14C 0040202D */   daddu    $a0, $v0, $zero
/* EEB00 802CA150 00108400 */  sll       $s0, $s0, 0x10
/* EEB04 802CA154 00108403 */  sra       $s0, $s0, 0x10
/* EEB08 802CA158 0200202D */  daddu     $a0, $s0, $zero
/* EEB0C 802CA15C 00021400 */  sll       $v0, $v0, 0x10
/* EEB10 802CA160 0C016DE0 */  jal       parent_collider_to_model
/* EEB14 802CA164 00022C03 */   sra      $a1, $v0, 0x10
/* EEB18 802CA168 0C016E89 */  jal       update_collider_transform
/* EEB1C 802CA16C 0200202D */   daddu    $a0, $s0, $zero
/* EEB20 802CA170 8FBF0018 */  lw        $ra, 0x18($sp)
/* EEB24 802CA174 8FB10014 */  lw        $s1, 0x14($sp)
/* EEB28 802CA178 8FB00010 */  lw        $s0, 0x10($sp)
/* EEB2C 802CA17C 24020002 */  addiu     $v0, $zero, 2
/* EEB30 802CA180 03E00008 */  jr        $ra
/* EEB34 802CA184 27BD0020 */   addiu    $sp, $sp, 0x20
