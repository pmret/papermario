.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B2C_CF46FC
/* CF46FC 80241B2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF4700 80241B30 AFB10014 */  sw        $s1, 0x14($sp)
/* CF4704 80241B34 0080882D */  daddu     $s1, $a0, $zero
/* CF4708 80241B38 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF470C 80241B3C AFB00010 */  sw        $s0, 0x10($sp)
/* CF4710 80241B40 8E30000C */  lw        $s0, 0xc($s1)
/* CF4714 80241B44 8E050000 */  lw        $a1, ($s0)
/* CF4718 80241B48 0C0B1EAF */  jal       get_variable
/* CF471C 80241B4C 26100004 */   addiu    $s0, $s0, 4
/* CF4720 80241B50 0C00EAD2 */  jal       get_npc_safe
/* CF4724 80241B54 0040202D */   daddu    $a0, $v0, $zero
/* CF4728 80241B58 10400005 */  beqz      $v0, .L80241B70
/* CF472C 80241B5C 00000000 */   nop      
/* CF4730 80241B60 8E050000 */  lw        $a1, ($s0)
/* CF4734 80241B64 844600A8 */  lh        $a2, 0xa8($v0)
/* CF4738 80241B68 0C0B2026 */  jal       set_variable
/* CF473C 80241B6C 0220202D */   daddu    $a0, $s1, $zero
.L80241B70:
/* CF4740 80241B70 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF4744 80241B74 8FB10014 */  lw        $s1, 0x14($sp)
/* CF4748 80241B78 8FB00010 */  lw        $s0, 0x10($sp)
/* CF474C 80241B7C 24020002 */  addiu     $v0, $zero, 2
/* CF4750 80241B80 03E00008 */  jr        $ra
/* CF4754 80241B84 27BD0020 */   addiu    $sp, $sp, 0x20
