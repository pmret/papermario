.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BA0_4B1D90
/* 4B1D90 80218BA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B1D94 80218BA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B1D98 80218BA8 0080882D */  daddu     $s1, $a0, $zero
/* 4B1D9C 80218BAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B1DA0 80218BB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1DA4 80218BB4 8E30000C */  lw        $s0, 0xc($s1)
/* 4B1DA8 80218BB8 8E050000 */  lw        $a1, ($s0)
/* 4B1DAC 80218BBC 0C0B1EAF */  jal       get_variable
/* 4B1DB0 80218BC0 26100004 */   addiu    $s0, $s0, 4
/* 4B1DB4 80218BC4 0220202D */  daddu     $a0, $s1, $zero
/* 4B1DB8 80218BC8 8E050000 */  lw        $a1, ($s0)
/* 4B1DBC 80218BCC 0C0B1EAF */  jal       get_variable
/* 4B1DC0 80218BD0 0040802D */   daddu    $s0, $v0, $zero
/* 4B1DC4 80218BD4 0200202D */  daddu     $a0, $s0, $zero
/* 4B1DC8 80218BD8 0C00A3C2 */  jal       start_rumble
/* 4B1DCC 80218BDC 0040282D */   daddu    $a1, $v0, $zero
/* 4B1DD0 80218BE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B1DD4 80218BE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B1DD8 80218BE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B1DDC 80218BEC 24020002 */  addiu     $v0, $zero, 2
/* 4B1DE0 80218BF0 03E00008 */  jr        $ra
/* 4B1DE4 80218BF4 27BD0020 */   addiu    $sp, $sp, 0x20
