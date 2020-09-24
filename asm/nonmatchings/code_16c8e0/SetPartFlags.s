.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartFlags
/* 19B868 8026CF88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19B86C 8026CF8C AFB20018 */  sw        $s2, 0x18($sp)
/* 19B870 8026CF90 0080902D */  daddu     $s2, $a0, $zero
/* 19B874 8026CF94 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19B878 8026CF98 AFB10014 */  sw        $s1, 0x14($sp)
/* 19B87C 8026CF9C AFB00010 */  sw        $s0, 0x10($sp)
/* 19B880 8026CFA0 8E51000C */  lw        $s1, 0xc($s2)
/* 19B884 8026CFA4 8E250000 */  lw        $a1, ($s1)
/* 19B888 8026CFA8 0C0B1EAF */  jal       get_variable
/* 19B88C 8026CFAC 26310004 */   addiu    $s1, $s1, 4
/* 19B890 8026CFB0 0040802D */  daddu     $s0, $v0, $zero
/* 19B894 8026CFB4 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19B898 8026CFB8 16020002 */  bne       $s0, $v0, .L8026CFC4
/* 19B89C 8026CFBC 00000000 */   nop      
/* 19B8A0 8026CFC0 8E500148 */  lw        $s0, 0x148($s2)
.L8026CFC4:
/* 19B8A4 8026CFC4 8E250000 */  lw        $a1, ($s1)
/* 19B8A8 8026CFC8 26310004 */  addiu     $s1, $s1, 4
/* 19B8AC 8026CFCC 0C0B1EAF */  jal       get_variable
/* 19B8B0 8026CFD0 0240202D */   daddu    $a0, $s2, $zero
/* 19B8B4 8026CFD4 0200202D */  daddu     $a0, $s0, $zero
/* 19B8B8 8026CFD8 8E310000 */  lw        $s1, ($s1)
/* 19B8BC 8026CFDC 0C09A75B */  jal       get_actor
/* 19B8C0 8026CFE0 0040802D */   daddu    $s0, $v0, $zero
/* 19B8C4 8026CFE4 0040202D */  daddu     $a0, $v0, $zero
/* 19B8C8 8026CFE8 0C099117 */  jal       get_actor_part
/* 19B8CC 8026CFEC 0200282D */   daddu    $a1, $s0, $zero
/* 19B8D0 8026CFF0 AC510000 */  sw        $s1, ($v0)
/* 19B8D4 8026CFF4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19B8D8 8026CFF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 19B8DC 8026CFFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 19B8E0 8026D000 8FB00010 */  lw        $s0, 0x10($sp)
/* 19B8E4 8026D004 24020002 */  addiu     $v0, $zero, 2
/* 19B8E8 8026D008 03E00008 */  jr        $ra
/* 19B8EC 8026D00C 27BD0020 */   addiu    $sp, $sp, 0x20
