.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* D1884C 8024006C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D18850 80240070 AFB10014 */  sw        $s1, 0x14($sp)
/* D18854 80240074 0080882D */  daddu     $s1, $a0, $zero
/* D18858 80240078 AFBF0018 */  sw        $ra, 0x18($sp)
/* D1885C 8024007C AFB00010 */  sw        $s0, 0x10($sp)
/* D18860 80240080 8E300148 */  lw        $s0, 0x148($s1)
/* D18864 80240084 0C00EABB */  jal       get_npc_unsafe
/* D18868 80240088 86040008 */   lh       $a0, 8($s0)
/* D1886C 8024008C 0040202D */  daddu     $a0, $v0, $zero
/* D18870 80240090 9482008E */  lhu       $v0, 0x8e($a0)
/* D18874 80240094 2442FFFF */  addiu     $v0, $v0, -1
/* D18878 80240098 A482008E */  sh        $v0, 0x8e($a0)
/* D1887C 8024009C 00021400 */  sll       $v0, $v0, 0x10
/* D18880 802400A0 1C400009 */  bgtz      $v0, .L802400C8
/* D18884 802400A4 24020003 */   addiu    $v0, $zero, 3
/* D18888 802400A8 96030076 */  lhu       $v1, 0x76($s0)
/* D1888C 802400AC AE02006C */  sw        $v0, 0x6c($s0)
/* D18890 802400B0 A483008E */  sh        $v1, 0x8e($a0)
/* D18894 802400B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* D18898 802400B8 8C420024 */  lw        $v0, 0x24($v0)
/* D1889C 802400BC AC820028 */  sw        $v0, 0x28($a0)
/* D188A0 802400C0 24020020 */  addiu     $v0, $zero, 0x20
/* D188A4 802400C4 AE220070 */  sw        $v0, 0x70($s1)
.L802400C8:
/* D188A8 802400C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D188AC 802400CC 8FB10014 */  lw        $s1, 0x14($sp)
/* D188B0 802400D0 8FB00010 */  lw        $s0, 0x10($sp)
/* D188B4 802400D4 03E00008 */  jr        $ra
/* D188B8 802400D8 27BD0020 */   addiu    $sp, $sp, 0x20
