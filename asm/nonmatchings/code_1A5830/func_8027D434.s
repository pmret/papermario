.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027D434
/* 1ABD14 8027D434 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1ABD18 8027D438 AFB20018 */  sw        $s2, 0x18($sp)
/* 1ABD1C 8027D43C 0080902D */  daddu     $s2, $a0, $zero
/* 1ABD20 8027D440 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1ABD24 8027D444 AFB10014 */  sw        $s1, 0x14($sp)
/* 1ABD28 8027D448 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABD2C 8027D44C 8E51000C */  lw        $s1, 0xc($s2)
/* 1ABD30 8027D450 8E250000 */  lw        $a1, ($s1)
/* 1ABD34 8027D454 0C0B1EAF */  jal       get_variable
/* 1ABD38 8027D458 26310004 */   addiu    $s1, $s1, 4
/* 1ABD3C 8027D45C 0040802D */  daddu     $s0, $v0, $zero
/* 1ABD40 8027D460 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABD44 8027D464 16020002 */  bne       $s0, $v0, .L8027D470
/* 1ABD48 8027D468 00000000 */   nop      
/* 1ABD4C 8027D46C 8E500148 */  lw        $s0, 0x148($s2)
.L8027D470:
/* 1ABD50 8027D470 8E250000 */  lw        $a1, ($s1)
/* 1ABD54 8027D474 26310004 */  addiu     $s1, $s1, 4
/* 1ABD58 8027D478 0C0B1EAF */  jal       get_variable
/* 1ABD5C 8027D47C 0240202D */   daddu    $a0, $s2, $zero
/* 1ABD60 8027D480 0200202D */  daddu     $a0, $s0, $zero
/* 1ABD64 8027D484 0C09A75B */  jal       get_actor
/* 1ABD68 8027D488 0040802D */   daddu    $s0, $v0, $zero
/* 1ABD6C 8027D48C 0040202D */  daddu     $a0, $v0, $zero
/* 1ABD70 8027D490 0C099117 */  jal       get_actor_part
/* 1ABD74 8027D494 0200282D */   daddu    $a1, $s0, $zero
/* 1ABD78 8027D498 0240202D */  daddu     $a0, $s2, $zero
/* 1ABD7C 8027D49C 8E250000 */  lw        $a1, ($s1)
/* 1ABD80 8027D4A0 0C0B1EAF */  jal       get_variable
/* 1ABD84 8027D4A4 0040802D */   daddu    $s0, $v0, $zero
/* 1ABD88 8027D4A8 A6020070 */  sh        $v0, 0x70($s0)
/* 1ABD8C 8027D4AC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1ABD90 8027D4B0 8FB20018 */  lw        $s2, 0x18($sp)
/* 1ABD94 8027D4B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1ABD98 8027D4B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABD9C 8027D4BC 24020002 */  addiu     $v0, $zero, 2
/* 1ABDA0 8027D4C0 03E00008 */  jr        $ra
/* 1ABDA4 8027D4C4 27BD0020 */   addiu    $sp, $sp, 0x20
