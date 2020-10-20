.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243780
/* 96C940 80243780 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96C944 80243784 AFB10014 */  sw        $s1, 0x14($sp)
/* 96C948 80243788 0080882D */  daddu     $s1, $a0, $zero
/* 96C94C 8024378C AFBF0018 */  sw        $ra, 0x18($sp)
/* 96C950 80243790 AFB00010 */  sw        $s0, 0x10($sp)
/* 96C954 80243794 8E30000C */  lw        $s0, 0xc($s1)
/* 96C958 80243798 8E050000 */  lw        $a1, ($s0)
/* 96C95C 8024379C 0C0B1EAF */  jal       get_variable
/* 96C960 802437A0 26100004 */   addiu    $s0, $s0, 4
/* 96C964 802437A4 AE22008C */  sw        $v0, 0x8c($s1)
/* 96C968 802437A8 8E050000 */  lw        $a1, ($s0)
/* 96C96C 802437AC 26100004 */  addiu     $s0, $s0, 4
/* 96C970 802437B0 0C0B1EAF */  jal       get_variable
/* 96C974 802437B4 0220202D */   daddu    $a0, $s1, $zero
/* 96C978 802437B8 AE220090 */  sw        $v0, 0x90($s1)
/* 96C97C 802437BC 8E050000 */  lw        $a1, ($s0)
/* 96C980 802437C0 26100004 */  addiu     $s0, $s0, 4
/* 96C984 802437C4 0C0B1EAF */  jal       get_variable
/* 96C988 802437C8 0220202D */   daddu    $a0, $s1, $zero
/* 96C98C 802437CC AE220094 */  sw        $v0, 0x94($s1)
/* 96C990 802437D0 8E050000 */  lw        $a1, ($s0)
/* 96C994 802437D4 26100004 */  addiu     $s0, $s0, 4
/* 96C998 802437D8 0C0B1EAF */  jal       get_variable
/* 96C99C 802437DC 0220202D */   daddu    $a0, $s1, $zero
/* 96C9A0 802437E0 AE220098 */  sw        $v0, 0x98($s1)
/* 96C9A4 802437E4 8E050000 */  lw        $a1, ($s0)
/* 96C9A8 802437E8 26100004 */  addiu     $s0, $s0, 4
/* 96C9AC 802437EC 0C0B1EAF */  jal       get_variable
/* 96C9B0 802437F0 0220202D */   daddu    $a0, $s1, $zero
/* 96C9B4 802437F4 AE22009C */  sw        $v0, 0x9c($s1)
/* 96C9B8 802437F8 8E050000 */  lw        $a1, ($s0)
/* 96C9BC 802437FC 26100004 */  addiu     $s0, $s0, 4
/* 96C9C0 80243800 0C0B1EAF */  jal       get_variable
/* 96C9C4 80243804 0220202D */   daddu    $a0, $s1, $zero
/* 96C9C8 80243808 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 96C9CC 8024380C 8E050000 */  lw        $a1, ($s0)
/* 96C9D0 80243810 26100004 */  addiu     $s0, $s0, 4
/* 96C9D4 80243814 0C0B1EAF */  jal       get_variable
/* 96C9D8 80243818 0220202D */   daddu    $a0, $s1, $zero
/* 96C9DC 8024381C AE2200A4 */  sw        $v0, 0xa4($s1)
/* 96C9E0 80243820 8E050000 */  lw        $a1, ($s0)
/* 96C9E4 80243824 26100004 */  addiu     $s0, $s0, 4
/* 96C9E8 80243828 0C0B1EAF */  jal       get_variable
/* 96C9EC 8024382C 0220202D */   daddu    $a0, $s1, $zero
/* 96C9F0 80243830 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 96C9F4 80243834 8E050000 */  lw        $a1, ($s0)
/* 96C9F8 80243838 26100004 */  addiu     $s0, $s0, 4
/* 96C9FC 8024383C 0C0B1EAF */  jal       get_variable
/* 96CA00 80243840 0220202D */   daddu    $a0, $s1, $zero
/* 96CA04 80243844 AE2200AC */  sw        $v0, 0xac($s1)
/* 96CA08 80243848 8E050000 */  lw        $a1, ($s0)
/* 96CA0C 8024384C 0C0B1EAF */  jal       get_variable
/* 96CA10 80243850 0220202D */   daddu    $a0, $s1, $zero
/* 96CA14 80243854 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 96CA18 80243858 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96CA1C 8024385C 8FB10014 */  lw        $s1, 0x14($sp)
/* 96CA20 80243860 8FB00010 */  lw        $s0, 0x10($sp)
/* 96CA24 80243864 24020002 */  addiu     $v0, $zero, 2
/* 96CA28 80243868 03E00008 */  jr        $ra
/* 96CA2C 8024386C 27BD0020 */   addiu    $sp, $sp, 0x20
