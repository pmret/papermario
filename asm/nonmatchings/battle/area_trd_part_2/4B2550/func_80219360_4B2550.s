.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219360_4B2550
/* 4B2550 80219360 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B2554 80219364 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B2558 80219368 0080882D */  daddu     $s1, $a0, $zero
/* 4B255C 8021936C AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B2560 80219370 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2564 80219374 8E30000C */  lw        $s0, 0xc($s1)
/* 4B2568 80219378 8E050000 */  lw        $a1, ($s0)
/* 4B256C 8021937C 0C0B1EAF */  jal       get_variable
/* 4B2570 80219380 26100004 */   addiu    $s0, $s0, 4
/* 4B2574 80219384 0220202D */  daddu     $a0, $s1, $zero
/* 4B2578 80219388 8E050000 */  lw        $a1, ($s0)
/* 4B257C 8021938C 0C0B1EAF */  jal       get_variable
/* 4B2580 80219390 0040802D */   daddu    $s0, $v0, $zero
/* 4B2584 80219394 0200202D */  daddu     $a0, $s0, $zero
/* 4B2588 80219398 0C00A3C2 */  jal       start_rumble
/* 4B258C 8021939C 0040282D */   daddu    $a1, $v0, $zero
/* 4B2590 802193A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B2594 802193A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B2598 802193A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B259C 802193AC 24020002 */  addiu     $v0, $zero, 2
/* 4B25A0 802193B0 03E00008 */  jr        $ra
/* 4B25A4 802193B4 27BD0020 */   addiu    $sp, $sp, 0x20
