.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026DA94
/* 19C374 8026DA94 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19C378 8026DA98 AFB10014 */  sw        $s1, 0x14($sp)
/* 19C37C 8026DA9C 0080882D */  daddu     $s1, $a0, $zero
/* 19C380 8026DAA0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19C384 8026DAA4 AFB40020 */  sw        $s4, 0x20($sp)
/* 19C388 8026DAA8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19C38C 8026DAAC AFB20018 */  sw        $s2, 0x18($sp)
/* 19C390 8026DAB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 19C394 8026DAB4 8E30000C */  lw        $s0, 0xc($s1)
/* 19C398 8026DAB8 8E050000 */  lw        $a1, ($s0)
/* 19C39C 8026DABC 0C0B1EAF */  jal       get_variable
/* 19C3A0 8026DAC0 26100004 */   addiu    $s0, $s0, 4
/* 19C3A4 8026DAC4 0040A02D */  daddu     $s4, $v0, $zero
/* 19C3A8 8026DAC8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19C3AC 8026DACC 16820002 */  bne       $s4, $v0, .L8026DAD8
/* 19C3B0 8026DAD0 00000000 */   nop      
/* 19C3B4 8026DAD4 8E340148 */  lw        $s4, 0x148($s1)
.L8026DAD8:
/* 19C3B8 8026DAD8 8E050000 */  lw        $a1, ($s0)
/* 19C3BC 8026DADC 26100004 */  addiu     $s0, $s0, 4
/* 19C3C0 8026DAE0 0C0B1EAF */  jal       get_variable
/* 19C3C4 8026DAE4 0220202D */   daddu    $a0, $s1, $zero
/* 19C3C8 8026DAE8 8E050000 */  lw        $a1, ($s0)
/* 19C3CC 8026DAEC 26100004 */  addiu     $s0, $s0, 4
/* 19C3D0 8026DAF0 0220202D */  daddu     $a0, $s1, $zero
/* 19C3D4 8026DAF4 0C0B1EAF */  jal       get_variable
/* 19C3D8 8026DAF8 0040982D */   daddu    $s3, $v0, $zero
/* 19C3DC 8026DAFC 8E050000 */  lw        $a1, ($s0)
/* 19C3E0 8026DB00 26100004 */  addiu     $s0, $s0, 4
/* 19C3E4 8026DB04 0220202D */  daddu     $a0, $s1, $zero
/* 19C3E8 8026DB08 0C0B1EAF */  jal       get_variable
/* 19C3EC 8026DB0C 0040902D */   daddu    $s2, $v0, $zero
/* 19C3F0 8026DB10 0220202D */  daddu     $a0, $s1, $zero
/* 19C3F4 8026DB14 8E050000 */  lw        $a1, ($s0)
/* 19C3F8 8026DB18 0C0B1EAF */  jal       get_variable
/* 19C3FC 8026DB1C 0040882D */   daddu    $s1, $v0, $zero
/* 19C400 8026DB20 0280202D */  daddu     $a0, $s4, $zero
/* 19C404 8026DB24 0C09A75B */  jal       get_actor
/* 19C408 8026DB28 0040802D */   daddu    $s0, $v0, $zero
/* 19C40C 8026DB2C 0040182D */  daddu     $v1, $v0, $zero
/* 19C410 8026DB30 A0730194 */  sb        $s3, 0x194($v1)
/* 19C414 8026DB34 A0720195 */  sb        $s2, 0x195($v1)
/* 19C418 8026DB38 A0710196 */  sb        $s1, 0x196($v1)
/* 19C41C 8026DB3C A0700197 */  sb        $s0, 0x197($v1)
/* 19C420 8026DB40 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19C424 8026DB44 8FB40020 */  lw        $s4, 0x20($sp)
/* 19C428 8026DB48 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19C42C 8026DB4C 8FB20018 */  lw        $s2, 0x18($sp)
/* 19C430 8026DB50 8FB10014 */  lw        $s1, 0x14($sp)
/* 19C434 8026DB54 8FB00010 */  lw        $s0, 0x10($sp)
/* 19C438 8026DB58 24020002 */  addiu     $v0, $zero, 2
/* 19C43C 8026DB5C 03E00008 */  jr        $ra
/* 19C440 8026DB60 27BD0028 */   addiu    $sp, $sp, 0x28
