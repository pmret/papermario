.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80251430_D4BA00
.double 0.1

glabel D_80251438_D4BA08
.double 0.2, 6.092491109832673e+247, 0.0

.section .text

glabel func_80241DAC_D3C37C
/* D3C37C 80241DAC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D3C380 80241DB0 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D3C384 80241DB4 4480E000 */  mtc1      $zero, $f28
/* D3C388 80241DB8 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D3C38C 80241DBC 3C018025 */  lui       $at, %hi(D_80251430_D4BA00)
/* D3C390 80241DC0 D43A1430 */  ldc1      $f26, %lo(D_80251430_D4BA00)($at)
/* D3C394 80241DC4 AFB1001C */  sw        $s1, 0x1c($sp)
/* D3C398 80241DC8 0000882D */  daddu     $s1, $zero, $zero
/* D3C39C 80241DCC AFB20020 */  sw        $s2, 0x20($sp)
/* D3C3A0 80241DD0 0220902D */  daddu     $s2, $s1, $zero
/* D3C3A4 80241DD4 AFBF0024 */  sw        $ra, 0x24($sp)
/* D3C3A8 80241DD8 AFB00018 */  sw        $s0, 0x18($sp)
/* D3C3AC 80241DDC F7B80038 */  sdc1      $f24, 0x38($sp)
/* D3C3B0 80241DE0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D3C3B4 80241DE4 F7B40028 */  sdc1      $f20, 0x28($sp)
.L80241DE8:
/* D3C3B8 80241DE8 3C022AAA */  lui       $v0, 0x2aaa
/* D3C3BC 80241DEC 3442AAAB */  ori       $v0, $v0, 0xaaab
/* D3C3C0 80241DF0 02220018 */  mult      $s1, $v0
/* D3C3C4 80241DF4 001127C3 */  sra       $a0, $s1, 0x1f
/* D3C3C8 80241DF8 00004010 */  mfhi      $t0
/* D3C3CC 80241DFC 01042023 */  subu      $a0, $t0, $a0
/* D3C3D0 80241E00 00041840 */  sll       $v1, $a0, 1
/* D3C3D4 80241E04 00641821 */  addu      $v1, $v1, $a0
/* D3C3D8 80241E08 00031840 */  sll       $v1, $v1, 1
/* D3C3DC 80241E0C 02231823 */  subu      $v1, $s1, $v1
/* D3C3E0 80241E10 00031080 */  sll       $v0, $v1, 2
/* D3C3E4 80241E14 00431021 */  addu      $v0, $v0, $v1
/* D3C3E8 80241E18 000210C0 */  sll       $v0, $v0, 3
/* D3C3EC 80241E1C 2442FF9C */  addiu     $v0, $v0, -0x64
/* D3C3F0 80241E20 4482C000 */  mtc1      $v0, $f24
/* D3C3F4 80241E24 00000000 */  nop
/* D3C3F8 80241E28 4680C620 */  cvt.s.w   $f24, $f24
/* D3C3FC 80241E2C 4600C1A1 */  cvt.d.s   $f6, $f24
/* D3C400 80241E30 463A3182 */  mul.d     $f6, $f6, $f26
/* D3C404 80241E34 00000000 */  nop
/* D3C408 80241E38 00041080 */  sll       $v0, $a0, 2
/* D3C40C 80241E3C 00441021 */  addu      $v0, $v0, $a0
/* D3C410 80241E40 000210C0 */  sll       $v0, $v0, 3
/* D3C414 80241E44 2442FF9C */  addiu     $v0, $v0, -0x64
/* D3C418 80241E48 4482B000 */  mtc1      $v0, $f22
/* D3C41C 80241E4C 00000000 */  nop
/* D3C420 80241E50 4680B5A0 */  cvt.s.w   $f22, $f22
/* D3C424 80241E54 4600B121 */  cvt.d.s   $f4, $f22
/* D3C428 80241E58 463A2102 */  mul.d     $f4, $f4, $f26
/* D3C42C 80241E5C 00000000 */  nop
/* D3C430 80241E60 3C013FF0 */  lui       $at, 0x3ff0
/* D3C434 80241E64 44811800 */  mtc1      $at, $f3
/* D3C438 80241E68 44801000 */  mtc1      $zero, $f2
/* D3C43C 80241E6C 32220003 */  andi      $v0, $s1, 3
/* D3C440 80241E70 44820000 */  mtc1      $v0, $f0
/* D3C444 80241E74 00000000 */  nop
/* D3C448 80241E78 46800021 */  cvt.d.w   $f0, $f0
/* D3C44C 80241E7C 46220000 */  add.d     $f0, $f0, $f2
/* D3C450 80241E80 4480A000 */  mtc1      $zero, $f20
/* D3C454 80241E84 3C06C120 */  lui       $a2, 0xc120
/* D3C458 80241E88 46200000 */  add.d     $f0, $f0, $f0
/* D3C45C 80241E8C 32240001 */  andi      $a0, $s1, 1
/* D3C460 80241E90 00021080 */  sll       $v0, $v0, 2
/* D3C464 80241E94 4614C080 */  add.s     $f2, $f24, $f20
/* D3C468 80241E98 46200020 */  cvt.s.d   $f0, $f0
/* D3C46C 80241E9C E7A00010 */  swc1      $f0, 0x10($sp)
/* D3C470 80241EA0 3C01437A */  lui       $at, 0x437a
/* D3C474 80241EA4 44810000 */  mtc1      $at, $f0
/* D3C478 80241EA8 2442001E */  addiu     $v0, $v0, 0x1e
/* D3C47C 80241EAC AFA20014 */  sw        $v0, 0x14($sp)
/* D3C480 80241EB0 4600B000 */  add.s     $f0, $f22, $f0
/* D3C484 80241EB4 44051000 */  mfc1      $a1, $f2
/* D3C488 80241EB8 46203620 */  cvt.s.d   $f24, $f6
/* D3C48C 80241EBC 44070000 */  mfc1      $a3, $f0
/* D3C490 80241EC0 0C01C994 */  jal       playFX_7A
/* D3C494 80241EC4 462025A0 */   cvt.s.d  $f22, $f4
/* D3C498 80241EC8 0040802D */  daddu     $s0, $v0, $zero
/* D3C49C 80241ECC 8E02000C */  lw        $v0, 0xc($s0)
/* D3C4A0 80241ED0 2404000A */  addiu     $a0, $zero, 0xa
/* D3C4A4 80241ED4 0C00A67F */  jal       rand_int
/* D3C4A8 80241ED8 E45C0044 */   swc1     $f28, 0x44($v0)
/* D3C4AC 80241EDC 3C018025 */  lui       $at, %hi(D_80251438_D4BA08)
/* D3C4B0 80241EE0 D4221438 */  ldc1      $f2, %lo(D_80251438_D4BA08)($at)
/* D3C4B4 80241EE4 44820000 */  mtc1      $v0, $f0
/* D3C4B8 80241EE8 00000000 */  nop
/* D3C4BC 80241EEC 46800021 */  cvt.d.w   $f0, $f0
/* D3C4C0 80241EF0 46220002 */  mul.d     $f0, $f0, $f2
/* D3C4C4 80241EF4 00000000 */  nop
/* D3C4C8 80241EF8 2404000A */  addiu     $a0, $zero, 0xa
/* D3C4CC 80241EFC 463A0000 */  add.d     $f0, $f0, $f26
/* D3C4D0 80241F00 3C014080 */  lui       $at, 0x4080
/* D3C4D4 80241F04 4481A000 */  mtc1      $at, $f20
/* D3C4D8 80241F08 8E02000C */  lw        $v0, 0xc($s0)
/* D3C4DC 80241F0C 46200020 */  cvt.s.d   $f0, $f0
/* D3C4E0 80241F10 E4400048 */  swc1      $f0, 0x48($v0)
/* D3C4E4 80241F14 8E02000C */  lw        $v0, 0xc($s0)
/* D3C4E8 80241F18 44920000 */  mtc1      $s2, $f0
/* D3C4EC 80241F1C 00000000 */  nop
/* D3C4F0 80241F20 46800020 */  cvt.s.w   $f0, $f0
/* D3C4F4 80241F24 0C00A67F */  jal       rand_int
/* D3C4F8 80241F28 E440003C */   swc1     $f0, 0x3c($v0)
/* D3C4FC 80241F2C 2442FFFB */  addiu     $v0, $v0, -5
/* D3C500 80241F30 8E03000C */  lw        $v1, 0xc($s0)
/* D3C504 80241F34 44820000 */  mtc1      $v0, $f0
/* D3C508 80241F38 00000000 */  nop
/* D3C50C 80241F3C 46800020 */  cvt.s.w   $f0, $f0
/* D3C510 80241F40 E4600040 */  swc1      $f0, 0x40($v1)
/* D3C514 80241F44 8E02000C */  lw        $v0, 0xc($s0)
/* D3C518 80241F48 3C01BDCC */  lui       $at, 0xbdcc
/* D3C51C 80241F4C 3421CCCD */  ori       $at, $at, 0xcccd
/* D3C520 80241F50 44810000 */  mtc1      $at, $f0
/* D3C524 80241F54 E458004C */  swc1      $f24, 0x4c($v0)
/* D3C528 80241F58 8E02000C */  lw        $v0, 0xc($s0)
/* D3C52C 80241F5C E4540050 */  swc1      $f20, 0x50($v0)
/* D3C530 80241F60 8E02000C */  lw        $v0, 0xc($s0)
/* D3C534 80241F64 26310001 */  addiu     $s1, $s1, 1
/* D3C538 80241F68 E4560054 */  swc1      $f22, 0x54($v0)
/* D3C53C 80241F6C 8E02000C */  lw        $v0, 0xc($s0)
/* D3C540 80241F70 E4400058 */  swc1      $f0, 0x58($v0)
/* D3C544 80241F74 2A220018 */  slti      $v0, $s1, 0x18
/* D3C548 80241F78 1440FF9B */  bnez      $v0, .L80241DE8
/* D3C54C 80241F7C 26520023 */   addiu    $s2, $s2, 0x23
/* D3C550 80241F80 8FBF0024 */  lw        $ra, 0x24($sp)
/* D3C554 80241F84 8FB20020 */  lw        $s2, 0x20($sp)
/* D3C558 80241F88 8FB1001C */  lw        $s1, 0x1c($sp)
/* D3C55C 80241F8C 8FB00018 */  lw        $s0, 0x18($sp)
/* D3C560 80241F90 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D3C564 80241F94 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D3C568 80241F98 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D3C56C 80241F9C D7B60030 */  ldc1      $f22, 0x30($sp)
/* D3C570 80241FA0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D3C574 80241FA4 24020002 */  addiu     $v0, $zero, 2
/* D3C578 80241FA8 03E00008 */  jr        $ra
/* D3C57C 80241FAC 27BD0050 */   addiu    $sp, $sp, 0x50
