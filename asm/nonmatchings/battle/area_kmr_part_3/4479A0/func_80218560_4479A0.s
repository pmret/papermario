.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218560_4479A0
/* 4479A0 80218560 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4479A4 80218564 AFB10014 */  sw        $s1, 0x14($sp)
/* 4479A8 80218568 0080882D */  daddu     $s1, $a0, $zero
/* 4479AC 8021856C AFBF0018 */  sw        $ra, 0x18($sp)
/* 4479B0 80218570 AFB00010 */  sw        $s0, 0x10($sp)
/* 4479B4 80218574 8E30000C */  lw        $s0, 0xc($s1)
/* 4479B8 80218578 8E050000 */  lw        $a1, ($s0)
/* 4479BC 8021857C 0C0B1EAF */  jal       get_variable
/* 4479C0 80218580 26100004 */   addiu    $s0, $s0, 4
/* 4479C4 80218584 0220202D */  daddu     $a0, $s1, $zero
/* 4479C8 80218588 8E050000 */  lw        $a1, ($s0)
/* 4479CC 8021858C 0C0B1EAF */  jal       get_variable
/* 4479D0 80218590 0040802D */   daddu    $s0, $v0, $zero
/* 4479D4 80218594 0200202D */  daddu     $a0, $s0, $zero
/* 4479D8 80218598 0C00A3C2 */  jal       start_rumble
/* 4479DC 8021859C 0040282D */   daddu    $a1, $v0, $zero
/* 4479E0 802185A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4479E4 802185A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4479E8 802185A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4479EC 802185AC 24020002 */  addiu     $v0, $zero, 2
/* 4479F0 802185B0 03E00008 */  jr        $ra
/* 4479F4 802185B4 27BD0020 */   addiu    $sp, $sp, 0x20
