.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219DF0_66BB70
/* 66BB70 80219DF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66BB74 80219DF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 66BB78 80219DF8 0080882D */  daddu     $s1, $a0, $zero
/* 66BB7C 80219DFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 66BB80 80219E00 AFB00010 */  sw        $s0, 0x10($sp)
/* 66BB84 80219E04 8E30000C */  lw        $s0, 0xc($s1)
/* 66BB88 80219E08 8E050000 */  lw        $a1, ($s0)
/* 66BB8C 80219E0C 0C0B1EAF */  jal       get_variable
/* 66BB90 80219E10 26100004 */   addiu    $s0, $s0, 4
/* 66BB94 80219E14 0220202D */  daddu     $a0, $s1, $zero
/* 66BB98 80219E18 8E050000 */  lw        $a1, ($s0)
/* 66BB9C 80219E1C 0C0B1EAF */  jal       get_variable
/* 66BBA0 80219E20 0040802D */   daddu    $s0, $v0, $zero
/* 66BBA4 80219E24 0200202D */  daddu     $a0, $s0, $zero
/* 66BBA8 80219E28 0C00A3C2 */  jal       start_rumble
/* 66BBAC 80219E2C 0040282D */   daddu    $a1, $v0, $zero
/* 66BBB0 80219E30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 66BBB4 80219E34 8FB10014 */  lw        $s1, 0x14($sp)
/* 66BBB8 80219E38 8FB00010 */  lw        $s0, 0x10($sp)
/* 66BBBC 80219E3C 24020002 */  addiu     $v0, $zero, 2
/* 66BBC0 80219E40 03E00008 */  jr        $ra
/* 66BBC4 80219E44 27BD0020 */   addiu    $sp, $sp, 0x20
