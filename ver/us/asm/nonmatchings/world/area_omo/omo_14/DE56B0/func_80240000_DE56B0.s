.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DE56B0
/* DE56B0 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DE56B4 80240004 AFB00018 */  sw        $s0, 0x18($sp)
/* DE56B8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* DE56BC 8024000C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* DE56C0 80240010 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* DE56C4 80240014 AFB1001C */  sw        $s1, 0x1c($sp)
/* DE56C8 80240018 3C118011 */  lui       $s1, %hi(gPlayerData)
/* DE56CC 8024001C 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* DE56D0 80240020 AFB20020 */  sw        $s2, 0x20($sp)
/* DE56D4 80240024 0220902D */  daddu     $s2, $s1, $zero
/* DE56D8 80240028 10A00004 */  beqz      $a1, .L8024003C
/* DE56DC 8024002C AFBF0024 */   sw       $ra, 0x24($sp)
/* DE56E0 80240030 240200FF */  addiu     $v0, $zero, 0xff
/* DE56E4 80240034 AE020070 */  sw        $v0, 0x70($s0)
/* DE56E8 80240038 AE000074 */  sw        $zero, 0x74($s0)
.L8024003C:
/* DE56EC 8024003C 24040001 */  addiu     $a0, $zero, 1
/* DE56F0 80240040 C460002C */  lwc1      $f0, 0x2c($v1)
/* DE56F4 80240044 3C014100 */  lui       $at, 0x4100
/* DE56F8 80240048 44811000 */  mtc1      $at, $f2
/* DE56FC 8024004C 00000000 */  nop
/* DE5700 80240050 46020000 */  add.s     $f0, $f0, $f2
/* DE5704 80240054 C4620030 */  lwc1      $f2, 0x30($v1)
/* DE5708 80240058 C4640028 */  lwc1      $f4, 0x28($v1)
/* DE570C 8024005C 4600118D */  trunc.w.s $f6, $f2
/* DE5710 80240060 E7A60010 */  swc1      $f6, 0x10($sp)
/* DE5714 80240064 4600218D */  trunc.w.s $f6, $f4
/* DE5718 80240068 44063000 */  mfc1      $a2, $f6
/* DE571C 8024006C 4600018D */  trunc.w.s $f6, $f0
/* DE5720 80240070 44073000 */  mfc1      $a3, $f6
/* DE5724 80240074 0C04DFB0 */  jal       set_screen_overlay_center_worldpos
/* DE5728 80240078 0080282D */   daddu    $a1, $a0, $zero
/* DE572C 8024007C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* DE5730 80240080 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* DE5734 80240084 10400012 */  beqz      $v0, .L802400D0
/* DE5738 80240088 24020006 */   addiu    $v0, $zero, 6
/* DE573C 8024008C 82230012 */  lb        $v1, 0x12($s1)
/* DE5740 80240090 14620022 */  bne       $v1, $v0, .L8024011C
/* DE5744 80240094 00000000 */   nop
/* DE5748 80240098 8E020074 */  lw        $v0, 0x74($s0)
/* DE574C 8024009C 14400004 */  bnez      $v0, .L802400B0
/* DE5750 802400A0 24020001 */   addiu    $v0, $zero, 1
/* DE5754 802400A4 AE020074 */  sw        $v0, 0x74($s0)
/* DE5758 802400A8 0C05272D */  jal       sfx_play_sound
/* DE575C 802400AC 24042011 */   addiu    $a0, $zero, 0x2011
.L802400B0:
/* DE5760 802400B0 8E020070 */  lw        $v0, 0x70($s0)
/* DE5764 802400B4 2442FFF8 */  addiu     $v0, $v0, -8
/* DE5768 802400B8 AE020070 */  sw        $v0, 0x70($s0)
/* DE576C 802400BC 2842005A */  slti      $v0, $v0, 0x5a
/* DE5770 802400C0 10400016 */  beqz      $v0, .L8024011C
/* DE5774 802400C4 2402005A */   addiu    $v0, $zero, 0x5a
/* DE5778 802400C8 08090047 */  j         .L8024011C
/* DE577C 802400CC AE020070 */   sw       $v0, 0x70($s0)
.L802400D0:
/* DE5780 802400D0 82430012 */  lb        $v1, 0x12($s2)
/* DE5784 802400D4 14620010 */  bne       $v1, $v0, .L80240118
/* DE5788 802400D8 240200FF */   addiu    $v0, $zero, 0xff
/* DE578C 802400DC 8E020074 */  lw        $v0, 0x74($s0)
/* DE5790 802400E0 10400007 */  beqz      $v0, .L80240100
/* DE5794 802400E4 00000000 */   nop
/* DE5798 802400E8 8E020070 */  lw        $v0, 0x70($s0)
/* DE579C 802400EC 284200FF */  slti      $v0, $v0, 0xff
/* DE57A0 802400F0 10400003 */  beqz      $v0, .L80240100
/* DE57A4 802400F4 AE000074 */   sw       $zero, 0x74($s0)
/* DE57A8 802400F8 0C05272D */  jal       sfx_play_sound
/* DE57AC 802400FC 24042012 */   addiu    $a0, $zero, 0x2012
.L80240100:
/* DE57B0 80240100 8E020070 */  lw        $v0, 0x70($s0)
/* DE57B4 80240104 24420008 */  addiu     $v0, $v0, 8
/* DE57B8 80240108 AE020070 */  sw        $v0, 0x70($s0)
/* DE57BC 8024010C 284200FF */  slti      $v0, $v0, 0xff
/* DE57C0 80240110 14400002 */  bnez      $v0, .L8024011C
/* DE57C4 80240114 240200FF */   addiu    $v0, $zero, 0xff
.L80240118:
/* DE57C8 80240118 AE020070 */  sw        $v0, 0x70($s0)
.L8024011C:
/* DE57CC 8024011C C6060070 */  lwc1      $f6, 0x70($s0)
/* DE57D0 80240120 468031A0 */  cvt.s.w   $f6, $f6
/* DE57D4 80240124 44053000 */  mfc1      $a1, $f6
/* DE57D8 80240128 0C04E035 */  jal       set_screen_overlay_alpha
/* DE57DC 8024012C 24040001 */   addiu    $a0, $zero, 1
/* DE57E0 80240130 3C05437F */  lui       $a1, 0x437f
/* DE57E4 80240134 0C04DF69 */  jal       set_screen_overlay_params_back
/* DE57E8 80240138 2404000B */   addiu    $a0, $zero, 0xb
/* DE57EC 8024013C 8FBF0024 */  lw        $ra, 0x24($sp)
/* DE57F0 80240140 8FB20020 */  lw        $s2, 0x20($sp)
/* DE57F4 80240144 8FB1001C */  lw        $s1, 0x1c($sp)
/* DE57F8 80240148 8FB00018 */  lw        $s0, 0x18($sp)
/* DE57FC 8024014C 0000102D */  daddu     $v0, $zero, $zero
/* DE5800 80240150 03E00008 */  jr        $ra
/* DE5804 80240154 27BD0028 */   addiu    $sp, $sp, 0x28
/* DE5808 80240158 00000000 */  nop
/* DE580C 8024015C 00000000 */  nop
