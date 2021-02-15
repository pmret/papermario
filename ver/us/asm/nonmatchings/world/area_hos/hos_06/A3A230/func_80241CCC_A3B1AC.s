.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CCC_A3B1AC
/* A3B1AC 80241CCC 27BDFF08 */  addiu     $sp, $sp, -0xf8
/* A3B1B0 80241CD0 AFB300B4 */  sw        $s3, 0xb4($sp)
/* A3B1B4 80241CD4 AFBF00C0 */  sw        $ra, 0xc0($sp)
/* A3B1B8 80241CD8 AFB500BC */  sw        $s5, 0xbc($sp)
/* A3B1BC 80241CDC AFB400B8 */  sw        $s4, 0xb8($sp)
/* A3B1C0 80241CE0 AFB200B0 */  sw        $s2, 0xb0($sp)
/* A3B1C4 80241CE4 AFB100AC */  sw        $s1, 0xac($sp)
/* A3B1C8 80241CE8 AFB000A8 */  sw        $s0, 0xa8($sp)
/* A3B1CC 80241CEC F7BE00F0 */  sdc1      $f30, 0xf0($sp)
/* A3B1D0 80241CF0 F7BC00E8 */  sdc1      $f28, 0xe8($sp)
/* A3B1D4 80241CF4 F7BA00E0 */  sdc1      $f26, 0xe0($sp)
/* A3B1D8 80241CF8 F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* A3B1DC 80241CFC F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* A3B1E0 80241D00 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* A3B1E4 80241D04 10A00011 */  beqz      $a1, .L80241D4C
/* A3B1E8 80241D08 0080982D */   daddu    $s3, $a0, $zero
/* A3B1EC 80241D0C 3C05F4AC */  lui       $a1, 0xf4ac
/* A3B1F0 80241D10 34A5D483 */  ori       $a1, $a1, 0xd483
/* A3B1F4 80241D14 240200B4 */  addiu     $v0, $zero, 0xb4
/* A3B1F8 80241D18 0C0B1EAF */  jal       get_variable
/* A3B1FC 80241D1C AE620070 */   sw       $v0, 0x70($s3)
/* A3B200 80241D20 0260202D */  daddu     $a0, $s3, $zero
/* A3B204 80241D24 3C05F4AC */  lui       $a1, 0xf4ac
/* A3B208 80241D28 34A5D484 */  ori       $a1, $a1, 0xd484
/* A3B20C 80241D2C 0C0B1EAF */  jal       get_variable
/* A3B210 80241D30 AE620074 */   sw       $v0, 0x74($s3)
/* A3B214 80241D34 0260202D */  daddu     $a0, $s3, $zero
/* A3B218 80241D38 3C05F4AC */  lui       $a1, 0xf4ac
/* A3B21C 80241D3C 34A5D485 */  ori       $a1, $a1, 0xd485
/* A3B220 80241D40 0C0B1EAF */  jal       get_variable
/* A3B224 80241D44 AE620078 */   sw       $v0, 0x78($s3)
/* A3B228 80241D48 AE62007C */  sw        $v0, 0x7c($s3)
.L80241D4C:
/* A3B22C 80241D4C 0000882D */  daddu     $s1, $zero, $zero
/* A3B230 80241D50 8E620074 */  lw        $v0, 0x74($s3)
/* A3B234 80241D54 3C014120 */  lui       $at, 0x4120
/* A3B238 80241D58 4481A000 */  mtc1      $at, $f20
/* A3B23C 80241D5C 27B00028 */  addiu     $s0, $sp, 0x28
/* A3B240 80241D60 AFA20018 */  sw        $v0, 0x18($sp)
/* A3B244 80241D64 8E620078 */  lw        $v0, 0x78($s3)
/* A3B248 80241D68 3C15800B */  lui       $s5, %hi(gCameras)
/* A3B24C 80241D6C 26B51D80 */  addiu     $s5, $s5, %lo(gCameras)
/* A3B250 80241D70 AFA2001C */  sw        $v0, 0x1c($sp)
/* A3B254 80241D74 8E62007C */  lw        $v0, 0x7c($s3)
/* A3B258 80241D78 AFA20020 */  sw        $v0, 0x20($sp)
/* A3B25C 80241D7C C66C0070 */  lwc1      $f12, 0x70($s3)
/* A3B260 80241D80 46806320 */  cvt.s.w   $f12, $f12
/* A3B264 80241D84 0C00A8BB */  jal       sin_deg
/* A3B268 80241D88 27B20068 */   addiu    $s2, $sp, 0x68
/* A3B26C 80241D8C 46140002 */  mul.s     $f0, $f0, $f20
/* A3B270 80241D90 00000000 */  nop
/* A3B274 80241D94 0220A02D */  daddu     $s4, $s1, $zero
/* A3B278 80241D98 C66C0070 */  lwc1      $f12, 0x70($s3)
/* A3B27C 80241D9C 46806320 */  cvt.s.w   $f12, $f12
/* A3B280 80241DA0 4480B000 */  mtc1      $zero, $f22
/* A3B284 80241DA4 3C013F80 */  lui       $at, 0x3f80
/* A3B288 80241DA8 4481D000 */  mtc1      $at, $f26
/* A3B28C 80241DAC 0C00A8BB */  jal       sin_deg
/* A3B290 80241DB0 46140780 */   add.s    $f30, $f0, $f20
/* A3B294 80241DB4 3C0141C8 */  lui       $at, 0x41c8
/* A3B298 80241DB8 44811000 */  mtc1      $at, $f2
/* A3B29C 80241DBC 8E630070 */  lw        $v1, 0x70($s3)
/* A3B2A0 80241DC0 46020002 */  mul.s     $f0, $f0, $f2
/* A3B2A4 80241DC4 00000000 */  nop
/* A3B2A8 80241DC8 00031080 */  sll       $v0, $v1, 2
/* A3B2AC 80241DCC 00431021 */  addu      $v0, $v0, $v1
/* A3B2B0 80241DD0 00021040 */  sll       $v0, $v0, 1
/* A3B2B4 80241DD4 4482C000 */  mtc1      $v0, $f24
/* A3B2B8 80241DD8 00000000 */  nop
/* A3B2BC 80241DDC 4680C620 */  cvt.s.w   $f24, $f24
/* A3B2C0 80241DE0 46140700 */  add.s     $f28, $f0, $f20
.L80241DE4:
/* A3B2C4 80241DE4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A3B2C8 80241DE8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A3B2CC 80241DEC 4406B000 */  mfc1      $a2, $f22
/* A3B2D0 80241DF0 00031080 */  sll       $v0, $v1, 2
/* A3B2D4 80241DF4 00431021 */  addu      $v0, $v0, $v1
/* A3B2D8 80241DF8 00021080 */  sll       $v0, $v0, 2
/* A3B2DC 80241DFC 00431023 */  subu      $v0, $v0, $v1
/* A3B2E0 80241E00 000218C0 */  sll       $v1, $v0, 3
/* A3B2E4 80241E04 00431021 */  addu      $v0, $v0, $v1
/* A3B2E8 80241E08 000210C0 */  sll       $v0, $v0, 3
/* A3B2EC 80241E0C 00551021 */  addu      $v0, $v0, $s5
/* A3B2F0 80241E10 C440006C */  lwc1      $f0, 0x6c($v0)
/* A3B2F4 80241E14 4407D000 */  mfc1      $a3, $f26
/* A3B2F8 80241E18 46000007 */  neg.s     $f0, $f0
/* A3B2FC 80241E1C 44050000 */  mfc1      $a1, $f0
/* A3B300 80241E20 0200202D */  daddu     $a0, $s0, $zero
/* A3B304 80241E24 0C019EC8 */  jal       guRotateF
/* A3B308 80241E28 E7B60010 */   swc1     $f22, 0x10($sp)
/* A3B30C 80241E2C 44942000 */  mtc1      $s4, $f4
/* A3B310 80241E30 00000000 */  nop
/* A3B314 80241E34 46802120 */  cvt.s.w   $f4, $f4
/* A3B318 80241E38 4406B000 */  mfc1      $a2, $f22
/* A3B31C 80241E3C 4407B000 */  mfc1      $a3, $f22
/* A3B320 80241E40 44052000 */  mfc1      $a1, $f4
/* A3B324 80241E44 0240202D */  daddu     $a0, $s2, $zero
/* A3B328 80241E48 0C019EC8 */  jal       guRotateF
/* A3B32C 80241E4C E7BA0010 */   swc1     $f26, 0x10($sp)
/* A3B330 80241E50 0240202D */  daddu     $a0, $s2, $zero
/* A3B334 80241E54 0200282D */  daddu     $a1, $s0, $zero
/* A3B338 80241E58 0C019D80 */  jal       guMtxCatF
/* A3B33C 80241E5C 0200302D */   daddu    $a2, $s0, $zero
/* A3B340 80241E60 0C00A8BB */  jal       sin_deg
/* A3B344 80241E64 4600C306 */   mov.s    $f12, $f24
/* A3B348 80241E68 4600F502 */  mul.s     $f20, $f30, $f0
/* A3B34C 80241E6C 00000000 */  nop
/* A3B350 80241E70 0C00A8D4 */  jal       cos_deg
/* A3B354 80241E74 4600C306 */   mov.s    $f12, $f24
/* A3B358 80241E78 4600E002 */  mul.s     $f0, $f28, $f0
/* A3B35C 80241E7C 00000000 */  nop
/* A3B360 80241E80 4407B000 */  mfc1      $a3, $f22
/* A3B364 80241E84 44060000 */  mfc1      $a2, $f0
/* A3B368 80241E88 4405A000 */  mfc1      $a1, $f20
/* A3B36C 80241E8C 0C019E40 */  jal       guTranslateF
/* A3B370 80241E90 0240202D */   daddu    $a0, $s2, $zero
/* A3B374 80241E94 0240202D */  daddu     $a0, $s2, $zero
/* A3B378 80241E98 0200282D */  daddu     $a1, $s0, $zero
/* A3B37C 80241E9C 0C019D80 */  jal       guMtxCatF
/* A3B380 80241EA0 0200302D */   daddu    $a2, $s0, $zero
/* A3B384 80241EA4 00111880 */  sll       $v1, $s1, 2
/* A3B388 80241EA8 27A40018 */  addiu     $a0, $sp, 0x18
/* A3B38C 80241EAC 00831821 */  addu      $v1, $a0, $v1
/* A3B390 80241EB0 8C620000 */  lw        $v0, ($v1)
/* A3B394 80241EB4 C7A00058 */  lwc1      $f0, 0x58($sp)
/* A3B398 80241EB8 8C42000C */  lw        $v0, 0xc($v0)
/* A3B39C 80241EBC E4400010 */  swc1      $f0, 0x10($v0)
/* A3B3A0 80241EC0 8C620000 */  lw        $v0, ($v1)
/* A3B3A4 80241EC4 C7A0005C */  lwc1      $f0, 0x5c($sp)
/* A3B3A8 80241EC8 8C42000C */  lw        $v0, 0xc($v0)
/* A3B3AC 80241ECC E4400014 */  swc1      $f0, 0x14($v0)
/* A3B3B0 80241ED0 8C620000 */  lw        $v0, ($v1)
/* A3B3B4 80241ED4 C7A00060 */  lwc1      $f0, 0x60($sp)
/* A3B3B8 80241ED8 8C42000C */  lw        $v0, 0xc($v0)
/* A3B3BC 80241EDC 26310001 */  addiu     $s1, $s1, 1
/* A3B3C0 80241EE0 E4400018 */  swc1      $f0, 0x18($v0)
/* A3B3C4 80241EE4 2A220003 */  slti      $v0, $s1, 3
/* A3B3C8 80241EE8 1440FFBE */  bnez      $v0, .L80241DE4
/* A3B3CC 80241EEC 26940078 */   addiu    $s4, $s4, 0x78
/* A3B3D0 80241EF0 8E620070 */  lw        $v0, 0x70($s3)
/* A3B3D4 80241EF4 2442FFFF */  addiu     $v0, $v0, -1
/* A3B3D8 80241EF8 AE620070 */  sw        $v0, 0x70($s3)
/* A3B3DC 80241EFC 28420010 */  slti      $v0, $v0, 0x10
/* A3B3E0 80241F00 1040000A */  beqz      $v0, .L80241F2C
/* A3B3E4 80241F04 00000000 */   nop
/* A3B3E8 80241F08 0000882D */  daddu     $s1, $zero, $zero
.L80241F0C:
/* A3B3EC 80241F0C 8C820000 */  lw        $v0, ($a0)
/* A3B3F0 80241F10 8C43000C */  lw        $v1, 0xc($v0)
/* A3B3F4 80241F14 8E620070 */  lw        $v0, 0x70($s3)
/* A3B3F8 80241F18 26310001 */  addiu     $s1, $s1, 1
/* A3B3FC 80241F1C AC62004C */  sw        $v0, 0x4c($v1)
/* A3B400 80241F20 2A220003 */  slti      $v0, $s1, 3
/* A3B404 80241F24 1440FFF9 */  bnez      $v0, .L80241F0C
/* A3B408 80241F28 24840004 */   addiu    $a0, $a0, 4
.L80241F2C:
/* A3B40C 80241F2C 8E620070 */  lw        $v0, 0x70($s3)
/* A3B410 80241F30 0441000A */  bgez      $v0, .L80241F5C
/* A3B414 80241F34 0000102D */   daddu    $v0, $zero, $zero
/* A3B418 80241F38 0000882D */  daddu     $s1, $zero, $zero
/* A3B41C 80241F3C 27B00018 */  addiu     $s0, $sp, 0x18
.L80241F40:
/* A3B420 80241F40 8E040000 */  lw        $a0, ($s0)
/* A3B424 80241F44 26100004 */  addiu     $s0, $s0, 4
/* A3B428 80241F48 0C016914 */  jal       remove_effect
/* A3B42C 80241F4C 26310001 */   addiu    $s1, $s1, 1
/* A3B430 80241F50 2A220003 */  slti      $v0, $s1, 3
/* A3B434 80241F54 1440FFFA */  bnez      $v0, .L80241F40
/* A3B438 80241F58 24020002 */   addiu    $v0, $zero, 2
.L80241F5C:
/* A3B43C 80241F5C 8FBF00C0 */  lw        $ra, 0xc0($sp)
/* A3B440 80241F60 8FB500BC */  lw        $s5, 0xbc($sp)
/* A3B444 80241F64 8FB400B8 */  lw        $s4, 0xb8($sp)
/* A3B448 80241F68 8FB300B4 */  lw        $s3, 0xb4($sp)
/* A3B44C 80241F6C 8FB200B0 */  lw        $s2, 0xb0($sp)
/* A3B450 80241F70 8FB100AC */  lw        $s1, 0xac($sp)
/* A3B454 80241F74 8FB000A8 */  lw        $s0, 0xa8($sp)
/* A3B458 80241F78 D7BE00F0 */  ldc1      $f30, 0xf0($sp)
/* A3B45C 80241F7C D7BC00E8 */  ldc1      $f28, 0xe8($sp)
/* A3B460 80241F80 D7BA00E0 */  ldc1      $f26, 0xe0($sp)
/* A3B464 80241F84 D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* A3B468 80241F88 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* A3B46C 80241F8C D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* A3B470 80241F90 03E00008 */  jr        $ra
/* A3B474 80241F94 27BD00F8 */   addiu    $sp, $sp, 0xf8
