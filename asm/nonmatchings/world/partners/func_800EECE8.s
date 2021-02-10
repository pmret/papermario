.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EECE8
/* 88198 800EECE8 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 8819C 800EECEC AFB00030 */  sw        $s0, 0x30($sp)
/* 881A0 800EECF0 0080802D */  daddu     $s0, $a0, $zero
/* 881A4 800EECF4 AFB10034 */  sw        $s1, 0x34($sp)
/* 881A8 800EECF8 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 881AC 800EECFC 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 881B0 800EED00 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 881B4 800EED04 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 881B8 800EED08 3C04800B */  lui       $a0, %hi(gCameras)
/* 881BC 800EED0C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 881C0 800EED10 AFB3003C */  sw        $s3, 0x3c($sp)
/* 881C4 800EED14 3C138011 */  lui       $s3, %hi(D_8010CFC8)
/* 881C8 800EED18 2673CFC8 */  addiu     $s3, $s3, %lo(D_8010CFC8)
/* 881CC 800EED1C AFBF0048 */  sw        $ra, 0x48($sp)
/* 881D0 800EED20 AFB50044 */  sw        $s5, 0x44($sp)
/* 881D4 800EED24 AFB40040 */  sw        $s4, 0x40($sp)
/* 881D8 800EED28 AFB20038 */  sw        $s2, 0x38($sp)
/* 881DC 800EED2C F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 881E0 800EED30 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 881E4 800EED34 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 881E8 800EED38 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 881EC 800EED3C 00031080 */  sll       $v0, $v1, 2
/* 881F0 800EED40 00431021 */  addu      $v0, $v0, $v1
/* 881F4 800EED44 00021080 */  sll       $v0, $v0, 2
/* 881F8 800EED48 00431023 */  subu      $v0, $v0, $v1
/* 881FC 800EED4C 000218C0 */  sll       $v1, $v0, 3
/* 88200 800EED50 00431021 */  addu      $v0, $v0, $v1
/* 88204 800EED54 000210C0 */  sll       $v0, $v0, 3
/* 88208 800EED58 00449021 */  addu      $s2, $v0, $a0
/* 8820C 800EED5C 86630000 */  lh        $v1, ($s3)
/* 88210 800EED60 24020001 */  addiu     $v0, $zero, 1
/* 88214 800EED64 106200E6 */  beq       $v1, $v0, .L800EF100
/* 88218 800EED68 28620002 */   slti     $v0, $v1, 2
/* 8821C 800EED6C 10400005 */  beqz      $v0, .L800EED84
/* 88220 800EED70 24020002 */   addiu    $v0, $zero, 2
/* 88224 800EED74 10600007 */  beqz      $v1, .L800EED94
/* 88228 800EED78 0000102D */   daddu    $v0, $zero, $zero
/* 8822C 800EED7C 0803BCB3 */  j         .L800EF2CC
/* 88230 800EED80 00000000 */   nop
.L800EED84:
/* 88234 800EED84 10620123 */  beq       $v1, $v0, .L800EF214
/* 88238 800EED88 0000102D */   daddu    $v0, $zero, $zero
/* 8823C 800EED8C 0803BCB3 */  j         .L800EF2CC
/* 88240 800EED90 00000000 */   nop
.L800EED94:
/* 88244 800EED94 0C00A6C9 */  jal       clamp_angle
/* 88248 800EED98 C62C00A8 */   lwc1     $f12, 0xa8($s1)
/* 8824C 800EED9C 3C014334 */  lui       $at, 0x4334
/* 88250 800EEDA0 44811000 */  mtc1      $at, $f2
/* 88254 800EEDA4 00000000 */  nop
/* 88258 800EEDA8 4602003C */  c.lt.s    $f0, $f2
/* 8825C 800EEDAC 00000000 */  nop
/* 88260 800EEDB0 45000006 */  bc1f      .L800EEDCC
/* 88264 800EEDB4 00000000 */   nop
/* 88268 800EEDB8 C640006C */  lwc1      $f0, 0x6c($s2)
/* 8826C 800EEDBC 3C0142B4 */  lui       $at, 0x42b4
/* 88270 800EEDC0 44816000 */  mtc1      $at, $f12
/* 88274 800EEDC4 0803BB78 */  j         .L800EEDE0
/* 88278 800EEDC8 460C0300 */   add.s    $f12, $f0, $f12
.L800EEDCC:
/* 8827C 800EEDCC C640006C */  lwc1      $f0, 0x6c($s2)
/* 88280 800EEDD0 3C0142B4 */  lui       $at, 0x42b4
/* 88284 800EEDD4 44816000 */  mtc1      $at, $f12
/* 88288 800EEDD8 00000000 */  nop
/* 8828C 800EEDDC 460C0301 */  sub.s     $f12, $f0, $f12
.L800EEDE0:
/* 88290 800EEDE0 0C00A6C9 */  jal       clamp_angle
/* 88294 800EEDE4 00000000 */   nop
/* 88298 800EEDE8 E600000C */  swc1      $f0, 0xc($s0)
/* 8829C 800EEDEC C6200028 */  lwc1      $f0, 0x28($s1)
/* 882A0 800EEDF0 3C128011 */  lui       $s2, %hi(D_8010CFEC)
/* 882A4 800EEDF4 2652CFEC */  addiu     $s2, $s2, %lo(D_8010CFEC)
/* 882A8 800EEDF8 E6000060 */  swc1      $f0, 0x60($s0)
/* 882AC 800EEDFC C620002C */  lwc1      $f0, 0x2c($s1)
/* 882B0 800EEE00 8E420000 */  lw        $v0, ($s2)
/* 882B4 800EEE04 E6000064 */  swc1      $f0, 0x64($s0)
/* 882B8 800EEE08 8C42000C */  lw        $v0, 0xc($v0)
/* 882BC 800EEE0C 10400003 */  beqz      $v0, .L800EEE1C
/* 882C0 800EEE10 26040060 */   addiu    $a0, $s0, 0x60
/* 882C4 800EEE14 C620002C */  lwc1      $f0, 0x2c($s1)
/* 882C8 800EEE18 E6000064 */  swc1      $f0, 0x64($s0)
.L800EEE1C:
/* 882CC 800EEE1C C6200030 */  lwc1      $f0, 0x30($s1)
/* 882D0 800EEE20 E6000068 */  swc1      $f0, 0x68($s0)
/* 882D4 800EEE24 862200B2 */  lh        $v0, 0xb2($s1)
/* 882D8 800EEE28 8E07000C */  lw        $a3, 0xc($s0)
/* 882DC 800EEE2C 44825000 */  mtc1      $v0, $f10
/* 882E0 800EEE30 00000000 */  nop
/* 882E4 800EEE34 468052A0 */  cvt.s.w   $f10, $f10
/* 882E8 800EEE38 44065000 */  mfc1      $a2, $f10
/* 882EC 800EEE3C 0C00A7E7 */  jal       add_vec2D_polar
/* 882F0 800EEE40 26050068 */   addiu    $a1, $s0, 0x68
/* 882F4 800EEE44 C6160060 */  lwc1      $f22, 0x60($s0)
/* 882F8 800EEE48 8E420000 */  lw        $v0, ($s2)
/* 882FC 800EEE4C C61A0064 */  lwc1      $f26, 0x64($s0)
/* 88300 800EEE50 8C42000C */  lw        $v0, 0xc($v0)
/* 88304 800EEE54 C6140068 */  lwc1      $f20, 0x68($s0)
/* 88308 800EEE58 14400052 */  bnez      $v0, .L800EEFA4
/* 8830C 800EEE5C 27B20020 */   addiu    $s2, $sp, 0x20
/* 88310 800EEE60 0240202D */  daddu     $a0, $s2, $zero
/* 88314 800EEE64 27B30024 */  addiu     $s3, $sp, 0x24
/* 88318 800EEE68 0260282D */  daddu     $a1, $s3, $zero
/* 8831C 800EEE6C 3C158007 */  lui       $s5, %hi(gCurrentCameraID)
/* 88320 800EEE70 26B57410 */  addiu     $s5, $s5, %lo(gCurrentCameraID)
/* 88324 800EEE74 8EA30000 */  lw        $v1, ($s5)
/* 88328 800EEE78 3C014000 */  lui       $at, 0x4000
/* 8832C 800EEE7C 4481C000 */  mtc1      $at, $f24
/* 88330 800EEE80 00031080 */  sll       $v0, $v1, 2
/* 88334 800EEE84 00431021 */  addu      $v0, $v0, $v1
/* 88338 800EEE88 00021080 */  sll       $v0, $v0, 2
/* 8833C 800EEE8C 00431023 */  subu      $v0, $v0, $v1
/* 88340 800EEE90 000218C0 */  sll       $v1, $v0, 3
/* 88344 800EEE94 00431021 */  addu      $v0, $v0, $v1
/* 88348 800EEE98 000210C0 */  sll       $v0, $v0, 3
/* 8834C 800EEE9C 4406C000 */  mfc1      $a2, $f24
/* 88350 800EEEA0 860300A8 */  lh        $v1, 0xa8($s0)
/* 88354 800EEEA4 3C07800B */  lui       $a3, %hi(D_800B1DEC)
/* 88358 800EEEA8 00E23821 */  addu      $a3, $a3, $v0
/* 8835C 800EEEAC 8CE71DEC */  lw        $a3, %lo(D_800B1DEC)($a3)
/* 88360 800EEEB0 44830000 */  mtc1      $v1, $f0
/* 88364 800EEEB4 00000000 */  nop
/* 88368 800EEEB8 46800020 */  cvt.s.w   $f0, $f0
/* 8836C 800EEEBC 4600D000 */  add.s     $f0, $f26, $f0
/* 88370 800EEEC0 E7B60020 */  swc1      $f22, 0x20($sp)
/* 88374 800EEEC4 E7B40024 */  swc1      $f20, 0x24($sp)
/* 88378 800EEEC8 0C00A7E7 */  jal       add_vec2D_polar
/* 8837C 800EEECC E7A00028 */   swc1     $f0, 0x28($sp)
/* 88380 800EEED0 3C040001 */  lui       $a0, 1
/* 88384 800EEED4 0240282D */  daddu     $a1, $s2, $zero
/* 88388 800EEED8 27A2002C */  addiu     $v0, $sp, 0x2c
/* 8838C 800EEEDC 3C01447A */  lui       $at, 0x447a
/* 88390 800EEEE0 44810000 */  mtc1      $at, $f0
/* 88394 800EEEE4 27A60028 */  addiu     $a2, $sp, 0x28
/* 88398 800EEEE8 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 8839C 800EEEEC AFA20010 */  sw        $v0, 0x10($sp)
/* 883A0 800EEEF0 C600000C */  lwc1      $f0, 0xc($s0)
/* 883A4 800EEEF4 0260382D */  daddu     $a3, $s3, $zero
/* 883A8 800EEEF8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 883AC 800EEEFC 860200A6 */  lh        $v0, 0xa6($s0)
/* 883B0 800EEF00 3C14800B */  lui       $s4, %hi(gCameras)
/* 883B4 800EEF04 26941D80 */  addiu     $s4, $s4, %lo(gCameras)
/* 883B8 800EEF08 44820000 */  mtc1      $v0, $f0
/* 883BC 800EEF0C 00000000 */  nop
/* 883C0 800EEF10 46800020 */  cvt.s.w   $f0, $f0
/* 883C4 800EEF14 0C0371DE */  jal       func_800DC778
/* 883C8 800EEF18 E7A00018 */   swc1     $f0, 0x18($sp)
/* 883CC 800EEF1C 10400011 */  beqz      $v0, .L800EEF64
/* 883D0 800EEF20 0240202D */   daddu    $a0, $s2, $zero
/* 883D4 800EEF24 3C048011 */  lui       $a0, %hi(D_8010C978)
/* 883D8 800EEF28 8C84C978 */  lw        $a0, %lo(D_8010C978)($a0)
/* 883DC 800EEF2C 0C016F6A */  jal       get_collider_type_by_id
/* 883E0 800EEF30 00000000 */   nop
/* 883E4 800EEF34 2442FFFE */  addiu     $v0, $v0, -2
/* 883E8 800EEF38 2C420002 */  sltiu     $v0, $v0, 2
/* 883EC 800EEF3C 14400009 */  bnez      $v0, .L800EEF64
/* 883F0 800EEF40 0240202D */   daddu    $a0, $s2, $zero
/* 883F4 800EEF44 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 883F8 800EEF48 3C0142C8 */  lui       $at, 0x42c8
/* 883FC 800EEF4C 44810000 */  mtc1      $at, $f0
/* 88400 800EEF50 00000000 */  nop
/* 88404 800EEF54 4602003C */  c.lt.s    $f0, $f2
/* 88408 800EEF58 00000000 */  nop
/* 8840C 800EEF5C 45000011 */  bc1f      .L800EEFA4
/* 88410 800EEF60 00000000 */   nop
.L800EEF64:
/* 88414 800EEF64 C6360028 */  lwc1      $f22, 0x28($s1)
/* 88418 800EEF68 C63A002C */  lwc1      $f26, 0x2c($s1)
/* 8841C 800EEF6C 8EA20000 */  lw        $v0, ($s5)
/* 88420 800EEF70 4406C000 */  mfc1      $a2, $f24
/* 88424 800EEF74 00021880 */  sll       $v1, $v0, 2
/* 88428 800EEF78 00621821 */  addu      $v1, $v1, $v0
/* 8842C 800EEF7C 00031880 */  sll       $v1, $v1, 2
/* 88430 800EEF80 00621823 */  subu      $v1, $v1, $v0
/* 88434 800EEF84 000310C0 */  sll       $v0, $v1, 3
/* 88438 800EEF88 00621821 */  addu      $v1, $v1, $v0
/* 8843C 800EEF8C 000318C0 */  sll       $v1, $v1, 3
/* 88440 800EEF90 00741821 */  addu      $v1, $v1, $s4
/* 88444 800EEF94 8C67006C */  lw        $a3, 0x6c($v1)
/* 88448 800EEF98 C6340030 */  lwc1      $f20, 0x30($s1)
/* 8844C 800EEF9C 0C00A7E7 */  jal       add_vec2D_polar
/* 88450 800EEFA0 0260282D */   daddu    $a1, $s3, $zero
.L800EEFA4:
/* 88454 800EEFA4 C62C0028 */  lwc1      $f12, 0x28($s1)
/* 88458 800EEFA8 4406B000 */  mfc1      $a2, $f22
/* 8845C 800EEFAC 4407A000 */  mfc1      $a3, $f20
/* 88460 800EEFB0 3C013F99 */  lui       $at, 0x3f99
/* 88464 800EEFB4 3421999A */  ori       $at, $at, 0x999a
/* 88468 800EEFB8 44812000 */  mtc1      $at, $f4
/* 8846C 800EEFBC E60C0038 */  swc1      $f12, 0x38($s0)
/* 88470 800EEFC0 962200B0 */  lhu       $v0, 0xb0($s1)
/* 88474 800EEFC4 C622002C */  lwc1      $f2, 0x2c($s1)
/* 88478 800EEFC8 00021400 */  sll       $v0, $v0, 0x10
/* 8847C 800EEFCC 00021C03 */  sra       $v1, $v0, 0x10
/* 88480 800EEFD0 000217C2 */  srl       $v0, $v0, 0x1f
/* 88484 800EEFD4 00621821 */  addu      $v1, $v1, $v0
/* 88488 800EEFD8 00031843 */  sra       $v1, $v1, 1
/* 8848C 800EEFDC 44830000 */  mtc1      $v1, $f0
/* 88490 800EEFE0 00000000 */  nop
/* 88494 800EEFE4 46800020 */  cvt.s.w   $f0, $f0
/* 88498 800EEFE8 46001080 */  add.s     $f2, $f2, $f0
/* 8849C 800EEFEC 3C014080 */  lui       $at, 0x4080
/* 884A0 800EEFF0 44810000 */  mtc1      $at, $f0
/* 884A4 800EEFF4 E602003C */  swc1      $f2, 0x3c($s0)
/* 884A8 800EEFF8 C62E0030 */  lwc1      $f14, 0x30($s1)
/* 884AC 800EEFFC E7AC0020 */  swc1      $f12, 0x20($sp)
/* 884B0 800EF000 E7A20028 */  swc1      $f2, 0x28($sp)
/* 884B4 800EF004 E6000018 */  swc1      $f0, 0x18($s0)
/* 884B8 800EF008 E6040014 */  swc1      $f4, 0x14($s0)
/* 884BC 800EF00C E60E0040 */  swc1      $f14, 0x40($s0)
/* 884C0 800EF010 0C00A7B5 */  jal       dist2D
/* 884C4 800EF014 E7AE0024 */   swc1     $f14, 0x24($sp)
/* 884C8 800EF018 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 884CC 800EF01C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 884D0 800EF020 4406B000 */  mfc1      $a2, $f22
/* 884D4 800EF024 4407A000 */  mfc1      $a3, $f20
/* 884D8 800EF028 0C00A720 */  jal       atan2
/* 884DC 800EF02C E6000010 */   swc1     $f0, 0x10($s0)
/* 884E0 800EF030 C6020010 */  lwc1      $f2, 0x10($s0)
/* 884E4 800EF034 C6040018 */  lwc1      $f4, 0x18($s0)
/* 884E8 800EF038 E600000C */  swc1      $f0, 0xc($s0)
/* 884EC 800EF03C 46041083 */  div.s     $f2, $f2, $f4
/* 884F0 800EF040 4600128D */  trunc.w.s $f10, $f2
/* 884F4 800EF044 44025000 */  mfc1      $v0, $f10
/* 884F8 800EF048 00000000 */  nop
/* 884FC 800EF04C A602008E */  sh        $v0, 0x8e($s0)
/* 88500 800EF050 00021400 */  sll       $v0, $v0, 0x10
/* 88504 800EF054 00021403 */  sra       $v0, $v0, 0x10
/* 88508 800EF058 2842000A */  slti      $v0, $v0, 0xa
/* 8850C 800EF05C 10400007 */  beqz      $v0, .L800EF07C
/* 88510 800EF060 2402000A */   addiu    $v0, $zero, 0xa
/* 88514 800EF064 3C014120 */  lui       $at, 0x4120
/* 88518 800EF068 44810000 */  mtc1      $at, $f0
/* 8851C 800EF06C C6020010 */  lwc1      $f2, 0x10($s0)
/* 88520 800EF070 A602008E */  sh        $v0, 0x8e($s0)
/* 88524 800EF074 46001083 */  div.s     $f2, $f2, $f0
/* 88528 800EF078 E6020018 */  swc1      $f2, 0x18($s0)
.L800EF07C:
/* 8852C 800EF07C 8602008E */  lh        $v0, 0x8e($s0)
/* 88530 800EF080 C6000014 */  lwc1      $f0, 0x14($s0)
/* 88534 800EF084 44822000 */  mtc1      $v0, $f4
/* 88538 800EF088 00000000 */  nop
/* 8853C 800EF08C 46802120 */  cvt.s.w   $f4, $f4
/* 88540 800EF090 46040002 */  mul.s     $f0, $f0, $f4
/* 88544 800EF094 00000000 */  nop
/* 88548 800EF098 46040002 */  mul.s     $f0, $f0, $f4
/* 8854C 800EF09C 00000000 */  nop
/* 88550 800EF0A0 3C013F00 */  lui       $at, 0x3f00
/* 88554 800EF0A4 44811000 */  mtc1      $at, $f2
/* 88558 800EF0A8 00000000 */  nop
/* 8855C 800EF0AC 46020002 */  mul.s     $f0, $f0, $f2
/* 88560 800EF0B0 00000000 */  nop
/* 88564 800EF0B4 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 88568 800EF0B8 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 8856C 800EF0BC 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 88570 800EF0C0 4602D081 */  sub.s     $f2, $f26, $f2
/* 88574 800EF0C4 000310C0 */  sll       $v0, $v1, 3
/* 88578 800EF0C8 46001000 */  add.s     $f0, $f2, $f0
/* 8857C 800EF0CC 00431021 */  addu      $v0, $v0, $v1
/* 88580 800EF0D0 00021080 */  sll       $v0, $v0, 2
/* 88584 800EF0D4 46040003 */  div.s     $f0, $f0, $f4
/* 88588 800EF0D8 E600001C */  swc1      $f0, 0x1c($s0)
/* 8858C 800EF0DC 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x8)
/* 88590 800EF0E0 00621821 */  addu      $v1, $v1, $v0
/* 88594 800EF0E4 8C638350 */  lw        $v1, %lo(gPartnerAnimations+0x8)($v1)
/* 88598 800EF0E8 24020001 */  addiu     $v0, $zero, 1
/* 8859C 800EF0EC 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 885A0 800EF0F0 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 885A4 800EF0F4 E7A20028 */  swc1      $f2, 0x28($sp)
/* 885A8 800EF0F8 0803BCB2 */  j         .L800EF2C8
/* 885AC 800EF0FC AE030028 */   sw       $v1, 0x28($s0)
.L800EF100:
/* 885B0 800EF100 C602001C */  lwc1      $f2, 0x1c($s0)
/* 885B4 800EF104 44800000 */  mtc1      $zero, $f0
/* 885B8 800EF108 00000000 */  nop
/* 885BC 800EF10C 4600103C */  c.lt.s    $f2, $f0
/* 885C0 800EF110 00000000 */  nop
/* 885C4 800EF114 45000009 */  bc1f      .L800EF13C
/* 885C8 800EF118 00000000 */   nop
/* 885CC 800EF11C 46001085 */  abs.s     $f2, $f2
/* 885D0 800EF120 44051000 */  mfc1      $a1, $f2
/* 885D4 800EF124 0C00E5FA */  jal       func_800397E8
/* 885D8 800EF128 0200202D */   daddu    $a0, $s0, $zero
/* 885DC 800EF12C 10400003 */  beqz      $v0, .L800EF13C
/* 885E0 800EF130 24020002 */   addiu    $v0, $zero, 2
/* 885E4 800EF134 0803BCB2 */  j         .L800EF2C8
/* 885E8 800EF138 A6620000 */   sh       $v0, ($s3)
.L800EF13C:
/* 885EC 800EF13C C600001C */  lwc1      $f0, 0x1c($s0)
/* 885F0 800EF140 C6020014 */  lwc1      $f2, 0x14($s0)
/* 885F4 800EF144 46020001 */  sub.s     $f0, $f0, $f2
/* 885F8 800EF148 C602003C */  lwc1      $f2, 0x3c($s0)
/* 885FC 800EF14C E600001C */  swc1      $f0, 0x1c($s0)
/* 88600 800EF150 46000106 */  mov.s     $f4, $f0
/* 88604 800EF154 46001080 */  add.s     $f2, $f2, $f0
/* 88608 800EF158 44800000 */  mtc1      $zero, $f0
/* 8860C 800EF15C 00000000 */  nop
/* 88610 800EF160 4600203E */  c.le.s    $f4, $f0
/* 88614 800EF164 00000000 */  nop
/* 88618 800EF168 4500000A */  bc1f      .L800EF194
/* 8861C 800EF16C E602003C */   swc1     $f2, 0x3c($s0)
/* 88620 800EF170 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 88624 800EF174 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 88628 800EF178 000218C0 */  sll       $v1, $v0, 3
/* 8862C 800EF17C 00621821 */  addu      $v1, $v1, $v0
/* 88630 800EF180 00031880 */  sll       $v1, $v1, 2
/* 88634 800EF184 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 88638 800EF188 00431021 */  addu      $v0, $v0, $v1
/* 8863C 800EF18C 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 88640 800EF190 AE020028 */  sw        $v0, 0x28($s0)
.L800EF194:
/* 88644 800EF194 8E050018 */  lw        $a1, 0x18($s0)
/* 88648 800EF198 8E06000C */  lw        $a2, 0xc($s0)
/* 8864C 800EF19C 0C00EA95 */  jal       npc_move_heading
/* 88650 800EF1A0 0200202D */   daddu    $a0, $s0, $zero
/* 88654 800EF1A4 0C00E2BF */  jal       npc_do_world_collision
/* 88658 800EF1A8 0200202D */   daddu    $a0, $s0, $zero
/* 8865C 800EF1AC 8602008E */  lh        $v0, 0x8e($s0)
/* 88660 800EF1B0 3C014120 */  lui       $at, 0x4120
/* 88664 800EF1B4 44811000 */  mtc1      $at, $f2
/* 88668 800EF1B8 44820000 */  mtc1      $v0, $f0
/* 8866C 800EF1BC 00000000 */  nop
/* 88670 800EF1C0 46800020 */  cvt.s.w   $f0, $f0
/* 88674 800EF1C4 4600103C */  c.lt.s    $f2, $f0
/* 88678 800EF1C8 00000000 */  nop
/* 8867C 800EF1CC 45030001 */  bc1tl     .L800EF1D4
/* 88680 800EF1D0 46001006 */   mov.s    $f0, $f2
.L800EF1D4:
/* 88684 800EF1D4 9602008E */  lhu       $v0, 0x8e($s0)
/* 88688 800EF1D8 46001001 */  sub.s     $f0, $f2, $f0
/* 8868C 800EF1DC 2442FFFF */  addiu     $v0, $v0, -1
/* 88690 800EF1E0 A602008E */  sh        $v0, 0x8e($s0)
/* 88694 800EF1E4 00021400 */  sll       $v0, $v0, 0x10
/* 88698 800EF1E8 46020003 */  div.s     $f0, $f0, $f2
/* 8869C 800EF1EC E6000054 */  swc1      $f0, 0x54($s0)
/* 886A0 800EF1F0 46000086 */  mov.s     $f2, $f0
/* 886A4 800EF1F4 E6000058 */  swc1      $f0, 0x58($s0)
/* 886A8 800EF1F8 04410033 */  bgez      $v0, .L800EF2C8
/* 886AC 800EF1FC E602005C */   swc1     $f2, 0x5c($s0)
/* 886B0 800EF200 24020002 */  addiu     $v0, $zero, 2
/* 886B4 800EF204 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 886B8 800EF208 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 886BC 800EF20C 0803BCB3 */  j         .L800EF2CC
/* 886C0 800EF210 0000102D */   daddu    $v0, $zero, $zero
.L800EF214:
/* 886C4 800EF214 C6000064 */  lwc1      $f0, 0x64($s0)
/* 886C8 800EF218 C6060038 */  lwc1      $f6, 0x38($s0)
/* 886CC 800EF21C C6020040 */  lwc1      $f2, 0x40($s0)
/* 886D0 800EF220 E600003C */  swc1      $f0, 0x3c($s0)
/* 886D4 800EF224 3C013F80 */  lui       $at, 0x3f80
/* 886D8 800EF228 44810000 */  mtc1      $at, $f0
/* 886DC 800EF22C C608003C */  lwc1      $f8, 0x3c($s0)
/* 886E0 800EF230 3C128011 */  lui       $s2, %hi(D_8010CFEC)
/* 886E4 800EF234 2652CFEC */  addiu     $s2, $s2, %lo(D_8010CFEC)
/* 886E8 800EF238 AE00001C */  sw        $zero, 0x1c($s0)
/* 886EC 800EF23C E6060060 */  swc1      $f6, 0x60($s0)
/* 886F0 800EF240 E6020068 */  swc1      $f2, 0x68($s0)
/* 886F4 800EF244 E6000054 */  swc1      $f0, 0x54($s0)
/* 886F8 800EF248 E6000058 */  swc1      $f0, 0x58($s0)
/* 886FC 800EF24C E600005C */  swc1      $f0, 0x5c($s0)
/* 88700 800EF250 E6080064 */  swc1      $f8, 0x64($s0)
/* 88704 800EF254 C620002C */  lwc1      $f0, 0x2c($s1)
/* 88708 800EF258 8E420000 */  lw        $v0, ($s2)
/* 8870C 800EF25C E600003C */  swc1      $f0, 0x3c($s0)
/* 88710 800EF260 8C42000C */  lw        $v0, 0xc($v0)
/* 88714 800EF264 10400003 */  beqz      $v0, .L800EF274
/* 88718 800EF268 46003106 */   mov.s    $f4, $f6
/* 8871C 800EF26C C620002C */  lwc1      $f0, 0x2c($s1)
/* 88720 800EF270 E600003C */  swc1      $f0, 0x3c($s0)
.L800EF274:
/* 88724 800EF274 C6000040 */  lwc1      $f0, 0x40($s0)
/* 88728 800EF278 0C03BD17 */  jal       clear_partner_move_history
/* 8872C 800EF27C 0200202D */   daddu    $a0, $s0, $zero
/* 88730 800EF280 C6000060 */  lwc1      $f0, 0x60($s0)
/* 88734 800EF284 C6020064 */  lwc1      $f2, 0x64($s0)
/* 88738 800EF288 8E020000 */  lw        $v0, ($s0)
/* 8873C 800EF28C C6040068 */  lwc1      $f4, 0x68($s0)
/* 88740 800EF290 30421000 */  andi      $v0, $v0, 0x1000
/* 88744 800EF294 E6000038 */  swc1      $f0, 0x38($s0)
/* 88748 800EF298 E602003C */  swc1      $f2, 0x3c($s0)
/* 8874C 800EF29C 10400008 */  beqz      $v0, .L800EF2C0
/* 88750 800EF2A0 E6040040 */   swc1     $f4, 0x40($s0)
/* 88754 800EF2A4 8E420000 */  lw        $v0, ($s2)
/* 88758 800EF2A8 8C42000C */  lw        $v0, 0xc($v0)
/* 8875C 800EF2AC 14400007 */  bnez      $v0, .L800EF2CC
/* 88760 800EF2B0 24020001 */   addiu    $v0, $zero, 1
/* 88764 800EF2B4 0200202D */  daddu     $a0, $s0, $zero
/* 88768 800EF2B8 0C00F598 */  jal       func_8003D660
/* 8876C 800EF2BC 24050002 */   addiu    $a1, $zero, 2
.L800EF2C0:
/* 88770 800EF2C0 0803BCB3 */  j         .L800EF2CC
/* 88774 800EF2C4 24020001 */   addiu    $v0, $zero, 1
.L800EF2C8:
/* 88778 800EF2C8 0000102D */  daddu     $v0, $zero, $zero
.L800EF2CC:
/* 8877C 800EF2CC 8FBF0048 */  lw        $ra, 0x48($sp)
/* 88780 800EF2D0 8FB50044 */  lw        $s5, 0x44($sp)
/* 88784 800EF2D4 8FB40040 */  lw        $s4, 0x40($sp)
/* 88788 800EF2D8 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8878C 800EF2DC 8FB20038 */  lw        $s2, 0x38($sp)
/* 88790 800EF2E0 8FB10034 */  lw        $s1, 0x34($sp)
/* 88794 800EF2E4 8FB00030 */  lw        $s0, 0x30($sp)
/* 88798 800EF2E8 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 8879C 800EF2EC D7B80060 */  ldc1      $f24, 0x60($sp)
/* 887A0 800EF2F0 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 887A4 800EF2F4 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 887A8 800EF2F8 03E00008 */  jr        $ra
/* 887AC 800EF2FC 27BD0070 */   addiu    $sp, $sp, 0x70
