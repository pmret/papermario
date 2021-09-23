.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80247B50_EE6510
.double 0.8

.section .text

glabel func_8024236C_EE0D2C
/* EE0D2C 8024236C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EE0D30 80242370 AFB3001C */  sw        $s3, 0x1c($sp)
/* EE0D34 80242374 0080982D */  daddu     $s3, $a0, $zero
/* EE0D38 80242378 AFBF0020 */  sw        $ra, 0x20($sp)
/* EE0D3C 8024237C AFB20018 */  sw        $s2, 0x18($sp)
/* EE0D40 80242380 AFB10014 */  sw        $s1, 0x14($sp)
/* EE0D44 80242384 AFB00010 */  sw        $s0, 0x10($sp)
/* EE0D48 80242388 8E710148 */  lw        $s1, 0x148($s3)
/* EE0D4C 8024238C 86240008 */  lh        $a0, 8($s1)
/* EE0D50 80242390 0C00F92F */  jal       dead_get_npc_unsafe
/* EE0D54 80242394 00A0902D */   daddu    $s2, $a1, $zero
/* EE0D58 80242398 0040802D */  daddu     $s0, $v0, $zero
/* EE0D5C 8024239C 8602008E */  lh        $v0, 0x8e($s0)
/* EE0D60 802423A0 9603008E */  lhu       $v1, 0x8e($s0)
/* EE0D64 802423A4 18400005 */  blez      $v0, .L802423BC
/* EE0D68 802423A8 2462FFFF */   addiu    $v0, $v1, -1
/* EE0D6C 802423AC A602008E */  sh        $v0, 0x8e($s0)
/* EE0D70 802423B0 00021400 */  sll       $v0, $v0, 0x10
/* EE0D74 802423B4 1C400033 */  bgtz      $v0, .L80242484
/* EE0D78 802423B8 00000000 */   nop
.L802423BC:
/* EE0D7C 802423BC 8602008C */  lh        $v0, 0x8c($s0)
/* EE0D80 802423C0 14400030 */  bnez      $v0, .L80242484
/* EE0D84 802423C4 00000000 */   nop
/* EE0D88 802423C8 8E2200CC */  lw        $v0, 0xcc($s1)
/* EE0D8C 802423CC 8C420024 */  lw        $v0, 0x24($v0)
/* EE0D90 802423D0 AE020028 */  sw        $v0, 0x28($s0)
/* EE0D94 802423D4 C6400018 */  lwc1      $f0, 0x18($s2)
/* EE0D98 802423D8 E6000018 */  swc1      $f0, 0x18($s0)
/* EE0D9C 802423DC 8E230088 */  lw        $v1, 0x88($s1)
/* EE0DA0 802423E0 24020005 */  addiu     $v0, $zero, 5
/* EE0DA4 802423E4 10620005 */  beq       $v1, $v0, .L802423FC
/* EE0DA8 802423E8 00000000 */   nop
/* EE0DAC 802423EC 10600003 */  beqz      $v1, .L802423FC
/* EE0DB0 802423F0 24020001 */   addiu    $v0, $zero, 1
/* EE0DB4 802423F4 14620006 */  bne       $v1, $v0, .L80242410
/* EE0DB8 802423F8 00000000 */   nop
.L802423FC:
/* EE0DBC 802423FC 8E220084 */  lw        $v0, 0x84($s1)
/* EE0DC0 80242400 00021FC2 */  srl       $v1, $v0, 0x1f
/* EE0DC4 80242404 00431021 */  addu      $v0, $v0, $v1
/* EE0DC8 80242408 00021043 */  sra       $v0, $v0, 1
/* EE0DCC 8024240C A60200A8 */  sh        $v0, 0xa8($s0)
.L80242410:
/* EE0DD0 80242410 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EE0DD4 80242414 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EE0DD8 80242418 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EE0DDC 8024241C C60E0040 */  lwc1      $f14, 0x40($s0)
/* EE0DE0 80242420 8C460028 */  lw        $a2, 0x28($v0)
/* EE0DE4 80242424 0C00AC71 */  jal       dead_dist2D
/* EE0DE8 80242428 8C470030 */   lw       $a3, 0x30($v0)
/* EE0DEC 8024242C C6020018 */  lwc1      $f2, 0x18($s0)
/* EE0DF0 80242430 46020003 */  div.s     $f0, $f0, $f2
/* EE0DF4 80242434 3C018024 */  lui       $at, %hi(D_80247B50_EE6510)
/* EE0DF8 80242438 D4227B50 */  ldc1      $f2, %lo(D_80247B50_EE6510)($at)
/* EE0DFC 8024243C 46000021 */  cvt.d.s   $f0, $f0
/* EE0E00 80242440 46220000 */  add.d     $f0, $f0, $f2
/* EE0E04 80242444 4620010D */  trunc.w.d $f4, $f0
/* EE0E08 80242448 44022000 */  mfc1      $v0, $f4
/* EE0E0C 8024244C 00000000 */  nop
/* EE0E10 80242450 A602008E */  sh        $v0, 0x8e($s0)
/* EE0E14 80242454 00021400 */  sll       $v0, $v0, 0x10
/* EE0E18 80242458 8E230078 */  lw        $v1, 0x78($s1)
/* EE0E1C 8024245C 00021403 */  sra       $v0, $v0, 0x10
/* EE0E20 80242460 0043102A */  slt       $v0, $v0, $v1
/* EE0E24 80242464 10400003 */  beqz      $v0, .L80242474
/* EE0E28 80242468 00000000 */   nop
/* EE0E2C 8024246C 9622007A */  lhu       $v0, 0x7a($s1)
/* EE0E30 80242470 A602008E */  sh        $v0, 0x8e($s0)
.L80242474:
/* EE0E34 80242474 8602008E */  lh        $v0, 0x8e($s0)
/* EE0E38 80242478 AE22007C */  sw        $v0, 0x7c($s1)
/* EE0E3C 8024247C 2402000E */  addiu     $v0, $zero, 0xe
/* EE0E40 80242480 AE620070 */  sw        $v0, 0x70($s3)
.L80242484:
/* EE0E44 80242484 8FBF0020 */  lw        $ra, 0x20($sp)
/* EE0E48 80242488 8FB3001C */  lw        $s3, 0x1c($sp)
/* EE0E4C 8024248C 8FB20018 */  lw        $s2, 0x18($sp)
/* EE0E50 80242490 8FB10014 */  lw        $s1, 0x14($sp)
/* EE0E54 80242494 8FB00010 */  lw        $s0, 0x10($sp)
/* EE0E58 80242498 03E00008 */  jr        $ra
/* EE0E5C 8024249C 27BD0028 */   addiu    $sp, $sp, 0x28
