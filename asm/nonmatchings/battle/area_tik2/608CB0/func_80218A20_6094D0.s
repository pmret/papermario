.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A20_6094D0
/* 6094D0 80218A20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6094D4 80218A24 AFB10014 */  sw        $s1, 0x14($sp)
/* 6094D8 80218A28 0080882D */  daddu     $s1, $a0, $zero
/* 6094DC 80218A2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 6094E0 80218A30 AFB00010 */  sw        $s0, 0x10($sp)
/* 6094E4 80218A34 8E30000C */  lw        $s0, 0xc($s1)
/* 6094E8 80218A38 8E050000 */  lw        $a1, ($s0)
/* 6094EC 80218A3C 0C0B1EAF */  jal       get_variable
/* 6094F0 80218A40 26100004 */   addiu    $s0, $s0, 4
/* 6094F4 80218A44 0220202D */  daddu     $a0, $s1, $zero
/* 6094F8 80218A48 8E050000 */  lw        $a1, ($s0)
/* 6094FC 80218A4C 0C0B1EAF */  jal       get_variable
/* 609500 80218A50 0040802D */   daddu    $s0, $v0, $zero
/* 609504 80218A54 0200202D */  daddu     $a0, $s0, $zero
/* 609508 80218A58 0C00A3C2 */  jal       start_rumble
/* 60950C 80218A5C 0040282D */   daddu    $a1, $v0, $zero
/* 609510 80218A60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 609514 80218A64 8FB10014 */  lw        $s1, 0x14($sp)
/* 609518 80218A68 8FB00010 */  lw        $s0, 0x10($sp)
/* 60951C 80218A6C 24020002 */  addiu     $v0, $zero, 2
/* 609520 80218A70 03E00008 */  jr        $ra
/* 609524 80218A74 27BD0020 */   addiu    $sp, $sp, 0x20
