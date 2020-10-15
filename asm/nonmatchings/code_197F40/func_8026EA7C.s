.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026EA7C
/* 19D35C 8026EA7C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19D360 8026EA80 AFB20018 */  sw        $s2, 0x18($sp)
/* 19D364 8026EA84 0080902D */  daddu     $s2, $a0, $zero
/* 19D368 8026EA88 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19D36C 8026EA8C AFB3001C */  sw        $s3, 0x1c($sp)
/* 19D370 8026EA90 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D374 8026EA94 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D378 8026EA98 8E50000C */  lw        $s0, 0xc($s2)
/* 19D37C 8026EA9C 8E050000 */  lw        $a1, ($s0)
/* 19D380 8026EAA0 0C0B1EAF */  jal       get_variable
/* 19D384 8026EAA4 26100004 */   addiu    $s0, $s0, 4
/* 19D388 8026EAA8 0040882D */  daddu     $s1, $v0, $zero
/* 19D38C 8026EAAC 8E050000 */  lw        $a1, ($s0)
/* 19D390 8026EAB0 26100004 */  addiu     $s0, $s0, 4
/* 19D394 8026EAB4 0C0B1EAF */  jal       get_variable
/* 19D398 8026EAB8 0240202D */   daddu    $a0, $s2, $zero
/* 19D39C 8026EABC 0240202D */  daddu     $a0, $s2, $zero
/* 19D3A0 8026EAC0 8E050000 */  lw        $a1, ($s0)
/* 19D3A4 8026EAC4 0C0B1EAF */  jal       get_variable
/* 19D3A8 8026EAC8 0040802D */   daddu    $s0, $v0, $zero
/* 19D3AC 8026EACC 0040982D */  daddu     $s3, $v0, $zero
/* 19D3B0 8026EAD0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D3B4 8026EAD4 16220002 */  bne       $s1, $v0, .L8026EAE0
/* 19D3B8 8026EAD8 00000000 */   nop      
/* 19D3BC 8026EADC 8E510148 */  lw        $s1, 0x148($s2)
.L8026EAE0:
/* 19D3C0 8026EAE0 0C09A75B */  jal       get_actor
/* 19D3C4 8026EAE4 0220202D */   daddu    $a0, $s1, $zero
/* 19D3C8 8026EAE8 0040202D */  daddu     $a0, $v0, $zero
/* 19D3CC 8026EAEC 0C099117 */  jal       get_actor_part
/* 19D3D0 8026EAF0 0200282D */   daddu    $a1, $s0, $zero
/* 19D3D4 8026EAF4 0040202D */  daddu     $a0, $v0, $zero
/* 19D3D8 8026EAF8 0C099B5B */  jal       func_80266D6C
/* 19D3DC 8026EAFC 0260282D */   daddu    $a1, $s3, $zero
/* 19D3E0 8026EB00 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19D3E4 8026EB04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D3E8 8026EB08 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D3EC 8026EB0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D3F0 8026EB10 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D3F4 8026EB14 24020002 */  addiu     $v0, $zero, 2
/* 19D3F8 8026EB18 03E00008 */  jr        $ra
/* 19D3FC 8026EB1C 27BD0028 */   addiu    $sp, $sp, 0x28
