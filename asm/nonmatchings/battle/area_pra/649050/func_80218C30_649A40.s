.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C30_649A40
/* 649A40 80218C30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 649A44 80218C34 AFB10014 */  sw        $s1, 0x14($sp)
/* 649A48 80218C38 0080882D */  daddu     $s1, $a0, $zero
/* 649A4C 80218C3C AFBF0018 */  sw        $ra, 0x18($sp)
/* 649A50 80218C40 AFB00010 */  sw        $s0, 0x10($sp)
/* 649A54 80218C44 8E30000C */  lw        $s0, 0xc($s1)
/* 649A58 80218C48 8E050000 */  lw        $a1, ($s0)
/* 649A5C 80218C4C 0C0B1EAF */  jal       get_variable
/* 649A60 80218C50 26100004 */   addiu    $s0, $s0, 4
/* 649A64 80218C54 0220202D */  daddu     $a0, $s1, $zero
/* 649A68 80218C58 8E050000 */  lw        $a1, ($s0)
/* 649A6C 80218C5C 0C0B1EAF */  jal       get_variable
/* 649A70 80218C60 0040802D */   daddu    $s0, $v0, $zero
/* 649A74 80218C64 0200202D */  daddu     $a0, $s0, $zero
/* 649A78 80218C68 0C00A3C2 */  jal       start_rumble
/* 649A7C 80218C6C 0040282D */   daddu    $a1, $v0, $zero
/* 649A80 80218C70 8FBF0018 */  lw        $ra, 0x18($sp)
/* 649A84 80218C74 8FB10014 */  lw        $s1, 0x14($sp)
/* 649A88 80218C78 8FB00010 */  lw        $s0, 0x10($sp)
/* 649A8C 80218C7C 24020002 */  addiu     $v0, $zero, 2
/* 649A90 80218C80 03E00008 */  jr        $ra
/* 649A94 80218C84 27BD0020 */   addiu    $sp, $sp, 0x20
