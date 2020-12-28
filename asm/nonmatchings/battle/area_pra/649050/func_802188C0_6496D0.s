.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188C0_6496D0
/* 6496D0 802188C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6496D4 802188C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 6496D8 802188C8 0080882D */  daddu     $s1, $a0, $zero
/* 6496DC 802188CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 6496E0 802188D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6496E4 802188D4 8E30000C */  lw        $s0, 0xc($s1)
/* 6496E8 802188D8 8E050000 */  lw        $a1, ($s0)
/* 6496EC 802188DC 0C0B1EAF */  jal       get_variable
/* 6496F0 802188E0 26100004 */   addiu    $s0, $s0, 4
/* 6496F4 802188E4 0220202D */  daddu     $a0, $s1, $zero
/* 6496F8 802188E8 8E050000 */  lw        $a1, ($s0)
/* 6496FC 802188EC 0C0B1EAF */  jal       get_variable
/* 649700 802188F0 0040802D */   daddu    $s0, $v0, $zero
/* 649704 802188F4 0200202D */  daddu     $a0, $s0, $zero
/* 649708 802188F8 0C00A3C2 */  jal       start_rumble
/* 64970C 802188FC 0040282D */   daddu    $a1, $v0, $zero
/* 649710 80218900 8FBF0018 */  lw        $ra, 0x18($sp)
/* 649714 80218904 8FB10014 */  lw        $s1, 0x14($sp)
/* 649718 80218908 8FB00010 */  lw        $s0, 0x10($sp)
/* 64971C 8021890C 24020002 */  addiu     $v0, $zero, 2
/* 649720 80218910 03E00008 */  jr        $ra
/* 649724 80218914 27BD0020 */   addiu    $sp, $sp, 0x20
