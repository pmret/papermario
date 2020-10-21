.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CF8_9D9D18
/* 9D9D18 80242CF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D9D1C 80242CFC AFB10014 */  sw        $s1, 0x14($sp)
/* 9D9D20 80242D00 0080882D */  daddu     $s1, $a0, $zero
/* 9D9D24 80242D04 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D9D28 80242D08 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D9D2C 80242D0C 8E30000C */  lw        $s0, 0xc($s1)
/* 9D9D30 80242D10 8E050000 */  lw        $a1, ($s0)
/* 9D9D34 80242D14 0C0B1EAF */  jal       get_variable
/* 9D9D38 80242D18 26100004 */   addiu    $s0, $s0, 4
/* 9D9D3C 80242D1C AE22008C */  sw        $v0, 0x8c($s1)
/* 9D9D40 80242D20 8E050000 */  lw        $a1, ($s0)
/* 9D9D44 80242D24 26100004 */  addiu     $s0, $s0, 4
/* 9D9D48 80242D28 0C0B1EAF */  jal       get_variable
/* 9D9D4C 80242D2C 0220202D */   daddu    $a0, $s1, $zero
/* 9D9D50 80242D30 AE220090 */  sw        $v0, 0x90($s1)
/* 9D9D54 80242D34 8E050000 */  lw        $a1, ($s0)
/* 9D9D58 80242D38 26100004 */  addiu     $s0, $s0, 4
/* 9D9D5C 80242D3C 0C0B1EAF */  jal       get_variable
/* 9D9D60 80242D40 0220202D */   daddu    $a0, $s1, $zero
/* 9D9D64 80242D44 AE220094 */  sw        $v0, 0x94($s1)
/* 9D9D68 80242D48 8E050000 */  lw        $a1, ($s0)
/* 9D9D6C 80242D4C 26100004 */  addiu     $s0, $s0, 4
/* 9D9D70 80242D50 0C0B1EAF */  jal       get_variable
/* 9D9D74 80242D54 0220202D */   daddu    $a0, $s1, $zero
/* 9D9D78 80242D58 AE220098 */  sw        $v0, 0x98($s1)
/* 9D9D7C 80242D5C 8E050000 */  lw        $a1, ($s0)
/* 9D9D80 80242D60 26100004 */  addiu     $s0, $s0, 4
/* 9D9D84 80242D64 0C0B1EAF */  jal       get_variable
/* 9D9D88 80242D68 0220202D */   daddu    $a0, $s1, $zero
/* 9D9D8C 80242D6C AE22009C */  sw        $v0, 0x9c($s1)
/* 9D9D90 80242D70 8E050000 */  lw        $a1, ($s0)
/* 9D9D94 80242D74 26100004 */  addiu     $s0, $s0, 4
/* 9D9D98 80242D78 0C0B1EAF */  jal       get_variable
/* 9D9D9C 80242D7C 0220202D */   daddu    $a0, $s1, $zero
/* 9D9DA0 80242D80 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 9D9DA4 80242D84 8E050000 */  lw        $a1, ($s0)
/* 9D9DA8 80242D88 26100004 */  addiu     $s0, $s0, 4
/* 9D9DAC 80242D8C 0C0B1EAF */  jal       get_variable
/* 9D9DB0 80242D90 0220202D */   daddu    $a0, $s1, $zero
/* 9D9DB4 80242D94 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 9D9DB8 80242D98 8E050000 */  lw        $a1, ($s0)
/* 9D9DBC 80242D9C 26100004 */  addiu     $s0, $s0, 4
/* 9D9DC0 80242DA0 0C0B1EAF */  jal       get_variable
/* 9D9DC4 80242DA4 0220202D */   daddu    $a0, $s1, $zero
/* 9D9DC8 80242DA8 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 9D9DCC 80242DAC 8E050000 */  lw        $a1, ($s0)
/* 9D9DD0 80242DB0 26100004 */  addiu     $s0, $s0, 4
/* 9D9DD4 80242DB4 0C0B1EAF */  jal       get_variable
/* 9D9DD8 80242DB8 0220202D */   daddu    $a0, $s1, $zero
/* 9D9DDC 80242DBC AE2200AC */  sw        $v0, 0xac($s1)
/* 9D9DE0 80242DC0 8E050000 */  lw        $a1, ($s0)
/* 9D9DE4 80242DC4 0C0B1EAF */  jal       get_variable
/* 9D9DE8 80242DC8 0220202D */   daddu    $a0, $s1, $zero
/* 9D9DEC 80242DCC AE2200B0 */  sw        $v0, 0xb0($s1)
/* 9D9DF0 80242DD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D9DF4 80242DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9DF8 80242DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9DFC 80242DDC 24020002 */  addiu     $v0, $zero, 2
/* 9D9E00 80242DE0 03E00008 */  jr        $ra
/* 9D9E04 80242DE4 27BD0020 */   addiu    $sp, $sp, 0x20
