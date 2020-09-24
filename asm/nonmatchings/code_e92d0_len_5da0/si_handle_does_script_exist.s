.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_does_script_exist
/* EB428 802C6A78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB42C 802C6A7C AFB10014 */  sw        $s1, 0x14($sp)
/* EB430 802C6A80 0080882D */  daddu     $s1, $a0, $zero
/* EB434 802C6A84 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB438 802C6A88 AFB00010 */  sw        $s0, 0x10($sp)
/* EB43C 802C6A8C 8E30000C */  lw        $s0, 0xc($s1)
/* EB440 802C6A90 8E050000 */  lw        $a1, ($s0)
/* EB444 802C6A94 0C0B1EAF */  jal       get_variable
/* EB448 802C6A98 26100004 */   addiu    $s0, $s0, 4
/* EB44C 802C6A9C 8E100000 */  lw        $s0, ($s0)
/* EB450 802C6AA0 0C0B1059 */  jal       does_script_exist
/* EB454 802C6AA4 0040202D */   daddu    $a0, $v0, $zero
/* EB458 802C6AA8 0220202D */  daddu     $a0, $s1, $zero
/* EB45C 802C6AAC 0040302D */  daddu     $a2, $v0, $zero
/* EB460 802C6AB0 0C0B2026 */  jal       set_variable
/* EB464 802C6AB4 0200282D */   daddu    $a1, $s0, $zero
/* EB468 802C6AB8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB46C 802C6ABC 8FB10014 */  lw        $s1, 0x14($sp)
/* EB470 802C6AC0 8FB00010 */  lw        $s0, 0x10($sp)
/* EB474 802C6AC4 24020002 */  addiu     $v0, $zero, 2
/* EB478 802C6AC8 03E00008 */  jr        $ra
/* EB47C 802C6ACC 27BD0020 */   addiu    $sp, $sp, 0x20
