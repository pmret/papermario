.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242618_C73A98
/* C73A98 80242618 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C73A9C 8024261C AFB10034 */  sw        $s1, 0x34($sp)
/* C73AA0 80242620 0080882D */  daddu     $s1, $a0, $zero
/* C73AA4 80242624 AFBF0038 */  sw        $ra, 0x38($sp)
/* C73AA8 80242628 AFB00030 */  sw        $s0, 0x30($sp)
/* C73AAC 8024262C 8E300148 */  lw        $s0, 0x148($s1)
/* C73AB0 80242630 0C00EABB */  jal       get_npc_unsafe
/* C73AB4 80242634 86040008 */   lh       $a0, 8($s0)
/* C73AB8 80242638 0040282D */  daddu     $a1, $v0, $zero
/* C73ABC 8024263C 94A2008E */  lhu       $v0, 0x8e($a1)
/* C73AC0 80242640 2442FFFF */  addiu     $v0, $v0, -1
/* C73AC4 80242644 A4A2008E */  sh        $v0, 0x8e($a1)
/* C73AC8 80242648 00021400 */  sll       $v0, $v0, 0x10
/* C73ACC 8024264C 1C400023 */  bgtz      $v0, .L802426DC
/* C73AD0 80242650 24020004 */   addiu    $v0, $zero, 4
/* C73AD4 80242654 8E0300CC */  lw        $v1, 0xcc($s0)
/* C73AD8 80242658 AE02006C */  sw        $v0, 0x6c($s0)
/* C73ADC 8024265C 8C620000 */  lw        $v0, ($v1)
/* C73AE0 80242660 ACA20028 */  sw        $v0, 0x28($a1)
/* C73AE4 80242664 9602007A */  lhu       $v0, 0x7a($s0)
/* C73AE8 80242668 A4A2008E */  sh        $v0, 0x8e($a1)
/* C73AEC 8024266C 8E020078 */  lw        $v0, 0x78($s0)
/* C73AF0 80242670 28420008 */  slti      $v0, $v0, 8
/* C73AF4 80242674 14400018 */  bnez      $v0, .L802426D8
/* C73AF8 80242678 24020021 */   addiu    $v0, $zero, 0x21
/* C73AFC 8024267C 24040003 */  addiu     $a0, $zero, 3
/* C73B00 80242680 27A30028 */  addiu     $v1, $sp, 0x28
/* C73B04 80242684 84A700A8 */  lh        $a3, 0xa8($a1)
/* C73B08 80242688 3C013F80 */  lui       $at, 0x3f80
/* C73B0C 8024268C 44810000 */  mtc1      $at, $f0
/* C73B10 80242690 3C014000 */  lui       $at, 0x4000
/* C73B14 80242694 44811000 */  mtc1      $at, $f2
/* C73B18 80242698 3C01C1A0 */  lui       $at, 0xc1a0
/* C73B1C 8024269C 44812000 */  mtc1      $at, $f4
/* C73B20 802426A0 44873000 */  mtc1      $a3, $f6
/* C73B24 802426A4 00000000 */  nop       
/* C73B28 802426A8 468031A0 */  cvt.s.w   $f6, $f6
/* C73B2C 802426AC E7A00010 */  swc1      $f0, 0x10($sp)
/* C73B30 802426B0 E7A20014 */  swc1      $f2, 0x14($sp)
/* C73B34 802426B4 E7A40018 */  swc1      $f4, 0x18($sp)
/* C73B38 802426B8 8E020078 */  lw        $v0, 0x78($s0)
/* C73B3C 802426BC 44073000 */  mfc1      $a3, $f6
/* C73B40 802426C0 0000302D */  daddu     $a2, $zero, $zero
/* C73B44 802426C4 AFA30020 */  sw        $v1, 0x20($sp)
/* C73B48 802426C8 2442FFFF */  addiu     $v0, $v0, -1
/* C73B4C 802426CC 0C01BFA4 */  jal       fx_emote
/* C73B50 802426D0 AFA2001C */   sw       $v0, 0x1c($sp)
/* C73B54 802426D4 24020021 */  addiu     $v0, $zero, 0x21
.L802426D8:
/* C73B58 802426D8 AE220070 */  sw        $v0, 0x70($s1)
.L802426DC:
/* C73B5C 802426DC 8FBF0038 */  lw        $ra, 0x38($sp)
/* C73B60 802426E0 8FB10034 */  lw        $s1, 0x34($sp)
/* C73B64 802426E4 8FB00030 */  lw        $s0, 0x30($sp)
/* C73B68 802426E8 03E00008 */  jr        $ra
/* C73B6C 802426EC 27BD0040 */   addiu    $sp, $sp, 0x40
