.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800454F8
/* 208F8 800454F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 208FC 800454FC AFB10014 */  sw        $s1, 0x14($sp)
/* 20900 80045500 0080882D */  daddu     $s1, $a0, $zero
/* 20904 80045504 AFBF0020 */  sw        $ra, 0x20($sp)
/* 20908 80045508 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2090C 8004550C AFB20018 */  sw        $s2, 0x18($sp)
/* 20910 80045510 AFB00010 */  sw        $s0, 0x10($sp)
/* 20914 80045514 8E30000C */  lw        $s0, 0xc($s1)
/* 20918 80045518 8E050000 */  lw        $a1, ($s0)
/* 2091C 8004551C 0C0B1EAF */  jal       func_802C7ABC
/* 20920 80045520 26100004 */   addiu    $s0, $s0, 4
/* 20924 80045524 8E050000 */  lw        $a1, ($s0)
/* 20928 80045528 26100004 */  addiu     $s0, $s0, 4
/* 2092C 8004552C 0220202D */  daddu     $a0, $s1, $zero
/* 20930 80045530 0C0B1EAF */  jal       func_802C7ABC
/* 20934 80045534 0040902D */   daddu    $s2, $v0, $zero
/* 20938 80045538 0220202D */  daddu     $a0, $s1, $zero
/* 2093C 8004553C 8E050000 */  lw        $a1, ($s0)
/* 20940 80045540 0C0B1EAF */  jal       func_802C7ABC
/* 20944 80045544 0040982D */   daddu    $s3, $v0, $zero
/* 20948 80045548 0220202D */  daddu     $a0, $s1, $zero
/* 2094C 8004554C 0240282D */  daddu     $a1, $s2, $zero
/* 20950 80045550 0C0B36B0 */  jal       func_802CDAC0
/* 20954 80045554 0040802D */   daddu    $s0, $v0, $zero
/* 20958 80045558 10400004 */  beqz      $v0, .L8004556C
/* 2095C 8004555C 0040202D */   daddu    $a0, $v0, $zero
/* 20960 80045560 0260282D */  daddu     $a1, $s3, $zero
/* 20964 80045564 0C01245C */  jal       func_80049170
/* 20968 80045568 0200302D */   daddu    $a2, $s0, $zero
.L8004556C:
/* 2096C 8004556C 24020002 */  addiu     $v0, $zero, 2
/* 20970 80045570 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20974 80045574 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20978 80045578 8FB20018 */  lw        $s2, 0x18($sp)
/* 2097C 8004557C 8FB10014 */  lw        $s1, 0x14($sp)
/* 20980 80045580 8FB00010 */  lw        $s0, 0x10($sp)
/* 20984 80045584 03E00008 */  jr        $ra
/* 20988 80045588 27BD0028 */   addiu    $sp, $sp, 0x28
