.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A2C0_6A14C0
/* 6A14C0 8021A2C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A14C4 8021A2C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A14C8 8021A2C8 0080882D */  daddu     $s1, $a0, $zero
/* 6A14CC 8021A2CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 6A14D0 8021A2D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A14D4 8021A2D4 8E30000C */  lw        $s0, 0xc($s1)
/* 6A14D8 8021A2D8 8E050000 */  lw        $a1, ($s0)
/* 6A14DC 8021A2DC 0C0B1EAF */  jal       get_variable
/* 6A14E0 8021A2E0 26100004 */   addiu    $s0, $s0, 4
/* 6A14E4 8021A2E4 0220202D */  daddu     $a0, $s1, $zero
/* 6A14E8 8021A2E8 8E050000 */  lw        $a1, ($s0)
/* 6A14EC 8021A2EC 0C0B1EAF */  jal       get_variable
/* 6A14F0 8021A2F0 0040802D */   daddu    $s0, $v0, $zero
/* 6A14F4 8021A2F4 0200202D */  daddu     $a0, $s0, $zero
/* 6A14F8 8021A2F8 0C00A3C2 */  jal       start_rumble
/* 6A14FC 8021A2FC 0040282D */   daddu    $a1, $v0, $zero
/* 6A1500 8021A300 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6A1504 8021A304 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A1508 8021A308 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A150C 8021A30C 24020002 */  addiu     $v0, $zero, 2
/* 6A1510 8021A310 03E00008 */  jr        $ra
/* 6A1514 8021A314 27BD0020 */   addiu    $sp, $sp, 0x20
