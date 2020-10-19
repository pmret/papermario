.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412E4
/* 940894 802412E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 940898 802412E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 94089C 802412EC 0080882D */  daddu     $s1, $a0, $zero
/* 9408A0 802412F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9408A4 802412F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9408A8 802412F8 8E30000C */  lw        $s0, 0xc($s1)
/* 9408AC 802412FC 8E050000 */  lw        $a1, ($s0)
/* 9408B0 80241300 0C0B1EAF */  jal       get_variable
/* 9408B4 80241304 26100004 */   addiu    $s0, $s0, 4
/* 9408B8 80241308 AE22008C */  sw        $v0, 0x8c($s1)
/* 9408BC 8024130C 8E050000 */  lw        $a1, ($s0)
/* 9408C0 80241310 26100004 */  addiu     $s0, $s0, 4
/* 9408C4 80241314 0C0B1EAF */  jal       get_variable
/* 9408C8 80241318 0220202D */   daddu    $a0, $s1, $zero
/* 9408CC 8024131C AE220090 */  sw        $v0, 0x90($s1)
/* 9408D0 80241320 8E050000 */  lw        $a1, ($s0)
/* 9408D4 80241324 26100004 */  addiu     $s0, $s0, 4
/* 9408D8 80241328 0C0B1EAF */  jal       get_variable
/* 9408DC 8024132C 0220202D */   daddu    $a0, $s1, $zero
/* 9408E0 80241330 AE220094 */  sw        $v0, 0x94($s1)
/* 9408E4 80241334 8E050000 */  lw        $a1, ($s0)
/* 9408E8 80241338 26100004 */  addiu     $s0, $s0, 4
/* 9408EC 8024133C 0C0B1EAF */  jal       get_variable
/* 9408F0 80241340 0220202D */   daddu    $a0, $s1, $zero
/* 9408F4 80241344 AE220098 */  sw        $v0, 0x98($s1)
/* 9408F8 80241348 8E050000 */  lw        $a1, ($s0)
/* 9408FC 8024134C 26100004 */  addiu     $s0, $s0, 4
/* 940900 80241350 0C0B1EAF */  jal       get_variable
/* 940904 80241354 0220202D */   daddu    $a0, $s1, $zero
/* 940908 80241358 AE22009C */  sw        $v0, 0x9c($s1)
/* 94090C 8024135C 8E050000 */  lw        $a1, ($s0)
/* 940910 80241360 26100004 */  addiu     $s0, $s0, 4
/* 940914 80241364 0C0B1EAF */  jal       get_variable
/* 940918 80241368 0220202D */   daddu    $a0, $s1, $zero
/* 94091C 8024136C AE2200A0 */  sw        $v0, 0xa0($s1)
/* 940920 80241370 8E050000 */  lw        $a1, ($s0)
/* 940924 80241374 26100004 */  addiu     $s0, $s0, 4
/* 940928 80241378 0C0B1EAF */  jal       get_variable
/* 94092C 8024137C 0220202D */   daddu    $a0, $s1, $zero
/* 940930 80241380 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 940934 80241384 8E050000 */  lw        $a1, ($s0)
/* 940938 80241388 26100004 */  addiu     $s0, $s0, 4
/* 94093C 8024138C 0C0B1EAF */  jal       get_variable
/* 940940 80241390 0220202D */   daddu    $a0, $s1, $zero
/* 940944 80241394 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 940948 80241398 8E050000 */  lw        $a1, ($s0)
/* 94094C 8024139C 26100004 */  addiu     $s0, $s0, 4
/* 940950 802413A0 0C0B1EAF */  jal       get_variable
/* 940954 802413A4 0220202D */   daddu    $a0, $s1, $zero
/* 940958 802413A8 AE2200AC */  sw        $v0, 0xac($s1)
/* 94095C 802413AC 8E050000 */  lw        $a1, ($s0)
/* 940960 802413B0 0C0B1EAF */  jal       get_variable
/* 940964 802413B4 0220202D */   daddu    $a0, $s1, $zero
/* 940968 802413B8 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 94096C 802413BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 940970 802413C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 940974 802413C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 940978 802413C8 24020002 */  addiu     $v0, $zero, 2
/* 94097C 802413CC 03E00008 */  jr        $ra
/* 940980 802413D0 27BD0020 */   addiu    $sp, $sp, 0x20
