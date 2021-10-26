.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_91_appendGfx
/* 3B7440 E00B62E0 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 3B7444 E00B62E4 0080302D */  daddu     $a2, $a0, $zero
/* 3B7448 E00B62E8 3C07DB06 */  lui       $a3, 0xdb06
/* 3B744C E00B62EC 34E70024 */  ori       $a3, $a3, 0x24
/* 3B7450 E00B62F0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B7454 E00B62F4 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3B7458 E00B62F8 3C160001 */  lui       $s6, 1
/* 3B745C E00B62FC AFB3009C */  sw        $s3, 0x9c($sp)
/* 3B7460 E00B6300 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3B7464 E00B6304 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3B7468 E00B6308 36D61630 */  ori       $s6, $s6, 0x1630
/* 3B746C E00B630C AFBF00B0 */  sw        $ra, 0xb0($sp)
/* 3B7470 E00B6310 AFB700AC */  sw        $s7, 0xac($sp)
/* 3B7474 E00B6314 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3B7478 E00B6318 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3B747C E00B631C AFB20098 */  sw        $s2, 0x98($sp)
/* 3B7480 E00B6320 AFB10094 */  sw        $s1, 0x94($sp)
/* 3B7484 E00B6324 AFB00090 */  sw        $s0, 0x90($sp)
/* 3B7488 E00B6328 F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* 3B748C E00B632C 8E650000 */  lw        $a1, ($s3)
/* 3B7490 E00B6330 8CD2000C */  lw        $s2, 0xc($a2)
/* 3B7494 E00B6334 3C01E00B */  lui       $at, %hi(D_E00B6768)
/* 3B7498 E00B6338 D4206768 */  ldc1      $f0, %lo(D_E00B6768)($at)
/* 3B749C E00B633C 00A0182D */  daddu     $v1, $a1, $zero
/* 3B74A0 E00B6340 24A50008 */  addiu     $a1, $a1, 8
/* 3B74A4 E00B6344 AE650000 */  sw        $a1, ($s3)
/* 3B74A8 E00B6348 8E570014 */  lw        $s7, 0x14($s2)
/* 3B74AC E00B634C 8E550024 */  lw        $s5, 0x24($s2)
/* 3B74B0 E00B6350 C6540028 */  lwc1      $f20, 0x28($s2)
/* 3B74B4 E00B6354 3C02E700 */  lui       $v0, 0xe700
/* 3B74B8 E00B6358 AC620000 */  sw        $v0, ($v1)
/* 3B74BC E00B635C AC600004 */  sw        $zero, 4($v1)
/* 3B74C0 E00B6360 ACA70000 */  sw        $a3, ($a1)
/* 3B74C4 E00B6364 8CC30010 */  lw        $v1, 0x10($a2)
/* 3B74C8 E00B6368 24A20008 */  addiu     $v0, $a1, 8
/* 3B74CC E00B636C AE620000 */  sw        $v0, ($s3)
/* 3B74D0 E00B6370 8C62001C */  lw        $v0, 0x1c($v1)
/* 3B74D4 E00B6374 3C038000 */  lui       $v1, 0x8000
/* 3B74D8 E00B6378 4600A521 */  cvt.d.s   $f20, $f20
/* 3B74DC E00B637C 4620A502 */  mul.d     $f20, $f20, $f0
/* 3B74E0 E00B6380 00000000 */  nop
/* 3B74E4 E00B6384 00431021 */  addu      $v0, $v0, $v1
/* 3B74E8 E00B6388 3C03800B */  lui       $v1, %hi(gCameras)
/* 3B74EC E00B638C 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3B74F0 E00B6390 ACA20004 */  sw        $v0, 4($a1)
/* 3B74F4 E00B6394 8E450004 */  lw        $a1, 4($s2)
/* 3B74F8 E00B6398 8E460008 */  lw        $a2, 8($s2)
/* 3B74FC E00B639C 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3B7500 E00B63A0 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3B7504 E00B63A4 8E47000C */  lw        $a3, 0xc($s2)
/* 3B7508 E00B63A8 00028880 */  sll       $s1, $v0, 2
/* 3B750C E00B63AC 02228821 */  addu      $s1, $s1, $v0
/* 3B7510 E00B63B0 00118880 */  sll       $s1, $s1, 2
/* 3B7514 E00B63B4 02228823 */  subu      $s1, $s1, $v0
/* 3B7518 E00B63B8 001110C0 */  sll       $v0, $s1, 3
/* 3B751C E00B63BC 02228821 */  addu      $s1, $s1, $v0
/* 3B7520 E00B63C0 001188C0 */  sll       $s1, $s1, 3
/* 3B7524 E00B63C4 02238821 */  addu      $s1, $s1, $v1
/* 3B7528 E00B63C8 0C080108 */  jal       shim_guTranslateF
/* 3B752C E00B63CC 4620A520 */   cvt.s.d  $f20, $f20
/* 3B7530 E00B63D0 27B00050 */  addiu     $s0, $sp, 0x50
/* 3B7534 E00B63D4 4405A000 */  mfc1      $a1, $f20
/* 3B7538 E00B63D8 0200202D */  daddu     $a0, $s0, $zero
/* 3B753C E00B63DC 00A0302D */  daddu     $a2, $a1, $zero
/* 3B7540 E00B63E0 0C080110 */  jal       shim_guScaleF
/* 3B7544 E00B63E4 00A0382D */   daddu    $a3, $a1, $zero
/* 3B7548 E00B63E8 0200202D */  daddu     $a0, $s0, $zero
/* 3B754C E00B63EC 27A50010 */  addiu     $a1, $sp, 0x10
/* 3B7550 E00B63F0 0C080114 */  jal       shim_guMtxCatF
/* 3B7554 E00B63F4 00A0302D */   daddu    $a2, $a1, $zero
/* 3B7558 E00B63F8 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B755C E00B63FC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3B7560 E00B6400 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3B7564 E00B6404 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3B7568 E00B6408 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3B756C E00B640C 96050000 */  lhu       $a1, ($s0)
/* 3B7570 E00B6410 8E820000 */  lw        $v0, ($s4)
/* 3B7574 E00B6414 00052980 */  sll       $a1, $a1, 6
/* 3B7578 E00B6418 00B62821 */  addu      $a1, $a1, $s6
/* 3B757C E00B641C 0C080118 */  jal       shim_guMtxF2L
/* 3B7580 E00B6420 00452821 */   addu     $a1, $v0, $a1
/* 3B7584 E00B6424 3C03DA38 */  lui       $v1, 0xda38
/* 3B7588 E00B6428 34630002 */  ori       $v1, $v1, 2
/* 3B758C E00B642C 3C06DA38 */  lui       $a2, 0xda38
/* 3B7590 E00B6430 34C60001 */  ori       $a2, $a2, 1
/* 3B7594 E00B6434 0000482D */  daddu     $t1, $zero, $zero
/* 3B7598 E00B6438 240F0258 */  addiu     $t7, $zero, 0x258
/* 3B759C E00B643C 240C00FF */  addiu     $t4, $zero, 0xff
/* 3B75A0 E00B6440 240E0400 */  addiu     $t6, $zero, 0x400
/* 3B75A4 E00B6444 240BFFFF */  addiu     $t3, $zero, -1
/* 3B75A8 E00B6448 240AFED4 */  addiu     $t2, $zero, -0x12c
/* 3B75AC E00B644C 32B500FF */  andi      $s5, $s5, 0xff
/* 3B75B0 E00B6450 8E640000 */  lw        $a0, ($s3)
/* 3B75B4 E00B6454 3C014270 */  lui       $at, 0x4270
/* 3B75B8 E00B6458 44812000 */  mtc1      $at, $f4
/* 3B75BC E00B645C 3C014120 */  lui       $at, 0x4120
/* 3B75C0 E00B6460 44811000 */  mtc1      $at, $f2
/* 3B75C4 E00B6464 96020000 */  lhu       $v0, ($s0)
/* 3B75C8 E00B6468 0080282D */  daddu     $a1, $a0, $zero
/* 3B75CC E00B646C 24840008 */  addiu     $a0, $a0, 8
/* 3B75D0 E00B6470 248D0020 */  addiu     $t5, $a0, 0x20
/* 3B75D4 E00B6474 01A0402D */  daddu     $t0, $t5, $zero
/* 3B75D8 E00B6478 2487002F */  addiu     $a3, $a0, 0x2f
/* 3B75DC E00B647C AE640000 */  sw        $a0, ($s3)
/* 3B75E0 E00B6480 ACA30000 */  sw        $v1, ($a1)
/* 3B75E4 E00B6484 24430001 */  addiu     $v1, $v0, 1
/* 3B75E8 E00B6488 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B75EC E00B648C 00021180 */  sll       $v0, $v0, 6
/* 3B75F0 E00B6490 A6030000 */  sh        $v1, ($s0)
/* 3B75F4 E00B6494 8E830000 */  lw        $v1, ($s4)
/* 3B75F8 E00B6498 00561021 */  addu      $v0, $v0, $s6
/* 3B75FC E00B649C 00621821 */  addu      $v1, $v1, $v0
/* 3B7600 E00B64A0 24820008 */  addiu     $v0, $a0, 8
/* 3B7604 E00B64A4 ACA30004 */  sw        $v1, 4($a1)
/* 3B7608 E00B64A8 AE620000 */  sw        $v0, ($s3)
/* 3B760C E00B64AC 24820010 */  addiu     $v0, $a0, 0x10
/* 3B7610 E00B64B0 AC860000 */  sw        $a2, ($a0)
/* 3B7614 E00B64B4 AE620000 */  sw        $v0, ($s3)
/* 3B7618 E00B64B8 8E230204 */  lw        $v1, 0x204($s1)
/* 3B761C E00B64BC 3C02FA00 */  lui       $v0, 0xfa00
/* 3B7620 E00B64C0 AC820008 */  sw        $v0, 8($a0)
/* 3B7624 E00B64C4 AC830004 */  sw        $v1, 4($a0)
/* 3B7628 E00B64C8 9243001B */  lbu       $v1, 0x1b($s2)
/* 3B762C E00B64CC 9245001F */  lbu       $a1, 0x1f($s2)
/* 3B7630 E00B64D0 92460023 */  lbu       $a2, 0x23($s2)
/* 3B7634 E00B64D4 24820018 */  addiu     $v0, $a0, 0x18
/* 3B7638 E00B64D8 AE620000 */  sw        $v0, ($s3)
/* 3B763C E00B64DC 3C02DE00 */  lui       $v0, 0xde00
/* 3B7640 E00B64E0 AC820010 */  sw        $v0, 0x10($a0)
/* 3B7644 E00B64E4 3C020900 */  lui       $v0, 0x900
/* 3B7648 E00B64E8 24420200 */  addiu     $v0, $v0, 0x200
/* 3B764C E00B64EC AC820014 */  sw        $v0, 0x14($a0)
/* 3B7650 E00B64F0 3C02DE01 */  lui       $v0, 0xde01
/* 3B7654 E00B64F4 AC820018 */  sw        $v0, 0x18($a0)
/* 3B7658 E00B64F8 248201A0 */  addiu     $v0, $a0, 0x1a0
/* 3B765C E00B64FC AC82001C */  sw        $v0, 0x1c($a0)
/* 3B7660 E00B6500 AE620000 */  sw        $v0, ($s3)
/* 3B7664 E00B6504 00031E00 */  sll       $v1, $v1, 0x18
/* 3B7668 E00B6508 00052C00 */  sll       $a1, $a1, 0x10
/* 3B766C E00B650C 00651825 */  or        $v1, $v1, $a1
/* 3B7670 E00B6510 00063200 */  sll       $a2, $a2, 8
/* 3B7674 E00B6514 00661825 */  or        $v1, $v1, $a2
/* 3B7678 E00B6518 00751825 */  or        $v1, $v1, $s5
/* 3B767C E00B651C AC83000C */  sw        $v1, 0xc($a0)
.LE00B6520:
/* 3B7680 E00B6520 A50A0000 */  sh        $t2, ($t0)
/* 3B7684 E00B6524 25080010 */  addiu     $t0, $t0, 0x10
/* 3B7688 E00B6528 00171940 */  sll       $v1, $s7, 5
/* 3B768C E00B652C 26F70004 */  addiu     $s7, $s7, 4
/* 3B7690 E00B6530 A4EFFFF3 */  sh        $t7, -0xd($a3)
/* 3B7694 E00B6534 A4E0FFF5 */  sh        $zero, -0xb($a3)
/* 3B7698 E00B6538 A4E3FFF9 */  sh        $v1, -7($a3)
/* 3B769C E00B653C C640002C */  lwc1      $f0, 0x2c($s2)
/* 3B76A0 E00B6540 25290001 */  addiu     $t1, $t1, 1
/* 3B76A4 E00B6544 A0ECFFFD */  sb        $t4, -3($a3)
/* 3B76A8 E00B6548 A0ECFFFE */  sb        $t4, -2($a3)
/* 3B76AC E00B654C A0ECFFFF */  sb        $t4, -1($a3)
/* 3B76B0 E00B6550 A0EB0000 */  sb        $t3, ($a3)
/* 3B76B4 E00B6554 4600018D */  trunc.w.s $f6, $f0
/* 3B76B8 E00B6558 44023000 */  mfc1      $v0, $f6
/* 3B76BC E00B655C 00000000 */  nop
/* 3B76C0 E00B6560 00021140 */  sll       $v0, $v0, 5
/* 3B76C4 E00B6564 A4E2FFFB */  sh        $v0, -5($a3)
/* 3B76C8 E00B6568 24E70010 */  addiu     $a3, $a3, 0x10
/* 3B76CC E00B656C A50A0000 */  sh        $t2, ($t0)
/* 3B76D0 E00B6570 C640002C */  lwc1      $f0, 0x2c($s2)
/* 3B76D4 E00B6574 25080010 */  addiu     $t0, $t0, 0x10
/* 3B76D8 E00B6578 A0EB0000 */  sb        $t3, ($a3)
/* 3B76DC E00B657C 256BFFEC */  addiu     $t3, $t3, -0x14
/* 3B76E0 E00B6580 26520004 */  addiu     $s2, $s2, 4
/* 3B76E4 E00B6584 254A0032 */  addiu     $t2, $t2, 0x32
/* 3B76E8 E00B6588 46040000 */  add.s     $f0, $f0, $f4
/* 3B76EC E00B658C A4E0FFF5 */  sh        $zero, -0xb($a3)
/* 3B76F0 E00B6590 A4E3FFF9 */  sh        $v1, -7($a3)
/* 3B76F4 E00B6594 46020002 */  mul.s     $f0, $f0, $f2
/* 3B76F8 E00B6598 00000000 */  nop
/* 3B76FC E00B659C A4EEFFFB */  sh        $t6, -5($a3)
/* 3B7700 E00B65A0 A0ECFFFD */  sb        $t4, -3($a3)
/* 3B7704 E00B65A4 A0ECFFFE */  sb        $t4, -2($a3)
/* 3B7708 E00B65A8 A0ECFFFF */  sb        $t4, -1($a3)
/* 3B770C E00B65AC 4600018D */  trunc.w.s $f6, $f0
/* 3B7710 E00B65B0 44023000 */  mfc1      $v0, $f6
/* 3B7714 E00B65B4 00000000 */  nop
/* 3B7718 E00B65B8 A4E2FFF3 */  sh        $v0, -0xd($a3)
/* 3B771C E00B65BC 2922000C */  slti      $v0, $t1, 0xc
/* 3B7720 E00B65C0 1440FFD7 */  bnez      $v0, .LE00B6520
/* 3B7724 E00B65C4 24E70010 */   addiu    $a3, $a3, 0x10
/* 3B7728 E00B65C8 0120302D */  daddu     $a2, $t1, $zero
/* 3B772C E00B65CC 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 3B7730 E00B65D0 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 3B7734 E00B65D4 00061040 */  sll       $v0, $a2, 1
/* 3B7738 E00B65D8 0000482D */  daddu     $t1, $zero, $zero
/* 3B773C E00B65DC 304400FF */  andi      $a0, $v0, 0xff
/* 3B7740 E00B65E0 00042300 */  sll       $a0, $a0, 0xc
/* 3B7744 E00B65E4 3042007F */  andi      $v0, $v0, 0x7f
/* 3B7748 E00B65E8 00021040 */  sll       $v0, $v0, 1
/* 3B774C E00B65EC 8CE30000 */  lw        $v1, ($a3)
/* 3B7750 E00B65F0 24C6FFFF */  addiu     $a2, $a2, -1
/* 3B7754 E00B65F4 0060282D */  daddu     $a1, $v1, $zero
/* 3B7758 E00B65F8 24630008 */  addiu     $v1, $v1, 8
/* 3B775C E00B65FC ACE30000 */  sw        $v1, ($a3)
/* 3B7760 E00B6600 3C030100 */  lui       $v1, 0x100
/* 3B7764 E00B6604 00431025 */  or        $v0, $v0, $v1
/* 3B7768 E00B6608 00822025 */  or        $a0, $a0, $v0
/* 3B776C E00B660C ACA40000 */  sw        $a0, ($a1)
/* 3B7770 E00B6610 18C00036 */  blez      $a2, .LE00B66EC
/* 3B7774 E00B6614 ACAD0004 */   sw       $t5, 4($a1)
/* 3B7778 E00B6618 00E0682D */  daddu     $t5, $a3, $zero
/* 3B777C E00B661C 3C0C0600 */  lui       $t4, 0x600
/* 3B7780 E00B6620 240B0001 */  addiu     $t3, $zero, 1
/* 3B7784 E00B6624 3C100606 */  lui       $s0, 0x606
/* 3B7788 E00B6628 36100402 */  ori       $s0, $s0, 0x402
/* 3B778C E00B662C 3C0F0002 */  lui       $t7, 2
/* 3B7790 E00B6630 35EF0406 */  ori       $t7, $t7, 0x406
/* 3B7794 E00B6634 3C0E0006 */  lui       $t6, 6
/* 3B7798 E00B6638 35CE0804 */  ori       $t6, $t6, 0x804
/* 3B779C E00B663C 24080004 */  addiu     $t0, $zero, 4
/* 3B77A0 E00B6640 24070002 */  addiu     $a3, $zero, 2
/* 3B77A4 E00B6644 240A0006 */  addiu     $t2, $zero, 6
.LE00B6648:
/* 3B77A8 E00B6648 8DA40000 */  lw        $a0, ($t5)
/* 3B77AC E00B664C 00092840 */  sll       $a1, $t1, 1
/* 3B77B0 E00B6650 24820008 */  addiu     $v0, $a0, 8
/* 3B77B4 E00B6654 14A00004 */  bnez      $a1, .LE00B6668
/* 3B77B8 E00B6658 ADA20000 */   sw       $v0, ($t5)
/* 3B77BC E00B665C 00091440 */  sll       $v0, $t1, 0x11
/* 3B77C0 E00B6660 0802D9A4 */  j         .LE00B6690
/* 3B77C4 E00B6664 34420402 */   ori      $v0, $v0, 0x402
.LE00B6668:
/* 3B77C8 E00B6668 14AB0003 */  bne       $a1, $t3, .LE00B6678
/* 3B77CC E00B666C 30E200FF */   andi     $v0, $a3, 0xff
/* 3B77D0 E00B6670 0802D9A6 */  j         .LE00B6698
/* 3B77D4 E00B6674 AC900000 */   sw       $s0, ($a0)
.LE00B6678:
/* 3B77D8 E00B6678 00021400 */  sll       $v0, $v0, 0x10
/* 3B77DC E00B667C 00091A80 */  sll       $v1, $t1, 0xa
/* 3B77E0 E00B6680 3063FC00 */  andi      $v1, $v1, 0xfc00
/* 3B77E4 E00B6684 00431025 */  or        $v0, $v0, $v1
/* 3B77E8 E00B6688 310300FF */  andi      $v1, $t0, 0xff
/* 3B77EC E00B668C 00431025 */  or        $v0, $v0, $v1
.LE00B6690:
/* 3B77F0 E00B6690 004C1025 */  or        $v0, $v0, $t4
/* 3B77F4 E00B6694 AC820000 */  sw        $v0, ($a0)
.LE00B6698:
/* 3B77F8 E00B6698 14A00003 */  bnez      $a1, .LE00B66A8
/* 3B77FC E00B669C 00000000 */   nop
/* 3B7800 E00B66A0 0802D9B5 */  j         .LE00B66D4
/* 3B7804 E00B66A4 AC8F0004 */   sw       $t7, 4($a0)
.LE00B66A8:
/* 3B7808 E00B66A8 14AB0003 */  bne       $a1, $t3, .LE00B66B8
/* 3B780C E00B66AC 314200FF */   andi     $v0, $t2, 0xff
/* 3B7810 E00B66B0 0802D9B5 */  j         .LE00B66D4
/* 3B7814 E00B66B4 AC8E0004 */   sw       $t6, 4($a0)
.LE00B66B8:
/* 3B7818 E00B66B8 00021400 */  sll       $v0, $v0, 0x10
/* 3B781C E00B66BC 30E300FF */  andi      $v1, $a3, 0xff
/* 3B7820 E00B66C0 00031A00 */  sll       $v1, $v1, 8
/* 3B7824 E00B66C4 00431025 */  or        $v0, $v0, $v1
/* 3B7828 E00B66C8 310300FF */  andi      $v1, $t0, 0xff
/* 3B782C E00B66CC 00431025 */  or        $v0, $v0, $v1
/* 3B7830 E00B66D0 AC820004 */  sw        $v0, 4($a0)
.LE00B66D4:
/* 3B7834 E00B66D4 25080004 */  addiu     $t0, $t0, 4
/* 3B7838 E00B66D8 24E70004 */  addiu     $a3, $a3, 4
/* 3B783C E00B66DC 25290001 */  addiu     $t1, $t1, 1
/* 3B7840 E00B66E0 0126102A */  slt       $v0, $t1, $a2
/* 3B7844 E00B66E4 1440FFD8 */  bnez      $v0, .LE00B6648
/* 3B7848 E00B66E8 254A0004 */   addiu    $t2, $t2, 4
.LE00B66EC:
/* 3B784C E00B66EC 3C05D838 */  lui       $a1, 0xd838
/* 3B7850 E00B66F0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3B7854 E00B66F4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3B7858 E00B66F8 8C620000 */  lw        $v0, ($v1)
/* 3B785C E00B66FC 34A50002 */  ori       $a1, $a1, 2
/* 3B7860 E00B6700 0040202D */  daddu     $a0, $v0, $zero
/* 3B7864 E00B6704 24420008 */  addiu     $v0, $v0, 8
/* 3B7868 E00B6708 AC620000 */  sw        $v0, ($v1)
/* 3B786C E00B670C 24020040 */  addiu     $v0, $zero, 0x40
/* 3B7870 E00B6710 AC850000 */  sw        $a1, ($a0)
/* 3B7874 E00B6714 AC820004 */  sw        $v0, 4($a0)
/* 3B7878 E00B6718 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* 3B787C E00B671C 8FB700AC */  lw        $s7, 0xac($sp)
/* 3B7880 E00B6720 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3B7884 E00B6724 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 3B7888 E00B6728 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 3B788C E00B672C 8FB3009C */  lw        $s3, 0x9c($sp)
/* 3B7890 E00B6730 8FB20098 */  lw        $s2, 0x98($sp)
/* 3B7894 E00B6734 8FB10094 */  lw        $s1, 0x94($sp)
/* 3B7898 E00B6738 8FB00090 */  lw        $s0, 0x90($sp)
/* 3B789C E00B673C D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* 3B78A0 E00B6740 03E00008 */  jr        $ra
/* 3B78A4 E00B6744 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 3B78A8 E00B6748 00000000 */  nop
/* 3B78AC E00B674C 00000000 */  nop
