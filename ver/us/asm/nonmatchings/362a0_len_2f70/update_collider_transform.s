.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_collider_transform
/* 36E24 8005BA24 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 36E28 8005BA28 00042400 */  sll       $a0, $a0, 0x10
/* 36E2C 8005BA2C 00042403 */  sra       $a0, $a0, 0x10
/* 36E30 8005BA30 000410C0 */  sll       $v0, $a0, 3
/* 36E34 8005BA34 00441023 */  subu      $v0, $v0, $a0
/* 36E38 8005BA38 3C03800B */  lui       $v1, %hi(gCollisionData+0x4)
/* 36E3C 8005BA3C 8C6342E4 */  lw        $v1, %lo(gCollisionData+0x4)($v1)
/* 36E40 8005BA40 00021080 */  sll       $v0, $v0, 2
/* 36E44 8005BA44 AFBF0074 */  sw        $ra, 0x74($sp)
/* 36E48 8005BA48 AFB40070 */  sw        $s4, 0x70($sp)
/* 36E4C 8005BA4C AFB3006C */  sw        $s3, 0x6c($sp)
/* 36E50 8005BA50 AFB20068 */  sw        $s2, 0x68($sp)
/* 36E54 8005BA54 AFB10064 */  sw        $s1, 0x64($sp)
/* 36E58 8005BA58 AFB00060 */  sw        $s0, 0x60($sp)
/* 36E5C 8005BA5C F7BE00A0 */  sdc1      $f30, 0xa0($sp)
/* 36E60 8005BA60 F7BC0098 */  sdc1      $f28, 0x98($sp)
/* 36E64 8005BA64 F7BA0090 */  sdc1      $f26, 0x90($sp)
/* 36E68 8005BA68 F7B80088 */  sdc1      $f24, 0x88($sp)
/* 36E6C 8005BA6C F7B60080 */  sdc1      $f22, 0x80($sp)
/* 36E70 8005BA70 F7B40078 */  sdc1      $f20, 0x78($sp)
/* 36E74 8005BA74 00629821 */  addu      $s3, $v1, $v0
/* 36E78 8005BA78 0C046B4C */  jal       get_model_from_list_index
/* 36E7C 8005BA7C 86640008 */   lh       $a0, 8($s3)
/* 36E80 8005BA80 0040802D */  daddu     $s0, $v0, $zero
/* 36E84 8005BA84 8E050004 */  lw        $a1, 4($s0)
/* 36E88 8005BA88 14A00005 */  bnez      $a1, .L8005BAA0
/* 36E8C 8005BA8C 26040058 */   addiu    $a0, $s0, 0x58
/* 36E90 8005BA90 0C00A5C8 */  jal       copy_matrix
/* 36E94 8005BA94 27A50020 */   addiu    $a1, $sp, 0x20
/* 36E98 8005BA98 08016EAF */  j         .L8005BABC
/* 36E9C 8005BA9C 0000902D */   daddu    $s2, $zero, $zero
.L8005BAA0:
/* 36EA0 8005BAA0 0C019D60 */  jal       guMtxL2F
/* 36EA4 8005BAA4 27A40020 */   addiu    $a0, $sp, 0x20
/* 36EA8 8005BAA8 26040058 */  addiu     $a0, $s0, 0x58
/* 36EAC 8005BAAC 27A50020 */  addiu     $a1, $sp, 0x20
/* 36EB0 8005BAB0 0C019D80 */  jal       guMtxCatF
/* 36EB4 8005BAB4 00A0302D */   daddu    $a2, $a1, $zero
/* 36EB8 8005BAB8 0000902D */  daddu     $s2, $zero, $zero
.L8005BABC:
/* 36EBC 8005BABC 8E74000C */  lw        $s4, 0xc($s3)
/* 36EC0 8005BAC0 8E710018 */  lw        $s1, 0x18($s3)
/* 36EC4 8005BAC4 3C014974 */  lui       $at, 0x4974
/* 36EC8 8005BAC8 342123FE */  ori       $at, $at, 0x23fe
/* 36ECC 8005BACC 4481A000 */  mtc1      $at, $f20
/* 36ED0 8005BAD0 3C01C974 */  lui       $at, 0xc974
/* 36ED4 8005BAD4 342123FE */  ori       $at, $at, 0x23fe
/* 36ED8 8005BAD8 4481B000 */  mtc1      $at, $f22
/* 36EDC 8005BADC 86620014 */  lh        $v0, 0x14($s3)
/* 36EE0 8005BAE0 4600A686 */  mov.s     $f26, $f20
/* 36EE4 8005BAE4 4600A606 */  mov.s     $f24, $f20
/* 36EE8 8005BAE8 4600B786 */  mov.s     $f30, $f22
/* 36EEC 8005BAEC 1840002C */  blez      $v0, .L8005BBA0
/* 36EF0 8005BAF0 4600B706 */   mov.s    $f28, $f22
/* 36EF4 8005BAF4 26300008 */  addiu     $s0, $s1, 8
.L8005BAF8:
/* 36EF8 8005BAF8 26220004 */  addiu     $v0, $s1, 4
/* 36EFC 8005BAFC AFB10010 */  sw        $s1, 0x10($sp)
/* 36F00 8005BB00 AFA20014 */  sw        $v0, 0x14($sp)
/* 36F04 8005BB04 AFB00018 */  sw        $s0, 0x18($sp)
/* 36F08 8005BB08 8E050004 */  lw        $a1, 4($s0)
/* 36F0C 8005BB0C 8E060008 */  lw        $a2, 8($s0)
/* 36F10 8005BB10 8E07000C */  lw        $a3, 0xc($s0)
/* 36F14 8005BB14 0C019E9C */  jal       guMtxXFMF
/* 36F18 8005BB18 27A40020 */   addiu    $a0, $sp, 0x20
/* 36F1C 8005BB1C C6200000 */  lwc1      $f0, ($s1)
/* 36F20 8005BB20 4618003C */  c.lt.s    $f0, $f24
/* 36F24 8005BB24 00000000 */  nop
/* 36F28 8005BB28 45030001 */  bc1tl     .L8005BB30
/* 36F2C 8005BB2C 46000606 */   mov.s    $f24, $f0
.L8005BB30:
/* 36F30 8005BB30 4600E03C */  c.lt.s    $f28, $f0
/* 36F34 8005BB34 00000000 */  nop
/* 36F38 8005BB38 45030001 */  bc1tl     .L8005BB40
/* 36F3C 8005BB3C 46000706 */   mov.s    $f28, $f0
.L8005BB40:
/* 36F40 8005BB40 C600FFFC */  lwc1      $f0, -4($s0)
/* 36F44 8005BB44 461A003C */  c.lt.s    $f0, $f26
/* 36F48 8005BB48 00000000 */  nop
/* 36F4C 8005BB4C 45030001 */  bc1tl     .L8005BB54
/* 36F50 8005BB50 46000686 */   mov.s    $f26, $f0
.L8005BB54:
/* 36F54 8005BB54 4600F03C */  c.lt.s    $f30, $f0
/* 36F58 8005BB58 00000000 */  nop
/* 36F5C 8005BB5C 45030001 */  bc1tl     .L8005BB64
/* 36F60 8005BB60 46000786 */   mov.s    $f30, $f0
.L8005BB64:
/* 36F64 8005BB64 C6000000 */  lwc1      $f0, ($s0)
/* 36F68 8005BB68 4614003C */  c.lt.s    $f0, $f20
/* 36F6C 8005BB6C 00000000 */  nop
/* 36F70 8005BB70 45030001 */  bc1tl     .L8005BB78
/* 36F74 8005BB74 46000506 */   mov.s    $f20, $f0
.L8005BB78:
/* 36F78 8005BB78 4600B03C */  c.lt.s    $f22, $f0
/* 36F7C 8005BB7C 00000000 */  nop
/* 36F80 8005BB80 45030001 */  bc1tl     .L8005BB88
/* 36F84 8005BB84 46000586 */   mov.s    $f22, $f0
.L8005BB88:
/* 36F88 8005BB88 26100018 */  addiu     $s0, $s0, 0x18
/* 36F8C 8005BB8C 86620014 */  lh        $v0, 0x14($s3)
/* 36F90 8005BB90 26520001 */  addiu     $s2, $s2, 1
/* 36F94 8005BB94 0242102A */  slt       $v0, $s2, $v0
/* 36F98 8005BB98 1440FFD7 */  bnez      $v0, .L8005BAF8
/* 36F9C 8005BB9C 26310018 */   addiu    $s1, $s1, 0x18
.L8005BBA0:
/* 36FA0 8005BBA0 8E620010 */  lw        $v0, 0x10($s3)
/* 36FA4 8005BBA4 E4580000 */  swc1      $f24, ($v0)
/* 36FA8 8005BBA8 8E620010 */  lw        $v0, 0x10($s3)
/* 36FAC 8005BBAC E45A0004 */  swc1      $f26, 4($v0)
/* 36FB0 8005BBB0 8E620010 */  lw        $v0, 0x10($s3)
/* 36FB4 8005BBB4 E4540008 */  swc1      $f20, 8($v0)
/* 36FB8 8005BBB8 8E620010 */  lw        $v0, 0x10($s3)
/* 36FBC 8005BBBC E45C000C */  swc1      $f28, 0xc($v0)
/* 36FC0 8005BBC0 8E620010 */  lw        $v0, 0x10($s3)
/* 36FC4 8005BBC4 E45E0010 */  swc1      $f30, 0x10($v0)
/* 36FC8 8005BBC8 8E620010 */  lw        $v0, 0x10($s3)
/* 36FCC 8005BBCC E4560014 */  swc1      $f22, 0x14($v0)
/* 36FD0 8005BBD0 8662000A */  lh        $v0, 0xa($s3)
/* 36FD4 8005BBD4 18400066 */  blez      $v0, .L8005BD70
/* 36FD8 8005BBD8 0000902D */   daddu    $s2, $zero, $zero
/* 36FDC 8005BBDC 4480D000 */  mtc1      $zero, $f26
/* 36FE0 8005BBE0 26900038 */  addiu     $s0, $s4, 0x38
.L8005BBE4:
/* 36FE4 8005BBE4 8E04FFD0 */  lw        $a0, -0x30($s0)
/* 36FE8 8005BBE8 8E820000 */  lw        $v0, ($s4)
/* 36FEC 8005BBEC C4800000 */  lwc1      $f0, ($a0)
/* 36FF0 8005BBF0 C4420000 */  lwc1      $f2, ($v0)
/* 36FF4 8005BBF4 46020001 */  sub.s     $f0, $f0, $f2
/* 36FF8 8005BBF8 E600FFD4 */  swc1      $f0, -0x2c($s0)
/* 36FFC 8005BBFC C4800004 */  lwc1      $f0, 4($a0)
/* 37000 8005BC00 C4420004 */  lwc1      $f2, 4($v0)
/* 37004 8005BC04 46020001 */  sub.s     $f0, $f0, $f2
/* 37008 8005BC08 E600FFD8 */  swc1      $f0, -0x28($s0)
/* 3700C 8005BC0C C4800008 */  lwc1      $f0, 8($a0)
/* 37010 8005BC10 C4420008 */  lwc1      $f2, 8($v0)
/* 37014 8005BC14 46020001 */  sub.s     $f0, $f0, $f2
/* 37018 8005BC18 8E03FFCC */  lw        $v1, -0x34($s0)
/* 3701C 8005BC1C E600FFDC */  swc1      $f0, -0x24($s0)
/* 37020 8005BC20 C4400000 */  lwc1      $f0, ($v0)
/* 37024 8005BC24 C4620000 */  lwc1      $f2, ($v1)
/* 37028 8005BC28 46020001 */  sub.s     $f0, $f0, $f2
/* 3702C 8005BC2C E600FFE0 */  swc1      $f0, -0x20($s0)
/* 37030 8005BC30 C4400004 */  lwc1      $f0, 4($v0)
/* 37034 8005BC34 C4620004 */  lwc1      $f2, 4($v1)
/* 37038 8005BC38 46020001 */  sub.s     $f0, $f0, $f2
/* 3703C 8005BC3C E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 37040 8005BC40 C4400008 */  lwc1      $f0, 8($v0)
/* 37044 8005BC44 C4620008 */  lwc1      $f2, 8($v1)
/* 37048 8005BC48 46020001 */  sub.s     $f0, $f0, $f2
/* 3704C 8005BC4C C60AFFD8 */  lwc1      $f10, -0x28($s0)
/* 37050 8005BC50 E600FFE8 */  swc1      $f0, -0x18($s0)
/* 37054 8005BC54 46000186 */  mov.s     $f6, $f0
/* 37058 8005BC58 46065382 */  mul.s     $f14, $f10, $f6
/* 3705C 8005BC5C 00000000 */  nop
/* 37060 8005BC60 C604FFD4 */  lwc1      $f4, -0x2c($s0)
/* 37064 8005BC64 46062182 */  mul.s     $f6, $f4, $f6
/* 37068 8005BC68 00000000 */  nop
/* 3706C 8005BC6C C608FFE4 */  lwc1      $f8, -0x1c($s0)
/* 37070 8005BC70 46082102 */  mul.s     $f4, $f4, $f8
/* 37074 8005BC74 00000000 */  nop
/* 37078 8005BC78 C602FFE0 */  lwc1      $f2, -0x20($s0)
/* 3707C 8005BC7C 46025282 */  mul.s     $f10, $f10, $f2
/* 37080 8005BC80 00000000 */  nop
/* 37084 8005BC84 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 37088 8005BC88 46080302 */  mul.s     $f12, $f0, $f8
/* 3708C 8005BC8C 00000000 */  nop
/* 37090 8005BC90 46020002 */  mul.s     $f0, $f0, $f2
/* 37094 8005BC94 00000000 */  nop
/* 37098 8005BC98 460A2501 */  sub.s     $f20, $f4, $f10
/* 3709C 8005BC9C 4614A102 */  mul.s     $f4, $f20, $f20
/* 370A0 8005BCA0 00000000 */  nop
/* 370A4 8005BCA4 460C7601 */  sub.s     $f24, $f14, $f12
/* 370A8 8005BCA8 4618C202 */  mul.s     $f8, $f24, $f24
/* 370AC 8005BCAC 00000000 */  nop
/* 370B0 8005BCB0 C4620000 */  lwc1      $f2, ($v1)
/* 370B4 8005BCB4 46060581 */  sub.s     $f22, $f0, $f6
/* 370B8 8005BCB8 C4800000 */  lwc1      $f0, ($a0)
/* 370BC 8005BCBC 46001081 */  sub.s     $f2, $f2, $f0
/* 370C0 8005BCC0 4616B182 */  mul.s     $f6, $f22, $f22
/* 370C4 8005BCC4 00000000 */  nop
/* 370C8 8005BCC8 E602FFEC */  swc1      $f2, -0x14($s0)
/* 370CC 8005BCCC C4620004 */  lwc1      $f2, 4($v1)
/* 370D0 8005BCD0 C4800004 */  lwc1      $f0, 4($a0)
/* 370D4 8005BCD4 46001081 */  sub.s     $f2, $f2, $f0
/* 370D8 8005BCD8 E602FFF0 */  swc1      $f2, -0x10($s0)
/* 370DC 8005BCDC C4620008 */  lwc1      $f2, 8($v1)
/* 370E0 8005BCE0 46064200 */  add.s     $f8, $f8, $f6
/* 370E4 8005BCE4 C4800008 */  lwc1      $f0, 8($a0)
/* 370E8 8005BCE8 46001081 */  sub.s     $f2, $f2, $f0
/* 370EC 8005BCEC 46044300 */  add.s     $f12, $f8, $f4
/* 370F0 8005BCF0 461A6032 */  c.eq.s    $f12, $f26
/* 370F4 8005BCF4 00000000 */  nop
/* 370F8 8005BCF8 4501000D */  bc1t      .L8005BD30
/* 370FC 8005BCFC E602FFF4 */   swc1     $f2, -0xc($s0)
/* 37100 8005BD00 46006084 */  sqrt.s    $f2, $f12
/* 37104 8005BD04 46021032 */  c.eq.s    $f2, $f2
/* 37108 8005BD08 00000000 */  nop
/* 3710C 8005BD0C 45010004 */  bc1t      .L8005BD20
/* 37110 8005BD10 00000000 */   nop
/* 37114 8005BD14 0C0187BC */  jal       sqrtf
/* 37118 8005BD18 00000000 */   nop
/* 3711C 8005BD1C 46000086 */  mov.s     $f2, $f0
.L8005BD20:
/* 37120 8005BD20 3C013F80 */  lui       $at, 0x3f80
/* 37124 8005BD24 44810000 */  mtc1      $at, $f0
/* 37128 8005BD28 08016F4D */  j         .L8005BD34
/* 3712C 8005BD2C 46020303 */   div.s    $f12, $f0, $f2
.L8005BD30:
/* 37130 8005BD30 4600D306 */  mov.s     $f12, $f26
.L8005BD34:
/* 37134 8005BD34 460CC002 */  mul.s     $f0, $f24, $f12
/* 37138 8005BD38 00000000 */  nop
/* 3713C 8005BD3C 460CB082 */  mul.s     $f2, $f22, $f12
/* 37140 8005BD40 00000000 */  nop
/* 37144 8005BD44 460CA102 */  mul.s     $f4, $f20, $f12
/* 37148 8005BD48 00000000 */  nop
/* 3714C 8005BD4C 26940040 */  addiu     $s4, $s4, 0x40
/* 37150 8005BD50 26520001 */  addiu     $s2, $s2, 1
/* 37154 8005BD54 E600FFF8 */  swc1      $f0, -8($s0)
/* 37158 8005BD58 E602FFFC */  swc1      $f2, -4($s0)
/* 3715C 8005BD5C E6040000 */  swc1      $f4, ($s0)
/* 37160 8005BD60 8662000A */  lh        $v0, 0xa($s3)
/* 37164 8005BD64 0242102A */  slt       $v0, $s2, $v0
/* 37168 8005BD68 1440FF9E */  bnez      $v0, .L8005BBE4
/* 3716C 8005BD6C 26100040 */   addiu    $s0, $s0, 0x40
.L8005BD70:
/* 37170 8005BD70 8FBF0074 */  lw        $ra, 0x74($sp)
/* 37174 8005BD74 8FB40070 */  lw        $s4, 0x70($sp)
/* 37178 8005BD78 8FB3006C */  lw        $s3, 0x6c($sp)
/* 3717C 8005BD7C 8FB20068 */  lw        $s2, 0x68($sp)
/* 37180 8005BD80 8FB10064 */  lw        $s1, 0x64($sp)
/* 37184 8005BD84 8FB00060 */  lw        $s0, 0x60($sp)
/* 37188 8005BD88 D7BE00A0 */  ldc1      $f30, 0xa0($sp)
/* 3718C 8005BD8C D7BC0098 */  ldc1      $f28, 0x98($sp)
/* 37190 8005BD90 D7BA0090 */  ldc1      $f26, 0x90($sp)
/* 37194 8005BD94 D7B80088 */  ldc1      $f24, 0x88($sp)
/* 37198 8005BD98 D7B60080 */  ldc1      $f22, 0x80($sp)
/* 3719C 8005BD9C D7B40078 */  ldc1      $f20, 0x78($sp)
/* 371A0 8005BDA0 03E00008 */  jr        $ra
/* 371A4 8005BDA4 27BD00A8 */   addiu    $sp, $sp, 0xa8
