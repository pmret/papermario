.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel make_player_display_list
/* 07A7A4 800E12F4 3C03800A */  lui   $v1, 0x800a
/* 07A7A8 800E12F8 8463A634 */  lh    $v1, -0x59cc($v1)
/* 07A7AC 800E12FC 27BDFEB0 */  addiu $sp, $sp, -0x150
/* 07A7B0 800E1300 AFB20128 */  sw    $s2, 0x128($sp)
/* 07A7B4 800E1304 3C128011 */  lui   $s2, 0x8011
/* 07A7B8 800E1308 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 07A7BC 800E130C AFBF012C */  sw    $ra, 0x12c($sp)
/* 07A7C0 800E1310 AFB10124 */  sw    $s1, 0x124($sp)
/* 07A7C4 800E1314 AFB00120 */  sw    $s0, 0x120($sp)
/* 07A7C8 800E1318 F7BA0148 */  sdc1  $f26, 0x148($sp)
/* 07A7CC 800E131C F7B80140 */  sdc1  $f24, 0x140($sp)
/* 07A7D0 800E1320 F7B60138 */  sdc1  $f22, 0x138($sp)
/* 07A7D4 800E1324 F7B40130 */  sdc1  $f20, 0x130($sp)
/* 07A7D8 800E1328 00031080 */  sll   $v0, $v1, 2
/* 07A7DC 800E132C 00431021 */  addu  $v0, $v0, $v1
/* 07A7E0 800E1330 00021080 */  sll   $v0, $v0, 2
/* 07A7E4 800E1334 00431023 */  subu  $v0, $v0, $v1
/* 07A7E8 800E1338 000218C0 */  sll   $v1, $v0, 3
/* 07A7EC 800E133C 00431021 */  addu  $v0, $v0, $v1
/* 07A7F0 800E1340 000210C0 */  sll   $v0, $v0, 3
/* 07A7F4 800E1344 24030011 */  addiu $v1, $zero, 0x11
/* 07A7F8 800E1348 3C01800B */  lui   $at, 0x800b
/* 07A7FC 800E134C 00220821 */  addu  $at, $at, $v0
/* 07A800 800E1350 C4201DEC */  lwc1  $f0, 0x1dec($at)
/* 07A804 800E1354 824200B4 */  lb    $v0, 0xb4($s2)
/* 07A808 800E1358 14430035 */  bne   $v0, $v1, .L800E1430
/* 07A80C 800E135C 46000687 */   neg.s $f26, $f0
/* 07A810 800E1360 3C013F36 */  lui   $at, 0x3f36
/* 07A814 800E1364 3421DB6E */  ori   $at, $at, 0xdb6e
/* 07A818 800E1368 44810000 */  mtc1  $at, $f0
/* 07A81C 800E136C 27B000E0 */  addiu $s0, $sp, 0xe0
/* 07A820 800E1370 44050000 */  mfc1  $a1, $f0
/* 07A824 800E1374 0200202D */  daddu $a0, $s0, $zero
/* 07A828 800E1378 00A0302D */  daddu $a2, $a1, $zero
/* 07A82C 800E137C 0C019DF0 */  jal   guScaleF
/* 07A830 800E1380 00A0382D */   daddu $a3, $a1, $zero
/* 07A834 800E1384 4405D000 */  mfc1  $a1, $f26
/* 07A838 800E1388 4480A000 */  mtc1  $zero, $f20
/* 07A83C 800E138C 3C013F80 */  lui   $at, 0x3f80
/* 07A840 800E1390 4481B000 */  mtc1  $at, $f22
/* 07A844 800E1394 4406A000 */  mfc1  $a2, $f20
/* 07A848 800E1398 4407B000 */  mfc1  $a3, $f22
/* 07A84C 800E139C 27A40020 */  addiu $a0, $sp, 0x20
/* 07A850 800E13A0 0C019EC8 */  jal   guRotateF
/* 07A854 800E13A4 E7B40010 */   swc1  $f20, 0x10($sp)
/* 07A858 800E13A8 0200202D */  daddu $a0, $s0, $zero
/* 07A85C 800E13AC 27A50020 */  addiu $a1, $sp, 0x20
/* 07A860 800E13B0 0C019D80 */  jal   guMtxCatF
/* 07A864 800E13B4 00A0302D */   daddu $a2, $a1, $zero
/* 07A868 800E13B8 27B000A0 */  addiu $s0, $sp, 0xa0
/* 07A86C 800E13BC 8E4500A8 */  lw    $a1, 0xa8($s2)
/* 07A870 800E13C0 4406A000 */  mfc1  $a2, $f20
/* 07A874 800E13C4 4407B000 */  mfc1  $a3, $f22
/* 07A878 800E13C8 0200202D */  daddu $a0, $s0, $zero
/* 07A87C 800E13CC 0C019EC8 */  jal   guRotateF
/* 07A880 800E13D0 AFA60010 */   sw    $a2, 0x10($sp)
/* 07A884 800E13D4 27A40020 */  addiu $a0, $sp, 0x20
/* 07A888 800E13D8 0200282D */  daddu $a1, $s0, $zero
/* 07A88C 800E13DC 0C019D80 */  jal   guMtxCatF
/* 07A890 800E13E0 0080302D */   daddu $a2, $a0, $zero
/* 07A894 800E13E4 C640002C */  lwc1  $f0, 0x2c($s2)
/* 07A898 800E13E8 27B00060 */  addiu $s0, $sp, 0x60
/* 07A89C 800E13EC 46160001 */  sub.s $f0, $f0, $f22
/* 07A8A0 800E13F0 8E450028 */  lw    $a1, 0x28($s2)
/* 07A8A4 800E13F4 8E470030 */  lw    $a3, 0x30($s2)
/* 07A8A8 800E13F8 44060000 */  mfc1  $a2, $f0
/* 07A8AC 800E13FC 0C019E40 */  jal   guTranslateF
/* 07A8B0 800E1400 0200202D */   daddu $a0, $s0, $zero
/* 07A8B4 800E1404 27A40020 */  addiu $a0, $sp, 0x20
/* 07A8B8 800E1408 0200282D */  daddu $a1, $s0, $zero
/* 07A8BC 800E140C 0C019D80 */  jal   guMtxCatF
/* 07A8C0 800E1410 0080302D */   daddu $a2, $a0, $zero
/* 07A8C4 800E1414 0000202D */  daddu $a0, $zero, $zero
/* 07A8C8 800E1418 0080282D */  daddu $a1, $a0, $zero
/* 07A8CC 800E141C 0080302D */  daddu $a2, $a0, $zero
/* 07A8D0 800E1420 0080382D */  daddu $a3, $a0, $zero
/* 07A8D4 800E1424 27A20020 */  addiu $v0, $sp, 0x20
/* 07A8D8 800E1428 080385AD */  j     .L800E16B4
/* 07A8DC 800E142C AFA20010 */   sw    $v0, 0x10($sp)

.L800E1430:
/* 07A8E0 800E1430 27B000A0 */  addiu $s0, $sp, 0xa0
/* 07A8E4 800E1434 4405D000 */  mfc1  $a1, $f26
/* 07A8E8 800E1438 4480A000 */  mtc1  $zero, $f20
/* 07A8EC 800E143C 3C07BF80 */  lui   $a3, 0xbf80
/* 07A8F0 800E1440 4406A000 */  mfc1  $a2, $f20
/* 07A8F4 800E1444 0200202D */  daddu $a0, $s0, $zero
/* 07A8F8 800E1448 0C019EC8 */  jal   guRotateF
/* 07A8FC 800E144C E7B40010 */   swc1  $f20, 0x10($sp)
/* 07A900 800E1450 C64C008C */  lwc1  $f12, 0x8c($s2)
/* 07A904 800E1454 0C00A6C9 */  jal   clamp_angle
/* 07A908 800E1458 00000000 */   nop   
/* 07A90C 800E145C 44050000 */  mfc1  $a1, $f0
/* 07A910 800E1460 4406A000 */  mfc1  $a2, $f20
/* 07A914 800E1464 4407A000 */  mfc1  $a3, $f20
/* 07A918 800E1468 3C013F80 */  lui   $at, 0x3f80
/* 07A91C 800E146C 4481B000 */  mtc1  $at, $f22
/* 07A920 800E1470 27A40020 */  addiu $a0, $sp, 0x20
/* 07A924 800E1474 0C019EC8 */  jal   guRotateF
/* 07A928 800E1478 E7B60010 */   swc1  $f22, 0x10($sp)
/* 07A92C 800E147C 0200202D */  daddu $a0, $s0, $zero
/* 07A930 800E1480 27A50020 */  addiu $a1, $sp, 0x20
/* 07A934 800E1484 0C019D80 */  jal   guMtxCatF
/* 07A938 800E1488 00A0302D */   daddu $a2, $a1, $zero
/* 07A93C 800E148C 864200B0 */  lh    $v0, 0xb0($s2)
/* 07A940 800E1490 3C013F00 */  lui   $at, 0x3f00
/* 07A944 800E1494 4481C000 */  mtc1  $at, $f24
/* 07A948 800E1498 00021023 */  negu  $v0, $v0
/* 07A94C 800E149C 44820000 */  mtc1  $v0, $f0
/* 07A950 800E14A0 00000000 */  nop   
/* 07A954 800E14A4 46800020 */  cvt.s.w $f0, $f0
/* 07A958 800E14A8 46180002 */  mul.s $f0, $f0, $f24
/* 07A95C 800E14AC 00000000 */  nop   
/* 07A960 800E14B0 27B10060 */  addiu $s1, $sp, 0x60
/* 07A964 800E14B4 4405A000 */  mfc1  $a1, $f20
/* 07A968 800E14B8 4407A000 */  mfc1  $a3, $f20
/* 07A96C 800E14BC 44060000 */  mfc1  $a2, $f0
/* 07A970 800E14C0 0C019E40 */  jal   guTranslateF
/* 07A974 800E14C4 0220202D */   daddu $a0, $s1, $zero
/* 07A978 800E14C8 0220202D */  daddu $a0, $s1, $zero
/* 07A97C 800E14CC 27A50020 */  addiu $a1, $sp, 0x20
/* 07A980 800E14D0 0C019D80 */  jal   guMtxCatF
/* 07A984 800E14D4 00A0302D */   daddu $a2, $a1, $zero
/* 07A988 800E14D8 4405D000 */  mfc1  $a1, $f26
/* 07A98C 800E14DC 4406A000 */  mfc1  $a2, $f20
/* 07A990 800E14E0 4407B000 */  mfc1  $a3, $f22
/* 07A994 800E14E4 0200202D */  daddu $a0, $s0, $zero
/* 07A998 800E14E8 0C019EC8 */  jal   guRotateF
/* 07A99C 800E14EC E7B40010 */   swc1  $f20, 0x10($sp)
/* 07A9A0 800E14F0 27A40020 */  addiu $a0, $sp, 0x20
/* 07A9A4 800E14F4 0200282D */  daddu $a1, $s0, $zero
/* 07A9A8 800E14F8 0C019D80 */  jal   guMtxCatF
/* 07A9AC 800E14FC 0080302D */   daddu $a2, $a0, $zero
/* 07A9B0 800E1500 8E4500A8 */  lw    $a1, 0xa8($s2)
/* 07A9B4 800E1504 4406A000 */  mfc1  $a2, $f20
/* 07A9B8 800E1508 4407B000 */  mfc1  $a3, $f22
/* 07A9BC 800E150C 0200202D */  daddu $a0, $s0, $zero
/* 07A9C0 800E1510 0C019EC8 */  jal   guRotateF
/* 07A9C4 800E1514 E7B40010 */   swc1  $f20, 0x10($sp)
/* 07A9C8 800E1518 27A40020 */  addiu $a0, $sp, 0x20
/* 07A9CC 800E151C 0200282D */  daddu $a1, $s0, $zero
/* 07A9D0 800E1520 0C019D80 */  jal   guMtxCatF
/* 07A9D4 800E1524 0080302D */   daddu $a2, $a0, $zero
/* 07A9D8 800E1528 864200B0 */  lh    $v0, 0xb0($s2)
/* 07A9DC 800E152C 44820000 */  mtc1  $v0, $f0
/* 07A9E0 800E1530 00000000 */  nop   
/* 07A9E4 800E1534 46800020 */  cvt.s.w $f0, $f0
/* 07A9E8 800E1538 46180002 */  mul.s $f0, $f0, $f24
/* 07A9EC 800E153C 00000000 */  nop   
/* 07A9F0 800E1540 0220202D */  daddu $a0, $s1, $zero
/* 07A9F4 800E1544 4405A000 */  mfc1  $a1, $f20
/* 07A9F8 800E1548 44060000 */  mfc1  $a2, $f0
/* 07A9FC 800E154C 0C019E40 */  jal   guTranslateF
/* 07AA00 800E1550 00A0382D */   daddu $a3, $a1, $zero
/* 07AA04 800E1554 27A40020 */  addiu $a0, $sp, 0x20
/* 07AA08 800E1558 0220282D */  daddu $a1, $s1, $zero
/* 07AA0C 800E155C 0C019D80 */  jal   guMtxCatF
/* 07AA10 800E1560 0080302D */   daddu $a2, $a0, $zero
/* 07AA14 800E1564 3C013F36 */  lui   $at, 0x3f36
/* 07AA18 800E1568 3421DB6E */  ori   $at, $at, 0xdb6e
/* 07AA1C 800E156C 44810000 */  mtc1  $at, $f0
/* 07AA20 800E1570 27B000E0 */  addiu $s0, $sp, 0xe0
/* 07AA24 800E1574 44050000 */  mfc1  $a1, $f0
/* 07AA28 800E1578 0200202D */  daddu $a0, $s0, $zero
/* 07AA2C 800E157C 00A0302D */  daddu $a2, $a1, $zero
/* 07AA30 800E1580 0C019DF0 */  jal   guScaleF
/* 07AA34 800E1584 00A0382D */   daddu $a3, $a1, $zero
/* 07AA38 800E1588 27A40020 */  addiu $a0, $sp, 0x20
/* 07AA3C 800E158C 0200282D */  daddu $a1, $s0, $zero
/* 07AA40 800E1590 0C019D80 */  jal   guMtxCatF
/* 07AA44 800E1594 0080302D */   daddu $a2, $a0, $zero
/* 07AA48 800E1598 8E450028 */  lw    $a1, 0x28($s2)
/* 07AA4C 800E159C 8E46002C */  lw    $a2, 0x2c($s2)
/* 07AA50 800E15A0 8E470030 */  lw    $a3, 0x30($s2)
/* 07AA54 800E15A4 0C019E40 */  jal   guTranslateF
/* 07AA58 800E15A8 0220202D */   daddu $a0, $s1, $zero
/* 07AA5C 800E15AC 27A40020 */  addiu $a0, $sp, 0x20
/* 07AA60 800E15B0 0220282D */  daddu $a1, $s1, $zero
/* 07AA64 800E15B4 0C019D80 */  jal   guMtxCatF
/* 07AA68 800E15B8 0080302D */   daddu $a2, $a0, $zero
/* 07AA6C 800E15BC 8E430004 */  lw    $v1, 4($s2)
/* 07AA70 800E15C0 30620400 */  andi  $v0, $v1, 0x400
/* 07AA74 800E15C4 10400017 */  beqz  $v0, .L800E1624
/* 07AA78 800E15C8 0000202D */   daddu $a0, $zero, $zero
/* 07AA7C 800E15CC 2405FFFF */  addiu $a1, $zero, -1
/* 07AA80 800E15D0 0080302D */  daddu $a2, $a0, $zero
/* 07AA84 800E15D4 0080382D */  daddu $a3, $a0, $zero
/* 07AA88 800E15D8 2402FBFF */  addiu $v0, $zero, -0x401
/* 07AA8C 800E15DC 00621024 */  and   $v0, $v1, $v0
/* 07AA90 800E15E0 AE420004 */  sw    $v0, 4($s2)
/* 07AA94 800E15E4 24020016 */  addiu $v0, $zero, 0x16
/* 07AA98 800E15E8 A242000A */  sb    $v0, 0xa($s2)
/* 07AA9C 800E15EC AFA00010 */  sw    $zero, 0x10($sp)
/* 07AAA0 800E15F0 AFA00014 */  sw    $zero, 0x14($sp)
/* 07AAA4 800E15F4 AFA00018 */  sw    $zero, 0x18($sp)
/* 07AAA8 800E15F8 0C0B77B9 */  jal   func_802DDEE4
/* 07AAAC 800E15FC AFA0001C */   sw    $zero, 0x1c($sp)
/* 07AAB0 800E1600 24050005 */  addiu $a1, $zero, 5
/* 07AAB4 800E1604 24060001 */  addiu $a2, $zero, 1
/* 07AAB8 800E1608 00C0382D */  daddu $a3, $a2, $zero
/* 07AABC 800E160C 8E4400B8 */  lw    $a0, 0xb8($s2)
/* 07AAC0 800E1610 00C0102D */  daddu $v0, $a2, $zero
/* 07AAC4 800E1614 AFA20010 */  sw    $v0, 0x10($sp)
/* 07AAC8 800E1618 AFA00014 */  sw    $zero, 0x14($sp)
/* 07AACC 800E161C 0C0B77FE */  jal   func_802DDFF8
/* 07AAD0 800E1620 AFA00018 */   sw    $zero, 0x18($sp)
.L800E1624:
/* 07AAD4 800E1624 8242000A */  lb    $v0, 0xa($s2)
/* 07AAD8 800E1628 9243000A */  lbu   $v1, 0xa($s2)
/* 07AADC 800E162C 1040000D */  beqz  $v0, .L800E1664
/* 07AAE0 800E1630 2462FFFF */   addiu $v0, $v1, -1
/* 07AAE4 800E1634 A242000A */  sb    $v0, 0xa($s2)
/* 07AAE8 800E1638 00021600 */  sll   $v0, $v0, 0x18
/* 07AAEC 800E163C 14400009 */  bnez  $v0, .L800E1664
/* 07AAF0 800E1640 0000202D */   daddu $a0, $zero, $zero
/* 07AAF4 800E1644 2405FFFF */  addiu $a1, $zero, -1
/* 07AAF8 800E1648 0080302D */  daddu $a2, $a0, $zero
/* 07AAFC 800E164C 0080382D */  daddu $a3, $a0, $zero
/* 07AB00 800E1650 AFA00010 */  sw    $zero, 0x10($sp)
/* 07AB04 800E1654 AFA00014 */  sw    $zero, 0x14($sp)
/* 07AB08 800E1658 AFA00018 */  sw    $zero, 0x18($sp)
/* 07AB0C 800E165C 0C0B77B9 */  jal   func_802DDEE4
/* 07AB10 800E1660 AFA0001C */   sw    $zero, 0x1c($sp)
.L800E1664:
/* 07AB14 800E1664 C64200A8 */  lwc1  $f2, 0xa8($s2)
/* 07AB18 800E1668 3C0142B4 */  lui   $at, 0x42b4
/* 07AB1C 800E166C 44810000 */  mtc1  $at, $f0
/* 07AB20 800E1670 00000000 */  nop   
/* 07AB24 800E1674 4602003E */  c.le.s $f0, $f2
/* 07AB28 800E1678 00000000 */  nop   
/* 07AB2C 800E167C 45000008 */  bc1f  .L800E16A0
/* 07AB30 800E1680 0000202D */   daddu $a0, $zero, $zero
/* 07AB34 800E1684 3C014387 */  lui   $at, 0x4387
/* 07AB38 800E1688 44810000 */  mtc1  $at, $f0
/* 07AB3C 800E168C 00000000 */  nop   
/* 07AB40 800E1690 4600103C */  c.lt.s $f2, $f0
/* 07AB44 800E1694 00000000 */  nop   
/* 07AB48 800E1698 45030001 */  bc1tl .L800E16A0
/* 07AB4C 800E169C 3C041000 */   lui   $a0, 0x1000
.L800E16A0:
/* 07AB50 800E16A0 27A20020 */  addiu $v0, $sp, 0x20
/* 07AB54 800E16A4 AFA20010 */  sw    $v0, 0x10($sp)
/* 07AB58 800E16A8 0000282D */  daddu $a1, $zero, $zero
/* 07AB5C 800E16AC 00A0302D */  daddu $a2, $a1, $zero
/* 07AB60 800E16B0 00A0382D */  daddu $a3, $a1, $zero
.L800E16B4:
/* 07AB64 800E16B4 0C0B7710 */  jal   render_sprite
/* 07AB68 800E16B8 00000000 */   nop   
/* 07AB6C 800E16BC 3C03800F */  lui   $v1, 0x800f
/* 07AB70 800E16C0 24637B4C */  addiu $v1, $v1, 0x7b4c
/* 07AB74 800E16C4 8C620000 */  lw    $v0, ($v1)
/* 07AB78 800E16C8 24420001 */  addiu $v0, $v0, 1
/* 07AB7C 800E16CC AC620000 */  sw    $v0, ($v1)
/* 07AB80 800E16D0 28420003 */  slti  $v0, $v0, 3
/* 07AB84 800E16D4 50400001 */  beql  $v0, $zero, .L800E16DC
/* 07AB88 800E16D8 AC600000 */   sw    $zero, ($v1)
.L800E16DC:
/* 07AB8C 800E16DC 8FBF012C */  lw    $ra, 0x12c($sp)
/* 07AB90 800E16E0 8FB20128 */  lw    $s2, 0x128($sp)
/* 07AB94 800E16E4 8FB10124 */  lw    $s1, 0x124($sp)
/* 07AB98 800E16E8 8FB00120 */  lw    $s0, 0x120($sp)
/* 07AB9C 800E16EC D7BA0148 */  ldc1  $f26, 0x148($sp)
/* 07ABA0 800E16F0 D7B80140 */  ldc1  $f24, 0x140($sp)
/* 07ABA4 800E16F4 D7B60138 */  ldc1  $f22, 0x138($sp)
/* 07ABA8 800E16F8 D7B40130 */  ldc1  $f20, 0x130($sp)
/* 07ABAC 800E16FC 03E00008 */  jr    $ra
/* 07ABB0 800E1700 27BD0150 */   addiu $sp, $sp, 0x150

