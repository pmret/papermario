.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802184D4_63D6B4
/* 63D6B4 802184D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 63D6B8 802184D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 63D6BC 802184DC 0080882D */  daddu     $s1, $a0, $zero
/* 63D6C0 802184E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 63D6C4 802184E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 63D6C8 802184E8 8E30000C */  lw        $s0, 0xc($s1)
/* 63D6CC 802184EC 8E050000 */  lw        $a1, ($s0)
/* 63D6D0 802184F0 0C0B1EAF */  jal       get_variable
/* 63D6D4 802184F4 26100004 */   addiu    $s0, $s0, 4
/* 63D6D8 802184F8 0220202D */  daddu     $a0, $s1, $zero
/* 63D6DC 802184FC 8E050000 */  lw        $a1, ($s0)
/* 63D6E0 80218500 0C0B1EAF */  jal       get_variable
/* 63D6E4 80218504 0040802D */   daddu    $s0, $v0, $zero
/* 63D6E8 80218508 0200202D */  daddu     $a0, $s0, $zero
/* 63D6EC 8021850C 0C00A3C2 */  jal       start_rumble
/* 63D6F0 80218510 0040282D */   daddu    $a1, $v0, $zero
/* 63D6F4 80218514 8FBF0018 */  lw        $ra, 0x18($sp)
/* 63D6F8 80218518 8FB10014 */  lw        $s1, 0x14($sp)
/* 63D6FC 8021851C 8FB00010 */  lw        $s0, 0x10($sp)
/* 63D700 80218520 24020002 */  addiu     $v0, $zero, 2
/* 63D704 80218524 03E00008 */  jr        $ra
/* 63D708 80218528 27BD0020 */   addiu    $sp, $sp, 0x20
/* 63D70C 8021852C 00000000 */  nop       
