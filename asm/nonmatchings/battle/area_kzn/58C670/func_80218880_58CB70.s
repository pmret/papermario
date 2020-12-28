.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218880_58CB70
/* 58CB70 80218880 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 58CB74 80218884 AFB10014 */  sw        $s1, 0x14($sp)
/* 58CB78 80218888 0080882D */  daddu     $s1, $a0, $zero
/* 58CB7C 8021888C AFBF0018 */  sw        $ra, 0x18($sp)
/* 58CB80 80218890 AFB00010 */  sw        $s0, 0x10($sp)
/* 58CB84 80218894 8E30000C */  lw        $s0, 0xc($s1)
/* 58CB88 80218898 8E050000 */  lw        $a1, ($s0)
/* 58CB8C 8021889C 0C0B1EAF */  jal       get_variable
/* 58CB90 802188A0 26100004 */   addiu    $s0, $s0, 4
/* 58CB94 802188A4 0220202D */  daddu     $a0, $s1, $zero
/* 58CB98 802188A8 8E050000 */  lw        $a1, ($s0)
/* 58CB9C 802188AC 0C0B1EAF */  jal       get_variable
/* 58CBA0 802188B0 0040802D */   daddu    $s0, $v0, $zero
/* 58CBA4 802188B4 0200202D */  daddu     $a0, $s0, $zero
/* 58CBA8 802188B8 0C00A3C2 */  jal       start_rumble
/* 58CBAC 802188BC 0040282D */   daddu    $a1, $v0, $zero
/* 58CBB0 802188C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 58CBB4 802188C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 58CBB8 802188C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 58CBBC 802188CC 24020002 */  addiu     $v0, $zero, 2
/* 58CBC0 802188D0 03E00008 */  jr        $ra
/* 58CBC4 802188D4 27BD0020 */   addiu    $sp, $sp, 0x20
