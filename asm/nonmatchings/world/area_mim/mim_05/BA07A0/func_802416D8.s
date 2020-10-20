.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416D8
/* BA1E08 802416D8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BA1E0C 802416DC AFB40040 */  sw        $s4, 0x40($sp)
/* BA1E10 802416E0 0080A02D */  daddu     $s4, $a0, $zero
/* BA1E14 802416E4 AFBF0044 */  sw        $ra, 0x44($sp)
/* BA1E18 802416E8 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA1E1C 802416EC AFB20038 */  sw        $s2, 0x38($sp)
/* BA1E20 802416F0 AFB10034 */  sw        $s1, 0x34($sp)
/* BA1E24 802416F4 AFB00030 */  sw        $s0, 0x30($sp)
/* BA1E28 802416F8 8E910148 */  lw        $s1, 0x148($s4)
/* BA1E2C 802416FC 00A0902D */  daddu     $s2, $a1, $zero
/* BA1E30 80241700 86240008 */  lh        $a0, 8($s1)
/* BA1E34 80241704 0C00EABB */  jal       get_npc_unsafe
/* BA1E38 80241708 00C0982D */   daddu    $s3, $a2, $zero
/* BA1E3C 8024170C 0040802D */  daddu     $s0, $v0, $zero
/* BA1E40 80241710 9602008E */  lhu       $v0, 0x8e($s0)
/* BA1E44 80241714 2442FFFF */  addiu     $v0, $v0, -1
/* BA1E48 80241718 A602008E */  sh        $v0, 0x8e($s0)
/* BA1E4C 8024171C 00021400 */  sll       $v0, $v0, 0x10
/* BA1E50 80241720 14400020 */  bnez      $v0, .L802417A4
/* BA1E54 80241724 0260202D */   daddu    $a0, $s3, $zero
/* BA1E58 80241728 AFA00010 */  sw        $zero, 0x10($sp)
/* BA1E5C 8024172C 8E46000C */  lw        $a2, 0xc($s2)
/* BA1E60 80241730 8E470010 */  lw        $a3, 0x10($s2)
/* BA1E64 80241734 0C01242D */  jal       func_800490B4
/* BA1E68 80241738 0220282D */   daddu    $a1, $s1, $zero
/* BA1E6C 8024173C 54400018 */  bnel      $v0, $zero, .L802417A0
/* BA1E70 80241740 A600008E */   sh       $zero, 0x8e($s0)
/* BA1E74 80241744 24040002 */  addiu     $a0, $zero, 2
/* BA1E78 80241748 0200282D */  daddu     $a1, $s0, $zero
/* BA1E7C 8024174C 0000302D */  daddu     $a2, $zero, $zero
/* BA1E80 80241750 860300A8 */  lh        $v1, 0xa8($s0)
/* BA1E84 80241754 3C013F80 */  lui       $at, 0x3f80
/* BA1E88 80241758 44810000 */  mtc1      $at, $f0
/* BA1E8C 8024175C 3C014000 */  lui       $at, 0x4000
/* BA1E90 80241760 44811000 */  mtc1      $at, $f2
/* BA1E94 80241764 3C01C1A0 */  lui       $at, 0xc1a0
/* BA1E98 80241768 44812000 */  mtc1      $at, $f4
/* BA1E9C 8024176C 2402000F */  addiu     $v0, $zero, 0xf
/* BA1EA0 80241770 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA1EA4 80241774 44833000 */  mtc1      $v1, $f6
/* BA1EA8 80241778 00000000 */  nop       
/* BA1EAC 8024177C 468031A0 */  cvt.s.w   $f6, $f6
/* BA1EB0 80241780 44073000 */  mfc1      $a3, $f6
/* BA1EB4 80241784 27A20028 */  addiu     $v0, $sp, 0x28
/* BA1EB8 80241788 AFA20020 */  sw        $v0, 0x20($sp)
/* BA1EBC 8024178C E7A00010 */  swc1      $f0, 0x10($sp)
/* BA1EC0 80241790 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA1EC4 80241794 0C01BFA4 */  jal       fx_emote
/* BA1EC8 80241798 E7A40018 */   swc1     $f4, 0x18($sp)
/* BA1ECC 8024179C A600008E */  sh        $zero, 0x8e($s0)
.L802417A0:
/* BA1ED0 802417A0 AE800070 */  sw        $zero, 0x70($s4)
.L802417A4:
/* BA1ED4 802417A4 8FBF0044 */  lw        $ra, 0x44($sp)
/* BA1ED8 802417A8 8FB40040 */  lw        $s4, 0x40($sp)
/* BA1EDC 802417AC 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA1EE0 802417B0 8FB20038 */  lw        $s2, 0x38($sp)
/* BA1EE4 802417B4 8FB10034 */  lw        $s1, 0x34($sp)
/* BA1EE8 802417B8 8FB00030 */  lw        $s0, 0x30($sp)
/* BA1EEC 802417BC 03E00008 */  jr        $ra
/* BA1EF0 802417C0 27BD0048 */   addiu    $sp, $sp, 0x48
