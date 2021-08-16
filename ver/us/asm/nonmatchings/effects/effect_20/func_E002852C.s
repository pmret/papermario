.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002852C
/* 33D31C E002852C 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* 33D320 E0028530 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 33D324 E0028534 0080B82D */  daddu     $s7, $a0, $zero
/* 33D328 E0028538 3C02DB06 */  lui       $v0, 0xdb06
/* 33D32C E002853C 34420024 */  ori       $v0, $v0, 0x24
/* 33D330 E0028540 3C061464 */  lui       $a2, 0x1464
/* 33D334 E0028544 34C61400 */  ori       $a2, $a2, 0x1400
/* 33D338 E0028548 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 33D33C E002854C 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 33D340 E0028550 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 33D344 E0028554 AFBF00F8 */  sw        $ra, 0xf8($sp)
/* 33D348 E0028558 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 33D34C E002855C AFB500EC */  sw        $s5, 0xec($sp)
/* 33D350 E0028560 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 33D354 E0028564 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 33D358 E0028568 AFB100DC */  sw        $s1, 0xdc($sp)
/* 33D35C E002856C AFB000D8 */  sw        $s0, 0xd8($sp)
/* 33D360 E0028570 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 33D364 E0028574 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 33D368 E0028578 8E650000 */  lw        $a1, ($s3)
/* 33D36C E002857C 8EF0000C */  lw        $s0, 0xc($s7)
/* 33D370 E0028580 00A0202D */  daddu     $a0, $a1, $zero
/* 33D374 E0028584 24A50008 */  addiu     $a1, $a1, 8
/* 33D378 E0028588 AE650000 */  sw        $a1, ($s3)
/* 33D37C E002858C AC820000 */  sw        $v0, ($a0)
/* 33D380 E0028590 24A20008 */  addiu     $v0, $a1, 8
/* 33D384 E0028594 AE620000 */  sw        $v0, ($s3)
/* 33D388 E0028598 8EE30010 */  lw        $v1, 0x10($s7)
/* 33D38C E002859C 24A20010 */  addiu     $v0, $a1, 0x10
/* 33D390 E00285A0 AE620000 */  sw        $v0, ($s3)
/* 33D394 E00285A4 8C62001C */  lw        $v0, 0x1c($v1)
/* 33D398 E00285A8 3C038000 */  lui       $v1, 0x8000
/* 33D39C E00285AC 00431021 */  addu      $v0, $v0, $v1
/* 33D3A0 E00285B0 AC820004 */  sw        $v0, 4($a0)
/* 33D3A4 E00285B4 3C02DE00 */  lui       $v0, 0xde00
/* 33D3A8 E00285B8 ACA20000 */  sw        $v0, ($a1)
/* 33D3AC E00285BC 3C020900 */  lui       $v0, 0x900
/* 33D3B0 E00285C0 24421180 */  addiu     $v0, $v0, 0x1180
/* 33D3B4 E00285C4 ACA20004 */  sw        $v0, 4($a1)
/* 33D3B8 E00285C8 3C02FA00 */  lui       $v0, 0xfa00
/* 33D3BC E00285CC ACA20008 */  sw        $v0, 8($a1)
/* 33D3C0 E00285D0 92020027 */  lbu       $v0, 0x27($s0)
/* 33D3C4 E00285D4 24120001 */  addiu     $s2, $zero, 1
/* 33D3C8 E00285D8 00461025 */  or        $v0, $v0, $a2
/* 33D3CC E00285DC ACA2000C */  sw        $v0, 0xc($a1)
/* 33D3D0 E00285E0 8E050004 */  lw        $a1, 4($s0)
/* 33D3D4 E00285E4 8E060008 */  lw        $a2, 8($s0)
/* 33D3D8 E00285E8 8E07000C */  lw        $a3, 0xc($s0)
/* 33D3DC E00285EC 0C080108 */  jal       func_E0200420
/* 33D3E0 E00285F0 27A40018 */   addiu    $a0, $sp, 0x18
/* 33D3E4 E00285F4 27B10058 */  addiu     $s1, $sp, 0x58
/* 33D3E8 E00285F8 4480A000 */  mtc1      $zero, $f20
/* 33D3EC E00285FC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 33D3F0 E0028600 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 33D3F4 E0028604 3C013F80 */  lui       $at, 0x3f80
/* 33D3F8 E0028608 4481B000 */  mtc1      $at, $f22
/* 33D3FC E002860C 00031080 */  sll       $v0, $v1, 2
/* 33D400 E0028610 00431021 */  addu      $v0, $v0, $v1
/* 33D404 E0028614 00021080 */  sll       $v0, $v0, 2
/* 33D408 E0028618 00431023 */  subu      $v0, $v0, $v1
/* 33D40C E002861C 000218C0 */  sll       $v1, $v0, 3
/* 33D410 E0028620 00431021 */  addu      $v0, $v0, $v1
/* 33D414 E0028624 000210C0 */  sll       $v0, $v0, 3
/* 33D418 E0028628 4406A000 */  mfc1      $a2, $f20
/* 33D41C E002862C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 33D420 E0028630 00220821 */  addu      $at, $at, $v0
/* 33D424 E0028634 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 33D428 E0028638 4407B000 */  mfc1      $a3, $f22
/* 33D42C E002863C 46000007 */  neg.s     $f0, $f0
/* 33D430 E0028640 44050000 */  mfc1      $a1, $f0
/* 33D434 E0028644 0220202D */  daddu     $a0, $s1, $zero
/* 33D438 E0028648 0C080104 */  jal       func_E0200410
/* 33D43C E002864C E7B40010 */   swc1     $f20, 0x10($sp)
/* 33D440 E0028650 0220202D */  daddu     $a0, $s1, $zero
/* 33D444 E0028654 27A50018 */  addiu     $a1, $sp, 0x18
/* 33D448 E0028658 0C080114 */  jal       func_E0200450
/* 33D44C E002865C 27A60098 */   addiu    $a2, $sp, 0x98
/* 33D450 E0028660 8EE20008 */  lw        $v0, 8($s7)
/* 33D454 E0028664 0242102A */  slt       $v0, $s2, $v0
/* 33D458 E0028668 1040004E */  beqz      $v0, .LE00287A4
/* 33D45C E002866C 26100030 */   addiu    $s0, $s0, 0x30
/* 33D460 E0028670 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 33D464 E0028674 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 33D468 E0028678 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 33D46C E002867C 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 33D470 E0028680 3C140001 */  lui       $s4, 1
/* 33D474 E0028684 36941630 */  ori       $s4, $s4, 0x1630
/* 33D478 E0028688 26100020 */  addiu     $s0, $s0, 0x20
.LE002868C:
/* 33D47C E002868C 0220202D */  daddu     $a0, $s1, $zero
/* 33D480 E0028690 8E05FFE4 */  lw        $a1, -0x1c($s0)
/* 33D484 E0028694 8E06FFE8 */  lw        $a2, -0x18($s0)
/* 33D488 E0028698 8E07FFEC */  lw        $a3, -0x14($s0)
/* 33D48C E002869C 0C080108 */  jal       func_E0200420
/* 33D490 E00286A0 26520001 */   addiu    $s2, $s2, 1
/* 33D494 E00286A4 0220202D */  daddu     $a0, $s1, $zero
/* 33D498 E00286A8 27A50098 */  addiu     $a1, $sp, 0x98
/* 33D49C E00286AC 0C080114 */  jal       func_E0200450
/* 33D4A0 E00286B0 27A60018 */   addiu    $a2, $sp, 0x18
/* 33D4A4 E00286B4 E7B60010 */  swc1      $f22, 0x10($sp)
/* 33D4A8 E00286B8 8E05FFF8 */  lw        $a1, -8($s0)
/* 33D4AC E00286BC 4406A000 */  mfc1      $a2, $f20
/* 33D4B0 E00286C0 4407A000 */  mfc1      $a3, $f20
/* 33D4B4 E00286C4 0C080104 */  jal       func_E0200410
/* 33D4B8 E00286C8 0220202D */   daddu    $a0, $s1, $zero
/* 33D4BC E00286CC 0220202D */  daddu     $a0, $s1, $zero
/* 33D4C0 E00286D0 27A50018 */  addiu     $a1, $sp, 0x18
/* 33D4C4 E00286D4 0C080114 */  jal       func_E0200450
/* 33D4C8 E00286D8 00A0302D */   daddu    $a2, $a1, $zero
/* 33D4CC E00286DC 0220202D */  daddu     $a0, $s1, $zero
/* 33D4D0 E00286E0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 33D4D4 E00286E4 8E050000 */  lw        $a1, ($s0)
/* 33D4D8 E00286E8 4406A000 */  mfc1      $a2, $f20
/* 33D4DC E00286EC 4407B000 */  mfc1      $a3, $f22
/* 33D4E0 E00286F0 0C080104 */  jal       func_E0200410
/* 33D4E4 E00286F4 26100030 */   addiu    $s0, $s0, 0x30
/* 33D4E8 E00286F8 0220202D */  daddu     $a0, $s1, $zero
/* 33D4EC E00286FC 27A50018 */  addiu     $a1, $sp, 0x18
/* 33D4F0 E0028700 0C080114 */  jal       func_E0200450
/* 33D4F4 E0028704 00A0302D */   daddu    $a2, $a1, $zero
/* 33D4F8 E0028708 27A40018 */  addiu     $a0, $sp, 0x18
/* 33D4FC E002870C 96A50000 */  lhu       $a1, ($s5)
/* 33D500 E0028710 8EC20000 */  lw        $v0, ($s6)
/* 33D504 E0028714 00052980 */  sll       $a1, $a1, 6
/* 33D508 E0028718 00B42821 */  addu      $a1, $a1, $s4
/* 33D50C E002871C 0C080118 */  jal       func_E0200460
/* 33D510 E0028720 00452821 */   addu     $a1, $v0, $a1
/* 33D514 E0028724 3C06D838 */  lui       $a2, 0xd838
/* 33D518 E0028728 8E640000 */  lw        $a0, ($s3)
/* 33D51C E002872C 34C60002 */  ori       $a2, $a2, 2
/* 33D520 E0028730 0080282D */  daddu     $a1, $a0, $zero
/* 33D524 E0028734 24840008 */  addiu     $a0, $a0, 8
/* 33D528 E0028738 AE640000 */  sw        $a0, ($s3)
/* 33D52C E002873C 96A20000 */  lhu       $v0, ($s5)
/* 33D530 E0028740 3C03DA38 */  lui       $v1, 0xda38
/* 33D534 E0028744 ACA30000 */  sw        $v1, ($a1)
/* 33D538 E0028748 24430001 */  addiu     $v1, $v0, 1
/* 33D53C E002874C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 33D540 E0028750 00021180 */  sll       $v0, $v0, 6
/* 33D544 E0028754 A6A30000 */  sh        $v1, ($s5)
/* 33D548 E0028758 8EC30000 */  lw        $v1, ($s6)
/* 33D54C E002875C 00541021 */  addu      $v0, $v0, $s4
/* 33D550 E0028760 00621821 */  addu      $v1, $v1, $v0
/* 33D554 E0028764 24820008 */  addiu     $v0, $a0, 8
/* 33D558 E0028768 ACA30004 */  sw        $v1, 4($a1)
/* 33D55C E002876C AE620000 */  sw        $v0, ($s3)
/* 33D560 E0028770 3C02DE00 */  lui       $v0, 0xde00
/* 33D564 E0028774 AC820000 */  sw        $v0, ($a0)
/* 33D568 E0028778 3C020900 */  lui       $v0, 0x900
/* 33D56C E002877C 24421230 */  addiu     $v0, $v0, 0x1230
/* 33D570 E0028780 AC820004 */  sw        $v0, 4($a0)
/* 33D574 E0028784 24020040 */  addiu     $v0, $zero, 0x40
/* 33D578 E0028788 AC860008 */  sw        $a2, 8($a0)
/* 33D57C E002878C AC82000C */  sw        $v0, 0xc($a0)
/* 33D580 E0028790 8EE20008 */  lw        $v0, 8($s7)
/* 33D584 E0028794 24840010 */  addiu     $a0, $a0, 0x10
/* 33D588 E0028798 0242102A */  slt       $v0, $s2, $v0
/* 33D58C E002879C 1440FFBB */  bnez      $v0, .LE002868C
/* 33D590 E00287A0 AE640000 */   sw       $a0, ($s3)
.LE00287A4:
/* 33D594 E00287A4 8FBF00F8 */  lw        $ra, 0xf8($sp)
/* 33D598 E00287A8 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 33D59C E00287AC 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 33D5A0 E00287B0 8FB500EC */  lw        $s5, 0xec($sp)
/* 33D5A4 E00287B4 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 33D5A8 E00287B8 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 33D5AC E00287BC 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 33D5B0 E00287C0 8FB100DC */  lw        $s1, 0xdc($sp)
/* 33D5B4 E00287C4 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 33D5B8 E00287C8 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 33D5BC E00287CC D7B40100 */  ldc1      $f20, 0x100($sp)
/* 33D5C0 E00287D0 03E00008 */  jr        $ra
/* 33D5C4 E00287D4 27BD0110 */   addiu    $sp, $sp, 0x110
/* 33D5C8 E00287D8 00000000 */  nop
/* 33D5CC E00287DC 00000000 */  nop
