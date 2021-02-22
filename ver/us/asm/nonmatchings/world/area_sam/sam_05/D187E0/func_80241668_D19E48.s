.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241668_D19E48
/* D19E48 80241668 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D19E4C 8024166C AFB40040 */  sw        $s4, 0x40($sp)
/* D19E50 80241670 0080A02D */  daddu     $s4, $a0, $zero
/* D19E54 80241674 AFBF0044 */  sw        $ra, 0x44($sp)
/* D19E58 80241678 AFB3003C */  sw        $s3, 0x3c($sp)
/* D19E5C 8024167C AFB20038 */  sw        $s2, 0x38($sp)
/* D19E60 80241680 AFB10034 */  sw        $s1, 0x34($sp)
/* D19E64 80241684 AFB00030 */  sw        $s0, 0x30($sp)
/* D19E68 80241688 8E910148 */  lw        $s1, 0x148($s4)
/* D19E6C 8024168C 00A0902D */  daddu     $s2, $a1, $zero
/* D19E70 80241690 86240008 */  lh        $a0, 8($s1)
/* D19E74 80241694 0C00EABB */  jal       get_npc_unsafe
/* D19E78 80241698 00C0982D */   daddu    $s3, $a2, $zero
/* D19E7C 8024169C 0040802D */  daddu     $s0, $v0, $zero
/* D19E80 802416A0 9602008E */  lhu       $v0, 0x8e($s0)
/* D19E84 802416A4 2442FFFF */  addiu     $v0, $v0, -1
/* D19E88 802416A8 A602008E */  sh        $v0, 0x8e($s0)
/* D19E8C 802416AC 00021400 */  sll       $v0, $v0, 0x10
/* D19E90 802416B0 14400020 */  bnez      $v0, .L80241734
/* D19E94 802416B4 0260202D */   daddu    $a0, $s3, $zero
/* D19E98 802416B8 AFA00010 */  sw        $zero, 0x10($sp)
/* D19E9C 802416BC 8E46000C */  lw        $a2, 0xc($s2)
/* D19EA0 802416C0 8E470010 */  lw        $a3, 0x10($s2)
/* D19EA4 802416C4 0C01242D */  jal       func_800490B4
/* D19EA8 802416C8 0220282D */   daddu    $a1, $s1, $zero
/* D19EAC 802416CC 54400018 */  bnel      $v0, $zero, .L80241730
/* D19EB0 802416D0 A600008E */   sh       $zero, 0x8e($s0)
/* D19EB4 802416D4 24040002 */  addiu     $a0, $zero, 2
/* D19EB8 802416D8 0200282D */  daddu     $a1, $s0, $zero
/* D19EBC 802416DC 0000302D */  daddu     $a2, $zero, $zero
/* D19EC0 802416E0 860300A8 */  lh        $v1, 0xa8($s0)
/* D19EC4 802416E4 3C013F80 */  lui       $at, 0x3f80
/* D19EC8 802416E8 44810000 */  mtc1      $at, $f0
/* D19ECC 802416EC 3C014000 */  lui       $at, 0x4000
/* D19ED0 802416F0 44811000 */  mtc1      $at, $f2
/* D19ED4 802416F4 3C01C1A0 */  lui       $at, 0xc1a0
/* D19ED8 802416F8 44812000 */  mtc1      $at, $f4
/* D19EDC 802416FC 2402000F */  addiu     $v0, $zero, 0xf
/* D19EE0 80241700 AFA2001C */  sw        $v0, 0x1c($sp)
/* D19EE4 80241704 44833000 */  mtc1      $v1, $f6
/* D19EE8 80241708 00000000 */  nop
/* D19EEC 8024170C 468031A0 */  cvt.s.w   $f6, $f6
/* D19EF0 80241710 44073000 */  mfc1      $a3, $f6
/* D19EF4 80241714 27A20028 */  addiu     $v0, $sp, 0x28
/* D19EF8 80241718 AFA20020 */  sw        $v0, 0x20($sp)
/* D19EFC 8024171C E7A00010 */  swc1      $f0, 0x10($sp)
/* D19F00 80241720 E7A20014 */  swc1      $f2, 0x14($sp)
/* D19F04 80241724 0C01BFA4 */  jal       fx_emote
/* D19F08 80241728 E7A40018 */   swc1     $f4, 0x18($sp)
/* D19F0C 8024172C A600008E */  sh        $zero, 0x8e($s0)
.L80241730:
/* D19F10 80241730 AE800070 */  sw        $zero, 0x70($s4)
.L80241734:
/* D19F14 80241734 8FBF0044 */  lw        $ra, 0x44($sp)
/* D19F18 80241738 8FB40040 */  lw        $s4, 0x40($sp)
/* D19F1C 8024173C 8FB3003C */  lw        $s3, 0x3c($sp)
/* D19F20 80241740 8FB20038 */  lw        $s2, 0x38($sp)
/* D19F24 80241744 8FB10034 */  lw        $s1, 0x34($sp)
/* D19F28 80241748 8FB00030 */  lw        $s0, 0x30($sp)
/* D19F2C 8024174C 03E00008 */  jr        $ra
/* D19F30 80241750 27BD0048 */   addiu    $sp, $sp, 0x48
