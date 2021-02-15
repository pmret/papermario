.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A133C_7308DC
/* 7308DC 802A133C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7308E0 802A1340 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7308E4 802A1344 0080882D */  daddu     $s1, $a0, $zero
/* 7308E8 802A1348 AFBF0028 */  sw        $ra, 0x28($sp)
/* 7308EC 802A134C AFB30024 */  sw        $s3, 0x24($sp)
/* 7308F0 802A1350 AFB20020 */  sw        $s2, 0x20($sp)
/* 7308F4 802A1354 AFB00018 */  sw        $s0, 0x18($sp)
/* 7308F8 802A1358 8E30000C */  lw        $s0, 0xc($s1)
/* 7308FC 802A135C 8E050000 */  lw        $a1, ($s0)
/* 730900 802A1360 0C0B1EAF */  jal       get_variable
/* 730904 802A1364 26100004 */   addiu    $s0, $s0, 4
/* 730908 802A1368 8E050000 */  lw        $a1, ($s0)
/* 73090C 802A136C 26100004 */  addiu     $s0, $s0, 4
/* 730910 802A1370 0220202D */  daddu     $a0, $s1, $zero
/* 730914 802A1374 0C0B1EAF */  jal       get_variable
/* 730918 802A1378 0040982D */   daddu    $s3, $v0, $zero
/* 73091C 802A137C 8E050000 */  lw        $a1, ($s0)
/* 730920 802A1380 26100004 */  addiu     $s0, $s0, 4
/* 730924 802A1384 0220202D */  daddu     $a0, $s1, $zero
/* 730928 802A1388 0C0B1EAF */  jal       get_variable
/* 73092C 802A138C 0040902D */   daddu    $s2, $v0, $zero
/* 730930 802A1390 0220202D */  daddu     $a0, $s1, $zero
/* 730934 802A1394 8E050000 */  lw        $a1, ($s0)
/* 730938 802A1398 0C0B1EAF */  jal       get_variable
/* 73093C 802A139C 0040802D */   daddu    $s0, $v0, $zero
/* 730940 802A13A0 44930000 */  mtc1      $s3, $f0
/* 730944 802A13A4 00000000 */  nop
/* 730948 802A13A8 46800020 */  cvt.s.w   $f0, $f0
/* 73094C 802A13AC 44050000 */  mfc1      $a1, $f0
/* 730950 802A13B0 44920000 */  mtc1      $s2, $f0
/* 730954 802A13B4 00000000 */  nop
/* 730958 802A13B8 46800020 */  cvt.s.w   $f0, $f0
/* 73095C 802A13BC 44060000 */  mfc1      $a2, $f0
/* 730960 802A13C0 44900000 */  mtc1      $s0, $f0
/* 730964 802A13C4 00000000 */  nop
/* 730968 802A13C8 46800020 */  cvt.s.w   $f0, $f0
/* 73096C 802A13CC 44070000 */  mfc1      $a3, $f0
/* 730970 802A13D0 24040001 */  addiu     $a0, $zero, 1
/* 730974 802A13D4 0C01C424 */  jal       func_80071090
/* 730978 802A13D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 73097C 802A13DC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 730980 802A13E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 730984 802A13E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 730988 802A13E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 73098C 802A13EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 730990 802A13F0 24020002 */  addiu     $v0, $zero, 2
/* 730994 802A13F4 03E00008 */  jr        $ra
/* 730998 802A13F8 27BD0030 */   addiu    $sp, $sp, 0x30
