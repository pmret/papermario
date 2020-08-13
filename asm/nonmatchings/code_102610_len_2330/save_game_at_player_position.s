.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel save_game_at_player_position
/* 102A20 802E11A0 3C04800F */  lui   $a0, 0x800f
/* 102A24 802E11A4 8C847B30 */  lw    $a0, 0x7b30($a0)
/* 102A28 802E11A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102A2C 802E11AC AFBF0010 */  sw    $ra, 0x10($sp)
/* 102A30 802E11B0 C4800028 */  lwc1  $f0, 0x28($a0)
/* 102A34 802E11B4 3C038007 */  lui   $v1, 0x8007
/* 102A38 802E11B8 8C63419C */  lw    $v1, 0x419c($v1)
/* 102A3C 802E11BC 4600008D */  trunc.w.s $f2, $f0
/* 102A40 802E11C0 44021000 */  mfc1  $v0, $f2
/* 102A44 802E11C4 00000000 */  nop   
/* 102A48 802E11C8 A4620160 */  sh    $v0, 0x160($v1)
/* 102A4C 802E11CC C480002C */  lwc1  $f0, 0x2c($a0)
/* 102A50 802E11D0 4600008D */  trunc.w.s $f2, $f0
/* 102A54 802E11D4 44021000 */  mfc1  $v0, $f2
/* 102A58 802E11D8 00000000 */  nop   
/* 102A5C 802E11DC A4620162 */  sh    $v0, 0x162($v1)
/* 102A60 802E11E0 C4800030 */  lwc1  $f0, 0x30($a0)
/* 102A64 802E11E4 90640166 */  lbu   $a0, 0x166($v1)
/* 102A68 802E11E8 4600008D */  trunc.w.s $f2, $f0
/* 102A6C 802E11EC 44021000 */  mfc1  $v0, $f2
/* 102A70 802E11F0 0C00ACDD */  jal   fio_save_game
/* 102A74 802E11F4 A4620164 */   sh    $v0, 0x164($v1)
/* 102A78 802E11F8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 102A7C 802E11FC 03E00008 */  jr    $ra
/* 102A80 802E1200 27BD0018 */   addiu $sp, $sp, 0x18

/* 102A84 802E1204 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102A88 802E1208 AFB00010 */  sw    $s0, 0x10($sp)
/* 102A8C 802E120C 0080802D */  daddu $s0, $a0, $zero
/* 102A90 802E1210 3C04F840 */  lui   $a0, 0xf840
/* 102A94 802E1214 AFBF0014 */  sw    $ra, 0x14($sp)
/* 102A98 802E1218 0C05152F */  jal   get_global_flag
/* 102A9C 802E121C 34845BDF */   ori   $a0, $a0, 0x5bdf
/* 102AA0 802E1220 1440000B */  bnez  $v0, .L802E1250
/* 102AA4 802E1224 00000000 */   nop   
/* 102AA8 802E1228 3C05802F */  lui   $a1, 0x802f
/* 102AAC 802E122C 24A5B390 */  addiu $a1, $a1, -0x4c70
/* 102AB0 802E1230 ACA00000 */  sw    $zero, ($a1)
/* 102AB4 802E1234 0C049640 */  jal   load_string
/* 102AB8 802E1238 3C04001D */   lui   $a0, 0x1d
/* 102ABC 802E123C 3C04F840 */  lui   $a0, 0xf840
/* 102AC0 802E1240 0C051514 */  jal   set_global_flag
/* 102AC4 802E1244 34845BDF */   ori   $a0, $a0, 0x5bdf
/* 102AC8 802E1248 080B8498 */  j     .L802E1260
/* 102ACC 802E124C 00000000 */   nop   

.L802E1250:
/* 102AD0 802E1250 0C043F5A */  jal   func_8010FD68
/* 102AD4 802E1254 0200202D */   daddu $a0, $s0, $zero
/* 102AD8 802E1258 0C043F5A */  jal   func_8010FD68
/* 102ADC 802E125C 0200202D */   daddu $a0, $s0, $zero
.L802E1260:
/* 102AE0 802E1260 8FBF0014 */  lw    $ra, 0x14($sp)
/* 102AE4 802E1264 8FB00010 */  lw    $s0, 0x10($sp)
/* 102AE8 802E1268 03E00008 */  jr    $ra
/* 102AEC 802E126C 27BD0018 */   addiu $sp, $sp, 0x18

/* 102AF0 802E1270 3C02802F */  lui   $v0, 0x802f
/* 102AF4 802E1274 8C42B390 */  lw    $v0, -0x4c70($v0)
/* 102AF8 802E1278 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102AFC 802E127C 10400003 */  beqz  $v0, .L802E128C
/* 102B00 802E1280 AFBF0010 */   sw    $ra, 0x10($sp)
/* 102B04 802E1284 0C043F5A */  jal   func_8010FD68
/* 102B08 802E1288 00000000 */   nop   
.L802E128C:
/* 102B0C 802E128C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 102B10 802E1290 03E00008 */  jr    $ra
/* 102B14 802E1294 27BD0018 */   addiu $sp, $sp, 0x18

/* 102B18 802E1298 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102B1C 802E129C 3C04001D */  lui   $a0, 0x1d
/* 102B20 802E12A0 34840004 */  ori   $a0, $a0, 4
/* 102B24 802E12A4 3C05802F */  lui   $a1, 0x802f
/* 102B28 802E12A8 24A5B394 */  addiu $a1, $a1, -0x4c6c
/* 102B2C 802E12AC AFB00010 */  sw    $s0, 0x10($sp)
/* 102B30 802E12B0 3C10802F */  lui   $s0, 0x802f
/* 102B34 802E12B4 2610B390 */  addiu $s0, $s0, -0x4c70
/* 102B38 802E12B8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 102B3C 802E12BC AE000000 */  sw    $zero, ($s0)
/* 102B40 802E12C0 0C049640 */  jal   load_string
/* 102B44 802E12C4 ACA00000 */   sw    $zero, ($a1)
/* 102B48 802E12C8 3C04001E */  lui   $a0, 0x1e
/* 102B4C 802E12CC 3484000A */  ori   $a0, $a0, 0xa
/* 102B50 802E12D0 3C01802F */  lui   $at, 0x802f
/* 102B54 802E12D4 AC22B39C */  sw    $v0, -0x4c64($at)
/* 102B58 802E12D8 0C049640 */  jal   load_string
/* 102B5C 802E12DC 0200282D */   daddu $a1, $s0, $zero
/* 102B60 802E12E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 102B64 802E12E4 8FB00010 */  lw    $s0, 0x10($sp)
/* 102B68 802E12E8 3C01802F */  lui   $at, 0x802f
/* 102B6C 802E12EC AC22B398 */  sw    $v0, -0x4c68($at)
/* 102B70 802E12F0 03E00008 */  jr    $ra
/* 102B74 802E12F4 27BD0018 */   addiu $sp, $sp, 0x18

/* 102B78 802E12F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102B7C 802E12FC 3C04001D */  lui   $a0, 0x1d
/* 102B80 802E1300 3C05802F */  lui   $a1, 0x802f
/* 102B84 802E1304 8CA5B39C */  lw    $a1, -0x4c64($a1)
/* 102B88 802E1308 AFBF0010 */  sw    $ra, 0x10($sp)
/* 102B8C 802E130C 0C04969A */  jal   load_message_to_printer
/* 102B90 802E1310 34840005 */   ori   $a0, $a0, 5
/* 102B94 802E1314 0C05272D */  jal   play_sound
/* 102B98 802E1318 24040010 */   addiu $a0, $zero, 0x10
/* 102B9C 802E131C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 102BA0 802E1320 03E00008 */  jr    $ra
/* 102BA4 802E1324 27BD0018 */   addiu $sp, $sp, 0x18

/* 102BA8 802E1328 3C02802F */  lui   $v0, 0x802f
/* 102BAC 802E132C 8C42B394 */  lw    $v0, -0x4c6c($v0)
/* 102BB0 802E1330 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102BB4 802E1334 10400003 */  beqz  $v0, .L802E1344
/* 102BB8 802E1338 AFBF0010 */   sw    $ra, 0x10($sp)
/* 102BBC 802E133C 0C043F5A */  jal   func_8010FD68
/* 102BC0 802E1340 00000000 */   nop   
.L802E1344:
/* 102BC4 802E1344 8FBF0010 */  lw    $ra, 0x10($sp)
/* 102BC8 802E1348 03E00008 */  jr    $ra
/* 102BCC 802E134C 27BD0018 */   addiu $sp, $sp, 0x18

/* 102BD0 802E1350 3C02802F */  lui   $v0, 0x802f
/* 102BD4 802E1354 8C42B390 */  lw    $v0, -0x4c70($v0)
/* 102BD8 802E1358 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102BDC 802E135C 10400013 */  beqz  $v0, .L802E13AC
/* 102BE0 802E1360 AFBF0010 */   sw    $ra, 0x10($sp)
/* 102BE4 802E1364 3C02802F */  lui   $v0, 0x802f
/* 102BE8 802E1368 8C42B398 */  lw    $v0, -0x4c68($v0)
/* 102BEC 802E136C 904304E8 */  lbu   $v1, 0x4e8($v0)
/* 102BF0 802E1370 24020001 */  addiu $v0, $zero, 1
/* 102BF4 802E1374 14620007 */  bne   $v1, $v0, .L802E1394
/* 102BF8 802E1378 00000000 */   nop   
/* 102BFC 802E137C 3C05802F */  lui   $a1, 0x802f
/* 102C00 802E1380 24A599DC */  addiu $a1, $a1, -0x6624
/* 102C04 802E1384 0C043EF0 */  jal   func_8010FBC0
/* 102C08 802E1388 00000000 */   nop   
/* 102C0C 802E138C 080B84E7 */  j     .L802E139C
/* 102C10 802E1390 00000000 */   nop   

.L802E1394:
/* 102C14 802E1394 0C043F5A */  jal   func_8010FD68
/* 102C18 802E1398 00000000 */   nop   
.L802E139C:
/* 102C1C 802E139C 3C04802F */  lui   $a0, 0x802f
/* 102C20 802E13A0 8C84B39C */  lw    $a0, -0x4c64($a0)
/* 102C24 802E13A4 0C04971C */  jal   close_message
/* 102C28 802E13A8 00000000 */   nop   
.L802E13AC:
/* 102C2C 802E13AC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 102C30 802E13B0 03E00008 */  jr    $ra
/* 102C34 802E13B4 27BD0018 */   addiu $sp, $sp, 0x18

/* 102C38 802E13B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 102C3C 802E13BC AFB00010 */  sw    $s0, 0x10($sp)
/* 102C40 802E13C0 0080802D */  daddu $s0, $a0, $zero
/* 102C44 802E13C4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 102C48 802E13C8 AFB10014 */  sw    $s1, 0x14($sp)
/* 102C4C 802E13CC 0C0B8DB9 */  jal   func_802E36E4
/* 102C50 802E13D0 8E110040 */   lw    $s1, 0x40($s0)
/* 102C54 802E13D4 3C02802E */  lui   $v0, 0x802e
/* 102C58 802E13D8 24420DE0 */  addiu $v0, $v0, 0xde0
/* 102C5C 802E13DC AE02003C */  sw    $v0, 0x3c($s0)
/* 102C60 802E13E0 24020008 */  addiu $v0, $zero, 8
/* 102C64 802E13E4 A6220004 */  sh    $v0, 4($s1)
/* 102C68 802E13E8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 102C6C 802E13EC 8FB10014 */  lw    $s1, 0x14($sp)
/* 102C70 802E13F0 8FB00010 */  lw    $s0, 0x10($sp)
/* 102C74 802E13F4 03E00008 */  jr    $ra
/* 102C78 802E13F8 27BD0020 */   addiu $sp, $sp, 0x20

/* 102C7C 802E13FC 00000000 */  nop   
/* 102C80 802E1400 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102C84 802E1404 AFBF0014 */  sw    $ra, 0x14($sp)
/* 102C88 802E1408 AFB00010 */  sw    $s0, 0x10($sp)
/* 102C8C 802E140C 90820006 */  lbu   $v0, 6($a0)
/* 102C90 802E1410 8C900040 */  lw    $s0, 0x40($a0)
/* 102C94 802E1414 30420001 */  andi  $v0, $v0, 1
/* 102C98 802E1418 1040000D */  beqz  $v0, .L802E1450
/* 102C9C 802E141C 00000000 */   nop   
/* 102CA0 802E1420 3C028011 */  lui   $v0, 0x8011
/* 102CA4 802E1424 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 102CA8 802E1428 804300B4 */  lb    $v1, 0xb4($v0)
/* 102CAC 802E142C 2402000E */  addiu $v0, $zero, 0xe
/* 102CB0 802E1430 10620003 */  beq   $v1, $v0, .L802E1440
/* 102CB4 802E1434 24020010 */   addiu $v0, $zero, 0x10
/* 102CB8 802E1438 14620005 */  bne   $v1, $v0, .L802E1450
/* 102CBC 802E143C 00000000 */   nop   
.L802E1440:
/* 102CC0 802E1440 0C043F5A */  jal   func_8010FD68
/* 102CC4 802E1444 00000000 */   nop   
/* 102CC8 802E1448 24020008 */  addiu $v0, $zero, 8
/* 102CCC 802E144C A6020022 */  sh    $v0, 0x22($s0)
.L802E1450:
/* 102CD0 802E1450 8FBF0014 */  lw    $ra, 0x14($sp)
/* 102CD4 802E1454 8FB00010 */  lw    $s0, 0x10($sp)
/* 102CD8 802E1458 03E00008 */  jr    $ra
/* 102CDC 802E145C 27BD0018 */   addiu $sp, $sp, 0x18

/* 102CE0 802E1460 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 102CE4 802E1464 AFB10014 */  sw    $s1, 0x14($sp)
/* 102CE8 802E1468 0080882D */  daddu $s1, $a0, $zero
/* 102CEC 802E146C AFBF0018 */  sw    $ra, 0x18($sp)
/* 102CF0 802E1470 AFB00010 */  sw    $s0, 0x10($sp)
/* 102CF4 802E1474 8E300040 */  lw    $s0, 0x40($s1)
/* 102CF8 802E1478 96020022 */  lhu   $v0, 0x22($s0)
/* 102CFC 802E147C 2443FFFF */  addiu $v1, $v0, -1
/* 102D00 802E1480 3042FFFF */  andi  $v0, $v0, 0xffff
/* 102D04 802E1484 10400009 */  beqz  $v0, .L802E14AC
/* 102D08 802E1488 A6030022 */   sh    $v1, 0x22($s0)
/* 102D0C 802E148C C620004C */  lwc1  $f0, 0x4c($s1)
/* 102D10 802E1490 3C01802F */  lui   $at, 0x802f
/* 102D14 802E1494 D422B000 */  ldc1  $f2, -0x5000($at)
/* 102D18 802E1498 46000021 */  cvt.d.s $f0, $f0
/* 102D1C 802E149C 46220001 */  sub.d $f0, $f0, $f2
/* 102D20 802E14A0 46200020 */  cvt.s.d $f0, $f0
/* 102D24 802E14A4 080B8531 */  j     .L802E14C4
/* 102D28 802E14A8 E620004C */   swc1  $f0, 0x4c($s1)

.L802E14AC:
/* 102D2C 802E14AC 0C04419E */  jal   func_80110678
/* 102D30 802E14B0 0220202D */   daddu $a0, $s1, $zero
/* 102D34 802E14B4 0C043F5A */  jal   func_8010FD68
/* 102D38 802E14B8 0220202D */   daddu $a0, $s1, $zero
/* 102D3C 802E14BC 24020008 */  addiu $v0, $zero, 8
/* 102D40 802E14C0 A6020022 */  sh    $v0, 0x22($s0)
.L802E14C4:
/* 102D44 802E14C4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 102D48 802E14C8 8FB10014 */  lw    $s1, 0x14($sp)
/* 102D4C 802E14CC 8FB00010 */  lw    $s0, 0x10($sp)
/* 102D50 802E14D0 03E00008 */  jr    $ra
/* 102D54 802E14D4 27BD0020 */   addiu $sp, $sp, 0x20

/* 102D58 802E14D8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102D5C 802E14DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 102D60 802E14E0 AFB00010 */  sw    $s0, 0x10($sp)
/* 102D64 802E14E4 8C900040 */  lw    $s0, 0x40($a0)
/* 102D68 802E14E8 96020022 */  lhu   $v0, 0x22($s0)
/* 102D6C 802E14EC 2443FFFF */  addiu $v1, $v0, -1
/* 102D70 802E14F0 3042FFFF */  andi  $v0, $v0, 0xffff
/* 102D74 802E14F4 10400009 */  beqz  $v0, .L802E151C
/* 102D78 802E14F8 A6030022 */   sh    $v1, 0x22($s0)
/* 102D7C 802E14FC C480004C */  lwc1  $f0, 0x4c($a0)
/* 102D80 802E1500 3C01802F */  lui   $at, 0x802f
/* 102D84 802E1504 D422B008 */  ldc1  $f2, -0x4ff8($at)
/* 102D88 802E1508 46000021 */  cvt.d.s $f0, $f0
/* 102D8C 802E150C 46220000 */  add.d $f0, $f0, $f2
/* 102D90 802E1510 46200020 */  cvt.s.d $f0, $f0
/* 102D94 802E1514 080B854B */  j     .L802E152C
/* 102D98 802E1518 E480004C */   swc1  $f0, 0x4c($a0)

.L802E151C:
/* 102D9C 802E151C 0C043F5A */  jal   func_8010FD68
/* 102DA0 802E1520 00000000 */   nop   
/* 102DA4 802E1524 24020008 */  addiu $v0, $zero, 8
/* 102DA8 802E1528 A6020022 */  sh    $v0, 0x22($s0)
.L802E152C:
/* 102DAC 802E152C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 102DB0 802E1530 8FB00010 */  lw    $s0, 0x10($sp)
/* 102DB4 802E1534 03E00008 */  jr    $ra
/* 102DB8 802E1538 27BD0018 */   addiu $sp, $sp, 0x18

