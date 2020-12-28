.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A60_63DC40
/* 63DC40 80218A60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 63DC44 80218A64 AFB10014 */  sw        $s1, 0x14($sp)
/* 63DC48 80218A68 0080882D */  daddu     $s1, $a0, $zero
/* 63DC4C 80218A6C AFBF0018 */  sw        $ra, 0x18($sp)
/* 63DC50 80218A70 AFB00010 */  sw        $s0, 0x10($sp)
/* 63DC54 80218A74 8E30000C */  lw        $s0, 0xc($s1)
/* 63DC58 80218A78 8E050000 */  lw        $a1, ($s0)
/* 63DC5C 80218A7C 0C0B1EAF */  jal       get_variable
/* 63DC60 80218A80 26100004 */   addiu    $s0, $s0, 4
/* 63DC64 80218A84 0220202D */  daddu     $a0, $s1, $zero
/* 63DC68 80218A88 8E050000 */  lw        $a1, ($s0)
/* 63DC6C 80218A8C 0C0B1EAF */  jal       get_variable
/* 63DC70 80218A90 0040802D */   daddu    $s0, $v0, $zero
/* 63DC74 80218A94 0200202D */  daddu     $a0, $s0, $zero
/* 63DC78 80218A98 0C00A3C2 */  jal       start_rumble
/* 63DC7C 80218A9C 0040282D */   daddu    $a1, $v0, $zero
/* 63DC80 80218AA0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 63DC84 80218AA4 8FB10014 */  lw        $s1, 0x14($sp)
/* 63DC88 80218AA8 8FB00010 */  lw        $s0, 0x10($sp)
/* 63DC8C 80218AAC 24020002 */  addiu     $v0, $zero, 2
/* 63DC90 80218AB0 03E00008 */  jr        $ra
/* 63DC94 80218AB4 27BD0020 */   addiu    $sp, $sp, 0x20
