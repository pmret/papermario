.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219310_64A120
/* 64A120 80219310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 64A124 80219314 AFB10014 */  sw        $s1, 0x14($sp)
/* 64A128 80219318 0080882D */  daddu     $s1, $a0, $zero
/* 64A12C 8021931C AFBF0018 */  sw        $ra, 0x18($sp)
/* 64A130 80219320 AFB00010 */  sw        $s0, 0x10($sp)
/* 64A134 80219324 8E30000C */  lw        $s0, 0xc($s1)
/* 64A138 80219328 8E050000 */  lw        $a1, ($s0)
/* 64A13C 8021932C 0C0B1EAF */  jal       get_variable
/* 64A140 80219330 26100004 */   addiu    $s0, $s0, 4
/* 64A144 80219334 0220202D */  daddu     $a0, $s1, $zero
/* 64A148 80219338 8E050000 */  lw        $a1, ($s0)
/* 64A14C 8021933C 0C0B1EAF */  jal       get_variable
/* 64A150 80219340 0040802D */   daddu    $s0, $v0, $zero
/* 64A154 80219344 0200202D */  daddu     $a0, $s0, $zero
/* 64A158 80219348 0C00A3C2 */  jal       start_rumble
/* 64A15C 8021934C 0040282D */   daddu    $a1, $v0, $zero
/* 64A160 80219350 8FBF0018 */  lw        $ra, 0x18($sp)
/* 64A164 80219354 8FB10014 */  lw        $s1, 0x14($sp)
/* 64A168 80219358 8FB00010 */  lw        $s0, 0x10($sp)
/* 64A16C 8021935C 24020002 */  addiu     $v0, $zero, 2
/* 64A170 80219360 03E00008 */  jr        $ra
/* 64A174 80219364 27BD0020 */   addiu    $sp, $sp, 0x20
