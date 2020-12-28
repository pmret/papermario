.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180F0_4A1190
/* 4A1190 802180F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A1194 802180F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4A1198 802180F8 0080882D */  daddu     $s1, $a0, $zero
/* 4A119C 802180FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 4A11A0 80218100 AFB00010 */  sw        $s0, 0x10($sp)
/* 4A11A4 80218104 8E30000C */  lw        $s0, 0xc($s1)
/* 4A11A8 80218108 8E050000 */  lw        $a1, ($s0)
/* 4A11AC 8021810C 0C0B1EAF */  jal       get_variable
/* 4A11B0 80218110 26100004 */   addiu    $s0, $s0, 4
/* 4A11B4 80218114 0220202D */  daddu     $a0, $s1, $zero
/* 4A11B8 80218118 8E050000 */  lw        $a1, ($s0)
/* 4A11BC 8021811C 0C0B1EAF */  jal       get_variable
/* 4A11C0 80218120 0040802D */   daddu    $s0, $v0, $zero
/* 4A11C4 80218124 0200202D */  daddu     $a0, $s0, $zero
/* 4A11C8 80218128 0C00A3C2 */  jal       start_rumble
/* 4A11CC 8021812C 0040282D */   daddu    $a1, $v0, $zero
/* 4A11D0 80218130 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4A11D4 80218134 8FB10014 */  lw        $s1, 0x14($sp)
/* 4A11D8 80218138 8FB00010 */  lw        $s0, 0x10($sp)
/* 4A11DC 8021813C 24020002 */  addiu     $v0, $zero, 2
/* 4A11E0 80218140 03E00008 */  jr        $ra
/* 4A11E4 80218144 27BD0020 */   addiu    $sp, $sp, 0x20
