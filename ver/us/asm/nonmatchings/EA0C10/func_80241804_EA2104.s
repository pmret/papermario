.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241804_EA2104
/* EA2104 80241804 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA2108 80241808 AFB10014 */  sw        $s1, 0x14($sp)
/* EA210C 8024180C 0080882D */  daddu     $s1, $a0, $zero
/* EA2110 80241810 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA2114 80241814 AFB00010 */  sw        $s0, 0x10($sp)
/* EA2118 80241818 8E300148 */  lw        $s0, 0x148($s1)
/* EA211C 8024181C 0C00F92F */  jal       dead_get_npc_unsafe
/* EA2120 80241820 86040008 */   lh       $a0, 8($s0)
/* EA2124 80241824 0040202D */  daddu     $a0, $v0, $zero
/* EA2128 80241828 9482008E */  lhu       $v0, 0x8e($a0)
/* EA212C 8024182C 2442FFFF */  addiu     $v0, $v0, -1
/* EA2130 80241830 A482008E */  sh        $v0, 0x8e($a0)
/* EA2134 80241834 00021400 */  sll       $v0, $v0, 0x10
/* EA2138 80241838 8E030098 */  lw        $v1, 0x98($s0)
/* EA213C 8024183C 00021403 */  sra       $v0, $v0, 0x10
/* EA2140 80241840 0062182A */  slt       $v1, $v1, $v0
/* EA2144 80241844 14600005 */  bnez      $v1, .L8024185C
/* EA2148 80241848 3C03E0EF */   lui      $v1, 0xe0ef
/* EA214C 8024184C 8E020000 */  lw        $v0, ($s0)
/* EA2150 80241850 3463FFFF */  ori       $v1, $v1, 0xffff
/* EA2154 80241854 00431024 */  and       $v0, $v0, $v1
/* EA2158 80241858 AE020000 */  sw        $v0, ($s0)
.L8024185C:
/* EA215C 8024185C 8482008E */  lh        $v0, 0x8e($a0)
/* EA2160 80241860 14400007 */  bnez      $v0, .L80241880
/* EA2164 80241864 00000000 */   nop
/* EA2168 80241868 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA216C 8024186C 8C420028 */  lw        $v0, 0x28($v0)
/* EA2170 80241870 A480008E */  sh        $zero, 0x8e($a0)
/* EA2174 80241874 AC820028 */  sw        $v0, 0x28($a0)
/* EA2178 80241878 2402000C */  addiu     $v0, $zero, 0xc
/* EA217C 8024187C AE220070 */  sw        $v0, 0x70($s1)
.L80241880:
/* EA2180 80241880 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA2184 80241884 8FB10014 */  lw        $s1, 0x14($sp)
/* EA2188 80241888 8FB00010 */  lw        $s0, 0x10($sp)
/* EA218C 8024188C 03E00008 */  jr        $ra
/* EA2190 80241890 27BD0020 */   addiu    $sp, $sp, 0x20
