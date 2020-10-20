.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407CC_AB07BC
/* AB07BC 802407CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB07C0 802407D0 AFB10014 */  sw        $s1, 0x14($sp)
/* AB07C4 802407D4 0080882D */  daddu     $s1, $a0, $zero
/* AB07C8 802407D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* AB07CC 802407DC AFB00010 */  sw        $s0, 0x10($sp)
/* AB07D0 802407E0 8E30000C */  lw        $s0, 0xc($s1)
/* AB07D4 802407E4 8E050000 */  lw        $a1, ($s0)
/* AB07D8 802407E8 0C0B1EAF */  jal       get_variable
/* AB07DC 802407EC 26100004 */   addiu    $s0, $s0, 4
/* AB07E0 802407F0 AE22008C */  sw        $v0, 0x8c($s1)
/* AB07E4 802407F4 8E050000 */  lw        $a1, ($s0)
/* AB07E8 802407F8 26100004 */  addiu     $s0, $s0, 4
/* AB07EC 802407FC 0C0B1EAF */  jal       get_variable
/* AB07F0 80240800 0220202D */   daddu    $a0, $s1, $zero
/* AB07F4 80240804 AE220090 */  sw        $v0, 0x90($s1)
/* AB07F8 80240808 8E050000 */  lw        $a1, ($s0)
/* AB07FC 8024080C 26100004 */  addiu     $s0, $s0, 4
/* AB0800 80240810 0C0B1EAF */  jal       get_variable
/* AB0804 80240814 0220202D */   daddu    $a0, $s1, $zero
/* AB0808 80240818 AE220094 */  sw        $v0, 0x94($s1)
/* AB080C 8024081C 8E050000 */  lw        $a1, ($s0)
/* AB0810 80240820 26100004 */  addiu     $s0, $s0, 4
/* AB0814 80240824 0C0B1EAF */  jal       get_variable
/* AB0818 80240828 0220202D */   daddu    $a0, $s1, $zero
/* AB081C 8024082C AE220098 */  sw        $v0, 0x98($s1)
/* AB0820 80240830 8E050000 */  lw        $a1, ($s0)
/* AB0824 80240834 26100004 */  addiu     $s0, $s0, 4
/* AB0828 80240838 0C0B1EAF */  jal       get_variable
/* AB082C 8024083C 0220202D */   daddu    $a0, $s1, $zero
/* AB0830 80240840 AE22009C */  sw        $v0, 0x9c($s1)
/* AB0834 80240844 8E050000 */  lw        $a1, ($s0)
/* AB0838 80240848 26100004 */  addiu     $s0, $s0, 4
/* AB083C 8024084C 0C0B1EAF */  jal       get_variable
/* AB0840 80240850 0220202D */   daddu    $a0, $s1, $zero
/* AB0844 80240854 AE2200A0 */  sw        $v0, 0xa0($s1)
/* AB0848 80240858 8E050000 */  lw        $a1, ($s0)
/* AB084C 8024085C 26100004 */  addiu     $s0, $s0, 4
/* AB0850 80240860 0C0B1EAF */  jal       get_variable
/* AB0854 80240864 0220202D */   daddu    $a0, $s1, $zero
/* AB0858 80240868 AE2200A4 */  sw        $v0, 0xa4($s1)
/* AB085C 8024086C 8E050000 */  lw        $a1, ($s0)
/* AB0860 80240870 26100004 */  addiu     $s0, $s0, 4
/* AB0864 80240874 0C0B1EAF */  jal       get_variable
/* AB0868 80240878 0220202D */   daddu    $a0, $s1, $zero
/* AB086C 8024087C AE2200A8 */  sw        $v0, 0xa8($s1)
/* AB0870 80240880 8E050000 */  lw        $a1, ($s0)
/* AB0874 80240884 26100004 */  addiu     $s0, $s0, 4
/* AB0878 80240888 0C0B1EAF */  jal       get_variable
/* AB087C 8024088C 0220202D */   daddu    $a0, $s1, $zero
/* AB0880 80240890 AE2200AC */  sw        $v0, 0xac($s1)
/* AB0884 80240894 8E050000 */  lw        $a1, ($s0)
/* AB0888 80240898 0C0B1EAF */  jal       get_variable
/* AB088C 8024089C 0220202D */   daddu    $a0, $s1, $zero
/* AB0890 802408A0 AE2200B0 */  sw        $v0, 0xb0($s1)
/* AB0894 802408A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB0898 802408A8 8FB10014 */  lw        $s1, 0x14($sp)
/* AB089C 802408AC 8FB00010 */  lw        $s0, 0x10($sp)
/* AB08A0 802408B0 24020002 */  addiu     $v0, $zero, 2
/* AB08A4 802408B4 03E00008 */  jr        $ra
/* AB08A8 802408B8 27BD0020 */   addiu    $sp, $sp, 0x20
