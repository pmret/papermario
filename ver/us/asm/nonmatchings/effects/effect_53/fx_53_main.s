.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_53_main
/* 36D208 E006A1E8 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 36D20C E006A1EC F7B60058 */  sdc1      $f22, 0x58($sp)
/* 36D210 E006A1F0 4485B000 */  mtc1      $a1, $f22
/* 36D214 E006A1F4 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 36D218 E006A1F8 4486C000 */  mtc1      $a2, $f24
/* 36D21C E006A1FC AFB00028 */  sw        $s0, 0x28($sp)
/* 36D220 E006A200 0080802D */  daddu     $s0, $a0, $zero
/* 36D224 E006A204 AFB20030 */  sw        $s2, 0x30($sp)
/* 36D228 E006A208 24120011 */  addiu     $s2, $zero, 0x11
/* 36D22C E006A20C F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 36D230 E006A210 4487D000 */  mtc1      $a3, $f26
/* 36D234 E006A214 27A40010 */  addiu     $a0, $sp, 0x10
/* 36D238 E006A218 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 36D23C E006A21C C7B40080 */  lwc1      $f20, 0x80($sp)
/* 36D240 E006A220 2A020002 */  slti      $v0, $s0, 2
/* 36D244 E006A224 AFBF0048 */  sw        $ra, 0x48($sp)
/* 36D248 E006A228 AFB70044 */  sw        $s7, 0x44($sp)
/* 36D24C E006A22C AFB60040 */  sw        $s6, 0x40($sp)
/* 36D250 E006A230 AFB5003C */  sw        $s5, 0x3c($sp)
/* 36D254 E006A234 AFB40038 */  sw        $s4, 0x38($sp)
/* 36D258 E006A238 AFB30034 */  sw        $s3, 0x34($sp)
/* 36D25C E006A23C 10400002 */  beqz      $v0, .LE006A248
/* 36D260 E006A240 AFB1002C */   sw       $s1, 0x2c($sp)
/* 36D264 E006A244 24120009 */  addiu     $s2, $zero, 9
.LE006A248:
/* 36D268 E006A248 3C02E007 */  lui       $v0, %hi(func_E006A45C)
/* 36D26C E006A24C 2442A45C */  addiu     $v0, $v0, %lo(func_E006A45C)
/* 36D270 E006A250 AFA20018 */  sw        $v0, 0x18($sp)
/* 36D274 E006A254 3C02E007 */  lui       $v0, %hi(func_E006A580)
/* 36D278 E006A258 2442A580 */  addiu     $v0, $v0, %lo(func_E006A580)
/* 36D27C E006A25C AFA2001C */  sw        $v0, 0x1c($sp)
/* 36D280 E006A260 3C02E007 */  lui       $v0, %hi(func_E006A814)
/* 36D284 E006A264 2442A814 */  addiu     $v0, $v0, %lo(func_E006A814)
/* 36D288 E006A268 AFA20020 */  sw        $v0, 0x20($sp)
/* 36D28C E006A26C 24020035 */  addiu     $v0, $zero, 0x35
/* 36D290 E006A270 AFA00010 */  sw        $zero, 0x10($sp)
/* 36D294 E006A274 AFA00024 */  sw        $zero, 0x24($sp)
/* 36D298 E006A278 0C080124 */  jal       shim_create_effect_instance
/* 36D29C E006A27C AFA20014 */   sw       $v0, 0x14($sp)
/* 36D2A0 E006A280 001220C0 */  sll       $a0, $s2, 3
/* 36D2A4 E006A284 00922021 */  addu      $a0, $a0, $s2
/* 36D2A8 E006A288 00042080 */  sll       $a0, $a0, 2
/* 36D2AC E006A28C 00922021 */  addu      $a0, $a0, $s2
/* 36D2B0 E006A290 00042080 */  sll       $a0, $a0, 2
/* 36D2B4 E006A294 0040B02D */  daddu     $s6, $v0, $zero
/* 36D2B8 E006A298 0C08012C */  jal       shim_general_heap_malloc
/* 36D2BC E006A29C AED20008 */   sw       $s2, 8($s6)
/* 36D2C0 E006A2A0 0040882D */  daddu     $s1, $v0, $zero
/* 36D2C4 E006A2A4 16200003 */  bnez      $s1, .LE006A2B4
/* 36D2C8 E006A2A8 AED1000C */   sw       $s1, 0xc($s6)
.LE006A2AC:
/* 36D2CC E006A2AC 0801A8AB */  j         .LE006A2AC
/* 36D2D0 E006A2B0 00000000 */   nop
.LE006A2B4:
/* 36D2D4 E006A2B4 24020064 */  addiu     $v0, $zero, 0x64
/* 36D2D8 E006A2B8 AE220028 */  sw        $v0, 0x28($s1)
/* 36D2DC E006A2BC 2A020002 */  slti      $v0, $s0, 2
/* 36D2E0 E006A2C0 AE300000 */  sw        $s0, ($s1)
/* 36D2E4 E006A2C4 AE20002C */  sw        $zero, 0x2c($s1)
/* 36D2E8 E006A2C8 E6360010 */  swc1      $f22, 0x10($s1)
/* 36D2EC E006A2CC E6380014 */  swc1      $f24, 0x14($s1)
/* 36D2F0 E006A2D0 E63A0018 */  swc1      $f26, 0x18($s1)
/* 36D2F4 E006A2D4 E6340020 */  swc1      $f20, 0x20($s1)
/* 36D2F8 E006A2D8 10400042 */  beqz      $v0, .LE006A3E4
/* 36D2FC E006A2DC E634001C */   swc1     $f20, 0x1c($s1)
/* 36D300 E006A2E0 06000040 */  bltz      $s0, .LE006A3E4
/* 36D304 E006A2E4 24100001 */   addiu    $s0, $zero, 1
/* 36D308 E006A2E8 8EC20008 */  lw        $v0, 8($s6)
/* 36D30C E006A2EC 0202102A */  slt       $v0, $s0, $v0
/* 36D310 E006A2F0 10400049 */  beqz      $v0, .LE006A418
/* 36D314 E006A2F4 26310094 */   addiu    $s1, $s1, 0x94
/* 36D318 E006A2F8 2655FFFF */  addiu     $s5, $s2, -1
/* 36D31C E006A2FC 24170032 */  addiu     $s7, $zero, 0x32
/* 36D320 E006A300 2632006C */  addiu     $s2, $s1, 0x6c
/* 36D324 E006A304 0000A02D */  daddu     $s4, $zero, $zero
/* 36D328 E006A308 0280982D */  daddu     $s3, $s4, $zero
/* 36D32C E006A30C 3C0141C8 */  lui       $at, 0x41c8
/* 36D330 E006A310 4481B000 */  mtc1      $at, $f22
/* 36D334 E006A314 3C014004 */  lui       $at, 0x4004
/* 36D338 E006A318 4481A800 */  mtc1      $at, $f21
/* 36D33C E006A31C 4480A000 */  mtc1      $zero, $f20
.LE006A320:
/* 36D340 E006A320 16A00002 */  bnez      $s5, .LE006A32C
/* 36D344 E006A324 0275001A */   div      $zero, $s3, $s5
/* 36D348 E006A328 0007000D */  break     7
.LE006A32C:
/* 36D34C E006A32C 2401FFFF */   addiu    $at, $zero, -1
/* 36D350 E006A330 16A10004 */  bne       $s5, $at, .LE006A344
/* 36D354 E006A334 3C018000 */   lui      $at, 0x8000
/* 36D358 E006A338 16610002 */  bne       $s3, $at, .LE006A344
/* 36D35C E006A33C 00000000 */   nop
/* 36D360 E006A340 0006000D */  break     6
.LE006A344:
/* 36D364 E006A344 00001812 */   mflo     $v1
/* 36D368 E006A348 00000000 */  nop
/* 36D36C E006A34C 16A00002 */  bnez      $s5, .LE006A358
/* 36D370 E006A350 0295001A */   div      $zero, $s4, $s5
/* 36D374 E006A354 0007000D */  break     7
.LE006A358:
/* 36D378 E006A358 2401FFFF */   addiu    $at, $zero, -1
/* 36D37C E006A35C 16A10004 */  bne       $s5, $at, .LE006A370
/* 36D380 E006A360 3C018000 */   lui      $at, 0x8000
/* 36D384 E006A364 16810002 */  bne       $s4, $at, .LE006A370
/* 36D388 E006A368 00000000 */   nop
/* 36D38C E006A36C 0006000D */  break     6
.LE006A370:
/* 36D390 E006A370 00003012 */   mflo     $a2
/* 36D394 E006A374 0220202D */  daddu     $a0, $s1, $zero
/* 36D398 E006A378 0200282D */  daddu     $a1, $s0, $zero
/* 36D39C E006A37C 26940014 */  addiu     $s4, $s4, 0x14
/* 36D3A0 E006A380 2673001E */  addiu     $s3, $s3, 0x1e
/* 36D3A4 E006A384 26100001 */  addiu     $s0, $s0, 1
/* 36D3A8 E006A388 26310094 */  addiu     $s1, $s1, 0x94
/* 36D3AC E006A38C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 36D3B0 E006A390 44831000 */  mtc1      $v1, $f2
/* 36D3B4 E006A394 00000000 */  nop
/* 36D3B8 E006A398 468010A0 */  cvt.s.w   $f2, $f2
/* 36D3BC E006A39C 02E63023 */  subu      $a2, $s7, $a2
/* 36D3C0 E006A3A0 44860000 */  mtc1      $a2, $f0
/* 36D3C4 E006A3A4 00000000 */  nop
/* 36D3C8 E006A3A8 46800020 */  cvt.s.w   $f0, $f0
/* 36D3CC E006A3AC 4600B003 */  div.s     $f0, $f22, $f0
/* 36D3D0 E006A3B0 46000021 */  cvt.d.s   $f0, $f0
/* 36D3D4 E006A3B4 46340000 */  add.d     $f0, $f0, $f20
/* 36D3D8 E006A3B8 E642FFFC */  swc1      $f2, -4($s2)
/* 36D3DC E006A3BC AE460010 */  sw        $a2, 0x10($s2)
/* 36D3E0 E006A3C0 46200020 */  cvt.s.d   $f0, $f0
/* 36D3E4 E006A3C4 0C01A800 */  jal       func_E006A000
/* 36D3E8 E006A3C8 E6400000 */   swc1     $f0, ($s2)
/* 36D3EC E006A3CC 8EC20008 */  lw        $v0, 8($s6)
/* 36D3F0 E006A3D0 0202102A */  slt       $v0, $s0, $v0
/* 36D3F4 E006A3D4 1440FFD2 */  bnez      $v0, .LE006A320
/* 36D3F8 E006A3D8 26520094 */   addiu    $s2, $s2, 0x94
/* 36D3FC E006A3DC 0801A906 */  j         .LE006A418
/* 36D400 E006A3E0 00000000 */   nop
.LE006A3E4:
/* 36D404 E006A3E4 8EC20008 */  lw        $v0, 8($s6)
/* 36D408 E006A3E8 24100001 */  addiu     $s0, $zero, 1
/* 36D40C E006A3EC 0202102A */  slt       $v0, $s0, $v0
/* 36D410 E006A3F0 10400009 */  beqz      $v0, .LE006A418
/* 36D414 E006A3F4 26310094 */   addiu    $s1, $s1, 0x94
.LE006A3F8:
/* 36D418 E006A3F8 0220202D */  daddu     $a0, $s1, $zero
/* 36D41C E006A3FC 0C01A82F */  jal       func_E006A0BC
/* 36D420 E006A400 0200282D */   daddu    $a1, $s0, $zero
/* 36D424 E006A404 26100001 */  addiu     $s0, $s0, 1
/* 36D428 E006A408 8EC20008 */  lw        $v0, 8($s6)
/* 36D42C E006A40C 0202102A */  slt       $v0, $s0, $v0
/* 36D430 E006A410 1440FFF9 */  bnez      $v0, .LE006A3F8
/* 36D434 E006A414 26310094 */   addiu    $s1, $s1, 0x94
.LE006A418:
/* 36D438 E006A418 8FA20084 */  lw        $v0, 0x84($sp)
/* 36D43C E006A41C AC560000 */  sw        $s6, ($v0)
/* 36D440 E006A420 8FBF0048 */  lw        $ra, 0x48($sp)
/* 36D444 E006A424 8FB70044 */  lw        $s7, 0x44($sp)
/* 36D448 E006A428 8FB60040 */  lw        $s6, 0x40($sp)
/* 36D44C E006A42C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 36D450 E006A430 8FB40038 */  lw        $s4, 0x38($sp)
/* 36D454 E006A434 8FB30034 */  lw        $s3, 0x34($sp)
/* 36D458 E006A438 8FB20030 */  lw        $s2, 0x30($sp)
/* 36D45C E006A43C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 36D460 E006A440 8FB00028 */  lw        $s0, 0x28($sp)
/* 36D464 E006A444 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 36D468 E006A448 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 36D46C E006A44C D7B60058 */  ldc1      $f22, 0x58($sp)
/* 36D470 E006A450 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 36D474 E006A454 03E00008 */  jr        $ra
/* 36D478 E006A458 27BD0070 */   addiu    $sp, $sp, 0x70
