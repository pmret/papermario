.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426B4_C88164
/* C88164 802426B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C88168 802426B8 AFB10014 */  sw        $s1, 0x14($sp)
/* C8816C 802426BC 0080882D */  daddu     $s1, $a0, $zero
/* C88170 802426C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C88174 802426C4 AFB00010 */  sw        $s0, 0x10($sp)
/* C88178 802426C8 8E30000C */  lw        $s0, 0xc($s1)
/* C8817C 802426CC 8E050000 */  lw        $a1, ($s0)
/* C88180 802426D0 0C0B1EAF */  jal       get_variable
/* C88184 802426D4 26100004 */   addiu    $s0, $s0, 4
/* C88188 802426D8 0C00EAD2 */  jal       get_npc_safe
/* C8818C 802426DC 0040202D */   daddu    $a0, $v0, $zero
/* C88190 802426E0 10400005 */  beqz      $v0, .L802426F8
/* C88194 802426E4 00000000 */   nop      
/* C88198 802426E8 8E050000 */  lw        $a1, ($s0)
/* C8819C 802426EC 844600A8 */  lh        $a2, 0xa8($v0)
/* C881A0 802426F0 0C0B2026 */  jal       set_variable
/* C881A4 802426F4 0220202D */   daddu    $a0, $s1, $zero
.L802426F8:
/* C881A8 802426F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C881AC 802426FC 8FB10014 */  lw        $s1, 0x14($sp)
/* C881B0 80242700 8FB00010 */  lw        $s0, 0x10($sp)
/* C881B4 80242704 24020002 */  addiu     $v0, $zero, 2
/* C881B8 80242708 03E00008 */  jr        $ra
/* C881BC 8024270C 27BD0020 */   addiu    $sp, $sp, 0x20
