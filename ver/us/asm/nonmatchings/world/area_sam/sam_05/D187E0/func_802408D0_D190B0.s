.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D0_D190B0
/* D190B0 802408D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D190B4 802408D4 AFB10014 */  sw        $s1, 0x14($sp)
/* D190B8 802408D8 0080882D */  daddu     $s1, $a0, $zero
/* D190BC 802408DC AFBF0018 */  sw        $ra, 0x18($sp)
/* D190C0 802408E0 AFB00010 */  sw        $s0, 0x10($sp)
/* D190C4 802408E4 8E300148 */  lw        $s0, 0x148($s1)
/* D190C8 802408E8 0C00EABB */  jal       get_npc_unsafe
/* D190CC 802408EC 86040008 */   lh       $a0, 8($s0)
/* D190D0 802408F0 0040202D */  daddu     $a0, $v0, $zero
/* D190D4 802408F4 8482008E */  lh        $v0, 0x8e($a0)
/* D190D8 802408F8 9483008E */  lhu       $v1, 0x8e($a0)
/* D190DC 802408FC 18400003 */  blez      $v0, .L8024090C
/* D190E0 80240900 2462FFFF */   addiu    $v0, $v1, -1
/* D190E4 80240904 0809024A */  j         .L80240928
/* D190E8 80240908 A482008E */   sh       $v0, 0x8e($a0)
.L8024090C:
/* D190EC 8024090C 8E0200CC */  lw        $v0, 0xcc($s0)
/* D190F0 80240910 AE00006C */  sw        $zero, 0x6c($s0)
/* D190F4 80240914 8C420000 */  lw        $v0, ($v0)
/* D190F8 80240918 AC820028 */  sw        $v0, 0x28($a0)
/* D190FC 8024091C 24020001 */  addiu     $v0, $zero, 1
/* D19100 80240920 AE200074 */  sw        $zero, 0x74($s1)
/* D19104 80240924 AE220070 */  sw        $v0, 0x70($s1)
.L80240928:
/* D19108 80240928 8FBF0018 */  lw        $ra, 0x18($sp)
/* D1910C 8024092C 8FB10014 */  lw        $s1, 0x14($sp)
/* D19110 80240930 8FB00010 */  lw        $s0, 0x10($sp)
/* D19114 80240934 03E00008 */  jr        $ra
/* D19118 80240938 27BD0020 */   addiu    $sp, $sp, 0x20
