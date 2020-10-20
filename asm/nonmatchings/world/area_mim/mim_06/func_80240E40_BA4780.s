.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E40_BA55C0
/* BA55C0 80240E40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA55C4 80240E44 AFB10014 */  sw        $s1, 0x14($sp)
/* BA55C8 80240E48 0080882D */  daddu     $s1, $a0, $zero
/* BA55CC 80240E4C AFBF0018 */  sw        $ra, 0x18($sp)
/* BA55D0 80240E50 AFB00010 */  sw        $s0, 0x10($sp)
/* BA55D4 80240E54 8E300148 */  lw        $s0, 0x148($s1)
/* BA55D8 80240E58 0C00EABB */  jal       get_npc_unsafe
/* BA55DC 80240E5C 86040008 */   lh       $a0, 8($s0)
/* BA55E0 80240E60 0040202D */  daddu     $a0, $v0, $zero
/* BA55E4 80240E64 8482008E */  lh        $v0, 0x8e($a0)
/* BA55E8 80240E68 9483008E */  lhu       $v1, 0x8e($a0)
/* BA55EC 80240E6C 18400003 */  blez      $v0, .L80240E7C
/* BA55F0 80240E70 2462FFFF */   addiu    $v0, $v1, -1
/* BA55F4 80240E74 080903A6 */  j         .L80240E98
/* BA55F8 80240E78 A482008E */   sh       $v0, 0x8e($a0)
.L80240E7C:
/* BA55FC 80240E7C 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA5600 80240E80 AE00006C */  sw        $zero, 0x6c($s0)
/* BA5604 80240E84 8C420000 */  lw        $v0, ($v0)
/* BA5608 80240E88 AC820028 */  sw        $v0, 0x28($a0)
/* BA560C 80240E8C 24020001 */  addiu     $v0, $zero, 1
/* BA5610 80240E90 AE200074 */  sw        $zero, 0x74($s1)
/* BA5614 80240E94 AE220070 */  sw        $v0, 0x70($s1)
.L80240E98:
/* BA5618 80240E98 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA561C 80240E9C 8FB10014 */  lw        $s1, 0x14($sp)
/* BA5620 80240EA0 8FB00010 */  lw        $s0, 0x10($sp)
/* BA5624 80240EA4 03E00008 */  jr        $ra
/* BA5628 80240EA8 27BD0020 */   addiu    $sp, $sp, 0x20
