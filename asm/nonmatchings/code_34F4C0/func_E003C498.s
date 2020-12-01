.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003C498
/* 34F958 E003C498 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* 34F95C E003C49C 3C05DB06 */  lui       $a1, 0xdb06
/* 34F960 E003C4A0 34A50024 */  ori       $a1, $a1, 0x24
/* 34F964 E003C4A4 AFA400E8 */  sw        $a0, 0xe8($sp)
/* 34F968 E003C4A8 27A40020 */  addiu     $a0, $sp, 0x20
/* 34F96C E003C4AC AFB300BC */  sw        $s3, 0xbc($sp)
/* 34F970 E003C4B0 3C13800A */  lui       $s3, %hi(D_8009A66C)
/* 34F974 E003C4B4 2673A66C */  addiu     $s3, $s3, %lo(D_8009A66C)
/* 34F978 E003C4B8 8FAA00E8 */  lw        $t2, 0xe8($sp)
/* 34F97C E003C4BC 3C02E700 */  lui       $v0, 0xe700
/* 34F980 E003C4C0 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 34F984 E003C4C4 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 34F988 E003C4C8 AFB700CC */  sw        $s7, 0xcc($sp)
/* 34F98C E003C4CC AFB600C8 */  sw        $s6, 0xc8($sp)
/* 34F990 E003C4D0 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 34F994 E003C4D4 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 34F998 E003C4D8 AFB200B8 */  sw        $s2, 0xb8($sp)
/* 34F99C E003C4DC AFB100B4 */  sw        $s1, 0xb4($sp)
/* 34F9A0 E003C4E0 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 34F9A4 E003C4E4 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 34F9A8 E003C4E8 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 34F9AC E003C4EC 8E680000 */  lw        $t0, ($s3)
/* 34F9B0 E003C4F0 8D54000C */  lw        $s4, 0xc($t2)
/* 34F9B4 E003C4F4 0100182D */  daddu     $v1, $t0, $zero
/* 34F9B8 E003C4F8 8E8A003C */  lw        $t2, 0x3c($s4)
/* 34F9BC E003C4FC 25080008 */  addiu     $t0, $t0, 8
/* 34F9C0 E003C500 AFAA00A8 */  sw        $t2, 0xa8($sp)
/* 34F9C4 E003C504 AC620000 */  sw        $v0, ($v1)
/* 34F9C8 E003C508 AC600004 */  sw        $zero, 4($v1)
/* 34F9CC E003C50C AD050000 */  sw        $a1, ($t0)
/* 34F9D0 E003C510 8FAA00E8 */  lw        $t2, 0xe8($sp)
/* 34F9D4 E003C514 3C120001 */  lui       $s2, 1
/* 34F9D8 E003C518 8D420010 */  lw        $v0, 0x10($t2)
/* 34F9DC E003C51C 36521630 */  ori       $s2, $s2, 0x1630
/* 34F9E0 E003C520 AE680000 */  sw        $t0, ($s3)
/* 34F9E4 E003C524 8C42001C */  lw        $v0, 0x1c($v0)
/* 34F9E8 E003C528 3C038000 */  lui       $v1, 0x8000
/* 34F9EC E003C52C 00431021 */  addu      $v0, $v0, $v1
/* 34F9F0 E003C530 AD020004 */  sw        $v0, 4($t0)
/* 34F9F4 E003C534 8E850004 */  lw        $a1, 4($s4)
/* 34F9F8 E003C538 8E860008 */  lw        $a2, 8($s4)
/* 34F9FC E003C53C 8E87000C */  lw        $a3, 0xc($s4)
/* 34FA00 E003C540 25080008 */  addiu     $t0, $t0, 8
/* 34FA04 E003C544 0C080108 */  jal       func_E0200420
/* 34FA08 E003C548 AE680000 */   sw       $t0, ($s3)
/* 34FA0C E003C54C 27B00060 */  addiu     $s0, $sp, 0x60
/* 34FA10 E003C550 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 34FA14 E003C554 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 34FA18 E003C558 44800000 */  mtc1      $zero, $f0
/* 34FA1C E003C55C 00031080 */  sll       $v0, $v1, 2
/* 34FA20 E003C560 00431021 */  addu      $v0, $v0, $v1
/* 34FA24 E003C564 00021080 */  sll       $v0, $v0, 2
/* 34FA28 E003C568 00431023 */  subu      $v0, $v0, $v1
/* 34FA2C E003C56C 000218C0 */  sll       $v1, $v0, 3
/* 34FA30 E003C570 00431021 */  addu      $v0, $v0, $v1
/* 34FA34 E003C574 000210C0 */  sll       $v0, $v0, 3
/* 34FA38 E003C578 44060000 */  mfc1      $a2, $f0
/* 34FA3C E003C57C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 34FA40 E003C580 00220821 */  addu      $at, $at, $v0
/* 34FA44 E003C584 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 34FA48 E003C588 3C073F80 */  lui       $a3, 0x3f80
/* 34FA4C E003C58C 46000007 */  neg.s     $f0, $f0
/* 34FA50 E003C590 44050000 */  mfc1      $a1, $f0
/* 34FA54 E003C594 0200202D */  daddu     $a0, $s0, $zero
/* 34FA58 E003C598 0C080104 */  jal       func_E0200410
/* 34FA5C E003C59C AFA60010 */   sw       $a2, 0x10($sp)
/* 34FA60 E003C5A0 0200202D */  daddu     $a0, $s0, $zero
/* 34FA64 E003C5A4 27A50020 */  addiu     $a1, $sp, 0x20
/* 34FA68 E003C5A8 0C080114 */  jal       func_E0200450
/* 34FA6C E003C5AC 00A0302D */   daddu    $a2, $a1, $zero
/* 34FA70 E003C5B0 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FA74 E003C5B4 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 34FA78 E003C5B8 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 34FA7C E003C5BC 3C11800A */  lui       $s1, %hi(D_8009A674)
/* 34FA80 E003C5C0 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* 34FA84 E003C5C4 96050000 */  lhu       $a1, ($s0)
/* 34FA88 E003C5C8 8E220000 */  lw        $v0, ($s1)
/* 34FA8C E003C5CC 00052980 */  sll       $a1, $a1, 6
/* 34FA90 E003C5D0 00B22821 */  addu      $a1, $a1, $s2
/* 34FA94 E003C5D4 0C080118 */  jal       func_E0200460
/* 34FA98 E003C5D8 00452821 */   addu     $a1, $v0, $a1
/* 34FA9C E003C5DC 8E670000 */  lw        $a3, ($s3)
/* 34FAA0 E003C5E0 00E0282D */  daddu     $a1, $a3, $zero
/* 34FAA4 E003C5E4 24E70008 */  addiu     $a3, $a3, 8
/* 34FAA8 E003C5E8 AE670000 */  sw        $a3, ($s3)
/* 34FAAC E003C5EC 96040000 */  lhu       $a0, ($s0)
/* 34FAB0 E003C5F0 3C02DA38 */  lui       $v0, 0xda38
/* 34FAB4 E003C5F4 ACA20000 */  sw        $v0, ($a1)
/* 34FAB8 E003C5F8 8E230000 */  lw        $v1, ($s1)
/* 34FABC E003C5FC 3082FFFF */  andi      $v0, $a0, 0xffff
/* 34FAC0 E003C600 00021180 */  sll       $v0, $v0, 6
/* 34FAC4 E003C604 00521021 */  addu      $v0, $v0, $s2
/* 34FAC8 E003C608 00621821 */  addu      $v1, $v1, $v0
/* 34FACC E003C60C ACA30004 */  sw        $v1, 4($a1)
/* 34FAD0 E003C610 8FAA00E8 */  lw        $t2, 0xe8($sp)
/* 34FAD4 E003C614 8D450008 */  lw        $a1, 8($t2)
/* 34FAD8 E003C618 24840001 */  addiu     $a0, $a0, 1
/* 34FADC E003C61C A6040000 */  sh        $a0, ($s0)
/* 34FAE0 E003C620 8D43000C */  lw        $v1, 0xc($t2)
/* 34FAE4 E003C624 8E840034 */  lw        $a0, 0x34($s4)
/* 34FAE8 E003C628 00051180 */  sll       $v0, $a1, 6
/* 34FAEC E003C62C 2442FFC0 */  addiu     $v0, $v0, -0x40
/* 34FAF0 E003C630 0062A021 */  addu      $s4, $v1, $v0
/* 34FAF4 E003C634 2484FFFF */  addiu     $a0, $a0, -1
/* 34FAF8 E003C638 24A5FFFF */  addiu     $a1, $a1, -1
/* 34FAFC E003C63C AFA400A0 */  sw        $a0, 0xa0($sp)
/* 34FB00 E003C640 AFA500A4 */  sw        $a1, 0xa4($sp)
/* 34FB04 E003C644 8E83002C */  lw        $v1, 0x2c($s4)
/* 34FB08 E003C648 240200FF */  addiu     $v0, $zero, 0xff
/* 34FB0C E003C64C 14620005 */  bne       $v1, $v0, .LE003C664
/* 34FB10 E003C650 3C05E200 */   lui      $a1, 0xe200
/* 34FB14 E003C654 34A5001C */  ori       $a1, $a1, 0x1c
/* 34FB18 E003C658 3C030055 */  lui       $v1, 0x55
/* 34FB1C E003C65C 0800F19C */  j         .LE003C670
/* 34FB20 E003C660 34633048 */   ori      $v1, $v1, 0x3048
.LE003C664:
/* 34FB24 E003C664 34A5001C */  ori       $a1, $a1, 0x1c
/* 34FB28 E003C668 3C030050 */  lui       $v1, 0x50
/* 34FB2C E003C66C 34634340 */  ori       $v1, $v1, 0x4340
.LE003C670:
/* 34FB30 E003C670 3C06FC62 */  lui       $a2, 0xfc62
/* 34FB34 E003C674 34C632C4 */  ori       $a2, $a2, 0x32c4
/* 34FB38 E003C678 3C04FF65 */  lui       $a0, 0xff65
/* 34FB3C E003C67C 3484FEFF */  ori       $a0, $a0, 0xfeff
/* 34FB40 E003C680 24E20008 */  addiu     $v0, $a3, 8
/* 34FB44 E003C684 AE620000 */  sw        $v0, ($s3)
/* 34FB48 E003C688 24E20010 */  addiu     $v0, $a3, 0x10
/* 34FB4C E003C68C ACE50000 */  sw        $a1, ($a3)
/* 34FB50 E003C690 ACE30004 */  sw        $v1, 4($a3)
/* 34FB54 E003C694 AE620000 */  sw        $v0, ($s3)
/* 34FB58 E003C698 ACE60008 */  sw        $a2, 8($a3)
/* 34FB5C E003C69C ACE4000C */  sw        $a0, 0xc($a3)
/* 34FB60 E003C6A0 8FAA00E8 */  lw        $t2, 0xe8($sp)
/* 34FB64 E003C6A4 8D420008 */  lw        $v0, 8($t2)
/* 34FB68 E003C6A8 24120001 */  addiu     $s2, $zero, 1
/* 34FB6C E003C6AC 0242102A */  slt       $v0, $s2, $v0
/* 34FB70 E003C6B0 10400161 */  beqz      $v0, .LE003CC38
/* 34FB74 E003C6B4 3C15DE00 */   lui      $s5, 0xde00
/* 34FB78 E003C6B8 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* 34FB7C E003C6BC 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* 34FB80 E003C6C0 3C17800A */  lui       $s7, %hi(D_8009A674)
/* 34FB84 E003C6C4 26F7A674 */  addiu     $s7, $s7, %lo(D_8009A674)
/* 34FB88 E003C6C8 3C168007 */  lui       $s6, %hi(D_800741F0)
/* 34FB8C E003C6CC 26D641F0 */  addiu     $s6, $s6, %lo(D_800741F0)
/* 34FB90 E003C6D0 3C130001 */  lui       $s3, 1
/* 34FB94 E003C6D4 36731630 */  ori       $s3, $s3, 0x1630
/* 34FB98 E003C6D8 3C1ED838 */  lui       $fp, 0xd838
/* 34FB9C E003C6DC 37DE0002 */  ori       $fp, $fp, 2
/* 34FBA0 E003C6E0 26910038 */  addiu     $s1, $s4, 0x38
/* 34FBA4 E003C6E4 4480A000 */  mtc1      $zero, $f20
/* 34FBA8 E003C6E8 3C013FE0 */  lui       $at, 0x3fe0
/* 34FBAC E003C6EC 4481B800 */  mtc1      $at, $f23
/* 34FBB0 E003C6F0 4480B000 */  mtc1      $zero, $f22
.LE003C6F4:
/* 34FBB4 E003C6F4 3C022AAA */  lui       $v0, 0x2aaa
/* 34FBB8 E003C6F8 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 34FBBC E003C6FC 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 34FBC0 E003C700 8E060000 */  lw        $a2, ($s0)
/* 34FBC4 E003C704 024A2021 */  addu      $a0, $s2, $t2
/* 34FBC8 E003C708 00C0402D */  daddu     $t0, $a2, $zero
/* 34FBCC E003C70C 24C60008 */  addiu     $a2, $a2, 8
/* 34FBD0 E003C710 00820018 */  mult      $a0, $v0
/* 34FBD4 E003C714 3C02FA00 */  lui       $v0, 0xfa00
/* 34FBD8 E003C718 AE060000 */  sw        $a2, ($s0)
/* 34FBDC E003C71C AD020000 */  sw        $v0, ($t0)
/* 34FBE0 E003C720 000417C3 */  sra       $v0, $a0, 0x1f
/* 34FBE4 E003C724 9227FFF7 */  lbu       $a3, -9($s1)
/* 34FBE8 E003C728 00005010 */  mfhi      $t2
/* 34FBEC E003C72C 000A1843 */  sra       $v1, $t2, 1
/* 34FBF0 E003C730 00621823 */  subu      $v1, $v1, $v0
/* 34FBF4 E003C734 00031040 */  sll       $v0, $v1, 1
/* 34FBF8 E003C738 00431021 */  addu      $v0, $v0, $v1
/* 34FBFC E003C73C 00021080 */  sll       $v0, $v0, 2
/* 34FC00 E003C740 00822023 */  subu      $a0, $a0, $v0
/* 34FC04 E003C744 00041040 */  sll       $v0, $a0, 1
/* 34FC08 E003C748 00441021 */  addu      $v0, $v0, $a0
/* 34FC0C E003C74C 3C0AE004 */  lui       $t2, %hi(D_E003CCF8)
/* 34FC10 E003C750 254ACCF8 */  addiu     $t2, $t2, %lo(D_E003CCF8)
/* 34FC14 E003C754 004A1821 */  addu      $v1, $v0, $t2
/* 34FC18 E003C758 0060202D */  daddu     $a0, $v1, $zero
/* 34FC1C E003C75C 0060102D */  daddu     $v0, $v1, $zero
/* 34FC20 E003C760 90630000 */  lbu       $v1, ($v1)
/* 34FC24 E003C764 90840001 */  lbu       $a0, 1($a0)
/* 34FC28 E003C768 90450002 */  lbu       $a1, 2($v0)
/* 34FC2C E003C76C 24C20008 */  addiu     $v0, $a2, 8
/* 34FC30 E003C770 AE020000 */  sw        $v0, ($s0)
/* 34FC34 E003C774 00031E00 */  sll       $v1, $v1, 0x18
/* 34FC38 E003C778 00042400 */  sll       $a0, $a0, 0x10
/* 34FC3C E003C77C 00641825 */  or        $v1, $v1, $a0
/* 34FC40 E003C780 00052A00 */  sll       $a1, $a1, 8
/* 34FC44 E003C784 00651825 */  or        $v1, $v1, $a1
/* 34FC48 E003C788 00671825 */  or        $v1, $v1, $a3
/* 34FC4C E003C78C AD030004 */  sw        $v1, 4($t0)
/* 34FC50 E003C790 3C0A0900 */  lui       $t2, 0x900
/* 34FC54 E003C794 254A1D40 */  addiu     $t2, $t2, 0x1d40
/* 34FC58 E003C798 ACD50000 */  sw        $s5, ($a2)
/* 34FC5C E003C79C ACCA0004 */  sw        $t2, 4($a2)
/* 34FC60 E003C7A0 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 34FC64 E003C7A4 164A006E */  bne       $s2, $t2, .LE003C960
/* 34FC68 E003C7A8 27A40020 */   addiu    $a0, $sp, 0x20
/* 34FC6C E003C7AC C6200000 */  lwc1      $f0, ($s1)
/* 34FC70 E003C7B0 4405A000 */  mfc1      $a1, $f20
/* 34FC74 E003C7B4 4406A000 */  mfc1      $a2, $f20
/* 34FC78 E003C7B8 4407A000 */  mfc1      $a3, $f20
/* 34FC7C E003C7BC E7A00010 */  swc1      $f0, 0x10($sp)
/* 34FC80 E003C7C0 C620FFD8 */  lwc1      $f0, -0x28($s1)
/* 34FC84 E003C7C4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 34FC88 E003C7C8 C620FFDC */  lwc1      $f0, -0x24($s1)
/* 34FC8C E003C7CC E7A00018 */  swc1      $f0, 0x18($sp)
/* 34FC90 E003C7D0 C620FFE0 */  lwc1      $f0, -0x20($s1)
/* 34FC94 E003C7D4 0C080180 */  jal       func_E0200600
/* 34FC98 E003C7D8 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 34FC9C E003C7DC 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FCA0 E003C7E0 96C50000 */  lhu       $a1, ($s6)
/* 34FCA4 E003C7E4 8EE20000 */  lw        $v0, ($s7)
/* 34FCA8 E003C7E8 00052980 */  sll       $a1, $a1, 6
/* 34FCAC E003C7EC 00B32821 */  addu      $a1, $a1, $s3
/* 34FCB0 E003C7F0 0C080118 */  jal       func_E0200460
/* 34FCB4 E003C7F4 00452821 */   addu     $a1, $v0, $a1
/* 34FCB8 E003C7F8 8E080000 */  lw        $t0, ($s0)
/* 34FCBC E003C7FC 96C90000 */  lhu       $t1, ($s6)
/* 34FCC0 E003C800 0100202D */  daddu     $a0, $t0, $zero
/* 34FCC4 E003C804 25080008 */  addiu     $t0, $t0, 8
/* 34FCC8 E003C808 3C0ADA38 */  lui       $t2, 0xda38
/* 34FCCC E003C80C 3122FFFF */  andi      $v0, $t1, 0xffff
/* 34FCD0 E003C810 00021180 */  sll       $v0, $v0, 6
/* 34FCD4 E003C814 AC8A0000 */  sw        $t2, ($a0)
/* 34FCD8 E003C818 8EE30000 */  lw        $v1, ($s7)
/* 34FCDC E003C81C 00531021 */  addu      $v0, $v0, $s3
/* 34FCE0 E003C820 00621821 */  addu      $v1, $v1, $v0
/* 34FCE4 E003C824 3C020900 */  lui       $v0, 0x900
/* 34FCE8 E003C828 24422150 */  addiu     $v0, $v0, 0x2150
/* 34FCEC E003C82C AC830004 */  sw        $v1, 4($a0)
/* 34FCF0 E003C830 240A0040 */  addiu     $t2, $zero, 0x40
/* 34FCF4 E003C834 AD150000 */  sw        $s5, ($t0)
/* 34FCF8 E003C838 AD020004 */  sw        $v0, 4($t0)
/* 34FCFC E003C83C AD1E0008 */  sw        $fp, 8($t0)
/* 34FD00 E003C840 AD0A000C */  sw        $t2, 0xc($t0)
/* 34FD04 E003C844 C6200000 */  lwc1      $f0, ($s1)
/* 34FD08 E003C848 E7A00010 */  swc1      $f0, 0x10($sp)
/* 34FD0C E003C84C C620FFD8 */  lwc1      $f0, -0x28($s1)
/* 34FD10 E003C850 C622FFCC */  lwc1      $f2, -0x34($s1)
/* 34FD14 E003C854 46020000 */  add.s     $f0, $f0, $f2
/* 34FD18 E003C858 46000021 */  cvt.d.s   $f0, $f0
/* 34FD1C E003C85C 46360002 */  mul.d     $f0, $f0, $f22
/* 34FD20 E003C860 00000000 */  nop       
/* 34FD24 E003C864 46200020 */  cvt.s.d   $f0, $f0
/* 34FD28 E003C868 E7A00014 */  swc1      $f0, 0x14($sp)
/* 34FD2C E003C86C C620FFDC */  lwc1      $f0, -0x24($s1)
/* 34FD30 E003C870 C622FFD0 */  lwc1      $f2, -0x30($s1)
/* 34FD34 E003C874 46020000 */  add.s     $f0, $f0, $f2
/* 34FD38 E003C878 46000021 */  cvt.d.s   $f0, $f0
/* 34FD3C E003C87C 46360002 */  mul.d     $f0, $f0, $f22
/* 34FD40 E003C880 00000000 */  nop       
/* 34FD44 E003C884 4405A000 */  mfc1      $a1, $f20
/* 34FD48 E003C888 46200020 */  cvt.s.d   $f0, $f0
/* 34FD4C E003C88C E7A00018 */  swc1      $f0, 0x18($sp)
/* 34FD50 E003C890 C620FFE0 */  lwc1      $f0, -0x20($s1)
/* 34FD54 E003C894 C622FFD4 */  lwc1      $f2, -0x2c($s1)
/* 34FD58 E003C898 4406A000 */  mfc1      $a2, $f20
/* 34FD5C E003C89C 46020000 */  add.s     $f0, $f0, $f2
/* 34FD60 E003C8A0 4407A000 */  mfc1      $a3, $f20
/* 34FD64 E003C8A4 25290001 */  addiu     $t1, $t1, 1
/* 34FD68 E003C8A8 46000021 */  cvt.d.s   $f0, $f0
/* 34FD6C E003C8AC 46360002 */  mul.d     $f0, $f0, $f22
/* 34FD70 E003C8B0 00000000 */  nop       
/* 34FD74 E003C8B4 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FD78 E003C8B8 25020008 */  addiu     $v0, $t0, 8
/* 34FD7C E003C8BC AE080000 */  sw        $t0, ($s0)
/* 34FD80 E003C8C0 25080010 */  addiu     $t0, $t0, 0x10
/* 34FD84 E003C8C4 A6C90000 */  sh        $t1, ($s6)
/* 34FD88 E003C8C8 AE020000 */  sw        $v0, ($s0)
/* 34FD8C E003C8CC AE080000 */  sw        $t0, ($s0)
/* 34FD90 E003C8D0 46200020 */  cvt.s.d   $f0, $f0
/* 34FD94 E003C8D4 0C080180 */  jal       func_E0200600
/* 34FD98 E003C8D8 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 34FD9C E003C8DC 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FDA0 E003C8E0 96C50000 */  lhu       $a1, ($s6)
/* 34FDA4 E003C8E4 8EE20000 */  lw        $v0, ($s7)
/* 34FDA8 E003C8E8 00052980 */  sll       $a1, $a1, 6
/* 34FDAC E003C8EC 00B32821 */  addu      $a1, $a1, $s3
/* 34FDB0 E003C8F0 0C080118 */  jal       func_E0200460
/* 34FDB4 E003C8F4 00452821 */   addu     $a1, $v0, $a1
/* 34FDB8 E003C8F8 8E040000 */  lw        $a0, ($s0)
/* 34FDBC E003C8FC 96C30000 */  lhu       $v1, ($s6)
/* 34FDC0 E003C900 0080282D */  daddu     $a1, $a0, $zero
/* 34FDC4 E003C904 24840008 */  addiu     $a0, $a0, 8
/* 34FDC8 E003C908 3C0ADA38 */  lui       $t2, 0xda38
/* 34FDCC E003C90C 24620001 */  addiu     $v0, $v1, 1
/* 34FDD0 E003C910 3063FFFF */  andi      $v1, $v1, 0xffff
/* 34FDD4 E003C914 00031980 */  sll       $v1, $v1, 6
/* 34FDD8 E003C918 AE040000 */  sw        $a0, ($s0)
/* 34FDDC E003C91C ACAA0000 */  sw        $t2, ($a1)
/* 34FDE0 E003C920 A6C20000 */  sh        $v0, ($s6)
/* 34FDE4 E003C924 8EE20000 */  lw        $v0, ($s7)
/* 34FDE8 E003C928 00731821 */  addu      $v1, $v1, $s3
/* 34FDEC E003C92C 00431021 */  addu      $v0, $v0, $v1
/* 34FDF0 E003C930 ACA20004 */  sw        $v0, 4($a1)
/* 34FDF4 E003C934 24820008 */  addiu     $v0, $a0, 8
/* 34FDF8 E003C938 AE020000 */  sw        $v0, ($s0)
/* 34FDFC E003C93C 3C020900 */  lui       $v0, 0x900
/* 34FE00 E003C940 24422160 */  addiu     $v0, $v0, 0x2160
/* 34FE04 E003C944 AC820004 */  sw        $v0, 4($a0)
/* 34FE08 E003C948 24820010 */  addiu     $v0, $a0, 0x10
/* 34FE0C E003C94C 240A0040 */  addiu     $t2, $zero, 0x40
/* 34FE10 E003C950 AC950000 */  sw        $s5, ($a0)
/* 34FE14 E003C954 AE020000 */  sw        $v0, ($s0)
/* 34FE18 E003C958 AC9E0008 */  sw        $fp, 8($a0)
/* 34FE1C E003C95C AC8A000C */  sw        $t2, 0xc($a0)
.LE003C960:
/* 34FE20 E003C960 8E030000 */  lw        $v1, ($s0)
/* 34FE24 E003C964 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FE28 E003C968 0060102D */  daddu     $v0, $v1, $zero
/* 34FE2C E003C96C 3C0A0900 */  lui       $t2, 0x900
/* 34FE30 E003C970 254A1D40 */  addiu     $t2, $t2, 0x1d40
/* 34FE34 E003C974 AC550000 */  sw        $s5, ($v0)
/* 34FE38 E003C978 AC4A0004 */  sw        $t2, 4($v0)
/* 34FE3C E003C97C 8E25FFCC */  lw        $a1, -0x34($s1)
/* 34FE40 E003C980 8E26FFD0 */  lw        $a2, -0x30($s1)
/* 34FE44 E003C984 8E27FFD4 */  lw        $a3, -0x2c($s1)
/* 34FE48 E003C988 24630008 */  addiu     $v1, $v1, 8
/* 34FE4C E003C98C 0C080108 */  jal       func_E0200420
/* 34FE50 E003C990 AE030000 */   sw       $v1, ($s0)
/* 34FE54 E003C994 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FE58 E003C998 96C50000 */  lhu       $a1, ($s6)
/* 34FE5C E003C99C 8EE20000 */  lw        $v0, ($s7)
/* 34FE60 E003C9A0 00052980 */  sll       $a1, $a1, 6
/* 34FE64 E003C9A4 00B32821 */  addu      $a1, $a1, $s3
/* 34FE68 E003C9A8 0C080118 */  jal       func_E0200460
/* 34FE6C E003C9AC 00452821 */   addu     $a1, $v0, $a1
/* 34FE70 E003C9B0 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FE74 E003C9B4 8E060000 */  lw        $a2, ($s0)
/* 34FE78 E003C9B8 3C073F80 */  lui       $a3, 0x3f80
/* 34FE7C E003C9BC 96C80000 */  lhu       $t0, ($s6)
/* 34FE80 E003C9C0 00C0282D */  daddu     $a1, $a2, $zero
/* 34FE84 E003C9C4 3C0ADA38 */  lui       $t2, 0xda38
/* 34FE88 E003C9C8 3102FFFF */  andi      $v0, $t0, 0xffff
/* 34FE8C E003C9CC 00021180 */  sll       $v0, $v0, 6
/* 34FE90 E003C9D0 00531021 */  addu      $v0, $v0, $s3
/* 34FE94 E003C9D4 ACAA0000 */  sw        $t2, ($a1)
/* 34FE98 E003C9D8 8EE30000 */  lw        $v1, ($s7)
/* 34FE9C E003C9DC 24C60008 */  addiu     $a2, $a2, 8
/* 34FEA0 E003C9E0 00621821 */  addu      $v1, $v1, $v0
/* 34FEA4 E003C9E4 ACA30004 */  sw        $v1, 4($a1)
/* 34FEA8 E003C9E8 8E250000 */  lw        $a1, ($s1)
/* 34FEAC E003C9EC 25080001 */  addiu     $t0, $t0, 1
/* 34FEB0 E003C9F0 AE060000 */  sw        $a2, ($s0)
/* 34FEB4 E003C9F4 A6C80000 */  sh        $t0, ($s6)
/* 34FEB8 E003C9F8 0C080110 */  jal       func_E0200440
/* 34FEBC E003C9FC 00A0302D */   daddu    $a2, $a1, $zero
/* 34FEC0 E003CA00 27A40020 */  addiu     $a0, $sp, 0x20
/* 34FEC4 E003CA04 96C50000 */  lhu       $a1, ($s6)
/* 34FEC8 E003CA08 8EE20000 */  lw        $v0, ($s7)
/* 34FECC E003CA0C 00052980 */  sll       $a1, $a1, 6
/* 34FED0 E003CA10 00B32821 */  addu      $a1, $a1, $s3
/* 34FED4 E003CA14 0C080118 */  jal       func_E0200460
/* 34FED8 E003CA18 00452821 */   addu     $a1, $v0, $a1
/* 34FEDC E003CA1C 8E050000 */  lw        $a1, ($s0)
/* 34FEE0 E003CA20 96C30000 */  lhu       $v1, ($s6)
/* 34FEE4 E003CA24 00A0202D */  daddu     $a0, $a1, $zero
/* 34FEE8 E003CA28 24A50008 */  addiu     $a1, $a1, 8
/* 34FEEC E003CA2C 3C0ADA38 */  lui       $t2, 0xda38
/* 34FEF0 E003CA30 24620001 */  addiu     $v0, $v1, 1
/* 34FEF4 E003CA34 3063FFFF */  andi      $v1, $v1, 0xffff
/* 34FEF8 E003CA38 00031980 */  sll       $v1, $v1, 6
/* 34FEFC E003CA3C AE050000 */  sw        $a1, ($s0)
/* 34FF00 E003CA40 AC8A0000 */  sw        $t2, ($a0)
/* 34FF04 E003CA44 A6C20000 */  sh        $v0, ($s6)
/* 34FF08 E003CA48 8EE20000 */  lw        $v0, ($s7)
/* 34FF0C E003CA4C 00731821 */  addu      $v1, $v1, $s3
/* 34FF10 E003CA50 00431021 */  addu      $v0, $v0, $v1
/* 34FF14 E003CA54 AC820004 */  sw        $v0, 4($a0)
/* 34FF18 E003CA58 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 34FF1C E003CA5C 164A0006 */  bne       $s2, $t2, .LE003CA78
/* 34FF20 E003CA60 24A20008 */   addiu    $v0, $a1, 8
/* 34FF24 E003CA64 AE020000 */  sw        $v0, ($s0)
/* 34FF28 E003CA68 3C020900 */  lui       $v0, 0x900
/* 34FF2C E003CA6C 24422170 */  addiu     $v0, $v0, 0x2170
/* 34FF30 E003CA70 0800F2A2 */  j         .LE003CA88
/* 34FF34 E003CA74 ACB50000 */   sw       $s5, ($a1)
.LE003CA78:
/* 34FF38 E003CA78 AE020000 */  sw        $v0, ($s0)
/* 34FF3C E003CA7C 3C020900 */  lui       $v0, 0x900
/* 34FF40 E003CA80 24422180 */  addiu     $v0, $v0, 0x2180
/* 34FF44 E003CA84 ACB50000 */  sw        $s5, ($a1)
.LE003CA88:
/* 34FF48 E003CA88 ACA20004 */  sw        $v0, 4($a1)
/* 34FF4C E003CA8C 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 34FF50 E003CA90 164A0050 */  bne       $s2, $t2, .LE003CBD4
/* 34FF54 E003CA94 240A0040 */   addiu    $t2, $zero, 0x40
/* 34FF58 E003CA98 8E050000 */  lw        $a1, ($s0)
/* 34FF5C E003CA9C 3C020900 */  lui       $v0, 0x900
/* 34FF60 E003CAA0 244221A8 */  addiu     $v0, $v0, 0x21a8
/* 34FF64 E003CAA4 00A0182D */  daddu     $v1, $a1, $zero
/* 34FF68 E003CAA8 24A50008 */  addiu     $a1, $a1, 8
/* 34FF6C E003CAAC AE050000 */  sw        $a1, ($s0)
/* 34FF70 E003CAB0 AC620004 */  sw        $v0, 4($v1)
/* 34FF74 E003CAB4 24A20008 */  addiu     $v0, $a1, 8
/* 34FF78 E003CAB8 AC750000 */  sw        $s5, ($v1)
/* 34FF7C E003CABC AE020000 */  sw        $v0, ($s0)
/* 34FF80 E003CAC0 24A20010 */  addiu     $v0, $a1, 0x10
/* 34FF84 E003CAC4 ACBE0000 */  sw        $fp, ($a1)
/* 34FF88 E003CAC8 ACAA0004 */  sw        $t2, 4($a1)
/* 34FF8C E003CACC AE020000 */  sw        $v0, ($s0)
/* 34FF90 E003CAD0 3C020900 */  lui       $v0, 0x900
/* 34FF94 E003CAD4 24421DE0 */  addiu     $v0, $v0, 0x1de0
/* 34FF98 E003CAD8 ACB50008 */  sw        $s5, 8($a1)
/* 34FF9C E003CADC ACA2000C */  sw        $v0, 0xc($a1)
/* 34FFA0 E003CAE0 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 34FFA4 E003CAE4 2942000A */  slti      $v0, $t2, 0xa
/* 34FFA8 E003CAE8 10400010 */  beqz      $v0, .LE003CB2C
/* 34FFAC E003CAEC 24A20018 */   addiu    $v0, $a1, 0x18
/* 34FFB0 E003CAF0 AE020000 */  sw        $v0, ($s0)
/* 34FFB4 E003CAF4 00121080 */  sll       $v0, $s2, 2
/* 34FFB8 E003CAF8 3C0AE004 */  lui       $t2, %hi(D_E003CCA0)
/* 34FFBC E003CAFC 254ACCA0 */  addiu     $t2, $t2, %lo(D_E003CCA0)
/* 34FFC0 E003CB00 004A1021 */  addu      $v0, $v0, $t2
/* 34FFC4 E003CB04 ACB50010 */  sw        $s5, 0x10($a1)
/* 34FFC8 E003CB08 8C430000 */  lw        $v1, ($v0)
/* 34FFCC E003CB0C 24A20020 */  addiu     $v0, $a1, 0x20
/* 34FFD0 E003CB10 AE020000 */  sw        $v0, ($s0)
/* 34FFD4 E003CB14 3C020900 */  lui       $v0, 0x900
/* 34FFD8 E003CB18 244221C0 */  addiu     $v0, $v0, 0x21c0
/* 34FFDC E003CB1C ACB50018 */  sw        $s5, 0x18($a1)
/* 34FFE0 E003CB20 ACA2001C */  sw        $v0, 0x1c($a1)
/* 34FFE4 E003CB24 0800F301 */  j         .LE003CC04
/* 34FFE8 E003CB28 ACA30014 */   sw       $v1, 0x14($a1)
.LE003CB2C:
/* 34FFEC E003CB2C 3C036666 */  lui       $v1, 0x6666
/* 34FFF0 E003CB30 34636667 */  ori       $v1, $v1, 0x6667
/* 34FFF4 E003CB34 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 34FFF8 E003CB38 01430018 */  mult      $t2, $v1
/* 34FFFC E003CB3C AE020000 */  sw        $v0, ($s0)
/* 350000 E003CB40 24A20020 */  addiu     $v0, $a1, 0x20
/* 350004 E003CB44 ACB50010 */  sw        $s5, 0x10($a1)
/* 350008 E003CB48 AE020000 */  sw        $v0, ($s0)
/* 35000C E003CB4C 00005010 */  mfhi      $t2
/* 350010 E003CB50 000A1883 */  sra       $v1, $t2, 2
/* 350014 E003CB54 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 350018 E003CB58 000A17C3 */  sra       $v0, $t2, 0x1f
/* 35001C E003CB5C 00621023 */  subu      $v0, $v1, $v0
/* 350020 E003CB60 0040182D */  daddu     $v1, $v0, $zero
/* 350024 E003CB64 00031080 */  sll       $v0, $v1, 2
/* 350028 E003CB68 00431021 */  addu      $v0, $v0, $v1
/* 35002C E003CB6C 00021040 */  sll       $v0, $v0, 1
/* 350030 E003CB70 01421023 */  subu      $v0, $t2, $v0
/* 350034 E003CB74 00021080 */  sll       $v0, $v0, 2
/* 350038 E003CB78 3C0AE004 */  lui       $t2, %hi(D_E003CCA0)
/* 35003C E003CB7C 254ACCA0 */  addiu     $t2, $t2, %lo(D_E003CCA0)
/* 350040 E003CB80 004A1021 */  addu      $v0, $v0, $t2
/* 350044 E003CB84 8C440000 */  lw        $a0, ($v0)
/* 350048 E003CB88 24A20028 */  addiu     $v0, $a1, 0x28
/* 35004C E003CB8C AE020000 */  sw        $v0, ($s0)
/* 350050 E003CB90 3C020900 */  lui       $v0, 0x900
/* 350054 E003CB94 24422200 */  addiu     $v0, $v0, 0x2200
/* 350058 E003CB98 00031880 */  sll       $v1, $v1, 2
/* 35005C E003CB9C 006A1821 */  addu      $v1, $v1, $t2
/* 350060 E003CBA0 ACB50018 */  sw        $s5, 0x18($a1)
/* 350064 E003CBA4 ACA2001C */  sw        $v0, 0x1c($a1)
/* 350068 E003CBA8 ACB50020 */  sw        $s5, 0x20($a1)
/* 35006C E003CBAC ACA40014 */  sw        $a0, 0x14($a1)
/* 350070 E003CBB0 8C630000 */  lw        $v1, ($v1)
/* 350074 E003CBB4 24A20030 */  addiu     $v0, $a1, 0x30
/* 350078 E003CBB8 AE020000 */  sw        $v0, ($s0)
/* 35007C E003CBBC 3C020900 */  lui       $v0, 0x900
/* 350080 E003CBC0 244221E0 */  addiu     $v0, $v0, 0x21e0
/* 350084 E003CBC4 ACB50028 */  sw        $s5, 0x28($a1)
/* 350088 E003CBC8 ACA2002C */  sw        $v0, 0x2c($a1)
/* 35008C E003CBCC 0800F301 */  j         .LE003CC04
/* 350090 E003CBD0 ACA30024 */   sw       $v1, 0x24($a1)
.LE003CBD4:
/* 350094 E003CBD4 8E030000 */  lw        $v1, ($s0)
/* 350098 E003CBD8 3C020900 */  lui       $v0, 0x900
/* 35009C E003CBDC 24422190 */  addiu     $v0, $v0, 0x2190
/* 3500A0 E003CBE0 0060202D */  daddu     $a0, $v1, $zero
/* 3500A4 E003CBE4 24630008 */  addiu     $v1, $v1, 8
/* 3500A8 E003CBE8 AE030000 */  sw        $v1, ($s0)
/* 3500AC E003CBEC AC820004 */  sw        $v0, 4($a0)
/* 3500B0 E003CBF0 24620008 */  addiu     $v0, $v1, 8
/* 3500B4 E003CBF4 AC950000 */  sw        $s5, ($a0)
/* 3500B8 E003CBF8 AE020000 */  sw        $v0, ($s0)
/* 3500BC E003CBFC AC7E0000 */  sw        $fp, ($v1)
/* 3500C0 E003CC00 AC6A0004 */  sw        $t2, 4($v1)
.LE003CC04:
/* 3500C4 E003CC04 8E020000 */  lw        $v0, ($s0)
/* 3500C8 E003CC08 26520001 */  addiu     $s2, $s2, 1
/* 3500CC E003CC0C 0040182D */  daddu     $v1, $v0, $zero
/* 3500D0 E003CC10 240A0040 */  addiu     $t2, $zero, 0x40
/* 3500D4 E003CC14 AC7E0000 */  sw        $fp, ($v1)
/* 3500D8 E003CC18 AC6A0004 */  sw        $t2, 4($v1)
/* 3500DC E003CC1C 8FAA00E8 */  lw        $t2, 0xe8($sp)
/* 3500E0 E003CC20 2631FFC0 */  addiu     $s1, $s1, -0x40
/* 3500E4 E003CC24 8D430008 */  lw        $v1, 8($t2)
/* 3500E8 E003CC28 24420008 */  addiu     $v0, $v0, 8
/* 3500EC E003CC2C 0243182A */  slt       $v1, $s2, $v1
/* 3500F0 E003CC30 1460FEB0 */  bnez      $v1, .LE003C6F4
/* 3500F4 E003CC34 AE020000 */   sw       $v0, ($s0)
.LE003CC38:
/* 3500F8 E003CC38 3C05D838 */  lui       $a1, 0xd838
/* 3500FC E003CC3C 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 350100 E003CC40 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 350104 E003CC44 8C620000 */  lw        $v0, ($v1)
/* 350108 E003CC48 34A50002 */  ori       $a1, $a1, 2
/* 35010C E003CC4C 0040202D */  daddu     $a0, $v0, $zero
/* 350110 E003CC50 24420008 */  addiu     $v0, $v0, 8
/* 350114 E003CC54 AC620000 */  sw        $v0, ($v1)
/* 350118 E003CC58 24020040 */  addiu     $v0, $zero, 0x40
/* 35011C E003CC5C AC850000 */  sw        $a1, ($a0)
/* 350120 E003CC60 AC820004 */  sw        $v0, 4($a0)
/* 350124 E003CC64 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 350128 E003CC68 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 35012C E003CC6C 8FB700CC */  lw        $s7, 0xcc($sp)
/* 350130 E003CC70 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 350134 E003CC74 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 350138 E003CC78 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 35013C E003CC7C 8FB300BC */  lw        $s3, 0xbc($sp)
/* 350140 E003CC80 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 350144 E003CC84 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 350148 E003CC88 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 35014C E003CC8C D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 350150 E003CC90 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 350154 E003CC94 03E00008 */  jr        $ra
/* 350158 E003CC98 27BD00E8 */   addiu    $sp, $sp, 0xe8
/* 35015C E003CC9C 00000000 */  nop       
