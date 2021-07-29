.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802491F8_EC2048
.double 32767.0

.section .text

glabel func_802406BC_EB950C
/* EB950C 802406BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB9510 802406C0 AFB10014 */  sw        $s1, 0x14($sp)
/* EB9514 802406C4 0080882D */  daddu     $s1, $a0, $zero
/* EB9518 802406C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* EB951C 802406CC AFB20018 */  sw        $s2, 0x18($sp)
/* EB9520 802406D0 AFB00010 */  sw        $s0, 0x10($sp)
/* EB9524 802406D4 8E300148 */  lw        $s0, 0x148($s1)
/* EB9528 802406D8 86040008 */  lh        $a0, 8($s0)
/* EB952C 802406DC 0C00F92F */  jal       func_8003E4BC
/* EB9530 802406E0 00A0902D */   daddu    $s2, $a1, $zero
/* EB9534 802406E4 8E230078 */  lw        $v1, 0x78($s1)
/* EB9538 802406E8 24630001 */  addiu     $v1, $v1, 1
/* EB953C 802406EC AE230078 */  sw        $v1, 0x78($s1)
/* EB9540 802406F0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* EB9544 802406F4 8C840000 */  lw        $a0, ($a0)
/* EB9548 802406F8 0064182A */  slt       $v1, $v1, $a0
/* EB954C 802406FC 14600002 */  bnez      $v1, .L80240708
/* EB9550 80240700 0040282D */   daddu    $a1, $v0, $zero
/* EB9554 80240704 AE200078 */  sw        $zero, 0x78($s1)
.L80240708:
/* EB9558 80240708 8E0200CC */  lw        $v0, 0xcc($s0)
/* EB955C 8024070C 8C420004 */  lw        $v0, 4($v0)
/* EB9560 80240710 ACA20028 */  sw        $v0, 0x28($a1)
/* EB9564 80240714 8E0200D0 */  lw        $v0, 0xd0($s0)
/* EB9568 80240718 8C42007C */  lw        $v0, 0x7c($v0)
/* EB956C 8024071C 04410004 */  bgez      $v0, .L80240730
/* EB9570 80240720 00000000 */   nop
/* EB9574 80240724 C6400000 */  lwc1      $f0, ($s2)
/* EB9578 80240728 080901D4 */  j         .L80240750
/* EB957C 8024072C E4A00018 */   swc1     $f0, 0x18($a1)
.L80240730:
/* EB9580 80240730 3C018025 */  lui       $at, %hi(D_802491F8_EC2048)
/* EB9584 80240734 D42291F8 */  ldc1      $f2, %lo(D_802491F8_EC2048)($at)
/* EB9588 80240738 44820000 */  mtc1      $v0, $f0
/* EB958C 8024073C 00000000 */  nop
/* EB9590 80240740 46800021 */  cvt.d.w   $f0, $f0
/* EB9594 80240744 46220003 */  div.d     $f0, $f0, $f2
/* EB9598 80240748 46200020 */  cvt.s.d   $f0, $f0
/* EB959C 8024074C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240750:
/* EB95A0 80240750 24020001 */  addiu     $v0, $zero, 1
/* EB95A4 80240754 AE220070 */  sw        $v0, 0x70($s1)
/* EB95A8 80240758 8FBF001C */  lw        $ra, 0x1c($sp)
/* EB95AC 8024075C 8FB20018 */  lw        $s2, 0x18($sp)
/* EB95B0 80240760 8FB10014 */  lw        $s1, 0x14($sp)
/* EB95B4 80240764 8FB00010 */  lw        $s0, 0x10($sp)
/* EB95B8 80240768 03E00008 */  jr        $ra
/* EB95BC 8024076C 27BD0020 */   addiu    $sp, $sp, 0x20
