.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427A4
/* 854914 802427A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 854918 802427A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 85491C 802427AC 0080882D */  daddu     $s1, $a0, $zero
/* 854920 802427B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 854924 802427B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 854928 802427B8 8E30000C */  lw        $s0, 0xc($s1)
/* 85492C 802427BC 8E050000 */  lw        $a1, ($s0)
/* 854930 802427C0 0C0B1EAF */  jal       get_variable
/* 854934 802427C4 26100004 */   addiu    $s0, $s0, 4
/* 854938 802427C8 AE22008C */  sw        $v0, 0x8c($s1)
/* 85493C 802427CC 8E050000 */  lw        $a1, ($s0)
/* 854940 802427D0 26100004 */  addiu     $s0, $s0, 4
/* 854944 802427D4 0C0B1EAF */  jal       get_variable
/* 854948 802427D8 0220202D */   daddu    $a0, $s1, $zero
/* 85494C 802427DC AE220090 */  sw        $v0, 0x90($s1)
/* 854950 802427E0 8E050000 */  lw        $a1, ($s0)
/* 854954 802427E4 26100004 */  addiu     $s0, $s0, 4
/* 854958 802427E8 0C0B1EAF */  jal       get_variable
/* 85495C 802427EC 0220202D */   daddu    $a0, $s1, $zero
/* 854960 802427F0 AE220094 */  sw        $v0, 0x94($s1)
/* 854964 802427F4 8E050000 */  lw        $a1, ($s0)
/* 854968 802427F8 26100004 */  addiu     $s0, $s0, 4
/* 85496C 802427FC 0C0B1EAF */  jal       get_variable
/* 854970 80242800 0220202D */   daddu    $a0, $s1, $zero
/* 854974 80242804 AE220098 */  sw        $v0, 0x98($s1)
/* 854978 80242808 8E050000 */  lw        $a1, ($s0)
/* 85497C 8024280C 26100004 */  addiu     $s0, $s0, 4
/* 854980 80242810 0C0B1EAF */  jal       get_variable
/* 854984 80242814 0220202D */   daddu    $a0, $s1, $zero
/* 854988 80242818 AE22009C */  sw        $v0, 0x9c($s1)
/* 85498C 8024281C 8E050000 */  lw        $a1, ($s0)
/* 854990 80242820 26100004 */  addiu     $s0, $s0, 4
/* 854994 80242824 0C0B1EAF */  jal       get_variable
/* 854998 80242828 0220202D */   daddu    $a0, $s1, $zero
/* 85499C 8024282C AE2200A0 */  sw        $v0, 0xa0($s1)
/* 8549A0 80242830 8E050000 */  lw        $a1, ($s0)
/* 8549A4 80242834 26100004 */  addiu     $s0, $s0, 4
/* 8549A8 80242838 0C0B1EAF */  jal       get_variable
/* 8549AC 8024283C 0220202D */   daddu    $a0, $s1, $zero
/* 8549B0 80242840 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 8549B4 80242844 8E050000 */  lw        $a1, ($s0)
/* 8549B8 80242848 26100004 */  addiu     $s0, $s0, 4
/* 8549BC 8024284C 0C0B1EAF */  jal       get_variable
/* 8549C0 80242850 0220202D */   daddu    $a0, $s1, $zero
/* 8549C4 80242854 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 8549C8 80242858 8E050000 */  lw        $a1, ($s0)
/* 8549CC 8024285C 26100004 */  addiu     $s0, $s0, 4
/* 8549D0 80242860 0C0B1EAF */  jal       get_variable
/* 8549D4 80242864 0220202D */   daddu    $a0, $s1, $zero
/* 8549D8 80242868 AE2200AC */  sw        $v0, 0xac($s1)
/* 8549DC 8024286C 8E050000 */  lw        $a1, ($s0)
/* 8549E0 80242870 0C0B1EAF */  jal       get_variable
/* 8549E4 80242874 0220202D */   daddu    $a0, $s1, $zero
/* 8549E8 80242878 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 8549EC 8024287C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8549F0 80242880 8FB10014 */  lw        $s1, 0x14($sp)
/* 8549F4 80242884 8FB00010 */  lw        $s0, 0x10($sp)
/* 8549F8 80242888 24020002 */  addiu     $v0, $zero, 2
/* 8549FC 8024288C 03E00008 */  jr        $ra
/* 854A00 80242890 27BD0020 */   addiu    $sp, $sp, 0x20
