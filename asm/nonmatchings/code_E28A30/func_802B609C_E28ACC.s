.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B609C_E28ACC
/* E28ACC 802B609C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* E28AD0 802B60A0 AFB20058 */  sw        $s2, 0x58($sp)
/* E28AD4 802B60A4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* E28AD8 802B60A8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* E28ADC 802B60AC AFBF005C */  sw        $ra, 0x5c($sp)
/* E28AE0 802B60B0 AFB10054 */  sw        $s1, 0x54($sp)
/* E28AE4 802B60B4 AFB00050 */  sw        $s0, 0x50($sp)
/* E28AE8 802B60B8 F7B60068 */  sdc1      $f22, 0x68($sp)
/* E28AEC 802B60BC F7B40060 */  sdc1      $f20, 0x60($sp)
/* E28AF0 802B60C0 8E430000 */  lw        $v1, ($s2)
/* E28AF4 802B60C4 0461000E */  bgez      $v1, .L802B6100
/* E28AF8 802B60C8 3C027FF7 */   lui      $v0, 0x7ff7
/* E28AFC 802B60CC 3442FFF1 */  ori       $v0, $v0, 0xfff1
/* E28B00 802B60D0 3C018011 */  lui       $at, %hi(D_8010C938)
/* E28B04 802B60D4 C420C938 */  lwc1      $f0, %lo(D_8010C938)($at)
/* E28B08 802B60D8 00621024 */  and       $v0, $v1, $v0
/* E28B0C 802B60DC AE420000 */  sw        $v0, ($s2)
/* E28B10 802B60E0 A24000B6 */  sb        $zero, 0xb6($s2)
/* E28B14 802B60E4 A6400008 */  sh        $zero, 8($s2)
/* E28B18 802B60E8 A64000C0 */  sh        $zero, 0xc0($s2)
/* E28B1C 802B60EC A64000C2 */  sh        $zero, 0xc2($s2)
/* E28B20 802B60F0 AE400054 */  sw        $zero, 0x54($s2)
/* E28B24 802B60F4 AE40008C */  sw        $zero, 0x8c($s2)
/* E28B28 802B60F8 3C01802B */  lui       $at, %hi(D_802B6770_E27C80)
/* E28B2C 802B60FC E4206770 */  swc1      $f0, %lo(D_802B6770_E27C80)($at)
.L802B6100:
/* E28B30 802B6100 824300B6 */  lb        $v1, 0xb6($s2)
/* E28B34 802B6104 924200B6 */  lbu       $v0, 0xb6($s2)
/* E28B38 802B6108 10600006 */  beqz      $v1, .L802B6124
/* E28B3C 802B610C 24420001 */   addiu    $v0, $v0, 1
/* E28B40 802B6110 24020001 */  addiu     $v0, $zero, 1
/* E28B44 802B6114 10620004 */  beq       $v1, $v0, .L802B6128
/* E28B48 802B6118 00000000 */   nop
/* E28B4C 802B611C 080AD8CC */  j         .L802B6330
/* E28B50 802B6120 00000000 */   nop
.L802B6124:
/* E28B54 802B6124 A24200B6 */  sb        $v0, 0xb6($s2)
.L802B6128:
/* E28B58 802B6128 3C018011 */  lui       $at, %hi(D_8010C990)
/* E28B5C 802B612C C42CC990 */  lwc1      $f12, %lo(D_8010C990)($at)
/* E28B60 802B6130 3C0140C9 */  lui       $at, 0x40c9
/* E28B64 802B6134 34210FD0 */  ori       $at, $at, 0xfd0
/* E28B68 802B6138 4481A000 */  mtc1      $at, $f20
/* E28B6C 802B613C 27B10028 */  addiu     $s1, $sp, 0x28
/* E28B70 802B6140 46146302 */  mul.s     $f12, $f12, $f20
/* E28B74 802B6144 00000000 */  nop
/* E28B78 802B6148 0220282D */  daddu     $a1, $s1, $zero
/* E28B7C 802B614C 27B0002C */  addiu     $s0, $sp, 0x2c
/* E28B80 802B6150 3C0143B4 */  lui       $at, 0x43b4
/* E28B84 802B6154 4481B000 */  mtc1      $at, $f22
/* E28B88 802B6158 0200302D */  daddu     $a2, $s0, $zero
/* E28B8C 802B615C 0C00A82D */  jal       sin_cos_rad
/* E28B90 802B6160 46166303 */   div.s    $f12, $f12, $f22
/* E28B94 802B6164 3C01802B */  lui       $at, %hi(D_802B6770_E27C80)
/* E28B98 802B6168 C42C6770 */  lwc1      $f12, %lo(D_802B6770_E27C80)($at)
/* E28B9C 802B616C 46146302 */  mul.s     $f12, $f12, $f20
/* E28BA0 802B6170 00000000 */  nop
/* E28BA4 802B6174 0220282D */  daddu     $a1, $s1, $zero
/* E28BA8 802B6178 C7A00028 */  lwc1      $f0, 0x28($sp)
/* E28BAC 802B617C 3C014040 */  lui       $at, 0x4040
/* E28BB0 802B6180 4481A000 */  mtc1      $at, $f20
/* E28BB4 802B6184 0200302D */  daddu     $a2, $s0, $zero
/* E28BB8 802B6188 46140502 */  mul.s     $f20, $f0, $f20
/* E28BBC 802B618C 00000000 */  nop
/* E28BC0 802B6190 0C00A82D */  jal       sin_cos_rad
/* E28BC4 802B6194 46166303 */   div.s    $f12, $f12, $f22
/* E28BC8 802B6198 C7A00028 */  lwc1      $f0, 0x28($sp)
/* E28BCC 802B619C 46140102 */  mul.s     $f4, $f0, $f20
/* E28BD0 802B61A0 00000000 */  nop
/* E28BD4 802B61A4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* E28BD8 802B61A8 46140182 */  mul.s     $f6, $f0, $f20
/* E28BDC 802B61AC 00000000 */  nop
/* E28BE0 802B61B0 3C01802B */  lui       $at, %hi(D_802B6760_E29190)
/* E28BE4 802B61B4 D4226760 */  ldc1      $f2, %lo(D_802B6760_E29190)($at)
/* E28BE8 802B61B8 46002021 */  cvt.d.s   $f0, $f4
/* E28BEC 802B61BC 46200005 */  abs.d     $f0, $f0
/* E28BF0 802B61C0 4622003C */  c.lt.d    $f0, $f2
/* E28BF4 802B61C4 00000000 */  nop
/* E28BF8 802B61C8 45020011 */  bc1fl     .L802B6210
/* E28BFC 802B61CC 46003021 */   cvt.d.s  $f0, $f6
/* E28C00 802B61D0 44800000 */  mtc1      $zero, $f0
/* E28C04 802B61D4 3C013DCC */  lui       $at, 0x3dcc
/* E28C08 802B61D8 3421CCCD */  ori       $at, $at, 0xcccd
/* E28C0C 802B61DC 44811000 */  mtc1      $at, $f2
/* E28C10 802B61E0 4600203C */  c.lt.s    $f4, $f0
/* E28C14 802B61E4 00000000 */  nop
/* E28C18 802B61E8 45000006 */  bc1f      .L802B6204
/* E28C1C 802B61EC 46001106 */   mov.s    $f4, $f2
/* E28C20 802B61F0 3C01BDCC */  lui       $at, 0xbdcc
/* E28C24 802B61F4 3421CCCD */  ori       $at, $at, 0xcccd
/* E28C28 802B61F8 44811000 */  mtc1      $at, $f2
/* E28C2C 802B61FC 00000000 */  nop
/* E28C30 802B6200 46001106 */  mov.s     $f4, $f2
.L802B6204:
/* E28C34 802B6204 46003021 */  cvt.d.s   $f0, $f6
/* E28C38 802B6208 3C01802B */  lui       $at, %hi(D_802B6768_E29198)
/* E28C3C 802B620C D4226768 */  ldc1      $f2, %lo(D_802B6768_E29198)($at)
.L802B6210:
/* E28C40 802B6210 46200005 */  abs.d     $f0, $f0
/* E28C44 802B6214 4622003C */  c.lt.d    $f0, $f2
/* E28C48 802B6218 00000000 */  nop
/* E28C4C 802B621C 4500000F */  bc1f      .L802B625C
/* E28C50 802B6220 0240202D */   daddu    $a0, $s2, $zero
/* E28C54 802B6224 44800000 */  mtc1      $zero, $f0
/* E28C58 802B6228 3C013DCC */  lui       $at, 0x3dcc
/* E28C5C 802B622C 3421CCCD */  ori       $at, $at, 0xcccd
/* E28C60 802B6230 44811000 */  mtc1      $at, $f2
/* E28C64 802B6234 4600303C */  c.lt.s    $f6, $f0
/* E28C68 802B6238 00000000 */  nop
/* E28C6C 802B623C 45000007 */  bc1f      .L802B625C
/* E28C70 802B6240 46001186 */   mov.s    $f6, $f2
/* E28C74 802B6244 3C01BDCC */  lui       $at, 0xbdcc
/* E28C78 802B6248 3421CCCD */  ori       $at, $at, 0xcccd
/* E28C7C 802B624C 44811000 */  mtc1      $at, $f2
/* E28C80 802B6250 00000000 */  nop
/* E28C84 802B6254 46001186 */  mov.s     $f6, $f2
/* E28C88 802B6258 0240202D */  daddu     $a0, $s2, $zero
.L802B625C:
/* E28C8C 802B625C 27A50030 */  addiu     $a1, $sp, 0x30
/* E28C90 802B6260 C6420028 */  lwc1      $f2, 0x28($s2)
/* E28C94 802B6264 27A60034 */  addiu     $a2, $sp, 0x34
/* E28C98 802B6268 46041080 */  add.s     $f2, $f2, $f4
/* E28C9C 802B626C C6400030 */  lwc1      $f0, 0x30($s2)
/* E28CA0 802B6270 27A2003C */  addiu     $v0, $sp, 0x3c
/* E28CA4 802B6274 46060001 */  sub.s     $f0, $f0, $f6
/* E28CA8 802B6278 E6420028 */  swc1      $f2, 0x28($s2)
/* E28CAC 802B627C 46001186 */  mov.s     $f6, $f2
/* E28CB0 802B6280 E6400030 */  swc1      $f0, 0x30($s2)
/* E28CB4 802B6284 46000106 */  mov.s     $f4, $f0
/* E28CB8 802B6288 C642002C */  lwc1      $f2, 0x2c($s2)
/* E28CBC 802B628C 3C0140A0 */  lui       $at, 0x40a0
/* E28CC0 802B6290 44810000 */  mtc1      $at, $f0
/* E28CC4 802B6294 27A70038 */  addiu     $a3, $sp, 0x38
/* E28CC8 802B6298 E7A60030 */  swc1      $f6, 0x30($sp)
/* E28CCC 802B629C E7A40038 */  swc1      $f4, 0x38($sp)
/* E28CD0 802B62A0 E7A20034 */  swc1      $f2, 0x34($sp)
/* E28CD4 802B62A4 E7A0003C */  swc1      $f0, 0x3c($sp)
/* E28CD8 802B62A8 AFA20010 */  sw        $v0, 0x10($sp)
/* E28CDC 802B62AC 27A20040 */  addiu     $v0, $sp, 0x40
/* E28CE0 802B62B0 AFA20014 */  sw        $v0, 0x14($sp)
/* E28CE4 802B62B4 27A20044 */  addiu     $v0, $sp, 0x44
/* E28CE8 802B62B8 AFA20018 */  sw        $v0, 0x18($sp)
/* E28CEC 802B62BC 27A20048 */  addiu     $v0, $sp, 0x48
/* E28CF0 802B62C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* E28CF4 802B62C4 27A2004C */  addiu     $v0, $sp, 0x4c
/* E28CF8 802B62C8 0C03791B */  jal       func_800DE46C
/* E28CFC 802B62CC AFA20020 */   sw       $v0, 0x20($sp)
/* E28D00 802B62D0 04400003 */  bltz      $v0, .L802B62E0
/* E28D04 802B62D4 00000000 */   nop
/* E28D08 802B62D8 C7A00034 */  lwc1      $f0, 0x34($sp)
/* E28D0C 802B62DC E640002C */  swc1      $f0, 0x2c($s2)
.L802B62E0:
/* E28D10 802B62E0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E28D14 802B62E4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E28D18 802B62E8 3C014270 */  lui       $at, 0x4270
/* E28D1C 802B62EC 4481A000 */  mtc1      $at, $f20
/* E28D20 802B62F0 84430086 */  lh        $v1, 0x86($v0)
/* E28D24 802B62F4 2402000A */  addiu     $v0, $zero, 0xa
/* E28D28 802B62F8 14620003 */  bne       $v1, $v0, .L802B6308
/* E28D2C 802B62FC 00000000 */   nop
/* E28D30 802B6300 3C0141F0 */  lui       $at, 0x41f0
/* E28D34 802B6304 4481A000 */  mtc1      $at, $f20
.L802B6308:
/* E28D38 802B6308 3C018011 */  lui       $at, %hi(D_8010C990)
/* E28D3C 802B630C C420C990 */  lwc1      $f0, %lo(D_8010C990)($at)
/* E28D40 802B6310 4614003C */  c.lt.s    $f0, $f20
/* E28D44 802B6314 00000000 */  nop
/* E28D48 802B6318 45000005 */  bc1f      .L802B6330
/* E28D4C 802B631C 00000000 */   nop
/* E28D50 802B6320 0C039769 */  jal       set_action_state
/* E28D54 802B6324 24040008 */   addiu    $a0, $zero, 8
/* E28D58 802B6328 0C038C1B */  jal       gravity_use_fall_parms
/* E28D5C 802B632C 00000000 */   nop
.L802B6330:
/* E28D60 802B6330 8FBF005C */  lw        $ra, 0x5c($sp)
/* E28D64 802B6334 8FB20058 */  lw        $s2, 0x58($sp)
/* E28D68 802B6338 8FB10054 */  lw        $s1, 0x54($sp)
/* E28D6C 802B633C 8FB00050 */  lw        $s0, 0x50($sp)
/* E28D70 802B6340 D7B60068 */  ldc1      $f22, 0x68($sp)
/* E28D74 802B6344 D7B40060 */  ldc1      $f20, 0x60($sp)
/* E28D78 802B6348 03E00008 */  jr        $ra
/* E28D7C 802B634C 27BD0070 */   addiu    $sp, $sp, 0x70
