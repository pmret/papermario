.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007E54C
/* 37FC6C E007E54C 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* 37FC70 E007E550 3C06DB06 */  lui       $a2, 0xdb06
/* 37FC74 E007E554 34C60024 */  ori       $a2, $a2, 0x24
/* 37FC78 E007E558 AFA400E8 */  sw        $a0, 0xe8($sp)
/* 37FC7C E007E55C 27A40018 */  addiu     $a0, $sp, 0x18
/* 37FC80 E007E560 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 37FC84 E007E564 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 37FC88 E007E568 26D6A66C */  addiu     $s6, $s6, %lo(gMasterGfxPos)
/* 37FC8C E007E56C AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 37FC90 E007E570 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 37FC94 E007E574 AFB700BC */  sw        $s7, 0xbc($sp)
/* 37FC98 E007E578 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 37FC9C E007E57C AFB400B0 */  sw        $s4, 0xb0($sp)
/* 37FCA0 E007E580 AFB300AC */  sw        $s3, 0xac($sp)
/* 37FCA4 E007E584 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 37FCA8 E007E588 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 37FCAC E007E58C AFB000A0 */  sw        $s0, 0xa0($sp)
/* 37FCB0 E007E590 F7BA00E0 */  sdc1      $f26, 0xe0($sp)
/* 37FCB4 E007E594 F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* 37FCB8 E007E598 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 37FCBC E007E59C F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 37FCC0 E007E5A0 8EC50000 */  lw        $a1, ($s6)
/* 37FCC4 E007E5A4 8FB900E8 */  lw        $t9, 0xe8($sp)
/* 37FCC8 E007E5A8 00A0182D */  daddu     $v1, $a1, $zero
/* 37FCCC E007E5AC 8F31000C */  lw        $s1, 0xc($t9)
/* 37FCD0 E007E5B0 24A50008 */  addiu     $a1, $a1, 8
/* 37FCD4 E007E5B4 AEC50000 */  sw        $a1, ($s6)
/* 37FCD8 E007E5B8 8E390034 */  lw        $t9, 0x34($s1)
/* 37FCDC E007E5BC 3C140001 */  lui       $s4, 1
/* 37FCE0 E007E5C0 AFB90098 */  sw        $t9, 0x98($sp)
/* 37FCE4 E007E5C4 C6380030 */  lwc1      $f24, 0x30($s1)
/* 37FCE8 E007E5C8 8E300004 */  lw        $s0, 4($s1)
/* 37FCEC E007E5CC C63A0028 */  lwc1      $f26, 0x28($s1)
/* 37FCF0 E007E5D0 C636002C */  lwc1      $f22, 0x2c($s1)
/* 37FCF4 E007E5D4 3C02E700 */  lui       $v0, 0xe700
/* 37FCF8 E007E5D8 AC620000 */  sw        $v0, ($v1)
/* 37FCFC E007E5DC AC600004 */  sw        $zero, 4($v1)
/* 37FD00 E007E5E0 ACA60000 */  sw        $a2, ($a1)
/* 37FD04 E007E5E4 8FB900E8 */  lw        $t9, 0xe8($sp)
/* 37FD08 E007E5E8 8F230010 */  lw        $v1, 0x10($t9)
/* 37FD0C E007E5EC 24A20008 */  addiu     $v0, $a1, 8
/* 37FD10 E007E5F0 AEC20000 */  sw        $v0, ($s6)
/* 37FD14 E007E5F4 8C62001C */  lw        $v0, 0x1c($v1)
/* 37FD18 E007E5F8 3C038000 */  lui       $v1, 0x8000
/* 37FD1C E007E5FC 00431021 */  addu      $v0, $v0, $v1
/* 37FD20 E007E600 ACA20004 */  sw        $v0, 4($a1)
/* 37FD24 E007E604 8E250008 */  lw        $a1, 8($s1)
/* 37FD28 E007E608 8E26000C */  lw        $a2, 0xc($s1)
/* 37FD2C E007E60C 8E270010 */  lw        $a3, 0x10($s1)
/* 37FD30 E007E610 4480A000 */  mtc1      $zero, $f20
/* 37FD34 E007E614 0C080108 */  jal       func_E0200420
/* 37FD38 E007E618 36941630 */   ori      $s4, $s4, 0x1630
/* 37FD3C E007E61C 27B50058 */  addiu     $s5, $sp, 0x58
/* 37FD40 E007E620 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 37FD44 E007E624 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 37FD48 E007E628 4406A000 */  mfc1      $a2, $f20
/* 37FD4C E007E62C 00031080 */  sll       $v0, $v1, 2
/* 37FD50 E007E630 00431021 */  addu      $v0, $v0, $v1
/* 37FD54 E007E634 00021080 */  sll       $v0, $v0, 2
/* 37FD58 E007E638 00431023 */  subu      $v0, $v0, $v1
/* 37FD5C E007E63C 000218C0 */  sll       $v1, $v0, 3
/* 37FD60 E007E640 00431021 */  addu      $v0, $v0, $v1
/* 37FD64 E007E644 000210C0 */  sll       $v0, $v0, 3
/* 37FD68 E007E648 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 37FD6C E007E64C 00220821 */  addu      $at, $at, $v0
/* 37FD70 E007E650 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 37FD74 E007E654 3C073F80 */  lui       $a3, 0x3f80
/* 37FD78 E007E658 46000007 */  neg.s     $f0, $f0
/* 37FD7C E007E65C 44050000 */  mfc1      $a1, $f0
/* 37FD80 E007E660 02A0202D */  daddu     $a0, $s5, $zero
/* 37FD84 E007E664 0C080104 */  jal       func_E0200410
/* 37FD88 E007E668 E7B40010 */   swc1     $f20, 0x10($sp)
/* 37FD8C E007E66C 02A0202D */  daddu     $a0, $s5, $zero
/* 37FD90 E007E670 27A50018 */  addiu     $a1, $sp, 0x18
/* 37FD94 E007E674 0C080114 */  jal       func_E0200450
/* 37FD98 E007E678 00A0302D */   daddu    $a2, $a1, $zero
/* 37FD9C E007E67C 27A40018 */  addiu     $a0, $sp, 0x18
/* 37FDA0 E007E680 3C138007 */  lui       $s3, %hi(gMatrixListPos)
/* 37FDA4 E007E684 267341F0 */  addiu     $s3, $s3, %lo(gMatrixListPos)
/* 37FDA8 E007E688 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 37FDAC E007E68C 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 37FDB0 E007E690 96650000 */  lhu       $a1, ($s3)
/* 37FDB4 E007E694 8EE20000 */  lw        $v0, ($s7)
/* 37FDB8 E007E698 00052980 */  sll       $a1, $a1, 6
/* 37FDBC E007E69C 00B42821 */  addu      $a1, $a1, $s4
/* 37FDC0 E007E6A0 0C080118 */  jal       func_E0200460
/* 37FDC4 E007E6A4 00452821 */   addu     $a1, $v0, $a1
/* 37FDC8 E007E6A8 3C03DA38 */  lui       $v1, 0xda38
/* 37FDCC E007E6AC 34630002 */  ori       $v1, $v1, 2
/* 37FDD0 E007E6B0 2610FFFC */  addiu     $s0, $s0, -4
/* 37FDD4 E007E6B4 8EC40000 */  lw        $a0, ($s6)
/* 37FDD8 E007E6B8 96620000 */  lhu       $v0, ($s3)
/* 37FDDC E007E6BC 0080282D */  daddu     $a1, $a0, $zero
/* 37FDE0 E007E6C0 24840008 */  addiu     $a0, $a0, 8
/* 37FDE4 E007E6C4 AEC40000 */  sw        $a0, ($s6)
/* 37FDE8 E007E6C8 ACA30000 */  sw        $v1, ($a1)
/* 37FDEC E007E6CC 24430001 */  addiu     $v1, $v0, 1
/* 37FDF0 E007E6D0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 37FDF4 E007E6D4 00021180 */  sll       $v0, $v0, 6
/* 37FDF8 E007E6D8 A6630000 */  sh        $v1, ($s3)
/* 37FDFC E007E6DC 8EE30000 */  lw        $v1, ($s7)
/* 37FE00 E007E6E0 00541021 */  addu      $v0, $v0, $s4
/* 37FE04 E007E6E4 00621821 */  addu      $v1, $v1, $v0
/* 37FE08 E007E6E8 24820008 */  addiu     $v0, $a0, 8
/* 37FE0C E007E6EC ACA30004 */  sw        $v1, 4($a1)
/* 37FE10 E007E6F0 AEC20000 */  sw        $v0, ($s6)
/* 37FE14 E007E6F4 3C02FA00 */  lui       $v0, 0xfa00
/* 37FE18 E007E6F8 AC820000 */  sw        $v0, ($a0)
/* 37FE1C E007E6FC 9223003F */  lbu       $v1, 0x3f($s1)
/* 37FE20 E007E700 24820010 */  addiu     $v0, $a0, 0x10
/* 37FE24 E007E704 AEC20000 */  sw        $v0, ($s6)
/* 37FE28 E007E708 3C02FB00 */  lui       $v0, 0xfb00
/* 37FE2C E007E70C 3C05FF00 */  lui       $a1, 0xff00
/* 37FE30 E007E710 AC820008 */  sw        $v0, 8($a0)
/* 37FE34 E007E714 00651825 */  or        $v1, $v1, $a1
/* 37FE38 E007E718 AC830004 */  sw        $v1, 4($a0)
/* 37FE3C E007E71C 9222003B */  lbu       $v0, 0x3b($s1)
/* 37FE40 E007E720 2E100003 */  sltiu     $s0, $s0, 3
/* 37FE44 E007E724 00451025 */  or        $v0, $v0, $a1
/* 37FE48 E007E728 1200007F */  beqz      $s0, .LE007E928
/* 37FE4C E007E72C AC82000C */   sw       $v0, 0xc($a0)
/* 37FE50 E007E730 4405A000 */  mfc1      $a1, $f20
/* 37FE54 E007E734 3C064180 */  lui       $a2, 0x4180
/* 37FE58 E007E738 4407A000 */  mfc1      $a3, $f20
/* 37FE5C E007E73C 0C080108 */  jal       func_E0200420
/* 37FE60 E007E740 27A40018 */   addiu    $a0, $sp, 0x18
/* 37FE64 E007E744 27A40018 */  addiu     $a0, $sp, 0x18
/* 37FE68 E007E748 96650000 */  lhu       $a1, ($s3)
/* 37FE6C E007E74C 8EE20000 */  lw        $v0, ($s7)
/* 37FE70 E007E750 00052980 */  sll       $a1, $a1, 6
/* 37FE74 E007E754 00B42821 */  addu      $a1, $a1, $s4
/* 37FE78 E007E758 0C080118 */  jal       func_E0200460
/* 37FE7C E007E75C 00452821 */   addu     $a1, $v0, $a1
/* 37FE80 E007E760 8EC40000 */  lw        $a0, ($s6)
/* 37FE84 E007E764 24120001 */  addiu     $s2, $zero, 1
/* 37FE88 E007E768 0080282D */  daddu     $a1, $a0, $zero
/* 37FE8C E007E76C 24840008 */  addiu     $a0, $a0, 8
/* 37FE90 E007E770 AEC40000 */  sw        $a0, ($s6)
/* 37FE94 E007E774 96620000 */  lhu       $v0, ($s3)
/* 37FE98 E007E778 3C03DA38 */  lui       $v1, 0xda38
/* 37FE9C E007E77C ACA30000 */  sw        $v1, ($a1)
/* 37FEA0 E007E780 00521821 */  addu      $v1, $v0, $s2
/* 37FEA4 E007E784 3042FFFF */  andi      $v0, $v0, 0xffff
/* 37FEA8 E007E788 00021180 */  sll       $v0, $v0, 6
/* 37FEAC E007E78C A6630000 */  sh        $v1, ($s3)
/* 37FEB0 E007E790 8EE30000 */  lw        $v1, ($s7)
/* 37FEB4 E007E794 00541021 */  addu      $v0, $v0, $s4
/* 37FEB8 E007E798 00621821 */  addu      $v1, $v1, $v0
/* 37FEBC E007E79C 3C02DE00 */  lui       $v0, 0xde00
/* 37FEC0 E007E7A0 ACA30004 */  sw        $v1, 4($a1)
/* 37FEC4 E007E7A4 AC820000 */  sw        $v0, ($a0)
/* 37FEC8 E007E7A8 3C020900 */  lui       $v0, 0x900
/* 37FECC E007E7AC 24420DE0 */  addiu     $v0, $v0, 0xde0
/* 37FED0 E007E7B0 AC820004 */  sw        $v0, 4($a0)
/* 37FED4 E007E7B4 8FB900E8 */  lw        $t9, 0xe8($sp)
/* 37FED8 E007E7B8 2631004C */  addiu     $s1, $s1, 0x4c
/* 37FEDC E007E7BC 8F220008 */  lw        $v0, 8($t9)
/* 37FEE0 E007E7C0 24840008 */  addiu     $a0, $a0, 8
/* 37FEE4 E007E7C4 0242102A */  slt       $v0, $s2, $v0
/* 37FEE8 E007E7C8 1040004C */  beqz      $v0, .LE007E8FC
/* 37FEEC E007E7CC AEC40000 */   sw       $a0, ($s6)
/* 37FEF0 E007E7D0 02E0F02D */  daddu     $fp, $s7, $zero
/* 37FEF4 E007E7D4 0260B82D */  daddu     $s7, $s3, $zero
/* 37FEF8 E007E7D8 3C140001 */  lui       $s4, 1
/* 37FEFC E007E7DC 36941630 */  ori       $s4, $s4, 0x1630
/* 37FF00 E007E7E0 02C0982D */  daddu     $s3, $s6, $zero
/* 37FF04 E007E7E4 26300010 */  addiu     $s0, $s1, 0x10
.LE007E7E8:
/* 37FF08 E007E7E8 8E020038 */  lw        $v0, 0x38($s0)
/* 37FF0C E007E7EC 5440003D */  bnel      $v0, $zero, .LE007E8E4
/* 37FF10 E007E7F0 26520001 */   addiu    $s2, $s2, 1
/* 37FF14 E007E7F4 3C013F80 */  lui       $at, 0x3f80
/* 37FF18 E007E7F8 44810000 */  mtc1      $at, $f0
/* 37FF1C E007E7FC 4406A000 */  mfc1      $a2, $f20
/* 37FF20 E007E800 4407A000 */  mfc1      $a3, $f20
/* 37FF24 E007E804 E7A00010 */  swc1      $f0, 0x10($sp)
/* 37FF28 E007E808 8E050014 */  lw        $a1, 0x14($s0)
/* 37FF2C E007E80C 0C080104 */  jal       func_E0200410
/* 37FF30 E007E810 27A40018 */   addiu    $a0, $sp, 0x18
/* 37FF34 E007E814 8E05FFF8 */  lw        $a1, -8($s0)
/* 37FF38 E007E818 8E06FFFC */  lw        $a2, -4($s0)
/* 37FF3C E007E81C 8E070000 */  lw        $a3, ($s0)
/* 37FF40 E007E820 0C080108 */  jal       func_E0200420
/* 37FF44 E007E824 02A0202D */   daddu    $a0, $s5, $zero
/* 37FF48 E007E828 02A0202D */  daddu     $a0, $s5, $zero
/* 37FF4C E007E82C 27A50018 */  addiu     $a1, $sp, 0x18
/* 37FF50 E007E830 0C080114 */  jal       func_E0200450
/* 37FF54 E007E834 00A0302D */   daddu    $a2, $a1, $zero
/* 37FF58 E007E838 27A40018 */  addiu     $a0, $sp, 0x18
/* 37FF5C E007E83C 96E50000 */  lhu       $a1, ($s7)
/* 37FF60 E007E840 8FC20000 */  lw        $v0, ($fp)
/* 37FF64 E007E844 00052980 */  sll       $a1, $a1, 6
/* 37FF68 E007E848 00B42821 */  addu      $a1, $a1, $s4
/* 37FF6C E007E84C 0C080118 */  jal       func_E0200460
/* 37FF70 E007E850 00452821 */   addu     $a1, $v0, $a1
/* 37FF74 E007E854 8E650000 */  lw        $a1, ($s3)
/* 37FF78 E007E858 3C060900 */  lui       $a2, 0x900
/* 37FF7C E007E85C 24C60EB8 */  addiu     $a2, $a2, 0xeb8
/* 37FF80 E007E860 00A0202D */  daddu     $a0, $a1, $zero
/* 37FF84 E007E864 24A50008 */  addiu     $a1, $a1, 8
/* 37FF88 E007E868 AE650000 */  sw        $a1, ($s3)
/* 37FF8C E007E86C 96E20000 */  lhu       $v0, ($s7)
/* 37FF90 E007E870 3C03DA38 */  lui       $v1, 0xda38
/* 37FF94 E007E874 AC830000 */  sw        $v1, ($a0)
/* 37FF98 E007E878 24430001 */  addiu     $v1, $v0, 1
/* 37FF9C E007E87C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 37FFA0 E007E880 00021180 */  sll       $v0, $v0, 6
/* 37FFA4 E007E884 A6E30000 */  sh        $v1, ($s7)
/* 37FFA8 E007E888 8FC30000 */  lw        $v1, ($fp)
/* 37FFAC E007E88C 00541021 */  addu      $v0, $v0, $s4
/* 37FFB0 E007E890 00621821 */  addu      $v1, $v1, $v0
/* 37FFB4 E007E894 3C02DE00 */  lui       $v0, 0xde00
/* 37FFB8 E007E898 AC830004 */  sw        $v1, 4($a0)
/* 37FFBC E007E89C ACA20000 */  sw        $v0, ($a1)
/* 37FFC0 E007E8A0 8E230000 */  lw        $v1, ($s1)
/* 37FFC4 E007E8A4 24A20008 */  addiu     $v0, $a1, 8
/* 37FFC8 E007E8A8 10600003 */  beqz      $v1, .LE007E8B8
/* 37FFCC E007E8AC AE620000 */   sw       $v0, ($s3)
/* 37FFD0 E007E8B0 3C060900 */  lui       $a2, 0x900
/* 37FFD4 E007E8B4 24C60ED8 */  addiu     $a2, $a2, 0xed8
.LE007E8B8:
/* 37FFD8 E007E8B8 3C04D838 */  lui       $a0, 0xd838
/* 37FFDC E007E8BC 8E620000 */  lw        $v0, ($s3)
/* 37FFE0 E007E8C0 34840002 */  ori       $a0, $a0, 2
/* 37FFE4 E007E8C4 ACA60004 */  sw        $a2, 4($a1)
/* 37FFE8 E007E8C8 0040182D */  daddu     $v1, $v0, $zero
/* 37FFEC E007E8CC 24420008 */  addiu     $v0, $v0, 8
/* 37FFF0 E007E8D0 AE620000 */  sw        $v0, ($s3)
/* 37FFF4 E007E8D4 24020040 */  addiu     $v0, $zero, 0x40
/* 37FFF8 E007E8D8 AC640000 */  sw        $a0, ($v1)
/* 37FFFC E007E8DC AC620004 */  sw        $v0, 4($v1)
/* 380000 E007E8E0 26520001 */  addiu     $s2, $s2, 1
.LE007E8E4:
/* 380004 E007E8E4 8FB900E8 */  lw        $t9, 0xe8($sp)
/* 380008 E007E8E8 2610004C */  addiu     $s0, $s0, 0x4c
/* 38000C E007E8EC 8F220008 */  lw        $v0, 8($t9)
/* 380010 E007E8F0 0242102A */  slt       $v0, $s2, $v0
/* 380014 E007E8F4 1440FFBC */  bnez      $v0, .LE007E7E8
/* 380018 E007E8F8 2631004C */   addiu    $s1, $s1, 0x4c
.LE007E8FC:
/* 38001C E007E8FC 3C05D838 */  lui       $a1, 0xd838
/* 380020 E007E900 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 380024 E007E904 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 380028 E007E908 8C620000 */  lw        $v0, ($v1)
/* 38002C E007E90C 34A50002 */  ori       $a1, $a1, 2
/* 380030 E007E910 0040202D */  daddu     $a0, $v0, $zero
/* 380034 E007E914 24420008 */  addiu     $v0, $v0, 8
/* 380038 E007E918 AC620000 */  sw        $v0, ($v1)
/* 38003C E007E91C 24020040 */  addiu     $v0, $zero, 0x40
/* 380040 E007E920 AC850000 */  sw        $a1, ($a0)
/* 380044 E007E924 AC820004 */  sw        $v0, 4($a0)
.LE007E928:
/* 380048 E007E928 3C0DFD48 */  lui       $t5, 0xfd48
/* 38004C E007E92C 35AD000F */  ori       $t5, $t5, 0xf
/* 380050 E007E930 3C09F548 */  lui       $t1, 0xf548
/* 380054 E007E934 35290400 */  ori       $t1, $t1, 0x400
/* 380058 E007E938 3C0E0705 */  lui       $t6, 0x705
/* 38005C E007E93C 35CE4150 */  ori       $t6, $t6, 0x4150
/* 380060 E007E940 3C0F0703 */  lui       $t7, 0x703
/* 380064 E007E944 35EFE07C */  ori       $t7, $t7, 0xe07c
/* 380068 E007E948 3C12F540 */  lui       $s2, 0xf540
/* 38006C E007E94C 36520400 */  ori       $s2, $s2, 0x400
/* 380070 E007E950 3C100005 */  lui       $s0, 5
/* 380074 E007E954 36104150 */  ori       $s0, $s0, 0x4150
/* 380078 E007E958 3C130007 */  lui       $s3, 7
/* 38007C E007E95C 3673C07C */  ori       $s3, $s3, 0xc07c
/* 380080 E007E960 3C14F548 */  lui       $s4, 0xf548
/* 380084 E007E964 36940480 */  ori       $s4, $s4, 0x480
/* 380088 E007E968 3C17F540 */  lui       $s7, 0xf540
/* 38008C E007E96C 36F70480 */  ori       $s7, $s7, 0x480
/* 380090 E007E970 3C160105 */  lui       $s6, 0x105
/* 380094 E007E974 36D64150 */  ori       $s6, $s6, 0x4150
/* 380098 E007E978 3C180107 */  lui       $t8, 0x107
/* 38009C E007E97C 3718C07C */  ori       $t8, $t8, 0xc07c
/* 3800A0 E007E980 27A40018 */  addiu     $a0, $sp, 0x18
/* 3800A4 E007E984 3C1E0001 */  lui       $fp, 1
/* 3800A8 E007E988 37DE1630 */  ori       $fp, $fp, 0x1630
/* 3800AC E007E98C 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3800B0 E007E990 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3800B4 E007E994 3C15DE00 */  lui       $s5, 0xde00
/* 3800B8 E007E998 3C020900 */  lui       $v0, 0x900
/* 3800BC E007E99C 24420D40 */  addiu     $v0, $v0, 0xd40
/* 3800C0 E007E9A0 3C0C0900 */  lui       $t4, 0x900
/* 3800C4 E007E9A4 258C0000 */  addiu     $t4, $t4, 0
/* 3800C8 E007E9A8 3C0BE600 */  lui       $t3, 0xe600
/* 3800CC E007E9AC 3C0AF400 */  lui       $t2, 0xf400
/* 3800D0 E007E9B0 8E230000 */  lw        $v1, ($s1)
/* 3800D4 E007E9B4 4480A000 */  mtc1      $zero, $f20
/* 3800D8 E007E9B8 4405B000 */  mfc1      $a1, $f22
/* 3800DC E007E9BC 0060402D */  daddu     $t0, $v1, $zero
/* 3800E0 E007E9C0 24630008 */  addiu     $v1, $v1, 8
/* 3800E4 E007E9C4 AE230000 */  sw        $v1, ($s1)
/* 3800E8 E007E9C8 AD020004 */  sw        $v0, 4($t0)
/* 3800EC E007E9CC 24620008 */  addiu     $v0, $v1, 8
/* 3800F0 E007E9D0 AD150000 */  sw        $s5, ($t0)
/* 3800F4 E007E9D4 AE220000 */  sw        $v0, ($s1)
/* 3800F8 E007E9D8 24020003 */  addiu     $v0, $zero, 3
/* 3800FC E007E9DC 4406A000 */  mfc1      $a2, $f20
/* 380100 E007E9E0 3C08F200 */  lui       $t0, 0xf200
/* 380104 E007E9E4 AC6D0000 */  sw        $t5, ($v1)
/* 380108 E007E9E8 8FB90098 */  lw        $t9, 0x98($sp)
/* 38010C E007E9EC 4407A000 */  mfc1      $a3, $f20
/* 380110 E007E9F0 00591023 */  subu      $v0, $v0, $t9
/* 380114 E007E9F4 00021240 */  sll       $v0, $v0, 9
/* 380118 E007E9F8 004C1021 */  addu      $v0, $v0, $t4
/* 38011C E007E9FC AC620004 */  sw        $v0, 4($v1)
/* 380120 E007EA00 24620010 */  addiu     $v0, $v1, 0x10
/* 380124 E007EA04 AE220000 */  sw        $v0, ($s1)
/* 380128 E007EA08 24620018 */  addiu     $v0, $v1, 0x18
/* 38012C E007EA0C AC690008 */  sw        $t1, 8($v1)
/* 380130 E007EA10 AC6E000C */  sw        $t6, 0xc($v1)
/* 380134 E007EA14 AE220000 */  sw        $v0, ($s1)
/* 380138 E007EA18 24620020 */  addiu     $v0, $v1, 0x20
/* 38013C E007EA1C AC6B0010 */  sw        $t3, 0x10($v1)
/* 380140 E007EA20 AC600014 */  sw        $zero, 0x14($v1)
/* 380144 E007EA24 AE220000 */  sw        $v0, ($s1)
/* 380148 E007EA28 24620028 */  addiu     $v0, $v1, 0x28
/* 38014C E007EA2C 3C09E700 */  lui       $t1, 0xe700
/* 380150 E007EA30 AC6A0018 */  sw        $t2, 0x18($v1)
/* 380154 E007EA34 AC6F001C */  sw        $t7, 0x1c($v1)
/* 380158 E007EA38 AE220000 */  sw        $v0, ($s1)
/* 38015C E007EA3C 24620030 */  addiu     $v0, $v1, 0x30
/* 380160 E007EA40 AC690020 */  sw        $t1, 0x20($v1)
/* 380164 E007EA44 AC600024 */  sw        $zero, 0x24($v1)
/* 380168 E007EA48 AE220000 */  sw        $v0, ($s1)
/* 38016C E007EA4C 24620038 */  addiu     $v0, $v1, 0x38
/* 380170 E007EA50 AC720028 */  sw        $s2, 0x28($v1)
/* 380174 E007EA54 AC70002C */  sw        $s0, 0x2c($v1)
/* 380178 E007EA58 AE220000 */  sw        $v0, ($s1)
/* 38017C E007EA5C 24620040 */  addiu     $v0, $v1, 0x40
/* 380180 E007EA60 AC680030 */  sw        $t0, 0x30($v1)
/* 380184 E007EA64 AC730034 */  sw        $s3, 0x34($v1)
/* 380188 E007EA68 AE220000 */  sw        $v0, ($s1)
/* 38018C E007EA6C 24020002 */  addiu     $v0, $zero, 2
/* 380190 E007EA70 AC6D0038 */  sw        $t5, 0x38($v1)
/* 380194 E007EA74 00591023 */  subu      $v0, $v0, $t9
/* 380198 E007EA78 00021240 */  sll       $v0, $v0, 9
/* 38019C E007EA7C 004C1021 */  addu      $v0, $v0, $t4
/* 3801A0 E007EA80 AC62003C */  sw        $v0, 0x3c($v1)
/* 3801A4 E007EA84 24620048 */  addiu     $v0, $v1, 0x48
/* 3801A8 E007EA88 AE220000 */  sw        $v0, ($s1)
/* 3801AC E007EA8C 24620050 */  addiu     $v0, $v1, 0x50
/* 3801B0 E007EA90 AC740040 */  sw        $s4, 0x40($v1)
/* 3801B4 E007EA94 AC6E0044 */  sw        $t6, 0x44($v1)
/* 3801B8 E007EA98 AE220000 */  sw        $v0, ($s1)
/* 3801BC E007EA9C 24620058 */  addiu     $v0, $v1, 0x58
/* 3801C0 E007EAA0 AC6B0048 */  sw        $t3, 0x48($v1)
/* 3801C4 E007EAA4 AC60004C */  sw        $zero, 0x4c($v1)
/* 3801C8 E007EAA8 AE220000 */  sw        $v0, ($s1)
/* 3801CC E007EAAC 24620060 */  addiu     $v0, $v1, 0x60
/* 3801D0 E007EAB0 AC6A0050 */  sw        $t2, 0x50($v1)
/* 3801D4 E007EAB4 AC6F0054 */  sw        $t7, 0x54($v1)
/* 3801D8 E007EAB8 AE220000 */  sw        $v0, ($s1)
/* 3801DC E007EABC 24620068 */  addiu     $v0, $v1, 0x68
/* 3801E0 E007EAC0 AC690058 */  sw        $t1, 0x58($v1)
/* 3801E4 E007EAC4 AC60005C */  sw        $zero, 0x5c($v1)
/* 3801E8 E007EAC8 AE220000 */  sw        $v0, ($s1)
/* 3801EC E007EACC 24620070 */  addiu     $v0, $v1, 0x70
/* 3801F0 E007EAD0 AC770060 */  sw        $s7, 0x60($v1)
/* 3801F4 E007EAD4 AC760064 */  sw        $s6, 0x64($v1)
/* 3801F8 E007EAD8 AE220000 */  sw        $v0, ($s1)
/* 3801FC E007EADC AC680068 */  sw        $t0, 0x68($v1)
/* 380200 E007EAE0 0C080108 */  jal       func_E0200420
/* 380204 E007EAE4 AC78006C */   sw       $t8, 0x6c($v1)
/* 380208 E007EAE8 27B00058 */  addiu     $s0, $sp, 0x58
/* 38020C E007EAEC 4405C000 */  mfc1      $a1, $f24
/* 380210 E007EAF0 0200202D */  daddu     $a0, $s0, $zero
/* 380214 E007EAF4 00A0302D */  daddu     $a2, $a1, $zero
/* 380218 E007EAF8 0C080110 */  jal       func_E0200440
/* 38021C E007EAFC 00A0382D */   daddu    $a3, $a1, $zero
/* 380220 E007EB00 0200202D */  daddu     $a0, $s0, $zero
/* 380224 E007EB04 27A50018 */  addiu     $a1, $sp, 0x18
/* 380228 E007EB08 0C080114 */  jal       func_E0200450
/* 38022C E007EB0C 00A0302D */   daddu    $a2, $a1, $zero
/* 380230 E007EB10 4405D000 */  mfc1      $a1, $f26
/* 380234 E007EB14 4406A000 */  mfc1      $a2, $f20
/* 380238 E007EB18 3C073F80 */  lui       $a3, 0x3f80
/* 38023C E007EB1C 0200202D */  daddu     $a0, $s0, $zero
/* 380240 E007EB20 0C080104 */  jal       func_E0200410
/* 380244 E007EB24 AFA60010 */   sw       $a2, 0x10($sp)
/* 380248 E007EB28 0200202D */  daddu     $a0, $s0, $zero
/* 38024C E007EB2C 27A50018 */  addiu     $a1, $sp, 0x18
/* 380250 E007EB30 0C080114 */  jal       func_E0200450
/* 380254 E007EB34 00A0302D */   daddu    $a2, $a1, $zero
/* 380258 E007EB38 27A40018 */  addiu     $a0, $sp, 0x18
/* 38025C E007EB3C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 380260 E007EB40 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 380264 E007EB44 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 380268 E007EB48 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 38026C E007EB4C 96050000 */  lhu       $a1, ($s0)
/* 380270 E007EB50 8E420000 */  lw        $v0, ($s2)
/* 380274 E007EB54 00052980 */  sll       $a1, $a1, 6
/* 380278 E007EB58 00BE2821 */  addu      $a1, $a1, $fp
/* 38027C E007EB5C 0C080118 */  jal       func_E0200460
/* 380280 E007EB60 00452821 */   addu     $a1, $v0, $a1
/* 380284 E007EB64 3C06D838 */  lui       $a2, 0xd838
/* 380288 E007EB68 8E240000 */  lw        $a0, ($s1)
/* 38028C E007EB6C 34C60002 */  ori       $a2, $a2, 2
/* 380290 E007EB70 0080282D */  daddu     $a1, $a0, $zero
/* 380294 E007EB74 24840008 */  addiu     $a0, $a0, 8
/* 380298 E007EB78 AE240000 */  sw        $a0, ($s1)
/* 38029C E007EB7C 96020000 */  lhu       $v0, ($s0)
/* 3802A0 E007EB80 3C03DA38 */  lui       $v1, 0xda38
/* 3802A4 E007EB84 ACA30000 */  sw        $v1, ($a1)
/* 3802A8 E007EB88 24430001 */  addiu     $v1, $v0, 1
/* 3802AC E007EB8C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3802B0 E007EB90 00021180 */  sll       $v0, $v0, 6
/* 3802B4 E007EB94 A6030000 */  sh        $v1, ($s0)
/* 3802B8 E007EB98 8E430000 */  lw        $v1, ($s2)
/* 3802BC E007EB9C 005E1021 */  addu      $v0, $v0, $fp
/* 3802C0 E007EBA0 00621821 */  addu      $v1, $v1, $v0
/* 3802C4 E007EBA4 24820008 */  addiu     $v0, $a0, 8
/* 3802C8 E007EBA8 ACA30004 */  sw        $v1, 4($a1)
/* 3802CC E007EBAC AE220000 */  sw        $v0, ($s1)
/* 3802D0 E007EBB0 3C020900 */  lui       $v0, 0x900
/* 3802D4 E007EBB4 24420EF8 */  addiu     $v0, $v0, 0xef8
/* 3802D8 E007EBB8 AC820004 */  sw        $v0, 4($a0)
/* 3802DC E007EBBC 24820010 */  addiu     $v0, $a0, 0x10
/* 3802E0 E007EBC0 24030040 */  addiu     $v1, $zero, 0x40
/* 3802E4 E007EBC4 AC950000 */  sw        $s5, ($a0)
/* 3802E8 E007EBC8 AE220000 */  sw        $v0, ($s1)
/* 3802EC E007EBCC 24820018 */  addiu     $v0, $a0, 0x18
/* 3802F0 E007EBD0 AC860008 */  sw        $a2, 8($a0)
/* 3802F4 E007EBD4 AC83000C */  sw        $v1, 0xc($a0)
/* 3802F8 E007EBD8 AE220000 */  sw        $v0, ($s1)
/* 3802FC E007EBDC AC860010 */  sw        $a2, 0x10($a0)
/* 380300 E007EBE0 AC830014 */  sw        $v1, 0x14($a0)
/* 380304 E007EBE4 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 380308 E007EBE8 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 38030C E007EBEC 8FB700BC */  lw        $s7, 0xbc($sp)
/* 380310 E007EBF0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 380314 E007EBF4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 380318 E007EBF8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 38031C E007EBFC 8FB300AC */  lw        $s3, 0xac($sp)
/* 380320 E007EC00 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 380324 E007EC04 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 380328 E007EC08 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 38032C E007EC0C D7BA00E0 */  ldc1      $f26, 0xe0($sp)
/* 380330 E007EC10 D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* 380334 E007EC14 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 380338 E007EC18 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 38033C E007EC1C 03E00008 */  jr        $ra
/* 380340 E007EC20 27BD00E8 */   addiu    $sp, $sp, 0xe8
/* 380344 E007EC24 00000000 */  nop       
/* 380348 E007EC28 00000000 */  nop       
/* 38034C E007EC2C 00000000 */  nop       
