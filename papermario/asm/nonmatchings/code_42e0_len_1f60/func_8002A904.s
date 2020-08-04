.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8002A904
/* 005D04 8002A904 27BDFFF8 */  addiu $sp, $sp, -8
/* 005D08 8002A908 0080602D */  daddu $t4, $a0, $zero
/* 005D0C 8002A90C 00A0682D */  daddu $t5, $a1, $zero
/* 005D10 8002A910 00E0582D */  daddu $t3, $a3, $zero
/* 005D14 8002A914 3C08800A */  lui   $t0, 0x800a
/* 005D18 8002A918 2508A66C */  addiu $t0, $t0, -0x5994
/* 005D1C 8002A91C 3C02E700 */  lui   $v0, 0xe700
/* 005D20 8002A920 AFB00000 */  sw    $s0, ($sp)
/* 005D24 8002A924 8D070000 */  lw    $a3, ($t0)
/* 005D28 8002A928 97B9001A */  lhu   $t9, 0x1a($sp)
/* 005D2C 8002A92C 97B0001E */  lhu   $s0, 0x1e($sp)
/* 005D30 8002A930 97AF0022 */  lhu   $t7, 0x22($sp)
/* 005D34 8002A934 97B80026 */  lhu   $t8, 0x26($sp)
/* 005D38 8002A938 00E0182D */  daddu $v1, $a3, $zero
/* 005D3C 8002A93C 24E70008 */  addiu $a3, $a3, 8
/* 005D40 8002A940 AD070000 */  sw    $a3, ($t0)
/* 005D44 8002A944 AC620000 */  sw    $v0, ($v1)
/* 005D48 8002A948 24E20008 */  addiu $v0, $a3, 8
/* 005D4C 8002A94C AC600004 */  sw    $zero, 4($v1)
/* 005D50 8002A950 AD020000 */  sw    $v0, ($t0)
/* 005D54 8002A954 3C02DE00 */  lui   $v0, 0xde00
/* 005D58 8002A958 ACE20000 */  sw    $v0, ($a3)
/* 005D5C 8002A95C 3C028007 */  lui   $v0, 0x8007
/* 005D60 8002A960 24424580 */  addiu $v0, $v0, 0x4580
/* 005D64 8002A964 316300FF */  andi  $v1, $t3, 0xff
/* 005D68 8002A968 ACE20004 */  sw    $v0, 4($a3)
/* 005D6C 8002A96C 240200FF */  addiu $v0, $zero, 0xff
/* 005D70 8002A970 1462000A */  bne   $v1, $v0, .L8002A99C
/* 005D74 8002A974 00C0702D */   daddu $t6, $a2, $zero
/* 005D78 8002A978 3C05E200 */  lui   $a1, 0xe200
/* 005D7C 8002A97C 34A5001C */  ori   $a1, $a1, 0x1c
/* 005D80 8002A980 3C030F0A */  lui   $v1, 0xf0a
/* 005D84 8002A984 34634000 */  ori   $v1, $v1, 0x4000
/* 005D88 8002A988 3C06FCFF */  lui   $a2, 0xfcff
/* 005D8C 8002A98C 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 005D90 8002A990 3C04FFFD */  lui   $a0, 0xfffd
/* 005D94 8002A994 0800AA6F */  j     .L8002A9BC
/* 005D98 8002A998 3484FCFE */   ori   $a0, $a0, 0xfcfe

.L8002A99C:
/* 005D9C 8002A99C 3C05E200 */  lui   $a1, 0xe200
/* 005DA0 8002A9A0 34A5001C */  ori   $a1, $a1, 0x1c
/* 005DA4 8002A9A4 3C030050 */  lui   $v1, 0x50
/* 005DA8 8002A9A8 34634240 */  ori   $v1, $v1, 0x4240
/* 005DAC 8002A9AC 3C06FCFF */  lui   $a2, 0xfcff
/* 005DB0 8002A9B0 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 005DB4 8002A9B4 3C04FFFD */  lui   $a0, 0xfffd
/* 005DB8 8002A9B8 3484F6FB */  ori   $a0, $a0, 0xf6fb
.L8002A9BC:
/* 005DBC 8002A9BC 24E20010 */  addiu $v0, $a3, 0x10
/* 005DC0 8002A9C0 AD020000 */  sw    $v0, ($t0)
/* 005DC4 8002A9C4 24E20018 */  addiu $v0, $a3, 0x18
/* 005DC8 8002A9C8 ACE50008 */  sw    $a1, 8($a3)
/* 005DCC 8002A9CC ACE3000C */  sw    $v1, 0xc($a3)
/* 005DD0 8002A9D0 AD020000 */  sw    $v0, ($t0)
/* 005DD4 8002A9D4 ACE60010 */  sw    $a2, 0x10($a3)
/* 005DD8 8002A9D8 ACE40014 */  sw    $a0, 0x14($a3)
/* 005DDC 8002A9DC 3C09E200 */  lui   $t1, 0xe200
/* 005DE0 8002A9E0 3529001C */  ori   $t1, $t1, 0x1c
/* 005DE4 8002A9E4 3C070F0A */  lui   $a3, 0xf0a
/* 005DE8 8002A9E8 34E77008 */  ori   $a3, $a3, 0x7008
/* 005DEC 8002A9EC 3C0AFCFF */  lui   $t2, 0xfcff
/* 005DF0 8002A9F0 354AFFFF */  ori   $t2, $t2, 0xffff
/* 005DF4 8002A9F4 3C08FFFC */  lui   $t0, 0xfffc
/* 005DF8 8002A9F8 3C06800A */  lui   $a2, 0x800a
/* 005DFC 8002A9FC 24C6A66C */  addiu $a2, $a2, -0x5994
/* 005E00 8002AA00 3508F279 */  ori   $t0, $t0, 0xf279
/* 005E04 8002AA04 3C02FA00 */  lui   $v0, 0xfa00
/* 005E08 8002AA08 8CC50000 */  lw    $a1, ($a2)
/* 005E0C 8002AA0C 000C1E00 */  sll   $v1, $t4, 0x18
/* 005E10 8002AA10 00A0202D */  daddu $a0, $a1, $zero
/* 005E14 8002AA14 24A50008 */  addiu $a1, $a1, 8
/* 005E18 8002AA18 ACC50000 */  sw    $a1, ($a2)
/* 005E1C 8002AA1C AC820000 */  sw    $v0, ($a0)
/* 005E20 8002AA20 31A200FF */  andi  $v0, $t5, 0xff
/* 005E24 8002AA24 00021400 */  sll   $v0, $v0, 0x10
/* 005E28 8002AA28 00621825 */  or    $v1, $v1, $v0
/* 005E2C 8002AA2C 31C200FF */  andi  $v0, $t6, 0xff
/* 005E30 8002AA30 00021200 */  sll   $v0, $v0, 8
/* 005E34 8002AA34 00621825 */  or    $v1, $v1, $v0
/* 005E38 8002AA38 316200FF */  andi  $v0, $t3, 0xff
/* 005E3C 8002AA3C 00621825 */  or    $v1, $v1, $v0
/* 005E40 8002AA40 24A20008 */  addiu $v0, $a1, 8
/* 005E44 8002AA44 AC830004 */  sw    $v1, 4($a0)
/* 005E48 8002AA48 31E403FF */  andi  $a0, $t7, 0x3ff
/* 005E4C 8002AA4C 00042380 */  sll   $a0, $a0, 0xe
/* 005E50 8002AA50 ACC20000 */  sw    $v0, ($a2)
/* 005E54 8002AA54 330203FF */  andi  $v0, $t8, 0x3ff
/* 005E58 8002AA58 00021080 */  sll   $v0, $v0, 2
/* 005E5C 8002AA5C 3C03F600 */  lui   $v1, 0xf600
/* 005E60 8002AA60 00431025 */  or    $v0, $v0, $v1
/* 005E64 8002AA64 00822025 */  or    $a0, $a0, $v0
/* 005E68 8002AA68 332303FF */  andi  $v1, $t9, 0x3ff
/* 005E6C 8002AA6C 00031B80 */  sll   $v1, $v1, 0xe
/* 005E70 8002AA70 320203FF */  andi  $v0, $s0, 0x3ff
/* 005E74 8002AA74 00021080 */  sll   $v0, $v0, 2
/* 005E78 8002AA78 00621825 */  or    $v1, $v1, $v0
/* 005E7C 8002AA7C 24A20010 */  addiu $v0, $a1, 0x10
/* 005E80 8002AA80 ACA40000 */  sw    $a0, ($a1)
/* 005E84 8002AA84 ACA30004 */  sw    $v1, 4($a1)
/* 005E88 8002AA88 ACC20000 */  sw    $v0, ($a2)
/* 005E8C 8002AA8C 3C02E700 */  lui   $v0, 0xe700
/* 005E90 8002AA90 ACA20008 */  sw    $v0, 8($a1)
/* 005E94 8002AA94 24A20018 */  addiu $v0, $a1, 0x18
/* 005E98 8002AA98 ACA0000C */  sw    $zero, 0xc($a1)
/* 005E9C 8002AA9C ACC20000 */  sw    $v0, ($a2)
/* 005EA0 8002AAA0 24A20020 */  addiu $v0, $a1, 0x20
/* 005EA4 8002AAA4 ACA90010 */  sw    $t1, 0x10($a1)
/* 005EA8 8002AAA8 ACA70014 */  sw    $a3, 0x14($a1)
/* 005EAC 8002AAAC ACC20000 */  sw    $v0, ($a2)
/* 005EB0 8002AAB0 ACAA0018 */  sw    $t2, 0x18($a1)
/* 005EB4 8002AAB4 ACA8001C */  sw    $t0, 0x1c($a1)
/* 005EB8 8002AAB8 8FB00000 */  lw    $s0, ($sp)
/* 005EBC 8002AABC 03E00008 */  jr    $ra
/* 005EC0 8002AAC0 27BD0008 */   addiu $sp, $sp, 8

