.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_player_shadow
/* 7B074 800E1BC4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 7B078 800E1BC8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 7B07C 800E1BCC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 7B080 800E1BD0 AFBF0058 */  sw        $ra, 0x58($sp)
/* 7B084 800E1BD4 AFB30054 */  sw        $s3, 0x54($sp)
/* 7B088 800E1BD8 AFB20050 */  sw        $s2, 0x50($sp)
/* 7B08C 800E1BDC AFB1004C */  sw        $s1, 0x4c($sp)
/* 7B090 800E1BE0 AFB00048 */  sw        $s0, 0x48($sp)
/* 7B094 800E1BE4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 7B098 800E1BE8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 7B09C 800E1BEC 0C044181 */  jal       get_shadow_by_index
/* 7B0A0 800E1BF0 8C4400CC */   lw       $a0, 0xcc($v0)
/* 7B0A4 800E1BF4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 7B0A8 800E1BF8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 7B0AC 800E1BFC 0040802D */  daddu     $s0, $v0, $zero
/* 7B0B0 800E1C00 3C04800B */  lui       $a0, %hi(gCameras)
/* 7B0B4 800E1C04 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 7B0B8 800E1C08 44801000 */  mtc1      $zero, $f2
/* 7B0BC 800E1C0C C64400A8 */  lwc1      $f4, 0xa8($s2)
/* 7B0C0 800E1C10 3C0142B4 */  lui       $at, 0x42b4
/* 7B0C4 800E1C14 44810000 */  mtc1      $at, $f0
/* 7B0C8 800E1C18 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7B0CC 800E1C1C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7B0D0 800E1C20 46001206 */  mov.s     $f8, $f2
/* 7B0D4 800E1C24 00031080 */  sll       $v0, $v1, 2
/* 7B0D8 800E1C28 00431021 */  addu      $v0, $v0, $v1
/* 7B0DC 800E1C2C 00021080 */  sll       $v0, $v0, 2
/* 7B0E0 800E1C30 00431023 */  subu      $v0, $v0, $v1
/* 7B0E4 800E1C34 000218C0 */  sll       $v1, $v0, 3
/* 7B0E8 800E1C38 00431021 */  addu      $v0, $v0, $v1
/* 7B0EC 800E1C3C 000210C0 */  sll       $v0, $v0, 3
/* 7B0F0 800E1C40 00448821 */  addu      $s1, $v0, $a0
/* 7B0F4 800E1C44 4604003E */  c.le.s    $f0, $f4
/* 7B0F8 800E1C48 00000000 */  nop       
/* 7B0FC 800E1C4C 4500000A */  bc1f      .L800E1C78
/* 7B100 800E1C50 E7A80034 */   swc1     $f8, 0x34($sp)
/* 7B104 800E1C54 3C014387 */  lui       $at, 0x4387
/* 7B108 800E1C58 44810000 */  mtc1      $at, $f0
/* 7B10C 800E1C5C 00000000 */  nop       
/* 7B110 800E1C60 4600203C */  c.lt.s    $f4, $f0
/* 7B114 800E1C64 00000000 */  nop       
/* 7B118 800E1C68 45000003 */  bc1f      .L800E1C78
/* 7B11C 800E1C6C 00000000 */   nop      
/* 7B120 800E1C70 3C014334 */  lui       $at, 0x4334
/* 7B124 800E1C74 44814000 */  mtc1      $at, $f8
.L800E1C78:
/* 7B128 800E1C78 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7B12C 800E1C7C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7B130 800E1C80 C6420028 */  lwc1      $f2, 0x28($s2)
/* 7B134 800E1C84 3C014480 */  lui       $at, 0x4480
/* 7B138 800E1C88 44810000 */  mtc1      $at, $f0
/* 7B13C 800E1C8C 3C0142B4 */  lui       $at, 0x42b4
/* 7B140 800E1C90 44816000 */  mtc1      $at, $f12
/* 7B144 800E1C94 00031080 */  sll       $v0, $v1, 2
/* 7B148 800E1C98 00431021 */  addu      $v0, $v0, $v1
/* 7B14C 800E1C9C 00021080 */  sll       $v0, $v0, 2
/* 7B150 800E1CA0 00431023 */  subu      $v0, $v0, $v1
/* 7B154 800E1CA4 000218C0 */  sll       $v1, $v0, 3
/* 7B158 800E1CA8 00431021 */  addu      $v0, $v0, $v1
/* 7B15C 800E1CAC 000210C0 */  sll       $v0, $v0, 3
/* 7B160 800E1CB0 3C01800B */  lui       $at, 0x800b
/* 7B164 800E1CB4 00220821 */  addu      $at, $at, $v0
/* 7B168 800E1CB8 C4261DEC */  lwc1      $f6, 0x1dec($at)
/* 7B16C 800E1CBC E6020010 */  swc1      $f2, 0x10($s0)
/* 7B170 800E1CC0 C6440030 */  lwc1      $f4, 0x30($s2)
/* 7B174 800E1CC4 E6040018 */  swc1      $f4, 0x18($s0)
/* 7B178 800E1CC8 864200B0 */  lh        $v0, 0xb0($s2)
/* 7B17C 800E1CCC 27A60028 */  addiu     $a2, $sp, 0x28
/* 7B180 800E1CD0 E7A00034 */  swc1      $f0, 0x34($sp)
/* 7B184 800E1CD4 3C014060 */  lui       $at, 0x4060
/* 7B188 800E1CD8 44810000 */  mtc1      $at, $f0
/* 7B18C 800E1CDC 460C4301 */  sub.s     $f12, $f8, $f12
/* 7B190 800E1CE0 E7A20028 */  swc1      $f2, 0x28($sp)
/* 7B194 800E1CE4 44821000 */  mtc1      $v0, $f2
/* 7B198 800E1CE8 00000000 */  nop       
/* 7B19C 800E1CEC 468010A0 */  cvt.s.w   $f2, $f2
/* 7B1A0 800E1CF0 46001083 */  div.s     $f2, $f2, $f0
/* 7B1A4 800E1CF4 46066300 */  add.s     $f12, $f12, $f6
/* 7B1A8 800E1CF8 C640002C */  lwc1      $f0, 0x2c($s2)
/* 7B1AC 800E1CFC 864200B2 */  lh        $v0, 0xb2($s2)
/* 7B1B0 800E1D00 27A7002C */  addiu     $a3, $sp, 0x2c
/* 7B1B4 800E1D04 E7A40030 */  swc1      $f4, 0x30($sp)
/* 7B1B8 800E1D08 46020000 */  add.s     $f0, $f0, $f2
/* 7B1BC 800E1D0C 44827000 */  mtc1      $v0, $f14
/* 7B1C0 800E1D10 00000000 */  nop       
/* 7B1C4 800E1D14 468073A0 */  cvt.s.w   $f14, $f14
/* 7B1C8 800E1D18 27A20030 */  addiu     $v0, $sp, 0x30
/* 7B1CC 800E1D1C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 7B1D0 800E1D20 AFA20010 */  sw        $v0, 0x10($sp)
/* 7B1D4 800E1D24 27A20034 */  addiu     $v0, $sp, 0x34
/* 7B1D8 800E1D28 AFA20014 */  sw        $v0, 0x14($sp)
/* 7B1DC 800E1D2C 27A20038 */  addiu     $v0, $sp, 0x38
/* 7B1E0 800E1D30 AFA20018 */  sw        $v0, 0x18($sp)
/* 7B1E4 800E1D34 27A2003C */  addiu     $v0, $sp, 0x3c
/* 7B1E8 800E1D38 AFA2001C */  sw        $v0, 0x1c($sp)
/* 7B1EC 800E1D3C 27A20040 */  addiu     $v0, $sp, 0x40
/* 7B1F0 800E1D40 AFA20020 */  sw        $v0, 0x20($sp)
/* 7B1F4 800E1D44 27A20044 */  addiu     $v0, $sp, 0x44
/* 7B1F8 800E1D48 0C0377F4 */  jal       test_below_player
/* 7B1FC 800E1D4C AFA20024 */   sw       $v0, 0x24($sp)
/* 7B200 800E1D50 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 7B204 800E1D54 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 7B208 800E1D58 3C018016 */  lui       $at, 0x8016
/* 7B20C 800E1D5C A422A556 */  sh        $v0, -0x5aaa($at)
/* 7B210 800E1D60 E6000028 */  swc1      $f0, 0x28($s0)
/* 7B214 800E1D64 E6020030 */  swc1      $f2, 0x30($s0)
/* 7B218 800E1D68 C62C006C */  lwc1      $f12, 0x6c($s1)
/* 7B21C 800E1D6C 0C00A6C9 */  jal       clamp_angle
/* 7B220 800E1D70 46006307 */   neg.s    $f12, $f12
/* 7B224 800E1D74 C7A40038 */  lwc1      $f4, 0x38($sp)
/* 7B228 800E1D78 3C014334 */  lui       $at, 0x4334
/* 7B22C 800E1D7C 44813000 */  mtc1      $at, $f6
/* 7B230 800E1D80 00000000 */  nop       
/* 7B234 800E1D84 46062100 */  add.s     $f4, $f4, $f6
/* 7B238 800E1D88 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 7B23C 800E1D8C 4480B000 */  mtc1      $zero, $f22
/* 7B240 800E1D90 46061080 */  add.s     $f2, $f2, $f6
/* 7B244 800E1D94 E600002C */  swc1      $f0, 0x2c($s0)
/* 7B248 800E1D98 46162032 */  c.eq.s    $f4, $f22
/* 7B24C 800E1D9C E7A40038 */  swc1      $f4, 0x38($sp)
/* 7B250 800E1DA0 45000005 */  bc1f      .L800E1DB8
/* 7B254 800E1DA4 E7A2003C */   swc1     $f2, 0x3c($sp)
/* 7B258 800E1DA8 46161032 */  c.eq.s    $f2, $f22
/* 7B25C 800E1DAC 00000000 */  nop       
/* 7B260 800E1DB0 45010041 */  bc1t      .L800E1EB8
/* 7B264 800E1DB4 00000000 */   nop      
.L800E1DB8:
/* 7B268 800E1DB8 C7AC0028 */  lwc1      $f12, 0x28($sp)
/* 7B26C 800E1DBC C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 7B270 800E1DC0 8E460028 */  lw        $a2, 0x28($s2)
/* 7B274 800E1DC4 0C00A7B5 */  jal       dist2D
/* 7B278 800E1DC8 8E470030 */   lw       $a3, 0x30($s2)
/* 7B27C 800E1DCC C64C0028 */  lwc1      $f12, 0x28($s2)
/* 7B280 800E1DD0 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 7B284 800E1DD4 8FA60028 */  lw        $a2, 0x28($sp)
/* 7B288 800E1DD8 8FA70030 */  lw        $a3, 0x30($sp)
/* 7B28C 800E1DDC 4600028D */  trunc.w.s $f10, $f0
/* 7B290 800E1DE0 44135000 */  mfc1      $s3, $f10
/* 7B294 800E1DE4 0C00A720 */  jal       atan2
/* 7B298 800E1DE8 00000000 */   nop      
/* 7B29C 800E1DEC 0C00A788 */  jal       get_player_normal_yaw
/* 7B2A0 800E1DF0 46000506 */   mov.s    $f20, $f0
/* 7B2A4 800E1DF4 3C01C2B4 */  lui       $at, 0xc2b4
/* 7B2A8 800E1DF8 44816000 */  mtc1      $at, $f12
/* 7B2AC 800E1DFC 00000000 */  nop       
/* 7B2B0 800E1E00 46146301 */  sub.s     $f12, $f12, $f20
/* 7B2B4 800E1E04 0C00A6C9 */  jal       clamp_angle
/* 7B2B8 800E1E08 46006300 */   add.s    $f12, $f12, $f0
/* 7B2BC 800E1E0C 3C118007 */  lui       $s1, %hi(gGameStatusPtr)
/* 7B2C0 800E1E10 2631419C */  addiu     $s1, $s1, %lo(gGameStatusPtr)
/* 7B2C4 800E1E14 8E220000 */  lw        $v0, ($s1)
/* 7B2C8 800E1E18 C442012C */  lwc1      $f2, 0x12c($v0)
/* 7B2CC 800E1E1C 4600028D */  trunc.w.s $f10, $f0
/* 7B2D0 800E1E20 44025000 */  mfc1      $v0, $f10
/* 7B2D4 800E1E24 46161032 */  c.eq.s    $f2, $f22
/* 7B2D8 800E1E28 00000000 */  nop       
/* 7B2DC 800E1E2C 45010022 */  bc1t      .L800E1EB8
/* 7B2E0 800E1E30 00000000 */   nop      
/* 7B2E4 800E1E34 44826000 */  mtc1      $v0, $f12
/* 7B2E8 800E1E38 00000000 */  nop       
/* 7B2EC 800E1E3C 0C00A8BB */  jal       sin_deg
/* 7B2F0 800E1E40 46806320 */   cvt.s.w  $f12, $f12
/* 7B2F4 800E1E44 8E220000 */  lw        $v0, ($s1)
/* 7B2F8 800E1E48 C4440128 */  lwc1      $f4, 0x128($v0)
/* 7B2FC 800E1E4C 46042102 */  mul.s     $f4, $f4, $f4
/* 7B300 800E1E50 00000000 */  nop       
/* 7B304 800E1E54 C4420130 */  lwc1      $f2, 0x130($v0)
/* 7B308 800E1E58 46021082 */  mul.s     $f2, $f2, $f2
/* 7B30C 800E1E5C 00000000 */  nop       
/* 7B310 800E1E60 46022300 */  add.s     $f12, $f4, $f2
/* 7B314 800E1E64 46006084 */  sqrt.s    $f2, $f12
/* 7B318 800E1E68 46021032 */  c.eq.s    $f2, $f2
/* 7B31C 800E1E6C 00000000 */  nop       
/* 7B320 800E1E70 45010005 */  bc1t      .L800E1E88
/* 7B324 800E1E74 46000506 */   mov.s    $f20, $f0
/* 7B328 800E1E78 0C0187BC */  jal       sqrtf
/* 7B32C 800E1E7C 00000000 */   nop      
/* 7B330 800E1E80 46000086 */  mov.s     $f2, $f0
/* 7B334 800E1E84 8E220000 */  lw        $v0, ($s1)
.L800E1E88:
/* 7B338 800E1E88 C440012C */  lwc1      $f0, 0x12c($v0)
/* 7B33C 800E1E8C 46001003 */  div.s     $f0, $f2, $f0
/* 7B340 800E1E90 44931000 */  mtc1      $s3, $f2
/* 7B344 800E1E94 00000000 */  nop       
/* 7B348 800E1E98 468010A0 */  cvt.s.w   $f2, $f2
/* 7B34C 800E1E9C 46020002 */  mul.s     $f0, $f0, $f2
/* 7B350 800E1EA0 00000000 */  nop       
/* 7B354 800E1EA4 46140002 */  mul.s     $f0, $f0, $f20
/* 7B358 800E1EA8 00000000 */  nop       
/* 7B35C 800E1EAC C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 7B360 800E1EB0 46001081 */  sub.s     $f2, $f2, $f0
/* 7B364 800E1EB4 E7A2002C */  swc1      $f2, 0x2c($sp)
.L800E1EB8:
/* 7B368 800E1EB8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 7B36C 800E1EBC E6000014 */  swc1      $f0, 0x14($s0)
/* 7B370 800E1EC0 9242000E */  lbu       $v0, 0xe($s2)
/* 7B374 800E1EC4 3C013FE0 */  lui       $at, 0x3fe0
/* 7B378 800E1EC8 44811800 */  mtc1      $at, $f3
/* 7B37C 800E1ECC 44801000 */  mtc1      $zero, $f2
/* 7B380 800E1ED0 44820000 */  mtc1      $v0, $f0
/* 7B384 800E1ED4 00000000 */  nop       
/* 7B388 800E1ED8 46800021 */  cvt.d.w   $f0, $f0
/* 7B38C 800E1EDC 46220002 */  mul.d     $f0, $f0, $f2
/* 7B390 800E1EE0 00000000 */  nop       
/* 7B394 800E1EE4 3C0141E0 */  lui       $at, 0x41e0
/* 7B398 800E1EE8 44811800 */  mtc1      $at, $f3
/* 7B39C 800E1EEC 44801000 */  mtc1      $zero, $f2
/* 7B3A0 800E1EF0 00000000 */  nop       
/* 7B3A4 800E1EF4 4620103E */  c.le.d    $f2, $f0
/* 7B3A8 800E1EF8 00000000 */  nop       
/* 7B3AC 800E1EFC 45010005 */  bc1t      .L800E1F14
/* 7B3B0 800E1F00 26040005 */   addiu    $a0, $s0, 5
/* 7B3B4 800E1F04 4620028D */  trunc.w.d $f10, $f0
/* 7B3B8 800E1F08 44035000 */  mfc1      $v1, $f10
/* 7B3BC 800E1F0C 080387CC */  j         .L800E1F30
/* 7B3C0 800E1F10 A0830000 */   sb       $v1, ($a0)
.L800E1F14:
/* 7B3C4 800E1F14 46220001 */  sub.d     $f0, $f0, $f2
/* 7B3C8 800E1F18 3C028000 */  lui       $v0, 0x8000
/* 7B3CC 800E1F1C 4620028D */  trunc.w.d $f10, $f0
/* 7B3D0 800E1F20 44035000 */  mfc1      $v1, $f10
/* 7B3D4 800E1F24 00000000 */  nop       
/* 7B3D8 800E1F28 00621825 */  or        $v1, $v1, $v0
/* 7B3DC 800E1F2C A0830000 */  sb        $v1, ($a0)
.L800E1F30:
/* 7B3E0 800E1F30 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7B3E4 800E1F34 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7B3E8 800E1F38 9042007E */  lbu       $v0, 0x7e($v0)
/* 7B3EC 800E1F3C 30420001 */  andi      $v0, $v0, 1
/* 7B3F0 800E1F40 14400006 */  bnez      $v0, .L800E1F5C
/* 7B3F4 800E1F44 00000000 */   nop      
/* 7B3F8 800E1F48 8FA50034 */  lw        $a1, 0x34($sp)
/* 7B3FC 800E1F4C 0C044A17 */  jal       set_standard_shadow_scale
/* 7B400 800E1F50 0200202D */   daddu    $a0, $s0, $zero
/* 7B404 800E1F54 080387DA */  j         .L800E1F68
/* 7B408 800E1F58 00000000 */   nop      
.L800E1F5C:
/* 7B40C 800E1F5C 8FA50034 */  lw        $a1, 0x34($sp)
/* 7B410 800E1F60 0C044A75 */  jal       set_peach_shadow_scale
/* 7B414 800E1F64 0200202D */   daddu    $a0, $s0, $zero
.L800E1F68:
/* 7B418 800E1F68 8FBF0058 */  lw        $ra, 0x58($sp)
/* 7B41C 800E1F6C 8FB30054 */  lw        $s3, 0x54($sp)
/* 7B420 800E1F70 8FB20050 */  lw        $s2, 0x50($sp)
/* 7B424 800E1F74 8FB1004C */  lw        $s1, 0x4c($sp)
/* 7B428 800E1F78 8FB00048 */  lw        $s0, 0x48($sp)
/* 7B42C 800E1F7C D7B60068 */  ldc1      $f22, 0x68($sp)
/* 7B430 800E1F80 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 7B434 800E1F84 03E00008 */  jr        $ra
/* 7B438 800E1F88 27BD0070 */   addiu    $sp, $sp, 0x70
/* 7B43C 800E1F8C 00000000 */  nop       
