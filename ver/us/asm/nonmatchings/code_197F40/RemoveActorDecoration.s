.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RemoveActorDecoration
/* 19D82C 8026EF4C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19D830 8026EF50 AFB20018 */  sw        $s2, 0x18($sp)
/* 19D834 8026EF54 0080902D */  daddu     $s2, $a0, $zero
/* 19D838 8026EF58 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19D83C 8026EF5C AFB3001C */  sw        $s3, 0x1c($sp)
/* 19D840 8026EF60 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D844 8026EF64 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D848 8026EF68 8E50000C */  lw        $s0, 0xc($s2)
/* 19D84C 8026EF6C 8E050000 */  lw        $a1, ($s0)
/* 19D850 8026EF70 0C0B1EAF */  jal       get_variable
/* 19D854 8026EF74 26100004 */   addiu    $s0, $s0, 4
/* 19D858 8026EF78 0040882D */  daddu     $s1, $v0, $zero
/* 19D85C 8026EF7C 8E050000 */  lw        $a1, ($s0)
/* 19D860 8026EF80 26100004 */  addiu     $s0, $s0, 4
/* 19D864 8026EF84 0C0B1EAF */  jal       get_variable
/* 19D868 8026EF88 0240202D */   daddu    $a0, $s2, $zero
/* 19D86C 8026EF8C 0240202D */  daddu     $a0, $s2, $zero
/* 19D870 8026EF90 8E050000 */  lw        $a1, ($s0)
/* 19D874 8026EF94 0C0B1EAF */  jal       get_variable
/* 19D878 8026EF98 0040802D */   daddu    $s0, $v0, $zero
/* 19D87C 8026EF9C 0040982D */  daddu     $s3, $v0, $zero
/* 19D880 8026EFA0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D884 8026EFA4 16220002 */  bne       $s1, $v0, .L8026EFB0
/* 19D888 8026EFA8 00000000 */   nop
/* 19D88C 8026EFAC 8E510148 */  lw        $s1, 0x148($s2)
.L8026EFB0:
/* 19D890 8026EFB0 0C09A75B */  jal       get_actor
/* 19D894 8026EFB4 0220202D */   daddu    $a0, $s1, $zero
/* 19D898 8026EFB8 0040202D */  daddu     $a0, $v0, $zero
/* 19D89C 8026EFBC 0C099117 */  jal       get_actor_part
/* 19D8A0 8026EFC0 0200282D */   daddu    $a1, $s0, $zero
/* 19D8A4 8026EFC4 0040202D */  daddu     $a0, $v0, $zero
/* 19D8A8 8026EFC8 0C099C86 */  jal       remove_part_decoration
/* 19D8AC 8026EFCC 0260282D */   daddu    $a1, $s3, $zero
/* 19D8B0 8026EFD0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19D8B4 8026EFD4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D8B8 8026EFD8 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D8BC 8026EFDC 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D8C0 8026EFE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D8C4 8026EFE4 24020002 */  addiu     $v0, $zero, 2
/* 19D8C8 8026EFE8 03E00008 */  jr        $ra
/* 19D8CC 8026EFEC 27BD0028 */   addiu    $sp, $sp, 0x28
