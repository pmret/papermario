.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218530_6CC5A0
/* 6CC5A0 80218530 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6CC5A4 80218534 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC5A8 80218538 0080882D */  daddu     $s1, $a0, $zero
/* 6CC5AC 8021853C AFBF0018 */  sw        $ra, 0x18($sp)
/* 6CC5B0 80218540 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC5B4 80218544 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC5B8 80218548 8E050000 */  lw        $a1, ($s0)
/* 6CC5BC 8021854C 0C0B1EAF */  jal       get_variable
/* 6CC5C0 80218550 26100004 */   addiu    $s0, $s0, 4
/* 6CC5C4 80218554 0220202D */  daddu     $a0, $s1, $zero
/* 6CC5C8 80218558 8E050000 */  lw        $a1, ($s0)
/* 6CC5CC 8021855C 0C0B1EAF */  jal       get_variable
/* 6CC5D0 80218560 0040802D */   daddu    $s0, $v0, $zero
/* 6CC5D4 80218564 0200202D */  daddu     $a0, $s0, $zero
/* 6CC5D8 80218568 0C00A3C2 */  jal       start_rumble
/* 6CC5DC 8021856C 0040282D */   daddu    $a1, $v0, $zero
/* 6CC5E0 80218570 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6CC5E4 80218574 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC5E8 80218578 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC5EC 8021857C 24020002 */  addiu     $v0, $zero, 2
/* 6CC5F0 80218580 03E00008 */  jr        $ra
/* 6CC5F4 80218584 27BD0020 */   addiu    $sp, $sp, 0x20
