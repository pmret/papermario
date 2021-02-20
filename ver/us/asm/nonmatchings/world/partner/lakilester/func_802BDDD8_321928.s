.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDDD8_321928
/* 321928 802BDDD8 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 32192C 802BDDDC AFB20060 */  sw        $s2, 0x60($sp)
/* 321930 802BDDE0 0080902D */  daddu     $s2, $a0, $zero
/* 321934 802BDDE4 27A40028 */  addiu     $a0, $sp, 0x28
/* 321938 802BDDE8 F7B40078 */  sdc1      $f20, 0x78($sp)
/* 32193C 802BDDEC 4480A000 */  mtc1      $zero, $f20
/* 321940 802BDDF0 27A5002C */  addiu     $a1, $sp, 0x2c
/* 321944 802BDDF4 AFBF0070 */  sw        $ra, 0x70($sp)
/* 321948 802BDDF8 AFB5006C */  sw        $s5, 0x6c($sp)
/* 32194C 802BDDFC AFB40068 */  sw        $s4, 0x68($sp)
/* 321950 802BDE00 AFB30064 */  sw        $s3, 0x64($sp)
/* 321954 802BDE04 AFB1005C */  sw        $s1, 0x5c($sp)
/* 321958 802BDE08 AFB00058 */  sw        $s0, 0x58($sp)
/* 32195C 802BDE0C E7B40028 */  swc1      $f20, 0x28($sp)
/* 321960 802BDE10 0C0AF5AF */  jal       func_802BD6BC_32120C
/* 321964 802BDE14 E7B4002C */   swc1     $f20, 0x2c($sp)
/* 321968 802BDE18 86440084 */  lh        $a0, 0x84($s2)
/* 32196C 802BDE1C 0C016F6A */  jal       get_collider_type_by_id
/* 321970 802BDE20 00000000 */   nop
/* 321974 802BDE24 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* 321978 802BDE28 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* 32197C 802BDE2C 3C158016 */  lui       $s5, %hi(gCollisionStatus)
/* 321980 802BDE30 26B5A550 */  addiu     $s5, $s5, %lo(gCollisionStatus)
/* 321984 802BDE34 304200FF */  andi      $v0, $v0, 0xff
/* 321988 802BDE38 24030003 */  addiu     $v1, $zero, 3
/* 32198C 802BDE3C 14430008 */  bne       $v0, $v1, .L802BDE60
/* 321990 802BDE40 00000000 */   nop
/* 321994 802BDE44 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 321998 802BDE48 3C013F00 */  lui       $at, 0x3f00
/* 32199C 802BDE4C 44811000 */  mtc1      $at, $f2
/* 3219A0 802BDE50 00000000 */  nop
/* 3219A4 802BDE54 46020002 */  mul.s     $f0, $f0, $f2
/* 3219A8 802BDE58 00000000 */  nop
/* 3219AC 802BDE5C E7A0002C */  swc1      $f0, 0x2c($sp)
.L802BDE60:
/* 3219B0 802BDE60 3C01802C */  lui       $at, %hi(D_802BFF28)
/* 3219B4 802BDE64 C422FF28 */  lwc1      $f2, %lo(D_802BFF28)($at)
/* 3219B8 802BDE68 3C0141A0 */  lui       $at, 0x41a0
/* 3219BC 802BDE6C 44810000 */  mtc1      $at, $f0
/* 3219C0 802BDE70 00000000 */  nop
/* 3219C4 802BDE74 4602003E */  c.le.s    $f0, $f2
/* 3219C8 802BDE78 00000000 */  nop
/* 3219CC 802BDE7C 45000009 */  bc1f      .L802BDEA4
/* 3219D0 802BDE80 00000000 */   nop
/* 3219D4 802BDE84 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 3219D8 802BDE88 3C013F4C */  lui       $at, 0x3f4c
/* 3219DC 802BDE8C 3421CCCD */  ori       $at, $at, 0xcccd
/* 3219E0 802BDE90 44811000 */  mtc1      $at, $f2
/* 3219E4 802BDE94 00000000 */  nop
/* 3219E8 802BDE98 46020002 */  mul.s     $f0, $f0, $f2
/* 3219EC 802BDE9C 00000000 */  nop
/* 3219F0 802BDEA0 E7A0002C */  swc1      $f0, 0x2c($sp)
.L802BDEA4:
/* 3219F4 802BDEA4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 3219F8 802BDEA8 46140032 */  c.eq.s    $f0, $f20
/* 3219FC 802BDEAC 00000000 */  nop
/* 321A00 802BDEB0 45010026 */  bc1t      .L802BDF4C
/* 321A04 802BDEB4 E6400018 */   swc1     $f0, 0x18($s2)
/* 321A08 802BDEB8 3C02802C */  lui       $v0, %hi(D_802BFF1C)
/* 321A0C 802BDEBC 2442FF1C */  addiu     $v0, $v0, %lo(D_802BFF1C)
/* 321A10 802BDEC0 3C07802C */  lui       $a3, %hi(D_802BFF20)
/* 321A14 802BDEC4 24E7FF20 */  addiu     $a3, $a3, %lo(D_802BFF20)
/* 321A18 802BDEC8 8C430000 */  lw        $v1, ($v0)
/* 321A1C 802BDECC 8CE40000 */  lw        $a0, ($a3)
/* 321A20 802BDED0 24630001 */  addiu     $v1, $v1, 1
/* 321A24 802BDED4 AC430000 */  sw        $v1, ($v0)
/* 321A28 802BDED8 24820001 */  addiu     $v0, $a0, 1
/* 321A2C 802BDEDC 30630007 */  andi      $v1, $v1, 7
/* 321A30 802BDEE0 1460001A */  bnez      $v1, .L802BDF4C
/* 321A34 802BDEE4 ACE20000 */   sw       $v0, ($a3)
/* 321A38 802BDEE8 28420078 */  slti      $v0, $v0, 0x78
/* 321A3C 802BDEEC 50400001 */  beql      $v0, $zero, .L802BDEF4
/* 321A40 802BDEF0 ACE00000 */   sw       $zero, ($a3)
.L802BDEF4:
/* 321A44 802BDEF4 8CE70000 */  lw        $a3, ($a3)
/* 321A48 802BDEF8 28E2003C */  slti      $v0, $a3, 0x3c
/* 321A4C 802BDEFC 10400005 */  beqz      $v0, .L802BDF14
/* 321A50 802BDF00 0000202D */   daddu    $a0, $zero, $zero
/* 321A54 802BDF04 4405A000 */  mfc1      $a1, $f20
/* 321A58 802BDF08 3C0642C8 */  lui       $a2, 0x42c8
/* 321A5C 802BDF0C 080AF7C9 */  j         .L802BDF24
/* 321A60 802BDF10 2402003C */   addiu    $v0, $zero, 0x3c
.L802BDF14:
/* 321A64 802BDF14 24E7FFC4 */  addiu     $a3, $a3, -0x3c
/* 321A68 802BDF18 3C0542C8 */  lui       $a1, 0x42c8
/* 321A6C 802BDF1C 4406A000 */  mfc1      $a2, $f20
/* 321A70 802BDF20 2402003C */  addiu     $v0, $zero, 0x3c
.L802BDF24:
/* 321A74 802BDF24 0C00A8ED */  jal       update_lerp
/* 321A78 802BDF28 AFA20010 */   sw       $v0, 0x10($sp)
/* 321A7C 802BDF2C 4600028D */  trunc.w.s $f10, $f0
/* 321A80 802BDF30 44075000 */  mfc1      $a3, $f10
/* 321A84 802BDF34 24040295 */  addiu     $a0, $zero, 0x295
/* 321A88 802BDF38 0000282D */  daddu     $a1, $zero, $zero
/* 321A8C 802BDF3C 24060040 */  addiu     $a2, $zero, 0x40
/* 321A90 802BDF40 00073C00 */  sll       $a3, $a3, 0x10
/* 321A94 802BDF44 0C0526AE */  jal       _play_sound
/* 321A98 802BDF48 00073C03 */   sra      $a3, $a3, 0x10
.L802BDF4C:
/* 321A9C 802BDF4C C6400038 */  lwc1      $f0, 0x38($s2)
/* 321AA0 802BDF50 C6420064 */  lwc1      $f2, 0x64($s2)
/* 321AA4 802BDF54 C6440040 */  lwc1      $f4, 0x40($s2)
/* 321AA8 802BDF58 864200A6 */  lh        $v0, 0xa6($s2)
/* 321AAC 802BDF5C E7A00030 */  swc1      $f0, 0x30($sp)
/* 321AB0 802BDF60 44820000 */  mtc1      $v0, $f0
/* 321AB4 802BDF64 00000000 */  nop
/* 321AB8 802BDF68 46800020 */  cvt.s.w   $f0, $f0
/* 321ABC 802BDF6C E7A20034 */  swc1      $f2, 0x34($sp)
/* 321AC0 802BDF70 E7A40038 */  swc1      $f4, 0x38($sp)
/* 321AC4 802BDF74 E7A00010 */  swc1      $f0, 0x10($sp)
/* 321AC8 802BDF78 C640000C */  lwc1      $f0, 0xc($s2)
/* 321ACC 802BDF7C E7A00014 */  swc1      $f0, 0x14($sp)
/* 321AD0 802BDF80 864200A8 */  lh        $v0, 0xa8($s2)
/* 321AD4 802BDF84 27A50030 */  addiu     $a1, $sp, 0x30
/* 321AD8 802BDF88 44820000 */  mtc1      $v0, $f0
/* 321ADC 802BDF8C 00000000 */  nop
/* 321AE0 802BDF90 46800020 */  cvt.s.w   $f0, $f0
/* 321AE4 802BDF94 E7A00018 */  swc1      $f0, 0x18($sp)
/* 321AE8 802BDF98 864200A6 */  lh        $v0, 0xa6($s2)
/* 321AEC 802BDF9C 27A60034 */  addiu     $a2, $sp, 0x34
/* 321AF0 802BDFA0 44820000 */  mtc1      $v0, $f0
/* 321AF4 802BDFA4 00000000 */  nop
/* 321AF8 802BDFA8 46800020 */  cvt.s.w   $f0, $f0
/* 321AFC 802BDFAC E7A0001C */  swc1      $f0, 0x1c($sp)
/* 321B00 802BDFB0 8E440080 */  lw        $a0, 0x80($s2)
/* 321B04 802BDFB4 0C0376B9 */  jal       func_800DDAE4
/* 321B08 802BDFB8 27A70038 */   addiu    $a3, $sp, 0x38
/* 321B0C 802BDFBC 1040000D */  beqz      $v0, .L802BDFF4
/* 321B10 802BDFC0 00000000 */   nop
/* 321B14 802BDFC4 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 321B18 802BDFC8 2442EBB0 */  addiu     $v0, $v0, %lo(D_8010EBB0)
/* 321B1C 802BDFCC 8C42000C */  lw        $v0, 0xc($v0)
/* 321B20 802BDFD0 30428000 */  andi      $v0, $v0, 0x8000
/* 321B24 802BDFD4 10400005 */  beqz      $v0, .L802BDFEC
/* 321B28 802BDFD8 26A3000A */   addiu    $v1, $s5, 0xa
/* 321B2C 802BDFDC 3C028011 */  lui       $v0, %hi(D_8010C97A)
/* 321B30 802BDFE0 9442C97A */  lhu       $v0, %lo(D_8010C97A)($v0)
/* 321B34 802BDFE4 080AF7FD */  j         .L802BDFF4
/* 321B38 802BDFE8 A4620000 */   sh       $v0, ($v1)
.L802BDFEC:
/* 321B3C 802BDFEC 2402FFFF */  addiu     $v0, $zero, -1
/* 321B40 802BDFF0 A4620000 */  sh        $v0, ($v1)
.L802BDFF4:
/* 321B44 802BDFF4 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 321B48 802BDFF8 44800000 */  mtc1      $zero, $f0
/* 321B4C 802BDFFC 00000000 */  nop
/* 321B50 802BE000 46001032 */  c.eq.s    $f2, $f0
/* 321B54 802BE004 00000000 */  nop
/* 321B58 802BE008 4501009E */  bc1t      .L802BE284
/* 321B5C 802BE00C 27B30030 */   addiu    $s3, $sp, 0x30
/* 321B60 802BE010 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 321B64 802BE014 C6420038 */  lwc1      $f2, 0x38($s2)
/* 321B68 802BE018 C6440064 */  lwc1      $f4, 0x64($s2)
/* 321B6C 802BE01C C6460040 */  lwc1      $f6, 0x40($s2)
/* 321B70 802BE020 C6480018 */  lwc1      $f8, 0x18($s2)
/* 321B74 802BE024 E640000C */  swc1      $f0, 0xc($s2)
/* 321B78 802BE028 E7A20030 */  swc1      $f2, 0x30($sp)
/* 321B7C 802BE02C E7A40034 */  swc1      $f4, 0x34($sp)
/* 321B80 802BE030 E7A60038 */  swc1      $f6, 0x38($sp)
/* 321B84 802BE034 E7A80010 */  swc1      $f8, 0x10($sp)
/* 321B88 802BE038 C640000C */  lwc1      $f0, 0xc($s2)
/* 321B8C 802BE03C E7A00014 */  swc1      $f0, 0x14($sp)
/* 321B90 802BE040 864200A8 */  lh        $v0, 0xa8($s2)
/* 321B94 802BE044 27A50030 */  addiu     $a1, $sp, 0x30
/* 321B98 802BE048 44820000 */  mtc1      $v0, $f0
/* 321B9C 802BE04C 00000000 */  nop
/* 321BA0 802BE050 46800020 */  cvt.s.w   $f0, $f0
/* 321BA4 802BE054 E7A00018 */  swc1      $f0, 0x18($sp)
/* 321BA8 802BE058 864200A6 */  lh        $v0, 0xa6($s2)
/* 321BAC 802BE05C 27A60034 */  addiu     $a2, $sp, 0x34
/* 321BB0 802BE060 44820000 */  mtc1      $v0, $f0
/* 321BB4 802BE064 00000000 */  nop
/* 321BB8 802BE068 46800020 */  cvt.s.w   $f0, $f0
/* 321BBC 802BE06C E7A0001C */  swc1      $f0, 0x1c($sp)
/* 321BC0 802BE070 8E440080 */  lw        $a0, 0x80($s2)
/* 321BC4 802BE074 0C037765 */  jal       func_800DDD94
/* 321BC8 802BE078 27A70038 */   addiu    $a3, $sp, 0x38
/* 321BCC 802BE07C 10400017 */  beqz      $v0, .L802BE0DC
/* 321BD0 802BE080 00000000 */   nop
/* 321BD4 802BE084 3C02802C */  lui       $v0, %hi(D_802BFF10)
/* 321BD8 802BE088 8C42FF10 */  lw        $v0, %lo(D_802BFF10)($v0)
/* 321BDC 802BE08C 10400004 */  beqz      $v0, .L802BE0A0
/* 321BE0 802BE090 00000000 */   nop
/* 321BE4 802BE094 3C028011 */  lui       $v0, %hi(D_8010C97A)
/* 321BE8 802BE098 9442C97A */  lhu       $v0, %lo(D_8010C97A)($v0)
/* 321BEC 802BE09C A6A20000 */  sh        $v0, ($s5)
.L802BE0A0:
/* 321BF0 802BE0A0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 321BF4 802BE0A4 C6460038 */  lwc1      $f6, 0x38($s2)
/* 321BF8 802BE0A8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 321BFC 802BE0AC 46060001 */  sub.s     $f0, $f0, $f6
/* 321C00 802BE0B0 C6440040 */  lwc1      $f4, 0x40($s2)
/* 321C04 802BE0B4 3C0140A0 */  lui       $at, 0x40a0
/* 321C08 802BE0B8 44814000 */  mtc1      $at, $f8
/* 321C0C 802BE0BC 46041081 */  sub.s     $f2, $f2, $f4
/* 321C10 802BE0C0 46080003 */  div.s     $f0, $f0, $f8
/* 321C14 802BE0C4 46003180 */  add.s     $f6, $f6, $f0
/* 321C18 802BE0C8 46081083 */  div.s     $f2, $f2, $f8
/* 321C1C 802BE0CC 46022100 */  add.s     $f4, $f4, $f2
/* 321C20 802BE0D0 E6460038 */  swc1      $f6, 0x38($s2)
/* 321C24 802BE0D4 080AF840 */  j         .L802BE100
/* 321C28 802BE0D8 E6440040 */   swc1     $f4, 0x40($s2)
.L802BE0DC:
/* 321C2C 802BE0DC 8E450018 */  lw        $a1, 0x18($s2)
/* 321C30 802BE0E0 8FA60028 */  lw        $a2, 0x28($sp)
/* 321C34 802BE0E4 0C00EA95 */  jal       npc_move_heading
/* 321C38 802BE0E8 0240202D */   daddu    $a0, $s2, $zero
/* 321C3C 802BE0EC 3C02802C */  lui       $v0, %hi(D_802BFF10)
/* 321C40 802BE0F0 8C42FF10 */  lw        $v0, %lo(D_802BFF10)($v0)
/* 321C44 802BE0F4 10400002 */  beqz      $v0, .L802BE100
/* 321C48 802BE0F8 2402FFFF */   addiu    $v0, $zero, -1
/* 321C4C 802BE0FC A6A20000 */  sh        $v0, ($s5)
.L802BE100:
/* 321C50 802BE100 C64C000C */  lwc1      $f12, 0xc($s2)
/* 321C54 802BE104 3C0141F0 */  lui       $at, 0x41f0
/* 321C58 802BE108 4481A000 */  mtc1      $at, $f20
/* 321C5C 802BE10C 0C00A6C9 */  jal       clamp_angle
/* 321C60 802BE110 46146301 */   sub.s    $f12, $f12, $f20
/* 321C64 802BE114 27B30030 */  addiu     $s3, $sp, 0x30
/* 321C68 802BE118 0260282D */  daddu     $a1, $s3, $zero
/* 321C6C 802BE11C C6420038 */  lwc1      $f2, 0x38($s2)
/* 321C70 802BE120 C6440064 */  lwc1      $f4, 0x64($s2)
/* 321C74 802BE124 C6460040 */  lwc1      $f6, 0x40($s2)
/* 321C78 802BE128 C6480018 */  lwc1      $f8, 0x18($s2)
/* 321C7C 802BE12C 27B10034 */  addiu     $s1, $sp, 0x34
/* 321C80 802BE130 E7A00028 */  swc1      $f0, 0x28($sp)
/* 321C84 802BE134 E7A20030 */  swc1      $f2, 0x30($sp)
/* 321C88 802BE138 E7A40034 */  swc1      $f4, 0x34($sp)
/* 321C8C 802BE13C E7A60038 */  swc1      $f6, 0x38($sp)
/* 321C90 802BE140 E7A80010 */  swc1      $f8, 0x10($sp)
/* 321C94 802BE144 E7A00014 */  swc1      $f0, 0x14($sp)
/* 321C98 802BE148 864200A8 */  lh        $v0, 0xa8($s2)
/* 321C9C 802BE14C 0220302D */  daddu     $a2, $s1, $zero
/* 321CA0 802BE150 44820000 */  mtc1      $v0, $f0
/* 321CA4 802BE154 00000000 */  nop
/* 321CA8 802BE158 46800020 */  cvt.s.w   $f0, $f0
/* 321CAC 802BE15C E7A00018 */  swc1      $f0, 0x18($sp)
/* 321CB0 802BE160 864200A6 */  lh        $v0, 0xa6($s2)
/* 321CB4 802BE164 27B00038 */  addiu     $s0, $sp, 0x38
/* 321CB8 802BE168 44820000 */  mtc1      $v0, $f0
/* 321CBC 802BE16C 00000000 */  nop
/* 321CC0 802BE170 46800020 */  cvt.s.w   $f0, $f0
/* 321CC4 802BE174 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 321CC8 802BE178 8E440080 */  lw        $a0, 0x80($s2)
/* 321CCC 802BE17C 0C0376B9 */  jal       func_800DDAE4
/* 321CD0 802BE180 0200382D */   daddu    $a3, $s0, $zero
/* 321CD4 802BE184 1040000F */  beqz      $v0, .L802BE1C4
/* 321CD8 802BE188 00000000 */   nop
/* 321CDC 802BE18C C7A00030 */  lwc1      $f0, 0x30($sp)
/* 321CE0 802BE190 C6460038 */  lwc1      $f6, 0x38($s2)
/* 321CE4 802BE194 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 321CE8 802BE198 46060001 */  sub.s     $f0, $f0, $f6
/* 321CEC 802BE19C C6440040 */  lwc1      $f4, 0x40($s2)
/* 321CF0 802BE1A0 3C0140A0 */  lui       $at, 0x40a0
/* 321CF4 802BE1A4 44814000 */  mtc1      $at, $f8
/* 321CF8 802BE1A8 46041081 */  sub.s     $f2, $f2, $f4
/* 321CFC 802BE1AC 46080003 */  div.s     $f0, $f0, $f8
/* 321D00 802BE1B0 46003180 */  add.s     $f6, $f6, $f0
/* 321D04 802BE1B4 46081083 */  div.s     $f2, $f2, $f8
/* 321D08 802BE1B8 46022100 */  add.s     $f4, $f4, $f2
/* 321D0C 802BE1BC E6460038 */  swc1      $f6, 0x38($s2)
/* 321D10 802BE1C0 E6440040 */  swc1      $f4, 0x40($s2)
.L802BE1C4:
/* 321D14 802BE1C4 C64C000C */  lwc1      $f12, 0xc($s2)
/* 321D18 802BE1C8 0C00A6C9 */  jal       clamp_angle
/* 321D1C 802BE1CC 46146300 */   add.s    $f12, $f12, $f20
/* 321D20 802BE1D0 C6420038 */  lwc1      $f2, 0x38($s2)
/* 321D24 802BE1D4 C6440064 */  lwc1      $f4, 0x64($s2)
/* 321D28 802BE1D8 C6460040 */  lwc1      $f6, 0x40($s2)
/* 321D2C 802BE1DC C6480018 */  lwc1      $f8, 0x18($s2)
/* 321D30 802BE1E0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 321D34 802BE1E4 E7A20030 */  swc1      $f2, 0x30($sp)
/* 321D38 802BE1E8 E7A40034 */  swc1      $f4, 0x34($sp)
/* 321D3C 802BE1EC E7A60038 */  swc1      $f6, 0x38($sp)
/* 321D40 802BE1F0 E7A80010 */  swc1      $f8, 0x10($sp)
/* 321D44 802BE1F4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 321D48 802BE1F8 864200A8 */  lh        $v0, 0xa8($s2)
/* 321D4C 802BE1FC 0260282D */  daddu     $a1, $s3, $zero
/* 321D50 802BE200 44820000 */  mtc1      $v0, $f0
/* 321D54 802BE204 00000000 */  nop
/* 321D58 802BE208 46800020 */  cvt.s.w   $f0, $f0
/* 321D5C 802BE20C E7A00018 */  swc1      $f0, 0x18($sp)
/* 321D60 802BE210 864200A6 */  lh        $v0, 0xa6($s2)
/* 321D64 802BE214 0220302D */  daddu     $a2, $s1, $zero
/* 321D68 802BE218 44820000 */  mtc1      $v0, $f0
/* 321D6C 802BE21C 00000000 */  nop
/* 321D70 802BE220 46800020 */  cvt.s.w   $f0, $f0
/* 321D74 802BE224 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 321D78 802BE228 8E440080 */  lw        $a0, 0x80($s2)
/* 321D7C 802BE22C 0C0376B9 */  jal       func_800DDAE4
/* 321D80 802BE230 0200382D */   daddu    $a3, $s0, $zero
/* 321D84 802BE234 1040000F */  beqz      $v0, .L802BE274
/* 321D88 802BE238 0240202D */   daddu    $a0, $s2, $zero
/* 321D8C 802BE23C C7A00030 */  lwc1      $f0, 0x30($sp)
/* 321D90 802BE240 C6460038 */  lwc1      $f6, 0x38($s2)
/* 321D94 802BE244 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 321D98 802BE248 46060001 */  sub.s     $f0, $f0, $f6
/* 321D9C 802BE24C C6440040 */  lwc1      $f4, 0x40($s2)
/* 321DA0 802BE250 3C0140A0 */  lui       $at, 0x40a0
/* 321DA4 802BE254 44814000 */  mtc1      $at, $f8
/* 321DA8 802BE258 46041081 */  sub.s     $f2, $f2, $f4
/* 321DAC 802BE25C 46080003 */  div.s     $f0, $f0, $f8
/* 321DB0 802BE260 46003180 */  add.s     $f6, $f6, $f0
/* 321DB4 802BE264 46081083 */  div.s     $f2, $f2, $f8
/* 321DB8 802BE268 46022100 */  add.s     $f4, $f4, $f2
/* 321DBC 802BE26C E6460038 */  swc1      $f6, 0x38($s2)
/* 321DC0 802BE270 E6440040 */  swc1      $f4, 0x40($s2)
.L802BE274:
/* 321DC4 802BE274 0C00F598 */  jal       func_8003D660
/* 321DC8 802BE278 24050001 */   addiu    $a1, $zero, 1
/* 321DCC 802BE27C 080AF8F9 */  j         .L802BE3E4
/* 321DD0 802BE280 00000000 */   nop
.L802BE284:
/* 321DD4 802BE284 0260282D */  daddu     $a1, $s3, $zero
/* 321DD8 802BE288 3C0142B4 */  lui       $at, 0x42b4
/* 321DDC 802BE28C 44813000 */  mtc1      $at, $f6
/* 321DE0 802BE290 C6400038 */  lwc1      $f0, 0x38($s2)
/* 321DE4 802BE294 C6420064 */  lwc1      $f2, 0x64($s2)
/* 321DE8 802BE298 C6440040 */  lwc1      $f4, 0x40($s2)
/* 321DEC 802BE29C 3C014080 */  lui       $at, 0x4080
/* 321DF0 802BE2A0 4481A000 */  mtc1      $at, $f20
/* 321DF4 802BE2A4 27B10034 */  addiu     $s1, $sp, 0x34
/* 321DF8 802BE2A8 E7A60028 */  swc1      $f6, 0x28($sp)
/* 321DFC 802BE2AC E7A00030 */  swc1      $f0, 0x30($sp)
/* 321E00 802BE2B0 E7A20034 */  swc1      $f2, 0x34($sp)
/* 321E04 802BE2B4 E7A40038 */  swc1      $f4, 0x38($sp)
/* 321E08 802BE2B8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 321E0C 802BE2BC E7A60014 */  swc1      $f6, 0x14($sp)
/* 321E10 802BE2C0 864200A8 */  lh        $v0, 0xa8($s2)
/* 321E14 802BE2C4 0220302D */  daddu     $a2, $s1, $zero
/* 321E18 802BE2C8 44820000 */  mtc1      $v0, $f0
/* 321E1C 802BE2CC 00000000 */  nop
/* 321E20 802BE2D0 46800020 */  cvt.s.w   $f0, $f0
/* 321E24 802BE2D4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 321E28 802BE2D8 864200A6 */  lh        $v0, 0xa6($s2)
/* 321E2C 802BE2DC 27B00038 */  addiu     $s0, $sp, 0x38
/* 321E30 802BE2E0 44820000 */  mtc1      $v0, $f0
/* 321E34 802BE2E4 00000000 */  nop
/* 321E38 802BE2E8 46800020 */  cvt.s.w   $f0, $f0
/* 321E3C 802BE2EC E7A0001C */  swc1      $f0, 0x1c($sp)
/* 321E40 802BE2F0 8E440080 */  lw        $a0, 0x80($s2)
/* 321E44 802BE2F4 0C0376B9 */  jal       func_800DDAE4
/* 321E48 802BE2F8 0200382D */   daddu    $a3, $s0, $zero
/* 321E4C 802BE2FC 1040000F */  beqz      $v0, .L802BE33C
/* 321E50 802BE300 00000000 */   nop
/* 321E54 802BE304 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 321E58 802BE308 C6460038 */  lwc1      $f6, 0x38($s2)
/* 321E5C 802BE30C C7A20038 */  lwc1      $f2, 0x38($sp)
/* 321E60 802BE310 46060001 */  sub.s     $f0, $f0, $f6
/* 321E64 802BE314 C6440040 */  lwc1      $f4, 0x40($s2)
/* 321E68 802BE318 3C0140A0 */  lui       $at, 0x40a0
/* 321E6C 802BE31C 44814000 */  mtc1      $at, $f8
/* 321E70 802BE320 46041081 */  sub.s     $f2, $f2, $f4
/* 321E74 802BE324 46080003 */  div.s     $f0, $f0, $f8
/* 321E78 802BE328 46003180 */  add.s     $f6, $f6, $f0
/* 321E7C 802BE32C 46081083 */  div.s     $f2, $f2, $f8
/* 321E80 802BE330 46022100 */  add.s     $f4, $f4, $f2
/* 321E84 802BE334 E6460038 */  swc1      $f6, 0x38($s2)
/* 321E88 802BE338 E6440040 */  swc1      $f4, 0x40($s2)
.L802BE33C:
/* 321E8C 802BE33C 3C014387 */  lui       $at, 0x4387
/* 321E90 802BE340 44813000 */  mtc1      $at, $f6
/* 321E94 802BE344 C6400038 */  lwc1      $f0, 0x38($s2)
/* 321E98 802BE348 C6420064 */  lwc1      $f2, 0x64($s2)
/* 321E9C 802BE34C C6440040 */  lwc1      $f4, 0x40($s2)
/* 321EA0 802BE350 E7A60028 */  swc1      $f6, 0x28($sp)
/* 321EA4 802BE354 E7A00030 */  swc1      $f0, 0x30($sp)
/* 321EA8 802BE358 E7A20034 */  swc1      $f2, 0x34($sp)
/* 321EAC 802BE35C E7A40038 */  swc1      $f4, 0x38($sp)
/* 321EB0 802BE360 E7B40010 */  swc1      $f20, 0x10($sp)
/* 321EB4 802BE364 E7A60014 */  swc1      $f6, 0x14($sp)
/* 321EB8 802BE368 864200A8 */  lh        $v0, 0xa8($s2)
/* 321EBC 802BE36C 0260282D */  daddu     $a1, $s3, $zero
/* 321EC0 802BE370 44820000 */  mtc1      $v0, $f0
/* 321EC4 802BE374 00000000 */  nop
/* 321EC8 802BE378 46800020 */  cvt.s.w   $f0, $f0
/* 321ECC 802BE37C E7A00018 */  swc1      $f0, 0x18($sp)
/* 321ED0 802BE380 864200A6 */  lh        $v0, 0xa6($s2)
/* 321ED4 802BE384 0220302D */  daddu     $a2, $s1, $zero
/* 321ED8 802BE388 44820000 */  mtc1      $v0, $f0
/* 321EDC 802BE38C 00000000 */  nop
/* 321EE0 802BE390 46800020 */  cvt.s.w   $f0, $f0
/* 321EE4 802BE394 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 321EE8 802BE398 8E440080 */  lw        $a0, 0x80($s2)
/* 321EEC 802BE39C 0C0376B9 */  jal       func_800DDAE4
/* 321EF0 802BE3A0 0200382D */   daddu    $a3, $s0, $zero
/* 321EF4 802BE3A4 1040000F */  beqz      $v0, .L802BE3E4
/* 321EF8 802BE3A8 00000000 */   nop
/* 321EFC 802BE3AC C7A00030 */  lwc1      $f0, 0x30($sp)
/* 321F00 802BE3B0 C6460038 */  lwc1      $f6, 0x38($s2)
/* 321F04 802BE3B4 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 321F08 802BE3B8 46060001 */  sub.s     $f0, $f0, $f6
/* 321F0C 802BE3BC C6440040 */  lwc1      $f4, 0x40($s2)
/* 321F10 802BE3C0 3C0140A0 */  lui       $at, 0x40a0
/* 321F14 802BE3C4 44814000 */  mtc1      $at, $f8
/* 321F18 802BE3C8 46041081 */  sub.s     $f2, $f2, $f4
/* 321F1C 802BE3CC 46080003 */  div.s     $f0, $f0, $f8
/* 321F20 802BE3D0 46003180 */  add.s     $f6, $f6, $f0
/* 321F24 802BE3D4 46081083 */  div.s     $f2, $f2, $f8
/* 321F28 802BE3D8 46022100 */  add.s     $f4, $f4, $f2
/* 321F2C 802BE3DC E6460038 */  swc1      $f6, 0x38($s2)
/* 321F30 802BE3E0 E6440040 */  swc1      $f4, 0x40($s2)
.L802BE3E4:
/* 321F34 802BE3E4 0C0AF6A4 */  jal       func_802BDA90_3215E0
/* 321F38 802BE3E8 0240202D */   daddu    $a0, $s2, $zero
/* 321F3C 802BE3EC 27B00030 */  addiu     $s0, $sp, 0x30
/* 321F40 802BE3F0 0200202D */  daddu     $a0, $s0, $zero
/* 321F44 802BE3F4 27B10038 */  addiu     $s1, $sp, 0x38
/* 321F48 802BE3F8 0220282D */  daddu     $a1, $s1, $zero
/* 321F4C 802BE3FC 3C014140 */  lui       $at, 0x4140
/* 321F50 802BE400 44810000 */  mtc1      $at, $f0
/* 321F54 802BE404 3C064000 */  lui       $a2, 0x4000
/* 321F58 802BE408 C6420064 */  lwc1      $f2, 0x64($s2)
/* 321F5C 802BE40C 864200A8 */  lh        $v0, 0xa8($s2)
/* 321F60 802BE410 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 321F64 802BE414 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 321F68 802BE418 46000506 */  mov.s     $f20, $f0
/* 321F6C 802BE41C C6400014 */  lwc1      $f0, 0x14($s2)
/* 321F70 802BE420 24420002 */  addiu     $v0, $v0, 2
/* 321F74 802BE424 46001081 */  sub.s     $f2, $f2, $f0
/* 321F78 802BE428 44820000 */  mtc1      $v0, $f0
/* 321F7C 802BE42C 00000000 */  nop
/* 321F80 802BE430 46800020 */  cvt.s.w   $f0, $f0
/* 321F84 802BE434 00031080 */  sll       $v0, $v1, 2
/* 321F88 802BE438 00431021 */  addu      $v0, $v0, $v1
/* 321F8C 802BE43C 00021080 */  sll       $v0, $v0, 2
/* 321F90 802BE440 00431023 */  subu      $v0, $v0, $v1
/* 321F94 802BE444 000218C0 */  sll       $v1, $v0, 3
/* 321F98 802BE448 00431021 */  addu      $v0, $v0, $v1
/* 321F9C 802BE44C 000210C0 */  sll       $v0, $v0, 3
/* 321FA0 802BE450 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 321FA4 802BE454 E6420064 */  swc1      $f2, 0x64($s2)
/* 321FA8 802BE458 46001006 */  mov.s     $f0, $f2
/* 321FAC 802BE45C 3C07800B */  lui       $a3, %hi(gCameras+0x6C)
/* 321FB0 802BE460 00E23821 */  addu      $a3, $a3, $v0
/* 321FB4 802BE464 8CE71DEC */  lw        $a3, %lo(gCameras+0x6C)($a3)
/* 321FB8 802BE468 C6820028 */  lwc1      $f2, 0x28($s4)
/* 321FBC 802BE46C C6840030 */  lwc1      $f4, 0x30($s4)
/* 321FC0 802BE470 46140000 */  add.s     $f0, $f0, $f20
/* 321FC4 802BE474 E7A20030 */  swc1      $f2, 0x30($sp)
/* 321FC8 802BE478 E7A40038 */  swc1      $f4, 0x38($sp)
/* 321FCC 802BE47C 0C00A7E7 */  jal       add_vec2D_polar
/* 321FD0 802BE480 E7A00034 */   swc1     $f0, 0x34($sp)
/* 321FD4 802BE484 0280202D */  daddu     $a0, $s4, $zero
/* 321FD8 802BE488 0200282D */  daddu     $a1, $s0, $zero
/* 321FDC 802BE48C 27A60034 */  addiu     $a2, $sp, 0x34
/* 321FE0 802BE490 0220382D */  daddu     $a3, $s1, $zero
/* 321FE4 802BE494 27A2003C */  addiu     $v0, $sp, 0x3c
/* 321FE8 802BE498 AFA20010 */  sw        $v0, 0x10($sp)
/* 321FEC 802BE49C 27A20040 */  addiu     $v0, $sp, 0x40
/* 321FF0 802BE4A0 AFA20014 */  sw        $v0, 0x14($sp)
/* 321FF4 802BE4A4 27A20044 */  addiu     $v0, $sp, 0x44
/* 321FF8 802BE4A8 AFA20018 */  sw        $v0, 0x18($sp)
/* 321FFC 802BE4AC 27A20048 */  addiu     $v0, $sp, 0x48
/* 322000 802BE4B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 322004 802BE4B4 27A2004C */  addiu     $v0, $sp, 0x4c
/* 322008 802BE4B8 0C03791B */  jal       func_800DE46C
/* 32200C 802BE4BC AFA20020 */   sw       $v0, 0x20($sp)
/* 322010 802BE4C0 0C00A794 */  jal       get_player_normal_pitch
/* 322014 802BE4C4 0040802D */   daddu    $s0, $v0, $zero
/* 322018 802BE4C8 44801000 */  mtc1      $zero, $f2
/* 32201C 802BE4CC 3C01802C */  lui       $at, %hi(D_802BFF28)
/* 322020 802BE4D0 E420FF28 */  swc1      $f0, %lo(D_802BFF28)($at)
/* 322024 802BE4D4 46020032 */  c.eq.s    $f0, $f2
/* 322028 802BE4D8 00000000 */  nop
/* 32202C 802BE4DC 45010003 */  bc1t      .L802BE4EC
/* 322030 802BE4E0 00000000 */   nop
/* 322034 802BE4E4 3C014200 */  lui       $at, 0x4200
/* 322038 802BE4E8 4481A000 */  mtc1      $at, $f20
.L802BE4EC:
/* 32203C 802BE4EC 4600103C */  c.lt.s    $f2, $f0
/* 322040 802BE4F0 00000000 */  nop
/* 322044 802BE4F4 4500001B */  bc1f      .L802BE564
/* 322048 802BE4F8 00000000 */   nop
/* 32204C 802BE4FC 06000019 */  bltz      $s0, .L802BE564
/* 322050 802BE500 27A50050 */   addiu    $a1, $sp, 0x50
/* 322054 802BE504 3C0140C9 */  lui       $at, 0x40c9
/* 322058 802BE508 34210FD0 */  ori       $at, $at, 0xfd0
/* 32205C 802BE50C 44816000 */  mtc1      $at, $f12
/* 322060 802BE510 00000000 */  nop
/* 322064 802BE514 460C0302 */  mul.s     $f12, $f0, $f12
/* 322068 802BE518 00000000 */  nop
/* 32206C 802BE51C 3C0143B4 */  lui       $at, 0x43b4
/* 322070 802BE520 44810000 */  mtc1      $at, $f0
/* 322074 802BE524 27A60054 */  addiu     $a2, $sp, 0x54
/* 322078 802BE528 0C00A82D */  jal       sin_cos_rad
/* 32207C 802BE52C 46006303 */   div.s    $f12, $f12, $f0
/* 322080 802BE530 C7A20050 */  lwc1      $f2, 0x50($sp)
/* 322084 802BE534 C7A00054 */  lwc1      $f0, 0x54($sp)
/* 322088 802BE538 C684005C */  lwc1      $f4, 0x5c($s4)
/* 32208C 802BE53C 46001083 */  div.s     $f2, $f2, $f0
/* 322090 802BE540 46041082 */  mul.s     $f2, $f2, $f4
/* 322094 802BE544 00000000 */  nop
/* 322098 802BE548 C640003C */  lwc1      $f0, 0x3c($s2)
/* 32209C 802BE54C 46000021 */  cvt.d.s   $f0, $f0
/* 3220A0 802BE550 460010A1 */  cvt.d.s   $f2, $f2
/* 3220A4 802BE554 46201085 */  abs.d     $f2, $f2
/* 3220A8 802BE558 46220000 */  add.d     $f0, $f0, $f2
/* 3220AC 802BE55C 46200020 */  cvt.s.d   $f0, $f0
/* 3220B0 802BE560 E640003C */  swc1      $f0, 0x3c($s2)
.L802BE564:
/* 3220B4 802BE564 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 3220B8 802BE568 4614003E */  c.le.s    $f0, $f20
/* 3220BC 802BE56C 00000000 */  nop
/* 3220C0 802BE570 4500002E */  bc1f      .L802BE62C
/* 3220C4 802BE574 00000000 */   nop
/* 3220C8 802BE578 0600002C */  bltz      $s0, .L802BE62C
/* 3220CC 802BE57C 0200202D */   daddu    $a0, $s0, $zero
/* 3220D0 802BE580 C6400038 */  lwc1      $f0, 0x38($s2)
/* 3220D4 802BE584 4600028D */  trunc.w.s $f10, $f0
/* 3220D8 802BE588 44025000 */  mfc1      $v0, $f10
/* 3220DC 802BE58C 00000000 */  nop
/* 3220E0 802BE590 A6820016 */  sh        $v0, 0x16($s4)
/* 3220E4 802BE594 C640003C */  lwc1      $f0, 0x3c($s2)
/* 3220E8 802BE598 4600028D */  trunc.w.s $f10, $f0
/* 3220EC 802BE59C 44025000 */  mfc1      $v0, $f10
/* 3220F0 802BE5A0 00000000 */  nop
/* 3220F4 802BE5A4 A6820018 */  sh        $v0, 0x18($s4)
/* 3220F8 802BE5A8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 3220FC 802BE5AC A6A40002 */  sh        $a0, 2($s5)
/* 322100 802BE5B0 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 322104 802BE5B4 C7A40030 */  lwc1      $f4, 0x30($sp)
/* 322108 802BE5B8 C7A60038 */  lwc1      $f6, 0x38($sp)
/* 32210C 802BE5BC 4600028D */  trunc.w.s $f10, $f0
/* 322110 802BE5C0 44025000 */  mfc1      $v0, $f10
/* 322114 802BE5C4 00000000 */  nop
/* 322118 802BE5C8 A682001A */  sh        $v0, 0x1a($s4)
/* 32211C 802BE5CC A6440084 */  sh        $a0, 0x84($s2)
/* 322120 802BE5D0 E6420064 */  swc1      $f2, 0x64($s2)
/* 322124 802BE5D4 E6440060 */  swc1      $f4, 0x60($s2)
/* 322128 802BE5D8 E6460068 */  swc1      $f6, 0x68($s2)
/* 32212C 802BE5DC AE400014 */  sw        $zero, 0x14($s2)
/* 322130 802BE5E0 0C016F6A */  jal       get_collider_type_by_id
/* 322134 802BE5E4 A68000C0 */   sh       $zero, 0xc0($s4)
/* 322138 802BE5E8 304200FF */  andi      $v0, $v0, 0xff
/* 32213C 802BE5EC 24030003 */  addiu     $v1, $zero, 3
/* 322140 802BE5F0 14430009 */  bne       $v0, $v1, .L802BE618
/* 322144 802BE5F4 3C020008 */   lui      $v0, 8
/* 322148 802BE5F8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 32214C 802BE5FC 3C013F00 */  lui       $at, 0x3f00
/* 322150 802BE600 44811000 */  mtc1      $at, $f2
/* 322154 802BE604 00000000 */  nop
/* 322158 802BE608 46020002 */  mul.s     $f0, $f0, $f2
/* 32215C 802BE60C 00000000 */  nop
/* 322160 802BE610 080AF988 */  j         .L802BE620
/* 322164 802BE614 34420006 */   ori      $v0, $v0, 6
.L802BE618:
/* 322168 802BE618 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 32216C 802BE61C 34420005 */  ori       $v0, $v0, 5
.L802BE620:
/* 322170 802BE620 AE420028 */  sw        $v0, 0x28($s2)
/* 322174 802BE624 080AF99E */  j         .L802BE678
/* 322178 802BE628 E6400018 */   swc1     $f0, 0x18($s2)
.L802BE62C:
/* 32217C 802BE62C 968200C0 */  lhu       $v0, 0xc0($s4)
/* 322180 802BE630 2403FFFF */  addiu     $v1, $zero, -1
/* 322184 802BE634 A6A30002 */  sh        $v1, 2($s5)
/* 322188 802BE638 24420001 */  addiu     $v0, $v0, 1
/* 32218C 802BE63C A68200C0 */  sh        $v0, 0xc0($s4)
/* 322190 802BE640 C6400014 */  lwc1      $f0, 0x14($s2)
/* 322194 802BE644 3C01802C */  lui       $at, %hi(D_802BFEF8)
/* 322198 802BE648 D422FEF8 */  ldc1      $f2, %lo(D_802BFEF8)($at)
/* 32219C 802BE64C 46000021 */  cvt.d.s   $f0, $f0
/* 3221A0 802BE650 46220000 */  add.d     $f0, $f0, $f2
/* 3221A4 802BE654 A6430084 */  sh        $v1, 0x84($s2)
/* 3221A8 802BE658 3C014140 */  lui       $at, 0x4140
/* 3221AC 802BE65C 44811000 */  mtc1      $at, $f2
/* 3221B0 802BE660 46200020 */  cvt.s.d   $f0, $f0
/* 3221B4 802BE664 4600103C */  c.lt.s    $f2, $f0
/* 3221B8 802BE668 00000000 */  nop
/* 3221BC 802BE66C 45000002 */  bc1f      .L802BE678
/* 3221C0 802BE670 E6400014 */   swc1     $f0, 0x14($s2)
/* 3221C4 802BE674 E6420014 */  swc1      $f2, 0x14($s2)
.L802BE678:
/* 3221C8 802BE678 8FBF0070 */  lw        $ra, 0x70($sp)
/* 3221CC 802BE67C 8FB5006C */  lw        $s5, 0x6c($sp)
/* 3221D0 802BE680 8FB40068 */  lw        $s4, 0x68($sp)
/* 3221D4 802BE684 8FB30064 */  lw        $s3, 0x64($sp)
/* 3221D8 802BE688 8FB20060 */  lw        $s2, 0x60($sp)
/* 3221DC 802BE68C 8FB1005C */  lw        $s1, 0x5c($sp)
/* 3221E0 802BE690 8FB00058 */  lw        $s0, 0x58($sp)
/* 3221E4 802BE694 D7B40078 */  ldc1      $f20, 0x78($sp)
/* 3221E8 802BE698 03E00008 */  jr        $ra
/* 3221EC 802BE69C 27BD0080 */   addiu    $sp, $sp, 0x80
