.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AB4
/* 7EC7C4 80241AB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EC7C8 80241AB8 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EC7CC 80241ABC 0080882D */  daddu     $s1, $a0, $zero
/* 7EC7D0 80241AC0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EC7D4 80241AC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EC7D8 80241AC8 8E30000C */  lw        $s0, 0xc($s1)
/* 7EC7DC 80241ACC 8E050000 */  lw        $a1, ($s0)
/* 7EC7E0 80241AD0 0C0B1EAF */  jal       get_variable
/* 7EC7E4 80241AD4 26100004 */   addiu    $s0, $s0, 4
/* 7EC7E8 80241AD8 AE22008C */  sw        $v0, 0x8c($s1)
/* 7EC7EC 80241ADC 8E050000 */  lw        $a1, ($s0)
/* 7EC7F0 80241AE0 26100004 */  addiu     $s0, $s0, 4
/* 7EC7F4 80241AE4 0C0B1EAF */  jal       get_variable
/* 7EC7F8 80241AE8 0220202D */   daddu    $a0, $s1, $zero
/* 7EC7FC 80241AEC AE220090 */  sw        $v0, 0x90($s1)
/* 7EC800 80241AF0 8E050000 */  lw        $a1, ($s0)
/* 7EC804 80241AF4 26100004 */  addiu     $s0, $s0, 4
/* 7EC808 80241AF8 0C0B1EAF */  jal       get_variable
/* 7EC80C 80241AFC 0220202D */   daddu    $a0, $s1, $zero
/* 7EC810 80241B00 AE220094 */  sw        $v0, 0x94($s1)
/* 7EC814 80241B04 8E050000 */  lw        $a1, ($s0)
/* 7EC818 80241B08 26100004 */  addiu     $s0, $s0, 4
/* 7EC81C 80241B0C 0C0B1EAF */  jal       get_variable
/* 7EC820 80241B10 0220202D */   daddu    $a0, $s1, $zero
/* 7EC824 80241B14 AE220098 */  sw        $v0, 0x98($s1)
/* 7EC828 80241B18 8E050000 */  lw        $a1, ($s0)
/* 7EC82C 80241B1C 26100004 */  addiu     $s0, $s0, 4
/* 7EC830 80241B20 0C0B1EAF */  jal       get_variable
/* 7EC834 80241B24 0220202D */   daddu    $a0, $s1, $zero
/* 7EC838 80241B28 AE22009C */  sw        $v0, 0x9c($s1)
/* 7EC83C 80241B2C 8E050000 */  lw        $a1, ($s0)
/* 7EC840 80241B30 26100004 */  addiu     $s0, $s0, 4
/* 7EC844 80241B34 0C0B1EAF */  jal       get_variable
/* 7EC848 80241B38 0220202D */   daddu    $a0, $s1, $zero
/* 7EC84C 80241B3C AE2200A0 */  sw        $v0, 0xa0($s1)
/* 7EC850 80241B40 8E050000 */  lw        $a1, ($s0)
/* 7EC854 80241B44 26100004 */  addiu     $s0, $s0, 4
/* 7EC858 80241B48 0C0B1EAF */  jal       get_variable
/* 7EC85C 80241B4C 0220202D */   daddu    $a0, $s1, $zero
/* 7EC860 80241B50 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 7EC864 80241B54 8E050000 */  lw        $a1, ($s0)
/* 7EC868 80241B58 26100004 */  addiu     $s0, $s0, 4
/* 7EC86C 80241B5C 0C0B1EAF */  jal       get_variable
/* 7EC870 80241B60 0220202D */   daddu    $a0, $s1, $zero
/* 7EC874 80241B64 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 7EC878 80241B68 8E050000 */  lw        $a1, ($s0)
/* 7EC87C 80241B6C 26100004 */  addiu     $s0, $s0, 4
/* 7EC880 80241B70 0C0B1EAF */  jal       get_variable
/* 7EC884 80241B74 0220202D */   daddu    $a0, $s1, $zero
/* 7EC888 80241B78 AE2200AC */  sw        $v0, 0xac($s1)
/* 7EC88C 80241B7C 8E050000 */  lw        $a1, ($s0)
/* 7EC890 80241B80 0C0B1EAF */  jal       get_variable
/* 7EC894 80241B84 0220202D */   daddu    $a0, $s1, $zero
/* 7EC898 80241B88 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 7EC89C 80241B8C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EC8A0 80241B90 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EC8A4 80241B94 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EC8A8 80241B98 24020002 */  addiu     $v0, $zero, 2
/* 7EC8AC 80241B9C 03E00008 */  jr        $ra
/* 7EC8B0 80241BA0 27BD0020 */   addiu    $sp, $sp, 0x20
