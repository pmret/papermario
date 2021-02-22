.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241204_9FB9F4
/* 9FB9F4 80241204 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9FB9F8 80241208 AFB40040 */  sw        $s4, 0x40($sp)
/* 9FB9FC 8024120C 0080A02D */  daddu     $s4, $a0, $zero
/* 9FBA00 80241210 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9FBA04 80241214 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9FBA08 80241218 AFB20038 */  sw        $s2, 0x38($sp)
/* 9FBA0C 8024121C AFB10034 */  sw        $s1, 0x34($sp)
/* 9FBA10 80241220 AFB00030 */  sw        $s0, 0x30($sp)
/* 9FBA14 80241224 8E910148 */  lw        $s1, 0x148($s4)
/* 9FBA18 80241228 00A0902D */  daddu     $s2, $a1, $zero
/* 9FBA1C 8024122C 86240008 */  lh        $a0, 8($s1)
/* 9FBA20 80241230 0C00EABB */  jal       get_npc_unsafe
/* 9FBA24 80241234 00C0982D */   daddu    $s3, $a2, $zero
/* 9FBA28 80241238 8E430014 */  lw        $v1, 0x14($s2)
/* 9FBA2C 8024123C 04600031 */  bltz      $v1, .L80241304
/* 9FBA30 80241240 0040802D */   daddu    $s0, $v0, $zero
/* 9FBA34 80241244 0260202D */  daddu     $a0, $s3, $zero
/* 9FBA38 80241248 AFA00010 */  sw        $zero, 0x10($sp)
/* 9FBA3C 8024124C 8E460024 */  lw        $a2, 0x24($s2)
/* 9FBA40 80241250 8E470028 */  lw        $a3, 0x28($s2)
/* 9FBA44 80241254 0C01242D */  jal       func_800490B4
/* 9FBA48 80241258 0220282D */   daddu    $a1, $s1, $zero
/* 9FBA4C 8024125C 10400029 */  beqz      $v0, .L80241304
/* 9FBA50 80241260 0000202D */   daddu    $a0, $zero, $zero
/* 9FBA54 80241264 0200282D */  daddu     $a1, $s0, $zero
/* 9FBA58 80241268 0000302D */  daddu     $a2, $zero, $zero
/* 9FBA5C 8024126C 860300A8 */  lh        $v1, 0xa8($s0)
/* 9FBA60 80241270 3C013F80 */  lui       $at, 0x3f80
/* 9FBA64 80241274 44810000 */  mtc1      $at, $f0
/* 9FBA68 80241278 3C014000 */  lui       $at, 0x4000
/* 9FBA6C 8024127C 44811000 */  mtc1      $at, $f2
/* 9FBA70 80241280 3C01C1A0 */  lui       $at, 0xc1a0
/* 9FBA74 80241284 44812000 */  mtc1      $at, $f4
/* 9FBA78 80241288 2402000F */  addiu     $v0, $zero, 0xf
/* 9FBA7C 8024128C AFA2001C */  sw        $v0, 0x1c($sp)
/* 9FBA80 80241290 44833000 */  mtc1      $v1, $f6
/* 9FBA84 80241294 00000000 */  nop
/* 9FBA88 80241298 468031A0 */  cvt.s.w   $f6, $f6
/* 9FBA8C 8024129C 44073000 */  mfc1      $a3, $f6
/* 9FBA90 802412A0 27A20028 */  addiu     $v0, $sp, 0x28
/* 9FBA94 802412A4 AFA20020 */  sw        $v0, 0x20($sp)
/* 9FBA98 802412A8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9FBA9C 802412AC E7A20014 */  swc1      $f2, 0x14($sp)
/* 9FBAA0 802412B0 0C01BFA4 */  jal       fx_emote
/* 9FBAA4 802412B4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9FBAA8 802412B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9FBAAC 802412BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9FBAB0 802412C0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9FBAB4 802412C4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9FBAB8 802412C8 8C460028 */  lw        $a2, 0x28($v0)
/* 9FBABC 802412CC 0C00A720 */  jal       atan2
/* 9FBAC0 802412D0 8C470030 */   lw       $a3, 0x30($v0)
/* 9FBAC4 802412D4 0200202D */  daddu     $a0, $s0, $zero
/* 9FBAC8 802412D8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9FBACC 802412DC 3C060020 */  lui       $a2, 0x20
/* 9FBAD0 802412E0 0C012530 */  jal       func_800494C0
/* 9FBAD4 802412E4 E480000C */   swc1     $f0, 0xc($a0)
/* 9FBAD8 802412E8 8E220018 */  lw        $v0, 0x18($s1)
/* 9FBADC 802412EC 9442002A */  lhu       $v0, 0x2a($v0)
/* 9FBAE0 802412F0 30420001 */  andi      $v0, $v0, 1
/* 9FBAE4 802412F4 14400029 */  bnez      $v0, .L8024139C
/* 9FBAE8 802412F8 2402000A */   addiu    $v0, $zero, 0xa
/* 9FBAEC 802412FC 080904E7 */  j         .L8024139C
/* 9FBAF0 80241300 2402000C */   addiu    $v0, $zero, 0xc
.L80241304:
/* 9FBAF4 80241304 8602008C */  lh        $v0, 0x8c($s0)
/* 9FBAF8 80241308 14400025 */  bnez      $v0, .L802413A0
/* 9FBAFC 8024130C 00000000 */   nop
/* 9FBB00 80241310 9602008E */  lhu       $v0, 0x8e($s0)
/* 9FBB04 80241314 2442FFFF */  addiu     $v0, $v0, -1
/* 9FBB08 80241318 A602008E */  sh        $v0, 0x8e($s0)
/* 9FBB0C 8024131C 00021400 */  sll       $v0, $v0, 0x10
/* 9FBB10 80241320 1440001F */  bnez      $v0, .L802413A0
/* 9FBB14 80241324 00000000 */   nop
/* 9FBB18 80241328 8E820074 */  lw        $v0, 0x74($s4)
/* 9FBB1C 8024132C 2442FFFF */  addiu     $v0, $v0, -1
/* 9FBB20 80241330 10400019 */  beqz      $v0, .L80241398
/* 9FBB24 80241334 AE820074 */   sw       $v0, 0x74($s4)
/* 9FBB28 80241338 8E220018 */  lw        $v0, 0x18($s1)
/* 9FBB2C 8024133C 9442002A */  lhu       $v0, 0x2a($v0)
/* 9FBB30 80241340 30420010 */  andi      $v0, $v0, 0x10
/* 9FBB34 80241344 14400007 */  bnez      $v0, .L80241364
/* 9FBB38 80241348 00000000 */   nop
/* 9FBB3C 8024134C C600000C */  lwc1      $f0, 0xc($s0)
/* 9FBB40 80241350 3C014334 */  lui       $at, 0x4334
/* 9FBB44 80241354 44816000 */  mtc1      $at, $f12
/* 9FBB48 80241358 0C00A6C9 */  jal       clamp_angle
/* 9FBB4C 8024135C 460C0300 */   add.s    $f12, $f0, $f12
/* 9FBB50 80241360 E600000C */  swc1      $f0, 0xc($s0)
.L80241364:
/* 9FBB54 80241364 8E440008 */  lw        $a0, 8($s2)
/* 9FBB58 80241368 000417C2 */  srl       $v0, $a0, 0x1f
/* 9FBB5C 8024136C 00822021 */  addu      $a0, $a0, $v0
/* 9FBB60 80241370 00042043 */  sra       $a0, $a0, 1
/* 9FBB64 80241374 0C00A67F */  jal       rand_int
/* 9FBB68 80241378 24840001 */   addiu    $a0, $a0, 1
/* 9FBB6C 8024137C 8E430008 */  lw        $v1, 8($s2)
/* 9FBB70 80241380 000327C2 */  srl       $a0, $v1, 0x1f
/* 9FBB74 80241384 00641821 */  addu      $v1, $v1, $a0
/* 9FBB78 80241388 00031843 */  sra       $v1, $v1, 1
/* 9FBB7C 8024138C 00621821 */  addu      $v1, $v1, $v0
/* 9FBB80 80241390 080904E8 */  j         .L802413A0
/* 9FBB84 80241394 A603008E */   sh       $v1, 0x8e($s0)
.L80241398:
/* 9FBB88 80241398 24020004 */  addiu     $v0, $zero, 4
.L8024139C:
/* 9FBB8C 8024139C AE820070 */  sw        $v0, 0x70($s4)
.L802413A0:
/* 9FBB90 802413A0 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9FBB94 802413A4 8FB40040 */  lw        $s4, 0x40($sp)
/* 9FBB98 802413A8 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9FBB9C 802413AC 8FB20038 */  lw        $s2, 0x38($sp)
/* 9FBBA0 802413B0 8FB10034 */  lw        $s1, 0x34($sp)
/* 9FBBA4 802413B4 8FB00030 */  lw        $s0, 0x30($sp)
/* 9FBBA8 802413B8 03E00008 */  jr        $ra
/* 9FBBAC 802413BC 27BD0048 */   addiu    $sp, $sp, 0x48
