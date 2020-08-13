.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ActorExists
/* 19C73C 8026DE5C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19C740 8026DE60 AFB20018 */  sw    $s2, 0x18($sp)
/* 19C744 8026DE64 0080902D */  daddu $s2, $a0, $zero
/* 19C748 8026DE68 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19C74C 8026DE6C AFB3001C */  sw    $s3, 0x1c($sp)
/* 19C750 8026DE70 AFB10014 */  sw    $s1, 0x14($sp)
/* 19C754 8026DE74 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C758 8026DE78 8E51000C */  lw    $s1, 0xc($s2)
/* 19C75C 8026DE7C 3C13800E */  lui   $s3, 0x800e
/* 19C760 8026DE80 8E73C14C */  lw    $s3, -0x3eb4($s3)
/* 19C764 8026DE84 8E250000 */  lw    $a1, ($s1)
/* 19C768 8026DE88 0C0B1EAF */  jal   get_variable
/* 19C76C 8026DE8C 26310004 */   addiu $s1, $s1, 4
/* 19C770 8026DE90 0040802D */  daddu $s0, $v0, $zero
/* 19C774 8026DE94 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C778 8026DE98 16020002 */  bne   $s0, $v0, .L8026DEA4
/* 19C77C 8026DE9C 00000000 */   nop   
/* 19C780 8026DEA0 8E500148 */  lw    $s0, 0x148($s2)
.L8026DEA4:
/* 19C784 8026DEA4 0C09A75B */  jal   get_actor
/* 19C788 8026DEA8 0200202D */   daddu $a0, $s0, $zero
/* 19C78C 8026DEAC 0002302B */  sltu  $a2, $zero, $v0
/* 19C790 8026DEB0 24020100 */  addiu $v0, $zero, 0x100
/* 19C794 8026DEB4 16020003 */  bne   $s0, $v0, .L8026DEC4
/* 19C798 8026DEB8 00000000 */   nop   
/* 19C79C 8026DEBC 52600001 */  beql  $s3, $zero, .L8026DEC4
/* 19C7A0 8026DEC0 0000302D */   daddu $a2, $zero, $zero
.L8026DEC4:
/* 19C7A4 8026DEC4 8E250000 */  lw    $a1, ($s1)
/* 19C7A8 8026DEC8 0C0B2026 */  jal   set_variable
/* 19C7AC 8026DECC 0240202D */   daddu $a0, $s2, $zero
/* 19C7B0 8026DED0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19C7B4 8026DED4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19C7B8 8026DED8 8FB20018 */  lw    $s2, 0x18($sp)
/* 19C7BC 8026DEDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 19C7C0 8026DEE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C7C4 8026DEE4 24020002 */  addiu $v0, $zero, 2
/* 19C7C8 8026DEE8 03E00008 */  jr    $ra
/* 19C7CC 8026DEEC 27BD0028 */   addiu $sp, $sp, 0x28

/* 19C7D0 8026DEF0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19C7D4 8026DEF4 AFB20018 */  sw    $s2, 0x18($sp)
/* 19C7D8 8026DEF8 0080902D */  daddu $s2, $a0, $zero
/* 19C7DC 8026DEFC AFBF0020 */  sw    $ra, 0x20($sp)
/* 19C7E0 8026DF00 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19C7E4 8026DF04 AFB10014 */  sw    $s1, 0x14($sp)
/* 19C7E8 8026DF08 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C7EC 8026DF0C 8E50000C */  lw    $s0, 0xc($s2)
/* 19C7F0 8026DF10 8E050000 */  lw    $a1, ($s0)
/* 19C7F4 8026DF14 0C0B1EAF */  jal   get_variable
/* 19C7F8 8026DF18 26100004 */   addiu $s0, $s0, 4
/* 19C7FC 8026DF1C 0040882D */  daddu $s1, $v0, $zero
/* 19C800 8026DF20 8E050000 */  lw    $a1, ($s0)
/* 19C804 8026DF24 26100004 */  addiu $s0, $s0, 4
/* 19C808 8026DF28 0C0B1EAF */  jal   get_variable
/* 19C80C 8026DF2C 0240202D */   daddu $a0, $s2, $zero
/* 19C810 8026DF30 0040982D */  daddu $s3, $v0, $zero
/* 19C814 8026DF34 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C818 8026DF38 16220002 */  bne   $s1, $v0, .L8026DF44
/* 19C81C 8026DF3C 8E100000 */   lw    $s0, ($s0)
/* 19C820 8026DF40 8E510148 */  lw    $s1, 0x148($s2)
.L8026DF44:
/* 19C824 8026DF44 0C09A75B */  jal   get_actor
/* 19C828 8026DF48 0220202D */   daddu $a0, $s1, $zero
/* 19C82C 8026DF4C 0040202D */  daddu $a0, $v0, $zero
/* 19C830 8026DF50 0C099117 */  jal   get_actor_part
/* 19C834 8026DF54 0260282D */   daddu $a1, $s3, $zero
/* 19C838 8026DF58 0240202D */  daddu $a0, $s2, $zero
/* 19C83C 8026DF5C 8C460084 */  lw    $a2, 0x84($v0)
/* 19C840 8026DF60 0C0B2026 */  jal   set_variable
/* 19C844 8026DF64 0200282D */   daddu $a1, $s0, $zero
/* 19C848 8026DF68 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19C84C 8026DF6C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19C850 8026DF70 8FB20018 */  lw    $s2, 0x18($sp)
/* 19C854 8026DF74 8FB10014 */  lw    $s1, 0x14($sp)
/* 19C858 8026DF78 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C85C 8026DF7C 24020002 */  addiu $v0, $zero, 2
/* 19C860 8026DF80 03E00008 */  jr    $ra
/* 19C864 8026DF84 27BD0028 */   addiu $sp, $sp, 0x28

/* 19C868 8026DF88 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19C86C 8026DF8C AFB20018 */  sw    $s2, 0x18($sp)
/* 19C870 8026DF90 0080902D */  daddu $s2, $a0, $zero
/* 19C874 8026DF94 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19C878 8026DF98 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19C87C 8026DF9C AFB10014 */  sw    $s1, 0x14($sp)
/* 19C880 8026DFA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C884 8026DFA4 8E50000C */  lw    $s0, 0xc($s2)
/* 19C888 8026DFA8 8E050000 */  lw    $a1, ($s0)
/* 19C88C 8026DFAC 0C0B1EAF */  jal   get_variable
/* 19C890 8026DFB0 26100004 */   addiu $s0, $s0, 4
/* 19C894 8026DFB4 0040882D */  daddu $s1, $v0, $zero
/* 19C898 8026DFB8 8E050000 */  lw    $a1, ($s0)
/* 19C89C 8026DFBC 26100004 */  addiu $s0, $s0, 4
/* 19C8A0 8026DFC0 0C0B1EAF */  jal   get_variable
/* 19C8A4 8026DFC4 0240202D */   daddu $a0, $s2, $zero
/* 19C8A8 8026DFC8 0040982D */  daddu $s3, $v0, $zero
/* 19C8AC 8026DFCC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C8B0 8026DFD0 16220002 */  bne   $s1, $v0, .L8026DFDC
/* 19C8B4 8026DFD4 8E100000 */   lw    $s0, ($s0)
/* 19C8B8 8026DFD8 8E510148 */  lw    $s1, 0x148($s2)
.L8026DFDC:
/* 19C8BC 8026DFDC 0C09A75B */  jal   get_actor
/* 19C8C0 8026DFE0 0220202D */   daddu $a0, $s1, $zero
/* 19C8C4 8026DFE4 0040202D */  daddu $a0, $v0, $zero
/* 19C8C8 8026DFE8 0C099117 */  jal   get_actor_part
/* 19C8CC 8026DFEC 0260282D */   daddu $a1, $s3, $zero
/* 19C8D0 8026DFF0 0240202D */  daddu $a0, $s2, $zero
/* 19C8D4 8026DFF4 8C46008C */  lw    $a2, 0x8c($v0)
/* 19C8D8 8026DFF8 0C0B2026 */  jal   set_variable
/* 19C8DC 8026DFFC 0200282D */   daddu $a1, $s0, $zero
/* 19C8E0 8026E000 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19C8E4 8026E004 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19C8E8 8026E008 8FB20018 */  lw    $s2, 0x18($sp)
/* 19C8EC 8026E00C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19C8F0 8026E010 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C8F4 8026E014 24020002 */  addiu $v0, $zero, 2
/* 19C8F8 8026E018 03E00008 */  jr    $ra
/* 19C8FC 8026E01C 27BD0028 */   addiu $sp, $sp, 0x28

/* 19C900 8026E020 8C82000C */  lw    $v0, 0xc($a0)
/* 19C904 8026E024 8C420000 */  lw    $v0, ($v0)
/* 19C908 8026E028 3C01800E */  lui   $at, 0x800e
/* 19C90C 8026E02C A422C0E0 */  sh    $v0, -0x3f20($at)
/* 19C910 8026E030 03E00008 */  jr    $ra
/* 19C914 8026E034 24020002 */   addiu $v0, $zero, 2

/* 19C918 8026E038 8C82000C */  lw    $v0, 0xc($a0)
/* 19C91C 8026E03C 8C420000 */  lw    $v0, ($v0)
/* 19C920 8026E040 3C01800E */  lui   $at, 0x800e
/* 19C924 8026E044 AC22C0E4 */  sw    $v0, -0x3f1c($at)
/* 19C928 8026E048 03E00008 */  jr    $ra
/* 19C92C 8026E04C 24020002 */   addiu $v0, $zero, 2

