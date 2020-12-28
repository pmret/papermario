.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D54_513324
/* 513324 80218D54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 513328 80218D58 AFB10014 */  sw        $s1, 0x14($sp)
/* 51332C 80218D5C 0080882D */  daddu     $s1, $a0, $zero
/* 513330 80218D60 AFBF0018 */  sw        $ra, 0x18($sp)
/* 513334 80218D64 AFB00010 */  sw        $s0, 0x10($sp)
/* 513338 80218D68 8E30000C */  lw        $s0, 0xc($s1)
/* 51333C 80218D6C 8E050000 */  lw        $a1, ($s0)
/* 513340 80218D70 0C0B1EAF */  jal       get_variable
/* 513344 80218D74 26100004 */   addiu    $s0, $s0, 4
/* 513348 80218D78 0220202D */  daddu     $a0, $s1, $zero
/* 51334C 80218D7C 8E050000 */  lw        $a1, ($s0)
/* 513350 80218D80 0C0B1EAF */  jal       get_variable
/* 513354 80218D84 0040802D */   daddu    $s0, $v0, $zero
/* 513358 80218D88 0200202D */  daddu     $a0, $s0, $zero
/* 51335C 80218D8C 0C00A3C2 */  jal       start_rumble
/* 513360 80218D90 0040282D */   daddu    $a1, $v0, $zero
/* 513364 80218D94 8FBF0018 */  lw        $ra, 0x18($sp)
/* 513368 80218D98 8FB10014 */  lw        $s1, 0x14($sp)
/* 51336C 80218D9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 513370 80218DA0 24020002 */  addiu     $v0, $zero, 2
/* 513374 80218DA4 03E00008 */  jr        $ra
/* 513378 80218DA8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 51337C 80218DAC 00000000 */  nop       
