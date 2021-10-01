.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_7_appendGfx
/* 32C398 E000E288 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 32C39C E000E28C AFB700B4 */  sw        $s7, 0xb4($sp)
/* 32C3A0 E000E290 0080B82D */  daddu     $s7, $a0, $zero
/* 32C3A4 E000E294 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 32C3A8 E000E298 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 32C3AC E000E29C AFB600B0 */  sw        $s6, 0xb0($sp)
/* 32C3B0 E000E2A0 AFB500AC */  sw        $s5, 0xac($sp)
/* 32C3B4 E000E2A4 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 32C3B8 E000E2A8 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 32C3BC E000E2AC AFB200A0 */  sw        $s2, 0xa0($sp)
/* 32C3C0 E000E2B0 AFB1009C */  sw        $s1, 0x9c($sp)
/* 32C3C4 E000E2B4 AFB00098 */  sw        $s0, 0x98($sp)
/* 32C3C8 E000E2B8 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 32C3CC E000E2BC 8EE7000C */  lw        $a3, 0xc($s7)
/* 32C3D0 E000E2C0 3C1E0900 */  lui       $fp, 0x900
/* 32C3D4 E000E2C4 27DE2B40 */  addiu     $fp, $fp, 0x2b40
/* 32C3D8 E000E2C8 94EB0004 */  lhu       $t3, 4($a3)
/* 32C3DC E000E2CC 8CEC0074 */  lw        $t4, 0x74($a3)
/* 32C3E0 E000E2D0 15600005 */  bnez      $t3, .LE000E2E8
/* 32C3E4 E000E2D4 0000682D */   daddu    $t5, $zero, $zero
/* 32C3E8 E000E2D8 3C1E0900 */  lui       $fp, 0x900
/* 32C3EC E000E2DC 27DE2B20 */  addiu     $fp, $fp, 0x2b20
/* 32C3F0 E000E2E0 1160000A */  beqz      $t3, .LE000E30C
/* 32C3F4 E000E2E4 00000000 */   nop
.LE000E2E8:
/* 32C3F8 E000E2E8 3C0A0900 */  lui       $t2, 0x900
/* 32C3FC E000E2EC 254A2950 */  addiu     $t2, $t2, 0x2950
/* 32C400 E000E2F0 24020001 */  addiu     $v0, $zero, 1
/* 32C404 E000E2F4 15620007 */  bne       $t3, $v0, .LE000E314
/* 32C408 E000E2F8 00000000 */   nop
/* 32C40C E000E2FC 3C0A0900 */  lui       $t2, 0x900
/* 32C410 E000E300 254A2868 */  addiu     $t2, $t2, 0x2868
/* 32C414 E000E304 080038C5 */  j         .LE000E314
/* 32C418 E000E308 00000000 */   nop
.LE000E30C:
/* 32C41C E000E30C 3C0A0900 */  lui       $t2, 0x900
/* 32C420 E000E310 254A2780 */  addiu     $t2, $t2, 0x2780
.LE000E314:
/* 32C424 E000E314 8CE3006C */  lw        $v1, 0x6c($a3)
/* 32C428 E000E318 14600004 */  bnez      $v1, .LE000E32C
/* 32C42C E000E31C 24020001 */   addiu    $v0, $zero, 1
/* 32C430 E000E320 24020006 */  addiu     $v0, $zero, 6
/* 32C434 E000E324 11820006 */  beq       $t4, $v0, .LE000E340
/* 32C438 E000E328 24020001 */   addiu    $v0, $zero, 1
.LE000E32C:
/* 32C43C E000E32C 14620006 */  bne       $v1, $v0, .LE000E348
/* 32C440 E000E330 3C04DB06 */   lui      $a0, 0xdb06
/* 32C444 E000E334 24020007 */  addiu     $v0, $zero, 7
/* 32C448 E000E338 15820004 */  bne       $t4, $v0, .LE000E34C
/* 32C44C E000E33C 34840024 */   ori      $a0, $a0, 0x24
.LE000E340:
/* 32C450 E000E340 240D0001 */  addiu     $t5, $zero, 1
/* 32C454 E000E344 3C04DB06 */  lui       $a0, 0xdb06
.LE000E348:
/* 32C458 E000E348 34840024 */  ori       $a0, $a0, 0x24
.LE000E34C:
/* 32C45C E000E34C 3C05E6DE */  lui       $a1, 0xe6de
/* 32C460 E000E350 34A5DE6E */  ori       $a1, $a1, 0xde6e
/* 32C464 E000E354 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 32C468 E000E358 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 32C46C E000E35C 24090020 */  addiu     $t1, $zero, 0x20
/* 32C470 E000E360 8D060000 */  lw        $a2, ($t0)
/* 32C474 E000E364 3C02E700 */  lui       $v0, 0xe700
/* 32C478 E000E368 00C0182D */  daddu     $v1, $a2, $zero
/* 32C47C E000E36C 24C60008 */  addiu     $a2, $a2, 8
/* 32C480 E000E370 AD060000 */  sw        $a2, ($t0)
/* 32C484 E000E374 AC620000 */  sw        $v0, ($v1)
/* 32C488 E000E378 24C20008 */  addiu     $v0, $a2, 8
/* 32C48C E000E37C AC600004 */  sw        $zero, 4($v1)
/* 32C490 E000E380 AD020000 */  sw        $v0, ($t0)
/* 32C494 E000E384 24C20010 */  addiu     $v0, $a2, 0x10
/* 32C498 E000E388 ACC40000 */  sw        $a0, ($a2)
/* 32C49C E000E38C AD020000 */  sw        $v0, ($t0)
/* 32C4A0 E000E390 24C20018 */  addiu     $v0, $a2, 0x18
/* 32C4A4 E000E394 AD020000 */  sw        $v0, ($t0)
/* 32C4A8 E000E398 8EE30010 */  lw        $v1, 0x10($s7)
/* 32C4AC E000E39C 00C91021 */  addu      $v0, $a2, $t1
/* 32C4B0 E000E3A0 AD020000 */  sw        $v0, ($t0)
/* 32C4B4 E000E3A4 8C63001C */  lw        $v1, 0x1c($v1)
/* 32C4B8 E000E3A8 3C02DE00 */  lui       $v0, 0xde00
/* 32C4BC E000E3AC ACC20008 */  sw        $v0, 8($a2)
/* 32C4C0 E000E3B0 3C02FB00 */  lui       $v0, 0xfb00
/* 32C4C4 E000E3B4 ACC20010 */  sw        $v0, 0x10($a2)
/* 32C4C8 E000E3B8 2402007F */  addiu     $v0, $zero, 0x7f
/* 32C4CC E000E3BC ACC20014 */  sw        $v0, 0x14($a2)
/* 32C4D0 E000E3C0 3C02FA00 */  lui       $v0, 0xfa00
/* 32C4D4 E000E3C4 ACC20018 */  sw        $v0, 0x18($a2)
/* 32C4D8 E000E3C8 3C028000 */  lui       $v0, 0x8000
/* 32C4DC E000E3CC ACCA000C */  sw        $t2, 0xc($a2)
/* 32C4E0 E000E3D0 ACC5001C */  sw        $a1, 0x1c($a2)
/* 32C4E4 E000E3D4 00621821 */  addu      $v1, $v1, $v0
/* 32C4E8 E000E3D8 15600002 */  bnez      $t3, .LE000E3E4
/* 32C4EC E000E3DC ACC30004 */   sw       $v1, 4($a2)
/* 32C4F0 E000E3E0 24090018 */  addiu     $t1, $zero, 0x18
.LE000E3E4:
/* 32C4F4 E000E3E4 01890018 */  mult      $t4, $t1
/* 32C4F8 E000E3E8 24C20028 */  addiu     $v0, $a2, 0x28
/* 32C4FC E000E3EC 3C0BF200 */  lui       $t3, 0xf200
/* 32C500 E000E3F0 AD020000 */  sw        $v0, ($t0)
/* 32C504 E000E3F4 00002812 */  mflo      $a1
/* 32C508 E000E3F8 00051080 */  sll       $v0, $a1, 2
/* 32C50C E000E3FC 30420FFF */  andi      $v0, $v0, 0xfff
/* 32C510 E000E400 00021300 */  sll       $v0, $v0, 0xc
/* 32C514 E000E404 004B1025 */  or        $v0, $v0, $t3
/* 32C518 E000E408 00A92021 */  addu      $a0, $a1, $t1
/* 32C51C E000E40C 2483FFFF */  addiu     $v1, $a0, -1
/* 32C520 E000E410 00031880 */  sll       $v1, $v1, 2
/* 32C524 E000E414 30630FFF */  andi      $v1, $v1, 0xfff
/* 32C528 E000E418 00031B00 */  sll       $v1, $v1, 0xc
/* 32C52C E000E41C ACC20020 */  sw        $v0, 0x20($a2)
/* 32C530 E000E420 2522FFFF */  addiu     $v0, $t1, -1
/* 32C534 E000E424 00021080 */  sll       $v0, $v0, 2
/* 32C538 E000E428 304A0FFF */  andi      $t2, $v0, 0xfff
/* 32C53C E000E42C 006A1825 */  or        $v1, $v1, $t2
/* 32C540 E000E430 11A00010 */  beqz      $t5, .LE000E474
/* 32C544 E000E434 ACC30024 */   sw       $v1, 0x24($a2)
/* 32C548 E000E438 24C20030 */  addiu     $v0, $a2, 0x30
/* 32C54C E000E43C AD020000 */  sw        $v0, ($t0)
/* 32C550 E000E440 00041080 */  sll       $v0, $a0, 2
/* 32C554 E000E444 30420FFF */  andi      $v0, $v0, 0xfff
/* 32C558 E000E448 00021300 */  sll       $v0, $v0, 0xc
/* 32C55C E000E44C 004B1025 */  or        $v0, $v0, $t3
/* 32C560 E000E450 ACC20028 */  sw        $v0, 0x28($a2)
/* 32C564 E000E454 00091040 */  sll       $v0, $t1, 1
/* 32C568 E000E458 00A21021 */  addu      $v0, $a1, $v0
/* 32C56C E000E45C 2442FFFF */  addiu     $v0, $v0, -1
/* 32C570 E000E460 00021080 */  sll       $v0, $v0, 2
/* 32C574 E000E464 30420FFF */  andi      $v0, $v0, 0xfff
/* 32C578 E000E468 00021300 */  sll       $v0, $v0, 0xc
/* 32C57C E000E46C 0800392C */  j         .LE000E4B0
/* 32C580 E000E470 3C030100 */   lui      $v1, 0x100
.LE000E474:
/* 32C584 E000E474 24C20030 */  addiu     $v0, $a2, 0x30
/* 32C588 E000E478 AD020000 */  sw        $v0, ($t0)
/* 32C58C E000E47C 00041080 */  sll       $v0, $a0, 2
/* 32C590 E000E480 30420FFF */  andi      $v0, $v0, 0xfff
/* 32C594 E000E484 00021300 */  sll       $v0, $v0, 0xc
/* 32C598 E000E488 004B1025 */  or        $v0, $v0, $t3
/* 32C59C E000E48C ACC20028 */  sw        $v0, 0x28($a2)
/* 32C5A0 E000E490 00091040 */  sll       $v0, $t1, 1
/* 32C5A4 E000E494 00A21021 */  addu      $v0, $a1, $v0
/* 32C5A8 E000E498 2442FFFF */  addiu     $v0, $v0, -1
/* 32C5AC E000E49C 00021080 */  sll       $v0, $v0, 2
/* 32C5B0 E000E4A0 30420FFF */  andi      $v0, $v0, 0xfff
/* 32C5B4 E000E4A4 00021300 */  sll       $v0, $v0, 0xc
/* 32C5B8 E000E4A8 3C030100 */  lui       $v1, 0x100
/* 32C5BC E000E4AC 01431825 */  or        $v1, $t2, $v1
.LE000E4B0:
/* 32C5C0 E000E4B0 00431025 */  or        $v0, $v0, $v1
/* 32C5C4 E000E4B4 ACC2002C */  sw        $v0, 0x2c($a2)
/* 32C5C8 E000E4B8 8EE20008 */  lw        $v0, 8($s7)
/* 32C5CC E000E4BC 18400051 */  blez      $v0, .LE000E604
/* 32C5D0 E000E4C0 0000882D */   daddu    $s1, $zero, $zero
/* 32C5D4 E000E4C4 27B40058 */  addiu     $s4, $sp, 0x58
/* 32C5D8 E000E4C8 4480A000 */  mtc1      $zero, $f20
/* 32C5DC E000E4CC 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 32C5E0 E000E4D0 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 32C5E4 E000E4D4 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 32C5E8 E000E4D8 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 32C5EC E000E4DC 3C130001 */  lui       $s3, 1
/* 32C5F0 E000E4E0 36731630 */  ori       $s3, $s3, 0x1630
/* 32C5F4 E000E4E4 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 32C5F8 E000E4E8 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 32C5FC E000E4EC 24F00010 */  addiu     $s0, $a3, 0x10
.LE000E4F0:
/* 32C600 E000E4F0 27A40018 */  addiu     $a0, $sp, 0x18
/* 32C604 E000E4F4 26310001 */  addiu     $s1, $s1, 1
/* 32C608 E000E4F8 8E05FFF8 */  lw        $a1, -8($s0)
/* 32C60C E000E4FC 8E06FFFC */  lw        $a2, -4($s0)
/* 32C610 E000E500 8E070000 */  lw        $a3, ($s0)
/* 32C614 E000E504 0C080108 */  jal       shim_guTranslateF
/* 32C618 E000E508 26100078 */   addiu    $s0, $s0, 0x78
/* 32C61C E000E50C 3C0E800B */  lui       $t6, %hi(gCameras)
/* 32C620 E000E510 25CE1D80 */  addiu     $t6, $t6, %lo(gCameras)
/* 32C624 E000E514 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 32C628 E000E518 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 32C62C E000E51C 4406A000 */  mfc1      $a2, $f20
/* 32C630 E000E520 00031080 */  sll       $v0, $v1, 2
/* 32C634 E000E524 00431021 */  addu      $v0, $v0, $v1
/* 32C638 E000E528 00021080 */  sll       $v0, $v0, 2
/* 32C63C E000E52C 00431023 */  subu      $v0, $v0, $v1
/* 32C640 E000E530 000218C0 */  sll       $v1, $v0, 3
/* 32C644 E000E534 00431021 */  addu      $v0, $v0, $v1
/* 32C648 E000E538 000210C0 */  sll       $v0, $v0, 3
/* 32C64C E000E53C 004E1021 */  addu      $v0, $v0, $t6
/* 32C650 E000E540 C440006C */  lwc1      $f0, 0x6c($v0)
/* 32C654 E000E544 3C073F80 */  lui       $a3, 0x3f80
/* 32C658 E000E548 46000007 */  neg.s     $f0, $f0
/* 32C65C E000E54C 44050000 */  mfc1      $a1, $f0
/* 32C660 E000E550 0280202D */  daddu     $a0, $s4, $zero
/* 32C664 E000E554 0C080104 */  jal       shim_guRotateF
/* 32C668 E000E558 E7B40010 */   swc1     $f20, 0x10($sp)
/* 32C66C E000E55C 0280202D */  daddu     $a0, $s4, $zero
/* 32C670 E000E560 27A50018 */  addiu     $a1, $sp, 0x18
/* 32C674 E000E564 0C080114 */  jal       shim_guMtxCatF
/* 32C678 E000E568 00A0302D */   daddu    $a2, $a1, $zero
/* 32C67C E000E56C 27A40018 */  addiu     $a0, $sp, 0x18
/* 32C680 E000E570 96A50000 */  lhu       $a1, ($s5)
/* 32C684 E000E574 8EC20000 */  lw        $v0, ($s6)
/* 32C688 E000E578 00052980 */  sll       $a1, $a1, 6
/* 32C68C E000E57C 00B32821 */  addu      $a1, $a1, $s3
/* 32C690 E000E580 0C080118 */  jal       shim_guMtxF2L
/* 32C694 E000E584 00452821 */   addu     $a1, $v0, $a1
/* 32C698 E000E588 3C02DA38 */  lui       $v0, 0xda38
/* 32C69C E000E58C 34420002 */  ori       $v0, $v0, 2
/* 32C6A0 E000E590 3C06D838 */  lui       $a2, 0xd838
/* 32C6A4 E000E594 34C60002 */  ori       $a2, $a2, 2
/* 32C6A8 E000E598 8E440000 */  lw        $a0, ($s2)
/* 32C6AC E000E59C 96A30000 */  lhu       $v1, ($s5)
/* 32C6B0 E000E5A0 0080282D */  daddu     $a1, $a0, $zero
/* 32C6B4 E000E5A4 24840008 */  addiu     $a0, $a0, 8
/* 32C6B8 E000E5A8 AE440000 */  sw        $a0, ($s2)
/* 32C6BC E000E5AC ACA20000 */  sw        $v0, ($a1)
/* 32C6C0 E000E5B0 24620001 */  addiu     $v0, $v1, 1
/* 32C6C4 E000E5B4 3063FFFF */  andi      $v1, $v1, 0xffff
/* 32C6C8 E000E5B8 00031980 */  sll       $v1, $v1, 6
/* 32C6CC E000E5BC A6A20000 */  sh        $v0, ($s5)
/* 32C6D0 E000E5C0 8EC20000 */  lw        $v0, ($s6)
/* 32C6D4 E000E5C4 00731821 */  addu      $v1, $v1, $s3
/* 32C6D8 E000E5C8 00431021 */  addu      $v0, $v0, $v1
/* 32C6DC E000E5CC ACA20004 */  sw        $v0, 4($a1)
/* 32C6E0 E000E5D0 24820008 */  addiu     $v0, $a0, 8
/* 32C6E4 E000E5D4 AE420000 */  sw        $v0, ($s2)
/* 32C6E8 E000E5D8 3C02DE00 */  lui       $v0, 0xde00
/* 32C6EC E000E5DC AC820000 */  sw        $v0, ($a0)
/* 32C6F0 E000E5E0 24020040 */  addiu     $v0, $zero, 0x40
/* 32C6F4 E000E5E4 AC9E0004 */  sw        $fp, 4($a0)
/* 32C6F8 E000E5E8 AC860008 */  sw        $a2, 8($a0)
/* 32C6FC E000E5EC AC82000C */  sw        $v0, 0xc($a0)
/* 32C700 E000E5F0 8EE20008 */  lw        $v0, 8($s7)
/* 32C704 E000E5F4 24840010 */  addiu     $a0, $a0, 0x10
/* 32C708 E000E5F8 0222102A */  slt       $v0, $s1, $v0
/* 32C70C E000E5FC 1440FFBC */  bnez      $v0, .LE000E4F0
/* 32C710 E000E600 AE440000 */   sw       $a0, ($s2)
.LE000E604:
/* 32C714 E000E604 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 32C718 E000E608 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 32C71C E000E60C 8C620000 */  lw        $v0, ($v1)
/* 32C720 E000E610 0040202D */  daddu     $a0, $v0, $zero
/* 32C724 E000E614 24420008 */  addiu     $v0, $v0, 8
/* 32C728 E000E618 AC620000 */  sw        $v0, ($v1)
/* 32C72C E000E61C 3C02E700 */  lui       $v0, 0xe700
/* 32C730 E000E620 AC820000 */  sw        $v0, ($a0)
/* 32C734 E000E624 AC800004 */  sw        $zero, 4($a0)
/* 32C738 E000E628 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 32C73C E000E62C 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 32C740 E000E630 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 32C744 E000E634 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 32C748 E000E638 8FB500AC */  lw        $s5, 0xac($sp)
/* 32C74C E000E63C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 32C750 E000E640 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 32C754 E000E644 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 32C758 E000E648 8FB1009C */  lw        $s1, 0x9c($sp)
/* 32C75C E000E64C 8FB00098 */  lw        $s0, 0x98($sp)
/* 32C760 E000E650 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 32C764 E000E654 03E00008 */  jr        $ra
/* 32C768 E000E658 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 32C76C E000E65C 00000000 */  nop
