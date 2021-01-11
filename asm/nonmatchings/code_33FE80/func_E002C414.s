.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002C414
/* 340294 E002C414 27BDFEA0 */  addiu     $sp, $sp, -0x160
/* 340298 E002C418 3C02DB06 */  lui       $v0, 0xdb06
/* 34029C E002C41C 34420024 */  ori       $v0, $v0, 0x24
/* 3402A0 E002C420 AFB40138 */  sw        $s4, 0x138($sp)
/* 3402A4 E002C424 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 3402A8 E002C428 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 3402AC E002C42C AFA40160 */  sw        $a0, 0x160($sp)
/* 3402B0 E002C430 8FA80160 */  lw        $t0, 0x160($sp)
/* 3402B4 E002C434 3C038000 */  lui       $v1, 0x8000
/* 3402B8 E002C438 AFBF014C */  sw        $ra, 0x14c($sp)
/* 3402BC E002C43C AFBE0148 */  sw        $fp, 0x148($sp)
/* 3402C0 E002C440 AFB70144 */  sw        $s7, 0x144($sp)
/* 3402C4 E002C444 AFB60140 */  sw        $s6, 0x140($sp)
/* 3402C8 E002C448 AFB5013C */  sw        $s5, 0x13c($sp)
/* 3402CC E002C44C AFB30134 */  sw        $s3, 0x134($sp)
/* 3402D0 E002C450 AFB20130 */  sw        $s2, 0x130($sp)
/* 3402D4 E002C454 AFB1012C */  sw        $s1, 0x12c($sp)
/* 3402D8 E002C458 AFB00128 */  sw        $s0, 0x128($sp)
/* 3402DC E002C45C F7B60158 */  sdc1      $f22, 0x158($sp)
/* 3402E0 E002C460 F7B40150 */  sdc1      $f20, 0x150($sp)
/* 3402E4 E002C464 8E840000 */  lw        $a0, ($s4)
/* 3402E8 E002C468 8D13000C */  lw        $s3, 0xc($t0)
/* 3402EC E002C46C 0080282D */  daddu     $a1, $a0, $zero
/* 3402F0 E002C470 ACA20000 */  sw        $v0, ($a1)
/* 3402F4 E002C474 8D020010 */  lw        $v0, 0x10($t0)
/* 3402F8 E002C478 24840008 */  addiu     $a0, $a0, 8
/* 3402FC E002C47C AE840000 */  sw        $a0, ($s4)
/* 340300 E002C480 8C42001C */  lw        $v0, 0x1c($v0)
/* 340304 E002C484 3C15DE00 */  lui       $s5, 0xde00
/* 340308 E002C488 00431021 */  addu      $v0, $v0, $v1
/* 34030C E002C48C ACA20004 */  sw        $v0, 4($a1)
/* 340310 E002C490 3C020900 */  lui       $v0, 0x900
/* 340314 E002C494 24420C00 */  addiu     $v0, $v0, 0xc00
/* 340318 E002C498 AC950000 */  sw        $s5, ($a0)
/* 34031C E002C49C AC820004 */  sw        $v0, 4($a0)
/* 340320 E002C4A0 8E620024 */  lw        $v0, 0x24($s3)
/* 340324 E002C4A4 24840008 */  addiu     $a0, $a0, 8
/* 340328 E002C4A8 1440007E */  bnez      $v0, .LE002C6A4
/* 34032C E002C4AC AE840000 */   sw       $a0, ($s4)
/* 340330 E002C4B0 27A40020 */  addiu     $a0, $sp, 0x20
/* 340334 E002C4B4 8E650000 */  lw        $a1, ($s3)
/* 340338 E002C4B8 8E660004 */  lw        $a2, 4($s3)
/* 34033C E002C4BC 8E670008 */  lw        $a3, 8($s3)
/* 340340 E002C4C0 0C080108 */  jal       func_E0200420
/* 340344 E002C4C4 3C120001 */   lui      $s2, 1
/* 340348 E002C4C8 36521630 */  ori       $s2, $s2, 0x1630
/* 34034C E002C4CC 3C013FC0 */  lui       $at, 0x3fc0
/* 340350 E002C4D0 44810000 */  mtc1      $at, $f0
/* 340354 E002C4D4 27B10060 */  addiu     $s1, $sp, 0x60
/* 340358 E002C4D8 44050000 */  mfc1      $a1, $f0
/* 34035C E002C4DC 0220202D */  daddu     $a0, $s1, $zero
/* 340360 E002C4E0 00A0302D */  daddu     $a2, $a1, $zero
/* 340364 E002C4E4 0C080110 */  jal       func_E0200440
/* 340368 E002C4E8 00A0382D */   daddu    $a3, $a1, $zero
/* 34036C E002C4EC 0220202D */  daddu     $a0, $s1, $zero
/* 340370 E002C4F0 27A50020 */  addiu     $a1, $sp, 0x20
/* 340374 E002C4F4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* 340378 E002C4F8 0C080114 */  jal       func_E0200450
/* 34037C E002C4FC 0200302D */   daddu    $a2, $s0, $zero
/* 340380 E002C500 4480A000 */  mtc1      $zero, $f20
/* 340384 E002C504 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 340388 E002C508 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 34038C E002C50C 3C013F80 */  lui       $at, 0x3f80
/* 340390 E002C510 4481B000 */  mtc1      $at, $f22
/* 340394 E002C514 00031080 */  sll       $v0, $v1, 2
/* 340398 E002C518 00431021 */  addu      $v0, $v0, $v1
/* 34039C E002C51C 00021080 */  sll       $v0, $v0, 2
/* 3403A0 E002C520 00431023 */  subu      $v0, $v0, $v1
/* 3403A4 E002C524 000218C0 */  sll       $v1, $v0, 3
/* 3403A8 E002C528 00431021 */  addu      $v0, $v0, $v1
/* 3403AC E002C52C 000210C0 */  sll       $v0, $v0, 3
/* 3403B0 E002C530 4406A000 */  mfc1      $a2, $f20
/* 3403B4 E002C534 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3403B8 E002C538 00220821 */  addu      $at, $at, $v0
/* 3403BC E002C53C C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 3403C0 E002C540 4407B000 */  mfc1      $a3, $f22
/* 3403C4 E002C544 46000007 */  neg.s     $f0, $f0
/* 3403C8 E002C548 44050000 */  mfc1      $a1, $f0
/* 3403CC E002C54C 0220202D */  daddu     $a0, $s1, $zero
/* 3403D0 E002C550 0C080104 */  jal       func_E0200410
/* 3403D4 E002C554 E7B40010 */   swc1     $f20, 0x10($sp)
/* 3403D8 E002C558 0220202D */  daddu     $a0, $s1, $zero
/* 3403DC E002C55C 0200282D */  daddu     $a1, $s0, $zero
/* 3403E0 E002C560 0C080114 */  jal       func_E0200450
/* 3403E4 E002C564 0200302D */   daddu    $a2, $s0, $zero
/* 3403E8 E002C568 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3403EC E002C56C 8E650034 */  lw        $a1, 0x34($s3)
/* 3403F0 E002C570 4406A000 */  mfc1      $a2, $f20
/* 3403F4 E002C574 4407A000 */  mfc1      $a3, $f20
/* 3403F8 E002C578 0C080104 */  jal       func_E0200410
/* 3403FC E002C57C 0220202D */   daddu    $a0, $s1, $zero
/* 340400 E002C580 0220202D */  daddu     $a0, $s1, $zero
/* 340404 E002C584 0200282D */  daddu     $a1, $s0, $zero
/* 340408 E002C588 0C080114 */  jal       func_E0200450
/* 34040C E002C58C 0200302D */   daddu    $a2, $s0, $zero
/* 340410 E002C590 E7B40010 */  swc1      $f20, 0x10($sp)
/* 340414 E002C594 8E65002C */  lw        $a1, 0x2c($s3)
/* 340418 E002C598 4406B000 */  mfc1      $a2, $f22
/* 34041C E002C59C 4407A000 */  mfc1      $a3, $f20
/* 340420 E002C5A0 0C080104 */  jal       func_E0200410
/* 340424 E002C5A4 0220202D */   daddu    $a0, $s1, $zero
/* 340428 E002C5A8 0220202D */  daddu     $a0, $s1, $zero
/* 34042C E002C5AC 0200282D */  daddu     $a1, $s0, $zero
/* 340430 E002C5B0 0C080114 */  jal       func_E0200450
/* 340434 E002C5B4 0200302D */   daddu    $a2, $s0, $zero
/* 340438 E002C5B8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 34043C E002C5BC 8E650030 */  lw        $a1, 0x30($s3)
/* 340440 E002C5C0 4406A000 */  mfc1      $a2, $f20
/* 340444 E002C5C4 4407B000 */  mfc1      $a3, $f22
/* 340448 E002C5C8 0C080104 */  jal       func_E0200410
/* 34044C E002C5CC 0220202D */   daddu    $a0, $s1, $zero
/* 340450 E002C5D0 0220202D */  daddu     $a0, $s1, $zero
/* 340454 E002C5D4 0200282D */  daddu     $a1, $s0, $zero
/* 340458 E002C5D8 0C080114 */  jal       func_E0200450
/* 34045C E002C5DC 0200302D */   daddu    $a2, $s0, $zero
/* 340460 E002C5E0 0200202D */  daddu     $a0, $s0, $zero
/* 340464 E002C5E4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 340468 E002C5E8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 34046C E002C5EC 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 340470 E002C5F0 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 340474 E002C5F4 96050000 */  lhu       $a1, ($s0)
/* 340478 E002C5F8 8E220000 */  lw        $v0, ($s1)
/* 34047C E002C5FC 00052980 */  sll       $a1, $a1, 6
/* 340480 E002C600 00B22821 */  addu      $a1, $a1, $s2
/* 340484 E002C604 0C080118 */  jal       func_E0200460
/* 340488 E002C608 00452821 */   addu     $a1, $v0, $a1
/* 34048C E002C60C 3C06666D */  lui       $a2, 0x666d
/* 340490 E002C610 34C67B00 */  ori       $a2, $a2, 0x7b00
/* 340494 E002C614 3C07D838 */  lui       $a3, 0xd838
/* 340498 E002C618 8E840000 */  lw        $a0, ($s4)
/* 34049C E002C61C 34E70002 */  ori       $a3, $a3, 2
/* 3404A0 E002C620 0080282D */  daddu     $a1, $a0, $zero
/* 3404A4 E002C624 24840008 */  addiu     $a0, $a0, 8
/* 3404A8 E002C628 AE840000 */  sw        $a0, ($s4)
/* 3404AC E002C62C 96020000 */  lhu       $v0, ($s0)
/* 3404B0 E002C630 3C03DA38 */  lui       $v1, 0xda38
/* 3404B4 E002C634 ACA30000 */  sw        $v1, ($a1)
/* 3404B8 E002C638 24430001 */  addiu     $v1, $v0, 1
/* 3404BC E002C63C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3404C0 E002C640 00021180 */  sll       $v0, $v0, 6
/* 3404C4 E002C644 A6030000 */  sh        $v1, ($s0)
/* 3404C8 E002C648 8E230000 */  lw        $v1, ($s1)
/* 3404CC E002C64C 00521021 */  addu      $v0, $v0, $s2
/* 3404D0 E002C650 00621821 */  addu      $v1, $v1, $v0
/* 3404D4 E002C654 24820008 */  addiu     $v0, $a0, 8
/* 3404D8 E002C658 ACA30004 */  sw        $v1, 4($a1)
/* 3404DC E002C65C AE820000 */  sw        $v0, ($s4)
/* 3404E0 E002C660 3C02FA00 */  lui       $v0, 0xfa00
/* 3404E4 E002C664 AC820000 */  sw        $v0, ($a0)
/* 3404E8 E002C668 9263002B */  lbu       $v1, 0x2b($s3)
/* 3404EC E002C66C 24820010 */  addiu     $v0, $a0, 0x10
/* 3404F0 E002C670 AE820000 */  sw        $v0, ($s4)
/* 3404F4 E002C674 AC950008 */  sw        $s5, 8($a0)
/* 3404F8 E002C678 00661825 */  or        $v1, $v1, $a2
/* 3404FC E002C67C AC830004 */  sw        $v1, 4($a0)
/* 340500 E002C680 3C03E003 */  lui       $v1, %hi(D_E002C940)
/* 340504 E002C684 8C63C940 */  lw        $v1, %lo(D_E002C940)($v1)
/* 340508 E002C688 24820018 */  addiu     $v0, $a0, 0x18
/* 34050C E002C68C AE820000 */  sw        $v0, ($s4)
/* 340510 E002C690 24020040 */  addiu     $v0, $zero, 0x40
/* 340514 E002C694 AC870010 */  sw        $a3, 0x10($a0)
/* 340518 E002C698 AC820014 */  sw        $v0, 0x14($a0)
/* 34051C E002C69C 0800B241 */  j         .LE002C904
/* 340520 E002C6A0 AC83000C */   sw       $v1, 0xc($a0)
.LE002C6A4:
/* 340524 E002C6A4 8E650000 */  lw        $a1, ($s3)
/* 340528 E002C6A8 8E660004 */  lw        $a2, 4($s3)
/* 34052C E002C6AC 8E670008 */  lw        $a3, 8($s3)
/* 340530 E002C6B0 8E760028 */  lw        $s6, 0x28($s3)
/* 340534 E002C6B4 0C080108 */  jal       func_E0200420
/* 340538 E002C6B8 27A40020 */   addiu    $a0, $sp, 0x20
/* 34053C E002C6BC 3C013FC0 */  lui       $at, 0x3fc0
/* 340540 E002C6C0 44810000 */  mtc1      $at, $f0
/* 340544 E002C6C4 27B10060 */  addiu     $s1, $sp, 0x60
/* 340548 E002C6C8 44050000 */  mfc1      $a1, $f0
/* 34054C E002C6CC 0220202D */  daddu     $a0, $s1, $zero
/* 340550 E002C6D0 00A0302D */  daddu     $a2, $a1, $zero
/* 340554 E002C6D4 0C080110 */  jal       func_E0200440
/* 340558 E002C6D8 00A0382D */   daddu    $a3, $a1, $zero
/* 34055C E002C6DC 0220202D */  daddu     $a0, $s1, $zero
/* 340560 E002C6E0 27A50020 */  addiu     $a1, $sp, 0x20
/* 340564 E002C6E4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* 340568 E002C6E8 0C080114 */  jal       func_E0200450
/* 34056C E002C6EC 0200302D */   daddu    $a2, $s0, $zero
/* 340570 E002C6F0 4480B000 */  mtc1      $zero, $f22
/* 340574 E002C6F4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 340578 E002C6F8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 34057C E002C6FC 3C013F80 */  lui       $at, 0x3f80
/* 340580 E002C700 4481A000 */  mtc1      $at, $f20
/* 340584 E002C704 00031080 */  sll       $v0, $v1, 2
/* 340588 E002C708 00431021 */  addu      $v0, $v0, $v1
/* 34058C E002C70C 00021080 */  sll       $v0, $v0, 2
/* 340590 E002C710 00431023 */  subu      $v0, $v0, $v1
/* 340594 E002C714 000218C0 */  sll       $v1, $v0, 3
/* 340598 E002C718 00431021 */  addu      $v0, $v0, $v1
/* 34059C E002C71C 000210C0 */  sll       $v0, $v0, 3
/* 3405A0 E002C720 4406B000 */  mfc1      $a2, $f22
/* 3405A4 E002C724 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3405A8 E002C728 00220821 */  addu      $at, $at, $v0
/* 3405AC E002C72C C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 3405B0 E002C730 4407A000 */  mfc1      $a3, $f20
/* 3405B4 E002C734 46000007 */  neg.s     $f0, $f0
/* 3405B8 E002C738 44050000 */  mfc1      $a1, $f0
/* 3405BC E002C73C 0220202D */  daddu     $a0, $s1, $zero
/* 3405C0 E002C740 0C080104 */  jal       func_E0200410
/* 3405C4 E002C744 E7B60010 */   swc1     $f22, 0x10($sp)
/* 3405C8 E002C748 0220202D */  daddu     $a0, $s1, $zero
/* 3405CC E002C74C 0200282D */  daddu     $a1, $s0, $zero
/* 3405D0 E002C750 0C080114 */  jal       func_E0200450
/* 3405D4 E002C754 00A0302D */   daddu    $a2, $a1, $zero
/* 3405D8 E002C758 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3405DC E002C75C 8E65002C */  lw        $a1, 0x2c($s3)
/* 3405E0 E002C760 4406A000 */  mfc1      $a2, $f20
/* 3405E4 E002C764 4407B000 */  mfc1      $a3, $f22
/* 3405E8 E002C768 0C080104 */  jal       func_E0200410
/* 3405EC E002C76C 27A400E0 */   addiu    $a0, $sp, 0xe0
/* 3405F0 E002C770 8FA80160 */  lw        $t0, 0x160($sp)
/* 3405F4 E002C774 24150001 */  addiu     $s5, $zero, 1
/* 3405F8 E002C778 8D020008 */  lw        $v0, 8($t0)
/* 3405FC E002C77C 02A2102A */  slt       $v0, $s5, $v0
/* 340600 E002C780 10400060 */  beqz      $v0, .LE002C904
/* 340604 E002C784 26730040 */   addiu    $s3, $s3, 0x40
/* 340608 E002C788 0220902D */  daddu     $s2, $s1, $zero
/* 34060C E002C78C 4600B506 */  mov.s     $f20, $f22
/* 340610 E002C790 3C1E8007 */  lui       $fp, %hi(gMatrixListPos)
/* 340614 E002C794 27DE41F0 */  addiu     $fp, $fp, %lo(gMatrixListPos)
/* 340618 E002C798 3C170001 */  lui       $s7, 1
/* 34061C E002C79C 36F71630 */  ori       $s7, $s7, 0x1630
/* 340620 E002C7A0 3C039696 */  lui       $v1, 0x9696
/* 340624 E002C7A4 3463C800 */  ori       $v1, $v1, 0xc800
/* 340628 E002C7A8 32C200FF */  andi      $v0, $s6, 0xff
/* 34062C E002C7AC 00431025 */  or        $v0, $v0, $v1
/* 340630 E002C7B0 AFA20120 */  sw        $v0, 0x120($sp)
/* 340634 E002C7B4 26710034 */  addiu     $s1, $s3, 0x34
/* 340638 E002C7B8 3C16E003 */  lui       $s6, %hi(D_E002C944)
/* 34063C E002C7BC 26D6C944 */  addiu     $s6, $s6, %lo(D_E002C944)
.LE002C7C0:
/* 340640 E002C7C0 8E650000 */  lw        $a1, ($s3)
/* 340644 E002C7C4 8E26FFD0 */  lw        $a2, -0x30($s1)
/* 340648 E002C7C8 8E27FFD4 */  lw        $a3, -0x2c($s1)
/* 34064C E002C7CC 8ED00000 */  lw        $s0, ($s6)
/* 340650 E002C7D0 0C080108 */  jal       func_E0200420
/* 340654 E002C7D4 0240202D */   daddu    $a0, $s2, $zero
/* 340658 E002C7D8 0240202D */  daddu     $a0, $s2, $zero
/* 34065C E002C7DC 27A500A0 */  addiu     $a1, $sp, 0xa0
/* 340660 E002C7E0 0C080114 */  jal       func_E0200450
/* 340664 E002C7E4 27A60020 */   addiu    $a2, $sp, 0x20
/* 340668 E002C7E8 27A400E0 */  addiu     $a0, $sp, 0xe0
/* 34066C E002C7EC 27A50020 */  addiu     $a1, $sp, 0x20
/* 340670 E002C7F0 0C080114 */  jal       func_E0200450
/* 340674 E002C7F4 00A0302D */   daddu    $a2, $a1, $zero
/* 340678 E002C7F8 4406A000 */  mfc1      $a2, $f20
/* 34067C E002C7FC 3C013F80 */  lui       $at, 0x3f80
/* 340680 E002C800 44810000 */  mtc1      $at, $f0
/* 340684 E002C804 26D60004 */  addiu     $s6, $s6, 4
/* 340688 E002C808 E7A00010 */  swc1      $f0, 0x10($sp)
/* 34068C E002C80C C620FFE4 */  lwc1      $f0, -0x1c($s1)
/* 340690 E002C810 26B50001 */  addiu     $s5, $s5, 1
/* 340694 E002C814 E7A00014 */  swc1      $f0, 0x14($sp)
/* 340698 E002C818 C620FFE8 */  lwc1      $f0, -0x18($s1)
/* 34069C E002C81C 26730040 */  addiu     $s3, $s3, 0x40
/* 3406A0 E002C820 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3406A4 E002C824 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3406A8 E002C828 8E25FFF8 */  lw        $a1, -8($s1)
/* 3406AC E002C82C 8E270000 */  lw        $a3, ($s1)
/* 3406B0 E002C830 0C080180 */  jal       func_E0200600
/* 3406B4 E002C834 0240202D */   daddu    $a0, $s2, $zero
/* 3406B8 E002C838 0240202D */  daddu     $a0, $s2, $zero
/* 3406BC E002C83C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3406C0 E002C840 0C080114 */  jal       func_E0200450
/* 3406C4 E002C844 00A0302D */   daddu    $a2, $a1, $zero
/* 3406C8 E002C848 27A40020 */  addiu     $a0, $sp, 0x20
/* 3406CC E002C84C 97C50000 */  lhu       $a1, ($fp)
/* 3406D0 E002C850 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3406D4 E002C854 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3406D8 E002C858 00052980 */  sll       $a1, $a1, 6
/* 3406DC E002C85C 00B72821 */  addu      $a1, $a1, $s7
/* 3406E0 E002C860 0C080118 */  jal       func_E0200460
/* 3406E4 E002C864 00452821 */   addu     $a1, $v0, $a1
/* 3406E8 E002C868 3C06D838 */  lui       $a2, 0xd838
/* 3406EC E002C86C 8E840000 */  lw        $a0, ($s4)
/* 3406F0 E002C870 34C60002 */  ori       $a2, $a2, 2
/* 3406F4 E002C874 0080282D */  daddu     $a1, $a0, $zero
/* 3406F8 E002C878 24840008 */  addiu     $a0, $a0, 8
/* 3406FC E002C87C AE840000 */  sw        $a0, ($s4)
/* 340700 E002C880 97C20000 */  lhu       $v0, ($fp)
/* 340704 E002C884 3C03DA38 */  lui       $v1, 0xda38
/* 340708 E002C888 ACA30000 */  sw        $v1, ($a1)
/* 34070C E002C88C 24430001 */  addiu     $v1, $v0, 1
/* 340710 E002C890 3042FFFF */  andi      $v0, $v0, 0xffff
/* 340714 E002C894 00021180 */  sll       $v0, $v0, 6
/* 340718 E002C898 A7C30000 */  sh        $v1, ($fp)
/* 34071C E002C89C 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 340720 E002C8A0 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 340724 E002C8A4 00571021 */  addu      $v0, $v0, $s7
/* 340728 E002C8A8 00621821 */  addu      $v1, $v1, $v0
/* 34072C E002C8AC 24820008 */  addiu     $v0, $a0, 8
/* 340730 E002C8B0 ACA30004 */  sw        $v1, 4($a1)
/* 340734 E002C8B4 AE820000 */  sw        $v0, ($s4)
/* 340738 E002C8B8 3C02FA00 */  lui       $v0, 0xfa00
/* 34073C E002C8BC AC820000 */  sw        $v0, ($a0)
/* 340740 E002C8C0 8FA80120 */  lw        $t0, 0x120($sp)
/* 340744 E002C8C4 24820010 */  addiu     $v0, $a0, 0x10
/* 340748 E002C8C8 AC880004 */  sw        $t0, 4($a0)
/* 34074C E002C8CC AE820000 */  sw        $v0, ($s4)
/* 340750 E002C8D0 3C02DE00 */  lui       $v0, 0xde00
/* 340754 E002C8D4 AC820008 */  sw        $v0, 8($a0)
/* 340758 E002C8D8 24020040 */  addiu     $v0, $zero, 0x40
/* 34075C E002C8DC AC90000C */  sw        $s0, 0xc($a0)
/* 340760 E002C8E0 AC860010 */  sw        $a2, 0x10($a0)
/* 340764 E002C8E4 AC820014 */  sw        $v0, 0x14($a0)
/* 340768 E002C8E8 8FA80160 */  lw        $t0, 0x160($sp)
/* 34076C E002C8EC 26310040 */  addiu     $s1, $s1, 0x40
/* 340770 E002C8F0 8D020008 */  lw        $v0, 8($t0)
/* 340774 E002C8F4 24840018 */  addiu     $a0, $a0, 0x18
/* 340778 E002C8F8 02A2102A */  slt       $v0, $s5, $v0
/* 34077C E002C8FC 1440FFB0 */  bnez      $v0, .LE002C7C0
/* 340780 E002C900 AE840000 */   sw       $a0, ($s4)
.LE002C904:
/* 340784 E002C904 8FBF014C */  lw        $ra, 0x14c($sp)
/* 340788 E002C908 8FBE0148 */  lw        $fp, 0x148($sp)
/* 34078C E002C90C 8FB70144 */  lw        $s7, 0x144($sp)
/* 340790 E002C910 8FB60140 */  lw        $s6, 0x140($sp)
/* 340794 E002C914 8FB5013C */  lw        $s5, 0x13c($sp)
/* 340798 E002C918 8FB40138 */  lw        $s4, 0x138($sp)
/* 34079C E002C91C 8FB30134 */  lw        $s3, 0x134($sp)
/* 3407A0 E002C920 8FB20130 */  lw        $s2, 0x130($sp)
/* 3407A4 E002C924 8FB1012C */  lw        $s1, 0x12c($sp)
/* 3407A8 E002C928 8FB00128 */  lw        $s0, 0x128($sp)
/* 3407AC E002C92C D7B60158 */  ldc1      $f22, 0x158($sp)
/* 3407B0 E002C930 D7B40150 */  ldc1      $f20, 0x150($sp)
/* 3407B4 E002C934 03E00008 */  jr        $ra
/* 3407B8 E002C938 27BD0160 */   addiu    $sp, $sp, 0x160
/* 3407BC E002C93C 00000000 */  nop       
