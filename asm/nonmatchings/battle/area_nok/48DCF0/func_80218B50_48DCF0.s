.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B50_48DCF0
/* 48DCF0 80218B50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 48DCF4 80218B54 AFB10014 */  sw        $s1, 0x14($sp)
/* 48DCF8 80218B58 0080882D */  daddu     $s1, $a0, $zero
/* 48DCFC 80218B5C AFBF0018 */  sw        $ra, 0x18($sp)
/* 48DD00 80218B60 AFB00010 */  sw        $s0, 0x10($sp)
/* 48DD04 80218B64 8E30000C */  lw        $s0, 0xc($s1)
/* 48DD08 80218B68 8E050000 */  lw        $a1, ($s0)
/* 48DD0C 80218B6C 0C0B1EAF */  jal       get_variable
/* 48DD10 80218B70 26100004 */   addiu    $s0, $s0, 4
/* 48DD14 80218B74 0220202D */  daddu     $a0, $s1, $zero
/* 48DD18 80218B78 8E050000 */  lw        $a1, ($s0)
/* 48DD1C 80218B7C 0C0B1EAF */  jal       get_variable
/* 48DD20 80218B80 0040802D */   daddu    $s0, $v0, $zero
/* 48DD24 80218B84 0200202D */  daddu     $a0, $s0, $zero
/* 48DD28 80218B88 0C00A3C2 */  jal       start_rumble
/* 48DD2C 80218B8C 0040282D */   daddu    $a1, $v0, $zero
/* 48DD30 80218B90 8FBF0018 */  lw        $ra, 0x18($sp)
/* 48DD34 80218B94 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DD38 80218B98 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DD3C 80218B9C 24020002 */  addiu     $v0, $zero, 2
/* 48DD40 80218BA0 03E00008 */  jr        $ra
/* 48DD44 80218BA4 27BD0020 */   addiu    $sp, $sp, 0x20
