.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A0_A8D020
/* A8D020 802405A0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A8D024 802405A4 AFB40040 */  sw        $s4, 0x40($sp)
/* A8D028 802405A8 0080A02D */  daddu     $s4, $a0, $zero
/* A8D02C 802405AC AFBF0044 */  sw        $ra, 0x44($sp)
/* A8D030 802405B0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A8D034 802405B4 AFB20038 */  sw        $s2, 0x38($sp)
/* A8D038 802405B8 AFB10034 */  sw        $s1, 0x34($sp)
/* A8D03C 802405BC AFB00030 */  sw        $s0, 0x30($sp)
/* A8D040 802405C0 8E910148 */  lw        $s1, 0x148($s4)
/* A8D044 802405C4 00A0902D */  daddu     $s2, $a1, $zero
/* A8D048 802405C8 86240008 */  lh        $a0, 8($s1)
/* A8D04C 802405CC 0C00EABB */  jal       get_npc_unsafe
/* A8D050 802405D0 00C0982D */   daddu    $s3, $a2, $zero
/* A8D054 802405D4 8E430014 */  lw        $v1, 0x14($s2)
/* A8D058 802405D8 04600031 */  bltz      $v1, .L802406A0
/* A8D05C 802405DC 0040802D */   daddu    $s0, $v0, $zero
/* A8D060 802405E0 0260202D */  daddu     $a0, $s3, $zero
/* A8D064 802405E4 AFA00010 */  sw        $zero, 0x10($sp)
/* A8D068 802405E8 8E460024 */  lw        $a2, 0x24($s2)
/* A8D06C 802405EC 8E470028 */  lw        $a3, 0x28($s2)
/* A8D070 802405F0 0C01242D */  jal       func_800490B4
/* A8D074 802405F4 0220282D */   daddu    $a1, $s1, $zero
/* A8D078 802405F8 10400029 */  beqz      $v0, .L802406A0
/* A8D07C 802405FC 0000202D */   daddu    $a0, $zero, $zero
/* A8D080 80240600 0200282D */  daddu     $a1, $s0, $zero
/* A8D084 80240604 0000302D */  daddu     $a2, $zero, $zero
/* A8D088 80240608 860300A8 */  lh        $v1, 0xa8($s0)
/* A8D08C 8024060C 3C013F80 */  lui       $at, 0x3f80
/* A8D090 80240610 44810000 */  mtc1      $at, $f0
/* A8D094 80240614 3C014000 */  lui       $at, 0x4000
/* A8D098 80240618 44811000 */  mtc1      $at, $f2
/* A8D09C 8024061C 3C01C1A0 */  lui       $at, 0xc1a0
/* A8D0A0 80240620 44812000 */  mtc1      $at, $f4
/* A8D0A4 80240624 2402000F */  addiu     $v0, $zero, 0xf
/* A8D0A8 80240628 AFA2001C */  sw        $v0, 0x1c($sp)
/* A8D0AC 8024062C 44833000 */  mtc1      $v1, $f6
/* A8D0B0 80240630 00000000 */  nop       
/* A8D0B4 80240634 468031A0 */  cvt.s.w   $f6, $f6
/* A8D0B8 80240638 44073000 */  mfc1      $a3, $f6
/* A8D0BC 8024063C 27A20028 */  addiu     $v0, $sp, 0x28
/* A8D0C0 80240640 AFA20020 */  sw        $v0, 0x20($sp)
/* A8D0C4 80240644 E7A00010 */  swc1      $f0, 0x10($sp)
/* A8D0C8 80240648 E7A20014 */  swc1      $f2, 0x14($sp)
/* A8D0CC 8024064C 0C01BFA4 */  jal       fx_emote
/* A8D0D0 80240650 E7A40018 */   swc1     $f4, 0x18($sp)
/* A8D0D4 80240654 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A8D0D8 80240658 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A8D0DC 8024065C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A8D0E0 80240660 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A8D0E4 80240664 8C460028 */  lw        $a2, 0x28($v0)
/* A8D0E8 80240668 0C00A720 */  jal       atan2
/* A8D0EC 8024066C 8C470030 */   lw       $a3, 0x30($v0)
/* A8D0F0 80240670 0200202D */  daddu     $a0, $s0, $zero
/* A8D0F4 80240674 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A8D0F8 80240678 3C060020 */  lui       $a2, 0x20
/* A8D0FC 8024067C 0C012530 */  jal       func_800494C0
/* A8D100 80240680 E480000C */   swc1     $f0, 0xc($a0)
/* A8D104 80240684 8E220018 */  lw        $v0, 0x18($s1)
/* A8D108 80240688 9442002A */  lhu       $v0, 0x2a($v0)
/* A8D10C 8024068C 30420001 */  andi      $v0, $v0, 1
/* A8D110 80240690 14400029 */  bnez      $v0, .L80240738
/* A8D114 80240694 2402000A */   addiu    $v0, $zero, 0xa
/* A8D118 80240698 080901CE */  j         .L80240738
/* A8D11C 8024069C 2402000C */   addiu    $v0, $zero, 0xc
.L802406A0:
/* A8D120 802406A0 8602008C */  lh        $v0, 0x8c($s0)
/* A8D124 802406A4 14400025 */  bnez      $v0, .L8024073C
/* A8D128 802406A8 00000000 */   nop      
/* A8D12C 802406AC 9602008E */  lhu       $v0, 0x8e($s0)
/* A8D130 802406B0 2442FFFF */  addiu     $v0, $v0, -1
/* A8D134 802406B4 A602008E */  sh        $v0, 0x8e($s0)
/* A8D138 802406B8 00021400 */  sll       $v0, $v0, 0x10
/* A8D13C 802406BC 1440001F */  bnez      $v0, .L8024073C
/* A8D140 802406C0 00000000 */   nop      
/* A8D144 802406C4 8E820074 */  lw        $v0, 0x74($s4)
/* A8D148 802406C8 2442FFFF */  addiu     $v0, $v0, -1
/* A8D14C 802406CC 10400019 */  beqz      $v0, .L80240734
/* A8D150 802406D0 AE820074 */   sw       $v0, 0x74($s4)
/* A8D154 802406D4 8E220018 */  lw        $v0, 0x18($s1)
/* A8D158 802406D8 9442002A */  lhu       $v0, 0x2a($v0)
/* A8D15C 802406DC 30420010 */  andi      $v0, $v0, 0x10
/* A8D160 802406E0 14400007 */  bnez      $v0, .L80240700
/* A8D164 802406E4 00000000 */   nop      
/* A8D168 802406E8 C600000C */  lwc1      $f0, 0xc($s0)
/* A8D16C 802406EC 3C014334 */  lui       $at, 0x4334
/* A8D170 802406F0 44816000 */  mtc1      $at, $f12
/* A8D174 802406F4 0C00A6C9 */  jal       clamp_angle
/* A8D178 802406F8 460C0300 */   add.s    $f12, $f0, $f12
/* A8D17C 802406FC E600000C */  swc1      $f0, 0xc($s0)
.L80240700:
/* A8D180 80240700 8E440008 */  lw        $a0, 8($s2)
/* A8D184 80240704 000417C2 */  srl       $v0, $a0, 0x1f
/* A8D188 80240708 00822021 */  addu      $a0, $a0, $v0
/* A8D18C 8024070C 00042043 */  sra       $a0, $a0, 1
/* A8D190 80240710 0C00A67F */  jal       rand_int
/* A8D194 80240714 24840001 */   addiu    $a0, $a0, 1
/* A8D198 80240718 8E430008 */  lw        $v1, 8($s2)
/* A8D19C 8024071C 000327C2 */  srl       $a0, $v1, 0x1f
/* A8D1A0 80240720 00641821 */  addu      $v1, $v1, $a0
/* A8D1A4 80240724 00031843 */  sra       $v1, $v1, 1
/* A8D1A8 80240728 00621821 */  addu      $v1, $v1, $v0
/* A8D1AC 8024072C 080901CF */  j         .L8024073C
/* A8D1B0 80240730 A603008E */   sh       $v1, 0x8e($s0)
.L80240734:
/* A8D1B4 80240734 24020004 */  addiu     $v0, $zero, 4
.L80240738:
/* A8D1B8 80240738 AE820070 */  sw        $v0, 0x70($s4)
.L8024073C:
/* A8D1BC 8024073C 8FBF0044 */  lw        $ra, 0x44($sp)
/* A8D1C0 80240740 8FB40040 */  lw        $s4, 0x40($sp)
/* A8D1C4 80240744 8FB3003C */  lw        $s3, 0x3c($sp)
/* A8D1C8 80240748 8FB20038 */  lw        $s2, 0x38($sp)
/* A8D1CC 8024074C 8FB10034 */  lw        $s1, 0x34($sp)
/* A8D1D0 80240750 8FB00030 */  lw        $s0, 0x30($sp)
/* A8D1D4 80240754 03E00008 */  jr        $ra
/* A8D1D8 80240758 27BD0048 */   addiu    $sp, $sp, 0x48
