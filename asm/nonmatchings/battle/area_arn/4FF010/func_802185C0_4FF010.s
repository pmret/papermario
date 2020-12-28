.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802185C0_4FF010
/* 4FF010 802185C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4FF014 802185C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4FF018 802185C8 0080882D */  daddu     $s1, $a0, $zero
/* 4FF01C 802185CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 4FF020 802185D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4FF024 802185D4 8E30000C */  lw        $s0, 0xc($s1)
/* 4FF028 802185D8 8E050000 */  lw        $a1, ($s0)
/* 4FF02C 802185DC 0C0B1EAF */  jal       get_variable
/* 4FF030 802185E0 26100004 */   addiu    $s0, $s0, 4
/* 4FF034 802185E4 0220202D */  daddu     $a0, $s1, $zero
/* 4FF038 802185E8 8E050000 */  lw        $a1, ($s0)
/* 4FF03C 802185EC 0C0B1EAF */  jal       get_variable
/* 4FF040 802185F0 0040802D */   daddu    $s0, $v0, $zero
/* 4FF044 802185F4 0200202D */  daddu     $a0, $s0, $zero
/* 4FF048 802185F8 0C00A3C2 */  jal       start_rumble
/* 4FF04C 802185FC 0040282D */   daddu    $a1, $v0, $zero
/* 4FF050 80218600 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4FF054 80218604 8FB10014 */  lw        $s1, 0x14($sp)
/* 4FF058 80218608 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FF05C 8021860C 24020002 */  addiu     $v0, $zero, 2
/* 4FF060 80218610 03E00008 */  jr        $ra
/* 4FF064 80218614 27BD0020 */   addiu    $sp, $sp, 0x20
