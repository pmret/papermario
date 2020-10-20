.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241770_BFEFF0
/* BFEFF0 80241770 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BFEFF4 80241774 AFB30024 */  sw        $s3, 0x24($sp)
/* BFEFF8 80241778 0080982D */  daddu     $s3, $a0, $zero
/* BFEFFC 8024177C AFBF0028 */  sw        $ra, 0x28($sp)
/* BFF000 80241780 AFB20020 */  sw        $s2, 0x20($sp)
/* BFF004 80241784 AFB1001C */  sw        $s1, 0x1c($sp)
/* BFF008 80241788 AFB00018 */  sw        $s0, 0x18($sp)
/* BFF00C 8024178C 8E700148 */  lw        $s0, 0x148($s3)
/* BFF010 80241790 00A0902D */  daddu     $s2, $a1, $zero
/* BFF014 80241794 86040008 */  lh        $a0, 8($s0)
/* BFF018 80241798 0C00EABB */  jal       get_npc_unsafe
/* BFF01C 8024179C 00C0882D */   daddu    $s1, $a2, $zero
/* BFF020 802417A0 0220202D */  daddu     $a0, $s1, $zero
/* BFF024 802417A4 0200282D */  daddu     $a1, $s0, $zero
/* BFF028 802417A8 24030001 */  addiu     $v1, $zero, 1
/* BFF02C 802417AC AFA30010 */  sw        $v1, 0x10($sp)
/* BFF030 802417B0 8E460024 */  lw        $a2, 0x24($s2)
/* BFF034 802417B4 8E470028 */  lw        $a3, 0x28($s2)
/* BFF038 802417B8 0C01242D */  jal       func_800490B4
/* BFF03C 802417BC 0040802D */   daddu    $s0, $v0, $zero
/* BFF040 802417C0 10400024 */  beqz      $v0, .L80241854
/* BFF044 802417C4 24020010 */   addiu    $v0, $zero, 0x10
/* BFF048 802417C8 8E050018 */  lw        $a1, 0x18($s0)
/* BFF04C 802417CC 8E06000C */  lw        $a2, 0xc($s0)
/* BFF050 802417D0 0C00EA95 */  jal       npc_move_heading
/* BFF054 802417D4 0200202D */   daddu    $a0, $s0, $zero
/* BFF058 802417D8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFF05C 802417DC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFF060 802417E0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BFF064 802417E4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BFF068 802417E8 8C460028 */  lw        $a2, 0x28($v0)
/* BFF06C 802417EC 0C00A7B5 */  jal       dist2D
/* BFF070 802417F0 8C470030 */   lw       $a3, 0x30($v0)
/* BFF074 802417F4 C6020018 */  lwc1      $f2, 0x18($s0)
/* BFF078 802417F8 3C014004 */  lui       $at, 0x4004
/* BFF07C 802417FC 44812800 */  mtc1      $at, $f5
/* BFF080 80241800 44802000 */  mtc1      $zero, $f4
/* BFF084 80241804 460010A1 */  cvt.d.s   $f2, $f2
/* BFF088 80241808 46241082 */  mul.d     $f2, $f2, $f4
/* BFF08C 8024180C 00000000 */  nop       
/* BFF090 80241810 46000021 */  cvt.d.s   $f0, $f0
/* BFF094 80241814 4622003E */  c.le.d    $f0, $f2
/* BFF098 80241818 00000000 */  nop       
/* BFF09C 8024181C 45000003 */  bc1f      .L8024182C
/* BFF0A0 80241820 2402000E */   addiu    $v0, $zero, 0xe
/* BFF0A4 80241824 08090615 */  j         .L80241854
/* BFF0A8 80241828 A600008E */   sh       $zero, 0x8e($s0)
.L8024182C:
/* BFF0AC 8024182C 9602008E */  lhu       $v0, 0x8e($s0)
/* BFF0B0 80241830 2442FFFF */  addiu     $v0, $v0, -1
/* BFF0B4 80241834 A602008E */  sh        $v0, 0x8e($s0)
/* BFF0B8 80241838 00021400 */  sll       $v0, $v0, 0x10
/* BFF0BC 8024183C 1C400006 */  bgtz      $v0, .L80241858
/* BFF0C0 80241840 3C030020 */   lui      $v1, 0x20
/* BFF0C4 80241844 8E020000 */  lw        $v0, ($s0)
/* BFF0C8 80241848 00431025 */  or        $v0, $v0, $v1
/* BFF0CC 8024184C AE020000 */  sw        $v0, ($s0)
/* BFF0D0 80241850 2402000C */  addiu     $v0, $zero, 0xc
.L80241854:
/* BFF0D4 80241854 AE620070 */  sw        $v0, 0x70($s3)
.L80241858:
/* BFF0D8 80241858 8FBF0028 */  lw        $ra, 0x28($sp)
/* BFF0DC 8024185C 8FB30024 */  lw        $s3, 0x24($sp)
/* BFF0E0 80241860 8FB20020 */  lw        $s2, 0x20($sp)
/* BFF0E4 80241864 8FB1001C */  lw        $s1, 0x1c($sp)
/* BFF0E8 80241868 8FB00018 */  lw        $s0, 0x18($sp)
/* BFF0EC 8024186C 03E00008 */  jr        $ra
/* BFF0F0 80241870 27BD0030 */   addiu    $sp, $sp, 0x30
