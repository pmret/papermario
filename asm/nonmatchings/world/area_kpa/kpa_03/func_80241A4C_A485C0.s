.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A4C_A4A00C
/* A4A00C 80241A4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4A010 80241A50 AFB10014 */  sw        $s1, 0x14($sp)
/* A4A014 80241A54 0080882D */  daddu     $s1, $a0, $zero
/* A4A018 80241A58 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4A01C 80241A5C AFB00010 */  sw        $s0, 0x10($sp)
/* A4A020 80241A60 8E300148 */  lw        $s0, 0x148($s1)
/* A4A024 80241A64 0C00EABB */  jal       get_npc_unsafe
/* A4A028 80241A68 86040008 */   lh       $a0, 8($s0)
/* A4A02C 80241A6C 0040202D */  daddu     $a0, $v0, $zero
/* A4A030 80241A70 9482008E */  lhu       $v0, 0x8e($a0)
/* A4A034 80241A74 2442FFFF */  addiu     $v0, $v0, -1
/* A4A038 80241A78 A482008E */  sh        $v0, 0x8e($a0)
/* A4A03C 80241A7C 00021400 */  sll       $v0, $v0, 0x10
/* A4A040 80241A80 1C400007 */  bgtz      $v0, .L80241AA0
/* A4A044 80241A84 00000000 */   nop      
/* A4A048 80241A88 8E0200CC */  lw        $v0, 0xcc($s0)
/* A4A04C 80241A8C 8C430000 */  lw        $v1, ($v0)
/* A4A050 80241A90 24020003 */  addiu     $v0, $zero, 3
/* A4A054 80241A94 A482008E */  sh        $v0, 0x8e($a0)
/* A4A058 80241A98 AC830028 */  sw        $v1, 0x28($a0)
/* A4A05C 80241A9C AE200070 */  sw        $zero, 0x70($s1)
.L80241AA0:
/* A4A060 80241AA0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4A064 80241AA4 8FB10014 */  lw        $s1, 0x14($sp)
/* A4A068 80241AA8 8FB00010 */  lw        $s0, 0x10($sp)
/* A4A06C 80241AAC 03E00008 */  jr        $ra
/* A4A070 80241AB0 27BD0020 */   addiu    $sp, $sp, 0x20
