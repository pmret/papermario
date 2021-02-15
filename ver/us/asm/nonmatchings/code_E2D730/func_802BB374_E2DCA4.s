.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB374_E2DCA4
/* E2DCA4 802BB374 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* E2DCA8 802BB378 AFBF00B8 */  sw        $ra, 0xb8($sp)
/* E2DCAC 802BB37C AFB500B4 */  sw        $s5, 0xb4($sp)
/* E2DCB0 802BB380 AFB400B0 */  sw        $s4, 0xb0($sp)
/* E2DCB4 802BB384 AFB300AC */  sw        $s3, 0xac($sp)
/* E2DCB8 802BB388 AFB200A8 */  sw        $s2, 0xa8($sp)
/* E2DCBC 802BB38C AFB100A4 */  sw        $s1, 0xa4($sp)
/* E2DCC0 802BB390 AFB000A0 */  sw        $s0, 0xa0($sp)
/* E2DCC4 802BB394 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* E2DCC8 802BB398 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* E2DCCC 802BB39C 0C04417A */  jal       get_entity_by_index
/* E2DCD0 802BB3A0 3C140001 */   lui      $s4, 1
/* E2DCD4 802BB3A4 0040902D */  daddu     $s2, $v0, $zero
/* E2DCD8 802BB3A8 27B10058 */  addiu     $s1, $sp, 0x58
/* E2DCDC 802BB3AC 8E530040 */  lw        $s3, 0x40($s2)
/* E2DCE0 802BB3B0 4480A000 */  mtc1      $zero, $f20
/* E2DCE4 802BB3B4 3C013F80 */  lui       $at, 0x3f80
/* E2DCE8 802BB3B8 4481B000 */  mtc1      $at, $f22
/* E2DCEC 802BB3BC 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* E2DCF0 802BB3C0 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* E2DCF4 802BB3C4 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2DCF8 802BB3C8 8E450064 */  lw        $a1, 0x64($s2)
/* E2DCFC 802BB3CC 4406A000 */  mfc1      $a2, $f20
/* E2DD00 802BB3D0 4407B000 */  mfc1      $a3, $f22
/* E2DD04 802BB3D4 8EB00000 */  lw        $s0, ($s5)
/* E2DD08 802BB3D8 0C019EC8 */  jal       guRotateF
/* E2DD0C 802BB3DC 0220202D */   daddu    $a0, $s1, $zero
/* E2DD10 802BB3E0 8E450054 */  lw        $a1, 0x54($s2)
/* E2DD14 802BB3E4 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DD18 802BB3E8 00A0302D */  daddu     $a2, $a1, $zero
/* E2DD1C 802BB3EC 0C019DF0 */  jal       guScaleF
/* E2DD20 802BB3F0 00A0382D */   daddu    $a3, $a1, $zero
/* E2DD24 802BB3F4 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DD28 802BB3F8 0220282D */  daddu     $a1, $s1, $zero
/* E2DD2C 802BB3FC 0C019D80 */  jal       guMtxCatF
/* E2DD30 802BB400 0220302D */   daddu    $a2, $s1, $zero
/* E2DD34 802BB404 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DD38 802BB408 3C050A00 */  lui       $a1, 0xa00
/* E2DD3C 802BB40C 24A51098 */  addiu     $a1, $a1, 0x1098
/* E2DD40 802BB410 8E420044 */  lw        $v0, 0x44($s2)
/* E2DD44 802BB414 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2DD48 802BB418 0C019D60 */  jal       guMtxL2F
/* E2DD4C 802BB41C 00452821 */   addu     $a1, $v0, $a1
/* E2DD50 802BB420 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* E2DD54 802BB424 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* E2DD58 802BB428 3C014334 */  lui       $at, 0x4334
/* E2DD5C 802BB42C 44810000 */  mtc1      $at, $f0
/* E2DD60 802BB430 00000000 */  nop
/* E2DD64 802BB434 46006300 */  add.s     $f12, $f12, $f0
/* E2DD68 802BB438 3C0140C9 */  lui       $at, 0x40c9
/* E2DD6C 802BB43C 34210FD0 */  ori       $at, $at, 0xfd0
/* E2DD70 802BB440 44810000 */  mtc1      $at, $f0
/* E2DD74 802BB444 00000000 */  nop
/* E2DD78 802BB448 46006302 */  mul.s     $f12, $f12, $f0
/* E2DD7C 802BB44C 00000000 */  nop
/* E2DD80 802BB450 27A50098 */  addiu     $a1, $sp, 0x98
/* E2DD84 802BB454 3C0143B4 */  lui       $at, 0x43b4
/* E2DD88 802BB458 44810000 */  mtc1      $at, $f0
/* E2DD8C 802BB45C 27A6009C */  addiu     $a2, $sp, 0x9c
/* E2DD90 802BB460 0C00A82D */  jal       sin_cos_rad
/* E2DD94 802BB464 46006303 */   div.s    $f12, $f12, $f0
/* E2DD98 802BB468 C7A2004C */  lwc1      $f2, 0x4c($sp)
/* E2DD9C 802BB46C 3C014120 */  lui       $at, 0x4120
/* E2DDA0 802BB470 44812000 */  mtc1      $at, $f4
/* E2DDA4 802BB474 0220202D */  daddu     $a0, $s1, $zero
/* E2DDA8 802BB478 46041080 */  add.s     $f2, $f2, $f4
/* E2DDAC 802BB47C C7A00050 */  lwc1      $f0, 0x50($sp)
/* E2DDB0 802BB480 27A50018 */  addiu     $a1, $sp, 0x18
/* E2DDB4 802BB484 46040001 */  sub.s     $f0, $f0, $f4
/* E2DDB8 802BB488 00A0302D */  daddu     $a2, $a1, $zero
/* E2DDBC 802BB48C E7A2004C */  swc1      $f2, 0x4c($sp)
/* E2DDC0 802BB490 0C019D80 */  jal       guMtxCatF
/* E2DDC4 802BB494 E7A00050 */   swc1     $f0, 0x50($sp)
/* E2DDC8 802BB498 E7B60010 */  swc1      $f22, 0x10($sp)
/* E2DDCC 802BB49C 8E450068 */  lw        $a1, 0x68($s2)
/* E2DDD0 802BB4A0 4406A000 */  mfc1      $a2, $f20
/* E2DDD4 802BB4A4 4407A000 */  mfc1      $a3, $f20
/* E2DDD8 802BB4A8 0C019EC8 */  jal       guRotateF
/* E2DDDC 802BB4AC 0220202D */   daddu    $a0, $s1, $zero
/* E2DDE0 802BB4B0 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DDE4 802BB4B4 0220282D */  daddu     $a1, $s1, $zero
/* E2DDE8 802BB4B8 0C019D80 */  jal       guMtxCatF
/* E2DDEC 802BB4BC 0080302D */   daddu    $a2, $a0, $zero
/* E2DDF0 802BB4C0 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2DDF4 802BB4C4 8E650008 */  lw        $a1, 8($s3)
/* E2DDF8 802BB4C8 4406A000 */  mfc1      $a2, $f20
/* E2DDFC 802BB4CC 4407B000 */  mfc1      $a3, $f22
/* E2DE00 802BB4D0 0C019EC8 */  jal       guRotateF
/* E2DE04 802BB4D4 0220202D */   daddu    $a0, $s1, $zero
/* E2DE08 802BB4D8 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DE0C 802BB4DC 0220282D */  daddu     $a1, $s1, $zero
/* E2DE10 802BB4E0 0C019D80 */  jal       guMtxCatF
/* E2DE14 802BB4E4 0080302D */   daddu    $a2, $a0, $zero
/* E2DE18 802BB4E8 C7A00098 */  lwc1      $f0, 0x98($sp)
/* E2DE1C 802BB4EC 3C014180 */  lui       $at, 0x4180
/* E2DE20 802BB4F0 44812000 */  mtc1      $at, $f4
/* E2DE24 802BB4F4 00000000 */  nop
/* E2DE28 802BB4F8 46040002 */  mul.s     $f0, $f0, $f4
/* E2DE2C 802BB4FC 00000000 */  nop
/* E2DE30 802BB500 C7A2009C */  lwc1      $f2, 0x9c($sp)
/* E2DE34 802BB504 46041082 */  mul.s     $f2, $f2, $f4
/* E2DE38 802BB508 00000000 */  nop
/* E2DE3C 802BB50C C6440048 */  lwc1      $f4, 0x48($s2)
/* E2DE40 802BB510 46002100 */  add.s     $f4, $f4, $f0
/* E2DE44 802BB514 C6400050 */  lwc1      $f0, 0x50($s2)
/* E2DE48 802BB518 36941630 */  ori       $s4, $s4, 0x1630
/* E2DE4C 802BB51C 46020001 */  sub.s     $f0, $f0, $f2
/* E2DE50 802BB520 8E46004C */  lw        $a2, 0x4c($s2)
/* E2DE54 802BB524 44052000 */  mfc1      $a1, $f4
/* E2DE58 802BB528 44070000 */  mfc1      $a3, $f0
/* E2DE5C 802BB52C 0C019E40 */  jal       guTranslateF
/* E2DE60 802BB530 0220202D */   daddu    $a0, $s1, $zero
/* E2DE64 802BB534 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DE68 802BB538 0220282D */  daddu     $a1, $s1, $zero
/* E2DE6C 802BB53C 0C019D80 */  jal       guMtxCatF
/* E2DE70 802BB540 0080302D */   daddu    $a2, $a0, $zero
/* E2DE74 802BB544 0200182D */  daddu     $v1, $s0, $zero
/* E2DE78 802BB548 26100008 */  addiu     $s0, $s0, 8
/* E2DE7C 802BB54C 3C05FCFF */  lui       $a1, 0xfcff
/* E2DE80 802BB550 34A5B3FF */  ori       $a1, $a1, 0xb3ff
/* E2DE84 802BB554 3C02FF2C */  lui       $v0, 0xff2c
/* E2DE88 802BB558 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* E2DE8C 802BB55C 0200302D */  daddu     $a2, $s0, $zero
/* E2DE90 802BB560 26100008 */  addiu     $s0, $s0, 8
/* E2DE94 802BB564 27A40018 */  addiu     $a0, $sp, 0x18
/* E2DE98 802BB568 AC620004 */  sw        $v0, 4($v1)
/* E2DE9C 802BB56C 3C02FA00 */  lui       $v0, 0xfa00
/* E2DEA0 802BB570 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* E2DEA4 802BB574 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* E2DEA8 802BB578 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E2DEAC 802BB57C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E2DEB0 802BB580 AC650000 */  sw        $a1, ($v1)
/* E2DEB4 802BB584 ACC20000 */  sw        $v0, ($a2)
/* E2DEB8 802BB588 96250000 */  lhu       $a1, ($s1)
/* E2DEBC 802BB58C 8E620000 */  lw        $v0, ($s3)
/* E2DEC0 802BB590 9243000B */  lbu       $v1, 0xb($s2)
/* E2DEC4 802BB594 00052980 */  sll       $a1, $a1, 6
/* E2DEC8 802BB598 00B42821 */  addu      $a1, $a1, $s4
/* E2DECC 802BB59C 00452821 */  addu      $a1, $v0, $a1
/* E2DED0 802BB5A0 0C019D40 */  jal       guMtxF2L
/* E2DED4 802BB5A4 ACC30004 */   sw       $v1, 4($a2)
/* E2DED8 802BB5A8 0200202D */  daddu     $a0, $s0, $zero
/* E2DEDC 802BB5AC 26100008 */  addiu     $s0, $s0, 8
/* E2DEE0 802BB5B0 3C03DA38 */  lui       $v1, 0xda38
/* E2DEE4 802BB5B4 34630002 */  ori       $v1, $v1, 2
/* E2DEE8 802BB5B8 0200282D */  daddu     $a1, $s0, $zero
/* E2DEEC 802BB5BC 26100008 */  addiu     $s0, $s0, 8
/* E2DEF0 802BB5C0 0200302D */  daddu     $a2, $s0, $zero
/* E2DEF4 802BB5C4 26100008 */  addiu     $s0, $s0, 8
/* E2DEF8 802BB5C8 3C07D838 */  lui       $a3, 0xd838
/* E2DEFC 802BB5CC 96220000 */  lhu       $v0, ($s1)
/* E2DF00 802BB5D0 34E70002 */  ori       $a3, $a3, 2
/* E2DF04 802BB5D4 AC830000 */  sw        $v1, ($a0)
/* E2DF08 802BB5D8 AEB00000 */  sw        $s0, ($s5)
/* E2DF0C 802BB5DC 24430001 */  addiu     $v1, $v0, 1
/* E2DF10 802BB5E0 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2DF14 802BB5E4 00021180 */  sll       $v0, $v0, 6
/* E2DF18 802BB5E8 A6230000 */  sh        $v1, ($s1)
/* E2DF1C 802BB5EC 8E630000 */  lw        $v1, ($s3)
/* E2DF20 802BB5F0 00541021 */  addu      $v0, $v0, $s4
/* E2DF24 802BB5F4 00621821 */  addu      $v1, $v1, $v0
/* E2DF28 802BB5F8 3C02DE00 */  lui       $v0, 0xde00
/* E2DF2C 802BB5FC AC830004 */  sw        $v1, 4($a0)
/* E2DF30 802BB600 ACA20000 */  sw        $v0, ($a1)
/* E2DF34 802BB604 3C020A00 */  lui       $v0, 0xa00
/* E2DF38 802BB608 244213B8 */  addiu     $v0, $v0, 0x13b8
/* E2DF3C 802BB60C ACA20004 */  sw        $v0, 4($a1)
/* E2DF40 802BB610 24020040 */  addiu     $v0, $zero, 0x40
/* E2DF44 802BB614 ACC70000 */  sw        $a3, ($a2)
/* E2DF48 802BB618 ACC20004 */  sw        $v0, 4($a2)
/* E2DF4C 802BB61C 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* E2DF50 802BB620 8FB500B4 */  lw        $s5, 0xb4($sp)
/* E2DF54 802BB624 8FB400B0 */  lw        $s4, 0xb0($sp)
/* E2DF58 802BB628 8FB300AC */  lw        $s3, 0xac($sp)
/* E2DF5C 802BB62C 8FB200A8 */  lw        $s2, 0xa8($sp)
/* E2DF60 802BB630 8FB100A4 */  lw        $s1, 0xa4($sp)
/* E2DF64 802BB634 8FB000A0 */  lw        $s0, 0xa0($sp)
/* E2DF68 802BB638 D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* E2DF6C 802BB63C D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* E2DF70 802BB640 03E00008 */  jr        $ra
/* E2DF74 802BB644 27BD00D0 */   addiu    $sp, $sp, 0xd0
