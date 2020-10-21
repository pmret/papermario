.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241150_B4BBC0
/* B4BBC0 80241150 27BDFF90 */  addiu     $sp, $sp, -0x70
/* B4BBC4 80241154 AFB40050 */  sw        $s4, 0x50($sp)
/* B4BBC8 80241158 0080A02D */  daddu     $s4, $a0, $zero
/* B4BBCC 8024115C AFBF0060 */  sw        $ra, 0x60($sp)
/* B4BBD0 80241160 AFB7005C */  sw        $s7, 0x5c($sp)
/* B4BBD4 80241164 AFB60058 */  sw        $s6, 0x58($sp)
/* B4BBD8 80241168 AFB50054 */  sw        $s5, 0x54($sp)
/* B4BBDC 8024116C AFB3004C */  sw        $s3, 0x4c($sp)
/* B4BBE0 80241170 AFB20048 */  sw        $s2, 0x48($sp)
/* B4BBE4 80241174 AFB10044 */  sw        $s1, 0x44($sp)
/* B4BBE8 80241178 AFB00040 */  sw        $s0, 0x40($sp)
/* B4BBEC 8024117C F7B40068 */  sdc1      $f20, 0x68($sp)
/* B4BBF0 80241180 8E950148 */  lw        $s5, 0x148($s4)
/* B4BBF4 80241184 00A0B02D */  daddu     $s6, $a1, $zero
/* B4BBF8 80241188 86A40008 */  lh        $a0, 8($s5)
/* B4BBFC 8024118C 0C00EABB */  jal       get_npc_unsafe
/* B4BC00 80241190 00C0B82D */   daddu    $s7, $a2, $zero
/* B4BC04 80241194 0040982D */  daddu     $s3, $v0, $zero
/* B4BC08 80241198 C6600018 */  lwc1      $f0, 0x18($s3)
/* B4BC0C 8024119C 44801000 */  mtc1      $zero, $f2
/* B4BC10 802411A0 44801800 */  mtc1      $zero, $f3
/* B4BC14 802411A4 46000021 */  cvt.d.s   $f0, $f0
/* B4BC18 802411A8 4620103C */  c.lt.d    $f2, $f0
/* B4BC1C 802411AC 00000000 */  nop       
/* B4BC20 802411B0 45000021 */  bc1f      .L80241238
/* B4BC24 802411B4 27A50028 */   addiu    $a1, $sp, 0x28
/* B4BC28 802411B8 C6600038 */  lwc1      $f0, 0x38($s3)
/* B4BC2C 802411BC C662003C */  lwc1      $f2, 0x3c($s3)
/* B4BC30 802411C0 C6640040 */  lwc1      $f4, 0x40($s3)
/* B4BC34 802411C4 C6660018 */  lwc1      $f6, 0x18($s3)
/* B4BC38 802411C8 E7A00028 */  swc1      $f0, 0x28($sp)
/* B4BC3C 802411CC E7A2002C */  swc1      $f2, 0x2c($sp)
/* B4BC40 802411D0 E7A40030 */  swc1      $f4, 0x30($sp)
/* B4BC44 802411D4 E7A60010 */  swc1      $f6, 0x10($sp)
/* B4BC48 802411D8 C660000C */  lwc1      $f0, 0xc($s3)
/* B4BC4C 802411DC E7A00014 */  swc1      $f0, 0x14($sp)
/* B4BC50 802411E0 866200A8 */  lh        $v0, 0xa8($s3)
/* B4BC54 802411E4 44820000 */  mtc1      $v0, $f0
/* B4BC58 802411E8 00000000 */  nop       
/* B4BC5C 802411EC 46800020 */  cvt.s.w   $f0, $f0
/* B4BC60 802411F0 E7A00018 */  swc1      $f0, 0x18($sp)
/* B4BC64 802411F4 866200A6 */  lh        $v0, 0xa6($s3)
/* B4BC68 802411F8 27A6002C */  addiu     $a2, $sp, 0x2c
/* B4BC6C 802411FC 44820000 */  mtc1      $v0, $f0
/* B4BC70 80241200 00000000 */  nop       
/* B4BC74 80241204 46800020 */  cvt.s.w   $f0, $f0
/* B4BC78 80241208 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B4BC7C 8024120C 8E640080 */  lw        $a0, 0x80($s3)
/* B4BC80 80241210 0C037711 */  jal       func_800DDC44
/* B4BC84 80241214 27A70030 */   addiu    $a3, $sp, 0x30
/* B4BC88 80241218 10400003 */  beqz      $v0, .L80241228
/* B4BC8C 8024121C 00000000 */   nop      
/* B4BC90 80241220 0809048E */  j         .L80241238
/* B4BC94 80241224 AE600018 */   sw       $zero, 0x18($s3)
.L80241228:
/* B4BC98 80241228 8E650018 */  lw        $a1, 0x18($s3)
/* B4BC9C 8024122C 8E66000C */  lw        $a2, 0xc($s3)
/* B4BCA0 80241230 0C00EA95 */  jal       npc_move_heading
/* B4BCA4 80241234 0260202D */   daddu    $a0, $s3, $zero
.L80241238:
/* B4BCA8 80241238 C660001C */  lwc1      $f0, 0x1c($s3)
/* B4BCAC 8024123C 44801000 */  mtc1      $zero, $f2
/* B4BCB0 80241240 44801800 */  mtc1      $zero, $f3
/* B4BCB4 80241244 46000021 */  cvt.d.s   $f0, $f0
/* B4BCB8 80241248 4622003C */  c.lt.d    $f0, $f2
/* B4BCBC 8024124C 00000000 */  nop       
/* B4BCC0 80241250 4500006C */  bc1f      .L80241404
/* B4BCC4 80241254 27B00028 */   addiu    $s0, $sp, 0x28
/* B4BCC8 80241258 0200282D */  daddu     $a1, $s0, $zero
/* B4BCCC 8024125C 27A60034 */  addiu     $a2, $sp, 0x34
/* B4BCD0 80241260 27B20038 */  addiu     $s2, $sp, 0x38
/* B4BCD4 80241264 C6600038 */  lwc1      $f0, 0x38($s3)
/* B4BCD8 80241268 3C0142C8 */  lui       $at, 0x42c8
/* B4BCDC 8024126C 44811000 */  mtc1      $at, $f2
/* B4BCE0 80241270 C6640040 */  lwc1      $f4, 0x40($s3)
/* B4BCE4 80241274 3C01447A */  lui       $at, 0x447a
/* B4BCE8 80241278 44813000 */  mtc1      $at, $f6
/* B4BCEC 8024127C 27B10030 */  addiu     $s1, $sp, 0x30
/* B4BCF0 80241280 E7A00028 */  swc1      $f0, 0x28($sp)
/* B4BCF4 80241284 E7A20034 */  swc1      $f2, 0x34($sp)
/* B4BCF8 80241288 E7A40030 */  swc1      $f4, 0x30($sp)
/* B4BCFC 8024128C E7A60038 */  swc1      $f6, 0x38($sp)
/* B4BD00 80241290 AFB20010 */  sw        $s2, 0x10($sp)
/* B4BD04 80241294 8E640080 */  lw        $a0, 0x80($s3)
/* B4BD08 80241298 0C0372DF */  jal       func_800DCB7C
/* B4BD0C 8024129C 0220382D */   daddu    $a3, $s1, $zero
/* B4BD10 802412A0 0200282D */  daddu     $a1, $s0, $zero
/* B4BD14 802412A4 27A6002C */  addiu     $a2, $sp, 0x2c
/* B4BD18 802412A8 C662003C */  lwc1      $f2, 0x3c($s3)
/* B4BD1C 802412AC C6660038 */  lwc1      $f6, 0x38($s3)
/* B4BD20 802412B0 3C01402A */  lui       $at, 0x402a
/* B4BD24 802412B4 4481A800 */  mtc1      $at, $f21
/* B4BD28 802412B8 4480A000 */  mtc1      $zero, $f20
/* B4BD2C 802412BC 460010A1 */  cvt.d.s   $f2, $f2
/* B4BD30 802412C0 46341080 */  add.d     $f2, $f2, $f20
/* B4BD34 802412C4 C660001C */  lwc1      $f0, 0x1c($s3)
/* B4BD38 802412C8 C6640040 */  lwc1      $f4, 0x40($s3)
/* B4BD3C 802412CC 46000005 */  abs.s     $f0, $f0
/* B4BD40 802412D0 E7A40030 */  swc1      $f4, 0x30($sp)
/* B4BD44 802412D4 3C014030 */  lui       $at, 0x4030
/* B4BD48 802412D8 44812800 */  mtc1      $at, $f5
/* B4BD4C 802412DC 44802000 */  mtc1      $zero, $f4
/* B4BD50 802412E0 46000021 */  cvt.d.s   $f0, $f0
/* B4BD54 802412E4 E7A60028 */  swc1      $f6, 0x28($sp)
/* B4BD58 802412E8 46240000 */  add.d     $f0, $f0, $f4
/* B4BD5C 802412EC 462010A0 */  cvt.s.d   $f2, $f2
/* B4BD60 802412F0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* B4BD64 802412F4 46200020 */  cvt.s.d   $f0, $f0
/* B4BD68 802412F8 E7A00038 */  swc1      $f0, 0x38($sp)
/* B4BD6C 802412FC AFB20010 */  sw        $s2, 0x10($sp)
/* B4BD70 80241300 8E640080 */  lw        $a0, 0x80($s3)
/* B4BD74 80241304 0C0372DF */  jal       func_800DCB7C
/* B4BD78 80241308 0220382D */   daddu    $a3, $s1, $zero
/* B4BD7C 8024130C 1040003D */  beqz      $v0, .L80241404
/* B4BD80 80241310 00000000 */   nop      
/* B4BD84 80241314 C660001C */  lwc1      $f0, 0x1c($s3)
/* B4BD88 80241318 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B4BD8C 8024131C 46000005 */  abs.s     $f0, $f0
/* B4BD90 80241320 46000021 */  cvt.d.s   $f0, $f0
/* B4BD94 80241324 46340000 */  add.d     $f0, $f0, $f20
/* B4BD98 80241328 460010A1 */  cvt.d.s   $f2, $f2
/* B4BD9C 8024132C 4620103E */  c.le.d    $f2, $f0
/* B4BDA0 80241330 00000000 */  nop       
/* B4BDA4 80241334 45000033 */  bc1f      .L80241404
/* B4BDA8 80241338 2403F7FF */   addiu    $v1, $zero, -0x801
/* B4BDAC 8024133C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B4BDB0 80241340 8E620000 */  lw        $v0, ($s3)
/* B4BDB4 80241344 AE60001C */  sw        $zero, 0x1c($s3)
/* B4BDB8 80241348 00431024 */  and       $v0, $v0, $v1
/* B4BDBC 8024134C E660003C */  swc1      $f0, 0x3c($s3)
/* B4BDC0 80241350 AE620000 */  sw        $v0, ($s3)
/* B4BDC4 80241354 AFA00010 */  sw        $zero, 0x10($sp)
/* B4BDC8 80241358 AFA00014 */  sw        $zero, 0x14($sp)
/* B4BDCC 8024135C 8E650038 */  lw        $a1, 0x38($s3)
/* B4BDD0 80241360 8E66003C */  lw        $a2, 0x3c($s3)
/* B4BDD4 80241364 8E670040 */  lw        $a3, 0x40($s3)
/* B4BDD8 80241368 0C01BECC */  jal       fx_walk_normal
/* B4BDDC 8024136C 24040002 */   addiu    $a0, $zero, 2
/* B4BDE0 80241370 02E0202D */  daddu     $a0, $s7, $zero
/* B4BDE4 80241374 2402000C */  addiu     $v0, $zero, 0xc
/* B4BDE8 80241378 AE820070 */  sw        $v0, 0x70($s4)
/* B4BDEC 8024137C 24020001 */  addiu     $v0, $zero, 1
/* B4BDF0 80241380 AFA20010 */  sw        $v0, 0x10($sp)
/* B4BDF4 80241384 8EC60024 */  lw        $a2, 0x24($s6)
/* B4BDF8 80241388 8EC70028 */  lw        $a3, 0x28($s6)
/* B4BDFC 8024138C 0C01242D */  jal       func_800490B4
/* B4BE00 80241390 02A0282D */   daddu    $a1, $s5, $zero
/* B4BE04 80241394 14400022 */  bnez      $v0, .L80241420
/* B4BE08 80241398 24040002 */   addiu    $a0, $zero, 2
/* B4BE0C 8024139C 0260282D */  daddu     $a1, $s3, $zero
/* B4BE10 802413A0 0000302D */  daddu     $a2, $zero, $zero
/* B4BE14 802413A4 866300A8 */  lh        $v1, 0xa8($s3)
/* B4BE18 802413A8 3C013F80 */  lui       $at, 0x3f80
/* B4BE1C 802413AC 44810000 */  mtc1      $at, $f0
/* B4BE20 802413B0 3C014000 */  lui       $at, 0x4000
/* B4BE24 802413B4 44811000 */  mtc1      $at, $f2
/* B4BE28 802413B8 3C01C1A0 */  lui       $at, 0xc1a0
/* B4BE2C 802413BC 44812000 */  mtc1      $at, $f4
/* B4BE30 802413C0 2402000F */  addiu     $v0, $zero, 0xf
/* B4BE34 802413C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* B4BE38 802413C8 44834000 */  mtc1      $v1, $f8
/* B4BE3C 802413CC 00000000 */  nop       
/* B4BE40 802413D0 46804220 */  cvt.s.w   $f8, $f8
/* B4BE44 802413D4 44074000 */  mfc1      $a3, $f8
/* B4BE48 802413D8 27A2003C */  addiu     $v0, $sp, 0x3c
/* B4BE4C 802413DC AFA20020 */  sw        $v0, 0x20($sp)
/* B4BE50 802413E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* B4BE54 802413E4 E7A20014 */  swc1      $f2, 0x14($sp)
/* B4BE58 802413E8 0C01BFA4 */  jal       fx_emote
/* B4BE5C 802413EC E7A40018 */   swc1     $f4, 0x18($sp)
/* B4BE60 802413F0 24020019 */  addiu     $v0, $zero, 0x19
/* B4BE64 802413F4 A662008E */  sh        $v0, 0x8e($s3)
/* B4BE68 802413F8 2402000E */  addiu     $v0, $zero, 0xe
/* B4BE6C 802413FC 08090508 */  j         .L80241420
/* B4BE70 80241400 AE820070 */   sw       $v0, 0x70($s4)
.L80241404:
/* B4BE74 80241404 C664003C */  lwc1      $f4, 0x3c($s3)
/* B4BE78 80241408 C660001C */  lwc1      $f0, 0x1c($s3)
/* B4BE7C 8024140C 46002100 */  add.s     $f4, $f4, $f0
/* B4BE80 80241410 C6620014 */  lwc1      $f2, 0x14($s3)
/* B4BE84 80241414 46020001 */  sub.s     $f0, $f0, $f2
/* B4BE88 80241418 E664003C */  swc1      $f4, 0x3c($s3)
/* B4BE8C 8024141C E660001C */  swc1      $f0, 0x1c($s3)
.L80241420:
/* B4BE90 80241420 8FBF0060 */  lw        $ra, 0x60($sp)
/* B4BE94 80241424 8FB7005C */  lw        $s7, 0x5c($sp)
/* B4BE98 80241428 8FB60058 */  lw        $s6, 0x58($sp)
/* B4BE9C 8024142C 8FB50054 */  lw        $s5, 0x54($sp)
/* B4BEA0 80241430 8FB40050 */  lw        $s4, 0x50($sp)
/* B4BEA4 80241434 8FB3004C */  lw        $s3, 0x4c($sp)
/* B4BEA8 80241438 8FB20048 */  lw        $s2, 0x48($sp)
/* B4BEAC 8024143C 8FB10044 */  lw        $s1, 0x44($sp)
/* B4BEB0 80241440 8FB00040 */  lw        $s0, 0x40($sp)
/* B4BEB4 80241444 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B4BEB8 80241448 03E00008 */  jr        $ra
/* B4BEBC 8024144C 27BD0070 */   addiu    $sp, $sp, 0x70
