.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C91A4
/* EDB54 802C91A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDB58 802C91A8 AFB10014 */  sw        $s1, 0x14($sp)
/* EDB5C 802C91AC 0080882D */  daddu     $s1, $a0, $zero
/* EDB60 802C91B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EDB64 802C91B4 AFB00010 */  sw        $s0, 0x10($sp)
/* EDB68 802C91B8 8E30000C */  lw        $s0, 0xc($s1)
/* EDB6C 802C91BC 8E050000 */  lw        $a1, ($s0)
/* EDB70 802C91C0 0C0B1EAF */  jal       get_variable
/* EDB74 802C91C4 26100004 */   addiu    $s0, $s0, 4
/* EDB78 802C91C8 0220202D */  daddu     $a0, $s1, $zero
/* EDB7C 802C91CC 8E050000 */  lw        $a1, ($s0)
/* EDB80 802C91D0 0C0B1EAF */  jal       get_variable
/* EDB84 802C91D4 0040802D */   daddu    $s0, $v0, $zero
/* EDB88 802C91D8 0200202D */  daddu     $a0, $s0, $zero
/* EDB8C 802C91DC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* EDB90 802C91E0 0040802D */   daddu    $s0, $v0, $zero
/* EDB94 802C91E4 0C046B4C */  jal       get_model_from_list_index
/* EDB98 802C91E8 0040202D */   daddu    $a0, $v0, $zero
/* EDB9C 802C91EC A05000A9 */  sb        $s0, 0xa9($v0)
/* EDBA0 802C91F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDBA4 802C91F4 8FB10014 */  lw        $s1, 0x14($sp)
/* EDBA8 802C91F8 8FB00010 */  lw        $s0, 0x10($sp)
/* EDBAC 802C91FC 24020002 */  addiu     $v0, $zero, 2
/* EDBB0 802C9200 03E00008 */  jr        $ra
/* EDBB4 802C9204 27BD0020 */   addiu    $sp, $sp, 0x20
