.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E27F40
/* E27F40 802B6000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* E27F44 802B6004 AFB00030 */  sw        $s0, 0x30($sp)
/* E27F48 802B6008 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E27F4C 802B600C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E27F50 802B6010 AFBF003C */  sw        $ra, 0x3c($sp)
/* E27F54 802B6014 AFB20038 */  sw        $s2, 0x38($sp)
/* E27F58 802B6018 AFB10034 */  sw        $s1, 0x34($sp)
/* E27F5C 802B601C F7B60048 */  sdc1      $f22, 0x48($sp)
/* E27F60 802B6020 F7B40040 */  sdc1      $f20, 0x40($sp)
/* E27F64 802B6024 8E040000 */  lw        $a0, ($s0)
/* E27F68 802B6028 0481002F */  bgez      $a0, .L802B60E8
/* E27F6C 802B602C 3C027FFF */   lui      $v0, 0x7fff
/* E27F70 802B6030 3442FFFF */  ori       $v0, $v0, 0xffff
/* E27F74 802B6034 3C030080 */  lui       $v1, 0x80
/* E27F78 802B6038 34630008 */  ori       $v1, $v1, 8
/* E27F7C 802B603C 00821024 */  and       $v0, $a0, $v0
/* E27F80 802B6040 00431025 */  or        $v0, $v0, $v1
/* E27F84 802B6044 8E030004 */  lw        $v1, 4($s0)
/* E27F88 802B6048 AE020000 */  sw        $v0, ($s0)
/* E27F8C 802B604C 34420800 */  ori       $v0, $v0, 0x800
/* E27F90 802B6050 AE020000 */  sw        $v0, ($s0)
/* E27F94 802B6054 34630004 */  ori       $v1, $v1, 4
/* E27F98 802B6058 AE030004 */  sw        $v1, 4($s0)
/* E27F9C 802B605C 820300BF */  lb        $v1, 0xbf($s0)
/* E27FA0 802B6060 24020001 */  addiu     $v0, $zero, 1
/* E27FA4 802B6064 54620005 */  bnel      $v1, $v0, .L802B607C
/* E27FA8 802B6068 A20000B6 */   sb       $zero, 0xb6($s0)
/* E27FAC 802B606C 24020014 */  addiu     $v0, $zero, 0x14
/* E27FB0 802B6070 A20200B6 */  sb        $v0, 0xb6($s0)
/* E27FB4 802B6074 24020002 */  addiu     $v0, $zero, 2
/* E27FB8 802B6078 A6020008 */  sh        $v0, 8($s0)
.L802B607C:
/* E27FBC 802B607C C600002C */  lwc1      $f0, 0x2c($s0)
/* E27FC0 802B6080 3C03800B */  lui       $v1, %hi(gCameras)
/* E27FC4 802B6084 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E27FC8 802B6088 AE000054 */  sw        $zero, 0x54($s0)
/* E27FCC 802B608C 94620002 */  lhu       $v0, 2($v1)
/* E27FD0 802B6090 3C01802B */  lui       $at, %hi(D_802B68B0)
/* E27FD4 802B6094 AC2068B0 */  sw        $zero, %lo(D_802B68B0)($at)
/* E27FD8 802B6098 3C01802B */  lui       $at, %hi(D_802B68BC)
/* E27FDC 802B609C E42068BC */  swc1      $f0, %lo(D_802B68BC)($at)
/* E27FE0 802B60A0 3C0142B4 */  lui       $at, 0x42b4
/* E27FE4 802B60A4 44810000 */  mtc1      $at, $f0
/* E27FE8 802B60A8 34420003 */  ori       $v0, $v0, 3
/* E27FEC 802B60AC A4620002 */  sh        $v0, 2($v1)
/* E27FF0 802B60B0 3C01802B */  lui       $at, %hi(D_802B68B4)
/* E27FF4 802B60B4 E42068B4 */  swc1      $f0, %lo(D_802B68B4)($at)
/* E27FF8 802B60B8 0C03A8CD */  jal       subtract_hp
/* E27FFC 802B60BC 24040001 */   addiu    $a0, $zero, 1
/* E28000 802B60C0 0C03A5D8 */  jal       open_status_menu_long
/* E28004 802B60C4 00000000 */   nop
/* E28008 802B60C8 240400E8 */  addiu     $a0, $zero, 0xe8
/* E2800C 802B60CC 3C03800A */  lui       $v1, %hi(D_8009A650)
/* E28010 802B60D0 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* E28014 802B60D4 8C620000 */  lw        $v0, ($v1)
/* E28018 802B60D8 0000282D */  daddu     $a1, $zero, $zero
/* E2801C 802B60DC 34420040 */  ori       $v0, $v0, 0x40
/* E28020 802B60E0 0C052736 */  jal       play_sound_at_player
/* E28024 802B60E4 AC620000 */   sw       $v0, ($v1)
.L802B60E8:
/* E28028 802B60E8 820300B6 */  lb        $v1, 0xb6($s0)
/* E2802C 802B60EC 2C620016 */  sltiu     $v0, $v1, 0x16
/* E28030 802B60F0 104001C5 */  beqz      $v0, L802B6808_E28748
/* E28034 802B60F4 00031080 */   sll      $v0, $v1, 2
/* E28038 802B60F8 3C01802B */  lui       $at, %hi(jtbl_802B6850_E28790)
/* E2803C 802B60FC 00220821 */  addu      $at, $at, $v0
/* E28040 802B6100 8C226850 */  lw        $v0, %lo(jtbl_802B6850_E28790)($at)
/* E28044 802B6104 00400008 */  jr        $v0
/* E28048 802B6108 00000000 */   nop
glabel L802B610C_E2804C
/* E2804C 802B610C 96020008 */  lhu       $v0, 8($s0)
/* E28050 802B6110 2403FFFF */  addiu     $v1, $zero, -1
/* E28054 802B6114 2442FFFF */  addiu     $v0, $v0, -1
/* E28058 802B6118 A6020008 */  sh        $v0, 8($s0)
/* E2805C 802B611C 00021400 */  sll       $v0, $v0, 0x10
/* E28060 802B6120 00021403 */  sra       $v0, $v0, 0x10
/* E28064 802B6124 504301B8 */  beql      $v0, $v1, L802B6808_E28748
/* E28068 802B6128 A20000B6 */   sb       $zero, 0xb6($s0)
/* E2806C 802B612C 080ADA02 */  j         L802B6808_E28748
/* E28070 802B6130 00000000 */   nop
glabel L802B6134_E28074
/* E28074 802B6134 96020008 */  lhu       $v0, 8($s0)
/* E28078 802B6138 2403FFFF */  addiu     $v1, $zero, -1
/* E2807C 802B613C 2442FFFF */  addiu     $v0, $v0, -1
/* E28080 802B6140 A6020008 */  sh        $v0, 8($s0)
/* E28084 802B6144 00021400 */  sll       $v0, $v0, 0x10
/* E28088 802B6148 00021403 */  sra       $v0, $v0, 0x10
/* E2808C 802B614C 50430001 */  beql      $v0, $v1, .L802B6154
/* E28090 802B6150 A20000B6 */   sb       $zero, 0xb6($s0)
.L802B6154:
/* E28094 802B6154 C600002C */  lwc1      $f0, 0x2c($s0)
/* E28098 802B6158 3C014080 */  lui       $at, 0x4080
/* E2809C 802B615C 44811000 */  mtc1      $at, $f2
/* E280A0 802B6160 00000000 */  nop
/* E280A4 802B6164 46020001 */  sub.s     $f0, $f0, $f2
/* E280A8 802B6168 080ADA02 */  j         L802B6808_E28748
/* E280AC 802B616C E600002C */   swc1     $f0, 0x2c($s0)
glabel L802B6170_E280B0
/* E280B0 802B6170 820200BF */  lb        $v0, 0xbf($s0)
/* E280B4 802B6174 24110001 */  addiu     $s1, $zero, 1
/* E280B8 802B6178 1451000C */  bne       $v0, $s1, .L802B61AC
/* E280BC 802B617C 3C040008 */   lui      $a0, 8
/* E280C0 802B6180 0000202D */  daddu     $a0, $zero, $zero
/* E280C4 802B6184 8E050028 */  lw        $a1, 0x28($s0)
/* E280C8 802B6188 8E06002C */  lw        $a2, 0x2c($s0)
/* E280CC 802B618C 8E070030 */  lw        $a3, 0x30($s0)
/* E280D0 802B6190 3C013F80 */  lui       $at, 0x3f80
/* E280D4 802B6194 44810000 */  mtc1      $at, $f0
/* E280D8 802B6198 24020028 */  addiu     $v0, $zero, 0x28
/* E280DC 802B619C AFA20014 */  sw        $v0, 0x14($sp)
/* E280E0 802B61A0 0C01C1CC */  jal       func_80070730
/* E280E4 802B61A4 E7A00010 */   swc1     $f0, 0x10($sp)
/* E280E8 802B61A8 3C040008 */  lui       $a0, 8
.L802B61AC:
/* E280EC 802B61AC 0C037FDE */  jal       func_800DFF78
/* E280F0 802B61B0 34840002 */   ori      $a0, $a0, 2
/* E280F4 802B61B4 3C0141A0 */  lui       $at, 0x41a0
/* E280F8 802B61B8 44810000 */  mtc1      $at, $f0
/* E280FC 802B61BC 3C01437A */  lui       $at, 0x437a
/* E28100 802B61C0 44811000 */  mtc1      $at, $f2
/* E28104 802B61C4 3C01802B */  lui       $at, %hi(D_802B68BC)
/* E28108 802B61C8 C42468BC */  lwc1      $f4, %lo(D_802B68BC)($at)
/* E2810C 802B61CC C6060028 */  lwc1      $f6, 0x28($s0)
/* E28110 802B61D0 C6080030 */  lwc1      $f8, 0x30($s0)
/* E28114 802B61D4 C60A002C */  lwc1      $f10, 0x2c($s0)
/* E28118 802B61D8 8E030000 */  lw        $v1, ($s0)
/* E2811C 802B61DC 24020002 */  addiu     $v0, $zero, 2
/* E28120 802B61E0 AE000074 */  sw        $zero, 0x74($s0)
/* E28124 802B61E4 A60000C0 */  sh        $zero, 0xc0($s0)
/* E28128 802B61E8 A60000C2 */  sh        $zero, 0xc2($s0)
/* E2812C 802B61EC A20200B6 */  sb        $v0, 0xb6($s0)
/* E28130 802B61F0 A6110008 */  sh        $s1, 8($s0)
/* E28134 802B61F4 34630002 */  ori       $v1, $v1, 2
/* E28138 802B61F8 E6000070 */  swc1      $f0, 0x70($s0)
/* E2813C 802B61FC E6020078 */  swc1      $f2, 0x78($s0)
/* E28140 802B6200 E604007C */  swc1      $f4, 0x7c($s0)
/* E28144 802B6204 E606003C */  swc1      $f6, 0x3c($s0)
/* E28148 802B6208 E6080040 */  swc1      $f8, 0x40($s0)
/* E2814C 802B620C E60A004C */  swc1      $f10, 0x4c($s0)
/* E28150 802B6210 080ADA02 */  j         L802B6808_E28748
/* E28154 802B6214 AE030000 */   sw       $v1, ($s0)
glabel L802B6218_E28158
/* E28158 802B6218 96020008 */  lhu       $v0, 8($s0)
/* E2815C 802B621C 2442FFFF */  addiu     $v0, $v0, -1
/* E28160 802B6220 A6020008 */  sh        $v0, 8($s0)
/* E28164 802B6224 00021400 */  sll       $v0, $v0, 0x10
/* E28168 802B6228 1C400177 */  bgtz      $v0, L802B6808_E28748
/* E2816C 802B622C 00000000 */   nop
/* E28170 802B6230 920200B6 */  lbu       $v0, 0xb6($s0)
/* E28174 802B6234 080AD9ED */  j         .L802B67B4
/* E28178 802B6238 24420001 */   addiu    $v0, $v0, 1
glabel L802B623C_E2817C
/* E2817C 802B623C 820300BF */  lb        $v1, 0xbf($s0)
/* E28180 802B6240 24020001 */  addiu     $v0, $zero, 1
/* E28184 802B6244 1462000F */  bne       $v1, $v0, .L802B6284
/* E28188 802B6248 00000000 */   nop
/* E2818C 802B624C 960200C0 */  lhu       $v0, 0xc0($s0)
/* E28190 802B6250 30420001 */  andi      $v0, $v0, 1
/* E28194 802B6254 1440000B */  bnez      $v0, .L802B6284
/* E28198 802B6258 0000202D */   daddu    $a0, $zero, $zero
/* E2819C 802B625C 8E050028 */  lw        $a1, 0x28($s0)
/* E281A0 802B6260 8E06002C */  lw        $a2, 0x2c($s0)
/* E281A4 802B6264 8E070030 */  lw        $a3, 0x30($s0)
/* E281A8 802B6268 3C013F33 */  lui       $at, 0x3f33
/* E281AC 802B626C 34213333 */  ori       $at, $at, 0x3333
/* E281B0 802B6270 44810000 */  mtc1      $at, $f0
/* E281B4 802B6274 24020012 */  addiu     $v0, $zero, 0x12
/* E281B8 802B6278 AFA20014 */  sw        $v0, 0x14($sp)
/* E281BC 802B627C 0C01C1CC */  jal       func_80070730
/* E281C0 802B6280 E7A00010 */   swc1     $f0, 0x10($sp)
.L802B6284:
/* E281C4 802B6284 C600007C */  lwc1      $f0, 0x7c($s0)
/* E281C8 802B6288 C6020078 */  lwc1      $f2, 0x78($s0)
/* E281CC 802B628C 46020080 */  add.s     $f2, $f0, $f2
/* E281D0 802B6290 C600002C */  lwc1      $f0, 0x2c($s0)
/* E281D4 802B6294 4602003C */  c.lt.s    $f0, $f2
/* E281D8 802B6298 00000000 */  nop
/* E281DC 802B629C 45000034 */  bc1f      .L802B6370
/* E281E0 802B62A0 27A50018 */   addiu    $a1, $sp, 0x18
/* E281E4 802B62A4 3C12802B */  lui       $s2, %hi(D_802B68B4)
/* E281E8 802B62A8 265268B4 */  addiu     $s2, $s2, %lo(D_802B68B4)
/* E281EC 802B62AC C64C0000 */  lwc1      $f12, ($s2)
/* E281F0 802B62B0 3C0140C9 */  lui       $at, 0x40c9
/* E281F4 802B62B4 34210FD0 */  ori       $at, $at, 0xfd0
/* E281F8 802B62B8 4481B000 */  mtc1      $at, $f22
/* E281FC 802B62BC 00000000 */  nop
/* E28200 802B62C0 46166302 */  mul.s     $f12, $f12, $f22
/* E28204 802B62C4 00000000 */  nop
/* E28208 802B62C8 3C0143B4 */  lui       $at, 0x43b4
/* E2820C 802B62CC 4481A000 */  mtc1      $at, $f20
/* E28210 802B62D0 27A6001C */  addiu     $a2, $sp, 0x1c
/* E28214 802B62D4 0C00A82D */  jal       sin_cos_rad
/* E28218 802B62D8 46146303 */   div.s    $f12, $f12, $f20
/* E2821C 802B62DC C64C0000 */  lwc1      $f12, ($s2)
/* E28220 802B62E0 46166302 */  mul.s     $f12, $f12, $f22
/* E28224 802B62E4 00000000 */  nop
/* E28228 802B62E8 0C00A85B */  jal       sin_rad
/* E2822C 802B62EC 46146303 */   div.s    $f12, $f12, $f20
/* E28230 802B62F0 3C014180 */  lui       $at, 0x4180
/* E28234 802B62F4 44811000 */  mtc1      $at, $f2
/* E28238 802B62F8 00000000 */  nop
/* E2823C 802B62FC 46020002 */  mul.s     $f0, $f0, $f2
/* E28240 802B6300 00000000 */  nop
/* E28244 802B6304 3C01BF80 */  lui       $at, 0xbf80
/* E28248 802B6308 44811000 */  mtc1      $at, $f2
/* E2824C 802B630C 3C11802B */  lui       $s1, %hi(D_802B68B0)
/* E28250 802B6310 263168B0 */  addiu     $s1, $s1, %lo(D_802B68B0)
/* E28254 802B6314 4602003C */  c.lt.s    $f0, $f2
/* E28258 802B6318 00000000 */  nop
/* E2825C 802B631C 45000002 */  bc1f      .L802B6328
/* E28260 802B6320 E6200000 */   swc1     $f0, ($s1)
/* E28264 802B6324 E6220000 */  swc1      $f2, ($s1)
.L802B6328:
/* E28268 802B6328 C604002C */  lwc1      $f4, 0x2c($s0)
/* E2826C 802B632C C6200000 */  lwc1      $f0, ($s1)
/* E28270 802B6330 C6420000 */  lwc1      $f2, ($s2)
/* E28274 802B6334 46002100 */  add.s     $f4, $f4, $f0
/* E28278 802B6338 3C014040 */  lui       $at, 0x4040
/* E2827C 802B633C 44810000 */  mtc1      $at, $f0
/* E28280 802B6340 00000000 */  nop
/* E28284 802B6344 46001080 */  add.s     $f2, $f2, $f0
/* E28288 802B6348 3C014334 */  lui       $at, 0x4334
/* E2828C 802B634C 44810000 */  mtc1      $at, $f0
/* E28290 802B6350 E604002C */  swc1      $f4, 0x2c($s0)
/* E28294 802B6354 4602003C */  c.lt.s    $f0, $f2
/* E28298 802B6358 00000000 */  nop
/* E2829C 802B635C 4500012A */  bc1f      L802B6808_E28748
/* E282A0 802B6360 E6420000 */   swc1     $f2, ($s2)
/* E282A4 802B6364 920200B6 */  lbu       $v0, 0xb6($s0)
/* E282A8 802B6368 080AD9EC */  j         .L802B67B0
/* E282AC 802B636C E6400000 */   swc1     $f0, ($s2)
.L802B6370:
/* E282B0 802B6370 920200B6 */  lbu       $v0, 0xb6($s0)
/* E282B4 802B6374 080AD9EC */  j         .L802B67B0
/* E282B8 802B6378 E602002C */   swc1     $f2, 0x2c($s0)
glabel L802B637C_E282BC
/* E282BC 802B637C 820300BF */  lb        $v1, 0xbf($s0)
/* E282C0 802B6380 24020001 */  addiu     $v0, $zero, 1
/* E282C4 802B6384 14620011 */  bne       $v1, $v0, .L802B63CC
/* E282C8 802B6388 27A40020 */   addiu    $a0, $sp, 0x20
/* E282CC 802B638C 960200C0 */  lhu       $v0, 0xc0($s0)
/* E282D0 802B6390 30420001 */  andi      $v0, $v0, 1
/* E282D4 802B6394 1440000E */  bnez      $v0, .L802B63D0
/* E282D8 802B6398 27A50024 */   addiu    $a1, $sp, 0x24
/* E282DC 802B639C 0000202D */  daddu     $a0, $zero, $zero
/* E282E0 802B63A0 8E050028 */  lw        $a1, 0x28($s0)
/* E282E4 802B63A4 8E06002C */  lw        $a2, 0x2c($s0)
/* E282E8 802B63A8 8E070030 */  lw        $a3, 0x30($s0)
/* E282EC 802B63AC 3C013F33 */  lui       $at, 0x3f33
/* E282F0 802B63B0 34213333 */  ori       $at, $at, 0x3333
/* E282F4 802B63B4 44810000 */  mtc1      $at, $f0
/* E282F8 802B63B8 24020012 */  addiu     $v0, $zero, 0x12
/* E282FC 802B63BC AFA20014 */  sw        $v0, 0x14($sp)
/* E28300 802B63C0 0C01C1CC */  jal       func_80070730
/* E28304 802B63C4 E7A00010 */   swc1     $f0, 0x10($sp)
/* E28308 802B63C8 27A40020 */  addiu     $a0, $sp, 0x20
.L802B63CC:
/* E2830C 802B63CC 27A50024 */  addiu     $a1, $sp, 0x24
.L802B63D0:
/* E28310 802B63D0 0C0B27F5 */  jal       func_802C9FD4
/* E28314 802B63D4 27A60028 */   addiu    $a2, $sp, 0x28
/* E28318 802B63D8 14400005 */  bnez      $v0, .L802B63F0
/* E2831C 802B63DC 00000000 */   nop
/* E28320 802B63E0 C6000028 */  lwc1      $f0, 0x28($s0)
/* E28324 802B63E4 C6020030 */  lwc1      $f2, 0x30($s0)
/* E28328 802B63E8 E7A00020 */  swc1      $f0, 0x20($sp)
/* E2832C 802B63EC E7A20028 */  swc1      $f2, 0x28($sp)
.L802B63F0:
/* E28330 802B63F0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* E28334 802B63F4 C602002C */  lwc1      $f2, 0x2c($s0)
/* E28338 802B63F8 3C013DEA */  lui       $at, 0x3dea
/* E2833C 802B63FC 3421161E */  ori       $at, $at, 0x161e
/* E28340 802B6400 44812000 */  mtc1      $at, $f4
/* E28344 802B6404 3C01BE92 */  lui       $at, 0xbe92
/* E28348 802B6408 3421FEC5 */  ori       $at, $at, 0xfec5
/* E2834C 802B640C 44813000 */  mtc1      $at, $f6
/* E28350 802B6410 3C01BE3A */  lui       $at, 0xbe3a
/* E28354 802B6414 3421ACDA */  ori       $at, $at, 0xacda
/* E28358 802B6418 44814000 */  mtc1      $at, $f8
/* E2835C 802B641C 3C013C3C */  lui       $at, 0x3c3c
/* E28360 802B6420 3421BE62 */  ori       $at, $at, 0xbe62
/* E28364 802B6424 44815000 */  mtc1      $at, $f10
/* E28368 802B6428 920300B6 */  lbu       $v1, 0xb6($s0)
/* E2836C 802B642C 4600040D */  trunc.w.s $f16, $f0
/* E28370 802B6430 44028000 */  mfc1      $v0, $f16
/* E28374 802B6434 00000000 */  nop
/* E28378 802B6438 A6020016 */  sh        $v0, 0x16($s0)
/* E2837C 802B643C C7A00028 */  lwc1      $f0, 0x28($sp)
/* E28380 802B6440 24630001 */  addiu     $v1, $v1, 1
/* E28384 802B6444 E6020050 */  swc1      $f2, 0x50($s0)
/* E28388 802B6448 E6040070 */  swc1      $f4, 0x70($s0)
/* E2838C 802B644C E6060074 */  swc1      $f6, 0x74($s0)
/* E28390 802B6450 E6080078 */  swc1      $f8, 0x78($s0)
/* E28394 802B6454 E60A007C */  swc1      $f10, 0x7c($s0)
/* E28398 802B6458 A20300B6 */  sb        $v1, 0xb6($s0)
/* E2839C 802B645C 4600040D */  trunc.w.s $f16, $f0
/* E283A0 802B6460 44028000 */  mfc1      $v0, $f16
/* E283A4 802B6464 080ADA02 */  j         L802B6808_E28748
/* E283A8 802B6468 A602001A */   sh       $v0, 0x1a($s0)
glabel L802B646C_E283AC
/* E283AC 802B646C C60C0028 */  lwc1      $f12, 0x28($s0)
/* E283B0 802B6470 C60E0030 */  lwc1      $f14, 0x30($s0)
/* E283B4 802B6474 86020016 */  lh        $v0, 0x16($s0)
/* E283B8 802B6478 8603001A */  lh        $v1, 0x1a($s0)
/* E283BC 802B647C 44828000 */  mtc1      $v0, $f16
/* E283C0 802B6480 00000000 */  nop
/* E283C4 802B6484 46808420 */  cvt.s.w   $f16, $f16
/* E283C8 802B6488 44068000 */  mfc1      $a2, $f16
/* E283CC 802B648C 44838000 */  mtc1      $v1, $f16
/* E283D0 802B6490 00000000 */  nop
/* E283D4 802B6494 46808420 */  cvt.s.w   $f16, $f16
/* E283D8 802B6498 44078000 */  mfc1      $a3, $f16
/* E283DC 802B649C 0C00A720 */  jal       atan2
/* E283E0 802B64A0 00000000 */   nop
/* E283E4 802B64A4 86020016 */  lh        $v0, 0x16($s0)
/* E283E8 802B64A8 8603001A */  lh        $v1, 0x1a($s0)
/* E283EC 802B64AC 3C01802B */  lui       $at, %hi(D_802B68B8)
/* E283F0 802B64B0 E42068B8 */  swc1      $f0, %lo(D_802B68B8)($at)
/* E283F4 802B64B4 44826000 */  mtc1      $v0, $f12
/* E283F8 802B64B8 00000000 */  nop
/* E283FC 802B64BC 46806320 */  cvt.s.w   $f12, $f12
/* E28400 802B64C0 44837000 */  mtc1      $v1, $f14
/* E28404 802B64C4 00000000 */  nop
/* E28408 802B64C8 0C038022 */  jal       func_800E0088
/* E2840C 802B64CC 468073A0 */   cvt.s.w  $f14, $f14
/* E28410 802B64D0 3C014190 */  lui       $at, 0x4190
/* E28414 802B64D4 44811000 */  mtc1      $at, $f2
/* E28418 802B64D8 920200B6 */  lbu       $v0, 0xb6($s0)
/* E2841C 802B64DC 46020003 */  div.s     $f0, $f0, $f2
/* E28420 802B64E0 24420001 */  addiu     $v0, $v0, 1
/* E28424 802B64E4 E6000054 */  swc1      $f0, 0x54($s0)
/* E28428 802B64E8 080ADA02 */  j         L802B6808_E28748
/* E2842C 802B64EC A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B64F0_E28430
/* E28430 802B64F0 C60C0028 */  lwc1      $f12, 0x28($s0)
/* E28434 802B64F4 C60E0030 */  lwc1      $f14, 0x30($s0)
/* E28438 802B64F8 86020016 */  lh        $v0, 0x16($s0)
/* E2843C 802B64FC 8603001A */  lh        $v1, 0x1a($s0)
/* E28440 802B6500 44828000 */  mtc1      $v0, $f16
/* E28444 802B6504 00000000 */  nop
/* E28448 802B6508 46808420 */  cvt.s.w   $f16, $f16
/* E2844C 802B650C 44068000 */  mfc1      $a2, $f16
/* E28450 802B6510 44838000 */  mtc1      $v1, $f16
/* E28454 802B6514 00000000 */  nop
/* E28458 802B6518 46808420 */  cvt.s.w   $f16, $f16
/* E2845C 802B651C 44078000 */  mfc1      $a3, $f16
/* E28460 802B6520 0C00A720 */  jal       atan2
/* E28464 802B6524 00000000 */   nop
/* E28468 802B6528 3C0140C9 */  lui       $at, 0x40c9
/* E2846C 802B652C 34210FD0 */  ori       $at, $at, 0xfd0
/* E28470 802B6530 44811000 */  mtc1      $at, $f2
/* E28474 802B6534 00000000 */  nop
/* E28478 802B6538 46020082 */  mul.s     $f2, $f0, $f2
/* E2847C 802B653C 00000000 */  nop
/* E28480 802B6540 3C0143B4 */  lui       $at, 0x43b4
/* E28484 802B6544 44812000 */  mtc1      $at, $f4
/* E28488 802B6548 3C01802B */  lui       $at, %hi(D_802B68B8)
/* E2848C 802B654C E42068B8 */  swc1      $f0, %lo(D_802B68B8)($at)
/* E28490 802B6550 46041503 */  div.s     $f20, $f2, $f4
/* E28494 802B6554 0C00A85B */  jal       sin_rad
/* E28498 802B6558 4600A306 */   mov.s    $f12, $f20
/* E2849C 802B655C C6020054 */  lwc1      $f2, 0x54($s0)
/* E284A0 802B6560 46001102 */  mul.s     $f4, $f2, $f0
/* E284A4 802B6564 00000000 */  nop
/* E284A8 802B6568 C6000028 */  lwc1      $f0, 0x28($s0)
/* E284AC 802B656C 44801000 */  mtc1      $zero, $f2
/* E284B0 802B6570 46040000 */  add.s     $f0, $f0, $f4
/* E284B4 802B6574 AFA0002C */  sw        $zero, 0x2c($sp)
/* E284B8 802B6578 4604103E */  c.le.s    $f2, $f4
/* E284BC 802B657C 00000000 */  nop
/* E284C0 802B6580 45000008 */  bc1f      .L802B65A4
/* E284C4 802B6584 E6000028 */   swc1     $f0, 0x28($s0)
/* E284C8 802B6588 86020016 */  lh        $v0, 0x16($s0)
/* E284CC 802B658C 44821000 */  mtc1      $v0, $f2
/* E284D0 802B6590 00000000 */  nop
/* E284D4 802B6594 468010A0 */  cvt.s.w   $f2, $f2
/* E284D8 802B6598 4600103E */  c.le.s    $f2, $f0
/* E284DC 802B659C 080AD970 */  j         .L802B65C0
/* E284E0 802B65A0 00000000 */   nop
.L802B65A4:
/* E284E4 802B65A4 86020016 */  lh        $v0, 0x16($s0)
/* E284E8 802B65A8 C6000028 */  lwc1      $f0, 0x28($s0)
/* E284EC 802B65AC 44821000 */  mtc1      $v0, $f2
/* E284F0 802B65B0 00000000 */  nop
/* E284F4 802B65B4 468010A0 */  cvt.s.w   $f2, $f2
/* E284F8 802B65B8 4602003E */  c.le.s    $f0, $f2
/* E284FC 802B65BC 00000000 */  nop
.L802B65C0:
/* E28500 802B65C0 45000003 */  bc1f      .L802B65D0
/* E28504 802B65C4 24020001 */   addiu    $v0, $zero, 1
/* E28508 802B65C8 E6020028 */  swc1      $f2, 0x28($s0)
/* E2850C 802B65CC AFA2002C */  sw        $v0, 0x2c($sp)
.L802B65D0:
/* E28510 802B65D0 0C00A874 */  jal       cos_rad
/* E28514 802B65D4 4600A306 */   mov.s    $f12, $f20
/* E28518 802B65D8 C6020054 */  lwc1      $f2, 0x54($s0)
/* E2851C 802B65DC 46001102 */  mul.s     $f4, $f2, $f0
/* E28520 802B65E0 00000000 */  nop
/* E28524 802B65E4 C6000030 */  lwc1      $f0, 0x30($s0)
/* E28528 802B65E8 46040081 */  sub.s     $f2, $f0, $f4
/* E2852C 802B65EC 44800000 */  mtc1      $zero, $f0
/* E28530 802B65F0 00000000 */  nop
/* E28534 802B65F4 4604003E */  c.le.s    $f0, $f4
/* E28538 802B65F8 00000000 */  nop
/* E2853C 802B65FC 45000008 */  bc1f      .L802B6620
/* E28540 802B6600 E6020030 */   swc1     $f2, 0x30($s0)
/* E28544 802B6604 8602001A */  lh        $v0, 0x1a($s0)
/* E28548 802B6608 44820000 */  mtc1      $v0, $f0
/* E2854C 802B660C 00000000 */  nop
/* E28550 802B6610 46800020 */  cvt.s.w   $f0, $f0
/* E28554 802B6614 4600103E */  c.le.s    $f2, $f0
/* E28558 802B6618 080AD98E */  j         .L802B6638
/* E2855C 802B661C 00000000 */   nop
.L802B6620:
/* E28560 802B6620 8602001A */  lh        $v0, 0x1a($s0)
/* E28564 802B6624 44820000 */  mtc1      $v0, $f0
/* E28568 802B6628 00000000 */  nop
/* E2856C 802B662C 46800020 */  cvt.s.w   $f0, $f0
/* E28570 802B6630 4602003E */  c.le.s    $f0, $f2
/* E28574 802B6634 00000000 */  nop
.L802B6638:
/* E28578 802B6638 45000005 */  bc1f      .L802B6650
/* E2857C 802B663C 00000000 */   nop
/* E28580 802B6640 8FA2002C */  lw        $v0, 0x2c($sp)
/* E28584 802B6644 E6000030 */  swc1      $f0, 0x30($s0)
/* E28588 802B6648 24420001 */  addiu     $v0, $v0, 1
/* E2858C 802B664C AFA2002C */  sw        $v0, 0x2c($sp)
.L802B6650:
/* E28590 802B6650 8FA3002C */  lw        $v1, 0x2c($sp)
/* E28594 802B6654 24020002 */  addiu     $v0, $zero, 2
/* E28598 802B6658 1462006B */  bne       $v1, $v0, L802B6808_E28748
/* E2859C 802B665C 00000000 */   nop
/* E285A0 802B6660 920200B6 */  lbu       $v0, 0xb6($s0)
/* E285A4 802B6664 080AD9ED */  j         .L802B67B4
/* E285A8 802B6668 24420001 */   addiu    $v0, $v0, 1
glabel L802B666C_E285AC
/* E285AC 802B666C 820300BF */  lb        $v1, 0xbf($s0)
/* E285B0 802B6670 24020001 */  addiu     $v0, $zero, 1
/* E285B4 802B6674 1462000F */  bne       $v1, $v0, .L802B66B4
/* E285B8 802B6678 00000000 */   nop
/* E285BC 802B667C 960200C0 */  lhu       $v0, 0xc0($s0)
/* E285C0 802B6680 30420001 */  andi      $v0, $v0, 1
/* E285C4 802B6684 1440000B */  bnez      $v0, .L802B66B4
/* E285C8 802B6688 0000202D */   daddu    $a0, $zero, $zero
/* E285CC 802B668C 8E050028 */  lw        $a1, 0x28($s0)
/* E285D0 802B6690 8E06002C */  lw        $a2, 0x2c($s0)
/* E285D4 802B6694 8E070030 */  lw        $a3, 0x30($s0)
/* E285D8 802B6698 3C013F33 */  lui       $at, 0x3f33
/* E285DC 802B669C 34213333 */  ori       $at, $at, 0x3333
/* E285E0 802B66A0 44810000 */  mtc1      $at, $f0
/* E285E4 802B66A4 24020012 */  addiu     $v0, $zero, 0x12
/* E285E8 802B66A8 AFA20014 */  sw        $v0, 0x14($sp)
/* E285EC 802B66AC 0C01C1CC */  jal       func_80070730
/* E285F0 802B66B0 E7A00010 */   swc1     $f0, 0x10($sp)
.L802B66B4:
/* E285F4 802B66B4 0C038D36 */  jal       func_800E34D8
/* E285F8 802B66B8 00000000 */   nop
/* E285FC 802B66BC 46000306 */  mov.s     $f12, $f0
/* E28600 802B66C0 0C038D45 */  jal       func_800E3514
/* E28604 802B66C4 27A5002C */   addiu    $a1, $sp, 0x2c
/* E28608 802B66C8 8FA2002C */  lw        $v0, 0x2c($sp)
/* E2860C 802B66CC 0440004E */  bltz      $v0, L802B6808_E28748
/* E28610 802B66D0 E600002C */   swc1     $f0, 0x2c($s0)
/* E28614 802B66D4 0000202D */  daddu     $a0, $zero, $zero
/* E28618 802B66D8 24050002 */  addiu     $a1, $zero, 2
/* E2861C 802B66DC 3C073F4C */  lui       $a3, 0x3f4c
/* E28620 802B66E0 34E7CCCD */  ori       $a3, $a3, 0xcccd
/* E28624 802B66E4 0C0B2D72 */  jal       exec_ShakeCamX
/* E28628 802B66E8 24060001 */   addiu    $a2, $zero, 1
/* E2862C 802B66EC 24040100 */  addiu     $a0, $zero, 0x100
/* E28630 802B66F0 0C00A3C2 */  jal       start_rumble
/* E28634 802B66F4 24050032 */   addiu    $a1, $zero, 0x32
/* E28638 802B66F8 0C03954C */  jal       func_800E5530
/* E2863C 802B66FC 00000000 */   nop
/* E28640 802B6700 240403FB */  addiu     $a0, $zero, 0x3fb
/* E28644 802B6704 3C03800B */  lui       $v1, %hi(gCameras)
/* E28648 802B6708 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E2864C 802B670C 94620002 */  lhu       $v0, 2($v1)
/* E28650 802B6710 0000282D */  daddu     $a1, $zero, $zero
/* E28654 802B6714 3042FFFD */  andi      $v0, $v0, 0xfffd
/* E28658 802B6718 0C052736 */  jal       play_sound_at_player
/* E2865C 802B671C A4620002 */   sh       $v0, 2($v1)
/* E28660 802B6720 3C040008 */  lui       $a0, 8
/* E28664 802B6724 0C037FDE */  jal       func_800DFF78
/* E28668 802B6728 3484001A */   ori      $a0, $a0, 0x1a
/* E2866C 802B672C 8E020000 */  lw        $v0, ($s0)
/* E28670 802B6730 3C0140C0 */  lui       $at, 0x40c0
/* E28674 802B6734 44811000 */  mtc1      $at, $f2
/* E28678 802B6738 C600002C */  lwc1      $f0, 0x2c($s0)
/* E2867C 802B673C 2403F7FF */  addiu     $v1, $zero, -0x801
/* E28680 802B6740 A20000BF */  sb        $zero, 0xbf($s0)
/* E28684 802B6744 00431024 */  and       $v0, $v0, $v1
/* E28688 802B6748 2403FFF7 */  addiu     $v1, $zero, -9
/* E2868C 802B674C 00431024 */  and       $v0, $v0, $v1
/* E28690 802B6750 AE020000 */  sw        $v0, ($s0)
/* E28694 802B6754 920200B6 */  lbu       $v0, 0xb6($s0)
/* E28698 802B6758 46020000 */  add.s     $f0, $f0, $f2
/* E2869C 802B675C E6020070 */  swc1      $f2, 0x70($s0)
/* E286A0 802B6760 24420001 */  addiu     $v0, $v0, 1
/* E286A4 802B6764 A20200B6 */  sb        $v0, 0xb6($s0)
/* E286A8 802B6768 080ADA02 */  j         L802B6808_E28748
/* E286AC 802B676C E600002C */   swc1     $f0, 0x2c($s0)
glabel L802B6770_E286B0
/* E286B0 802B6770 C60C0070 */  lwc1      $f12, 0x70($s0)
/* E286B4 802B6774 3C013FF0 */  lui       $at, 0x3ff0
/* E286B8 802B6778 44810800 */  mtc1      $at, $f1
/* E286BC 802B677C 44800000 */  mtc1      $zero, $f0
/* E286C0 802B6780 46006321 */  cvt.d.s   $f12, $f12
/* E286C4 802B6784 46206301 */  sub.d     $f12, $f12, $f0
/* E286C8 802B6788 27A5002C */  addiu     $a1, $sp, 0x2c
/* E286CC 802B678C 46206320 */  cvt.s.d   $f12, $f12
/* E286D0 802B6790 0C038D45 */  jal       func_800E3514
/* E286D4 802B6794 E60C0070 */   swc1     $f12, 0x70($s0)
/* E286D8 802B6798 8FA2002C */  lw        $v0, 0x2c($sp)
/* E286DC 802B679C 0440001A */  bltz      $v0, L802B6808_E28748
/* E286E0 802B67A0 E600002C */   swc1     $f0, 0x2c($s0)
/* E286E4 802B67A4 920200B6 */  lbu       $v0, 0xb6($s0)
/* E286E8 802B67A8 2403000A */  addiu     $v1, $zero, 0xa
/* E286EC 802B67AC A6030008 */  sh        $v1, 8($s0)
.L802B67B0:
/* E286F0 802B67B0 24420001 */  addiu     $v0, $v0, 1
.L802B67B4:
/* E286F4 802B67B4 080ADA02 */  j         L802B6808_E28748
/* E286F8 802B67B8 A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B67BC_E286FC
/* E286FC 802B67BC 96020008 */  lhu       $v0, 8($s0)
/* E28700 802B67C0 2442FFFF */  addiu     $v0, $v0, -1
/* E28704 802B67C4 A6020008 */  sh        $v0, 8($s0)
/* E28708 802B67C8 00021400 */  sll       $v0, $v0, 0x10
/* E2870C 802B67CC 1C40000E */  bgtz      $v0, L802B6808_E28748
/* E28710 802B67D0 00000000 */   nop
/* E28714 802B67D4 0C039769 */  jal       set_action_state
/* E28718 802B67D8 2404000A */   addiu    $a0, $zero, 0xa
/* E2871C 802B67DC 3C03FF7F */  lui       $v1, 0xff7f
/* E28720 802B67E0 3463FFFF */  ori       $v1, $v1, 0xffff
/* E28724 802B67E4 8E020000 */  lw        $v0, ($s0)
/* E28728 802B67E8 3C04800A */  lui       $a0, %hi(D_8009A650)
/* E2872C 802B67EC 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* E28730 802B67F0 00431024 */  and       $v0, $v0, $v1
/* E28734 802B67F4 AE020000 */  sw        $v0, ($s0)
/* E28738 802B67F8 8C820000 */  lw        $v0, ($a0)
/* E2873C 802B67FC 2403FFBF */  addiu     $v1, $zero, -0x41
/* E28740 802B6800 00431024 */  and       $v0, $v0, $v1
/* E28744 802B6804 AC820000 */  sw        $v0, ($a0)
glabel L802B6808_E28748
/* E28748 802B6808 820200B6 */  lb        $v0, 0xb6($s0)
/* E2874C 802B680C 28420007 */  slti      $v0, $v0, 7
/* E28750 802B6810 10400004 */  beqz      $v0, .L802B6824
/* E28754 802B6814 00000000 */   nop
/* E28758 802B6818 960200C0 */  lhu       $v0, 0xc0($s0)
/* E2875C 802B681C 24420001 */  addiu     $v0, $v0, 1
/* E28760 802B6820 A60200C0 */  sh        $v0, 0xc0($s0)
.L802B6824:
/* E28764 802B6824 8FBF003C */  lw        $ra, 0x3c($sp)
/* E28768 802B6828 8FB20038 */  lw        $s2, 0x38($sp)
/* E2876C 802B682C 8FB10034 */  lw        $s1, 0x34($sp)
/* E28770 802B6830 8FB00030 */  lw        $s0, 0x30($sp)
/* E28774 802B6834 D7B60048 */  ldc1      $f22, 0x48($sp)
/* E28778 802B6838 D7B40040 */  ldc1      $f20, 0x40($sp)
/* E2877C 802B683C 03E00008 */  jr        $ra
/* E28780 802B6840 27BD0050 */   addiu    $sp, $sp, 0x50
/* E28784 802B6844 00000000 */  nop
/* E28788 802B6848 00000000 */  nop
/* E2878C 802B684C 00000000 */  nop
