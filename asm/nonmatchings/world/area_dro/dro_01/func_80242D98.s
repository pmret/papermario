.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D98
/* 95DF98 80242D98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95DF9C 80242D9C AFB10014 */  sw        $s1, 0x14($sp)
/* 95DFA0 80242DA0 0080882D */  daddu     $s1, $a0, $zero
/* 95DFA4 80242DA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95DFA8 80242DA8 AFB00010 */  sw        $s0, 0x10($sp)
/* 95DFAC 80242DAC 8E30000C */  lw        $s0, 0xc($s1)
/* 95DFB0 80242DB0 8E050000 */  lw        $a1, ($s0)
/* 95DFB4 80242DB4 0C0B1EAF */  jal       get_variable
/* 95DFB8 80242DB8 26100004 */   addiu    $s0, $s0, 4
/* 95DFBC 80242DBC AE22008C */  sw        $v0, 0x8c($s1)
/* 95DFC0 80242DC0 8E050000 */  lw        $a1, ($s0)
/* 95DFC4 80242DC4 26100004 */  addiu     $s0, $s0, 4
/* 95DFC8 80242DC8 0C0B1EAF */  jal       get_variable
/* 95DFCC 80242DCC 0220202D */   daddu    $a0, $s1, $zero
/* 95DFD0 80242DD0 AE220090 */  sw        $v0, 0x90($s1)
/* 95DFD4 80242DD4 8E050000 */  lw        $a1, ($s0)
/* 95DFD8 80242DD8 26100004 */  addiu     $s0, $s0, 4
/* 95DFDC 80242DDC 0C0B1EAF */  jal       get_variable
/* 95DFE0 80242DE0 0220202D */   daddu    $a0, $s1, $zero
/* 95DFE4 80242DE4 AE220094 */  sw        $v0, 0x94($s1)
/* 95DFE8 80242DE8 8E050000 */  lw        $a1, ($s0)
/* 95DFEC 80242DEC 26100004 */  addiu     $s0, $s0, 4
/* 95DFF0 80242DF0 0C0B1EAF */  jal       get_variable
/* 95DFF4 80242DF4 0220202D */   daddu    $a0, $s1, $zero
/* 95DFF8 80242DF8 AE220098 */  sw        $v0, 0x98($s1)
/* 95DFFC 80242DFC 8E050000 */  lw        $a1, ($s0)
/* 95E000 80242E00 26100004 */  addiu     $s0, $s0, 4
/* 95E004 80242E04 0C0B1EAF */  jal       get_variable
/* 95E008 80242E08 0220202D */   daddu    $a0, $s1, $zero
/* 95E00C 80242E0C AE22009C */  sw        $v0, 0x9c($s1)
/* 95E010 80242E10 8E050000 */  lw        $a1, ($s0)
/* 95E014 80242E14 26100004 */  addiu     $s0, $s0, 4
/* 95E018 80242E18 0C0B1EAF */  jal       get_variable
/* 95E01C 80242E1C 0220202D */   daddu    $a0, $s1, $zero
/* 95E020 80242E20 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 95E024 80242E24 8E050000 */  lw        $a1, ($s0)
/* 95E028 80242E28 26100004 */  addiu     $s0, $s0, 4
/* 95E02C 80242E2C 0C0B1EAF */  jal       get_variable
/* 95E030 80242E30 0220202D */   daddu    $a0, $s1, $zero
/* 95E034 80242E34 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 95E038 80242E38 8E050000 */  lw        $a1, ($s0)
/* 95E03C 80242E3C 26100004 */  addiu     $s0, $s0, 4
/* 95E040 80242E40 0C0B1EAF */  jal       get_variable
/* 95E044 80242E44 0220202D */   daddu    $a0, $s1, $zero
/* 95E048 80242E48 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 95E04C 80242E4C 8E050000 */  lw        $a1, ($s0)
/* 95E050 80242E50 26100004 */  addiu     $s0, $s0, 4
/* 95E054 80242E54 0C0B1EAF */  jal       get_variable
/* 95E058 80242E58 0220202D */   daddu    $a0, $s1, $zero
/* 95E05C 80242E5C AE2200AC */  sw        $v0, 0xac($s1)
/* 95E060 80242E60 8E050000 */  lw        $a1, ($s0)
/* 95E064 80242E64 0C0B1EAF */  jal       get_variable
/* 95E068 80242E68 0220202D */   daddu    $a0, $s1, $zero
/* 95E06C 80242E6C AE2200B0 */  sw        $v0, 0xb0($s1)
/* 95E070 80242E70 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95E074 80242E74 8FB10014 */  lw        $s1, 0x14($sp)
/* 95E078 80242E78 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E07C 80242E7C 24020002 */  addiu     $v0, $zero, 2
/* 95E080 80242E80 03E00008 */  jr        $ra
/* 95E084 80242E84 27BD0020 */   addiu    $sp, $sp, 0x20
