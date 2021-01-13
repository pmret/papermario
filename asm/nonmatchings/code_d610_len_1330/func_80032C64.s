.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80032C64
/* E064 80032C64 27BDFF68 */  addiu     $sp, $sp, -0x98
/* E068 80032C68 AFB10054 */  sw        $s1, 0x54($sp)
/* E06C 80032C6C 0080882D */  daddu     $s1, $a0, $zero
/* E070 80032C70 AFBF0068 */  sw        $ra, 0x68($sp)
/* E074 80032C74 AFB50064 */  sw        $s5, 0x64($sp)
/* E078 80032C78 AFB40060 */  sw        $s4, 0x60($sp)
/* E07C 80032C7C AFB3005C */  sw        $s3, 0x5c($sp)
/* E080 80032C80 AFB20058 */  sw        $s2, 0x58($sp)
/* E084 80032C84 AFB00050 */  sw        $s0, 0x50($sp)
/* E088 80032C88 F7BC0090 */  sdc1      $f28, 0x90($sp)
/* E08C 80032C8C F7BA0088 */  sdc1      $f26, 0x88($sp)
/* E090 80032C90 F7B80080 */  sdc1      $f24, 0x80($sp)
/* E094 80032C94 F7B60078 */  sdc1      $f22, 0x78($sp)
/* E098 80032C98 F7B40070 */  sdc1      $f20, 0x70($sp)
/* E09C 80032C9C C6200084 */  lwc1      $f0, 0x84($s1)
/* E0A0 80032CA0 3C014334 */  lui       $at, 0x4334
/* E0A4 80032CA4 44811000 */  mtc1      $at, $f2
/* E0A8 80032CA8 3C014049 */  lui       $at, 0x4049
/* E0AC 80032CAC 34210FD8 */  ori       $at, $at, 0xfd8
/* E0B0 80032CB0 44812000 */  mtc1      $at, $f4
/* E0B4 80032CB4 46020003 */  div.s     $f0, $f0, $f2
/* E0B8 80032CB8 46040502 */  mul.s     $f20, $f0, $f4
/* E0BC 80032CBC 00000000 */  nop
/* E0C0 80032CC0 0000902D */  daddu     $s2, $zero, $zero
/* E0C4 80032CC4 C63A050C */  lwc1      $f26, 0x50c($s1)
/* E0C8 80032CC8 0C00A874 */  jal       cos_rad
/* E0CC 80032CCC 4600A306 */   mov.s    $f12, $f20
/* E0D0 80032CD0 0C00A85B */  jal       sin_rad
/* E0D4 80032CD4 4600A306 */   mov.s    $f12, $f20
/* E0D8 80032CD8 C6200064 */  lwc1      $f0, 0x64($s1)
/* E0DC 80032CDC 3C014120 */  lui       $at, 0x4120
/* E0E0 80032CE0 44817000 */  mtc1      $at, $f14
/* E0E4 80032CE4 C62C0060 */  lwc1      $f12, 0x60($s1)
/* E0E8 80032CE8 460E0380 */  add.s     $f14, $f0, $f14
/* E0EC 80032CEC 8E260068 */  lw        $a2, 0x68($s1)
/* E0F0 80032CF0 0C00C884 */  jal       func_80032210
/* E0F4 80032CF4 0240382D */   daddu    $a3, $s2, $zero
/* E0F8 80032CF8 0040802D */  daddu     $s0, $v0, $zero
/* E0FC 80032CFC 120000A1 */  beqz      $s0, .L80032F84
/* E100 80032D00 0200982D */   daddu    $s3, $s0, $zero
/* E104 80032D04 8E030000 */  lw        $v1, ($s0)
/* E108 80032D08 24020002 */  addiu     $v0, $zero, 2
/* E10C 80032D0C 1062000A */  beq       $v1, $v0, .L80032D38
/* E110 80032D10 24020005 */   addiu    $v0, $zero, 5
/* E114 80032D14 10620008 */  beq       $v1, $v0, .L80032D38
/* E118 80032D18 00000000 */   nop
/* E11C 80032D1C 8E250060 */  lw        $a1, 0x60($s1)
/* E120 80032D20 8E260068 */  lw        $a2, 0x68($s1)
/* E124 80032D24 0C00CA29 */  jal       func_800328A4
/* E128 80032D28 0200202D */   daddu    $a0, $s0, $zero
/* E12C 80032D2C 0040902D */  daddu     $s2, $v0, $zero
/* E130 80032D30 12400094 */  beqz      $s2, .L80032F84
/* E134 80032D34 00000000 */   nop
.L80032D38:
/* E138 80032D38 8E220530 */  lw        $v0, 0x530($s1)
/* E13C 80032D3C 10400049 */  beqz      $v0, .L80032E64
/* E140 80032D40 00000000 */   nop
/* E144 80032D44 263000D4 */  addiu     $s0, $s1, 0xd4
/* E148 80032D48 0200202D */  daddu     $a0, $s0, $zero
/* E14C 80032D4C 8627000A */  lh        $a3, 0xa($s1)
/* E150 80032D50 86220012 */  lh        $v0, 0x12($s1)
/* E154 80032D54 8623000C */  lh        $v1, 0xc($s1)
/* E158 80032D58 3C013F80 */  lui       $at, 0x3f80
/* E15C 80032D5C 4481A000 */  mtc1      $at, $f20
/* E160 80032D60 44820000 */  mtc1      $v0, $f0
/* E164 80032D64 00000000 */  nop
/* E168 80032D68 46800020 */  cvt.s.w   $f0, $f0
/* E16C 80032D6C E7A00010 */  swc1      $f0, 0x10($sp)
/* E170 80032D70 86220014 */  lh        $v0, 0x14($s1)
/* E174 80032D74 44871000 */  mtc1      $a3, $f2
/* E178 80032D78 00000000 */  nop
/* E17C 80032D7C 468010A0 */  cvt.s.w   $f2, $f2
/* E180 80032D80 E7B40018 */  swc1      $f20, 0x18($sp)
/* E184 80032D84 44820000 */  mtc1      $v0, $f0
/* E188 80032D88 00000000 */  nop
/* E18C 80032D8C 46800020 */  cvt.s.w   $f0, $f0
/* E190 80032D90 E7A00014 */  swc1      $f0, 0x14($sp)
/* E194 80032D94 44830000 */  mtc1      $v1, $f0
/* E198 80032D98 00000000 */  nop
/* E19C 80032D9C 46800020 */  cvt.s.w   $f0, $f0
/* E1A0 80032DA0 46001083 */  div.s     $f2, $f2, $f0
/* E1A4 80032DA4 8E260018 */  lw        $a2, 0x18($s1)
/* E1A8 80032DA8 44071000 */  mfc1      $a3, $f2
/* E1AC 80032DAC 0C018EE4 */  jal       guPerspectiveF
/* E1B0 80032DB0 26250038 */   addiu    $a1, $s1, 0x38
/* E1B4 80032DB4 26240114 */  addiu     $a0, $s1, 0x114
/* E1B8 80032DB8 0200282D */  daddu     $a1, $s0, $zero
/* E1BC 80032DBC 0C019D80 */  jal       guMtxCatF
/* E1C0 80032DC0 0200302D */   daddu    $a2, $s0, $zero
/* E1C4 80032DC4 27A20030 */  addiu     $v0, $sp, 0x30
/* E1C8 80032DC8 AFA20014 */  sw        $v0, 0x14($sp)
/* E1CC 80032DCC 27A20034 */  addiu     $v0, $sp, 0x34
/* E1D0 80032DD0 AFA20018 */  sw        $v0, 0x18($sp)
/* E1D4 80032DD4 27A20038 */  addiu     $v0, $sp, 0x38
/* E1D8 80032DD8 AFA2001C */  sw        $v0, 0x1c($sp)
/* E1DC 80032DDC 27A2003C */  addiu     $v0, $sp, 0x3c
/* E1E0 80032DE0 E7B40010 */  swc1      $f20, 0x10($sp)
/* E1E4 80032DE4 AFA20020 */  sw        $v0, 0x20($sp)
/* E1E8 80032DE8 8E250060 */  lw        $a1, 0x60($s1)
/* E1EC 80032DEC 8E260064 */  lw        $a2, 0x64($s1)
/* E1F0 80032DF0 8E270068 */  lw        $a3, 0x68($s1)
/* E1F4 80032DF4 0C00A588 */  jal       transform_point
/* E1F8 80032DF8 0200202D */   daddu    $a0, $s0, $zero
/* E1FC 80032DFC C7A0003C */  lwc1      $f0, 0x3c($sp)
/* E200 80032E00 44802000 */  mtc1      $zero, $f4
/* E204 80032E04 00000000 */  nop
/* E208 80032E08 46040032 */  c.eq.s    $f0, $f4
/* E20C 80032E0C 00000000 */  nop
/* E210 80032E10 45030001 */  bc1tl     .L80032E18
/* E214 80032E14 E7B4003C */   swc1     $f20, 0x3c($sp)
.L80032E18:
/* E218 80032E18 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* E21C 80032E1C C7A20030 */  lwc1      $f2, 0x30($sp)
/* E220 80032E20 4600A003 */  div.s     $f0, $f20, $f0
/* E224 80032E24 46001082 */  mul.s     $f2, $f2, $f0
/* E228 80032E28 00000000 */  nop
/* E22C 80032E2C 2623052C */  addiu     $v1, $s1, 0x52c
/* E230 80032E30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* E234 80032E34 4602203C */  c.lt.s    $f4, $f2
/* E238 80032E38 E7A20030 */  swc1      $f2, 0x30($sp)
/* E23C 80032E3C 45010006 */  bc1t      .L80032E58
/* E240 80032E40 24020001 */   addiu    $v0, $zero, 1
/* E244 80032E44 4604103C */  c.lt.s    $f2, $f4
/* E248 80032E48 00000000 */  nop
/* E24C 80032E4C 45000002 */  bc1f      .L80032E58
/* E250 80032E50 0000102D */   daddu    $v0, $zero, $zero
/* E254 80032E54 2402FFFF */  addiu     $v0, $zero, -1
.L80032E58:
/* E258 80032E58 AC620000 */  sw        $v0, ($v1)
/* E25C 80032E5C 0800CBC9 */  j         .L80032F24
/* E260 80032E60 AE200530 */   sw       $zero, 0x530($s1)
.L80032E64:
/* E264 80032E64 8E220534 */  lw        $v0, 0x534($s1)
/* E268 80032E68 10400011 */  beqz      $v0, .L80032EB0
/* E26C 80032E6C 00000000 */   nop
/* E270 80032E70 8C430000 */  lw        $v1, ($v0)
/* E274 80032E74 24020002 */  addiu     $v0, $zero, 2
/* E278 80032E78 1062002A */  beq       $v1, $v0, .L80032F24
/* E27C 80032E7C 24020005 */   addiu    $v0, $zero, 5
/* E280 80032E80 10620028 */  beq       $v1, $v0, .L80032F24
/* E284 80032E84 00000000 */   nop
/* E288 80032E88 8E250524 */  lw        $a1, 0x524($s1)
/* E28C 80032E8C 8E260528 */  lw        $a2, 0x528($s1)
/* E290 80032E90 0C00CA29 */  jal       func_800328A4
/* E294 80032E94 0200202D */   daddu    $a0, $s0, $zero
/* E298 80032E98 14400022 */  bnez      $v0, .L80032F24
/* E29C 80032E9C 00000000 */   nop
/* E2A0 80032EA0 12400003 */  beqz      $s2, .L80032EB0
/* E2A4 80032EA4 00000000 */   nop
/* E2A8 80032EA8 0800CBC9 */  j         .L80032F24
/* E2AC 80032EAC AE32052C */   sw       $s2, 0x52c($s1)
.L80032EB0:
/* E2B0 80032EB0 C6380060 */  lwc1      $f24, 0x60($s1)
/* E2B4 80032EB4 C6200524 */  lwc1      $f0, 0x524($s1)
/* E2B8 80032EB8 C6360068 */  lwc1      $f22, 0x68($s1)
/* E2BC 80032EBC 4600C601 */  sub.s     $f24, $f24, $f0
/* E2C0 80032EC0 C6200528 */  lwc1      $f0, 0x528($s1)
/* E2C4 80032EC4 C62C006C */  lwc1      $f12, 0x6c($s1)
/* E2C8 80032EC8 0C00A8D4 */  jal       cos_deg
/* E2CC 80032ECC 4600B581 */   sub.s    $f22, $f22, $f0
/* E2D0 80032ED0 C62C006C */  lwc1      $f12, 0x6c($s1)
/* E2D4 80032ED4 0C00A8BB */  jal       sin_deg
/* E2D8 80032ED8 46000507 */   neg.s    $f20, $f0
/* E2DC 80032EDC 4614C602 */  mul.s     $f24, $f24, $f20
/* E2E0 80032EE0 00000000 */  nop
/* E2E4 80032EE4 46000007 */  neg.s     $f0, $f0
/* E2E8 80032EE8 4600B582 */  mul.s     $f22, $f22, $f0
/* E2EC 80032EEC 00000000 */  nop
/* E2F0 80032EF0 4616C600 */  add.s     $f24, $f24, $f22
/* E2F4 80032EF4 44800000 */  mtc1      $zero, $f0
/* E2F8 80032EF8 00000000 */  nop
/* E2FC 80032EFC 4618003C */  c.lt.s    $f0, $f24
/* E300 80032F00 00000000 */  nop
/* E304 80032F04 45010006 */  bc1t      .L80032F20
/* E308 80032F08 2402FFFF */   addiu    $v0, $zero, -1
/* E30C 80032F0C 4600C03C */  c.lt.s    $f24, $f0
/* E310 80032F10 00000000 */  nop
/* E314 80032F14 45010002 */  bc1t      .L80032F20
/* E318 80032F18 24020001 */   addiu    $v0, $zero, 1
/* E31C 80032F1C 0000102D */  daddu     $v0, $zero, $zero
.L80032F20:
/* E320 80032F20 AE22052C */  sw        $v0, 0x52c($s1)
.L80032F24:
/* E324 80032F24 44800000 */  mtc1      $zero, $f0
/* E328 80032F28 00000000 */  nop
/* E32C 80032F2C 461A003C */  c.lt.s    $f0, $f26
/* E330 80032F30 00000000 */  nop
/* E334 80032F34 45000004 */  bc1f      .L80032F48
/* E338 80032F38 00000000 */   nop
/* E33C 80032F3C 8E22052C */  lw        $v0, 0x52c($s1)
/* E340 80032F40 5C400009 */  bgtzl     $v0, .L80032F68
/* E344 80032F44 AE200514 */   sw       $zero, 0x514($s1)
.L80032F48:
/* E348 80032F48 4600D03C */  c.lt.s    $f26, $f0
/* E34C 80032F4C 00000000 */  nop
/* E350 80032F50 45000006 */  bc1f      .L80032F6C
/* E354 80032F54 00000000 */   nop
/* E358 80032F58 8E22052C */  lw        $v0, 0x52c($s1)
/* E35C 80032F5C 04410003 */  bgez      $v0, .L80032F6C
/* E360 80032F60 00000000 */   nop
/* E364 80032F64 AE200514 */  sw        $zero, 0x514($s1)
.L80032F68:
/* E368 80032F68 AE20050C */  sw        $zero, 0x50c($s1)
.L80032F6C:
/* E36C 80032F6C C6200060 */  lwc1      $f0, 0x60($s1)
/* E370 80032F70 C6220068 */  lwc1      $f2, 0x68($s1)
/* E374 80032F74 AE330534 */  sw        $s3, 0x534($s1)
/* E378 80032F78 E6200524 */  swc1      $f0, 0x524($s1)
/* E37C 80032F7C 0800CCD7 */  j         .L8003335C
/* E380 80032F80 E6220528 */   swc1     $f2, 0x528($s1)
.L80032F84:
/* E384 80032F84 C6200060 */  lwc1      $f0, 0x60($s1)
/* E388 80032F88 C6220068 */  lwc1      $f2, 0x68($s1)
/* E38C 80032F8C 4600A306 */  mov.s     $f12, $f20
/* E390 80032F90 AE20052C */  sw        $zero, 0x52c($s1)
/* E394 80032F94 AE330534 */  sw        $s3, 0x534($s1)
/* E398 80032F98 E6200524 */  swc1      $f0, 0x524($s1)
/* E39C 80032F9C 0C00A874 */  jal       cos_rad
/* E3A0 80032FA0 E6220528 */   swc1     $f2, 0x528($s1)
/* E3A4 80032FA4 4600D002 */  mul.s     $f0, $f26, $f0
/* E3A8 80032FA8 00000000 */  nop
/* E3AC 80032FAC C6220060 */  lwc1      $f2, 0x60($s1)
/* E3B0 80032FB0 46001700 */  add.s     $f28, $f2, $f0
/* E3B4 80032FB4 0C00A85B */  jal       sin_rad
/* E3B8 80032FB8 4600A306 */   mov.s    $f12, $f20
/* E3BC 80032FBC 4600D002 */  mul.s     $f0, $f26, $f0
/* E3C0 80032FC0 00000000 */  nop
/* E3C4 80032FC4 C6220068 */  lwc1      $f2, 0x68($s1)
/* E3C8 80032FC8 3C014120 */  lui       $at, 0x4120
/* E3CC 80032FCC 44817000 */  mtc1      $at, $f14
/* E3D0 80032FD0 46001680 */  add.s     $f26, $f2, $f0
/* E3D4 80032FD4 C6200064 */  lwc1      $f0, 0x64($s1)
/* E3D8 80032FD8 27A70040 */  addiu     $a3, $sp, 0x40
/* E3DC 80032FDC 460E0380 */  add.s     $f14, $f0, $f14
/* E3E0 80032FE0 4406D000 */  mfc1      $a2, $f26
/* E3E4 80032FE4 0C00C884 */  jal       func_80032210
/* E3E8 80032FE8 4600E306 */   mov.s    $f12, $f28
/* E3EC 80032FEC 0040802D */  daddu     $s0, $v0, $zero
/* E3F0 80032FF0 120000DA */  beqz      $s0, .L8003335C
/* E3F4 80032FF4 24020002 */   addiu    $v0, $zero, 2
/* E3F8 80032FF8 8E040000 */  lw        $a0, ($s0)
/* E3FC 80032FFC 1082000A */  beq       $a0, $v0, .L80033028
/* E400 80033000 24020005 */   addiu    $v0, $zero, 5
/* E404 80033004 10820008 */  beq       $a0, $v0, .L80033028
/* E408 80033008 00000000 */   nop
/* E40C 8003300C 8E240534 */  lw        $a0, 0x534($s1)
/* E410 80033010 4405E000 */  mfc1      $a1, $f28
/* E414 80033014 4406D000 */  mfc1      $a2, $f26
/* E418 80033018 0C00CA29 */  jal       func_800328A4
/* E41C 8003301C 00000000 */   nop
/* E420 80033020 104000CE */  beqz      $v0, .L8003335C
/* E424 80033024 00000000 */   nop
.L80033028:
/* E428 80033028 8E240534 */  lw        $a0, 0x534($s1)
/* E42C 8003302C 3C014974 */  lui       $at, 0x4974
/* E430 80033030 34212400 */  ori       $at, $at, 0x2400
/* E434 80033034 4481A000 */  mtc1      $at, $f20
/* E438 80033038 10800043 */  beqz      $a0, .L80033148
/* E43C 8003303C 24120001 */   addiu    $s2, $zero, 1
/* E440 80033040 8C830000 */  lw        $v1, ($a0)
/* E444 80033044 24020006 */  addiu     $v0, $zero, 6
/* E448 80033048 1462003F */  bne       $v1, $v0, .L80033148
/* E44C 8003304C 0080802D */   daddu    $s0, $a0, $zero
/* E450 80033050 C6200060 */  lwc1      $f0, 0x60($s1)
/* E454 80033054 C6080018 */  lwc1      $f8, 0x18($s0)
/* E458 80033058 C604000C */  lwc1      $f4, 0xc($s0)
/* E45C 8003305C C6020020 */  lwc1      $f2, 0x20($s0)
/* E460 80033060 C6060014 */  lwc1      $f6, 0x14($s0)
/* E464 80033064 E7A00010 */  swc1      $f0, 0x10($sp)
/* E468 80033068 C6200068 */  lwc1      $f0, 0x68($s1)
/* E46C 8003306C 27A20044 */  addiu     $v0, $sp, 0x44
/* E470 80033070 AFA20020 */  sw        $v0, 0x20($sp)
/* E474 80033074 27A20048 */  addiu     $v0, $sp, 0x48
/* E478 80033078 46061601 */  sub.s     $f24, $f2, $f6
/* E47C 8003307C AFA20024 */  sw        $v0, 0x24($sp)
/* E480 80033080 27A2004C */  addiu     $v0, $sp, 0x4c
/* E484 80033084 46044581 */  sub.s     $f22, $f8, $f4
/* E488 80033088 E7BC0018 */  swc1      $f28, 0x18($sp)
/* E48C 8003308C E7BA001C */  swc1      $f26, 0x1c($sp)
/* E490 80033090 AFA20028 */  sw        $v0, 0x28($sp)
/* E494 80033094 46182281 */  sub.s     $f10, $f4, $f24
/* E498 80033098 E7A00014 */  swc1      $f0, 0x14($sp)
/* E49C 8003309C C60C000C */  lwc1      $f12, 0xc($s0)
/* E4A0 800330A0 46163180 */  add.s     $f6, $f6, $f22
/* E4A4 800330A4 C60E0014 */  lwc1      $f14, 0x14($s0)
/* E4A8 800330A8 44065000 */  mfc1      $a2, $f10
/* E4AC 800330AC 44073000 */  mfc1      $a3, $f6
/* E4B0 800330B0 0C00C979 */  jal       func_800325E4
/* E4B4 800330B4 0000902D */   daddu    $s2, $zero, $zero
/* E4B8 800330B8 10400006 */  beqz      $v0, .L800330D4
/* E4BC 800330BC 00000000 */   nop
/* E4C0 800330C0 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* E4C4 800330C4 4614003C */  c.lt.s    $f0, $f20
/* E4C8 800330C8 00000000 */  nop
/* E4CC 800330CC 45030001 */  bc1tl     .L800330D4
/* E4D0 800330D0 46000506 */   mov.s    $f20, $f0
.L800330D4:
/* E4D4 800330D4 C6200060 */  lwc1      $f0, 0x60($s1)
/* E4D8 800330D8 C6020018 */  lwc1      $f2, 0x18($s0)
/* E4DC 800330DC C6040020 */  lwc1      $f4, 0x20($s0)
/* E4E0 800330E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* E4E4 800330E4 C6200068 */  lwc1      $f0, 0x68($s1)
/* E4E8 800330E8 27A20044 */  addiu     $v0, $sp, 0x44
/* E4EC 800330EC AFA20020 */  sw        $v0, 0x20($sp)
/* E4F0 800330F0 27A20048 */  addiu     $v0, $sp, 0x48
/* E4F4 800330F4 46181081 */  sub.s     $f2, $f2, $f24
/* E4F8 800330F8 AFA20024 */  sw        $v0, 0x24($sp)
/* E4FC 800330FC 27A2004C */  addiu     $v0, $sp, 0x4c
/* E500 80033100 46162100 */  add.s     $f4, $f4, $f22
/* E504 80033104 E7BC0018 */  swc1      $f28, 0x18($sp)
/* E508 80033108 E7BA001C */  swc1      $f26, 0x1c($sp)
/* E50C 8003310C AFA20028 */  sw        $v0, 0x28($sp)
/* E510 80033110 E7A00014 */  swc1      $f0, 0x14($sp)
/* E514 80033114 C60C0018 */  lwc1      $f12, 0x18($s0)
/* E518 80033118 C60E0020 */  lwc1      $f14, 0x20($s0)
/* E51C 8003311C 44061000 */  mfc1      $a2, $f2
/* E520 80033120 44072000 */  mfc1      $a3, $f4
/* E524 80033124 0C00C979 */  jal       func_800325E4
/* E528 80033128 00000000 */   nop
/* E52C 8003312C 10400006 */  beqz      $v0, .L80033148
/* E530 80033130 00000000 */   nop
/* E534 80033134 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* E538 80033138 4614003C */  c.lt.s    $f0, $f20
/* E53C 8003313C 00000000 */  nop
/* E540 80033140 45030001 */  bc1tl     .L80033148
/* E544 80033144 46000506 */   mov.s    $f20, $f0
.L80033148:
/* E548 80033148 1240005C */  beqz      $s2, .L800332BC
/* E54C 8003314C 00000000 */   nop
/* E550 80033150 8FA30040 */  lw        $v1, 0x40($sp)
/* E554 80033154 8462000A */  lh        $v0, 0xa($v1)
/* E558 80033158 18400058 */  blez      $v0, .L800332BC
/* E55C 8003315C 0000902D */   daddu    $s2, $zero, $zero
/* E560 80033160 27B50044 */  addiu     $s5, $sp, 0x44
/* E564 80033164 27B40048 */  addiu     $s4, $sp, 0x48
/* E568 80033168 27B3004C */  addiu     $s3, $sp, 0x4c
/* E56C 8003316C 0240802D */  daddu     $s0, $s2, $zero
.L80033170:
/* E570 80033170 8C62000C */  lw        $v0, 0xc($v1)
/* E574 80033174 C6200060 */  lwc1      $f0, 0x60($s1)
/* E578 80033178 02021021 */  addu      $v0, $s0, $v0
/* E57C 8003317C 8C430000 */  lw        $v1, ($v0)
/* E580 80033180 8C420004 */  lw        $v0, 4($v0)
/* E584 80033184 E7A00010 */  swc1      $f0, 0x10($sp)
/* E588 80033188 C6200068 */  lwc1      $f0, 0x68($s1)
/* E58C 8003318C E7BC0018 */  swc1      $f28, 0x18($sp)
/* E590 80033190 E7BA001C */  swc1      $f26, 0x1c($sp)
/* E594 80033194 AFB50020 */  sw        $s5, 0x20($sp)
/* E598 80033198 AFB40024 */  sw        $s4, 0x24($sp)
/* E59C 8003319C AFB30028 */  sw        $s3, 0x28($sp)
/* E5A0 800331A0 E7A00014 */  swc1      $f0, 0x14($sp)
/* E5A4 800331A4 C46C0000 */  lwc1      $f12, ($v1)
/* E5A8 800331A8 C46E0008 */  lwc1      $f14, 8($v1)
/* E5AC 800331AC 8C460000 */  lw        $a2, ($v0)
/* E5B0 800331B0 0C00C8B7 */  jal       func_800322DC
/* E5B4 800331B4 8C470008 */   lw       $a3, 8($v0)
/* E5B8 800331B8 10400006 */  beqz      $v0, .L800331D4
/* E5BC 800331BC 00000000 */   nop
/* E5C0 800331C0 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* E5C4 800331C4 4614003C */  c.lt.s    $f0, $f20
/* E5C8 800331C8 00000000 */  nop
/* E5CC 800331CC 45030001 */  bc1tl     .L800331D4
/* E5D0 800331D0 46000506 */   mov.s    $f20, $f0
.L800331D4:
/* E5D4 800331D4 8FA20040 */  lw        $v0, 0x40($sp)
/* E5D8 800331D8 8C42000C */  lw        $v0, 0xc($v0)
/* E5DC 800331DC C6200060 */  lwc1      $f0, 0x60($s1)
/* E5E0 800331E0 02021021 */  addu      $v0, $s0, $v0
/* E5E4 800331E4 8C430004 */  lw        $v1, 4($v0)
/* E5E8 800331E8 8C420008 */  lw        $v0, 8($v0)
/* E5EC 800331EC E7A00010 */  swc1      $f0, 0x10($sp)
/* E5F0 800331F0 C6200068 */  lwc1      $f0, 0x68($s1)
/* E5F4 800331F4 E7BC0018 */  swc1      $f28, 0x18($sp)
/* E5F8 800331F8 E7BA001C */  swc1      $f26, 0x1c($sp)
/* E5FC 800331FC AFB50020 */  sw        $s5, 0x20($sp)
/* E600 80033200 AFB40024 */  sw        $s4, 0x24($sp)
/* E604 80033204 AFB30028 */  sw        $s3, 0x28($sp)
/* E608 80033208 E7A00014 */  swc1      $f0, 0x14($sp)
/* E60C 8003320C C46C0000 */  lwc1      $f12, ($v1)
/* E610 80033210 C46E0008 */  lwc1      $f14, 8($v1)
/* E614 80033214 8C460000 */  lw        $a2, ($v0)
/* E618 80033218 0C00C8B7 */  jal       func_800322DC
/* E61C 8003321C 8C470008 */   lw       $a3, 8($v0)
/* E620 80033220 10400006 */  beqz      $v0, .L8003323C
/* E624 80033224 00000000 */   nop
/* E628 80033228 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* E62C 8003322C 4614003C */  c.lt.s    $f0, $f20
/* E630 80033230 00000000 */  nop
/* E634 80033234 45030001 */  bc1tl     .L8003323C
/* E638 80033238 46000506 */   mov.s    $f20, $f0
.L8003323C:
/* E63C 8003323C 8FA20040 */  lw        $v0, 0x40($sp)
/* E640 80033240 8C42000C */  lw        $v0, 0xc($v0)
/* E644 80033244 C6200060 */  lwc1      $f0, 0x60($s1)
/* E648 80033248 02021021 */  addu      $v0, $s0, $v0
/* E64C 8003324C 8C430008 */  lw        $v1, 8($v0)
/* E650 80033250 8C420000 */  lw        $v0, ($v0)
/* E654 80033254 E7A00010 */  swc1      $f0, 0x10($sp)
/* E658 80033258 C6200068 */  lwc1      $f0, 0x68($s1)
/* E65C 8003325C E7BC0018 */  swc1      $f28, 0x18($sp)
/* E660 80033260 E7BA001C */  swc1      $f26, 0x1c($sp)
/* E664 80033264 AFB50020 */  sw        $s5, 0x20($sp)
/* E668 80033268 AFB40024 */  sw        $s4, 0x24($sp)
/* E66C 8003326C AFB30028 */  sw        $s3, 0x28($sp)
/* E670 80033270 E7A00014 */  swc1      $f0, 0x14($sp)
/* E674 80033274 C46C0000 */  lwc1      $f12, ($v1)
/* E678 80033278 C46E0008 */  lwc1      $f14, 8($v1)
/* E67C 8003327C 8C460000 */  lw        $a2, ($v0)
/* E680 80033280 0C00C8B7 */  jal       func_800322DC
/* E684 80033284 8C470008 */   lw       $a3, 8($v0)
/* E688 80033288 10400006 */  beqz      $v0, .L800332A4
/* E68C 8003328C 00000000 */   nop
/* E690 80033290 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* E694 80033294 4614003C */  c.lt.s    $f0, $f20
/* E698 80033298 00000000 */  nop
/* E69C 8003329C 45030001 */  bc1tl     .L800332A4
/* E6A0 800332A0 46000506 */   mov.s    $f20, $f0
.L800332A4:
/* E6A4 800332A4 8FA30040 */  lw        $v1, 0x40($sp)
/* E6A8 800332A8 8462000A */  lh        $v0, 0xa($v1)
/* E6AC 800332AC 26520001 */  addiu     $s2, $s2, 1
/* E6B0 800332B0 0242102A */  slt       $v0, $s2, $v0
/* E6B4 800332B4 1440FFAE */  bnez      $v0, .L80033170
/* E6B8 800332B8 26100040 */   addiu    $s0, $s0, 0x40
.L800332BC:
/* E6BC 800332BC 3C014974 */  lui       $at, 0x4974
/* E6C0 800332C0 34212400 */  ori       $at, $at, 0x2400
/* E6C4 800332C4 44810000 */  mtc1      $at, $f0
/* E6C8 800332C8 00000000 */  nop
/* E6CC 800332CC 4600A032 */  c.eq.s    $f20, $f0
/* E6D0 800332D0 00000000 */  nop
/* E6D4 800332D4 45030020 */  bc1tl     .L80033358
/* E6D8 800332D8 AE20050C */   sw       $zero, 0x50c($s1)
/* E6DC 800332DC 44801000 */  mtc1      $zero, $f2
/* E6E0 800332E0 00000000 */  nop
/* E6E4 800332E4 4602A032 */  c.eq.s    $f20, $f2
/* E6E8 800332E8 00000000 */  nop
/* E6EC 800332EC 45000003 */  bc1f      .L800332FC
/* E6F0 800332F0 00000000 */   nop
/* E6F4 800332F4 0800CCD6 */  j         .L80033358
/* E6F8 800332F8 AE20050C */   sw       $zero, 0x50c($s1)
.L800332FC:
/* E6FC 800332FC C620050C */  lwc1      $f0, 0x50c($s1)
/* E700 80033300 4600103C */  c.lt.s    $f2, $f0
/* E704 80033304 00000000 */  nop
/* E708 80033308 4500000A */  bc1f      .L80033334
/* E70C 8003330C 2630050C */   addiu    $s0, $s1, 0x50c
/* E710 80033310 4600A004 */  sqrt.s    $f0, $f20
/* E714 80033314 46000032 */  c.eq.s    $f0, $f0
/* E718 80033318 00000000 */  nop
/* E71C 8003331C 4503000E */  bc1tl     .L80033358
/* E720 80033320 E6000000 */   swc1     $f0, ($s0)
/* E724 80033324 0C0187BC */  jal       sqrtf
/* E728 80033328 4600A306 */   mov.s    $f12, $f20
/* E72C 8003332C 0800CCD6 */  j         .L80033358
/* E730 80033330 E6000000 */   swc1     $f0, ($s0)
.L80033334:
/* E734 80033334 4600A004 */  sqrt.s    $f0, $f20
/* E738 80033338 46000032 */  c.eq.s    $f0, $f0
/* E73C 8003333C 00000000 */  nop
/* E740 80033340 45030004 */  bc1tl     .L80033354
/* E744 80033344 46000007 */   neg.s    $f0, $f0
/* E748 80033348 0C0187BC */  jal       sqrtf
/* E74C 8003334C 4600A306 */   mov.s    $f12, $f20
/* E750 80033350 46000007 */  neg.s     $f0, $f0
.L80033354:
/* E754 80033354 E6000000 */  swc1      $f0, ($s0)
.L80033358:
/* E758 80033358 AE200514 */  sw        $zero, 0x514($s1)
.L8003335C:
/* E75C 8003335C 8FBF0068 */  lw        $ra, 0x68($sp)
/* E760 80033360 8FB50064 */  lw        $s5, 0x64($sp)
/* E764 80033364 8FB40060 */  lw        $s4, 0x60($sp)
/* E768 80033368 8FB3005C */  lw        $s3, 0x5c($sp)
/* E76C 8003336C 8FB20058 */  lw        $s2, 0x58($sp)
/* E770 80033370 8FB10054 */  lw        $s1, 0x54($sp)
/* E774 80033374 8FB00050 */  lw        $s0, 0x50($sp)
/* E778 80033378 D7BC0090 */  ldc1      $f28, 0x90($sp)
/* E77C 8003337C D7BA0088 */  ldc1      $f26, 0x88($sp)
/* E780 80033380 D7B80080 */  ldc1      $f24, 0x80($sp)
/* E784 80033384 D7B60078 */  ldc1      $f22, 0x78($sp)
/* E788 80033388 D7B40070 */  ldc1      $f20, 0x70($sp)
/* E78C 8003338C 03E00008 */  jr        $ra
/* E790 80033390 27BD0098 */   addiu    $sp, $sp, 0x98
