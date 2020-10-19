.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ECC_B4B93C
/* B4B93C 80240ECC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B4B940 80240ED0 AFB40040 */  sw        $s4, 0x40($sp)
/* B4B944 80240ED4 0080A02D */  daddu     $s4, $a0, $zero
/* B4B948 80240ED8 AFBF0044 */  sw        $ra, 0x44($sp)
/* B4B94C 80240EDC AFB3003C */  sw        $s3, 0x3c($sp)
/* B4B950 80240EE0 AFB20038 */  sw        $s2, 0x38($sp)
/* B4B954 80240EE4 AFB10034 */  sw        $s1, 0x34($sp)
/* B4B958 80240EE8 AFB00030 */  sw        $s0, 0x30($sp)
/* B4B95C 80240EEC 8E920148 */  lw        $s2, 0x148($s4)
/* B4B960 80240EF0 00A0882D */  daddu     $s1, $a1, $zero
/* B4B964 80240EF4 86440008 */  lh        $a0, 8($s2)
/* B4B968 80240EF8 0C00EABB */  jal       get_npc_unsafe
/* B4B96C 80240EFC 00C0982D */   daddu    $s3, $a2, $zero
/* B4B970 80240F00 8E230014 */  lw        $v1, 0x14($s1)
/* B4B974 80240F04 0460002D */  bltz      $v1, .L80240FBC
/* B4B978 80240F08 0040802D */   daddu    $s0, $v0, $zero
/* B4B97C 80240F0C 0260202D */  daddu     $a0, $s3, $zero
/* B4B980 80240F10 AFA00010 */  sw        $zero, 0x10($sp)
/* B4B984 80240F14 8E260024 */  lw        $a2, 0x24($s1)
/* B4B988 80240F18 8E270028 */  lw        $a3, 0x28($s1)
/* B4B98C 80240F1C 0C01242D */  jal       func_800490B4
/* B4B990 80240F20 0240282D */   daddu    $a1, $s2, $zero
/* B4B994 80240F24 10400025 */  beqz      $v0, .L80240FBC
/* B4B998 80240F28 0000202D */   daddu    $a0, $zero, $zero
/* B4B99C 80240F2C 0200282D */  daddu     $a1, $s0, $zero
/* B4B9A0 80240F30 0000302D */  daddu     $a2, $zero, $zero
/* B4B9A4 80240F34 860300A8 */  lh        $v1, 0xa8($s0)
/* B4B9A8 80240F38 3C013F80 */  lui       $at, 0x3f80
/* B4B9AC 80240F3C 44810000 */  mtc1      $at, $f0
/* B4B9B0 80240F40 3C014000 */  lui       $at, 0x4000
/* B4B9B4 80240F44 44811000 */  mtc1      $at, $f2
/* B4B9B8 80240F48 3C01C1A0 */  lui       $at, 0xc1a0
/* B4B9BC 80240F4C 44812000 */  mtc1      $at, $f4
/* B4B9C0 80240F50 2402000F */  addiu     $v0, $zero, 0xf
/* B4B9C4 80240F54 AFA2001C */  sw        $v0, 0x1c($sp)
/* B4B9C8 80240F58 44833000 */  mtc1      $v1, $f6
/* B4B9CC 80240F5C 00000000 */  nop       
/* B4B9D0 80240F60 468031A0 */  cvt.s.w   $f6, $f6
/* B4B9D4 80240F64 44073000 */  mfc1      $a3, $f6
/* B4B9D8 80240F68 27A20028 */  addiu     $v0, $sp, 0x28
/* B4B9DC 80240F6C AFA20020 */  sw        $v0, 0x20($sp)
/* B4B9E0 80240F70 E7A00010 */  swc1      $f0, 0x10($sp)
/* B4B9E4 80240F74 E7A20014 */  swc1      $f2, 0x14($sp)
/* B4B9E8 80240F78 0C01BFA4 */  jal       fx_emote
/* B4B9EC 80240F7C E7A40018 */   swc1     $f4, 0x18($sp)
/* B4B9F0 80240F80 0200202D */  daddu     $a0, $s0, $zero
/* B4B9F4 80240F84 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B4B9F8 80240F88 0C012530 */  jal       func_800494C0
/* B4B9FC 80240F8C 3C060020 */   lui      $a2, 0x20
/* B4BA00 80240F90 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B4BA04 80240F94 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B4BA08 80240F98 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B4BA0C 80240F9C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B4BA10 80240FA0 8C460028 */  lw        $a2, 0x28($v0)
/* B4BA14 80240FA4 0C00A720 */  jal       atan2
/* B4BA18 80240FA8 8C470030 */   lw       $a3, 0x30($v0)
/* B4BA1C 80240FAC 2402000C */  addiu     $v0, $zero, 0xc
/* B4BA20 80240FB0 E600000C */  swc1      $f0, 0xc($s0)
/* B4BA24 80240FB4 08090414 */  j         .L80241050
/* B4BA28 80240FB8 AE820070 */   sw       $v0, 0x70($s4)
.L80240FBC:
/* B4BA2C 80240FBC 8602008C */  lh        $v0, 0x8c($s0)
/* B4BA30 80240FC0 14400023 */  bnez      $v0, .L80241050
/* B4BA34 80240FC4 00000000 */   nop      
/* B4BA38 80240FC8 9602008E */  lhu       $v0, 0x8e($s0)
/* B4BA3C 80240FCC 2442FFFF */  addiu     $v0, $v0, -1
/* B4BA40 80240FD0 A602008E */  sh        $v0, 0x8e($s0)
/* B4BA44 80240FD4 00021400 */  sll       $v0, $v0, 0x10
/* B4BA48 80240FD8 1C40001D */  bgtz      $v0, .L80241050
/* B4BA4C 80240FDC 00000000 */   nop      
/* B4BA50 80240FE0 8E820074 */  lw        $v0, 0x74($s4)
/* B4BA54 80240FE4 2442FFFF */  addiu     $v0, $v0, -1
/* B4BA58 80240FE8 18400018 */  blez      $v0, .L8024104C
/* B4BA5C 80240FEC AE820074 */   sw       $v0, 0x74($s4)
/* B4BA60 80240FF0 C600000C */  lwc1      $f0, 0xc($s0)
/* B4BA64 80240FF4 3C014334 */  lui       $at, 0x4334
/* B4BA68 80240FF8 44816000 */  mtc1      $at, $f12
/* B4BA6C 80240FFC 0C00A6C9 */  jal       clamp_angle
/* B4BA70 80241000 460C0300 */   add.s    $f12, $f0, $f12
/* B4BA74 80241004 240403E8 */  addiu     $a0, $zero, 0x3e8
/* B4BA78 80241008 0C00A67F */  jal       rand_int
/* B4BA7C 8024100C E600000C */   swc1     $f0, 0xc($s0)
/* B4BA80 80241010 3C032E8B */  lui       $v1, 0x2e8b
/* B4BA84 80241014 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* B4BA88 80241018 00430018 */  mult      $v0, $v1
/* B4BA8C 8024101C 00021FC3 */  sra       $v1, $v0, 0x1f
/* B4BA90 80241020 00004010 */  mfhi      $t0
/* B4BA94 80241024 00082043 */  sra       $a0, $t0, 1
/* B4BA98 80241028 00832023 */  subu      $a0, $a0, $v1
/* B4BA9C 8024102C 00041840 */  sll       $v1, $a0, 1
/* B4BAA0 80241030 00641821 */  addu      $v1, $v1, $a0
/* B4BAA4 80241034 00031880 */  sll       $v1, $v1, 2
/* B4BAA8 80241038 00641823 */  subu      $v1, $v1, $a0
/* B4BAAC 8024103C 00431023 */  subu      $v0, $v0, $v1
/* B4BAB0 80241040 24420005 */  addiu     $v0, $v0, 5
/* B4BAB4 80241044 08090414 */  j         .L80241050
/* B4BAB8 80241048 A602008E */   sh       $v0, 0x8e($s0)
.L8024104C:
/* B4BABC 8024104C AE800070 */  sw        $zero, 0x70($s4)
.L80241050:
/* B4BAC0 80241050 8FBF0044 */  lw        $ra, 0x44($sp)
/* B4BAC4 80241054 8FB40040 */  lw        $s4, 0x40($sp)
/* B4BAC8 80241058 8FB3003C */  lw        $s3, 0x3c($sp)
/* B4BACC 8024105C 8FB20038 */  lw        $s2, 0x38($sp)
/* B4BAD0 80241060 8FB10034 */  lw        $s1, 0x34($sp)
/* B4BAD4 80241064 8FB00030 */  lw        $s0, 0x30($sp)
/* B4BAD8 80241068 03E00008 */  jr        $ra
/* B4BADC 8024106C 27BD0048 */   addiu    $sp, $sp, 0x48
