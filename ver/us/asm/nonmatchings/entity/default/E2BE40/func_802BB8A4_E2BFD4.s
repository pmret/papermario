.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BCFA0_E2D6D0
.double 0.4

glabel D_802BCFA8_E2D6D8
.double 1.6

glabel D_802BCFB0_E2D6E0
.double 0.8

glabel D_802BCFB8_E2D6E8
.double -10.2

.section .text

glabel func_802BB8A4_E2BFD4
/* E2BFD4 802BB8A4 27BDFF78 */  addiu     $sp, $sp, -0x88
/* E2BFD8 802BB8A8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* E2BFDC 802BB8AC 4480D000 */  mtc1      $zero, $f26
/* E2BFE0 802BB8B0 F7BE0080 */  sdc1      $f30, 0x80($sp)
/* E2BFE4 802BB8B4 3C014F00 */  lui       $at, 0x4f00
/* E2BFE8 802BB8B8 4481F000 */  mtc1      $at, $f30
/* E2BFEC 802BB8BC AFBE0050 */  sw        $fp, 0x50($sp)
/* E2BFF0 802BB8C0 0080F02D */  daddu     $fp, $a0, $zero
/* E2BFF4 802BB8C4 AFB3003C */  sw        $s3, 0x3c($sp)
/* E2BFF8 802BB8C8 0000982D */  daddu     $s3, $zero, $zero
/* E2BFFC 802BB8CC AFB60048 */  sw        $s6, 0x48($sp)
/* E2C000 802BB8D0 27B60020 */  addiu     $s6, $sp, 0x20
/* E2C004 802BB8D4 AFB50044 */  sw        $s5, 0x44($sp)
/* E2C008 802BB8D8 27B50024 */  addiu     $s5, $sp, 0x24
/* E2C00C 802BB8DC AFB40040 */  sw        $s4, 0x40($sp)
/* E2C010 802BB8E0 27B40028 */  addiu     $s4, $sp, 0x28
/* E2C014 802BB8E4 AFB7004C */  sw        $s7, 0x4c($sp)
/* E2C018 802BB8E8 3C178000 */  lui       $s7, 0x8000
/* E2C01C 802BB8EC AFBF0054 */  sw        $ra, 0x54($sp)
/* E2C020 802BB8F0 AFB20038 */  sw        $s2, 0x38($sp)
/* E2C024 802BB8F4 AFB10034 */  sw        $s1, 0x34($sp)
/* E2C028 802BB8F8 AFB00030 */  sw        $s0, 0x30($sp)
/* E2C02C 802BB8FC F7BC0078 */  sdc1      $f28, 0x78($sp)
/* E2C030 802BB900 F7B80068 */  sdc1      $f24, 0x68($sp)
/* E2C034 802BB904 F7B60060 */  sdc1      $f22, 0x60($sp)
/* E2C038 802BB908 F7B40058 */  sdc1      $f20, 0x58($sp)
/* E2C03C 802BB90C 8FD20040 */  lw        $s2, 0x40($fp)
/* E2C040 802BB910 4600D706 */  mov.s     $f28, $f26
/* E2C044 802BB914 4600D606 */  mov.s     $f24, $f26
/* E2C048 802BB918 0240882D */  daddu     $s1, $s2, $zero
/* E2C04C 802BB91C 0240802D */  daddu     $s0, $s2, $zero
.L802BB920:
/* E2C050 802BB920 82230008 */  lb        $v1, 8($s1)
/* E2C054 802BB924 24020001 */  addiu     $v0, $zero, 1
/* E2C058 802BB928 10620028 */  beq       $v1, $v0, .L802BB9CC
/* E2C05C 802BB92C 28620002 */   slti     $v0, $v1, 2
/* E2C060 802BB930 10400005 */  beqz      $v0, .L802BB948
/* E2C064 802BB934 24020002 */   addiu    $v0, $zero, 2
/* E2C068 802BB938 10600009 */  beqz      $v1, .L802BB960
/* E2C06C 802BB93C 00000000 */   nop
/* E2C070 802BB940 080AEE9B */  j         .L802BBA6C
/* E2C074 802BB944 00000000 */   nop
.L802BB948:
/* E2C078 802BB948 10620029 */  beq       $v1, $v0, .L802BB9F0
/* E2C07C 802BB94C 24020003 */   addiu    $v0, $zero, 3
/* E2C080 802BB950 50620046 */  beql      $v1, $v0, .L802BBA6C
/* E2C084 802BB954 26730001 */   addiu    $s3, $s3, 1
/* E2C088 802BB958 080AEE9B */  j         .L802BBA6C
/* E2C08C 802BB95C 00000000 */   nop
.L802BB960:
/* E2C090 802BB960 3C014000 */  lui       $at, 0x4000
/* E2C094 802BB964 4481E000 */  mtc1      $at, $f28
/* E2C098 802BB968 9222003C */  lbu       $v0, 0x3c($s1)
/* E2C09C 802BB96C C61A004C */  lwc1      $f26, 0x4c($s0)
/* E2C0A0 802BB970 3C014120 */  lui       $at, 0x4120
/* E2C0A4 802BB974 44810000 */  mtc1      $at, $f0
/* E2C0A8 802BB978 44801000 */  mtc1      $zero, $f2
/* E2C0AC 802BB97C 44822000 */  mtc1      $v0, $f4
/* E2C0B0 802BB980 00000000 */  nop
/* E2C0B4 802BB984 46802120 */  cvt.s.w   $f4, $f4
/* E2C0B8 802BB988 461A103E */  c.le.s    $f2, $f26
/* E2C0BC 802BB98C 00000000 */  nop
/* E2C0C0 802BB990 45000006 */  bc1f      .L802BB9AC
/* E2C0C4 802BB994 46002603 */   div.s    $f24, $f4, $f0
/* E2C0C8 802BB998 3C01802C */  lui       $at, %hi(D_802BCFA0_E2D6D0)
/* E2C0CC 802BB99C D422CFA0 */  ldc1      $f2, %lo(D_802BCFA0_E2D6D0)($at)
/* E2C0D0 802BB9A0 4600D021 */  cvt.d.s   $f0, $f26
/* E2C0D4 802BB9A4 080AEE70 */  j         .L802BB9C0
/* E2C0D8 802BB9A8 46220001 */   sub.d    $f0, $f0, $f2
.L802BB9AC:
/* E2C0DC 802BB9AC 3C013FE0 */  lui       $at, 0x3fe0
/* E2C0E0 802BB9B0 44811800 */  mtc1      $at, $f3
/* E2C0E4 802BB9B4 44801000 */  mtc1      $zero, $f2
/* E2C0E8 802BB9B8 4600D021 */  cvt.d.s   $f0, $f26
/* E2C0EC 802BB9BC 46220000 */  add.d     $f0, $f0, $f2
.L802BB9C0:
/* E2C0F0 802BB9C0 46200020 */  cvt.s.d   $f0, $f0
/* E2C0F4 802BB9C4 080AEE9B */  j         .L802BBA6C
/* E2C0F8 802BB9C8 E600004C */   swc1     $f0, 0x4c($s0)
.L802BB9CC:
/* E2C0FC 802BB9CC 3C013F80 */  lui       $at, 0x3f80
/* E2C100 802BB9D0 4481C000 */  mtc1      $at, $f24
/* E2C104 802BB9D4 C602004C */  lwc1      $f2, 0x4c($s0)
/* E2C108 802BB9D8 3C013E80 */  lui       $at, 0x3e80
/* E2C10C 802BB9DC 44810000 */  mtc1      $at, $f0
/* E2C110 802BB9E0 4480E000 */  mtc1      $zero, $f28
/* E2C114 802BB9E4 46001682 */  mul.s     $f26, $f2, $f0
/* E2C118 802BB9E8 080AEE9B */  j         .L802BBA6C
/* E2C11C 802BB9EC 00000000 */   nop
.L802BB9F0:
/* E2C120 802BB9F0 C602004C */  lwc1      $f2, 0x4c($s0)
/* E2C124 802BB9F4 3C013F80 */  lui       $at, 0x3f80
/* E2C128 802BB9F8 44810000 */  mtc1      $at, $f0
/* E2C12C 802BB9FC 00000000 */  nop
/* E2C130 802BBA00 46001080 */  add.s     $f2, $f2, $f0
/* E2C134 802BBA04 3C0141A0 */  lui       $at, 0x41a0
/* E2C138 802BBA08 44810000 */  mtc1      $at, $f0
/* E2C13C 802BBA0C 00000000 */  nop
/* E2C140 802BBA10 4602003C */  c.lt.s    $f0, $f2
/* E2C144 802BBA14 00000000 */  nop
/* E2C148 802BBA18 45000002 */  bc1f      .L802BBA24
/* E2C14C 802BBA1C E602004C */   swc1     $f2, 0x4c($s0)
/* E2C150 802BBA20 E600004C */  swc1      $f0, 0x4c($s0)
.L802BBA24:
/* E2C154 802BBA24 C602004C */  lwc1      $f2, 0x4c($s0)
/* E2C158 802BBA28 3C01428C */  lui       $at, 0x428c
/* E2C15C 802BBA2C 44812000 */  mtc1      $at, $f4
/* E2C160 802BBA30 C60000B4 */  lwc1      $f0, 0xb4($s0)
/* E2C164 802BBA34 46041083 */  div.s     $f2, $f2, $f4
/* E2C168 802BBA38 46020001 */  sub.s     $f0, $f0, $f2
/* E2C16C 802BBA3C E60000B4 */  swc1      $f0, 0xb4($s0)
/* E2C170 802BBA40 92220015 */  lbu       $v0, 0x15($s1)
/* E2C174 802BBA44 2442FFFB */  addiu     $v0, $v0, -5
/* E2C178 802BBA48 A2220015 */  sb        $v0, 0x15($s1)
/* E2C17C 802BBA4C 304200FF */  andi      $v0, $v0, 0xff
/* E2C180 802BBA50 2C420006 */  sltiu     $v0, $v0, 6
/* E2C184 802BBA54 10400005 */  beqz      $v0, .L802BBA6C
/* E2C188 802BBA58 00000000 */   nop
/* E2C18C 802BBA5C 92220008 */  lbu       $v0, 8($s1)
/* E2C190 802BBA60 A2200015 */  sb        $zero, 0x15($s1)
/* E2C194 802BBA64 24420001 */  addiu     $v0, $v0, 1
/* E2C198 802BBA68 A2220008 */  sb        $v0, 8($s1)
.L802BBA6C:
/* E2C19C 802BBA6C 82220008 */  lb        $v0, 8($s1)
/* E2C1A0 802BBA70 28420002 */  slti      $v0, $v0, 2
/* E2C1A4 802BBA74 504000D6 */  beql      $v0, $zero, .L802BBDD0
/* E2C1A8 802BBA78 26310001 */   addiu    $s1, $s1, 1
/* E2C1AC 802BBA7C C602011C */  lwc1      $f2, 0x11c($s0)
/* E2C1B0 802BBA80 44800000 */  mtc1      $zero, $f0
/* E2C1B4 802BBA84 00000000 */  nop
/* E2C1B8 802BBA88 4602003E */  c.le.s    $f0, $f2
/* E2C1BC 802BBA8C 3C01802C */  lui       $at, %hi(D_802BCFA8_E2D6D8)
/* E2C1C0 802BBA90 D420CFA8 */  ldc1      $f0, %lo(D_802BCFA8_E2D6D8)($at)
/* E2C1C4 802BBA94 45000003 */  bc1f      .L802BBAA4
/* E2C1C8 802BBA98 460010A1 */   cvt.d.s  $f2, $f2
/* E2C1CC 802BBA9C 3C01802C */  lui       $at, %hi(D_802BCFB0_E2D6E0)
/* E2C1D0 802BBAA0 D420CFB0 */  ldc1      $f0, %lo(D_802BCFB0_E2D6E0)($at)
.L802BBAA4:
/* E2C1D4 802BBAA4 46201081 */  sub.d     $f2, $f2, $f0
/* E2C1D8 802BBAA8 3C01802C */  lui       $at, %hi(D_802BCFB8_E2D6E8)
/* E2C1DC 802BBAAC D424CFB8 */  ldc1      $f4, %lo(D_802BCFB8_E2D6E8)($at)
/* E2C1E0 802BBAB0 462010A0 */  cvt.s.d   $f2, $f2
/* E2C1E4 802BBAB4 46001021 */  cvt.d.s   $f0, $f2
/* E2C1E8 802BBAB8 4624003C */  c.lt.d    $f0, $f4
/* E2C1EC 802BBABC 00000000 */  nop
/* E2C1F0 802BBAC0 45000006 */  bc1f      .L802BBADC
/* E2C1F4 802BBAC4 E602011C */   swc1     $f2, 0x11c($s0)
/* E2C1F8 802BBAC8 3C01C123 */  lui       $at, 0xc123
/* E2C1FC 802BBACC 34213333 */  ori       $at, $at, 0x3333
/* E2C200 802BBAD0 44810000 */  mtc1      $at, $f0
/* E2C204 802BBAD4 00000000 */  nop
/* E2C208 802BBAD8 E600011C */  swc1      $f0, 0x11c($s0)
.L802BBADC:
/* E2C20C 802BBADC C60000B4 */  lwc1      $f0, 0xb4($s0)
/* E2C210 802BBAE0 C602011C */  lwc1      $f2, 0x11c($s0)
/* E2C214 802BBAE4 46020000 */  add.s     $f0, $f0, $f2
/* E2C218 802BBAE8 E60000B4 */  swc1      $f0, 0xb4($s0)
/* E2C21C 802BBAEC 92220015 */  lbu       $v0, 0x15($s1)
/* E2C220 802BBAF0 3C0143B4 */  lui       $at, 0x43b4
/* E2C224 802BBAF4 44814000 */  mtc1      $at, $f8
/* E2C228 802BBAF8 4482A000 */  mtc1      $v0, $f20
/* E2C22C 802BBAFC 00000000 */  nop
/* E2C230 802BBB00 4680A520 */  cvt.s.w   $f20, $f20
/* E2C234 802BBB04 4608A502 */  mul.s     $f20, $f20, $f8
/* E2C238 802BBB08 00000000 */  nop
/* E2C23C 802BBB0C 3C013B80 */  lui       $at, 0x3b80
/* E2C240 802BBB10 44814000 */  mtc1      $at, $f8
/* E2C244 802BBB14 00000000 */  nop
/* E2C248 802BBB18 4608A502 */  mul.s     $f20, $f20, $f8
/* E2C24C 802BBB1C 00000000 */  nop
/* E2C250 802BBB20 3C0140C9 */  lui       $at, 0x40c9
/* E2C254 802BBB24 34210FD0 */  ori       $at, $at, 0xfd0
/* E2C258 802BBB28 44814000 */  mtc1      $at, $f8
/* E2C25C 802BBB2C 00000000 */  nop
/* E2C260 802BBB30 4608A002 */  mul.s     $f0, $f20, $f8
/* E2C264 802BBB34 00000000 */  nop
/* E2C268 802BBB38 3C0143B4 */  lui       $at, 0x43b4
/* E2C26C 802BBB3C 44814000 */  mtc1      $at, $f8
/* E2C270 802BBB40 00000000 */  nop
/* E2C274 802BBB44 46080583 */  div.s     $f22, $f0, $f8
/* E2C278 802BBB48 0C00A85B */  jal       sin_rad
/* E2C27C 802BBB4C 4600B306 */   mov.s    $f12, $f22
/* E2C280 802BBB50 4600C002 */  mul.s     $f0, $f24, $f0
/* E2C284 802BBB54 00000000 */  nop
/* E2C288 802BBB58 C6020080 */  lwc1      $f2, 0x80($s0)
/* E2C28C 802BBB5C 46001080 */  add.s     $f2, $f2, $f0
/* E2C290 802BBB60 4600B306 */  mov.s     $f12, $f22
/* E2C294 802BBB64 0C00A874 */  jal       cos_rad
/* E2C298 802BBB68 E6020080 */   swc1     $f2, 0x80($s0)
/* E2C29C 802BBB6C 4600C002 */  mul.s     $f0, $f24, $f0
/* E2C2A0 802BBB70 00000000 */  nop
/* E2C2A4 802BBB74 C60200E8 */  lwc1      $f2, 0xe8($s0)
/* E2C2A8 802BBB78 3C040004 */  lui       $a0, 4
/* E2C2AC 802BBB7C 46001080 */  add.s     $f2, $f2, $f0
/* E2C2B0 802BBB80 C6000080 */  lwc1      $f0, 0x80($s0)
/* E2C2B4 802BBB84 02C0282D */  daddu     $a1, $s6, $zero
/* E2C2B8 802BBB88 E60200E8 */  swc1      $f2, 0xe8($s0)
/* E2C2BC 802BBB8C C60200B4 */  lwc1      $f2, 0xb4($s0)
/* E2C2C0 802BBB90 C60400E8 */  lwc1      $f4, 0xe8($s0)
/* E2C2C4 802BBB94 02A0302D */  daddu     $a2, $s5, $zero
/* E2C2C8 802BBB98 E7A00020 */  swc1      $f0, 0x20($sp)
/* E2C2CC 802BBB9C E7A20024 */  swc1      $f2, 0x24($sp)
/* E2C2D0 802BBBA0 E7A40028 */  swc1      $f4, 0x28($sp)
/* E2C2D4 802BBBA4 3C014100 */  lui       $at, 0x4100
/* E2C2D8 802BBBA8 44814000 */  mtc1      $at, $f8
/* E2C2DC 802BBBAC 0280382D */  daddu     $a3, $s4, $zero
/* E2C2E0 802BBBB0 E7B80010 */  swc1      $f24, 0x10($sp)
/* E2C2E4 802BBBB4 E7B40014 */  swc1      $f20, 0x14($sp)
/* E2C2E8 802BBBB8 E7A80018 */  swc1      $f8, 0x18($sp)
/* E2C2EC 802BBBBC 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* E2C2F0 802BBBC0 E7A8001C */   swc1     $f8, 0x1c($sp)
/* E2C2F4 802BBBC4 10400031 */  beqz      $v0, .L802BBC8C
/* E2C2F8 802BBBC8 3C040004 */   lui      $a0, 4
/* E2C2FC 802BBBCC C7A00020 */  lwc1      $f0, 0x20($sp)
/* E2C300 802BBBD0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E2C304 802BBBD4 C7A40028 */  lwc1      $f4, 0x28($sp)
/* E2C308 802BBBD8 E6000080 */  swc1      $f0, 0x80($s0)
/* E2C30C 802BBBDC E60200B4 */  swc1      $f2, 0xb4($s0)
/* E2C310 802BBBE0 E60400E8 */  swc1      $f4, 0xe8($s0)
/* E2C314 802BBBE4 92220015 */  lbu       $v0, 0x15($s1)
/* E2C318 802BBBE8 3C0143B4 */  lui       $at, 0x43b4
/* E2C31C 802BBBEC 44814000 */  mtc1      $at, $f8
/* E2C320 802BBBF0 24420080 */  addiu     $v0, $v0, 0x80
/* E2C324 802BBBF4 A2220015 */  sb        $v0, 0x15($s1)
/* E2C328 802BBBF8 304200FF */  andi      $v0, $v0, 0xff
/* E2C32C 802BBBFC 44820000 */  mtc1      $v0, $f0
/* E2C330 802BBC00 00000000 */  nop
/* E2C334 802BBC04 46800020 */  cvt.s.w   $f0, $f0
/* E2C338 802BBC08 46080002 */  mul.s     $f0, $f0, $f8
/* E2C33C 802BBC0C 00000000 */  nop
/* E2C340 802BBC10 3C013B80 */  lui       $at, 0x3b80
/* E2C344 802BBC14 44814000 */  mtc1      $at, $f8
/* E2C348 802BBC18 00000000 */  nop
/* E2C34C 802BBC1C 46080002 */  mul.s     $f0, $f0, $f8
/* E2C350 802BBC20 00000000 */  nop
/* E2C354 802BBC24 3C0140C9 */  lui       $at, 0x40c9
/* E2C358 802BBC28 34210FD0 */  ori       $at, $at, 0xfd0
/* E2C35C 802BBC2C 44814000 */  mtc1      $at, $f8
/* E2C360 802BBC30 00000000 */  nop
/* E2C364 802BBC34 46080002 */  mul.s     $f0, $f0, $f8
/* E2C368 802BBC38 00000000 */  nop
/* E2C36C 802BBC3C 3C0143B4 */  lui       $at, 0x43b4
/* E2C370 802BBC40 44814000 */  mtc1      $at, $f8
/* E2C374 802BBC44 3C014100 */  lui       $at, 0x4100
/* E2C378 802BBC48 4481C000 */  mtc1      $at, $f24
/* E2C37C 802BBC4C 46080583 */  div.s     $f22, $f0, $f8
/* E2C380 802BBC50 0C00A85B */  jal       sin_rad
/* E2C384 802BBC54 4600B306 */   mov.s    $f12, $f22
/* E2C388 802BBC58 46180002 */  mul.s     $f0, $f0, $f24
/* E2C38C 802BBC5C 00000000 */  nop
/* E2C390 802BBC60 C6020080 */  lwc1      $f2, 0x80($s0)
/* E2C394 802BBC64 46001080 */  add.s     $f2, $f2, $f0
/* E2C398 802BBC68 4600B306 */  mov.s     $f12, $f22
/* E2C39C 802BBC6C 0C00A874 */  jal       cos_rad
/* E2C3A0 802BBC70 E6020080 */   swc1     $f2, 0x80($s0)
/* E2C3A4 802BBC74 46180002 */  mul.s     $f0, $f0, $f24
/* E2C3A8 802BBC78 00000000 */  nop
/* E2C3AC 802BBC7C C60200E8 */  lwc1      $f2, 0xe8($s0)
/* E2C3B0 802BBC80 46001080 */  add.s     $f2, $f2, $f0
/* E2C3B4 802BBC84 E60200E8 */  swc1      $f2, 0xe8($s0)
/* E2C3B8 802BBC88 3C040004 */  lui       $a0, 4
.L802BBC8C:
/* E2C3BC 802BBC8C 02C0282D */  daddu     $a1, $s6, $zero
/* E2C3C0 802BBC90 02A0302D */  daddu     $a2, $s5, $zero
/* E2C3C4 802BBC94 0280382D */  daddu     $a3, $s4, $zero
/* E2C3C8 802BBC98 27A2002C */  addiu     $v0, $sp, 0x2c
/* E2C3CC 802BBC9C C6020080 */  lwc1      $f2, 0x80($s0)
/* E2C3D0 802BBCA0 C60400B4 */  lwc1      $f4, 0xb4($s0)
/* E2C3D4 802BBCA4 C600011C */  lwc1      $f0, 0x11c($s0)
/* E2C3D8 802BBCA8 C60600E8 */  lwc1      $f6, 0xe8($s0)
/* E2C3DC 802BBCAC 46000005 */  abs.s     $f0, $f0
/* E2C3E0 802BBCB0 E7A20020 */  swc1      $f2, 0x20($sp)
/* E2C3E4 802BBCB4 E7A40024 */  swc1      $f4, 0x24($sp)
/* E2C3E8 802BBCB8 E7A60028 */  swc1      $f6, 0x28($sp)
/* E2C3EC 802BBCBC E7A0002C */  swc1      $f0, 0x2c($sp)
/* E2C3F0 802BBCC0 0C0372DF */  jal       npc_raycast_down_sides
/* E2C3F4 802BBCC4 AFA20010 */   sw       $v0, 0x10($sp)
/* E2C3F8 802BBCC8 1440000B */  bnez      $v0, .L802BBCF8
/* E2C3FC 802BBCCC 00000000 */   nop
/* E2C400 802BBCD0 C6400004 */  lwc1      $f0, 4($s2)
/* E2C404 802BBCD4 3C014348 */  lui       $at, 0x4348
/* E2C408 802BBCD8 44811000 */  mtc1      $at, $f2
/* E2C40C 802BBCDC 00000000 */  nop
/* E2C410 802BBCE0 46020001 */  sub.s     $f0, $f0, $f2
/* E2C414 802BBCE4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E2C418 802BBCE8 4600103C */  c.lt.s    $f2, $f0
/* E2C41C 802BBCEC 00000000 */  nop
/* E2C420 802BBCF0 45000010 */  bc1f      .L802BBD34
/* E2C424 802BBCF4 00000000 */   nop
.L802BBCF8:
/* E2C428 802BBCF8 92220008 */  lbu       $v0, 8($s1)
/* E2C42C 802BBCFC 24420001 */  addiu     $v0, $v0, 1
/* E2C430 802BBD00 A2220008 */  sb        $v0, 8($s1)
/* E2C434 802BBD04 C600011C */  lwc1      $f0, 0x11c($s0)
/* E2C438 802BBD08 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E2C43C 802BBD0C 46000005 */  abs.s     $f0, $f0
/* E2C440 802BBD10 46001080 */  add.s     $f2, $f2, $f0
/* E2C444 802BBD14 E61C011C */  swc1      $f28, 0x11c($s0)
/* E2C448 802BBD18 E60200B4 */  swc1      $f2, 0xb4($s0)
/* E2C44C 802BBD1C 82230008 */  lb        $v1, 8($s1)
/* E2C450 802BBD20 24020002 */  addiu     $v0, $zero, 2
/* E2C454 802BBD24 14620003 */  bne       $v1, $v0, .L802BBD34
/* E2C458 802BBD28 240200FE */   addiu    $v0, $zero, 0xfe
/* E2C45C 802BBD2C A2220015 */  sb        $v0, 0x15($s1)
/* E2C460 802BBD30 AE00004C */  sw        $zero, 0x4c($s0)
.L802BBD34:
/* E2C464 802BBD34 92220022 */  lbu       $v0, 0x22($s1)
/* E2C468 802BBD38 44820000 */  mtc1      $v0, $f0
/* E2C46C 802BBD3C 00000000 */  nop
/* E2C470 802BBD40 46800020 */  cvt.s.w   $f0, $f0
/* E2C474 802BBD44 461A0000 */  add.s     $f0, $f0, $f26
/* E2C478 802BBD48 4600F03E */  c.le.s    $f30, $f0
/* E2C47C 802BBD4C 00000000 */  nop
/* E2C480 802BBD50 45010005 */  bc1t      .L802BBD68
/* E2C484 802BBD54 26230022 */   addiu    $v1, $s1, 0x22
/* E2C488 802BBD58 4600020D */  trunc.w.s $f8, $f0
/* E2C48C 802BBD5C 44024000 */  mfc1      $v0, $f8
/* E2C490 802BBD60 080AEF60 */  j         .L802BBD80
/* E2C494 802BBD64 A0620000 */   sb       $v0, ($v1)
.L802BBD68:
/* E2C498 802BBD68 461E0001 */  sub.s     $f0, $f0, $f30
/* E2C49C 802BBD6C 4600020D */  trunc.w.s $f8, $f0
/* E2C4A0 802BBD70 44024000 */  mfc1      $v0, $f8
/* E2C4A4 802BBD74 00000000 */  nop
/* E2C4A8 802BBD78 00571025 */  or        $v0, $v0, $s7
/* E2C4AC 802BBD7C A0620000 */  sb        $v0, ($v1)
.L802BBD80:
/* E2C4B0 802BBD80 9222002F */  lbu       $v0, 0x2f($s1)
/* E2C4B4 802BBD84 44820000 */  mtc1      $v0, $f0
/* E2C4B8 802BBD88 00000000 */  nop
/* E2C4BC 802BBD8C 46800020 */  cvt.s.w   $f0, $f0
/* E2C4C0 802BBD90 461A0001 */  sub.s     $f0, $f0, $f26
/* E2C4C4 802BBD94 4600F03E */  c.le.s    $f30, $f0
/* E2C4C8 802BBD98 00000000 */  nop
/* E2C4CC 802BBD9C 45010005 */  bc1t      .L802BBDB4
/* E2C4D0 802BBDA0 2623002F */   addiu    $v1, $s1, 0x2f
/* E2C4D4 802BBDA4 4600020D */  trunc.w.s $f8, $f0
/* E2C4D8 802BBDA8 44024000 */  mfc1      $v0, $f8
/* E2C4DC 802BBDAC 080AEF73 */  j         .L802BBDCC
/* E2C4E0 802BBDB0 A0620000 */   sb       $v0, ($v1)
.L802BBDB4:
/* E2C4E4 802BBDB4 461E0001 */  sub.s     $f0, $f0, $f30
/* E2C4E8 802BBDB8 4600020D */  trunc.w.s $f8, $f0
/* E2C4EC 802BBDBC 44024000 */  mfc1      $v0, $f8
/* E2C4F0 802BBDC0 00000000 */  nop
/* E2C4F4 802BBDC4 00571025 */  or        $v0, $v0, $s7
/* E2C4F8 802BBDC8 A0620000 */  sb        $v0, ($v1)
.L802BBDCC:
/* E2C4FC 802BBDCC 26310001 */  addiu     $s1, $s1, 1
.L802BBDD0:
/* E2C500 802BBDD0 2642000C */  addiu     $v0, $s2, 0xc
/* E2C504 802BBDD4 0222102A */  slt       $v0, $s1, $v0
/* E2C508 802BBDD8 1440FED1 */  bnez      $v0, .L802BB920
/* E2C50C 802BBDDC 26100004 */   addiu    $s0, $s0, 4
/* E2C510 802BBDE0 2A62000C */  slti      $v0, $s3, 0xc
/* E2C514 802BBDE4 14400003 */  bnez      $v0, .L802BBDF4
/* E2C518 802BBDE8 00000000 */   nop
/* E2C51C 802BBDEC 0C043F5A */  jal       exec_entity_commandlist
/* E2C520 802BBDF0 03C0202D */   daddu    $a0, $fp, $zero
.L802BBDF4:
/* E2C524 802BBDF4 8FBF0054 */  lw        $ra, 0x54($sp)
/* E2C528 802BBDF8 8FBE0050 */  lw        $fp, 0x50($sp)
/* E2C52C 802BBDFC 8FB7004C */  lw        $s7, 0x4c($sp)
/* E2C530 802BBE00 8FB60048 */  lw        $s6, 0x48($sp)
/* E2C534 802BBE04 8FB50044 */  lw        $s5, 0x44($sp)
/* E2C538 802BBE08 8FB40040 */  lw        $s4, 0x40($sp)
/* E2C53C 802BBE0C 8FB3003C */  lw        $s3, 0x3c($sp)
/* E2C540 802BBE10 8FB20038 */  lw        $s2, 0x38($sp)
/* E2C544 802BBE14 8FB10034 */  lw        $s1, 0x34($sp)
/* E2C548 802BBE18 8FB00030 */  lw        $s0, 0x30($sp)
/* E2C54C 802BBE1C D7BE0080 */  ldc1      $f30, 0x80($sp)
/* E2C550 802BBE20 D7BC0078 */  ldc1      $f28, 0x78($sp)
/* E2C554 802BBE24 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* E2C558 802BBE28 D7B80068 */  ldc1      $f24, 0x68($sp)
/* E2C55C 802BBE2C D7B60060 */  ldc1      $f22, 0x60($sp)
/* E2C560 802BBE30 D7B40058 */  ldc1      $f20, 0x58($sp)
/* E2C564 802BBE34 03E00008 */  jr        $ra
/* E2C568 802BBE38 27BD0088 */   addiu    $sp, $sp, 0x88
