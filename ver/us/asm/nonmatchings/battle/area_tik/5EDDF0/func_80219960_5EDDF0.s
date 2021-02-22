.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219960_5EDDF0
/* 5EDDF0 80219960 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5EDDF4 80219964 AFB00020 */  sw        $s0, 0x20($sp)
/* 5EDDF8 80219968 0080802D */  daddu     $s0, $a0, $zero
/* 5EDDFC 8021996C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5EDE00 80219970 AFB10024 */  sw        $s1, 0x24($sp)
/* 5EDE04 80219974 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5EDE08 80219978 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5EDE0C 8021997C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5EDE10 80219980 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5EDE14 80219984 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5EDE18 80219988 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5EDE1C 8021998C 8E02000C */  lw        $v0, 0xc($s0)
/* 5EDE20 80219990 0C0B1EAF */  jal       get_variable
/* 5EDE24 80219994 8C450000 */   lw       $a1, ($v0)
/* 5EDE28 80219998 0040882D */  daddu     $s1, $v0, $zero
/* 5EDE2C 8021999C 24040001 */  addiu     $a0, $zero, 1
/* 5EDE30 802199A0 1224002F */  beq       $s1, $a0, .L80219A60
/* 5EDE34 802199A4 AE110070 */   sw       $s1, 0x70($s0)
/* 5EDE38 802199A8 2A220002 */  slti      $v0, $s1, 2
/* 5EDE3C 802199AC 10400005 */  beqz      $v0, .L802199C4
/* 5EDE40 802199B0 24020002 */   addiu    $v0, $zero, 2
/* 5EDE44 802199B4 12200009 */  beqz      $s1, .L802199DC
/* 5EDE48 802199B8 2402008E */   addiu    $v0, $zero, 0x8e
/* 5EDE4C 802199BC 08086758 */  j         .L80219D60
/* 5EDE50 802199C0 00000000 */   nop
.L802199C4:
/* 5EDE54 802199C4 12220085 */  beq       $s1, $v0, .L80219BDC
/* 5EDE58 802199C8 24020003 */   addiu    $v0, $zero, 3
/* 5EDE5C 802199CC 12220013 */  beq       $s1, $v0, .L80219A1C
/* 5EDE60 802199D0 2403005B */   addiu    $v1, $zero, 0x5b
/* 5EDE64 802199D4 08086758 */  j         .L80219D60
/* 5EDE68 802199D8 00000000 */   nop
.L802199DC:
/* 5EDE6C 802199DC 3C01430E */  lui       $at, 0x430e
/* 5EDE70 802199E0 44812000 */  mtc1      $at, $f4
/* 5EDE74 802199E4 3C01C2EC */  lui       $at, 0xc2ec
/* 5EDE78 802199E8 4481F000 */  mtc1      $at, $f30
/* 5EDE7C 802199EC 2403FF8A */  addiu     $v1, $zero, -0x76
/* 5EDE80 802199F0 AFA00014 */  sw        $zero, 0x14($sp)
/* 5EDE84 802199F4 E7A40010 */  swc1      $f4, 0x10($sp)
/* 5EDE88 802199F8 AE020090 */  sw        $v0, 0x90($s0)
/* 5EDE8C 802199FC 2402002C */  addiu     $v0, $zero, 0x2c
/* 5EDE90 80219A00 AE02009C */  sw        $v0, 0x9c($s0)
/* 5EDE94 80219A04 24020003 */  addiu     $v0, $zero, 3
/* 5EDE98 80219A08 AE000094 */  sw        $zero, 0x94($s0)
/* 5EDE9C 80219A0C AE030098 */  sw        $v1, 0x98($s0)
/* 5EDEA0 80219A10 AE0300A0 */  sw        $v1, 0xa0($s0)
/* 5EDEA4 80219A14 08086694 */  j         .L80219A50
/* 5EDEA8 80219A18 AE0200A4 */   sw       $v0, 0xa4($s0)
.L80219A1C:
/* 5EDEAC 80219A1C 3C0142B6 */  lui       $at, 0x42b6
/* 5EDEB0 80219A20 44812000 */  mtc1      $at, $f4
/* 5EDEB4 80219A24 3C01C2EC */  lui       $at, 0xc2ec
/* 5EDEB8 80219A28 4481F000 */  mtc1      $at, $f30
/* 5EDEBC 80219A2C 2402FF8A */  addiu     $v0, $zero, -0x76
/* 5EDEC0 80219A30 AFA00014 */  sw        $zero, 0x14($sp)
/* 5EDEC4 80219A34 E7A40010 */  swc1      $f4, 0x10($sp)
/* 5EDEC8 80219A38 AE030090 */  sw        $v1, 0x90($s0)
/* 5EDECC 80219A3C AE000094 */  sw        $zero, 0x94($s0)
/* 5EDED0 80219A40 AE020098 */  sw        $v0, 0x98($s0)
/* 5EDED4 80219A44 AE03009C */  sw        $v1, 0x9c($s0)
/* 5EDED8 80219A48 AE0200A0 */  sw        $v0, 0xa0($s0)
/* 5EDEDC 80219A4C AE1100A4 */  sw        $s1, 0xa4($s0)
.L80219A50:
/* 5EDEE0 80219A50 AE0000A8 */  sw        $zero, 0xa8($s0)
/* 5EDEE4 80219A54 AE0000B0 */  sw        $zero, 0xb0($s0)
/* 5EDEE8 80219A58 08086758 */  j         .L80219D60
/* 5EDEEC 80219A5C AE040070 */   sw       $a0, 0x70($s0)
.L80219A60:
/* 5EDEF0 80219A60 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 5EDEF4 80219A64 8E0300A4 */  lw        $v1, 0xa4($s0)
/* 5EDEF8 80219A68 00431021 */  addu      $v0, $v0, $v1
/* 5EDEFC 80219A6C AE0200A8 */  sw        $v0, 0xa8($s0)
/* 5EDF00 80219A70 2842002E */  slti      $v0, $v0, 0x2e
/* 5EDF04 80219A74 14400003 */  bnez      $v0, .L80219A84
/* 5EDF08 80219A78 00000000 */   nop
/* 5EDF0C 80219A7C 2402002D */  addiu     $v0, $zero, 0x2d
/* 5EDF10 80219A80 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219A84:
/* 5EDF14 80219A84 C6040090 */  lwc1      $f4, 0x90($s0)
/* 5EDF18 80219A88 46802120 */  cvt.s.w   $f4, $f4
/* 5EDF1C 80219A8C E7A40010 */  swc1      $f4, 0x10($sp)
/* 5EDF20 80219A90 C6040094 */  lwc1      $f4, 0x94($s0)
/* 5EDF24 80219A94 46802120 */  cvt.s.w   $f4, $f4
/* 5EDF28 80219A98 E7A40014 */  swc1      $f4, 0x14($sp)
/* 5EDF2C 80219A9C C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EDF30 80219AA0 46806320 */  cvt.s.w   $f12, $f12
/* 5EDF34 80219AA4 3C0140C9 */  lui       $at, 0x40c9
/* 5EDF38 80219AA8 34210FD0 */  ori       $at, $at, 0xfd0
/* 5EDF3C 80219AAC 4481D000 */  mtc1      $at, $f26
/* 5EDF40 80219AB0 C61E0098 */  lwc1      $f30, 0x98($s0)
/* 5EDF44 80219AB4 4680F7A0 */  cvt.s.w   $f30, $f30
/* 5EDF48 80219AB8 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EDF4C 80219ABC 00000000 */  nop
/* 5EDF50 80219AC0 C61C009C */  lwc1      $f28, 0x9c($s0)
/* 5EDF54 80219AC4 4680E720 */  cvt.s.w   $f28, $f28
/* 5EDF58 80219AC8 3C0143B4 */  lui       $at, 0x43b4
/* 5EDF5C 80219ACC 4481C000 */  mtc1      $at, $f24
/* 5EDF60 80219AD0 C60400A0 */  lwc1      $f4, 0xa0($s0)
/* 5EDF64 80219AD4 46802120 */  cvt.s.w   $f4, $f4
/* 5EDF68 80219AD8 E7A40018 */  swc1      $f4, 0x18($sp)
/* 5EDF6C 80219ADC 0C00A85B */  jal       sin_rad
/* 5EDF70 80219AE0 46186303 */   div.s    $f12, $f12, $f24
/* 5EDF74 80219AE4 46000021 */  cvt.d.s   $f0, $f0
/* 5EDF78 80219AE8 3C013FF0 */  lui       $at, 0x3ff0
/* 5EDF7C 80219AEC 4481B800 */  mtc1      $at, $f23
/* 5EDF80 80219AF0 4480B000 */  mtc1      $zero, $f22
/* 5EDF84 80219AF4 C7A40010 */  lwc1      $f4, 0x10($sp)
/* 5EDF88 80219AF8 4620B001 */  sub.d     $f0, $f22, $f0
/* 5EDF8C 80219AFC 46002521 */  cvt.d.s   $f20, $f4
/* 5EDF90 80219B00 4620A502 */  mul.d     $f20, $f20, $f0
/* 5EDF94 80219B04 00000000 */  nop
/* 5EDF98 80219B08 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EDF9C 80219B0C 46806320 */  cvt.s.w   $f12, $f12
/* 5EDFA0 80219B10 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EDFA4 80219B14 00000000 */  nop
/* 5EDFA8 80219B18 0C00A85B */  jal       sin_rad
/* 5EDFAC 80219B1C 46186303 */   div.s    $f12, $f12, $f24
/* 5EDFB0 80219B20 4600E002 */  mul.s     $f0, $f28, $f0
/* 5EDFB4 80219B24 00000000 */  nop
/* 5EDFB8 80219B28 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 5EDFBC 80219B2C 00021040 */  sll       $v0, $v0, 1
/* 5EDFC0 80219B30 44826000 */  mtc1      $v0, $f12
/* 5EDFC4 80219B34 00000000 */  nop
/* 5EDFC8 80219B38 46806320 */  cvt.s.w   $f12, $f12
/* 5EDFCC 80219B3C 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EDFD0 80219B40 00000000 */  nop
/* 5EDFD4 80219B44 46000021 */  cvt.d.s   $f0, $f0
/* 5EDFD8 80219B48 4620A500 */  add.d     $f20, $f20, $f0
/* 5EDFDC 80219B4C 46186303 */  div.s     $f12, $f12, $f24
/* 5EDFE0 80219B50 4620A520 */  cvt.s.d   $f20, $f20
/* 5EDFE4 80219B54 0C00A85B */  jal       sin_rad
/* 5EDFE8 80219B58 E7B40010 */   swc1     $f20, 0x10($sp)
/* 5EDFEC 80219B5C C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EDFF0 80219B60 46806320 */  cvt.s.w   $f12, $f12
/* 5EDFF4 80219B64 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EDFF8 80219B68 00000000 */  nop
/* 5EDFFC 80219B6C 3C0142B4 */  lui       $at, 0x42b4
/* 5EE000 80219B70 44811000 */  mtc1      $at, $f2
/* 5EE004 80219B74 00000000 */  nop
/* 5EE008 80219B78 46020002 */  mul.s     $f0, $f0, $f2
/* 5EE00C 80219B7C 00000000 */  nop
/* 5EE010 80219B80 C7A40014 */  lwc1      $f4, 0x14($sp)
/* 5EE014 80219B84 46002100 */  add.s     $f4, $f4, $f0
/* 5EE018 80219B88 46186303 */  div.s     $f12, $f12, $f24
/* 5EE01C 80219B8C 0C00A85B */  jal       sin_rad
/* 5EE020 80219B90 E7A40014 */   swc1     $f4, 0x14($sp)
/* 5EE024 80219B94 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EE028 80219B98 46806320 */  cvt.s.w   $f12, $f12
/* 5EE02C 80219B9C 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EE030 80219BA0 00000000 */  nop
/* 5EE034 80219BA4 46000021 */  cvt.d.s   $f0, $f0
/* 5EE038 80219BA8 4620B581 */  sub.d     $f22, $f22, $f0
/* 5EE03C 80219BAC 4600F521 */  cvt.d.s   $f20, $f30
/* 5EE040 80219BB0 4636A502 */  mul.d     $f20, $f20, $f22
/* 5EE044 80219BB4 00000000 */  nop
/* 5EE048 80219BB8 0C00A85B */  jal       sin_rad
/* 5EE04C 80219BBC 46186303 */   div.s    $f12, $f12, $f24
/* 5EE050 80219BC0 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 5EE054 80219BC4 46002002 */  mul.s     $f0, $f4, $f0
/* 5EE058 80219BC8 00000000 */  nop
/* 5EE05C 80219BCC 46000021 */  cvt.d.s   $f0, $f0
/* 5EE060 80219BD0 4620A500 */  add.d     $f20, $f20, $f0
/* 5EE064 80219BD4 08086754 */  j         .L80219D50
/* 5EE068 80219BD8 2402002D */   addiu    $v0, $zero, 0x2d
.L80219BDC:
/* 5EE06C 80219BDC 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 5EE070 80219BE0 8E0300A4 */  lw        $v1, 0xa4($s0)
/* 5EE074 80219BE4 00431021 */  addu      $v0, $v0, $v1
/* 5EE078 80219BE8 AE0200A8 */  sw        $v0, 0xa8($s0)
/* 5EE07C 80219BEC 2842005B */  slti      $v0, $v0, 0x5b
/* 5EE080 80219BF0 14400002 */  bnez      $v0, .L80219BFC
/* 5EE084 80219BF4 2402005A */   addiu    $v0, $zero, 0x5a
/* 5EE088 80219BF8 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219BFC:
/* 5EE08C 80219BFC C6040090 */  lwc1      $f4, 0x90($s0)
/* 5EE090 80219C00 46802120 */  cvt.s.w   $f4, $f4
/* 5EE094 80219C04 E7A40010 */  swc1      $f4, 0x10($sp)
/* 5EE098 80219C08 C6040094 */  lwc1      $f4, 0x94($s0)
/* 5EE09C 80219C0C 46802120 */  cvt.s.w   $f4, $f4
/* 5EE0A0 80219C10 E7A40014 */  swc1      $f4, 0x14($sp)
/* 5EE0A4 80219C14 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EE0A8 80219C18 46806320 */  cvt.s.w   $f12, $f12
/* 5EE0AC 80219C1C 3C0140C9 */  lui       $at, 0x40c9
/* 5EE0B0 80219C20 34210FD0 */  ori       $at, $at, 0xfd0
/* 5EE0B4 80219C24 4481D000 */  mtc1      $at, $f26
/* 5EE0B8 80219C28 C61E0098 */  lwc1      $f30, 0x98($s0)
/* 5EE0BC 80219C2C 4680F7A0 */  cvt.s.w   $f30, $f30
/* 5EE0C0 80219C30 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EE0C4 80219C34 00000000 */  nop
/* 5EE0C8 80219C38 C61C009C */  lwc1      $f28, 0x9c($s0)
/* 5EE0CC 80219C3C 4680E720 */  cvt.s.w   $f28, $f28
/* 5EE0D0 80219C40 3C0143B4 */  lui       $at, 0x43b4
/* 5EE0D4 80219C44 4481C000 */  mtc1      $at, $f24
/* 5EE0D8 80219C48 C60400A0 */  lwc1      $f4, 0xa0($s0)
/* 5EE0DC 80219C4C 46802120 */  cvt.s.w   $f4, $f4
/* 5EE0E0 80219C50 E7A40018 */  swc1      $f4, 0x18($sp)
/* 5EE0E4 80219C54 0C00A85B */  jal       sin_rad
/* 5EE0E8 80219C58 46186303 */   div.s    $f12, $f12, $f24
/* 5EE0EC 80219C5C 46000021 */  cvt.d.s   $f0, $f0
/* 5EE0F0 80219C60 3C013FF0 */  lui       $at, 0x3ff0
/* 5EE0F4 80219C64 4481B800 */  mtc1      $at, $f23
/* 5EE0F8 80219C68 4480B000 */  mtc1      $zero, $f22
/* 5EE0FC 80219C6C C7A40010 */  lwc1      $f4, 0x10($sp)
/* 5EE100 80219C70 4620B001 */  sub.d     $f0, $f22, $f0
/* 5EE104 80219C74 46002521 */  cvt.d.s   $f20, $f4
/* 5EE108 80219C78 4620A502 */  mul.d     $f20, $f20, $f0
/* 5EE10C 80219C7C 00000000 */  nop
/* 5EE110 80219C80 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EE114 80219C84 46806320 */  cvt.s.w   $f12, $f12
/* 5EE118 80219C88 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EE11C 80219C8C 00000000 */  nop
/* 5EE120 80219C90 0C00A85B */  jal       sin_rad
/* 5EE124 80219C94 46186303 */   div.s    $f12, $f12, $f24
/* 5EE128 80219C98 4600E002 */  mul.s     $f0, $f28, $f0
/* 5EE12C 80219C9C 00000000 */  nop
/* 5EE130 80219CA0 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 5EE134 80219CA4 00021040 */  sll       $v0, $v0, 1
/* 5EE138 80219CA8 44826000 */  mtc1      $v0, $f12
/* 5EE13C 80219CAC 00000000 */  nop
/* 5EE140 80219CB0 46806320 */  cvt.s.w   $f12, $f12
/* 5EE144 80219CB4 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EE148 80219CB8 00000000 */  nop
/* 5EE14C 80219CBC 46000021 */  cvt.d.s   $f0, $f0
/* 5EE150 80219CC0 4620A500 */  add.d     $f20, $f20, $f0
/* 5EE154 80219CC4 46186303 */  div.s     $f12, $f12, $f24
/* 5EE158 80219CC8 4620A520 */  cvt.s.d   $f20, $f20
/* 5EE15C 80219CCC 0C00A85B */  jal       sin_rad
/* 5EE160 80219CD0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 5EE164 80219CD4 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EE168 80219CD8 46806320 */  cvt.s.w   $f12, $f12
/* 5EE16C 80219CDC 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EE170 80219CE0 00000000 */  nop
/* 5EE174 80219CE4 3C0142B4 */  lui       $at, 0x42b4
/* 5EE178 80219CE8 44811000 */  mtc1      $at, $f2
/* 5EE17C 80219CEC 00000000 */  nop
/* 5EE180 80219CF0 46020002 */  mul.s     $f0, $f0, $f2
/* 5EE184 80219CF4 00000000 */  nop
/* 5EE188 80219CF8 C7A40014 */  lwc1      $f4, 0x14($sp)
/* 5EE18C 80219CFC 46002100 */  add.s     $f4, $f4, $f0
/* 5EE190 80219D00 46186303 */  div.s     $f12, $f12, $f24
/* 5EE194 80219D04 0C00A85B */  jal       sin_rad
/* 5EE198 80219D08 E7A40014 */   swc1     $f4, 0x14($sp)
/* 5EE19C 80219D0C C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 5EE1A0 80219D10 46806320 */  cvt.s.w   $f12, $f12
/* 5EE1A4 80219D14 461A6302 */  mul.s     $f12, $f12, $f26
/* 5EE1A8 80219D18 00000000 */  nop
/* 5EE1AC 80219D1C 46000021 */  cvt.d.s   $f0, $f0
/* 5EE1B0 80219D20 4620B581 */  sub.d     $f22, $f22, $f0
/* 5EE1B4 80219D24 4600F521 */  cvt.d.s   $f20, $f30
/* 5EE1B8 80219D28 4636A502 */  mul.d     $f20, $f20, $f22
/* 5EE1BC 80219D2C 00000000 */  nop
/* 5EE1C0 80219D30 0C00A85B */  jal       sin_rad
/* 5EE1C4 80219D34 46186303 */   div.s    $f12, $f12, $f24
/* 5EE1C8 80219D38 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 5EE1CC 80219D3C 46002002 */  mul.s     $f0, $f4, $f0
/* 5EE1D0 80219D40 00000000 */  nop
/* 5EE1D4 80219D44 46000021 */  cvt.d.s   $f0, $f0
/* 5EE1D8 80219D48 4620A500 */  add.d     $f20, $f20, $f0
/* 5EE1DC 80219D4C 2402005A */  addiu     $v0, $zero, 0x5a
.L80219D50:
/* 5EE1E0 80219D50 8E0300A8 */  lw        $v1, 0xa8($s0)
/* 5EE1E4 80219D54 14620002 */  bne       $v1, $v0, .L80219D60
/* 5EE1E8 80219D58 4620A7A0 */   cvt.s.d  $f30, $f20
/* 5EE1EC 80219D5C AE1100B0 */  sw        $s1, 0xb0($s0)
.L80219D60:
/* 5EE1F0 80219D60 C7A40010 */  lwc1      $f4, 0x10($sp)
/* 5EE1F4 80219D64 4600210D */  trunc.w.s $f4, $f4
/* 5EE1F8 80219D68 E6040084 */  swc1      $f4, 0x84($s0)
/* 5EE1FC 80219D6C C7A40014 */  lwc1      $f4, 0x14($sp)
/* 5EE200 80219D70 4600210D */  trunc.w.s $f4, $f4
/* 5EE204 80219D74 E6040088 */  swc1      $f4, 0x88($s0)
/* 5EE208 80219D78 4600F10D */  trunc.w.s $f4, $f30
/* 5EE20C 80219D7C E604008C */  swc1      $f4, 0x8c($s0)
/* 5EE210 80219D80 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5EE214 80219D84 8FB10024 */  lw        $s1, 0x24($sp)
/* 5EE218 80219D88 8FB00020 */  lw        $s0, 0x20($sp)
/* 5EE21C 80219D8C D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5EE220 80219D90 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5EE224 80219D94 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5EE228 80219D98 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5EE22C 80219D9C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5EE230 80219DA0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5EE234 80219DA4 24020002 */  addiu     $v0, $zero, 2
/* 5EE238 80219DA8 03E00008 */  jr        $ra
/* 5EE23C 80219DAC 27BD0060 */   addiu    $sp, $sp, 0x60
