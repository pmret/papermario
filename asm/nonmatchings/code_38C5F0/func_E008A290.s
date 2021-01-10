.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008A290
/* 38C880 E008A290 0080402D */  daddu     $t0, $a0, $zero
/* 38C884 E008A294 3C04800B */  lui       $a0, %hi(gCameras)
/* 38C888 E008A298 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 38C88C E008A29C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 38C890 E008A2A0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 38C894 E008A2A4 C5000008 */  lwc1      $f0, 8($t0)
/* 38C898 E008A2A8 C508000C */  lwc1      $f8, 0xc($t0)
/* 38C89C E008A2AC 00031080 */  sll       $v0, $v1, 2
/* 38C8A0 E008A2B0 00431021 */  addu      $v0, $v0, $v1
/* 38C8A4 E008A2B4 00021080 */  sll       $v0, $v0, 2
/* 38C8A8 E008A2B8 00431023 */  subu      $v0, $v0, $v1
/* 38C8AC E008A2BC 000218C0 */  sll       $v1, $v0, 3
/* 38C8B0 E008A2C0 00431021 */  addu      $v0, $v0, $v1
/* 38C8B4 E008A2C4 000210C0 */  sll       $v0, $v0, 3
/* 38C8B8 E008A2C8 00441021 */  addu      $v0, $v0, $a0
/* 38C8BC E008A2CC C4420048 */  lwc1      $f2, 0x48($v0)
/* 38C8C0 E008A2D0 C50A0010 */  lwc1      $f10, 0x10($t0)
/* 38C8C4 E008A2D4 46020001 */  sub.s     $f0, $f0, $f2
/* 38C8C8 E008A2D8 C444004C */  lwc1      $f4, 0x4c($v0)
/* 38C8CC E008A2DC C4460050 */  lwc1      $f6, 0x50($v0)
/* 38C8D0 E008A2E0 4600030D */  trunc.w.s $f12, $f0
/* 38C8D4 E008A2E4 44046000 */  mfc1      $a0, $f12
/* 38C8D8 E008A2E8 00000000 */  nop       
/* 38C8DC E008A2EC 00A4182A */  slt       $v1, $a1, $a0
/* 38C8E0 E008A2F0 10600014 */  beqz      $v1, .LE008A344
/* 38C8E4 E008A2F4 00051023 */   negu     $v0, $a1
/* 38C8E8 E008A2F8 14A00002 */  bnez      $a1, .LE008A304
/* 38C8EC E008A2FC 0085001A */   div      $zero, $a0, $a1
/* 38C8F0 E008A300 0007000D */  break     7
.LE008A304:
/* 38C8F4 E008A304 2401FFFF */   addiu    $at, $zero, -1
/* 38C8F8 E008A308 14A10004 */  bne       $a1, $at, .LE008A31C
/* 38C8FC E008A30C 3C018000 */   lui      $at, 0x8000
/* 38C900 E008A310 14810002 */  bne       $a0, $at, .LE008A31C
/* 38C904 E008A314 00000000 */   nop      
/* 38C908 E008A318 0006000D */  break     6
.LE008A31C:
/* 38C90C E008A31C 00002010 */   mfhi     $a0
/* 38C910 E008A320 44850000 */  mtc1      $a1, $f0
/* 38C914 E008A324 00000000 */  nop       
/* 38C918 E008A328 46800020 */  cvt.s.w   $f0, $f0
/* 38C91C E008A32C 46001001 */  sub.s     $f0, $f2, $f0
/* 38C920 E008A330 44841000 */  mtc1      $a0, $f2
/* 38C924 E008A334 00000000 */  nop       
/* 38C928 E008A338 468010A0 */  cvt.s.w   $f2, $f2
/* 38C92C E008A33C 080228E6 */  j         .LE008A398
/* 38C930 E008A340 46020000 */   add.s    $f0, $f0, $f2
.LE008A344:
/* 38C934 E008A344 0082102A */  slt       $v0, $a0, $v0
/* 38C938 E008A348 10400014 */  beqz      $v0, .LE008A39C
/* 38C93C E008A34C 00042023 */   negu     $a0, $a0
/* 38C940 E008A350 14A00002 */  bnez      $a1, .LE008A35C
/* 38C944 E008A354 0085001A */   div      $zero, $a0, $a1
/* 38C948 E008A358 0007000D */  break     7
.LE008A35C:
/* 38C94C E008A35C 2401FFFF */   addiu    $at, $zero, -1
/* 38C950 E008A360 14A10004 */  bne       $a1, $at, .LE008A374
/* 38C954 E008A364 3C018000 */   lui      $at, 0x8000
/* 38C958 E008A368 14810002 */  bne       $a0, $at, .LE008A374
/* 38C95C E008A36C 00000000 */   nop      
/* 38C960 E008A370 0006000D */  break     6
.LE008A374:
/* 38C964 E008A374 00002010 */   mfhi     $a0
/* 38C968 E008A378 44850000 */  mtc1      $a1, $f0
/* 38C96C E008A37C 00000000 */  nop       
/* 38C970 E008A380 46800020 */  cvt.s.w   $f0, $f0
/* 38C974 E008A384 46001000 */  add.s     $f0, $f2, $f0
/* 38C978 E008A388 44841000 */  mtc1      $a0, $f2
/* 38C97C E008A38C 00000000 */  nop       
/* 38C980 E008A390 468010A0 */  cvt.s.w   $f2, $f2
/* 38C984 E008A394 46020001 */  sub.s     $f0, $f0, $f2
.LE008A398:
/* 38C988 E008A398 E5000008 */  swc1      $f0, 8($t0)
.LE008A39C:
/* 38C98C E008A39C 46044001 */  sub.s     $f0, $f8, $f4
/* 38C990 E008A3A0 4600030D */  trunc.w.s $f12, $f0
/* 38C994 E008A3A4 44036000 */  mfc1      $v1, $f12
/* 38C998 E008A3A8 00000000 */  nop       
/* 38C99C E008A3AC 00C3102A */  slt       $v0, $a2, $v1
/* 38C9A0 E008A3B0 10400014 */  beqz      $v0, .LE008A404
/* 38C9A4 E008A3B4 00061023 */   negu     $v0, $a2
/* 38C9A8 E008A3B8 14C00002 */  bnez      $a2, .LE008A3C4
/* 38C9AC E008A3BC 0066001A */   div      $zero, $v1, $a2
/* 38C9B0 E008A3C0 0007000D */  break     7
.LE008A3C4:
/* 38C9B4 E008A3C4 2401FFFF */   addiu    $at, $zero, -1
/* 38C9B8 E008A3C8 14C10004 */  bne       $a2, $at, .LE008A3DC
/* 38C9BC E008A3CC 3C018000 */   lui      $at, 0x8000
/* 38C9C0 E008A3D0 14610002 */  bne       $v1, $at, .LE008A3DC
/* 38C9C4 E008A3D4 00000000 */   nop      
/* 38C9C8 E008A3D8 0006000D */  break     6
.LE008A3DC:
/* 38C9CC E008A3DC 00001810 */   mfhi     $v1
/* 38C9D0 E008A3E0 44860000 */  mtc1      $a2, $f0
/* 38C9D4 E008A3E4 00000000 */  nop       
/* 38C9D8 E008A3E8 46800020 */  cvt.s.w   $f0, $f0
/* 38C9DC E008A3EC 46002001 */  sub.s     $f0, $f4, $f0
/* 38C9E0 E008A3F0 44831000 */  mtc1      $v1, $f2
/* 38C9E4 E008A3F4 00000000 */  nop       
/* 38C9E8 E008A3F8 468010A0 */  cvt.s.w   $f2, $f2
/* 38C9EC E008A3FC 0802291B */  j         .LE008A46C
/* 38C9F0 E008A400 46020000 */   add.s    $f0, $f0, $f2
.LE008A404:
/* 38C9F4 E008A404 0062102A */  slt       $v0, $v1, $v0
/* 38C9F8 E008A408 10400019 */  beqz      $v0, .LE008A470
/* 38C9FC E008A40C 28E20064 */   slti     $v0, $a3, 0x64
/* 38CA00 E008A410 10400004 */  beqz      $v0, .LE008A424
/* 38CA04 E008A414 00031823 */   negu     $v1, $v1
/* 38CA08 E008A418 AD000018 */  sw        $zero, 0x18($t0)
/* 38CA0C E008A41C 0802291C */  j         .LE008A470
/* 38CA10 E008A420 AD000028 */   sw       $zero, 0x28($t0)
.LE008A424:
/* 38CA14 E008A424 14C00002 */  bnez      $a2, .LE008A430
/* 38CA18 E008A428 0066001A */   div      $zero, $v1, $a2
/* 38CA1C E008A42C 0007000D */  break     7
.LE008A430:
/* 38CA20 E008A430 2401FFFF */   addiu    $at, $zero, -1
/* 38CA24 E008A434 14C10004 */  bne       $a2, $at, .LE008A448
/* 38CA28 E008A438 3C018000 */   lui      $at, 0x8000
/* 38CA2C E008A43C 14610002 */  bne       $v1, $at, .LE008A448
/* 38CA30 E008A440 00000000 */   nop      
/* 38CA34 E008A444 0006000D */  break     6
.LE008A448:
/* 38CA38 E008A448 00001810 */   mfhi     $v1
/* 38CA3C E008A44C 44860000 */  mtc1      $a2, $f0
/* 38CA40 E008A450 00000000 */  nop       
/* 38CA44 E008A454 46800020 */  cvt.s.w   $f0, $f0
/* 38CA48 E008A458 46002000 */  add.s     $f0, $f4, $f0
/* 38CA4C E008A45C 44831000 */  mtc1      $v1, $f2
/* 38CA50 E008A460 00000000 */  nop       
/* 38CA54 E008A464 468010A0 */  cvt.s.w   $f2, $f2
/* 38CA58 E008A468 46020001 */  sub.s     $f0, $f0, $f2
.LE008A46C:
/* 38CA5C E008A46C E500000C */  swc1      $f0, 0xc($t0)
.LE008A470:
/* 38CA60 E008A470 46065001 */  sub.s     $f0, $f10, $f6
/* 38CA64 E008A474 4600030D */  trunc.w.s $f12, $f0
/* 38CA68 E008A478 44036000 */  mfc1      $v1, $f12
/* 38CA6C E008A47C 00000000 */  nop       
/* 38CA70 E008A480 00A3102A */  slt       $v0, $a1, $v1
/* 38CA74 E008A484 10400015 */  beqz      $v0, .LE008A4DC
/* 38CA78 E008A488 00051023 */   negu     $v0, $a1
/* 38CA7C E008A48C 14A00002 */  bnez      $a1, .LE008A498
/* 38CA80 E008A490 0065001A */   div      $zero, $v1, $a1
/* 38CA84 E008A494 0007000D */  break     7
.LE008A498:
/* 38CA88 E008A498 2401FFFF */   addiu    $at, $zero, -1
/* 38CA8C E008A49C 14A10004 */  bne       $a1, $at, .LE008A4B0
/* 38CA90 E008A4A0 3C018000 */   lui      $at, 0x8000
/* 38CA94 E008A4A4 14610002 */  bne       $v1, $at, .LE008A4B0
/* 38CA98 E008A4A8 00000000 */   nop      
/* 38CA9C E008A4AC 0006000D */  break     6
.LE008A4B0:
/* 38CAA0 E008A4B0 00001810 */   mfhi     $v1
/* 38CAA4 E008A4B4 44850000 */  mtc1      $a1, $f0
/* 38CAA8 E008A4B8 00000000 */  nop       
/* 38CAAC E008A4BC 46800020 */  cvt.s.w   $f0, $f0
/* 38CAB0 E008A4C0 46003001 */  sub.s     $f0, $f6, $f0
/* 38CAB4 E008A4C4 44831000 */  mtc1      $v1, $f2
/* 38CAB8 E008A4C8 00000000 */  nop       
/* 38CABC E008A4CC 468010A0 */  cvt.s.w   $f2, $f2
/* 38CAC0 E008A4D0 46020000 */  add.s     $f0, $f0, $f2
/* 38CAC4 E008A4D4 03E00008 */  jr        $ra
/* 38CAC8 E008A4D8 E5000010 */   swc1     $f0, 0x10($t0)
.LE008A4DC:
/* 38CACC E008A4DC 0062102A */  slt       $v0, $v1, $v0
/* 38CAD0 E008A4E0 10400014 */  beqz      $v0, .LE008A534
/* 38CAD4 E008A4E4 00031823 */   negu     $v1, $v1
/* 38CAD8 E008A4E8 14A00002 */  bnez      $a1, .LE008A4F4
/* 38CADC E008A4EC 0065001A */   div      $zero, $v1, $a1
/* 38CAE0 E008A4F0 0007000D */  break     7
.LE008A4F4:
/* 38CAE4 E008A4F4 2401FFFF */   addiu    $at, $zero, -1
/* 38CAE8 E008A4F8 14A10004 */  bne       $a1, $at, .LE008A50C
/* 38CAEC E008A4FC 3C018000 */   lui      $at, 0x8000
/* 38CAF0 E008A500 14610002 */  bne       $v1, $at, .LE008A50C
/* 38CAF4 E008A504 00000000 */   nop      
/* 38CAF8 E008A508 0006000D */  break     6
.LE008A50C:
/* 38CAFC E008A50C 00001810 */   mfhi     $v1
/* 38CB00 E008A510 44850000 */  mtc1      $a1, $f0
/* 38CB04 E008A514 00000000 */  nop       
/* 38CB08 E008A518 46800020 */  cvt.s.w   $f0, $f0
/* 38CB0C E008A51C 46003000 */  add.s     $f0, $f6, $f0
/* 38CB10 E008A520 44831000 */  mtc1      $v1, $f2
/* 38CB14 E008A524 00000000 */  nop       
/* 38CB18 E008A528 468010A0 */  cvt.s.w   $f2, $f2
/* 38CB1C E008A52C 46020001 */  sub.s     $f0, $f0, $f2
/* 38CB20 E008A530 E5000010 */  swc1      $f0, 0x10($t0)
.LE008A534:
/* 38CB24 E008A534 03E00008 */  jr        $ra
/* 38CB28 E008A538 00000000 */   nop      
