.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240270_DF6C70
/* DF6C70 80240270 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* DF6C74 80240274 AFB1008C */  sw        $s1, 0x8c($sp)
/* DF6C78 80240278 0080882D */  daddu     $s1, $a0, $zero
/* DF6C7C 8024027C AFB00088 */  sw        $s0, 0x88($sp)
/* DF6C80 80240280 00A0802D */  daddu     $s0, $a1, $zero
/* DF6C84 80240284 0000202D */  daddu     $a0, $zero, $zero
/* DF6C88 80240288 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* DF6C8C 8024028C AFB5009C */  sw        $s5, 0x9c($sp)
/* DF6C90 80240290 AFB40098 */  sw        $s4, 0x98($sp)
/* DF6C94 80240294 AFB30094 */  sw        $s3, 0x94($sp)
/* DF6C98 80240298 AFB20090 */  sw        $s2, 0x90($sp)
/* DF6C9C 8024029C F7B800B8 */  sdc1      $f24, 0xb8($sp)
/* DF6CA0 802402A0 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* DF6CA4 802402A4 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* DF6CA8 802402A8 C6160010 */  lwc1      $f22, 0x10($s0)
/* DF6CAC 802402AC 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF6CB0 802402B0 3C01437F */  lui       $at, 0x437f
/* DF6CB4 802402B4 4481A000 */  mtc1      $at, $f20
/* DF6CB8 802402B8 8E22001C */  lw        $v0, 0x1c($s1)
/* DF6CBC 802402BC 4406A000 */  mfc1      $a2, $f20
/* DF6CC0 802402C0 C6180014 */  lwc1      $f24, 0x14($s0)
/* DF6CC4 802402C4 4680C620 */  cvt.s.w   $f24, $f24
/* DF6CC8 802402C8 AFA20010 */  sw        $v0, 0x10($sp)
/* DF6CCC 802402CC 8E070018 */  lw        $a3, 0x18($s0)
/* DF6CD0 802402D0 0C00A8ED */  jal       update_lerp
/* DF6CD4 802402D4 0000282D */   daddu    $a1, $zero, $zero
/* DF6CD8 802402D8 4600A03C */  c.lt.s    $f20, $f0
/* DF6CDC 802402DC 00000000 */  nop
/* DF6CE0 802402E0 45000002 */  bc1f      .L802402EC
/* DF6CE4 802402E4 27B50038 */   addiu    $s5, $sp, 0x38
/* DF6CE8 802402E8 4600A006 */  mov.s     $f0, $f20
.L802402EC:
/* DF6CEC 802402EC 8E24001C */  lw        $a0, 0x1c($s1)
/* DF6CF0 802402F0 8E030018 */  lw        $v1, 0x18($s0)
/* DF6CF4 802402F4 2482FFFC */  addiu     $v0, $a0, -4
/* DF6CF8 802402F8 14620007 */  bne       $v1, $v0, .L80240318
/* DF6CFC 802402FC 2482FFFD */   addiu    $v0, $a0, -3
/* DF6D00 80240300 4600010D */  trunc.w.s $f4, $f0
/* DF6D04 80240304 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6D08 80240308 0000202D */  daddu     $a0, $zero, $zero
/* DF6D0C 8024030C 2405000A */  addiu     $a1, $zero, 0xa
/* DF6D10 80240310 080900E1 */  j         .L80240384
/* DF6D14 80240314 24060040 */   addiu    $a2, $zero, 0x40
.L80240318:
/* DF6D18 80240318 14620007 */  bne       $v1, $v0, .L80240338
/* DF6D1C 8024031C 2482FFFE */   addiu    $v0, $a0, -2
/* DF6D20 80240320 4600010D */  trunc.w.s $f4, $f0
/* DF6D24 80240324 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6D28 80240328 0000202D */  daddu     $a0, $zero, $zero
/* DF6D2C 8024032C 2405000A */  addiu     $a1, $zero, 0xa
/* DF6D30 80240330 080900E1 */  j         .L80240384
/* DF6D34 80240334 24060060 */   addiu    $a2, $zero, 0x60
.L80240338:
/* DF6D38 80240338 14620007 */  bne       $v1, $v0, .L80240358
/* DF6D3C 8024033C 2482FFFF */   addiu    $v0, $a0, -1
/* DF6D40 80240340 4600010D */  trunc.w.s $f4, $f0
/* DF6D44 80240344 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6D48 80240348 0000202D */  daddu     $a0, $zero, $zero
/* DF6D4C 8024034C 2405000A */  addiu     $a1, $zero, 0xa
/* DF6D50 80240350 080900E1 */  j         .L80240384
/* DF6D54 80240354 2406007F */   addiu    $a2, $zero, 0x7f
.L80240358:
/* DF6D58 80240358 14620006 */  bne       $v1, $v0, .L80240374
/* DF6D5C 8024035C 0000202D */   daddu    $a0, $zero, $zero
/* DF6D60 80240360 4600010D */  trunc.w.s $f4, $f0
/* DF6D64 80240364 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6D68 80240368 2405000A */  addiu     $a1, $zero, 0xa
/* DF6D6C 8024036C 080900E1 */  j         .L80240384
/* DF6D70 80240370 24060050 */   addiu    $a2, $zero, 0x50
.L80240374:
/* DF6D74 80240374 4600010D */  trunc.w.s $f4, $f0
/* DF6D78 80240378 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6D7C 8024037C 24050007 */  addiu     $a1, $zero, 7
/* DF6D80 80240380 240600FF */  addiu     $a2, $zero, 0xff
.L80240384:
/* DF6D84 80240384 00C0382D */  daddu     $a3, $a2, $zero
/* DF6D88 80240388 00C0102D */  daddu     $v0, $a2, $zero
/* DF6D8C 8024038C AFA20010 */  sw        $v0, 0x10($sp)
/* DF6D90 80240390 0C04EAA7 */  jal       fold_update
/* DF6D94 80240394 AFA00018 */   sw       $zero, 0x18($sp)
/* DF6D98 80240398 AFB50010 */  sw        $s5, 0x10($sp)
/* DF6D9C 8024039C 8E040004 */  lw        $a0, 4($s0)
/* DF6DA0 802403A0 8E050008 */  lw        $a1, 8($s0)
/* DF6DA4 802403A4 8E060000 */  lw        $a2, ($s0)
/* DF6DA8 802403A8 8E07000C */  lw        $a3, 0xc($s0)
/* DF6DAC 802403AC 0C04BA38 */  jal       msg_get_glyph
/* DF6DB0 802403B0 3C140001 */   lui      $s4, 1
/* DF6DB4 802403B4 92A2000A */  lbu       $v0, 0xa($s5)
/* DF6DB8 802403B8 3C013FE0 */  lui       $at, 0x3fe0
/* DF6DBC 802403BC 4481A800 */  mtc1      $at, $f21
/* DF6DC0 802403C0 4480A000 */  mtc1      $zero, $f20
/* DF6DC4 802403C4 44820000 */  mtc1      $v0, $f0
/* DF6DC8 802403C8 00000000 */  nop
/* DF6DCC 802403CC 46800021 */  cvt.d.w   $f0, $f0
/* DF6DD0 802403D0 46340002 */  mul.d     $f0, $f0, $f20
/* DF6DD4 802403D4 00000000 */  nop
/* DF6DD8 802403D8 36941630 */  ori       $s4, $s4, 0x1630
/* DF6DDC 802403DC 4600B0A1 */  cvt.d.s   $f2, $f22
/* DF6DE0 802403E0 46201080 */  add.d     $f2, $f2, $f0
/* DF6DE4 802403E4 27B30048 */  addiu     $s3, $sp, 0x48
/* DF6DE8 802403E8 0260202D */  daddu     $a0, $s3, $zero
/* DF6DEC 802403EC 4600C607 */  neg.s     $f24, $f24
/* DF6DF0 802403F0 4406C000 */  mfc1      $a2, $f24
/* DF6DF4 802403F4 462010A0 */  cvt.s.d   $f2, $f2
/* DF6DF8 802403F8 44051000 */  mfc1      $a1, $f2
/* DF6DFC 802403FC 0C019E40 */  jal       guTranslateF
/* DF6E00 80240400 0000382D */   daddu    $a3, $zero, $zero
/* DF6E04 80240404 0260202D */  daddu     $a0, $s3, $zero
/* DF6E08 80240408 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* DF6E0C 8024040C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* DF6E10 80240410 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* DF6E14 80240414 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* DF6E18 80240418 96050000 */  lhu       $a1, ($s0)
/* DF6E1C 8024041C 8E420000 */  lw        $v0, ($s2)
/* DF6E20 80240420 00052980 */  sll       $a1, $a1, 6
/* DF6E24 80240424 00B42821 */  addu      $a1, $a1, $s4
/* DF6E28 80240428 0C019D40 */  jal       guMtxF2L
/* DF6E2C 8024042C 00452821 */   addu     $a1, $v0, $a1
/* DF6E30 80240430 3C02DA38 */  lui       $v0, 0xda38
/* DF6E34 80240434 34420002 */  ori       $v0, $v0, 2
/* DF6E38 80240438 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* DF6E3C 8024043C 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* DF6E40 80240440 8E240000 */  lw        $a0, ($s1)
/* DF6E44 80240444 96050000 */  lhu       $a1, ($s0)
/* DF6E48 80240448 0080302D */  daddu     $a2, $a0, $zero
/* DF6E4C 8024044C ACC20000 */  sw        $v0, ($a2)
/* DF6E50 80240450 30A2FFFF */  andi      $v0, $a1, 0xffff
/* DF6E54 80240454 00021180 */  sll       $v0, $v0, 6
/* DF6E58 80240458 8E430000 */  lw        $v1, ($s2)
/* DF6E5C 8024045C 00541021 */  addu      $v0, $v0, $s4
/* DF6E60 80240460 00621821 */  addu      $v1, $v1, $v0
/* DF6E64 80240464 3C028000 */  lui       $v0, 0x8000
/* DF6E68 80240468 00621821 */  addu      $v1, $v1, $v0
/* DF6E6C 8024046C ACC30004 */  sw        $v1, 4($a2)
/* DF6E70 80240470 8EA20000 */  lw        $v0, ($s5)
/* DF6E74 80240474 24840008 */  addiu     $a0, $a0, 8
/* DF6E78 80240478 AE240000 */  sw        $a0, ($s1)
/* DF6E7C 8024047C AFA20020 */  sw        $v0, 0x20($sp)
/* DF6E80 80240480 8EA20004 */  lw        $v0, 4($s5)
/* DF6E84 80240484 24A50001 */  addiu     $a1, $a1, 1
/* DF6E88 80240488 A6050000 */  sh        $a1, ($s0)
/* DF6E8C 8024048C AFA20024 */  sw        $v0, 0x24($sp)
/* DF6E90 80240490 92A20008 */  lbu       $v0, 8($s5)
/* DF6E94 80240494 A7A20028 */  sh        $v0, 0x28($sp)
/* DF6E98 80240498 92A20009 */  lbu       $v0, 9($s5)
/* DF6E9C 8024049C A7A2002A */  sh        $v0, 0x2a($sp)
/* DF6EA0 802404A0 92A2000A */  lbu       $v0, 0xa($s5)
/* DF6EA4 802404A4 0260382D */  daddu     $a3, $s3, $zero
/* DF6EA8 802404A8 44820000 */  mtc1      $v0, $f0
/* DF6EAC 802404AC 00000000 */  nop
/* DF6EB0 802404B0 46800021 */  cvt.d.w   $f0, $f0
/* DF6EB4 802404B4 46340002 */  mul.d     $f0, $f0, $f20
/* DF6EB8 802404B8 00000000 */  nop
/* DF6EBC 802404BC 0000202D */  daddu     $a0, $zero, $zero
/* DF6EC0 802404C0 3C060005 */  lui       $a2, 5
/* DF6EC4 802404C4 34C60040 */  ori       $a2, $a2, 0x40
/* DF6EC8 802404C8 27A50020 */  addiu     $a1, $sp, 0x20
/* DF6ECC 802404CC A7A0002E */  sh        $zero, 0x2e($sp)
/* DF6ED0 802404D0 240200FF */  addiu     $v0, $zero, 0xff
/* DF6ED4 802404D4 A3A20030 */  sb        $v0, 0x30($sp)
/* DF6ED8 802404D8 46200007 */  neg.d     $f0, $f0
/* DF6EDC 802404DC 4620010D */  trunc.w.d $f4, $f0
/* DF6EE0 802404E0 44022000 */  mfc1      $v0, $f4
/* DF6EE4 802404E4 0C04EBDC */  jal       fold_appendGfx_component
/* DF6EE8 802404E8 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF6EEC 802404EC 3C04D838 */  lui       $a0, 0xd838
/* DF6EF0 802404F0 8E220000 */  lw        $v0, ($s1)
/* DF6EF4 802404F4 34840002 */  ori       $a0, $a0, 2
/* DF6EF8 802404F8 0040182D */  daddu     $v1, $v0, $zero
/* DF6EFC 802404FC 24420008 */  addiu     $v0, $v0, 8
/* DF6F00 80240500 AE220000 */  sw        $v0, ($s1)
/* DF6F04 80240504 24020040 */  addiu     $v0, $zero, 0x40
/* DF6F08 80240508 AC640000 */  sw        $a0, ($v1)
/* DF6F0C 8024050C AC620004 */  sw        $v0, 4($v1)
/* DF6F10 80240510 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* DF6F14 80240514 8FB5009C */  lw        $s5, 0x9c($sp)
/* DF6F18 80240518 8FB40098 */  lw        $s4, 0x98($sp)
/* DF6F1C 8024051C 8FB30094 */  lw        $s3, 0x94($sp)
/* DF6F20 80240520 8FB20090 */  lw        $s2, 0x90($sp)
/* DF6F24 80240524 8FB1008C */  lw        $s1, 0x8c($sp)
/* DF6F28 80240528 8FB00088 */  lw        $s0, 0x88($sp)
/* DF6F2C 8024052C D7B800B8 */  ldc1      $f24, 0xb8($sp)
/* DF6F30 80240530 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* DF6F34 80240534 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* DF6F38 80240538 03E00008 */  jr        $ra
/* DF6F3C 8024053C 27BD00C0 */   addiu    $sp, $sp, 0xc0
