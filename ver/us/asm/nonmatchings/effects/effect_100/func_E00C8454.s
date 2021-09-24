.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C8454
/* 3CF7F4 E00C8454 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 3CF7F8 E00C8458 0080302D */  daddu     $a2, $a0, $zero
/* 3CF7FC E00C845C 3C07DB06 */  lui       $a3, 0xdb06
/* 3CF800 E00C8460 34E70024 */  ori       $a3, $a3, 0x24
/* 3CF804 E00C8464 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3CF808 E00C8468 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3CF80C E00C846C 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3CF810 E00C8470 27A40018 */  addiu     $a0, $sp, 0x18
/* 3CF814 E00C8474 AFBF00B8 */  sw        $ra, 0xb8($sp)
/* 3CF818 E00C8478 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3CF81C E00C847C AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3CF820 E00C8480 AFB500AC */  sw        $s5, 0xac($sp)
/* 3CF824 E00C8484 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3CF828 E00C8488 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3CF82C E00C848C AFB1009C */  sw        $s1, 0x9c($sp)
/* 3CF830 E00C8490 AFB00098 */  sw        $s0, 0x98($sp)
/* 3CF834 E00C8494 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 3CF838 E00C8498 8E650000 */  lw        $a1, ($s3)
/* 3CF83C E00C849C 8CD2000C */  lw        $s2, 0xc($a2)
/* 3CF840 E00C84A0 3C01E00D */  lui       $at, %hi(D_E00C8740)
/* 3CF844 E00C84A4 D4208740 */  ldc1      $f0, %lo(D_E00C8740)($at)
/* 3CF848 E00C84A8 00A0182D */  daddu     $v1, $a1, $zero
/* 3CF84C E00C84AC 24A50008 */  addiu     $a1, $a1, 8
/* 3CF850 E00C84B0 AE650000 */  sw        $a1, ($s3)
/* 3CF854 E00C84B4 8E55003C */  lw        $s5, 0x3c($s2)
/* 3CF858 E00C84B8 8E560000 */  lw        $s6, ($s2)
/* 3CF85C E00C84BC C6540040 */  lwc1      $f20, 0x40($s2)
/* 3CF860 E00C84C0 3C02E700 */  lui       $v0, 0xe700
/* 3CF864 E00C84C4 AC620000 */  sw        $v0, ($v1)
/* 3CF868 E00C84C8 AC600004 */  sw        $zero, 4($v1)
/* 3CF86C E00C84CC ACA70000 */  sw        $a3, ($a1)
/* 3CF870 E00C84D0 8CC30010 */  lw        $v1, 0x10($a2)
/* 3CF874 E00C84D4 24A20008 */  addiu     $v0, $a1, 8
/* 3CF878 E00C84D8 AE620000 */  sw        $v0, ($s3)
/* 3CF87C E00C84DC 8C62001C */  lw        $v0, 0x1c($v1)
/* 3CF880 E00C84E0 3C038000 */  lui       $v1, 0x8000
/* 3CF884 E00C84E4 4600A521 */  cvt.d.s   $f20, $f20
/* 3CF888 E00C84E8 4620A502 */  mul.d     $f20, $f20, $f0
/* 3CF88C E00C84EC 00000000 */  nop
/* 3CF890 E00C84F0 00431021 */  addu      $v0, $v0, $v1
/* 3CF894 E00C84F4 3C03800B */  lui       $v1, %hi(gCameras)
/* 3CF898 E00C84F8 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3CF89C E00C84FC ACA20004 */  sw        $v0, 4($a1)
/* 3CF8A0 E00C8500 8E450004 */  lw        $a1, 4($s2)
/* 3CF8A4 E00C8504 8E460008 */  lw        $a2, 8($s2)
/* 3CF8A8 E00C8508 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3CF8AC E00C850C 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3CF8B0 E00C8510 8E47000C */  lw        $a3, 0xc($s2)
/* 3CF8B4 E00C8514 00028880 */  sll       $s1, $v0, 2
/* 3CF8B8 E00C8518 02228821 */  addu      $s1, $s1, $v0
/* 3CF8BC E00C851C 00118880 */  sll       $s1, $s1, 2
/* 3CF8C0 E00C8520 02228823 */  subu      $s1, $s1, $v0
/* 3CF8C4 E00C8524 001110C0 */  sll       $v0, $s1, 3
/* 3CF8C8 E00C8528 02228821 */  addu      $s1, $s1, $v0
/* 3CF8CC E00C852C 001188C0 */  sll       $s1, $s1, 3
/* 3CF8D0 E00C8530 02238821 */  addu      $s1, $s1, $v1
/* 3CF8D4 E00C8534 0C080108 */  jal       shim_guTranslateF
/* 3CF8D8 E00C8538 4620A520 */   cvt.s.d  $f20, $f20
/* 3CF8DC E00C853C C6400058 */  lwc1      $f0, 0x58($s2)
/* 3CF8E0 E00C8540 4600A002 */  mul.s     $f0, $f20, $f0
/* 3CF8E4 E00C8544 00000000 */  nop
/* 3CF8E8 E00C8548 44050000 */  mfc1      $a1, $f0
/* 3CF8EC E00C854C C640005C */  lwc1      $f0, 0x5c($s2)
/* 3CF8F0 E00C8550 4600A002 */  mul.s     $f0, $f20, $f0
/* 3CF8F4 E00C8554 00000000 */  nop
/* 3CF8F8 E00C8558 3C170001 */  lui       $s7, 1
/* 3CF8FC E00C855C 27B00058 */  addiu     $s0, $sp, 0x58
/* 3CF900 E00C8560 4407A000 */  mfc1      $a3, $f20
/* 3CF904 E00C8564 44060000 */  mfc1      $a2, $f0
/* 3CF908 E00C8568 0C080110 */  jal       shim_guScaleF
/* 3CF90C E00C856C 0200202D */   daddu    $a0, $s0, $zero
/* 3CF910 E00C8570 0200202D */  daddu     $a0, $s0, $zero
/* 3CF914 E00C8574 27A50018 */  addiu     $a1, $sp, 0x18
/* 3CF918 E00C8578 0C080114 */  jal       shim_guMtxCatF
/* 3CF91C E00C857C 00A0302D */   daddu    $a2, $a1, $zero
/* 3CF920 E00C8580 3C013F80 */  lui       $at, 0x3f80
/* 3CF924 E00C8584 44810000 */  mtc1      $at, $f0
/* 3CF928 E00C8588 36F71630 */  ori       $s7, $s7, 0x1630
/* 3CF92C E00C858C E7A00010 */  swc1      $f0, 0x10($sp)
/* 3CF930 E00C8590 44800000 */  mtc1      $zero, $f0
/* 3CF934 E00C8594 0200202D */  daddu     $a0, $s0, $zero
/* 3CF938 E00C8598 44060000 */  mfc1      $a2, $f0
/* 3CF93C E00C859C 8E450050 */  lw        $a1, 0x50($s2)
/* 3CF940 E00C85A0 0C080104 */  jal       shim_guRotateF
/* 3CF944 E00C85A4 00C0382D */   daddu    $a3, $a2, $zero
/* 3CF948 E00C85A8 0200202D */  daddu     $a0, $s0, $zero
/* 3CF94C E00C85AC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3CF950 E00C85B0 0C080114 */  jal       shim_guMtxCatF
/* 3CF954 E00C85B4 00A0302D */   daddu    $a2, $a1, $zero
/* 3CF958 E00C85B8 27A40018 */  addiu     $a0, $sp, 0x18
/* 3CF95C E00C85BC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3CF960 E00C85C0 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3CF964 E00C85C4 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3CF968 E00C85C8 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3CF96C E00C85CC 96050000 */  lhu       $a1, ($s0)
/* 3CF970 E00C85D0 8E820000 */  lw        $v0, ($s4)
/* 3CF974 E00C85D4 00052980 */  sll       $a1, $a1, 6
/* 3CF978 E00C85D8 00B72821 */  addu      $a1, $a1, $s7
/* 3CF97C E00C85DC 0C080118 */  jal       shim_guMtxF2L
/* 3CF980 E00C85E0 00452821 */   addu     $a1, $v0, $a1
/* 3CF984 E00C85E4 3C03DA38 */  lui       $v1, 0xda38
/* 3CF988 E00C85E8 34630002 */  ori       $v1, $v1, 2
/* 3CF98C E00C85EC 3C06DA38 */  lui       $a2, 0xda38
/* 3CF990 E00C85F0 34C60001 */  ori       $a2, $a2, 1
/* 3CF994 E00C85F4 3C08D838 */  lui       $t0, 0xd838
/* 3CF998 E00C85F8 35080002 */  ori       $t0, $t0, 2
/* 3CF99C E00C85FC 3C07DE00 */  lui       $a3, 0xde00
/* 3CF9A0 E00C8600 32B500FF */  andi      $s5, $s5, 0xff
/* 3CF9A4 E00C8604 0016B080 */  sll       $s6, $s6, 2
/* 3CF9A8 E00C8608 8E640000 */  lw        $a0, ($s3)
/* 3CF9AC E00C860C 96020000 */  lhu       $v0, ($s0)
/* 3CF9B0 E00C8610 0080282D */  daddu     $a1, $a0, $zero
/* 3CF9B4 E00C8614 24840008 */  addiu     $a0, $a0, 8
/* 3CF9B8 E00C8618 AE640000 */  sw        $a0, ($s3)
/* 3CF9BC E00C861C ACA30000 */  sw        $v1, ($a1)
/* 3CF9C0 E00C8620 24430001 */  addiu     $v1, $v0, 1
/* 3CF9C4 E00C8624 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3CF9C8 E00C8628 00021180 */  sll       $v0, $v0, 6
/* 3CF9CC E00C862C A6030000 */  sh        $v1, ($s0)
/* 3CF9D0 E00C8630 8E830000 */  lw        $v1, ($s4)
/* 3CF9D4 E00C8634 00571021 */  addu      $v0, $v0, $s7
/* 3CF9D8 E00C8638 00621821 */  addu      $v1, $v1, $v0
/* 3CF9DC E00C863C 24820008 */  addiu     $v0, $a0, 8
/* 3CF9E0 E00C8640 ACA30004 */  sw        $v1, 4($a1)
/* 3CF9E4 E00C8644 AE620000 */  sw        $v0, ($s3)
/* 3CF9E8 E00C8648 24820010 */  addiu     $v0, $a0, 0x10
/* 3CF9EC E00C864C AC860000 */  sw        $a2, ($a0)
/* 3CF9F0 E00C8650 AE620000 */  sw        $v0, ($s3)
/* 3CF9F4 E00C8654 8E230204 */  lw        $v1, 0x204($s1)
/* 3CF9F8 E00C8658 3C02FA00 */  lui       $v0, 0xfa00
/* 3CF9FC E00C865C AC820008 */  sw        $v0, 8($a0)
/* 3CFA00 E00C8660 AC830004 */  sw        $v1, 4($a0)
/* 3CFA04 E00C8664 92430033 */  lbu       $v1, 0x33($s2)
/* 3CFA08 E00C8668 92450037 */  lbu       $a1, 0x37($s2)
/* 3CFA0C E00C866C 9246003B */  lbu       $a2, 0x3b($s2)
/* 3CFA10 E00C8670 24820018 */  addiu     $v0, $a0, 0x18
/* 3CFA14 E00C8674 AE620000 */  sw        $v0, ($s3)
/* 3CFA18 E00C8678 24820020 */  addiu     $v0, $a0, 0x20
/* 3CFA1C E00C867C AC870010 */  sw        $a3, 0x10($a0)
/* 3CFA20 E00C8680 AE620000 */  sw        $v0, ($s3)
/* 3CFA24 E00C8684 00031E00 */  sll       $v1, $v1, 0x18
/* 3CFA28 E00C8688 00052C00 */  sll       $a1, $a1, 0x10
/* 3CFA2C E00C868C 00651825 */  or        $v1, $v1, $a1
/* 3CFA30 E00C8690 00063200 */  sll       $a2, $a2, 8
/* 3CFA34 E00C8694 00661825 */  or        $v1, $v1, $a2
/* 3CFA38 E00C8698 00751825 */  or        $v1, $v1, $s5
/* 3CFA3C E00C869C AC83000C */  sw        $v1, 0xc($a0)
/* 3CFA40 E00C86A0 3C03E00D */  lui       $v1, %hi(D_E00C8710)
/* 3CFA44 E00C86A4 00761821 */  addu      $v1, $v1, $s6
/* 3CFA48 E00C86A8 8C638710 */  lw        $v1, %lo(D_E00C8710)($v1)
/* 3CFA4C E00C86AC 24820028 */  addiu     $v0, $a0, 0x28
/* 3CFA50 E00C86B0 AE620000 */  sw        $v0, ($s3)
/* 3CFA54 E00C86B4 3C020900 */  lui       $v0, 0x900
/* 3CFA58 E00C86B8 244209F0 */  addiu     $v0, $v0, 0x9f0
/* 3CFA5C E00C86BC AC82001C */  sw        $v0, 0x1c($a0)
/* 3CFA60 E00C86C0 24020040 */  addiu     $v0, $zero, 0x40
/* 3CFA64 E00C86C4 AC870018 */  sw        $a3, 0x18($a0)
/* 3CFA68 E00C86C8 AC880020 */  sw        $t0, 0x20($a0)
/* 3CFA6C E00C86CC AC820024 */  sw        $v0, 0x24($a0)
/* 3CFA70 E00C86D0 AC830014 */  sw        $v1, 0x14($a0)
/* 3CFA74 E00C86D4 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* 3CFA78 E00C86D8 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3CFA7C E00C86DC 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3CFA80 E00C86E0 8FB500AC */  lw        $s5, 0xac($sp)
/* 3CFA84 E00C86E4 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3CFA88 E00C86E8 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3CFA8C E00C86EC 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3CFA90 E00C86F0 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3CFA94 E00C86F4 8FB00098 */  lw        $s0, 0x98($sp)
/* 3CFA98 E00C86F8 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 3CFA9C E00C86FC 03E00008 */  jr        $ra
/* 3CFAA0 E00C8700 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 3CFAA4 E00C8704 00000000 */  nop
/* 3CFAA8 E00C8708 00000000 */  nop
/* 3CFAAC E00C870C 00000000 */  nop
