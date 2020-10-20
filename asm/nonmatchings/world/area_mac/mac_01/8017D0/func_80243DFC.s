.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243DFC
/* 80467C 80243DFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 804680 80243E00 AFB10014 */  sw        $s1, 0x14($sp)
/* 804684 80243E04 0080882D */  daddu     $s1, $a0, $zero
/* 804688 80243E08 AFBF0018 */  sw        $ra, 0x18($sp)
/* 80468C 80243E0C AFB00010 */  sw        $s0, 0x10($sp)
/* 804690 80243E10 8E30000C */  lw        $s0, 0xc($s1)
/* 804694 80243E14 8E050000 */  lw        $a1, ($s0)
/* 804698 80243E18 0C0B1EAF */  jal       get_variable
/* 80469C 80243E1C 26100004 */   addiu    $s0, $s0, 4
/* 8046A0 80243E20 AE22008C */  sw        $v0, 0x8c($s1)
/* 8046A4 80243E24 8E050000 */  lw        $a1, ($s0)
/* 8046A8 80243E28 26100004 */  addiu     $s0, $s0, 4
/* 8046AC 80243E2C 0C0B1EAF */  jal       get_variable
/* 8046B0 80243E30 0220202D */   daddu    $a0, $s1, $zero
/* 8046B4 80243E34 AE220090 */  sw        $v0, 0x90($s1)
/* 8046B8 80243E38 8E050000 */  lw        $a1, ($s0)
/* 8046BC 80243E3C 26100004 */  addiu     $s0, $s0, 4
/* 8046C0 80243E40 0C0B1EAF */  jal       get_variable
/* 8046C4 80243E44 0220202D */   daddu    $a0, $s1, $zero
/* 8046C8 80243E48 AE220094 */  sw        $v0, 0x94($s1)
/* 8046CC 80243E4C 8E050000 */  lw        $a1, ($s0)
/* 8046D0 80243E50 26100004 */  addiu     $s0, $s0, 4
/* 8046D4 80243E54 0C0B1EAF */  jal       get_variable
/* 8046D8 80243E58 0220202D */   daddu    $a0, $s1, $zero
/* 8046DC 80243E5C AE220098 */  sw        $v0, 0x98($s1)
/* 8046E0 80243E60 8E050000 */  lw        $a1, ($s0)
/* 8046E4 80243E64 26100004 */  addiu     $s0, $s0, 4
/* 8046E8 80243E68 0C0B1EAF */  jal       get_variable
/* 8046EC 80243E6C 0220202D */   daddu    $a0, $s1, $zero
/* 8046F0 80243E70 AE22009C */  sw        $v0, 0x9c($s1)
/* 8046F4 80243E74 8E050000 */  lw        $a1, ($s0)
/* 8046F8 80243E78 26100004 */  addiu     $s0, $s0, 4
/* 8046FC 80243E7C 0C0B1EAF */  jal       get_variable
/* 804700 80243E80 0220202D */   daddu    $a0, $s1, $zero
/* 804704 80243E84 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 804708 80243E88 8E050000 */  lw        $a1, ($s0)
/* 80470C 80243E8C 26100004 */  addiu     $s0, $s0, 4
/* 804710 80243E90 0C0B1EAF */  jal       get_variable
/* 804714 80243E94 0220202D */   daddu    $a0, $s1, $zero
/* 804718 80243E98 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 80471C 80243E9C 8E050000 */  lw        $a1, ($s0)
/* 804720 80243EA0 26100004 */  addiu     $s0, $s0, 4
/* 804724 80243EA4 0C0B1EAF */  jal       get_variable
/* 804728 80243EA8 0220202D */   daddu    $a0, $s1, $zero
/* 80472C 80243EAC AE2200A8 */  sw        $v0, 0xa8($s1)
/* 804730 80243EB0 8E050000 */  lw        $a1, ($s0)
/* 804734 80243EB4 26100004 */  addiu     $s0, $s0, 4
/* 804738 80243EB8 0C0B1EAF */  jal       get_variable
/* 80473C 80243EBC 0220202D */   daddu    $a0, $s1, $zero
/* 804740 80243EC0 AE2200AC */  sw        $v0, 0xac($s1)
/* 804744 80243EC4 8E050000 */  lw        $a1, ($s0)
/* 804748 80243EC8 0C0B1EAF */  jal       get_variable
/* 80474C 80243ECC 0220202D */   daddu    $a0, $s1, $zero
/* 804750 80243ED0 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 804754 80243ED4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 804758 80243ED8 8FB10014 */  lw        $s1, 0x14($sp)
/* 80475C 80243EDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 804760 80243EE0 24020002 */  addiu     $v0, $zero, 2
/* 804764 80243EE4 03E00008 */  jr        $ra
/* 804768 80243EE8 27BD0020 */   addiu    $sp, $sp, 0x20
