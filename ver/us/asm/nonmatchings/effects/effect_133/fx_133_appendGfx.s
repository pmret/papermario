.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_133_appendGfx
/* 41384C E01264EC 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 413850 E01264F0 0080302D */  daddu     $a2, $a0, $zero
/* 413854 E01264F4 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 413858 E01264F8 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 41385C E01264FC AFB700CC */  sw        $s7, 0xcc($sp)
/* 413860 E0126500 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 413864 E0126504 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 413868 E0126508 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 41386C E012650C AFB300BC */  sw        $s3, 0xbc($sp)
/* 413870 E0126510 AFB200B8 */  sw        $s2, 0xb8($sp)
/* 413874 E0126514 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 413878 E0126518 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 41387C E012651C F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 413880 E0126520 8CD3000C */  lw        $s3, 0xc($a2)
/* 413884 E0126524 8E690024 */  lw        $t1, 0x24($s3)
/* 413888 E0126528 8E760018 */  lw        $s6, 0x18($s3)
/* 41388C E012652C 8E77001C */  lw        $s7, 0x1c($s3)
/* 413890 E0126530 8E7E0020 */  lw        $fp, 0x20($s3)
/* 413894 E0126534 AFA900A0 */  sw        $t1, 0xa0($sp)
/* 413898 E0126538 8E690028 */  lw        $t1, 0x28($s3)
/* 41389C E012653C AFA900A4 */  sw        $t1, 0xa4($sp)
/* 4138A0 E0126540 8E69002C */  lw        $t1, 0x2c($s3)
/* 4138A4 E0126544 AFA900A8 */  sw        $t1, 0xa8($sp)
/* 4138A8 E0126548 8E690030 */  lw        $t1, 0x30($s3)
/* 4138AC E012654C 2AC20100 */  slti      $v0, $s6, 0x100
/* 4138B0 E0126550 AFA900AC */  sw        $t1, 0xac($sp)
/* 4138B4 E0126554 8E750034 */  lw        $s5, 0x34($s3)
/* 4138B8 E0126558 50400001 */  beql      $v0, $zero, .LE0126560
/* 4138BC E012655C 241600FF */   addiu    $s6, $zero, 0xff
.LE0126560:
/* 4138C0 E0126560 2AE20100 */  slti      $v0, $s7, 0x100
/* 4138C4 E0126564 50400001 */  beql      $v0, $zero, .LE012656C
/* 4138C8 E0126568 241700FF */   addiu    $s7, $zero, 0xff
.LE012656C:
/* 4138CC E012656C 2BC20100 */  slti      $v0, $fp, 0x100
/* 4138D0 E0126570 50400001 */  beql      $v0, $zero, .LE0126578
/* 4138D4 E0126574 241E00FF */   addiu    $fp, $zero, 0xff
.LE0126578:
/* 4138D8 E0126578 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 4138DC E012657C 29220100 */  slti      $v0, $t1, 0x100
/* 4138E0 E0126580 14400002 */  bnez      $v0, .LE012658C
/* 4138E4 E0126584 240900FF */   addiu    $t1, $zero, 0xff
/* 4138E8 E0126588 AFA900A0 */  sw        $t1, 0xa0($sp)
.LE012658C:
/* 4138EC E012658C 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 4138F0 E0126590 29220100 */  slti      $v0, $t1, 0x100
/* 4138F4 E0126594 14400002 */  bnez      $v0, .LE01265A0
/* 4138F8 E0126598 240900FF */   addiu    $t1, $zero, 0xff
/* 4138FC E012659C AFA900A4 */  sw        $t1, 0xa4($sp)
.LE01265A0:
/* 413900 E01265A0 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 413904 E01265A4 29220100 */  slti      $v0, $t1, 0x100
/* 413908 E01265A8 14400002 */  bnez      $v0, .LE01265B4
/* 41390C E01265AC 240900FF */   addiu    $t1, $zero, 0xff
/* 413910 E01265B0 AFA900A8 */  sw        $t1, 0xa8($sp)
.LE01265B4:
/* 413914 E01265B4 8FA900AC */  lw        $t1, 0xac($sp)
/* 413918 E01265B8 29220100 */  slti      $v0, $t1, 0x100
/* 41391C E01265BC 14400003 */  bnez      $v0, .LE01265CC
/* 413920 E01265C0 2AA20100 */   slti     $v0, $s5, 0x100
/* 413924 E01265C4 240900FF */  addiu     $t1, $zero, 0xff
/* 413928 E01265C8 AFA900AC */  sw        $t1, 0xac($sp)
.LE01265CC:
/* 41392C E01265CC 50400001 */  beql      $v0, $zero, .LE01265D4
/* 413930 E01265D0 241500FF */   addiu    $s5, $zero, 0xff
.LE01265D4:
/* 413934 E01265D4 06C20001 */  bltzl     $s6, .LE01265DC
/* 413938 E01265D8 0000B02D */   daddu    $s6, $zero, $zero
.LE01265DC:
/* 41393C E01265DC 06E20001 */  bltzl     $s7, .LE01265E4
/* 413940 E01265E0 0000B82D */   daddu    $s7, $zero, $zero
.LE01265E4:
/* 413944 E01265E4 07C20001 */  bltzl     $fp, .LE01265EC
/* 413948 E01265E8 0000F02D */   daddu    $fp, $zero, $zero
.LE01265EC:
/* 41394C E01265EC 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 413950 E01265F0 05220001 */  bltzl     $t1, .LE01265F8
/* 413954 E01265F4 AFA000A0 */   sw       $zero, 0xa0($sp)
.LE01265F8:
/* 413958 E01265F8 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 41395C E01265FC 05220001 */  bltzl     $t1, .LE0126604
/* 413960 E0126600 AFA000A4 */   sw       $zero, 0xa4($sp)
.LE0126604:
/* 413964 E0126604 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 413968 E0126608 05220001 */  bltzl     $t1, .LE0126610
/* 41396C E012660C AFA000A8 */   sw       $zero, 0xa8($sp)
.LE0126610:
/* 413970 E0126610 8FA900AC */  lw        $t1, 0xac($sp)
/* 413974 E0126614 05220001 */  bltzl     $t1, .LE012661C
/* 413978 E0126618 AFA000AC */   sw       $zero, 0xac($sp)
.LE012661C:
/* 41397C E012661C 06A20001 */  bltzl     $s5, .LE0126624
/* 413980 E0126620 0000A82D */   daddu    $s5, $zero, $zero
.LE0126624:
/* 413984 E0126624 3C05DB06 */  lui       $a1, 0xdb06
/* 413988 E0126628 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 41398C E012662C 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 413990 E0126630 34A50024 */  ori       $a1, $a1, 0x24
/* 413994 E0126634 8E840000 */  lw        $a0, ($s4)
/* 413998 E0126638 3C02E700 */  lui       $v0, 0xe700
/* 41399C E012663C 0080182D */  daddu     $v1, $a0, $zero
/* 4139A0 E0126640 24840008 */  addiu     $a0, $a0, 8
/* 4139A4 E0126644 AE840000 */  sw        $a0, ($s4)
/* 4139A8 E0126648 AC620000 */  sw        $v0, ($v1)
/* 4139AC E012664C AC600004 */  sw        $zero, 4($v1)
/* 4139B0 E0126650 AC850000 */  sw        $a1, ($a0)
/* 4139B4 E0126654 8CC30010 */  lw        $v1, 0x10($a2)
/* 4139B8 E0126658 24820008 */  addiu     $v0, $a0, 8
/* 4139BC E012665C AE820000 */  sw        $v0, ($s4)
/* 4139C0 E0126660 8C63001C */  lw        $v1, 0x1c($v1)
/* 4139C4 E0126664 3C02DE00 */  lui       $v0, 0xde00
/* 4139C8 E0126668 AC820008 */  sw        $v0, 8($a0)
/* 4139CC E012666C 3C028000 */  lui       $v0, 0x8000
/* 4139D0 E0126670 00621821 */  addu      $v1, $v1, $v0
/* 4139D4 E0126674 AC830004 */  sw        $v1, 4($a0)
/* 4139D8 E0126678 3C03E012 */  lui       $v1, %hi(D_E0126BC8)
/* 4139DC E012667C 8C636BC8 */  lw        $v1, %lo(D_E0126BC8)($v1)
/* 4139E0 E0126680 24820010 */  addiu     $v0, $a0, 0x10
/* 4139E4 E0126684 AE820000 */  sw        $v0, ($s4)
/* 4139E8 E0126688 12A0008F */  beqz      $s5, .LE01268C8
/* 4139EC E012668C AC83000C */   sw       $v1, 0xc($a0)
/* 4139F0 E0126690 4480A000 */  mtc1      $zero, $f20
/* 4139F4 E0126694 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 4139F8 E0126698 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 4139FC E012669C C6600054 */  lwc1      $f0, 0x54($s3)
/* 413A00 E01266A0 3C01E012 */  lui       $at, %hi(D_E0126C30)
/* 413A04 E01266A4 D4226C30 */  ldc1      $f2, %lo(D_E0126C30)($at)
/* 413A08 E01266A8 00031080 */  sll       $v0, $v1, 2
/* 413A0C E01266AC 46000021 */  cvt.d.s   $f0, $f0
/* 413A10 E01266B0 00431021 */  addu      $v0, $v0, $v1
/* 413A14 E01266B4 00021080 */  sll       $v0, $v0, 2
/* 413A18 E01266B8 46220002 */  mul.d     $f0, $f0, $f2
/* 413A1C E01266BC 00000000 */  nop
/* 413A20 E01266C0 00431023 */  subu      $v0, $v0, $v1
/* 413A24 E01266C4 000218C0 */  sll       $v1, $v0, 3
/* 413A28 E01266C8 00431021 */  addu      $v0, $v0, $v1
/* 413A2C E01266CC 000210C0 */  sll       $v0, $v0, 3
/* 413A30 E01266D0 4405A000 */  mfc1      $a1, $f20
/* 413A34 E01266D4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 413A38 E01266D8 00220821 */  addu      $at, $at, $v0
/* 413A3C E01266DC C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 413A40 E01266E0 4407A000 */  mfc1      $a3, $f20
/* 413A44 E01266E4 46001087 */  neg.s     $f2, $f2
/* 413A48 E01266E8 44061000 */  mfc1      $a2, $f2
/* 413A4C E01266EC 46200020 */  cvt.s.d   $f0, $f0
/* 413A50 E01266F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 413A54 E01266F4 C6600004 */  lwc1      $f0, 4($s3)
/* 413A58 E01266F8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 413A5C E01266FC C6600008 */  lwc1      $f0, 8($s3)
/* 413A60 E0126700 27A40020 */  addiu     $a0, $sp, 0x20
/* 413A64 E0126704 E7A00018 */  swc1      $f0, 0x18($sp)
/* 413A68 E0126708 C660000C */  lwc1      $f0, 0xc($s3)
/* 413A6C E012670C 3C120001 */  lui       $s2, 1
/* 413A70 E0126710 0C080180 */  jal       shim_guPositionF
/* 413A74 E0126714 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 413A78 E0126718 36521630 */  ori       $s2, $s2, 0x1630
/* 413A7C E012671C 3C013F80 */  lui       $at, 0x3f80
/* 413A80 E0126720 44810000 */  mtc1      $at, $f0
/* 413A84 E0126724 27B00060 */  addiu     $s0, $sp, 0x60
/* 413A88 E0126728 E7B40014 */  swc1      $f20, 0x14($sp)
/* 413A8C E012672C E7B40018 */  swc1      $f20, 0x18($sp)
/* 413A90 E0126730 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 413A94 E0126734 E7A00010 */  swc1      $f0, 0x10($sp)
/* 413A98 E0126738 8E650048 */  lw        $a1, 0x48($s3)
/* 413A9C E012673C 8E66004C */  lw        $a2, 0x4c($s3)
/* 413AA0 E0126740 8E670050 */  lw        $a3, 0x50($s3)
/* 413AA4 E0126744 0C080180 */  jal       shim_guPositionF
/* 413AA8 E0126748 0200202D */   daddu    $a0, $s0, $zero
/* 413AAC E012674C 0200202D */  daddu     $a0, $s0, $zero
/* 413AB0 E0126750 27A50020 */  addiu     $a1, $sp, 0x20
/* 413AB4 E0126754 0C080114 */  jal       shim_guMtxCatF
/* 413AB8 E0126758 00A0302D */   daddu    $a2, $a1, $zero
/* 413ABC E012675C 27A40020 */  addiu     $a0, $sp, 0x20
/* 413AC0 E0126760 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 413AC4 E0126764 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 413AC8 E0126768 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 413ACC E012676C 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 413AD0 E0126770 96050000 */  lhu       $a1, ($s0)
/* 413AD4 E0126774 8E220000 */  lw        $v0, ($s1)
/* 413AD8 E0126778 00052980 */  sll       $a1, $a1, 6
/* 413ADC E012677C 00B22821 */  addu      $a1, $a1, $s2
/* 413AE0 E0126780 0C080118 */  jal       shim_guMtxF2L
/* 413AE4 E0126784 00452821 */   addu     $a1, $v0, $a1
/* 413AE8 E0126788 3C02DA38 */  lui       $v0, 0xda38
/* 413AEC E012678C 34420002 */  ori       $v0, $v0, 2
/* 413AF0 E0126790 8E860000 */  lw        $a2, ($s4)
/* 413AF4 E0126794 96040000 */  lhu       $a0, ($s0)
/* 413AF8 E0126798 00C0282D */  daddu     $a1, $a2, $zero
/* 413AFC E012679C 24C60008 */  addiu     $a2, $a2, 8
/* 413B00 E01267A0 AE860000 */  sw        $a2, ($s4)
/* 413B04 E01267A4 ACA20000 */  sw        $v0, ($a1)
/* 413B08 E01267A8 3082FFFF */  andi      $v0, $a0, 0xffff
/* 413B0C E01267AC 00021180 */  sll       $v0, $v0, 6
/* 413B10 E01267B0 8E230000 */  lw        $v1, ($s1)
/* 413B14 E01267B4 00521021 */  addu      $v0, $v0, $s2
/* 413B18 E01267B8 00621821 */  addu      $v1, $v1, $v0
/* 413B1C E01267BC ACA30004 */  sw        $v1, 4($a1)
/* 413B20 E01267C0 86620000 */  lh        $v0, ($s3)
/* 413B24 E01267C4 24840001 */  addiu     $a0, $a0, 1
/* 413B28 E01267C8 14400006 */  bnez      $v0, .LE01267E4
/* 413B2C E01267CC A6040000 */   sh       $a0, ($s0)
/* 413B30 E01267D0 3C04E200 */  lui       $a0, 0xe200
/* 413B34 E01267D4 3484001C */  ori       $a0, $a0, 0x1c
/* 413B38 E01267D8 3C030050 */  lui       $v1, 0x50
/* 413B3C E01267DC 080499FD */  j         .LE01267F4
/* 413B40 E01267E0 34634340 */   ori      $v1, $v1, 0x4340
.LE01267E4:
/* 413B44 E01267E4 3C04E200 */  lui       $a0, 0xe200
/* 413B48 E01267E8 3484001C */  ori       $a0, $a0, 0x1c
/* 413B4C E01267EC 3C030050 */  lui       $v1, 0x50
/* 413B50 E01267F0 34634B50 */  ori       $v1, $v1, 0x4b50
.LE01267F4:
/* 413B54 E01267F4 24C20008 */  addiu     $v0, $a2, 8
/* 413B58 E01267F8 AE820000 */  sw        $v0, ($s4)
/* 413B5C E01267FC ACC40000 */  sw        $a0, ($a2)
/* 413B60 E0126800 ACC30004 */  sw        $v1, 4($a2)
/* 413B64 E0126804 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 413B68 E0126808 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 413B6C E012680C 3C02FA00 */  lui       $v0, 0xfa00
/* 413B70 E0126810 00161E00 */  sll       $v1, $s6, 0x18
/* 413B74 E0126814 00152843 */  sra       $a1, $s5, 1
/* 413B78 E0126818 8CC40000 */  lw        $a0, ($a2)
/* 413B7C E012681C 30A500FF */  andi      $a1, $a1, 0xff
/* 413B80 E0126820 0080382D */  daddu     $a3, $a0, $zero
/* 413B84 E0126824 24840008 */  addiu     $a0, $a0, 8
/* 413B88 E0126828 ACC40000 */  sw        $a0, ($a2)
/* 413B8C E012682C ACE20000 */  sw        $v0, ($a3)
/* 413B90 E0126830 32E200FF */  andi      $v0, $s7, 0xff
/* 413B94 E0126834 00021400 */  sll       $v0, $v0, 0x10
/* 413B98 E0126838 00621825 */  or        $v1, $v1, $v0
/* 413B9C E012683C 33C200FF */  andi      $v0, $fp, 0xff
/* 413BA0 E0126840 00021200 */  sll       $v0, $v0, 8
/* 413BA4 E0126844 00621825 */  or        $v1, $v1, $v0
/* 413BA8 E0126848 00651825 */  or        $v1, $v1, $a1
/* 413BAC E012684C 24820008 */  addiu     $v0, $a0, 8
/* 413BB0 E0126850 ACE30004 */  sw        $v1, 4($a3)
/* 413BB4 E0126854 ACC20000 */  sw        $v0, ($a2)
/* 413BB8 E0126858 3C02FB00 */  lui       $v0, 0xfb00
/* 413BBC E012685C AC820000 */  sw        $v0, ($a0)
/* 413BC0 E0126860 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 413BC4 E0126864 3C08D838 */  lui       $t0, 0xd838
/* 413BC8 E0126868 00091E00 */  sll       $v1, $t1, 0x18
/* 413BCC E012686C 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 413BD0 E0126870 35080002 */  ori       $t0, $t0, 2
/* 413BD4 E0126874 312200FF */  andi      $v0, $t1, 0xff
/* 413BD8 E0126878 00021400 */  sll       $v0, $v0, 0x10
/* 413BDC E012687C 8FA900AC */  lw        $t1, 0xac($sp)
/* 413BE0 E0126880 00621825 */  or        $v1, $v1, $v0
/* 413BE4 E0126884 312200FF */  andi      $v0, $t1, 0xff
/* 413BE8 E0126888 00021200 */  sll       $v0, $v0, 8
/* 413BEC E012688C 00621825 */  or        $v1, $v1, $v0
/* 413BF0 E0126890 00651825 */  or        $v1, $v1, $a1
/* 413BF4 E0126894 24820010 */  addiu     $v0, $a0, 0x10
/* 413BF8 E0126898 AC830004 */  sw        $v1, 4($a0)
/* 413BFC E012689C ACC20000 */  sw        $v0, ($a2)
/* 413C00 E01268A0 3C02DE00 */  lui       $v0, 0xde00
/* 413C04 E01268A4 AC820008 */  sw        $v0, 8($a0)
/* 413C08 E01268A8 3C03E012 */  lui       $v1, %hi(D_E0126BC4)
/* 413C0C E01268AC 8C636BC4 */  lw        $v1, %lo(D_E0126BC4)($v1)
/* 413C10 E01268B0 24820018 */  addiu     $v0, $a0, 0x18
/* 413C14 E01268B4 ACC20000 */  sw        $v0, ($a2)
/* 413C18 E01268B8 24020040 */  addiu     $v0, $zero, 0x40
/* 413C1C E01268BC AC880010 */  sw        $t0, 0x10($a0)
/* 413C20 E01268C0 AC820014 */  sw        $v0, 0x14($a0)
/* 413C24 E01268C4 AC83000C */  sw        $v1, 0xc($a0)
.LE01268C8:
/* 413C28 E01268C8 4480A000 */  mtc1      $zero, $f20
/* 413C2C E01268CC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 413C30 E01268D0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 413C34 E01268D4 C6600038 */  lwc1      $f0, 0x38($s3)
/* 413C38 E01268D8 3C01E012 */  lui       $at, %hi(D_E0126C38)
/* 413C3C E01268DC D4226C38 */  ldc1      $f2, %lo(D_E0126C38)($at)
/* 413C40 E01268E0 00031080 */  sll       $v0, $v1, 2
/* 413C44 E01268E4 46000021 */  cvt.d.s   $f0, $f0
/* 413C48 E01268E8 00431021 */  addu      $v0, $v0, $v1
/* 413C4C E01268EC 00021080 */  sll       $v0, $v0, 2
/* 413C50 E01268F0 46220002 */  mul.d     $f0, $f0, $f2
/* 413C54 E01268F4 00000000 */  nop
/* 413C58 E01268F8 00431023 */  subu      $v0, $v0, $v1
/* 413C5C E01268FC 000218C0 */  sll       $v1, $v0, 3
/* 413C60 E0126900 00431021 */  addu      $v0, $v0, $v1
/* 413C64 E0126904 000210C0 */  sll       $v0, $v0, 3
/* 413C68 E0126908 4405A000 */  mfc1      $a1, $f20
/* 413C6C E012690C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 413C70 E0126910 00220821 */  addu      $at, $at, $v0
/* 413C74 E0126914 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 413C78 E0126918 4407A000 */  mfc1      $a3, $f20
/* 413C7C E012691C 46001087 */  neg.s     $f2, $f2
/* 413C80 E0126920 44061000 */  mfc1      $a2, $f2
/* 413C84 E0126924 46200020 */  cvt.s.d   $f0, $f0
/* 413C88 E0126928 E7A00010 */  swc1      $f0, 0x10($sp)
/* 413C8C E012692C C6600004 */  lwc1      $f0, 4($s3)
/* 413C90 E0126930 E7A00014 */  swc1      $f0, 0x14($sp)
/* 413C94 E0126934 C6600008 */  lwc1      $f0, 8($s3)
/* 413C98 E0126938 27A40020 */  addiu     $a0, $sp, 0x20
/* 413C9C E012693C E7A00018 */  swc1      $f0, 0x18($sp)
/* 413CA0 E0126940 C660000C */  lwc1      $f0, 0xc($s3)
/* 413CA4 E0126944 3C120001 */  lui       $s2, 1
/* 413CA8 E0126948 0C080180 */  jal       shim_guPositionF
/* 413CAC E012694C E7A0001C */   swc1     $f0, 0x1c($sp)
/* 413CB0 E0126950 36521630 */  ori       $s2, $s2, 0x1630
/* 413CB4 E0126954 3C013F80 */  lui       $at, 0x3f80
/* 413CB8 E0126958 44810000 */  mtc1      $at, $f0
/* 413CBC E012695C 27B00060 */  addiu     $s0, $sp, 0x60
/* 413CC0 E0126960 E7B40014 */  swc1      $f20, 0x14($sp)
/* 413CC4 E0126964 E7B40018 */  swc1      $f20, 0x18($sp)
/* 413CC8 E0126968 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 413CCC E012696C E7A00010 */  swc1      $f0, 0x10($sp)
/* 413CD0 E0126970 8E65003C */  lw        $a1, 0x3c($s3)
/* 413CD4 E0126974 8E660040 */  lw        $a2, 0x40($s3)
/* 413CD8 E0126978 8E670044 */  lw        $a3, 0x44($s3)
/* 413CDC E012697C 0C080180 */  jal       shim_guPositionF
/* 413CE0 E0126980 0200202D */   daddu    $a0, $s0, $zero
/* 413CE4 E0126984 0200202D */  daddu     $a0, $s0, $zero
/* 413CE8 E0126988 27A50020 */  addiu     $a1, $sp, 0x20
/* 413CEC E012698C 0C080114 */  jal       shim_guMtxCatF
/* 413CF0 E0126990 00A0302D */   daddu    $a2, $a1, $zero
/* 413CF4 E0126994 27A40020 */  addiu     $a0, $sp, 0x20
/* 413CF8 E0126998 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 413CFC E012699C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 413D00 E01269A0 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 413D04 E01269A4 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 413D08 E01269A8 96050000 */  lhu       $a1, ($s0)
/* 413D0C E01269AC 8E220000 */  lw        $v0, ($s1)
/* 413D10 E01269B0 00052980 */  sll       $a1, $a1, 6
/* 413D14 E01269B4 00B22821 */  addu      $a1, $a1, $s2
/* 413D18 E01269B8 0C080118 */  jal       shim_guMtxF2L
/* 413D1C E01269BC 00452821 */   addu     $a1, $v0, $a1
/* 413D20 E01269C0 3C03DA38 */  lui       $v1, 0xda38
/* 413D24 E01269C4 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 413D28 E01269C8 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 413D2C E01269CC 34630002 */  ori       $v1, $v1, 2
/* 413D30 E01269D0 8CC50000 */  lw        $a1, ($a2)
/* 413D34 E01269D4 96020000 */  lhu       $v0, ($s0)
/* 413D38 E01269D8 00A0202D */  daddu     $a0, $a1, $zero
/* 413D3C E01269DC 24A50008 */  addiu     $a1, $a1, 8
/* 413D40 E01269E0 ACC50000 */  sw        $a1, ($a2)
/* 413D44 E01269E4 AC830000 */  sw        $v1, ($a0)
/* 413D48 E01269E8 24430001 */  addiu     $v1, $v0, 1
/* 413D4C E01269EC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 413D50 E01269F0 00021180 */  sll       $v0, $v0, 6
/* 413D54 E01269F4 A6030000 */  sh        $v1, ($s0)
/* 413D58 E01269F8 8E230000 */  lw        $v1, ($s1)
/* 413D5C E01269FC 00521021 */  addu      $v0, $v0, $s2
/* 413D60 E0126A00 00621821 */  addu      $v1, $v1, $v0
/* 413D64 E0126A04 12A0001A */  beqz      $s5, .LE0126A70
/* 413D68 E0126A08 AC830004 */   sw       $v1, 4($a0)
/* 413D6C E0126A0C 86620000 */  lh        $v0, ($s3)
/* 413D70 E0126A10 14400005 */  bnez      $v0, .LE0126A28
/* 413D74 E0126A14 3C04E200 */   lui      $a0, 0xe200
/* 413D78 E0126A18 3484001C */  ori       $a0, $a0, 0x1c
/* 413D7C E0126A1C 3C030050 */  lui       $v1, 0x50
/* 413D80 E0126A20 08049A8D */  j         .LE0126A34
/* 413D84 E0126A24 34634340 */   ori      $v1, $v1, 0x4340
.LE0126A28:
/* 413D88 E0126A28 3484001C */  ori       $a0, $a0, 0x1c
/* 413D8C E0126A2C 3C030050 */  lui       $v1, 0x50
/* 413D90 E0126A30 34634B50 */  ori       $v1, $v1, 0x4b50
.LE0126A34:
/* 413D94 E0126A34 24A20008 */  addiu     $v0, $a1, 8
/* 413D98 E0126A38 ACC20000 */  sw        $v0, ($a2)
/* 413D9C E0126A3C ACA40000 */  sw        $a0, ($a1)
/* 413DA0 E0126A40 ACA30004 */  sw        $v1, 4($a1)
/* 413DA4 E0126A44 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 413DA8 E0126A48 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 413DAC E0126A4C 8CA30000 */  lw        $v1, ($a1)
/* 413DB0 E0126A50 3C02DE00 */  lui       $v0, 0xde00
/* 413DB4 E0126A54 0060202D */  daddu     $a0, $v1, $zero
/* 413DB8 E0126A58 AC820000 */  sw        $v0, ($a0)
/* 413DBC E0126A5C 3C02E012 */  lui       $v0, %hi(D_E0126BC4)
/* 413DC0 E0126A60 8C426BC4 */  lw        $v0, %lo(D_E0126BC4)($v0)
/* 413DC4 E0126A64 24630008 */  addiu     $v1, $v1, 8
/* 413DC8 E0126A68 ACA30000 */  sw        $v1, ($a1)
/* 413DCC E0126A6C AC820004 */  sw        $v0, 4($a0)
.LE0126A70:
/* 413DD0 E0126A70 86620000 */  lh        $v0, ($s3)
/* 413DD4 E0126A74 14400008 */  bnez      $v0, .LE0126A98
/* 413DD8 E0126A78 3C06E200 */   lui      $a2, 0xe200
/* 413DDC E0126A7C 34C6001C */  ori       $a2, $a2, 0x1c
/* 413DE0 E0126A80 3C050050 */  lui       $a1, 0x50
/* 413DE4 E0126A84 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 413DE8 E0126A88 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 413DEC E0126A8C 8C820000 */  lw        $v0, ($a0)
/* 413DF0 E0126A90 08049AAC */  j         .LE0126AB0
/* 413DF4 E0126A94 34A541C8 */   ori      $a1, $a1, 0x41c8
.LE0126A98:
/* 413DF8 E0126A98 34C6001C */  ori       $a2, $a2, 0x1c
/* 413DFC E0126A9C 3C050050 */  lui       $a1, 0x50
/* 413E00 E0126AA0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 413E04 E0126AA4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 413E08 E0126AA8 8C820000 */  lw        $v0, ($a0)
/* 413E0C E0126AAC 34A549D8 */  ori       $a1, $a1, 0x49d8
.LE0126AB0:
/* 413E10 E0126AB0 0040182D */  daddu     $v1, $v0, $zero
/* 413E14 E0126AB4 24420008 */  addiu     $v0, $v0, 8
/* 413E18 E0126AB8 AC820000 */  sw        $v0, ($a0)
/* 413E1C E0126ABC AC660000 */  sw        $a2, ($v1)
/* 413E20 E0126AC0 AC650004 */  sw        $a1, 4($v1)
/* 413E24 E0126AC4 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 413E28 E0126AC8 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 413E2C E0126ACC 3C02FA00 */  lui       $v0, 0xfa00
/* 413E30 E0126AD0 8CA40000 */  lw        $a0, ($a1)
/* 413E34 E0126AD4 00161E00 */  sll       $v1, $s6, 0x18
/* 413E38 E0126AD8 0080302D */  daddu     $a2, $a0, $zero
/* 413E3C E0126ADC 24840008 */  addiu     $a0, $a0, 8
/* 413E40 E0126AE0 ACA40000 */  sw        $a0, ($a1)
/* 413E44 E0126AE4 ACC20000 */  sw        $v0, ($a2)
/* 413E48 E0126AE8 32E200FF */  andi      $v0, $s7, 0xff
/* 413E4C E0126AEC 00021400 */  sll       $v0, $v0, 0x10
/* 413E50 E0126AF0 00621825 */  or        $v1, $v1, $v0
/* 413E54 E0126AF4 33C200FF */  andi      $v0, $fp, 0xff
/* 413E58 E0126AF8 00021200 */  sll       $v0, $v0, 8
/* 413E5C E0126AFC 00621825 */  or        $v1, $v1, $v0
/* 413E60 E0126B00 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 413E64 E0126B04 24820008 */  addiu     $v0, $a0, 8
/* 413E68 E0126B08 312700FF */  andi      $a3, $t1, 0xff
/* 413E6C E0126B0C 00671825 */  or        $v1, $v1, $a3
/* 413E70 E0126B10 ACC30004 */  sw        $v1, 4($a2)
/* 413E74 E0126B14 ACA20000 */  sw        $v0, ($a1)
/* 413E78 E0126B18 3C02FB00 */  lui       $v0, 0xfb00
/* 413E7C E0126B1C AC820000 */  sw        $v0, ($a0)
/* 413E80 E0126B20 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 413E84 E0126B24 3C08D838 */  lui       $t0, 0xd838
/* 413E88 E0126B28 00091E00 */  sll       $v1, $t1, 0x18
/* 413E8C E0126B2C 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 413E90 E0126B30 35080002 */  ori       $t0, $t0, 2
/* 413E94 E0126B34 312200FF */  andi      $v0, $t1, 0xff
/* 413E98 E0126B38 00021400 */  sll       $v0, $v0, 0x10
/* 413E9C E0126B3C 8FA900AC */  lw        $t1, 0xac($sp)
/* 413EA0 E0126B40 00621825 */  or        $v1, $v1, $v0
/* 413EA4 E0126B44 312200FF */  andi      $v0, $t1, 0xff
/* 413EA8 E0126B48 00021200 */  sll       $v0, $v0, 8
/* 413EAC E0126B4C 00621825 */  or        $v1, $v1, $v0
/* 413EB0 E0126B50 00671825 */  or        $v1, $v1, $a3
/* 413EB4 E0126B54 24820010 */  addiu     $v0, $a0, 0x10
/* 413EB8 E0126B58 AC830004 */  sw        $v1, 4($a0)
/* 413EBC E0126B5C ACA20000 */  sw        $v0, ($a1)
/* 413EC0 E0126B60 3C02DE00 */  lui       $v0, 0xde00
/* 413EC4 E0126B64 AC820008 */  sw        $v0, 8($a0)
/* 413EC8 E0126B68 3C03E012 */  lui       $v1, %hi(D_E0126BC0)
/* 413ECC E0126B6C 8C636BC0 */  lw        $v1, %lo(D_E0126BC0)($v1)
/* 413ED0 E0126B70 24820018 */  addiu     $v0, $a0, 0x18
/* 413ED4 E0126B74 ACA20000 */  sw        $v0, ($a1)
/* 413ED8 E0126B78 24020040 */  addiu     $v0, $zero, 0x40
/* 413EDC E0126B7C AC880010 */  sw        $t0, 0x10($a0)
/* 413EE0 E0126B80 AC820014 */  sw        $v0, 0x14($a0)
/* 413EE4 E0126B84 AC83000C */  sw        $v1, 0xc($a0)
/* 413EE8 E0126B88 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 413EEC E0126B8C 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 413EF0 E0126B90 8FB700CC */  lw        $s7, 0xcc($sp)
/* 413EF4 E0126B94 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 413EF8 E0126B98 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 413EFC E0126B9C 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 413F00 E0126BA0 8FB300BC */  lw        $s3, 0xbc($sp)
/* 413F04 E0126BA4 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 413F08 E0126BA8 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 413F0C E0126BAC 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 413F10 E0126BB0 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 413F14 E0126BB4 03E00008 */  jr        $ra
/* 413F18 E0126BB8 27BD00E0 */   addiu    $sp, $sp, 0xe0
/* 413F1C E0126BBC 00000000 */  nop
