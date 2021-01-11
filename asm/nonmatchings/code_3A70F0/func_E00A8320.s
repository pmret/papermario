.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A8320
/* 3A7410 E00A8320 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 3A7414 E00A8324 0080302D */  daddu     $a2, $a0, $zero
/* 3A7418 E00A8328 3C07DB06 */  lui       $a3, 0xdb06
/* 3A741C E00A832C 34E70024 */  ori       $a3, $a3, 0x24
/* 3A7420 E00A8330 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A7424 E00A8334 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3A7428 E00A8338 3C120001 */  lui       $s2, 1
/* 3A742C E00A833C 36521630 */  ori       $s2, $s2, 0x1630
/* 3A7430 E00A8340 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3A7434 E00A8344 0000A02D */  daddu     $s4, $zero, $zero
/* 3A7438 E00A8348 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3A743C E00A834C 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 3A7440 E00A8350 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 3A7444 E00A8354 0040F02D */  daddu     $fp, $v0, $zero
/* 3A7448 E00A8358 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 3A744C E00A835C 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 3A7450 E00A8360 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3A7454 E00A8364 0040B02D */  daddu     $s6, $v0, $zero
/* 3A7458 E00A8368 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3A745C E00A836C 3C170001 */  lui       $s7, 1
/* 3A7460 E00A8370 36F71630 */  ori       $s7, $s7, 0x1630
/* 3A7464 E00A8374 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3A7468 E00A8378 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3A746C E00A837C AFB500AC */  sw        $s5, 0xac($sp)
/* 3A7470 E00A8380 0040A82D */  daddu     $s5, $v0, $zero
/* 3A7474 E00A8384 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 3A7478 E00A8388 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3A747C E00A838C AFB1009C */  sw        $s1, 0x9c($sp)
/* 3A7480 E00A8390 AFB00098 */  sw        $s0, 0x98($sp)
/* 3A7484 E00A8394 8C480000 */  lw        $t0, ($v0)
/* 3A7488 E00A8398 3C02E700 */  lui       $v0, 0xe700
/* 3A748C E00A839C 8CC5000C */  lw        $a1, 0xc($a2)
/* 3A7490 E00A83A0 0100182D */  daddu     $v1, $t0, $zero
/* 3A7494 E00A83A4 8CB00018 */  lw        $s0, 0x18($a1)
/* 3A7498 E00A83A8 25080008 */  addiu     $t0, $t0, 8
/* 3A749C E00A83AC AC620000 */  sw        $v0, ($v1)
/* 3A74A0 E00A83B0 AC600004 */  sw        $zero, 4($v1)
/* 3A74A4 E00A83B4 AD070000 */  sw        $a3, ($t0)
/* 3A74A8 E00A83B8 8CC20010 */  lw        $v0, 0x10($a2)
/* 3A74AC E00A83BC 00A0982D */  daddu     $s3, $a1, $zero
/* 3A74B0 E00A83C0 AEA80000 */  sw        $t0, ($s5)
/* 3A74B4 E00A83C4 8C42001C */  lw        $v0, 0x1c($v0)
/* 3A74B8 E00A83C8 3C038000 */  lui       $v1, 0x8000
/* 3A74BC E00A83CC 00431021 */  addu      $v0, $v0, $v1
/* 3A74C0 E00A83D0 AD020004 */  sw        $v0, 4($t0)
/* 3A74C4 E00A83D4 8E65000C */  lw        $a1, 0xc($s3)
/* 3A74C8 E00A83D8 8E660010 */  lw        $a2, 0x10($s3)
/* 3A74CC E00A83DC 8E670014 */  lw        $a3, 0x14($s3)
/* 3A74D0 E00A83E0 25080008 */  addiu     $t0, $t0, 8
/* 3A74D4 E00A83E4 0C080108 */  jal       func_E0200420
/* 3A74D8 E00A83E8 AEA80000 */   sw       $t0, ($s5)
/* 3A74DC E00A83EC 27B10058 */  addiu     $s1, $sp, 0x58
/* 3A74E0 E00A83F0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3A74E4 E00A83F4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3A74E8 E00A83F8 44800000 */  mtc1      $zero, $f0
/* 3A74EC E00A83FC 00031080 */  sll       $v0, $v1, 2
/* 3A74F0 E00A8400 00431021 */  addu      $v0, $v0, $v1
/* 3A74F4 E00A8404 00021080 */  sll       $v0, $v0, 2
/* 3A74F8 E00A8408 00431023 */  subu      $v0, $v0, $v1
/* 3A74FC E00A840C 000218C0 */  sll       $v1, $v0, 3
/* 3A7500 E00A8410 00431021 */  addu      $v0, $v0, $v1
/* 3A7504 E00A8414 000210C0 */  sll       $v0, $v0, 3
/* 3A7508 E00A8418 44060000 */  mfc1      $a2, $f0
/* 3A750C E00A841C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3A7510 E00A8420 00220821 */  addu      $at, $at, $v0
/* 3A7514 E00A8424 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 3A7518 E00A8428 3C073F80 */  lui       $a3, 0x3f80
/* 3A751C E00A842C 46000007 */  neg.s     $f0, $f0
/* 3A7520 E00A8430 44050000 */  mfc1      $a1, $f0
/* 3A7524 E00A8434 0220202D */  daddu     $a0, $s1, $zero
/* 3A7528 E00A8438 0C080104 */  jal       func_E0200410
/* 3A752C E00A843C AFA60010 */   sw       $a2, 0x10($sp)
/* 3A7530 E00A8440 0220202D */  daddu     $a0, $s1, $zero
/* 3A7534 E00A8444 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A7538 E00A8448 0C080114 */  jal       func_E0200450
/* 3A753C E00A844C 00A0302D */   daddu    $a2, $a1, $zero
/* 3A7540 E00A8450 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A7544 E00A8454 96C50000 */  lhu       $a1, ($s6)
/* 3A7548 E00A8458 8FC20000 */  lw        $v0, ($fp)
/* 3A754C E00A845C 00052980 */  sll       $a1, $a1, 6
/* 3A7550 E00A8460 00B22821 */  addu      $a1, $a1, $s2
/* 3A7554 E00A8464 0C080118 */  jal       func_E0200460
/* 3A7558 E00A8468 00452821 */   addu     $a1, $v0, $a1
/* 3A755C E00A846C 3C03DA38 */  lui       $v1, 0xda38
/* 3A7560 E00A8470 34630002 */  ori       $v1, $v1, 2
/* 3A7564 E00A8474 321000FF */  andi      $s0, $s0, 0xff
/* 3A7568 E00A8478 8EA40000 */  lw        $a0, ($s5)
/* 3A756C E00A847C 96C20000 */  lhu       $v0, ($s6)
/* 3A7570 E00A8480 0080282D */  daddu     $a1, $a0, $zero
/* 3A7574 E00A8484 24840008 */  addiu     $a0, $a0, 8
/* 3A7578 E00A8488 AEA40000 */  sw        $a0, ($s5)
/* 3A757C E00A848C ACA30000 */  sw        $v1, ($a1)
/* 3A7580 E00A8490 24430001 */  addiu     $v1, $v0, 1
/* 3A7584 E00A8494 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A7588 E00A8498 00021180 */  sll       $v0, $v0, 6
/* 3A758C E00A849C A6C30000 */  sh        $v1, ($s6)
/* 3A7590 E00A84A0 8FC30000 */  lw        $v1, ($fp)
/* 3A7594 E00A84A4 00521021 */  addu      $v0, $v0, $s2
/* 3A7598 E00A84A8 00621821 */  addu      $v1, $v1, $v0
/* 3A759C E00A84AC 24820008 */  addiu     $v0, $a0, 8
/* 3A75A0 E00A84B0 ACA30004 */  sw        $v1, 4($a1)
/* 3A75A4 E00A84B4 AEA20000 */  sw        $v0, ($s5)
/* 3A75A8 E00A84B8 3C02FA00 */  lui       $v0, 0xfa00
/* 3A75AC E00A84BC AC820000 */  sw        $v0, ($a0)
/* 3A75B0 E00A84C0 00101600 */  sll       $v0, $s0, 0x18
/* 3A75B4 E00A84C4 00101C00 */  sll       $v1, $s0, 0x10
/* 3A75B8 E00A84C8 00431025 */  or        $v0, $v0, $v1
/* 3A75BC E00A84CC 00108200 */  sll       $s0, $s0, 8
/* 3A75C0 E00A84D0 00501025 */  or        $v0, $v0, $s0
/* 3A75C4 E00A84D4 344200FF */  ori       $v0, $v0, 0xff
/* 3A75C8 E00A84D8 AC820004 */  sw        $v0, 4($a0)
/* 3A75CC E00A84DC 24820010 */  addiu     $v0, $a0, 0x10
/* 3A75D0 E00A84E0 AEA20000 */  sw        $v0, ($s5)
/* 3A75D4 E00A84E4 3C02DE00 */  lui       $v0, 0xde00
/* 3A75D8 E00A84E8 AC820008 */  sw        $v0, 8($a0)
/* 3A75DC E00A84EC 3C020900 */  lui       $v0, 0x900
/* 3A75E0 E00A84F0 24423110 */  addiu     $v0, $v0, 0x3110
/* 3A75E4 E00A84F4 AC82000C */  sw        $v0, 0xc($a0)
.LE00A84F8:
/* 3A75E8 E00A84F8 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A75EC E00A84FC 0000382D */  daddu     $a3, $zero, $zero
/* 3A75F0 E00A8500 8E6500BC */  lw        $a1, 0xbc($s3)
/* 3A75F4 E00A8504 8E6600E4 */  lw        $a2, 0xe4($s3)
/* 3A75F8 E00A8508 26730004 */  addiu     $s3, $s3, 4
/* 3A75FC E00A850C 00148080 */  sll       $s0, $s4, 2
/* 3A7600 E00A8510 0C080108 */  jal       func_E0200420
/* 3A7604 E00A8514 26940001 */   addiu    $s4, $s4, 1
/* 3A7608 E00A8518 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A760C E00A851C 96C50000 */  lhu       $a1, ($s6)
/* 3A7610 E00A8520 8FC20000 */  lw        $v0, ($fp)
/* 3A7614 E00A8524 00052980 */  sll       $a1, $a1, 6
/* 3A7618 E00A8528 00B72821 */  addu      $a1, $a1, $s7
/* 3A761C E00A852C 0C080118 */  jal       func_E0200460
/* 3A7620 E00A8530 00452821 */   addu     $a1, $v0, $a1
/* 3A7624 E00A8534 3C06D838 */  lui       $a2, 0xd838
/* 3A7628 E00A8538 8EA40000 */  lw        $a0, ($s5)
/* 3A762C E00A853C 34C60002 */  ori       $a2, $a2, 2
/* 3A7630 E00A8540 0080282D */  daddu     $a1, $a0, $zero
/* 3A7634 E00A8544 24840008 */  addiu     $a0, $a0, 8
/* 3A7638 E00A8548 AEA40000 */  sw        $a0, ($s5)
/* 3A763C E00A854C 96C20000 */  lhu       $v0, ($s6)
/* 3A7640 E00A8550 3C03DA38 */  lui       $v1, 0xda38
/* 3A7644 E00A8554 ACA30000 */  sw        $v1, ($a1)
/* 3A7648 E00A8558 24430001 */  addiu     $v1, $v0, 1
/* 3A764C E00A855C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A7650 E00A8560 00021180 */  sll       $v0, $v0, 6
/* 3A7654 E00A8564 A6C30000 */  sh        $v1, ($s6)
/* 3A7658 E00A8568 8FC30000 */  lw        $v1, ($fp)
/* 3A765C E00A856C 00571021 */  addu      $v0, $v0, $s7
/* 3A7660 E00A8570 00621821 */  addu      $v1, $v1, $v0
/* 3A7664 E00A8574 24820008 */  addiu     $v0, $a0, 8
/* 3A7668 E00A8578 ACA30004 */  sw        $v1, 4($a1)
/* 3A766C E00A857C AEA20000 */  sw        $v0, ($s5)
/* 3A7670 E00A8580 3C02DE00 */  lui       $v0, 0xde00
/* 3A7674 E00A8584 AC820000 */  sw        $v0, ($a0)
/* 3A7678 E00A8588 24820010 */  addiu     $v0, $a0, 0x10
/* 3A767C E00A858C 3C03E00B */  lui       $v1, %hi(D_E00A8620)
/* 3A7680 E00A8590 00701821 */  addu      $v1, $v1, $s0
/* 3A7684 E00A8594 8C638620 */  lw        $v1, %lo(D_E00A8620)($v1)
/* 3A7688 E00A8598 24050040 */  addiu     $a1, $zero, 0x40
/* 3A768C E00A859C AEA20000 */  sw        $v0, ($s5)
/* 3A7690 E00A85A0 2A82000A */  slti      $v0, $s4, 0xa
/* 3A7694 E00A85A4 AC860008 */  sw        $a2, 8($a0)
/* 3A7698 E00A85A8 AC85000C */  sw        $a1, 0xc($a0)
/* 3A769C E00A85AC 1440FFD2 */  bnez      $v0, .LE00A84F8
/* 3A76A0 E00A85B0 AC830004 */   sw       $v1, 4($a0)
/* 3A76A4 E00A85B4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3A76A8 E00A85B8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3A76AC E00A85BC 8C820000 */  lw        $v0, ($a0)
/* 3A76B0 E00A85C0 0040182D */  daddu     $v1, $v0, $zero
/* 3A76B4 E00A85C4 24420008 */  addiu     $v0, $v0, 8
/* 3A76B8 E00A85C8 AC820000 */  sw        $v0, ($a0)
/* 3A76BC E00A85CC AC660000 */  sw        $a2, ($v1)
/* 3A76C0 E00A85D0 AC650004 */  sw        $a1, 4($v1)
/* 3A76C4 E00A85D4 24430008 */  addiu     $v1, $v0, 8
/* 3A76C8 E00A85D8 AC830000 */  sw        $v1, ($a0)
/* 3A76CC E00A85DC 3C03E700 */  lui       $v1, 0xe700
/* 3A76D0 E00A85E0 AC430000 */  sw        $v1, ($v0)
/* 3A76D4 E00A85E4 AC400004 */  sw        $zero, 4($v0)
/* 3A76D8 E00A85E8 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 3A76DC E00A85EC 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 3A76E0 E00A85F0 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3A76E4 E00A85F4 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3A76E8 E00A85F8 8FB500AC */  lw        $s5, 0xac($sp)
/* 3A76EC E00A85FC 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3A76F0 E00A8600 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3A76F4 E00A8604 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3A76F8 E00A8608 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3A76FC E00A860C 8FB00098 */  lw        $s0, 0x98($sp)
/* 3A7700 E00A8610 03E00008 */  jr        $ra
/* 3A7704 E00A8614 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 3A7708 E00A8618 00000000 */  nop       
/* 3A770C E00A861C 00000000 */  nop       
