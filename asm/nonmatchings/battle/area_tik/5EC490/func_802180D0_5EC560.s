.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180D0_5EC560
/* 5EC560 802180D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5EC564 802180D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 5EC568 802180D8 0080882D */  daddu     $s1, $a0, $zero
/* 5EC56C 802180DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 5EC570 802180E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 5EC574 802180E4 8E30000C */  lw        $s0, 0xc($s1)
/* 5EC578 802180E8 8E050000 */  lw        $a1, ($s0)
/* 5EC57C 802180EC 0C0B1EAF */  jal       get_variable
/* 5EC580 802180F0 26100004 */   addiu    $s0, $s0, 4
/* 5EC584 802180F4 0220202D */  daddu     $a0, $s1, $zero
/* 5EC588 802180F8 8E050000 */  lw        $a1, ($s0)
/* 5EC58C 802180FC 0C0B1EAF */  jal       get_variable
/* 5EC590 80218100 0040802D */   daddu    $s0, $v0, $zero
/* 5EC594 80218104 0200202D */  daddu     $a0, $s0, $zero
/* 5EC598 80218108 0C00A3C2 */  jal       start_rumble
/* 5EC59C 8021810C 0040282D */   daddu    $a1, $v0, $zero
/* 5EC5A0 80218110 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5EC5A4 80218114 8FB10014 */  lw        $s1, 0x14($sp)
/* 5EC5A8 80218118 8FB00010 */  lw        $s0, 0x10($sp)
/* 5EC5AC 8021811C 24020002 */  addiu     $v0, $zero, 2
/* 5EC5B0 80218120 03E00008 */  jr        $ra
/* 5EC5B4 80218124 27BD0020 */   addiu    $sp, $sp, 0x20
