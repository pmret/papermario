.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026EDE4
/* 19D6C4 8026EDE4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19D6C8 8026EDE8 AFB20018 */  sw        $s2, 0x18($sp)
/* 19D6CC 8026EDEC 0080902D */  daddu     $s2, $a0, $zero
/* 19D6D0 8026EDF0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19D6D4 8026EDF4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19D6D8 8026EDF8 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D6DC 8026EDFC AFB00010 */  sw        $s0, 0x10($sp)
/* 19D6E0 8026EE00 8E50000C */  lw        $s0, 0xc($s2)
/* 19D6E4 8026EE04 8E050000 */  lw        $a1, ($s0)
/* 19D6E8 8026EE08 0C0B1EAF */  jal       get_variable
/* 19D6EC 8026EE0C 26100004 */   addiu    $s0, $s0, 4
/* 19D6F0 8026EE10 0040882D */  daddu     $s1, $v0, $zero
/* 19D6F4 8026EE14 8E050000 */  lw        $a1, ($s0)
/* 19D6F8 8026EE18 26100004 */  addiu     $s0, $s0, 4
/* 19D6FC 8026EE1C 0C0B1EAF */  jal       get_variable
/* 19D700 8026EE20 0240202D */   daddu    $a0, $s2, $zero
/* 19D704 8026EE24 0240202D */  daddu     $a0, $s2, $zero
/* 19D708 8026EE28 8E050000 */  lw        $a1, ($s0)
/* 19D70C 8026EE2C 0C0B1EAF */  jal       get_variable
/* 19D710 8026EE30 0040802D */   daddu    $s0, $v0, $zero
/* 19D714 8026EE34 0040982D */  daddu     $s3, $v0, $zero
/* 19D718 8026EE38 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D71C 8026EE3C 16220002 */  bne       $s1, $v0, .L8026EE48
/* 19D720 8026EE40 00000000 */   nop      
/* 19D724 8026EE44 8E510148 */  lw        $s1, 0x148($s2)
.L8026EE48:
/* 19D728 8026EE48 0C09A75B */  jal       get_actor
/* 19D72C 8026EE4C 0220202D */   daddu    $a0, $s1, $zero
/* 19D730 8026EE50 0040202D */  daddu     $a0, $v0, $zero
/* 19D734 8026EE54 0C099117 */  jal       get_actor_part
/* 19D738 8026EE58 0200282D */   daddu    $a1, $s0, $zero
/* 19D73C 8026EE5C 0040202D */  daddu     $a0, $v0, $zero
/* 19D740 8026EE60 0C099BAA */  jal       func_80266EA8
/* 19D744 8026EE64 0260282D */   daddu    $a1, $s3, $zero
/* 19D748 8026EE68 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19D74C 8026EE6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D750 8026EE70 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D754 8026EE74 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D758 8026EE78 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D75C 8026EE7C 24020002 */  addiu     $v0, $zero, 2
/* 19D760 8026EE80 03E00008 */  jr        $ra
/* 19D764 8026EE84 27BD0028 */   addiu    $sp, $sp, 0x28
