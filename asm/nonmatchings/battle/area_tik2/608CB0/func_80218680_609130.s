.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218680_609130
/* 609130 80218680 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 609134 80218684 AFB10014 */  sw        $s1, 0x14($sp)
/* 609138 80218688 0080882D */  daddu     $s1, $a0, $zero
/* 60913C 8021868C AFBF0018 */  sw        $ra, 0x18($sp)
/* 609140 80218690 AFB00010 */  sw        $s0, 0x10($sp)
/* 609144 80218694 8E30000C */  lw        $s0, 0xc($s1)
/* 609148 80218698 8E050000 */  lw        $a1, ($s0)
/* 60914C 8021869C 0C0B1EAF */  jal       get_variable
/* 609150 802186A0 26100004 */   addiu    $s0, $s0, 4
/* 609154 802186A4 0220202D */  daddu     $a0, $s1, $zero
/* 609158 802186A8 8E050000 */  lw        $a1, ($s0)
/* 60915C 802186AC 0C0B1EAF */  jal       get_variable
/* 609160 802186B0 0040802D */   daddu    $s0, $v0, $zero
/* 609164 802186B4 0200202D */  daddu     $a0, $s0, $zero
/* 609168 802186B8 0C00A3C2 */  jal       start_rumble
/* 60916C 802186BC 0040282D */   daddu    $a1, $v0, $zero
/* 609170 802186C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 609174 802186C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 609178 802186C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 60917C 802186CC 24020002 */  addiu     $v0, $zero, 2
/* 609180 802186D0 03E00008 */  jr        $ra
/* 609184 802186D4 27BD0020 */   addiu    $sp, $sp, 0x20
