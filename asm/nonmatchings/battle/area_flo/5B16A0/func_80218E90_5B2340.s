.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218E90_5B2340
/* 5B2340 80218E90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B2344 80218E94 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B2348 80218E98 0080882D */  daddu     $s1, $a0, $zero
/* 5B234C 80218E9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B2350 80218EA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B2354 80218EA4 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2358 80218EA8 8E050000 */  lw        $a1, ($s0)
/* 5B235C 80218EAC 0C0B1EAF */  jal       get_variable
/* 5B2360 80218EB0 26100004 */   addiu    $s0, $s0, 4
/* 5B2364 80218EB4 0220202D */  daddu     $a0, $s1, $zero
/* 5B2368 80218EB8 8E050000 */  lw        $a1, ($s0)
/* 5B236C 80218EBC 0C0B1EAF */  jal       get_variable
/* 5B2370 80218EC0 0040802D */   daddu    $s0, $v0, $zero
/* 5B2374 80218EC4 0200202D */  daddu     $a0, $s0, $zero
/* 5B2378 80218EC8 0C00A3C2 */  jal       start_rumble
/* 5B237C 80218ECC 0040282D */   daddu    $a1, $v0, $zero
/* 5B2380 80218ED0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B2384 80218ED4 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B2388 80218ED8 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B238C 80218EDC 24020002 */  addiu     $v0, $zero, 2
/* 5B2390 80218EE0 03E00008 */  jr        $ra
/* 5B2394 80218EE4 27BD0020 */   addiu    $sp, $sp, 0x20
