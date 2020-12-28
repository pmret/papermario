.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218F00_6A0100
/* 6A0100 80218F00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A0104 80218F04 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A0108 80218F08 0080882D */  daddu     $s1, $a0, $zero
/* 6A010C 80218F0C AFBF0018 */  sw        $ra, 0x18($sp)
/* 6A0110 80218F10 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A0114 80218F14 8E30000C */  lw        $s0, 0xc($s1)
/* 6A0118 80218F18 8E050000 */  lw        $a1, ($s0)
/* 6A011C 80218F1C 0C0B1EAF */  jal       get_variable
/* 6A0120 80218F20 26100004 */   addiu    $s0, $s0, 4
/* 6A0124 80218F24 0220202D */  daddu     $a0, $s1, $zero
/* 6A0128 80218F28 8E050000 */  lw        $a1, ($s0)
/* 6A012C 80218F2C 0C0B1EAF */  jal       get_variable
/* 6A0130 80218F30 0040802D */   daddu    $s0, $v0, $zero
/* 6A0134 80218F34 0200202D */  daddu     $a0, $s0, $zero
/* 6A0138 80218F38 0C00A3C2 */  jal       start_rumble
/* 6A013C 80218F3C 0040282D */   daddu    $a1, $v0, $zero
/* 6A0140 80218F40 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6A0144 80218F44 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A0148 80218F48 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A014C 80218F4C 24020002 */  addiu     $v0, $zero, 2
/* 6A0150 80218F50 03E00008 */  jr        $ra
/* 6A0154 80218F54 27BD0020 */   addiu    $sp, $sp, 0x20
