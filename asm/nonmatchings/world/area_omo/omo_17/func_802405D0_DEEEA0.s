.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D0_DEF470
/* DEF470 802405D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DEF474 802405D4 AFB20028 */  sw        $s2, 0x28($sp)
/* DEF478 802405D8 0080902D */  daddu     $s2, $a0, $zero
/* DEF47C 802405DC AFBF002C */  sw        $ra, 0x2c($sp)
/* DEF480 802405E0 AFB10024 */  sw        $s1, 0x24($sp)
/* DEF484 802405E4 AFB00020 */  sw        $s0, 0x20($sp)
/* DEF488 802405E8 8E510148 */  lw        $s1, 0x148($s2)
/* DEF48C 802405EC 0C00EABB */  jal       get_npc_unsafe
/* DEF490 802405F0 86240008 */   lh       $a0, 8($s1)
/* DEF494 802405F4 0040802D */  daddu     $s0, $v0, $zero
/* DEF498 802405F8 0200202D */  daddu     $a0, $s0, $zero
/* DEF49C 802405FC C600000C */  lwc1      $f0, 0xc($s0)
/* DEF4A0 80240600 27A60018 */  addiu     $a2, $sp, 0x18
/* DEF4A4 80240604 E7A00018 */  swc1      $f0, 0x18($sp)
/* DEF4A8 80240608 AFA00010 */  sw        $zero, 0x10($sp)
/* DEF4AC 8024060C AFA00014 */  sw        $zero, 0x14($sp)
/* DEF4B0 80240610 8E050018 */  lw        $a1, 0x18($s0)
/* DEF4B4 80240614 0C0129E1 */  jal       func_8004A784
/* DEF4B8 80240618 0000382D */   daddu    $a3, $zero, $zero
/* DEF4BC 8024061C 14400005 */  bnez      $v0, .L80240634
/* DEF4C0 80240620 00000000 */   nop      
/* DEF4C4 80240624 8E050018 */  lw        $a1, 0x18($s0)
/* DEF4C8 80240628 8E06000C */  lw        $a2, 0xc($s0)
/* DEF4CC 8024062C 0C00EA95 */  jal       npc_move_heading
/* DEF4D0 80240630 0200202D */   daddu    $a0, $s0, $zero
.L80240634:
/* DEF4D4 80240634 9602008E */  lhu       $v0, 0x8e($s0)
/* DEF4D8 80240638 2442FFFF */  addiu     $v0, $v0, -1
/* DEF4DC 8024063C A602008E */  sh        $v0, 0x8e($s0)
/* DEF4E0 80240640 00021400 */  sll       $v0, $v0, 0x10
/* DEF4E4 80240644 14400010 */  bnez      $v0, .L80240688
/* DEF4E8 80240648 00000000 */   nop      
/* DEF4EC 8024064C C6000018 */  lwc1      $f0, 0x18($s0)
/* DEF4F0 80240650 3C018024 */  lui       $at, 0x8024
/* DEF4F4 80240654 D4227618 */  ldc1      $f2, 0x7618($at)
/* DEF4F8 80240658 46000021 */  cvt.d.s   $f0, $f0
/* DEF4FC 8024065C 46220002 */  mul.d     $f0, $f0, $f2
/* DEF500 80240660 00000000 */  nop       
/* DEF504 80240664 46200020 */  cvt.s.d   $f0, $f0
/* DEF508 80240668 E6000018 */  swc1      $f0, 0x18($s0)
/* DEF50C 8024066C 8E2200CC */  lw        $v0, 0xcc($s1)
/* DEF510 80240670 8C43002C */  lw        $v1, 0x2c($v0)
/* DEF514 80240674 2402000A */  addiu     $v0, $zero, 0xa
/* DEF518 80240678 A602008E */  sh        $v0, 0x8e($s0)
/* DEF51C 8024067C 24020010 */  addiu     $v0, $zero, 0x10
/* DEF520 80240680 AE030028 */  sw        $v1, 0x28($s0)
/* DEF524 80240684 AE420070 */  sw        $v0, 0x70($s2)
.L80240688:
/* DEF528 80240688 8FBF002C */  lw        $ra, 0x2c($sp)
/* DEF52C 8024068C 8FB20028 */  lw        $s2, 0x28($sp)
/* DEF530 80240690 8FB10024 */  lw        $s1, 0x24($sp)
/* DEF534 80240694 8FB00020 */  lw        $s0, 0x20($sp)
/* DEF538 80240698 03E00008 */  jr        $ra
/* DEF53C 8024069C 27BD0030 */   addiu    $sp, $sp, 0x30
