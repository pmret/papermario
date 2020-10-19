.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024134C
/* A0824C 8024134C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* A08250 80241350 AFB3004C */  sw        $s3, 0x4c($sp)
/* A08254 80241354 0080982D */  daddu     $s3, $a0, $zero
/* A08258 80241358 AFBF0054 */  sw        $ra, 0x54($sp)
/* A0825C 8024135C AFB40050 */  sw        $s4, 0x50($sp)
/* A08260 80241360 AFB20048 */  sw        $s2, 0x48($sp)
/* A08264 80241364 AFB10044 */  sw        $s1, 0x44($sp)
/* A08268 80241368 AFB00040 */  sw        $s0, 0x40($sp)
/* A0826C 8024136C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* A08270 80241370 F7B80068 */  sdc1      $f24, 0x68($sp)
/* A08274 80241374 F7B60060 */  sdc1      $f22, 0x60($sp)
/* A08278 80241378 F7B40058 */  sdc1      $f20, 0x58($sp)
/* A0827C 8024137C 8E710148 */  lw        $s1, 0x148($s3)
/* A08280 80241380 00A0902D */  daddu     $s2, $a1, $zero
/* A08284 80241384 86240008 */  lh        $a0, 8($s1)
/* A08288 80241388 0C00EABB */  jal       get_npc_unsafe
/* A0828C 8024138C 00C0A02D */   daddu    $s4, $a2, $zero
/* A08290 80241390 0040802D */  daddu     $s0, $v0, $zero
/* A08294 80241394 C6200078 */  lwc1      $f0, 0x78($s1)
/* A08298 80241398 46800020 */  cvt.s.w   $f0, $f0
/* A0829C 8024139C 46000021 */  cvt.d.s   $f0, $f0
/* A082A0 802413A0 3C014059 */  lui       $at, 0x4059
/* A082A4 802413A4 44811800 */  mtc1      $at, $f3
/* A082A8 802413A8 44801000 */  mtc1      $zero, $f2
/* A082AC 802413AC 8602008E */  lh        $v0, 0x8e($s0)
/* A082B0 802413B0 9603008E */  lhu       $v1, 0x8e($s0)
/* A082B4 802413B4 46220003 */  div.d     $f0, $f0, $f2
/* A082B8 802413B8 46200620 */  cvt.s.d   $f24, $f0
/* A082BC 802413BC C6200088 */  lwc1      $f0, 0x88($s1)
/* A082C0 802413C0 46800020 */  cvt.s.w   $f0, $f0
/* A082C4 802413C4 46000021 */  cvt.d.s   $f0, $f0
/* A082C8 802413C8 46220003 */  div.d     $f0, $f0, $f2
/* A082CC 802413CC 46200020 */  cvt.s.d   $f0, $f0
/* A082D0 802413D0 18400003 */  blez      $v0, .L802413E0
/* A082D4 802413D4 4600C680 */   add.s    $f26, $f24, $f0
/* A082D8 802413D8 2462FFFF */  addiu     $v0, $v1, -1
/* A082DC 802413DC A602008E */  sh        $v0, 0x8e($s0)
.L802413E0:
/* A082E0 802413E0 8E220070 */  lw        $v0, 0x70($s1)
/* A082E4 802413E4 18400034 */  blez      $v0, .L802414B8
/* A082E8 802413E8 00000000 */   nop      
/* A082EC 802413EC C62C0074 */  lwc1      $f12, 0x74($s1)
/* A082F0 802413F0 46806320 */  cvt.s.w   $f12, $f12
/* A082F4 802413F4 44820000 */  mtc1      $v0, $f0
/* A082F8 802413F8 00000000 */  nop       
/* A082FC 802413FC 46800020 */  cvt.s.w   $f0, $f0
/* A08300 80241400 46000021 */  cvt.d.s   $f0, $f0
/* A08304 80241404 46220003 */  div.d     $f0, $f0, $f2
/* A08308 80241408 0C00A8BB */  jal       sin_deg
/* A0830C 8024140C 462005A0 */   cvt.s.d  $f22, $f0
/* A08310 80241410 8E020000 */  lw        $v0, ($s0)
/* A08314 80241414 30420008 */  andi      $v0, $v0, 8
/* A08318 80241418 10400003 */  beqz      $v0, .L80241428
/* A0831C 8024141C 46000506 */   mov.s    $f20, $f0
/* A08320 80241420 0809051A */  j         .L80241468
/* A08324 80241424 0000102D */   daddu    $v0, $zero, $zero
.L80241428:
/* A08328 80241428 27A50028 */  addiu     $a1, $sp, 0x28
/* A0832C 8024142C 27A6002C */  addiu     $a2, $sp, 0x2c
/* A08330 80241430 C6000038 */  lwc1      $f0, 0x38($s0)
/* A08334 80241434 C602003C */  lwc1      $f2, 0x3c($s0)
/* A08338 80241438 C6040040 */  lwc1      $f4, 0x40($s0)
/* A0833C 8024143C 3C01447A */  lui       $at, 0x447a
/* A08340 80241440 44813000 */  mtc1      $at, $f6
/* A08344 80241444 27A20034 */  addiu     $v0, $sp, 0x34
/* A08348 80241448 E7A00028 */  swc1      $f0, 0x28($sp)
/* A0834C 8024144C E7A2002C */  swc1      $f2, 0x2c($sp)
/* A08350 80241450 E7A40030 */  swc1      $f4, 0x30($sp)
/* A08354 80241454 E7A60034 */  swc1      $f6, 0x34($sp)
/* A08358 80241458 AFA20010 */  sw        $v0, 0x10($sp)
/* A0835C 8024145C 8E040080 */  lw        $a0, 0x80($s0)
/* A08360 80241460 0C0372DF */  jal       func_800DCB7C
/* A08364 80241464 27A70030 */   addiu    $a3, $sp, 0x30
.L80241468:
/* A08368 80241468 10400007 */  beqz      $v0, .L80241488
/* A0836C 8024146C 00000000 */   nop      
/* A08370 80241470 4616A082 */  mul.s     $f2, $f20, $f22
/* A08374 80241474 00000000 */  nop       
/* A08378 80241478 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A0837C 8024147C 46180000 */  add.s     $f0, $f0, $f24
/* A08380 80241480 08090525 */  j         .L80241494
/* A08384 80241484 46020000 */   add.s    $f0, $f0, $f2
.L80241488:
/* A08388 80241488 4616A002 */  mul.s     $f0, $f20, $f22
/* A0838C 8024148C 00000000 */  nop       
/* A08390 80241490 4600D000 */  add.s     $f0, $f26, $f0
.L80241494:
/* A08394 80241494 E600003C */  swc1      $f0, 0x3c($s0)
/* A08398 80241498 8E220074 */  lw        $v0, 0x74($s1)
/* A0839C 8024149C 2442000A */  addiu     $v0, $v0, 0xa
/* A083A0 802414A0 44826000 */  mtc1      $v0, $f12
/* A083A4 802414A4 00000000 */  nop       
/* A083A8 802414A8 0C00A6C9 */  jal       clamp_angle
/* A083AC 802414AC 46806320 */   cvt.s.w  $f12, $f12
/* A083B0 802414B0 4600020D */  trunc.w.s $f8, $f0
/* A083B4 802414B4 E6280074 */  swc1      $f8, 0x74($s1)
.L802414B8:
/* A083B8 802414B8 8E220090 */  lw        $v0, 0x90($s1)
/* A083BC 802414BC 1C400040 */  bgtz      $v0, .L802415C0
/* A083C0 802414C0 2442FFFF */   addiu    $v0, $v0, -1
/* A083C4 802414C4 860200A8 */  lh        $v0, 0xa8($s0)
/* A083C8 802414C8 C600003C */  lwc1      $f0, 0x3c($s0)
/* A083CC 802414CC 44821000 */  mtc1      $v0, $f2
/* A083D0 802414D0 00000000 */  nop       
/* A083D4 802414D4 468010A0 */  cvt.s.w   $f2, $f2
/* A083D8 802414D8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A083DC 802414DC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A083E0 802414E0 46020000 */  add.s     $f0, $f0, $f2
/* A083E4 802414E4 3C014024 */  lui       $at, 0x4024
/* A083E8 802414E8 44812800 */  mtc1      $at, $f5
/* A083EC 802414EC 44802000 */  mtc1      $zero, $f4
/* A083F0 802414F0 C442002C */  lwc1      $f2, 0x2c($v0)
/* A083F4 802414F4 46000021 */  cvt.d.s   $f0, $f0
/* A083F8 802414F8 46240000 */  add.d     $f0, $f0, $f4
/* A083FC 802414FC 460010A1 */  cvt.d.s   $f2, $f2
/* A08400 80241500 4620103C */  c.lt.d    $f2, $f0
/* A08404 80241504 00000000 */  nop       
/* A08408 80241508 4500002E */  bc1f      .L802415C4
/* A0840C 8024150C 0280202D */   daddu    $a0, $s4, $zero
/* A08410 80241510 24020001 */  addiu     $v0, $zero, 1
/* A08414 80241514 AFA20010 */  sw        $v0, 0x10($sp)
/* A08418 80241518 8E460024 */  lw        $a2, 0x24($s2)
/* A0841C 8024151C 8E470028 */  lw        $a3, 0x28($s2)
/* A08420 80241520 0C01242D */  jal       func_800490B4
/* A08424 80241524 0220282D */   daddu    $a1, $s1, $zero
/* A08428 80241528 10400026 */  beqz      $v0, .L802415C4
/* A0842C 8024152C 0000202D */   daddu    $a0, $zero, $zero
/* A08430 80241530 0200282D */  daddu     $a1, $s0, $zero
/* A08434 80241534 0000302D */  daddu     $a2, $zero, $zero
/* A08438 80241538 2412000C */  addiu     $s2, $zero, 0xc
/* A0843C 8024153C 860300A8 */  lh        $v1, 0xa8($s0)
/* A08440 80241540 3C013F80 */  lui       $at, 0x3f80
/* A08444 80241544 44810000 */  mtc1      $at, $f0
/* A08448 80241548 3C014000 */  lui       $at, 0x4000
/* A0844C 8024154C 44811000 */  mtc1      $at, $f2
/* A08450 80241550 3C01C1A0 */  lui       $at, 0xc1a0
/* A08454 80241554 44812000 */  mtc1      $at, $f4
/* A08458 80241558 44834000 */  mtc1      $v1, $f8
/* A0845C 8024155C 00000000 */  nop       
/* A08460 80241560 46804220 */  cvt.s.w   $f8, $f8
/* A08464 80241564 44074000 */  mfc1      $a3, $f8
/* A08468 80241568 27A20038 */  addiu     $v0, $sp, 0x38
/* A0846C 8024156C AFB2001C */  sw        $s2, 0x1c($sp)
/* A08470 80241570 AFA20020 */  sw        $v0, 0x20($sp)
/* A08474 80241574 E7A00010 */  swc1      $f0, 0x10($sp)
/* A08478 80241578 E7A20014 */  swc1      $f2, 0x14($sp)
/* A0847C 8024157C 0C01BFA4 */  jal       fx_emote
/* A08480 80241580 E7A40018 */   swc1     $f4, 0x18($sp)
/* A08484 80241584 0200202D */  daddu     $a0, $s0, $zero
/* A08488 80241588 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A0848C 8024158C C480003C */  lwc1      $f0, 0x3c($a0)
/* A08490 80241590 3C060020 */  lui       $a2, 0x20
/* A08494 80241594 0C012530 */  jal       func_800494C0
/* A08498 80241598 E4800064 */   swc1     $f0, 0x64($a0)
/* A0849C 8024159C 8E220018 */  lw        $v0, 0x18($s1)
/* A084A0 802415A0 9442002A */  lhu       $v0, 0x2a($v0)
/* A084A4 802415A4 30420001 */  andi      $v0, $v0, 1
/* A084A8 802415A8 10400003 */  beqz      $v0, .L802415B8
/* A084AC 802415AC 2402000A */   addiu    $v0, $zero, 0xa
/* A084B0 802415B0 08090598 */  j         .L80241660
/* A084B4 802415B4 AE620070 */   sw       $v0, 0x70($s3)
.L802415B8:
/* A084B8 802415B8 08090598 */  j         .L80241660
/* A084BC 802415BC AE720070 */   sw       $s2, 0x70($s3)
.L802415C0:
/* A084C0 802415C0 AE220090 */  sw        $v0, 0x90($s1)
.L802415C4:
/* A084C4 802415C4 8602008C */  lh        $v0, 0x8c($s0)
/* A084C8 802415C8 14400025 */  bnez      $v0, .L80241660
/* A084CC 802415CC 00000000 */   nop      
/* A084D0 802415D0 8602008E */  lh        $v0, 0x8e($s0)
/* A084D4 802415D4 1C400022 */  bgtz      $v0, .L80241660
/* A084D8 802415D8 00000000 */   nop      
/* A084DC 802415DC 8E620074 */  lw        $v0, 0x74($s3)
/* A084E0 802415E0 2442FFFF */  addiu     $v0, $v0, -1
/* A084E4 802415E4 1840001D */  blez      $v0, .L8024165C
/* A084E8 802415E8 AE620074 */   sw       $v0, 0x74($s3)
/* A084EC 802415EC 8E220018 */  lw        $v0, 0x18($s1)
/* A084F0 802415F0 9442002A */  lhu       $v0, 0x2a($v0)
/* A084F4 802415F4 30420010 */  andi      $v0, $v0, 0x10
/* A084F8 802415F8 14400007 */  bnez      $v0, .L80241618
/* A084FC 802415FC 00000000 */   nop      
/* A08500 80241600 C600000C */  lwc1      $f0, 0xc($s0)
/* A08504 80241604 3C014334 */  lui       $at, 0x4334
/* A08508 80241608 44816000 */  mtc1      $at, $f12
/* A0850C 8024160C 0C00A6C9 */  jal       clamp_angle
/* A08510 80241610 460C0300 */   add.s    $f12, $f0, $f12
/* A08514 80241614 E600000C */  swc1      $f0, 0xc($s0)
.L80241618:
/* A08518 80241618 0C00A67F */  jal       rand_int
/* A0851C 8024161C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* A08520 80241620 3C032E8B */  lui       $v1, 0x2e8b
/* A08524 80241624 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* A08528 80241628 00430018 */  mult      $v0, $v1
/* A0852C 8024162C 00021FC3 */  sra       $v1, $v0, 0x1f
/* A08530 80241630 00004010 */  mfhi      $t0
/* A08534 80241634 00082043 */  sra       $a0, $t0, 1
/* A08538 80241638 00832023 */  subu      $a0, $a0, $v1
/* A0853C 8024163C 00041840 */  sll       $v1, $a0, 1
/* A08540 80241640 00641821 */  addu      $v1, $v1, $a0
/* A08544 80241644 00031880 */  sll       $v1, $v1, 2
/* A08548 80241648 00641823 */  subu      $v1, $v1, $a0
/* A0854C 8024164C 00431023 */  subu      $v0, $v0, $v1
/* A08550 80241650 24420005 */  addiu     $v0, $v0, 5
/* A08554 80241654 08090598 */  j         .L80241660
/* A08558 80241658 A602008E */   sh       $v0, 0x8e($s0)
.L8024165C:
/* A0855C 8024165C AE600070 */  sw        $zero, 0x70($s3)
.L80241660:
/* A08560 80241660 8FBF0054 */  lw        $ra, 0x54($sp)
/* A08564 80241664 8FB40050 */  lw        $s4, 0x50($sp)
/* A08568 80241668 8FB3004C */  lw        $s3, 0x4c($sp)
/* A0856C 8024166C 8FB20048 */  lw        $s2, 0x48($sp)
/* A08570 80241670 8FB10044 */  lw        $s1, 0x44($sp)
/* A08574 80241674 8FB00040 */  lw        $s0, 0x40($sp)
/* A08578 80241678 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* A0857C 8024167C D7B80068 */  ldc1      $f24, 0x68($sp)
/* A08580 80241680 D7B60060 */  ldc1      $f22, 0x60($sp)
/* A08584 80241684 D7B40058 */  ldc1      $f20, 0x58($sp)
/* A08588 80241688 03E00008 */  jr        $ra
/* A0858C 8024168C 27BD0078 */   addiu    $sp, $sp, 0x78
