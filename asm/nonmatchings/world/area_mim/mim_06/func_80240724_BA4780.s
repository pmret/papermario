.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240724_BA4EA4
/* BA4EA4 80240724 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA4EA8 80240728 AFB10014 */  sw        $s1, 0x14($sp)
/* BA4EAC 8024072C 0080882D */  daddu     $s1, $a0, $zero
/* BA4EB0 80240730 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA4EB4 80240734 AFB00010 */  sw        $s0, 0x10($sp)
/* BA4EB8 80240738 8E300148 */  lw        $s0, 0x148($s1)
/* BA4EBC 8024073C 0C00EABB */  jal       get_npc_unsafe
/* BA4EC0 80240740 86040008 */   lh       $a0, 8($s0)
/* BA4EC4 80240744 9443008E */  lhu       $v1, 0x8e($v0)
/* BA4EC8 80240748 2463FFFF */  addiu     $v1, $v1, -1
/* BA4ECC 8024074C A443008E */  sh        $v1, 0x8e($v0)
/* BA4ED0 80240750 00031C00 */  sll       $v1, $v1, 0x10
/* BA4ED4 80240754 1C600003 */  bgtz      $v1, .L80240764
/* BA4ED8 80240758 2402000C */   addiu    $v0, $zero, 0xc
/* BA4EDC 8024075C AE00006C */  sw        $zero, 0x6c($s0)
/* BA4EE0 80240760 AE220070 */  sw        $v0, 0x70($s1)
.L80240764:
/* BA4EE4 80240764 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA4EE8 80240768 8FB10014 */  lw        $s1, 0x14($sp)
/* BA4EEC 8024076C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA4EF0 80240770 03E00008 */  jr        $ra
/* BA4EF4 80240774 27BD0020 */   addiu    $sp, $sp, 0x20
