.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241678
/* BA1DA8 80241678 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA1DAC 8024167C AFB10014 */  sw        $s1, 0x14($sp)
/* BA1DB0 80241680 0080882D */  daddu     $s1, $a0, $zero
/* BA1DB4 80241684 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA1DB8 80241688 AFB00010 */  sw        $s0, 0x10($sp)
/* BA1DBC 8024168C 8E300148 */  lw        $s0, 0x148($s1)
/* BA1DC0 80241690 0C00EABB */  jal       get_npc_unsafe
/* BA1DC4 80241694 86040008 */   lh       $a0, 8($s0)
/* BA1DC8 80241698 0040182D */  daddu     $v1, $v0, $zero
/* BA1DCC 8024169C 9462008E */  lhu       $v0, 0x8e($v1)
/* BA1DD0 802416A0 2442FFFF */  addiu     $v0, $v0, -1
/* BA1DD4 802416A4 A462008E */  sh        $v0, 0x8e($v1)
/* BA1DD8 802416A8 00021400 */  sll       $v0, $v0, 0x10
/* BA1DDC 802416AC 14400005 */  bnez      $v0, .L802416C4
/* BA1DE0 802416B0 00000000 */   nop      
/* BA1DE4 802416B4 960200AA */  lhu       $v0, 0xaa($s0)
/* BA1DE8 802416B8 A462008E */  sh        $v0, 0x8e($v1)
/* BA1DEC 802416BC 2402000E */  addiu     $v0, $zero, 0xe
/* BA1DF0 802416C0 AE220070 */  sw        $v0, 0x70($s1)
.L802416C4:
/* BA1DF4 802416C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA1DF8 802416C8 8FB10014 */  lw        $s1, 0x14($sp)
/* BA1DFC 802416CC 8FB00010 */  lw        $s0, 0x10($sp)
/* BA1E00 802416D0 03E00008 */  jr        $ra
/* BA1E04 802416D4 27BD0020 */   addiu    $sp, $sp, 0x20
