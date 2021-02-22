.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241294_DF7C94
/* DF7C94 80241294 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* DF7C98 80241298 AFB00088 */  sw        $s0, 0x88($sp)
/* DF7C9C 8024129C 00A0802D */  daddu     $s0, $a1, $zero
/* DF7CA0 802412A0 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* DF7CA4 802412A4 AFB5009C */  sw        $s5, 0x9c($sp)
/* DF7CA8 802412A8 AFB40098 */  sw        $s4, 0x98($sp)
/* DF7CAC 802412AC AFB30094 */  sw        $s3, 0x94($sp)
/* DF7CB0 802412B0 AFB20090 */  sw        $s2, 0x90($sp)
/* DF7CB4 802412B4 AFB1008C */  sw        $s1, 0x8c($sp)
/* DF7CB8 802412B8 F7BA00C0 */  sdc1      $f26, 0xc0($sp)
/* DF7CBC 802412BC F7B800B8 */  sdc1      $f24, 0xb8($sp)
/* DF7CC0 802412C0 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* DF7CC4 802412C4 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* DF7CC8 802412C8 C6140010 */  lwc1      $f20, 0x10($s0)
/* DF7CCC 802412CC 4680A520 */  cvt.s.w   $f20, $f20
/* DF7CD0 802412D0 4480C000 */  mtc1      $zero, $f24
/* DF7CD4 802412D4 3C05437F */  lui       $a1, 0x437f
/* DF7CD8 802412D8 8C820050 */  lw        $v0, 0x50($a0)
/* DF7CDC 802412DC 4406C000 */  mfc1      $a2, $f24
/* DF7CE0 802412E0 C61A0014 */  lwc1      $f26, 0x14($s0)
/* DF7CE4 802412E4 4680D6A0 */  cvt.s.w   $f26, $f26
/* DF7CE8 802412E8 AFA20010 */  sw        $v0, 0x10($sp)
/* DF7CEC 802412EC 8E070018 */  lw        $a3, 0x18($s0)
/* DF7CF0 802412F0 0C00A8ED */  jal       update_lerp
/* DF7CF4 802412F4 2404000B */   addiu    $a0, $zero, 0xb
/* DF7CF8 802412F8 4600008D */  trunc.w.s $f2, $f0
/* DF7CFC 802412FC E7A20014 */  swc1      $f2, 0x14($sp)
/* DF7D00 80241300 0000202D */  daddu     $a0, $zero, $zero
/* DF7D04 80241304 24050007 */  addiu     $a1, $zero, 7
/* DF7D08 80241308 240600FF */  addiu     $a2, $zero, 0xff
/* DF7D0C 8024130C 00C0382D */  daddu     $a3, $a2, $zero
/* DF7D10 80241310 00C0A82D */  daddu     $s5, $a2, $zero
/* DF7D14 80241314 AFB50010 */  sw        $s5, 0x10($sp)
/* DF7D18 80241318 0C04EAA7 */  jal       func_8013AA9C
/* DF7D1C 8024131C AFA00018 */   sw       $zero, 0x18($sp)
/* DF7D20 80241320 27A20038 */  addiu     $v0, $sp, 0x38
/* DF7D24 80241324 AFA20010 */  sw        $v0, 0x10($sp)
/* DF7D28 80241328 8E040004 */  lw        $a0, 4($s0)
/* DF7D2C 8024132C 8E050008 */  lw        $a1, 8($s0)
/* DF7D30 80241330 8E060000 */  lw        $a2, ($s0)
/* DF7D34 80241334 8E07000C */  lw        $a3, 0xc($s0)
/* DF7D38 80241338 0C04BA38 */  jal       func_8012E8E0
/* DF7D3C 8024133C 3C140001 */   lui      $s4, 1
/* DF7D40 80241340 93A20042 */  lbu       $v0, 0x42($sp)
/* DF7D44 80241344 3C013FE0 */  lui       $at, 0x3fe0
/* DF7D48 80241348 4481B800 */  mtc1      $at, $f23
/* DF7D4C 8024134C 4480B000 */  mtc1      $zero, $f22
/* DF7D50 80241350 44820000 */  mtc1      $v0, $f0
/* DF7D54 80241354 00000000 */  nop
/* DF7D58 80241358 46800021 */  cvt.d.w   $f0, $f0
/* DF7D5C 8024135C 46360002 */  mul.d     $f0, $f0, $f22
/* DF7D60 80241360 00000000 */  nop
/* DF7D64 80241364 36941630 */  ori       $s4, $s4, 0x1630
/* DF7D68 80241368 4600A521 */  cvt.d.s   $f20, $f20
/* DF7D6C 8024136C 27B00048 */  addiu     $s0, $sp, 0x48
/* DF7D70 80241370 4600D687 */  neg.s     $f26, $f26
/* DF7D74 80241374 4620A500 */  add.d     $f20, $f20, $f0
/* DF7D78 80241378 4406D000 */  mfc1      $a2, $f26
/* DF7D7C 8024137C 4407C000 */  mfc1      $a3, $f24
/* DF7D80 80241380 4620A520 */  cvt.s.d   $f20, $f20
/* DF7D84 80241384 4405A000 */  mfc1      $a1, $f20
/* DF7D88 80241388 0C019E40 */  jal       guTranslateF
/* DF7D8C 8024138C 0200202D */   daddu    $a0, $s0, $zero
/* DF7D90 80241390 0200202D */  daddu     $a0, $s0, $zero
/* DF7D94 80241394 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* DF7D98 80241398 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* DF7D9C 8024139C 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* DF7DA0 802413A0 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* DF7DA4 802413A4 96450000 */  lhu       $a1, ($s2)
/* DF7DA8 802413A8 8E620000 */  lw        $v0, ($s3)
/* DF7DAC 802413AC 00052980 */  sll       $a1, $a1, 6
/* DF7DB0 802413B0 00B42821 */  addu      $a1, $a1, $s4
/* DF7DB4 802413B4 0C019D40 */  jal       guMtxF2L
/* DF7DB8 802413B8 00452821 */   addu     $a1, $v0, $a1
/* DF7DBC 802413BC 3C03DA38 */  lui       $v1, 0xda38
/* DF7DC0 802413C0 34630002 */  ori       $v1, $v1, 2
/* DF7DC4 802413C4 0000202D */  daddu     $a0, $zero, $zero
/* DF7DC8 802413C8 27A50020 */  addiu     $a1, $sp, 0x20
/* DF7DCC 802413CC 3C060001 */  lui       $a2, 1
/* DF7DD0 802413D0 34C60040 */  ori       $a2, $a2, 0x40
/* DF7DD4 802413D4 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* DF7DD8 802413D8 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* DF7DDC 802413DC 0200382D */  daddu     $a3, $s0, $zero
/* DF7DE0 802413E0 8E220000 */  lw        $v0, ($s1)
/* DF7DE4 802413E4 96480000 */  lhu       $t0, ($s2)
/* DF7DE8 802413E8 0040482D */  daddu     $t1, $v0, $zero
/* DF7DEC 802413EC 24420008 */  addiu     $v0, $v0, 8
/* DF7DF0 802413F0 AE220000 */  sw        $v0, ($s1)
/* DF7DF4 802413F4 3102FFFF */  andi      $v0, $t0, 0xffff
/* DF7DF8 802413F8 00021180 */  sll       $v0, $v0, 6
/* DF7DFC 802413FC 00541021 */  addu      $v0, $v0, $s4
/* DF7E00 80241400 AD230000 */  sw        $v1, ($t1)
/* DF7E04 80241404 8E630000 */  lw        $v1, ($s3)
/* DF7E08 80241408 25080001 */  addiu     $t0, $t0, 1
/* DF7E0C 8024140C 00621821 */  addu      $v1, $v1, $v0
/* DF7E10 80241410 3C028000 */  lui       $v0, 0x8000
/* DF7E14 80241414 00621821 */  addu      $v1, $v1, $v0
/* DF7E18 80241418 AD230004 */  sw        $v1, 4($t1)
/* DF7E1C 8024141C 93A20042 */  lbu       $v0, 0x42($sp)
/* DF7E20 80241420 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF7E24 80241424 93A90040 */  lbu       $t1, 0x40($sp)
/* DF7E28 80241428 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF7E2C 8024142C 44820000 */  mtc1      $v0, $f0
/* DF7E30 80241430 00000000 */  nop
/* DF7E34 80241434 46800021 */  cvt.d.w   $f0, $f0
/* DF7E38 80241438 8FA20038 */  lw        $v0, 0x38($sp)
/* DF7E3C 8024143C 46360002 */  mul.d     $f0, $f0, $f22
/* DF7E40 80241440 00000000 */  nop
/* DF7E44 80241444 A6480000 */  sh        $t0, ($s2)
/* DF7E48 80241448 A7A0002E */  sh        $zero, 0x2e($sp)
/* DF7E4C 8024144C A3B50030 */  sb        $s5, 0x30($sp)
/* DF7E50 80241450 AFA30024 */  sw        $v1, 0x24($sp)
/* DF7E54 80241454 A7A90028 */  sh        $t1, 0x28($sp)
/* DF7E58 80241458 A7AA002A */  sh        $t2, 0x2a($sp)
/* DF7E5C 8024145C AFA20020 */  sw        $v0, 0x20($sp)
/* DF7E60 80241460 46200007 */  neg.d     $f0, $f0
/* DF7E64 80241464 4620008D */  trunc.w.d $f2, $f0
/* DF7E68 80241468 44021000 */  mfc1      $v0, $f2
/* DF7E6C 8024146C 0C04EBDC */  jal       func_8013AF70
/* DF7E70 80241470 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF7E74 80241474 3C04D838 */  lui       $a0, 0xd838
/* DF7E78 80241478 8E220000 */  lw        $v0, ($s1)
/* DF7E7C 8024147C 34840002 */  ori       $a0, $a0, 2
/* DF7E80 80241480 0040182D */  daddu     $v1, $v0, $zero
/* DF7E84 80241484 24420008 */  addiu     $v0, $v0, 8
/* DF7E88 80241488 AE220000 */  sw        $v0, ($s1)
/* DF7E8C 8024148C 24020040 */  addiu     $v0, $zero, 0x40
/* DF7E90 80241490 AC640000 */  sw        $a0, ($v1)
/* DF7E94 80241494 AC620004 */  sw        $v0, 4($v1)
/* DF7E98 80241498 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* DF7E9C 8024149C 8FB5009C */  lw        $s5, 0x9c($sp)
/* DF7EA0 802414A0 8FB40098 */  lw        $s4, 0x98($sp)
/* DF7EA4 802414A4 8FB30094 */  lw        $s3, 0x94($sp)
/* DF7EA8 802414A8 8FB20090 */  lw        $s2, 0x90($sp)
/* DF7EAC 802414AC 8FB1008C */  lw        $s1, 0x8c($sp)
/* DF7EB0 802414B0 8FB00088 */  lw        $s0, 0x88($sp)
/* DF7EB4 802414B4 D7BA00C0 */  ldc1      $f26, 0xc0($sp)
/* DF7EB8 802414B8 D7B800B8 */  ldc1      $f24, 0xb8($sp)
/* DF7EBC 802414BC D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* DF7EC0 802414C0 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* DF7EC4 802414C4 03E00008 */  jr        $ra
/* DF7EC8 802414C8 27BD00C8 */   addiu    $sp, $sp, 0xc8
