.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240650
/* D2C380 80240650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2C384 80240654 AFB10014 */  sw        $s1, 0x14($sp)
/* D2C388 80240658 0080882D */  daddu     $s1, $a0, $zero
/* D2C38C 8024065C AFBF0018 */  sw        $ra, 0x18($sp)
/* D2C390 80240660 AFB00010 */  sw        $s0, 0x10($sp)
/* D2C394 80240664 8E300148 */  lw        $s0, 0x148($s1)
/* D2C398 80240668 0C00EABB */  jal       get_npc_unsafe
/* D2C39C 8024066C 86040008 */   lh       $a0, 8($s0)
/* D2C3A0 80240670 24030001 */  addiu     $v1, $zero, 1
/* D2C3A4 80240674 0040202D */  daddu     $a0, $v0, $zero
/* D2C3A8 80240678 AE03006C */  sw        $v1, 0x6c($s0)
/* D2C3AC 8024067C 8482008C */  lh        $v0, 0x8c($a0)
/* D2C3B0 80240680 14400009 */  bnez      $v0, .L802406A8
/* D2C3B4 80240684 24020002 */   addiu    $v0, $zero, 2
/* D2C3B8 80240688 96030072 */  lhu       $v1, 0x72($s0)
/* D2C3BC 8024068C AE02006C */  sw        $v0, 0x6c($s0)
/* D2C3C0 80240690 A483008E */  sh        $v1, 0x8e($a0)
/* D2C3C4 80240694 8E0200CC */  lw        $v0, 0xcc($s0)
/* D2C3C8 80240698 8C420020 */  lw        $v0, 0x20($v0)
/* D2C3CC 8024069C AC820028 */  sw        $v0, 0x28($a0)
/* D2C3D0 802406A0 2402001F */  addiu     $v0, $zero, 0x1f
/* D2C3D4 802406A4 AE220070 */  sw        $v0, 0x70($s1)
.L802406A8:
/* D2C3D8 802406A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2C3DC 802406AC 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C3E0 802406B0 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C3E4 802406B4 03E00008 */  jr        $ra
/* D2C3E8 802406B8 27BD0020 */   addiu    $sp, $sp, 0x20
