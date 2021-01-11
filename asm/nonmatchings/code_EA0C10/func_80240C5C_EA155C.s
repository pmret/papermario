.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C5C_EA155C
/* EA155C 80240C5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA1560 80240C60 AFB10014 */  sw        $s1, 0x14($sp)
/* EA1564 80240C64 0080882D */  daddu     $s1, $a0, $zero
/* EA1568 80240C68 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA156C 80240C6C AFB00010 */  sw        $s0, 0x10($sp)
/* EA1570 80240C70 8E300148 */  lw        $s0, 0x148($s1)
/* EA1574 80240C74 0C00F92F */  jal       func_8003E4BC
/* EA1578 80240C78 86040008 */   lh       $a0, 8($s0)
/* EA157C 80240C7C 0040202D */  daddu     $a0, $v0, $zero
/* EA1580 80240C80 8482008E */  lh        $v0, 0x8e($a0)
/* EA1584 80240C84 9483008E */  lhu       $v1, 0x8e($a0)
/* EA1588 80240C88 18400003 */  blez      $v0, .L80240C98
/* EA158C 80240C8C 2462FFFF */   addiu    $v0, $v1, -1
/* EA1590 80240C90 0809032D */  j         .L80240CB4
/* EA1594 80240C94 A482008E */   sh       $v0, 0x8e($a0)
.L80240C98:
/* EA1598 80240C98 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA159C 80240C9C AE00006C */  sw        $zero, 0x6c($s0)
/* EA15A0 80240CA0 8C420000 */  lw        $v0, ($v0)
/* EA15A4 80240CA4 AC820028 */  sw        $v0, 0x28($a0)
/* EA15A8 80240CA8 24020001 */  addiu     $v0, $zero, 1
/* EA15AC 80240CAC AE200074 */  sw        $zero, 0x74($s1)
/* EA15B0 80240CB0 AE220070 */  sw        $v0, 0x70($s1)
.L80240CB4:
/* EA15B4 80240CB4 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA15B8 80240CB8 8FB10014 */  lw        $s1, 0x14($sp)
/* EA15BC 80240CBC 8FB00010 */  lw        $s0, 0x10($sp)
/* EA15C0 80240CC0 03E00008 */  jr        $ra
/* EA15C4 80240CC4 27BD0020 */   addiu    $sp, $sp, 0x20
