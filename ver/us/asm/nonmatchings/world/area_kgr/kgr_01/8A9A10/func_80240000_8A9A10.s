.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8A9A10
/* 8A9A10 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8A9A14 80240004 AFB00018 */  sw        $s0, 0x18($sp)
/* 8A9A18 80240008 0080802D */  daddu     $s0, $a0, $zero
/* 8A9A1C 8024000C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 8A9A20 80240010 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 8A9A24 80240014 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8A9A28 80240018 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 8A9A2C 8024001C 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 8A9A30 80240020 AFB20020 */  sw        $s2, 0x20($sp)
/* 8A9A34 80240024 0220902D */  daddu     $s2, $s1, $zero
/* 8A9A38 80240028 10A00004 */  beqz      $a1, .L8024003C
/* 8A9A3C 8024002C AFBF0024 */   sw       $ra, 0x24($sp)
/* 8A9A40 80240030 240200FF */  addiu     $v0, $zero, 0xff
/* 8A9A44 80240034 AE020070 */  sw        $v0, 0x70($s0)
/* 8A9A48 80240038 AE000074 */  sw        $zero, 0x74($s0)
.L8024003C:
/* 8A9A4C 8024003C 24040001 */  addiu     $a0, $zero, 1
/* 8A9A50 80240040 C460002C */  lwc1      $f0, 0x2c($v1)
/* 8A9A54 80240044 3C014100 */  lui       $at, 0x4100
/* 8A9A58 80240048 44811000 */  mtc1      $at, $f2
/* 8A9A5C 8024004C 00000000 */  nop
/* 8A9A60 80240050 46020000 */  add.s     $f0, $f0, $f2
/* 8A9A64 80240054 C4620030 */  lwc1      $f2, 0x30($v1)
/* 8A9A68 80240058 C4640028 */  lwc1      $f4, 0x28($v1)
/* 8A9A6C 8024005C 4600118D */  trunc.w.s $f6, $f2
/* 8A9A70 80240060 E7A60010 */  swc1      $f6, 0x10($sp)
/* 8A9A74 80240064 4600218D */  trunc.w.s $f6, $f4
/* 8A9A78 80240068 44063000 */  mfc1      $a2, $f6
/* 8A9A7C 8024006C 4600018D */  trunc.w.s $f6, $f0
/* 8A9A80 80240070 44073000 */  mfc1      $a3, $f6
/* 8A9A84 80240074 0C04DFB0 */  jal       set_screen_overlay_center_worldpos
/* 8A9A88 80240078 0080282D */   daddu    $a1, $a0, $zero
/* 8A9A8C 8024007C 3C028011 */  lui       $v0, %hi(gPartnerActionStatus)
/* 8A9A90 80240080 8042EBB0 */  lb        $v0, %lo(gPartnerActionStatus)($v0)
/* 8A9A94 80240084 10400012 */  beqz      $v0, .L802400D0
/* 8A9A98 80240088 24020006 */   addiu    $v0, $zero, 6
/* 8A9A9C 8024008C 82230012 */  lb        $v1, 0x12($s1)
/* 8A9AA0 80240090 14620022 */  bne       $v1, $v0, .L8024011C
/* 8A9AA4 80240094 00000000 */   nop
/* 8A9AA8 80240098 8E020074 */  lw        $v0, 0x74($s0)
/* 8A9AAC 8024009C 14400004 */  bnez      $v0, .L802400B0
/* 8A9AB0 802400A0 24020001 */   addiu    $v0, $zero, 1
/* 8A9AB4 802400A4 AE020074 */  sw        $v0, 0x74($s0)
/* 8A9AB8 802400A8 0C05272D */  jal       sfx_play_sound
/* 8A9ABC 802400AC 24042011 */   addiu    $a0, $zero, 0x2011
.L802400B0:
/* 8A9AC0 802400B0 8E020070 */  lw        $v0, 0x70($s0)
/* 8A9AC4 802400B4 2442FFF8 */  addiu     $v0, $v0, -8
/* 8A9AC8 802400B8 AE020070 */  sw        $v0, 0x70($s0)
/* 8A9ACC 802400BC 2842005A */  slti      $v0, $v0, 0x5a
/* 8A9AD0 802400C0 10400016 */  beqz      $v0, .L8024011C
/* 8A9AD4 802400C4 2402005A */   addiu    $v0, $zero, 0x5a
/* 8A9AD8 802400C8 08090047 */  j         .L8024011C
/* 8A9ADC 802400CC AE020070 */   sw       $v0, 0x70($s0)
.L802400D0:
/* 8A9AE0 802400D0 82430012 */  lb        $v1, 0x12($s2)
/* 8A9AE4 802400D4 14620010 */  bne       $v1, $v0, .L80240118
/* 8A9AE8 802400D8 240200FF */   addiu    $v0, $zero, 0xff
/* 8A9AEC 802400DC 8E020074 */  lw        $v0, 0x74($s0)
/* 8A9AF0 802400E0 10400007 */  beqz      $v0, .L80240100
/* 8A9AF4 802400E4 00000000 */   nop
/* 8A9AF8 802400E8 8E020070 */  lw        $v0, 0x70($s0)
/* 8A9AFC 802400EC 284200FF */  slti      $v0, $v0, 0xff
/* 8A9B00 802400F0 10400003 */  beqz      $v0, .L80240100
/* 8A9B04 802400F4 AE000074 */   sw       $zero, 0x74($s0)
/* 8A9B08 802400F8 0C05272D */  jal       sfx_play_sound
/* 8A9B0C 802400FC 24042012 */   addiu    $a0, $zero, 0x2012
.L80240100:
/* 8A9B10 80240100 8E020070 */  lw        $v0, 0x70($s0)
/* 8A9B14 80240104 24420008 */  addiu     $v0, $v0, 8
/* 8A9B18 80240108 AE020070 */  sw        $v0, 0x70($s0)
/* 8A9B1C 8024010C 284200FF */  slti      $v0, $v0, 0xff
/* 8A9B20 80240110 14400002 */  bnez      $v0, .L8024011C
/* 8A9B24 80240114 240200FF */   addiu    $v0, $zero, 0xff
.L80240118:
/* 8A9B28 80240118 AE020070 */  sw        $v0, 0x70($s0)
.L8024011C:
/* 8A9B2C 8024011C C6060070 */  lwc1      $f6, 0x70($s0)
/* 8A9B30 80240120 468031A0 */  cvt.s.w   $f6, $f6
/* 8A9B34 80240124 44053000 */  mfc1      $a1, $f6
/* 8A9B38 80240128 0C04E035 */  jal       set_screen_overlay_alpha
/* 8A9B3C 8024012C 24040001 */   addiu    $a0, $zero, 1
/* 8A9B40 80240130 3C05437F */  lui       $a1, 0x437f
/* 8A9B44 80240134 0C04DF69 */  jal       set_screen_overlay_params_back
/* 8A9B48 80240138 2404000B */   addiu    $a0, $zero, 0xb
/* 8A9B4C 8024013C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 8A9B50 80240140 8FB20020 */  lw        $s2, 0x20($sp)
/* 8A9B54 80240144 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8A9B58 80240148 8FB00018 */  lw        $s0, 0x18($sp)
/* 8A9B5C 8024014C 0000102D */  daddu     $v0, $zero, $zero
/* 8A9B60 80240150 03E00008 */  jr        $ra
/* 8A9B64 80240154 27BD0028 */   addiu    $sp, $sp, 0x28
/* 8A9B68 80240158 00000000 */  nop
/* 8A9B6C 8024015C 00000000 */  nop
