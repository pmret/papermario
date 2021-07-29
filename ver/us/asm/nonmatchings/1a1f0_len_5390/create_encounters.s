.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_encounters
/* 1EAB0 800436B0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 1EAB4 800436B4 AFBE0058 */  sw        $fp, 0x58($sp)
/* 1EAB8 800436B8 27BE0010 */  addiu     $fp, $sp, 0x10
/* 1EABC 800436BC 3C07800B */  lui       $a3, %hi(gCurrentEncounter+0x24)
/* 1EAC0 800436C0 8CE70F34 */  lw        $a3, %lo(gCurrentEncounter+0x24)($a3)
/* 1EAC4 800436C4 3C03800A */  lui       $v1, %hi(D_8009A5D0)
/* 1EAC8 800436C8 8C63A5D0 */  lw        $v1, %lo(D_8009A5D0)($v1)
/* 1EACC 800436CC 3C08800B */  lui       $t0, %hi(gCurrentEncounter+0x20)
/* 1EAD0 800436D0 81080F30 */  lb        $t0, %lo(gCurrentEncounter+0x20)($t0)
/* 1EAD4 800436D4 24040001 */  addiu     $a0, $zero, 1
/* 1EAD8 800436D8 AFBF005C */  sw        $ra, 0x5c($sp)
/* 1EADC 800436DC AFB70054 */  sw        $s7, 0x54($sp)
/* 1EAE0 800436E0 AFB60050 */  sw        $s6, 0x50($sp)
/* 1EAE4 800436E4 AFB5004C */  sw        $s5, 0x4c($sp)
/* 1EAE8 800436E8 AFB40048 */  sw        $s4, 0x48($sp)
/* 1EAEC 800436EC AFB30044 */  sw        $s3, 0x44($sp)
/* 1EAF0 800436F0 AFB20040 */  sw        $s2, 0x40($sp)
/* 1EAF4 800436F4 AFB1003C */  sw        $s1, 0x3c($sp)
/* 1EAF8 800436F8 AFB00038 */  sw        $s0, 0x38($sp)
/* 1EAFC 800436FC AFA70020 */  sw        $a3, 0x20($sp)
/* 1EB00 80043700 106401A5 */  beq       $v1, $a0, .L80043D98
/* 1EB04 80043704 AFA80028 */   sw       $t0, 0x28($sp)
/* 1EB08 80043708 28620002 */  slti      $v0, $v1, 2
/* 1EB0C 8004370C 50400005 */  beql      $v0, $zero, .L80043724
/* 1EB10 80043710 24020002 */   addiu    $v0, $zero, 2
/* 1EB14 80043714 10600007 */  beqz      $v1, .L80043734
/* 1EB18 80043718 00000000 */   nop
/* 1EB1C 8004371C 08011044 */  j         .L80044110
/* 1EB20 80043720 00000000 */   nop
.L80043724:
/* 1EB24 80043724 106201EF */  beq       $v1, $v0, .L80043EE4
/* 1EB28 80043728 0000A82D */   daddu    $s5, $zero, $zero
/* 1EB2C 8004372C 08011044 */  j         .L80044110
/* 1EB30 80043730 00000000 */   nop
.L80043734:
/* 1EB34 80043734 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x21)
/* 1EB38 80043738 80420F31 */  lb        $v0, %lo(gCurrentEncounter+0x21)($v0)
/* 1EB3C 8004373C 1044002A */  beq       $v0, $a0, .L800437E8
/* 1EB40 80043740 00000000 */   nop
/* 1EB44 80043744 0000982D */  daddu     $s3, $zero, $zero
/* 1EB48 80043748 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 1EB4C 8004374C 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
.L80043750:
/* 1EB50 80043750 84620BF0 */  lh        $v0, 0xbf0($v1)
/* 1EB54 80043754 8FA70028 */  lw        $a3, 0x28($sp)
/* 1EB58 80043758 10470006 */  beq       $v0, $a3, .L80043774
/* 1EB5C 8004375C 2A620002 */   slti     $v0, $s3, 2
/* 1EB60 80043760 26730001 */  addiu     $s3, $s3, 1
/* 1EB64 80043764 2A620002 */  slti      $v0, $s3, 2
/* 1EB68 80043768 1440FFF9 */  bnez      $v0, .L80043750
/* 1EB6C 8004376C 24630002 */   addiu    $v1, $v1, 2
/* 1EB70 80043770 2A620002 */  slti      $v0, $s3, 2
.L80043774:
/* 1EB74 80043774 1440000F */  bnez      $v0, .L800437B4
/* 1EB78 80043778 0000982D */   daddu    $s3, $zero, $zero
/* 1EB7C 8004377C 8FA80028 */  lw        $t0, 0x28($sp)
/* 1EB80 80043780 0000182D */  daddu     $v1, $zero, $zero
/* 1EB84 80043784 00081040 */  sll       $v0, $t0, 1
/* 1EB88 80043788 00481021 */  addu      $v0, $v0, $t0
/* 1EB8C 8004378C 00022100 */  sll       $a0, $v0, 4
/* 1EB90 80043790 3C07800B */  lui       $a3, %hi(gCurrentEncounter)
/* 1EB94 80043794 24E70F10 */  addiu     $a3, $a3, %lo(gCurrentEncounter)
.L80043798:
/* 1EB98 80043798 00E41021 */  addu      $v0, $a3, $a0
/* 1EB9C 8004379C AC4000B0 */  sw        $zero, 0xb0($v0)
/* 1EBA0 800437A0 24630001 */  addiu     $v1, $v1, 1
/* 1EBA4 800437A4 2862000C */  slti      $v0, $v1, 0xc
/* 1EBA8 800437A8 1440FFFB */  bnez      $v0, .L80043798
/* 1EBAC 800437AC 24840004 */   addiu    $a0, $a0, 4
/* 1EBB0 800437B0 0000982D */  daddu     $s3, $zero, $zero
.L800437B4:
/* 1EBB4 800437B4 00131840 */  sll       $v1, $s3, 1
/* 1EBB8 800437B8 26620001 */  addiu     $v0, $s3, 1
/* 1EBBC 800437BC 0040982D */  daddu     $s3, $v0, $zero
/* 1EBC0 800437C0 00131040 */  sll       $v0, $s3, 1
/* 1EBC4 800437C4 3C08800B */  lui       $t0, %hi(gCurrentEncounter)
/* 1EBC8 800437C8 25080F10 */  addiu     $t0, $t0, %lo(gCurrentEncounter)
/* 1EBCC 800437CC 01022021 */  addu      $a0, $t0, $v0
/* 1EBD0 800437D0 94820BF0 */  lhu       $v0, 0xbf0($a0)
/* 1EBD4 800437D4 01031821 */  addu      $v1, $t0, $v1
/* 1EBD8 800437D8 1A60FFF6 */  blez      $s3, .L800437B4
/* 1EBDC 800437DC A4620BF0 */   sh       $v0, 0xbf0($v1)
/* 1EBE0 800437E0 97A7002A */  lhu       $a3, 0x2a($sp)
/* 1EBE4 800437E4 A4870BF0 */  sh        $a3, 0xbf0($a0)
.L800437E8:
/* 1EBE8 800437E8 8FA80020 */  lw        $t0, 0x20($sp)
/* 1EBEC 800437EC 0000B02D */  daddu     $s6, $zero, $zero
/* 1EBF0 800437F0 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1EBF4 800437F4 2508000A */  addiu     $t0, $t0, 0xa
/* 1EBF8 800437F8 AFA80034 */  sw        $t0, 0x34($sp)
.L800437FC:
/* 1EBFC 800437FC 8FA70020 */  lw        $a3, 0x20($sp)
/* 1EC00 80043800 8CE20000 */  lw        $v0, ($a3)
/* 1EC04 80043804 1040015D */  beqz      $v0, .L80043D7C
/* 1EC08 80043808 2404004C */   addiu    $a0, $zero, 0x4c
/* 1EC0C 8004380C 8FA80034 */  lw        $t0, 0x34($sp)
/* 1EC10 80043810 8D17FFFA */  lw        $s7, -6($t0)
/* 1EC14 80043814 0C00AB39 */  jal       heap_malloc
/* 1EC18 80043818 AFA20024 */   sw       $v0, 0x24($sp)
/* 1EC1C 8004381C 0040A02D */  daddu     $s4, $v0, $zero
/* 1EC20 80043820 00161080 */  sll       $v0, $s6, 2
/* 1EC24 80043824 3C07800B */  lui       $a3, %hi(gCurrentEncounter)
/* 1EC28 80043828 24E70F10 */  addiu     $a3, $a3, %lo(gCurrentEncounter)
/* 1EC2C 8004382C 00E21021 */  addu      $v0, $a3, $v0
/* 1EC30 80043830 16800003 */  bnez      $s4, .L80043840
/* 1EC34 80043834 AC540028 */   sw       $s4, 0x28($v0)
.L80043838:
/* 1EC38 80043838 08010E0E */  j         .L80043838
/* 1EC3C 8004383C 00000000 */   nop
.L80043840:
/* 1EC40 80043840 8FA80024 */  lw        $t0, 0x24($sp)
/* 1EC44 80043844 AE880000 */  sw        $t0, ($s4)
/* 1EC48 80043848 8FA70034 */  lw        $a3, 0x34($sp)
/* 1EC4C 8004384C 94E2FFFE */  lhu       $v0, -2($a3)
/* 1EC50 80043850 A6820044 */  sh        $v0, 0x44($s4)
/* 1EC54 80043854 94E20000 */  lhu       $v0, ($a3)
/* 1EC58 80043858 97A8002E */  lhu       $t0, 0x2e($sp)
/* 1EC5C 8004385C 2442FFFF */  addiu     $v0, $v0, -1
/* 1EC60 80043860 A6880048 */  sh        $t0, 0x48($s4)
/* 1EC64 80043864 A6820046 */  sh        $v0, 0x46($s4)
/* 1EC68 80043868 8FA70024 */  lw        $a3, 0x24($sp)
/* 1EC6C 8004386C 18E00137 */  blez      $a3, .L80043D4C
/* 1EC70 80043870 0000982D */   daddu    $s3, $zero, $zero
/* 1EC74 80043874 AFB40030 */  sw        $s4, 0x30($sp)
/* 1EC78 80043878 26F20024 */  addiu     $s2, $s7, 0x24
.L8004387C:
/* 1EC7C 8004387C 86850048 */  lh        $a1, 0x48($s4)
/* 1EC80 80043880 8FA40028 */  lw        $a0, 0x28($sp)
/* 1EC84 80043884 0C00FB7C */  jal       get_defeated
/* 1EC88 80043888 00B32821 */   addu     $a1, $a1, $s3
/* 1EC8C 8004388C 10400006 */  beqz      $v0, .L800438A8
/* 1EC90 80043890 00000000 */   nop
/* 1EC94 80043894 265201F0 */  addiu     $s2, $s2, 0x1f0
/* 1EC98 80043898 8FA80030 */  lw        $t0, 0x30($sp)
/* 1EC9C 8004389C 26F701F0 */  addiu     $s7, $s7, 0x1f0
/* 1ECA0 800438A0 08010F4C */  j         .L80043D30
/* 1ECA4 800438A4 AD000004 */   sw       $zero, 4($t0)
.L800438A8:
/* 1ECA8 800438A8 0C00AB39 */  jal       heap_malloc
/* 1ECAC 800438AC 240400E8 */   addiu    $a0, $zero, 0xe8
/* 1ECB0 800438B0 8FA70030 */  lw        $a3, 0x30($sp)
/* 1ECB4 800438B4 0040802D */  daddu     $s0, $v0, $zero
/* 1ECB8 800438B8 16000003 */  bnez      $s0, .L800438C8
/* 1ECBC 800438BC ACE20004 */   sw       $v0, 4($a3)
.L800438C0:
/* 1ECC0 800438C0 08010E30 */  j         .L800438C0
/* 1ECC4 800438C4 00000000 */   nop
.L800438C8:
/* 1ECC8 800438C8 2403000F */  addiu     $v1, $zero, 0xf
/* 1ECCC 800438CC 2602003C */  addiu     $v0, $s0, 0x3c
.L800438D0:
/* 1ECD0 800438D0 AC40006C */  sw        $zero, 0x6c($v0)
/* 1ECD4 800438D4 2463FFFF */  addiu     $v1, $v1, -1
/* 1ECD8 800438D8 0461FFFD */  bgez      $v1, .L800438D0
/* 1ECDC 800438DC 2442FFFC */   addiu    $v0, $v0, -4
/* 1ECE0 800438E0 A2160004 */  sb        $s6, 4($s0)
/* 1ECE4 800438E4 9642FFDE */  lhu       $v0, -0x22($s2)
/* 1ECE8 800438E8 A6020008 */  sh        $v0, 8($s0)
/* 1ECEC 800438EC 8E44FFE0 */  lw        $a0, -0x20($s2)
/* 1ECF0 800438F0 26E20028 */  addiu     $v0, $s7, 0x28
/* 1ECF4 800438F4 AE0200D4 */  sw        $v0, 0xd4($s0)
/* 1ECF8 800438F8 34028000 */  ori       $v0, $zero, 0x8000
/* 1ECFC 800438FC AE040018 */  sw        $a0, 0x18($s0)
/* 1ED00 80043900 86430004 */  lh        $v1, 4($s2)
/* 1ED04 80043904 3063FF00 */  andi      $v1, $v1, 0xff00
/* 1ED08 80043908 10620004 */  beq       $v1, $v0, .L8004391C
/* 1ED0C 8004390C 0080A82D */   daddu    $s5, $a0, $zero
/* 1ED10 80043910 3C028007 */  lui       $v0, %hi(D_80077EB8)
/* 1ED14 80043914 24427EB8 */  addiu     $v0, $v0, %lo(D_80077EB8)
/* 1ED18 80043918 AE0200D4 */  sw        $v0, 0xd4($s0)
.L8004391C:
/* 1ED1C 8004391C 3C02EFE8 */  lui       $v0, 0xefe8
/* 1ED20 80043920 A2000005 */  sb        $zero, 5($s0)
/* 1ED24 80043924 8E43FFF4 */  lw        $v1, -0xc($s2)
/* 1ED28 80043928 34422080 */  ori       $v0, $v0, 0x2080
/* 1ED2C 8004392C 0062102A */  slt       $v0, $v1, $v0
/* 1ED30 80043930 50400002 */  beql      $v0, $zero, .L8004393C
/* 1ED34 80043934 AE00001C */   sw       $zero, 0x1c($s0)
/* 1ED38 80043938 AE03001C */  sw        $v1, 0x1c($s0)
.L8004393C:
/* 1ED3C 8004393C 8EA2000C */  lw        $v0, 0xc($s5)
/* 1ED40 80043940 AE020020 */  sw        $v0, 0x20($s0)
/* 1ED44 80043944 8EA20010 */  lw        $v0, 0x10($s5)
/* 1ED48 80043948 AE020024 */  sw        $v0, 0x24($s0)
/* 1ED4C 8004394C 8EA20014 */  lw        $v0, 0x14($s5)
/* 1ED50 80043950 AE020028 */  sw        $v0, 0x28($s0)
/* 1ED54 80043954 8EA20018 */  lw        $v0, 0x18($s5)
/* 1ED58 80043958 AE02002C */  sw        $v0, 0x2c($s0)
/* 1ED5C 8004395C 8EA2001C */  lw        $v0, 0x1c($s5)
/* 1ED60 80043960 AE000034 */  sw        $zero, 0x34($s0)
/* 1ED64 80043964 AE000038 */  sw        $zero, 0x38($s0)
/* 1ED68 80043968 AE00003C */  sw        $zero, 0x3c($s0)
/* 1ED6C 8004396C AE000040 */  sw        $zero, 0x40($s0)
/* 1ED70 80043970 AE000044 */  sw        $zero, 0x44($s0)
/* 1ED74 80043974 AE000048 */  sw        $zero, 0x48($s0)
/* 1ED78 80043978 AE000050 */  sw        $zero, 0x50($s0)
/* 1ED7C 8004397C AE000054 */  sw        $zero, 0x54($s0)
/* 1ED80 80043980 AE000058 */  sw        $zero, 0x58($s0)
/* 1ED84 80043984 AE00005C */  sw        $zero, 0x5c($s0)
/* 1ED88 80043988 AE000060 */  sw        $zero, 0x60($s0)
/* 1ED8C 8004398C A2000007 */  sb        $zero, 7($s0)
/* 1ED90 80043990 A20000B5 */  sb        $zero, 0xb5($s0)
/* 1ED94 80043994 AE020030 */  sw        $v0, 0x30($s0)
/* 1ED98 80043998 924201BF */  lbu       $v0, 0x1bf($s2)
/* 1ED9C 8004399C A20200AC */  sb        $v0, 0xac($s0)
/* 1EDA0 800439A0 8E4201C0 */  lw        $v0, 0x1c0($s2)
/* 1EDA4 800439A4 AE0000DC */  sw        $zero, 0xdc($s0)
/* 1EDA8 800439A8 A20000B4 */  sb        $zero, 0xb4($s0)
/* 1EDAC 800439AC AE0200B0 */  sw        $v0, 0xb0($s0)
/* 1EDB0 800439B0 8EA20024 */  lw        $v0, 0x24($s5)
/* 1EDB4 800439B4 AE0000BC */  sw        $zero, 0xbc($s0)
/* 1EDB8 800439B8 AE0000C0 */  sw        $zero, 0xc0($s0)
/* 1EDBC 800439BC AE0200B8 */  sw        $v0, 0xb8($s0)
/* 1EDC0 800439C0 26E201A0 */  addiu     $v0, $s7, 0x1a0
/* 1EDC4 800439C4 AE0000C4 */  sw        $zero, 0xc4($s0)
/* 1EDC8 800439C8 AE0200CC */  sw        $v0, 0xcc($s0)
/* 1EDCC 800439CC 26E200E0 */  addiu     $v0, $s7, 0xe0
/* 1EDD0 800439D0 AE0200D0 */  sw        $v0, 0xd0($s0)
/* 1EDD4 800439D4 8EA20020 */  lw        $v0, 0x20($s5)
/* 1EDD8 800439D8 AE020000 */  sw        $v0, ($s0)
/* 1EDDC 800439DC 8E43FFF0 */  lw        $v1, -0x10($s2)
/* 1EDE0 800439E0 AE000064 */  sw        $zero, 0x64($s0)
/* 1EDE4 800439E4 00431025 */  or        $v0, $v0, $v1
/* 1EDE8 800439E8 AE020000 */  sw        $v0, ($s0)
/* 1EDEC 800439EC 8E4201C8 */  lw        $v0, 0x1c8($s2)
/* 1EDF0 800439F0 AE0200D8 */  sw        $v0, 0xd8($s0)
/* 1EDF4 800439F4 8E44FFF8 */  lw        $a0, -8($s2)
/* 1EDF8 800439F8 10800012 */  beqz      $a0, .L80043A44
/* 1EDFC 800439FC 24020001 */   addiu    $v0, $zero, 1
/* 1EE00 80043A00 14820004 */  bne       $a0, $v0, .L80043A14
/* 1EE04 80043A04 00000000 */   nop
/* 1EE08 80043A08 8E42FFFC */  lw        $v0, -4($s2)
/* 1EE0C 80043A0C 08010E91 */  j         .L80043A44
/* 1EE10 80043A10 AE02006C */   sw       $v0, 0x6c($s0)
.L80043A14:
/* 1EE14 80043A14 8E45FFFC */  lw        $a1, -4($s2)
/* 1EE18 80043A18 1880000A */  blez      $a0, .L80043A44
/* 1EE1C 80043A1C 0000182D */   daddu    $v1, $zero, $zero
/* 1EE20 80043A20 0200202D */  daddu     $a0, $s0, $zero
.L80043A24:
/* 1EE24 80043A24 8CA20000 */  lw        $v0, ($a1)
/* 1EE28 80043A28 24A50004 */  addiu     $a1, $a1, 4
/* 1EE2C 80043A2C 24630001 */  addiu     $v1, $v1, 1
/* 1EE30 80043A30 AC82006C */  sw        $v0, 0x6c($a0)
/* 1EE34 80043A34 8E42FFF8 */  lw        $v0, -8($s2)
/* 1EE38 80043A38 0062102A */  slt       $v0, $v1, $v0
/* 1EE3C 80043A3C 1440FFF9 */  bnez      $v0, .L80043A24
/* 1EE40 80043A40 24840004 */   addiu    $a0, $a0, 4
.L80043A44:
/* 1EE44 80043A44 AFC00000 */  sw        $zero, ($fp)
/* 1EE48 80043A48 8EA20000 */  lw        $v0, ($s5)
/* 1EE4C 80043A4C 54400004 */  bnel      $v0, $zero, .L80043A60
/* 1EE50 80043A50 AFC20004 */   sw       $v0, 4($fp)
/* 1EE54 80043A54 8E0200CC */  lw        $v0, 0xcc($s0)
/* 1EE58 80043A58 8C420000 */  lw        $v0, ($v0)
/* 1EE5C 80043A5C AFC20004 */  sw        $v0, 4($fp)
.L80043A60:
/* 1EE60 80043A60 AFC00008 */  sw        $zero, 8($fp)
/* 1EE64 80043A64 AFC0000C */  sw        $zero, 0xc($fp)
/* 1EE68 80043A68 8E020000 */  lw        $v0, ($s0)
/* 1EE6C 80043A6C 3C030002 */  lui       $v1, 2
/* 1EE70 80043A70 00431024 */  and       $v0, $v0, $v1
/* 1EE74 80043A74 14400006 */  bnez      $v0, .L80043A90
/* 1EE78 80043A78 00000000 */   nop
/* 1EE7C 80043A7C 8E4501C4 */  lw        $a1, 0x1c4($s2)
/* 1EE80 80043A80 0C00E219 */  jal       _create_npc_standard
/* 1EE84 80043A84 03C0202D */   daddu    $a0, $fp, $zero
/* 1EE88 80043A88 08010EA6 */  j         .L80043A98
/* 1EE8C 80043A8C 00000000 */   nop
.L80043A90:
/* 1EE90 80043A90 0C00E220 */  jal       _create_npc_partner
/* 1EE94 80043A94 03C0202D */   daddu    $a0, $fp, $zero
.L80043A98:
/* 1EE98 80043A98 0C00E2B7 */  jal       get_npc_by_index
/* 1EE9C 80043A9C 0040202D */   daddu    $a0, $v0, $zero
/* 1EEA0 80043AA0 9243FFDF */  lbu       $v1, -0x21($s2)
/* 1EEA4 80043AA4 0040882D */  daddu     $s1, $v0, $zero
/* 1EEA8 80043AA8 A22300A4 */  sb        $v1, 0xa4($s1)
/* 1EEAC 80043AAC 96A20006 */  lhu       $v0, 6($s5)
/* 1EEB0 80043AB0 A62200A6 */  sh        $v0, 0xa6($s1)
/* 1EEB4 80043AB4 96A20004 */  lhu       $v0, 4($s5)
/* 1EEB8 80043AB8 A62200A8 */  sh        $v0, 0xa8($s1)
/* 1EEBC 80043ABC C640FFE4 */  lwc1      $f0, -0x1c($s2)
/* 1EEC0 80043AC0 4600010D */  trunc.w.s $f4, $f0
/* 1EEC4 80043AC4 44022000 */  mfc1      $v0, $f4
/* 1EEC8 80043AC8 E6200038 */  swc1      $f0, 0x38($s1)
/* 1EECC 80043ACC A602000A */  sh        $v0, 0xa($s0)
/* 1EED0 80043AD0 C640FFE8 */  lwc1      $f0, -0x18($s2)
/* 1EED4 80043AD4 4600010D */  trunc.w.s $f4, $f0
/* 1EED8 80043AD8 44022000 */  mfc1      $v0, $f4
/* 1EEDC 80043ADC E620003C */  swc1      $f0, 0x3c($s1)
/* 1EEE0 80043AE0 A602000C */  sh        $v0, 0xc($s0)
/* 1EEE4 80043AE4 C640FFEC */  lwc1      $f0, -0x14($s2)
/* 1EEE8 80043AE8 4600010D */  trunc.w.s $f4, $f0
/* 1EEEC 80043AEC 44022000 */  mfc1      $v0, $f4
/* 1EEF0 80043AF0 E6200040 */  swc1      $f0, 0x40($s1)
/* 1EEF4 80043AF4 A602000E */  sh        $v0, 0xe($s0)
/* 1EEF8 80043AF8 C6200038 */  lwc1      $f0, 0x38($s1)
/* 1EEFC 80043AFC C6220040 */  lwc1      $f2, 0x40($s1)
/* 1EF00 80043B00 4600010D */  trunc.w.s $f4, $f0
/* 1EF04 80043B04 44022000 */  mfc1      $v0, $f4
/* 1EF08 80043B08 C620003C */  lwc1      $f0, 0x3c($s1)
/* 1EF0C 80043B0C A6200096 */  sh        $zero, 0x96($s1)
/* 1EF10 80043B10 AE200010 */  sw        $zero, 0x10($s1)
/* 1EF14 80043B14 A6220090 */  sh        $v0, 0x90($s1)
/* 1EF18 80043B18 4600010D */  trunc.w.s $f4, $f0
/* 1EF1C 80043B1C 44022000 */  mfc1      $v0, $f4
/* 1EF20 80043B20 00000000 */  nop
/* 1EF24 80043B24 A6220092 */  sh        $v0, 0x92($s1)
/* 1EF28 80043B28 4600110D */  trunc.w.s $f4, $f2
/* 1EF2C 80043B2C 44022000 */  mfc1      $v0, $f4
/* 1EF30 80043B30 00000000 */  nop
/* 1EF34 80043B34 A6220094 */  sh        $v0, 0x94($s1)
/* 1EF38 80043B38 C6440000 */  lwc1      $f4, ($s2)
/* 1EF3C 80043B3C 46802120 */  cvt.s.w   $f4, $f4
/* 1EF40 80043B40 44052000 */  mfc1      $a1, $f4
/* 1EF44 80043B44 0C00ECD0 */  jal       set_npc_yaw
/* 1EF48 80043B48 0220202D */   daddu    $a0, $s1, $zero
/* 1EF4C 80043B4C 24023039 */  addiu     $v0, $zero, 0x3039
/* 1EF50 80043B50 A60200E0 */  sh        $v0, 0xe0($s0)
/* 1EF54 80043B54 862200A6 */  lh        $v0, 0xa6($s1)
/* 1EF58 80043B58 3C014038 */  lui       $at, 0x4038
/* 1EF5C 80043B5C 44811800 */  mtc1      $at, $f3
/* 1EF60 80043B60 44801000 */  mtc1      $zero, $f2
/* 1EF64 80043B64 44820000 */  mtc1      $v0, $f0
/* 1EF68 80043B68 00000000 */  nop
/* 1EF6C 80043B6C 46800021 */  cvt.d.w   $f0, $f0
/* 1EF70 80043B70 4620103E */  c.le.d    $f2, $f0
/* 1EF74 80043B74 00000000 */  nop
/* 1EF78 80043B78 45000004 */  bc1f      .L80043B8C
/* 1EF7C 80043B7C 00000000 */   nop
/* 1EF80 80043B80 46220003 */  div.d     $f0, $f0, $f2
/* 1EF84 80043B84 08010EE6 */  j         .L80043B98
/* 1EF88 80043B88 46200020 */   cvt.s.d  $f0, $f0
.L80043B8C:
/* 1EF8C 80043B8C 3C013F80 */  lui       $at, 0x3f80
/* 1EF90 80043B90 44810000 */  mtc1      $at, $f0
/* 1EF94 80043B94 00000000 */  nop
.L80043B98:
/* 1EF98 80043B98 E620007C */  swc1      $f0, 0x7c($s1)
/* 1EF9C 80043B9C 8E020000 */  lw        $v0, ($s0)
/* 1EFA0 80043BA0 30420100 */  andi      $v0, $v0, 0x100
/* 1EFA4 80043BA4 10400004 */  beqz      $v0, .L80043BB8
/* 1EFA8 80043BA8 00000000 */   nop
/* 1EFAC 80043BAC 8E220000 */  lw        $v0, ($s1)
/* 1EFB0 80043BB0 34420040 */  ori       $v0, $v0, 0x40
/* 1EFB4 80043BB4 AE220000 */  sw        $v0, ($s1)
.L80043BB8:
/* 1EFB8 80043BB8 8E020000 */  lw        $v0, ($s0)
/* 1EFBC 80043BBC 30420200 */  andi      $v0, $v0, 0x200
/* 1EFC0 80043BC0 10400004 */  beqz      $v0, .L80043BD4
/* 1EFC4 80043BC4 00000000 */   nop
/* 1EFC8 80043BC8 8E220000 */  lw        $v0, ($s1)
/* 1EFCC 80043BCC 34420100 */  ori       $v0, $v0, 0x100
/* 1EFD0 80043BD0 AE220000 */  sw        $v0, ($s1)
.L80043BD4:
/* 1EFD4 80043BD4 8E020000 */  lw        $v0, ($s0)
/* 1EFD8 80043BD8 30420400 */  andi      $v0, $v0, 0x400
/* 1EFDC 80043BDC 10400004 */  beqz      $v0, .L80043BF0
/* 1EFE0 80043BE0 00000000 */   nop
/* 1EFE4 80043BE4 8E220000 */  lw        $v0, ($s1)
/* 1EFE8 80043BE8 34428000 */  ori       $v0, $v0, 0x8000
/* 1EFEC 80043BEC AE220000 */  sw        $v0, ($s1)
.L80043BF0:
/* 1EFF0 80043BF0 8E020000 */  lw        $v0, ($s0)
/* 1EFF4 80043BF4 30420800 */  andi      $v0, $v0, 0x800
/* 1EFF8 80043BF8 10400004 */  beqz      $v0, .L80043C0C
/* 1EFFC 80043BFC 00000000 */   nop
/* 1F000 80043C00 8E220000 */  lw        $v0, ($s1)
/* 1F004 80043C04 34420008 */  ori       $v0, $v0, 8
/* 1F008 80043C08 AE220000 */  sw        $v0, ($s1)
.L80043C0C:
/* 1F00C 80043C0C 8E020000 */  lw        $v0, ($s0)
/* 1F010 80043C10 30421000 */  andi      $v0, $v0, 0x1000
/* 1F014 80043C14 10400004 */  beqz      $v0, .L80043C28
/* 1F018 80043C18 00000000 */   nop
/* 1F01C 80043C1C 8E220000 */  lw        $v0, ($s1)
/* 1F020 80043C20 34420200 */  ori       $v0, $v0, 0x200
/* 1F024 80043C24 AE220000 */  sw        $v0, ($s1)
.L80043C28:
/* 1F028 80043C28 8E020000 */  lw        $v0, ($s0)
/* 1F02C 80043C2C 30420001 */  andi      $v0, $v0, 1
/* 1F030 80043C30 14400004 */  bnez      $v0, .L80043C44
/* 1F034 80043C34 00000000 */   nop
/* 1F038 80043C38 8E220000 */  lw        $v0, ($s1)
/* 1F03C 80043C3C 34420100 */  ori       $v0, $v0, 0x100
/* 1F040 80043C40 AE220000 */  sw        $v0, ($s1)
.L80043C44:
/* 1F044 80043C44 8E020000 */  lw        $v0, ($s0)
/* 1F048 80043C48 30424000 */  andi      $v0, $v0, 0x4000
/* 1F04C 80043C4C 10400004 */  beqz      $v0, .L80043C60
/* 1F050 80043C50 3C030100 */   lui      $v1, 0x100
/* 1F054 80043C54 8E220000 */  lw        $v0, ($s1)
/* 1F058 80043C58 00431025 */  or        $v0, $v0, $v1
/* 1F05C 80043C5C AE220000 */  sw        $v0, ($s1)
.L80043C60:
/* 1F060 80043C60 8E020000 */  lw        $v0, ($s0)
/* 1F064 80043C64 30422000 */  andi      $v0, $v0, 0x2000
/* 1F068 80043C68 10400004 */  beqz      $v0, .L80043C7C
/* 1F06C 80043C6C 00000000 */   nop
/* 1F070 80043C70 8E220000 */  lw        $v0, ($s1)
/* 1F074 80043C74 34420020 */  ori       $v0, $v0, 0x20
/* 1F078 80043C78 AE220000 */  sw        $v0, ($s1)
.L80043C7C:
/* 1F07C 80043C7C 8E020000 */  lw        $v0, ($s0)
/* 1F080 80043C80 30428000 */  andi      $v0, $v0, 0x8000
/* 1F084 80043C84 10400004 */  beqz      $v0, .L80043C98
/* 1F088 80043C88 3C031000 */   lui      $v1, 0x1000
/* 1F08C 80043C8C 8E220000 */  lw        $v0, ($s1)
/* 1F090 80043C90 00431025 */  or        $v0, $v0, $v1
/* 1F094 80043C94 AE220000 */  sw        $v0, ($s1)
.L80043C98:
/* 1F098 80043C98 8E020000 */  lw        $v0, ($s0)
/* 1F09C 80043C9C 3C030001 */  lui       $v1, 1
/* 1F0A0 80043CA0 00431024 */  and       $v0, $v0, $v1
/* 1F0A4 80043CA4 10400004 */  beqz      $v0, .L80043CB8
/* 1F0A8 80043CA8 3C032000 */   lui      $v1, 0x2000
/* 1F0AC 80043CAC 8E220000 */  lw        $v0, ($s1)
/* 1F0B0 80043CB0 00431025 */  or        $v0, $v0, $v1
/* 1F0B4 80043CB4 AE220000 */  sw        $v0, ($s1)
.L80043CB8:
/* 1F0B8 80043CB8 8E020000 */  lw        $v0, ($s0)
/* 1F0BC 80043CBC 30420080 */  andi      $v0, $v0, 0x80
/* 1F0C0 80043CC0 10400004 */  beqz      $v0, .L80043CD4
/* 1F0C4 80043CC4 00000000 */   nop
/* 1F0C8 80043CC8 8E220000 */  lw        $v0, ($s1)
/* 1F0CC 80043CCC 34420400 */  ori       $v0, $v0, 0x400
/* 1F0D0 80043CD0 AE220000 */  sw        $v0, ($s1)
.L80043CD4:
/* 1F0D4 80043CD4 8E030000 */  lw        $v1, ($s0)
/* 1F0D8 80043CD8 2402000B */  addiu     $v0, $zero, 0xb
/* 1F0DC 80043CDC 30630001 */  andi      $v1, $v1, 1
/* 1F0E0 80043CE0 10600003 */  beqz      $v1, .L80043CF0
/* 1F0E4 80043CE4 A2020006 */   sb       $v0, 6($s0)
/* 1F0E8 80043CE8 2402000A */  addiu     $v0, $zero, 0xa
/* 1F0EC 80043CEC A2020006 */  sb        $v0, 6($s0)
.L80043CF0:
/* 1F0F0 80043CF0 8EA40008 */  lw        $a0, 8($s5)
/* 1F0F4 80043CF4 1080000C */  beqz      $a0, .L80043D28
/* 1F0F8 80043CF8 2405000A */   addiu    $a1, $zero, 0xa
/* 1F0FC 80043CFC 0C0B0CF8 */  jal       start_script
/* 1F100 80043D00 0000302D */   daddu    $a2, $zero, $zero
/* 1F104 80043D04 0040182D */  daddu     $v1, $v0, $zero
/* 1F108 80043D08 AE03003C */  sw        $v1, 0x3c($s0)
/* 1F10C 80043D0C 8C620144 */  lw        $v0, 0x144($v1)
/* 1F110 80043D10 AE020054 */  sw        $v0, 0x54($s0)
/* 1F114 80043D14 AC700148 */  sw        $s0, 0x148($v1)
/* 1F118 80043D18 86020008 */  lh        $v0, 8($s0)
/* 1F11C 80043D1C AC62014C */  sw        $v0, 0x14c($v1)
/* 1F120 80043D20 92020006 */  lbu       $v0, 6($s0)
/* 1F124 80043D24 A0620004 */  sb        $v0, 4($v1)
.L80043D28:
/* 1F128 80043D28 265201F0 */  addiu     $s2, $s2, 0x1f0
/* 1F12C 80043D2C 26F701F0 */  addiu     $s7, $s7, 0x1f0
.L80043D30:
/* 1F130 80043D30 26730001 */  addiu     $s3, $s3, 1
/* 1F134 80043D34 8FA70030 */  lw        $a3, 0x30($sp)
/* 1F138 80043D38 8FA80024 */  lw        $t0, 0x24($sp)
/* 1F13C 80043D3C 24E70004 */  addiu     $a3, $a3, 4
/* 1F140 80043D40 0268102A */  slt       $v0, $s3, $t0
/* 1F144 80043D44 1440FECD */  bnez      $v0, .L8004387C
/* 1F148 80043D48 AFA70030 */   sw       $a3, 0x30($sp)
.L80043D4C:
/* 1F14C 80043D4C 8FA70034 */  lw        $a3, 0x34($sp)
/* 1F150 80043D50 8FA80020 */  lw        $t0, 0x20($sp)
/* 1F154 80043D54 24E7000C */  addiu     $a3, $a3, 0xc
/* 1F158 80043D58 AFA70034 */  sw        $a3, 0x34($sp)
/* 1F15C 80043D5C 8FA7002C */  lw        $a3, 0x2c($sp)
/* 1F160 80043D60 2508000C */  addiu     $t0, $t0, 0xc
/* 1F164 80043D64 AFA80020 */  sw        $t0, 0x20($sp)
/* 1F168 80043D68 8FA80024 */  lw        $t0, 0x24($sp)
/* 1F16C 80043D6C 26D60001 */  addiu     $s6, $s6, 1
/* 1F170 80043D70 00E83821 */  addu      $a3, $a3, $t0
/* 1F174 80043D74 08010DFF */  j         .L800437FC
/* 1F178 80043D78 AFA7002C */   sw       $a3, 0x2c($sp)
.L80043D7C:
/* 1F17C 80043D7C 24020001 */  addiu     $v0, $zero, 1
/* 1F180 80043D80 3C01800B */  lui       $at, %hi(gCurrentEncounter+0x1C)
/* 1F184 80043D84 A0360F2C */  sb        $s6, %lo(gCurrentEncounter+0x1C)($at)
/* 1F188 80043D88 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1F18C 80043D8C AC22A5D0 */  sw        $v0, %lo(D_8009A5D0)($at)
/* 1F190 80043D90 08011044 */  j         .L80044110
/* 1F194 80043D94 00000000 */   nop
.L80043D98:
/* 1F198 80043D98 0000A82D */  daddu     $s5, $zero, $zero
/* 1F19C 80043D9C 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F1A0 80043DA0 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F1A4 80043DA4 1840001F */  blez      $v0, .L80043E24
/* 1F1A8 80043DA8 02A0B02D */   daddu    $s6, $s5, $zero
/* 1F1AC 80043DAC 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 1F1B0 80043DB0 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
.L80043DB4:
/* 1F1B4 80043DB4 8E540028 */  lw        $s4, 0x28($s2)
/* 1F1B8 80043DB8 12800014 */  beqz      $s4, .L80043E0C
/* 1F1BC 80043DBC 00000000 */   nop
/* 1F1C0 80043DC0 8E820000 */  lw        $v0, ($s4)
/* 1F1C4 80043DC4 18400011 */  blez      $v0, .L80043E0C
/* 1F1C8 80043DC8 0000982D */   daddu    $s3, $zero, $zero
/* 1F1CC 80043DCC 0280882D */  daddu     $s1, $s4, $zero
.L80043DD0:
/* 1F1D0 80043DD0 8E300004 */  lw        $s0, 4($s1)
/* 1F1D4 80043DD4 12000008 */  beqz      $s0, .L80043DF8
/* 1F1D8 80043DD8 00000000 */   nop
/* 1F1DC 80043DDC 8E02003C */  lw        $v0, 0x3c($s0)
/* 1F1E0 80043DE0 10400005 */  beqz      $v0, .L80043DF8
/* 1F1E4 80043DE4 00000000 */   nop
/* 1F1E8 80043DE8 0C0B1059 */  jal       does_script_exist
/* 1F1EC 80043DEC 8E040054 */   lw       $a0, 0x54($s0)
/* 1F1F0 80043DF0 54400001 */  bnel      $v0, $zero, .L80043DF8
/* 1F1F4 80043DF4 24150001 */   addiu    $s5, $zero, 1
.L80043DF8:
/* 1F1F8 80043DF8 8E820000 */  lw        $v0, ($s4)
/* 1F1FC 80043DFC 26730001 */  addiu     $s3, $s3, 1
/* 1F200 80043E00 0262102A */  slt       $v0, $s3, $v0
/* 1F204 80043E04 1440FFF2 */  bnez      $v0, .L80043DD0
/* 1F208 80043E08 26310004 */   addiu    $s1, $s1, 4
.L80043E0C:
/* 1F20C 80043E0C 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F210 80043E10 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F214 80043E14 26D60001 */  addiu     $s6, $s6, 1
/* 1F218 80043E18 02C2102A */  slt       $v0, $s6, $v0
/* 1F21C 80043E1C 1440FFE5 */  bnez      $v0, .L80043DB4
/* 1F220 80043E20 26520004 */   addiu    $s2, $s2, 4
.L80043E24:
/* 1F224 80043E24 16A000BA */  bnez      $s5, .L80044110
/* 1F228 80043E28 00000000 */   nop
/* 1F22C 80043E2C 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F230 80043E30 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F234 80043E34 18400026 */  blez      $v0, .L80043ED0
/* 1F238 80043E38 0000B02D */   daddu    $s6, $zero, $zero
/* 1F23C 80043E3C 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 1F240 80043E40 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
.L80043E44:
/* 1F244 80043E44 8E540028 */  lw        $s4, 0x28($s2)
/* 1F248 80043E48 1280001B */  beqz      $s4, .L80043EB8
/* 1F24C 80043E4C 00000000 */   nop
/* 1F250 80043E50 8E820000 */  lw        $v0, ($s4)
/* 1F254 80043E54 18400018 */  blez      $v0, .L80043EB8
/* 1F258 80043E58 0000982D */   daddu    $s3, $zero, $zero
/* 1F25C 80043E5C 0280882D */  daddu     $s1, $s4, $zero
.L80043E60:
/* 1F260 80043E60 8E300004 */  lw        $s0, 4($s1)
/* 1F264 80043E64 1200000F */  beqz      $s0, .L80043EA4
/* 1F268 80043E68 00000000 */   nop
/* 1F26C 80043E6C 8E04001C */  lw        $a0, 0x1c($s0)
/* 1F270 80043E70 1080000C */  beqz      $a0, .L80043EA4
/* 1F274 80043E74 2405000A */   addiu    $a1, $zero, 0xa
/* 1F278 80043E78 0C0B0CF8 */  jal       start_script
/* 1F27C 80043E7C 0000302D */   daddu    $a2, $zero, $zero
/* 1F280 80043E80 0040182D */  daddu     $v1, $v0, $zero
/* 1F284 80043E84 AE030034 */  sw        $v1, 0x34($s0)
/* 1F288 80043E88 8C620144 */  lw        $v0, 0x144($v1)
/* 1F28C 80043E8C AE02004C */  sw        $v0, 0x4c($s0)
/* 1F290 80043E90 AC700148 */  sw        $s0, 0x148($v1)
/* 1F294 80043E94 86020008 */  lh        $v0, 8($s0)
/* 1F298 80043E98 AC62014C */  sw        $v0, 0x14c($v1)
/* 1F29C 80043E9C 92020006 */  lbu       $v0, 6($s0)
/* 1F2A0 80043EA0 A0620004 */  sb        $v0, 4($v1)
.L80043EA4:
/* 1F2A4 80043EA4 8E820000 */  lw        $v0, ($s4)
/* 1F2A8 80043EA8 26730001 */  addiu     $s3, $s3, 1
/* 1F2AC 80043EAC 0262102A */  slt       $v0, $s3, $v0
/* 1F2B0 80043EB0 1440FFEB */  bnez      $v0, .L80043E60
/* 1F2B4 80043EB4 26310004 */   addiu    $s1, $s1, 4
.L80043EB8:
/* 1F2B8 80043EB8 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F2BC 80043EBC 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F2C0 80043EC0 26D60001 */  addiu     $s6, $s6, 1
/* 1F2C4 80043EC4 02C2102A */  slt       $v0, $s6, $v0
/* 1F2C8 80043EC8 1440FFDE */  bnez      $v0, .L80043E44
/* 1F2CC 80043ECC 26520004 */   addiu    $s2, $s2, 4
.L80043ED0:
/* 1F2D0 80043ED0 24020002 */  addiu     $v0, $zero, 2
/* 1F2D4 80043ED4 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1F2D8 80043ED8 AC22A5D0 */  sw        $v0, %lo(D_8009A5D0)($at)
/* 1F2DC 80043EDC 08011044 */  j         .L80044110
/* 1F2E0 80043EE0 00000000 */   nop
.L80043EE4:
/* 1F2E4 80043EE4 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F2E8 80043EE8 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F2EC 80043EEC 18400020 */  blez      $v0, .L80043F70
/* 1F2F0 80043EF0 02A0B02D */   daddu    $s6, $s5, $zero
/* 1F2F4 80043EF4 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 1F2F8 80043EF8 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
.L80043EFC:
/* 1F2FC 80043EFC 8E540028 */  lw        $s4, 0x28($s2)
/* 1F300 80043F00 12800015 */  beqz      $s4, .L80043F58
/* 1F304 80043F04 00000000 */   nop
/* 1F308 80043F08 8E820000 */  lw        $v0, ($s4)
/* 1F30C 80043F0C 18400012 */  blez      $v0, .L80043F58
/* 1F310 80043F10 0000982D */   daddu    $s3, $zero, $zero
/* 1F314 80043F14 0280882D */  daddu     $s1, $s4, $zero
.L80043F18:
/* 1F318 80043F18 8E300004 */  lw        $s0, 4($s1)
/* 1F31C 80043F1C 12000009 */  beqz      $s0, .L80043F44
/* 1F320 80043F20 00000000 */   nop
/* 1F324 80043F24 8E020034 */  lw        $v0, 0x34($s0)
/* 1F328 80043F28 10400006 */  beqz      $v0, .L80043F44
/* 1F32C 80043F2C 00000000 */   nop
/* 1F330 80043F30 0C0B1059 */  jal       does_script_exist
/* 1F334 80043F34 8E04004C */   lw       $a0, 0x4c($s0)
/* 1F338 80043F38 50400002 */  beql      $v0, $zero, .L80043F44
/* 1F33C 80043F3C AE000034 */   sw       $zero, 0x34($s0)
/* 1F340 80043F40 24150001 */  addiu     $s5, $zero, 1
.L80043F44:
/* 1F344 80043F44 8E820000 */  lw        $v0, ($s4)
/* 1F348 80043F48 26730001 */  addiu     $s3, $s3, 1
/* 1F34C 80043F4C 0262102A */  slt       $v0, $s3, $v0
/* 1F350 80043F50 1440FFF1 */  bnez      $v0, .L80043F18
/* 1F354 80043F54 26310004 */   addiu    $s1, $s1, 4
.L80043F58:
/* 1F358 80043F58 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F35C 80043F5C 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F360 80043F60 26D60001 */  addiu     $s6, $s6, 1
/* 1F364 80043F64 02C2102A */  slt       $v0, $s6, $v0
/* 1F368 80043F68 1440FFE4 */  bnez      $v0, .L80043EFC
/* 1F36C 80043F6C 26520004 */   addiu    $s2, $s2, 4
.L80043F70:
/* 1F370 80043F70 16A00067 */  bnez      $s5, .L80044110
/* 1F374 80043F74 00000000 */   nop
/* 1F378 80043F78 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F37C 80043F7C 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F380 80043F80 1840002E */  blez      $v0, .L8004403C
/* 1F384 80043F84 0000B02D */   daddu    $s6, $zero, $zero
/* 1F388 80043F88 24150064 */  addiu     $s5, $zero, 0x64
/* 1F38C 80043F8C 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 1F390 80043F90 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
.L80043F94:
/* 1F394 80043F94 8E540028 */  lw        $s4, 0x28($s2)
/* 1F398 80043F98 12800020 */  beqz      $s4, .L8004401C
/* 1F39C 80043F9C 00000000 */   nop
/* 1F3A0 80043FA0 8E820000 */  lw        $v0, ($s4)
/* 1F3A4 80043FA4 1840001D */  blez      $v0, .L8004401C
/* 1F3A8 80043FA8 0000982D */   daddu    $s3, $zero, $zero
/* 1F3AC 80043FAC 0280882D */  daddu     $s1, $s4, $zero
.L80043FB0:
/* 1F3B0 80043FB0 8E300004 */  lw        $s0, 4($s1)
/* 1F3B4 80043FB4 12000014 */  beqz      $s0, .L80044008
/* 1F3B8 80043FB8 00000000 */   nop
/* 1F3BC 80043FBC 8E020000 */  lw        $v0, ($s0)
/* 1F3C0 80043FC0 30420020 */  andi      $v0, $v0, 0x20
/* 1F3C4 80043FC4 14400010 */  bnez      $v0, .L80044008
/* 1F3C8 80043FC8 00000000 */   nop
/* 1F3CC 80043FCC 8E040024 */  lw        $a0, 0x24($s0)
/* 1F3D0 80043FD0 1080000D */  beqz      $a0, .L80044008
/* 1F3D4 80043FD4 2405000A */   addiu    $a1, $zero, 0xa
/* 1F3D8 80043FD8 0C0B0CF8 */  jal       start_script
/* 1F3DC 80043FDC 0000302D */   daddu    $a2, $zero, $zero
/* 1F3E0 80043FE0 0040182D */  daddu     $v1, $v0, $zero
/* 1F3E4 80043FE4 AE03003C */  sw        $v1, 0x3c($s0)
/* 1F3E8 80043FE8 8C620144 */  lw        $v0, 0x144($v1)
/* 1F3EC 80043FEC AE1500C8 */  sw        $s5, 0xc8($s0)
/* 1F3F0 80043FF0 AE020054 */  sw        $v0, 0x54($s0)
/* 1F3F4 80043FF4 AC700148 */  sw        $s0, 0x148($v1)
/* 1F3F8 80043FF8 86020008 */  lh        $v0, 8($s0)
/* 1F3FC 80043FFC AC62014C */  sw        $v0, 0x14c($v1)
/* 1F400 80044000 92020006 */  lbu       $v0, 6($s0)
/* 1F404 80044004 A0620004 */  sb        $v0, 4($v1)
.L80044008:
/* 1F408 80044008 8E820000 */  lw        $v0, ($s4)
/* 1F40C 8004400C 26730001 */  addiu     $s3, $s3, 1
/* 1F410 80044010 0262102A */  slt       $v0, $s3, $v0
/* 1F414 80044014 1440FFE6 */  bnez      $v0, .L80043FB0
/* 1F418 80044018 26310004 */   addiu    $s1, $s1, 4
.L8004401C:
/* 1F41C 8004401C 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F420 80044020 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F424 80044024 26D60001 */  addiu     $s6, $s6, 1
/* 1F428 80044028 02C2102A */  slt       $v0, $s6, $v0
/* 1F42C 8004402C 1440FFD9 */  bnez      $v0, .L80043F94
/* 1F430 80044030 26520004 */   addiu    $s2, $s2, 4
/* 1F434 80044034 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F438 80044038 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
.L8004403C:
/* 1F43C 8004403C 1840002A */  blez      $v0, .L800440E8
/* 1F440 80044040 0000B02D */   daddu    $s6, $zero, $zero
/* 1F444 80044044 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 1F448 80044048 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
.L8004404C:
/* 1F44C 8004404C 8E540028 */  lw        $s4, 0x28($s2)
/* 1F450 80044050 1280001F */  beqz      $s4, .L800440D0
/* 1F454 80044054 00000000 */   nop
/* 1F458 80044058 8E820000 */  lw        $v0, ($s4)
/* 1F45C 8004405C 1840001C */  blez      $v0, .L800440D0
/* 1F460 80044060 0000982D */   daddu    $s3, $zero, $zero
/* 1F464 80044064 0280882D */  daddu     $s1, $s4, $zero
.L80044068:
/* 1F468 80044068 8E300004 */  lw        $s0, 4($s1)
/* 1F46C 8004406C 12000013 */  beqz      $s0, .L800440BC
/* 1F470 80044070 00000000 */   nop
/* 1F474 80044074 8E020000 */  lw        $v0, ($s0)
/* 1F478 80044078 30420020 */  andi      $v0, $v0, 0x20
/* 1F47C 8004407C 1440000F */  bnez      $v0, .L800440BC
/* 1F480 80044080 00000000 */   nop
/* 1F484 80044084 8E04002C */  lw        $a0, 0x2c($s0)
/* 1F488 80044088 1080000C */  beqz      $a0, .L800440BC
/* 1F48C 8004408C 2405000A */   addiu    $a1, $zero, 0xa
/* 1F490 80044090 0C0B0CF8 */  jal       start_script
/* 1F494 80044094 0000302D */   daddu    $a2, $zero, $zero
/* 1F498 80044098 0040182D */  daddu     $v1, $v0, $zero
/* 1F49C 8004409C AE030044 */  sw        $v1, 0x44($s0)
/* 1F4A0 800440A0 8C620144 */  lw        $v0, 0x144($v1)
/* 1F4A4 800440A4 AE02005C */  sw        $v0, 0x5c($s0)
/* 1F4A8 800440A8 AC700148 */  sw        $s0, 0x148($v1)
/* 1F4AC 800440AC 86020008 */  lh        $v0, 8($s0)
/* 1F4B0 800440B0 AC62014C */  sw        $v0, 0x14c($v1)
/* 1F4B4 800440B4 92020006 */  lbu       $v0, 6($s0)
/* 1F4B8 800440B8 A0620004 */  sb        $v0, 4($v1)
.L800440BC:
/* 1F4BC 800440BC 8E820000 */  lw        $v0, ($s4)
/* 1F4C0 800440C0 26730001 */  addiu     $s3, $s3, 1
/* 1F4C4 800440C4 0262102A */  slt       $v0, $s3, $v0
/* 1F4C8 800440C8 1440FFE7 */  bnez      $v0, .L80044068
/* 1F4CC 800440CC 26310004 */   addiu    $s1, $s1, 4
.L800440D0:
/* 1F4D0 800440D0 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x1C)
/* 1F4D4 800440D4 80420F2C */  lb        $v0, %lo(gCurrentEncounter+0x1C)($v0)
/* 1F4D8 800440D8 26D60001 */  addiu     $s6, $s6, 1
/* 1F4DC 800440DC 02C2102A */  slt       $v0, $s6, $v0
/* 1F4E0 800440E0 1440FFDA */  bnez      $v0, .L8004404C
/* 1F4E4 800440E4 26520004 */   addiu    $s2, $s2, 4
.L800440E8:
/* 1F4E8 800440E8 0C0B1192 */  jal       resume_all_group
/* 1F4EC 800440EC 24040010 */   addiu    $a0, $zero, 0x10
/* 1F4F0 800440F0 24020002 */  addiu     $v0, $zero, 2
/* 1F4F4 800440F4 3C01800A */  lui       $at, %hi(gGameState)
/* 1F4F8 800440F8 AC22A600 */  sw        $v0, %lo(gGameState)($at)
/* 1F4FC 800440FC 24020001 */  addiu     $v0, $zero, 1
/* 1F500 80044100 3C01800A */  lui       $at, %hi(D_8009A678)
/* 1F504 80044104 AC22A678 */  sw        $v0, %lo(D_8009A678)($at)
/* 1F508 80044108 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1F50C 8004410C AC20A5D0 */  sw        $zero, %lo(D_8009A5D0)($at)
.L80044110:
/* 1F510 80044110 8FBF005C */  lw        $ra, 0x5c($sp)
/* 1F514 80044114 8FBE0058 */  lw        $fp, 0x58($sp)
/* 1F518 80044118 8FB70054 */  lw        $s7, 0x54($sp)
/* 1F51C 8004411C 8FB60050 */  lw        $s6, 0x50($sp)
/* 1F520 80044120 8FB5004C */  lw        $s5, 0x4c($sp)
/* 1F524 80044124 8FB40048 */  lw        $s4, 0x48($sp)
/* 1F528 80044128 8FB30044 */  lw        $s3, 0x44($sp)
/* 1F52C 8004412C 8FB20040 */  lw        $s2, 0x40($sp)
/* 1F530 80044130 8FB1003C */  lw        $s1, 0x3c($sp)
/* 1F534 80044134 8FB00038 */  lw        $s0, 0x38($sp)
/* 1F538 80044138 03E00008 */  jr        $ra
/* 1F53C 8004413C 27BD0060 */   addiu    $sp, $sp, 0x60
