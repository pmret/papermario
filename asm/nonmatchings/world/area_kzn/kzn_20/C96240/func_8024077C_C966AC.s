.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024077C_C966AC
/* C966AC 8024077C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C966B0 80240780 AFB10014 */  sw        $s1, 0x14($sp)
/* C966B4 80240784 0080882D */  daddu     $s1, $a0, $zero
/* C966B8 80240788 AFBF0018 */  sw        $ra, 0x18($sp)
/* C966BC 8024078C AFB00010 */  sw        $s0, 0x10($sp)
/* C966C0 80240790 8E30000C */  lw        $s0, 0xc($s1)
/* C966C4 80240794 8E050000 */  lw        $a1, ($s0)
/* C966C8 80240798 0C0B1EAF */  jal       get_variable
/* C966CC 8024079C 26100004 */   addiu    $s0, $s0, 4
/* C966D0 802407A0 AE22008C */  sw        $v0, 0x8c($s1)
/* C966D4 802407A4 8E050000 */  lw        $a1, ($s0)
/* C966D8 802407A8 26100004 */  addiu     $s0, $s0, 4
/* C966DC 802407AC 0C0B1EAF */  jal       get_variable
/* C966E0 802407B0 0220202D */   daddu    $a0, $s1, $zero
/* C966E4 802407B4 AE220090 */  sw        $v0, 0x90($s1)
/* C966E8 802407B8 8E050000 */  lw        $a1, ($s0)
/* C966EC 802407BC 26100004 */  addiu     $s0, $s0, 4
/* C966F0 802407C0 0C0B1EAF */  jal       get_variable
/* C966F4 802407C4 0220202D */   daddu    $a0, $s1, $zero
/* C966F8 802407C8 AE220094 */  sw        $v0, 0x94($s1)
/* C966FC 802407CC 8E050000 */  lw        $a1, ($s0)
/* C96700 802407D0 26100004 */  addiu     $s0, $s0, 4
/* C96704 802407D4 0C0B1EAF */  jal       get_variable
/* C96708 802407D8 0220202D */   daddu    $a0, $s1, $zero
/* C9670C 802407DC AE220098 */  sw        $v0, 0x98($s1)
/* C96710 802407E0 8E050000 */  lw        $a1, ($s0)
/* C96714 802407E4 26100004 */  addiu     $s0, $s0, 4
/* C96718 802407E8 0C0B1EAF */  jal       get_variable
/* C9671C 802407EC 0220202D */   daddu    $a0, $s1, $zero
/* C96720 802407F0 AE22009C */  sw        $v0, 0x9c($s1)
/* C96724 802407F4 8E050000 */  lw        $a1, ($s0)
/* C96728 802407F8 26100004 */  addiu     $s0, $s0, 4
/* C9672C 802407FC 0C0B1EAF */  jal       get_variable
/* C96730 80240800 0220202D */   daddu    $a0, $s1, $zero
/* C96734 80240804 AE2200A0 */  sw        $v0, 0xa0($s1)
/* C96738 80240808 8E050000 */  lw        $a1, ($s0)
/* C9673C 8024080C 26100004 */  addiu     $s0, $s0, 4
/* C96740 80240810 0C0B1EAF */  jal       get_variable
/* C96744 80240814 0220202D */   daddu    $a0, $s1, $zero
/* C96748 80240818 AE2200A4 */  sw        $v0, 0xa4($s1)
/* C9674C 8024081C 8E050000 */  lw        $a1, ($s0)
/* C96750 80240820 26100004 */  addiu     $s0, $s0, 4
/* C96754 80240824 0C0B1EAF */  jal       get_variable
/* C96758 80240828 0220202D */   daddu    $a0, $s1, $zero
/* C9675C 8024082C AE2200A8 */  sw        $v0, 0xa8($s1)
/* C96760 80240830 8E050000 */  lw        $a1, ($s0)
/* C96764 80240834 26100004 */  addiu     $s0, $s0, 4
/* C96768 80240838 0C0B1EAF */  jal       get_variable
/* C9676C 8024083C 0220202D */   daddu    $a0, $s1, $zero
/* C96770 80240840 AE2200AC */  sw        $v0, 0xac($s1)
/* C96774 80240844 8E050000 */  lw        $a1, ($s0)
/* C96778 80240848 0C0B1EAF */  jal       get_variable
/* C9677C 8024084C 0220202D */   daddu    $a0, $s1, $zero
/* C96780 80240850 AE2200B0 */  sw        $v0, 0xb0($s1)
/* C96784 80240854 8FBF0018 */  lw        $ra, 0x18($sp)
/* C96788 80240858 8FB10014 */  lw        $s1, 0x14($sp)
/* C9678C 8024085C 8FB00010 */  lw        $s0, 0x10($sp)
/* C96790 80240860 24020002 */  addiu     $v0, $zero, 2
/* C96794 80240864 03E00008 */  jr        $ra
/* C96798 80240868 27BD0020 */   addiu    $sp, $sp, 0x20
