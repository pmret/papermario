.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010C39C
/* 3E585C E010C39C 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3E5860 E010C3A0 3C07DB06 */  lui       $a3, 0xdb06
/* 3E5864 E010C3A4 34E70024 */  ori       $a3, $a3, 0x24
/* 3E5868 E010C3A8 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 3E586C E010C3AC 0000982D */  daddu     $s3, $zero, $zero
/* 3E5870 E010C3B0 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 3E5874 E010C3B4 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 3E5878 E010C3B8 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 3E587C E010C3BC AFB500BC */  sw        $s5, 0xbc($sp)
/* 3E5880 E010C3C0 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 3E5884 E010C3C4 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 3E5888 E010C3C8 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 3E588C E010C3CC 3C140001 */  lui       $s4, 1
/* 3E5890 E010C3D0 36941630 */  ori       $s4, $s4, 0x1630
/* 3E5894 E010C3D4 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3E5898 E010C3D8 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3E589C E010C3DC AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3E58A0 E010C3E0 0040802D */  daddu     $s0, $v0, $zero
/* 3E58A4 E010C3E4 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 3E58A8 E010C3E8 3C16DE00 */  lui       $s6, 0xde00
/* 3E58AC E010C3EC AFB100AC */  sw        $s1, 0xac($sp)
/* 3E58B0 E010C3F0 2411005C */  addiu     $s1, $zero, 0x5c
/* 3E58B4 E010C3F4 3C06800B */  lui       $a2, %hi(gCameras)
/* 3E58B8 E010C3F8 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* 3E58BC E010C3FC AFBF00CC */  sw        $ra, 0xcc($sp)
/* 3E58C0 E010C400 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 3E58C4 E010C404 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3E58C8 E010C408 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 3E58CC E010C40C 8E050000 */  lw        $a1, ($s0)
/* 3E58D0 E010C410 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3E58D4 E010C414 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3E58D8 E010C418 4480A000 */  mtc1      $zero, $f20
/* 3E58DC E010C41C 00031080 */  sll       $v0, $v1, 2
/* 3E58E0 E010C420 00431021 */  addu      $v0, $v0, $v1
/* 3E58E4 E010C424 00021080 */  sll       $v0, $v0, 2
/* 3E58E8 E010C428 00431023 */  subu      $v0, $v0, $v1
/* 3E58EC E010C42C 000218C0 */  sll       $v1, $v0, 3
/* 3E58F0 E010C430 00431021 */  addu      $v0, $v0, $v1
/* 3E58F4 E010C434 000210C0 */  sll       $v0, $v0, 3
/* 3E58F8 E010C438 00461021 */  addu      $v0, $v0, $a2
/* 3E58FC E010C43C 00A0182D */  daddu     $v1, $a1, $zero
/* 3E5900 E010C440 AFA200A0 */  sw        $v0, 0xa0($sp)
/* 3E5904 E010C444 8C92000C */  lw        $s2, 0xc($a0)
/* 3E5908 E010C448 24A50008 */  addiu     $a1, $a1, 8
/* 3E590C E010C44C AE050000 */  sw        $a1, ($s0)
/* 3E5910 E010C450 8E4A0024 */  lw        $t2, 0x24($s2)
/* 3E5914 E010C454 3C02E700 */  lui       $v0, 0xe700
/* 3E5918 E010C458 AFAA00A4 */  sw        $t2, 0xa4($sp)
/* 3E591C E010C45C AC620000 */  sw        $v0, ($v1)
/* 3E5920 E010C460 24A20008 */  addiu     $v0, $a1, 8
/* 3E5924 E010C464 AC600004 */  sw        $zero, 4($v1)
/* 3E5928 E010C468 AE020000 */  sw        $v0, ($s0)
/* 3E592C E010C46C ACA70000 */  sw        $a3, ($a1)
/* 3E5930 E010C470 8C830010 */  lw        $v1, 0x10($a0)
/* 3E5934 E010C474 24A20010 */  addiu     $v0, $a1, 0x10
/* 3E5938 E010C478 AE020000 */  sw        $v0, ($s0)
/* 3E593C E010C47C 8C63001C */  lw        $v1, 0x1c($v1)
/* 3E5940 E010C480 02C0102D */  daddu     $v0, $s6, $zero
/* 3E5944 E010C484 ACA20008 */  sw        $v0, 8($a1)
/* 3E5948 E010C488 3C020900 */  lui       $v0, 0x900
/* 3E594C E010C48C 24425090 */  addiu     $v0, $v0, 0x5090
/* 3E5950 E010C490 ACA2000C */  sw        $v0, 0xc($a1)
/* 3E5954 E010C494 3C028000 */  lui       $v0, 0x8000
/* 3E5958 E010C498 00621821 */  addu      $v1, $v1, $v0
/* 3E595C E010C49C ACA30004 */  sw        $v1, 4($a1)
.LE010C4A0:
/* 3E5960 E010C4A0 02511821 */  addu      $v1, $s2, $s1
/* 3E5964 E010C4A4 8C640000 */  lw        $a0, ($v1)
/* 3E5968 E010C4A8 30820001 */  andi      $v0, $a0, 1
/* 3E596C E010C4AC 10400056 */  beqz      $v0, .LE010C608
/* 3E5970 E010C4B0 30820002 */   andi     $v0, $a0, 2
/* 3E5974 E010C4B4 10400005 */  beqz      $v0, .LE010C4CC
/* 3E5978 E010C4B8 00000000 */   nop
/* 3E597C E010C4BC C4660010 */  lwc1      $f6, 0x10($v1)
/* 3E5980 E010C4C0 C4640014 */  lwc1      $f4, 0x14($v1)
/* 3E5984 E010C4C4 08043136 */  j         .LE010C4D8
/* 3E5988 E010C4C8 C4620018 */   lwc1     $f2, 0x18($v1)
.LE010C4CC:
/* 3E598C E010C4CC C4660004 */  lwc1      $f6, 4($v1)
/* 3E5990 E010C4D0 C4640008 */  lwc1      $f4, 8($v1)
/* 3E5994 E010C4D4 C462000C */  lwc1      $f2, 0xc($v1)
.LE010C4D8:
/* 3E5998 E010C4D8 C640000C */  lwc1      $f0, 0xc($s2)
/* 3E599C E010C4DC 4602003C */  c.lt.s    $f0, $f2
/* 3E59A0 E010C4E0 00000000 */  nop
/* 3E59A4 E010C4E4 45030049 */  bc1tl     .LE010C60C
/* 3E59A8 E010C4E8 26730001 */   addiu    $s3, $s3, 1
/* 3E59AC E010C4EC 4405A000 */  mfc1      $a1, $f20
/* 3E59B0 E010C4F0 4406A000 */  mfc1      $a2, $f20
/* 3E59B4 E010C4F4 4407A000 */  mfc1      $a3, $f20
/* 3E59B8 E010C4F8 3C013F36 */  lui       $at, 0x3f36
/* 3E59BC E010C4FC 3421DB6E */  ori       $at, $at, 0xdb6e
/* 3E59C0 E010C500 44810000 */  mtc1      $at, $f0
/* 3E59C4 E010C504 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E59C8 E010C508 E7A60014 */  swc1      $f6, 0x14($sp)
/* 3E59CC E010C50C E7A40018 */  swc1      $f4, 0x18($sp)
/* 3E59D0 E010C510 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 3E59D4 E010C514 0C080180 */  jal       func_E0200600
/* 3E59D8 E010C518 E7A00010 */   swc1     $f0, 0x10($sp)
/* 3E59DC E010C51C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E59E0 E010C520 96A50000 */  lhu       $a1, ($s5)
/* 3E59E4 E010C524 8EE20000 */  lw        $v0, ($s7)
/* 3E59E8 E010C528 00052980 */  sll       $a1, $a1, 6
/* 3E59EC E010C52C 00B42821 */  addu      $a1, $a1, $s4
/* 3E59F0 E010C530 0C080118 */  jal       func_E0200460
/* 3E59F4 E010C534 00452821 */   addu     $a1, $v0, $a1
/* 3E59F8 E010C538 3C02DA38 */  lui       $v0, 0xda38
/* 3E59FC E010C53C 34420002 */  ori       $v0, $v0, 2
/* 3E5A00 E010C540 3C068080 */  lui       $a2, 0x8080
/* 3E5A04 E010C544 34C680FF */  ori       $a2, $a2, 0x80ff
/* 3E5A08 E010C548 3C078080 */  lui       $a3, 0x8080
/* 3E5A0C E010C54C 34E7807F */  ori       $a3, $a3, 0x807f
/* 3E5A10 E010C550 3C08D838 */  lui       $t0, 0xd838
/* 3E5A14 E010C554 35080002 */  ori       $t0, $t0, 2
/* 3E5A18 E010C558 8E040000 */  lw        $a0, ($s0)
/* 3E5A1C E010C55C 96A30000 */  lhu       $v1, ($s5)
/* 3E5A20 E010C560 0080282D */  daddu     $a1, $a0, $zero
/* 3E5A24 E010C564 24840008 */  addiu     $a0, $a0, 8
/* 3E5A28 E010C568 AE040000 */  sw        $a0, ($s0)
/* 3E5A2C E010C56C ACA20000 */  sw        $v0, ($a1)
/* 3E5A30 E010C570 24620001 */  addiu     $v0, $v1, 1
/* 3E5A34 E010C574 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3E5A38 E010C578 00031980 */  sll       $v1, $v1, 6
/* 3E5A3C E010C57C A6A20000 */  sh        $v0, ($s5)
/* 3E5A40 E010C580 8EE20000 */  lw        $v0, ($s7)
/* 3E5A44 E010C584 00741821 */  addu      $v1, $v1, $s4
/* 3E5A48 E010C588 00431021 */  addu      $v0, $v0, $v1
/* 3E5A4C E010C58C ACA20004 */  sw        $v0, 4($a1)
/* 3E5A50 E010C590 24820008 */  addiu     $v0, $a0, 8
/* 3E5A54 E010C594 AE020000 */  sw        $v0, ($s0)
/* 3E5A58 E010C598 3C02FA00 */  lui       $v0, 0xfa00
/* 3E5A5C E010C59C AC820000 */  sw        $v0, ($a0)
/* 3E5A60 E010C5A0 24820010 */  addiu     $v0, $a0, 0x10
/* 3E5A64 E010C5A4 AC860004 */  sw        $a2, 4($a0)
/* 3E5A68 E010C5A8 AE020000 */  sw        $v0, ($s0)
/* 3E5A6C E010C5AC 3C02FB00 */  lui       $v0, 0xfb00
/* 3E5A70 E010C5B0 AC820008 */  sw        $v0, 8($a0)
/* 3E5A74 E010C5B4 24820018 */  addiu     $v0, $a0, 0x18
/* 3E5A78 E010C5B8 00131880 */  sll       $v1, $s3, 2
/* 3E5A7C E010C5BC AC87000C */  sw        $a3, 0xc($a0)
/* 3E5A80 E010C5C0 AE020000 */  sw        $v0, ($s0)
/* 3E5A84 E010C5C4 AC960010 */  sw        $s6, 0x10($a0)
/* 3E5A88 E010C5C8 3C05E011 */  lui       $a1, %hi(D_E010CA38)
/* 3E5A8C E010C5CC 00A32821 */  addu      $a1, $a1, $v1
/* 3E5A90 E010C5D0 8CA5CA38 */  lw        $a1, %lo(D_E010CA38)($a1)
/* 3E5A94 E010C5D4 24820020 */  addiu     $v0, $a0, 0x20
/* 3E5A98 E010C5D8 AE020000 */  sw        $v0, ($s0)
/* 3E5A9C E010C5DC AC960018 */  sw        $s6, 0x18($a0)
/* 3E5AA0 E010C5E0 AC850014 */  sw        $a1, 0x14($a0)
/* 3E5AA4 E010C5E4 3C01E011 */  lui       $at, %hi(D_E010CA18)
/* 3E5AA8 E010C5E8 00230821 */  addu      $at, $at, $v1
/* 3E5AAC E010C5EC 8C23CA18 */  lw        $v1, %lo(D_E010CA18)($at)
/* 3E5AB0 E010C5F0 24820028 */  addiu     $v0, $a0, 0x28
/* 3E5AB4 E010C5F4 AE020000 */  sw        $v0, ($s0)
/* 3E5AB8 E010C5F8 24020040 */  addiu     $v0, $zero, 0x40
/* 3E5ABC E010C5FC AC880020 */  sw        $t0, 0x20($a0)
/* 3E5AC0 E010C600 AC820024 */  sw        $v0, 0x24($a0)
/* 3E5AC4 E010C604 AC83001C */  sw        $v1, 0x1c($a0)
.LE010C608:
/* 3E5AC8 E010C608 26730001 */  addiu     $s3, $s3, 1
.LE010C60C:
/* 3E5ACC E010C60C 2A620008 */  slti      $v0, $s3, 8
/* 3E5AD0 E010C610 1440FFA3 */  bnez      $v0, .LE010C4A0
/* 3E5AD4 E010C614 2631001C */   addiu    $s1, $s1, 0x1c
/* 3E5AD8 E010C618 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E5ADC E010C61C 240200FF */  addiu     $v0, $zero, 0xff
/* 3E5AE0 E010C620 8E43003C */  lw        $v1, 0x3c($s2)
/* 3E5AE4 E010C624 3C014079 */  lui       $at, 0x4079
/* 3E5AE8 E010C628 44811800 */  mtc1      $at, $f3
/* 3E5AEC E010C62C 44801000 */  mtc1      $zero, $f2
/* 3E5AF0 E010C630 00431023 */  subu      $v0, $v0, $v1
/* 3E5AF4 E010C634 44820000 */  mtc1      $v0, $f0
/* 3E5AF8 E010C638 00000000 */  nop
/* 3E5AFC E010C63C 46800020 */  cvt.s.w   $f0, $f0
/* 3E5B00 E010C640 46000021 */  cvt.d.s   $f0, $f0
/* 3E5B04 E010C644 46220002 */  mul.d     $f0, $f0, $f2
/* 3E5B08 E010C648 00000000 */  nop
/* 3E5B0C E010C64C 3C110001 */  lui       $s1, 1
/* 3E5B10 E010C650 36311630 */  ori       $s1, $s1, 0x1630
/* 3E5B14 E010C654 0000982D */  daddu     $s3, $zero, $zero
/* 3E5B18 E010C658 3C01E011 */  lui       $at, %hi(D_E010CA60)
/* 3E5B1C E010C65C D424CA60 */  ldc1      $f4, %lo(D_E010CA60)($at)
/* 3E5B20 E010C660 C6420008 */  lwc1      $f2, 8($s2)
/* 3E5B24 E010C664 8E450004 */  lw        $a1, 4($s2)
/* 3E5B28 E010C668 460010A1 */  cvt.d.s   $f2, $f2
/* 3E5B2C E010C66C 46240003 */  div.d     $f0, $f0, $f4
/* 3E5B30 E010C670 46201081 */  sub.d     $f2, $f2, $f0
/* 3E5B34 E010C674 8E47000C */  lw        $a3, 0xc($s2)
/* 3E5B38 E010C678 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3E5B3C E010C67C 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 3E5B40 E010C680 462010A0 */  cvt.s.d   $f2, $f2
/* 3E5B44 E010C684 44061000 */  mfc1      $a2, $f2
/* 3E5B48 E010C688 0C080108 */  jal       func_E0200420
/* 3E5B4C E010C68C 0040B82D */   daddu    $s7, $v0, $zero
/* 3E5B50 E010C690 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 3E5B54 E010C694 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 3E5B58 E010C698 C6400038 */  lwc1      $f0, 0x38($s2)
/* 3E5B5C E010C69C 3C01E011 */  lui       $at, %hi(D_E010CA68)
/* 3E5B60 E010C6A0 D422CA68 */  ldc1      $f2, %lo(D_E010CA68)($at)
/* 3E5B64 E010C6A4 46000021 */  cvt.d.s   $f0, $f0
/* 3E5B68 E010C6A8 46220002 */  mul.d     $f0, $f0, $f2
/* 3E5B6C E010C6AC 00000000 */  nop
/* 3E5B70 E010C6B0 0040A02D */  daddu     $s4, $v0, $zero
/* 3E5B74 E010C6B4 3C160001 */  lui       $s6, 1
/* 3E5B78 E010C6B8 36D61630 */  ori       $s6, $s6, 0x1630
/* 3E5B7C E010C6BC 3C1EDE00 */  lui       $fp, 0xde00
/* 3E5B80 E010C6C0 2415005C */  addiu     $s5, $zero, 0x5c
/* 3E5B84 E010C6C4 27B00060 */  addiu     $s0, $sp, 0x60
/* 3E5B88 E010C6C8 0200202D */  daddu     $a0, $s0, $zero
/* 3E5B8C E010C6CC 46200020 */  cvt.s.d   $f0, $f0
/* 3E5B90 E010C6D0 44050000 */  mfc1      $a1, $f0
/* 3E5B94 E010C6D4 4480A000 */  mtc1      $zero, $f20
/* 3E5B98 E010C6D8 00A0302D */  daddu     $a2, $a1, $zero
/* 3E5B9C E010C6DC 0C080110 */  jal       func_E0200440
/* 3E5BA0 E010C6E0 00A0382D */   daddu    $a3, $a1, $zero
/* 3E5BA4 E010C6E4 0200202D */  daddu     $a0, $s0, $zero
/* 3E5BA8 E010C6E8 27A50020 */  addiu     $a1, $sp, 0x20
/* 3E5BAC E010C6EC 0C080114 */  jal       func_E0200450
/* 3E5BB0 E010C6F0 00A0302D */   daddu    $a2, $a1, $zero
/* 3E5BB4 E010C6F4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E5BB8 E010C6F8 96850000 */  lhu       $a1, ($s4)
/* 3E5BBC E010C6FC 8EE20000 */  lw        $v0, ($s7)
/* 3E5BC0 E010C700 00052980 */  sll       $a1, $a1, 6
/* 3E5BC4 E010C704 00B12821 */  addu      $a1, $a1, $s1
/* 3E5BC8 E010C708 0C080118 */  jal       func_E0200460
/* 3E5BCC E010C70C 00452821 */   addu     $a1, $v0, $a1
/* 3E5BD0 E010C710 3C03DA38 */  lui       $v1, 0xda38
/* 3E5BD4 E010C714 34630002 */  ori       $v1, $v1, 2
/* 3E5BD8 E010C718 3C06DA38 */  lui       $a2, 0xda38
/* 3E5BDC E010C71C 34C60001 */  ori       $a2, $a2, 1
/* 3E5BE0 E010C720 3C09D838 */  lui       $t1, 0xd838
/* 3E5BE4 E010C724 35290002 */  ori       $t1, $t1, 2
/* 3E5BE8 E010C728 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3E5BEC E010C72C 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3E5BF0 E010C730 0040802D */  daddu     $s0, $v0, $zero
/* 3E5BF4 E010C734 8C440000 */  lw        $a0, ($v0)
/* 3E5BF8 E010C738 96820000 */  lhu       $v0, ($s4)
/* 3E5BFC E010C73C 0080282D */  daddu     $a1, $a0, $zero
/* 3E5C00 E010C740 24840008 */  addiu     $a0, $a0, 8
/* 3E5C04 E010C744 AE040000 */  sw        $a0, ($s0)
/* 3E5C08 E010C748 ACA30000 */  sw        $v1, ($a1)
/* 3E5C0C E010C74C 24430001 */  addiu     $v1, $v0, 1
/* 3E5C10 E010C750 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3E5C14 E010C754 00021180 */  sll       $v0, $v0, 6
/* 3E5C18 E010C758 A6830000 */  sh        $v1, ($s4)
/* 3E5C1C E010C75C 8EE30000 */  lw        $v1, ($s7)
/* 3E5C20 E010C760 00511021 */  addu      $v0, $v0, $s1
/* 3E5C24 E010C764 00621821 */  addu      $v1, $v1, $v0
/* 3E5C28 E010C768 24820008 */  addiu     $v0, $a0, 8
/* 3E5C2C E010C76C ACA30004 */  sw        $v1, 4($a1)
/* 3E5C30 E010C770 AE020000 */  sw        $v0, ($s0)
/* 3E5C34 E010C774 24820010 */  addiu     $v0, $a0, 0x10
/* 3E5C38 E010C778 AC860000 */  sw        $a2, ($a0)
/* 3E5C3C E010C77C AE020000 */  sw        $v0, ($s0)
/* 3E5C40 E010C780 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3E5C44 E010C784 03C0382D */  daddu     $a3, $fp, $zero
/* 3E5C48 E010C788 8D430204 */  lw        $v1, 0x204($t2)
/* 3E5C4C E010C78C 3C02FA00 */  lui       $v0, 0xfa00
/* 3E5C50 E010C790 AC820008 */  sw        $v0, 8($a0)
/* 3E5C54 E010C794 AC830004 */  sw        $v1, 4($a0)
/* 3E5C58 E010C798 9242001B */  lbu       $v0, 0x1b($s2)
/* 3E5C5C E010C79C 9245001F */  lbu       $a1, 0x1f($s2)
/* 3E5C60 E010C7A0 92460023 */  lbu       $a2, 0x23($s2)
/* 3E5C64 E010C7A4 24830018 */  addiu     $v1, $a0, 0x18
/* 3E5C68 E010C7A8 AE030000 */  sw        $v1, ($s0)
/* 3E5C6C E010C7AC 3C03FB00 */  lui       $v1, 0xfb00
/* 3E5C70 E010C7B0 AC830010 */  sw        $v1, 0x10($a0)
/* 3E5C74 E010C7B4 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 3E5C78 E010C7B8 00021600 */  sll       $v0, $v0, 0x18
/* 3E5C7C E010C7BC 00052C00 */  sll       $a1, $a1, 0x10
/* 3E5C80 E010C7C0 00451025 */  or        $v0, $v0, $a1
/* 3E5C84 E010C7C4 00063200 */  sll       $a2, $a2, 8
/* 3E5C88 E010C7C8 00461025 */  or        $v0, $v0, $a2
/* 3E5C8C E010C7CC 314300FF */  andi      $v1, $t2, 0xff
/* 3E5C90 E010C7D0 00431025 */  or        $v0, $v0, $v1
/* 3E5C94 E010C7D4 AC82000C */  sw        $v0, 0xc($a0)
/* 3E5C98 E010C7D8 9242002B */  lbu       $v0, 0x2b($s2)
/* 3E5C9C E010C7DC 9245002F */  lbu       $a1, 0x2f($s2)
/* 3E5CA0 E010C7E0 92460033 */  lbu       $a2, 0x33($s2)
/* 3E5CA4 E010C7E4 92480037 */  lbu       $t0, 0x37($s2)
/* 3E5CA8 E010C7E8 24830020 */  addiu     $v1, $a0, 0x20
/* 3E5CAC E010C7EC AE030000 */  sw        $v1, ($s0)
/* 3E5CB0 E010C7F0 AC870018 */  sw        $a3, 0x18($a0)
/* 3E5CB4 E010C7F4 00021600 */  sll       $v0, $v0, 0x18
/* 3E5CB8 E010C7F8 00052C00 */  sll       $a1, $a1, 0x10
/* 3E5CBC E010C7FC 00451025 */  or        $v0, $v0, $a1
/* 3E5CC0 E010C800 00063200 */  sll       $a2, $a2, 8
/* 3E5CC4 E010C804 00461025 */  or        $v0, $v0, $a2
/* 3E5CC8 E010C808 00481025 */  or        $v0, $v0, $t0
/* 3E5CCC E010C80C AC820014 */  sw        $v0, 0x14($a0)
/* 3E5CD0 E010C810 3C03E011 */  lui       $v1, %hi(D_E010CA14)
/* 3E5CD4 E010C814 8C63CA14 */  lw        $v1, %lo(D_E010CA14)($v1)
/* 3E5CD8 E010C818 24820028 */  addiu     $v0, $a0, 0x28
/* 3E5CDC E010C81C AE020000 */  sw        $v0, ($s0)
/* 3E5CE0 E010C820 AC870020 */  sw        $a3, 0x20($a0)
/* 3E5CE4 E010C824 AC83001C */  sw        $v1, 0x1c($a0)
/* 3E5CE8 E010C828 3C03E011 */  lui       $v1, %hi(D_E010CA10)
/* 3E5CEC E010C82C 8C63CA10 */  lw        $v1, %lo(D_E010CA10)($v1)
/* 3E5CF0 E010C830 24820030 */  addiu     $v0, $a0, 0x30
/* 3E5CF4 E010C834 AE020000 */  sw        $v0, ($s0)
/* 3E5CF8 E010C838 24020040 */  addiu     $v0, $zero, 0x40
/* 3E5CFC E010C83C AC830024 */  sw        $v1, 0x24($a0)
/* 3E5D00 E010C840 AC890028 */  sw        $t1, 0x28($a0)
/* 3E5D04 E010C844 AC82002C */  sw        $v0, 0x2c($a0)
/* 3E5D08 E010C848 24820038 */  addiu     $v0, $a0, 0x38
/* 3E5D0C E010C84C AE020000 */  sw        $v0, ($s0)
/* 3E5D10 E010C850 3C020900 */  lui       $v0, 0x900
/* 3E5D14 E010C854 24425090 */  addiu     $v0, $v0, 0x5090
/* 3E5D18 E010C858 AC870030 */  sw        $a3, 0x30($a0)
/* 3E5D1C E010C85C AC820034 */  sw        $v0, 0x34($a0)
.LE010C860:
/* 3E5D20 E010C860 02551821 */  addu      $v1, $s2, $s5
/* 3E5D24 E010C864 8C640000 */  lw        $a0, ($v1)
/* 3E5D28 E010C868 30820001 */  andi      $v0, $a0, 1
/* 3E5D2C E010C86C 10400056 */  beqz      $v0, .LE010C9C8
/* 3E5D30 E010C870 30820002 */   andi     $v0, $a0, 2
/* 3E5D34 E010C874 10400005 */  beqz      $v0, .LE010C88C
/* 3E5D38 E010C878 00000000 */   nop
/* 3E5D3C E010C87C C4660010 */  lwc1      $f6, 0x10($v1)
/* 3E5D40 E010C880 C4640014 */  lwc1      $f4, 0x14($v1)
/* 3E5D44 E010C884 08043226 */  j         .LE010C898
/* 3E5D48 E010C888 C4620018 */   lwc1     $f2, 0x18($v1)
.LE010C88C:
/* 3E5D4C E010C88C C4660004 */  lwc1      $f6, 4($v1)
/* 3E5D50 E010C890 C4640008 */  lwc1      $f4, 8($v1)
/* 3E5D54 E010C894 C462000C */  lwc1      $f2, 0xc($v1)
.LE010C898:
/* 3E5D58 E010C898 C640000C */  lwc1      $f0, 0xc($s2)
/* 3E5D5C E010C89C 4600103E */  c.le.s    $f2, $f0
/* 3E5D60 E010C8A0 00000000 */  nop
/* 3E5D64 E010C8A4 45030049 */  bc1tl     .LE010C9CC
/* 3E5D68 E010C8A8 26730001 */   addiu    $s3, $s3, 1
/* 3E5D6C E010C8AC 4405A000 */  mfc1      $a1, $f20
/* 3E5D70 E010C8B0 4406A000 */  mfc1      $a2, $f20
/* 3E5D74 E010C8B4 4407A000 */  mfc1      $a3, $f20
/* 3E5D78 E010C8B8 3C013F2B */  lui       $at, 0x3f2b
/* 3E5D7C E010C8BC 3421851F */  ori       $at, $at, 0x851f
/* 3E5D80 E010C8C0 44810000 */  mtc1      $at, $f0
/* 3E5D84 E010C8C4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E5D88 E010C8C8 E7A60014 */  swc1      $f6, 0x14($sp)
/* 3E5D8C E010C8CC E7A40018 */  swc1      $f4, 0x18($sp)
/* 3E5D90 E010C8D0 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 3E5D94 E010C8D4 0C080180 */  jal       func_E0200600
/* 3E5D98 E010C8D8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 3E5D9C E010C8DC 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E5DA0 E010C8E0 96850000 */  lhu       $a1, ($s4)
/* 3E5DA4 E010C8E4 8EE20000 */  lw        $v0, ($s7)
/* 3E5DA8 E010C8E8 00052980 */  sll       $a1, $a1, 6
/* 3E5DAC E010C8EC 00B62821 */  addu      $a1, $a1, $s6
/* 3E5DB0 E010C8F0 0C080118 */  jal       func_E0200460
/* 3E5DB4 E010C8F4 00452821 */   addu     $a1, $v0, $a1
/* 3E5DB8 E010C8F8 3C02DA38 */  lui       $v0, 0xda38
/* 3E5DBC E010C8FC 34420002 */  ori       $v0, $v0, 2
/* 3E5DC0 E010C900 3C068080 */  lui       $a2, 0x8080
/* 3E5DC4 E010C904 34C680FF */  ori       $a2, $a2, 0x80ff
/* 3E5DC8 E010C908 3C078080 */  lui       $a3, 0x8080
/* 3E5DCC E010C90C 34E7807F */  ori       $a3, $a3, 0x807f
/* 3E5DD0 E010C910 3C08D838 */  lui       $t0, 0xd838
/* 3E5DD4 E010C914 35080002 */  ori       $t0, $t0, 2
/* 3E5DD8 E010C918 8E040000 */  lw        $a0, ($s0)
/* 3E5DDC E010C91C 96830000 */  lhu       $v1, ($s4)
/* 3E5DE0 E010C920 0080282D */  daddu     $a1, $a0, $zero
/* 3E5DE4 E010C924 24840008 */  addiu     $a0, $a0, 8
/* 3E5DE8 E010C928 AE040000 */  sw        $a0, ($s0)
/* 3E5DEC E010C92C ACA20000 */  sw        $v0, ($a1)
/* 3E5DF0 E010C930 24620001 */  addiu     $v0, $v1, 1
/* 3E5DF4 E010C934 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3E5DF8 E010C938 00031980 */  sll       $v1, $v1, 6
/* 3E5DFC E010C93C A6820000 */  sh        $v0, ($s4)
/* 3E5E00 E010C940 8EE20000 */  lw        $v0, ($s7)
/* 3E5E04 E010C944 00761821 */  addu      $v1, $v1, $s6
/* 3E5E08 E010C948 00431021 */  addu      $v0, $v0, $v1
/* 3E5E0C E010C94C ACA20004 */  sw        $v0, 4($a1)
/* 3E5E10 E010C950 24820008 */  addiu     $v0, $a0, 8
/* 3E5E14 E010C954 AE020000 */  sw        $v0, ($s0)
/* 3E5E18 E010C958 3C02FA00 */  lui       $v0, 0xfa00
/* 3E5E1C E010C95C AC820000 */  sw        $v0, ($a0)
/* 3E5E20 E010C960 24820010 */  addiu     $v0, $a0, 0x10
/* 3E5E24 E010C964 AC860004 */  sw        $a2, 4($a0)
/* 3E5E28 E010C968 AE020000 */  sw        $v0, ($s0)
/* 3E5E2C E010C96C 3C02FB00 */  lui       $v0, 0xfb00
/* 3E5E30 E010C970 AC820008 */  sw        $v0, 8($a0)
/* 3E5E34 E010C974 24820018 */  addiu     $v0, $a0, 0x18
/* 3E5E38 E010C978 00131880 */  sll       $v1, $s3, 2
/* 3E5E3C E010C97C AC87000C */  sw        $a3, 0xc($a0)
/* 3E5E40 E010C980 AE020000 */  sw        $v0, ($s0)
/* 3E5E44 E010C984 AC9E0010 */  sw        $fp, 0x10($a0)
/* 3E5E48 E010C988 3C05E011 */  lui       $a1, %hi(D_E010CA38)
/* 3E5E4C E010C98C 00A32821 */  addu      $a1, $a1, $v1
/* 3E5E50 E010C990 8CA5CA38 */  lw        $a1, %lo(D_E010CA38)($a1)
/* 3E5E54 E010C994 24820020 */  addiu     $v0, $a0, 0x20
/* 3E5E58 E010C998 AE020000 */  sw        $v0, ($s0)
/* 3E5E5C E010C99C AC9E0018 */  sw        $fp, 0x18($a0)
/* 3E5E60 E010C9A0 AC850014 */  sw        $a1, 0x14($a0)
/* 3E5E64 E010C9A4 3C01E011 */  lui       $at, %hi(D_E010CA18)
/* 3E5E68 E010C9A8 00230821 */  addu      $at, $at, $v1
/* 3E5E6C E010C9AC 8C23CA18 */  lw        $v1, %lo(D_E010CA18)($at)
/* 3E5E70 E010C9B0 24820028 */  addiu     $v0, $a0, 0x28
/* 3E5E74 E010C9B4 AE020000 */  sw        $v0, ($s0)
/* 3E5E78 E010C9B8 24020040 */  addiu     $v0, $zero, 0x40
/* 3E5E7C E010C9BC AC880020 */  sw        $t0, 0x20($a0)
/* 3E5E80 E010C9C0 AC820024 */  sw        $v0, 0x24($a0)
/* 3E5E84 E010C9C4 AC83001C */  sw        $v1, 0x1c($a0)
.LE010C9C8:
/* 3E5E88 E010C9C8 26730001 */  addiu     $s3, $s3, 1
.LE010C9CC:
/* 3E5E8C E010C9CC 2A620008 */  slti      $v0, $s3, 8
/* 3E5E90 E010C9D0 1440FFA3 */  bnez      $v0, .LE010C860
/* 3E5E94 E010C9D4 26B5001C */   addiu    $s5, $s5, 0x1c
/* 3E5E98 E010C9D8 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 3E5E9C E010C9DC 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 3E5EA0 E010C9E0 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 3E5EA4 E010C9E4 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 3E5EA8 E010C9E8 8FB500BC */  lw        $s5, 0xbc($sp)
/* 3E5EAC E010C9EC 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 3E5EB0 E010C9F0 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 3E5EB4 E010C9F4 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 3E5EB8 E010C9F8 8FB100AC */  lw        $s1, 0xac($sp)
/* 3E5EBC E010C9FC 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 3E5EC0 E010CA00 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 3E5EC4 E010CA04 03E00008 */  jr        $ra
/* 3E5EC8 E010CA08 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 3E5ECC E010CA0C 00000000 */  nop
