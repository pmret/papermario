.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_C9E5DC
/* C9E5DC 802406BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9E5E0 802406C0 AFB10014 */  sw        $s1, 0x14($sp)
/* C9E5E4 802406C4 0080882D */  daddu     $s1, $a0, $zero
/* C9E5E8 802406C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* C9E5EC 802406CC AFB20018 */  sw        $s2, 0x18($sp)
/* C9E5F0 802406D0 AFB00010 */  sw        $s0, 0x10($sp)
/* C9E5F4 802406D4 8E300148 */  lw        $s0, 0x148($s1)
/* C9E5F8 802406D8 86040008 */  lh        $a0, 8($s0)
/* C9E5FC 802406DC 0C00EABB */  jal       get_npc_unsafe
/* C9E600 802406E0 00A0902D */   daddu    $s2, $a1, $zero
/* C9E604 802406E4 8E230078 */  lw        $v1, 0x78($s1)
/* C9E608 802406E8 24630001 */  addiu     $v1, $v1, 1
/* C9E60C 802406EC AE230078 */  sw        $v1, 0x78($s1)
/* C9E610 802406F0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* C9E614 802406F4 8C840000 */  lw        $a0, ($a0)
/* C9E618 802406F8 0064182A */  slt       $v1, $v1, $a0
/* C9E61C 802406FC 14600002 */  bnez      $v1, .L80240708
/* C9E620 80240700 0040282D */   daddu    $a1, $v0, $zero
/* C9E624 80240704 AE200078 */  sw        $zero, 0x78($s1)
.L80240708:
/* C9E628 80240708 8E0200CC */  lw        $v0, 0xcc($s0)
/* C9E62C 8024070C 8C420004 */  lw        $v0, 4($v0)
/* C9E630 80240710 ACA20028 */  sw        $v0, 0x28($a1)
/* C9E634 80240714 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C9E638 80240718 8C42007C */  lw        $v0, 0x7c($v0)
/* C9E63C 8024071C 04410004 */  bgez      $v0, .L80240730
/* C9E640 80240720 00000000 */   nop
/* C9E644 80240724 C6400000 */  lwc1      $f0, ($s2)
/* C9E648 80240728 080901D4 */  j         .L80240750
/* C9E64C 8024072C E4A00018 */   swc1     $f0, 0x18($a1)
.L80240730:
/* C9E650 80240730 3C018025 */  lui       $at, %hi(D_802491C8_CA70E8)
/* C9E654 80240734 D42291C8 */  ldc1      $f2, %lo(D_802491C8_CA70E8)($at)
/* C9E658 80240738 44820000 */  mtc1      $v0, $f0
/* C9E65C 8024073C 00000000 */  nop
/* C9E660 80240740 46800021 */  cvt.d.w   $f0, $f0
/* C9E664 80240744 46220003 */  div.d     $f0, $f0, $f2
/* C9E668 80240748 46200020 */  cvt.s.d   $f0, $f0
/* C9E66C 8024074C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240750:
/* C9E670 80240750 24020001 */  addiu     $v0, $zero, 1
/* C9E674 80240754 AE220070 */  sw        $v0, 0x70($s1)
/* C9E678 80240758 8FBF001C */  lw        $ra, 0x1c($sp)
/* C9E67C 8024075C 8FB20018 */  lw        $s2, 0x18($sp)
/* C9E680 80240760 8FB10014 */  lw        $s1, 0x14($sp)
/* C9E684 80240764 8FB00010 */  lw        $s0, 0x10($sp)
/* C9E688 80240768 03E00008 */  jr        $ra
/* C9E68C 8024076C 27BD0020 */   addiu    $sp, $sp, 0x20
