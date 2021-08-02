.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242374_EEF474
/* EEF474 80242374 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EEF478 80242378 AFB3001C */  sw        $s3, 0x1c($sp)
/* EEF47C 8024237C 0080982D */  daddu     $s3, $a0, $zero
/* EEF480 80242380 AFBF0020 */  sw        $ra, 0x20($sp)
/* EEF484 80242384 AFB20018 */  sw        $s2, 0x18($sp)
/* EEF488 80242388 AFB10014 */  sw        $s1, 0x14($sp)
/* EEF48C 8024238C AFB00010 */  sw        $s0, 0x10($sp)
/* EEF490 80242390 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EEF494 80242394 8E710148 */  lw        $s1, 0x148($s3)
/* EEF498 80242398 86240008 */  lh        $a0, 8($s1)
/* EEF49C 8024239C 0C00F92F */  jal       dead_get_npc_unsafe
/* EEF4A0 802423A0 00A0802D */   daddu    $s0, $a1, $zero
/* EEF4A4 802423A4 8E040020 */  lw        $a0, 0x20($s0)
/* EEF4A8 802423A8 0040902D */  daddu     $s2, $v0, $zero
/* EEF4AC 802423AC 00041FC2 */  srl       $v1, $a0, 0x1f
/* EEF4B0 802423B0 00832021 */  addu      $a0, $a0, $v1
/* EEF4B4 802423B4 00042043 */  sra       $a0, $a0, 1
/* EEF4B8 802423B8 0C00AB3B */  jal       dead_rand_int
/* EEF4BC 802423BC 24840001 */   addiu    $a0, $a0, 1
/* EEF4C0 802423C0 8E030020 */  lw        $v1, 0x20($s0)
/* EEF4C4 802423C4 C64C0038 */  lwc1      $f12, 0x38($s2)
/* EEF4C8 802423C8 000327C2 */  srl       $a0, $v1, 0x1f
/* EEF4CC 802423CC 00641821 */  addu      $v1, $v1, $a0
/* EEF4D0 802423D0 00031843 */  sra       $v1, $v1, 1
/* EEF4D4 802423D4 00621821 */  addu      $v1, $v1, $v0
/* EEF4D8 802423D8 A643008E */  sh        $v1, 0x8e($s2)
/* EEF4DC 802423DC 8E2200CC */  lw        $v0, 0xcc($s1)
/* EEF4E0 802423E0 C64E0040 */  lwc1      $f14, 0x40($s2)
/* EEF4E4 802423E4 8C42000C */  lw        $v0, 0xc($v0)
/* EEF4E8 802423E8 AE420028 */  sw        $v0, 0x28($s2)
/* EEF4EC 802423EC C6000018 */  lwc1      $f0, 0x18($s0)
/* EEF4F0 802423F0 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EEF4F4 802423F4 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EEF4F8 802423F8 E6400018 */  swc1      $f0, 0x18($s2)
/* EEF4FC 802423FC 8C460028 */  lw        $a2, 0x28($v0)
/* EEF500 80242400 0C00ABDC */  jal       fio_validate_header_checksums
/* EEF504 80242404 8C470030 */   lw       $a3, 0x30($v0)
/* EEF508 80242408 46000506 */  mov.s     $f20, $f0
/* EEF50C 8024240C C64C000C */  lwc1      $f12, 0xc($s2)
/* EEF510 80242410 0C00ABC6 */  jal       func_8002AF18
/* EEF514 80242414 4600A386 */   mov.s    $f14, $f20
/* EEF518 80242418 46000086 */  mov.s     $f2, $f0
/* EEF51C 8024241C 8E02001C */  lw        $v0, 0x1c($s0)
/* EEF520 80242420 46001005 */  abs.s     $f0, $f2
/* EEF524 80242424 44822000 */  mtc1      $v0, $f4
/* EEF528 80242428 00000000 */  nop
/* EEF52C 8024242C 46802120 */  cvt.s.w   $f4, $f4
/* EEF530 80242430 4600203C */  c.lt.s    $f4, $f0
/* EEF534 80242434 00000000 */  nop
/* EEF538 80242438 4500000D */  bc1f      .L80242470
/* EEF53C 8024243C 00000000 */   nop
/* EEF540 80242440 44800000 */  mtc1      $zero, $f0
/* EEF544 80242444 C654000C */  lwc1      $f20, 0xc($s2)
/* EEF548 80242448 4600103C */  c.lt.s    $f2, $f0
/* EEF54C 8024244C 00000000 */  nop
/* EEF550 80242450 45000006 */  bc1f      .L8024246C
/* EEF554 80242454 00021023 */   negu     $v0, $v0
/* EEF558 80242458 44820000 */  mtc1      $v0, $f0
/* EEF55C 8024245C 00000000 */  nop
/* EEF560 80242460 46800020 */  cvt.s.w   $f0, $f0
/* EEF564 80242464 0809091C */  j         .L80242470
/* EEF568 80242468 4600A500 */   add.s    $f20, $f20, $f0
.L8024246C:
/* EEF56C 8024246C 4604A500 */  add.s     $f20, $f20, $f4
.L80242470:
/* EEF570 80242470 0C00AB85 */  jal       dead_clamp_angle
/* EEF574 80242474 4600A306 */   mov.s    $f12, $f20
/* EEF578 80242478 2402000D */  addiu     $v0, $zero, 0xd
/* EEF57C 8024247C E640000C */  swc1      $f0, 0xc($s2)
/* EEF580 80242480 AE620070 */  sw        $v0, 0x70($s3)
/* EEF584 80242484 8FBF0020 */  lw        $ra, 0x20($sp)
/* EEF588 80242488 8FB3001C */  lw        $s3, 0x1c($sp)
/* EEF58C 8024248C 8FB20018 */  lw        $s2, 0x18($sp)
/* EEF590 80242490 8FB10014 */  lw        $s1, 0x14($sp)
/* EEF594 80242494 8FB00010 */  lw        $s0, 0x10($sp)
/* EEF598 80242498 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EEF59C 8024249C 03E00008 */  jr        $ra
/* EEF5A0 802424A0 27BD0030 */   addiu    $sp, $sp, 0x30
