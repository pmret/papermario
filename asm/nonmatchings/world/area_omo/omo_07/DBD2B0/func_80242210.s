.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242210
/* DBF4C0 80242210 27BDFF88 */  addiu     $sp, $sp, -0x78
/* DBF4C4 80242214 AFB3004C */  sw        $s3, 0x4c($sp)
/* DBF4C8 80242218 0080982D */  daddu     $s3, $a0, $zero
/* DBF4CC 8024221C AFBF0054 */  sw        $ra, 0x54($sp)
/* DBF4D0 80242220 AFB40050 */  sw        $s4, 0x50($sp)
/* DBF4D4 80242224 AFB20048 */  sw        $s2, 0x48($sp)
/* DBF4D8 80242228 AFB10044 */  sw        $s1, 0x44($sp)
/* DBF4DC 8024222C AFB00040 */  sw        $s0, 0x40($sp)
/* DBF4E0 80242230 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* DBF4E4 80242234 F7B80068 */  sdc1      $f24, 0x68($sp)
/* DBF4E8 80242238 F7B60060 */  sdc1      $f22, 0x60($sp)
/* DBF4EC 8024223C F7B40058 */  sdc1      $f20, 0x58($sp)
/* DBF4F0 80242240 8E710148 */  lw        $s1, 0x148($s3)
/* DBF4F4 80242244 00A0902D */  daddu     $s2, $a1, $zero
/* DBF4F8 80242248 86240008 */  lh        $a0, 8($s1)
/* DBF4FC 8024224C 0C00EABB */  jal       get_npc_unsafe
/* DBF500 80242250 00C0A02D */   daddu    $s4, $a2, $zero
/* DBF504 80242254 0040802D */  daddu     $s0, $v0, $zero
/* DBF508 80242258 C6200078 */  lwc1      $f0, 0x78($s1)
/* DBF50C 8024225C 46800020 */  cvt.s.w   $f0, $f0
/* DBF510 80242260 46000021 */  cvt.d.s   $f0, $f0
/* DBF514 80242264 3C014059 */  lui       $at, 0x4059
/* DBF518 80242268 44811800 */  mtc1      $at, $f3
/* DBF51C 8024226C 44801000 */  mtc1      $zero, $f2
/* DBF520 80242270 8602008E */  lh        $v0, 0x8e($s0)
/* DBF524 80242274 9603008E */  lhu       $v1, 0x8e($s0)
/* DBF528 80242278 46220003 */  div.d     $f0, $f0, $f2
/* DBF52C 8024227C 46200620 */  cvt.s.d   $f24, $f0
/* DBF530 80242280 C6200088 */  lwc1      $f0, 0x88($s1)
/* DBF534 80242284 46800020 */  cvt.s.w   $f0, $f0
/* DBF538 80242288 46000021 */  cvt.d.s   $f0, $f0
/* DBF53C 8024228C 46220003 */  div.d     $f0, $f0, $f2
/* DBF540 80242290 46200020 */  cvt.s.d   $f0, $f0
/* DBF544 80242294 18400003 */  blez      $v0, .L802422A4
/* DBF548 80242298 4600C680 */   add.s    $f26, $f24, $f0
/* DBF54C 8024229C 2462FFFF */  addiu     $v0, $v1, -1
/* DBF550 802422A0 A602008E */  sh        $v0, 0x8e($s0)
.L802422A4:
/* DBF554 802422A4 8E220070 */  lw        $v0, 0x70($s1)
/* DBF558 802422A8 18400034 */  blez      $v0, .L8024237C
/* DBF55C 802422AC 00000000 */   nop      
/* DBF560 802422B0 C62C0074 */  lwc1      $f12, 0x74($s1)
/* DBF564 802422B4 46806320 */  cvt.s.w   $f12, $f12
/* DBF568 802422B8 44820000 */  mtc1      $v0, $f0
/* DBF56C 802422BC 00000000 */  nop       
/* DBF570 802422C0 46800020 */  cvt.s.w   $f0, $f0
/* DBF574 802422C4 46000021 */  cvt.d.s   $f0, $f0
/* DBF578 802422C8 46220003 */  div.d     $f0, $f0, $f2
/* DBF57C 802422CC 0C00A8BB */  jal       sin_deg
/* DBF580 802422D0 462005A0 */   cvt.s.d  $f22, $f0
/* DBF584 802422D4 8E020000 */  lw        $v0, ($s0)
/* DBF588 802422D8 30420008 */  andi      $v0, $v0, 8
/* DBF58C 802422DC 10400003 */  beqz      $v0, .L802422EC
/* DBF590 802422E0 46000506 */   mov.s    $f20, $f0
/* DBF594 802422E4 080908CB */  j         .L8024232C
/* DBF598 802422E8 0000102D */   daddu    $v0, $zero, $zero
.L802422EC:
/* DBF59C 802422EC 27A50028 */  addiu     $a1, $sp, 0x28
/* DBF5A0 802422F0 27A6002C */  addiu     $a2, $sp, 0x2c
/* DBF5A4 802422F4 C6000038 */  lwc1      $f0, 0x38($s0)
/* DBF5A8 802422F8 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBF5AC 802422FC C6040040 */  lwc1      $f4, 0x40($s0)
/* DBF5B0 80242300 3C01447A */  lui       $at, 0x447a
/* DBF5B4 80242304 44813000 */  mtc1      $at, $f6
/* DBF5B8 80242308 27A20034 */  addiu     $v0, $sp, 0x34
/* DBF5BC 8024230C E7A00028 */  swc1      $f0, 0x28($sp)
/* DBF5C0 80242310 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DBF5C4 80242314 E7A40030 */  swc1      $f4, 0x30($sp)
/* DBF5C8 80242318 E7A60034 */  swc1      $f6, 0x34($sp)
/* DBF5CC 8024231C AFA20010 */  sw        $v0, 0x10($sp)
/* DBF5D0 80242320 8E040080 */  lw        $a0, 0x80($s0)
/* DBF5D4 80242324 0C0372DF */  jal       func_800DCB7C
/* DBF5D8 80242328 27A70030 */   addiu    $a3, $sp, 0x30
.L8024232C:
/* DBF5DC 8024232C 10400007 */  beqz      $v0, .L8024234C
/* DBF5E0 80242330 00000000 */   nop      
/* DBF5E4 80242334 4616A082 */  mul.s     $f2, $f20, $f22
/* DBF5E8 80242338 00000000 */  nop       
/* DBF5EC 8024233C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DBF5F0 80242340 46180000 */  add.s     $f0, $f0, $f24
/* DBF5F4 80242344 080908D6 */  j         .L80242358
/* DBF5F8 80242348 46020000 */   add.s    $f0, $f0, $f2
.L8024234C:
/* DBF5FC 8024234C 4616A002 */  mul.s     $f0, $f20, $f22
/* DBF600 80242350 00000000 */  nop       
/* DBF604 80242354 4600D000 */  add.s     $f0, $f26, $f0
.L80242358:
/* DBF608 80242358 E600003C */  swc1      $f0, 0x3c($s0)
/* DBF60C 8024235C 8E220074 */  lw        $v0, 0x74($s1)
/* DBF610 80242360 2442000A */  addiu     $v0, $v0, 0xa
/* DBF614 80242364 44826000 */  mtc1      $v0, $f12
/* DBF618 80242368 00000000 */  nop       
/* DBF61C 8024236C 0C00A6C9 */  jal       clamp_angle
/* DBF620 80242370 46806320 */   cvt.s.w  $f12, $f12
/* DBF624 80242374 4600020D */  trunc.w.s $f8, $f0
/* DBF628 80242378 E6280074 */  swc1      $f8, 0x74($s1)
.L8024237C:
/* DBF62C 8024237C 8E220090 */  lw        $v0, 0x90($s1)
/* DBF630 80242380 1C400040 */  bgtz      $v0, .L80242484
/* DBF634 80242384 2442FFFF */   addiu    $v0, $v0, -1
/* DBF638 80242388 860200A8 */  lh        $v0, 0xa8($s0)
/* DBF63C 8024238C C600003C */  lwc1      $f0, 0x3c($s0)
/* DBF640 80242390 44821000 */  mtc1      $v0, $f2
/* DBF644 80242394 00000000 */  nop       
/* DBF648 80242398 468010A0 */  cvt.s.w   $f2, $f2
/* DBF64C 8024239C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBF650 802423A0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBF654 802423A4 46020000 */  add.s     $f0, $f0, $f2
/* DBF658 802423A8 3C014024 */  lui       $at, 0x4024
/* DBF65C 802423AC 44812800 */  mtc1      $at, $f5
/* DBF660 802423B0 44802000 */  mtc1      $zero, $f4
/* DBF664 802423B4 C442002C */  lwc1      $f2, 0x2c($v0)
/* DBF668 802423B8 46000021 */  cvt.d.s   $f0, $f0
/* DBF66C 802423BC 46240000 */  add.d     $f0, $f0, $f4
/* DBF670 802423C0 460010A1 */  cvt.d.s   $f2, $f2
/* DBF674 802423C4 4620103C */  c.lt.d    $f2, $f0
/* DBF678 802423C8 00000000 */  nop       
/* DBF67C 802423CC 4500002E */  bc1f      .L80242488
/* DBF680 802423D0 0280202D */   daddu    $a0, $s4, $zero
/* DBF684 802423D4 24020001 */  addiu     $v0, $zero, 1
/* DBF688 802423D8 AFA20010 */  sw        $v0, 0x10($sp)
/* DBF68C 802423DC 8E460024 */  lw        $a2, 0x24($s2)
/* DBF690 802423E0 8E470028 */  lw        $a3, 0x28($s2)
/* DBF694 802423E4 0C01242D */  jal       func_800490B4
/* DBF698 802423E8 0220282D */   daddu    $a1, $s1, $zero
/* DBF69C 802423EC 10400026 */  beqz      $v0, .L80242488
/* DBF6A0 802423F0 0000202D */   daddu    $a0, $zero, $zero
/* DBF6A4 802423F4 0200282D */  daddu     $a1, $s0, $zero
/* DBF6A8 802423F8 0000302D */  daddu     $a2, $zero, $zero
/* DBF6AC 802423FC 2412000C */  addiu     $s2, $zero, 0xc
/* DBF6B0 80242400 860300A8 */  lh        $v1, 0xa8($s0)
/* DBF6B4 80242404 3C013F80 */  lui       $at, 0x3f80
/* DBF6B8 80242408 44810000 */  mtc1      $at, $f0
/* DBF6BC 8024240C 3C014000 */  lui       $at, 0x4000
/* DBF6C0 80242410 44811000 */  mtc1      $at, $f2
/* DBF6C4 80242414 3C01C1A0 */  lui       $at, 0xc1a0
/* DBF6C8 80242418 44812000 */  mtc1      $at, $f4
/* DBF6CC 8024241C 44834000 */  mtc1      $v1, $f8
/* DBF6D0 80242420 00000000 */  nop       
/* DBF6D4 80242424 46804220 */  cvt.s.w   $f8, $f8
/* DBF6D8 80242428 44074000 */  mfc1      $a3, $f8
/* DBF6DC 8024242C 27A20038 */  addiu     $v0, $sp, 0x38
/* DBF6E0 80242430 AFB2001C */  sw        $s2, 0x1c($sp)
/* DBF6E4 80242434 AFA20020 */  sw        $v0, 0x20($sp)
/* DBF6E8 80242438 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBF6EC 8024243C E7A20014 */  swc1      $f2, 0x14($sp)
/* DBF6F0 80242440 0C01BFA4 */  jal       fx_emote
/* DBF6F4 80242444 E7A40018 */   swc1     $f4, 0x18($sp)
/* DBF6F8 80242448 0200202D */  daddu     $a0, $s0, $zero
/* DBF6FC 8024244C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DBF700 80242450 C480003C */  lwc1      $f0, 0x3c($a0)
/* DBF704 80242454 3C060020 */  lui       $a2, 0x20
/* DBF708 80242458 0C012530 */  jal       func_800494C0
/* DBF70C 8024245C E4800064 */   swc1     $f0, 0x64($a0)
/* DBF710 80242460 8E220018 */  lw        $v0, 0x18($s1)
/* DBF714 80242464 9442002A */  lhu       $v0, 0x2a($v0)
/* DBF718 80242468 30420001 */  andi      $v0, $v0, 1
/* DBF71C 8024246C 10400003 */  beqz      $v0, .L8024247C
/* DBF720 80242470 2402000A */   addiu    $v0, $zero, 0xa
/* DBF724 80242474 08090949 */  j         .L80242524
/* DBF728 80242478 AE620070 */   sw       $v0, 0x70($s3)
.L8024247C:
/* DBF72C 8024247C 08090949 */  j         .L80242524
/* DBF730 80242480 AE720070 */   sw       $s2, 0x70($s3)
.L80242484:
/* DBF734 80242484 AE220090 */  sw        $v0, 0x90($s1)
.L80242488:
/* DBF738 80242488 8602008C */  lh        $v0, 0x8c($s0)
/* DBF73C 8024248C 14400025 */  bnez      $v0, .L80242524
/* DBF740 80242490 00000000 */   nop      
/* DBF744 80242494 8602008E */  lh        $v0, 0x8e($s0)
/* DBF748 80242498 1C400022 */  bgtz      $v0, .L80242524
/* DBF74C 8024249C 00000000 */   nop      
/* DBF750 802424A0 8E620074 */  lw        $v0, 0x74($s3)
/* DBF754 802424A4 2442FFFF */  addiu     $v0, $v0, -1
/* DBF758 802424A8 1840001D */  blez      $v0, .L80242520
/* DBF75C 802424AC AE620074 */   sw       $v0, 0x74($s3)
/* DBF760 802424B0 8E220018 */  lw        $v0, 0x18($s1)
/* DBF764 802424B4 9442002A */  lhu       $v0, 0x2a($v0)
/* DBF768 802424B8 30420010 */  andi      $v0, $v0, 0x10
/* DBF76C 802424BC 14400007 */  bnez      $v0, .L802424DC
/* DBF770 802424C0 00000000 */   nop      
/* DBF774 802424C4 C600000C */  lwc1      $f0, 0xc($s0)
/* DBF778 802424C8 3C014334 */  lui       $at, 0x4334
/* DBF77C 802424CC 44816000 */  mtc1      $at, $f12
/* DBF780 802424D0 0C00A6C9 */  jal       clamp_angle
/* DBF784 802424D4 460C0300 */   add.s    $f12, $f0, $f12
/* DBF788 802424D8 E600000C */  swc1      $f0, 0xc($s0)
.L802424DC:
/* DBF78C 802424DC 0C00A67F */  jal       rand_int
/* DBF790 802424E0 240403E8 */   addiu    $a0, $zero, 0x3e8
/* DBF794 802424E4 3C032E8B */  lui       $v1, 0x2e8b
/* DBF798 802424E8 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* DBF79C 802424EC 00430018 */  mult      $v0, $v1
/* DBF7A0 802424F0 00021FC3 */  sra       $v1, $v0, 0x1f
/* DBF7A4 802424F4 00004010 */  mfhi      $t0
/* DBF7A8 802424F8 00082043 */  sra       $a0, $t0, 1
/* DBF7AC 802424FC 00832023 */  subu      $a0, $a0, $v1
/* DBF7B0 80242500 00041840 */  sll       $v1, $a0, 1
/* DBF7B4 80242504 00641821 */  addu      $v1, $v1, $a0
/* DBF7B8 80242508 00031880 */  sll       $v1, $v1, 2
/* DBF7BC 8024250C 00641823 */  subu      $v1, $v1, $a0
/* DBF7C0 80242510 00431023 */  subu      $v0, $v0, $v1
/* DBF7C4 80242514 24420005 */  addiu     $v0, $v0, 5
/* DBF7C8 80242518 08090949 */  j         .L80242524
/* DBF7CC 8024251C A602008E */   sh       $v0, 0x8e($s0)
.L80242520:
/* DBF7D0 80242520 AE600070 */  sw        $zero, 0x70($s3)
.L80242524:
/* DBF7D4 80242524 8FBF0054 */  lw        $ra, 0x54($sp)
/* DBF7D8 80242528 8FB40050 */  lw        $s4, 0x50($sp)
/* DBF7DC 8024252C 8FB3004C */  lw        $s3, 0x4c($sp)
/* DBF7E0 80242530 8FB20048 */  lw        $s2, 0x48($sp)
/* DBF7E4 80242534 8FB10044 */  lw        $s1, 0x44($sp)
/* DBF7E8 80242538 8FB00040 */  lw        $s0, 0x40($sp)
/* DBF7EC 8024253C D7BA0070 */  ldc1      $f26, 0x70($sp)
/* DBF7F0 80242540 D7B80068 */  ldc1      $f24, 0x68($sp)
/* DBF7F4 80242544 D7B60060 */  ldc1      $f22, 0x60($sp)
/* DBF7F8 80242548 D7B40058 */  ldc1      $f20, 0x58($sp)
/* DBF7FC 8024254C 03E00008 */  jr        $ra
/* DBF800 80242550 27BD0078 */   addiu    $sp, $sp, 0x78
