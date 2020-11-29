.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_AACF10
/* AACF10 802406E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AACF14 802406E4 AFB00010 */  sw        $s0, 0x10($sp)
/* AACF18 802406E8 3C100011 */  lui       $s0, 0x11
/* AACF1C 802406EC 2610F1B0 */  addiu     $s0, $s0, -0xe50
/* AACF20 802406F0 3C040000 */  lui       $a0, 0
/* AACF24 802406F4 24847308 */  addiu     $a0, $a0, 0x7308
/* AACF28 802406F8 02042021 */  addu      $a0, $s0, $a0
/* AACF2C 802406FC 24853D86 */  addiu     $a1, $a0, 0x3d86
/* AACF30 80240700 AFB10014 */  sw        $s1, 0x14($sp)
/* AACF34 80240704 3C118024 */  lui       $s1, %hi(D_802437C0)
/* AACF38 80240708 263137C0 */  addiu     $s1, $s1, %lo(D_802437C0)
/* AACF3C 8024070C AFBF0018 */  sw        $ra, 0x18($sp)
/* AACF40 80240710 0C00A5CF */  jal       dma_copy
/* AACF44 80240714 0220302D */   daddu    $a2, $s1, $zero
/* AACF48 80240718 3C020001 */  lui       $v0, 1
/* AACF4C 8024071C 2442B090 */  addiu     $v0, $v0, -0x4f70
/* AACF50 80240720 02028021 */  addu      $s0, $s0, $v0
/* AACF54 80240724 0200202D */  daddu     $a0, $s0, $zero
/* AACF58 80240728 24850200 */  addiu     $a1, $a0, 0x200
/* AACF5C 8024072C 3C108024 */  lui       $s0, %hi(D_80247548)
/* AACF60 80240730 26107548 */  addiu     $s0, $s0, %lo(D_80247548)
/* AACF64 80240734 0C00A5CF */  jal       dma_copy
/* AACF68 80240738 0200302D */   daddu    $a2, $s0, $zero
/* AACF6C 8024073C 3C048024 */  lui       $a0, %hi(D_80247750)
/* AACF70 80240740 24847750 */  addiu     $a0, $a0, %lo(D_80247750)
/* AACF74 80240744 24020096 */  addiu     $v0, $zero, 0x96
/* AACF78 80240748 A4820008 */  sh        $v0, 8($a0)
/* AACF7C 8024074C 24020069 */  addiu     $v0, $zero, 0x69
/* AACF80 80240750 A482000A */  sh        $v0, 0xa($a0)
/* AACF84 80240754 24020002 */  addiu     $v0, $zero, 2
/* AACF88 80240758 AC82000C */  sw        $v0, 0xc($a0)
/* AACF8C 8024075C 24020001 */  addiu     $v0, $zero, 1
/* AACF90 80240760 AC910000 */  sw        $s1, ($a0)
/* AACF94 80240764 AC900004 */  sw        $s0, 4($a0)
/* AACF98 80240768 0C0496CB */  jal       set_message_images
/* AACF9C 8024076C AC820010 */   sw       $v0, 0x10($a0)
/* AACFA0 80240770 8FBF0018 */  lw        $ra, 0x18($sp)
/* AACFA4 80240774 8FB10014 */  lw        $s1, 0x14($sp)
/* AACFA8 80240778 8FB00010 */  lw        $s0, 0x10($sp)
/* AACFAC 8024077C 24020002 */  addiu     $v0, $zero, 2
/* AACFB0 80240780 03E00008 */  jr        $ra
/* AACFB4 80240784 27BD0020 */   addiu    $sp, $sp, 0x20
/* AACFB8 80240788 00000000 */  nop       
/* AACFBC 8024078C 00000000 */  nop       
