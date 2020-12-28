.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219300_5B27B0
/* 5B27B0 80219300 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B27B4 80219304 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B27B8 80219308 0080882D */  daddu     $s1, $a0, $zero
/* 5B27BC 8021930C AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B27C0 80219310 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B27C4 80219314 8E30000C */  lw        $s0, 0xc($s1)
/* 5B27C8 80219318 8E050000 */  lw        $a1, ($s0)
/* 5B27CC 8021931C 0C0B1EAF */  jal       get_variable
/* 5B27D0 80219320 26100004 */   addiu    $s0, $s0, 4
/* 5B27D4 80219324 0220202D */  daddu     $a0, $s1, $zero
/* 5B27D8 80219328 8E050000 */  lw        $a1, ($s0)
/* 5B27DC 8021932C 0C0B1EAF */  jal       get_variable
/* 5B27E0 80219330 0040802D */   daddu    $s0, $v0, $zero
/* 5B27E4 80219334 0200202D */  daddu     $a0, $s0, $zero
/* 5B27E8 80219338 0C00A3C2 */  jal       start_rumble
/* 5B27EC 8021933C 0040282D */   daddu    $a1, $v0, $zero
/* 5B27F0 80219340 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B27F4 80219344 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B27F8 80219348 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B27FC 8021934C 24020002 */  addiu     $v0, $zero, 2
/* 5B2800 80219350 03E00008 */  jr        $ra
/* 5B2804 80219354 27BD0020 */   addiu    $sp, $sp, 0x20
