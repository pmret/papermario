.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetJumpAnimations
/* 19A16C 8026B88C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19A170 8026B890 AFB10014 */  sw        $s1, 0x14($sp)
/* 19A174 8026B894 0080882D */  daddu     $s1, $a0, $zero
/* 19A178 8026B898 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19A17C 8026B89C AFB3001C */  sw        $s3, 0x1c($sp)
/* 19A180 8026B8A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 19A184 8026B8A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A188 8026B8A8 8E32000C */  lw        $s2, 0xc($s1)
/* 19A18C 8026B8AC 8E450000 */  lw        $a1, ($s2)
/* 19A190 8026B8B0 0C0B1EAF */  jal       get_variable
/* 19A194 8026B8B4 26520004 */   addiu    $s2, $s2, 4
/* 19A198 8026B8B8 0040802D */  daddu     $s0, $v0, $zero
/* 19A19C 8026B8BC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19A1A0 8026B8C0 16020002 */  bne       $s0, $v0, .L8026B8CC
/* 19A1A4 8026B8C4 00000000 */   nop      
/* 19A1A8 8026B8C8 8E300148 */  lw        $s0, 0x148($s1)
.L8026B8CC:
/* 19A1AC 8026B8CC 8E450000 */  lw        $a1, ($s2)
/* 19A1B0 8026B8D0 26520004 */  addiu     $s2, $s2, 4
/* 19A1B4 8026B8D4 0C0B1EAF */  jal       get_variable
/* 19A1B8 8026B8D8 0220202D */   daddu    $a0, $s1, $zero
/* 19A1BC 8026B8DC 8E530000 */  lw        $s3, ($s2)
/* 19A1C0 8026B8E0 26520004 */  addiu     $s2, $s2, 4
/* 19A1C4 8026B8E4 0200202D */  daddu     $a0, $s0, $zero
/* 19A1C8 8026B8E8 8E510000 */  lw        $s1, ($s2)
/* 19A1CC 8026B8EC 8E520004 */  lw        $s2, 4($s2)
/* 19A1D0 8026B8F0 0C09A75B */  jal       get_actor
/* 19A1D4 8026B8F4 0040802D */   daddu    $s0, $v0, $zero
/* 19A1D8 8026B8F8 0040182D */  daddu     $v1, $v0, $zero
/* 19A1DC 8026B8FC A0700077 */  sb        $s0, 0x77($v1)
/* 19A1E0 8026B900 AC730064 */  sw        $s3, 0x64($v1)
/* 19A1E4 8026B904 AC710068 */  sw        $s1, 0x68($v1)
/* 19A1E8 8026B908 AC72006C */  sw        $s2, 0x6c($v1)
/* 19A1EC 8026B90C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19A1F0 8026B910 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19A1F4 8026B914 8FB20018 */  lw        $s2, 0x18($sp)
/* 19A1F8 8026B918 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A1FC 8026B91C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A200 8026B920 24020002 */  addiu     $v0, $zero, 2
/* 19A204 8026B924 03E00008 */  jr        $ra
/* 19A208 8026B928 27BD0028 */   addiu    $sp, $sp, 0x28
