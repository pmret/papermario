.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B960
/* 46D60 8006B960 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 46D64 8006B964 AFB10044 */  sw        $s1, 0x44($sp)
/* 46D68 8006B968 00808821 */  addu      $s1, $a0, $zero
/* 46D6C 8006B96C AFB60058 */  sw        $s6, 0x58($sp)
/* 46D70 8006B970 3C168009 */  lui       $s6, %hi(D_800958D0)
/* 46D74 8006B974 26D658D0 */  addiu     $s6, $s6, %lo(D_800958D0)
/* 46D78 8006B978 00A02021 */  addu      $a0, $a1, $zero
/* 46D7C 8006B97C 00052E00 */  sll       $a1, $a1, 0x18
/* 46D80 8006B980 00052E03 */  sra       $a1, $a1, 0x18
/* 46D84 8006B984 24020058 */  addiu     $v0, $zero, 0x58
/* 46D88 8006B988 AFBF005C */  sw        $ra, 0x5c($sp)
/* 46D8C 8006B98C AFB50054 */  sw        $s5, 0x54($sp)
/* 46D90 8006B990 AFB40050 */  sw        $s4, 0x50($sp)
/* 46D94 8006B994 AFB3004C */  sw        $s3, 0x4c($sp)
/* 46D98 8006B998 AFB20048 */  sw        $s2, 0x48($sp)
/* 46D9C 8006B99C 14A20003 */  bne       $a1, $v0, .L8006B9AC
/* 46DA0 8006B9A0 AFB00040 */   sw       $s0, 0x40($sp)
/* 46DA4 8006B9A4 3C168009 */  lui       $s6, %hi(D_800958E4)
/* 46DA8 8006B9A8 26D658E4 */  addiu     $s6, $s6, %lo(D_800958E4)
.L8006B9AC:
/* 46DAC 8006B9AC 2402006F */  addiu     $v0, $zero, 0x6f
/* 46DB0 8006B9B0 10A20009 */  beq       $a1, $v0, .L8006B9D8
/* 46DB4 8006B9B4 38A30078 */   xori     $v1, $a1, 0x78
/* 46DB8 8006B9B8 0003182B */  sltu      $v1, $zero, $v1
/* 46DBC 8006B9BC 38A20058 */  xori      $v0, $a1, 0x58
/* 46DC0 8006B9C0 0002102B */  sltu      $v0, $zero, $v0
/* 46DC4 8006B9C4 00621824 */  and       $v1, $v1, $v0
/* 46DC8 8006B9C8 10600004 */  beqz      $v1, .L8006B9DC
/* 46DCC 8006B9CC 24130010 */   addiu    $s3, $zero, 0x10
/* 46DD0 8006B9D0 0801AE77 */  j         .L8006B9DC
/* 46DD4 8006B9D4 2413000A */   addiu    $s3, $zero, 0xa
.L8006B9D8:
/* 46DD8 8006B9D8 24130008 */  addiu     $s3, $zero, 8
.L8006B9DC:
/* 46DDC 8006B9DC 8E340000 */  lw        $s4, ($s1)
/* 46DE0 8006B9E0 8E350004 */  lw        $s5, 4($s1)
/* 46DE4 8006B9E4 00041600 */  sll       $v0, $a0, 0x18
/* 46DE8 8006B9E8 00021603 */  sra       $v0, $v0, 0x18
/* 46DEC 8006B9EC 38430064 */  xori      $v1, $v0, 0x64
/* 46DF0 8006B9F0 2C630001 */  sltiu     $v1, $v1, 1
/* 46DF4 8006B9F4 38420069 */  xori      $v0, $v0, 0x69
/* 46DF8 8006B9F8 2C420001 */  sltiu     $v0, $v0, 1
/* 46DFC 8006B9FC 00621825 */  or        $v1, $v1, $v0
/* 46E00 8006BA00 10600008 */  beqz      $v1, .L8006BA24
/* 46E04 8006BA04 24120018 */   addiu    $s2, $zero, 0x18
/* 46E08 8006BA08 8E220000 */  lw        $v0, ($s1)
/* 46E0C 8006BA0C 04410005 */  bgez      $v0, .L8006BA24
/* 46E10 8006BA10 00000000 */   nop
/* 46E14 8006BA14 0015A823 */  negu      $s5, $s5
/* 46E18 8006BA18 0014A023 */  negu      $s4, $s4
/* 46E1C 8006BA1C 0015102B */  sltu      $v0, $zero, $s5
/* 46E20 8006BA20 0282A023 */  subu      $s4, $s4, $v0
.L8006BA24:
/* 46E24 8006BA24 56800007 */  bnel      $s4, $zero, .L8006BA44
/* 46E28 8006BA28 2652FFFF */   addiu    $s2, $s2, -1
/* 46E2C 8006BA2C 56A00005 */  bnel      $s5, $zero, .L8006BA44
/* 46E30 8006BA30 2652FFFF */   addiu    $s2, $s2, -1
/* 46E34 8006BA34 8E220024 */  lw        $v0, 0x24($s1)
/* 46E38 8006BA38 1040000D */  beqz      $v0, .L8006BA70
/* 46E3C 8006BA3C 02603821 */   addu     $a3, $s3, $zero
/* 46E40 8006BA40 2652FFFF */  addiu     $s2, $s2, -1
.L8006BA44:
/* 46E44 8006BA44 02603821 */  addu      $a3, $s3, $zero
/* 46E48 8006BA48 00003021 */  addu      $a2, $zero, $zero
/* 46E4C 8006BA4C 02802021 */  addu      $a0, $s4, $zero
/* 46E50 8006BA50 02A02821 */  addu      $a1, $s5, $zero
/* 46E54 8006BA54 27B00018 */  addiu     $s0, $sp, 0x18
/* 46E58 8006BA58 0C01BA14 */  jal       func_8006E850
/* 46E5C 8006BA5C 02128021 */   addu     $s0, $s0, $s2
/* 46E60 8006BA60 02C31021 */  addu      $v0, $s6, $v1
/* 46E64 8006BA64 90420000 */  lbu       $v0, ($v0)
/* 46E68 8006BA68 A2020000 */  sb        $v0, ($s0)
/* 46E6C 8006BA6C 02603821 */  addu      $a3, $s3, $zero
.L8006BA70:
/* 46E70 8006BA70 00003021 */  addu      $a2, $zero, $zero
/* 46E74 8006BA74 02802021 */  addu      $a0, $s4, $zero
/* 46E78 8006BA78 0C01B8BC */  jal       func_8006E2F0
/* 46E7C 8006BA7C 02A02821 */   addu     $a1, $s5, $zero
/* 46E80 8006BA80 AE220000 */  sw        $v0, ($s1)
/* 46E84 8006BA84 AE230004 */  sw        $v1, 4($s1)
/* 46E88 8006BA88 27A20018 */  addiu     $v0, $sp, 0x18
/* 46E8C 8006BA8C 02428021 */  addu      $s0, $s2, $v0
.L8006BA90:
/* 46E90 8006BA90 8E220000 */  lw        $v0, ($s1)
/* 46E94 8006BA94 1C400006 */  bgtz      $v0, .L8006BAB0
/* 46E98 8006BA98 00001821 */   addu     $v1, $zero, $zero
/* 46E9C 8006BA9C 14400006 */  bnez      $v0, .L8006BAB8
/* 46EA0 8006BAA0 0012102A */   slt      $v0, $zero, $s2
/* 46EA4 8006BAA4 8E220004 */  lw        $v0, 4($s1)
/* 46EA8 8006BAA8 10400003 */  beqz      $v0, .L8006BAB8
/* 46EAC 8006BAAC 0012102A */   slt      $v0, $zero, $s2
.L8006BAB0:
/* 46EB0 8006BAB0 24030001 */  addiu     $v1, $zero, 1
/* 46EB4 8006BAB4 0012102A */  slt       $v0, $zero, $s2
.L8006BAB8:
/* 46EB8 8006BAB8 00621024 */  and       $v0, $v1, $v0
/* 46EBC 8006BABC 10400014 */  beqz      $v0, .L8006BB10
/* 46EC0 8006BAC0 02601821 */   addu     $v1, $s3, $zero
/* 46EC4 8006BAC4 8E260000 */  lw        $a2, ($s1)
/* 46EC8 8006BAC8 8E270004 */  lw        $a3, 4($s1)
/* 46ECC 8006BACC 001317C3 */  sra       $v0, $s3, 0x1f
/* 46ED0 8006BAD0 AFA20010 */  sw        $v0, 0x10($sp)
/* 46ED4 8006BAD4 AFA30014 */  sw        $v1, 0x14($sp)
/* 46ED8 8006BAD8 0C01B5A1 */  jal       func_8006D684
/* 46EDC 8006BADC 27A40030 */   addiu    $a0, $sp, 0x30
/* 46EE0 8006BAE0 8FA20030 */  lw        $v0, 0x30($sp)
/* 46EE4 8006BAE4 8FA30034 */  lw        $v1, 0x34($sp)
/* 46EE8 8006BAE8 AE220000 */  sw        $v0, ($s1)
/* 46EEC 8006BAEC AE230004 */  sw        $v1, 4($s1)
/* 46EF0 8006BAF0 8FA20038 */  lw        $v0, 0x38($sp)
/* 46EF4 8006BAF4 8FA3003C */  lw        $v1, 0x3c($sp)
/* 46EF8 8006BAF8 02C31021 */  addu      $v0, $s6, $v1
/* 46EFC 8006BAFC 90420000 */  lbu       $v0, ($v0)
/* 46F00 8006BB00 2610FFFF */  addiu     $s0, $s0, -1
/* 46F04 8006BB04 2652FFFF */  addiu     $s2, $s2, -1
/* 46F08 8006BB08 0801AEA4 */  j         .L8006BA90
/* 46F0C 8006BB0C A2020000 */   sb       $v0, ($s0)
.L8006BB10:
/* 46F10 8006BB10 8E240008 */  lw        $a0, 8($s1)
/* 46F14 8006BB14 27A50018 */  addiu     $a1, $sp, 0x18
/* 46F18 8006BB18 00B22821 */  addu      $a1, $a1, $s2
/* 46F1C 8006BB1C 24060018 */  addiu     $a2, $zero, 0x18
/* 46F20 8006BB20 00D23023 */  subu      $a2, $a2, $s2
/* 46F24 8006BB24 0C019291 */  jal       func_80064A44
/* 46F28 8006BB28 AE260014 */   sw       $a2, 0x14($s1)
/* 46F2C 8006BB2C 8E240014 */  lw        $a0, 0x14($s1)
/* 46F30 8006BB30 8E230024 */  lw        $v1, 0x24($s1)
/* 46F34 8006BB34 0083102A */  slt       $v0, $a0, $v1
/* 46F38 8006BB38 10400002 */  beqz      $v0, .L8006BB44
/* 46F3C 8006BB3C 00641023 */   subu     $v0, $v1, $a0
/* 46F40 8006BB40 AE220010 */  sw        $v0, 0x10($s1)
.L8006BB44:
/* 46F44 8006BB44 8E220024 */  lw        $v0, 0x24($s1)
/* 46F48 8006BB48 0441000F */  bgez      $v0, .L8006BB88
/* 46F4C 8006BB4C 24030010 */   addiu    $v1, $zero, 0x10
/* 46F50 8006BB50 8E220030 */  lw        $v0, 0x30($s1)
/* 46F54 8006BB54 30420014 */  andi      $v0, $v0, 0x14
/* 46F58 8006BB58 1443000B */  bne       $v0, $v1, .L8006BB88
/* 46F5C 8006BB5C 00000000 */   nop
/* 46F60 8006BB60 8E220028 */  lw        $v0, 0x28($s1)
/* 46F64 8006BB64 8E23000C */  lw        $v1, 0xc($s1)
/* 46F68 8006BB68 8E250010 */  lw        $a1, 0x10($s1)
/* 46F6C 8006BB6C 8E240014 */  lw        $a0, 0x14($s1)
/* 46F70 8006BB70 00431023 */  subu      $v0, $v0, $v1
/* 46F74 8006BB74 00451023 */  subu      $v0, $v0, $a1
/* 46F78 8006BB78 00449023 */  subu      $s2, $v0, $a0
/* 46F7C 8006BB7C 1A400002 */  blez      $s2, .L8006BB88
/* 46F80 8006BB80 00B21021 */   addu     $v0, $a1, $s2
/* 46F84 8006BB84 AE220010 */  sw        $v0, 0x10($s1)
.L8006BB88:
/* 46F88 8006BB88 8FBF005C */  lw        $ra, 0x5c($sp)
/* 46F8C 8006BB8C 8FB60058 */  lw        $s6, 0x58($sp)
/* 46F90 8006BB90 8FB50054 */  lw        $s5, 0x54($sp)
/* 46F94 8006BB94 8FB40050 */  lw        $s4, 0x50($sp)
/* 46F98 8006BB98 8FB3004C */  lw        $s3, 0x4c($sp)
/* 46F9C 8006BB9C 8FB20048 */  lw        $s2, 0x48($sp)
/* 46FA0 8006BBA0 8FB10044 */  lw        $s1, 0x44($sp)
/* 46FA4 8006BBA4 8FB00040 */  lw        $s0, 0x40($sp)
/* 46FA8 8006BBA8 03E00008 */  jr        $ra
/* 46FAC 8006BBAC 27BD0060 */   addiu    $sp, $sp, 0x60
