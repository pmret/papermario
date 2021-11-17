.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802DA1D0
.double -0.8, 0.0

.section .text

glabel ShakeCam
/* EFC58 802CB2A8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EFC5C 802CB2AC AFB5002C */  sw        $s5, 0x2c($sp)
/* EFC60 802CB2B0 0080A82D */  daddu     $s5, $a0, $zero
/* EFC64 802CB2B4 AFB20020 */  sw        $s2, 0x20($sp)
/* EFC68 802CB2B8 00A0902D */  daddu     $s2, $a1, $zero
/* EFC6C 802CB2BC AFBF0030 */  sw        $ra, 0x30($sp)
/* EFC70 802CB2C0 AFB40028 */  sw        $s4, 0x28($sp)
/* EFC74 802CB2C4 AFB30024 */  sw        $s3, 0x24($sp)
/* EFC78 802CB2C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* EFC7C 802CB2CC AFB00018 */  sw        $s0, 0x18($sp)
/* EFC80 802CB2D0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* EFC84 802CB2D4 8EB0000C */  lw        $s0, 0xc($s5)
/* EFC88 802CB2D8 8E050000 */  lw        $a1, ($s0)
/* EFC8C 802CB2DC 0C0B1EAF */  jal       evt_get_variable
/* EFC90 802CB2E0 26100004 */   addiu    $s0, $s0, 4
/* EFC94 802CB2E4 8E050000 */  lw        $a1, ($s0)
/* EFC98 802CB2E8 26100004 */  addiu     $s0, $s0, 4
/* EFC9C 802CB2EC 02A0202D */  daddu     $a0, $s5, $zero
/* EFCA0 802CB2F0 0C0B1EAF */  jal       evt_get_variable
/* EFCA4 802CB2F4 0040882D */   daddu    $s1, $v0, $zero
/* EFCA8 802CB2F8 8E050000 */  lw        $a1, ($s0)
/* EFCAC 802CB2FC 26100004 */  addiu     $s0, $s0, 4
/* EFCB0 802CB300 02A0202D */  daddu     $a0, $s5, $zero
/* EFCB4 802CB304 0C0B1EAF */  jal       evt_get_variable
/* EFCB8 802CB308 0040982D */   daddu    $s3, $v0, $zero
/* EFCBC 802CB30C 0040A02D */  daddu     $s4, $v0, $zero
/* EFCC0 802CB310 8E050000 */  lw        $a1, ($s0)
/* EFCC4 802CB314 0C0B210B */  jal       evt_get_float_variable
/* EFCC8 802CB318 02A0202D */   daddu    $a0, $s5, $zero
/* EFCCC 802CB31C 3C04800B */  lui       $a0, %hi(gCameras)
/* EFCD0 802CB320 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* EFCD4 802CB324 00111080 */  sll       $v0, $s1, 2
/* EFCD8 802CB328 00511021 */  addu      $v0, $v0, $s1
/* EFCDC 802CB32C 00021080 */  sll       $v0, $v0, 2
/* EFCE0 802CB330 00511023 */  subu      $v0, $v0, $s1
/* EFCE4 802CB334 000218C0 */  sll       $v1, $v0, 3
/* EFCE8 802CB338 00431021 */  addu      $v0, $v0, $v1
/* EFCEC 802CB33C 000210C0 */  sll       $v0, $v0, 3
/* EFCF0 802CB340 00448021 */  addu      $s0, $v0, $a0
/* EFCF4 802CB344 12400031 */  beqz      $s2, .L802CB40C
/* EFCF8 802CB348 46000500 */   add.s    $f20, $f0, $f0
/* EFCFC 802CB34C 06600005 */  bltz      $s3, .L802CB364
/* EFD00 802CB350 2A620002 */   slti     $v0, $s3, 2
/* EFD04 802CB354 14400003 */  bnez      $v0, .L802CB364
/* EFD08 802CB358 24020002 */   addiu    $v0, $zero, 2
/* EFD0C 802CB35C 52620001 */  beql      $s3, $v0, .L802CB364
/* EFD10 802CB360 0054A004 */   sllv     $s4, $s4, $v0
.L802CB364:
/* EFD14 802CB364 3C013F80 */  lui       $at, 0x3f80
/* EFD18 802CB368 44810000 */  mtc1      $at, $f0
/* EFD1C 802CB36C 00000000 */  nop
/* EFD20 802CB370 E6A0007C */  swc1      $f0, 0x7c($s5)
/* EFD24 802CB374 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* EFD28 802CB378 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* EFD2C 802CB37C AEB40074 */  sw        $s4, 0x74($s5)
/* EFD30 802CB380 80420070 */  lb        $v0, 0x70($v0)
/* EFD34 802CB384 14400021 */  bnez      $v0, .L802CB40C
/* EFD38 802CB388 00000000 */   nop
/* EFD3C 802CB38C 3C014120 */  lui       $at, 0x4120
/* EFD40 802CB390 44810000 */  mtc1      $at, $f0
/* EFD44 802CB394 00000000 */  nop
/* EFD48 802CB398 4614003C */  c.lt.s    $f0, $f20
/* EFD4C 802CB39C 00000000 */  nop
/* EFD50 802CB3A0 45030001 */  bc1tl     .L802CB3A8
/* EFD54 802CB3A4 46000506 */   mov.s    $f20, $f0
.L802CB3A8:
/* EFD58 802CB3A8 3C0140C0 */  lui       $at, 0x40c0
/* EFD5C 802CB3AC 44810000 */  mtc1      $at, $f0
/* EFD60 802CB3B0 00000000 */  nop
/* EFD64 802CB3B4 4614003C */  c.lt.s    $f0, $f20
/* EFD68 802CB3B8 00000000 */  nop
/* EFD6C 802CB3BC 45000002 */  bc1f      .L802CB3C8
/* EFD70 802CB3C0 4600A086 */   mov.s    $f2, $f20
/* EFD74 802CB3C4 46000086 */  mov.s     $f2, $f0
.L802CB3C8:
/* EFD78 802CB3C8 3C014200 */  lui       $at, 0x4200
/* EFD7C 802CB3CC 44810000 */  mtc1      $at, $f0
/* EFD80 802CB3D0 00000000 */  nop
/* EFD84 802CB3D4 46001002 */  mul.s     $f0, $f2, $f0
/* EFD88 802CB3D8 00000000 */  nop
/* EFD8C 802CB3DC 0280282D */  daddu     $a1, $s4, $zero
/* EFD90 802CB3E0 3C014280 */  lui       $at, 0x4280
/* EFD94 802CB3E4 44811000 */  mtc1      $at, $f2
/* EFD98 802CB3E8 2A820005 */  slti      $v0, $s4, 5
/* EFD9C 802CB3EC 10400002 */  beqz      $v0, .L802CB3F8
/* EFDA0 802CB3F0 46020080 */   add.s    $f2, $f0, $f2
/* EFDA4 802CB3F4 24050005 */  addiu     $a1, $zero, 5
.L802CB3F8:
/* EFDA8 802CB3F8 4600110D */  trunc.w.s $f4, $f2
/* EFDAC 802CB3FC 44042000 */  mfc1      $a0, $f4
/* EFDB0 802CB400 30A5FFFF */  andi      $a1, $a1, 0xffff
/* EFDB4 802CB404 0C00A3C2 */  jal       start_rumble
/* EFDB8 802CB408 00052840 */   sll      $a1, $a1, 1
.L802CB40C:
/* EFDBC 802CB40C 96020000 */  lhu       $v0, ($s0)
/* EFDC0 802CB410 34420008 */  ori       $v0, $v0, 8
/* EFDC4 802CB414 A6020000 */  sh        $v0, ($s0)
/* EFDC8 802CB418 24020001 */  addiu     $v0, $zero, 1
/* EFDCC 802CB41C C6A2007C */  lwc1      $f2, 0x7c($s5)
/* EFDD0 802CB420 12620016 */  beq       $s3, $v0, .L802CB47C
/* EFDD4 802CB424 2A620002 */   slti     $v0, $s3, 2
/* EFDD8 802CB428 10400005 */  beqz      $v0, .L802CB440
/* EFDDC 802CB42C 24020002 */   addiu    $v0, $zero, 2
/* EFDE0 802CB430 52600007 */  beql      $s3, $zero, .L802CB450
/* EFDE4 802CB434 46001007 */   neg.s    $f0, $f2
/* EFDE8 802CB438 080B2D47 */  j         .L802CB51C
/* EFDEC 802CB43C 00000000 */   nop
.L802CB440:
/* EFDF0 802CB440 5262001B */  beql      $s3, $v0, .L802CB4B0
/* EFDF4 802CB444 46001007 */   neg.s    $f0, $f2
/* EFDF8 802CB448 080B2D47 */  j         .L802CB51C
/* EFDFC 802CB44C 00000000 */   nop
.L802CB450:
/* EFE00 802CB450 46140002 */  mul.s     $f0, $f0, $f20
/* EFE04 802CB454 00000000 */  nop
/* EFE08 802CB458 44060000 */  mfc1      $a2, $f0
/* EFE0C 802CB45C 44800000 */  mtc1      $zero, $f0
/* EFE10 802CB460 00000000 */  nop
/* EFE14 802CB464 44050000 */  mfc1      $a1, $f0
/* EFE18 802CB468 26040194 */  addiu     $a0, $s0, 0x194
/* EFE1C 802CB46C 0C019E40 */  jal       guTranslateF
/* EFE20 802CB470 00A0382D */   daddu    $a3, $a1, $zero
/* EFE24 802CB474 080B2D44 */  j         .L802CB510
/* EFE28 802CB478 00000000 */   nop
.L802CB47C:
/* EFE2C 802CB47C 46141082 */  mul.s     $f2, $f2, $f20
/* EFE30 802CB480 00000000 */  nop
/* EFE34 802CB484 44800000 */  mtc1      $zero, $f0
/* EFE38 802CB488 26040194 */  addiu     $a0, $s0, 0x194
/* EFE3C 802CB48C 44060000 */  mfc1      $a2, $f0
/* EFE40 802CB490 3C013F80 */  lui       $at, 0x3f80
/* EFE44 802CB494 44810000 */  mtc1      $at, $f0
/* EFE48 802CB498 44051000 */  mfc1      $a1, $f2
/* EFE4C 802CB49C 00C0382D */  daddu     $a3, $a2, $zero
/* EFE50 802CB4A0 0C019EC8 */  jal       guRotateF
/* EFE54 802CB4A4 E7A00010 */   swc1     $f0, 0x10($sp)
/* EFE58 802CB4A8 080B2D44 */  j         .L802CB510
/* EFE5C 802CB4AC 00000000 */   nop
.L802CB4B0:
/* EFE60 802CB4B0 46140002 */  mul.s     $f0, $f0, $f20
/* EFE64 802CB4B4 00000000 */  nop
/* EFE68 802CB4B8 44060000 */  mfc1      $a2, $f0
/* EFE6C 802CB4BC 44800000 */  mtc1      $zero, $f0
/* EFE70 802CB4C0 00000000 */  nop
/* EFE74 802CB4C4 44050000 */  mfc1      $a1, $f0
/* EFE78 802CB4C8 26040194 */  addiu     $a0, $s0, 0x194
/* EFE7C 802CB4CC 0C019E40 */  jal       guTranslateF
/* EFE80 802CB4D0 00A0382D */   daddu    $a3, $a1, $zero
/* EFE84 802CB4D4 8EA30074 */  lw        $v1, 0x74($s5)
/* EFE88 802CB4D8 00141040 */  sll       $v0, $s4, 1
/* EFE8C 802CB4DC 0062102A */  slt       $v0, $v1, $v0
/* EFE90 802CB4E0 1040000B */  beqz      $v0, .L802CB510
/* EFE94 802CB4E4 0283102A */   slt      $v0, $s4, $v1
/* EFE98 802CB4E8 10400009 */  beqz      $v0, .L802CB510
/* EFE9C 802CB4EC 00000000 */   nop
/* EFEA0 802CB4F0 C6A0007C */  lwc1      $f0, 0x7c($s5)
/* EFEA4 802CB4F4 3C01802E */  lui       $at, %hi(D_802DA1D0)
/* EFEA8 802CB4F8 D422A1D0 */  ldc1      $f2, %lo(D_802DA1D0)($at)
/* EFEAC 802CB4FC 46000021 */  cvt.d.s   $f0, $f0
/* EFEB0 802CB500 46220002 */  mul.d     $f0, $f0, $f2
/* EFEB4 802CB504 00000000 */  nop
/* EFEB8 802CB508 080B2D46 */  j         .L802CB518
/* EFEBC 802CB50C 46200020 */   cvt.s.d  $f0, $f0
.L802CB510:
/* EFEC0 802CB510 C6A0007C */  lwc1      $f0, 0x7c($s5)
/* EFEC4 802CB514 46000007 */  neg.s     $f0, $f0
.L802CB518:
/* EFEC8 802CB518 E6A0007C */  swc1      $f0, 0x7c($s5)
.L802CB51C:
/* EFECC 802CB51C 8EA20074 */  lw        $v0, 0x74($s5)
/* EFED0 802CB520 10400004 */  beqz      $v0, .L802CB534
/* EFED4 802CB524 2442FFFF */   addiu    $v0, $v0, -1
/* EFED8 802CB528 AEA20074 */  sw        $v0, 0x74($s5)
/* EFEDC 802CB52C 080B2D51 */  j         .L802CB544
/* EFEE0 802CB530 0000102D */   daddu    $v0, $zero, $zero
.L802CB534:
/* EFEE4 802CB534 96030000 */  lhu       $v1, ($s0)
/* EFEE8 802CB538 24020002 */  addiu     $v0, $zero, 2
/* EFEEC 802CB53C 3063FFF7 */  andi      $v1, $v1, 0xfff7
/* EFEF0 802CB540 A6030000 */  sh        $v1, ($s0)
.L802CB544:
/* EFEF4 802CB544 8FBF0030 */  lw        $ra, 0x30($sp)
/* EFEF8 802CB548 8FB5002C */  lw        $s5, 0x2c($sp)
/* EFEFC 802CB54C 8FB40028 */  lw        $s4, 0x28($sp)
/* EFF00 802CB550 8FB30024 */  lw        $s3, 0x24($sp)
/* EFF04 802CB554 8FB20020 */  lw        $s2, 0x20($sp)
/* EFF08 802CB558 8FB1001C */  lw        $s1, 0x1c($sp)
/* EFF0C 802CB55C 8FB00018 */  lw        $s0, 0x18($sp)
/* EFF10 802CB560 D7B40038 */  ldc1      $f20, 0x38($sp)
/* EFF14 802CB564 03E00008 */  jr        $ra
/* EFF18 802CB568 27BD0040 */   addiu    $sp, $sp, 0x40
