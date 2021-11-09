.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241500_8D2A10
/* 8D2A10 80241500 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 8D2A14 80241504 0000202D */  daddu     $a0, $zero, $zero
/* 8D2A18 80241508 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2A1C 8024150C AFBF00D8 */  sw        $ra, 0xd8($sp)
/* 8D2A20 80241510 AFB700D4 */  sw        $s7, 0xd4($sp)
/* 8D2A24 80241514 AFB600D0 */  sw        $s6, 0xd0($sp)
/* 8D2A28 80241518 AFB500CC */  sw        $s5, 0xcc($sp)
/* 8D2A2C 8024151C AFB400C8 */  sw        $s4, 0xc8($sp)
/* 8D2A30 80241520 AFB300C4 */  sw        $s3, 0xc4($sp)
/* 8D2A34 80241524 AFB200C0 */  sw        $s2, 0xc0($sp)
/* 8D2A38 80241528 AFB100BC */  sw        $s1, 0xbc($sp)
/* 8D2A3C 8024152C AFB000B8 */  sw        $s0, 0xb8($sp)
/* 8D2A40 80241530 F7B600E8 */  sdc1      $f22, 0xe8($sp)
/* 8D2A44 80241534 F7B400E0 */  sdc1      $f20, 0xe0($sp)
/* 8D2A48 80241538 0C0B1EAF */  jal       evt_get_variable
/* 8D2A4C 8024153C 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 8D2A50 80241540 0000202D */  daddu     $a0, $zero, $zero
/* 8D2A54 80241544 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2A58 80241548 34A50F8B */  ori       $a1, $a1, 0xf8b
/* 8D2A5C 8024154C 0C0B1EAF */  jal       evt_get_variable
/* 8D2A60 80241550 0040B02D */   daddu    $s6, $v0, $zero
/* 8D2A64 80241554 0000202D */  daddu     $a0, $zero, $zero
/* 8D2A68 80241558 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2A6C 8024155C 34A50F8C */  ori       $a1, $a1, 0xf8c
/* 8D2A70 80241560 0C0B1EAF */  jal       evt_get_variable
/* 8D2A74 80241564 0040A82D */   daddu    $s5, $v0, $zero
/* 8D2A78 80241568 24170400 */  addiu     $s7, $zero, 0x400
/* 8D2A7C 8024156C 27B10038 */  addiu     $s1, $sp, 0x38
/* 8D2A80 80241570 0220202D */  daddu     $a0, $s1, $zero
/* 8D2A84 80241574 3C130001 */  lui       $s3, 1
/* 8D2A88 80241578 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 8D2A8C 8024157C 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 8D2A90 80241580 36731630 */  ori       $s3, $s3, 0x1630
/* 8D2A94 80241584 3C03E700 */  lui       $v1, 0xe700
/* 8D2A98 80241588 0040A02D */  daddu     $s4, $v0, $zero
/* 8D2A9C 8024158C 8E480000 */  lw        $t0, ($s2)
/* 8D2AA0 80241590 4480A000 */  mtc1      $zero, $f20
/* 8D2AA4 80241594 0100282D */  daddu     $a1, $t0, $zero
/* 8D2AA8 80241598 ACA30000 */  sw        $v1, ($a1)
/* 8D2AAC 8024159C ACA00004 */  sw        $zero, 4($a1)
/* 8D2AB0 802415A0 8EC50008 */  lw        $a1, 8($s6)
/* 8D2AB4 802415A4 8EC6000C */  lw        $a2, 0xc($s6)
/* 8D2AB8 802415A8 8EC70010 */  lw        $a3, 0x10($s6)
/* 8D2ABC 802415AC 25080008 */  addiu     $t0, $t0, 8
/* 8D2AC0 802415B0 0C019E40 */  jal       guTranslateF
/* 8D2AC4 802415B4 AE480000 */   sw       $t0, ($s2)
/* 8D2AC8 802415B8 27B00078 */  addiu     $s0, $sp, 0x78
/* 8D2ACC 802415BC E7B40010 */  swc1      $f20, 0x10($sp)
/* 8D2AD0 802415C0 8EC50018 */  lw        $a1, 0x18($s6)
/* 8D2AD4 802415C4 3C013F80 */  lui       $at, 0x3f80
/* 8D2AD8 802415C8 4481B000 */  mtc1      $at, $f22
/* 8D2ADC 802415CC 4406A000 */  mfc1      $a2, $f20
/* 8D2AE0 802415D0 4407B000 */  mfc1      $a3, $f22
/* 8D2AE4 802415D4 0C019EC8 */  jal       guRotateF
/* 8D2AE8 802415D8 0200202D */   daddu    $a0, $s0, $zero
/* 8D2AEC 802415DC 0200202D */  daddu     $a0, $s0, $zero
/* 8D2AF0 802415E0 0220282D */  daddu     $a1, $s1, $zero
/* 8D2AF4 802415E4 0C019D80 */  jal       guMtxCatF
/* 8D2AF8 802415E8 0220302D */   daddu    $a2, $s1, $zero
/* 8D2AFC 802415EC E7B40010 */  swc1      $f20, 0x10($sp)
/* 8D2B00 802415F0 8EC50014 */  lw        $a1, 0x14($s6)
/* 8D2B04 802415F4 4406B000 */  mfc1      $a2, $f22
/* 8D2B08 802415F8 4407A000 */  mfc1      $a3, $f20
/* 8D2B0C 802415FC 0C019EC8 */  jal       guRotateF
/* 8D2B10 80241600 0200202D */   daddu    $a0, $s0, $zero
/* 8D2B14 80241604 0200202D */  daddu     $a0, $s0, $zero
/* 8D2B18 80241608 0220282D */  daddu     $a1, $s1, $zero
/* 8D2B1C 8024160C 0C019D80 */  jal       guMtxCatF
/* 8D2B20 80241610 0220302D */   daddu    $a2, $s1, $zero
/* 8D2B24 80241614 8EC5001C */  lw        $a1, 0x1c($s6)
/* 8D2B28 80241618 8EC60020 */  lw        $a2, 0x20($s6)
/* 8D2B2C 8024161C 8EC70024 */  lw        $a3, 0x24($s6)
/* 8D2B30 80241620 0C019DF0 */  jal       guScaleF
/* 8D2B34 80241624 0200202D */   daddu    $a0, $s0, $zero
/* 8D2B38 80241628 0200202D */  daddu     $a0, $s0, $zero
/* 8D2B3C 8024162C 0220282D */  daddu     $a1, $s1, $zero
/* 8D2B40 80241630 0C019D80 */  jal       guMtxCatF
/* 8D2B44 80241634 0220302D */   daddu    $a2, $s1, $zero
/* 8D2B48 80241638 0220202D */  daddu     $a0, $s1, $zero
/* 8D2B4C 8024163C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 8D2B50 80241640 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 8D2B54 80241644 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 8D2B58 80241648 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 8D2B5C 8024164C 96050000 */  lhu       $a1, ($s0)
/* 8D2B60 80241650 8E220000 */  lw        $v0, ($s1)
/* 8D2B64 80241654 00052980 */  sll       $a1, $a1, 6
/* 8D2B68 80241658 00B32821 */  addu      $a1, $a1, $s3
/* 8D2B6C 8024165C 0C019D40 */  jal       guMtxF2L
/* 8D2B70 80241660 00452821 */   addu     $a1, $v0, $a1
/* 8D2B74 80241664 3C04DA38 */  lui       $a0, 0xda38
/* 8D2B78 80241668 34840002 */  ori       $a0, $a0, 2
/* 8D2B7C 8024166C 8E430000 */  lw        $v1, ($s2)
/* 8D2B80 80241670 96020000 */  lhu       $v0, ($s0)
/* 8D2B84 80241674 0060282D */  daddu     $a1, $v1, $zero
/* 8D2B88 80241678 24630008 */  addiu     $v1, $v1, 8
/* 8D2B8C 8024167C AE430000 */  sw        $v1, ($s2)
/* 8D2B90 80241680 24430001 */  addiu     $v1, $v0, 1
/* 8D2B94 80241684 3042FFFF */  andi      $v0, $v0, 0xffff
/* 8D2B98 80241688 00021180 */  sll       $v0, $v0, 6
/* 8D2B9C 8024168C ACA40000 */  sw        $a0, ($a1)
/* 8D2BA0 80241690 A6030000 */  sh        $v1, ($s0)
/* 8D2BA4 80241694 8E230000 */  lw        $v1, ($s1)
/* 8D2BA8 80241698 00531021 */  addu      $v0, $v0, $s3
/* 8D2BAC 8024169C 00621821 */  addu      $v1, $v1, $v0
/* 8D2BB0 802416A0 3C028000 */  lui       $v0, 0x8000
/* 8D2BB4 802416A4 00621821 */  addu      $v1, $v1, $v0
/* 8D2BB8 802416A8 24020020 */  addiu     $v0, $zero, 0x20
/* 8D2BBC 802416AC ACA30004 */  sw        $v1, 4($a1)
/* 8D2BC0 802416B0 A7A20028 */  sh        $v0, 0x28($sp)
/* 8D2BC4 802416B4 A7A2002A */  sh        $v0, 0x2a($sp)
/* 8D2BC8 802416B8 2402FFF0 */  addiu     $v0, $zero, -0x10
/* 8D2BCC 802416BC A7A2002C */  sh        $v0, 0x2c($sp)
/* 8D2BD0 802416C0 24020010 */  addiu     $v0, $zero, 0x10
/* 8D2BD4 802416C4 A7A2002E */  sh        $v0, 0x2e($sp)
/* 8D2BD8 802416C8 240200FF */  addiu     $v0, $zero, 0xff
/* 8D2BDC 802416CC AFB50020 */  sw        $s5, 0x20($sp)
/* 8D2BE0 802416D0 AFB40024 */  sw        $s4, 0x24($sp)
/* 8D2BE4 802416D4 A3A20030 */  sb        $v0, 0x30($sp)
/* 8D2BE8 802416D8 C6C00018 */  lwc1      $f0, 0x18($s6)
/* 8D2BEC 802416DC 44801000 */  mtc1      $zero, $f2
/* 8D2BF0 802416E0 44801800 */  mtc1      $zero, $f3
/* 8D2BF4 802416E4 46000021 */  cvt.d.s   $f0, $f0
/* 8D2BF8 802416E8 46220032 */  c.eq.d    $f0, $f2
/* 8D2BFC 802416EC 00000000 */  nop
/* 8D2C00 802416F0 45020008 */  bc1fl     .L80241714
/* 8D2C04 802416F4 24172400 */   addiu    $s7, $zero, 0x2400
/* 8D2C08 802416F8 C6C00014 */  lwc1      $f0, 0x14($s6)
/* 8D2C0C 802416FC 46000021 */  cvt.d.s   $f0, $f0
/* 8D2C10 80241700 46220032 */  c.eq.d    $f0, $f2
/* 8D2C14 80241704 00000000 */  nop
/* 8D2C18 80241708 45010003 */  bc1t      .L80241718
/* 8D2C1C 8024170C 0000202D */   daddu    $a0, $zero, $zero
/* 8D2C20 80241710 24172400 */  addiu     $s7, $zero, 0x2400
.L80241714:
/* 8D2C24 80241714 0000202D */  daddu     $a0, $zero, $zero
.L80241718:
/* 8D2C28 80241718 0080282D */  daddu     $a1, $a0, $zero
/* 8D2C2C 8024171C 0080302D */  daddu     $a2, $a0, $zero
/* 8D2C30 80241720 0080382D */  daddu     $a3, $a0, $zero
/* 8D2C34 80241724 AFA00010 */  sw        $zero, 0x10($sp)
/* 8D2C38 80241728 AFA00014 */  sw        $zero, 0x14($sp)
/* 8D2C3C 8024172C 0C04EAA7 */  jal       sprfx_update
/* 8D2C40 80241730 AFA00018 */   sw       $zero, 0x18($sp)
/* 8D2C44 80241734 0000202D */  daddu     $a0, $zero, $zero
/* 8D2C48 80241738 27A50020 */  addiu     $a1, $sp, 0x20
/* 8D2C4C 8024173C 02E0302D */  daddu     $a2, $s7, $zero
/* 8D2C50 80241740 0C04EBDC */  jal       sprfx_appendGfx_component
/* 8D2C54 80241744 27A70038 */   addiu    $a3, $sp, 0x38
/* 8D2C58 80241748 3C05D838 */  lui       $a1, 0xd838
/* 8D2C5C 8024174C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8D2C60 80241750 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8D2C64 80241754 8C620000 */  lw        $v0, ($v1)
/* 8D2C68 80241758 34A50002 */  ori       $a1, $a1, 2
/* 8D2C6C 8024175C 0040202D */  daddu     $a0, $v0, $zero
/* 8D2C70 80241760 24420008 */  addiu     $v0, $v0, 8
/* 8D2C74 80241764 AC620000 */  sw        $v0, ($v1)
/* 8D2C78 80241768 24020040 */  addiu     $v0, $zero, 0x40
/* 8D2C7C 8024176C AC850000 */  sw        $a1, ($a0)
/* 8D2C80 80241770 AC820004 */  sw        $v0, 4($a0)
/* 8D2C84 80241774 8FBF00D8 */  lw        $ra, 0xd8($sp)
/* 8D2C88 80241778 8FB700D4 */  lw        $s7, 0xd4($sp)
/* 8D2C8C 8024177C 8FB600D0 */  lw        $s6, 0xd0($sp)
/* 8D2C90 80241780 8FB500CC */  lw        $s5, 0xcc($sp)
/* 8D2C94 80241784 8FB400C8 */  lw        $s4, 0xc8($sp)
/* 8D2C98 80241788 8FB300C4 */  lw        $s3, 0xc4($sp)
/* 8D2C9C 8024178C 8FB200C0 */  lw        $s2, 0xc0($sp)
/* 8D2CA0 80241790 8FB100BC */  lw        $s1, 0xbc($sp)
/* 8D2CA4 80241794 8FB000B8 */  lw        $s0, 0xb8($sp)
/* 8D2CA8 80241798 D7B600E8 */  ldc1      $f22, 0xe8($sp)
/* 8D2CAC 8024179C D7B400E0 */  ldc1      $f20, 0xe0($sp)
/* 8D2CB0 802417A0 03E00008 */  jr        $ra
/* 8D2CB4 802417A4 27BD00F0 */   addiu    $sp, $sp, 0xf0
