.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244018_BA4748
.double 380.0

glabel D_80244020_BA4750
.double -380.0

glabel D_80244028_BA4758
.double 305.0

glabel D_80244030_BA4760
.double 375.0

glabel D_80244038_BA4768
.double 45.0

glabel D_80244040_BA4770
.double 150.0, 0.0

.section .text

glabel btl_restore_world_cameras_BA11D8
/* BA11D8 80240AA8 27BDFF80 */  addiu     $sp, $sp, -0x80
/* BA11DC 80240AAC AFBF0064 */  sw        $ra, 0x64($sp)
/* BA11E0 80240AB0 AFBE0060 */  sw        $fp, 0x60($sp)
/* BA11E4 80240AB4 AFB7005C */  sw        $s7, 0x5c($sp)
/* BA11E8 80240AB8 AFB60058 */  sw        $s6, 0x58($sp)
/* BA11EC 80240ABC AFB50054 */  sw        $s5, 0x54($sp)
/* BA11F0 80240AC0 AFB40050 */  sw        $s4, 0x50($sp)
/* BA11F4 80240AC4 AFB3004C */  sw        $s3, 0x4c($sp)
/* BA11F8 80240AC8 AFB20048 */  sw        $s2, 0x48($sp)
/* BA11FC 80240ACC AFB10044 */  sw        $s1, 0x44($sp)
/* BA1200 80240AD0 AFB00040 */  sw        $s0, 0x40($sp)
/* BA1204 80240AD4 F7B80078 */  sdc1      $f24, 0x78($sp)
/* BA1208 80240AD8 F7B60070 */  sdc1      $f22, 0x70($sp)
/* BA120C 80240ADC F7B40068 */  sdc1      $f20, 0x68($sp)
/* BA1210 80240AE0 AFA40080 */  sw        $a0, 0x80($sp)
/* BA1214 80240AE4 8C960148 */  lw        $s6, 0x148($a0)
/* BA1218 80240AE8 00C0902D */  daddu     $s2, $a2, $zero
/* BA121C 80240AEC 86C40008 */  lh        $a0, 8($s6)
/* BA1220 80240AF0 0C00EABB */  jal       get_npc_unsafe
/* BA1224 80240AF4 0000B82D */   daddu    $s7, $zero, $zero
/* BA1228 80240AF8 0040882D */  daddu     $s1, $v0, $zero
/* BA122C 80240AFC 9622008E */  lhu       $v0, 0x8e($s1)
/* BA1230 80240B00 2442FFFF */  addiu     $v0, $v0, -1
/* BA1234 80240B04 A622008E */  sh        $v0, 0x8e($s1)
/* BA1238 80240B08 00021400 */  sll       $v0, $v0, 0x10
/* BA123C 80240B0C 8EC30090 */  lw        $v1, 0x90($s6)
/* BA1240 80240B10 00021403 */  sra       $v0, $v0, 0x10
/* BA1244 80240B14 0062182A */  slt       $v1, $v1, $v0
/* BA1248 80240B18 14600005 */  bnez      $v1, .L80240B30
/* BA124C 80240B1C 02E0F02D */   daddu    $fp, $s7, $zero
/* BA1250 80240B20 8EC20000 */  lw        $v0, ($s6)
/* BA1254 80240B24 3C031F10 */  lui       $v1, 0x1f10
/* BA1258 80240B28 00431025 */  or        $v0, $v0, $v1
/* BA125C 80240B2C AEC20000 */  sw        $v0, ($s6)
.L80240B30:
/* BA1260 80240B30 8622008E */  lh        $v0, 0x8e($s1)
/* BA1264 80240B34 1440025D */  bnez      $v0, .L802414AC
/* BA1268 80240B38 00000000 */   nop
/* BA126C 80240B3C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA1270 80240B40 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA1274 80240B44 0C00A6C9 */  jal       clamp_angle
/* BA1278 80240B48 C44C00A8 */   lwc1     $f12, 0xa8($v0)
/* BA127C 80240B4C 3C014334 */  lui       $at, 0x4334
/* BA1280 80240B50 44811000 */  mtc1      $at, $f2
/* BA1284 80240B54 00000000 */  nop
/* BA1288 80240B58 4602003C */  c.lt.s    $f0, $f2
/* BA128C 80240B5C 00000000 */  nop
/* BA1290 80240B60 45000011 */  bc1f      .L80240BA8
/* BA1294 80240B64 00000000 */   nop
/* BA1298 80240B68 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BA129C 80240B6C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BA12A0 80240B70 3C0142B4 */  lui       $at, 0x42b4
/* BA12A4 80240B74 44816000 */  mtc1      $at, $f12
/* BA12A8 80240B78 00031080 */  sll       $v0, $v1, 2
/* BA12AC 80240B7C 00431021 */  addu      $v0, $v0, $v1
/* BA12B0 80240B80 00021080 */  sll       $v0, $v0, 2
/* BA12B4 80240B84 00431023 */  subu      $v0, $v0, $v1
/* BA12B8 80240B88 000218C0 */  sll       $v1, $v0, 3
/* BA12BC 80240B8C 00431021 */  addu      $v0, $v0, $v1
/* BA12C0 80240B90 000210C0 */  sll       $v0, $v0, 3
/* BA12C4 80240B94 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* BA12C8 80240B98 00220821 */  addu      $at, $at, $v0
/* BA12CC 80240B9C C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* BA12D0 80240BA0 080902F9 */  j         .L80240BE4
/* BA12D4 80240BA4 460C0301 */   sub.s    $f12, $f0, $f12
.L80240BA8:
/* BA12D8 80240BA8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BA12DC 80240BAC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BA12E0 80240BB0 3C0142B4 */  lui       $at, 0x42b4
/* BA12E4 80240BB4 44816000 */  mtc1      $at, $f12
/* BA12E8 80240BB8 00031080 */  sll       $v0, $v1, 2
/* BA12EC 80240BBC 00431021 */  addu      $v0, $v0, $v1
/* BA12F0 80240BC0 00021080 */  sll       $v0, $v0, 2
/* BA12F4 80240BC4 00431023 */  subu      $v0, $v0, $v1
/* BA12F8 80240BC8 000218C0 */  sll       $v1, $v0, 3
/* BA12FC 80240BCC 00431021 */  addu      $v0, $v0, $v1
/* BA1300 80240BD0 000210C0 */  sll       $v0, $v0, 3
/* BA1304 80240BD4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* BA1308 80240BD8 00220821 */  addu      $at, $at, $v0
/* BA130C 80240BDC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* BA1310 80240BE0 460C0300 */  add.s     $f12, $f0, $f12
.L80240BE4:
/* BA1314 80240BE4 0C00A6C9 */  jal       clamp_angle
/* BA1318 80240BE8 00000000 */   nop
/* BA131C 80240BEC 46000586 */  mov.s     $f22, $f0
/* BA1320 80240BF0 3C014334 */  lui       $at, 0x4334
/* BA1324 80240BF4 44816000 */  mtc1      $at, $f12
/* BA1328 80240BF8 0C00A6C9 */  jal       clamp_angle
/* BA132C 80240BFC 460CB300 */   add.s    $f12, $f22, $f12
/* BA1330 80240C00 8EC20088 */  lw        $v0, 0x88($s6)
/* BA1334 80240C04 14400010 */  bnez      $v0, .L80240C48
/* BA1338 80240C08 46000606 */   mov.s    $f24, $f0
/* BA133C 80240C0C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA1340 80240C10 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA1344 80240C14 804300B4 */  lb        $v1, 0xb4($v0)
/* BA1348 80240C18 3C014200 */  lui       $at, 0x4200
/* BA134C 80240C1C 4481A000 */  mtc1      $at, $f20
/* BA1350 80240C20 10600016 */  beqz      $v1, .L80240C7C
/* BA1354 80240C24 24020001 */   addiu    $v0, $zero, 1
/* BA1358 80240C28 3C0142C8 */  lui       $at, 0x42c8
/* BA135C 80240C2C 4481A000 */  mtc1      $at, $f20
/* BA1360 80240C30 14620013 */  bne       $v1, $v0, .L80240C80
/* BA1364 80240C34 26300038 */   addiu    $s0, $s1, 0x38
/* BA1368 80240C38 3C0142B4 */  lui       $at, 0x42b4
/* BA136C 80240C3C 4481A000 */  mtc1      $at, $f20
/* BA1370 80240C40 08090321 */  j         .L80240C84
/* BA1374 80240C44 0200202D */   daddu    $a0, $s0, $zero
.L80240C48:
/* BA1378 80240C48 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA137C 80240C4C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA1380 80240C50 804300B4 */  lb        $v1, 0xb4($v0)
/* BA1384 80240C54 3C014218 */  lui       $at, 0x4218
/* BA1388 80240C58 4481A000 */  mtc1      $at, $f20
/* BA138C 80240C5C 10600007 */  beqz      $v1, .L80240C7C
/* BA1390 80240C60 24020001 */   addiu    $v0, $zero, 1
/* BA1394 80240C64 3C0142B4 */  lui       $at, 0x42b4
/* BA1398 80240C68 4481A000 */  mtc1      $at, $f20
/* BA139C 80240C6C 14620004 */  bne       $v1, $v0, .L80240C80
/* BA13A0 80240C70 26300038 */   addiu    $s0, $s1, 0x38
/* BA13A4 80240C74 3C014296 */  lui       $at, 0x4296
/* BA13A8 80240C78 4481A000 */  mtc1      $at, $f20
.L80240C7C:
/* BA13AC 80240C7C 26300038 */  addiu     $s0, $s1, 0x38
.L80240C80:
/* BA13B0 80240C80 0200202D */  daddu     $a0, $s0, $zero
.L80240C84:
/* BA13B4 80240C84 3C15800F */  lui       $s5, %hi(gPlayerStatusPtr)
/* BA13B8 80240C88 26B57B30 */  addiu     $s5, $s5, %lo(gPlayerStatusPtr)
/* BA13BC 80240C8C 4407C000 */  mfc1      $a3, $f24
/* BA13C0 80240C90 862200A6 */  lh        $v0, 0xa6($s1)
/* BA13C4 80240C94 8EA30000 */  lw        $v1, ($s5)
/* BA13C8 80240C98 44824000 */  mtc1      $v0, $f8
/* BA13CC 80240C9C 00000000 */  nop
/* BA13D0 80240CA0 46804220 */  cvt.s.w   $f8, $f8
/* BA13D4 80240CA4 C4600028 */  lwc1      $f0, 0x28($v1)
/* BA13D8 80240CA8 44064000 */  mfc1      $a2, $f8
/* BA13DC 80240CAC 26330040 */  addiu     $s3, $s1, 0x40
/* BA13E0 80240CB0 E6200038 */  swc1      $f0, 0x38($s1)
/* BA13E4 80240CB4 C4600030 */  lwc1      $f0, 0x30($v1)
/* BA13E8 80240CB8 0260282D */  daddu     $a1, $s3, $zero
/* BA13EC 80240CBC 0C00A7E7 */  jal       add_vec2D_polar
/* BA13F0 80240CC0 E6200040 */   swc1     $f0, 0x40($s1)
/* BA13F4 80240CC4 862200A6 */  lh        $v0, 0xa6($s1)
/* BA13F8 80240CC8 44820000 */  mtc1      $v0, $f0
/* BA13FC 80240CCC 00000000 */  nop
/* BA1400 80240CD0 46800020 */  cvt.s.w   $f0, $f0
/* BA1404 80240CD4 4600A000 */  add.s     $f0, $f20, $f0
/* BA1408 80240CD8 4406B000 */  mfc1      $a2, $f22
/* BA140C 80240CDC 44050000 */  mfc1      $a1, $f0
/* BA1410 80240CE0 0C00EA95 */  jal       npc_move_heading
/* BA1414 80240CE4 0220202D */   daddu    $a0, $s1, $zero
/* BA1418 80240CE8 8EC20088 */  lw        $v0, 0x88($s6)
/* BA141C 80240CEC 1440005D */  bnez      $v0, .L80240E64
/* BA1420 80240CF0 00000000 */   nop
/* BA1424 80240CF4 C6200038 */  lwc1      $f0, 0x38($s1)
/* BA1428 80240CF8 3C018024 */  lui       $at, %hi(D_80244018_BA4748)
/* BA142C 80240CFC D4244018 */  ldc1      $f4, %lo(D_80244018_BA4748)($at)
/* BA1430 80240D00 46000021 */  cvt.d.s   $f0, $f0
/* BA1434 80240D04 4620203C */  c.lt.d    $f4, $f0
/* BA1438 80240D08 00000000 */  nop
/* BA143C 80240D0C 45000005 */  bc1f      .L80240D24
/* BA1440 80240D10 00000000 */   nop
/* BA1444 80240D14 3C0143BE */  lui       $at, 0x43be
/* BA1448 80240D18 44810000 */  mtc1      $at, $f0
/* BA144C 80240D1C 00000000 */  nop
/* BA1450 80240D20 E6200038 */  swc1      $f0, 0x38($s1)
.L80240D24:
/* BA1454 80240D24 C6200038 */  lwc1      $f0, 0x38($s1)
/* BA1458 80240D28 3C018024 */  lui       $at, %hi(D_80244020_BA4750)
/* BA145C 80240D2C D4224020 */  ldc1      $f2, %lo(D_80244020_BA4750)($at)
/* BA1460 80240D30 46000021 */  cvt.d.s   $f0, $f0
/* BA1464 80240D34 4622003C */  c.lt.d    $f0, $f2
/* BA1468 80240D38 00000000 */  nop
/* BA146C 80240D3C 45000005 */  bc1f      .L80240D54
/* BA1470 80240D40 00000000 */   nop
/* BA1474 80240D44 3C01C3BE */  lui       $at, 0xc3be
/* BA1478 80240D48 44810000 */  mtc1      $at, $f0
/* BA147C 80240D4C 00000000 */  nop
/* BA1480 80240D50 E6200038 */  swc1      $f0, 0x38($s1)
.L80240D54:
/* BA1484 80240D54 C6200040 */  lwc1      $f0, 0x40($s1)
/* BA1488 80240D58 46000021 */  cvt.d.s   $f0, $f0
/* BA148C 80240D5C 4620203C */  c.lt.d    $f4, $f0
/* BA1490 80240D60 00000000 */  nop
/* BA1494 80240D64 45000005 */  bc1f      .L80240D7C
/* BA1498 80240D68 00000000 */   nop
/* BA149C 80240D6C 3C0143BE */  lui       $at, 0x43be
/* BA14A0 80240D70 44810000 */  mtc1      $at, $f0
/* BA14A4 80240D74 00000000 */  nop
/* BA14A8 80240D78 E6200040 */  swc1      $f0, 0x40($s1)
.L80240D7C:
/* BA14AC 80240D7C C6200040 */  lwc1      $f0, 0x40($s1)
/* BA14B0 80240D80 46000021 */  cvt.d.s   $f0, $f0
/* BA14B4 80240D84 4622003C */  c.lt.d    $f0, $f2
/* BA14B8 80240D88 00000000 */  nop
/* BA14BC 80240D8C 45000005 */  bc1f      .L80240DA4
/* BA14C0 80240D90 00000000 */   nop
/* BA14C4 80240D94 3C01C3BE */  lui       $at, 0xc3be
/* BA14C8 80240D98 44810000 */  mtc1      $at, $f0
/* BA14CC 80240D9C 00000000 */  nop
/* BA14D0 80240DA0 E6200040 */  swc1      $f0, 0x40($s1)
.L80240DA4:
/* BA14D4 80240DA4 C6220038 */  lwc1      $f2, 0x38($s1)
/* BA14D8 80240DA8 46021082 */  mul.s     $f2, $f2, $f2
/* BA14DC 80240DAC 00000000 */  nop
/* BA14E0 80240DB0 C6200040 */  lwc1      $f0, 0x40($s1)
/* BA14E4 80240DB4 46000002 */  mul.s     $f0, $f0, $f0
/* BA14E8 80240DB8 00000000 */  nop
/* BA14EC 80240DBC 46001300 */  add.s     $f12, $f2, $f0
/* BA14F0 80240DC0 46006004 */  sqrt.s    $f0, $f12
/* BA14F4 80240DC4 46000032 */  c.eq.s    $f0, $f0
/* BA14F8 80240DC8 00000000 */  nop
/* BA14FC 80240DCC 45010003 */  bc1t      .L80240DDC
/* BA1500 80240DD0 00000000 */   nop
/* BA1504 80240DD4 0C0187BC */  jal       sqrtf
/* BA1508 80240DD8 00000000 */   nop
.L80240DDC:
/* BA150C 80240DDC 8E260038 */  lw        $a2, 0x38($s1)
/* BA1510 80240DE0 8E270040 */  lw        $a3, 0x40($s1)
/* BA1514 80240DE4 4480A000 */  mtc1      $zero, $f20
/* BA1518 80240DE8 E7A00038 */  swc1      $f0, 0x38($sp)
/* BA151C 80240DEC 4600A306 */  mov.s     $f12, $f20
/* BA1520 80240DF0 0C00A720 */  jal       atan2
/* BA1524 80240DF4 4600A386 */   mov.s    $f14, $f20
/* BA1528 80240DF8 46000586 */  mov.s     $f22, $f0
/* BA152C 80240DFC C7A20038 */  lwc1      $f2, 0x38($sp)
/* BA1530 80240E00 3C018024 */  lui       $at, %hi(D_80244028_BA4758)
/* BA1534 80240E04 D4204028 */  ldc1      $f0, %lo(D_80244028_BA4758)($at)
/* BA1538 80240E08 460010A1 */  cvt.d.s   $f2, $f2
/* BA153C 80240E0C 4620103C */  c.lt.d    $f2, $f0
/* BA1540 80240E10 00000000 */  nop
/* BA1544 80240E14 45000004 */  bc1f      .L80240E28
/* BA1548 80240E18 0200202D */   daddu    $a0, $s0, $zero
/* BA154C 80240E1C 3C064398 */  lui       $a2, 0x4398
/* BA1550 80240E20 08090392 */  j         .L80240E48
/* BA1554 80240E24 34C68000 */   ori      $a2, $a2, 0x8000
.L80240E28:
/* BA1558 80240E28 3C018024 */  lui       $at, %hi(D_80244030_BA4760)
/* BA155C 80240E2C D4204030 */  ldc1      $f0, %lo(D_80244030_BA4760)($at)
/* BA1560 80240E30 4622003C */  c.lt.d    $f0, $f2
/* BA1564 80240E34 00000000 */  nop
/* BA1568 80240E38 450000FA */  bc1f      .L80241224
/* BA156C 80240E3C 00000000 */   nop
/* BA1570 80240E40 3C0643BB */  lui       $a2, 0x43bb
/* BA1574 80240E44 34C68000 */  ori       $a2, $a2, 0x8000
.L80240E48:
/* BA1578 80240E48 4407B000 */  mfc1      $a3, $f22
/* BA157C 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* BA1580 80240E50 E6340038 */  swc1      $f20, 0x38($s1)
/* BA1584 80240E54 0C00A7E7 */  jal       add_vec2D_polar
/* BA1588 80240E58 E6340040 */   swc1     $f20, 0x40($s1)
/* BA158C 80240E5C 08090489 */  j         .L80241224
/* BA1590 80240E60 00000000 */   nop
.L80240E64:
/* BA1594 80240E64 8E220000 */  lw        $v0, ($s1)
/* BA1598 80240E68 30420040 */  andi      $v0, $v0, 0x40
/* BA159C 80240E6C 144000B0 */  bnez      $v0, .L80241130
/* BA15A0 80240E70 27A50020 */   addiu    $a1, $sp, 0x20
/* BA15A4 80240E74 27B40020 */  addiu     $s4, $sp, 0x20
/* BA15A8 80240E78 0280282D */  daddu     $a1, $s4, $zero
/* BA15AC 80240E7C 27B30024 */  addiu     $s3, $sp, 0x24
/* BA15B0 80240E80 8EA20000 */  lw        $v0, ($s5)
/* BA15B4 80240E84 3C014032 */  lui       $at, 0x4032
/* BA15B8 80240E88 44811800 */  mtc1      $at, $f3
/* BA15BC 80240E8C 44801000 */  mtc1      $zero, $f2
/* BA15C0 80240E90 C440002C */  lwc1      $f0, 0x2c($v0)
/* BA15C4 80240E94 C4460028 */  lwc1      $f6, 0x28($v0)
/* BA15C8 80240E98 C4440030 */  lwc1      $f4, 0x30($v0)
/* BA15CC 80240E9C 46000021 */  cvt.d.s   $f0, $f0
/* BA15D0 80240EA0 46220000 */  add.d     $f0, $f0, $f2
/* BA15D4 80240EA4 E7A60020 */  swc1      $f6, 0x20($sp)
/* BA15D8 80240EA8 E7A40028 */  swc1      $f4, 0x28($sp)
/* BA15DC 80240EAC 46200020 */  cvt.s.d   $f0, $f0
/* BA15E0 80240EB0 E7A00024 */  swc1      $f0, 0x24($sp)
/* BA15E4 80240EB4 E7B40010 */  swc1      $f20, 0x10($sp)
/* BA15E8 80240EB8 E7B60014 */  swc1      $f22, 0x14($sp)
/* BA15EC 80240EBC 862200A8 */  lh        $v0, 0xa8($s1)
/* BA15F0 80240EC0 0260302D */  daddu     $a2, $s3, $zero
/* BA15F4 80240EC4 44820000 */  mtc1      $v0, $f0
/* BA15F8 80240EC8 00000000 */  nop
/* BA15FC 80240ECC 46800020 */  cvt.s.w   $f0, $f0
/* BA1600 80240ED0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BA1604 80240ED4 862200A6 */  lh        $v0, 0xa6($s1)
/* BA1608 80240ED8 27B00028 */  addiu     $s0, $sp, 0x28
/* BA160C 80240EDC 44820000 */  mtc1      $v0, $f0
/* BA1610 80240EE0 00000000 */  nop
/* BA1614 80240EE4 46800020 */  cvt.s.w   $f0, $f0
/* BA1618 80240EE8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA161C 80240EEC 8E240080 */  lw        $a0, 0x80($s1)
/* BA1620 80240EF0 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BA1624 80240EF4 0200382D */   daddu    $a3, $s0, $zero
/* BA1628 80240EF8 104000CA */  beqz      $v0, .L80241224
/* BA162C 80240EFC 0280282D */   daddu    $a1, $s4, $zero
/* BA1630 80240F00 8EA20000 */  lw        $v0, ($s5)
/* BA1634 80240F04 3C018024 */  lui       $at, %hi(D_80244038_BA4768)
/* BA1638 80240F08 D4224038 */  ldc1      $f2, %lo(D_80244038_BA4768)($at)
/* BA163C 80240F0C C440002C */  lwc1      $f0, 0x2c($v0)
/* BA1640 80240F10 C4460028 */  lwc1      $f6, 0x28($v0)
/* BA1644 80240F14 C4440030 */  lwc1      $f4, 0x30($v0)
/* BA1648 80240F18 46000021 */  cvt.d.s   $f0, $f0
/* BA164C 80240F1C 46220000 */  add.d     $f0, $f0, $f2
/* BA1650 80240F20 E7A60020 */  swc1      $f6, 0x20($sp)
/* BA1654 80240F24 E7A40028 */  swc1      $f4, 0x28($sp)
/* BA1658 80240F28 46200020 */  cvt.s.d   $f0, $f0
/* BA165C 80240F2C E7A00024 */  swc1      $f0, 0x24($sp)
/* BA1660 80240F30 E7B40010 */  swc1      $f20, 0x10($sp)
/* BA1664 80240F34 E7B60014 */  swc1      $f22, 0x14($sp)
/* BA1668 80240F38 862200A8 */  lh        $v0, 0xa8($s1)
/* BA166C 80240F3C 44820000 */  mtc1      $v0, $f0
/* BA1670 80240F40 00000000 */  nop
/* BA1674 80240F44 46800020 */  cvt.s.w   $f0, $f0
/* BA1678 80240F48 E7A00018 */  swc1      $f0, 0x18($sp)
/* BA167C 80240F4C 862200A6 */  lh        $v0, 0xa6($s1)
/* BA1680 80240F50 0260302D */  daddu     $a2, $s3, $zero
/* BA1684 80240F54 44820000 */  mtc1      $v0, $f0
/* BA1688 80240F58 00000000 */  nop
/* BA168C 80240F5C 46800020 */  cvt.s.w   $f0, $f0
/* BA1690 80240F60 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA1694 80240F64 8E240080 */  lw        $a0, 0x80($s1)
/* BA1698 80240F68 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BA169C 80240F6C 0200382D */   daddu    $a3, $s0, $zero
/* BA16A0 80240F70 27A5002C */  addiu     $a1, $sp, 0x2c
/* BA16A4 80240F74 27A60030 */  addiu     $a2, $sp, 0x30
/* BA16A8 80240F78 27A70034 */  addiu     $a3, $sp, 0x34
/* BA16AC 80240F7C 27A30038 */  addiu     $v1, $sp, 0x38
/* BA16B0 80240F80 C6220038 */  lwc1      $f2, 0x38($s1)
/* BA16B4 80240F84 C620003C */  lwc1      $f0, 0x3c($s1)
/* BA16B8 80240F88 3C014348 */  lui       $at, 0x4348
/* BA16BC 80240F8C 44813000 */  mtc1      $at, $f6
/* BA16C0 80240F90 46000021 */  cvt.d.s   $f0, $f0
/* BA16C4 80240F94 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BA16C8 80240F98 3C014059 */  lui       $at, 0x4059
/* BA16CC 80240F9C 44811800 */  mtc1      $at, $f3
/* BA16D0 80240FA0 44801000 */  mtc1      $zero, $f2
/* BA16D4 80240FA4 C6240040 */  lwc1      $f4, 0x40($s1)
/* BA16D8 80240FA8 46220000 */  add.d     $f0, $f0, $f2
/* BA16DC 80240FAC E7A60038 */  swc1      $f6, 0x38($sp)
/* BA16E0 80240FB0 E7A40034 */  swc1      $f4, 0x34($sp)
/* BA16E4 80240FB4 46200020 */  cvt.s.d   $f0, $f0
/* BA16E8 80240FB8 E7A00030 */  swc1      $f0, 0x30($sp)
/* BA16EC 80240FBC AFA30010 */  sw        $v1, 0x10($sp)
/* BA16F0 80240FC0 8E240080 */  lw        $a0, 0x80($s1)
/* BA16F4 80240FC4 0C0372DF */  jal       npc_raycast_down_sides
/* BA16F8 80240FC8 0040802D */   daddu    $s0, $v0, $zero
/* BA16FC 80240FCC 1600001C */  bnez      $s0, .L80241040
/* BA1700 80240FD0 00000000 */   nop
/* BA1704 80240FD4 1040001A */  beqz      $v0, .L80241040
/* BA1708 80240FD8 00000000 */   nop
/* BA170C 80240FDC C7A20038 */  lwc1      $f2, 0x38($sp)
/* BA1710 80240FE0 3C014054 */  lui       $at, 0x4054
/* BA1714 80240FE4 44810800 */  mtc1      $at, $f1
/* BA1718 80240FE8 44800000 */  mtc1      $zero, $f0
/* BA171C 80240FEC 460010A1 */  cvt.d.s   $f2, $f2
/* BA1720 80240FF0 4622003C */  c.lt.d    $f0, $f2
/* BA1724 80240FF4 00000000 */  nop
/* BA1728 80240FF8 45000011 */  bc1f      .L80241040
/* BA172C 80240FFC 00000000 */   nop
/* BA1730 80241000 3C01405E */  lui       $at, 0x405e
/* BA1734 80241004 44810800 */  mtc1      $at, $f1
/* BA1738 80241008 44800000 */  mtc1      $zero, $f0
/* BA173C 8024100C 00000000 */  nop
/* BA1740 80241010 4620103C */  c.lt.d    $f2, $f0
/* BA1744 80241014 00000000 */  nop
/* BA1748 80241018 45000009 */  bc1f      .L80241040
/* BA174C 8024101C 00000000 */   nop
/* BA1750 80241020 C622003C */  lwc1      $f2, 0x3c($s1)
/* BA1754 80241024 C7A00030 */  lwc1      $f0, 0x30($sp)
/* BA1758 80241028 46001032 */  c.eq.s    $f2, $f0
/* BA175C 8024102C 00000000 */  nop
/* BA1760 80241030 45010003 */  bc1t      .L80241040
/* BA1764 80241034 00000000 */   nop
/* BA1768 80241038 08090489 */  j         .L80241224
/* BA176C 8024103C 241E0001 */   addiu    $fp, $zero, 1
.L80241040:
/* BA1770 80241040 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* BA1774 80241044 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* BA1778 80241048 8E020000 */  lw        $v0, ($s0)
/* BA177C 8024104C 3C014024 */  lui       $at, 0x4024
/* BA1780 80241050 44811800 */  mtc1      $at, $f3
/* BA1784 80241054 44801000 */  mtc1      $zero, $f2
/* BA1788 80241058 C440002C */  lwc1      $f0, 0x2c($v0)
/* BA178C 8024105C C4460028 */  lwc1      $f6, 0x28($v0)
/* BA1790 80241060 C4440030 */  lwc1      $f4, 0x30($v0)
/* BA1794 80241064 46000021 */  cvt.d.s   $f0, $f0
/* BA1798 80241068 46220000 */  add.d     $f0, $f0, $f2
/* BA179C 8024106C E7A60020 */  swc1      $f6, 0x20($sp)
/* BA17A0 80241070 E7A40028 */  swc1      $f4, 0x28($sp)
/* BA17A4 80241074 46200020 */  cvt.s.d   $f0, $f0
/* BA17A8 80241078 E7A00024 */  swc1      $f0, 0x24($sp)
/* BA17AC 8024107C E7B40010 */  swc1      $f20, 0x10($sp)
/* BA17B0 80241080 E7B60014 */  swc1      $f22, 0x14($sp)
/* BA17B4 80241084 862200A8 */  lh        $v0, 0xa8($s1)
/* BA17B8 80241088 27A50020 */  addiu     $a1, $sp, 0x20
/* BA17BC 8024108C 44820000 */  mtc1      $v0, $f0
/* BA17C0 80241090 00000000 */  nop
/* BA17C4 80241094 46800020 */  cvt.s.w   $f0, $f0
/* BA17C8 80241098 E7A00018 */  swc1      $f0, 0x18($sp)
/* BA17CC 8024109C 862200A6 */  lh        $v0, 0xa6($s1)
/* BA17D0 802410A0 27A60024 */  addiu     $a2, $sp, 0x24
/* BA17D4 802410A4 44820000 */  mtc1      $v0, $f0
/* BA17D8 802410A8 00000000 */  nop
/* BA17DC 802410AC 46800020 */  cvt.s.w   $f0, $f0
/* BA17E0 802410B0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA17E4 802410B4 8E240080 */  lw        $a0, 0x80($s1)
/* BA17E8 802410B8 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BA17EC 802410BC 27A70028 */   addiu    $a3, $sp, 0x28
/* BA17F0 802410C0 8FA60020 */  lw        $a2, 0x20($sp)
/* BA17F4 802410C4 8E020000 */  lw        $v0, ($s0)
/* BA17F8 802410C8 8FA70028 */  lw        $a3, 0x28($sp)
/* BA17FC 802410CC C44C0028 */  lwc1      $f12, 0x28($v0)
/* BA1800 802410D0 C44E0030 */  lwc1      $f14, 0x30($v0)
/* BA1804 802410D4 0C00A7B5 */  jal       dist2D
/* BA1808 802410D8 24170001 */   addiu    $s7, $zero, 1
/* BA180C 802410DC 46000506 */  mov.s     $f20, $f0
/* BA1810 802410E0 8E030000 */  lw        $v1, ($s0)
/* BA1814 802410E4 862200A6 */  lh        $v0, 0xa6($s1)
/* BA1818 802410E8 4407C000 */  mfc1      $a3, $f24
/* BA181C 802410EC 44824000 */  mtc1      $v0, $f8
/* BA1820 802410F0 00000000 */  nop
/* BA1824 802410F4 46804220 */  cvt.s.w   $f8, $f8
/* BA1828 802410F8 C4600028 */  lwc1      $f0, 0x28($v1)
/* BA182C 802410FC 44064000 */  mfc1      $a2, $f8
/* BA1830 80241100 26240038 */  addiu     $a0, $s1, 0x38
/* BA1834 80241104 E6200038 */  swc1      $f0, 0x38($s1)
/* BA1838 80241108 C4600030 */  lwc1      $f0, 0x30($v1)
/* BA183C 8024110C 26250040 */  addiu     $a1, $s1, 0x40
/* BA1840 80241110 0C00A7E7 */  jal       add_vec2D_polar
/* BA1844 80241114 E6200040 */   swc1     $f0, 0x40($s1)
/* BA1848 80241118 862200A6 */  lh        $v0, 0xa6($s1)
/* BA184C 8024111C 44820000 */  mtc1      $v0, $f0
/* BA1850 80241120 00000000 */  nop
/* BA1854 80241124 46800020 */  cvt.s.w   $f0, $f0
/* BA1858 80241128 08090485 */  j         .L80241214
/* BA185C 8024112C 4600A500 */   add.s    $f20, $f20, $f0
.L80241130:
/* BA1860 80241130 8EA20000 */  lw        $v0, ($s5)
/* BA1864 80241134 3C014032 */  lui       $at, 0x4032
/* BA1868 80241138 44811800 */  mtc1      $at, $f3
/* BA186C 8024113C 44801000 */  mtc1      $zero, $f2
/* BA1870 80241140 C440002C */  lwc1      $f0, 0x2c($v0)
/* BA1874 80241144 C4460028 */  lwc1      $f6, 0x28($v0)
/* BA1878 80241148 C4440030 */  lwc1      $f4, 0x30($v0)
/* BA187C 8024114C 46000021 */  cvt.d.s   $f0, $f0
/* BA1880 80241150 46220000 */  add.d     $f0, $f0, $f2
/* BA1884 80241154 E7A60020 */  swc1      $f6, 0x20($sp)
/* BA1888 80241158 E7A40028 */  swc1      $f4, 0x28($sp)
/* BA188C 8024115C 46200020 */  cvt.s.d   $f0, $f0
/* BA1890 80241160 E7A00024 */  swc1      $f0, 0x24($sp)
/* BA1894 80241164 E7B40010 */  swc1      $f20, 0x10($sp)
/* BA1898 80241168 E7B60014 */  swc1      $f22, 0x14($sp)
/* BA189C 8024116C 862200A8 */  lh        $v0, 0xa8($s1)
/* BA18A0 80241170 44820000 */  mtc1      $v0, $f0
/* BA18A4 80241174 00000000 */  nop
/* BA18A8 80241178 46800020 */  cvt.s.w   $f0, $f0
/* BA18AC 8024117C E7A00018 */  swc1      $f0, 0x18($sp)
/* BA18B0 80241180 862200A6 */  lh        $v0, 0xa6($s1)
/* BA18B4 80241184 27A60024 */  addiu     $a2, $sp, 0x24
/* BA18B8 80241188 44820000 */  mtc1      $v0, $f0
/* BA18BC 8024118C 00000000 */  nop
/* BA18C0 80241190 46800020 */  cvt.s.w   $f0, $f0
/* BA18C4 80241194 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA18C8 80241198 8E240080 */  lw        $a0, 0x80($s1)
/* BA18CC 8024119C 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BA18D0 802411A0 27A70028 */   addiu    $a3, $sp, 0x28
/* BA18D4 802411A4 1040001F */  beqz      $v0, .L80241224
/* BA18D8 802411A8 00000000 */   nop
/* BA18DC 802411AC 8FA60020 */  lw        $a2, 0x20($sp)
/* BA18E0 802411B0 8EA20000 */  lw        $v0, ($s5)
/* BA18E4 802411B4 8FA70028 */  lw        $a3, 0x28($sp)
/* BA18E8 802411B8 C44C0028 */  lwc1      $f12, 0x28($v0)
/* BA18EC 802411BC 0C00A7B5 */  jal       dist2D
/* BA18F0 802411C0 C44E0030 */   lwc1     $f14, 0x30($v0)
/* BA18F4 802411C4 46000506 */  mov.s     $f20, $f0
/* BA18F8 802411C8 8EA30000 */  lw        $v1, ($s5)
/* BA18FC 802411CC 862200A6 */  lh        $v0, 0xa6($s1)
/* BA1900 802411D0 4407C000 */  mfc1      $a3, $f24
/* BA1904 802411D4 44824000 */  mtc1      $v0, $f8
/* BA1908 802411D8 00000000 */  nop
/* BA190C 802411DC 46804220 */  cvt.s.w   $f8, $f8
/* BA1910 802411E0 C4600028 */  lwc1      $f0, 0x28($v1)
/* BA1914 802411E4 44064000 */  mfc1      $a2, $f8
/* BA1918 802411E8 0200202D */  daddu     $a0, $s0, $zero
/* BA191C 802411EC E6200038 */  swc1      $f0, 0x38($s1)
/* BA1920 802411F0 C4600030 */  lwc1      $f0, 0x30($v1)
/* BA1924 802411F4 0260282D */  daddu     $a1, $s3, $zero
/* BA1928 802411F8 0C00A7E7 */  jal       add_vec2D_polar
/* BA192C 802411FC E6200040 */   swc1     $f0, 0x40($s1)
/* BA1930 80241200 862200A6 */  lh        $v0, 0xa6($s1)
/* BA1934 80241204 44820000 */  mtc1      $v0, $f0
/* BA1938 80241208 00000000 */  nop
/* BA193C 8024120C 46800020 */  cvt.s.w   $f0, $f0
/* BA1940 80241210 4600A500 */  add.s     $f20, $f20, $f0
.L80241214:
/* BA1944 80241214 4406B000 */  mfc1      $a2, $f22
/* BA1948 80241218 4405A000 */  mfc1      $a1, $f20
/* BA194C 8024121C 0C00EA95 */  jal       npc_move_heading
/* BA1950 80241220 0220202D */   daddu    $a0, $s1, $zero
.L80241224:
/* BA1954 80241224 C6400008 */  lwc1      $f0, 8($s2)
/* BA1958 80241228 46800020 */  cvt.s.w   $f0, $f0
/* BA195C 8024122C 44050000 */  mfc1      $a1, $f0
/* BA1960 80241230 C640000C */  lwc1      $f0, 0xc($s2)
/* BA1964 80241234 46800020 */  cvt.s.w   $f0, $f0
/* BA1968 80241238 44060000 */  mfc1      $a2, $f0
/* BA196C 8024123C C6200040 */  lwc1      $f0, 0x40($s1)
/* BA1970 80241240 26300038 */  addiu     $s0, $s1, 0x38
/* BA1974 80241244 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA1978 80241248 C6400010 */  lwc1      $f0, 0x10($s2)
/* BA197C 8024124C 46800020 */  cvt.s.w   $f0, $f0
/* BA1980 80241250 E7A00014 */  swc1      $f0, 0x14($sp)
/* BA1984 80241254 C6400014 */  lwc1      $f0, 0x14($s2)
/* BA1988 80241258 46800020 */  cvt.s.w   $f0, $f0
/* BA198C 8024125C E7A00018 */  swc1      $f0, 0x18($sp)
/* BA1990 80241260 8E440004 */  lw        $a0, 4($s2)
/* BA1994 80241264 8E270038 */  lw        $a3, 0x38($s1)
/* BA1998 80241268 0C0123F5 */  jal       is_point_within_region
/* BA199C 8024126C 26330040 */   addiu    $s3, $s1, 0x40
/* BA19A0 80241270 1040005A */  beqz      $v0, .L802413DC
/* BA19A4 80241274 00000000 */   nop
/* BA19A8 80241278 8E430004 */  lw        $v1, 4($s2)
/* BA19AC 8024127C 10600005 */  beqz      $v1, .L80241294
/* BA19B0 80241280 24020001 */   addiu    $v0, $zero, 1
/* BA19B4 80241284 10620029 */  beq       $v1, $v0, .L8024132C
/* BA19B8 80241288 00000000 */   nop
/* BA19BC 8024128C 080904F7 */  j         .L802413DC
/* BA19C0 80241290 00000000 */   nop
.L80241294:
/* BA19C4 80241294 C6480008 */  lwc1      $f8, 8($s2)
/* BA19C8 80241298 46804220 */  cvt.s.w   $f8, $f8
/* BA19CC 8024129C 44064000 */  mfc1      $a2, $f8
/* BA19D0 802412A0 C648000C */  lwc1      $f8, 0xc($s2)
/* BA19D4 802412A4 46804220 */  cvt.s.w   $f8, $f8
/* BA19D8 802412A8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BA19DC 802412AC C62E0040 */  lwc1      $f14, 0x40($s1)
/* BA19E0 802412B0 44074000 */  mfc1      $a3, $f8
/* BA19E4 802412B4 0C00A7B5 */  jal       dist2D
/* BA19E8 802412B8 00000000 */   nop
/* BA19EC 802412BC C6420010 */  lwc1      $f2, 0x10($s2)
/* BA19F0 802412C0 468010A0 */  cvt.s.w   $f2, $f2
/* BA19F4 802412C4 4600103C */  c.lt.s    $f2, $f0
/* BA19F8 802412C8 00000000 */  nop
/* BA19FC 802412CC 45000043 */  bc1f      .L802413DC
/* BA1A00 802412D0 E7A00038 */   swc1     $f0, 0x38($sp)
/* BA1A04 802412D4 C64C0008 */  lwc1      $f12, 8($s2)
/* BA1A08 802412D8 46806320 */  cvt.s.w   $f12, $f12
/* BA1A0C 802412DC 8E260038 */  lw        $a2, 0x38($s1)
/* BA1A10 802412E0 8E270040 */  lw        $a3, 0x40($s1)
/* BA1A14 802412E4 C64E000C */  lwc1      $f14, 0xc($s2)
/* BA1A18 802412E8 0C00A720 */  jal       atan2
/* BA1A1C 802412EC 468073A0 */   cvt.s.w  $f14, $f14
/* BA1A20 802412F0 0200202D */  daddu     $a0, $s0, $zero
/* BA1A24 802412F4 44070000 */  mfc1      $a3, $f0
/* BA1A28 802412F8 C6400008 */  lwc1      $f0, 8($s2)
/* BA1A2C 802412FC 46800020 */  cvt.s.w   $f0, $f0
/* BA1A30 80241300 E6200038 */  swc1      $f0, 0x38($s1)
/* BA1A34 80241304 C640000C */  lwc1      $f0, 0xc($s2)
/* BA1A38 80241308 46800020 */  cvt.s.w   $f0, $f0
/* BA1A3C 8024130C E6200040 */  swc1      $f0, 0x40($s1)
/* BA1A40 80241310 C6480010 */  lwc1      $f8, 0x10($s2)
/* BA1A44 80241314 46804220 */  cvt.s.w   $f8, $f8
/* BA1A48 80241318 44064000 */  mfc1      $a2, $f8
/* BA1A4C 8024131C 0C00A7E7 */  jal       add_vec2D_polar
/* BA1A50 80241320 0260282D */   daddu    $a1, $s3, $zero
/* BA1A54 80241324 080904F7 */  j         .L802413DC
/* BA1A58 80241328 00000000 */   nop
.L8024132C:
/* BA1A5C 8024132C 8E420008 */  lw        $v0, 8($s2)
/* BA1A60 80241330 8E430010 */  lw        $v1, 0x10($s2)
/* BA1A64 80241334 C6200038 */  lwc1      $f0, 0x38($s1)
/* BA1A68 80241338 00431021 */  addu      $v0, $v0, $v1
/* BA1A6C 8024133C 44821000 */  mtc1      $v0, $f2
/* BA1A70 80241340 00000000 */  nop
/* BA1A74 80241344 468010A0 */  cvt.s.w   $f2, $f2
/* BA1A78 80241348 4600103C */  c.lt.s    $f2, $f0
/* BA1A7C 8024134C 00000000 */  nop
/* BA1A80 80241350 45030001 */  bc1tl     .L80241358
/* BA1A84 80241354 E6220038 */   swc1     $f2, 0x38($s1)
.L80241358:
/* BA1A88 80241358 8E420008 */  lw        $v0, 8($s2)
/* BA1A8C 8024135C 8E430010 */  lw        $v1, 0x10($s2)
/* BA1A90 80241360 C6200038 */  lwc1      $f0, 0x38($s1)
/* BA1A94 80241364 00431023 */  subu      $v0, $v0, $v1
/* BA1A98 80241368 44821000 */  mtc1      $v0, $f2
/* BA1A9C 8024136C 00000000 */  nop
/* BA1AA0 80241370 468010A0 */  cvt.s.w   $f2, $f2
/* BA1AA4 80241374 4602003C */  c.lt.s    $f0, $f2
/* BA1AA8 80241378 00000000 */  nop
/* BA1AAC 8024137C 45030001 */  bc1tl     .L80241384
/* BA1AB0 80241380 E6220038 */   swc1     $f2, 0x38($s1)
.L80241384:
/* BA1AB4 80241384 8E42000C */  lw        $v0, 0xc($s2)
/* BA1AB8 80241388 8E430014 */  lw        $v1, 0x14($s2)
/* BA1ABC 8024138C C6200040 */  lwc1      $f0, 0x40($s1)
/* BA1AC0 80241390 00431021 */  addu      $v0, $v0, $v1
/* BA1AC4 80241394 44821000 */  mtc1      $v0, $f2
/* BA1AC8 80241398 00000000 */  nop
/* BA1ACC 8024139C 468010A0 */  cvt.s.w   $f2, $f2
/* BA1AD0 802413A0 4600103C */  c.lt.s    $f2, $f0
/* BA1AD4 802413A4 00000000 */  nop
/* BA1AD8 802413A8 45030001 */  bc1tl     .L802413B0
/* BA1ADC 802413AC E6220040 */   swc1     $f2, 0x40($s1)
.L802413B0:
/* BA1AE0 802413B0 8E42000C */  lw        $v0, 0xc($s2)
/* BA1AE4 802413B4 8E430014 */  lw        $v1, 0x14($s2)
/* BA1AE8 802413B8 C6200040 */  lwc1      $f0, 0x40($s1)
/* BA1AEC 802413BC 00431023 */  subu      $v0, $v0, $v1
/* BA1AF0 802413C0 44821000 */  mtc1      $v0, $f2
/* BA1AF4 802413C4 00000000 */  nop
/* BA1AF8 802413C8 468010A0 */  cvt.s.w   $f2, $f2
/* BA1AFC 802413CC 4602003C */  c.lt.s    $f0, $f2
/* BA1B00 802413D0 00000000 */  nop
/* BA1B04 802413D4 45030001 */  bc1tl     .L802413DC
/* BA1B08 802413D8 E6220040 */   swc1     $f2, 0x40($s1)
.L802413DC:
/* BA1B0C 802413DC 16E0001F */  bnez      $s7, .L8024145C
/* BA1B10 802413E0 00000000 */   nop
/* BA1B14 802413E4 8E220000 */  lw        $v0, ($s1)
/* BA1B18 802413E8 30420008 */  andi      $v0, $v0, 8
/* BA1B1C 802413EC 10400003 */  beqz      $v0, .L802413FC
/* BA1B20 802413F0 27A50020 */   addiu    $a1, $sp, 0x20
/* BA1B24 802413F4 13C00019 */  beqz      $fp, .L8024145C
/* BA1B28 802413F8 00000000 */   nop
.L802413FC:
/* BA1B2C 802413FC 27A60024 */  addiu     $a2, $sp, 0x24
/* BA1B30 80241400 27A20038 */  addiu     $v0, $sp, 0x38
/* BA1B34 80241404 C6220038 */  lwc1      $f2, 0x38($s1)
/* BA1B38 80241408 C620003C */  lwc1      $f0, 0x3c($s1)
/* BA1B3C 8024140C 3C0143C8 */  lui       $at, 0x43c8
/* BA1B40 80241410 44813000 */  mtc1      $at, $f6
/* BA1B44 80241414 46000021 */  cvt.d.s   $f0, $f0
/* BA1B48 80241418 E7A20020 */  swc1      $f2, 0x20($sp)
/* BA1B4C 8024141C 3C018024 */  lui       $at, %hi(D_80244040_BA4770)
/* BA1B50 80241420 D4224040 */  ldc1      $f2, %lo(D_80244040_BA4770)($at)
/* BA1B54 80241424 C6240040 */  lwc1      $f4, 0x40($s1)
/* BA1B58 80241428 46220000 */  add.d     $f0, $f0, $f2
/* BA1B5C 8024142C E7A60038 */  swc1      $f6, 0x38($sp)
/* BA1B60 80241430 E7A40028 */  swc1      $f4, 0x28($sp)
/* BA1B64 80241434 46200020 */  cvt.s.d   $f0, $f0
/* BA1B68 80241438 E7A00024 */  swc1      $f0, 0x24($sp)
/* BA1B6C 8024143C AFA20010 */  sw        $v0, 0x10($sp)
/* BA1B70 80241440 8E240080 */  lw        $a0, 0x80($s1)
/* BA1B74 80241444 0C0372DF */  jal       npc_raycast_down_sides
/* BA1B78 80241448 27A70028 */   addiu    $a3, $sp, 0x28
/* BA1B7C 8024144C 10400003 */  beqz      $v0, .L8024145C
/* BA1B80 80241450 00000000 */   nop
/* BA1B84 80241454 C7A00024 */  lwc1      $f0, 0x24($sp)
/* BA1B88 80241458 E620003C */  swc1      $f0, 0x3c($s1)
.L8024145C:
/* BA1B8C 8024145C C62C0038 */  lwc1      $f12, 0x38($s1)
/* BA1B90 80241460 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA1B94 80241464 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA1B98 80241468 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BA1B9C 8024146C 8C460028 */  lw        $a2, 0x28($v0)
/* BA1BA0 80241470 0C00A720 */  jal       atan2
/* BA1BA4 80241474 8C470030 */   lw       $a3, 0x30($v0)
/* BA1BA8 80241478 0220202D */  daddu     $a0, $s1, $zero
/* BA1BAC 8024147C 24050321 */  addiu     $a1, $zero, 0x321
/* BA1BB0 80241480 0000302D */  daddu     $a2, $zero, $zero
/* BA1BB4 80241484 0C012530 */  jal       ai_enemy_play_sound
/* BA1BB8 80241488 E620000C */   swc1     $f0, 0xc($s1)
/* BA1BBC 8024148C 8EC200CC */  lw        $v0, 0xcc($s6)
/* BA1BC0 80241490 8C420024 */  lw        $v0, 0x24($v0)
/* BA1BC4 80241494 AE220028 */  sw        $v0, 0x28($s1)
/* BA1BC8 80241498 96C20096 */  lhu       $v0, 0x96($s6)
/* BA1BCC 8024149C A622008E */  sh        $v0, 0x8e($s1)
/* BA1BD0 802414A0 8FA80080 */  lw        $t0, 0x80($sp)
/* BA1BD4 802414A4 2402000B */  addiu     $v0, $zero, 0xb
/* BA1BD8 802414A8 AD020070 */  sw        $v0, 0x70($t0)
.L802414AC:
/* BA1BDC 802414AC 8FBF0064 */  lw        $ra, 0x64($sp)
/* BA1BE0 802414B0 8FBE0060 */  lw        $fp, 0x60($sp)
/* BA1BE4 802414B4 8FB7005C */  lw        $s7, 0x5c($sp)
/* BA1BE8 802414B8 8FB60058 */  lw        $s6, 0x58($sp)
/* BA1BEC 802414BC 8FB50054 */  lw        $s5, 0x54($sp)
/* BA1BF0 802414C0 8FB40050 */  lw        $s4, 0x50($sp)
/* BA1BF4 802414C4 8FB3004C */  lw        $s3, 0x4c($sp)
/* BA1BF8 802414C8 8FB20048 */  lw        $s2, 0x48($sp)
/* BA1BFC 802414CC 8FB10044 */  lw        $s1, 0x44($sp)
/* BA1C00 802414D0 8FB00040 */  lw        $s0, 0x40($sp)
/* BA1C04 802414D4 D7B80078 */  ldc1      $f24, 0x78($sp)
/* BA1C08 802414D8 D7B60070 */  ldc1      $f22, 0x70($sp)
/* BA1C0C 802414DC D7B40068 */  ldc1      $f20, 0x68($sp)
/* BA1C10 802414E0 03E00008 */  jr        $ra
/* BA1C14 802414E4 27BD0080 */   addiu    $sp, $sp, 0x80
