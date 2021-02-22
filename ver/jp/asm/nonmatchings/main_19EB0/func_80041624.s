.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80041624
/* 1CA24 80041624 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 1CA28 80041628 AFB00038 */  sw        $s0, 0x38($sp)
/* 1CA2C 8004162C 3C10800B */  lui       $s0, %hi(D_800B0EF0)
/* 1CA30 80041630 26100EF0 */  addiu     $s0, $s0, %lo(D_800B0EF0)
/* 1CA34 80041634 AFBF0040 */  sw        $ra, 0x40($sp)
/* 1CA38 80041638 AFB1003C */  sw        $s1, 0x3c($sp)
/* 1CA3C 8004163C F7BE0070 */  sdc1      $f30, 0x70($sp)
/* 1CA40 80041640 F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 1CA44 80041644 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 1CA48 80041648 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 1CA4C 8004164C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 1CA50 80041650 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 1CA54 80041654 8E02008C */  lw        $v0, 0x8c($s0)
/* 1CA58 80041658 84440008 */  lh        $a0, 8($v0)
/* 1CA5C 8004165C 0C00E9EB */  jal       func_8003A7AC
/* 1CA60 80041660 0200882D */   daddu    $s1, $s0, $zero
/* 1CA64 80041664 0040382D */  daddu     $a3, $v0, $zero
/* 1CA68 80041668 8E020094 */  lw        $v0, 0x94($s0)
/* 1CA6C 8004166C 3C048011 */  lui       $a0, %hi(D_8010F188)
/* 1CA70 80041670 2484F188 */  addiu     $a0, $a0, %lo(D_8010F188)
/* 1CA74 80041674 1040009E */  beqz      $v0, .L800418F0
/* 1CA78 80041678 240500FF */   addiu    $a1, $zero, 0xff
/* 1CA7C 8004167C 8E030090 */  lw        $v1, 0x90($s0)
/* 1CA80 80041680 1065009B */  beq       $v1, $a1, .L800418F0
/* 1CA84 80041684 00000000 */   nop
/* 1CA88 80041688 8E020098 */  lw        $v0, 0x98($s0)
/* 1CA8C 8004168C 24420001 */  addiu     $v0, $v0, 1
/* 1CA90 80041690 AE020098 */  sw        $v0, 0x98($s0)
/* 1CA94 80041694 2842000B */  slti      $v0, $v0, 0xb
/* 1CA98 80041698 14400002 */  bnez      $v0, .L800416A4
/* 1CA9C 8004169C 2402000A */   addiu    $v0, $zero, 0xa
/* 1CAA0 800416A0 AE020098 */  sw        $v0, 0x98($s0)
.L800416A4:
/* 1CAA4 800416A4 8E020098 */  lw        $v0, 0x98($s0)
/* 1CAA8 800416A8 00621021 */  addu      $v0, $v1, $v0
/* 1CAAC 800416AC AE020090 */  sw        $v0, 0x90($s0)
/* 1CAB0 800416B0 28420100 */  slti      $v0, $v0, 0x100
/* 1CAB4 800416B4 50400001 */  beql      $v0, $zero, .L800416BC
/* 1CAB8 800416B8 AE050090 */   sw       $a1, 0x90($s0)
.L800416BC:
/* 1CABC 800416BC C4FE0038 */  lwc1      $f30, 0x38($a3)
/* 1CAC0 800416C0 C4FA003C */  lwc1      $f26, 0x3c($a3)
/* 1CAC4 800416C4 3C01C477 */  lui       $at, 0xc477
/* 1CAC8 800416C8 34218000 */  ori       $at, $at, 0x8000
/* 1CACC 800416CC 44810000 */  mtc1      $at, $f0
/* 1CAD0 800416D0 C4FC0040 */  lwc1      $f28, 0x40($a3)
/* 1CAD4 800416D4 C4940028 */  lwc1      $f20, 0x28($a0)
/* 1CAD8 800416D8 C498002C */  lwc1      $f24, 0x2c($a0)
/* 1CADC 800416DC C4960030 */  lwc1      $f22, 0x30($a0)
/* 1CAE0 800416E0 4600D03C */  c.lt.s    $f26, $f0
/* 1CAE4 800416E4 00000000 */  nop
/* 1CAE8 800416E8 45000004 */  bc1f      .L800416FC
/* 1CAEC 800416EC 00000000 */   nop
/* 1CAF0 800416F0 4600A786 */  mov.s     $f30, $f20
/* 1CAF4 800416F4 4600C686 */  mov.s     $f26, $f24
/* 1CAF8 800416F8 4600B706 */  mov.s     $f28, $f22
.L800416FC:
/* 1CAFC 800416FC 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 1CB00 80041700 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 1CB04 80041704 80430071 */  lb        $v1, 0x71($v0)
/* 1CB08 80041708 24020002 */  addiu     $v0, $zero, 2
/* 1CB0C 8004170C 1462003C */  bne       $v1, $v0, .L80041800
/* 1CB10 80041710 00000000 */   nop
/* 1CB14 80041714 C6020090 */  lwc1      $f2, 0x90($s0)
/* 1CB18 80041718 468010A0 */  cvt.s.w   $f2, $f2
/* 1CB1C 8004171C 44051000 */  mfc1      $a1, $f2
/* 1CB20 80041720 0C04F395 */  jal       func_8013CE54
/* 1CB24 80041724 2404000A */   addiu    $a0, $zero, 0xa
/* 1CB28 80041728 3C05437F */  lui       $a1, 0x437f
/* 1CB2C 8004172C 0C04F461 */  jal       func_8013D184
/* 1CB30 80041730 24040001 */   addiu    $a0, $zero, 1
/* 1CB34 80041734 24040001 */  addiu     $a0, $zero, 1
/* 1CB38 80041738 0000282D */  daddu     $a1, $zero, $zero
/* 1CB3C 8004173C 00A0302D */  daddu     $a2, $a1, $zero
/* 1CB40 80041740 0C04F3B0 */  jal       func_8013CEC0
/* 1CB44 80041744 00A0382D */   daddu    $a3, $a1, $zero
/* 1CB48 80041748 3C108007 */  lui       $s0, %hi(D_800773E0)
/* 1CB4C 8004174C 261073E0 */  addiu     $s0, $s0, %lo(D_800773E0)
/* 1CB50 80041750 8E040000 */  lw        $a0, ($s0)
/* 1CB54 80041754 4405A000 */  mfc1      $a1, $f20
/* 1CB58 80041758 4407B000 */  mfc1      $a3, $f22
/* 1CB5C 8004175C 3C0141A0 */  lui       $at, 0x41a0
/* 1CB60 80041760 44810000 */  mtc1      $at, $f0
/* 1CB64 80041764 27A20020 */  addiu     $v0, $sp, 0x20
/* 1CB68 80041768 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CB6C 8004176C 4600C600 */  add.s     $f24, $f24, $f0
/* 1CB70 80041770 27A20024 */  addiu     $v0, $sp, 0x24
/* 1CB74 80041774 AFA20014 */  sw        $v0, 0x14($sp)
/* 1CB78 80041778 4406C000 */  mfc1      $a2, $f24
/* 1CB7C 8004177C 27A20028 */  addiu     $v0, $sp, 0x28
/* 1CB80 80041780 0C00B872 */  jal       func_8002E1C8
/* 1CB84 80041784 AFA20018 */   sw       $v0, 0x18($sp)
/* 1CB88 80041788 8E040000 */  lw        $a0, ($s0)
/* 1CB8C 8004178C 4405F000 */  mfc1      $a1, $f30
/* 1CB90 80041790 4407E000 */  mfc1      $a3, $f28
/* 1CB94 80041794 3C014170 */  lui       $at, 0x4170
/* 1CB98 80041798 44810000 */  mtc1      $at, $f0
/* 1CB9C 8004179C 27A2002C */  addiu     $v0, $sp, 0x2c
/* 1CBA0 800417A0 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CBA4 800417A4 4600D680 */  add.s     $f26, $f26, $f0
/* 1CBA8 800417A8 27A20030 */  addiu     $v0, $sp, 0x30
/* 1CBAC 800417AC AFA20014 */  sw        $v0, 0x14($sp)
/* 1CBB0 800417B0 4406D000 */  mfc1      $a2, $f26
/* 1CBB4 800417B4 27A20034 */  addiu     $v0, $sp, 0x34
/* 1CBB8 800417B8 0C00B872 */  jal       func_8002E1C8
/* 1CBBC 800417BC AFA20018 */   sw       $v0, 0x18($sp)
/* 1CBC0 800417C0 24040001 */  addiu     $a0, $zero, 1
/* 1CBC4 800417C4 0000282D */  daddu     $a1, $zero, $zero
/* 1CBC8 800417C8 8FA60020 */  lw        $a2, 0x20($sp)
/* 1CBCC 800417CC 8FA8002C */  lw        $t0, 0x2c($sp)
/* 1CBD0 800417D0 8FA70024 */  lw        $a3, 0x24($sp)
/* 1CBD4 800417D4 8FA30030 */  lw        $v1, 0x30($sp)
/* 1CBD8 800417D8 00C83023 */  subu      $a2, $a2, $t0
/* 1CBDC 800417DC 000617C2 */  srl       $v0, $a2, 0x1f
/* 1CBE0 800417E0 00C23021 */  addu      $a2, $a2, $v0
/* 1CBE4 800417E4 00863007 */  srav      $a2, $a2, $a0
/* 1CBE8 800417E8 00C83021 */  addu      $a2, $a2, $t0
/* 1CBEC 800417EC 00E33823 */  subu      $a3, $a3, $v1
/* 1CBF0 800417F0 000717C2 */  srl       $v0, $a3, 0x1f
/* 1CBF4 800417F4 00E23821 */  addu      $a3, $a3, $v0
/* 1CBF8 800417F8 0801063A */  j         .L800418E8
/* 1CBFC 800417FC 00873807 */   srav     $a3, $a3, $a0
.L80041800:
/* 1CC00 80041800 C6220090 */  lwc1      $f2, 0x90($s1)
/* 1CC04 80041804 468010A0 */  cvt.s.w   $f2, $f2
/* 1CC08 80041808 44051000 */  mfc1      $a1, $f2
/* 1CC0C 8004180C 0C04F38E */  jal       func_8013CE38
/* 1CC10 80041810 2404000A */   addiu    $a0, $zero, 0xa
/* 1CC14 80041814 3C05437F */  lui       $a1, 0x437f
/* 1CC18 80041818 0C04F461 */  jal       func_8013D184
/* 1CC1C 8004181C 0000202D */   daddu    $a0, $zero, $zero
/* 1CC20 80041820 0000202D */  daddu     $a0, $zero, $zero
/* 1CC24 80041824 0080282D */  daddu     $a1, $a0, $zero
/* 1CC28 80041828 0080302D */  daddu     $a2, $a0, $zero
/* 1CC2C 8004182C 0C04F3B0 */  jal       func_8013CEC0
/* 1CC30 80041830 0080382D */   daddu    $a3, $a0, $zero
/* 1CC34 80041834 3C108007 */  lui       $s0, %hi(D_800773E0)
/* 1CC38 80041838 261073E0 */  addiu     $s0, $s0, %lo(D_800773E0)
/* 1CC3C 8004183C 8E040000 */  lw        $a0, ($s0)
/* 1CC40 80041840 4405A000 */  mfc1      $a1, $f20
/* 1CC44 80041844 4407B000 */  mfc1      $a3, $f22
/* 1CC48 80041848 3C0141A0 */  lui       $at, 0x41a0
/* 1CC4C 8004184C 44810000 */  mtc1      $at, $f0
/* 1CC50 80041850 27A20020 */  addiu     $v0, $sp, 0x20
/* 1CC54 80041854 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CC58 80041858 4600C600 */  add.s     $f24, $f24, $f0
/* 1CC5C 8004185C 27A20024 */  addiu     $v0, $sp, 0x24
/* 1CC60 80041860 AFA20014 */  sw        $v0, 0x14($sp)
/* 1CC64 80041864 4406C000 */  mfc1      $a2, $f24
/* 1CC68 80041868 27A20028 */  addiu     $v0, $sp, 0x28
/* 1CC6C 8004186C 0C00B872 */  jal       func_8002E1C8
/* 1CC70 80041870 AFA20018 */   sw       $v0, 0x18($sp)
/* 1CC74 80041874 8E040000 */  lw        $a0, ($s0)
/* 1CC78 80041878 4405F000 */  mfc1      $a1, $f30
/* 1CC7C 8004187C 4407E000 */  mfc1      $a3, $f28
/* 1CC80 80041880 3C014170 */  lui       $at, 0x4170
/* 1CC84 80041884 44810000 */  mtc1      $at, $f0
/* 1CC88 80041888 27A2002C */  addiu     $v0, $sp, 0x2c
/* 1CC8C 8004188C AFA20010 */  sw        $v0, 0x10($sp)
/* 1CC90 80041890 4600D680 */  add.s     $f26, $f26, $f0
/* 1CC94 80041894 27A20030 */  addiu     $v0, $sp, 0x30
/* 1CC98 80041898 AFA20014 */  sw        $v0, 0x14($sp)
/* 1CC9C 8004189C 4406D000 */  mfc1      $a2, $f26
/* 1CCA0 800418A0 27A20034 */  addiu     $v0, $sp, 0x34
/* 1CCA4 800418A4 0C00B872 */  jal       func_8002E1C8
/* 1CCA8 800418A8 AFA20018 */   sw       $v0, 0x18($sp)
/* 1CCAC 800418AC 0000202D */  daddu     $a0, $zero, $zero
/* 1CCB0 800418B0 0080282D */  daddu     $a1, $a0, $zero
/* 1CCB4 800418B4 8FA60020 */  lw        $a2, 0x20($sp)
/* 1CCB8 800418B8 8FA8002C */  lw        $t0, 0x2c($sp)
/* 1CCBC 800418BC 8FA70024 */  lw        $a3, 0x24($sp)
/* 1CCC0 800418C0 8FA30030 */  lw        $v1, 0x30($sp)
/* 1CCC4 800418C4 00C83023 */  subu      $a2, $a2, $t0
/* 1CCC8 800418C8 000617C2 */  srl       $v0, $a2, 0x1f
/* 1CCCC 800418CC 00C23021 */  addu      $a2, $a2, $v0
/* 1CCD0 800418D0 00063043 */  sra       $a2, $a2, 1
/* 1CCD4 800418D4 00C83021 */  addu      $a2, $a2, $t0
/* 1CCD8 800418D8 00E33823 */  subu      $a3, $a3, $v1
/* 1CCDC 800418DC 000717C2 */  srl       $v0, $a3, 0x1f
/* 1CCE0 800418E0 00E23821 */  addu      $a3, $a3, $v0
/* 1CCE4 800418E4 00073843 */  sra       $a3, $a3, 1
.L800418E8:
/* 1CCE8 800418E8 0C04F3BF */  jal       func_8013CEFC
/* 1CCEC 800418EC 00E33821 */   addu     $a3, $a3, $v1
.L800418F0:
/* 1CCF0 800418F0 8FBF0040 */  lw        $ra, 0x40($sp)
/* 1CCF4 800418F4 8FB1003C */  lw        $s1, 0x3c($sp)
/* 1CCF8 800418F8 8FB00038 */  lw        $s0, 0x38($sp)
/* 1CCFC 800418FC D7BE0070 */  ldc1      $f30, 0x70($sp)
/* 1CD00 80041900 D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 1CD04 80041904 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 1CD08 80041908 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 1CD0C 8004190C D7B60050 */  ldc1      $f22, 0x50($sp)
/* 1CD10 80041910 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 1CD14 80041914 03E00008 */  jr        $ra
/* 1CD18 80041918 27BD0078 */   addiu    $sp, $sp, 0x78
