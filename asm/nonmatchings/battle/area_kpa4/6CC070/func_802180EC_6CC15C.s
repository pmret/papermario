.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180EC_6CC15C
/* 6CC15C 802180EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6CC160 802180F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC164 802180F4 0080882D */  daddu     $s1, $a0, $zero
/* 6CC168 802180F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6CC16C 802180FC AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC170 80218100 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC174 80218104 8E050000 */  lw        $a1, ($s0)
/* 6CC178 80218108 0C0B1EAF */  jal       get_variable
/* 6CC17C 8021810C 26100004 */   addiu    $s0, $s0, 4
/* 6CC180 80218110 0220202D */  daddu     $a0, $s1, $zero
/* 6CC184 80218114 8E050000 */  lw        $a1, ($s0)
/* 6CC188 80218118 0C0B1EAF */  jal       get_variable
/* 6CC18C 8021811C 0040802D */   daddu    $s0, $v0, $zero
/* 6CC190 80218120 0200202D */  daddu     $a0, $s0, $zero
/* 6CC194 80218124 0C00A3C2 */  jal       start_rumble
/* 6CC198 80218128 0040282D */   daddu    $a1, $v0, $zero
/* 6CC19C 8021812C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6CC1A0 80218130 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC1A4 80218134 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC1A8 80218138 24020002 */  addiu     $v0, $zero, 2
/* 6CC1AC 8021813C 03E00008 */  jr        $ra
/* 6CC1B0 80218140 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6CC1B4 80218144 00000000 */  nop       
/* 6CC1B8 80218148 00000000 */  nop       
/* 6CC1BC 8021814C 00000000 */  nop       
