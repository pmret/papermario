.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C30
/* B37800 80242C30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B37804 80242C34 AFB10014 */  sw        $s1, 0x14($sp)
/* B37808 80242C38 0080882D */  daddu     $s1, $a0, $zero
/* B3780C 80242C3C AFBF0018 */  sw        $ra, 0x18($sp)
/* B37810 80242C40 AFB00010 */  sw        $s0, 0x10($sp)
/* B37814 80242C44 8E30000C */  lw        $s0, 0xc($s1)
/* B37818 80242C48 8E050000 */  lw        $a1, ($s0)
/* B3781C 80242C4C 0C0B1EAF */  jal       get_variable
/* B37820 80242C50 26100004 */   addiu    $s0, $s0, 4
/* B37824 80242C54 AE22008C */  sw        $v0, 0x8c($s1)
/* B37828 80242C58 8E050000 */  lw        $a1, ($s0)
/* B3782C 80242C5C 26100004 */  addiu     $s0, $s0, 4
/* B37830 80242C60 0C0B1EAF */  jal       get_variable
/* B37834 80242C64 0220202D */   daddu    $a0, $s1, $zero
/* B37838 80242C68 AE220090 */  sw        $v0, 0x90($s1)
/* B3783C 80242C6C 8E050000 */  lw        $a1, ($s0)
/* B37840 80242C70 26100004 */  addiu     $s0, $s0, 4
/* B37844 80242C74 0C0B1EAF */  jal       get_variable
/* B37848 80242C78 0220202D */   daddu    $a0, $s1, $zero
/* B3784C 80242C7C AE220094 */  sw        $v0, 0x94($s1)
/* B37850 80242C80 8E050000 */  lw        $a1, ($s0)
/* B37854 80242C84 26100004 */  addiu     $s0, $s0, 4
/* B37858 80242C88 0C0B1EAF */  jal       get_variable
/* B3785C 80242C8C 0220202D */   daddu    $a0, $s1, $zero
/* B37860 80242C90 AE220098 */  sw        $v0, 0x98($s1)
/* B37864 80242C94 8E050000 */  lw        $a1, ($s0)
/* B37868 80242C98 26100004 */  addiu     $s0, $s0, 4
/* B3786C 80242C9C 0C0B1EAF */  jal       get_variable
/* B37870 80242CA0 0220202D */   daddu    $a0, $s1, $zero
/* B37874 80242CA4 AE22009C */  sw        $v0, 0x9c($s1)
/* B37878 80242CA8 8E050000 */  lw        $a1, ($s0)
/* B3787C 80242CAC 26100004 */  addiu     $s0, $s0, 4
/* B37880 80242CB0 0C0B1EAF */  jal       get_variable
/* B37884 80242CB4 0220202D */   daddu    $a0, $s1, $zero
/* B37888 80242CB8 AE2200A0 */  sw        $v0, 0xa0($s1)
/* B3788C 80242CBC 8E050000 */  lw        $a1, ($s0)
/* B37890 80242CC0 26100004 */  addiu     $s0, $s0, 4
/* B37894 80242CC4 0C0B1EAF */  jal       get_variable
/* B37898 80242CC8 0220202D */   daddu    $a0, $s1, $zero
/* B3789C 80242CCC AE2200A4 */  sw        $v0, 0xa4($s1)
/* B378A0 80242CD0 8E050000 */  lw        $a1, ($s0)
/* B378A4 80242CD4 26100004 */  addiu     $s0, $s0, 4
/* B378A8 80242CD8 0C0B1EAF */  jal       get_variable
/* B378AC 80242CDC 0220202D */   daddu    $a0, $s1, $zero
/* B378B0 80242CE0 AE2200A8 */  sw        $v0, 0xa8($s1)
/* B378B4 80242CE4 8E050000 */  lw        $a1, ($s0)
/* B378B8 80242CE8 26100004 */  addiu     $s0, $s0, 4
/* B378BC 80242CEC 0C0B1EAF */  jal       get_variable
/* B378C0 80242CF0 0220202D */   daddu    $a0, $s1, $zero
/* B378C4 80242CF4 AE2200AC */  sw        $v0, 0xac($s1)
/* B378C8 80242CF8 8E050000 */  lw        $a1, ($s0)
/* B378CC 80242CFC 0C0B1EAF */  jal       get_variable
/* B378D0 80242D00 0220202D */   daddu    $a0, $s1, $zero
/* B378D4 80242D04 AE2200B0 */  sw        $v0, 0xb0($s1)
/* B378D8 80242D08 8FBF0018 */  lw        $ra, 0x18($sp)
/* B378DC 80242D0C 8FB10014 */  lw        $s1, 0x14($sp)
/* B378E0 80242D10 8FB00010 */  lw        $s0, 0x10($sp)
/* B378E4 80242D14 24020002 */  addiu     $v0, $zero, 2
/* B378E8 80242D18 03E00008 */  jr        $ra
/* B378EC 80242D1C 27BD0020 */   addiu    $sp, $sp, 0x20
