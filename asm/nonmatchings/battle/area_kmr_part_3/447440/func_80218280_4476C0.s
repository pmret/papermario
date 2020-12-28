.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218280_4476C0
/* 4476C0 80218280 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4476C4 80218284 AFB10014 */  sw        $s1, 0x14($sp)
/* 4476C8 80218288 0080882D */  daddu     $s1, $a0, $zero
/* 4476CC 8021828C AFBF0018 */  sw        $ra, 0x18($sp)
/* 4476D0 80218290 AFB00010 */  sw        $s0, 0x10($sp)
/* 4476D4 80218294 8E30000C */  lw        $s0, 0xc($s1)
/* 4476D8 80218298 8E050000 */  lw        $a1, ($s0)
/* 4476DC 8021829C 0C0B1EAF */  jal       get_variable
/* 4476E0 802182A0 26100004 */   addiu    $s0, $s0, 4
/* 4476E4 802182A4 0220202D */  daddu     $a0, $s1, $zero
/* 4476E8 802182A8 8E050000 */  lw        $a1, ($s0)
/* 4476EC 802182AC 0C0B1EAF */  jal       get_variable
/* 4476F0 802182B0 0040802D */   daddu    $s0, $v0, $zero
/* 4476F4 802182B4 0200202D */  daddu     $a0, $s0, $zero
/* 4476F8 802182B8 0C00A3C2 */  jal       start_rumble
/* 4476FC 802182BC 0040282D */   daddu    $a1, $v0, $zero
/* 447700 802182C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 447704 802182C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 447708 802182C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 44770C 802182CC 24020002 */  addiu     $v0, $zero, 2
/* 447710 802182D0 03E00008 */  jr        $ra
/* 447714 802182D4 27BD0020 */   addiu    $sp, $sp, 0x20
