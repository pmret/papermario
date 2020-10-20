.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024072C_D2C45C
/* D2C45C 8024072C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D2C460 80240730 AFB10034 */  sw        $s1, 0x34($sp)
/* D2C464 80240734 0080882D */  daddu     $s1, $a0, $zero
/* D2C468 80240738 AFBF0038 */  sw        $ra, 0x38($sp)
/* D2C46C 8024073C AFB00030 */  sw        $s0, 0x30($sp)
/* D2C470 80240740 8E300148 */  lw        $s0, 0x148($s1)
/* D2C474 80240744 0C00EABB */  jal       get_npc_unsafe
/* D2C478 80240748 86040008 */   lh       $a0, 8($s0)
/* D2C47C 8024074C 0040282D */  daddu     $a1, $v0, $zero
/* D2C480 80240750 94A2008E */  lhu       $v0, 0x8e($a1)
/* D2C484 80240754 2442FFFF */  addiu     $v0, $v0, -1
/* D2C488 80240758 A4A2008E */  sh        $v0, 0x8e($a1)
/* D2C48C 8024075C 00021400 */  sll       $v0, $v0, 0x10
/* D2C490 80240760 1C400023 */  bgtz      $v0, .L802407F0
/* D2C494 80240764 24020004 */   addiu    $v0, $zero, 4
/* D2C498 80240768 8E0300CC */  lw        $v1, 0xcc($s0)
/* D2C49C 8024076C AE02006C */  sw        $v0, 0x6c($s0)
/* D2C4A0 80240770 8C620000 */  lw        $v0, ($v1)
/* D2C4A4 80240774 ACA20028 */  sw        $v0, 0x28($a1)
/* D2C4A8 80240778 9602007A */  lhu       $v0, 0x7a($s0)
/* D2C4AC 8024077C A4A2008E */  sh        $v0, 0x8e($a1)
/* D2C4B0 80240780 8E020078 */  lw        $v0, 0x78($s0)
/* D2C4B4 80240784 28420008 */  slti      $v0, $v0, 8
/* D2C4B8 80240788 14400018 */  bnez      $v0, .L802407EC
/* D2C4BC 8024078C 24020021 */   addiu    $v0, $zero, 0x21
/* D2C4C0 80240790 24040003 */  addiu     $a0, $zero, 3
/* D2C4C4 80240794 27A30028 */  addiu     $v1, $sp, 0x28
/* D2C4C8 80240798 84A700A8 */  lh        $a3, 0xa8($a1)
/* D2C4CC 8024079C 3C013F80 */  lui       $at, 0x3f80
/* D2C4D0 802407A0 44810000 */  mtc1      $at, $f0
/* D2C4D4 802407A4 3C014000 */  lui       $at, 0x4000
/* D2C4D8 802407A8 44811000 */  mtc1      $at, $f2
/* D2C4DC 802407AC 3C01C1A0 */  lui       $at, 0xc1a0
/* D2C4E0 802407B0 44812000 */  mtc1      $at, $f4
/* D2C4E4 802407B4 44873000 */  mtc1      $a3, $f6
/* D2C4E8 802407B8 00000000 */  nop       
/* D2C4EC 802407BC 468031A0 */  cvt.s.w   $f6, $f6
/* D2C4F0 802407C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* D2C4F4 802407C4 E7A20014 */  swc1      $f2, 0x14($sp)
/* D2C4F8 802407C8 E7A40018 */  swc1      $f4, 0x18($sp)
/* D2C4FC 802407CC 8E020078 */  lw        $v0, 0x78($s0)
/* D2C500 802407D0 44073000 */  mfc1      $a3, $f6
/* D2C504 802407D4 0000302D */  daddu     $a2, $zero, $zero
/* D2C508 802407D8 AFA30020 */  sw        $v1, 0x20($sp)
/* D2C50C 802407DC 2442FFFF */  addiu     $v0, $v0, -1
/* D2C510 802407E0 0C01BFA4 */  jal       fx_emote
/* D2C514 802407E4 AFA2001C */   sw       $v0, 0x1c($sp)
/* D2C518 802407E8 24020021 */  addiu     $v0, $zero, 0x21
.L802407EC:
/* D2C51C 802407EC AE220070 */  sw        $v0, 0x70($s1)
.L802407F0:
/* D2C520 802407F0 8FBF0038 */  lw        $ra, 0x38($sp)
/* D2C524 802407F4 8FB10034 */  lw        $s1, 0x34($sp)
/* D2C528 802407F8 8FB00030 */  lw        $s0, 0x30($sp)
/* D2C52C 802407FC 03E00008 */  jr        $ra
/* D2C530 80240800 27BD0040 */   addiu    $sp, $sp, 0x40
