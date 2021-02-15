.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C0_AC5630
/* AC5630 802404C0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AC5634 802404C4 AFB40040 */  sw        $s4, 0x40($sp)
/* AC5638 802404C8 0080A02D */  daddu     $s4, $a0, $zero
/* AC563C 802404CC AFBF0044 */  sw        $ra, 0x44($sp)
/* AC5640 802404D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* AC5644 802404D4 AFB20038 */  sw        $s2, 0x38($sp)
/* AC5648 802404D8 AFB10034 */  sw        $s1, 0x34($sp)
/* AC564C 802404DC AFB00030 */  sw        $s0, 0x30($sp)
/* AC5650 802404E0 8E910148 */  lw        $s1, 0x148($s4)
/* AC5654 802404E4 00A0902D */  daddu     $s2, $a1, $zero
/* AC5658 802404E8 86240008 */  lh        $a0, 8($s1)
/* AC565C 802404EC 0C00EABB */  jal       get_npc_unsafe
/* AC5660 802404F0 00C0982D */   daddu    $s3, $a2, $zero
/* AC5664 802404F4 8E430014 */  lw        $v1, 0x14($s2)
/* AC5668 802404F8 04600031 */  bltz      $v1, .L802405C0
/* AC566C 802404FC 0040802D */   daddu    $s0, $v0, $zero
/* AC5670 80240500 0260202D */  daddu     $a0, $s3, $zero
/* AC5674 80240504 AFA00010 */  sw        $zero, 0x10($sp)
/* AC5678 80240508 8E460024 */  lw        $a2, 0x24($s2)
/* AC567C 8024050C 8E470028 */  lw        $a3, 0x28($s2)
/* AC5680 80240510 0C01242D */  jal       func_800490B4
/* AC5684 80240514 0220282D */   daddu    $a1, $s1, $zero
/* AC5688 80240518 10400029 */  beqz      $v0, .L802405C0
/* AC568C 8024051C 0000202D */   daddu    $a0, $zero, $zero
/* AC5690 80240520 0200282D */  daddu     $a1, $s0, $zero
/* AC5694 80240524 0000302D */  daddu     $a2, $zero, $zero
/* AC5698 80240528 860300A8 */  lh        $v1, 0xa8($s0)
/* AC569C 8024052C 3C013F80 */  lui       $at, 0x3f80
/* AC56A0 80240530 44810000 */  mtc1      $at, $f0
/* AC56A4 80240534 3C014000 */  lui       $at, 0x4000
/* AC56A8 80240538 44811000 */  mtc1      $at, $f2
/* AC56AC 8024053C 3C01C1A0 */  lui       $at, 0xc1a0
/* AC56B0 80240540 44812000 */  mtc1      $at, $f4
/* AC56B4 80240544 2402000F */  addiu     $v0, $zero, 0xf
/* AC56B8 80240548 AFA2001C */  sw        $v0, 0x1c($sp)
/* AC56BC 8024054C 44833000 */  mtc1      $v1, $f6
/* AC56C0 80240550 00000000 */  nop
/* AC56C4 80240554 468031A0 */  cvt.s.w   $f6, $f6
/* AC56C8 80240558 44073000 */  mfc1      $a3, $f6
/* AC56CC 8024055C 27A20028 */  addiu     $v0, $sp, 0x28
/* AC56D0 80240560 AFA20020 */  sw        $v0, 0x20($sp)
/* AC56D4 80240564 E7A00010 */  swc1      $f0, 0x10($sp)
/* AC56D8 80240568 E7A20014 */  swc1      $f2, 0x14($sp)
/* AC56DC 8024056C 0C01BFA4 */  jal       fx_emote
/* AC56E0 80240570 E7A40018 */   swc1     $f4, 0x18($sp)
/* AC56E4 80240574 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* AC56E8 80240578 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* AC56EC 8024057C C60C0038 */  lwc1      $f12, 0x38($s0)
/* AC56F0 80240580 C60E0040 */  lwc1      $f14, 0x40($s0)
/* AC56F4 80240584 8C460028 */  lw        $a2, 0x28($v0)
/* AC56F8 80240588 0C00A720 */  jal       atan2
/* AC56FC 8024058C 8C470030 */   lw       $a3, 0x30($v0)
/* AC5700 80240590 0200202D */  daddu     $a0, $s0, $zero
/* AC5704 80240594 240502F4 */  addiu     $a1, $zero, 0x2f4
/* AC5708 80240598 3C060020 */  lui       $a2, 0x20
/* AC570C 8024059C 0C012530 */  jal       func_800494C0
/* AC5710 802405A0 E480000C */   swc1     $f0, 0xc($a0)
/* AC5714 802405A4 8E220018 */  lw        $v0, 0x18($s1)
/* AC5718 802405A8 9442002A */  lhu       $v0, 0x2a($v0)
/* AC571C 802405AC 30420001 */  andi      $v0, $v0, 1
/* AC5720 802405B0 14400029 */  bnez      $v0, .L80240658
/* AC5724 802405B4 2402000A */   addiu    $v0, $zero, 0xa
/* AC5728 802405B8 08090196 */  j         .L80240658
/* AC572C 802405BC 2402000C */   addiu    $v0, $zero, 0xc
.L802405C0:
/* AC5730 802405C0 8602008C */  lh        $v0, 0x8c($s0)
/* AC5734 802405C4 14400025 */  bnez      $v0, .L8024065C
/* AC5738 802405C8 00000000 */   nop
/* AC573C 802405CC 9602008E */  lhu       $v0, 0x8e($s0)
/* AC5740 802405D0 2442FFFF */  addiu     $v0, $v0, -1
/* AC5744 802405D4 A602008E */  sh        $v0, 0x8e($s0)
/* AC5748 802405D8 00021400 */  sll       $v0, $v0, 0x10
/* AC574C 802405DC 1440001F */  bnez      $v0, .L8024065C
/* AC5750 802405E0 00000000 */   nop
/* AC5754 802405E4 8E820074 */  lw        $v0, 0x74($s4)
/* AC5758 802405E8 2442FFFF */  addiu     $v0, $v0, -1
/* AC575C 802405EC 10400019 */  beqz      $v0, .L80240654
/* AC5760 802405F0 AE820074 */   sw       $v0, 0x74($s4)
/* AC5764 802405F4 8E220018 */  lw        $v0, 0x18($s1)
/* AC5768 802405F8 9442002A */  lhu       $v0, 0x2a($v0)
/* AC576C 802405FC 30420010 */  andi      $v0, $v0, 0x10
/* AC5770 80240600 14400007 */  bnez      $v0, .L80240620
/* AC5774 80240604 00000000 */   nop
/* AC5778 80240608 C600000C */  lwc1      $f0, 0xc($s0)
/* AC577C 8024060C 3C014334 */  lui       $at, 0x4334
/* AC5780 80240610 44816000 */  mtc1      $at, $f12
/* AC5784 80240614 0C00A6C9 */  jal       clamp_angle
/* AC5788 80240618 460C0300 */   add.s    $f12, $f0, $f12
/* AC578C 8024061C E600000C */  swc1      $f0, 0xc($s0)
.L80240620:
/* AC5790 80240620 8E440008 */  lw        $a0, 8($s2)
/* AC5794 80240624 000417C2 */  srl       $v0, $a0, 0x1f
/* AC5798 80240628 00822021 */  addu      $a0, $a0, $v0
/* AC579C 8024062C 00042043 */  sra       $a0, $a0, 1
/* AC57A0 80240630 0C00A67F */  jal       rand_int
/* AC57A4 80240634 24840001 */   addiu    $a0, $a0, 1
/* AC57A8 80240638 8E430008 */  lw        $v1, 8($s2)
/* AC57AC 8024063C 000327C2 */  srl       $a0, $v1, 0x1f
/* AC57B0 80240640 00641821 */  addu      $v1, $v1, $a0
/* AC57B4 80240644 00031843 */  sra       $v1, $v1, 1
/* AC57B8 80240648 00621821 */  addu      $v1, $v1, $v0
/* AC57BC 8024064C 08090197 */  j         .L8024065C
/* AC57C0 80240650 A603008E */   sh       $v1, 0x8e($s0)
.L80240654:
/* AC57C4 80240654 24020004 */  addiu     $v0, $zero, 4
.L80240658:
/* AC57C8 80240658 AE820070 */  sw        $v0, 0x70($s4)
.L8024065C:
/* AC57CC 8024065C 8FBF0044 */  lw        $ra, 0x44($sp)
/* AC57D0 80240660 8FB40040 */  lw        $s4, 0x40($sp)
/* AC57D4 80240664 8FB3003C */  lw        $s3, 0x3c($sp)
/* AC57D8 80240668 8FB20038 */  lw        $s2, 0x38($sp)
/* AC57DC 8024066C 8FB10034 */  lw        $s1, 0x34($sp)
/* AC57E0 80240670 8FB00030 */  lw        $s0, 0x30($sp)
/* AC57E4 80240674 03E00008 */  jr        $ra
/* AC57E8 80240678 27BD0048 */   addiu    $sp, $sp, 0x48
