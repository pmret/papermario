.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ResetCam
/* 0F1278 802CC8C8 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0F127C 802CC8CC AFB1005C */  sw    $s1, 0x5c($sp)
/* 0F1280 802CC8D0 0080882D */  daddu $s1, $a0, $zero
/* 0F1284 802CC8D4 AFB20060 */  sw    $s2, 0x60($sp)
/* 0F1288 802CC8D8 00A0902D */  daddu $s2, $a1, $zero
/* 0F128C 802CC8DC AFBF0064 */  sw    $ra, 0x64($sp)
/* 0F1290 802CC8E0 AFB00058 */  sw    $s0, 0x58($sp)
/* 0F1294 802CC8E4 F7BA0080 */  sdc1  $f26, 0x80($sp)
/* 0F1298 802CC8E8 F7B80078 */  sdc1  $f24, 0x78($sp)
/* 0F129C 802CC8EC F7B60070 */  sdc1  $f22, 0x70($sp)
/* 0F12A0 802CC8F0 F7B40068 */  sdc1  $f20, 0x68($sp)
/* 0F12A4 802CC8F4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F12A8 802CC8F8 8E050000 */  lw    $a1, ($s0)
/* 0F12AC 802CC8FC 0C0B1EAF */  jal   get_variable
/* 0F12B0 802CC900 26100004 */   addiu $s0, $s0, 4
/* 0F12B4 802CC904 0220202D */  daddu $a0, $s1, $zero
/* 0F12B8 802CC908 3C06800B */  lui   $a2, 0x800b
/* 0F12BC 802CC90C 24C61D80 */  addiu $a2, $a2, 0x1d80
/* 0F12C0 802CC910 00021880 */  sll   $v1, $v0, 2
/* 0F12C4 802CC914 00621821 */  addu  $v1, $v1, $v0
/* 0F12C8 802CC918 00031880 */  sll   $v1, $v1, 2
/* 0F12CC 802CC91C 00621823 */  subu  $v1, $v1, $v0
/* 0F12D0 802CC920 000310C0 */  sll   $v0, $v1, 3
/* 0F12D4 802CC924 00621821 */  addu  $v1, $v1, $v0
/* 0F12D8 802CC928 000318C0 */  sll   $v1, $v1, 3
/* 0F12DC 802CC92C 8E050000 */  lw    $a1, ($s0)
/* 0F12E0 802CC930 0C0B210B */  jal   get_float_variable
/* 0F12E4 802CC934 00668021 */   addu  $s0, $v1, $a2
/* 0F12E8 802CC938 3C038011 */  lui   $v1, 0x8011
/* 0F12EC 802CC93C 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F12F0 802CC940 12400047 */  beqz  $s2, .L802CCA60
/* 0F12F4 802CC944 46000686 */   mov.s $f26, $f0
/* 0F12F8 802CC948 3C0146FF */  lui   $at, 0x46ff
/* 0F12FC 802CC94C 3421FE00 */  ori   $at, $at, 0xfe00
/* 0F1300 802CC950 44811000 */  mtc1  $at, $f2
/* 0F1304 802CC954 44802000 */  mtc1  $zero, $f4
/* 0F1308 802CC958 3C01BF80 */  lui   $at, 0xbf80
/* 0F130C 802CC95C 44810000 */  mtc1  $at, $f0
/* 0F1310 802CC960 3C014120 */  lui   $at, 0x4120
/* 0F1314 802CC964 44817000 */  mtc1  $at, $f14
/* 0F1318 802CC968 27A20038 */  addiu $v0, $sp, 0x38
/* 0F131C 802CC96C E7A20044 */  swc1  $f2, 0x44($sp)
/* 0F1320 802CC970 AFA20018 */  sw    $v0, 0x18($sp)
/* 0F1324 802CC974 27A2003C */  addiu $v0, $sp, 0x3c
/* 0F1328 802CC978 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0F132C 802CC97C 27A20040 */  addiu $v0, $sp, 0x40
/* 0F1330 802CC980 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F1334 802CC984 27A20044 */  addiu $v0, $sp, 0x44
/* 0F1338 802CC988 AFA20024 */  sw    $v0, 0x24($sp)
/* 0F133C 802CC98C 27A20048 */  addiu $v0, $sp, 0x48
/* 0F1340 802CC990 AFA20028 */  sw    $v0, 0x28($sp)
/* 0F1344 802CC994 27A2004C */  addiu $v0, $sp, 0x4c
/* 0F1348 802CC998 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0F134C 802CC99C E7A40014 */  swc1  $f4, 0x14($sp)
/* 0F1350 802CC9A0 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F1354 802CC9A4 C478002C */  lwc1  $f24, 0x2c($v1)
/* 0F1358 802CC9A8 27A20050 */  addiu $v0, $sp, 0x50
/* 0F135C 802CC9AC AFA20030 */  sw    $v0, 0x30($sp)
/* 0F1360 802CC9B0 C4760030 */  lwc1  $f22, 0x30($v1)
/* 0F1364 802CC9B4 C4740028 */  lwc1  $f20, 0x28($v1)
/* 0F1368 802CC9B8 44072000 */  mfc1  $a3, $f4
/* 0F136C 802CC9BC 460EC380 */  add.s $f14, $f24, $f14
/* 0F1370 802CC9C0 4406B000 */  mfc1  $a2, $f22
/* 0F1374 802CC9C4 0C017449 */  jal   test_ray_zones
/* 0F1378 802CC9C8 4600A306 */   mov.s $f12, $f20
/* 0F137C 802CC9CC 0040182D */  daddu $v1, $v0, $zero
/* 0F1380 802CC9D0 0460001A */  bltz  $v1, .L802CCA3C
/* 0F1384 802CC9D4 000310C0 */   sll   $v0, $v1, 3
/* 0F1388 802CC9D8 00431023 */  subu  $v0, $v0, $v1
/* 0F138C 802CC9DC 3C03800E */  lui   $v1, 0x800e
/* 0F1390 802CC9E0 8C6391D4 */  lw    $v1, -0x6e2c($v1)
/* 0F1394 802CC9E4 00021080 */  sll   $v0, $v0, 2
/* 0F1398 802CC9E8 00431021 */  addu  $v0, $v0, $v1
/* 0F139C 802CC9EC 8C420010 */  lw    $v0, 0x10($v0)
/* 0F13A0 802CC9F0 260304D8 */  addiu $v1, $s0, 0x4d8
/* 0F13A4 802CC9F4 24440020 */  addiu $a0, $v0, 0x20
.L802CC9F8:
/* 0F13A8 802CC9F8 8C480000 */  lw    $t0, ($v0)
/* 0F13AC 802CC9FC 8C490004 */  lw    $t1, 4($v0)
/* 0F13B0 802CCA00 8C4A0008 */  lw    $t2, 8($v0)
/* 0F13B4 802CCA04 8C4B000C */  lw    $t3, 0xc($v0)
/* 0F13B8 802CCA08 AC680000 */  sw    $t0, ($v1)
/* 0F13BC 802CCA0C AC690004 */  sw    $t1, 4($v1)
/* 0F13C0 802CCA10 AC6A0008 */  sw    $t2, 8($v1)
/* 0F13C4 802CCA14 AC6B000C */  sw    $t3, 0xc($v1)
/* 0F13C8 802CCA18 24420010 */  addiu $v0, $v0, 0x10
/* 0F13CC 802CCA1C 1444FFF6 */  bne   $v0, $a0, .L802CC9F8
/* 0F13D0 802CCA20 24630010 */   addiu $v1, $v1, 0x10
/* 0F13D4 802CCA24 8C480000 */  lw    $t0, ($v0)
/* 0F13D8 802CCA28 8C490004 */  lw    $t1, 4($v0)
/* 0F13DC 802CCA2C 8C4A0008 */  lw    $t2, 8($v0)
/* 0F13E0 802CCA30 AC680000 */  sw    $t0, ($v1)
/* 0F13E4 802CCA34 AC690004 */  sw    $t1, 4($v1)
/* 0F13E8 802CCA38 AC6A0008 */  sw    $t2, 8($v1)
.L802CCA3C:
/* 0F13EC 802CCA3C 0000102D */  daddu $v0, $zero, $zero
/* 0F13F0 802CCA40 24030001 */  addiu $v1, $zero, 1
/* 0F13F4 802CCA44 E61404B0 */  swc1  $f20, 0x4b0($s0)
/* 0F13F8 802CCA48 E61804B4 */  swc1  $f24, 0x4b4($s0)
/* 0F13FC 802CCA4C E61604B8 */  swc1  $f22, 0x4b8($s0)
/* 0F1400 802CCA50 E61A0490 */  swc1  $f26, 0x490($s0)
/* 0F1404 802CCA54 A6030506 */  sh    $v1, 0x506($s0)
/* 0F1408 802CCA58 080B32A5 */  j     .L802CCA94
/* 0F140C 802CCA5C A6030504 */   sh    $v1, 0x504($s0)

.L802CCA60:
/* 0F1410 802CCA60 C6000484 */  lwc1  $f0, 0x484($s0)
/* 0F1414 802CCA64 3C013F80 */  lui   $at, 0x3f80
/* 0F1418 802CCA68 44811000 */  mtc1  $at, $f2
/* 0F141C 802CCA6C 00000000 */  nop   
/* 0F1420 802CCA70 4600103E */  c.le.s $f2, $f0
/* 0F1424 802CCA74 00000000 */  nop   
/* 0F1428 802CCA78 45000007 */  bc1f  .L802CCA98
/* 0F142C 802CCA7C 0000102D */   daddu $v0, $zero, $zero
/* 0F1430 802CCA80 24020002 */  addiu $v0, $zero, 2
/* 0F1434 802CCA84 24030001 */  addiu $v1, $zero, 1
/* 0F1438 802CCA88 A6030506 */  sh    $v1, 0x506($s0)
/* 0F143C 802CCA8C A6000504 */  sh    $zero, 0x504($s0)
/* 0F1440 802CCA90 E6020490 */  swc1  $f2, 0x490($s0)
.L802CCA94:
/* 0F1444 802CCA94 AE000508 */  sw    $zero, 0x508($s0)
.L802CCA98:
/* 0F1448 802CCA98 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0F144C 802CCA9C 8FB20060 */  lw    $s2, 0x60($sp)
/* 0F1450 802CCAA0 8FB1005C */  lw    $s1, 0x5c($sp)
/* 0F1454 802CCAA4 8FB00058 */  lw    $s0, 0x58($sp)
/* 0F1458 802CCAA8 D7BA0080 */  ldc1  $f26, 0x80($sp)
/* 0F145C 802CCAAC D7B80078 */  ldc1  $f24, 0x78($sp)
/* 0F1460 802CCAB0 D7B60070 */  ldc1  $f22, 0x70($sp)
/* 0F1464 802CCAB4 D7B40068 */  ldc1  $f20, 0x68($sp)
/* 0F1468 802CCAB8 03E00008 */  jr    $ra
/* 0F146C 802CCABC 27BD0088 */   addiu $sp, $sp, 0x88

/* 0F1470 802CCAC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1474 802CCAC4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1478 802CCAC8 0000802D */  daddu $s0, $zero, $zero
/* 0F147C 802CCACC AFBF0014 */  sw    $ra, 0x14($sp)
.L802CCAD0:
/* 0F1480 802CCAD0 3C03802E */  lui   $v1, 0x802e
/* 0F1484 802CCAD4 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F1488 802CCAD8 00101080 */  sll   $v0, $s0, 2
/* 0F148C 802CCADC 00431021 */  addu  $v0, $v0, $v1
/* 0F1490 802CCAE0 8C420000 */  lw    $v0, ($v0)
/* 0F1494 802CCAE4 8C440000 */  lw    $a0, ($v0)
/* 0F1498 802CCAE8 04820004 */  bltzl $a0, .L802CCAFC
/* 0F149C 802CCAEC 26100001 */   addiu $s0, $s0, 1
/* 0F14A0 802CCAF0 0C047A95 */  jal   func_8011EA54
/* 0F14A4 802CCAF4 24450028 */   addiu $a1, $v0, 0x28
/* 0F14A8 802CCAF8 26100001 */  addiu $s0, $s0, 1
.L802CCAFC:
/* 0F14AC 802CCAFC 2A020010 */  slti  $v0, $s0, 0x10
/* 0F14B0 802CCB00 1440FFF3 */  bnez  $v0, .L802CCAD0
/* 0F14B4 802CCB04 00000000 */   nop   
/* 0F14B8 802CCB08 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F14BC 802CCB0C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F14C0 802CCB10 03E00008 */  jr    $ra
/* 0F14C4 802CCB14 27BD0018 */   addiu $sp, $sp, 0x18

