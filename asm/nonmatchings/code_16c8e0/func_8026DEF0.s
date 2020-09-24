.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026DEF0
/* 19C7D0 8026DEF0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19C7D4 8026DEF4 AFB20018 */  sw        $s2, 0x18($sp)
/* 19C7D8 8026DEF8 0080902D */  daddu     $s2, $a0, $zero
/* 19C7DC 8026DEFC AFBF0020 */  sw        $ra, 0x20($sp)
/* 19C7E0 8026DF00 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19C7E4 8026DF04 AFB10014 */  sw        $s1, 0x14($sp)
/* 19C7E8 8026DF08 AFB00010 */  sw        $s0, 0x10($sp)
/* 19C7EC 8026DF0C 8E50000C */  lw        $s0, 0xc($s2)
/* 19C7F0 8026DF10 8E050000 */  lw        $a1, ($s0)
/* 19C7F4 8026DF14 0C0B1EAF */  jal       get_variable
/* 19C7F8 8026DF18 26100004 */   addiu    $s0, $s0, 4
/* 19C7FC 8026DF1C 0040882D */  daddu     $s1, $v0, $zero
/* 19C800 8026DF20 8E050000 */  lw        $a1, ($s0)
/* 19C804 8026DF24 26100004 */  addiu     $s0, $s0, 4
/* 19C808 8026DF28 0C0B1EAF */  jal       get_variable
/* 19C80C 8026DF2C 0240202D */   daddu    $a0, $s2, $zero
/* 19C810 8026DF30 0040982D */  daddu     $s3, $v0, $zero
/* 19C814 8026DF34 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19C818 8026DF38 16220002 */  bne       $s1, $v0, .L8026DF44
/* 19C81C 8026DF3C 8E100000 */   lw       $s0, ($s0)
/* 19C820 8026DF40 8E510148 */  lw        $s1, 0x148($s2)
.L8026DF44:
/* 19C824 8026DF44 0C09A75B */  jal       get_actor
/* 19C828 8026DF48 0220202D */   daddu    $a0, $s1, $zero
/* 19C82C 8026DF4C 0040202D */  daddu     $a0, $v0, $zero
/* 19C830 8026DF50 0C099117 */  jal       get_actor_part
/* 19C834 8026DF54 0260282D */   daddu    $a1, $s3, $zero
/* 19C838 8026DF58 0240202D */  daddu     $a0, $s2, $zero
/* 19C83C 8026DF5C 8C460084 */  lw        $a2, 0x84($v0)
/* 19C840 8026DF60 0C0B2026 */  jal       set_variable
/* 19C844 8026DF64 0200282D */   daddu    $a1, $s0, $zero
/* 19C848 8026DF68 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19C84C 8026DF6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19C850 8026DF70 8FB20018 */  lw        $s2, 0x18($sp)
/* 19C854 8026DF74 8FB10014 */  lw        $s1, 0x14($sp)
/* 19C858 8026DF78 8FB00010 */  lw        $s0, 0x10($sp)
/* 19C85C 8026DF7C 24020002 */  addiu     $v0, $zero, 2
/* 19C860 8026DF80 03E00008 */  jr        $ra
/* 19C864 8026DF84 27BD0028 */   addiu    $sp, $sp, 0x28
