.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A70_DAEE70
/* DAEE70 80241A70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DAEE74 80241A74 AFB10014 */  sw        $s1, 0x14($sp)
/* DAEE78 80241A78 0080882D */  daddu     $s1, $a0, $zero
/* DAEE7C 80241A7C AFBF0018 */  sw        $ra, 0x18($sp)
/* DAEE80 80241A80 AFB00010 */  sw        $s0, 0x10($sp)
/* DAEE84 80241A84 8E300148 */  lw        $s0, 0x148($s1)
/* DAEE88 80241A88 0C00EABB */  jal       get_npc_unsafe
/* DAEE8C 80241A8C 86040008 */   lh       $a0, 8($s0)
/* DAEE90 80241A90 0040182D */  daddu     $v1, $v0, $zero
/* DAEE94 80241A94 9462008E */  lhu       $v0, 0x8e($v1)
/* DAEE98 80241A98 2442FFFF */  addiu     $v0, $v0, -1
/* DAEE9C 80241A9C A462008E */  sh        $v0, 0x8e($v1)
/* DAEEA0 80241AA0 00021400 */  sll       $v0, $v0, 0x10
/* DAEEA4 80241AA4 14400005 */  bnez      $v0, .L80241ABC
/* DAEEA8 80241AA8 00000000 */   nop      
/* DAEEAC 80241AAC 8E0200CC */  lw        $v0, 0xcc($s0)
/* DAEEB0 80241AB0 8C420000 */  lw        $v0, ($v0)
/* DAEEB4 80241AB4 AC620028 */  sw        $v0, 0x28($v1)
/* DAEEB8 80241AB8 AE200070 */  sw        $zero, 0x70($s1)
.L80241ABC:
/* DAEEBC 80241ABC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DAEEC0 80241AC0 8FB10014 */  lw        $s1, 0x14($sp)
/* DAEEC4 80241AC4 8FB00010 */  lw        $s0, 0x10($sp)
/* DAEEC8 80241AC8 03E00008 */  jr        $ra
/* DAEECC 80241ACC 27BD0020 */   addiu    $sp, $sp, 0x20
