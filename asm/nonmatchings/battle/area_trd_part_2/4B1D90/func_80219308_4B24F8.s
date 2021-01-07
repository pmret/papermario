.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219308_4B24F8
/* 4B24F8 80219308 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B24FC 8021930C AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2500 80219310 0080802D */  daddu     $s0, $a0, $zero
/* 4B2504 80219314 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B2508 80219318 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B250C 8021931C 8E040148 */  lw        $a0, 0x148($s0)
/* 4B2510 80219320 0C09A75B */  jal       get_actor
/* 4B2514 80219324 8E11000C */   lw       $s1, 0xc($s0)
/* 4B2518 80219328 0200202D */  daddu     $a0, $s0, $zero
/* 4B251C 8021932C 8E250000 */  lw        $a1, ($s1)
/* 4B2520 80219330 0C0B1EAF */  jal       get_variable
/* 4B2524 80219334 0040802D */   daddu    $s0, $v0, $zero
/* 4B2528 80219338 A20201F0 */  sb        $v0, 0x1f0($s0)
/* 4B252C 8021933C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B2530 80219340 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B2534 80219344 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2538 80219348 24020002 */  addiu     $v0, $zero, 2
/* 4B253C 8021934C 03E00008 */  jr        $ra
/* 4B2540 80219350 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4B2544 80219354 00000000 */  nop       
/* 4B2548 80219358 00000000 */  nop       
/* 4B254C 8021935C 00000000 */  nop       
