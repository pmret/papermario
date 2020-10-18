.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006C5E8
/* 36E7B8 E006C5E8 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* 36E7BC E006C5EC 3C05DB06 */  lui       $a1, 0xdb06
/* 36E7C0 E006C5F0 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 36E7C4 E006C5F4 3C14800A */  lui       $s4, 0x800a
/* 36E7C8 E006C5F8 2694A66C */  addiu     $s4, $s4, -0x5994
/* 36E7CC E006C5FC AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 36E7D0 E006C600 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 36E7D4 E006C604 AFB700CC */  sw        $s7, 0xcc($sp)
/* 36E7D8 E006C608 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 36E7DC E006C60C AFB500C4 */  sw        $s5, 0xc4($sp)
/* 36E7E0 E006C610 AFB300BC */  sw        $s3, 0xbc($sp)
/* 36E7E4 E006C614 AFB200B8 */  sw        $s2, 0xb8($sp)
/* 36E7E8 E006C618 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 36E7EC E006C61C AFB000B0 */  sw        $s0, 0xb0($sp)
/* 36E7F0 E006C620 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 36E7F4 E006C624 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 36E7F8 E006C628 8E860000 */  lw        $a2, ($s4)
/* 36E7FC E006C62C 8C93000C */  lw        $s3, 0xc($a0)
/* 36E800 E006C630 00C0182D */  daddu     $v1, $a2, $zero
/* 36E804 E006C634 8E750000 */  lw        $s5, ($s3)
/* 36E808 E006C638 24C60008 */  addiu     $a2, $a2, 8
/* 36E80C E006C63C AE860000 */  sw        $a2, ($s4)
/* 36E810 E006C640 8E670018 */  lw        $a3, 0x18($s3)
/* 36E814 E006C644 00151080 */  sll       $v0, $s5, 2
/* 36E818 E006C648 3C0AE007 */  lui       $t2, 0xe007
/* 36E81C E006C64C 01425021 */  addu      $t2, $t2, $v0
/* 36E820 E006C650 8D4ACB60 */  lw        $t2, -0x34a0($t2)
/* 36E824 E006C654 34A50024 */  ori       $a1, $a1, 0x24
/* 36E828 E006C658 AFAA00A4 */  sw        $t2, 0xa4($sp)
/* 36E82C E006C65C 3C08E007 */  lui       $t0, 0xe007
/* 36E830 E006C660 01024021 */  addu      $t0, $t0, $v0
/* 36E834 E006C664 8D08CB78 */  lw        $t0, -0x3488($t0)
/* 36E838 E006C668 3C02E700 */  lui       $v0, 0xe700
/* 36E83C E006C66C AC620000 */  sw        $v0, ($v1)
/* 36E840 E006C670 AC600004 */  sw        $zero, 4($v1)
/* 36E844 E006C674 ACC50000 */  sw        $a1, ($a2)
/* 36E848 E006C678 8C830010 */  lw        $v1, 0x10($a0)
/* 36E84C E006C67C 24C20008 */  addiu     $v0, $a2, 8
/* 36E850 E006C680 AE820000 */  sw        $v0, ($s4)
/* 36E854 E006C684 8C62001C */  lw        $v0, 0x1c($v1)
/* 36E858 E006C688 3C038000 */  lui       $v1, 0x8000
/* 36E85C E006C68C 00431021 */  addu      $v0, $v0, $v1
/* 36E860 E006C690 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 36E864 E006C694 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 36E868 E006C698 3C04800B */  lui       $a0, %hi(gCameras)
/* 36E86C E006C69C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 36E870 E006C6A0 ACC20004 */  sw        $v0, 4($a2)
/* 36E874 E006C6A4 00031080 */  sll       $v0, $v1, 2
/* 36E878 E006C6A8 00431021 */  addu      $v0, $v0, $v1
/* 36E87C E006C6AC 00021080 */  sll       $v0, $v0, 2
/* 36E880 E006C6B0 00431023 */  subu      $v0, $v0, $v1
/* 36E884 E006C6B4 000218C0 */  sll       $v1, $v0, 3
/* 36E888 E006C6B8 00431021 */  addu      $v0, $v0, $v1
/* 36E88C E006C6BC 000210C0 */  sll       $v0, $v0, 3
/* 36E890 E006C6C0 00441821 */  addu      $v1, $v0, $a0
/* 36E894 E006C6C4 24020001 */  addiu     $v0, $zero, 1
/* 36E898 E006C6C8 16A20004 */  bne       $s5, $v0, .LE006C6DC
/* 36E89C E006C6CC 3C02DE00 */   lui      $v0, 0xde00
/* 36E8A0 E006C6D0 28E20012 */  slti      $v0, $a3, 0x12
/* 36E8A4 E006C6D4 14400111 */  bnez      $v0, .LE006CB1C
/* 36E8A8 E006C6D8 3C02DE00 */   lui      $v0, 0xde00
.LE006C6DC:
/* 36E8AC E006C6DC ACC20008 */  sw        $v0, 8($a2)
/* 36E8B0 E006C6E0 ACC8000C */  sw        $t0, 0xc($a2)
/* 36E8B4 E006C6E4 C666001C */  lwc1      $f6, 0x1c($s3)
/* 36E8B8 E006C6E8 3C014080 */  lui       $at, 0x4080
/* 36E8BC E006C6EC 44814000 */  mtc1      $at, $f8
/* 36E8C0 E006C6F0 00000000 */  nop       
/* 36E8C4 E006C6F4 46083182 */  mul.s     $f6, $f6, $f8
/* 36E8C8 E006C6F8 00000000 */  nop       
/* 36E8CC E006C6FC C6640020 */  lwc1      $f4, 0x20($s3)
/* 36E8D0 E006C700 46082102 */  mul.s     $f4, $f4, $f8
/* 36E8D4 E006C704 00000000 */  nop       
/* 36E8D8 E006C708 C6620024 */  lwc1      $f2, 0x24($s3)
/* 36E8DC E006C70C 46081082 */  mul.s     $f2, $f2, $f8
/* 36E8E0 E006C710 00000000 */  nop       
/* 36E8E4 E006C714 24C20010 */  addiu     $v0, $a2, 0x10
/* 36E8E8 E006C718 AE820000 */  sw        $v0, ($s4)
/* 36E8EC E006C71C C6600028 */  lwc1      $f0, 0x28($s3)
/* 36E8F0 E006C720 46080002 */  mul.s     $f0, $f0, $f8
/* 36E8F4 E006C724 00000000 */  nop       
/* 36E8F8 E006C728 2AA20003 */  slti      $v0, $s5, 3
/* 36E8FC E006C72C 4600328D */  trunc.w.s $f10, $f6
/* 36E900 E006C730 44165000 */  mfc1      $s6, $f10
/* 36E904 E006C734 4600228D */  trunc.w.s $f10, $f4
/* 36E908 E006C738 44175000 */  mfc1      $s7, $f10
/* 36E90C E006C73C 4600128D */  trunc.w.s $f10, $f2
/* 36E910 E006C740 441E5000 */  mfc1      $fp, $f10
/* 36E914 E006C744 4600028D */  trunc.w.s $f10, $f0
/* 36E918 E006C748 E7AA00A8 */  swc1      $f10, 0xa8($sp)
/* 36E91C E006C74C 10400057 */  beqz      $v0, .LE006C8AC
/* 36E920 E006C750 27A40020 */   addiu    $a0, $sp, 0x20
/* 36E924 E006C754 06A00056 */  bltz      $s5, .LE006C8B0
/* 36E928 E006C758 3C120001 */   lui      $s2, 1
/* 36E92C E006C75C 27A500A0 */  addiu     $a1, $sp, 0xa0
/* 36E930 E006C760 3C0641F0 */  lui       $a2, 0x41f0
/* 36E934 E006C764 8462000A */  lh        $v0, 0xa($v1)
/* 36E938 E006C768 8463000C */  lh        $v1, 0xc($v1)
/* 36E93C E006C76C 3C014680 */  lui       $at, 0x4680
/* 36E940 E006C770 44811000 */  mtc1      $at, $f2
/* 36E944 E006C774 3C013F80 */  lui       $at, 0x3f80
/* 36E948 E006C778 44812000 */  mtc1      $at, $f4
/* 36E94C E006C77C 44823000 */  mtc1      $v0, $f6
/* 36E950 E006C780 00000000 */  nop       
/* 36E954 E006C784 468031A0 */  cvt.s.w   $f6, $f6
/* 36E958 E006C788 44830000 */  mtc1      $v1, $f0
/* 36E95C E006C78C 00000000 */  nop       
/* 36E960 E006C790 46800020 */  cvt.s.w   $f0, $f0
/* 36E964 E006C794 46003183 */  div.s     $f6, $f6, $f0
/* 36E968 E006C798 44073000 */  mfc1      $a3, $f6
/* 36E96C E006C79C 36521630 */  ori       $s2, $s2, 0x1630
/* 36E970 E006C7A0 E7A80010 */  swc1      $f8, 0x10($sp)
/* 36E974 E006C7A4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 36E978 E006C7A8 0C080160 */  jal       func_E0200580
/* 36E97C E006C7AC E7A40018 */   swc1     $f4, 0x18($sp)
/* 36E980 E006C7B0 27A40020 */  addiu     $a0, $sp, 0x20
/* 36E984 E006C7B4 3C108007 */  lui       $s0, 0x8007
/* 36E988 E006C7B8 261041F0 */  addiu     $s0, $s0, 0x41f0
/* 36E98C E006C7BC 3C11800A */  lui       $s1, 0x800a
/* 36E990 E006C7C0 2631A674 */  addiu     $s1, $s1, -0x598c
/* 36E994 E006C7C4 96050000 */  lhu       $a1, ($s0)
/* 36E998 E006C7C8 8E220000 */  lw        $v0, ($s1)
/* 36E99C E006C7CC 00052980 */  sll       $a1, $a1, 6
/* 36E9A0 E006C7D0 00B22821 */  addu      $a1, $a1, $s2
/* 36E9A4 E006C7D4 0C080118 */  jal       func_E0200460
/* 36E9A8 E006C7D8 00452821 */   addu     $a1, $v0, $a1
/* 36E9AC E006C7DC 3C02DA38 */  lui       $v0, 0xda38
/* 36E9B0 E006C7E0 34420007 */  ori       $v0, $v0, 7
/* 36E9B4 E006C7E4 27A40020 */  addiu     $a0, $sp, 0x20
/* 36E9B8 E006C7E8 8E880000 */  lw        $t0, ($s4)
/* 36E9BC E006C7EC 3C07C3FA */  lui       $a3, 0xc3fa
/* 36E9C0 E006C7F0 96090000 */  lhu       $t1, ($s0)
/* 36E9C4 E006C7F4 0100282D */  daddu     $a1, $t0, $zero
/* 36E9C8 E006C7F8 ACA20000 */  sw        $v0, ($a1)
/* 36E9CC E006C7FC 3122FFFF */  andi      $v0, $t1, 0xffff
/* 36E9D0 E006C800 00021180 */  sll       $v0, $v0, 6
/* 36E9D4 E006C804 00521021 */  addu      $v0, $v0, $s2
/* 36E9D8 E006C808 8E230000 */  lw        $v1, ($s1)
/* 36E9DC E006C80C 25080008 */  addiu     $t0, $t0, 8
/* 36E9E0 E006C810 00621821 */  addu      $v1, $v1, $v0
/* 36E9E4 E006C814 ACA30004 */  sw        $v1, 4($a1)
/* 36E9E8 E006C818 8E650004 */  lw        $a1, 4($s3)
/* 36E9EC E006C81C 8E660008 */  lw        $a2, 8($s3)
/* 36E9F0 E006C820 25290001 */  addiu     $t1, $t1, 1
/* 36E9F4 E006C824 AE880000 */  sw        $t0, ($s4)
/* 36E9F8 E006C828 0C080108 */  jal       func_E0200420
/* 36E9FC E006C82C A6090000 */   sh       $t1, ($s0)
/* 36EA00 E006C830 27A40020 */  addiu     $a0, $sp, 0x20
/* 36EA04 E006C834 96050000 */  lhu       $a1, ($s0)
/* 36EA08 E006C838 8E220000 */  lw        $v0, ($s1)
/* 36EA0C E006C83C 00052980 */  sll       $a1, $a1, 6
/* 36EA10 E006C840 00B22821 */  addu      $a1, $a1, $s2
/* 36EA14 E006C844 0C080118 */  jal       func_E0200460
/* 36EA18 E006C848 00452821 */   addu     $a1, $v0, $a1
/* 36EA1C E006C84C 3C03DA38 */  lui       $v1, 0xda38
/* 36EA20 E006C850 34630002 */  ori       $v1, $v1, 2
/* 36EA24 E006C854 3C06FF2F */  lui       $a2, 0xff2f
/* 36EA28 E006C858 34C6C6FF */  ori       $a2, $a2, 0xc6ff
/* 36EA2C E006C85C 8E840000 */  lw        $a0, ($s4)
/* 36EA30 E006C860 96020000 */  lhu       $v0, ($s0)
/* 36EA34 E006C864 0080282D */  daddu     $a1, $a0, $zero
/* 36EA38 E006C868 24840008 */  addiu     $a0, $a0, 8
/* 36EA3C E006C86C AE840000 */  sw        $a0, ($s4)
/* 36EA40 E006C870 ACA30000 */  sw        $v1, ($a1)
/* 36EA44 E006C874 24430001 */  addiu     $v1, $v0, 1
/* 36EA48 E006C878 3042FFFF */  andi      $v0, $v0, 0xffff
/* 36EA4C E006C87C 00021180 */  sll       $v0, $v0, 6
/* 36EA50 E006C880 A6030000 */  sh        $v1, ($s0)
/* 36EA54 E006C884 8E230000 */  lw        $v1, ($s1)
/* 36EA58 E006C888 00521021 */  addu      $v0, $v0, $s2
/* 36EA5C E006C88C 00621821 */  addu      $v1, $v1, $v0
/* 36EA60 E006C890 24820008 */  addiu     $v0, $a0, 8
/* 36EA64 E006C894 ACA30004 */  sw        $v1, 4($a1)
/* 36EA68 E006C898 AE820000 */  sw        $v0, ($s4)
/* 36EA6C E006C89C 3C02FA00 */  lui       $v0, 0xfa00
/* 36EA70 E006C8A0 AC820000 */  sw        $v0, ($a0)
/* 36EA74 E006C8A4 0801B27A */  j         .LE006C9E8
/* 36EA78 E006C8A8 AC860004 */   sw       $a2, 4($a0)
.LE006C8AC:
/* 36EA7C E006C8AC 3C120001 */  lui       $s2, 1
.LE006C8B0:
/* 36EA80 E006C8B0 8E650004 */  lw        $a1, 4($s3)
/* 36EA84 E006C8B4 8E660008 */  lw        $a2, 8($s3)
/* 36EA88 E006C8B8 8E67000C */  lw        $a3, 0xc($s3)
/* 36EA8C E006C8BC 0C080108 */  jal       func_E0200420
/* 36EA90 E006C8C0 36521630 */   ori      $s2, $s2, 0x1630
/* 36EA94 E006C8C4 27B00060 */  addiu     $s0, $sp, 0x60
/* 36EA98 E006C8C8 4480A000 */  mtc1      $zero, $f20
/* 36EA9C E006C8CC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 36EAA0 E006C8D0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 36EAA4 E006C8D4 3C013F80 */  lui       $at, 0x3f80
/* 36EAA8 E006C8D8 4481B000 */  mtc1      $at, $f22
/* 36EAAC E006C8DC 00031080 */  sll       $v0, $v1, 2
/* 36EAB0 E006C8E0 00431021 */  addu      $v0, $v0, $v1
/* 36EAB4 E006C8E4 00021080 */  sll       $v0, $v0, 2
/* 36EAB8 E006C8E8 00431023 */  subu      $v0, $v0, $v1
/* 36EABC E006C8EC 000218C0 */  sll       $v1, $v0, 3
/* 36EAC0 E006C8F0 00431021 */  addu      $v0, $v0, $v1
/* 36EAC4 E006C8F4 000210C0 */  sll       $v0, $v0, 3
/* 36EAC8 E006C8F8 4406A000 */  mfc1      $a2, $f20
/* 36EACC E006C8FC 3C01800B */  lui       $at, 0x800b
/* 36EAD0 E006C900 00220821 */  addu      $at, $at, $v0
/* 36EAD4 E006C904 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 36EAD8 E006C908 4407B000 */  mfc1      $a3, $f22
/* 36EADC E006C90C 46000007 */  neg.s     $f0, $f0
/* 36EAE0 E006C910 44050000 */  mfc1      $a1, $f0
/* 36EAE4 E006C914 0200202D */  daddu     $a0, $s0, $zero
/* 36EAE8 E006C918 0C080104 */  jal       func_E0200410
/* 36EAEC E006C91C E7B40010 */   swc1     $f20, 0x10($sp)
/* 36EAF0 E006C920 0200202D */  daddu     $a0, $s0, $zero
/* 36EAF4 E006C924 27A50020 */  addiu     $a1, $sp, 0x20
/* 36EAF8 E006C928 0C080114 */  jal       func_E0200450
/* 36EAFC E006C92C 00A0302D */   daddu    $a2, $a1, $zero
/* 36EB00 E006C930 0200202D */  daddu     $a0, $s0, $zero
/* 36EB04 E006C934 4405A000 */  mfc1      $a1, $f20
/* 36EB08 E006C938 4407B000 */  mfc1      $a3, $f22
/* 36EB0C E006C93C 0C080108 */  jal       func_E0200420
/* 36EB10 E006C940 00A0302D */   daddu    $a2, $a1, $zero
/* 36EB14 E006C944 0200202D */  daddu     $a0, $s0, $zero
/* 36EB18 E006C948 27A50020 */  addiu     $a1, $sp, 0x20
/* 36EB1C E006C94C 0C080114 */  jal       func_E0200450
/* 36EB20 E006C950 00A0302D */   daddu    $a2, $a1, $zero
/* 36EB24 E006C954 27A40020 */  addiu     $a0, $sp, 0x20
/* 36EB28 E006C958 3C108007 */  lui       $s0, 0x8007
/* 36EB2C E006C95C 261041F0 */  addiu     $s0, $s0, 0x41f0
/* 36EB30 E006C960 3C11800A */  lui       $s1, 0x800a
/* 36EB34 E006C964 2631A674 */  addiu     $s1, $s1, -0x598c
/* 36EB38 E006C968 96050000 */  lhu       $a1, ($s0)
/* 36EB3C E006C96C 8E220000 */  lw        $v0, ($s1)
/* 36EB40 E006C970 00052980 */  sll       $a1, $a1, 6
/* 36EB44 E006C974 00B22821 */  addu      $a1, $a1, $s2
/* 36EB48 E006C978 0C080118 */  jal       func_E0200460
/* 36EB4C E006C97C 00452821 */   addu     $a1, $v0, $a1
/* 36EB50 E006C980 3C03DA38 */  lui       $v1, 0xda38
/* 36EB54 E006C984 3C05800A */  lui       $a1, 0x800a
/* 36EB58 E006C988 24A5A66C */  addiu     $a1, $a1, -0x5994
/* 36EB5C E006C98C 34630002 */  ori       $v1, $v1, 2
/* 36EB60 E006C990 8CA40000 */  lw        $a0, ($a1)
/* 36EB64 E006C994 96020000 */  lhu       $v0, ($s0)
/* 36EB68 E006C998 0080302D */  daddu     $a2, $a0, $zero
/* 36EB6C E006C99C 24840008 */  addiu     $a0, $a0, 8
/* 36EB70 E006C9A0 ACA40000 */  sw        $a0, ($a1)
/* 36EB74 E006C9A4 ACC30000 */  sw        $v1, ($a2)
/* 36EB78 E006C9A8 24430001 */  addiu     $v1, $v0, 1
/* 36EB7C E006C9AC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 36EB80 E006C9B0 00021180 */  sll       $v0, $v0, 6
/* 36EB84 E006C9B4 A6030000 */  sh        $v1, ($s0)
/* 36EB88 E006C9B8 8E230000 */  lw        $v1, ($s1)
/* 36EB8C E006C9BC 00521021 */  addu      $v0, $v0, $s2
/* 36EB90 E006C9C0 00621821 */  addu      $v1, $v1, $v0
/* 36EB94 E006C9C4 24820008 */  addiu     $v0, $a0, 8
/* 36EB98 E006C9C8 ACC30004 */  sw        $v1, 4($a2)
/* 36EB9C E006C9CC ACA20000 */  sw        $v0, ($a1)
/* 36EBA0 E006C9D0 3C02FA00 */  lui       $v0, 0xfa00
/* 36EBA4 E006C9D4 AC820000 */  sw        $v0, ($a0)
/* 36EBA8 E006C9D8 92620013 */  lbu       $v0, 0x13($s3)
/* 36EBAC E006C9DC 3C03FFFF */  lui       $v1, 0xffff
/* 36EBB0 E006C9E0 00431025 */  or        $v0, $v0, $v1
/* 36EBB4 E006C9E4 AC820004 */  sw        $v0, 4($a0)
.LE006C9E8:
/* 36EBB8 E006C9E8 3C06D838 */  lui       $a2, 0xd838
/* 36EBBC E006C9EC 3C08800A */  lui       $t0, 0x800a
/* 36EBC0 E006C9F0 2508A66C */  addiu     $t0, $t0, -0x5994
/* 36EBC4 E006C9F4 34C60002 */  ori       $a2, $a2, 2
/* 36EBC8 E006C9F8 32C30FFF */  andi      $v1, $s6, 0xfff
/* 36EBCC E006C9FC 00031B00 */  sll       $v1, $v1, 0xc
/* 36EBD0 E006CA00 32E20FFF */  andi      $v0, $s7, 0xfff
/* 36EBD4 E006CA04 3C05F200 */  lui       $a1, 0xf200
/* 36EBD8 E006CA08 00451025 */  or        $v0, $v0, $a1
/* 36EBDC E006CA0C 00621825 */  or        $v1, $v1, $v0
/* 36EBE0 E006CA10 26C203FC */  addiu     $v0, $s6, 0x3fc
/* 36EBE4 E006CA14 30420FFF */  andi      $v0, $v0, 0xfff
/* 36EBE8 E006CA18 8D070000 */  lw        $a3, ($t0)
/* 36EBEC E006CA1C 00021300 */  sll       $v0, $v0, 0xc
/* 36EBF0 E006CA20 00E0202D */  daddu     $a0, $a3, $zero
/* 36EBF4 E006CA24 24E70008 */  addiu     $a3, $a3, 8
/* 36EBF8 E006CA28 AD070000 */  sw        $a3, ($t0)
/* 36EBFC E006CA2C AC830000 */  sw        $v1, ($a0)
/* 36EC00 E006CA30 26E3007C */  addiu     $v1, $s7, 0x7c
/* 36EC04 E006CA34 30630FFF */  andi      $v1, $v1, 0xfff
/* 36EC08 E006CA38 00431025 */  or        $v0, $v0, $v1
/* 36EC0C E006CA3C AC820004 */  sw        $v0, 4($a0)
/* 36EC10 E006CA40 24E20008 */  addiu     $v0, $a3, 8
/* 36EC14 E006CA44 33C30FFF */  andi      $v1, $fp, 0xfff
/* 36EC18 E006CA48 00031B00 */  sll       $v1, $v1, 0xc
/* 36EC1C E006CA4C AD020000 */  sw        $v0, ($t0)
/* 36EC20 E006CA50 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 36EC24 E006CA54 3C040100 */  lui       $a0, 0x100
/* 36EC28 E006CA58 31420FFF */  andi      $v0, $t2, 0xfff
/* 36EC2C E006CA5C 00451025 */  or        $v0, $v0, $a1
/* 36EC30 E006CA60 00621825 */  or        $v1, $v1, $v0
/* 36EC34 E006CA64 27C203FC */  addiu     $v0, $fp, 0x3fc
/* 36EC38 E006CA68 30420FFF */  andi      $v0, $v0, 0xfff
/* 36EC3C E006CA6C 00021300 */  sll       $v0, $v0, 0xc
/* 36EC40 E006CA70 ACE30000 */  sw        $v1, ($a3)
/* 36EC44 E006CA74 2543007C */  addiu     $v1, $t2, 0x7c
/* 36EC48 E006CA78 30630FFF */  andi      $v1, $v1, 0xfff
/* 36EC4C E006CA7C 00641825 */  or        $v1, $v1, $a0
/* 36EC50 E006CA80 00431025 */  or        $v0, $v0, $v1
/* 36EC54 E006CA84 ACE20004 */  sw        $v0, 4($a3)
/* 36EC58 E006CA88 24E20010 */  addiu     $v0, $a3, 0x10
/* 36EC5C E006CA8C AD020000 */  sw        $v0, ($t0)
/* 36EC60 E006CA90 3C02DE00 */  lui       $v0, 0xde00
/* 36EC64 E006CA94 ACE20008 */  sw        $v0, 8($a3)
/* 36EC68 E006CA98 24E20018 */  addiu     $v0, $a3, 0x18
/* 36EC6C E006CA9C 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 36EC70 E006CAA0 3C05E700 */  lui       $a1, 0xe700
/* 36EC74 E006CAA4 ACEA000C */  sw        $t2, 0xc($a3)
/* 36EC78 E006CAA8 AD020000 */  sw        $v0, ($t0)
/* 36EC7C E006CAAC 24E20020 */  addiu     $v0, $a3, 0x20
/* 36EC80 E006CAB0 ACE50010 */  sw        $a1, 0x10($a3)
/* 36EC84 E006CAB4 ACE00014 */  sw        $zero, 0x14($a3)
/* 36EC88 E006CAB8 AD020000 */  sw        $v0, ($t0)
/* 36EC8C E006CABC 24020040 */  addiu     $v0, $zero, 0x40
/* 36EC90 E006CAC0 ACE2001C */  sw        $v0, 0x1c($a3)
/* 36EC94 E006CAC4 2AA20003 */  slti      $v0, $s5, 3
/* 36EC98 E006CAC8 1040000E */  beqz      $v0, .LE006CB04
/* 36EC9C E006CACC ACE60018 */   sw       $a2, 0x18($a3)
/* 36ECA0 E006CAD0 3C04DA38 */  lui       $a0, 0xda38
/* 36ECA4 E006CAD4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 36ECA8 E006CAD8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 36ECAC E006CADC 24E20028 */  addiu     $v0, $a3, 0x28
/* 36ECB0 E006CAE0 AD020000 */  sw        $v0, ($t0)
/* 36ECB4 E006CAE4 3C02800A */  lui       $v0, 0x800a
/* 36ECB8 E006CAE8 8C42A674 */  lw        $v0, -0x598c($v0)
/* 36ECBC E006CAEC 34840007 */  ori       $a0, $a0, 7
/* 36ECC0 E006CAF0 ACE40020 */  sw        $a0, 0x20($a3)
/* 36ECC4 E006CAF4 00031980 */  sll       $v1, $v1, 6
/* 36ECC8 E006CAF8 24630030 */  addiu     $v1, $v1, 0x30
/* 36ECCC E006CAFC 00431021 */  addu      $v0, $v0, $v1
/* 36ECD0 E006CB00 ACE20024 */  sw        $v0, 0x24($a3)
.LE006CB04:
/* 36ECD4 E006CB04 8D020000 */  lw        $v0, ($t0)
/* 36ECD8 E006CB08 0040182D */  daddu     $v1, $v0, $zero
/* 36ECDC E006CB0C 24420008 */  addiu     $v0, $v0, 8
/* 36ECE0 E006CB10 AD020000 */  sw        $v0, ($t0)
/* 36ECE4 E006CB14 AC650000 */  sw        $a1, ($v1)
/* 36ECE8 E006CB18 AC600004 */  sw        $zero, 4($v1)
.LE006CB1C:
/* 36ECEC E006CB1C 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 36ECF0 E006CB20 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 36ECF4 E006CB24 8FB700CC */  lw        $s7, 0xcc($sp)
/* 36ECF8 E006CB28 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 36ECFC E006CB2C 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 36ED00 E006CB30 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 36ED04 E006CB34 8FB300BC */  lw        $s3, 0xbc($sp)
/* 36ED08 E006CB38 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 36ED0C E006CB3C 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 36ED10 E006CB40 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 36ED14 E006CB44 D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 36ED18 E006CB48 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 36ED1C E006CB4C 03E00008 */  jr        $ra
/* 36ED20 E006CB50 27BD00E8 */   addiu    $sp, $sp, 0xe8
/* 36ED24 E006CB54 00000000 */  nop       
/* 36ED28 E006CB58 00000000 */  nop       
/* 36ED2C E006CB5C 00000000 */  nop       
