.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80242200_D614B0
.word .L80241080_D60330, .L802410AC_D6035C, .L8024167C_D6092C, .L8024167C_D6092C, .L8024167C_D6092C, .L8024167C_D6092C, .L8024167C_D6092C, .L8024167C_D6092C, .L8024167C_D6092C, .L8024167C_D6092C, .L80241118_D603C8, .L8024121C_D604CC, .L80241304_D605B4, .L80241410_D606C0, .L80241634_D608E4, .L80241664_D60914

dlabel D_80242240_D614F0
.double 0.7

dlabel D_80242248_D614F8
.double 0.7

.section .text

glabel func_80240F20_D601D0
/* D601D0 80240F20 27BDFF88 */  addiu     $sp, $sp, -0x78
/* D601D4 80240F24 AFB3005C */  sw        $s3, 0x5c($sp)
/* D601D8 80240F28 0080982D */  daddu     $s3, $a0, $zero
/* D601DC 80240F2C AFBF006C */  sw        $ra, 0x6c($sp)
/* D601E0 80240F30 AFB60068 */  sw        $s6, 0x68($sp)
/* D601E4 80240F34 AFB50064 */  sw        $s5, 0x64($sp)
/* D601E8 80240F38 AFB40060 */  sw        $s4, 0x60($sp)
/* D601EC 80240F3C AFB20058 */  sw        $s2, 0x58($sp)
/* D601F0 80240F40 AFB10054 */  sw        $s1, 0x54($sp)
/* D601F4 80240F44 AFB00050 */  sw        $s0, 0x50($sp)
/* D601F8 80240F48 F7B40070 */  sdc1      $f20, 0x70($sp)
/* D601FC 80240F4C 8E720148 */  lw        $s2, 0x148($s3)
/* D60200 80240F50 86440008 */  lh        $a0, 8($s2)
/* D60204 80240F54 0C00EABB */  jal       get_npc_unsafe
/* D60208 80240F58 00A0802D */   daddu    $s0, $a1, $zero
/* D6020C 80240F5C 8E63000C */  lw        $v1, 0xc($s3)
/* D60210 80240F60 0260202D */  daddu     $a0, $s3, $zero
/* D60214 80240F64 8C650000 */  lw        $a1, ($v1)
/* D60218 80240F68 0C0B1EAF */  jal       evt_get_variable
/* D6021C 80240F6C 0040882D */   daddu    $s1, $v0, $zero
/* D60220 80240F70 AFA00020 */  sw        $zero, 0x20($sp)
/* D60224 80240F74 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D60228 80240F78 8C630030 */  lw        $v1, 0x30($v1)
/* D6022C 80240F7C AFA30024 */  sw        $v1, 0x24($sp)
/* D60230 80240F80 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D60234 80240F84 8C63001C */  lw        $v1, 0x1c($v1)
/* D60238 80240F88 AFA30028 */  sw        $v1, 0x28($sp)
/* D6023C 80240F8C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D60240 80240F90 8C630024 */  lw        $v1, 0x24($v1)
/* D60244 80240F94 AFA3002C */  sw        $v1, 0x2c($sp)
/* D60248 80240F98 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D6024C 80240F9C 3C158011 */  lui       $s5, %hi(gPlayerStatus)
/* D60250 80240FA0 26B5EFC8 */  addiu     $s5, $s5, %lo(gPlayerStatus)
/* D60254 80240FA4 8C630028 */  lw        $v1, 0x28($v1)
/* D60258 80240FA8 27B60020 */  addiu     $s6, $sp, 0x20
/* D6025C 80240FAC AFA30030 */  sw        $v1, 0x30($sp)
/* D60260 80240FB0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D60264 80240FB4 3C0143FA */  lui       $at, 0x43fa
/* D60268 80240FB8 44810000 */  mtc1      $at, $f0
/* D6026C 80240FBC 8C63002C */  lw        $v1, 0x2c($v1)
/* D60270 80240FC0 0040A02D */  daddu     $s4, $v0, $zero
/* D60274 80240FC4 E7A00038 */  swc1      $f0, 0x38($sp)
/* D60278 80240FC8 A7A0003C */  sh        $zero, 0x3c($sp)
/* D6027C 80240FCC 12000019 */  beqz      $s0, .L80241034
/* D60280 80240FD0 AFA30034 */   sw       $v1, 0x34($sp)
/* D60284 80240FD4 27A50040 */  addiu     $a1, $sp, 0x40
/* D60288 80240FD8 27A60044 */  addiu     $a2, $sp, 0x44
/* D6028C 80240FDC AE600070 */  sw        $zero, 0x70($s3)
/* D60290 80240FE0 A620008E */  sh        $zero, 0x8e($s1)
/* D60294 80240FE4 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D60298 80240FE8 3C01447A */  lui       $at, 0x447a
/* D6029C 80240FEC 44810000 */  mtc1      $at, $f0
/* D602A0 80240FF0 34420010 */  ori       $v0, $v0, 0x10
/* D602A4 80240FF4 AE4200B0 */  sw        $v0, 0xb0($s2)
/* D602A8 80240FF8 C6220038 */  lwc1      $f2, 0x38($s1)
/* D602AC 80240FFC C624003C */  lwc1      $f4, 0x3c($s1)
/* D602B0 80241000 C6260040 */  lwc1      $f6, 0x40($s1)
/* D602B4 80241004 27A2004C */  addiu     $v0, $sp, 0x4c
/* D602B8 80241008 E7A0004C */  swc1      $f0, 0x4c($sp)
/* D602BC 8024100C E7A20040 */  swc1      $f2, 0x40($sp)
/* D602C0 80241010 E7A40044 */  swc1      $f4, 0x44($sp)
/* D602C4 80241014 E7A60048 */  swc1      $f6, 0x48($sp)
/* D602C8 80241018 AFA20010 */  sw        $v0, 0x10($sp)
/* D602CC 8024101C 8E240080 */  lw        $a0, 0x80($s1)
/* D602D0 80241020 0C0372DF */  jal       npc_raycast_down_sides
/* D602D4 80241024 27A70048 */   addiu    $a3, $sp, 0x48
/* D602D8 80241028 C7A00044 */  lwc1      $f0, 0x44($sp)
/* D602DC 8024102C 4600028D */  trunc.w.s $f10, $f0
/* D602E0 80241030 E64A0070 */  swc1      $f10, 0x70($s2)
.L80241034:
/* D602E4 80241034 8E4300B0 */  lw        $v1, 0xb0($s2)
/* D602E8 80241038 30620004 */  andi      $v0, $v1, 4
/* D602EC 8024103C 10400007 */  beqz      $v0, .L8024105C
/* D602F0 80241040 00000000 */   nop
/* D602F4 80241044 824200B4 */  lb        $v0, 0xb4($s2)
/* D602F8 80241048 1440018D */  bnez      $v0, .L80241680
/* D602FC 8024104C 0000102D */   daddu    $v0, $zero, $zero
/* D60300 80241050 2402FFFB */  addiu     $v0, $zero, -5
/* D60304 80241054 00621024 */  and       $v0, $v1, $v0
/* D60308 80241058 AE4200B0 */  sw        $v0, 0xb0($s2)
.L8024105C:
/* D6030C 8024105C 8E630070 */  lw        $v1, 0x70($s3)
/* D60310 80241060 2C620010 */  sltiu     $v0, $v1, 0x10
/* D60314 80241064 10400185 */  beqz      $v0, .L8024167C_D6092C
/* D60318 80241068 00031080 */   sll      $v0, $v1, 2
/* D6031C 8024106C 3C018024 */  lui       $at, %hi(jtbl_80242200_D614B0)
/* D60320 80241070 00220821 */  addu      $at, $at, $v0
/* D60324 80241074 8C222200 */  lw        $v0, %lo(jtbl_80242200_D614B0)($at)
/* D60328 80241078 00400008 */  jr        $v0
/* D6032C 8024107C 00000000 */   nop
.L80241080_D60330:
/* D60330 80241080 8E4200CC */  lw        $v0, 0xcc($s2)
/* D60334 80241084 922300A9 */  lbu       $v1, 0xa9($s1)
/* D60338 80241088 8C440000 */  lw        $a0, ($v0)
/* D6033C 8024108C 8E220000 */  lw        $v0, ($s1)
/* D60340 80241090 A22300AB */  sb        $v1, 0xab($s1)
/* D60344 80241094 34420080 */  ori       $v0, $v0, 0x80
/* D60348 80241098 AE220000 */  sw        $v0, ($s1)
/* D6034C 8024109C 24020001 */  addiu     $v0, $zero, 1
/* D60350 802410A0 AE240028 */  sw        $a0, 0x28($s1)
/* D60354 802410A4 AE600074 */  sw        $zero, 0x74($s3)
/* D60358 802410A8 AE620070 */  sw        $v0, 0x70($s3)
.L802410AC_D6035C:
/* D6035C 802410AC 8E830014 */  lw        $v1, 0x14($s4)
/* D60360 802410B0 04600015 */  bltz      $v1, .L80241108
/* D60364 802410B4 00000000 */   nop
/* D60368 802410B8 8E620074 */  lw        $v0, 0x74($s3)
/* D6036C 802410BC 1C400011 */  bgtz      $v0, .L80241104
/* D60370 802410C0 2442FFFF */   addiu    $v0, $v0, -1
/* D60374 802410C4 02C0202D */  daddu     $a0, $s6, $zero
/* D60378 802410C8 AE630074 */  sw        $v1, 0x74($s3)
/* D6037C 802410CC AFA00010 */  sw        $zero, 0x10($sp)
/* D60380 802410D0 8E86000C */  lw        $a2, 0xc($s4)
/* D60384 802410D4 8E870010 */  lw        $a3, 0x10($s4)
/* D60388 802410D8 0C01242D */  jal       basic_ai_check_player_dist
/* D6038C 802410DC 0240282D */   daddu    $a1, $s2, $zero
/* D60390 802410E0 10400006 */  beqz      $v0, .L802410FC
/* D60394 802410E4 0220202D */   daddu    $a0, $s1, $zero
/* D60398 802410E8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D6039C 802410EC 0C012530 */  jal       ai_enemy_play_sound
/* D603A0 802410F0 3C060020 */   lui      $a2, 0x20
/* D603A4 802410F4 2402000A */  addiu     $v0, $zero, 0xa
/* D603A8 802410F8 AE620070 */  sw        $v0, 0x70($s3)
.L802410FC:
/* D603AC 802410FC 8E620074 */  lw        $v0, 0x74($s3)
/* D603B0 80241100 2442FFFF */  addiu     $v0, $v0, -1
.L80241104:
/* D603B4 80241104 AE620074 */  sw        $v0, 0x74($s3)
.L80241108:
/* D603B8 80241108 8E630070 */  lw        $v1, 0x70($s3)
/* D603BC 8024110C 2402000A */  addiu     $v0, $zero, 0xa
/* D603C0 80241110 1462015B */  bne       $v1, $v0, .L80241680
/* D603C4 80241114 0000102D */   daddu    $v0, $zero, $zero
.L80241118_D603C8:
/* D603C8 80241118 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D603CC 8024111C 8E4200CC */  lw        $v0, 0xcc($s2)
/* D603D0 80241120 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D603D4 80241124 8C42000C */  lw        $v0, 0xc($v0)
/* D603D8 80241128 AE220028 */  sw        $v0, 0x28($s1)
/* D603DC 8024112C 8EA60028 */  lw        $a2, 0x28($s5)
/* D603E0 80241130 0C00A720 */  jal       atan2
/* D603E4 80241134 8EA70030 */   lw       $a3, 0x30($s5)
/* D603E8 80241138 3C013FA6 */  lui       $at, 0x3fa6
/* D603EC 8024113C 34216666 */  ori       $at, $at, 0x6666
/* D603F0 80241140 44811000 */  mtc1      $at, $f2
/* D603F4 80241144 27A50040 */  addiu     $a1, $sp, 0x40
/* D603F8 80241148 E6200010 */  swc1      $f0, 0x10($s1)
/* D603FC 8024114C C6200038 */  lwc1      $f0, 0x38($s1)
/* D60400 80241150 C6240040 */  lwc1      $f4, 0x40($s1)
/* D60404 80241154 3C01447A */  lui       $at, 0x447a
/* D60408 80241158 44813000 */  mtc1      $at, $f6
/* D6040C 8024115C 27A60044 */  addiu     $a2, $sp, 0x44
/* D60410 80241160 AE20001C */  sw        $zero, 0x1c($s1)
/* D60414 80241164 E6220014 */  swc1      $f2, 0x14($s1)
/* D60418 80241168 C6880000 */  lwc1      $f8, ($s4)
/* D6041C 8024116C C622003C */  lwc1      $f2, 0x3c($s1)
/* D60420 80241170 27A2004C */  addiu     $v0, $sp, 0x4c
/* D60424 80241174 E7A00040 */  swc1      $f0, 0x40($sp)
/* D60428 80241178 E7A40048 */  swc1      $f4, 0x48($sp)
/* D6042C 8024117C E7A6004C */  swc1      $f6, 0x4c($sp)
/* D60430 80241180 E7A20044 */  swc1      $f2, 0x44($sp)
/* D60434 80241184 E6280018 */  swc1      $f8, 0x18($s1)
/* D60438 80241188 AFA20010 */  sw        $v0, 0x10($sp)
/* D6043C 8024118C 8E240080 */  lw        $a0, 0x80($s1)
/* D60440 80241190 0C0372DF */  jal       npc_raycast_down_sides
/* D60444 80241194 27A70048 */   addiu    $a3, $sp, 0x48
/* D60448 80241198 10400010 */  beqz      $v0, .L802411DC
/* D6044C 8024119C 00000000 */   nop
/* D60450 802411A0 C620003C */  lwc1      $f0, 0x3c($s1)
/* D60454 802411A4 C6440070 */  lwc1      $f4, 0x70($s2)
/* D60458 802411A8 46802120 */  cvt.s.w   $f4, $f4
/* D6045C 802411AC 46040001 */  sub.s     $f0, $f0, $f4
/* D60460 802411B0 3C018024 */  lui       $at, %hi(D_80242240_D614F0)
/* D60464 802411B4 D4222240 */  ldc1      $f2, %lo(D_80242240_D614F0)($at)
/* D60468 802411B8 46000021 */  cvt.d.s   $f0, $f0
/* D6046C 802411BC 46220002 */  mul.d     $f0, $f0, $f2
/* D60470 802411C0 00000000 */  nop
/* D60474 802411C4 460020A1 */  cvt.d.s   $f2, $f4
/* D60478 802411C8 46201080 */  add.d     $f2, $f2, $f0
/* D6047C 802411CC E7A40044 */  swc1      $f4, 0x44($sp)
/* D60480 802411D0 462010A0 */  cvt.s.d   $f2, $f2
/* D60484 802411D4 08090483 */  j         .L8024120C
/* D60488 802411D8 E6220064 */   swc1     $f2, 0x64($s1)
.L802411DC:
/* D6048C 802411DC C6A0002C */  lwc1      $f0, 0x2c($s5)
/* D60490 802411E0 C622003C */  lwc1      $f2, 0x3c($s1)
/* D60494 802411E4 46001081 */  sub.s     $f2, $f2, $f0
/* D60498 802411E8 3C018024 */  lui       $at, %hi(D_80242248_D614F8)
/* D6049C 802411EC D4242248 */  ldc1      $f4, %lo(D_80242248_D614F8)($at)
/* D604A0 802411F0 460010A1 */  cvt.d.s   $f2, $f2
/* D604A4 802411F4 46241082 */  mul.d     $f2, $f2, $f4
/* D604A8 802411F8 00000000 */  nop
/* D604AC 802411FC 46000021 */  cvt.d.s   $f0, $f0
/* D604B0 80241200 46220000 */  add.d     $f0, $f0, $f2
/* D604B4 80241204 46200020 */  cvt.s.d   $f0, $f0
/* D604B8 80241208 E6200064 */  swc1      $f0, 0x64($s1)
.L8024120C:
/* D604BC 8024120C C620003C */  lwc1      $f0, 0x3c($s1)
/* D604C0 80241210 2402000B */  addiu     $v0, $zero, 0xb
/* D604C4 80241214 E6200068 */  swc1      $f0, 0x68($s1)
/* D604C8 80241218 AE620070 */  sw        $v0, 0x70($s3)
.L8024121C_D604CC:
/* D604CC 8024121C C6200018 */  lwc1      $f0, 0x18($s1)
/* D604D0 80241220 44801000 */  mtc1      $zero, $f2
/* D604D4 80241224 44801800 */  mtc1      $zero, $f3
/* D604D8 80241228 46000021 */  cvt.d.s   $f0, $f0
/* D604DC 8024122C 4620103C */  c.lt.d    $f2, $f0
/* D604E0 80241230 00000000 */  nop
/* D604E4 80241234 45000025 */  bc1f      .L802412CC
/* D604E8 80241238 27A50040 */   addiu    $a1, $sp, 0x40
/* D604EC 8024123C C6200038 */  lwc1      $f0, 0x38($s1)
/* D604F0 80241240 C622003C */  lwc1      $f2, 0x3c($s1)
/* D604F4 80241244 C6240040 */  lwc1      $f4, 0x40($s1)
/* D604F8 80241248 C6260018 */  lwc1      $f6, 0x18($s1)
/* D604FC 8024124C E7A00040 */  swc1      $f0, 0x40($sp)
/* D60500 80241250 E7A20044 */  swc1      $f2, 0x44($sp)
/* D60504 80241254 E7A40048 */  swc1      $f4, 0x48($sp)
/* D60508 80241258 E7A60010 */  swc1      $f6, 0x10($sp)
/* D6050C 8024125C C620000C */  lwc1      $f0, 0xc($s1)
/* D60510 80241260 E7A00014 */  swc1      $f0, 0x14($sp)
/* D60514 80241264 862200A8 */  lh        $v0, 0xa8($s1)
/* D60518 80241268 44820000 */  mtc1      $v0, $f0
/* D6051C 8024126C 00000000 */  nop
/* D60520 80241270 46800020 */  cvt.s.w   $f0, $f0
/* D60524 80241274 E7A00018 */  swc1      $f0, 0x18($sp)
/* D60528 80241278 862200A6 */  lh        $v0, 0xa6($s1)
/* D6052C 8024127C 27A60044 */  addiu     $a2, $sp, 0x44
/* D60530 80241280 44820000 */  mtc1      $v0, $f0
/* D60534 80241284 00000000 */  nop
/* D60538 80241288 46800020 */  cvt.s.w   $f0, $f0
/* D6053C 8024128C E7A0001C */  swc1      $f0, 0x1c($sp)
/* D60540 80241290 8E240080 */  lw        $a0, 0x80($s1)
/* D60544 80241294 0C037711 */  jal       npc_test_move_simple_with_slipping
/* D60548 80241298 27A70048 */   addiu    $a3, $sp, 0x48
/* D6054C 8024129C 54400001 */  bnel      $v0, $zero, .L802412A4
/* D60550 802412A0 AE200018 */   sw       $zero, 0x18($s1)
.L802412A4:
/* D60554 802412A4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D60558 802412A8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D6055C 802412AC 8EA60028 */  lw        $a2, 0x28($s5)
/* D60560 802412B0 0C00A720 */  jal       atan2
/* D60564 802412B4 8EA70030 */   lw       $a3, 0x30($s5)
/* D60568 802412B8 8E250018 */  lw        $a1, 0x18($s1)
/* D6056C 802412BC 44060000 */  mfc1      $a2, $f0
/* D60570 802412C0 0220202D */  daddu     $a0, $s1, $zero
/* D60574 802412C4 0C00EA95 */  jal       npc_move_heading
/* D60578 802412C8 AE26000C */   sw       $a2, 0xc($s1)
.L802412CC:
/* D6057C 802412CC C620001C */  lwc1      $f0, 0x1c($s1)
/* D60580 802412D0 C6220014 */  lwc1      $f2, 0x14($s1)
/* D60584 802412D4 46020001 */  sub.s     $f0, $f0, $f2
/* D60588 802412D8 C622003C */  lwc1      $f2, 0x3c($s1)
/* D6058C 802412DC C6240064 */  lwc1      $f4, 0x64($s1)
/* D60590 802412E0 46001080 */  add.s     $f2, $f2, $f0
/* D60594 802412E4 E620001C */  swc1      $f0, 0x1c($s1)
/* D60598 802412E8 4604103C */  c.lt.s    $f2, $f4
/* D6059C 802412EC 00000000 */  nop
/* D605A0 802412F0 450000E2 */  bc1f      .L8024167C_D6092C
/* D605A4 802412F4 E622003C */   swc1     $f2, 0x3c($s1)
/* D605A8 802412F8 2402000C */  addiu     $v0, $zero, 0xc
/* D605AC 802412FC E624003C */  swc1      $f4, 0x3c($s1)
/* D605B0 80241300 AE620070 */  sw        $v0, 0x70($s3)
.L80241304_D605B4:
/* D605B4 80241304 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D605B8 80241308 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D605BC 8024130C 8EA60028 */  lw        $a2, 0x28($s5)
/* D605C0 80241310 0C00A7B5 */  jal       dist2D
/* D605C4 80241314 8EA70030 */   lw       $a3, 0x30($s5)
/* D605C8 80241318 3C014270 */  lui       $at, 0x4270
/* D605CC 8024131C 44811000 */  mtc1      $at, $f2
/* D605D0 80241320 00000000 */  nop
/* D605D4 80241324 4602003C */  c.lt.s    $f0, $f2
/* D605D8 80241328 00000000 */  nop
/* D605DC 8024132C 45000002 */  bc1f      .L80241338
/* D605E0 80241330 E6200010 */   swc1     $f0, 0x10($s1)
/* D605E4 80241334 E6220010 */  swc1      $f2, 0x10($s1)
.L80241338:
/* D605E8 80241338 C6860018 */  lwc1      $f6, 0x18($s4)
/* D605EC 8024133C C6400070 */  lwc1      $f0, 0x70($s2)
/* D605F0 80241340 46800020 */  cvt.s.w   $f0, $f0
/* D605F4 80241344 E7A00044 */  swc1      $f0, 0x44($sp)
/* D605F8 80241348 46000021 */  cvt.d.s   $f0, $f0
/* D605FC 8024134C C6240010 */  lwc1      $f4, 0x10($s1)
/* D60600 80241350 3C014024 */  lui       $at, 0x4024
/* D60604 80241354 44811800 */  mtc1      $at, $f3
/* D60608 80241358 44801000 */  mtc1      $zero, $f2
/* D6060C 8024135C 46062103 */  div.s     $f4, $f4, $f6
/* D60610 80241360 46220000 */  add.d     $f0, $f0, $f2
/* D60614 80241364 C622003C */  lwc1      $f2, 0x3c($s1)
/* D60618 80241368 4600228D */  trunc.w.s $f10, $f4
/* D6061C 8024136C 44025000 */  mfc1      $v0, $f10
/* D60620 80241370 00000000 */  nop
/* D60624 80241374 A622008E */  sh        $v0, 0x8e($s1)
/* D60628 80241378 460010A1 */  cvt.d.s   $f2, $f2
/* D6062C 8024137C 46220001 */  sub.d     $f0, $f0, $f2
/* D60630 80241380 00021400 */  sll       $v0, $v0, 0x10
/* D60634 80241384 E6260018 */  swc1      $f6, 0x18($s1)
/* D60638 80241388 14400003 */  bnez      $v0, .L80241398
/* D6063C 8024138C 46200120 */   cvt.s.d  $f4, $f0
/* D60640 80241390 24020001 */  addiu     $v0, $zero, 1
/* D60644 80241394 A622008E */  sh        $v0, 0x8e($s1)
.L80241398:
/* D60648 80241398 8622008E */  lh        $v0, 0x8e($s1)
/* D6064C 8024139C C620001C */  lwc1      $f0, 0x1c($s1)
/* D60650 802413A0 44821000 */  mtc1      $v0, $f2
/* D60654 802413A4 00000000 */  nop
/* D60658 802413A8 468010A0 */  cvt.s.w   $f2, $f2
/* D6065C 802413AC 46000007 */  neg.s     $f0, $f0
/* D60660 802413B0 46020002 */  mul.s     $f0, $f0, $f2
/* D60664 802413B4 00000000 */  nop
/* D60668 802413B8 00420018 */  mult      $v0, $v0
/* D6066C 802413BC 8E230000 */  lw        $v1, ($s1)
/* D60670 802413C0 46040000 */  add.s     $f0, $f0, $f4
/* D60674 802413C4 A22000AB */  sb        $zero, 0xab($s1)
/* D60678 802413C8 2402FF7F */  addiu     $v0, $zero, -0x81
/* D6067C 802413CC 00004012 */  mflo      $t0
/* D60680 802413D0 00621824 */  and       $v1, $v1, $v0
/* D60684 802413D4 24020005 */  addiu     $v0, $zero, 5
/* D60688 802413D8 46000000 */  add.s     $f0, $f0, $f0
/* D6068C 802413DC AE230000 */  sw        $v1, ($s1)
/* D60690 802413E0 44881000 */  mtc1      $t0, $f2
/* D60694 802413E4 00000000 */  nop
/* D60698 802413E8 468010A0 */  cvt.s.w   $f2, $f2
/* D6069C 802413EC 46000007 */  neg.s     $f0, $f0
/* D606A0 802413F0 46020003 */  div.s     $f0, $f0, $f2
/* D606A4 802413F4 46000005 */  abs.s     $f0, $f0
/* D606A8 802413F8 46000007 */  neg.s     $f0, $f0
/* D606AC 802413FC E6200014 */  swc1      $f0, 0x14($s1)
/* D606B0 80241400 AE42006C */  sw        $v0, 0x6c($s2)
/* D606B4 80241404 2402000D */  addiu     $v0, $zero, 0xd
/* D606B8 80241408 A620008E */  sh        $zero, 0x8e($s1)
/* D606BC 8024140C AE620070 */  sw        $v0, 0x70($s3)
.L80241410_D606C0:
/* D606C0 80241410 C620001C */  lwc1      $f0, 0x1c($s1)
/* D606C4 80241414 C6220014 */  lwc1      $f2, 0x14($s1)
/* D606C8 80241418 46020001 */  sub.s     $f0, $f0, $f2
/* D606CC 8024141C 4480A000 */  mtc1      $zero, $f20
/* D606D0 80241420 00000000 */  nop
/* D606D4 80241424 4614003C */  c.lt.s    $f0, $f20
/* D606D8 80241428 00000000 */  nop
/* D606DC 8024142C 45000012 */  bc1f      .L80241478
/* D606E0 80241430 E620001C */   swc1     $f0, 0x1c($s1)
/* D606E4 80241434 27A50040 */  addiu     $a1, $sp, 0x40
/* D606E8 80241438 27A60044 */  addiu     $a2, $sp, 0x44
/* D606EC 8024143C 27A2004C */  addiu     $v0, $sp, 0x4c
/* D606F0 80241440 C6220038 */  lwc1      $f2, 0x38($s1)
/* D606F4 80241444 C624003C */  lwc1      $f4, 0x3c($s1)
/* D606F8 80241448 C6260040 */  lwc1      $f6, 0x40($s1)
/* D606FC 8024144C 46000007 */  neg.s     $f0, $f0
/* D60700 80241450 E7A0004C */  swc1      $f0, 0x4c($sp)
/* D60704 80241454 E7A20040 */  swc1      $f2, 0x40($sp)
/* D60708 80241458 E7A40044 */  swc1      $f4, 0x44($sp)
/* D6070C 8024145C E7A60048 */  swc1      $f6, 0x48($sp)
/* D60710 80241460 AFA20010 */  sw        $v0, 0x10($sp)
/* D60714 80241464 8E240080 */  lw        $a0, 0x80($s1)
/* D60718 80241468 0C0372DF */  jal       npc_raycast_down_sides
/* D6071C 8024146C 27A70048 */   addiu    $a3, $sp, 0x48
/* D60720 80241470 54400001 */  bnel      $v0, $zero, .L80241478
/* D60724 80241474 E634001C */   swc1     $f20, 0x1c($s1)
.L80241478:
/* D60728 80241478 C624003C */  lwc1      $f4, 0x3c($s1)
/* D6072C 8024147C C620001C */  lwc1      $f0, 0x1c($s1)
/* D60730 80241480 46002100 */  add.s     $f4, $f4, $f0
/* D60734 80241484 C6200018 */  lwc1      $f0, 0x18($s1)
/* D60738 80241488 44801000 */  mtc1      $zero, $f2
/* D6073C 8024148C 44801800 */  mtc1      $zero, $f3
/* D60740 80241490 46000021 */  cvt.d.s   $f0, $f0
/* D60744 80241494 4620103C */  c.lt.d    $f2, $f0
/* D60748 80241498 00000000 */  nop
/* D6074C 8024149C 45000057 */  bc1f      .L802415FC
/* D60750 802414A0 E624003C */   swc1     $f4, 0x3c($s1)
/* D60754 802414A4 46002086 */  mov.s     $f2, $f4
/* D60758 802414A8 C6200038 */  lwc1      $f0, 0x38($s1)
/* D6075C 802414AC C6240040 */  lwc1      $f4, 0x40($s1)
/* D60760 802414B0 C6260018 */  lwc1      $f6, 0x18($s1)
/* D60764 802414B4 E7A20044 */  swc1      $f2, 0x44($sp)
/* D60768 802414B8 E7A00040 */  swc1      $f0, 0x40($sp)
/* D6076C 802414BC E7A40048 */  swc1      $f4, 0x48($sp)
/* D60770 802414C0 E7A60010 */  swc1      $f6, 0x10($sp)
/* D60774 802414C4 C620000C */  lwc1      $f0, 0xc($s1)
/* D60778 802414C8 E7A00014 */  swc1      $f0, 0x14($sp)
/* D6077C 802414CC 862200A8 */  lh        $v0, 0xa8($s1)
/* D60780 802414D0 27A50040 */  addiu     $a1, $sp, 0x40
/* D60784 802414D4 44820000 */  mtc1      $v0, $f0
/* D60788 802414D8 00000000 */  nop
/* D6078C 802414DC 46800020 */  cvt.s.w   $f0, $f0
/* D60790 802414E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* D60794 802414E4 862200A6 */  lh        $v0, 0xa6($s1)
/* D60798 802414E8 27A60044 */  addiu     $a2, $sp, 0x44
/* D6079C 802414EC 44820000 */  mtc1      $v0, $f0
/* D607A0 802414F0 00000000 */  nop
/* D607A4 802414F4 46800020 */  cvt.s.w   $f0, $f0
/* D607A8 802414F8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* D607AC 802414FC 8E240080 */  lw        $a0, 0x80($s1)
/* D607B0 80241500 0C037711 */  jal       npc_test_move_simple_with_slipping
/* D607B4 80241504 27A70048 */   addiu    $a3, $sp, 0x48
/* D607B8 80241508 10400003 */  beqz      $v0, .L80241518
/* D607BC 8024150C 00000000 */   nop
/* D607C0 80241510 0809057B */  j         .L802415EC
/* D607C4 80241514 AE200018 */   sw       $zero, 0x18($s1)
.L80241518:
/* D607C8 80241518 C620001C */  lwc1      $f0, 0x1c($s1)
/* D607CC 8024151C 3C01C004 */  lui       $at, 0xc004
/* D607D0 80241520 44811800 */  mtc1      $at, $f3
/* D607D4 80241524 44801000 */  mtc1      $zero, $f2
/* D607D8 80241528 46000021 */  cvt.d.s   $f0, $f0
/* D607DC 8024152C 4622003C */  c.lt.d    $f0, $f2
/* D607E0 80241530 00000000 */  nop
/* D607E4 80241534 4500002D */  bc1f      .L802415EC
/* D607E8 80241538 00000000 */   nop
/* D607EC 8024153C 9622008E */  lhu       $v0, 0x8e($s1)
/* D607F0 80241540 24420001 */  addiu     $v0, $v0, 1
/* D607F4 80241544 A622008E */  sh        $v0, 0x8e($s1)
/* D607F8 80241548 00021400 */  sll       $v0, $v0, 0x10
/* D607FC 8024154C 8E830020 */  lw        $v1, 0x20($s4)
/* D60800 80241550 00021403 */  sra       $v0, $v0, 0x10
/* D60804 80241554 0043102A */  slt       $v0, $v0, $v1
/* D60808 80241558 14400024 */  bnez      $v0, .L802415EC
/* D6080C 8024155C 00000000 */   nop
/* D60810 80241560 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D60814 80241564 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D60818 80241568 8EA60028 */  lw        $a2, 0x28($s5)
/* D6081C 8024156C 0C00A720 */  jal       atan2
/* D60820 80241570 8EA70030 */   lw       $a3, 0x30($s5)
/* D60824 80241574 46000506 */  mov.s     $f20, $f0
/* D60828 80241578 C62C000C */  lwc1      $f12, 0xc($s1)
/* D6082C 8024157C 0C00A70A */  jal       get_clamped_angle_diff
/* D60830 80241580 4600A386 */   mov.s    $f14, $f20
/* D60834 80241584 46000086 */  mov.s     $f2, $f0
/* D60838 80241588 8E82001C */  lw        $v0, 0x1c($s4)
/* D6083C 8024158C 46001005 */  abs.s     $f0, $f2
/* D60840 80241590 44822000 */  mtc1      $v0, $f4
/* D60844 80241594 00000000 */  nop
/* D60848 80241598 46802120 */  cvt.s.w   $f4, $f4
/* D6084C 8024159C 4600203C */  c.lt.s    $f4, $f0
/* D60850 802415A0 00000000 */  nop
/* D60854 802415A4 4500000D */  bc1f      .L802415DC
/* D60858 802415A8 00000000 */   nop
/* D6085C 802415AC 44800000 */  mtc1      $zero, $f0
/* D60860 802415B0 C634000C */  lwc1      $f20, 0xc($s1)
/* D60864 802415B4 4600103C */  c.lt.s    $f2, $f0
/* D60868 802415B8 00000000 */  nop
/* D6086C 802415BC 45000006 */  bc1f      .L802415D8
/* D60870 802415C0 00021023 */   negu     $v0, $v0
/* D60874 802415C4 44820000 */  mtc1      $v0, $f0
/* D60878 802415C8 00000000 */  nop
/* D6087C 802415CC 46800020 */  cvt.s.w   $f0, $f0
/* D60880 802415D0 08090577 */  j         .L802415DC
/* D60884 802415D4 4600A500 */   add.s    $f20, $f20, $f0
.L802415D8:
/* D60888 802415D8 4604A500 */  add.s     $f20, $f20, $f4
.L802415DC:
/* D6088C 802415DC 0C00A6C9 */  jal       clamp_angle
/* D60890 802415E0 4600A306 */   mov.s    $f12, $f20
/* D60894 802415E4 E620000C */  swc1      $f0, 0xc($s1)
/* D60898 802415E8 A620008E */  sh        $zero, 0x8e($s1)
.L802415EC:
/* D6089C 802415EC 8E250018 */  lw        $a1, 0x18($s1)
/* D608A0 802415F0 8E26000C */  lw        $a2, 0xc($s1)
/* D608A4 802415F4 0C00EA95 */  jal       npc_move_heading
/* D608A8 802415F8 0220202D */   daddu    $a0, $s1, $zero
.L802415FC:
/* D608AC 802415FC 8E42006C */  lw        $v0, 0x6c($s2)
/* D608B0 80241600 2442FFFF */  addiu     $v0, $v0, -1
/* D608B4 80241604 1C400003 */  bgtz      $v0, .L80241614
/* D608B8 80241608 AE42006C */   sw       $v0, 0x6c($s2)
/* D608BC 8024160C 24020005 */  addiu     $v0, $zero, 5
/* D608C0 80241610 AE42006C */  sw        $v0, 0x6c($s2)
.L80241614:
/* D608C4 80241614 C620003C */  lwc1      $f0, 0x3c($s1)
/* D608C8 80241618 C6220068 */  lwc1      $f2, 0x68($s1)
/* D608CC 8024161C 4600103C */  c.lt.s    $f2, $f0
/* D608D0 80241620 00000000 */  nop
/* D608D4 80241624 45000015 */  bc1f      .L8024167C_D6092C
/* D608D8 80241628 2402000E */   addiu    $v0, $zero, 0xe
/* D608DC 8024162C E622003C */  swc1      $f2, 0x3c($s1)
/* D608E0 80241630 AE620070 */  sw        $v0, 0x70($s3)
.L80241634_D608E4:
/* D608E4 80241634 8E4200CC */  lw        $v0, 0xcc($s2)
/* D608E8 80241638 922300A9 */  lbu       $v1, 0xa9($s1)
/* D608EC 8024163C 8C440020 */  lw        $a0, 0x20($v0)
/* D608F0 80241640 8E220000 */  lw        $v0, ($s1)
/* D608F4 80241644 A22300AB */  sb        $v1, 0xab($s1)
/* D608F8 80241648 34420080 */  ori       $v0, $v0, 0x80
/* D608FC 8024164C AE220000 */  sw        $v0, ($s1)
/* D60900 80241650 2402000F */  addiu     $v0, $zero, 0xf
/* D60904 80241654 A622008E */  sh        $v0, 0x8e($s1)
/* D60908 80241658 2402000F */  addiu     $v0, $zero, 0xf
/* D6090C 8024165C AE240028 */  sw        $a0, 0x28($s1)
/* D60910 80241660 AE620070 */  sw        $v0, 0x70($s3)
.L80241664_D60914:
/* D60914 80241664 9622008E */  lhu       $v0, 0x8e($s1)
/* D60918 80241668 2442FFFF */  addiu     $v0, $v0, -1
/* D6091C 8024166C A622008E */  sh        $v0, 0x8e($s1)
/* D60920 80241670 00021400 */  sll       $v0, $v0, 0x10
/* D60924 80241674 58400001 */  blezl     $v0, .L8024167C_D6092C
/* D60928 80241678 AE600070 */   sw       $zero, 0x70($s3)
.L8024167C_D6092C:
/* D6092C 8024167C 0000102D */  daddu     $v0, $zero, $zero
.L80241680:
/* D60930 80241680 8FBF006C */  lw        $ra, 0x6c($sp)
/* D60934 80241684 8FB60068 */  lw        $s6, 0x68($sp)
/* D60938 80241688 8FB50064 */  lw        $s5, 0x64($sp)
/* D6093C 8024168C 8FB40060 */  lw        $s4, 0x60($sp)
/* D60940 80241690 8FB3005C */  lw        $s3, 0x5c($sp)
/* D60944 80241694 8FB20058 */  lw        $s2, 0x58($sp)
/* D60948 80241698 8FB10054 */  lw        $s1, 0x54($sp)
/* D6094C 8024169C 8FB00050 */  lw        $s0, 0x50($sp)
/* D60950 802416A0 D7B40070 */  ldc1      $f20, 0x70($sp)
/* D60954 802416A4 03E00008 */  jr        $ra
/* D60958 802416A8 27BD0078 */   addiu    $sp, $sp, 0x78
/* D6095C 802416AC 00000000 */  nop
