.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B0_AF7C00
/* AF7C00 802402B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF7C04 802402B4 AFB10014 */  sw        $s1, 0x14($sp)
/* AF7C08 802402B8 0080882D */  daddu     $s1, $a0, $zero
/* AF7C0C 802402BC AFBF0018 */  sw        $ra, 0x18($sp)
/* AF7C10 802402C0 AFB00010 */  sw        $s0, 0x10($sp)
/* AF7C14 802402C4 8E30000C */  lw        $s0, 0xc($s1)
/* AF7C18 802402C8 8E050000 */  lw        $a1, ($s0)
/* AF7C1C 802402CC 0C0B1EAF */  jal       get_variable
/* AF7C20 802402D0 26100004 */   addiu    $s0, $s0, 4
/* AF7C24 802402D4 0C00EAD2 */  jal       get_npc_safe
/* AF7C28 802402D8 0040202D */   daddu    $a0, $v0, $zero
/* AF7C2C 802402DC 10400005 */  beqz      $v0, .L802402F4
/* AF7C30 802402E0 00000000 */   nop      
/* AF7C34 802402E4 8E050000 */  lw        $a1, ($s0)
/* AF7C38 802402E8 844600A8 */  lh        $a2, 0xa8($v0)
/* AF7C3C 802402EC 0C0B2026 */  jal       set_variable
/* AF7C40 802402F0 0220202D */   daddu    $a0, $s1, $zero
.L802402F4:
/* AF7C44 802402F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* AF7C48 802402F8 8FB10014 */  lw        $s1, 0x14($sp)
/* AF7C4C 802402FC 8FB00010 */  lw        $s0, 0x10($sp)
/* AF7C50 80240300 24020002 */  addiu     $v0, $zero, 2
/* AF7C54 80240304 03E00008 */  jr        $ra
/* AF7C58 80240308 27BD0020 */   addiu    $sp, $sp, 0x20
