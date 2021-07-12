.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel player_test_lateral_overlap
/* 780B4 800DEC04 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 780B8 800DEC08 AFB40078 */  sw        $s4, 0x78($sp)
/* 780BC 800DEC0C 0080A02D */  daddu     $s4, $a0, $zero
/* 780C0 800DEC10 AFB20070 */  sw        $s2, 0x70($sp)
/* 780C4 800DEC14 00C0902D */  daddu     $s2, $a2, $zero
/* 780C8 800DEC18 AFB00068 */  sw        $s0, 0x68($sp)
/* 780CC 800DEC1C 00E0802D */  daddu     $s0, $a3, $zero
/* 780D0 800DEC20 AFB30074 */  sw        $s3, 0x74($sp)
/* 780D4 800DEC24 AFBF007C */  sw        $ra, 0x7c($sp)
/* 780D8 800DEC28 AFB1006C */  sw        $s1, 0x6c($sp)
/* 780DC 800DEC2C F7BC00A0 */  sdc1      $f28, 0xa0($sp)
/* 780E0 800DEC30 F7BA0098 */  sdc1      $f26, 0x98($sp)
/* 780E4 800DEC34 F7B80090 */  sdc1      $f24, 0x90($sp)
/* 780E8 800DEC38 F7B60088 */  sdc1      $f22, 0x88($sp)
/* 780EC 800DEC3C F7B40080 */  sdc1      $f20, 0x80($sp)
/* 780F0 800DEC40 84A200B2 */  lh        $v0, 0xb2($a1)
/* 780F4 800DEC44 3C013F00 */  lui       $at, 0x3f00
/* 780F8 800DEC48 44810000 */  mtc1      $at, $f0
/* 780FC 800DEC4C 8FB100B8 */  lw        $s1, 0xb8($sp)
/* 78100 800DEC50 C7B400BC */  lwc1      $f20, 0xbc($sp)
/* 78104 800DEC54 44821000 */  mtc1      $v0, $f2
/* 78108 800DEC58 00000000 */  nop
/* 7810C 800DEC5C 468010A0 */  cvt.s.w   $f2, $f2
/* 78110 800DEC60 8CA20000 */  lw        $v0, ($a1)
/* 78114 800DEC64 46001702 */  mul.s     $f28, $f2, $f0
/* 78118 800DEC68 00000000 */  nop
/* 7811C 800DEC6C 30420006 */  andi      $v0, $v0, 6
/* 78120 800DEC70 1440000B */  bnez      $v0, .L800DECA0
/* 78124 800DEC74 2413FFFF */   addiu    $s3, $zero, -1
/* 78128 800DEC78 84A200B0 */  lh        $v0, 0xb0($a1)
/* 7812C 800DEC7C 3C013E92 */  lui       $at, 0x3e92
/* 78130 800DEC80 34216E98 */  ori       $at, $at, 0x6e98
/* 78134 800DEC84 44811000 */  mtc1      $at, $f2
/* 78138 800DEC88 44820000 */  mtc1      $v0, $f0
/* 7813C 800DEC8C 00000000 */  nop
/* 78140 800DEC90 46800020 */  cvt.s.w   $f0, $f0
/* 78144 800DEC94 46020582 */  mul.s     $f22, $f0, $f2
/* 78148 800DEC98 08037B2A */  j         .L800DECA8
/* 7814C 800DEC9C 00000000 */   nop
.L800DECA0:
/* 78150 800DECA0 3C013F80 */  lui       $at, 0x3f80
/* 78154 800DECA4 4481B000 */  mtc1      $at, $f22
.L800DECA8:
/* 78158 800DECA8 3C0140C9 */  lui       $at, 0x40c9
/* 7815C 800DECAC 34210FD0 */  ori       $at, $at, 0xfd0
/* 78160 800DECB0 44810000 */  mtc1      $at, $f0
/* 78164 800DECB4 C7AC00C0 */  lwc1      $f12, 0xc0($sp)
/* 78168 800DECB8 46006302 */  mul.s     $f12, $f12, $f0
/* 7816C 800DECBC 00000000 */  nop
/* 78170 800DECC0 27A50038 */  addiu     $a1, $sp, 0x38
/* 78174 800DECC4 3C0143B4 */  lui       $at, 0x43b4
/* 78178 800DECC8 44810000 */  mtc1      $at, $f0
/* 7817C 800DECCC 27A6003C */  addiu     $a2, $sp, 0x3c
/* 78180 800DECD0 0C00A82D */  jal       sin_cos_rad
/* 78184 800DECD4 46006303 */   div.s    $f12, $f12, $f0
/* 78188 800DECD8 461CA080 */  add.s     $f2, $f20, $f28
/* 7818C 800DECDC C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 78190 800DECE0 46000007 */  neg.s     $f0, $f0
/* 78194 800DECE4 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 78198 800DECE8 E7A2004C */  swc1      $f2, 0x4c($sp)
/* 7819C 800DECEC C7A20038 */  lwc1      $f2, 0x38($sp)
/* 781A0 800DECF0 C6040000 */  lwc1      $f4, ($s0)
/* 781A4 800DECF4 27A20040 */  addiu     $v0, $sp, 0x40
/* 781A8 800DECF8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 781AC 800DECFC 27A20044 */  addiu     $v0, $sp, 0x44
/* 781B0 800DED00 AFA20020 */  sw        $v0, 0x20($sp)
/* 781B4 800DED04 27A20048 */  addiu     $v0, $sp, 0x48
/* 781B8 800DED08 AFA20024 */  sw        $v0, 0x24($sp)
/* 781BC 800DED0C 27A2004C */  addiu     $v0, $sp, 0x4c
/* 781C0 800DED10 AFA20028 */  sw        $v0, 0x28($sp)
/* 781C4 800DED14 27A20050 */  addiu     $v0, $sp, 0x50
/* 781C8 800DED18 AFA2002C */  sw        $v0, 0x2c($sp)
/* 781CC 800DED1C 27A20054 */  addiu     $v0, $sp, 0x54
/* 781D0 800DED20 AFA20030 */  sw        $v0, 0x30($sp)
/* 781D4 800DED24 27A20058 */  addiu     $v0, $sp, 0x58
/* 781D8 800DED28 AFA00014 */  sw        $zero, 0x14($sp)
/* 781DC 800DED2C E7A00018 */  swc1      $f0, 0x18($sp)
/* 781E0 800DED30 AFA20034 */  sw        $v0, 0x34($sp)
/* 781E4 800DED34 46162100 */  add.s     $f4, $f4, $f22
/* 781E8 800DED38 E7A20010 */  swc1      $f2, 0x10($sp)
/* 781EC 800DED3C 8E450000 */  lw        $a1, ($s2)
/* 781F0 800DED40 8E270000 */  lw        $a3, ($s1)
/* 781F4 800DED44 44062000 */  mfc1      $a2, $f4
/* 781F8 800DED48 0C037B97 */  jal       player_raycast_general
/* 781FC 800DED4C 0280202D */   daddu    $a0, $s4, $zero
/* 78200 800DED50 0040802D */  daddu     $s0, $v0, $zero
/* 78204 800DED54 24020003 */  addiu     $v0, $zero, 3
/* 78208 800DED58 16820004 */  bne       $s4, $v0, .L800DED6C
/* 7820C 800DED5C 00000000 */   nop
/* 78210 800DED60 4480C000 */  mtc1      $zero, $f24
/* 78214 800DED64 08037B61 */  j         .L800DED84
/* 78218 800DED68 4600C686 */   mov.s    $f26, $f24
.L800DED6C:
/* 7821C 800DED6C C7A00038 */  lwc1      $f0, 0x38($sp)
/* 78220 800DED70 4600A682 */  mul.s     $f26, $f20, $f0
/* 78224 800DED74 00000000 */  nop
/* 78228 800DED78 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 7822C 800DED7C 4600A602 */  mul.s     $f24, $f20, $f0
/* 78230 800DED80 00000000 */  nop
.L800DED84:
/* 78234 800DED84 06000021 */  bltz      $s0, .L800DEE0C
/* 78238 800DED88 00000000 */   nop
/* 7823C 800DED8C 461CA080 */  add.s     $f2, $f20, $f28
/* 78240 800DED90 C7B6004C */  lwc1      $f22, 0x4c($sp)
/* 78244 800DED94 4602B03E */  c.le.s    $f22, $f2
/* 78248 800DED98 00000000 */  nop
/* 7824C 800DED9C 4500001B */  bc1f      .L800DEE0C
/* 78250 800DEDA0 27A4005C */   addiu    $a0, $sp, 0x5c
/* 78254 800DEDA4 4602B581 */  sub.s     $f22, $f22, $f2
/* 78258 800DEDA8 4406D000 */  mfc1      $a2, $f26
/* 7825C 800DEDAC C7B40038 */  lwc1      $f20, 0x38($sp)
/* 78260 800DEDB0 4407C000 */  mfc1      $a3, $f24
/* 78264 800DEDB4 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 78268 800DEDB8 4614B502 */  mul.s     $f20, $f22, $f20
/* 7826C 800DEDBC 00000000 */  nop
/* 78270 800DEDC0 C7A00050 */  lwc1      $f0, 0x50($sp)
/* 78274 800DEDC4 27A50060 */  addiu     $a1, $sp, 0x60
/* 78278 800DEDC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 7827C 800DEDCC C7A00058 */  lwc1      $f0, 0x58($sp)
/* 78280 800DEDD0 4602B582 */  mul.s     $f22, $f22, $f2
/* 78284 800DEDD4 00000000 */  nop
/* 78288 800DEDD8 0C037CFF */  jal       player_get_slip_vector
/* 7828C 800DEDDC E7A00014 */   swc1     $f0, 0x14($sp)
/* 78290 800DEDE0 C7A0005C */  lwc1      $f0, 0x5c($sp)
/* 78294 800DEDE4 4600A500 */  add.s     $f20, $f20, $f0
/* 78298 800DEDE8 C6400000 */  lwc1      $f0, ($s2)
/* 7829C 800DEDEC 46140000 */  add.s     $f0, $f0, $f20
/* 782A0 800DEDF0 E6400000 */  swc1      $f0, ($s2)
/* 782A4 800DEDF4 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 782A8 800DEDF8 4600B580 */  add.s     $f22, $f22, $f0
/* 782AC 800DEDFC C6200000 */  lwc1      $f0, ($s1)
/* 782B0 800DEE00 46160000 */  add.s     $f0, $f0, $f22
/* 782B4 800DEE04 0200982D */  daddu     $s3, $s0, $zero
/* 782B8 800DEE08 E6200000 */  swc1      $f0, ($s1)
.L800DEE0C:
/* 782BC 800DEE0C C6400000 */  lwc1      $f0, ($s2)
/* 782C0 800DEE10 461A0000 */  add.s     $f0, $f0, $f26
/* 782C4 800DEE14 E6400000 */  swc1      $f0, ($s2)
/* 782C8 800DEE18 C6200000 */  lwc1      $f0, ($s1)
/* 782CC 800DEE1C 46180000 */  add.s     $f0, $f0, $f24
/* 782D0 800DEE20 0260102D */  daddu     $v0, $s3, $zero
/* 782D4 800DEE24 E6200000 */  swc1      $f0, ($s1)
/* 782D8 800DEE28 8FBF007C */  lw        $ra, 0x7c($sp)
/* 782DC 800DEE2C 8FB40078 */  lw        $s4, 0x78($sp)
/* 782E0 800DEE30 8FB30074 */  lw        $s3, 0x74($sp)
/* 782E4 800DEE34 8FB20070 */  lw        $s2, 0x70($sp)
/* 782E8 800DEE38 8FB1006C */  lw        $s1, 0x6c($sp)
/* 782EC 800DEE3C 8FB00068 */  lw        $s0, 0x68($sp)
/* 782F0 800DEE40 D7BC00A0 */  ldc1      $f28, 0xa0($sp)
/* 782F4 800DEE44 D7BA0098 */  ldc1      $f26, 0x98($sp)
/* 782F8 800DEE48 D7B80090 */  ldc1      $f24, 0x90($sp)
/* 782FC 800DEE4C D7B60088 */  ldc1      $f22, 0x88($sp)
/* 78300 800DEE50 D7B40080 */  ldc1      $f20, 0x80($sp)
/* 78304 800DEE54 03E00008 */  jr        $ra
/* 78308 800DEE58 27BD00A8 */   addiu    $sp, $sp, 0xa8
