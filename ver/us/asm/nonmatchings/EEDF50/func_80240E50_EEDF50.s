.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245450_EF2550
.double 32767.0

.section .text

glabel func_80240E50_EEDF50
/* EEDF50 80240E50 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EEDF54 80240E54 AFB3002C */  sw        $s3, 0x2c($sp)
/* EEDF58 80240E58 0080982D */  daddu     $s3, $a0, $zero
/* EEDF5C 80240E5C AFBF0030 */  sw        $ra, 0x30($sp)
/* EEDF60 80240E60 AFB20028 */  sw        $s2, 0x28($sp)
/* EEDF64 80240E64 AFB10024 */  sw        $s1, 0x24($sp)
/* EEDF68 80240E68 AFB00020 */  sw        $s0, 0x20($sp)
/* EEDF6C 80240E6C 8E710148 */  lw        $s1, 0x148($s3)
/* EEDF70 80240E70 86240008 */  lh        $a0, 8($s1)
/* EEDF74 80240E74 0C00F92F */  jal       dead_get_npc_unsafe
/* EEDF78 80240E78 00A0902D */   daddu    $s2, $a1, $zero
/* EEDF7C 80240E7C 8E440004 */  lw        $a0, 4($s2)
/* EEDF80 80240E80 0040802D */  daddu     $s0, $v0, $zero
/* EEDF84 80240E84 00041FC2 */  srl       $v1, $a0, 0x1f
/* EEDF88 80240E88 00832021 */  addu      $a0, $a0, $v1
/* EEDF8C 80240E8C 00042043 */  sra       $a0, $a0, 1
/* EEDF90 80240E90 0C00AB3B */  jal       dead_rand_int
/* EEDF94 80240E94 24840001 */   addiu    $a0, $a0, 1
/* EEDF98 80240E98 8E430004 */  lw        $v1, 4($s2)
/* EEDF9C 80240E9C 000327C2 */  srl       $a0, $v1, 0x1f
/* EEDFA0 80240EA0 00641821 */  addu      $v1, $v1, $a0
/* EEDFA4 80240EA4 00031843 */  sra       $v1, $v1, 1
/* EEDFA8 80240EA8 00621821 */  addu      $v1, $v1, $v0
/* EEDFAC 80240EAC A603008E */  sh        $v1, 0x8e($s0)
/* EEDFB0 80240EB0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EEDFB4 80240EB4 C6000040 */  lwc1      $f0, 0x40($s0)
/* EEDFB8 80240EB8 C4640000 */  lwc1      $f4, ($v1)
/* EEDFBC 80240EBC 46802120 */  cvt.s.w   $f4, $f4
/* EEDFC0 80240EC0 C4620008 */  lwc1      $f2, 8($v1)
/* EEDFC4 80240EC4 468010A0 */  cvt.s.w   $f2, $f2
/* EEDFC8 80240EC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEDFCC 80240ECC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEDFD0 80240ED0 44061000 */  mfc1      $a2, $f2
/* EEDFD4 80240ED4 C440000C */  lwc1      $f0, 0xc($v0)
/* EEDFD8 80240ED8 46800020 */  cvt.s.w   $f0, $f0
/* EEDFDC 80240EDC E7A00014 */  swc1      $f0, 0x14($sp)
/* EEDFE0 80240EE0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEDFE4 80240EE4 44052000 */  mfc1      $a1, $f4
/* EEDFE8 80240EE8 C4400010 */  lwc1      $f0, 0x10($v0)
/* EEDFEC 80240EEC 46800020 */  cvt.s.w   $f0, $f0
/* EEDFF0 80240EF0 E7A00018 */  swc1      $f0, 0x18($sp)
/* EEDFF4 80240EF4 8C640018 */  lw        $a0, 0x18($v1)
/* EEDFF8 80240EF8 0C013431 */  jal       func_8004D0C4
/* EEDFFC 80240EFC 8E070038 */   lw       $a3, 0x38($s0)
/* EEE000 80240F00 1040000E */  beqz      $v0, .L80240F3C
/* EEE004 80240F04 00000000 */   nop
/* EEE008 80240F08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE00C 80240F0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* EEE010 80240F10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EEE014 80240F14 C4460000 */  lwc1      $f6, ($v0)
/* EEE018 80240F18 468031A0 */  cvt.s.w   $f6, $f6
/* EEE01C 80240F1C 44063000 */  mfc1      $a2, $f6
/* EEE020 80240F20 C4460008 */  lwc1      $f6, 8($v0)
/* EEE024 80240F24 468031A0 */  cvt.s.w   $f6, $f6
/* EEE028 80240F28 44073000 */  mfc1      $a3, $f6
/* EEE02C 80240F2C 0C00ABDC */  jal       fio_validate_header_checksums
/* EEE030 80240F30 00000000 */   nop
/* EEE034 80240F34 080903DB */  j         .L80240F6C
/* EEE038 80240F38 E600000C */   swc1     $f0, 0xc($s0)
.L80240F3C:
/* EEE03C 80240F3C 0C00AB3B */  jal       dead_rand_int
/* EEE040 80240F40 2404003C */   addiu    $a0, $zero, 0x3c
/* EEE044 80240F44 C60C000C */  lwc1      $f12, 0xc($s0)
/* EEE048 80240F48 44820000 */  mtc1      $v0, $f0
/* EEE04C 80240F4C 00000000 */  nop
/* EEE050 80240F50 46800020 */  cvt.s.w   $f0, $f0
/* EEE054 80240F54 46006300 */  add.s     $f12, $f12, $f0
/* EEE058 80240F58 3C0141F0 */  lui       $at, 0x41f0
/* EEE05C 80240F5C 44810000 */  mtc1      $at, $f0
/* EEE060 80240F60 0C00AB85 */  jal       dead_clamp_angle
/* EEE064 80240F64 46006301 */   sub.s    $f12, $f12, $f0
/* EEE068 80240F68 E600000C */  swc1      $f0, 0xc($s0)
.L80240F6C:
/* EEE06C 80240F6C 8E2200CC */  lw        $v0, 0xcc($s1)
/* EEE070 80240F70 8C420004 */  lw        $v0, 4($v0)
/* EEE074 80240F74 AE020028 */  sw        $v0, 0x28($s0)
/* EEE078 80240F78 AE600074 */  sw        $zero, 0x74($s3)
/* EEE07C 80240F7C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE080 80240F80 8C420014 */  lw        $v0, 0x14($v0)
/* EEE084 80240F84 04410004 */  bgez      $v0, .L80240F98
/* EEE088 80240F88 00000000 */   nop
/* EEE08C 80240F8C C6400000 */  lwc1      $f0, ($s2)
/* EEE090 80240F90 080903EE */  j         .L80240FB8
/* EEE094 80240F94 E6000018 */   swc1     $f0, 0x18($s0)
.L80240F98:
/* EEE098 80240F98 3C018024 */  lui       $at, %hi(D_80245450_EF2550)
/* EEE09C 80240F9C D4225450 */  ldc1      $f2, %lo(D_80245450_EF2550)($at)
/* EEE0A0 80240FA0 44820000 */  mtc1      $v0, $f0
/* EEE0A4 80240FA4 00000000 */  nop
/* EEE0A8 80240FA8 46800021 */  cvt.d.w   $f0, $f0
/* EEE0AC 80240FAC 46220003 */  div.d     $f0, $f0, $f2
/* EEE0B0 80240FB0 46200020 */  cvt.s.d   $f0, $f0
/* EEE0B4 80240FB4 E6000018 */  swc1      $f0, 0x18($s0)
.L80240FB8:
/* EEE0B8 80240FB8 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEE0BC 80240FBC 3C014059 */  lui       $at, 0x4059
/* EEE0C0 80240FC0 44811800 */  mtc1      $at, $f3
/* EEE0C4 80240FC4 44801000 */  mtc1      $zero, $f2
/* EEE0C8 80240FC8 46000021 */  cvt.d.s   $f0, $f0
/* EEE0CC 80240FCC 46220002 */  mul.d     $f0, $f0, $f2
/* EEE0D0 80240FD0 00000000 */  nop
/* EEE0D4 80240FD4 24020001 */  addiu     $v0, $zero, 1
/* EEE0D8 80240FD8 4620018D */  trunc.w.d $f6, $f0
/* EEE0DC 80240FDC E626007C */  swc1      $f6, 0x7c($s1)
/* EEE0E0 80240FE0 AE620070 */  sw        $v0, 0x70($s3)
/* EEE0E4 80240FE4 8FBF0030 */  lw        $ra, 0x30($sp)
/* EEE0E8 80240FE8 8FB3002C */  lw        $s3, 0x2c($sp)
/* EEE0EC 80240FEC 8FB20028 */  lw        $s2, 0x28($sp)
/* EEE0F0 80240FF0 8FB10024 */  lw        $s1, 0x24($sp)
/* EEE0F4 80240FF4 8FB00020 */  lw        $s0, 0x20($sp)
/* EEE0F8 80240FF8 03E00008 */  jr        $ra
/* EEE0FC 80240FFC 27BD0038 */   addiu    $sp, $sp, 0x38
