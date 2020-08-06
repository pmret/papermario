.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800F102C
/* 08A4DC 800F102C 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 08A4E0 800F1030 3C090050 */  lui   $t1, 0x50
/* 08A4E4 800F1034 352903C0 */  ori   $t1, $t1, 0x3c0
/* 08A4E8 800F1038 3C0ADC08 */  lui   $t2, 0xdc08
/* 08A4EC 800F103C 354A0008 */  ori   $t2, $t2, 8
/* 08A4F0 800F1040 27A40020 */  addiu $a0, $sp, 0x20
/* 08A4F4 800F1044 AFB100A4 */  sw    $s1, 0xa4($sp)
/* 08A4F8 800F1048 3C110001 */  lui   $s1, 1
/* 08A4FC 800F104C 36311630 */  ori   $s1, $s1, 0x1630
/* 08A500 800F1050 AFB700BC */  sw    $s7, 0xbc($sp)
/* 08A504 800F1054 0000B82D */  daddu $s7, $zero, $zero
/* 08A508 800F1058 AFB600B8 */  sw    $s6, 0xb8($sp)
/* 08A50C 800F105C 27B60060 */  addiu $s6, $sp, 0x60
/* 08A510 800F1060 3C02800A */  lui   $v0, 0x800a
/* 08A514 800F1064 2442A674 */  addiu $v0, $v0, -0x598c
/* 08A518 800F1068 AFBE00C0 */  sw    $fp, 0xc0($sp)
/* 08A51C 800F106C 0040F02D */  daddu $fp, $v0, $zero
/* 08A520 800F1070 3C028007 */  lui   $v0, 0x8007
/* 08A524 800F1074 244241F0 */  addiu $v0, $v0, 0x41f0
/* 08A528 800F1078 AFB300AC */  sw    $s3, 0xac($sp)
/* 08A52C 800F107C 0040982D */  daddu $s3, $v0, $zero
/* 08A530 800F1080 AFB500B4 */  sw    $s5, 0xb4($sp)
/* 08A534 800F1084 3C150001 */  lui   $s5, 1
/* 08A538 800F1088 36B51630 */  ori   $s5, $s5, 0x1630
/* 08A53C 800F108C AFB400B0 */  sw    $s4, 0xb0($sp)
/* 08A540 800F1090 02E0A02D */  daddu $s4, $s7, $zero
/* 08A544 800F1094 AFB000A0 */  sw    $s0, 0xa0($sp)
/* 08A548 800F1098 3C10800A */  lui   $s0, 0x800a
/* 08A54C 800F109C 2610A66C */  addiu $s0, $s0, -0x5994
/* 08A550 800F10A0 3C02E700 */  lui   $v0, 0xe700
/* 08A554 800F10A4 AFBF00C4 */  sw    $ra, 0xc4($sp)
/* 08A558 800F10A8 AFB200A8 */  sw    $s2, 0xa8($sp)
/* 08A55C 800F10AC F7B600D0 */  sdc1  $f22, 0xd0($sp)
/* 08A560 800F10B0 F7B400C8 */  sdc1  $f20, 0xc8($sp)
/* 08A564 800F10B4 8E030000 */  lw    $v1, ($s0)
/* 08A568 800F10B8 3C0643A0 */  lui   $a2, 0x43a0
/* 08A56C 800F10BC 3C074370 */  lui   $a3, 0x4370
/* 08A570 800F10C0 44800000 */  mtc1  $zero, $f0
/* 08A574 800F10C4 3C0142C8 */  lui   $at, 0x42c8
/* 08A578 800F10C8 44811000 */  mtc1  $at, $f2
/* 08A57C 800F10CC 3C013F80 */  lui   $at, 0x3f80
/* 08A580 800F10D0 44812000 */  mtc1  $at, $f4
/* 08A584 800F10D4 0060402D */  daddu $t0, $v1, $zero
/* 08A588 800F10D8 44050000 */  mfc1  $a1, $f0
/* 08A58C 800F10DC 3C01C2C8 */  lui   $at, 0xc2c8
/* 08A590 800F10E0 44810000 */  mtc1  $at, $f0
/* 08A594 800F10E4 24630008 */  addiu $v1, $v1, 8
/* 08A598 800F10E8 AE030000 */  sw    $v1, ($s0)
/* 08A59C 800F10EC AD020000 */  sw    $v0, ($t0)
/* 08A5A0 800F10F0 24620008 */  addiu $v0, $v1, 8
/* 08A5A4 800F10F4 AD000004 */  sw    $zero, 4($t0)
/* 08A5A8 800F10F8 AE020000 */  sw    $v0, ($s0)
/* 08A5AC 800F10FC 3C02DB06 */  lui   $v0, 0xdb06
/* 08A5B0 800F1100 AC620000 */  sw    $v0, ($v1)
/* 08A5B4 800F1104 24620010 */  addiu $v0, $v1, 0x10
/* 08A5B8 800F1108 AC600004 */  sw    $zero, 4($v1)
/* 08A5BC 800F110C AE020000 */  sw    $v0, ($s0)
/* 08A5C0 800F1110 3C02ED00 */  lui   $v0, 0xed00
/* 08A5C4 800F1114 AC620008 */  sw    $v0, 8($v1)
/* 08A5C8 800F1118 24620018 */  addiu $v0, $v1, 0x18
/* 08A5CC 800F111C AC69000C */  sw    $t1, 0xc($v1)
/* 08A5D0 800F1120 AE020000 */  sw    $v0, ($s0)
/* 08A5D4 800F1124 4485B000 */  mtc1  $a1, $f22
/* 08A5D8 800F1128 3C028011 */  lui   $v0, 0x8011
/* 08A5DC 800F112C 244296B0 */  addiu $v0, $v0, -0x6950
/* 08A5E0 800F1130 AC6A0010 */  sw    $t2, 0x10($v1)
/* 08A5E4 800F1134 AC620014 */  sw    $v0, 0x14($v1)
/* 08A5E8 800F1138 E7A20018 */  swc1  $f2, 0x18($sp)
/* 08A5EC 800F113C E7A4001C */  swc1  $f4, 0x1c($sp)
/* 08A5F0 800F1140 AFA50010 */  sw    $a1, 0x10($sp)
/* 08A5F4 800F1144 0C018E44 */  jal   guOrthoF
/* 08A5F8 800F1148 E7A00014 */   swc1  $f0, 0x14($sp)
/* 08A5FC 800F114C 27A40020 */  addiu $a0, $sp, 0x20
/* 08A600 800F1150 96650000 */  lhu   $a1, ($s3)
/* 08A604 800F1154 8FC20000 */  lw    $v0, ($fp)
/* 08A608 800F1158 00052980 */  sll   $a1, $a1, 6
/* 08A60C 800F115C 00B12821 */  addu  $a1, $a1, $s1
/* 08A610 800F1160 0C019D40 */  jal   guMtxF2L
/* 08A614 800F1164 00452821 */   addu  $a1, $v0, $a1
/* 08A618 800F1168 3C03DA38 */  lui   $v1, 0xda38
/* 08A61C 800F116C 34630007 */  ori   $v1, $v1, 7
/* 08A620 800F1170 3C067F7F */  lui   $a2, 0x7f7f
/* 08A624 800F1174 34C67F7F */  ori   $a2, $a2, 0x7f7f
/* 08A628 800F1178 8E040000 */  lw    $a0, ($s0)
/* 08A62C 800F117C 96620000 */  lhu   $v0, ($s3)
/* 08A630 800F1180 0080282D */  daddu $a1, $a0, $zero
/* 08A634 800F1184 24840008 */  addiu $a0, $a0, 8
/* 08A638 800F1188 AE040000 */  sw    $a0, ($s0)
/* 08A63C 800F118C ACA30000 */  sw    $v1, ($a1)
/* 08A640 800F1190 24430001 */  addiu $v1, $v0, 1
/* 08A644 800F1194 3042FFFF */  andi  $v0, $v0, 0xffff
/* 08A648 800F1198 00021180 */  sll   $v0, $v0, 6
/* 08A64C 800F119C A6630000 */  sh    $v1, ($s3)
/* 08A650 800F11A0 8FC30000 */  lw    $v1, ($fp)
/* 08A654 800F11A4 00511021 */  addu  $v0, $v0, $s1
/* 08A658 800F11A8 00621821 */  addu  $v1, $v1, $v0
/* 08A65C 800F11AC 24820008 */  addiu $v0, $a0, 8
/* 08A660 800F11B0 ACA30004 */  sw    $v1, 4($a1)
/* 08A664 800F11B4 AE020000 */  sw    $v0, ($s0)
/* 08A668 800F11B8 3C02DE00 */  lui   $v0, 0xde00
/* 08A66C 800F11BC AC820000 */  sw    $v0, ($a0)
/* 08A670 800F11C0 3C028011 */  lui   $v0, 0x8011
/* 08A674 800F11C4 24429710 */  addiu $v0, $v0, -0x68f0
/* 08A678 800F11C8 AC820004 */  sw    $v0, 4($a0)
/* 08A67C 800F11CC 24820010 */  addiu $v0, $a0, 0x10
/* 08A680 800F11D0 AE020000 */  sw    $v0, ($s0)
/* 08A684 800F11D4 3C02FB00 */  lui   $v0, 0xfb00
/* 08A688 800F11D8 AC820008 */  sw    $v0, 8($a0)
/* 08A68C 800F11DC AC86000C */  sw    $a2, 0xc($a0)
.L800F11E0:
/* 08A690 800F11E0 3C0B8011 */  lui   $t3, 0x8011
/* 08A694 800F11E4 256BD000 */  addiu $t3, $t3, -0x3000
/* 08A698 800F11E8 028B1821 */  addu  $v1, $s4, $t3
/* 08A69C 800F11EC 90620000 */  lbu   $v0, ($v1)
/* 08A6A0 800F11F0 5040005C */  beql  $v0, $zero, .L800F1364
/* 08A6A4 800F11F4 26F70001 */   addiu $s7, $s7, 1
/* 08A6A8 800F11F8 C4740018 */  lwc1  $f20, 0x18($v1)
/* 08A6AC 800F11FC 24120001 */  addiu $s2, $zero, 1
/* 08A6B0 800F1200 3C11800A */  lui   $s1, 0x800a
/* 08A6B4 800F1204 2631A66C */  addiu $s1, $s1, -0x5994
/* 08A6B8 800F1208 24700022 */  addiu $s0, $v1, 0x22
.L800F120C:
/* 08A6BC 800F120C 82020001 */  lb    $v0, 1($s0)
/* 08A6C0 800F1210 0440004F */  bltz  $v0, .L800F1350
/* 08A6C4 800F1214 02C0202D */   daddu $a0, $s6, $zero
/* 08A6C8 800F1218 C6000012 */  lwc1  $f0, 0x12($s0)
/* 08A6CC 800F121C 4405B000 */  mfc1  $a1, $f22
/* 08A6D0 800F1220 3C028007 */  lui   $v0, 0x8007
/* 08A6D4 800F1224 8C42419C */  lw    $v0, 0x419c($v0)
/* 08A6D8 800F1228 4406B000 */  mfc1  $a2, $f22
/* 08A6DC 800F122C 94430134 */  lhu   $v1, 0x134($v0)
/* 08A6E0 800F1230 46140002 */  mul.s $f0, $f0, $f20
/* 08A6E4 800F1234 00000000 */  nop   
/* 08A6E8 800F1238 00031080 */  sll   $v0, $v1, 2
/* 08A6EC 800F123C 00431021 */  addu  $v0, $v0, $v1
/* 08A6F0 800F1240 00021040 */  sll   $v0, $v0, 1
/* 08A6F4 800F1244 44823000 */  mtc1  $v0, $f6
/* 08A6F8 800F1248 00000000 */  nop   
/* 08A6FC 800F124C 468031A0 */  cvt.s.w $f6, $f6
/* 08A700 800F1250 44073000 */  mfc1  $a3, $f6
/* 08A704 800F1254 E7A00010 */  swc1  $f0, 0x10($sp)
/* 08A708 800F1258 C6000002 */  lwc1  $f0, 2($s0)
/* 08A70C 800F125C E7A00014 */  swc1  $f0, 0x14($sp)
/* 08A710 800F1260 C6000006 */  lwc1  $f0, 6($s0)
/* 08A714 800F1264 E7B6001C */  swc1  $f22, 0x1c($sp)
/* 08A718 800F1268 0C018FC4 */  jal   guPositionF
/* 08A71C 800F126C E7A00018 */   swc1  $f0, 0x18($sp)
/* 08A720 800F1270 02C0202D */  daddu $a0, $s6, $zero
/* 08A724 800F1274 96650000 */  lhu   $a1, ($s3)
/* 08A728 800F1278 8FC20000 */  lw    $v0, ($fp)
/* 08A72C 800F127C 00052980 */  sll   $a1, $a1, 6
/* 08A730 800F1280 00B52821 */  addu  $a1, $a1, $s5
/* 08A734 800F1284 0C019D40 */  jal   guMtxF2L
/* 08A738 800F1288 00452821 */   addu  $a1, $v0, $a1
/* 08A73C 800F128C 3C08D838 */  lui   $t0, 0xd838
/* 08A740 800F1290 8E240000 */  lw    $a0, ($s1)
/* 08A744 800F1294 35080002 */  ori   $t0, $t0, 2
/* 08A748 800F1298 0080282D */  daddu $a1, $a0, $zero
/* 08A74C 800F129C 24840008 */  addiu $a0, $a0, 8
/* 08A750 800F12A0 AE240000 */  sw    $a0, ($s1)
/* 08A754 800F12A4 96620000 */  lhu   $v0, ($s3)
/* 08A758 800F12A8 3C03DA38 */  lui   $v1, 0xda38
/* 08A75C 800F12AC ACA30000 */  sw    $v1, ($a1)
/* 08A760 800F12B0 24430001 */  addiu $v1, $v0, 1
/* 08A764 800F12B4 3042FFFF */  andi  $v0, $v0, 0xffff
/* 08A768 800F12B8 00021180 */  sll   $v0, $v0, 6
/* 08A76C 800F12BC A6630000 */  sh    $v1, ($s3)
/* 08A770 800F12C0 8FC30000 */  lw    $v1, ($fp)
/* 08A774 800F12C4 00551021 */  addu  $v0, $v0, $s5
/* 08A778 800F12C8 00621821 */  addu  $v1, $v1, $v0
/* 08A77C 800F12CC 24820008 */  addiu $v0, $a0, 8
/* 08A780 800F12D0 ACA30004 */  sw    $v1, 4($a1)
/* 08A784 800F12D4 AE220000 */  sw    $v0, ($s1)
/* 08A788 800F12D8 82030001 */  lb    $v1, 1($s0)
/* 08A78C 800F12DC 24020050 */  addiu $v0, $zero, 0x50
/* 08A790 800F12E0 00431023 */  subu  $v0, $v0, $v1
/* 08A794 800F12E4 304200FF */  andi  $v0, $v0, 0xff
/* 08A798 800F12E8 3C03FA00 */  lui   $v1, 0xfa00
/* 08A79C 800F12EC 00431025 */  or    $v0, $v0, $v1
/* 08A7A0 800F12F0 AC820000 */  sw    $v0, ($a0)
/* 08A7A4 800F12F4 9203FFFD */  lbu   $v1, -3($s0)
/* 08A7A8 800F12F8 9205FFFE */  lbu   $a1, -2($s0)
/* 08A7AC 800F12FC 9206FFFF */  lbu   $a2, -1($s0)
/* 08A7B0 800F1300 92070000 */  lbu   $a3, ($s0)
/* 08A7B4 800F1304 24820010 */  addiu $v0, $a0, 0x10
/* 08A7B8 800F1308 AE220000 */  sw    $v0, ($s1)
/* 08A7BC 800F130C 3C02DE00 */  lui   $v0, 0xde00
/* 08A7C0 800F1310 AC820008 */  sw    $v0, 8($a0)
/* 08A7C4 800F1314 3C028011 */  lui   $v0, 0x8011
/* 08A7C8 800F1318 244297D8 */  addiu $v0, $v0, -0x6828
/* 08A7CC 800F131C AC82000C */  sw    $v0, 0xc($a0)
/* 08A7D0 800F1320 24820018 */  addiu $v0, $a0, 0x18
/* 08A7D4 800F1324 AE220000 */  sw    $v0, ($s1)
/* 08A7D8 800F1328 24020040 */  addiu $v0, $zero, 0x40
/* 08A7DC 800F132C AC880010 */  sw    $t0, 0x10($a0)
/* 08A7E0 800F1330 AC820014 */  sw    $v0, 0x14($a0)
/* 08A7E4 800F1334 00031E00 */  sll   $v1, $v1, 0x18
/* 08A7E8 800F1338 00052C00 */  sll   $a1, $a1, 0x10
/* 08A7EC 800F133C 00651825 */  or    $v1, $v1, $a1
/* 08A7F0 800F1340 00063200 */  sll   $a2, $a2, 8
/* 08A7F4 800F1344 00661825 */  or    $v1, $v1, $a2
/* 08A7F8 800F1348 00671825 */  or    $v1, $v1, $a3
/* 08A7FC 800F134C AC830004 */  sw    $v1, 4($a0)
.L800F1350:
/* 08A800 800F1350 26520001 */  addiu $s2, $s2, 1
/* 08A804 800F1354 2A420039 */  slti  $v0, $s2, 0x39
/* 08A808 800F1358 1440FFAC */  bnez  $v0, .L800F120C
/* 08A80C 800F135C 2610001C */   addiu $s0, $s0, 0x1c
/* 08A810 800F1360 26F70001 */  addiu $s7, $s7, 1
.L800F1364:
/* 08A814 800F1364 1AE0FF9E */  blez  $s7, .L800F11E0
/* 08A818 800F1368 2694063C */   addiu $s4, $s4, 0x63c
/* 08A81C 800F136C 8FBF00C4 */  lw    $ra, 0xc4($sp)
/* 08A820 800F1370 8FBE00C0 */  lw    $fp, 0xc0($sp)
/* 08A824 800F1374 8FB700BC */  lw    $s7, 0xbc($sp)
/* 08A828 800F1378 8FB600B8 */  lw    $s6, 0xb8($sp)
/* 08A82C 800F137C 8FB500B4 */  lw    $s5, 0xb4($sp)
/* 08A830 800F1380 8FB400B0 */  lw    $s4, 0xb0($sp)
/* 08A834 800F1384 8FB300AC */  lw    $s3, 0xac($sp)
/* 08A838 800F1388 8FB200A8 */  lw    $s2, 0xa8($sp)
/* 08A83C 800F138C 8FB100A4 */  lw    $s1, 0xa4($sp)
/* 08A840 800F1390 8FB000A0 */  lw    $s0, 0xa0($sp)
/* 08A844 800F1394 D7B600D0 */  ldc1  $f22, 0xd0($sp)
/* 08A848 800F1398 D7B400C8 */  ldc1  $f20, 0xc8($sp)
/* 08A84C 800F139C 03E00008 */  jr    $ra
/* 08A850 800F13A0 27BD00D8 */   addiu $sp, $sp, 0xd8


