.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241054_A650E4
/* A650E4 80241054 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A650E8 80241058 AFB10014 */  sw        $s1, 0x14($sp)
/* A650EC 8024105C 0080882D */  daddu     $s1, $a0, $zero
/* A650F0 80241060 AFBF0018 */  sw        $ra, 0x18($sp)
/* A650F4 80241064 AFB00010 */  sw        $s0, 0x10($sp)
/* A650F8 80241068 8E300148 */  lw        $s0, 0x148($s1)
/* A650FC 8024106C 0C00EABB */  jal       get_npc_unsafe
/* A65100 80241070 86040008 */   lh       $a0, 8($s0)
/* A65104 80241074 0040202D */  daddu     $a0, $v0, $zero
/* A65108 80241078 9482008E */  lhu       $v0, 0x8e($a0)
/* A6510C 8024107C 2442FFFF */  addiu     $v0, $v0, -1
/* A65110 80241080 A482008E */  sh        $v0, 0x8e($a0)
/* A65114 80241084 00021400 */  sll       $v0, $v0, 0x10
/* A65118 80241088 1C400007 */  bgtz      $v0, .L802410A8
/* A6511C 8024108C 00000000 */   nop
/* A65120 80241090 8E0200CC */  lw        $v0, 0xcc($s0)
/* A65124 80241094 8C430000 */  lw        $v1, ($v0)
/* A65128 80241098 24020003 */  addiu     $v0, $zero, 3
/* A6512C 8024109C A482008E */  sh        $v0, 0x8e($a0)
/* A65130 802410A0 AC830028 */  sw        $v1, 0x28($a0)
/* A65134 802410A4 AE200070 */  sw        $zero, 0x70($s1)
.L802410A8:
/* A65138 802410A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* A6513C 802410AC 8FB10014 */  lw        $s1, 0x14($sp)
/* A65140 802410B0 8FB00010 */  lw        $s0, 0x10($sp)
/* A65144 802410B4 03E00008 */  jr        $ra
/* A65148 802410B8 27BD0020 */   addiu    $sp, $sp, 0x20
