.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240954
/* 910004 80240954 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 910008 80240958 AFB10014 */  sw        $s1, 0x14($sp)
/* 91000C 8024095C 0080882D */  daddu     $s1, $a0, $zero
/* 910010 80240960 AFBF0018 */  sw        $ra, 0x18($sp)
/* 910014 80240964 AFB00010 */  sw        $s0, 0x10($sp)
/* 910018 80240968 8E300148 */  lw        $s0, 0x148($s1)
/* 91001C 8024096C 0C00EABB */  jal       get_npc_unsafe
/* 910020 80240970 86040008 */   lh       $a0, 8($s0)
/* 910024 80240974 96030076 */  lhu       $v1, 0x76($s0)
/* 910028 80240978 A443008E */  sh        $v1, 0x8e($v0)
/* 91002C 8024097C 24020021 */  addiu     $v0, $zero, 0x21
/* 910030 80240980 AE220070 */  sw        $v0, 0x70($s1)
/* 910034 80240984 8FBF0018 */  lw        $ra, 0x18($sp)
/* 910038 80240988 8FB10014 */  lw        $s1, 0x14($sp)
/* 91003C 8024098C 8FB00010 */  lw        $s0, 0x10($sp)
/* 910040 80240990 03E00008 */  jr        $ra
/* 910044 80240994 27BD0020 */   addiu    $sp, $sp, 0x20
