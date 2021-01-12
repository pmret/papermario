.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026EB20
/* 19D400 8026EB20 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19D404 8026EB24 AFB20018 */  sw        $s2, 0x18($sp)
/* 19D408 8026EB28 0080902D */  daddu     $s2, $a0, $zero
/* 19D40C 8026EB2C AFBF0020 */  sw        $ra, 0x20($sp)
/* 19D410 8026EB30 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19D414 8026EB34 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D418 8026EB38 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D41C 8026EB3C 8E51000C */  lw        $s1, 0xc($s2)
/* 19D420 8026EB40 8E250000 */  lw        $a1, ($s1)
/* 19D424 8026EB44 0C0B1EAF */  jal       get_variable
/* 19D428 8026EB48 26310004 */   addiu    $s1, $s1, 4
/* 19D42C 8026EB4C 0040802D */  daddu     $s0, $v0, $zero
/* 19D430 8026EB50 8E250000 */  lw        $a1, ($s1)
/* 19D434 8026EB54 26310004 */  addiu     $s1, $s1, 4
/* 19D438 8026EB58 0C0B1EAF */  jal       get_variable
/* 19D43C 8026EB5C 0240202D */   daddu    $a0, $s2, $zero
/* 19D440 8026EB60 0040982D */  daddu     $s3, $v0, $zero
/* 19D444 8026EB64 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D448 8026EB68 16020002 */  bne       $s0, $v0, .L8026EB74
/* 19D44C 8026EB6C 00000000 */   nop
/* 19D450 8026EB70 8E500148 */  lw        $s0, 0x148($s2)
.L8026EB74:
/* 19D454 8026EB74 0C09A75B */  jal       get_actor
/* 19D458 8026EB78 0200202D */   daddu    $a0, $s0, $zero
/* 19D45C 8026EB7C 0040202D */  daddu     $a0, $v0, $zero
/* 19D460 8026EB80 0C099117 */  jal       get_actor_part
/* 19D464 8026EB84 0260282D */   daddu    $a1, $s3, $zero
/* 19D468 8026EB88 8E250000 */  lw        $a1, ($s1)
/* 19D46C 8026EB8C 26310004 */  addiu     $s1, $s1, 4
/* 19D470 8026EB90 8C5000C0 */  lw        $s0, 0xc0($v0)
/* 19D474 8026EB94 0C0B1EAF */  jal       get_variable
/* 19D478 8026EB98 0240202D */   daddu    $a0, $s2, $zero
/* 19D47C 8026EB9C A6020740 */  sh        $v0, 0x740($s0)
/* 19D480 8026EBA0 8E250000 */  lw        $a1, ($s1)
/* 19D484 8026EBA4 26310004 */  addiu     $s1, $s1, 4
/* 19D488 8026EBA8 0C0B1EAF */  jal       get_variable
/* 19D48C 8026EBAC 0240202D */   daddu    $a0, $s2, $zero
/* 19D490 8026EBB0 A6020742 */  sh        $v0, 0x742($s0)
/* 19D494 8026EBB4 8E250000 */  lw        $a1, ($s1)
/* 19D498 8026EBB8 26310004 */  addiu     $s1, $s1, 4
/* 19D49C 8026EBBC 0C0B1EAF */  jal       get_variable
/* 19D4A0 8026EBC0 0240202D */   daddu    $a0, $s2, $zero
/* 19D4A4 8026EBC4 A6020744 */  sh        $v0, 0x744($s0)
/* 19D4A8 8026EBC8 8E250000 */  lw        $a1, ($s1)
/* 19D4AC 8026EBCC 0C0B1EAF */  jal       get_variable
/* 19D4B0 8026EBD0 0240202D */   daddu    $a0, $s2, $zero
/* 19D4B4 8026EBD4 A6020746 */  sh        $v0, 0x746($s0)
/* 19D4B8 8026EBD8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19D4BC 8026EBDC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D4C0 8026EBE0 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D4C4 8026EBE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D4C8 8026EBE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D4CC 8026EBEC 24020002 */  addiu     $v0, $zero, 2
/* 19D4D0 8026EBF0 03E00008 */  jr        $ra
/* 19D4D4 8026EBF4 27BD0028 */   addiu    $sp, $sp, 0x28
