.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026DF88
/* 19C868 8026DF88 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19C86C 8026DF8C AFB20018 */  sw        $s2, 0x18($sp)
/* 19C870 8026DF90 0080902D */  daddu     $s2, $a0, $zero
/* 19C874 8026DF94 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19C878 8026DF98 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19C87C 8026DF9C AFB10014 */  sw        $s1, 0x14($sp)
/* 19C880 8026DFA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 19C884 8026DFA4 8E50000C */  lw        $s0, 0xc($s2)
/* 19C888 8026DFA8 8E050000 */  lw        $a1, ($s0)
/* 19C88C 8026DFAC 0C0B1EAF */  jal       get_variable
/* 19C890 8026DFB0 26100004 */   addiu    $s0, $s0, 4
/* 19C894 8026DFB4 0040882D */  daddu     $s1, $v0, $zero
/* 19C898 8026DFB8 8E050000 */  lw        $a1, ($s0)
/* 19C89C 8026DFBC 26100004 */  addiu     $s0, $s0, 4
/* 19C8A0 8026DFC0 0C0B1EAF */  jal       get_variable
/* 19C8A4 8026DFC4 0240202D */   daddu    $a0, $s2, $zero
/* 19C8A8 8026DFC8 0040982D */  daddu     $s3, $v0, $zero
/* 19C8AC 8026DFCC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19C8B0 8026DFD0 16220002 */  bne       $s1, $v0, .L8026DFDC
/* 19C8B4 8026DFD4 8E100000 */   lw       $s0, ($s0)
/* 19C8B8 8026DFD8 8E510148 */  lw        $s1, 0x148($s2)
.L8026DFDC:
/* 19C8BC 8026DFDC 0C09A75B */  jal       get_actor
/* 19C8C0 8026DFE0 0220202D */   daddu    $a0, $s1, $zero
/* 19C8C4 8026DFE4 0040202D */  daddu     $a0, $v0, $zero
/* 19C8C8 8026DFE8 0C099117 */  jal       get_actor_part
/* 19C8CC 8026DFEC 0260282D */   daddu    $a1, $s3, $zero
/* 19C8D0 8026DFF0 0240202D */  daddu     $a0, $s2, $zero
/* 19C8D4 8026DFF4 8C46008C */  lw        $a2, 0x8c($v0)
/* 19C8D8 8026DFF8 0C0B2026 */  jal       set_variable
/* 19C8DC 8026DFFC 0200282D */   daddu    $a1, $s0, $zero
/* 19C8E0 8026E000 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19C8E4 8026E004 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19C8E8 8026E008 8FB20018 */  lw        $s2, 0x18($sp)
/* 19C8EC 8026E00C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19C8F0 8026E010 8FB00010 */  lw        $s0, 0x10($sp)
/* 19C8F4 8026E014 24020002 */  addiu     $v0, $zero, 2
/* 19C8F8 8026E018 03E00008 */  jr        $ra
/* 19C8FC 8026E01C 27BD0028 */   addiu    $sp, $sp, 0x28
