.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218530_63D710
/* 63D710 80218530 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 63D714 80218534 AFB10014 */  sw        $s1, 0x14($sp)
/* 63D718 80218538 0080882D */  daddu     $s1, $a0, $zero
/* 63D71C 8021853C AFBF0018 */  sw        $ra, 0x18($sp)
/* 63D720 80218540 AFB00010 */  sw        $s0, 0x10($sp)
/* 63D724 80218544 8E30000C */  lw        $s0, 0xc($s1)
/* 63D728 80218548 8E050000 */  lw        $a1, ($s0)
/* 63D72C 8021854C 0C0B1EAF */  jal       get_variable
/* 63D730 80218550 26100004 */   addiu    $s0, $s0, 4
/* 63D734 80218554 0220202D */  daddu     $a0, $s1, $zero
/* 63D738 80218558 8E050000 */  lw        $a1, ($s0)
/* 63D73C 8021855C 0C0B1EAF */  jal       get_variable
/* 63D740 80218560 0040802D */   daddu    $s0, $v0, $zero
/* 63D744 80218564 0200202D */  daddu     $a0, $s0, $zero
/* 63D748 80218568 0C00A3C2 */  jal       start_rumble
/* 63D74C 8021856C 0040282D */   daddu    $a1, $v0, $zero
/* 63D750 80218570 8FBF0018 */  lw        $ra, 0x18($sp)
/* 63D754 80218574 8FB10014 */  lw        $s1, 0x14($sp)
/* 63D758 80218578 8FB00010 */  lw        $s0, 0x10($sp)
/* 63D75C 8021857C 24020002 */  addiu     $v0, $zero, 2
/* 63D760 80218580 03E00008 */  jr        $ra
/* 63D764 80218584 27BD0020 */   addiu    $sp, $sp, 0x20
