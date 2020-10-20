.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240570_ABB800
/* ABB800 80240570 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* ABB804 80240574 AFB40040 */  sw        $s4, 0x40($sp)
/* ABB808 80240578 0080A02D */  daddu     $s4, $a0, $zero
/* ABB80C 8024057C AFBF0044 */  sw        $ra, 0x44($sp)
/* ABB810 80240580 AFB3003C */  sw        $s3, 0x3c($sp)
/* ABB814 80240584 AFB20038 */  sw        $s2, 0x38($sp)
/* ABB818 80240588 AFB10034 */  sw        $s1, 0x34($sp)
/* ABB81C 8024058C AFB00030 */  sw        $s0, 0x30($sp)
/* ABB820 80240590 8E910148 */  lw        $s1, 0x148($s4)
/* ABB824 80240594 00A0902D */  daddu     $s2, $a1, $zero
/* ABB828 80240598 86240008 */  lh        $a0, 8($s1)
/* ABB82C 8024059C 0C00EABB */  jal       get_npc_unsafe
/* ABB830 802405A0 00C0982D */   daddu    $s3, $a2, $zero
/* ABB834 802405A4 8E430014 */  lw        $v1, 0x14($s2)
/* ABB838 802405A8 04600031 */  bltz      $v1, .L80240670
/* ABB83C 802405AC 0040802D */   daddu    $s0, $v0, $zero
/* ABB840 802405B0 0260202D */  daddu     $a0, $s3, $zero
/* ABB844 802405B4 AFA00010 */  sw        $zero, 0x10($sp)
/* ABB848 802405B8 8E460024 */  lw        $a2, 0x24($s2)
/* ABB84C 802405BC 8E470028 */  lw        $a3, 0x28($s2)
/* ABB850 802405C0 0C01242D */  jal       func_800490B4
/* ABB854 802405C4 0220282D */   daddu    $a1, $s1, $zero
/* ABB858 802405C8 10400029 */  beqz      $v0, .L80240670
/* ABB85C 802405CC 0000202D */   daddu    $a0, $zero, $zero
/* ABB860 802405D0 0200282D */  daddu     $a1, $s0, $zero
/* ABB864 802405D4 0000302D */  daddu     $a2, $zero, $zero
/* ABB868 802405D8 860300A8 */  lh        $v1, 0xa8($s0)
/* ABB86C 802405DC 3C013F80 */  lui       $at, 0x3f80
/* ABB870 802405E0 44810000 */  mtc1      $at, $f0
/* ABB874 802405E4 3C014000 */  lui       $at, 0x4000
/* ABB878 802405E8 44811000 */  mtc1      $at, $f2
/* ABB87C 802405EC 3C01C1A0 */  lui       $at, 0xc1a0
/* ABB880 802405F0 44812000 */  mtc1      $at, $f4
/* ABB884 802405F4 2402000F */  addiu     $v0, $zero, 0xf
/* ABB888 802405F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* ABB88C 802405FC 44833000 */  mtc1      $v1, $f6
/* ABB890 80240600 00000000 */  nop       
/* ABB894 80240604 468031A0 */  cvt.s.w   $f6, $f6
/* ABB898 80240608 44073000 */  mfc1      $a3, $f6
/* ABB89C 8024060C 27A20028 */  addiu     $v0, $sp, 0x28
/* ABB8A0 80240610 AFA20020 */  sw        $v0, 0x20($sp)
/* ABB8A4 80240614 E7A00010 */  swc1      $f0, 0x10($sp)
/* ABB8A8 80240618 E7A20014 */  swc1      $f2, 0x14($sp)
/* ABB8AC 8024061C 0C01BFA4 */  jal       fx_emote
/* ABB8B0 80240620 E7A40018 */   swc1     $f4, 0x18($sp)
/* ABB8B4 80240624 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* ABB8B8 80240628 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* ABB8BC 8024062C C60C0038 */  lwc1      $f12, 0x38($s0)
/* ABB8C0 80240630 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ABB8C4 80240634 8C460028 */  lw        $a2, 0x28($v0)
/* ABB8C8 80240638 0C00A720 */  jal       atan2
/* ABB8CC 8024063C 8C470030 */   lw       $a3, 0x30($v0)
/* ABB8D0 80240640 0200202D */  daddu     $a0, $s0, $zero
/* ABB8D4 80240644 240502F4 */  addiu     $a1, $zero, 0x2f4
/* ABB8D8 80240648 3C060020 */  lui       $a2, 0x20
/* ABB8DC 8024064C 0C012530 */  jal       func_800494C0
/* ABB8E0 80240650 E480000C */   swc1     $f0, 0xc($a0)
/* ABB8E4 80240654 8E220018 */  lw        $v0, 0x18($s1)
/* ABB8E8 80240658 9442002A */  lhu       $v0, 0x2a($v0)
/* ABB8EC 8024065C 30420001 */  andi      $v0, $v0, 1
/* ABB8F0 80240660 14400029 */  bnez      $v0, .L80240708
/* ABB8F4 80240664 2402000A */   addiu    $v0, $zero, 0xa
/* ABB8F8 80240668 080901C2 */  j         .L80240708
/* ABB8FC 8024066C 2402000C */   addiu    $v0, $zero, 0xc
.L80240670:
/* ABB900 80240670 8602008C */  lh        $v0, 0x8c($s0)
/* ABB904 80240674 14400025 */  bnez      $v0, .L8024070C
/* ABB908 80240678 00000000 */   nop      
/* ABB90C 8024067C 9602008E */  lhu       $v0, 0x8e($s0)
/* ABB910 80240680 2442FFFF */  addiu     $v0, $v0, -1
/* ABB914 80240684 A602008E */  sh        $v0, 0x8e($s0)
/* ABB918 80240688 00021400 */  sll       $v0, $v0, 0x10
/* ABB91C 8024068C 1440001F */  bnez      $v0, .L8024070C
/* ABB920 80240690 00000000 */   nop      
/* ABB924 80240694 8E820074 */  lw        $v0, 0x74($s4)
/* ABB928 80240698 2442FFFF */  addiu     $v0, $v0, -1
/* ABB92C 8024069C 10400019 */  beqz      $v0, .L80240704
/* ABB930 802406A0 AE820074 */   sw       $v0, 0x74($s4)
/* ABB934 802406A4 8E220018 */  lw        $v0, 0x18($s1)
/* ABB938 802406A8 9442002A */  lhu       $v0, 0x2a($v0)
/* ABB93C 802406AC 30420010 */  andi      $v0, $v0, 0x10
/* ABB940 802406B0 14400007 */  bnez      $v0, .L802406D0
/* ABB944 802406B4 00000000 */   nop      
/* ABB948 802406B8 C600000C */  lwc1      $f0, 0xc($s0)
/* ABB94C 802406BC 3C014334 */  lui       $at, 0x4334
/* ABB950 802406C0 44816000 */  mtc1      $at, $f12
/* ABB954 802406C4 0C00A6C9 */  jal       clamp_angle
/* ABB958 802406C8 460C0300 */   add.s    $f12, $f0, $f12
/* ABB95C 802406CC E600000C */  swc1      $f0, 0xc($s0)
.L802406D0:
/* ABB960 802406D0 8E440008 */  lw        $a0, 8($s2)
/* ABB964 802406D4 000417C2 */  srl       $v0, $a0, 0x1f
/* ABB968 802406D8 00822021 */  addu      $a0, $a0, $v0
/* ABB96C 802406DC 00042043 */  sra       $a0, $a0, 1
/* ABB970 802406E0 0C00A67F */  jal       rand_int
/* ABB974 802406E4 24840001 */   addiu    $a0, $a0, 1
/* ABB978 802406E8 8E430008 */  lw        $v1, 8($s2)
/* ABB97C 802406EC 000327C2 */  srl       $a0, $v1, 0x1f
/* ABB980 802406F0 00641821 */  addu      $v1, $v1, $a0
/* ABB984 802406F4 00031843 */  sra       $v1, $v1, 1
/* ABB988 802406F8 00621821 */  addu      $v1, $v1, $v0
/* ABB98C 802406FC 080901C3 */  j         .L8024070C
/* ABB990 80240700 A603008E */   sh       $v1, 0x8e($s0)
.L80240704:
/* ABB994 80240704 24020004 */  addiu     $v0, $zero, 4
.L80240708:
/* ABB998 80240708 AE820070 */  sw        $v0, 0x70($s4)
.L8024070C:
/* ABB99C 8024070C 8FBF0044 */  lw        $ra, 0x44($sp)
/* ABB9A0 80240710 8FB40040 */  lw        $s4, 0x40($sp)
/* ABB9A4 80240714 8FB3003C */  lw        $s3, 0x3c($sp)
/* ABB9A8 80240718 8FB20038 */  lw        $s2, 0x38($sp)
/* ABB9AC 8024071C 8FB10034 */  lw        $s1, 0x34($sp)
/* ABB9B0 80240720 8FB00030 */  lw        $s0, 0x30($sp)
/* ABB9B4 80240724 03E00008 */  jr        $ra
/* ABB9B8 80240728 27BD0048 */   addiu    $sp, $sp, 0x48
