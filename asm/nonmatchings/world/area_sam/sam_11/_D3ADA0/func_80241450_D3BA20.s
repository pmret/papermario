.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241450_D3BA20
/* D3BA20 80241450 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D3BA24 80241454 AFB20018 */  sw        $s2, 0x18($sp)
/* D3BA28 80241458 0080902D */  daddu     $s2, $a0, $zero
/* D3BA2C 8024145C AFBF0030 */  sw        $ra, 0x30($sp)
/* D3BA30 80241460 AFB7002C */  sw        $s7, 0x2c($sp)
/* D3BA34 80241464 AFB60028 */  sw        $s6, 0x28($sp)
/* D3BA38 80241468 AFB50024 */  sw        $s5, 0x24($sp)
/* D3BA3C 8024146C AFB40020 */  sw        $s4, 0x20($sp)
/* D3BA40 80241470 AFB3001C */  sw        $s3, 0x1c($sp)
/* D3BA44 80241474 AFB10014 */  sw        $s1, 0x14($sp)
/* D3BA48 80241478 AFB00010 */  sw        $s0, 0x10($sp)
/* D3BA4C 8024147C F7B60040 */  sdc1      $f22, 0x40($sp)
/* D3BA50 80241480 F7B40038 */  sdc1      $f20, 0x38($sp)
/* D3BA54 80241484 8E50000C */  lw        $s0, 0xc($s2)
/* D3BA58 80241488 8E050000 */  lw        $a1, ($s0)
/* D3BA5C 8024148C 0C0B1EAF */  jal       get_variable
/* D3BA60 80241490 26100004 */   addiu    $s0, $s0, 4
/* D3BA64 80241494 8E050000 */  lw        $a1, ($s0)
/* D3BA68 80241498 26100004 */  addiu     $s0, $s0, 4
/* D3BA6C 8024149C 0240202D */  daddu     $a0, $s2, $zero
/* D3BA70 802414A0 0C0B1EAF */  jal       get_variable
/* D3BA74 802414A4 0040B82D */   daddu    $s7, $v0, $zero
/* D3BA78 802414A8 8E050000 */  lw        $a1, ($s0)
/* D3BA7C 802414AC 26100004 */  addiu     $s0, $s0, 4
/* D3BA80 802414B0 0240202D */  daddu     $a0, $s2, $zero
/* D3BA84 802414B4 0C0B1EAF */  jal       get_variable
/* D3BA88 802414B8 0040B02D */   daddu    $s6, $v0, $zero
/* D3BA8C 802414BC 0240202D */  daddu     $a0, $s2, $zero
/* D3BA90 802414C0 3C05F4AC */  lui       $a1, 0xf4ac
/* D3BA94 802414C4 34A5D481 */  ori       $a1, $a1, 0xd481
/* D3BA98 802414C8 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* D3BA9C 802414CC 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* D3BAA0 802414D0 8E140000 */  lw        $s4, ($s0)
/* D3BAA4 802414D4 00061880 */  sll       $v1, $a2, 2
/* D3BAA8 802414D8 00661821 */  addu      $v1, $v1, $a2
/* D3BAAC 802414DC 00031880 */  sll       $v1, $v1, 2
/* D3BAB0 802414E0 00661823 */  subu      $v1, $v1, $a2
/* D3BAB4 802414E4 000330C0 */  sll       $a2, $v1, 3
/* D3BAB8 802414E8 00661821 */  addu      $v1, $v1, $a2
/* D3BABC 802414EC 000318C0 */  sll       $v1, $v1, 3
/* D3BAC0 802414F0 3C01800B */  lui       $at, 0x800b
/* D3BAC4 802414F4 00230821 */  addu      $at, $at, $v1
/* D3BAC8 802414F8 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* D3BACC 802414FC 8E150004 */  lw        $s5, 4($s0)
/* D3BAD0 80241500 4600010D */  trunc.w.s $f4, $f0
/* D3BAD4 80241504 44112000 */  mfc1      $s1, $f4
/* D3BAD8 80241508 0C0B1EAF */  jal       get_variable
/* D3BADC 8024150C 0040982D */   daddu    $s3, $v0, $zero
/* D3BAE0 80241510 4491B000 */  mtc1      $s1, $f22
/* D3BAE4 80241514 00000000 */  nop       
/* D3BAE8 80241518 4680B5A0 */  cvt.s.w   $f22, $f22
/* D3BAEC 8024151C 4600B306 */  mov.s     $f12, $f22
/* D3BAF0 80241520 0C00A8D4 */  jal       cos_deg
/* D3BAF4 80241524 0040802D */   daddu    $s0, $v0, $zero
/* D3BAF8 80241528 4493A000 */  mtc1      $s3, $f20
/* D3BAFC 8024152C 00000000 */  nop       
/* D3BB00 80241530 4680A520 */  cvt.s.w   $f20, $f20
/* D3BB04 80241534 4600A002 */  mul.s     $f0, $f20, $f0
/* D3BB08 80241538 00000000 */  nop       
/* D3BB0C 8024153C 0240202D */  daddu     $a0, $s2, $zero
/* D3BB10 80241540 44901000 */  mtc1      $s0, $f2
/* D3BB14 80241544 00000000 */  nop       
/* D3BB18 80241548 468010A0 */  cvt.s.w   $f2, $f2
/* D3BB1C 8024154C 46001081 */  sub.s     $f2, $f2, $f0
/* D3BB20 80241550 3C05F4AC */  lui       $a1, 0xf4ac
/* D3BB24 80241554 4600110D */  trunc.w.s $f4, $f2
/* D3BB28 80241558 44102000 */  mfc1      $s0, $f4
/* D3BB2C 8024155C 0C0B1EAF */  jal       get_variable
/* D3BB30 80241560 34A5D483 */   ori      $a1, $a1, 0xd483
/* D3BB34 80241564 4600B306 */  mov.s     $f12, $f22
/* D3BB38 80241568 0C00A8BB */  jal       sin_deg
/* D3BB3C 8024156C 0040882D */   daddu    $s1, $v0, $zero
/* D3BB40 80241570 4600A502 */  mul.s     $f20, $f20, $f0
/* D3BB44 80241574 00000000 */  nop       
/* D3BB48 80241578 0240202D */  daddu     $a0, $s2, $zero
/* D3BB4C 8024157C 44910000 */  mtc1      $s1, $f0
/* D3BB50 80241580 00000000 */  nop       
/* D3BB54 80241584 46800020 */  cvt.s.w   $f0, $f0
/* D3BB58 80241588 46140001 */  sub.s     $f0, $f0, $f20
/* D3BB5C 8024158C 0280282D */  daddu     $a1, $s4, $zero
/* D3BB60 80241590 02173023 */  subu      $a2, $s0, $s7
/* D3BB64 80241594 4600010D */  trunc.w.s $f4, $f0
/* D3BB68 80241598 44102000 */  mfc1      $s0, $f4
/* D3BB6C 8024159C 0C0B2026 */  jal       set_variable
/* D3BB70 802415A0 02168023 */   subu     $s0, $s0, $s6
/* D3BB74 802415A4 0240202D */  daddu     $a0, $s2, $zero
/* D3BB78 802415A8 02A0282D */  daddu     $a1, $s5, $zero
/* D3BB7C 802415AC 0C0B2026 */  jal       set_variable
/* D3BB80 802415B0 0200302D */   daddu    $a2, $s0, $zero
/* D3BB84 802415B4 8FBF0030 */  lw        $ra, 0x30($sp)
/* D3BB88 802415B8 8FB7002C */  lw        $s7, 0x2c($sp)
/* D3BB8C 802415BC 8FB60028 */  lw        $s6, 0x28($sp)
/* D3BB90 802415C0 8FB50024 */  lw        $s5, 0x24($sp)
/* D3BB94 802415C4 8FB40020 */  lw        $s4, 0x20($sp)
/* D3BB98 802415C8 8FB3001C */  lw        $s3, 0x1c($sp)
/* D3BB9C 802415CC 8FB20018 */  lw        $s2, 0x18($sp)
/* D3BBA0 802415D0 8FB10014 */  lw        $s1, 0x14($sp)
/* D3BBA4 802415D4 8FB00010 */  lw        $s0, 0x10($sp)
/* D3BBA8 802415D8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* D3BBAC 802415DC D7B40038 */  ldc1      $f20, 0x38($sp)
/* D3BBB0 802415E0 24020002 */  addiu     $v0, $zero, 2
/* D3BBB4 802415E4 03E00008 */  jr        $ra
/* D3BBB8 802415E8 27BD0048 */   addiu    $sp, $sp, 0x48
