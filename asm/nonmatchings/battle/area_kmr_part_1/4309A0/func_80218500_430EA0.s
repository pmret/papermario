.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218500_430EA0
/* 430EA0 80218500 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 430EA4 80218504 AFB10014 */  sw        $s1, 0x14($sp)
/* 430EA8 80218508 0080882D */  daddu     $s1, $a0, $zero
/* 430EAC 8021850C AFBF0018 */  sw        $ra, 0x18($sp)
/* 430EB0 80218510 AFB00010 */  sw        $s0, 0x10($sp)
/* 430EB4 80218514 8E30000C */  lw        $s0, 0xc($s1)
/* 430EB8 80218518 8E050000 */  lw        $a1, ($s0)
/* 430EBC 8021851C 0C0B1EAF */  jal       get_variable
/* 430EC0 80218520 26100004 */   addiu    $s0, $s0, 4
/* 430EC4 80218524 0220202D */  daddu     $a0, $s1, $zero
/* 430EC8 80218528 8E050000 */  lw        $a1, ($s0)
/* 430ECC 8021852C 0C0B1EAF */  jal       get_variable
/* 430ED0 80218530 0040802D */   daddu    $s0, $v0, $zero
/* 430ED4 80218534 0200202D */  daddu     $a0, $s0, $zero
/* 430ED8 80218538 0C00A3C2 */  jal       start_rumble
/* 430EDC 8021853C 0040282D */   daddu    $a1, $v0, $zero
/* 430EE0 80218540 8FBF0018 */  lw        $ra, 0x18($sp)
/* 430EE4 80218544 8FB10014 */  lw        $s1, 0x14($sp)
/* 430EE8 80218548 8FB00010 */  lw        $s0, 0x10($sp)
/* 430EEC 8021854C 24020002 */  addiu     $v0, $zero, 2
/* 430EF0 80218550 03E00008 */  jr        $ra
/* 430EF4 80218554 27BD0020 */   addiu    $sp, $sp, 0x20
