.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002A8C4
/* 5CC4 8002A8C4 27BDFFF8 */  addiu     $sp, $sp, -8
/* 5CC8 8002A8C8 0080602D */  daddu     $t4, $a0, $zero
/* 5CCC 8002A8CC 00A0682D */  daddu     $t5, $a1, $zero
/* 5CD0 8002A8D0 00E0582D */  daddu     $t3, $a3, $zero
/* 5CD4 8002A8D4 3C08800A */  lui       $t0, %hi(D_8009A64C)
/* 5CD8 8002A8D8 2508A64C */  addiu     $t0, $t0, %lo(D_8009A64C)
/* 5CDC 8002A8DC 3C02E700 */  lui       $v0, 0xe700
/* 5CE0 8002A8E0 AFB00000 */  sw        $s0, ($sp)
/* 5CE4 8002A8E4 8D070000 */  lw        $a3, ($t0)
/* 5CE8 8002A8E8 97B9001A */  lhu       $t9, 0x1a($sp)
/* 5CEC 8002A8EC 97B0001E */  lhu       $s0, 0x1e($sp)
/* 5CF0 8002A8F0 97AF0022 */  lhu       $t7, 0x22($sp)
/* 5CF4 8002A8F4 97B80026 */  lhu       $t8, 0x26($sp)
/* 5CF8 8002A8F8 00E0182D */  daddu     $v1, $a3, $zero
/* 5CFC 8002A8FC 24E70008 */  addiu     $a3, $a3, 8
/* 5D00 8002A900 AD070000 */  sw        $a3, ($t0)
/* 5D04 8002A904 AC620000 */  sw        $v0, ($v1)
/* 5D08 8002A908 24E20008 */  addiu     $v0, $a3, 8
/* 5D0C 8002A90C AC600004 */  sw        $zero, 4($v1)
/* 5D10 8002A910 AD020000 */  sw        $v0, ($t0)
/* 5D14 8002A914 3C02DE00 */  lui       $v0, 0xde00
/* 5D18 8002A918 ACE20000 */  sw        $v0, ($a3)
/* 5D1C 8002A91C 3C028007 */  lui       $v0, %hi(D_80074560)
/* 5D20 8002A920 24424560 */  addiu     $v0, $v0, %lo(D_80074560)
/* 5D24 8002A924 316300FF */  andi      $v1, $t3, 0xff
/* 5D28 8002A928 ACE20004 */  sw        $v0, 4($a3)
/* 5D2C 8002A92C 240200FF */  addiu     $v0, $zero, 0xff
/* 5D30 8002A930 1462000A */  bne       $v1, $v0, .L8002A95C
/* 5D34 8002A934 00C0702D */   daddu    $t6, $a2, $zero
/* 5D38 8002A938 3C05E200 */  lui       $a1, 0xe200
/* 5D3C 8002A93C 34A5001C */  ori       $a1, $a1, 0x1c
/* 5D40 8002A940 3C030F0A */  lui       $v1, 0xf0a
/* 5D44 8002A944 34634000 */  ori       $v1, $v1, 0x4000
/* 5D48 8002A948 3C06FCFF */  lui       $a2, 0xfcff
/* 5D4C 8002A94C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 5D50 8002A950 3C04FFFD */  lui       $a0, 0xfffd
/* 5D54 8002A954 0800AA5F */  j         .L8002A97C
/* 5D58 8002A958 3484FCFE */   ori      $a0, $a0, 0xfcfe
.L8002A95C:
/* 5D5C 8002A95C 3C05E200 */  lui       $a1, 0xe200
/* 5D60 8002A960 34A5001C */  ori       $a1, $a1, 0x1c
/* 5D64 8002A964 3C030050 */  lui       $v1, 0x50
/* 5D68 8002A968 34634240 */  ori       $v1, $v1, 0x4240
/* 5D6C 8002A96C 3C06FCFF */  lui       $a2, 0xfcff
/* 5D70 8002A970 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 5D74 8002A974 3C04FFFD */  lui       $a0, 0xfffd
/* 5D78 8002A978 3484F6FB */  ori       $a0, $a0, 0xf6fb
.L8002A97C:
/* 5D7C 8002A97C 24E20010 */  addiu     $v0, $a3, 0x10
/* 5D80 8002A980 AD020000 */  sw        $v0, ($t0)
/* 5D84 8002A984 24E20018 */  addiu     $v0, $a3, 0x18
/* 5D88 8002A988 ACE50008 */  sw        $a1, 8($a3)
/* 5D8C 8002A98C ACE3000C */  sw        $v1, 0xc($a3)
/* 5D90 8002A990 AD020000 */  sw        $v0, ($t0)
/* 5D94 8002A994 ACE60010 */  sw        $a2, 0x10($a3)
/* 5D98 8002A998 ACE40014 */  sw        $a0, 0x14($a3)
/* 5D9C 8002A99C 3C09E200 */  lui       $t1, 0xe200
/* 5DA0 8002A9A0 3529001C */  ori       $t1, $t1, 0x1c
/* 5DA4 8002A9A4 3C070F0A */  lui       $a3, 0xf0a
/* 5DA8 8002A9A8 34E77008 */  ori       $a3, $a3, 0x7008
/* 5DAC 8002A9AC 3C0AFCFF */  lui       $t2, 0xfcff
/* 5DB0 8002A9B0 354AFFFF */  ori       $t2, $t2, 0xffff
/* 5DB4 8002A9B4 3C08FFFC */  lui       $t0, 0xfffc
/* 5DB8 8002A9B8 3C06800A */  lui       $a2, %hi(D_8009A64C)
/* 5DBC 8002A9BC 24C6A64C */  addiu     $a2, $a2, %lo(D_8009A64C)
/* 5DC0 8002A9C0 3508F279 */  ori       $t0, $t0, 0xf279
/* 5DC4 8002A9C4 3C02FA00 */  lui       $v0, 0xfa00
/* 5DC8 8002A9C8 8CC50000 */  lw        $a1, ($a2)
/* 5DCC 8002A9CC 000C1E00 */  sll       $v1, $t4, 0x18
/* 5DD0 8002A9D0 00A0202D */  daddu     $a0, $a1, $zero
/* 5DD4 8002A9D4 24A50008 */  addiu     $a1, $a1, 8
/* 5DD8 8002A9D8 ACC50000 */  sw        $a1, ($a2)
/* 5DDC 8002A9DC AC820000 */  sw        $v0, ($a0)
/* 5DE0 8002A9E0 31A200FF */  andi      $v0, $t5, 0xff
/* 5DE4 8002A9E4 00021400 */  sll       $v0, $v0, 0x10
/* 5DE8 8002A9E8 00621825 */  or        $v1, $v1, $v0
/* 5DEC 8002A9EC 31C200FF */  andi      $v0, $t6, 0xff
/* 5DF0 8002A9F0 00021200 */  sll       $v0, $v0, 8
/* 5DF4 8002A9F4 00621825 */  or        $v1, $v1, $v0
/* 5DF8 8002A9F8 316200FF */  andi      $v0, $t3, 0xff
/* 5DFC 8002A9FC 00621825 */  or        $v1, $v1, $v0
/* 5E00 8002AA00 24A20008 */  addiu     $v0, $a1, 8
/* 5E04 8002AA04 AC830004 */  sw        $v1, 4($a0)
/* 5E08 8002AA08 31E403FF */  andi      $a0, $t7, 0x3ff
/* 5E0C 8002AA0C 00042380 */  sll       $a0, $a0, 0xe
/* 5E10 8002AA10 ACC20000 */  sw        $v0, ($a2)
/* 5E14 8002AA14 330203FF */  andi      $v0, $t8, 0x3ff
/* 5E18 8002AA18 00021080 */  sll       $v0, $v0, 2
/* 5E1C 8002AA1C 3C03F600 */  lui       $v1, 0xf600
/* 5E20 8002AA20 00431025 */  or        $v0, $v0, $v1
/* 5E24 8002AA24 00822025 */  or        $a0, $a0, $v0
/* 5E28 8002AA28 332303FF */  andi      $v1, $t9, 0x3ff
/* 5E2C 8002AA2C 00031B80 */  sll       $v1, $v1, 0xe
/* 5E30 8002AA30 320203FF */  andi      $v0, $s0, 0x3ff
/* 5E34 8002AA34 00021080 */  sll       $v0, $v0, 2
/* 5E38 8002AA38 00621825 */  or        $v1, $v1, $v0
/* 5E3C 8002AA3C 24A20010 */  addiu     $v0, $a1, 0x10
/* 5E40 8002AA40 ACA40000 */  sw        $a0, ($a1)
/* 5E44 8002AA44 ACA30004 */  sw        $v1, 4($a1)
/* 5E48 8002AA48 ACC20000 */  sw        $v0, ($a2)
/* 5E4C 8002AA4C 3C02E700 */  lui       $v0, 0xe700
/* 5E50 8002AA50 ACA20008 */  sw        $v0, 8($a1)
/* 5E54 8002AA54 24A20018 */  addiu     $v0, $a1, 0x18
/* 5E58 8002AA58 ACA0000C */  sw        $zero, 0xc($a1)
/* 5E5C 8002AA5C ACC20000 */  sw        $v0, ($a2)
/* 5E60 8002AA60 24A20020 */  addiu     $v0, $a1, 0x20
/* 5E64 8002AA64 ACA90010 */  sw        $t1, 0x10($a1)
/* 5E68 8002AA68 ACA70014 */  sw        $a3, 0x14($a1)
/* 5E6C 8002AA6C ACC20000 */  sw        $v0, ($a2)
/* 5E70 8002AA70 ACAA0018 */  sw        $t2, 0x18($a1)
/* 5E74 8002AA74 ACA8001C */  sw        $t0, 0x1c($a1)
/* 5E78 8002AA78 8FB00000 */  lw        $s0, ($sp)
/* 5E7C 8002AA7C 03E00008 */  jr        $ra
/* 5E80 8002AA80 27BD0008 */   addiu    $sp, $sp, 8
