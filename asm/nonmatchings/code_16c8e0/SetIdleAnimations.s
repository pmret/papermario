.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetIdleAnimations
/* 1AB45C 8027CB7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AB460 8027CB80 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AB464 8027CB84 0080882D */  daddu     $s1, $a0, $zero
/* 1AB468 8027CB88 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AB46C 8027CB8C AFB20018 */  sw        $s2, 0x18($sp)
/* 1AB470 8027CB90 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AB474 8027CB94 8E30000C */  lw        $s0, 0xc($s1)
/* 1AB478 8027CB98 8E050000 */  lw        $a1, ($s0)
/* 1AB47C 8027CB9C 0C0B1EAF */  jal       get_variable
/* 1AB480 8027CBA0 26100004 */   addiu    $s0, $s0, 4
/* 1AB484 8027CBA4 0040902D */  daddu     $s2, $v0, $zero
/* 1AB488 8027CBA8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AB48C 8027CBAC 16420002 */  bne       $s2, $v0, .L8027CBB8
/* 1AB490 8027CBB0 00000000 */   nop      
/* 1AB494 8027CBB4 8E320148 */  lw        $s2, 0x148($s1)
.L8027CBB8:
/* 1AB498 8027CBB8 8E050000 */  lw        $a1, ($s0)
/* 1AB49C 8027CBBC 26100004 */  addiu     $s0, $s0, 4
/* 1AB4A0 8027CBC0 0C0B1EAF */  jal       get_variable
/* 1AB4A4 8027CBC4 0220202D */   daddu    $a0, $s1, $zero
/* 1AB4A8 8027CBC8 0220202D */  daddu     $a0, $s1, $zero
/* 1AB4AC 8027CBCC 8E050000 */  lw        $a1, ($s0)
/* 1AB4B0 8027CBD0 0C0B1EAF */  jal       get_variable
/* 1AB4B4 8027CBD4 0040882D */   daddu    $s1, $v0, $zero
/* 1AB4B8 8027CBD8 0240202D */  daddu     $a0, $s2, $zero
/* 1AB4BC 8027CBDC 0C09A75B */  jal       get_actor
/* 1AB4C0 8027CBE0 0040802D */   daddu    $s0, $v0, $zero
/* 1AB4C4 8027CBE4 0040202D */  daddu     $a0, $v0, $zero
/* 1AB4C8 8027CBE8 0C099117 */  jal       get_actor_part
/* 1AB4CC 8027CBEC 0220282D */   daddu    $a1, $s1, $zero
/* 1AB4D0 8027CBF0 AC500094 */  sw        $s0, 0x94($v0)
/* 1AB4D4 8027CBF4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AB4D8 8027CBF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AB4DC 8027CBFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AB4E0 8027CC00 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AB4E4 8027CC04 24020002 */  addiu     $v0, $zero, 2
/* 1AB4E8 8027CC08 03E00008 */  jr        $ra
/* 1AB4EC 8027CC0C 27BD0020 */   addiu    $sp, $sp, 0x20
