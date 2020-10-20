.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240744
/* A93E84 80240744 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A93E88 80240748 AFB10014 */  sw        $s1, 0x14($sp)
/* A93E8C 8024074C 0080882D */  daddu     $s1, $a0, $zero
/* A93E90 80240750 AFBF0018 */  sw        $ra, 0x18($sp)
/* A93E94 80240754 AFB00010 */  sw        $s0, 0x10($sp)
/* A93E98 80240758 8E300148 */  lw        $s0, 0x148($s1)
/* A93E9C 8024075C 0C00EABB */  jal       get_npc_unsafe
/* A93EA0 80240760 86040008 */   lh       $a0, 8($s0)
/* A93EA4 80240764 96030076 */  lhu       $v1, 0x76($s0)
/* A93EA8 80240768 A443008E */  sh        $v1, 0x8e($v0)
/* A93EAC 8024076C 24020021 */  addiu     $v0, $zero, 0x21
/* A93EB0 80240770 AE220070 */  sw        $v0, 0x70($s1)
/* A93EB4 80240774 8FBF0018 */  lw        $ra, 0x18($sp)
/* A93EB8 80240778 8FB10014 */  lw        $s1, 0x14($sp)
/* A93EBC 8024077C 8FB00010 */  lw        $s0, 0x10($sp)
/* A93EC0 80240780 03E00008 */  jr        $ra
/* A93EC4 80240784 27BD0020 */   addiu    $sp, $sp, 0x20
