.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A08_C63718
/* C63718 80242A08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C6371C 80242A0C AFB10014 */  sw        $s1, 0x14($sp)
/* C63720 80242A10 0080882D */  daddu     $s1, $a0, $zero
/* C63724 80242A14 AFBF0018 */  sw        $ra, 0x18($sp)
/* C63728 80242A18 AFB00010 */  sw        $s0, 0x10($sp)
/* C6372C 80242A1C 8E30000C */  lw        $s0, 0xc($s1)
/* C63730 80242A20 8E050000 */  lw        $a1, ($s0)
/* C63734 80242A24 0C0B1EAF */  jal       get_variable
/* C63738 80242A28 26100004 */   addiu    $s0, $s0, 4
/* C6373C 80242A2C AE22008C */  sw        $v0, 0x8c($s1)
/* C63740 80242A30 8E050000 */  lw        $a1, ($s0)
/* C63744 80242A34 26100004 */  addiu     $s0, $s0, 4
/* C63748 80242A38 0C0B1EAF */  jal       get_variable
/* C6374C 80242A3C 0220202D */   daddu    $a0, $s1, $zero
/* C63750 80242A40 AE220090 */  sw        $v0, 0x90($s1)
/* C63754 80242A44 8E050000 */  lw        $a1, ($s0)
/* C63758 80242A48 26100004 */  addiu     $s0, $s0, 4
/* C6375C 80242A4C 0C0B1EAF */  jal       get_variable
/* C63760 80242A50 0220202D */   daddu    $a0, $s1, $zero
/* C63764 80242A54 AE220094 */  sw        $v0, 0x94($s1)
/* C63768 80242A58 8E050000 */  lw        $a1, ($s0)
/* C6376C 80242A5C 26100004 */  addiu     $s0, $s0, 4
/* C63770 80242A60 0C0B1EAF */  jal       get_variable
/* C63774 80242A64 0220202D */   daddu    $a0, $s1, $zero
/* C63778 80242A68 AE220098 */  sw        $v0, 0x98($s1)
/* C6377C 80242A6C 8E050000 */  lw        $a1, ($s0)
/* C63780 80242A70 26100004 */  addiu     $s0, $s0, 4
/* C63784 80242A74 0C0B1EAF */  jal       get_variable
/* C63788 80242A78 0220202D */   daddu    $a0, $s1, $zero
/* C6378C 80242A7C AE22009C */  sw        $v0, 0x9c($s1)
/* C63790 80242A80 8E050000 */  lw        $a1, ($s0)
/* C63794 80242A84 26100004 */  addiu     $s0, $s0, 4
/* C63798 80242A88 0C0B1EAF */  jal       get_variable
/* C6379C 80242A8C 0220202D */   daddu    $a0, $s1, $zero
/* C637A0 80242A90 AE2200A0 */  sw        $v0, 0xa0($s1)
/* C637A4 80242A94 8E050000 */  lw        $a1, ($s0)
/* C637A8 80242A98 26100004 */  addiu     $s0, $s0, 4
/* C637AC 80242A9C 0C0B1EAF */  jal       get_variable
/* C637B0 80242AA0 0220202D */   daddu    $a0, $s1, $zero
/* C637B4 80242AA4 AE2200A4 */  sw        $v0, 0xa4($s1)
/* C637B8 80242AA8 8E050000 */  lw        $a1, ($s0)
/* C637BC 80242AAC 26100004 */  addiu     $s0, $s0, 4
/* C637C0 80242AB0 0C0B1EAF */  jal       get_variable
/* C637C4 80242AB4 0220202D */   daddu    $a0, $s1, $zero
/* C637C8 80242AB8 AE2200A8 */  sw        $v0, 0xa8($s1)
/* C637CC 80242ABC 8E050000 */  lw        $a1, ($s0)
/* C637D0 80242AC0 26100004 */  addiu     $s0, $s0, 4
/* C637D4 80242AC4 0C0B1EAF */  jal       get_variable
/* C637D8 80242AC8 0220202D */   daddu    $a0, $s1, $zero
/* C637DC 80242ACC AE2200AC */  sw        $v0, 0xac($s1)
/* C637E0 80242AD0 8E050000 */  lw        $a1, ($s0)
/* C637E4 80242AD4 0C0B1EAF */  jal       get_variable
/* C637E8 80242AD8 0220202D */   daddu    $a0, $s1, $zero
/* C637EC 80242ADC AE2200B0 */  sw        $v0, 0xb0($s1)
/* C637F0 80242AE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C637F4 80242AE4 8FB10014 */  lw        $s1, 0x14($sp)
/* C637F8 80242AE8 8FB00010 */  lw        $s0, 0x10($sp)
/* C637FC 80242AEC 24020002 */  addiu     $v0, $zero, 2
/* C63800 80242AF0 03E00008 */  jr        $ra
/* C63804 80242AF4 27BD0020 */   addiu    $sp, $sp, 0x20
