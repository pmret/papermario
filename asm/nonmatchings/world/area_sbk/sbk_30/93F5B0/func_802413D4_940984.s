.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D4_940984
/* 940984 802413D4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 940988 802413D8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 94098C 802413DC 0080882D */  daddu     $s1, $a0, $zero
/* 940990 802413E0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 940994 802413E4 AFB60030 */  sw        $s6, 0x30($sp)
/* 940998 802413E8 AFB5002C */  sw        $s5, 0x2c($sp)
/* 94099C 802413EC AFB40028 */  sw        $s4, 0x28($sp)
/* 9409A0 802413F0 AFB30024 */  sw        $s3, 0x24($sp)
/* 9409A4 802413F4 AFB20020 */  sw        $s2, 0x20($sp)
/* 9409A8 802413F8 AFB00018 */  sw        $s0, 0x18($sp)
/* 9409AC 802413FC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 9409B0 80241400 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9409B4 80241404 8E30000C */  lw        $s0, 0xc($s1)
/* 9409B8 80241408 8E160000 */  lw        $s6, ($s0)
/* 9409BC 8024140C 26100004 */  addiu     $s0, $s0, 4
/* 9409C0 80241410 0C0B1EAF */  jal       get_variable
/* 9409C4 80241414 02C0282D */   daddu    $a1, $s6, $zero
/* 9409C8 80241418 44820000 */  mtc1      $v0, $f0
/* 9409CC 8024141C 00000000 */  nop       
/* 9409D0 80241420 46800020 */  cvt.s.w   $f0, $f0
/* 9409D4 80241424 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9409D8 80241428 8E140000 */  lw        $s4, ($s0)
/* 9409DC 8024142C 26100004 */  addiu     $s0, $s0, 4
/* 9409E0 80241430 0220202D */  daddu     $a0, $s1, $zero
/* 9409E4 80241434 0C0B1EAF */  jal       get_variable
/* 9409E8 80241438 0280282D */   daddu    $a1, $s4, $zero
/* 9409EC 8024143C 0220202D */  daddu     $a0, $s1, $zero
/* 9409F0 80241440 8E150000 */  lw        $s5, ($s0)
/* 9409F4 80241444 4482B000 */  mtc1      $v0, $f22
/* 9409F8 80241448 00000000 */  nop       
/* 9409FC 8024144C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 940A00 80241450 0C0B1EAF */  jal       get_variable
/* 940A04 80241454 02A0282D */   daddu    $a1, $s5, $zero
/* 940A08 80241458 2404FFFC */  addiu     $a0, $zero, -4
/* 940A0C 8024145C 44820000 */  mtc1      $v0, $f0
/* 940A10 80241460 00000000 */  nop       
/* 940A14 80241464 46800020 */  cvt.s.w   $f0, $f0
/* 940A18 80241468 0C00EABB */  jal       get_npc_unsafe
/* 940A1C 8024146C E7A00014 */   swc1     $f0, 0x14($sp)
/* 940A20 80241470 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 940A24 80241474 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 940A28 80241478 3C014334 */  lui       $at, 0x4334
/* 940A2C 8024147C 44816000 */  mtc1      $at, $f12
/* 940A30 80241480 00041880 */  sll       $v1, $a0, 2
/* 940A34 80241484 00641821 */  addu      $v1, $v1, $a0
/* 940A38 80241488 00031880 */  sll       $v1, $v1, 2
/* 940A3C 8024148C 00641823 */  subu      $v1, $v1, $a0
/* 940A40 80241490 000320C0 */  sll       $a0, $v1, 3
/* 940A44 80241494 00641821 */  addu      $v1, $v1, $a0
/* 940A48 80241498 000318C0 */  sll       $v1, $v1, 3
/* 940A4C 8024149C 3C01800B */  lui       $at, 0x800b
/* 940A50 802414A0 00230821 */  addu      $at, $at, $v1
/* 940A54 802414A4 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 940A58 802414A8 460C0300 */  add.s     $f12, $f0, $f12
/* 940A5C 802414AC 0C00A6C9 */  jal       clamp_angle
/* 940A60 802414B0 0040982D */   daddu    $s3, $v0, $zero
/* 940A64 802414B4 27B00010 */  addiu     $s0, $sp, 0x10
/* 940A68 802414B8 0200202D */  daddu     $a0, $s0, $zero
/* 940A6C 802414BC 27B20014 */  addiu     $s2, $sp, 0x14
/* 940A70 802414C0 0240282D */  daddu     $a1, $s2, $zero
/* 940A74 802414C4 3C064170 */  lui       $a2, 0x4170
/* 940A78 802414C8 8E67000C */  lw        $a3, 0xc($s3)
/* 940A7C 802414CC 0C00A7E7 */  jal       add_vec2D_polar
/* 940A80 802414D0 46000506 */   mov.s    $f20, $f0
/* 940A84 802414D4 0200202D */  daddu     $a0, $s0, $zero
/* 940A88 802414D8 3C064120 */  lui       $a2, 0x4120
/* 940A8C 802414DC 4407A000 */  mfc1      $a3, $f20
/* 940A90 802414E0 0C00A7E7 */  jal       add_vec2D_polar
/* 940A94 802414E4 0240282D */   daddu    $a1, $s2, $zero
/* 940A98 802414E8 0220202D */  daddu     $a0, $s1, $zero
/* 940A9C 802414EC C7A00010 */  lwc1      $f0, 0x10($sp)
/* 940AA0 802414F0 4600008D */  trunc.w.s $f2, $f0
/* 940AA4 802414F4 44061000 */  mfc1      $a2, $f2
/* 940AA8 802414F8 0C0B2026 */  jal       set_variable
/* 940AAC 802414FC 02C0282D */   daddu    $a1, $s6, $zero
/* 940AB0 80241500 0220202D */  daddu     $a0, $s1, $zero
/* 940AB4 80241504 4600B08D */  trunc.w.s $f2, $f22
/* 940AB8 80241508 44061000 */  mfc1      $a2, $f2
/* 940ABC 8024150C 0C0B2026 */  jal       set_variable
/* 940AC0 80241510 0280282D */   daddu    $a1, $s4, $zero
/* 940AC4 80241514 0220202D */  daddu     $a0, $s1, $zero
/* 940AC8 80241518 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 940ACC 8024151C 4600008D */  trunc.w.s $f2, $f0
/* 940AD0 80241520 44061000 */  mfc1      $a2, $f2
/* 940AD4 80241524 0C0B2026 */  jal       set_variable
/* 940AD8 80241528 02A0282D */   daddu    $a1, $s5, $zero
/* 940ADC 8024152C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 940AE0 80241530 8FB60030 */  lw        $s6, 0x30($sp)
/* 940AE4 80241534 8FB5002C */  lw        $s5, 0x2c($sp)
/* 940AE8 80241538 8FB40028 */  lw        $s4, 0x28($sp)
/* 940AEC 8024153C 8FB30024 */  lw        $s3, 0x24($sp)
/* 940AF0 80241540 8FB20020 */  lw        $s2, 0x20($sp)
/* 940AF4 80241544 8FB1001C */  lw        $s1, 0x1c($sp)
/* 940AF8 80241548 8FB00018 */  lw        $s0, 0x18($sp)
/* 940AFC 8024154C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 940B00 80241550 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 940B04 80241554 24020002 */  addiu     $v0, $zero, 2
/* 940B08 80241558 03E00008 */  jr        $ra
/* 940B0C 8024155C 27BD0048 */   addiu    $sp, $sp, 0x48
