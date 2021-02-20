.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006E764
/* 372EF4 E006E764 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 372EF8 E006E768 3C07DB06 */  lui       $a3, 0xdb06
/* 372EFC E006E76C AFB500B4 */  sw        $s5, 0xb4($sp)
/* 372F00 E006E770 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 372F04 E006E774 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 372F08 E006E778 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 372F0C E006E77C AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 372F10 E006E780 AFB700BC */  sw        $s7, 0xbc($sp)
/* 372F14 E006E784 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 372F18 E006E788 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 372F1C E006E78C AFB300AC */  sw        $s3, 0xac($sp)
/* 372F20 E006E790 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 372F24 E006E794 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 372F28 E006E798 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 372F2C E006E79C F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 372F30 E006E7A0 8EA50000 */  lw        $a1, ($s5)
/* 372F34 E006E7A4 8C94000C */  lw        $s4, 0xc($a0)
/* 372F38 E006E7A8 00A0182D */  daddu     $v1, $a1, $zero
/* 372F3C E006E7AC 24A50008 */  addiu     $a1, $a1, 8
/* 372F40 E006E7B0 AEA50000 */  sw        $a1, ($s5)
/* 372F44 E006E7B4 8E860000 */  lw        $a2, ($s4)
/* 372F48 E006E7B8 24A20008 */  addiu     $v0, $a1, 8
/* 372F4C E006E7BC AEA20000 */  sw        $v0, ($s5)
/* 372F50 E006E7C0 C682005C */  lwc1      $f2, 0x5c($s4)
/* 372F54 E006E7C4 00061080 */  sll       $v0, $a2, 2
/* 372F58 E006E7C8 3C0CE007 */  lui       $t4, %hi(D_E006EC00)
/* 372F5C E006E7CC 01826021 */  addu      $t4, $t4, $v0
/* 372F60 E006E7D0 8D8CEC00 */  lw        $t4, %lo(D_E006EC00)($t4)
/* 372F64 E006E7D4 34E70024 */  ori       $a3, $a3, 0x24
/* 372F68 E006E7D8 AFAC0098 */  sw        $t4, 0x98($sp)
/* 372F6C E006E7DC 3C17E007 */  lui       $s7, %hi(D_E006EC0C)
/* 372F70 E006E7E0 02E2B821 */  addu      $s7, $s7, $v0
/* 372F74 E006E7E4 8EF7EC0C */  lw        $s7, %lo(D_E006EC0C)($s7)
/* 372F78 E006E7E8 3C02E700 */  lui       $v0, 0xe700
/* 372F7C E006E7EC 4600110D */  trunc.w.s $f4, $f2
/* 372F80 E006E7F0 44162000 */  mfc1      $s6, $f4
/* 372F84 E006E7F4 00000000 */  nop
/* 372F88 E006E7F8 44960000 */  mtc1      $s6, $f0
/* 372F8C E006E7FC 00000000 */  nop
/* 372F90 E006E800 46800020 */  cvt.s.w   $f0, $f0
/* 372F94 E006E804 46001081 */  sub.s     $f2, $f2, $f0
/* 372F98 E006E808 AC620000 */  sw        $v0, ($v1)
/* 372F9C E006E80C AC600004 */  sw        $zero, 4($v1)
/* 372FA0 E006E810 ACA70000 */  sw        $a3, ($a1)
/* 372FA4 E006E814 8C820010 */  lw        $v0, 0x10($a0)
/* 372FA8 E006E818 3C014380 */  lui       $at, 0x4380
/* 372FAC E006E81C 44810000 */  mtc1      $at, $f0
/* 372FB0 E006E820 8C42001C */  lw        $v0, 0x1c($v0)
/* 372FB4 E006E824 46001082 */  mul.s     $f2, $f2, $f0
/* 372FB8 E006E828 00000000 */  nop
/* 372FBC E006E82C 3C038000 */  lui       $v1, 0x8000
/* 372FC0 E006E830 00431021 */  addu      $v0, $v0, $v1
/* 372FC4 E006E834 ACA20004 */  sw        $v0, 4($a1)
/* 372FC8 E006E838 24020001 */  addiu     $v0, $zero, 1
/* 372FCC E006E83C 4600110D */  trunc.w.s $f4, $f2
/* 372FD0 E006E840 441E2000 */  mfc1      $fp, $f4
/* 372FD4 E006E844 14C20051 */  bne       $a2, $v0, .LE006E98C
/* 372FD8 E006E848 3C0B0100 */   lui      $t3, 0x100
/* 372FDC E006E84C 27A40018 */  addiu     $a0, $sp, 0x18
/* 372FE0 E006E850 3C120001 */  lui       $s2, 1
/* 372FE4 E006E854 8E850018 */  lw        $a1, 0x18($s4)
/* 372FE8 E006E858 8E86001C */  lw        $a2, 0x1c($s4)
/* 372FEC E006E85C 8E870020 */  lw        $a3, 0x20($s4)
/* 372FF0 E006E860 0C080108 */  jal       func_E0200420
/* 372FF4 E006E864 36521630 */   ori      $s2, $s2, 0x1630
/* 372FF8 E006E868 27B00058 */  addiu     $s0, $sp, 0x58
/* 372FFC E006E86C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 373000 E006E870 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 373004 E006E874 44800000 */  mtc1      $zero, $f0
/* 373008 E006E878 00031080 */  sll       $v0, $v1, 2
/* 37300C E006E87C 00431021 */  addu      $v0, $v0, $v1
/* 373010 E006E880 00021080 */  sll       $v0, $v0, 2
/* 373014 E006E884 00431023 */  subu      $v0, $v0, $v1
/* 373018 E006E888 000218C0 */  sll       $v1, $v0, 3
/* 37301C E006E88C 00431021 */  addu      $v0, $v0, $v1
/* 373020 E006E890 000210C0 */  sll       $v0, $v0, 3
/* 373024 E006E894 44060000 */  mfc1      $a2, $f0
/* 373028 E006E898 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 37302C E006E89C 00220821 */  addu      $at, $at, $v0
/* 373030 E006E8A0 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 373034 E006E8A4 3C073F80 */  lui       $a3, 0x3f80
/* 373038 E006E8A8 46000007 */  neg.s     $f0, $f0
/* 37303C E006E8AC 44050000 */  mfc1      $a1, $f0
/* 373040 E006E8B0 0200202D */  daddu     $a0, $s0, $zero
/* 373044 E006E8B4 0C080104 */  jal       func_E0200410
/* 373048 E006E8B8 AFA60010 */   sw       $a2, 0x10($sp)
/* 37304C E006E8BC 0200202D */  daddu     $a0, $s0, $zero
/* 373050 E006E8C0 27A50018 */  addiu     $a1, $sp, 0x18
/* 373054 E006E8C4 0C080114 */  jal       func_E0200450
/* 373058 E006E8C8 00A0302D */   daddu    $a2, $a1, $zero
/* 37305C E006E8CC 27A40018 */  addiu     $a0, $sp, 0x18
/* 373060 E006E8D0 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 373064 E006E8D4 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 373068 E006E8D8 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 37306C E006E8DC 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 373070 E006E8E0 96050000 */  lhu       $a1, ($s0)
/* 373074 E006E8E4 8E220000 */  lw        $v0, ($s1)
/* 373078 E006E8E8 00052980 */  sll       $a1, $a1, 6
/* 37307C E006E8EC 00B22821 */  addu      $a1, $a1, $s2
/* 373080 E006E8F0 0C080118 */  jal       func_E0200460
/* 373084 E006E8F4 00452821 */   addu     $a1, $v0, $a1
/* 373088 E006E8F8 3C03DA38 */  lui       $v1, 0xda38
/* 37308C E006E8FC 34630002 */  ori       $v1, $v1, 2
/* 373090 E006E900 3C06D838 */  lui       $a2, 0xd838
/* 373094 E006E904 34C60002 */  ori       $a2, $a2, 2
/* 373098 E006E908 8EA40000 */  lw        $a0, ($s5)
/* 37309C E006E90C 96020000 */  lhu       $v0, ($s0)
/* 3730A0 E006E910 0080282D */  daddu     $a1, $a0, $zero
/* 3730A4 E006E914 24840008 */  addiu     $a0, $a0, 8
/* 3730A8 E006E918 AEA40000 */  sw        $a0, ($s5)
/* 3730AC E006E91C ACA30000 */  sw        $v1, ($a1)
/* 3730B0 E006E920 24430001 */  addiu     $v1, $v0, 1
/* 3730B4 E006E924 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3730B8 E006E928 00021180 */  sll       $v0, $v0, 6
/* 3730BC E006E92C A6030000 */  sh        $v1, ($s0)
/* 3730C0 E006E930 8E230000 */  lw        $v1, ($s1)
/* 3730C4 E006E934 00521021 */  addu      $v0, $v0, $s2
/* 3730C8 E006E938 00621821 */  addu      $v1, $v1, $v0
/* 3730CC E006E93C 24820008 */  addiu     $v0, $a0, 8
/* 3730D0 E006E940 ACA30004 */  sw        $v1, 4($a1)
/* 3730D4 E006E944 3C03DE00 */  lui       $v1, 0xde00
/* 3730D8 E006E948 AEA20000 */  sw        $v0, ($s5)
/* 3730DC E006E94C 3C020900 */  lui       $v0, 0x900
/* 3730E0 E006E950 24420C20 */  addiu     $v0, $v0, 0xc20
/* 3730E4 E006E954 AC820004 */  sw        $v0, 4($a0)
/* 3730E8 E006E958 24820010 */  addiu     $v0, $a0, 0x10
/* 3730EC E006E95C AC830000 */  sw        $v1, ($a0)
/* 3730F0 E006E960 AEA20000 */  sw        $v0, ($s5)
/* 3730F4 E006E964 3C020900 */  lui       $v0, 0x900
/* 3730F8 E006E968 24420C00 */  addiu     $v0, $v0, 0xc00
/* 3730FC E006E96C AC82000C */  sw        $v0, 0xc($a0)
/* 373100 E006E970 24820018 */  addiu     $v0, $a0, 0x18
/* 373104 E006E974 AC830008 */  sw        $v1, 8($a0)
/* 373108 E006E978 AEA20000 */  sw        $v0, ($s5)
/* 37310C E006E97C 24020040 */  addiu     $v0, $zero, 0x40
/* 373110 E006E980 AC860010 */  sw        $a2, 0x10($a0)
/* 373114 E006E984 AC820014 */  sw        $v0, 0x14($a0)
/* 373118 E006E988 3C0B0100 */  lui       $t3, 0x100
.LE006E98C:
/* 37311C E006E98C 356B0080 */  ori       $t3, $t3, 0x80
/* 373120 E006E990 27A40018 */  addiu     $a0, $sp, 0x18
/* 373124 E006E994 3C130001 */  lui       $s3, 1
/* 373128 E006E998 3C12DE00 */  lui       $s2, 0xde00
/* 37312C E006E99C 8EA60000 */  lw        $a2, ($s5)
/* 373130 E006E9A0 3C0AF200 */  lui       $t2, 0xf200
/* 373134 E006E9A4 00C0102D */  daddu     $v0, $a2, $zero
/* 373138 E006E9A8 24C60008 */  addiu     $a2, $a2, 8
/* 37313C E006E9AC AEA60000 */  sw        $a2, ($s5)
/* 373140 E006E9B0 AC520000 */  sw        $s2, ($v0)
/* 373144 E006E9B4 AC570004 */  sw        $s7, 4($v0)
/* 373148 E006E9B8 24C20008 */  addiu     $v0, $a2, 8
/* 37314C E006E9BC AEA20000 */  sw        $v0, ($s5)
/* 373150 E006E9C0 3C02FA00 */  lui       $v0, 0xfa00
/* 373154 E006E9C4 ACC20000 */  sw        $v0, ($a2)
/* 373158 E006E9C8 92820067 */  lbu       $v0, 0x67($s4)
/* 37315C E006E9CC 9285006B */  lbu       $a1, 0x6b($s4)
/* 373160 E006E9D0 9287006F */  lbu       $a3, 0x6f($s4)
/* 373164 E006E9D4 92880043 */  lbu       $t0, 0x43($s4)
/* 373168 E006E9D8 24C30010 */  addiu     $v1, $a2, 0x10
/* 37316C E006E9DC AEA30000 */  sw        $v1, ($s5)
/* 373170 E006E9E0 3C03FB00 */  lui       $v1, 0xfb00
/* 373174 E006E9E4 ACC30008 */  sw        $v1, 8($a2)
/* 373178 E006E9E8 00161940 */  sll       $v1, $s6, 5
/* 37317C E006E9EC 00021600 */  sll       $v0, $v0, 0x18
/* 373180 E006E9F0 00052C00 */  sll       $a1, $a1, 0x10
/* 373184 E006E9F4 00451025 */  or        $v0, $v0, $a1
/* 373188 E006E9F8 00073A00 */  sll       $a3, $a3, 8
/* 37318C E006E9FC 00471025 */  or        $v0, $v0, $a3
/* 373190 E006EA00 00481025 */  or        $v0, $v0, $t0
/* 373194 E006EA04 ACC20004 */  sw        $v0, 4($a2)
/* 373198 E006EA08 92870073 */  lbu       $a3, 0x73($s4)
/* 37319C E006EA0C 92880077 */  lbu       $t0, 0x77($s4)
/* 3731A0 E006EA10 9289007B */  lbu       $t1, 0x7b($s4)
/* 3731A4 E006EA14 24C20018 */  addiu     $v0, $a2, 0x18
/* 3731A8 E006EA18 AEA20000 */  sw        $v0, ($s5)
/* 3731AC E006EA1C 001611C0 */  sll       $v0, $s6, 7
/* 3731B0 E006EA20 30420FFF */  andi      $v0, $v0, 0xfff
/* 3731B4 E006EA24 00021300 */  sll       $v0, $v0, 0xc
/* 3731B8 E006EA28 004A1025 */  or        $v0, $v0, $t2
/* 3731BC E006EA2C ACC20010 */  sw        $v0, 0x10($a2)
/* 3731C0 E006EA30 24620020 */  addiu     $v0, $v1, 0x20
/* 3731C4 E006EA34 00021080 */  sll       $v0, $v0, 2
/* 3731C8 E006EA38 30420FFF */  andi      $v0, $v0, 0xfff
/* 3731CC E006EA3C 00021300 */  sll       $v0, $v0, 0xc
/* 3731D0 E006EA40 34450080 */  ori       $a1, $v0, 0x80
/* 3731D4 E006EA44 ACC50014 */  sw        $a1, 0x14($a2)
/* 3731D8 E006EA48 24C50020 */  addiu     $a1, $a2, 0x20
/* 3731DC E006EA4C 004A1025 */  or        $v0, $v0, $t2
/* 3731E0 E006EA50 24630040 */  addiu     $v1, $v1, 0x40
/* 3731E4 E006EA54 00031880 */  sll       $v1, $v1, 2
/* 3731E8 E006EA58 30630FFF */  andi      $v1, $v1, 0xfff
/* 3731EC E006EA5C 00031B00 */  sll       $v1, $v1, 0xc
/* 3731F0 E006EA60 006B1825 */  or        $v1, $v1, $t3
/* 3731F4 E006EA64 AEA50000 */  sw        $a1, ($s5)
/* 3731F8 E006EA68 ACC20018 */  sw        $v0, 0x18($a2)
/* 3731FC E006EA6C 33C200FF */  andi      $v0, $fp, 0xff
/* 373200 E006EA70 ACC3001C */  sw        $v1, 0x1c($a2)
/* 373204 E006EA74 00073E00 */  sll       $a3, $a3, 0x18
/* 373208 E006EA78 00084400 */  sll       $t0, $t0, 0x10
/* 37320C E006EA7C 00E83825 */  or        $a3, $a3, $t0
/* 373210 E006EA80 00094A00 */  sll       $t1, $t1, 8
/* 373214 E006EA84 00E93825 */  or        $a3, $a3, $t1
/* 373218 E006EA88 00E23825 */  or        $a3, $a3, $v0
/* 37321C E006EA8C ACC7000C */  sw        $a3, 0xc($a2)
/* 373220 E006EA90 8E85000C */  lw        $a1, 0xc($s4)
/* 373224 E006EA94 8E860010 */  lw        $a2, 0x10($s4)
/* 373228 E006EA98 8E870014 */  lw        $a3, 0x14($s4)
/* 37322C E006EA9C 4480A000 */  mtc1      $zero, $f20
/* 373230 E006EAA0 0C080108 */  jal       func_E0200420
/* 373234 E006EAA4 36731630 */   ori      $s3, $s3, 0x1630
/* 373238 E006EAA8 27B00058 */  addiu     $s0, $sp, 0x58
/* 37323C E006EAAC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 373240 E006EAB0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 373244 E006EAB4 4406A000 */  mfc1      $a2, $f20
/* 373248 E006EAB8 00031080 */  sll       $v0, $v1, 2
/* 37324C E006EABC 00431021 */  addu      $v0, $v0, $v1
/* 373250 E006EAC0 00021080 */  sll       $v0, $v0, 2
/* 373254 E006EAC4 00431023 */  subu      $v0, $v0, $v1
/* 373258 E006EAC8 000218C0 */  sll       $v1, $v0, 3
/* 37325C E006EACC 00431021 */  addu      $v0, $v0, $v1
/* 373260 E006EAD0 000210C0 */  sll       $v0, $v0, 3
/* 373264 E006EAD4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 373268 E006EAD8 00220821 */  addu      $at, $at, $v0
/* 37326C E006EADC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 373270 E006EAE0 3C073F80 */  lui       $a3, 0x3f80
/* 373274 E006EAE4 46000007 */  neg.s     $f0, $f0
/* 373278 E006EAE8 44050000 */  mfc1      $a1, $f0
/* 37327C E006EAEC 0200202D */  daddu     $a0, $s0, $zero
/* 373280 E006EAF0 0C080104 */  jal       func_E0200410
/* 373284 E006EAF4 E7B40010 */   swc1     $f20, 0x10($sp)
/* 373288 E006EAF8 0200202D */  daddu     $a0, $s0, $zero
/* 37328C E006EAFC 27A50018 */  addiu     $a1, $sp, 0x18
/* 373290 E006EB00 0C080114 */  jal       func_E0200450
/* 373294 E006EB04 00A0302D */   daddu    $a2, $a1, $zero
/* 373298 E006EB08 0200202D */  daddu     $a0, $s0, $zero
/* 37329C E006EB0C 8E850038 */  lw        $a1, 0x38($s4)
/* 3732A0 E006EB10 4407A000 */  mfc1      $a3, $f20
/* 3732A4 E006EB14 0C080110 */  jal       func_E0200440
/* 3732A8 E006EB18 00A0302D */   daddu    $a2, $a1, $zero
/* 3732AC E006EB1C 0200202D */  daddu     $a0, $s0, $zero
/* 3732B0 E006EB20 27A50018 */  addiu     $a1, $sp, 0x18
/* 3732B4 E006EB24 0C080114 */  jal       func_E0200450
/* 3732B8 E006EB28 00A0302D */   daddu    $a2, $a1, $zero
/* 3732BC E006EB2C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3732C0 E006EB30 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3732C4 E006EB34 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3732C8 E006EB38 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3732CC E006EB3C 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3732D0 E006EB40 96050000 */  lhu       $a1, ($s0)
/* 3732D4 E006EB44 8E220000 */  lw        $v0, ($s1)
/* 3732D8 E006EB48 00052980 */  sll       $a1, $a1, 6
/* 3732DC E006EB4C 00B32821 */  addu      $a1, $a1, $s3
/* 3732E0 E006EB50 0C080118 */  jal       func_E0200460
/* 3732E4 E006EB54 00452821 */   addu     $a1, $v0, $a1
/* 3732E8 E006EB58 3C06D838 */  lui       $a2, 0xd838
/* 3732EC E006EB5C 8EA40000 */  lw        $a0, ($s5)
/* 3732F0 E006EB60 34C60002 */  ori       $a2, $a2, 2
/* 3732F4 E006EB64 0080282D */  daddu     $a1, $a0, $zero
/* 3732F8 E006EB68 24840008 */  addiu     $a0, $a0, 8
/* 3732FC E006EB6C AEA40000 */  sw        $a0, ($s5)
/* 373300 E006EB70 96020000 */  lhu       $v0, ($s0)
/* 373304 E006EB74 3C03DA38 */  lui       $v1, 0xda38
/* 373308 E006EB78 ACA30000 */  sw        $v1, ($a1)
/* 37330C E006EB7C 24430001 */  addiu     $v1, $v0, 1
/* 373310 E006EB80 3042FFFF */  andi      $v0, $v0, 0xffff
/* 373314 E006EB84 00021180 */  sll       $v0, $v0, 6
/* 373318 E006EB88 A6030000 */  sh        $v1, ($s0)
/* 37331C E006EB8C 8E230000 */  lw        $v1, ($s1)
/* 373320 E006EB90 00531021 */  addu      $v0, $v0, $s3
/* 373324 E006EB94 00621821 */  addu      $v1, $v1, $v0
/* 373328 E006EB98 24820008 */  addiu     $v0, $a0, 8
/* 37332C E006EB9C ACA30004 */  sw        $v1, 4($a1)
/* 373330 E006EBA0 AEA20000 */  sw        $v0, ($s5)
/* 373334 E006EBA4 AC920000 */  sw        $s2, ($a0)
/* 373338 E006EBA8 8FAC0098 */  lw        $t4, 0x98($sp)
/* 37333C E006EBAC 24820010 */  addiu     $v0, $a0, 0x10
/* 373340 E006EBB0 AC8C0004 */  sw        $t4, 4($a0)
/* 373344 E006EBB4 AEA20000 */  sw        $v0, ($s5)
/* 373348 E006EBB8 24020040 */  addiu     $v0, $zero, 0x40
/* 37334C E006EBBC AC860008 */  sw        $a2, 8($a0)
/* 373350 E006EBC0 AC82000C */  sw        $v0, 0xc($a0)
/* 373354 E006EBC4 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 373358 E006EBC8 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 37335C E006EBCC 8FB700BC */  lw        $s7, 0xbc($sp)
/* 373360 E006EBD0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 373364 E006EBD4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 373368 E006EBD8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 37336C E006EBDC 8FB300AC */  lw        $s3, 0xac($sp)
/* 373370 E006EBE0 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 373374 E006EBE4 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 373378 E006EBE8 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 37337C E006EBEC D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 373380 E006EBF0 03E00008 */  jr        $ra
/* 373384 E006EBF4 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 373388 E006EBF8 00000000 */  nop
/* 37338C E006EBFC 00000000 */  nop
