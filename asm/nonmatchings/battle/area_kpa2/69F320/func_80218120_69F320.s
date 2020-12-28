.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218120_69F320
/* 69F320 80218120 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 69F324 80218124 AFB10014 */  sw        $s1, 0x14($sp)
/* 69F328 80218128 0080882D */  daddu     $s1, $a0, $zero
/* 69F32C 8021812C AFBF0018 */  sw        $ra, 0x18($sp)
/* 69F330 80218130 AFB00010 */  sw        $s0, 0x10($sp)
/* 69F334 80218134 8E30000C */  lw        $s0, 0xc($s1)
/* 69F338 80218138 8E050000 */  lw        $a1, ($s0)
/* 69F33C 8021813C 0C0B1EAF */  jal       get_variable
/* 69F340 80218140 26100004 */   addiu    $s0, $s0, 4
/* 69F344 80218144 0220202D */  daddu     $a0, $s1, $zero
/* 69F348 80218148 8E050000 */  lw        $a1, ($s0)
/* 69F34C 8021814C 0C0B1EAF */  jal       get_variable
/* 69F350 80218150 0040802D */   daddu    $s0, $v0, $zero
/* 69F354 80218154 0200202D */  daddu     $a0, $s0, $zero
/* 69F358 80218158 0C00A3C2 */  jal       start_rumble
/* 69F35C 8021815C 0040282D */   daddu    $a1, $v0, $zero
/* 69F360 80218160 8FBF0018 */  lw        $ra, 0x18($sp)
/* 69F364 80218164 8FB10014 */  lw        $s1, 0x14($sp)
/* 69F368 80218168 8FB00010 */  lw        $s0, 0x10($sp)
/* 69F36C 8021816C 24020002 */  addiu     $v0, $zero, 2
/* 69F370 80218170 03E00008 */  jr        $ra
/* 69F374 80218174 27BD0020 */   addiu    $sp, $sp, 0x20
