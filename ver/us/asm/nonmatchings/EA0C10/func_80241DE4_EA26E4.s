.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246648_EA6F48
.double 0.8

.section .text

glabel func_80241DE4_EA26E4
/* EA26E4 80241DE4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA26E8 80241DE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* EA26EC 80241DEC 0080982D */  daddu     $s3, $a0, $zero
/* EA26F0 80241DF0 AFBF0020 */  sw        $ra, 0x20($sp)
/* EA26F4 80241DF4 AFB20018 */  sw        $s2, 0x18($sp)
/* EA26F8 80241DF8 AFB10014 */  sw        $s1, 0x14($sp)
/* EA26FC 80241DFC AFB00010 */  sw        $s0, 0x10($sp)
/* EA2700 80241E00 8E710148 */  lw        $s1, 0x148($s3)
/* EA2704 80241E04 86240008 */  lh        $a0, 8($s1)
/* EA2708 80241E08 0C00F92F */  jal       dead_get_npc_unsafe
/* EA270C 80241E0C 00A0902D */   daddu    $s2, $a1, $zero
/* EA2710 80241E10 0040802D */  daddu     $s0, $v0, $zero
/* EA2714 80241E14 8602008E */  lh        $v0, 0x8e($s0)
/* EA2718 80241E18 9603008E */  lhu       $v1, 0x8e($s0)
/* EA271C 80241E1C 18400005 */  blez      $v0, .L80241E34
/* EA2720 80241E20 2462FFFF */   addiu    $v0, $v1, -1
/* EA2724 80241E24 A602008E */  sh        $v0, 0x8e($s0)
/* EA2728 80241E28 00021400 */  sll       $v0, $v0, 0x10
/* EA272C 80241E2C 1C400033 */  bgtz      $v0, .L80241EFC
/* EA2730 80241E30 00000000 */   nop
.L80241E34:
/* EA2734 80241E34 8602008C */  lh        $v0, 0x8c($s0)
/* EA2738 80241E38 14400030 */  bnez      $v0, .L80241EFC
/* EA273C 80241E3C 00000000 */   nop
/* EA2740 80241E40 8E2200CC */  lw        $v0, 0xcc($s1)
/* EA2744 80241E44 8C420024 */  lw        $v0, 0x24($v0)
/* EA2748 80241E48 AE020028 */  sw        $v0, 0x28($s0)
/* EA274C 80241E4C C6400018 */  lwc1      $f0, 0x18($s2)
/* EA2750 80241E50 E6000018 */  swc1      $f0, 0x18($s0)
/* EA2754 80241E54 8E230088 */  lw        $v1, 0x88($s1)
/* EA2758 80241E58 24020005 */  addiu     $v0, $zero, 5
/* EA275C 80241E5C 10620005 */  beq       $v1, $v0, .L80241E74
/* EA2760 80241E60 00000000 */   nop
/* EA2764 80241E64 10600003 */  beqz      $v1, .L80241E74
/* EA2768 80241E68 24020001 */   addiu    $v0, $zero, 1
/* EA276C 80241E6C 14620006 */  bne       $v1, $v0, .L80241E88
/* EA2770 80241E70 00000000 */   nop
.L80241E74:
/* EA2774 80241E74 8E220084 */  lw        $v0, 0x84($s1)
/* EA2778 80241E78 00021FC2 */  srl       $v1, $v0, 0x1f
/* EA277C 80241E7C 00431021 */  addu      $v0, $v0, $v1
/* EA2780 80241E80 00021043 */  sra       $v0, $v0, 1
/* EA2784 80241E84 A60200A8 */  sh        $v0, 0xa8($s0)
.L80241E88:
/* EA2788 80241E88 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EA278C 80241E8C 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EA2790 80241E90 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EA2794 80241E94 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EA2798 80241E98 8C460028 */  lw        $a2, 0x28($v0)
/* EA279C 80241E9C 0C00AC71 */  jal       dead_dist2D
/* EA27A0 80241EA0 8C470030 */   lw       $a3, 0x30($v0)
/* EA27A4 80241EA4 C6020018 */  lwc1      $f2, 0x18($s0)
/* EA27A8 80241EA8 46020003 */  div.s     $f0, $f0, $f2
/* EA27AC 80241EAC 3C018024 */  lui       $at, %hi(D_80246648_EA6F48)
/* EA27B0 80241EB0 D4226648 */  ldc1      $f2, %lo(D_80246648_EA6F48)($at)
/* EA27B4 80241EB4 46000021 */  cvt.d.s   $f0, $f0
/* EA27B8 80241EB8 46220000 */  add.d     $f0, $f0, $f2
/* EA27BC 80241EBC 4620010D */  trunc.w.d $f4, $f0
/* EA27C0 80241EC0 44022000 */  mfc1      $v0, $f4
/* EA27C4 80241EC4 00000000 */  nop
/* EA27C8 80241EC8 A602008E */  sh        $v0, 0x8e($s0)
/* EA27CC 80241ECC 00021400 */  sll       $v0, $v0, 0x10
/* EA27D0 80241ED0 8E230078 */  lw        $v1, 0x78($s1)
/* EA27D4 80241ED4 00021403 */  sra       $v0, $v0, 0x10
/* EA27D8 80241ED8 0043102A */  slt       $v0, $v0, $v1
/* EA27DC 80241EDC 10400003 */  beqz      $v0, .L80241EEC
/* EA27E0 80241EE0 00000000 */   nop
/* EA27E4 80241EE4 9622007A */  lhu       $v0, 0x7a($s1)
/* EA27E8 80241EE8 A602008E */  sh        $v0, 0x8e($s0)
.L80241EEC:
/* EA27EC 80241EEC 8602008E */  lh        $v0, 0x8e($s0)
/* EA27F0 80241EF0 AE22007C */  sw        $v0, 0x7c($s1)
/* EA27F4 80241EF4 2402000E */  addiu     $v0, $zero, 0xe
/* EA27F8 80241EF8 AE620070 */  sw        $v0, 0x70($s3)
.L80241EFC:
/* EA27FC 80241EFC 8FBF0020 */  lw        $ra, 0x20($sp)
/* EA2800 80241F00 8FB3001C */  lw        $s3, 0x1c($sp)
/* EA2804 80241F04 8FB20018 */  lw        $s2, 0x18($sp)
/* EA2808 80241F08 8FB10014 */  lw        $s1, 0x14($sp)
/* EA280C 80241F0C 8FB00010 */  lw        $s0, 0x10($sp)
/* EA2810 80241F10 03E00008 */  jr        $ra
/* EA2814 80241F14 27BD0028 */   addiu    $sp, $sp, 0x28
