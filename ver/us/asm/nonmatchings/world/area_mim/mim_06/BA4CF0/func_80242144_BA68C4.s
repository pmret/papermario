.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242144_BA68C4
/* BA68C4 80242144 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* BA68C8 80242148 AFB3004C */  sw        $s3, 0x4c($sp)
/* BA68CC 8024214C 0080982D */  daddu     $s3, $a0, $zero
/* BA68D0 80242150 AFBF0054 */  sw        $ra, 0x54($sp)
/* BA68D4 80242154 AFB40050 */  sw        $s4, 0x50($sp)
/* BA68D8 80242158 AFB20048 */  sw        $s2, 0x48($sp)
/* BA68DC 8024215C AFB10044 */  sw        $s1, 0x44($sp)
/* BA68E0 80242160 AFB00040 */  sw        $s0, 0x40($sp)
/* BA68E4 80242164 F7B40058 */  sdc1      $f20, 0x58($sp)
/* BA68E8 80242168 8E710148 */  lw        $s1, 0x148($s3)
/* BA68EC 8024216C 00A0A02D */  daddu     $s4, $a1, $zero
/* BA68F0 80242170 86240008 */  lh        $a0, 8($s1)
/* BA68F4 80242174 0C00EABB */  jal       get_npc_unsafe
/* BA68F8 80242178 00C0902D */   daddu    $s2, $a2, $zero
/* BA68FC 8024217C 8E830014 */  lw        $v1, 0x14($s4)
/* BA6900 80242180 04600034 */  bltz      $v1, .L80242254
/* BA6904 80242184 0040802D */   daddu    $s0, $v0, $zero
/* BA6908 80242188 8E620074 */  lw        $v0, 0x74($s3)
/* BA690C 8024218C 1C400030 */  bgtz      $v0, .L80242250
/* BA6910 80242190 2442FFFF */   addiu    $v0, $v0, -1
/* BA6914 80242194 0240202D */  daddu     $a0, $s2, $zero
/* BA6918 80242198 AE630074 */  sw        $v1, 0x74($s3)
/* BA691C 8024219C AFA00010 */  sw        $zero, 0x10($sp)
/* BA6920 802421A0 8E86000C */  lw        $a2, 0xc($s4)
/* BA6924 802421A4 8E870010 */  lw        $a3, 0x10($s4)
/* BA6928 802421A8 0C01242D */  jal       func_800490B4
/* BA692C 802421AC 0220282D */   daddu    $a1, $s1, $zero
/* BA6930 802421B0 10400025 */  beqz      $v0, .L80242248
/* BA6934 802421B4 0000202D */   daddu    $a0, $zero, $zero
/* BA6938 802421B8 0200282D */  daddu     $a1, $s0, $zero
/* BA693C 802421BC 0000302D */  daddu     $a2, $zero, $zero
/* BA6940 802421C0 860300A8 */  lh        $v1, 0xa8($s0)
/* BA6944 802421C4 3C013F80 */  lui       $at, 0x3f80
/* BA6948 802421C8 44810000 */  mtc1      $at, $f0
/* BA694C 802421CC 3C014000 */  lui       $at, 0x4000
/* BA6950 802421D0 44811000 */  mtc1      $at, $f2
/* BA6954 802421D4 3C01C1A0 */  lui       $at, 0xc1a0
/* BA6958 802421D8 44812000 */  mtc1      $at, $f4
/* BA695C 802421DC 2402000F */  addiu     $v0, $zero, 0xf
/* BA6960 802421E0 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA6964 802421E4 44835000 */  mtc1      $v1, $f10
/* BA6968 802421E8 00000000 */  nop
/* BA696C 802421EC 468052A0 */  cvt.s.w   $f10, $f10
/* BA6970 802421F0 44075000 */  mfc1      $a3, $f10
/* BA6974 802421F4 27A20028 */  addiu     $v0, $sp, 0x28
/* BA6978 802421F8 AFA20020 */  sw        $v0, 0x20($sp)
/* BA697C 802421FC E7A00010 */  swc1      $f0, 0x10($sp)
/* BA6980 80242200 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA6984 80242204 0C01BFA4 */  jal       fx_emote
/* BA6988 80242208 E7A40018 */   swc1     $f4, 0x18($sp)
/* BA698C 8024220C 0200202D */  daddu     $a0, $s0, $zero
/* BA6990 80242210 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BA6994 80242214 0C012530 */  jal       ai_enemy_play_sound
/* BA6998 80242218 3C060020 */   lui      $a2, 0x20
/* BA699C 8024221C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA69A0 80242220 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA69A4 80242224 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA69A8 80242228 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA69AC 8024222C 8C460028 */  lw        $a2, 0x28($v0)
/* BA69B0 80242230 0C00A720 */  jal       atan2
/* BA69B4 80242234 8C470030 */   lw       $a3, 0x30($v0)
/* BA69B8 80242238 2402000C */  addiu     $v0, $zero, 0xc
/* BA69BC 8024223C E600000C */  swc1      $f0, 0xc($s0)
/* BA69C0 80242240 08090916 */  j         .L80242458
/* BA69C4 80242244 AE620070 */   sw       $v0, 0x70($s3)
.L80242248:
/* BA69C8 80242248 8E620074 */  lw        $v0, 0x74($s3)
/* BA69CC 8024224C 2442FFFF */  addiu     $v0, $v0, -1
.L80242250:
/* BA69D0 80242250 AE620074 */  sw        $v0, 0x74($s3)
.L80242254:
/* BA69D4 80242254 C6000018 */  lwc1      $f0, 0x18($s0)
/* BA69D8 80242258 44801000 */  mtc1      $zero, $f2
/* BA69DC 8024225C 44801800 */  mtc1      $zero, $f3
/* BA69E0 80242260 46000021 */  cvt.d.s   $f0, $f0
/* BA69E4 80242264 4620103C */  c.lt.d    $f2, $f0
/* BA69E8 80242268 00000000 */  nop
/* BA69EC 8024226C 45000025 */  bc1f      .L80242304
/* BA69F0 80242270 27A5002C */   addiu    $a1, $sp, 0x2c
/* BA69F4 80242274 C6000038 */  lwc1      $f0, 0x38($s0)
/* BA69F8 80242278 860200A6 */  lh        $v0, 0xa6($s0)
/* BA69FC 8024227C 3C018024 */  lui       $at, %hi(D_80245978_BAA0F8)
/* BA6A00 80242280 D4225978 */  ldc1      $f2, %lo(D_80245978_BAA0F8)($at)
/* BA6A04 80242284 27A60030 */  addiu     $a2, $sp, 0x30
/* BA6A08 80242288 E7A0002C */  swc1      $f0, 0x2c($sp)
/* BA6A0C 8024228C 44820000 */  mtc1      $v0, $f0
/* BA6A10 80242290 00000000 */  nop
/* BA6A14 80242294 46800020 */  cvt.s.w   $f0, $f0
/* BA6A18 80242298 46000021 */  cvt.d.s   $f0, $f0
/* BA6A1C 8024229C C604003C */  lwc1      $f4, 0x3c($s0)
/* BA6A20 802422A0 C6060040 */  lwc1      $f6, 0x40($s0)
/* BA6A24 802422A4 C6080018 */  lwc1      $f8, 0x18($s0)
/* BA6A28 802422A8 860200A8 */  lh        $v0, 0xa8($s0)
/* BA6A2C 802422AC 46220002 */  mul.d     $f0, $f0, $f2
/* BA6A30 802422B0 00000000 */  nop
/* BA6A34 802422B4 E7A40030 */  swc1      $f4, 0x30($sp)
/* BA6A38 802422B8 E7A60034 */  swc1      $f6, 0x34($sp)
/* BA6A3C 802422BC E7A80010 */  swc1      $f8, 0x10($sp)
/* BA6A40 802422C0 C604000C */  lwc1      $f4, 0xc($s0)
/* BA6A44 802422C4 44821000 */  mtc1      $v0, $f2
/* BA6A48 802422C8 00000000 */  nop
/* BA6A4C 802422CC 468010A0 */  cvt.s.w   $f2, $f2
/* BA6A50 802422D0 E7A20018 */  swc1      $f2, 0x18($sp)
/* BA6A54 802422D4 E7A40014 */  swc1      $f4, 0x14($sp)
/* BA6A58 802422D8 46200020 */  cvt.s.d   $f0, $f0
/* BA6A5C 802422DC E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA6A60 802422E0 8E040080 */  lw        $a0, 0x80($s0)
/* BA6A64 802422E4 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BA6A68 802422E8 27A70034 */   addiu    $a3, $sp, 0x34
/* BA6A6C 802422EC 54400005 */  bnel      $v0, $zero, .L80242304
/* BA6A70 802422F0 AE000018 */   sw       $zero, 0x18($s0)
/* BA6A74 802422F4 8E050018 */  lw        $a1, 0x18($s0)
/* BA6A78 802422F8 8E06000C */  lw        $a2, 0xc($s0)
/* BA6A7C 802422FC 0C00EA95 */  jal       npc_move_heading
/* BA6A80 80242300 0200202D */   daddu    $a0, $s0, $zero
.L80242304:
/* BA6A84 80242304 C600001C */  lwc1      $f0, 0x1c($s0)
/* BA6A88 80242308 44801000 */  mtc1      $zero, $f2
/* BA6A8C 8024230C 44801800 */  mtc1      $zero, $f3
/* BA6A90 80242310 46000021 */  cvt.d.s   $f0, $f0
/* BA6A94 80242314 4622003C */  c.lt.d    $f0, $f2
/* BA6A98 80242318 00000000 */  nop
/* BA6A9C 8024231C 45000047 */  bc1f      .L8024243C
/* BA6AA0 80242320 27A5002C */   addiu    $a1, $sp, 0x2c
/* BA6AA4 80242324 27A60030 */  addiu     $a2, $sp, 0x30
/* BA6AA8 80242328 27A20038 */  addiu     $v0, $sp, 0x38
/* BA6AAC 8024232C C602003C */  lwc1      $f2, 0x3c($s0)
/* BA6AB0 80242330 C6060038 */  lwc1      $f6, 0x38($s0)
/* BA6AB4 80242334 3C01402A */  lui       $at, 0x402a
/* BA6AB8 80242338 4481A800 */  mtc1      $at, $f21
/* BA6ABC 8024233C 4480A000 */  mtc1      $zero, $f20
/* BA6AC0 80242340 460010A1 */  cvt.d.s   $f2, $f2
/* BA6AC4 80242344 46341080 */  add.d     $f2, $f2, $f20
/* BA6AC8 80242348 C600001C */  lwc1      $f0, 0x1c($s0)
/* BA6ACC 8024234C C6040040 */  lwc1      $f4, 0x40($s0)
/* BA6AD0 80242350 46000005 */  abs.s     $f0, $f0
/* BA6AD4 80242354 E7A40034 */  swc1      $f4, 0x34($sp)
/* BA6AD8 80242358 3C014030 */  lui       $at, 0x4030
/* BA6ADC 8024235C 44812800 */  mtc1      $at, $f5
/* BA6AE0 80242360 44802000 */  mtc1      $zero, $f4
/* BA6AE4 80242364 46000021 */  cvt.d.s   $f0, $f0
/* BA6AE8 80242368 E7A6002C */  swc1      $f6, 0x2c($sp)
/* BA6AEC 8024236C 46240000 */  add.d     $f0, $f0, $f4
/* BA6AF0 80242370 462010A0 */  cvt.s.d   $f2, $f2
/* BA6AF4 80242374 E7A20030 */  swc1      $f2, 0x30($sp)
/* BA6AF8 80242378 46200020 */  cvt.s.d   $f0, $f0
/* BA6AFC 8024237C E7A00038 */  swc1      $f0, 0x38($sp)
/* BA6B00 80242380 AFA20010 */  sw        $v0, 0x10($sp)
/* BA6B04 80242384 8E040080 */  lw        $a0, 0x80($s0)
/* BA6B08 80242388 0C0372DF */  jal       npc_raycast_down_sides
/* BA6B0C 8024238C 27A70034 */   addiu    $a3, $sp, 0x34
/* BA6B10 80242390 1040002A */  beqz      $v0, .L8024243C
/* BA6B14 80242394 00000000 */   nop
/* BA6B18 80242398 C600001C */  lwc1      $f0, 0x1c($s0)
/* BA6B1C 8024239C C7A20038 */  lwc1      $f2, 0x38($sp)
/* BA6B20 802423A0 46000005 */  abs.s     $f0, $f0
/* BA6B24 802423A4 46000021 */  cvt.d.s   $f0, $f0
/* BA6B28 802423A8 46340000 */  add.d     $f0, $f0, $f20
/* BA6B2C 802423AC 460010A1 */  cvt.d.s   $f2, $f2
/* BA6B30 802423B0 4620103E */  c.le.d    $f2, $f0
/* BA6B34 802423B4 00000000 */  nop
/* BA6B38 802423B8 45000020 */  bc1f      .L8024243C
/* BA6B3C 802423BC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BA6B40 802423C0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* BA6B44 802423C4 8E020000 */  lw        $v0, ($s0)
/* BA6B48 802423C8 2403F7FF */  addiu     $v1, $zero, -0x801
/* BA6B4C 802423CC AE00001C */  sw        $zero, 0x1c($s0)
/* BA6B50 802423D0 00431024 */  and       $v0, $v0, $v1
/* BA6B54 802423D4 AE020000 */  sw        $v0, ($s0)
/* BA6B58 802423D8 24020002 */  addiu     $v0, $zero, 2
/* BA6B5C 802423DC E600003C */  swc1      $f0, 0x3c($s0)
/* BA6B60 802423E0 0C00A67F */  jal       rand_int
/* BA6B64 802423E4 AE620070 */   sw       $v0, 0x70($s3)
/* BA6B68 802423E8 3C035555 */  lui       $v1, 0x5555
/* BA6B6C 802423EC 34635556 */  ori       $v1, $v1, 0x5556
/* BA6B70 802423F0 00430018 */  mult      $v0, $v1
/* BA6B74 802423F4 000227C3 */  sra       $a0, $v0, 0x1f
/* BA6B78 802423F8 00004010 */  mfhi      $t0
/* BA6B7C 802423FC 01042023 */  subu      $a0, $t0, $a0
/* BA6B80 80242400 00041840 */  sll       $v1, $a0, 1
/* BA6B84 80242404 00641821 */  addu      $v1, $v1, $a0
/* BA6B88 80242408 00431023 */  subu      $v0, $v0, $v1
/* BA6B8C 8024240C 24430002 */  addiu     $v1, $v0, 2
/* BA6B90 80242410 AE630074 */  sw        $v1, 0x74($s3)
/* BA6B94 80242414 8E82002C */  lw        $v0, 0x2c($s4)
/* BA6B98 80242418 5840000F */  blezl     $v0, .L80242458
/* BA6B9C 8024241C AE600070 */   sw       $zero, 0x70($s3)
/* BA6BA0 80242420 8E820004 */  lw        $v0, 4($s4)
/* BA6BA4 80242424 5840000C */  blezl     $v0, .L80242458
/* BA6BA8 80242428 AE600070 */   sw       $zero, 0x70($s3)
/* BA6BAC 8024242C 1460000A */  bnez      $v1, .L80242458
/* BA6BB0 80242430 00000000 */   nop
/* BA6BB4 80242434 08090916 */  j         .L80242458
/* BA6BB8 80242438 AE600070 */   sw       $zero, 0x70($s3)
.L8024243C:
/* BA6BBC 8024243C C604003C */  lwc1      $f4, 0x3c($s0)
/* BA6BC0 80242440 C600001C */  lwc1      $f0, 0x1c($s0)
/* BA6BC4 80242444 46002100 */  add.s     $f4, $f4, $f0
/* BA6BC8 80242448 C6020014 */  lwc1      $f2, 0x14($s0)
/* BA6BCC 8024244C 46020001 */  sub.s     $f0, $f0, $f2
/* BA6BD0 80242450 E604003C */  swc1      $f4, 0x3c($s0)
/* BA6BD4 80242454 E600001C */  swc1      $f0, 0x1c($s0)
.L80242458:
/* BA6BD8 80242458 8FBF0054 */  lw        $ra, 0x54($sp)
/* BA6BDC 8024245C 8FB40050 */  lw        $s4, 0x50($sp)
/* BA6BE0 80242460 8FB3004C */  lw        $s3, 0x4c($sp)
/* BA6BE4 80242464 8FB20048 */  lw        $s2, 0x48($sp)
/* BA6BE8 80242468 8FB10044 */  lw        $s1, 0x44($sp)
/* BA6BEC 8024246C 8FB00040 */  lw        $s0, 0x40($sp)
/* BA6BF0 80242470 D7B40058 */  ldc1      $f20, 0x58($sp)
/* BA6BF4 80242474 03E00008 */  jr        $ra
/* BA6BF8 80242478 27BD0060 */   addiu    $sp, $sp, 0x60
