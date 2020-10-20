.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405DC_B93A1C
/* B93A1C 802405DC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B93A20 802405E0 AFB10034 */  sw        $s1, 0x34($sp)
/* B93A24 802405E4 0080882D */  daddu     $s1, $a0, $zero
/* B93A28 802405E8 AFBF0038 */  sw        $ra, 0x38($sp)
/* B93A2C 802405EC AFB00030 */  sw        $s0, 0x30($sp)
/* B93A30 802405F0 8E300148 */  lw        $s0, 0x148($s1)
/* B93A34 802405F4 0C00EABB */  jal       get_npc_unsafe
/* B93A38 802405F8 86040008 */   lh       $a0, 8($s0)
/* B93A3C 802405FC 0040282D */  daddu     $a1, $v0, $zero
/* B93A40 80240600 94A2008E */  lhu       $v0, 0x8e($a1)
/* B93A44 80240604 2442FFFF */  addiu     $v0, $v0, -1
/* B93A48 80240608 A4A2008E */  sh        $v0, 0x8e($a1)
/* B93A4C 8024060C 00021400 */  sll       $v0, $v0, 0x10
/* B93A50 80240610 1C400023 */  bgtz      $v0, .L802406A0
/* B93A54 80240614 24020004 */   addiu    $v0, $zero, 4
/* B93A58 80240618 8E0300CC */  lw        $v1, 0xcc($s0)
/* B93A5C 8024061C AE02006C */  sw        $v0, 0x6c($s0)
/* B93A60 80240620 8C620000 */  lw        $v0, ($v1)
/* B93A64 80240624 ACA20028 */  sw        $v0, 0x28($a1)
/* B93A68 80240628 9602007A */  lhu       $v0, 0x7a($s0)
/* B93A6C 8024062C A4A2008E */  sh        $v0, 0x8e($a1)
/* B93A70 80240630 8E020078 */  lw        $v0, 0x78($s0)
/* B93A74 80240634 28420008 */  slti      $v0, $v0, 8
/* B93A78 80240638 14400018 */  bnez      $v0, .L8024069C
/* B93A7C 8024063C 24020021 */   addiu    $v0, $zero, 0x21
/* B93A80 80240640 24040003 */  addiu     $a0, $zero, 3
/* B93A84 80240644 27A30028 */  addiu     $v1, $sp, 0x28
/* B93A88 80240648 84A700A8 */  lh        $a3, 0xa8($a1)
/* B93A8C 8024064C 3C013F80 */  lui       $at, 0x3f80
/* B93A90 80240650 44810000 */  mtc1      $at, $f0
/* B93A94 80240654 3C014000 */  lui       $at, 0x4000
/* B93A98 80240658 44811000 */  mtc1      $at, $f2
/* B93A9C 8024065C 3C01C1A0 */  lui       $at, 0xc1a0
/* B93AA0 80240660 44812000 */  mtc1      $at, $f4
/* B93AA4 80240664 44873000 */  mtc1      $a3, $f6
/* B93AA8 80240668 00000000 */  nop       
/* B93AAC 8024066C 468031A0 */  cvt.s.w   $f6, $f6
/* B93AB0 80240670 E7A00010 */  swc1      $f0, 0x10($sp)
/* B93AB4 80240674 E7A20014 */  swc1      $f2, 0x14($sp)
/* B93AB8 80240678 E7A40018 */  swc1      $f4, 0x18($sp)
/* B93ABC 8024067C 8E020078 */  lw        $v0, 0x78($s0)
/* B93AC0 80240680 44073000 */  mfc1      $a3, $f6
/* B93AC4 80240684 0000302D */  daddu     $a2, $zero, $zero
/* B93AC8 80240688 AFA30020 */  sw        $v1, 0x20($sp)
/* B93ACC 8024068C 2442FFFF */  addiu     $v0, $v0, -1
/* B93AD0 80240690 0C01BFA4 */  jal       fx_emote
/* B93AD4 80240694 AFA2001C */   sw       $v0, 0x1c($sp)
/* B93AD8 80240698 24020021 */  addiu     $v0, $zero, 0x21
.L8024069C:
/* B93ADC 8024069C AE220070 */  sw        $v0, 0x70($s1)
.L802406A0:
/* B93AE0 802406A0 8FBF0038 */  lw        $ra, 0x38($sp)
/* B93AE4 802406A4 8FB10034 */  lw        $s1, 0x34($sp)
/* B93AE8 802406A8 8FB00030 */  lw        $s0, 0x30($sp)
/* B93AEC 802406AC 03E00008 */  jr        $ra
/* B93AF0 802406B0 27BD0040 */   addiu    $sp, $sp, 0x40
